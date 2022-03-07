#include "light.h"
#include "color.h"


#define DIST_LIGHT(a, b) (sqrt(pow((a.x - b->x), 2) + pow((a.y - b->y), 2) + pow((a.z - b->z), 2)))

void computeLight(Light light, Triangle* mesh){
    for (size_t i = 0; i < 8; i++)
    {
        /*printf("---------------------\n");
        printf("dist: %f\n", DIST_3D(light, getAverage(mesh[i])));
        printf("up: %f\n", ABS(100 - DIST_3D(light, getAverage(mesh[i]))));
        printf("r: %u, g:%u, b: %u\n", mesh[i].color.r, mesh[i].color.g, mesh[i].color.b);*/
    
        mesh[i].first->color.r = MAX(0, MIN(255, mesh[i].first->baseColor.r + light.color.r * ABS(120 - DIST_LIGHT(light, mesh[i].first)) / 100));
        mesh[i].first->color.g = MAX(0, MIN(255, mesh[i].first->baseColor.g + light.color.g * ABS(120 - DIST_LIGHT(light, mesh[i].first)) / 100));
        mesh[i].first->color.b = MAX(0, MIN(255, mesh[i].first->baseColor.b + light.color.b * ABS(120 - DIST_LIGHT(light, mesh[i].first)) / 100));
        mesh[i].second->color.r = MAX(0, MIN(255, mesh[i].second->baseColor.r + light.color.r * ABS(120 - DIST_LIGHT(light, mesh[i].second)) / 100));
        mesh[i].second->color.g = MAX(0, MIN(255, mesh[i].second->baseColor.g + light.color.g * ABS(120 - DIST_LIGHT(light, mesh[i].second)) / 100));
        mesh[i].second->color.b = MAX(0, MIN(255, mesh[i].second->baseColor.b + light.color.b * ABS(120 - DIST_LIGHT(light, mesh[i].second)) / 100));
        mesh[i].third->color.r = MAX(0, MIN(255, mesh[i].third->baseColor.r + light.color.r * ABS(120 - DIST_LIGHT(light, mesh[i].third)) / 100));
        mesh[i].third->color.g = MAX(0, MIN(255, mesh[i].third->baseColor.g + light.color.g * ABS(120 - DIST_LIGHT(light, mesh[i].third)) / 100));
        mesh[i].third->color.b = MAX(0, MIN(255, mesh[i].third->baseColor.b + light.color.b * ABS(120 - DIST_LIGHT(light, mesh[i].third)) / 100));
        
        //printf("r: %u, g:%u, b: %u\n", mesh[i].color.r, mesh[i].color.g, mesh[i].color.b);
    }
}

//MAX(0, MIN(255, 