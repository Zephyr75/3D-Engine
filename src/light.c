#include "light.h"
#include "color.h"

void computeLight(Light light, Mesh* mesh){
    for (size_t i = 0; i < mesh->verticesCount; i++)
    {  
        mesh->vertices[i].color.r += light.color.r * light.intensity / (1 + 3 * DIST_3D(light, mesh->vertices[i]));
        mesh->vertices[i].color.g += light.color.g * light.intensity / (1 + 3 * DIST_3D(light, mesh->vertices[i]));
        mesh->vertices[i].color.b += light.color.b * light.intensity / (1 + 3 * DIST_3D(light, mesh->vertices[i]));
        
        mesh->vertices[i].color.r = MAX(0, MIN(255, mesh->vertices[i].color.r));
        mesh->vertices[i].color.g = MAX(0, MIN(255, mesh->vertices[i].color.g));
        mesh->vertices[i].color.b = MAX(0, MIN(255, mesh->vertices[i].color.b));
    }
}