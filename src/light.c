#include "light.h"
#include "color.h"


#define DIST_LIGHT(a, b) (sqrt(pow((a.x - b->x), 2) + pow((a.y - b->y), 2) + pow((a.z - b->z), 2)))

void computeLight(Light light, Mesh* mesh){
    for (size_t i = 0; i < 8; i++)
    {
        /*printf("---------------------\n");
        printf("dist: %f\n", DIST_3D(light, getAverage(mesh->faces[i])));
        printf("up: %f\n", ABS(100 - DIST_3D(light, getAverage(mesh->faces[i]))));
        printf("r: %u, g:%u, b: %u\n", mesh->faces[i].color.r, mesh->faces[i].color.g, mesh->faces[i].color.b);*/
    
        mesh->faces[i].first->color.r = MAX(0, MIN(255, mesh->faces[i].first->baseColor.r + light.color.r * ABS(130 - DIST_LIGHT(light, mesh->faces[i].first)) / 100));
        mesh->faces[i].first->color.g = MAX(0, MIN(255, mesh->faces[i].first->baseColor.g + light.color.g * ABS(130 - DIST_LIGHT(light, mesh->faces[i].first)) / 100));
        mesh->faces[i].first->color.b = MAX(0, MIN(255, mesh->faces[i].first->baseColor.b + light.color.b * ABS(130 - DIST_LIGHT(light, mesh->faces[i].first)) / 100));
        mesh->faces[i].second->color.r = MAX(0, MIN(255, mesh->faces[i].second->baseColor.r + light.color.r * ABS(130 - DIST_LIGHT(light, mesh->faces[i].second)) / 100));
        mesh->faces[i].second->color.g = MAX(0, MIN(255, mesh->faces[i].second->baseColor.g + light.color.g * ABS(130 - DIST_LIGHT(light, mesh->faces[i].second)) / 100));
        mesh->faces[i].second->color.b = MAX(0, MIN(255, mesh->faces[i].second->baseColor.b + light.color.b * ABS(130 - DIST_LIGHT(light, mesh->faces[i].second)) / 100));
        mesh->faces[i].third->color.r = MAX(0, MIN(255, mesh->faces[i].third->baseColor.r + light.color.r * ABS(130 - DIST_LIGHT(light, mesh->faces[i].third)) / 100));
        mesh->faces[i].third->color.g = MAX(0, MIN(255, mesh->faces[i].third->baseColor.g + light.color.g * ABS(130 - DIST_LIGHT(light, mesh->faces[i].third)) / 100));
        mesh->faces[i].third->color.b = MAX(0, MIN(255, mesh->faces[i].third->baseColor.b + light.color.b * ABS(130 - DIST_LIGHT(light, mesh->faces[i].third)) / 100));
        
        //printf("r: %u, g:%u, b: %u\n", mesh->faces[i].color.r, mesh->faces[i].color.g, mesh->faces[i].color.b);
    }
}

//MAX(0, MIN(255, 