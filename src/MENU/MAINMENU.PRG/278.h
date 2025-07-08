#pragma once
#include <stddef.h>
#include "../../SLUS_010.40/main.h"

typedef struct {
    u_short containerData[0x1C00];
    char unk3800[0x100];
    char unk3900[0x300];
} containerData_t;

typedef struct {
    char unk0[15][256];
    D_800619D8_t unkF00;
    containerData_t unkFB0;
    char unk4BB0[0x7800];
    u_short unkC3B0[0x40];
    containerData_t unkC430;
    signed char unk10030[0x4700];
} D_8010245C_t;

void func_800FA448();
void func_800FA8E0(int);
int func_800FA9D0();
void func_800FAEBC(int);
void func_800FBBD4(int);
void func_800FBD80(int);
void func_800FBEA4(int);
void func_800FC268(int);
void func_8010044C(u_int*);

extern D_8010245C_t* D_8010245C;
extern char D_80102578;
