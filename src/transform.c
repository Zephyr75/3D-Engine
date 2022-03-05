#include "transform.h"
#include <math.h>

enum Axis
{
    X,
    Y,
    Z
};

void multiplyByRotationMatrix(Vertex *vertex, double angle, enum Axis axis)
{
    double oldX;
    double oldY;
    double oldZ;
    switch (axis)
    {
    case X:
        oldY = vertex->y;
        oldZ = vertex->z;
        vertex->y = oldY * cos(angle) - oldZ * sin(angle);
        vertex->z = oldY * sin(angle) + oldZ * cos(angle);
        break;
    case Y:
        oldX = vertex->x;
        oldZ = vertex->z;
        vertex->x = oldX * cos(angle) - oldZ * sin(angle);
        vertex->z = oldX * sin(angle) + oldZ * cos(angle);
        break;
    default:
        oldX = vertex->x;
        oldY = vertex->y;
        vertex->x = oldX * cos(angle) - oldY * sin(angle);
        vertex->y = oldX * sin(angle) + oldY * cos(angle);
        break;
        break;
    }
}

void rotate(Vertex *vertex, double x, double y, double z)
{
    multiplyByRotationMatrix(vertex, x, X);
    multiplyByRotationMatrix(vertex, y, Y);
    multiplyByRotationMatrix(vertex, z, Z);
}