#include "mesh.h"

void drawMesh(SDL_Renderer* renderer, Mesh* mesh, Camera camera){
    for (size_t i = 0; i < mesh->trianglesCount; i++)
    {
        drawTriangle(renderer, mesh->triangles[mesh->trianglesCount - 1 - i], camera);
    }
}


void clearMesh(Mesh* mesh){
    for (size_t i = 0; i < mesh->verticesCount; i++)
    {
        mesh->vertices[i].color.r = mesh->vertices[i].baseColor.r;
        mesh->vertices[i].color.g = mesh->vertices[i].baseColor.g;
        mesh->vertices[i].color.b = mesh->vertices[i].baseColor.b;
    }
}