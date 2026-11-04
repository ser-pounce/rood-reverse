#pragma once
#include <sys/types.h>

typedef struct {
    int unk0;
    int unk4;
    char unk8;
    char unk9;
} vs_main_sfxContext;

int TeardownSound(void);
int InitSound(void);
int Sound_BindAkaoSfxBlob(void* arg0);
int func_80011EBC(u_int);
int func_80011F08(void);
int func_80011F90(void);
u_int Sound_StartFieldMusic(void*);
void Sound_StopMusicById(u_int);
void Sound_PushMusicState(void);
int func_80012024(void);
u_int Sound_StartMasterAndMusicVolumeFade(void*, u_int, int);
u_int func_800120E8(void*);
int Sound_PlaySfx(u_long, int, int, int);
int Sound_PlaySfxFromPointer(void*, int, int, int);
void Sound_EvictSfx(u_long, int);
int func_80012358(int);
int func_800123C8(vs_main_sfxContext*);
void Sound_SetSpeakerMode(int);
void Sound_SetMusicJumpThreshold(void*);
void Sound_FadeSfxVolumeMod(int, int, int, int);
void Sound_FadeSfxPanMod(int, int, int, int);
void Sound_FadeSfxPitchMod(int, int, int, int);
void Sound_FadeMasterVolumeByMusicId(u_long, int, int);
void Sound_SetCdVolume(int);
void Sound_FadeCdVolume(int, int);
void Sound_FadeTempoScale(int, int);
int Sound_FadeMasterPitchScale(int, int);
void Sound_StopMusic(void);
void Sound_StopSfx(void);
void func_80012BB8(void*, int);
int IsSpuTransferring(void);
int func_80012EBC(void);
int func_80013188(void*, int);
int func_800131DC(void*, int, int);
int Sound_SetCdMixVolume(u_int);
void func_800132C4(void*, int, int);
void Sound_StopCutsceneStream(void);
void Sound_FadeOutCutscene(int, int);
