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

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
} D_8010229C_t;

typedef struct {
    D_8010229C_t* unk0;
    void* unk4;
} func_800FD0E0_t;

typedef struct {
    u_short unk0;
    char unk2;
    char unk3;
} func_800FD17C_t;

void func_800FA448();
void func_800FA8A0(int arg0);
void func_800FA8E0(int);
int vs_mainmenu_ready();
void func_800FA92C(int arg0, int arg1);
void func_800FAAC8(int);
void func_800FAEBC(int);
void func_800FBBD4(int);
void func_800FBD80(int);
void func_800FBEA4(int);
void func_800FC268(int);
void func_800FD0E0(func_800FD17C_t* arg0, func_800FD0E0_t* arg1, int* arg2, void* arg3);
void func_8010044C(u_int*);

extern D_8010245C_t* D_8010245C;
extern char D_80102578;
