#include "vector.h"

Vector getVector(Vertex a, Vertex b){
    Vector result;
    result.x = b.x - a.x;
    result.y = b.y - a.y;
    result.z = b.z - a.z;
    return result;
}