#pragma once
#include <libgte.h>

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    VECTOR unk14;
} func_800CFE98_t;

int func_800A152C(int, int, int);
int func_800A1648(int, int, int);
void func_800A1720(int, int, func_800CFE98_t*, void*);
void func_800A1AF8(int, int, SVECTOR*, int);
