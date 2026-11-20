#pragma once
#include "entity.h"
#include <sys/types.h>
#include <libgte.h>

void func_8007ACB0(void);
/** Frame rates, as the number of vblanks (display refreshes) each frame lasts. */
typedef enum {
    frameRateFull = 2, // 30 frames per second, the normal rate
    frameRateHalf = 4, // 15 frames per second
} FrameRate;

int setFrameRate(FrameRate rate);
void setFramebufferEffect(int);
void vs_battle_setFramebufferEffectSpin(int angle);
void vs_battle_setFramebufferEffectScale(VECTOR* scale);
void vs_battle_setFramebufferEffectTint(CVECTOR* tint);
void vs_battle_setFramebufferEffectOffset(VECTOR* offset);
void vs_battle_setFramebufferEffectBlendMode(int blendMode);
void vs_battle_setFramebufferEffectDepth(u_int depth);
void vs_battle_setFramebufferEffectUsePreviousFrame(int usePreviousFrame);
int func_8007DFF0(u_int, u_int, int);
int func_8007E0A8(u_int, u_int, int);

typedef struct {
    void* unk0;
    void* unk4;
    char unk8[0x78F8];
} func_8009C378_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    char unk10;
    char unk11;
} D_800F4590_t;

extern D_800F4590_t* D_800F4590[];
extern int D_800F4594;
extern char D_800F49DC;
void func_8009C378(func_8009C378_t*, func_8009C378_t*);

void func_800B28A8(D_800F4538_t*, MATRIX*, int);
