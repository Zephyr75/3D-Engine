#include "triangle.h"

#define LOW(y) function((double) y, points[0].point, points[1].point)
#define HIGH(y) function((double) y, points[1].point, points[2].point)
#define FULL(y) function((double) y, points[0].point, points[2].point)

typedef struct Temp
{
    SDL_Point point;
    Vertex vertex;
} Temp;

double function(double y, SDL_Point first, SDL_Point second)
{
    double fX = (double) first.x;
    double fY = (double) first.y;
    double sX = (double) second.x;
    double sY = (double) second.y;
    return fX + (sX - fX) * fabs((fY - y)/(fY - sY));
}

int compare (const void* first, const void* second) 
{
    SDL_Point f = ((Temp*)first)->point;
    SDL_Point s = ((Temp*)second)->point;
    if (f.y > s.y) return 1;
    if (f.y < s.y) return -1;
    return 0;
}

void drawTriangle(SDL_Renderer* renderer, Triangle triangle, Camera camera){
    Temp* points = calloc(3, sizeof(Temp));
    points[0].point = get2DCoordinates(*triangle.first, camera);
    points[0].vertex = *triangle.first;
    points[1].point = get2DCoordinates(*triangle.second, camera);
    points[1].vertex = *triangle.second;
    points[2].point = get2DCoordinates(*triangle.third, camera);
    points[2].vertex = *triangle.third;

    qsort(points, 3, sizeof(Temp), compare);

    int half, full, min, max;
    double weight_0, weight_1, weight_2;
    SDL_Point current, p0, p1, p2;
    p0 = points[0].point;
    p1 = points[1].point;
    p2 = points[2].point;
    int r, g, b;

    for (size_t j = p0.y; j < p1.y; j++)
    {
        half = LOW(j);
        full = FULL(j);
        min = MIN(half, full);
        max = MAX(half, full);
        for (size_t i = min; i <= max; i++)
        {
            current.x = i;
            current.y = j;
            weight_0 = (((double) p1.y - (double) p2.y) * ((double) current.x - (double) p2.x) + ((double) p2.x - (double) p1.x) * ((double) current.y - (double) p2.y)) /
                       (((double) p1.y - (double) p2.y) * ((double) p0.x - (double) p2.x) + ((double) p2.x - (double) p1.x) * ((double) p0.y - (double) p2.y));
            weight_1 = (((double) p2.y - (double) p0.y) * ((double) current.x - (double) p2.x) + ((double) p0.x - (double) p2.x) * ((double) current.y - (double) p2.y)) /
                       (((double) p1.y - (double) p2.y) * ((double) p0.x - (double) p2.x) + ((double) p2.x - (double) p1.x) * ((double) p0.y - (double) p2.y));
            weight_2 = 1 - weight_0 - weight_1;
            r = (int) (points[0].vertex.color.r * weight_0
                     + points[1].vertex.color.r * weight_1
                     + points[2].vertex.color.r * weight_2);
            g = (int) (points[0].vertex.color.g * weight_0
                     + points[1].vertex.color.g * weight_1
                     + points[2].vertex.color.g * weight_2);
            b = (int) (points[0].vertex.color.b * weight_0
                     + points[1].vertex.color.b * weight_1
                     + points[2].vertex.color.b * weight_2);
            r = MAX(0, MIN(255, r));
            g = MAX(0, MIN(255, g));
            b = MAX(0, MIN(255, b));
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
    for (size_t j = p1.y; j < p2.y; j++)
    {
        half = HIGH(j);
        full = FULL(j);
        min = MIN(half, full);
        max = MAX(half, full);
        for (size_t i = min; i <= max; i++)
        {
            current.x = i;
            current.y = j;
            weight_0 = (((double) p1.y - (double) p2.y) * ((double) current.x - (double) p2.x) + ((double) p2.x - (double) p1.x) * ((double) current.y - (double) p2.y)) /
                       (((double) p1.y - (double) p2.y) * ((double) p0.x - (double) p2.x) + ((double) p2.x - (double) p1.x) * ((double) p0.y - (double) p2.y));
            weight_1 = (((double) p2.y - (double) p0.y) * ((double) current.x - (double) p2.x) + ((double) p0.x - (double) p2.x) * ((double) current.y - (double) p2.y)) /
                       (((double) p1.y - (double) p2.y) * ((double) p0.x - (double) p2.x) + ((double) p2.x - (double) p1.x) * ((double) p0.y - (double) p2.y));
            weight_2 = 1 - weight_0 - weight_1;
            r = (int) (points[0].vertex.color.r * weight_0
                     + points[1].vertex.color.r * weight_1
                     + points[2].vertex.color.r * weight_2);
            g = (int) (points[0].vertex.color.g * weight_0
                     + points[1].vertex.color.g * weight_1
                     + points[2].vertex.color.g * weight_2);
            b = (int) (points[0].vertex.color.b * weight_0
                     + points[1].vertex.color.b * weight_1
                     + points[2].vertex.color.b * weight_2);
            r = MAX(0, MIN(255, r));
            g = MAX(0, MIN(255, g));
            b = MAX(0, MIN(255, b));
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
    
    //resetColor(triangle.first);
    //resetColor(triangle.second);
    //resetColor(triangle.third);
    
    free(points);
}

void drawWireframeTriangle(SDL_Renderer* renderer, Triangle triangle, Camera camera){
    SDL_Point* points = calloc(3, sizeof(SDL_Point));
    points[0] = get2DCoordinates(*triangle.first, camera);
    points[1] = get2DCoordinates(*triangle.second, camera);
    points[2] = get2DCoordinates(*triangle.third, camera);
    
    SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[1].x, points[1].y);
    SDL_RenderDrawLine(renderer, points[2].x, points[2].y, points[1].x, points[1].y);
    SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[2].x, points[2].y);
    free(points);
}

Vertex getAverage(Triangle triangle){
    Vertex result;
    result.x = (triangle.first->x + triangle.second->x + triangle.third->x) / 3;
    result.y = (triangle.first->y + triangle.second->y + triangle.third->y) / 3;
    result.z = (triangle.first->z + triangle.second->z + triangle.third->z) / 3;
    return result;
}