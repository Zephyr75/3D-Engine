#include "vertex.h"
#include "constants.h"

SDL_Point get2DCoordinates(Vertex vertex){
    float z0 = 2;
    double x1 = (vertex.x * z0 / (z0 + vertex.z)) + 500/2;
    double y1 = (vertex.y * z0 / (z0 + vertex.z)) + 500/2;
    SDL_Point result = {x1, y1};
    return result;
}