#include "utilities.h"

#include "vertex.h"
#include "triangle.h"
#include "transform.h"
#include "camera.h"
#include "pixel.h"

Camera cam = {0, 0, -100};

void drawAxis(SDL_Renderer* renderer, Camera cam);

int compareTriangles (const void* first, const void* second) 
{
    Triangle f = *((Triangle*)first);
    Triangle s = *((Triangle*)second);
    if (DIST(getAverage(f), cam) > DIST(getAverage(s), cam)) return 1;
    if (DIST(getAverage(f), cam) < DIST(getAverage(s), cam)) return -1;
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
                
                Triangle tri1 = {a, b, c, magentaColor()};
                Triangle tri2 = {b, c, d, magentaColor()};
                Triangle tri3 = {e, f, g, yellowColor()};
                Triangle tri4 = {f, g, h, yellowColor()};
                Triangle tri5 = {a, b, e, cyanColor()};
                Triangle tri6 = {b, e, f, cyanColor()};
                Triangle tri7 = {c, d, g, whiteColor()};
                Triangle tri8 = {d, g, h, whiteColor()};
                mesh[0] = tri1;
                mesh[1] = tri2;
                mesh[2] = tri3;
                mesh[3] = tri4;
                mesh[4] = tri5;
                mesh[5] = tri6;
                mesh[6] = tri7;
                mesh[7] = tri8;
                
                qsort(mesh, 8, sizeof(Triangle), compareTriangles);
                for (size_t i = 0; i < 8; i++)
                {
                    drawTriangle(renderer, mesh[7-i], cam, &screen);
                }

                rotate(&a, M_PI / 10000, M_PI / 10000, 0);
                rotate(&b, M_PI / 10000, M_PI / 10000, 0);
                rotate(&c, M_PI / 10000, M_PI / 10000, 0);
                rotate(&d, M_PI / 10000, M_PI / 10000, 0);
                rotate(&e, M_PI / 10000, M_PI / 10000, 0);
                rotate(&f, M_PI / 10000, M_PI / 10000, 0);
                rotate(&g, M_PI / 10000, M_PI / 10000, 0);
                rotate(&h, M_PI / 10000, M_PI / 10000, 0);

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
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
                Vertex x1_1 = {-200, 0, 0};
                Vertex x2_1 = {200, 0, 0};
                SDL_Point x1 = get2DCoordinates(x1_1, cam);
                SDL_Point x2 = get2DCoordinates(x2_1, cam);
                SDL_RenderDrawLine(renderer, x1.x, x1.y, x2.x, x2.y);

                SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                Vertex y1_1 = {0, -200, 0};
                Vertex y2_1 = {0, 200, 0};
                SDL_Point y1 = get2DCoordinates(y1_1, cam);
                SDL_Point y2 = get2DCoordinates(y2_1, cam);
                SDL_RenderDrawLine(renderer, y1.x, y1.y, y2.x, y2.y);

                SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
                Vertex z1_1 = {0, 0, -200};
                Vertex z2_1 = {0, 0, 200};
                SDL_Point z1 = get2DCoordinates(z1_1, cam);
                SDL_Point z2 = get2DCoordinates(z2_1, cam);
                SDL_RenderDrawLine(renderer, z1.x, z1.y, z2.x, z2.y);
}


/*
gcc .\src\main.c .\src\vertex.c .\src\triangle.c .\src\constants.c .\src\transform.c .\src\camera.c .\src\pixel.c src/color.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
bin/prog.exe
*/