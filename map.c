#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE_X 32
#define MAP_SIZE_Y 32

void map(char fname[], int m[][MAP_SIZE_X], int t[][MAP_SIZE_X+1])
{
    FILE * fptr;
 
    char map_field;

    fptr = fopen(fname, "r"); 
    
    map_field = fgetc(fptr);

    for (int i = 0; i < MAP_SIZE_Y; i++)
        for (int j = 0; j < MAP_SIZE_X+1; j++)
        {
            t[i][j] = atoi(&map_field); 
            map_field = fgetc(fptr);
        }

    for (int i = 0; i < MAP_SIZE_Y; i++)
        for (int j = 0; j < MAP_SIZE_X; j++)
            m[i][j] = t[i][j];

    fclose (fptr);
}