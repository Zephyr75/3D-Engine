#include "input.h"

static char** _strsplit( const char* s, const char* delim, size_t* nb );
char** strsplit( const char* s, const char* delim );

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
        //printf("%s\n", line);
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
                char** index = strsplit(token, "/");
                if (i == 1) first = atoi(index[0]);
                if (i == 2) second = atoi(index[0]);
                if (i == 3) third = atoi(index[0]);
                printf("%d\n", atoi(index[0]));
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

    /*for (size_t i = 0; i < nbrVertices; i++)
    {
        printf("------------------------\n");
        printf("first: %f, %f, %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
    }

    for (size_t i = 0; i < nbrFaces; i++)
    {
        printf("------------------------\n");
        printf("first: %f, %f, %f\n", triangles[i].first->x, triangles[i].first->y, triangles[i].first->z);
        printf("second: %f, %f, %f\n", triangles[i].second->x, triangles[i].second->y, triangles[i].second->z);
        printf("third: %f, %f, %f\n", triangles[i].third->x, triangles[i].third->y, triangles[i].third->z);
    }*/

    Mesh* result = malloc(sizeof(Mesh));
    result->faces = triangles;
    result->length = nbrFaces;
    return result;

}

static char** _strsplit( const char* s, const char* delim, size_t* nb ) {
	void* data;
	char* _s = ( char* )s;
	const char** ptrs;
	size_t
		ptrsSize,
		nbWords = 1,
		sLen = strlen( s ),
		delimLen = strlen( delim );

	while ( ( _s = strstr( _s, delim ) ) ) {
		_s += delimLen;
		++nbWords;
	}
	ptrsSize = ( nbWords + 1 ) * sizeof( char* );
	ptrs =
	data = malloc( ptrsSize + sLen + 1 );
	if ( data ) {
		*ptrs =
		_s = strcpy( ( ( char* )data ) + ptrsSize, s );
		if ( nbWords > 1 ) {
			while ( ( _s = strstr( _s, delim ) ) ) {
				*_s = '\0';
				_s += delimLen;
				*++ptrs = _s;
			}
		}
		*++ptrs = NULL;
	}
	if ( nb ) {
		*nb = data ? nbWords : 0;
	}
	return data;
}

char** strsplit( const char* s, const char* delim ) {
	return _strsplit( s, delim, NULL );
}