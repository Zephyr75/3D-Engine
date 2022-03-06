#include "light.h"
#include "color.h"

void computeLight(Light light, Triangle* mesh){
    for (size_t i = 0; i < 8; i++)
    {
        printf("current: %f, x:%f, dist: %f\n", mesh[i].first.x, getAverage(mesh[i]).x, DIST(light, getAverage(mesh[i])));
    
        mesh[i].color.r += light.color.r * ABS(100 - DIST(light, getAverage(mesh[i]))) / 100;
        mesh[i].color.g += light.color.g * ABS(100 - DIST(light, getAverage(mesh[i]))) / 100;
        mesh[i].color.b += light.color.b * ABS(100 - DIST(light, getAverage(mesh[i]))) / 100;
    }
    
}