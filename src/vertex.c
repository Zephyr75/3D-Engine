#include "vertex.h"

#define ABS(a) (a > 0 ? a : -a)

SDL_Point get2DCoordinates(Vertex vertex, Camera camera){
    float z0 = camToScreen();
    double x1 = (vertex.x * z0 / (z0 + ABS(vertex.z - camera.z))) + RESOLUTION_X/2;
    double y1 = (vertex.y * z0 / (z0 + ABS(vertex.z - camera.z))) + RESOLUTION_Y/2;
    SDL_Point result = {x1, y1};
    return result;
}