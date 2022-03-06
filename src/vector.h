#ifndef VECTOR_H
#define VECTOR_H

#include "utilities.h"
#include "vertex.h"

typedef struct Vector
{
    double x;
    double y;
    double z;
} Vector;

Vector getVector(Vertex a, Vertex b);

#endif