#pragma once
#include "cd.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    int currentMusicSlot;
    u_int currentMusicHandle;
    u_int unk8;
    void* currentMusicData;
    char musicIds[4];
    u_int musicHandleBySlot[4];
    void* musicData[4];
    vs_Main_CdQueueSlot* musicQueueSlot[4];
    u_int currentSfxId;
    char sfxIds[4];
    int* sfxData[3]; // bank: [0] = entry count, [1..] = byte offsets to each effect
    vs_Main_CdQueueSlot* sfxQueueSlot[3];
    void* unk64[3];
    UNUSED int* unused[3];
    int soundFileId;
    void* soundData;
    vs_Main_CdQueueSlot* soundQueueSlot;
} SoundData;

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern SoundData vs_main_soundData;
#endif

int vs_main_loadMusicSlot(int id, int targetSlot);
int vs_main_clearMusicLoadQueue(void);
int vs_main_loadAndWaitMusicSlot(int id, int targetSlot);
void vs_main_loadAndWaitSoundSlot(int id);
void vs_main_playSfx(int group, int id, int pan, int volume);
void vs_main_playSfxDefault(int group, int id);
void vs_main_stopMusic(void);
int vs_main_freeMusic(int slotId);
void vs_main_resetSound(void);
void vs_main_pushMusicState(void);
int vs_main_getMusicPosition(void);
void vs_main_setMusicJumpThreshold(int threshold);
int vs_main_stopMusicSlot(int slot);
int vs_main_queueMusicSlot(int slot);
int vs_main_playMusicSlotFadeIn(int slot, int volume, u_int duration);
int vs_main_playMusicSlot(int slot, int volume, int duration);
int vs_main_getMusicSlotVolume(int slot);
int vs_main_fadeMusicTempo(int slot, int tempo, int duration);
int vs_main_fadeMusicPitch(int slot, int pitch, int duration);
int vs_main_getMusicSlotVolume2(int slot);
void vs_main_stopAllSfx(void);
void vs_main_panSfx(int group, int id, SVECTOR* position);
int vs_main_computeSfxPan(int pan, int depth);
void vs_main_fadeSfxVolume(int group, int id, int volume, char duration);
void vs_main_fadeSfxPitch(int group, int id, int pitch, char duration);
void vs_main_fadeSfxPan(int group, int id, int pan, char duration);
int vs_main_setSfxSlot3Data(void* bank);
int vs_main_clearSfxSlot3(void);
void vs_main_playBankSfx(int group, u_int bank[], u_int index, int pan, int volume);
void vs_main_playBankSfxDefault(int group, int* bank, u_int index);
void vs_main_evictBankSfx(int group, int const* bank, int index);
void vs_main_fadeBankSfxVolume(
    int group, int const* bank, int index, int volume, int duration);
void vs_main_startCutsceneStreamDefault(int slot);
void vs_main_setMonoSound(int set);
int vs_main_setCutsceneStreamSlot3(void* stream);
int vs_main_clearCutsceneStreamSlot3(void);
void vs_main_loadSoundFile(int id);
int vs_main_fadeMusicVolume(int slot, int volume, int duration);
int vs_main_getCurrentMusicId(void);
void vs_main_evictSfx(int group, int id);
int vs_main_processSoundQueue(void);
int vs_main_setCurrentSfx(int slot);
int vs_main_freeSfx(u_int slot);
int vs_main_freeSfxQueueSlot(u_int slot);
int vs_main_clearMusicLoadSlot(u_int slot);
int vs_main_loadSfxSlot(int id, u_int slot);
