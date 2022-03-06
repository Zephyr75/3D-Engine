#include "light.h"
#include "color.h"

void computeLight(Light light, Triangle* mesh){
    for (size_t i = 0; i < 8; i++)
    {
        printf("---------------------\n");
        printf("dist: %f\n", DIST(light, getAverage(mesh[i])));
        printf("up: %f\n", ABS(100 - DIST(light, getAverage(mesh[i]))));
        printf("r: %u, g:%u, b: %u\n", mesh[i].color.r, mesh[i].color.g, mesh[i].color.b);
    
        mesh[i].color.r = MAX(0, MIN(255, mesh[i].baseColor.r + light.color.r * ABS(120 - DIST(light, getAverage(mesh[i]))) / 100 ));
        mesh[i].color.g = MAX(0, MIN(255, mesh[i].baseColor.g + light.color.g * ABS(120 - DIST(light, getAverage(mesh[i]))) / 100 ));
        mesh[i].color.b = MAX(0, MIN(255, mesh[i].baseColor.b + light.color.b * ABS(120 - DIST(light, getAverage(mesh[i]))) / 100 ));
        
        printf("r: %u, g:%u, b: %u\n", mesh[i].color.r, mesh[i].color.g, mesh[i].color.b);
    }
    
}