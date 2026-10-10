#pragma once
#include <stddef.h>
#include <libgpu.h>

typedef struct {
    char x;
    char y;
    char w;
    char h;
    u_short tpage;
    u_short clut;
} _texture_t;

extern _texture_t _disMap[];

static void _renderTextureFadeInTint(int, int, int, CVECTOR[]);
static void _renderTexturePopIn(int, int, int, CVECTOR[]);
static void _renderTextureWipe(int, int, int, CVECTOR[], int);
