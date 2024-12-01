#include <iostream>
#include <cmath>
#include "nbody/Constants.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <psapi.h>
#elif defined(__APPLE__) && defined(__MACH__)
#include <mach/mach.h>
#include <unistd.h>
#endif

void singleInteraction(struct body *a, struct body *b)
{
    vec3 positive_difference;
    positive_difference.x = (a->position.x - b->position.x) * AU_TO_METRES;
    positive_difference.y = (a->position.y - b->position.y) * AU_TO_METRES;
    positive_difference.z = (a->position.z - b->position.z) * AU_TO_METRES;

    double distance = sqrt(pow(positive_difference.x, 2) + pow(positive_difference.y, 2) + pow(positive_difference.z, 2));

    double force = TIME_STEP * (G * a->mass * b->mass) / ((pow(distance, 2) + pow(SOFTENING, 2)) * distance);

    a->accel.x -= force * positive_difference.x / a->mass;
    a->accel.y -= force * positive_difference.y / a->mass;
    a->accel.z -= force * positive_difference.z / a->mass;

    b->accel.x -= force * positive_difference.x / b->mass;
    b->accel.y -= force * positive_difference.y / b->mass;
    b->accel.z -= force * positive_difference.z / b->mass;
}

#if defined(_WIN32) || defined(_WIN64)
SIZE_T getMemoryUsage()
{
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
    return pmc.WorkingSetSize;
}
#elif defined(__APPLE__) && defined(__MACH__)
size_t getMemoryUsage()
{
    struct mach_task_basic_info info;
    mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;
    if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info, &infoCount) != KERN_SUCCESS)
    {
        return 0;
    }
    return info.resident_size;
}
#endif

int main()
{
    body body_a, body_b;

    // Siruis A: The primary star
    body_a.position = vec3(0.0, 1.5e10, 0.0);
    body_a.velocity = vec3(-1.5e4, 0.0, 0.0);
    body_a.accel = vec3(0.0, 0.0, 0.0);
    body_a.mass = 2.0 * SOLAR_MASS;

    // Sirius B: The white dwarf companion star
    body_b.position = vec3(0.0, -1.5e10, 0.0);
    body_b.velocity = vec3(4.5e4, 0.0, 0.0);
    body_b.accel = vec3(0.0, 0.0, 0.0);
    body_b.mass = 1.0 * SOLAR_MASS;

    auto initial_memory = getMemoryUsage();

    singleInteraction(&body_a, &body_b);

    auto final_memory = getMemoryUsage();

    std::cout << "Memory used by function: " << (final_memory - initial_memory) / 1024 << " KB" << std::endl;
}
