#include "input.h"

void readObj(char* fileName){
    /*FILE* objFile;
    objFile = fopen(fileName, "r");
    double x, y, z;
    char line[255];
    
    int nbrVertices = 0;
    int nbrFaces = 0;
    Vertex* vertices = calloc(1, sizeof(Vertex));
    Triangle* result = calloc(1, sizeof(Triangle));

    while(fgets(line, 255, objFile) != NULL){
        if (nbrVertices > 0) vertices = realloc(vertices, nbrVertices * sizeof(Triangle));
        char *token;
        token = strtok(line, " ");
        SDL_bool isVertex = (strcmp(token, "v") == 0);
        int i = 0;
        while( token != NULL ) 
        {
            if (isVertex) {
                if (i == 0) x = strtod(token, NULL);
                if (i == 1) y = strtod(token, NULL);
                if (i == 2) z = strtod(token, NULL);
            }
            token = strtok(NULL, " ");
        }
        if (isVertex){
            Vertex vertex = {x, y, z};
            vertices[nbrVertices] = vertex;
            nbrVertices++;
            printf("added a vertex\n");
        }
    }

    for (size_t i = 0; i < nbrVertices; i++)
    {
        printf("%d, %d, %d\n", vertices[i].x, vertices[i].y,  vertices[i].z);
    }*/
    

}