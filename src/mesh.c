#include "mesh.h"

void drawMesh(SDL_Renderer* renderer, Mesh* mesh, Camera camera){
    for (size_t i = 0; i < mesh->length; i++)
    {
        drawTriangle(renderer, mesh->faces[mesh->length - 1 - i], camera);
    }
}