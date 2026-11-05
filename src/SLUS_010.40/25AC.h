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
int Sound_GetMusicVolumeById(u_int);
int Sound_GetLoadedMusicBankIds(void);
int Sound_GetMusicPosition(void);
u_int Sound_StartFieldMusic(void*);
void Sound_StopMusicById(u_int);
void Sound_PushMusicState(void);
int func_80012024(void);
u_int Sound_StartMasterAndMusicVolumeFade(void*, u_int, int);
u_int Sound_QueueMusic(void*);
int Sound_PlaySfx(u_long, int, int, int);
int Sound_PlaySfxFromPointer(void*, int, int, int);
void Sound_EvictSfx(u_long, int);
int Sound_GetPlayingSfxByGroup(int);
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
void Sound_LoadAkaoBankBlocking(void*, int);
int IsSpuTransferring(void);
int Sound_ResetMusicBankIds(void);
int Sound_LoadMusicBank(void*, int);
int Sound_LoadSfxBank(void*, int, int);
int Sound_SetCdMixVolume(u_int);
void Sound_StartCutsceneStream(void*, int, int);
void Sound_StopCutsceneStream(void);
void Sound_FadeOutCutscene(int, int);
