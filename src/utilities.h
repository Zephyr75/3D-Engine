#ifndef UTILITIES_H
#define UTILITIES_H

#include "SDL.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "constants.h"

#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a > b) ? a : b)
#define DIST_3D(a, b) (sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2)))
#define DIST_2D(a, b) (sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2)))
#define DOT(a, b) (a.x * b.x + a.y * b.y + a.z * b.z)

#endif