#include "utilities.h"

#include "vertex.h"
#include "triangle.h"
#include "transform.h"
#include "camera.h"
#include "color.h"
#include "light.h"
#include "input.h"
#include "bitmap_library.h"

Camera cam = {0, 0, -100};

void drawAxis(SDL_Renderer* renderer, Camera cam);
void drawText(SDL_Renderer* renderer);

int compareTriangles (const void* first, const void* second) 
{
    Triangle f = *((Triangle*)first);
    Triangle s = *((Triangle*)second);
    if (DIST_3D(getAverage(f), cam) > DIST_3D(getAverage(s), cam)) return 1;
    if (DIST_3D(getAverage(f), cam) < DIST_3D(getAverage(s), cam)) return -1;
    return 0;
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(RESOLUTION_X, RESOLUTION_Y, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;
            
            Vertex ver_a = {-50, -50, 50};
            Vertex ver_b = {-50, 50, 50};
            Vertex ver_c = {50, -50, 50};
            Vertex ver_d = {50, 50, 50};
            Vertex ver_e = {-50, -50, -50};
            Vertex ver_f = {-50, 50, -50};
            Vertex ver_g = {50, -50, -50};
            Vertex ver_h = {50, 50, -50};
            Triangle tri1 = {&ver_a, &ver_b, &ver_c, redColor(), redColor()};
            Triangle tri2 = {&ver_b, &ver_c, &ver_d, redColor(), redColor()};
            Triangle tri3 = {&ver_e, &ver_f, &ver_g, redColor(), redColor()};
            Triangle tri4 = {&ver_f, &ver_g, &ver_h, redColor(), redColor()};
            Triangle tri5 = {&ver_a, &ver_b, &ver_e, redColor(), redColor()};
            Triangle tri6 = {&ver_b, &ver_e, &ver_f, redColor(), redColor()};
            Triangle tri7 = {&ver_c, &ver_d, &ver_g, redColor(), redColor()};
            Triangle tri8 = {&ver_d, &ver_g, &ver_h, redColor(), redColor()};
            Mesh* mesh;
            mesh->triangles = calloc(8, sizeof(Triangle));
            mesh->triangles[0] = tri1;
            mesh->triangles[1] = tri2;
            mesh->triangles[2] = tri3;
            mesh->triangles[3] = tri4;
            mesh->triangles[4] = tri5;
            mesh->triangles[5] = tri6;
            mesh->triangles[6] = tri7;
            mesh->triangles[7] = tri8;
            mesh->trianglesCount = 8;
            Mesh* mesh2 = readObj("resources/suzanne.obj");

            Light light = {-50, 0, -100, 50, whiteColor()};
            Light light2 = {100, 0, -50, 30, whiteColor()};
            //SDL_Surface* surface = IMG_Load("resources/brick.jpg");

            /*BMP* bmp = bopen("resources/image.bmp");
            unsigned int width, height;
            unsigned char r, g, b;
            width = get_width(bmp);
            height = get_height(bmp);*/

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 50, 50, 50, SDL_ALPHA_OPAQUE);

                SDL_RenderClear(renderer);

                SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


                SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
                
                clearMesh(mesh);
                clearMesh(mesh2);


                //get_pixel_rgb(bmp, 50, 50, &r, &g, &b);
                
                /*
                qsort(mesh->triangles, mesh->trianglesCount, sizeof(Triangle), compareTriangles);
                //computeLight(light, mesh);
                //computeLight(light2, mesh);
                drawMesh(renderer, mesh, cam);
                */
               
                qsort(mesh2->triangles, mesh2->trianglesCount, sizeof(Triangle), compareTriangles);
                /*for (size_t i = 0; i < 50; i++)
                {
                    mesh2->vertices[i].baseColor.r = 0;
                    mesh2->vertices[i].baseColor.g = 0;
                    mesh2->vertices[i].baseColor.b = 255;
                }*/
                
                
                computeLight(light, mesh2);
                computeLight(light2, mesh2);
                drawMesh(renderer, mesh2, cam);
                

                /*                
                rotate(&a, M_PI / 1000, M_PI / 1000, 0);
                rotate(&b, M_PI / 1000, M_PI / 1000, 0);
                rotate(&c, M_PI / 1000, M_PI / 1000, 0);
                rotate(&d, M_PI / 1000, M_PI / 1000, 0);
                rotate(&e, M_PI / 1000, M_PI / 1000, 0);
                rotate(&f, M_PI / 1000, M_PI / 1000, 0);
                rotate(&g, M_PI / 1000, M_PI / 1000, 0);
                rotate(&h, M_PI / 1000, M_PI / 1000, 0);
                */

                drawAxis(renderer, cam);

                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }

                
            }
            //bclose(bmp);
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
                Vertex x1_1 = {-300, 0, 0};
                Vertex x2_1 = {300, 0, 0};
                SDL_Point x1 = get2DCoordinates(x1_1, cam);
                SDL_Point x2 = get2DCoordinates(x2_1, cam);
                SDL_RenderDrawLine(renderer, x1.x, x1.y, x2.x, x2.y);

                SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                Vertex y1_1 = {0, -300, 0};
                Vertex y2_1 = {0, 300, 0};
                SDL_Point y1 = get2DCoordinates(y1_1, cam);
                SDL_Point y2 = get2DCoordinates(y2_1, cam);
                SDL_RenderDrawLine(renderer, y1.x, y1.y, y2.x, y2.y);

                SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
                Vertex z1_1 = {0, 0, -300};
                Vertex z2_1 = {0, 0, 300};
                SDL_Point z1 = get2DCoordinates(z1_1, cam);
                SDL_Point z2 = get2DCoordinates(z2_1, cam);
                SDL_RenderDrawLine(renderer, z1.x, z1.y, z2.x, z2.y);
}

// void drawText(SDL_Renderer* renderer){
// TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
// SDL_Color White = {255, 255, 255};

// SDL_Surface* surfaceMessage =
//     TTF_RenderText_Solid(Sans, "put your text here", White); 

// SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

// SDL_Rect Message_rect;
// Message_rect.x = 0;
// Message_rect.y = 0;
// Message_rect.w = 100;
// Message_rect.h = 100;

// SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

// SDL_FreeSurface(surfaceMessage);
// SDL_DestroyTexture(Message);
// }


/*
gcc .\src\main.c .\src\vertex.c .\src\triangle.c .\src\constants.c .\src\transform.c .\src\camera.c src/color.c .\src\vector.c .\src\light.c .\src\input.c .\src\mesh.c .\src\bitmap_library.c  -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -g
bin/prog.exe

gdb bin/prog.exe
*/