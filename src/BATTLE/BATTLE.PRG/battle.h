#pragma once

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
void func_8008B430(char*, int);
void func_8008EB30(int*);
u_int* func_8008EB24();
void func_8008AB68();
void func_800A0768(int, char*);
void func_800A1108(int, char*);
void vs_battle_exec();

extern u_short D_800F18E8;
extern int D_800F19D0[];
extern D_800F19FC_t* D_800F19FC;
extern D_80061068_t D_800F1AB0;