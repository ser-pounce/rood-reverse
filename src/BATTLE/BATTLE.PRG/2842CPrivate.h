#pragma once
#include "common.h"
#include "2842C.h"

short clamp(short arg0, int arg1, int arg2);
VS_HIDDEN(clamp);

void setParticleEffect(int arg0);
VS_HIDDEN(setParticleEffect);

void func_80090EEC(void);
VS_HIDDEN(func_80090EEC);

void setParticleEffectDrift(int);
VS_HIDDEN(setParticleEffectDrift);

void setParticleEffectIntensity(int);
VS_HIDDEN(setParticleEffectIntensity);

void setParticleEffectDirection(int, int);
VS_HIDDEN(setParticleEffectDirection);

void func_80091378(void);
VS_HIDDEN(func_80091378);

int setParticleEffectSound(int);
VS_HIDDEN(setParticleEffectSound);

void setBackgroundOffset(int, int);
VS_HIDDEN(setBackgroundOffset);

void func_8009147C(BackgroundLayout*, int, int, int);
VS_HIDDEN(func_8009147C);

void func_800918E8(int);
VS_HIDDEN(func_800918E8);

void* func_8009195C(int arg0);
VS_HIDDEN(func_8009195C);

int showGeometryObject(int);
VS_HIDDEN(showGeometryObject);

int hideGeometryObject(int);
VS_HIDDEN(hideGeometryObject);

int swapGeometryFlags(int, int);
VS_HIDDEN(swapGeometryFlags);

int adjustGeometryObjectDepth(int, int);
VS_HIDDEN(adjustGeometryObjectDepth);

int func_80091AC0(int arg0);
VS_HIDDEN(func_80091AC0);

void func_80091B04(void);
VS_HIDDEN(func_80091B04);

void func_80092548(void);
VS_HIDDEN(func_80092548);

int startRoomTask(int);
VS_HIDDEN(startRoomTask);

int func_80092A18(void);
VS_HIDDEN(func_80092A18);

int toggleRoomTaskPaused(int);
VS_HIDDEN(toggleRoomTaskPaused);

int isRoomTaskRunning(int);
VS_HIDDEN(isRoomTaskRunning);

void finishRoomTask(int);
VS_HIDDEN(finishRoomTask);

void func_80093824(int arg0);
VS_HIDDEN(func_80093824);

void func_800938AC(int);
VS_HIDDEN(func_800938AC);

void func_80093914(int arg0);
VS_HIDDEN(func_80093914);

void func_80093A14(void);
VS_HIDDEN(func_80093A14);

void func_80093A70(void);
VS_HIDDEN(func_80093A70);

void func_80093AB4(void);
VS_HIDDEN(func_80093AB4);

int func_80093B04(SVECTOR* arg0);
VS_HIDDEN(func_80093B04);

int func_80093B68(int arg0, int arg1, u_int arg2, int arg3);
VS_HIDDEN(func_80093B68);

int func_80093F24(int arg0);
VS_HIDDEN(func_80093F24);

int func_80093FEC(int arg0, int arg1, int arg2, int arg3);
VS_HIDDEN(func_80093FEC);

void func_80095B70(int);
VS_HIDDEN(func_80095B70);

void func_80095B7C(int arg0, int arg1);
VS_HIDDEN(func_80095B7C);

void func_8009627C(void);
VS_HIDDEN(func_8009627C);

int func_80096768(int arg0, int arg1, int arg2);
VS_HIDDEN(func_80096768);

void func_80096FF0(int arg0);
VS_HIDDEN(func_80096FF0);

void func_800971D4(void);
VS_HIDDEN(func_800971D4);

void func_8009722C(void);
VS_HIDDEN(func_8009722C);

void func_800941FC(void);
VS_HIDDEN(func_800941FC);

int renderBattleAbilityTimingResult(int arg0);
VS_HIDDEN(renderBattleAbilityTimingResult);
