#include "color.h"

SDL_Color whiteColor(){
    SDL_Color result = {255, 255, 255, 255};
    return result;
}

SDL_Color blackColor(){
    SDL_Color result = {0, 0, 0, 255};
    return result;
}

SDL_Color redColor(){
    SDL_Color result = {255, 0, 0, 255};
    return result;
}

SDL_Color greenColor(){
    SDL_Color result = {0, 255, 0, 255};
    return result;
}

SDL_Color blueColor()
{
    SDL_Color result = {0, 0, 255, 255};
    return result;
}

SDL_Color yellowColor(){
    SDL_Color result = {255, 255, 0, 255};
    return result;
}

SDL_Color cyanColor(){
    SDL_Color result = {0, 255, 255, 255};
    return result;
}

SDL_Color magentaColor(){
    SDL_Color result = {255, 0, 255, 255};
    return result;
}