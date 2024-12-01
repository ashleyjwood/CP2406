#include <iostream>
#include <chrono>
#include <cmath>
#include "nbody/Constants.h"

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

    auto start = std::chrono::high_resolution_clock::now();

    singleInteraction(&body_a, &body_b);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Function execution time: " << duration.count() << " ms" << std::endl;
}
