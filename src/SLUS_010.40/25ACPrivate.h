#pragma once
#include "common.h"
#include "25AC.h"

int TeardownSound(void);
VS_HIDDEN(TeardownSound);

int InitSound(void);
VS_HIDDEN(InitSound);

int Sound_BindAkaoSfxBlob(void* arg0);
VS_HIDDEN(Sound_BindAkaoSfxBlob);

int Sound_GetMusicVolumeById(u_int);
VS_HIDDEN(Sound_GetMusicVolumeById);

int Sound_GetLoadedMusicBankIds(void);
VS_HIDDEN(Sound_GetLoadedMusicBankIds);

int Sound_GetMusicPosition(void);
VS_HIDDEN(Sound_GetMusicPosition);

u_int Sound_StartFieldMusic(void*);
VS_HIDDEN(Sound_StartFieldMusic);

void Sound_StopMusicById(u_int);
VS_HIDDEN(Sound_StopMusicById);

void Sound_PushMusicState(void);
VS_HIDDEN(Sound_PushMusicState);

int Sound_ClearSuspendedMusic(void);
VS_HIDDEN(Sound_ClearSuspendedMusic);

u_int Sound_StartMasterAndMusicVolumeFade(void*, u_int, int);
VS_HIDDEN(Sound_StartMasterAndMusicVolumeFade);

u_int Sound_QueueMusic(void*);
VS_HIDDEN(Sound_QueueMusic);

int Sound_PlaySfx(u_long, int, int, int);
VS_HIDDEN(Sound_PlaySfx);

int Sound_PlaySfxFromPointer(void*, int, int, int);
VS_HIDDEN(Sound_PlaySfxFromPointer);

void Sound_EvictSfx(u_long, int);
VS_HIDDEN(Sound_EvictSfx);

int Sound_GetPlayingSfxByGroup(int);
VS_HIDDEN(Sound_GetPlayingSfxByGroup);

int Sound_SfxHasVoiceFlag(u_long);
VS_HIDDEN(Sound_SfxHasVoiceFlag);

void Sound_SetSpeakerMode(int);
VS_HIDDEN(Sound_SetSpeakerMode);

void Sound_SetMusicJumpThreshold(int);
VS_HIDDEN(Sound_SetMusicJumpThreshold);

void Sound_FadeSfxVolumeMod(u_long, int, int, int);
VS_HIDDEN(Sound_FadeSfxVolumeMod);

void Sound_FadeSfxPanMod(u_long, int, int, int);
VS_HIDDEN(Sound_FadeSfxPanMod);

void Sound_FadeSfxPitchMod(u_long, int, int, int);
VS_HIDDEN(Sound_FadeSfxPitchMod);

void Sound_FadeMasterVolumeByMusicId(u_long, int, int);
VS_HIDDEN(Sound_FadeMasterVolumeByMusicId);

void Sound_SetCdVolume(int);
VS_HIDDEN(Sound_SetCdVolume);

void Sound_FadeCdVolume(int, int);
VS_HIDDEN(Sound_FadeCdVolume);

void Sound_FadeTempoScale(int, int);
VS_HIDDEN(Sound_FadeTempoScale);

int Sound_FadeMasterPitchScale(int, int);
VS_HIDDEN(Sound_FadeMasterPitchScale);

void Sound_StopMusic(void);
VS_HIDDEN(Sound_StopMusic);

void Sound_StopSfx(void);
VS_HIDDEN(Sound_StopSfx);

void Sound_LoadAkaoBankBlocking(void*, int);
VS_HIDDEN(Sound_LoadAkaoBankBlocking);

int IsSpuTransferring(void);
VS_HIDDEN(IsSpuTransferring);

int Sound_ResetMusicBankIds(void);
VS_HIDDEN(Sound_ResetMusicBankIds);

int Sound_LoadMusicBank(void*, int);
VS_HIDDEN(Sound_LoadMusicBank);

int Sound_LoadSfxBank(void*, int, int);
VS_HIDDEN(Sound_LoadSfxBank);

void Sound_StartCutsceneStream(void*, int, int);
VS_HIDDEN(Sound_StartCutsceneStream);

void Sound_StopCutsceneStream(void);
VS_HIDDEN(Sound_StopCutsceneStream);

void Sound_FadeOutCutscene(int, int);
VS_HIDDEN(Sound_FadeOutCutscene);
