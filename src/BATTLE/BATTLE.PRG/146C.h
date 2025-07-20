#pragma once
#include "../../SLUS_010.40/D_80061068_t.h"

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    int unk4[9];
    u_int unk28;
    u_int unk2C[8];
    u_int unk4C;
    int unk50[14];
    int unk88;
    int unk8C[8];
    int unkAC;
    int unkB0[5];
} D_800F1BF8_t;

typedef struct {
    u_short unk0;
    u_short unk2;
    u_short unk4;
    u_short unk6;
    u_short unk8[4];
    u_short unk10[102];
} D_800F19FC_t3;

typedef struct {
    u_short unk0[460];
    D_800F19FC_t3 unk398[6];
    u_short unk8C0[68];
    int unk948;
    char unk94C[8];
    u_short unk954;
} D_800F19FC_t2;

typedef struct {
    int unk0[15];
    D_800F19FC_t2* unk38;
} D_800F19FC_t;

void func_80069FC4(int, int);
void func_8006B02C(void*, int);
void func_8006B110(int*, int);
void func_8006CE50();
int func_8007C874();
void func_8007DFF0(int, int, int);
void func_8007E0A8(int, int, int);
int func_8007E180(int arg0);
int func_8007E1C0(int arg0);
void func_8008AB68();
void func_8008A4DC(int arg0);
char func_8008A4FC();
int func_8008A5D0(int, int);
void func_8008B430(char*, int);
void func_8008B6B4();
int func_8008E5F0();
void func_8008E88C();
int* func_8008EB24();
void func_8008EB30(int*);
void func_800995B0();
int func_8009967C();
void vs_battle_exec();

extern u_short D_800F18E8;
extern int D_800F19D0[];
extern D_800F19FC_t* D_800F19FC;
extern D_80061068_t D_800F1AB0;
extern u_short D_800F1BA4;
extern short* D_800F1BA8;
extern void* D_800F1BAC;
extern short D_800F1BB6;
extern short D_800F1BBE;
extern int D_800F1BC0;
extern signed char D_800F1BC8[36];
extern signed char D_800F1BF0[8];
extern D_800F1BF8_t D_800F1BF8;
extern void* D_800F1CBC;
extern signed char D_800F1CC8[12];
extern short D_800F1CD4;
extern char D_800F1CD6;
extern int D_800F1CD8;
extern int D_800F1CE0[8];
