#include "triangle.h"

#define LOW(y) function((double) y, points[0], points[1])
#define HIGH(y) function((double) y, points[1], points[2])
#define FULL(y) function((double) y, points[0], points[2])

double function(double y, SDL_Point first, SDL_Point second)
{
    double fX = (double) first.x;
    double fY = (double) first.y;
    double sX = (double) second.x;
    double sY = (double) second.y;
    return fX + (sX - fX) * ABS((fY - y)/(fY - sY));
}

int compare (const void* first, const void* second) 
{
    SDL_Point f = *((SDL_Point*)first);
    SDL_Point s = *((SDL_Point*)second);
    if (f.y > s.y) return 1;
    if (f.y < s.y) return -1;
    return 0;
}

void drawTriangle(SDL_Renderer* renderer, Triangle triangle, Camera camera, Screen* screen){
    SDL_Point* points = calloc(3, sizeof(SDL_Point));
    points[0] = get2DCoordinates(triangle.first, camera);
    points[1] = get2DCoordinates(triangle.second, camera);
    points[2] = get2DCoordinates(triangle.third, camera);

    qsort(points, 3, sizeof(SDL_Point), compare);

    int half, full;

    SDL_SetRenderDrawColor(renderer, triangle.color.r, triangle.color.g, triangle.color.b, triangle.color.a);

    for (size_t i = points[0].y; i < points[1].y; i++)
    {
        half = LOW(i);
        full = FULL(i);
        SDL_RenderDrawLine(renderer, half, i, full, i);
    }
    for (size_t i = points[1].y; i < points[2].y; i++)
    {
        half = HIGH(i);
        full = FULL(i);
        SDL_RenderDrawLine(renderer, half, i, full, i);
    }
    /*SDL_RenderDrawPoint(renderer, points[0].x, points[0].y);
    SDL_RenderDrawPoint(renderer, points[1].x, points[1].y);
    SDL_RenderDrawPoint(renderer, points[2].x, points[2].y);*/
    /*SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[1].x, points[1].y);
    SDL_RenderDrawLine(renderer, points[2].x, points[2].y, points[1].x, points[1].y);
    SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[2].x, points[2].y);*/
    
    free(points);
}

Vertex getAverage(Triangle triangle){
    Vertex result;
    result.x = (triangle.first.x + triangle.second.x + triangle.third.x) / 3;
    result.y = (triangle.first.y + triangle.second.y + triangle.third.y) / 3;
    result.z = (triangle.first.z + triangle.second.z + triangle.third.z) / 3;
    return result;
}