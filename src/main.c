#include "SDL.h"
#include <math.h>
#include <stdio.h>

#include "vertex.h"
#include "triangle.h"
#include "constants.h"
#include "transform.h"
#include "camera.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(RESOLUTION_X, RESOLUTION_Y, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;
            Camera cam = {0, 0, -100};
            Vertex a = {-100, -100, 5};
            Vertex b = {-100, 100, 5};
            Vertex c = {100, -100, 10};
            Vertex d = {100, 100, 10};

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
                
                /*Vertex a = {0, 0, 5};
                Vertex b = {0, 100, 5};
                Vertex c = {100, 100, 5};
                Vertex d = {100, 0, 5};
                Vertex e = {0, 0, 10};
                Vertex f = {0, 100, 10};
                Vertex g = {100, 100, 10};
                Vertex h = {100, 0, 10};

                Triangle tri1 = {a, b, d};
                Triangle tri2 = {b, c, d};
                Triangle tri3 = {e, f, h};
                Triangle tri4 = {f, g, h};*/

                //drawTriangle(renderer, tri1);
                //drawTriangle(renderer, tri2);
                /*drawTriangle(renderer, tri3);
                drawTriangle(renderer, tri4);*/
                
                /*rotate(&c, M_PI / 10000, 0, 0);
                rotate(&a, M_PI / 10000, 0, 0);
                rotate(&b, M_PI / 10000, 0, 0);
                rotate(&d, M_PI / 10000, 0, 0);*/

                rotate(&c, 0, M_PI / 10000, 0);
                rotate(&a, 0, M_PI / 10000, 0);
                rotate(&b, 0, M_PI / 10000, 0);
                rotate(&d, 0, M_PI / 10000, 0);

                /*rotate(&c, 0, 0, M_PI / 10000);
                rotate(&a, 0, 0, M_PI / 10000);
                rotate(&b, 0, 0, M_PI / 10000);
                rotate(&d, 0, 0, M_PI / 10000);*/
                
                Triangle tri1 = {a, b, c};
                Triangle tri2 = {b, c, d};
                drawTriangle(renderer, tri1, cam);
                drawTriangle(renderer, tri2, cam);


                /*SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
                Vertex x1_1 = {-100, 0, 0};
                Vertex x2_1 = {100, 0, 0};
                SDL_Point x1 = get2DCoordinates(x1_1);
                SDL_Point x2 = get2DCoordinates(x2_1);
                SDL_RenderDrawLine(renderer, x1.x, x1.y, x2.x, x2.y);

                SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
                Vertex y1_1 = {0, -100, 0};
                Vertex y2_1 = {0, 100, 0};
                SDL_Point y1 = get2DCoordinates(y1_1);
                SDL_Point y2 = get2DCoordinates(y2_1);
                SDL_RenderDrawLine(renderer, y1.x, y1.y, y2.x, y2.y);

                SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
                Vertex z1_1 = {0, 0, -100};
                Vertex z2_1 = {0, 0, 100};
                SDL_Point z1 = get2DCoordinates(z1_1);
                SDL_Point z2 = get2DCoordinates(z2_1);
                SDL_RenderDrawLine(renderer, z1.x, z1.y, z2.x, z2.y);*/

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

//gcc .\src\main.c .\src\vertex.c .\src\triangle.c .\src\constants.c .\src\transform.c .\src\camera.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
//bin/prog.exe