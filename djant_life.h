#ifndef DJANT_LIFE_H
#define DJANT_LIFE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define STREAM 0

typedef struct {
    int width;
    int height;
    int iterator;
    char    **life;
    char    *commands;
} t_data;

char    **copy_grid(char **source, int w, int h);

#endif