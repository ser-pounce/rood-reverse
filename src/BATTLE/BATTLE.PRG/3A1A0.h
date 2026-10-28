#pragma once
#include <sys/types.h>
#include <libgte.h>
#include "entity.h"
#include "func_8006EBF8_t.h"

typedef struct {
    char unk0_0;
    char unk0_8;
    char unk0_16;
    u_int unk0_24 : 8;
} func_80089888_t;

// The 0xE8-byte SHP header that _parseShp copies to an actor's texMapOverlays
typedef struct {
    texMapOverlay_t texMapOverlays[8];
    D_800F4538_unk614 unk20[2];
    D_800F4538_unk61C unk28[4];
    u_char unk48[0x28];
    u_int btSeqLbas[12];
    u_short btSeqSizes[12];
    u_int spSeqLbas[4];
    int unkC8[4];
    u_short spSeqSizes[4];
    int unkE0[2];
} shpHeader_t;

typedef struct {
    int unk0;
    u_char excluded[17];
    u_char pad15[3];
    D_800F4538_t* unk18;
    short unk1C[8];
    u_char blocked[8];
    u_char attributes[8];
    u_char centerAttribute;
    u_char pad3D[3];
    int unk40;
} D_1F8003BC_t;

void func_800A2C48(D_800F4538_t* arg0);
void func_800A36E0(int, int, func_8006EBF8_t*);
int func_800A3DB4(int x, int z, int minimumHeight);
void func_800A41D0(D_800F4538_t* actor, int mode);
int func_800A4494(int, SVECTOR*);
void func_800A48CC(int, int, int);
void func_800A4D8C(void);
void func_800A30A0(int, func_80089888_t*, int, int);
void func_800A35A8(void);
int func_800A3500(int, int);
D_800F4538_t* func_800A3C00(D_800F45E0_t* arg0, u_int arg1);
void func_800A4828(int, MATRIX*);
void func_800A525C(D_800F4538_t* arg0);
int func_800A6EE8(SVECTOR* position, int dx, int dz, int mode);
void func_800A70DC(D_800F4538_t* actor, int diagonal);
int func_800A3760(int, int, int);
int func_800A38E0(int);
int func_800A3E6C(int);
int func_800A47C4(void);
void func_800A4E68(int);
