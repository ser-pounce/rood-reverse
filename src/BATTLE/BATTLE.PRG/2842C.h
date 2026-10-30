#pragma once
#include "objectData.h"
#include <stddef.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    RECT uv;
    CVECTOR colors[4];
} vs_battle_backgroundTile;

typedef struct {
    int width;
    int height;
    int unk8;
    vs_battle_backgroundTile tiles[0];
} vs_battle_backgroundLayout;

short vs_battle_clamp(short arg0, int arg1, int arg2);
void func_80090C2C(int arg0);
void func_80090EEC(void);
void func_80091314(int);
void func_80091320(int);
void func_8009134C(int, int);
void func_80091378(void);
int func_800913BC(int);
void func_80091468(int, int);
void func_8009147C(vs_battle_backgroundLayout*, int, int, int);
void func_800918E8(int);
void* func_8009195C(int arg0);
int func_80091998(int);
int func_800919D8(int);
int func_80091A1C(int, int);
int func_80091A78(int, int);
int func_80091AC0(int arg0);
void func_80091B04(void);
void func_80092548(void);
int func_8009291C(int);
int func_80092A18(void);
int func_800936F8(int);
int func_80093764(int);
void func_80093788(int);
void func_80093824(int arg0);
void func_800938AC(int);
void func_80093914(int arg0);
void func_80093A14(void);
void func_80093A70(void);
void func_80093AB4(void);
int func_80093B04(SVECTOR* arg0);
int func_80093B68(int arg0, int arg1, u_int arg2, int arg3);
int func_80093F24(int arg0);
int func_80093FEC(int arg0, int arg1, int arg2, int arg3);
void func_80095B70(int);
void func_80095B7C(int arg0, int arg1);
void func_8009627C(void);
int func_80096768(int arg0, int arg1, int arg2);
void func_80096FF0(int arg0);
void func_800971D4(void);
void func_8009722C(void);
void func_80098160(int);
void func_80098194(int);
void func_80098B38(int, int);
void func_800941FC(void);
int vs_battle_renderBattleAbilityTimingResult(int arg0);

extern vs_battle_objectData vs_battle_objectDataSlots[16];
