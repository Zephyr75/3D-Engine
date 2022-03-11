#include "input.h"

char* getVertex(char* full);

Mesh* readObj(char* fileName){
    FILE* objFile;
    objFile = fopen(fileName, "r");
    double x, y, z;
    int first, second, third;
    char line[255];
    
    int nbrVertices = 0;
    int nbrFaces = 0;
    Vertex* vertices = malloc(sizeof(Vertex));
    Triangle* triangles = malloc(sizeof(Triangle));

    while(fgets(line, 255, objFile) != NULL){
        char *token;
        token = strtok(line, " ");
        SDL_bool isVertex = (strcmp(token, "v") == 0);
        SDL_bool isFace = (strcmp(token, "f") == 0);
        Vertex vertex;
        Triangle triangle;
        int i = 0;
        while( token != NULL ) 
        {
            if (isVertex) {
                if (i == 1) x = strtod(token, NULL);
                if (i == 2) y = strtod(token, NULL);
                if (i == 3) z = strtod(token, NULL);
            }
            if (isFace) {
                char* index = getVertex(token);
                if (i == 1) first = atoi(index);
                if (i == 2) second = atoi(index);
                if (i == 3) third = atoi(index);
                printf("%d\n", atoi(index));
            }
            token = strtok(NULL, " ");
            i++;
        }
        if (isVertex){
            nbrVertices++;
            vertices = realloc(vertices, nbrVertices * sizeof(Vertex));
            vertex.x = x;
            vertex.y = y;
            vertex.z = z;
            vertices[nbrVertices - 1] = vertex;
        }
        if (isFace){
            nbrFaces++;
            triangles = realloc(triangles, nbrFaces * sizeof(Triangle));
            triangle.first = &vertices[first - 1];
            triangle.second = &vertices[second - 1];
            triangle.third = &vertices[third - 1];
            triangles[nbrFaces - 1] = triangle;
        }
    }

    Mesh* result = malloc(sizeof(Mesh));
    result->faces = triangles;
    result->length = nbrFaces;
    return result;

}

char* getVertex(char* full){
    char* result = malloc(1);
    for (size_t i = 0; i < sizeof(full); i++)
    {
        result = realloc(result, i + 1);
        if (strcmp(&full[i], "/") == 0) break;
        result[i] = full[i];
    }
    return result;
}