#pragma once
#include <stddef.h>
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

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
    char* unk0;
    void* unk4;
} func_800FD0E0_t;

typedef struct {
    u_short unk0;
    char unk2;
    char unk3;
} func_800FD17C_t;

void func_800FA448(void);
void func_800FA8A0(int arg0);
void func_800FA810(int arg0);
void func_800FA8E0(int);
int vs_mainmenu_ready(void);
void func_800FA92C(int arg0, int arg1);
void func_800FAAC8(int);
void func_800FAEBC(int);
void func_800FBB8C(int arg0);
void func_800FBBD4(int);
void func_800FBD0C(int arg0, int arg1, int arg2, int arg3);
void func_800FBD28(int, int, int, int);
void func_800FBD80(int);
void func_800FBEA4(int);
void func_800FC208(int, int, int, int);
void func_800FC268(int);
void func_800FC85C(u_short*, char**, int*, D_800F4E8C_t*);
void func_800FCCE8(void*, char**, int*, D_800F4E8C_t*);
void func_800FCECC(void*, char**, int*, D_800F4E8C_t*);
void func_800FD084(int* arg0, char** arg1, int* arg2, D_800F4E8C_t* arg3);
void func_800FD0E0(func_800FD17C_t* arg0, func_800FD0E0_t* arg1, int* arg2, void* arg3);
void func_800FD220();
void func_8010044C(u_int*);

extern char D_80102140[];
extern char (*D_8010229C)[24];
extern D_8010245C_t* D_8010245C;
extern short D_801024A8[];
extern char D_801024B9;
extern short D_801024C0[];
extern short D_80102508;
extern u_short* D_80102540;
extern char D_80102544;
extern char D_80102545;
extern char D_80102578;
