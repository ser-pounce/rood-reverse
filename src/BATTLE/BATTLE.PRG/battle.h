#pragma once

typedef struct {
    unsigned short unk0;
    unsigned short unk2;
    unsigned short unk4;
    unsigned short unk6;
    unsigned short unk8[4];
    unsigned short unk10[102];
} D_800F19FC_t3;

typedef struct {
    unsigned short unk0[460];
    D_800F19FC_t3 unk398[6];
    unsigned short unk8C0[68];
    int unk948;
    char unk94C[8];
    unsigned short unk954;
} D_800F19FC_t2;

typedef struct {
    int unk0[15];
    D_800F19FC_t2* unk38;
} D_800F19FC_t;

struct D_80061068_t;

void func_8008B430(char*, int);
void func_8008EB30(int*);
unsigned int* func_8008EB24();
void func_800A0768(int, char*);

extern unsigned short D_800F18E8;
extern int D_800F19D0[];
extern D_800F19FC_t* D_800F19FC;
extern struct D_80061068_t D_800F1AB0;