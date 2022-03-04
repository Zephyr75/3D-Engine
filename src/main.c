#include "SDL.h"
#include <math.h>
#include <stdio.h>

#include "vertex.h"
#include "triangle.h"
#include "constants.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(500, 500, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
                
                Vertex a = {-50, 0, 1};
                Vertex b = {50, -100, 1};
                Vertex c = {100, 100, 1};

                Triangle tri = {a, b, c};

                SDL_RenderDrawPoint(renderer, 50, 50);

                drawTriangle(renderer, tri);
                
                //printf("z0: %f\n", tan(FOV/2));
                //printf("z0: %.6f\n", camToScreen());
                

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

//gcc .\src\main.c .\src\vertex.c .\src\triangle.c .\src\constants.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
//bin/prog.exe