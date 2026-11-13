#pragma once
#include "entity.h"
#include "actorPosition.h"
#include <libgte.h>

typedef struct {
    u_char unk0[0x1800];
    MATRIX bones[42];
    VECTOR boneScale[41];
    int unk1FD0[3];
    int unk1FDC;
    u_short unk1FE0;
} D_800F2458_t;

typedef struct {
    u_char unk0[0x34];
    u_short tpage;
    u_short clut;
    u_short unk38;
    u_short unk3A;
    u_short unk3C;
    u_char unk3E[0xE];
    SVECTOR position;
    SVECTOR offset;
    MATRIX* parent;
    int unk60;
    MATRIX matrix;
    SVECTOR rotation;
    VECTOR scale;
    D_800F4538_unk68* model;
} D_1F80035C_t;

typedef struct {
    short tpage;
    short clut0;
    short clut1;
    u_char refCount;
} TexInfo;

extern WepModelOffsets* vs_battle_commonWepBuffs[];
extern TexInfo D_800F46A8[];
extern TexInfo vs_battle_wepTextures[20];
extern char D_800E8FC0;
extern void* D_800F4768;
extern void* D_800F4930;
void func_8009FB64(VECTOR*);
