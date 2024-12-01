/*
 * Constants.h
 *
 *  Created on: Feb 3, 2016
 *      Author: peterwhidden
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// #define NULL 0

// Simulation Parameters
#define NUM_BODIES (1024 * 32)		   // Number of small particles
#define SYSTEM_SIZE 3.5				   // Farthest particles in AU
#define SYSTEM_THICKNESS 1			   // Thickness in AU
#define INNER_BOUND 0				   // Closest particles to center in AU
#define SOFTENING (0.5 * AU_TO_METRES) // Softens particle interactions at close distances
#define EXTRA_MASS 5.5				   // Additional central mass (black hole/star)
#define BINARY_SEPARATION 0.07		   // AU (only applies when binary code uncommented)
#define TIME_STEP (3 * 32 * 1024)	   // Time step in seconds
#define STEP_COUNT 600				   // Number of simulation steps
#define MAX_DISTANCE 0.75			   // Barnes-Hut distance approximation factor

// Rendering Parameters
#define WIDTH 1024			   // Image render width
#define HEIGHT 1024			   // Image render height
#define RENDER_SCALE 2.5	   // "Zoom" of images produced
#define DOT_SIZE 8			   // Range of pixels to render
#define PARTICLE_BRIGHTNESS 1  // Adjust particle brightness
#define PARTICLE_SHARPNESS 1.0 // Adjust particle sharpness
#define MAX_VEL_COLOR 40000.0  // Max velocity color mapping (in km/s)
#define MIN_VEL_COLOR 14000.0  // Min velocity color mapping (in km/s)
#define RENDER_INTERVAL 1	   // Timesteps between each rendered frame

// Physical Constants
#define PI 3.14159265358979323846 // Mathematical constant
#define AU_TO_METRES 1.496e11	  // Meters in an Astronomical Unit
#define SOLAR_MASS 2.0e30		  // Mass of the Sun (in kg)
#define G 6.67408e-11			  // Gravitational constant

// Debugging Options
#define DEBUG_INFO false // Print detailed debug information to the console
// #define PARALLEL_RENDER            // Enable parallel rendering (may introduce inaccuracies)

struct vec3
{
	vec3() {}
	vec3(double x, double y, double z) : x(x), y(y), z(z) {}
	double x, y, z;
};

struct body
{
	body() : mass(0) {}
	vec3 position, velocity, accel;
	double mass;
};

struct color
{
	double r, g, b;
};

#endif /* CONSTANTS_H_ */
