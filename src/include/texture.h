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
} vs_Texture;

static void renderTextureFadeInTint(int, int, int, CVECTOR[]);
static void renderTexturePopIn(int, int, int, CVECTOR[]);
static void renderTextureWipe(int, int, int, CVECTOR[], int);
