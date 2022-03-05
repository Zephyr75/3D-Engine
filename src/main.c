#include "SDL.h"
#include <math.h>
#include <stdio.h>

#include "vertex.h"
#include "triangle.h"
#include "constants.h"
#include "transform.h"
#include "camera.h"
#include "pixel.h"

Camera cam = {0, 0, -100};

void drawAxis(SDL_Renderer* renderer, Camera cam);

int compareTriangles (const void* first, const void* second) 
{
    Triangle f = *((Triangle*)first);
    Triangle s = *((Triangle*)second);
    /*printf("---------------------\n");
    printf("avgf: %f\n", DIST(getAverage(f), cam));
    printf("avgf: %f\n", DIST(getAverage(s), cam));*/
    if (DIST(getAverage(f), cam) > DIST(getAverage(s), cam)) {
        //printf("1\n");
        return 1;
    }
    if (DIST(getAverage(f), cam) < DIST(getAverage(s), cam)){
        //printf("-1\n");
        return -1;
    }
    
    //printf("0\n");
    return 0;
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(RESOLUTION_X, RESOLUTION_Y, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;
            
            Vertex a = {-50, -50, 50};
            Vertex b = {-50, 50, 50};
            Vertex c = {50, -50, 50};
            Vertex d = {50, 50, 50};
            Vertex e = {-50, -50, -50};
            Vertex f = {-50, 50, -50};
            Vertex g = {50, -50, -50};
            Vertex h = {50, 50, -50};
            Screen screen = calloc(RESOLUTION_Y * RESOLUTION_X, sizeof(Pixel));
            Triangle* mesh = calloc(8, sizeof(Triangle));

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
                
                Triangle tri1 = {a, b, c};
                Triangle tri2 = {b, c, d};
                Triangle tri3 = {e, f, g};
                Triangle tri4 = {f, g, h};
                Triangle tri5 = {a, b, e};
                Triangle tri6 = {b, e, f};
                Triangle tri7 = {c, d, g};
                Triangle tri8 = {d, g, h};
                mesh[0] = tri1;
                mesh[1] = tri2;
                mesh[2] = tri3;
                mesh[3] = tri4;
                mesh[4] = tri5;
                mesh[5] = tri6;
                mesh[6] = tri7;
                mesh[7] = tri8;

                printf("1111111111111\n");
                for (size_t i = 0; i < 8; i++)
                {
                    printf("avgf: %f\n", DIST(getAverage(mesh[i]), cam));
                    /*drawTriangle(renderer, mesh[i], cam, &screen);
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);*/
                }
                
                qsort(mesh, 8, sizeof(Triangle), compareTriangles);

                printf("222222222222222\n");
                for (size_t i = 0; i < 8; i++)
                {
                    printf("avgf: %f\n", DIST(getAverage(mesh[7-i]), cam));
                    drawTriangle(renderer, mesh[7-i], cam, &screen);
                    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
                }
                

                /*drawTriangle(renderer, tri1, cam, &screen);
                drawTriangle(renderer, tri2, cam, &screen);
                
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

                drawTriangle(renderer, tri3, cam, &screen);
                drawTriangle(renderer, tri4, cam, &screen);
                
                SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);

                drawTriangle(renderer, tri5, cam, &screen);
                drawTriangle(renderer, tri6, cam, &screen);

                SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);

                drawTriangle(renderer, tri7, cam, &screen);
                drawTriangle(renderer, tri8, cam, &screen);*/

                rotate(&b, 0, M_PI / 10000, 0);
                rotate(&a, 0, M_PI / 10000, 0);
                rotate(&c, 0, M_PI / 10000, 0);
                rotate(&d, 0, M_PI / 10000, 0);
                rotate(&e, 0, M_PI / 10000, 0);
                rotate(&f, 0, M_PI / 10000, 0);
                rotate(&g, 0, M_PI / 10000, 0);
                rotate(&h, 0, M_PI / 10000, 0);

                /*rotate(&c, 0, 0, M_PI / 10000);
                rotate(&a, 0, 0, M_PI / 10000);
                rotate(&b, 0, 0, M_PI / 10000);
                rotate(&d, 0, 0, M_PI / 10000);*/

                drawAxis(renderer, cam);

                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}

void drawAxis(SDL_Renderer* renderer, Camera cam){
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
                Vertex x1_1 = {-100, 0, 0};
                Vertex x2_1 = {100, 0, 0};
                SDL_Point x1 = get2DCoordinates(x1_1, cam);
                SDL_Point x2 = get2DCoordinates(x2_1, cam);
                SDL_RenderDrawLine(renderer, x1.x, x1.y, x2.x, x2.y);

                SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
                Vertex y1_1 = {0, -100, 0};
                Vertex y2_1 = {0, 100, 0};
                SDL_Point y1 = get2DCoordinates(y1_1, cam);
                SDL_Point y2 = get2DCoordinates(y2_1, cam);
                SDL_RenderDrawLine(renderer, y1.x, y1.y, y2.x, y2.y);

                SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
                Vertex z1_1 = {0, 0, -100};
                Vertex z2_1 = {0, 0, 100};
                SDL_Point z1 = get2DCoordinates(z1_1, cam);
                SDL_Point z2 = get2DCoordinates(z2_1, cam);
                SDL_RenderDrawLine(renderer, z1.x, z1.y, z2.x, z2.y);
}

//gcc .\src\main.c .\src\vertex.c .\src\triangle.c .\src\constants.c .\src\transform.c .\src\camera.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
//bin/prog.exe