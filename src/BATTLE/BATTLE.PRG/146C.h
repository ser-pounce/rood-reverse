#pragma once
#include "common.h"
#include "actor.h"
#include "charInit.h"
#include "hitEntity.h"
#include "objectData.h"
#include "src/SLUS_010.40/zoneState.h"
#include "src/SLUS_010.40/memory.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    SVECTOR position;
    short unk8;
    short unkA;
    char unkC;
    char unkD;
    char unkE;
    char unkF;
} D_800F1DD4_t;

typedef struct {
    SVECTOR unk0;
    union {
        char u8[2];
        u_short u16;
    } unk8;
    u_char unkA;
    u_char unkB;
    u_short unkC;
    u_char unkE;
    u_char displayTextLen;
    short unk10;
    short unk12;
    signed char displayText[4];
} D_800F1BAC_t;

void func_800760CC(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
void func_80076F24(int id, vs_CharInitData* arg1, int arg2, int arg3, int arg4, int arg5);
vs_Actor* func_800774FC(int arg0, int arg1, int bladeWepId, int bladeMaterial,
    int shieldWepId, int shieldMaterial, vs_battle_tilePosition* arg6, int arg7);
void func_80077EC4(void);
void func_8007D3F8(void);
void func_8007DF48(void);
void func_8008B6B4(void);
void func_8008E88C(void);
extern u_short D_800F1BA4;
extern u_short* D_800F1BA8;
extern short D_800F1BB6;
extern DVECTOR* D_800F1CBC;
extern vs_Warp D_800F1CC8;
extern short D_800F1CD4;
extern char D_800F1CD6;
extern VECTOR D_800F1CE0[2];
extern DR_STP D_800F1970[];
extern DR_STP D_800F1988[];
extern int D_800F190C;
extern int D_800F1968;

extern D_800F1BAC_t (*D_800F1BAC)[32];
