#include "light.h"
#include "color.h"


#define DIST_LIGHT(a, b) (1 / (1 + 3 * sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2))))

void computeLight(Light light, Mesh* mesh){
    for (size_t i = 0; i < mesh->verticesCount; i++)
    {
        
        
        mesh->vertices[i].color.r += light.color.r * light.intensity * DIST_LIGHT(light, mesh->vertices[i]);
        mesh->vertices[i].color.g += light.color.g * light.intensity * DIST_LIGHT(light, mesh->vertices[i]);
        mesh->vertices[i].color.b += light.color.b * light.intensity * DIST_LIGHT(light, mesh->vertices[i]);
        
        mesh->vertices[i].color.r = MAX(0, MIN(255, mesh->vertices[i].color.r));
        mesh->vertices[i].color.g = MAX(0, MIN(255, mesh->vertices[i].color.g));
        mesh->vertices[i].color.b = MAX(0, MIN(255, mesh->vertices[i].color.b));
        
        

        //printf("r: %u, g:%u, b: %u\n", mesh->triangles[i].first->color.r, mesh->triangles[i].first->color.g, mesh->triangles[i].first->color.b);
    }
}

//MAX(0, MIN(255, 