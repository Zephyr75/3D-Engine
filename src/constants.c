#include "constants.h"

const float FOV = 3.14/2;
const int RESOLUTION_X = 500;
const int RESOLUTION_Y = 500;
double camToScreen(){
    return 200; //(1000 / 2) / tan(FOV/2);
}