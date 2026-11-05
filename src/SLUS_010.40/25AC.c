// Largely copied from
// https://github.com/jdperos/chrono-cross-decomp/blob/master/src/slps_023.64/system/sound.c

#include "common.h"
#include "25AC.h"
#include "hw.h"
#include "sound.h"
#include <kernel.h>
#include <libspu.h>
#include <libapi.h>
#include <libetc.h>
#include <libcd.h>

#define SPU_VOICE_INDEX_STRIDE                                                           \
    8 // u16s to skip per voice when indexing voice register arrays

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} D_80036770_t;

// From https://ff7-mods.github.io/ff7-flat-wiki/FF7/PSX/Sound/AKAO_sequence.html

typedef struct {
    char year_bcd;
    char month_bcd;
    char day_bcd;
    char hours_bcd;
    char minutes_bcd;
    char seconds_bcd;
} AkaoTimeStamp;

typedef struct {
    int magic;
    u_short id;
    u_short length;
    u_short reverb_type;
    AkaoTimeStamp timestamp;
} AkaoSeqHeader;

// Format used for EFFECT00.DAT:
// 384 sfx slots total
// AkaoSeqHeader (Magic string only, everything else is 0)
// Block 0: 84 pairs of u16 offsets into data block, 0xFFFF == no data
// Block 1: 384 u16 flags, one for each sfx, function TBD but only value seems to be 0xC8
// Block 2: Akao data indexed by block 0 offsets

typedef struct {
    int index;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
} func_800172D4_t;

typedef struct {
    void* unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
} D_800378C0_t;

typedef struct {
    int magic;
    int count;
    int flags;
    int unkC;
    int offsets[4];
} func_8001733C_t;

// Streaming state for Sound_StreamAkaoBankChunk (instrument bank uploaded in chunks)
typedef struct {
    int* pInstrumentInfoCursor; // next g_InstrumentInfo word to fill
    int SpuTransferStartAddr; // next SPU transfer address; 0 = start a new stream
    u_int SampleBytesRemaining;
    u_int InstrumentBytesRemaining;
} FSoundAkaoLoadState;

#define AKAO_MAGIC ('A' | ('K' << 8) | ('A' << 16) | ('O' << 24))

typedef void (*FSoundCommandHandler)(FSoundCommandParams*);

static int Sound_IsNotAkaoFile(int*);
int Sound_TryLoadInstrumentBank(void*, int);
int Sound_LoadInstrumentBank(void*, int, int, int);
void Sound_Setup(void);
static void Sound_Start(void);
static void SetVoiceKeyOff(u_int);
void Sound_EvictSfxVoice(int, int);
void func_8001653C(FSoundChannel*, FSoundCommandParams*, int, char*);
void Sound_PlaySfxProgram(FSoundCommandParams*, char*, char*, int);
int func_80016DA8(int);
u_int Sound_ExecuteSoundVm2Function(u_int);
long Sound_MainLoop(void);
static void Sound_Stop(void);
static void WriteSpu(char* data, u_int len);
static void WaitForSpuTransfer(void);
void Sound_CopyAndRelocateInstruments(FSoundInstrumentInfo* in_A,
    FSoundInstrumentInfo* in_B, int in_AddrOffset, int in_Count);
void Sound_ClearVoiceFromSfxState(FSoundChannel* arg0, int arg1);
void Sound_Cutscene_OnInitialTransferComplete(void);
void Sound_Cutscene_InitVoice(int, int, int, int);
void Sound_Cutscene_BeginPlayback(int, int, void (*)(void));
void Sound_Cutscene_LoadNextBuffer(int, int, int, void (*)(void));
void Sound_Cutscene_OnBufferAComplete(void);
void Sound_Cutscene_OnBufferBComplete(void);
void Sound_Cutscene_StopStream(void);
void Sound_LoadAkaoSequence(FAkaoSequence* in_Sequence);
void Sound_SetMusicSequence(FAkaoSequence* in_Sequence, int in_SwapWithSavedState);
void Sound_ReconcileSavedMusicVoices(void);
void Sound_BuildVoiceModeMask(int* out_VoiceMask, int in_SavedChannelMask,
    int in_ActiveChannelMask, int in_ExtraVoiceMask);
void memcpy32(void* in_Src, void* in_Dst, u_int in_Size);
void memswap32(void* in_A, void* in_B, u_int in_Size);
void Sound_UpdateCdVolume(void);
int func_8001A1F4(int, int);
int func_8001A22C(int, u_int);
void Sound_CopyInstrumentInfoToChannel(FSoundChannel*, FSoundInstrumentInfo*, int);
void Sound_ProcessAkaoVM(FSoundChannel*, int);
void Sound_SetReverbMode(int in_ReverbMode);

void func_80015220();

extern int g_Sound_EventDescriptor;
extern char _soundFlush[64];
extern short D_800358FE;
extern CdlATV g_Sound_CdlATV;
extern D_80036770_t D_80036770;
extern int D_800377E0[3];
extern u_int* g_Sound_Sfx_ProgramOffsets;
extern u_short* g_Sound_Sfx_MetadataTableA;
extern char* g_Sound_Sfx_ProgramData;
extern int D_800378A0;
extern D_800378C0_t g_Sound_Vm2Params;
extern int g_Sound_MutedMusicChannelMask;
extern char _spuMemInfo;
extern volatile int g_bSpuTransferring;
extern FSoundChannel g_SfxSoundChannels[12];
extern int D_80039AFC;
extern int D_80039B14;
extern int D_80039B64;
extern int g_Sound_CdVolumeFadeStep;
extern short g_Sound_CdVolumeFadeLength;
extern int g_CdVolume;
extern short D_800378E2;
extern char D_8002F66C[];
extern int D_800378D4;
extern char D_80039AF2;
extern int D_8002F548;
extern u_short D_8002F54C;
extern int D_8002F550[];
extern FSoundCommandHandler g_Sound_CommandHandlers[];
extern FSoundCommandParams D_80037788;
extern FSoundCommandParams g_Sound_CommandContext;
extern int D_80037898;
extern int D_8003789C;
extern int D_80039B00;
extern u_int D_8002F63C[];
extern int D_80039BCC;
extern FSoundAkaoLoadState g_Sound_AkaoLoadState;
extern int D_80037850[16];
extern u_char D_8002F5A0[];
extern u_char D_8002F600[];
extern FSoundCommandParams D_80037790;
extern FSoundCommandHandler D_800301E0[];

extern FSoundMusicContext* g_pActiveMusicContext;
extern FSoundSfxState g_Sound_SfxState;
extern FSoundGlobalFlags g_Sound_GlobalFlags;
extern FSpuVoiceInfo g_SpuVoiceInfo[VOICE_COUNT];
extern FSoundChannel g_ActiveMusicChannels[0x20];
extern FSoundMusicContext* g_pSuspendedMusicContext;
extern FSoundChannel* g_pSecondaryMusicChannels;
extern FSoundChannel* g_Sound_pMusicSoudChannels;
extern FSoundFadeTimer g_Sound_MasterFadeTimer;
extern FSoundCutsceneStreamState g_Sound_Cutscene_StreamState;
extern u_int g_Sound_ProgramCounter;
extern FSoundMusicContext* g_Sound_VoiceOwnerContexts[VOICE_COUNT];
#define SPU_PAN_TABLE_SIZE (0x100)
#define PAN_CENTER_INDEX (SPU_PAN_TABLE_SIZE / 2)
extern short g_Sound_StereoPanGainTableQ15[SPU_PAN_TABLE_SIZE];
extern short D_8002F89C;
extern FSoundMusicContext g_SuspendedMusicContext;
extern u_int g_Music_LoopCounter;
extern FSoundMusicContext g_PrimaryMusicContext;
extern FSoundChannel g_PushedMusicChannels[];
extern FSoundInstrumentInfo g_InstrumentInfo[256];
extern short* g_Sound_LfoTable[];
extern FSoundCommandParams g_Sound_CommandParams_Vm_FE08;
extern int g_Sound_MasterPitchScaleStep;
extern int g_Sound_TempoScaleStep;
extern short g_Sound_MasterPitchScaleStepsRemaining;
extern short g_Sound_TempoScaleStepsRemaining;
extern int g_Sound_MasterPitchScaleQ16_16;
extern int g_Sound_TempoScale;
extern int D_80039B48;
extern int g_Sound_LfoPhase;
extern FSoundVoiceModeFlags g_Sound_VoiceModeFlags;
extern int D_80037894;

int InitSound(void)
{
    Sound_Start();
    return 0;
}

int TeardownSound(void)
{
    Sound_Stop();
    return 0;
}

int Sound_BindAkaoSfxBlob(void* in_Blob)
{
    int notAkao = Sound_IsNotAkaoFile(in_Blob);

    in_Blob += sizeof(AkaoSeqHeader);

    if (notAkao == 0) {
        g_Sound_Sfx_ProgramOffsets = in_Blob;
        in_Blob += 0x600;
        g_Sound_Sfx_MetadataTableA = in_Blob;
        in_Blob += 0x300;
        g_Sound_Sfx_ProgramData = in_Blob;
    }
    return notAkao;
}

int func_80011E40(void)
{
    int var_v1 = g_pActiveMusicContext->ActiveChannelMask != 0;
    if (g_pSuspendedMusicContext != NULL) {
        if (g_pSuspendedMusicContext->ActiveChannelMask != 0) {
            var_v1 |= 2;
        }
    }
    if (D_80037788.Param1 != 0) {
        var_v1 |= 0x10;
    }
    if (g_Sound_SfxState.ActiveVoiceMask != 0) {
        var_v1 |= 0x100;
    }
    if (D_80039B14 != 0) {
        var_v1 |= 0x10000;
    }
    return var_v1;
}

int func_80011EBC(u_int arg0)
{
    FSoundMusicContext* var_v1 = g_pActiveMusicContext;
    int var_a1 = 0;

    if ((var_v1->MusicId == arg0)
        || ((var_v1 = g_pSuspendedMusicContext, (var_v1 != NULL))
            && (var_v1->MusicId == arg0))) {
        var_a1 = (var_v1->MasterVolume >> 0x10);
    }
    return var_a1;
}

int func_80011F08(void)
{
    return (u_short)D_80036770.unk0 | ((u_short)D_80036770.unk4 << 0x10);
}

int func_80011F24(int arg0)
{
    int var_a1 = 0;
    if (arg0 & 1) {
        var_a1 = g_pActiveMusicContext->MasterVolumeStepsRemaining;
    }
    if (arg0 & 2) {
        if (var_a1 < g_Sound_TempoScaleStepsRemaining) {
            var_a1 = g_Sound_TempoScaleStepsRemaining;
        }
    }
    if ((arg0 & 4) && (var_a1 < g_Sound_MasterPitchScaleStepsRemaining)) {
        var_a1 = g_Sound_MasterPitchScaleStepsRemaining;
    }
    return var_a1;
}

int func_80011F90(void)
{
    int upper = g_pActiveMusicContext->TimerUpperCurrent;
    int top = g_pActiveMusicContext->TimerTopCurrent;
    top = (top << 16) | (upper + 1);
    return top;
}

u_int Sound_StartFieldMusic(void* arg0)
{
    g_Sound_Vm2Params.unk0 = arg0;
    return Sound_ExecuteSoundVm2Function(0x10);
}

void Sound_StopMusicById(u_int arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    Sound_ExecuteSoundVm2Function(0x11);
}

void Sound_PushMusicState(void) { Sound_ExecuteSoundVm2Function(0x40); }

int func_80012024(void)
{
    D_800358FE = 0;
    return 0;
}

void Sound_SetMasterVolumeByMusicId(u_long, int);

u_int Sound_SetMusicLevelImmediate(void* arg0, int arg1)
{
    u_int temp_v0;

    g_Sound_Vm2Params.unk0 = arg0;
    temp_v0 = Sound_ExecuteSoundVm2Function(0x19);
    Sound_SetMasterVolumeByMusicId(temp_v0, arg1);
    return temp_v0;
}

u_int Sound_StartMasterAndMusicVolumeFade(void* arg0, u_int arg1, int arg2)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1;
    g_Sound_Vm2Params.unk8 = arg2 & 0x7F;
    return Sound_ExecuteSoundVm2Function(0x1A);
}

void Sound_StartFieldMusicLooped(void* arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1;
    Sound_ExecuteSoundVm2Function(0x12);
}

u_int func_800120E8(void* arg0)
{
    g_Sound_Vm2Params.unk0 = arg0;
    return Sound_ExecuteSoundVm2Function(0x14);
}

void* func_80012110(void* arg0, int arg1)
{
    u_long v0;
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1;
    Sound_ExecuteSoundVm2Function(0x16);
    v0 = g_Sound_Vm2Params.unk4 << 0x10;
    v0 += (u_long)g_Sound_Vm2Params.unk0;
    return (void*)v0;
}

void func_8001215C(void) { Sound_ExecuteSoundVm2Function(0x17); }

int Sound_PlaySfx(u_long arg0, int arg1, int arg2, int arg3)
{
    int temp_s0 = g_Sound_Sfx_ProgramOffsets[arg0 & 0x3FF];
    if (temp_s0 != -1) {
        g_Sound_Vm2Params.unk0 = (void*)(arg0 & 0x3FF);
        g_Sound_Vm2Params.unk4 = arg1 & 0xFFFFFF;
        g_Sound_Vm2Params.unk8 = arg2 & 0xFF;
        g_Sound_Vm2Params.unkC = arg3 & 0x7F;
        Sound_ExecuteSoundVm2Function(0x20);
    }
    return temp_s0;
}

int Sound_PlaySfxFromPointer(void* arg0, int arg1, int arg2, int arg3)
{
    void* var_v0;

    var_v0 = (void*)-1;
    if (Sound_IsNotAkaoFile(arg0) == 0) {
        g_Sound_Vm2Params.unk0 = arg0;
        g_Sound_Vm2Params.unk4 = (int)(arg1 & 0xFFFFFF);
        g_Sound_Vm2Params.unk8 = (int)(arg2 & 0xFF);
        g_Sound_Vm2Params.unkC = (int)(arg3 & 0x7F);
        Sound_ExecuteSoundVm2Function(0x24);
        var_v0 = arg0;
    }
    return (u_long)var_v0;
}

void Sound_EvictSfx(u_long arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFFFFFF;
    Sound_ExecuteSoundVm2Function(0x21);
}

void Sound_PlaySfxProtected(u_long arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)(arg0 & 0x3FF);
    Sound_ExecuteSoundVm2Function(0x30);
}

int Sound_GetAllSfxUnkFlags(void)
{
    FSoundChannel* var_a1;
    int var_a0;
    int var_v1;
    int mask = g_Sound_SfxState.ActiveVoiceMask;

    var_a0 = mask == 0;
    if (var_a0) {
        return 0;
    }

    var_a1 = g_SfxSoundChannels;
    var_a0 = 0;
    var_v1 = 0x1000;

    do {
        if (mask & var_v1) {
            var_a0 |= var_a1->unk_Flags;
        }
        var_v1 *= 2;
        ++var_a1;
    } while (var_v1 & 0xFFFFFF);

    return var_a0 & 0xFFFFFF;
}

int func_80012358(int arg0)
{
    FSoundChannel* var_a1;
    int var_v1;
    int a2;
    if ((arg0 == 0) || ((a2 = g_Sound_SfxState.ActiveVoiceMask) == 0)) {
        return 0;
    }
    for (var_a1 = g_SfxSoundChannels, var_v1 = 0x1000; var_v1 & 0xFFFFFF;
        var_v1 *= 2, ++var_a1) {
        if ((a2 & var_v1) && (arg0 == var_a1->unk_Flags)) {
            return var_a1->AkaoProgramIndex;
        }
    }

    return 0;
}

int func_800123C8(vs_main_sfxContext* arg0)
{
    int ret = 0;
    if ((long)arg0 >= 0x80000000) {
        ret = arg0->unk9 >> 7;
    } else if (g_Sound_Sfx_MetadataTableA[(long)arg0] & 0x8000) {
        ret = 1;
    }
    return ret;
}

void Sound_SetSpeakerMode(int arg0)
{
    if (arg0 == 1) {
        Sound_ExecuteSoundVm2Function(0x81);
    } else {
        Sound_ExecuteSoundVm2Function(0x80);
    }
}

void Sound_SetMutedMusicChannelMask(void* arg0)
{
    g_Sound_Vm2Params.unk0 = arg0;
    Sound_ExecuteSoundVm2Function(0x90);
}

void Sound_SetMusicJumpThreshold(void* arg0)
{
    g_Sound_Vm2Params.unk0 = arg0;
    Sound_ExecuteSoundVm2Function(0x92);
}

void Sound_SuspendChannelsByType(u_int arg0)
{
    switch (arg0) {
    case 1:
        Sound_ExecuteSoundVm2Function(0x9B);
        break;
    case 2:
        Sound_ExecuteSoundVm2Function(0x9D);
        break;
    case 3:
        Sound_ExecuteSoundVm2Function(0x9F);
        break;
    default:
        Sound_ExecuteSoundVm2Function(0x99);
        break;
    }
}

void Sound_RestoreChannelsByType(u_int arg0)
{
    switch (arg0) {
    case 1:
        Sound_ExecuteSoundVm2Function(0x9A);
        break;
    case 2:
        Sound_ExecuteSoundVm2Function(0x9C);
        break;
    case 3:
        Sound_ExecuteSoundVm2Function(0x9E);
        break;
    default:
        Sound_ExecuteSoundVm2Function(0x98);
        break;
    }
}

int func_80012568(int arg0)
{
    if (arg0 != 0) {
        g_Sound_GlobalFlags.MixBehavior |= 0x10;
    } else {
        g_Sound_GlobalFlags.MixBehavior &= ~0x10;
    }
    return 0;
}

void Sound_SetAllSfxVolumeMod(u_long arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)(arg0 & 0x7F);
    Sound_ExecuteSoundVm2Function(0xA8);
}

void Sound_FadeAllSfxVolumeMod(void* arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0x7F;
    Sound_ExecuteSoundVm2Function(0xA9);
}

void Sound_SetSfxVolumeMod(void* arg0, int arg1, int arg2)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFFFFFF;
    g_Sound_Vm2Params.unk8 = arg2 & 0x7F;
    Sound_ExecuteSoundVm2Function(0xA0);
}

void Sound_FadeSfxVolumeMod(int arg0, int arg1, int arg2, int arg3)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFFFFFF;
    g_Sound_Vm2Params.unk8 = arg2;
    g_Sound_Vm2Params.unkC = arg3 & 0x7F;
    Sound_ExecuteSoundVm2Function(0xA1);
}

void Sound_SetAllSfxPanMod(int arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)(arg0 & 0xFF);
    Sound_ExecuteSoundVm2Function(0xAA);
}

void Sound_FadeAllSfxPanMod(void* arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xAB);
}

void Sound_SetSfxPanMod(void* arg0, int arg1, int arg2)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFFFFFF;
    g_Sound_Vm2Params.unk8 = arg2 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xA2);
}

void Sound_FadeSfxPanMod(int arg0, int arg1, int arg2, int arg3)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFFFFFF;
    g_Sound_Vm2Params.unk8 = arg2;
    g_Sound_Vm2Params.unkC = arg3 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xA3);
}

void Sound_SetAllSfxPitchMod(int arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)(arg0 & 0xFF);
    Sound_ExecuteSoundVm2Function(0xAC);
}

void Sound_FadeAllSfxPitchMod(void* arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xAD);
}

void Sound_SetSfxPitchMod(void* arg0, int arg1, int arg2)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFFFFFF;
    g_Sound_Vm2Params.unk8 = arg2 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xA4);
}

void Sound_FadeSfxPitchMod(int arg0, int arg1, int arg2, int arg3)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFFFFFF;
    g_Sound_Vm2Params.unk8 = arg2;
    g_Sound_Vm2Params.unkC = arg3 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xA5);
}

void Sound_SetMasterVolumeByMusicId(u_long arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0x7F;
    Sound_ExecuteSoundVm2Function(0xC0);
}

void Sound_FadeMasterVolumeByMusicId(u_long arg0, int arg1, int arg2)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = arg1;
    g_Sound_Vm2Params.unk8 = arg2 & 0x7F;
    Sound_ExecuteSoundVm2Function(0xC1);
}

void Sound_FadeMasterVolumeFromByMusicId(void* arg0, int arg1, int arg2, int arg3)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1;
    g_Sound_Vm2Params.unk8 = arg2 & 0x7F;
    g_Sound_Vm2Params.unkC = arg3 & 0x7F;
    Sound_ExecuteSoundVm2Function(0xC2);
}

void Sound_SetCdVolume(int arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    Sound_ExecuteSoundVm2Function(0xC8);
}

void Sound_FadeCdVolume(int arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = arg1;
    Sound_ExecuteSoundVm2Function(0xC9);
}

void Sound_FadeCdVolumeFrom(void* arg0, int arg1, int arg2)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1;
    g_Sound_Vm2Params.unk8 = arg2;
    Sound_ExecuteSoundVm2Function(0xCA);
}

void Sound_SetTempoScale(int arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)(arg0 & 0xFF);
    Sound_ExecuteSoundVm2Function(0xD0);
}

void Sound_FadeTempoScale(int arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xD1);
}

void Sound_FadeTempoScaleFrom(void* arg0, int arg1, int arg2)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFF;
    g_Sound_Vm2Params.unk8 = arg2 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xD2);
}

void Sound_SetMasterPitchScale(int arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)(arg0 & 0xFF);
    Sound_ExecuteSoundVm2Function(0xD4);
}

int Sound_FadeMasterPitchScale(int arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFF;
    return Sound_ExecuteSoundVm2Function(0xD5);
}

void Sound_FadeMasterPitchScaleFrom(void* arg0, int arg1, int arg2)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFF;
    g_Sound_Vm2Params.unk8 = arg2 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xD6);
}

void func_80012ADC(int arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)(arg0 & 0xFF);
    Sound_ExecuteSoundVm2Function(0xD8);
}

void func_80012B08(void* arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xD9);
}

void func_80012B3C(void* arg0, int arg1, int arg2)
{
    g_Sound_Vm2Params.unk0 = arg0;
    g_Sound_Vm2Params.unk4 = arg1 & 0xFF;
    g_Sound_Vm2Params.unk8 = arg2 & 0xFF;
    Sound_ExecuteSoundVm2Function(0xDA);
}

void Sound_StopMusic(void) { Sound_ExecuteSoundVm2Function(240); }

void Sound_StopSfx(void) { Sound_ExecuteSoundVm2Function(241); }

void func_80012BB8(void* arg0, int arg1)
{
    while (Sound_TryLoadInstrumentBank(arg0, arg1) == 1)
        ;
}

int IsSpuTransferring(void) { return g_bSpuTransferring; }

int func_80012C14(int* arg0, int* arg1, int* arg2)
{
    int var_a3;

    if (g_pActiveMusicContext->ActiveChannelMask == 0) {
        g_pActiveMusicContext->StatusFlags &= ~0x60;
    }

    var_a3 = 0;

    if ((arg0[7] >= 0x21U) || (arg0[5] > 0x20000U)) {
        g_Sound_GlobalFlags.MixBehavior &= 0xFFFEFFFF;
        D_80036770.unk4 = 0;
        D_80036770.unk0 = 0;
    } else {
        if ((g_pActiveMusicContext->StatusFlags & 0x20)
            || (!(g_pActiveMusicContext->StatusFlags & 0x40) && (D_80039AFC & 0x10000))) {
            var_a3 = 1;
            g_Sound_GlobalFlags.MixBehavior &= 0xFFFEFFFF;
        } else {
            g_Sound_GlobalFlags.MixBehavior |= 0x10000;
        }
    }
    if (var_a3 == 0) {
        *arg1 = 0x40;
        *arg2 = 0x35100;
        D_80036770.unk0 = arg0[1];
        if (D_80036770.unk4 == arg0[1]) {
            D_80036770.unk4 = 0;
        }
    } else {
        *arg1 = 0x60;
        *arg2 = 0x55100;
        D_80036770.unk4 = arg0[1];
        if (D_80036770.unk0 == arg0[1]) {
            D_80036770.unk0 = 0;
        }
    }
    return var_a3;
}

static int func_80012D9C(int* arg0, int* arg1, int* arg2, int arg3)
{
    u_int i;

    for (i = 0; i < 3; ++i) {
        if (D_800377E0[i] == arg0[1]) {
            D_800377E0[i] = 0;
        }
    }
    switch (arg3) {
    case 1:
        *arg1 = 0xA0;
        *arg2 = 0x13100;
        D_800377E0[1] = arg0[1];
        break;
    case 2:
        *arg1 = 0xC0;
        *arg2 = 0x1B100;
        D_800377E0[2] = arg0[1];
        break;
    default:
        *arg1 = 0x80;
        *arg2 = 0xB100;
        D_800377E0[0] = arg0[1];
        break;
    }
    return arg3;
}

int func_80012E50(int arg0)
{
    if (D_80036770.unk0 == arg0) {
        g_Sound_GlobalFlags.MixBehavior |= 0x10000;
    } else if (D_80036770.unk4 == arg0) {
        g_Sound_GlobalFlags.MixBehavior &= 0xFFFEFFFF;
    }
    return D_80039AFC & 0x10000;
}

int func_80012EBC(void)
{
    g_Sound_GlobalFlags.MixBehavior &= ~0x10000;
    D_80036770.unk4 = 0;
    D_80036770.unk0 = 0;
    return 0;
}

int Sound_StartAkaoBankStreaming(void)
{
    D_80039BCC = 0;
    g_Sound_GlobalFlags.ControlLatches |= 1;
    return 0;
}

int Sound_StreamAkaoBankChunk(int* in_Data, u_int in_Size, int in_Slot, int in_Wait)
{
    int instrumentIndex;
    int spuAddr;
    u_int chunk;
    u_int spuChunk;

    if (g_Sound_GlobalFlags.ControlLatches & 1) {
        if (g_Sound_AkaoLoadState.SpuTransferStartAddr == 0) {
            if (Sound_IsNotAkaoFile(in_Data) == 0) {
                if (in_Data[4] == 0x35100) {
                    func_80012C14(in_Data, &instrumentIndex, &spuAddr);
                } else if (in_Data[4] == 0xB100) {
                    func_80012D9C(in_Data, &instrumentIndex, &spuAddr, in_Slot);
                } else {
                    spuAddr = in_Data[4];
                    instrumentIndex = in_Data[6];
                }
                memcpy32(in_Data, D_80037850, 0x40);
                in_Data += 0x10;
                in_Size -= 0x40;
                D_80037850[4] = spuAddr;
                g_Sound_AkaoLoadState.SpuTransferStartAddr = spuAddr;
                D_80037850[6] = instrumentIndex;
                g_Sound_AkaoLoadState.SampleBytesRemaining = D_80037850[5];
                g_Sound_AkaoLoadState.pInstrumentInfoCursor =
                    (int*)&g_InstrumentInfo[instrumentIndex];
                g_Sound_AkaoLoadState.InstrumentBytesRemaining =
                    D_80037850[7] * sizeof(FSoundInstrumentInfo);
            } else {
                in_Size = 0;
                g_Sound_AkaoLoadState.SampleBytesRemaining = 0;
                g_Sound_AkaoLoadState.InstrumentBytesRemaining = 0;
            }
        }
        if ((g_Sound_AkaoLoadState.InstrumentBytesRemaining != 0) && (in_Size != 0)) {
            chunk = g_Sound_AkaoLoadState.InstrumentBytesRemaining;
            if (chunk >= in_Size) {
                chunk = in_Size;
            }
            // The original reuses the spuAddr stack slot for the chunk size.
            spuAddr = chunk;
            memcpy32(in_Data, g_Sound_AkaoLoadState.pInstrumentInfoCursor, spuAddr);
            in_Data += (u_int)spuAddr / 4;
            in_Size -= spuAddr;
            g_Sound_AkaoLoadState.pInstrumentInfoCursor += (u_int)spuAddr / 4;
            g_Sound_AkaoLoadState.InstrumentBytesRemaining -= spuAddr;
            if (g_Sound_AkaoLoadState.InstrumentBytesRemaining == 0) {
                Sound_CopyAndRelocateInstruments(&g_InstrumentInfo[D_80037850[6]],
                    &g_InstrumentInfo[D_80037850[6]], D_80037850[4], D_80037850[7]);
            }
        }
        if ((in_Size != 0) && (g_Sound_AkaoLoadState.SampleBytesRemaining != 0)) {
            spuChunk = g_Sound_AkaoLoadState.SampleBytesRemaining;
            if (spuChunk >= in_Size) {
                spuChunk = in_Size;
            }
            in_Size = spuChunk;
            SpuSetTransferStartAddr(g_Sound_AkaoLoadState.SpuTransferStartAddr);
            WriteSpu((char*)in_Data, in_Size);
            g_Sound_AkaoLoadState.SpuTransferStartAddr += in_Size;
            g_Sound_AkaoLoadState.SampleBytesRemaining -= in_Size;
            if (in_Wait != 0) {
                WaitForSpuTransfer();
            }
        }
        if (g_Sound_AkaoLoadState.SampleBytesRemaining == 0) {
            g_Sound_GlobalFlags.ControlLatches &= ~1;
        }
    }
    return g_Sound_AkaoLoadState.SampleBytesRemaining;
}

int func_80013188(void* arg0, int arg1)
{
    int sp10;
    int sp14;
    int temp_s0 = func_80012C14(arg0, &sp10, &sp14);
    Sound_LoadInstrumentBank(arg0, arg1, sp10, sp14);
    return temp_s0;
}

int func_800131DC(void* arg0, int arg1, int arg2)
{
    int sp10;
    int sp14;

    func_80012D9C((int*)arg0, &sp10, &sp14, arg1);
    Sound_LoadInstrumentBank(arg0, arg2, sp10, sp14);
    return 0;
}

int Sound_SetCdMixVolume(u_int arg0)
{
    if (D_80039AFC & 2) {
        g_Sound_CdlATV.val0 = g_Sound_CdlATV.val2 = g_Sound_CdlATV.val1 =
            g_Sound_CdlATV.val3 = (arg0 * 0xB570) >> 0x11;
    } else {
        g_Sound_CdlATV.val2 = arg0;
        g_Sound_CdlATV.val0 = arg0;
        g_Sound_CdlATV.val3 = 0;
        g_Sound_CdlATV.val1 = 0;
    }
    CdMix(&g_Sound_CdlATV);
    return 0;
}

void func_800132C4(void* arg0, int arg1, int arg2)
{
    if (Sound_IsNotAkaoFile(arg0) == 0) {
        g_Sound_Vm2Params.unk0 = arg0;
        g_Sound_Vm2Params.unk4 = (arg1 & 0xFF) << 8;
        g_Sound_Vm2Params.unk8 = arg2;
        Sound_ExecuteSoundVm2Function(0xE0);
    }
}

void Sound_StopCutsceneStream(void) { Sound_ExecuteSoundVm2Function(0xE2); }

void Sound_SetCutsceneVolume(int arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)((arg0 & 0x7F) << 8);
    Sound_ExecuteSoundVm2Function(0xE4);
}

void Sound_FadeOutCutscene(int arg0, int arg1)
{
    g_Sound_Vm2Params.unk0 = (void*)arg0;
    g_Sound_Vm2Params.unk4 = (arg1 & 0x7F) << 8;
    Sound_ExecuteSoundVm2Function(0xE5);
}

void func_800133B0(int arg0)
{
    g_Sound_Vm2Params.unk0 = (void*)((arg0 & 0xFF) << 8);
    Sound_ExecuteSoundVm2Function(0xE6);
}

u_int func_800133E0(u_int* arg0)
{
    int i;
    FSoundChannel* var_a1 = g_SfxSoundChannels;

    for (i = 0; i < 12; ++i) {
        *arg0++ = (var_a1++)->AkaoProgramIndex;
    }
    return g_Sound_SfxState.ActiveVoiceMask;
}

void Sound_CopyAndRelocateInstruments(FSoundInstrumentInfo* in_A,
    FSoundInstrumentInfo* in_B, int in_AddrOffset, int in_Count)
{
    do {
        in_B->StartAddr = in_A->StartAddr + in_AddrOffset;
        in_B->LoopAddr = in_A->LoopAddr + in_AddrOffset;
        *(int*)&in_B->FineTune = *(int*)&in_A->FineTune;
        *(int*)&in_B->AdsrLower = *(int*)&in_A->AdsrLower;
        in_A++;
        in_B++;
        in_Count--;
    } while (in_Count != 0);
}

static int Sound_IsNotAkaoFile(int* data)
{
    return data[0] - ('A' | ('K' << 8) | ('A' << 16) | ('O' << 24));
}

static void ClearSpuTransferCallback(void)
{
    SpuSetTransferCallback(NULL);
    g_bSpuTransferring = 0;
}

void SetSpuTransferCallback(void)
{
    g_bSpuTransferring = 1;
    SpuSetTransferCallback(ClearSpuTransferCallback);
}

static void WriteSpu(char* data, u_int len)
{
    g_bSpuTransferring = 1;
    SpuSetTransferCallback(ClearSpuTransferCallback);
    SpuWrite(data, len);
}

static void ReadSpu(char* data, u_int len)
{
    SetSpuTransferCallback();
    SpuRead(data, len);
}

static void WaitForSpuTransfer(void)
{
    if (g_bSpuTransferring == 1) {
        do {

        } while (g_bSpuTransferring == 1);
    }
}

int Sound_TryLoadInstrumentBank(void* arg0, int arg1)
{
    if (Sound_IsNotAkaoFile(arg0) == 0) {
        Sound_LoadInstrumentBank(arg0, arg1, ((int*)arg0)[6], ((int*)arg0)[4]);
        return 0;
    }
    return -1;
}

int Sound_LoadInstrumentBank(
    void* in_Data, int in_Wait, int in_FirstInstrument, int in_SpuAddr)
{
    FAkaoSequence* header;
    FSoundInstrumentInfo* instruments;

    WaitForSpuTransfer();
    if (Sound_IsNotAkaoFile(in_Data) == 0) {
        header = in_Data;
        SpuSetTransferStartAddr(in_SpuAddr);
        in_Data = header->Payload;
        instruments = in_Data;
        in_Data = instruments + header->unk1C;
        WriteSpu(in_Data, header->unk14);
        Sound_CopyAndRelocateInstruments(instruments,
            &g_InstrumentInfo[in_FirstInstrument], in_SpuAddr, header->unk1C);
        if (in_Wait != 0) {
            WaitForSpuTransfer();
        }
        return 0;
    }
    g_bSpuTransferring = -1;
    return -1;
}

// Keep the published music base in a3 for matching; use a plain local for nonmatching
// builds.
#ifdef NON_MATCHING
#define VS_REG_VAR(type, name, reg) type name
#else
#define VS_REG_VAR(type, name, reg) register type name __asm__(reg)
#endif

void Sound_Setup(void)
{
    u_int count;
    u_int voiceIndex;
    int assignedVoiceNumber;
    FSoundChannel* channel;
    FSoundChannel* sfxChannel;
    FSoundChannel** musicSlot;
    VS_REG_VAR(FSoundChannel*, musicBase, "$7");

    g_pActiveMusicContext = &g_PrimaryMusicContext;
    g_pSuspendedMusicContext = NULL;
    musicSlot = &g_Sound_pMusicSoudChannels;
    musicBase = g_ActiveMusicChannels;
    *musicSlot = musicBase;
    g_pSecondaryMusicChannels = NULL;
    g_Sound_GlobalFlags.ControlLatches = 0;
    g_Sound_LfoPhase = 0;
    D_80037788.Param1 = 0;
    D_80036770.unk4 = 0;
    D_80036770.unk0 = 0;
    D_800377E0[2] = 0;
    D_800377E0[1] = 0;
    D_800377E0[0] = 0;
    g_Sound_GlobalFlags.MixBehavior = 1;
    g_Sound_SfxState.ActiveVoiceMask = 0;
    g_PrimaryMusicContext.ActiveChannelMask = 0;
    g_PrimaryMusicContext.KeyedMask = 0;
    g_PrimaryMusicContext.MusicId = 0;
    g_Sound_SfxState.SuspendedVoiceMask = 0;
    g_PrimaryMusicContext.SuspendedChannelMask = 0;
    g_SuspendedMusicContext.MusicId = 0;
    g_SuspendedMusicContext.ActiveChannelMask = 0;
    g_PrimaryMusicContext.MasterVolume = 0x7F0000;
    g_CdVolume = 0x7FFF0000;
    g_PrimaryMusicContext.MasterVolumeStepsRemaining = 0;
    g_Sound_MasterPitchScaleStepsRemaining = 0;
    g_Sound_MasterPitchScaleQ16_16 = 0;
    g_Sound_TempoScaleStepsRemaining = 0;
    g_Sound_TempoScale = 0;
    g_Sound_CdVolumeFadeLength = 0;
    g_Sound_SfxState.NoiseVoiceFlags = 0;
    g_PrimaryMusicContext.NoiseChannelFlags = 0;
    g_Sound_SfxState.ReverbVoiceFlags = 0;
    g_PrimaryMusicContext.ReverbChannelFlags = 0;
    g_Sound_SfxState.FmVoiceFlags = 0;
    g_PrimaryMusicContext.FmChannelFlags = 0;
    g_PrimaryMusicContext.TimerLower = 0;
    g_PrimaryMusicContext.TimerUpperCurrent = 0;
    g_PrimaryMusicContext.TimerUpper = 0;
    g_PrimaryMusicContext.TimerTopCurrent = 0;
    *SPU_MAIN_VOL_L = 0x3FFF;
    *SPU_MAIN_VOL_R = 0x3FFF;
    *CD_VOL_L = 0x7FFF;
    *CD_VOL_R = 0x7FFF;
    count = *SPU_CONTROL;
    g_Music_LoopCounter = 0;
    g_Sound_MutedMusicChannelMask = 0;
    D_80039B64 = 0;
    g_Sound_Cutscene_StreamState.VolFadeStepsRemaining = 0;
    g_Sound_Cutscene_StreamState.Volume = 0x7F00;
    g_Sound_VoiceModeFlags.Fm = 0;
    g_Sound_VoiceModeFlags.Noise = 0;
    g_Sound_VoiceModeFlags.Reverb = 0;
    assignedVoiceNumber = count;
    *SPU_CONTROL = (assignedVoiceNumber & 0xFFFA) | 1;

    channel = musicBase;

    for (count = 0; (count & 0xFFFF) < SOUND_CHANNEL_COUNT;) {
        ++count;
        channel->UpdateFlags = 0;
        channel->VoiceParams.AssignedVoiceNumber = VOICE_COUNT;
        channel->Type = SOUND_CHANNEL_TYPE_MUSIC;
        channel->Priority = 0;
        ++channel;
    }

    sfxChannel = &g_SfxSoundChannels[0];

    for (voiceIndex = 12; (voiceIndex & 0xFFFF) < VOICE_COUNT;) {
        assignedVoiceNumber = voiceIndex & 0xFFFF;
        ++voiceIndex;
        sfxChannel->UpdateFlags = 0;
        sfxChannel->VoiceParams.AssignedVoiceNumber = assignedVoiceNumber;
        sfxChannel->Type = SOUND_CHANNEL_TYPE_SOUND;
        sfxChannel->Priority = 0;
        sfxChannel->VolumeMod = 0x7F00;
        sfxChannel->VolumeModStepsRemaining = 0;
        sfxChannel->PitchModStepsRemaining = 0;
        sfxChannel->PitchMod = 0;
        sfxChannel->KeyOnVolumeSlideLength = 0;
        ++sfxChannel;
    }

    g_pActiveMusicContext->PendingKeyOffMask = 0;
    g_pActiveMusicContext->ActiveNoteMask = 0;
    g_pActiveMusicContext->PendingKeyOnMask = 0;
    g_Sound_SfxState.TempoAccumulator = 1;
    g_Sound_SfxState.TempoBase = 0x66A80000;
    g_Sound_SfxState.KeyOffFlags = 0;
    g_Sound_SfxState.KeyedFlags = 0;
    g_Sound_SfxState.KeyOnFlags = 0;
    g_pActiveMusicContext->RevDepth = 0x3FFF000;
    g_pActiveMusicContext->ReverbDepthSlideStep = 0;
    g_pActiveMusicContext->ReverbDepthSlideLength = 0;
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_UPDATE_REVERB;
    Sound_SetReverbMode(SPU_REV_MODE_STUDIO_C);
    SpuSetReverb(SPU_ON);
}
#undef VS_REG_VAR

static void Sound_Start(void)
{
    int event;

    SpuStart();
    SpuInitMalloc(4, &_spuMemInfo);
    SpuSetTransferMode(SPU_TRANSFER_BY_DMA);
    SpuSetTransferStartAddr(0x1010);
    WriteSpu(_soundFlush, 64);
    WaitForSpuTransfer();
    Sound_Setup();
    SpuSetIRQ(SPU_OFF);
    SpuSetIRQCallback(NULL);
    while (SetRCnt(RCntCNT2, 0x44E8, RCntMdINTR) == 0)
        ;
    while (StartRCnt(RCntCNT2) == 0)
        ;
    do {
        event = OpenEvent(RCntCNT2, EvSpINT, EvMdINTR, Sound_MainLoop);
        g_Sound_EventDescriptor = event;
    } while (event == -1);
    while (EnableEvent(g_Sound_EventDescriptor) == 0)
        ;
}

static void Sound_Stop(void)
{
    if (g_bSpuTransferring == 1) {
        WriteSpu(_soundFlush, 64);
        WaitForSpuTransfer();
    }
    while (StopRCnt(RCntCNT2) == 0)
        ;
    UnDeliverEvent(RCntCNT2, EvSpINT);
    while (DisableEvent(g_Sound_EventDescriptor) == 0)
        ;
    while (CloseEvent(g_Sound_EventDescriptor) == 0)
        ;
    SetVoiceKeyOff(0xFFFFFF);
    SpuQuit();
}

static void SetVoiceKeyOn(u_int in_KeyOn)
{
    *SPU_VOICE_KEY_ON_LO = in_KeyOn;
    *SPU_VOICE_KEY_ON_HI = (in_KeyOn >> 0x10);
}

static void SetVoiceKeyOff(u_int in_KeyOff)
{
    *SPU_VOICE_KEY_OFF_LO = in_KeyOff;
    *SPU_VOICE_KEY_OFF_HI = (in_KeyOff >> 0x10);
}

static void SetVoiceReverbMode(u_int in_ReverbMode)
{
    *SPU_VOICE_CHN_REVERB_MODE_LO = in_ReverbMode;
    *SPU_VOICE_CHN_REVERB_MODE_HI = (in_ReverbMode >> 0x10);
}

static void SetVoiceNoiseMode(u_int in_NoiseMode)
{
    *SPU_VOICE_CHN_NOISE_MODE_LO = in_NoiseMode;
    *SPU_VOICE_CHN_NOISE_MODE_HI = (in_NoiseMode >> 0x10);
}

static void SetVoiceFmMode(u_int in_FmMode)
{
    *SPU_VOICE_CHN_FM_MODE_LO = in_FmMode;
    *SPU_VOICE_CHN_FM_MODE_HI = (in_FmMode >> 0x10);
}

void SetVoiceVolume(int in_VoiceIndex, u_int in_VolL, u_int in_VolR, u_int in_VolumeScale)
{
    SpuVolume* pVolume;

    if (in_VolumeScale != 0) {
        in_VolL = in_VolL * in_VolumeScale;
        in_VolR = in_VolR * in_VolumeScale;
        in_VolL = in_VolL >> 7;
        in_VolR = in_VolR >> 7;
    }

    pVolume = (SpuVolume*)&VOICE_00_LEFT_RIGHT[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE];
    pVolume->left = in_VolL & 0x7FFF;
    pVolume->right = in_VolR & 0x7FFF;
}

static void SetVoiceSampleRate(int in_VoiceIndex, int in_SampleRate)
{
    VOICE_00_ADPCM_SAMPLE_RATE[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE] = in_SampleRate;
}

static void SetVoiceStartAddr(int in_VoiceIndex, u_int in_Addr)
{
    VOICE_00_ADPCM_START_ADDR[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE] = (in_Addr >> 3);
}

static void SetVoiceRepeatAddr(int in_VoiceIndex, u_int in_Addr)
{
    VOICE_00_ADPCM_REPEAT_ADDR[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE] = (in_Addr >> 3);
}

static void SetVoiceAdsrLower(int in_VoiceIndex, u_short in_Register)
{
    VOICE_00_ADPCM_ADSR_LOWER[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE] = in_Register;
}

static void SetVoiceAdsrUpper(int in_VoiceIndex, u_short in_Register)
{
    VOICE_00_ADPCM_ADSR_UPPER[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE] = in_Register;
}

//----------------------------------------------------------------------------------------------------------------------
// ADSR LOWER 16-bit (at 1F801C08h+N*10h)
//----------------------------------------------------------------------------------------------------------------------

// Bit positions
#define ADSR_ATTACK_MODE_BIT 15
#define ADSR_ATTACK_SHIFT_POS 10 // 5 bits (14-10)
#define ADSR_ATTACK_STEP_POS 8 // 2 bits (9-8)
#define ADSR_DECAY_SHIFT_POS 4 // 4 bits (7-4)
#define ADSR_SUSTAIN_LEVEL_POS 0 // 4 bits (3-0)

// Bit masks (for masking out fields)
#define ADSR_ATTACK_MODE_MASK (0x1 << ADSR_ATTACK_MODE_BIT)
#define ADSR_ATTACK_SHIFT_MASK (0x1F << ADSR_ATTACK_SHIFT_POS)
#define ADSR_ATTACK_STEP_MASK (0x3 << ADSR_ATTACK_STEP_POS)
#define ADSR_DECAY_SHIFT_MASK (0xF << ADSR_DECAY_SHIFT_POS)
#define ADSR_SUSTAIN_LEVEL_MASK (0xF << ADSR_SUSTAIN_LEVEL_POS)

// Attack Mode values
#define ADSR_ATTACK_MODE_LINEAR 0
#define ADSR_ATTACK_MODE_EXPONENTIAL 1

// Attack Step values ("+7,+6,+5,+4")
#define ADSR_ATTACK_STEP_PLUS_7 0
#define ADSR_ATTACK_STEP_PLUS_6 1
#define ADSR_ATTACK_STEP_PLUS_5 2
#define ADSR_ATTACK_STEP_PLUS_4 3

// Helper macros to build fields
#define ADSR_ATTACK_MODE(mode) ((mode) << ADSR_ATTACK_MODE_BIT)
#define ADSR_ATTACK_SHIFT(shift) (((shift) & 0x1F) << ADSR_ATTACK_SHIFT_POS)
#define ADSR_ATTACK_STEP(step) (((step) & 0x3) << ADSR_ATTACK_STEP_POS)
#define ADSR_DECAY_SHIFT(shift) (((shift) & 0xF) << ADSR_DECAY_SHIFT_POS)
#define ADSR_SUSTAIN_LEVEL(level) (((level) & 0xF) << ADSR_SUSTAIN_LEVEL_POS)

//----------------------------------------------------------------------------------------------------------------------
// ADSR UPPER 16-bit (at 1F801C0Ah+N*10h)
//----------------------------------------------------------------------------------------------------------------------

// Bit positions (relative to the upper 16-bit word, bits 0-15)
#define ADSR_SUSTAIN_MODE_BIT 15
#define ADSR_SUSTAIN_DIRECTION_BIT 14
// Bit 13 unused
#define ADSR_SUSTAIN_SHIFT_POS 8 // 5 bits (12-8)
#define ADSR_SUSTAIN_STEP_POS 6 // 2 bits (7-6)
#define ADSR_RELEASE_MODE_BIT 5
#define ADSR_RELEASE_SHIFT_POS 0 // 5 bits (4-0)

// Bit masks (for masking out fields)
#define ADSR_SUSTAIN_MODE_MASK (0x1 << ADSR_SUSTAIN_MODE_BIT)
#define ADSR_SUSTAIN_DIRECTION_MASK (0x1 << ADSR_SUSTAIN_DIRECTION_BIT)
#define ADSR_SUSTAIN_SHIFT_MASK (0x1F << ADSR_SUSTAIN_SHIFT_POS)
#define ADSR_SUSTAIN_STEP_MASK (0x3 << ADSR_SUSTAIN_STEP_POS)
#define ADSR_RELEASE_MODE_MASK (0x1 << ADSR_RELEASE_MODE_BIT)
#define ADSR_RELEASE_SHIFT_MASK (0x1F << ADSR_RELEASE_SHIFT_POS)

// Sustain Mode values
#define ADSR_SUSTAIN_MODE_LINEAR 0
#define ADSR_SUSTAIN_MODE_EXPONENTIAL 1

// Sustain Direction values
#define ADSR_SUSTAIN_DIR_INCREASE 0
#define ADSR_SUSTAIN_DIR_DECREASE 1

// Sustain Step values
// When Increase: "+7,+6,+5,+4"
#define ADSR_SUSTAIN_STEP_INC_PLUS_7 0
#define ADSR_SUSTAIN_STEP_INC_PLUS_6 1
#define ADSR_SUSTAIN_STEP_INC_PLUS_5 2
#define ADSR_SUSTAIN_STEP_INC_PLUS_4 3

// When Decrease: "-8,-7,-6,-5"
#define ADSR_SUSTAIN_STEP_DEC_MINUS_8 0
#define ADSR_SUSTAIN_STEP_DEC_MINUS_7 1
#define ADSR_SUSTAIN_STEP_DEC_MINUS_6 2
#define ADSR_SUSTAIN_STEP_DEC_MINUS_5 3

// Release Mode values
#define ADSR_RELEASE_MODE_LINEAR 0
#define ADSR_RELEASE_MODE_EXPONENTIAL 1

// Helper macros to build fields
#define ADSR_SUSTAIN_MODE(mode) ((mode) << ADSR_SUSTAIN_MODE_BIT)
#define ADSR_SUSTAIN_DIRECTION(dir) ((dir) << ADSR_SUSTAIN_DIRECTION_BIT)
#define ADSR_SUSTAIN_SHIFT(shift) (((shift) & 0x1F) << ADSR_SUSTAIN_SHIFT_POS)
#define ADSR_SUSTAIN_STEP(step) (((step) & 0x3) << ADSR_SUSTAIN_STEP_POS)
#define ADSR_RELEASE_MODE(mode) ((mode) << ADSR_RELEASE_MODE_BIT)
#define ADSR_RELEASE_SHIFT(shift) (((shift) & 0x1F) << ADSR_RELEASE_SHIFT_POS)

void SetVoiceAdsrAttackRateAndMode(
    int in_VoiceIndex, int in_AttackStep, u_int in_AttackMode)
{
    u_short* AdsrLower =
        &VOICE_00_ADPCM_ADSR_LOWER[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE];
    // Extract Attack Mode bit (bit 2 of in_AttackRate -> bit 15 of ADSR)
    u_short AttackMode = ADSR_ATTACK_MODE(in_AttackMode >> 2);
    // Position Attack Step (0-3) at bits 8-9
    u_short AttackStep = in_AttackStep << ADSR_ATTACK_STEP_POS;
    *AdsrLower = AttackMode | AttackStep | *(char*)AdsrLower;
}

void SetVoiceAdsrDecayRate(int in_VoiceIndex, int in_DecayRate)
{
    u_short* AdsrLower =
        &VOICE_00_ADPCM_ADSR_LOWER[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE];
    u_short AttackStep = in_DecayRate * 0x10;
    u_short Masked = (*AdsrLower & 0xFF0F);
    *AdsrLower = Masked | AttackStep;
}

void SetVoiceAdsrSustainLevel(int in_VoiceIndex, int in_SustainLevel)
{
    u_short* AdsrLower =
        &VOICE_00_ADPCM_ADSR_LOWER[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE];
    *AdsrLower = (*AdsrLower & 0xFFF0) | in_SustainLevel;
}

void SetVoiceAdsrSustainRateAndDirection(
    int in_VoiceIndex, int in_SustainRate, u_int in_SustainDirection)
{
    u_short* AdsrUpper =
        &VOICE_00_ADPCM_ADSR_UPPER[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE];
    u_short SustainDirection = ADSR_SUSTAIN_DIRECTION(in_SustainDirection >> 1);
    u_short SustainRate = in_SustainRate << ADSR_SUSTAIN_STEP_POS;
    u_short Masked = *AdsrUpper & 0x3F;
    *AdsrUpper = Masked | (SustainDirection | SustainRate);
}

void SetVoiceAdsrReleaseRateAndMode(
    int in_VoiceIndex, int in_ReleaseRate, u_int in_ReleaseMode)
{
    u_short* AdsrUpper =
        &VOICE_00_ADPCM_ADSR_UPPER[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE];
    u_short ReleaseMode = (in_ReleaseMode >> 2) << ADSR_RELEASE_MODE_BIT;
    u_short ReleaseRate = in_ReleaseRate << ADSR_RELEASE_SHIFT_POS;
    u_short Masked = *AdsrUpper & 0xFFC0;
    *AdsrUpper = Masked | (ReleaseMode | ReleaseRate);
}

void SetVoiceParams(
    int in_VoiceIndex, FSoundVoiceParams* in_VoiceParams, int in_VolumeScale)
{
    int left;
    int right;
    short* p;

    in_VoiceParams->VoiceParamFlags = 0;
    p = (short*)&VOICE_00_LEFT_RIGHT[in_VoiceIndex * SPU_VOICE_INDEX_STRIDE];
    if (in_VolumeScale == 0) {
        left = in_VoiceParams->Volume.left;
        right = in_VoiceParams->Volume.right;
    } else {
        left = in_VoiceParams->Volume.left * in_VolumeScale;
        right = in_VoiceParams->Volume.right * in_VolumeScale;
        left >>= 7;
        right >>= 7;
    }

    // This is the dumbest shit, but I can't find any other way that compiles correctly
    *p++ = left & 0x7FFF;
    *p++ = right & 0x7FFF;
    *p++ = in_VoiceParams->SampleRate;
    *p++ = in_VoiceParams->StartAddress >> 3;
    *p++ = in_VoiceParams->AdsrLower;
    *p++ = in_VoiceParams->AdsrUpper;
    p++;
    *p = in_VoiceParams->LoopAddress >> 3;
}

void SetVoiceParamsByFlags(u_int in_VoiceIndex, FSoundVoiceParams* in_VoiceParams,
    int arg2 __attribute__((unused)))
{
    int flags;

    flags = in_VoiceParams->VoiceParamFlags;
    if (flags == 0) {
        return;
    }

    in_VoiceParams->VoiceParamFlags = 0;

    if (flags & VOICE_PARAM_SAMPLE_RATE) {
        flags &= ~VOICE_PARAM_SAMPLE_RATE;
        SetVoiceSampleRate(in_VoiceIndex, in_VoiceParams->SampleRate);
        if (flags == 0) {
            return;
        }
    }

    if (flags & VOICE_PARAM_VOLUME) {
        flags &= ~VOICE_PARAM_VOLUME;
        SetVoiceVolume(in_VoiceIndex, in_VoiceParams->Volume.left,
            in_VoiceParams->Volume.right, in_VoiceParams->VolumeScale);
        if (flags == 0) {
            return;
        }
    }

    if (flags & VOICE_PARAM_START_ADDR) {
        flags &= ~VOICE_PARAM_START_ADDR;
        SetVoiceStartAddr(in_VoiceIndex, in_VoiceParams->StartAddress);
        if (flags == 0) {
            return;
        }
    }

    if (flags & VOICE_PARAM_LOOP_ADDR) {
        flags &= ~VOICE_PARAM_LOOP_ADDR;
        SetVoiceRepeatAddr(in_VoiceIndex, in_VoiceParams->LoopAddress);
        if (flags == 0) {
            return;
        }
    }

    if (flags & VOICE_PARAM_ADSR_UPPER) {
        flags &= ~VOICE_PARAM_ADSR_UPPER;
        SetVoiceAdsrUpper(in_VoiceIndex, in_VoiceParams->AdsrUpper);
        if (flags == 0) {
            return;
        }
    }

    if (flags & VOICE_PARAM_ADSR_LOWER) {
        SetVoiceAdsrLower(in_VoiceIndex, in_VoiceParams->AdsrLower);
    }
}

void Sound_UpdateSlidesAndDelays(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags, int in_Arg2)
{

    short* Wave;
    int temp;

    if (in_Arg2 == 0) {
        if (in_pChannel->VolumeBalanceSlideLength != 0) {
            in_pChannel->VolumeBalanceSlideLength--;
            temp = in_pChannel->VolumeBalance + in_pChannel->VolumeBalanceSlideStep;
            if ((temp & 0x7F00) != (in_pChannel->VolumeBalance & 0x7F00)) {
                in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
            }
            in_pChannel->VolumeBalance = temp;
        }
    }

    if (in_pChannel->ChannelVolumeSlideLength != 0) {
        int Volume;
        in_pChannel->ChannelVolumeSlideLength--;
        Volume = in_pChannel->Volume;
        temp = Volume + in_pChannel->VolumeSlideStep;
        if ((temp & 0xFFE00000) != (Volume & 0xFFE00000)) {
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
        }
        in_pChannel->Volume = temp;
    }

    if (in_pChannel->ChannelPanSlideLength != 0) {
        u_short Pan;
        in_pChannel->ChannelPanSlideLength--;
        Pan = in_pChannel->ChannelPan;
        temp = Pan + in_pChannel->PanSlideStep;
        if ((temp & 0xFF00) != (Pan & 0xFF00)) {
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
        }
        in_pChannel->ChannelPan = temp;
    }

    if (in_pChannel->VibratoDelayCurrent != 0) {
        in_pChannel->VibratoDelayCurrent--;
    }

    if (in_pChannel->TremeloDelayCurrent != 0) {
        in_pChannel->TremeloDelayCurrent--;
    }

    if (in_pChannel->NoiseTimer != 0) {
        in_pChannel->NoiseTimer--;
        if (!(in_pChannel->NoiseTimer & 0xFFFF)) {
            if (in_Arg2 == 0) {
                g_pActiveMusicContext->NoiseChannelFlags ^= in_VoiceFlags;
            } else {
                g_Sound_SfxState.NoiseVoiceFlags ^= in_VoiceFlags;
            }
            g_Sound_GlobalFlags.UpdateFlags |=
                (SOUND_GLOBAL_UPDATE_04 | SOUND_GLOBAL_UPDATE_08);
        }
    }

    if (in_pChannel->FmTimer != 0) {
        in_pChannel->FmTimer--;
        if (!(in_pChannel->FmTimer & 0xFFFF)) {
            if (in_Arg2 == 0) {
                g_pActiveMusicContext->FmChannelFlags ^= in_VoiceFlags;
            } else {
                g_Sound_SfxState.FmVoiceFlags ^= in_VoiceFlags;
            }
            g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_08;
        }
    }

    if (in_pChannel->VibratoDepthSlideLength != 0) {
        u_int var_lo;
        u_short VibratoDepth;
        int NewVibratoDepth;

        in_pChannel->VibratoDepthSlideLength--;
        VibratoDepth = in_pChannel->VibratoDepth + in_pChannel->VibratoDepthSlideStep;
        in_pChannel->VibratoDepth = VibratoDepth;
        NewVibratoDepth = (u_int)(VibratoDepth & 0x7F00) >> 8;
        if (VibratoDepth & 0x8000) {
            var_lo = (u_int)(NewVibratoDepth * in_pChannel->PitchBase) >> 7;
        } else {
            var_lo = (NewVibratoDepth * ((u_int)(in_pChannel->PitchBase * 15) >> 8)) >> 7;
        }

        in_pChannel->VibratoBase = var_lo;

        if ((in_pChannel->VibratoDelayCurrent == 0)
            && (in_pChannel->VibratoRateCurrent != 1)) {
            Wave = in_pChannel->VibratoWave;
            if (Wave[0] == 0 && Wave[1] == 0) {
                Wave += Wave[2];
            }

            temp = (in_pChannel->VibratoBase * Wave[0]) >> 16;
            if (temp != in_pChannel->VibratoPitch) {
                in_pChannel->VibratoPitch = temp;
                in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_SAMPLE_RATE;
                if (temp >= 0) {
                    in_pChannel->VibratoPitch = temp * 2;
                }
            }
        }
    }

    if (in_pChannel->TremeloDepthSlideLength != 0) {

        in_pChannel->TremeloDepthSlideLength--;
        in_pChannel->TremeloDepth += (u_short)in_pChannel->TremeloDepthSlideStep;
        if (((u_short)in_pChannel->TremeloDelayCurrent == 0)
            && ((u_short)in_pChannel->TremeloRateCurrent != 1)) {
            int FinalVolume;
            int TremeloDepthHi8;
            int VolumeBalanceHigh8;
            int VolumeHigh16;

            Wave = in_pChannel->TremeloWave;
            if (Wave[0] == 0 && Wave[1] == 0) {
                Wave += Wave[2];
            }

            VolumeBalanceHigh8 = (u_short)in_pChannel->VolumeBalance >> 8;
            VolumeHigh16 = in_pChannel->Volume >> 16;
            FinalVolume = (VolumeHigh16 * VolumeBalanceHigh8) >> 7;
            TremeloDepthHi8 = in_pChannel->TremeloDepth >> 8;
            temp = ((FinalVolume * TremeloDepthHi8) << 9) >> 16;
            temp = (temp * *Wave) >> 15;
            if (temp != in_pChannel->TremeloVolume) {
                in_pChannel->TremeloVolume = temp;
                in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
            }
        }
    }

    if (in_pChannel->AutoPanDepthSlideLength != 0) {
        in_pChannel->AutoPanDepthSlideLength--;
        in_pChannel->AutoPanDepth += in_pChannel->AutoPanDepthSlideStep;
        if (in_pChannel->AutoPanRateCurrent != 1) {
            Wave = in_pChannel->AutoPanWave;
            if ((Wave[0] == 0) && (Wave[1] == 0)) {
                Wave += Wave[2];
            }

            temp = ((in_pChannel->AutoPanDepth >> 8) * *Wave) >> 15;
            if (temp != in_pChannel->AutoPanVolume) {
                in_pChannel->AutoPanVolume = temp;
                in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
            }
        }
    }

    if (in_pChannel->PitchSlideStepsCurrent != 0) {
        int PitchSlide;

        in_pChannel->PitchSlideStepsCurrent--;
        PitchSlide = in_pChannel->PitchSlide;
        temp = PitchSlide + in_pChannel->PitchSlideStep;
        if ((temp & 0xFFFF0000) != (PitchSlide & 0xFFFF0000)) {
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_SAMPLE_RATE;
        }
        in_pChannel->PitchSlide = temp;
    }
}

void Sound_UpdateModulation(
    FSoundChannel* in_pChannel, int in_VoiceFlags __attribute__((unused)))
{
    short* Wave;
    int temp;
    int Volume = ((in_pChannel->Volume >> 16) * (in_pChannel->VolumeBalance >> 8)) >> 7;
    int Sample;
    u_int UpdateFlags = in_pChannel->UpdateFlags;

    if ((UpdateFlags & SOUND_UPDATE_VIBRATO) && (in_pChannel->VibratoDelayCurrent == 0)
        && (--in_pChannel->VibratoRateCurrent == 0)) {
        in_pChannel->VibratoRateCurrent = in_pChannel->VibratoRatePhase;
        Wave = in_pChannel->VibratoWave;
        if (Wave[0] == 0 && Wave[1] == 0) {
            in_pChannel->VibratoWave = Wave + Wave[2];
        }
        Sample = *in_pChannel->VibratoWave++;
        temp = (in_pChannel->VibratoBase * Sample) >> 16;
        if (temp != in_pChannel->VibratoPitch) {
            in_pChannel->VibratoPitch = temp;
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_SAMPLE_RATE;
            if (temp >= 0) {
                in_pChannel->VibratoPitch = temp * 2;
            }
        }
    }

    if ((UpdateFlags & SOUND_UPDATE_TREMOLO) && (in_pChannel->TremeloDelayCurrent == 0)
        && !(--in_pChannel->TremeloRateCurrent & 0xFFFF)) {
        in_pChannel->TremeloRateCurrent = in_pChannel->TremeloRatePhase;
        Wave = in_pChannel->TremeloWave;
        if (Wave[0] == 0 && Wave[1] == 0) {
            in_pChannel->TremeloWave = Wave + Wave[2];
        }
        temp = ((Volume * (in_pChannel->TremeloDepth >> 8)) << 9) >> 16;
        Sample = *in_pChannel->TremeloWave++;
        temp = (temp * Sample) >> 15;
        if (temp != in_pChannel->TremeloVolume) {
            in_pChannel->TremeloVolume = temp;
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
        }
    }

    if ((UpdateFlags & SOUND_UPDATE_PAN_LFO)
        && (--in_pChannel->AutoPanRateCurrent == 0)) {
        in_pChannel->AutoPanRateCurrent = in_pChannel->AutoPanRatePhase;
        Wave = in_pChannel->AutoPanWave;
        if (Wave[0] == 0 && Wave[1] == 0) {
            in_pChannel->AutoPanWave = Wave + Wave[2];
        }
        Sample = *in_pChannel->AutoPanWave++;
        temp = ((in_pChannel->AutoPanDepth >> 8) * Sample) >> 15;
        if (temp != in_pChannel->AutoPanVolume) {
            in_pChannel->AutoPanVolume = temp;
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
        }
    }

    if (UpdateFlags & SOUND_UPDATE_SIDE_CHAIN_VOL) {
        Volume = ((short)((in_pChannel - 1)->VoiceParams.SampleRate * 2)
                     * (in_pChannel->VolumeBalance >> 8))
              >> 7;
        in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
    }

    if (in_pChannel->VoiceParams.VoiceParamFlags & VOICE_PARAM_VOLUME) {
        Volume += in_pChannel->TremeloVolume;
        Volume =
            (Volume * (int)(((u_int)g_pActiveMusicContext->MasterVolume >> 16) & 0x7F))
            >> 7;
        temp = ((in_pChannel->ChannelPan >> 8) + in_pChannel->AutoPanVolume) & 0xFF;
        if (D_80039AFC & 2) {
            in_pChannel->VoiceParams.Volume.right = (Volume * D_8002F89C) >> 15;
            in_pChannel->VoiceParams.Volume.left = in_pChannel->VoiceParams.Volume.right;
        } else {
            in_pChannel->VoiceParams.Volume.left =
                (Volume * g_Sound_StereoPanGainTableQ15[temp]) >> 15;
            in_pChannel->VoiceParams.Volume.right =
                (Volume * g_Sound_StereoPanGainTableQ15[temp ^ 0xFF]) >> 15;
        }
    }

    if (UpdateFlags & SOUND_UPDATE_SIDE_CHAIN_PITCH) {
        Sample = (in_pChannel - 1)->VoiceParams.SampleRate + in_pChannel->VibratoPitch
               + (in_pChannel->PitchSlide >> 16);
        temp = g_Sound_MasterPitchScaleQ16_16 & 0xFF0000;
        if (temp != 0) {
            temp >>= 16;
            if (temp < 0x80) {
                Sample += (Sample * temp) >> 7;
            } else {
                Sample = (Sample * temp) >> 8;
            }
        }
        in_pChannel->VoiceParams.SampleRate =
            (in_pChannel->FinePitchDelta + Sample) & 0x3FFF;
        in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_SAMPLE_RATE;
    } else if (in_pChannel->VoiceParams.VoiceParamFlags & VOICE_PARAM_SAMPLE_RATE) {
        Sample = in_pChannel->PitchBase + in_pChannel->VibratoPitch
               + (in_pChannel->PitchSlide >> 16);
        temp = g_Sound_MasterPitchScaleQ16_16 & 0xFF0000;
        if (temp != 0) {
            temp >>= 16;
            if (temp < 0x80) {
                Sample += (Sample * temp) >> 7;
            } else {
                Sample = (Sample * temp) >> 8;
            }
        }
        in_pChannel->VoiceParams.SampleRate =
            (in_pChannel->FinePitchDelta + Sample) & 0x3FFF;
    }
}

void func_800147CC(FSoundChannel* in_pChannel, int in_VoiceFlags __attribute__((unused)))
{
    short* Wave;
    int temp;
    int Volume = ((in_pChannel->Volume >> 16) * (in_pChannel->VolumeBalance >> 8)) >> 7;
    int Sample;
    u_int UpdateFlags = in_pChannel->UpdateFlags;

    if ((UpdateFlags & SOUND_UPDATE_VIBRATO)
        && (--in_pChannel->VibratoRateCurrent == 0)) {
        in_pChannel->VibratoRateCurrent = in_pChannel->VibratoRatePhase;
        Wave = in_pChannel->VibratoWave;
        if (Wave[0] == 0 && Wave[1] == 0) {
            in_pChannel->VibratoWave = Wave + Wave[2];
        }
        Sample = *in_pChannel->VibratoWave++;
        temp = (in_pChannel->VibratoBase * Sample) >> 16;
        if (temp != in_pChannel->VibratoPitch) {
            in_pChannel->VibratoPitch = temp;
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_SAMPLE_RATE;
            if (temp >= 0) {
                in_pChannel->VibratoPitch = temp * 2;
            }
        }
    }

    if ((UpdateFlags & SOUND_UPDATE_TREMOLO)
        && !(--in_pChannel->TremeloRateCurrent & 0xFFFF)) {
        in_pChannel->TremeloRateCurrent = in_pChannel->TremeloRatePhase;
        Wave = in_pChannel->TremeloWave;
        if (Wave[0] == 0 && Wave[1] == 0) {
            in_pChannel->TremeloWave = Wave + Wave[2];
        }
        temp = ((Volume * (in_pChannel->TremeloDepth >> 8)) << 9) >> 16;
        Sample = *in_pChannel->TremeloWave++;
        temp = (temp * Sample) >> 15;
        if (temp != in_pChannel->TremeloVolume) {
            in_pChannel->TremeloVolume = temp;
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
        }
    }

    if ((UpdateFlags & SOUND_UPDATE_PAN_LFO)
        && (--in_pChannel->AutoPanRateCurrent == 0)) {
        in_pChannel->AutoPanRateCurrent = in_pChannel->AutoPanRatePhase;
        Wave = in_pChannel->AutoPanWave;
        if (Wave[0] == 0 && Wave[1] == 0) {
            in_pChannel->AutoPanWave = Wave + Wave[2];
        }
        Sample = *in_pChannel->AutoPanWave++;
        temp = ((in_pChannel->AutoPanDepth >> 8) * Sample) >> 15;
        if (temp != in_pChannel->AutoPanVolume) {
            in_pChannel->AutoPanVolume = temp;
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
        }
    }

    if (UpdateFlags & SOUND_UPDATE_SIDE_CHAIN_VOL) {
        Volume = ((short)((in_pChannel - 1)->VoiceParams.SampleRate * 2)
                     * (in_pChannel->VolumeBalance >> 8))
              >> 7;
        in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
    }

    if (in_pChannel->VoiceParams.VoiceParamFlags & VOICE_PARAM_VOLUME) {
        Volume += in_pChannel->TremeloVolume;
        if (!(in_pChannel->unk_Flags & 0x2000000)) {
            Volume = (Volume * (in_pChannel->VolumeMod >> 8)) >> 7;
            temp = ((in_pChannel->ChannelPan + in_pChannel->PanMod) >> 8)
                 + in_pChannel->AutoPanVolume + 0x80;
            temp &= 0xFF;
        } else {
            temp = 0x80;
        }
        if (D_80039AFC & 2) {
            in_pChannel->VoiceParams.Volume.right = (Volume * D_8002F89C) >> 15;
            in_pChannel->VoiceParams.Volume.left = in_pChannel->VoiceParams.Volume.right;
        } else {
            in_pChannel->VoiceParams.Volume.left =
                (Volume * g_Sound_StereoPanGainTableQ15[temp]) >> 15;
            in_pChannel->VoiceParams.Volume.right =
                (Volume * g_Sound_StereoPanGainTableQ15[temp ^ 0xFF]) >> 15;
        }
    }

    if (UpdateFlags & SOUND_UPDATE_SIDE_CHAIN_PITCH) {
        Sample = (in_pChannel - 1)->VoiceParams.SampleRate + in_pChannel->VibratoPitch
               + (in_pChannel->PitchSlide >> 16);
        if (!(in_pChannel->unk_Flags & 0x2000000)) {
            temp = in_pChannel->PitchMod & 0xFF00;
            if (temp != 0) {
                temp >>= 8;
                if (temp < 0x80) {
                    Sample += (Sample * temp) >> 7;
                } else {
                    Sample = (Sample * temp) >> 8;
                }
            }
        }
        in_pChannel->VoiceParams.SampleRate =
            (in_pChannel->FinePitchDelta + Sample) & 0x3FFF;
        in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_SAMPLE_RATE;
    } else if (in_pChannel->VoiceParams.VoiceParamFlags & VOICE_PARAM_SAMPLE_RATE) {
        Sample = in_pChannel->PitchBase + in_pChannel->VibratoPitch
               + (in_pChannel->PitchSlide >> 16);
        if (!(in_pChannel->unk_Flags & 0x2000000)) {
            temp = in_pChannel->PitchMod & 0xFF00;
            if (temp != 0) {
                temp >>= 8;
                if (temp < 0x80) {
                    Sample += (Sample * temp) >> 7;
                } else {
                    Sample = (Sample * temp) >> 8;
                }
            }
        }
        in_pChannel->VoiceParams.SampleRate =
            (in_pChannel->FinePitchDelta + Sample) & 0x3FFF;
    }
}

void UnassignVoicesFromChannels(FSoundChannel* in_pChannel, int);

int Sound_StealQuietestVoice(int in_bForceFullScan)
{
    FSpuVoiceInfo* pVoiceInfo;
    short EnvX;
    int i;
    int out_VoiceIndex;

    if (in_bForceFullScan) {
        i = 0;
    } else {
        i = g_pActiveMusicContext->SomeIndexRelatedToSpuVoiceInfo;
    }

    EnvX = 0x7FFF;
    out_VoiceIndex = VOICE_COUNT;
    pVoiceInfo = &g_SpuVoiceInfo[i];

    do {
        if (pVoiceInfo->pEnvx < EnvX) {
            EnvX = pVoiceInfo->pEnvx;
            out_VoiceIndex = i;
        }
        i++;
        pVoiceInfo++;
    } while (i < VOICE_COUNT);

    if (EnvX == 0x7FFF) {
        return VOICE_COUNT;
    }
    UnassignVoicesFromChannels(g_ActiveMusicChannels, out_VoiceIndex);
    return out_VoiceIndex;
}

int Sound_FindFreeVoice(int arg0)
{
    FSpuVoiceInfo* var_v1;

    if (arg0 != 0) {
        arg0 = 0;
    } else {
        arg0 = g_pActiveMusicContext->SomeIndexRelatedToSpuVoiceInfo;
    }

    var_v1 = &g_SpuVoiceInfo[arg0];

    if (var_v1->pEnvx != 0) {
        ++arg0;
        while (1) {
            if (arg0 >= 0x18) {
                break;
            }
            ++var_v1;
            ++arg0;
            if (var_v1->pEnvx == 0) {
                --arg0;
                break;
            }
        }
    }
    return arg0;
}

void Sound_UpdateModulation(FSoundChannel*, int);

void Sound_AssignAndUpdateMusicVoice(
    FSoundChannel* in_pChannel, u_int in_Flags1, u_int in_Flags2, u_int* out_KeyOnFlags)
{
    int var_s2 = 1;
    int var_s5 = 0;
    int sp10 = in_Flags1 & g_pActiveMusicContext->PendingKeyOnMask;

    do {
        if (in_Flags1 & var_s2) {
            Sound_UpdateModulation(in_pChannel, var_s2);
            if (in_pChannel->VoiceParams.VoiceParamFlags != 0) {
                if (g_Sound_MutedMusicChannelMask & var_s2) {
                    in_pChannel->VoiceParams.Volume.right = 0;
                    in_pChannel->VoiceParams.Volume.left = 0;
                }
                if (sp10 & var_s2) {
                    if (in_Flags2 & var_s2) {
                        *out_KeyOnFlags |= 1 << var_s5;
                        in_pChannel->VoiceParams.AssignedVoiceNumber = var_s5;
                    } else {
                        int temp_s0 = g_pActiveMusicContext->KeyedMask & var_s2;
                        int var_a0 = Sound_FindFreeVoice(temp_s0);
                        if (var_a0 == 0x18) {
                            g_pActiveMusicContext->StatusFlags |= 2;
                            var_a0 = Sound_StealQuietestVoice(temp_s0);
                            if (var_a0 == 0x18) {
                                in_pChannel->VoiceParams.AssignedVoiceNumber = var_a0;
                                g_pActiveMusicContext->StatusFlags |= 1;
                            } else {
                                *out_KeyOnFlags |= 1 << var_a0;
                                in_pChannel->VoiceParams.AssignedVoiceNumber = var_a0;
                                g_SpuVoiceInfo[var_a0].pEnvx = 0x7FFF;
                            }
                        } else {
                            *out_KeyOnFlags |= 1 << var_a0;
                            in_pChannel->VoiceParams.AssignedVoiceNumber = var_a0;
                            g_SpuVoiceInfo[var_a0].pEnvx = 0x7FFF;
                        }
                    }
                    if (in_pChannel->VoiceParams.AssignedVoiceNumber < 0x18) {
                        SetVoiceParams(in_pChannel->VoiceParams.AssignedVoiceNumber,
                            &in_pChannel->VoiceParams,
                            in_pChannel->VoiceParams.VolumeScale);
                        g_Sound_VoiceOwnerContexts[in_pChannel->VoiceParams
                                .AssignedVoiceNumber] = g_pActiveMusicContext;
                        g_Sound_GlobalFlags.UpdateFlags |= 0x100;
                    }
                } else {
                    if (in_pChannel->VoiceParams.AssignedVoiceNumber < 0x18) {
                        SetVoiceParamsByFlags(
                            in_pChannel->VoiceParams.AssignedVoiceNumber,
                            &in_pChannel->VoiceParams, in_pChannel->UpdateFlags);
                    }
                }
            }
            in_Flags1 &= ~var_s2;
        }
        var_s2 *= 2;
        ++in_pChannel;
        ++var_s5;
    } while (in_Flags1 != 0);
}

void UnassignVoicesFromChannels(FSoundChannel* in_pChannel, int arg1)
{
    FSoundChannel* pChannel;
    u_int Count;

    Count = 0;
    pChannel = in_pChannel;

    do {
        if (arg1 == pChannel->VoiceParams.AssignedVoiceNumber) {
            pChannel->VoiceParams.AssignedVoiceNumber = VOICE_COUNT;
        }
        Count++;
        pChannel++;
    } while (Count < SOUND_CHANNEL_COUNT);

    Count = 0;

    if (g_pSuspendedMusicContext != NULL) {
        pChannel = g_pSecondaryMusicChannels;
        do {
            if (arg1 == pChannel->VoiceParams.AssignedVoiceNumber) {
                pChannel->VoiceParams.AssignedVoiceNumber = VOICE_COUNT;
            }
            Count++;
            pChannel++;
        } while (Count < SOUND_CHANNEL_COUNT);
    }
}

int func_8001503C(FSoundChannel* channels, int mask, int voiceNumber)
{
    u_int i;
    for (i = 0; i < 32; i++) {
        int v = 1;
        if (voiceNumber == channels[i].VoiceParams.AssignedVoiceNumber) {
            if (mask & (v << i)) {
                return 1;
            }
        }
    }
    return 0;
}

// https://decomp.me/scratch/VmgoV
void Sound_UpdateVoiceEnvelopeStates(u_int in_ReservedVoices)
{
    u_int i;
    u_int reserved = (g_pActiveMusicContext->ActiveChannelMask
                         & g_pActiveMusicContext->AllocatedVoiceMask)
                   | in_ReservedVoices;
    FSpuVoiceInfo* pVoice;

    if (g_pSuspendedMusicContext != NULL) {
        reserved |= g_pSuspendedMusicContext->ActiveChannelMask
                  & g_pSuspendedMusicContext->AllocatedVoiceMask;
    }

    for (i = 0, pVoice = g_SpuVoiceInfo; i < VOICE_COUNT; pVoice++, i++) {
        if (reserved & (1 << i)) {
            pVoice->pEnvx = 0x7FFF;
            continue;
        }
        SpuGetVoiceEnvelope(i, &pVoice->pEnvx);
        if (pVoice->pEnvx == 0) {
            UnassignVoicesFromChannels(g_ActiveMusicChannels, i);
        } else if (g_pActiveMusicContext->KeyedMask != 0) {
            if (func_8001503C(
                    g_ActiveMusicChannels, g_pActiveMusicContext->KeyedMask, i)) {
                pVoice->pEnvx = 0x7FFF;
            }
            if (g_pSuspendedMusicContext != NULL
                && func_8001503C(
                    g_pSecondaryMusicChannels, g_pSuspendedMusicContext->KeyedMask, i)) {
                pVoice->pEnvx = 0x7FFF;
            }
        }
    }
}

void Sound_ApplyMasterFadeToChannelVolume(
    FSoundMusicContext* in_Context, FSoundChannel* arg1 __attribute__((unused)))
{
    int Volume;

    Volume = in_Context->MasterVolume;
    g_Sound_MasterFadeTimer.SavedValue = in_Context->MasterVolume;
    Volume >>= 16;
    Volume *= g_Sound_MasterFadeTimer.Value >> 8;
    Volume /= 127;
    Volume <<= 8;
    in_Context->MasterVolume = Volume;
}

void Sound_RestoreChannelVolumeFromMasterFade(
    FSoundMusicContext* in_Config, FSoundChannel* arg1 __attribute__((unused)))
{
    in_Config->MasterVolume = g_Sound_MasterFadeTimer.SavedValue;
}

// https://decomp.me/scratch/0wUZ7
void func_80015220(void)
{
    u_int KeyOnFlags = 0;
    u_int ReservedVoices = g_Sound_SfxState.ActiveVoiceMask
                         | g_Sound_SfxState.SuspendedVoiceMask | D_80039B14;
    u_int Voices;
    u_int Flags;
    u_int SavedChannels;
    u_int SavedVoices;
    FSoundChannel* pChannel;

    if ((g_pActiveMusicContext->ActiveChannelMask
            & g_pActiveMusicContext->PendingKeyOnMask)
        || ((g_pSuspendedMusicContext != NULL)
            && (g_pSuspendedMusicContext->ActiveChannelMask
                & g_pSuspendedMusicContext->PendingKeyOnMask))) {
        Sound_UpdateVoiceEnvelopeStates(ReservedVoices);
    }

    if (g_pSuspendedMusicContext != NULL) {
        if (g_Sound_GlobalFlags.MixBehavior & 0x100) {
            Sound_ApplyMasterFadeToChannelVolume(
                g_pSuspendedMusicContext, g_pSecondaryMusicChannels);
        }

        g_pActiveMusicContext = g_pSuspendedMusicContext;
        SavedChannels = (g_pActiveMusicContext->ActiveChannelMask
                            & g_pActiveMusicContext->ActiveNoteMask)
                      & ~(g_pActiveMusicContext->AllocatedVoiceMask & ReservedVoices);
        SavedVoices =
            (SavedChannels & g_pActiveMusicContext->AllocatedVoiceMask) & ~ReservedVoices;
        if (SavedChannels & g_pActiveMusicContext->KeyedMask) {
            Sound_AssignAndUpdateMusicVoice(g_pSecondaryMusicChannels,
                SavedChannels & g_pActiveMusicContext->KeyedMask, SavedVoices,
                &KeyOnFlags);
            g_pActiveMusicContext->PendingKeyOnMask &= ~g_pActiveMusicContext->KeyedMask;
            SavedChannels &= ~g_pActiveMusicContext->KeyedMask;
        }

        g_pActiveMusicContext = &g_PrimaryMusicContext;
        Flags = (g_pActiveMusicContext->ActiveChannelMask
                    & g_pActiveMusicContext->ActiveNoteMask)
              & ~(g_pActiveMusicContext->AllocatedVoiceMask
                  & (SavedVoices | ReservedVoices));
        Voices = SavedVoices | ReservedVoices;
        Voices = (Flags & g_pActiveMusicContext->AllocatedVoiceMask) & ~Voices;
        if (Flags & g_pActiveMusicContext->KeyedMask) {
            Sound_AssignAndUpdateMusicVoice(g_ActiveMusicChannels,
                Flags & g_pActiveMusicContext->KeyedMask, Voices, &KeyOnFlags);
            g_pActiveMusicContext->PendingKeyOnMask &= ~g_pActiveMusicContext->KeyedMask;
            Flags &= ~g_pActiveMusicContext->KeyedMask;
        }

        if (SavedChannels != 0) {
            g_pActiveMusicContext = g_pSuspendedMusicContext;
            SavedVoices &= ~Voices;
            Sound_AssignAndUpdateMusicVoice(
                g_pSecondaryMusicChannels, SavedChannels, SavedVoices, &KeyOnFlags);
            g_pActiveMusicContext->PendingKeyOnMask = 0;
            g_pActiveMusicContext = &g_PrimaryMusicContext;
        }

        if (Flags != 0) {
            Sound_AssignAndUpdateMusicVoice(
                g_ActiveMusicChannels, Flags, Voices, &KeyOnFlags);
            g_pActiveMusicContext->PendingKeyOnMask = 0;
        }

        if (g_Sound_GlobalFlags.MixBehavior & 0x100) {
            Sound_RestoreChannelVolumeFromMasterFade(
                g_pSuspendedMusicContext, g_pSecondaryMusicChannels);
        }
    } else {
        Flags = (g_pActiveMusicContext->ActiveChannelMask
                    & g_pActiveMusicContext->ActiveNoteMask)
              & ~(g_pActiveMusicContext->AllocatedVoiceMask & ReservedVoices);
        Voices = (Flags & g_pActiveMusicContext->AllocatedVoiceMask) & ~ReservedVoices;
        if (Flags & g_pActiveMusicContext->KeyedMask) {
            Sound_AssignAndUpdateMusicVoice(g_ActiveMusicChannels,
                Flags & g_pActiveMusicContext->KeyedMask, Voices, &KeyOnFlags);
            g_pActiveMusicContext->PendingKeyOnMask &= ~g_pActiveMusicContext->KeyedMask;
            Flags &= ~g_pActiveMusicContext->KeyedMask;
        }
        if (Flags != 0) {
            Sound_AssignAndUpdateMusicVoice(
                g_ActiveMusicChannels, Flags, Voices, &KeyOnFlags);
            g_pActiveMusicContext->PendingKeyOnMask = 0;
        }
    }

    Flags = g_Sound_SfxState.ActiveVoiceMask & g_Sound_SfxState.KeyedFlags;
    if (Flags != 0) {
        KeyOnFlags |= g_Sound_SfxState.KeyOnFlags;
        for (Voices = 0x1000, pChannel = g_SfxSoundChannels; Flags != 0;
            Voices <<= 1, pChannel++) {
            if (Flags & Voices) {
                func_800147CC(pChannel, Voices);
                if (pChannel->VoiceParams.VoiceParamFlags != 0) {
                    SetVoiceParamsByFlags(pChannel->VoiceParams.AssignedVoiceNumber,
                        &pChannel->VoiceParams, pChannel->UpdateFlags);
                }
                Flags &= ~Voices;
            }
        }
        D_80037894 = 0;
    }

    Flags = g_Sound_GlobalFlags.UpdateFlags;
    if (Flags & 0x80) {
        SpuSetReverbModeDepth(
            g_pActiveMusicContext->RevDepth >> 12, g_pActiveMusicContext->RevDepth >> 12);
        g_Sound_GlobalFlags.UpdateFlags &= ~0x80;
    }
    if (Flags & 0x10) {
        if (g_Sound_SfxState.ActiveVoiceMask != 0) {
            SpuSetNoiseClock(g_Sound_SfxState.NoiseClock);
        } else {
            SpuSetNoiseClock(g_pActiveMusicContext->NoiseClock);
        }
        g_Sound_GlobalFlags.UpdateFlags &= ~0x10;
    }
    if (Flags & 0x100) {
        Sound_BuildVoiceModeMask(&g_Sound_VoiceModeFlags.Noise,
            g_pSuspendedMusicContext->NoiseChannelFlags,
            g_pActiveMusicContext->NoiseChannelFlags, g_Sound_SfxState.NoiseVoiceFlags);
        Sound_BuildVoiceModeMask(&g_Sound_VoiceModeFlags.Reverb,
            g_pSuspendedMusicContext->ReverbChannelFlags,
            g_pActiveMusicContext->ReverbChannelFlags, g_Sound_SfxState.ReverbVoiceFlags);
        Sound_BuildVoiceModeMask(&g_Sound_VoiceModeFlags.Fm,
            g_pSuspendedMusicContext->FmChannelFlags,
            g_pActiveMusicContext->FmChannelFlags, g_Sound_SfxState.FmVoiceFlags);
        SetVoiceReverbMode(g_Sound_VoiceModeFlags.Reverb);
        SetVoiceNoiseMode(g_Sound_VoiceModeFlags.Noise);
        SetVoiceFmMode(g_Sound_VoiceModeFlags.Fm);
        g_Sound_GlobalFlags.UpdateFlags &= ~0x100;
    }
    if (KeyOnFlags != 0) {
        SetVoiceKeyOn(KeyOnFlags);
    }
}

void ChannelMaskToVoiceMaskFiltered(FSoundChannel* in_Channel, int* io_VoiceMask,
    int in_ChannelMask, int in_VoiceMaskFilter)
{
    u_int bit = 1;

    do {
        if (in_ChannelMask & bit) {
            if (in_Channel->VoiceParams.AssignedVoiceNumber < VOICE_COUNT) {
                *io_VoiceMask |= 1 << in_Channel->VoiceParams.AssignedVoiceNumber;
            }
        }
        in_ChannelMask &= ~bit;
        in_Channel++;
        bit <<= 1;
    } while (in_ChannelMask != 0);

    *io_VoiceMask &= in_VoiceMaskFilter;
}

void Sound_ProcessKeyOffRequests(void)
{
    int VoiceMask;
    int SavedConfigKeyedMask;
    int ActiveKeyedMask;
    int Filter;
    int ActiveOffMask;
    int SavedOffMask;

    Filter = ~(g_Sound_SfxState.ActiveVoiceMask | g_Sound_SfxState.SuspendedVoiceMask
               | g_Sound_Cutscene_StreamState.VoicesInUseFlags);
    VoiceMask = 0;
    SavedOffMask = 0;

    if (g_pSuspendedMusicContext) {
        SavedOffMask = g_pSuspendedMusicContext->PendingKeyOffMask;
        SavedConfigKeyedMask = SavedOffMask & g_pSuspendedMusicContext->KeyedMask;

        if (SavedConfigKeyedMask != 0) {
            ChannelMaskToVoiceMaskFiltered(
                g_pSecondaryMusicChannels, &VoiceMask, SavedConfigKeyedMask, Filter);
            g_pSuspendedMusicContext->PendingKeyOffMask &=
                ~g_pSuspendedMusicContext->KeyedMask;
            SavedOffMask &= ~g_pSuspendedMusicContext->KeyedMask;
        }
    }

    ActiveOffMask = g_pActiveMusicContext->PendingKeyOffMask;
    ActiveKeyedMask = ActiveOffMask & g_pActiveMusicContext->KeyedMask;

    if (ActiveKeyedMask != 0) {
        ChannelMaskToVoiceMaskFiltered(
            g_ActiveMusicChannels, &VoiceMask, ActiveKeyedMask, Filter);
        g_pActiveMusicContext->PendingKeyOffMask &= ~g_pActiveMusicContext->KeyedMask;
        ActiveOffMask &= ~g_pActiveMusicContext->KeyedMask;
    }

    if (g_pSuspendedMusicContext && (SavedOffMask != 0)) {
        ChannelMaskToVoiceMaskFiltered(
            g_pSecondaryMusicChannels, &VoiceMask, SavedOffMask, Filter);
        g_pSuspendedMusicContext->PendingKeyOffMask = 0;
    }

    if (ActiveOffMask != 0) {
        ChannelMaskToVoiceMaskFiltered(
            g_ActiveMusicChannels, &VoiceMask, ActiveOffMask, Filter);
        g_pActiveMusicContext->PendingKeyOffMask = 0;
    }

    VoiceMask |= g_Sound_SfxState.KeyOffFlags;
    g_Sound_SfxState.KeyOffFlags = 0;

    if (VoiceMask != 0) {
        SetVoiceKeyOff(VoiceMask);
    }
}

void Sound_BuildVoiceModeMask(int* out_VoiceMask, int in_SavedChannelMask,
    int in_ActiveChannelMask, int in_ExtraVoiceMask)
{
    int VoiceMask = 0;
    int SavedKeyedMask;
    int ActiveKeyedMask;
    int Filter = ~(g_Sound_SfxState.ActiveVoiceMask | g_Sound_SfxState.SuspendedVoiceMask
                   | D_80039B14);
    int ActiveMask;
    int SavedMask = 0;

    if (g_pSuspendedMusicContext != NULL) {
        SavedMask = g_pSuspendedMusicContext->ActiveChannelMask & in_SavedChannelMask;
        SavedKeyedMask = SavedMask & g_pSuspendedMusicContext->KeyedMask;

        if (SavedKeyedMask != 0) {
            ChannelMaskToVoiceMaskFiltered(
                g_pSecondaryMusicChannels, &VoiceMask, SavedKeyedMask, Filter);
            SavedMask &= ~g_pSuspendedMusicContext->KeyedMask;
        }
    }

    ActiveMask = g_pActiveMusicContext->ActiveChannelMask & in_ActiveChannelMask;
    ActiveKeyedMask = ActiveMask & g_pActiveMusicContext->KeyedMask;

    if (ActiveKeyedMask != 0) {
        ChannelMaskToVoiceMaskFiltered(
            g_ActiveMusicChannels, &VoiceMask, ActiveKeyedMask, Filter);
        ActiveMask &= ~g_pActiveMusicContext->KeyedMask;
    }

    if ((g_pSuspendedMusicContext != NULL) && (SavedMask != 0)) {
        ChannelMaskToVoiceMaskFiltered(
            g_pSecondaryMusicChannels, &VoiceMask, SavedMask, Filter);
    }

    if (ActiveMask != 0) {
        ChannelMaskToVoiceMaskFiltered(
            g_ActiveMusicChannels, &VoiceMask, ActiveMask, Filter);
    }

    VoiceMask |= in_ExtraVoiceMask;
    *out_VoiceMask = VoiceMask;
    g_Sound_GlobalFlags.UpdateFlags |= 0x100;
}

// 0x20 toggles whether we use the alternate sample bank
#define SOUND_BANK_FLAG_ALT_SAMPLE_BANK (1u << 6) // 0x40

// the instrument index window that is eligible for bank remap
#define SOUND_BANK_REMAP_BASE_INDEX 0x20u // first remappable instrument
#define SOUND_BANK_REMAP_COUNT 0x60u // 64 instruments (0x20..0x5F)

// how far to shift SPU sample addresses when remapping
#define SOUND_BANK_SPU_ADDR_OFFSET 0x20000u

extern int D_80094FAC[];
extern int D_80094FFC;

u_short Sound_MapInstrumentToAltSampleBank(u_int in_Flags, FSoundChannel* in_pChannel)
{
    if (in_Flags & SOUND_BANK_FLAG_ALT_SAMPLE_BANK && 0x40 <= in_pChannel->InstrumentIndex
        && in_pChannel->InstrumentIndex < SOUND_BANK_REMAP_COUNT) {
        in_pChannel->VoiceParams.StartAddress += SOUND_BANK_SPU_ADDR_OFFSET;
        in_pChannel->VoiceParams.LoopAddress += SOUND_BANK_SPU_ADDR_OFFSET;
        in_pChannel->InstrumentIndex +=
            SOUND_BANK_REMAP_BASE_INDEX; // mirror into alt-bank instrument table
    }
    return in_pChannel->InstrumentIndex;
}

u_short Sound_MapInstrumentToBaseSampleBank(u_int in_Flags, FSoundChannel* in_Channel)
{
    if ((in_Flags & SOUND_BANK_FLAG_ALT_SAMPLE_BANK)
        && 0x60 <= in_Channel->InstrumentIndex && in_Channel->InstrumentIndex < 0x80) {
        in_Channel->VoiceParams.StartAddress -= SOUND_BANK_SPU_ADDR_OFFSET;
        in_Channel->VoiceParams.LoopAddress -= SOUND_BANK_SPU_ADDR_OFFSET;
        in_Channel->InstrumentIndex -= SOUND_BANK_REMAP_BASE_INDEX;
    }
    return in_Channel->InstrumentIndex;
}

void Sound_ReconcileSavedMusicVoices(void)
{
    FSoundChannel* pChannel;
    int voice;
    u_int bit;
    u_int bitCopy;
    u_int keyOff;
    u_int release;
    int count;
    u_int activeKeyed;
    u_int savedKeyed;

    if (g_pSuspendedMusicContext == NULL) {
        return;
    }

    activeKeyed =
        g_pActiveMusicContext->KeyedMask & g_pActiveMusicContext->AllocatedVoiceMask;
    savedKeyed = g_pSuspendedMusicContext->KeyedMask
               & g_pSuspendedMusicContext->AllocatedVoiceMask;

    voice = ~activeKeyed | savedKeyed;
    release = ~(g_pSuspendedMusicContext->AllocatedVoiceMask & voice);
    release &= g_pActiveMusicContext->AllocatedVoiceMask;
    release &= 0xFFFFFF;
    keyOff = 0;

    for (voice = 0; release != 0; ++voice) {
        bit = 1 << voice;

        if (!(release & bit)) {
            continue;
        }

        pChannel = g_pSecondaryMusicChannels;
        count = SOUND_CHANNEL_COUNT;
        bitCopy = bit;
        for (; count != 0; --count, ++pChannel) {
            if (pChannel->VoiceParams.AssignedVoiceNumber == voice) {
                pChannel->VoiceParams.AssignedVoiceNumber = VOICE_COUNT;
                keyOff |= bitCopy;
            }
        }

        release &= ~(1 << voice);
    }

    g_Sound_SfxState.KeyOffFlags |=
        keyOff & ~(g_Sound_SfxState.ActiveVoiceMask | D_80039B14);
}

void Sound_SetInstrumentToChannel(FSoundChannel* arg0, int arg1);

void Sound_ResetChannel(FSoundChannel* arg0, char* arg1)
{
    arg0->VolumeBalance = 0x6E00;
    arg0->Volume = 0x32000000;
    arg0->ProgramCounter = arg1;
    arg0->Transpose = 0;
    arg0->FineTune = 0;
    arg0->PortamentoSteps = 0;
    arg0->PitchSlide = 0;
    arg0->PitchBendSlideTranspose = 0;
    arg0->PitchSlideStepsCurrent = 0;
    arg0->FixedNoteLength = 0;
    arg0->LengthStored = 0;
    arg0->ChannelVolumeSlideLength = 0;
    arg0->FinePitchDelta = 0;
    arg0->RandomPitchDepth = 0;
    arg0->LoopStackTop = 0;
    arg0->UpdateFlags = 0;
    arg0->AutoPanVolume = 0;
    arg0->Articulation = 0;
    arg0->OpcodeStepCounter = 0xFFFF;
    arg0->VoiceParams.VolumeScale = 0;
    arg0->AutoPanDepth = 0;
    arg0->TremeloDepth = 0;
    arg0->VibratoDepth = 0;
    arg0->AutoPanDepthSlideLength = 0;
    arg0->TremeloDepthSlideLength = 0;
    arg0->VibratoDepthSlideLength = 0;
    arg0->FmTimer = 0;
    arg0->NoiseTimer = 0;
    Sound_SetInstrumentToChannel(arg0, 0);
}

u_int ChannelMaskToVoiceMask(FSoundChannel* arg0, u_int arg1)
{
    u_int i;
    u_int var_a3;

    for (i = 0, var_a3 = 0; i < 32; ++i) {
        if (arg1 & (1 << i)) {
            if (arg0->VoiceParams.AssignedVoiceNumber < 0x18) {
                var_a3 |= 1 << arg0->VoiceParams.AssignedVoiceNumber;
            }
        }
        ++arg0;
    }
    return var_a3;
}

void Sound_LoadAkaoSequence(FAkaoSequence* in_Sequence)
{
    u_int mask;
    u_int i;
    FSoundChannel* pChannel;
    FSoundMusicContext* pConfig;
    void* pRegion;
    FAkaoSequence* pSequence = in_Sequence;
    u_short* pChannelOffsets = (u_short*)in_Sequence;
    u_int channelMask;

    g_pActiveMusicContext->SequenceBase = (int)in_Sequence;
    channelMask = in_Sequence->ChannelEnableMask;

    if (g_pSuspendedMusicContext != NULL) {
        mask = ChannelMaskToVoiceMask(
            g_pSecondaryMusicChannels, g_pSuspendedMusicContext->ActiveChannelMask);
    } else {
        mask = 0;
    }

    g_Sound_SfxState.KeyOffFlags |=
        ~mask & 0xFFFFFF & ~(g_Sound_SfxState.ActiveVoiceMask | D_80039B14);
    pConfig = g_pActiveMusicContext;
    pConfig->PendingKeyOffMask = 0;

    if (D_80039B64 & 1) {
        pConfig->ActiveChannelMask = 0;
        pConfig->SuspendedChannelMask |= channelMask;
    } else {
        pConfig->SuspendedChannelMask = 0;
        pConfig->ActiveChannelMask |= channelMask;
    }

    g_pActiveMusicContext->KeyedMask = pSequence->KeyedMask;
    g_pActiveMusicContext->AllocatedVoiceMask = pSequence->AllocatedVoiceMask;
    g_pActiveMusicContext->StatusFlags &= ~0x61;
    g_pActiveMusicContext->StatusFlags |=
        pSequence->unk14 == D_80036770.unk4 ? 0x40 : 0x20;
    pRegion = (char*)&pSequence->PatchRegionOffset + pSequence->PatchRegionOffset;
    g_pActiveMusicContext->SequencePatchTable =
        pSequence->PatchRegionOffset != 0 ? pRegion : NULL;
    pRegion = (char*)&pSequence->KeymapRegionOffset + pSequence->KeymapRegionOffset;
    g_pActiveMusicContext->KeymapTable =
        pSequence->KeymapRegionOffset != 0 ? pRegion : NULL;
    g_pActiveMusicContext->SomeIndexRelatedToSpuVoiceInfo = 0;
    g_pActiveMusicContext->unk2C = pSequence->unk38;
    g_pActiveMusicContext->unk30 = pSequence->unk3C;

    mask = 1;
    i = 0;
    pChannel = g_ActiveMusicChannels;
    pChannelOffsets += 32;

    while (i < 32) {
        if (channelMask & mask) {
            int updateFlags;

            pChannel->ProgramCounter = (char*)pChannelOffsets + *pChannelOffsets;
            pChannel->NoteLength = 4;
            pChannel->KeyLength = 2;
            pChannel->VolumeBalance = 0x7F00;
            pChannel->Volume = 0x3FFF0000;
            pChannel->VolumeMod = 0x4000;
            pChannel->FineTune = 0;
            pChannel->Transpose = 0;
            pChannel->PortamentoSteps = 0;
            pChannel->PitchSlide = 0;
            pChannel->PitchBendSlideTranspose = 0;
            pChannel->PitchSlideStepsCurrent = 0;
            pChannel->FixedNoteLength = 0;
            pChannel->LengthStored = 0;
            pChannel->ChannelPan = 0x8000;
            pChannel->ChannelPanSlideLength = 0;
            pChannel->PortamentoSteps = 0;
            pChannel->VolumeModStepsRemaining = 0;
            pChannel->ChannelVolumeSlideLength = 0;
            pChannel->FinePitchDelta = 0;
            pChannel->RandomPitchDepth = 0;
            pChannel->KeyOnVolumeSlideLength = 0;
            pChannel->Articulation = 0;
            pChannel->AutoPanVolume = 0;
            pChannel->LoopStackTop = 0;
            updateFlags = !(g_pActiveMusicContext->AllocatedVoiceMask & mask) << 6;
            pChannel->AutoPanDepth = 0;
            pChannel->TremeloDepth = 0;
            pChannel->VibratoDepth = 0;
            pChannel->AutoPanDepthSlideLength = 0;
            pChannel->UpdateFlags = updateFlags;
            pChannel->TremeloDepthSlideLength = 0;
            pChannel->VibratoDepthSlideLength = 0;
            pChannel->FmTimer = 0;
            pChannel->NoiseTimer = 0;
            ++pChannelOffsets;
            Sound_SetInstrumentToChannel(pChannel, 0);
        } else {
            pChannel->NoteLength = 3;
            pChannel->KeyLength = 1;
            pChannel->ProgramCounter = (char*)&g_Sound_ProgramCounter;
            pChannel->VoiceParams.VoiceParamFlags |= 0x4400;
            pChannel->VoiceParams.AdsrUpper =
                (pChannel->VoiceParams.AdsrUpper & 0xFFE0) | 5;
        }

        pChannel->VoiceParams.AssignedVoiceNumber = VOICE_COUNT;
        channelMask &= ~mask;
        ++pChannel;
        ++i;
        mask <<= 1;
    }

    g_pActiveMusicContext->Tempo = 0xFFFF0000;
    g_pActiveMusicContext->TempoUpdate = 1;
    g_pActiveMusicContext->TempoSlideLength = 0;
    g_pActiveMusicContext->RevDepth = 0;
    g_pActiveMusicContext->ReverbDepthSlideLength = 0;
    g_pActiveMusicContext->ReverbDepthSlideStep = 0;
    g_pActiveMusicContext->TimerLowerCurrent = 0;
    g_pActiveMusicContext->TimerLower = 0;
    g_pActiveMusicContext->TimerUpperCurrent = 0;
    g_pActiveMusicContext->TimerTopCurrent = 0;
    g_pActiveMusicContext->NoiseChannelFlags = 0;
    g_pActiveMusicContext->ReverbChannelFlags = 0;
    g_pActiveMusicContext->FmChannelFlags = 0;
    g_pActiveMusicContext->JumpThreshold = 0;
    g_pActiveMusicContext->ActiveNoteMask = 0;
    g_pActiveMusicContext->PendingKeyOnMask = 0;
    g_Sound_GlobalFlags.UpdateFlags |= 0x100;
}

void Sound_KillMusicContext(
    FSoundMusicContext* in_Config, FSoundChannel* in_pChannel, u_int arg2)
{
    FSoundChannel* pChannel;
    FSoundMusicContext** ppThisChannelConfig;
    u_int Count;

    pChannel = in_pChannel;
    if ((in_Config->ActiveChannelMask != 0)
        && ((arg2 == 0) || (arg2 == in_Config->MusicId))) {
        in_Config->PendingKeyOffMask = -1;
        for (Count = SOUND_CHANNEL_COUNT; Count != 0; Count--) {
            pChannel->NoteLength = 3;
            pChannel->KeyLength = 1;
            pChannel->ProgramCounter = (char*)&g_Sound_ProgramCounter;
            pChannel++;
        };

        ppThisChannelConfig = g_Sound_VoiceOwnerContexts;
        in_Config->MusicId = 0;
        in_Config->ActiveNoteMask = 0;
        in_Config->PendingKeyOnMask = 0;

        for (Count = 0; Count < VOICE_COUNT; Count++) {
            if (*ppThisChannelConfig == in_Config) {
                *ppThisChannelConfig = NULL;
                SetVoiceAdsrReleaseRateAndMode(Count, 5, 3U);
            }
            ppThisChannelConfig++;
        };
    }
}

void Sound_EvictSfxVoice(int in_SfxId, int in_StopFlags)
{
    u_int i;
    int maxPriority;
    u_int voiceBit = 0x1000;
    u_int activeVoices =
        g_Sound_SfxState.ActiveVoiceMask | g_Sound_SfxState.SuspendedVoiceMask;
    FSoundChannel* pChannel = g_SfxSoundChannels;

    if (in_StopFlags & 0x0FFFFFFF) {
        for (i = 0; i < 12; i++, pChannel++, voiceBit <<= 1) {
            if ((activeVoices & voiceBit) && (pChannel->unk_Flags & in_StopFlags)) {
                if (pChannel->UpdateFlags & 0x100000) {
                    pChannel->UpdateFlags |= 0x200000;
                } else {
                    g_Sound_SfxState.KeyOffFlags |= voiceBit;
                    Sound_ClearVoiceFromSfxState(pChannel, voiceBit);
                    pChannel->UpdateFlags = 0;
                }
            }
        }
    } else if (in_StopFlags < 0) {
        pChannel += in_SfxId;
        voiceBit <<= in_SfxId;
        if (activeVoices & voiceBit) {
            Sound_EvictSfxVoice(pChannel->AkaoProgramIndex, 0);
        }
        voiceBit <<= 1;
        pChannel++;
        if (activeVoices & voiceBit) {
            Sound_EvictSfxVoice(pChannel->AkaoProgramIndex, 0);
        }
        return;
    } else if (in_StopFlags & 0x40000000) {
        for (i = 0; i < 12; i++, pChannel++, voiceBit <<= 1) {
            if (pChannel->unk_Flags != 0) {
                activeVoices &= ~voiceBit;
            }
        }
        pChannel = g_SfxSoundChannels;
        voiceBit = 0x1000;
        maxPriority = 0;
        for (i = 0; i < 12; i++, pChannel++, voiceBit <<= 1) {
            if ((activeVoices & voiceBit) && (maxPriority < pChannel->Priority)) {
                maxPriority = pChannel->Priority;
            }
        }
        pChannel = g_SfxSoundChannels;
        voiceBit = 0x1000;
        for (i = 0; i < 12; i++, pChannel++, voiceBit <<= 1) {
            if ((activeVoices & voiceBit) && (maxPriority == pChannel->Priority)) {
                if (pChannel->UpdateFlags & 0x100000) {
                    pChannel->UpdateFlags |= 0x200000;
                } else {
                    g_Sound_SfxState.KeyOffFlags |= voiceBit;
                    Sound_ClearVoiceFromSfxState(pChannel, voiceBit);
                    pChannel->UpdateFlags = 0;
                }
            }
        }
    } else {
        for (i = 0; i < 12; i++, pChannel++, voiceBit <<= 1) {
            if (!(activeVoices & voiceBit)) {
                continue;
            }
            if (in_SfxId == -1) {
                if (pChannel->AkaoProgramIndex < 0) {
                    if (pChannel->UpdateFlags & 0x100000) {
                        pChannel->UpdateFlags |= 0x200000;
                    } else {
                        g_Sound_SfxState.KeyOffFlags |= voiceBit;
                        Sound_ClearVoiceFromSfxState(pChannel, voiceBit);
                        pChannel->UpdateFlags = 0;
                    }
                }
            } else if (in_SfxId == -2) {
                if (pChannel->unk_Flags == 0) {
                    if (pChannel->UpdateFlags & 0x100000) {
                        pChannel->UpdateFlags |= 0x200000;
                    } else {
                        g_Sound_SfxState.KeyOffFlags |= voiceBit;
                        Sound_ClearVoiceFromSfxState(pChannel, voiceBit);
                        pChannel->UpdateFlags = 0;
                    }
                }
            } else if (pChannel->AkaoProgramIndex == in_SfxId) {
                if (pChannel->UpdateFlags & 0x100000) {
                    pChannel->UpdateFlags |= 0x200000;
                } else {
                    g_Sound_SfxState.KeyOffFlags |= voiceBit;
                    Sound_ClearVoiceFromSfxState(pChannel, voiceBit);
                    pChannel->UpdateFlags = 0;
                }
            }
        }
    }
    g_Sound_GlobalFlags.UpdateFlags |= 0x110;
}

void func_8001653C(FSoundChannel* in_Channel, FSoundCommandParams* in_CommandParams,
    int in_VoiceBit, char* in_ProgramCounter)
{
    u_int i;
    int pan;
    int volume;
    int voiceMask;

    in_Channel->AkaoProgramIndex = in_CommandParams->Param1;
    in_Channel->unk_Flags = in_CommandParams->Param2;
    pan = (u_char)in_CommandParams->Param3 << 8;
    in_Channel->PanModStepsRemaining = 0;
    in_Channel->ChannelPan = 0x8000;
    in_Channel->ChannelPanSlideLength = 0;
    in_Channel->PanMod = pan;
    volume = ((u_short)in_CommandParams->Param4 & 0x7F) << 8;
    in_Channel->VolumeModStepsRemaining = 0;
    in_Channel->VolumeMod = volume;
    voiceMask = 1 << in_CommandParams->ExtParam1;
    in_Channel->NoteLength = 2;
    in_Channel->unk38 = voiceMask;
    in_Channel->KeyLength = 1;
    in_Channel->Type = 1;
    in_Channel->Priority = -2;
    in_Channel->PitchMod = 0;
    in_Channel->PitchModStepsRemaining = 0;
    Sound_ResetChannel(in_Channel, in_ProgramCounter);
    g_Sound_VoiceOwnerContexts[in_Channel->VoiceParams.AssignedVoiceNumber] = NULL;
    SetVoiceAdsrReleaseRateAndMode(in_Channel->VoiceParams.AssignedVoiceNumber, 5, 3);

    g_Sound_SfxState.ActiveVoiceMask |= in_VoiceBit;
    g_Sound_SfxState.KeyOffFlags |= in_VoiceBit;
    in_VoiceBit = ~in_VoiceBit;
    g_Sound_SfxState.KeyOnFlags &= in_VoiceBit;
    g_Sound_SfxState.KeyedFlags &= in_VoiceBit;
    g_Sound_SfxState.NoiseVoiceFlags &= in_VoiceBit;
    g_Sound_SfxState.ReverbVoiceFlags &= in_VoiceBit;
    g_Sound_SfxState.FmVoiceFlags &= in_VoiceBit;

    if (D_80039B64 & 2) {
        in_VoiceBit = 0x1000;
        in_Channel = g_SfxSoundChannels;
        for (i = 12; i != 0; i--, in_Channel++, in_VoiceBit <<= 1) {
            if ((g_Sound_SfxState.ActiveVoiceMask & in_VoiceBit)
                && !(in_Channel->unk_Flags & 0x02000000)) {
                g_Sound_SfxState.ActiveVoiceMask &= ~in_VoiceBit;
                g_Sound_SfxState.SuspendedVoiceMask |= in_VoiceBit;
            }
        }
    }
}

void FreeVoiceChannels(FSoundChannel* in_Channel, u_int in_Voice)
{
    u_int VoiceIndex;

    if (in_Voice < VOICE_COUNT) {
        VoiceIndex = 0;
        while (VoiceIndex < SOUND_CHANNEL_COUNT) {
            if (in_Channel->VoiceParams.AssignedVoiceNumber == in_Voice) {
                in_Channel->VoiceParams.AssignedVoiceNumber = VOICE_COUNT;
                g_pActiveMusicContext->ActiveNoteMask &= ~(1 << VoiceIndex);
            }
            in_Channel++;
            VoiceIndex++;
        };
    }
}

#define SOUND_UPDATE_STEREO_LINKED (1 << 16) // Second channel of stereo pair

void Sound_PlaySfxProgram(FSoundCommandParams* in_CommandParams, char* in_ProgramCounter1,
    char* in_ProgramCounter2, int in_SkipRelease)
{
    FSoundChannel* channel;
    int activeVoices;
    int slotsRemaining;
    u_int voiceBit;

    if ((in_ProgramCounter1 == NULL) && (in_ProgramCounter2 == NULL)) {
        return;
    }

    if ((in_SkipRelease == 0) && (in_CommandParams->Param2 != 0)) {
        Sound_EvictSfxVoice(0, in_CommandParams->Param2);
    }

    while (1) {
        channel = &g_SfxSoundChannels[10];
        voiceBit = 0x400000;

        activeVoices = g_Sound_SfxState.ActiveVoiceMask
                     | g_Sound_SfxState.SuspendedVoiceMask
                     | g_Sound_Cutscene_StreamState.VoicesInUseFlags;

        for (slotsRemaining = 0xC; slotsRemaining != 0;
            slotsRemaining -= 2, channel -= 2, voiceBit /= 4) {
            if (!(activeVoices & (voiceBit | (voiceBit * 2)))) {
                break;
            }
        }

        if (slotsRemaining != 0) {
            break;
        }

        Sound_EvictSfxVoice(0, 0x40000000);

        if (activeVoices
            == (g_Sound_SfxState.ActiveVoiceMask | g_Sound_SfxState.SuspendedVoiceMask
                | g_Sound_Cutscene_StreamState.VoicesInUseFlags)) {
            return;
        }
    }

    if (in_ProgramCounter1 != NULL) {
        func_8001653C(channel, in_CommandParams, voiceBit, in_ProgramCounter1);
        FreeVoiceChannels(
            g_ActiveMusicChannels, channel->VoiceParams.AssignedVoiceNumber);
    }

    if (in_ProgramCounter2 != NULL) {
        if (in_ProgramCounter1 != NULL) {
            ++channel;
            voiceBit *= 2;
        }

        func_8001653C(channel, in_CommandParams, voiceBit, in_ProgramCounter2);
        FreeVoiceChannels(
            g_ActiveMusicChannels, channel->VoiceParams.AssignedVoiceNumber);

        if (in_ProgramCounter1 != NULL) {
            channel->UpdateFlags |= SOUND_UPDATE_STEREO_LINKED;
        }
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_04 | SOUND_GLOBAL_UPDATE_08;
}

void Sound_GetProgramCounters(
    char** out_ProgramCounter1, char** out_ProgramCounter2, int in_SfxIndex)
{
    char* block2;
    u_short* block0;

    in_SfxIndex &= 0x3FF;
    in_SfxIndex *= 2;
    block2 = g_Sound_Sfx_ProgramData;
    block0 = (u_short*)g_Sound_Sfx_ProgramOffsets;

    *out_ProgramCounter1 =
        block0[in_SfxIndex] == 0xFFFF ? NULL : block2 + block0[in_SfxIndex];

    ++in_SfxIndex;

    *out_ProgramCounter2 =
        block0[in_SfxIndex] == 0xFFFF ? NULL : block2 + block0[in_SfxIndex];
}

void Sound_MarkActiveChannelsVolumeDirty(
    FSoundMusicContext* in_pChannelConfig, FSoundChannel* in_pChannel)
{
    u_int ActiveChannelMask;
    u_int Flags;
    u_int Mask;

    ActiveChannelMask = in_pChannelConfig->ActiveChannelMask;
    if (ActiveChannelMask == 0) {
        return;
    }

    Flags = ActiveChannelMask;
    Mask = 1;

    while (Flags != 0) {
        if (Flags & Mask) {
            in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
            Flags ^= Mask;
        }
        in_pChannel++;
        Mask <<= 1;
    }
}

void Sound_MarkScheduledSfxChannelsVolumeDirty(void)
{
    u_int Mask;
    u_int ActiveChannelMask;
    FSoundChannel* pChannel = g_SfxSoundChannels;

    if (g_Sound_SfxState.ActiveVoiceMask == 0) {
        return;
    }

    ActiveChannelMask = g_Sound_SfxState.ActiveVoiceMask;

    Mask = (1 << 12); // SFX Channels start at channel 12
    while (ActiveChannelMask != 0) {
        if (ActiveChannelMask & Mask) {
            ActiveChannelMask ^= Mask;
            pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
        }
        pChannel++;
        Mask <<= 1;
    };
}

void Sound_SetMusicSequence(FAkaoSequence* in_Sequence, int in_SwapWithSavedState)
{
    int delta;
    u_int mask;
    u_int channelBit;
    int count;
    FSoundChannel* pChannel;
    FSoundMusicContext* pConfig;

    if (in_SwapWithSavedState == 0) {
        memcpy32(&g_SuspendedMusicContext, &g_PrimaryMusicContext, 0x80);
        memcpy32(
            g_PushedMusicChannels, g_ActiveMusicChannels, sizeof g_ActiveMusicChannels);
    } else {
        memswap32(&g_SuspendedMusicContext, &g_PrimaryMusicContext, 0x80);
        memswap32(
            g_PushedMusicChannels, g_ActiveMusicChannels, sizeof g_ActiveMusicChannels);
    }

    g_pActiveMusicContext->StatusFlags &= ~0x60;
    g_pActiveMusicContext->StatusFlags |=
        in_Sequence->unk14 == D_80036770.unk4 ? 0x40 : 0x20;

    delta = (int)in_Sequence - g_PrimaryMusicContext.SequenceBase;
    g_pActiveMusicContext->SequenceBase = (int)in_Sequence;
    g_pActiveMusicContext->PendingKeyOnMask = 0;
    g_Sound_GlobalFlags.UpdateFlags |= 0x90;
    g_pActiveMusicContext->SequencePatchTable =
        (FAkaoSequence*)((char*)g_pActiveMusicContext->SequencePatchTable + delta);
    mask = g_pActiveMusicContext->ActiveChannelMask;
    g_pActiveMusicContext->KeymapTable =
        (u_short*)((char*)g_pActiveMusicContext->KeymapTable + delta);
    g_pActiveMusicContext->PendingKeyOnMask = g_pActiveMusicContext->ActiveNoteMask;
    pChannel = g_ActiveMusicChannels;

    for (count = 32, channelBit = 1; count != 0; --count, ++pChannel, channelBit <<= 1) {
        if (mask & channelBit) {
            pChannel->ProgramCounter += delta;
            pChannel->Keymap += delta;
            pChannel->LoopStartPc[0] += delta;
            pChannel->LoopStartPc[1] += delta;
            pChannel->LoopStartPc[2] += delta;
            pChannel->LoopStartPc[3] += delta;
            pChannel->NoteLength += 2;
            pChannel->KeyLength += 2;
            pChannel->VoiceParams.VoiceParamFlags |= 0x1FF93;
            Sound_MapInstrumentToAltSampleBank(
                g_pActiveMusicContext->StatusFlags, pChannel);
        } else {
            pChannel->NoteLength = 4;
            pChannel->KeyLength = 2;
            pChannel->ProgramCounter = (char*)&g_Sound_ProgramCounter;
        }

        pChannel->VoiceParams.AssignedVoiceNumber = VOICE_COUNT;
    }

    if (g_pSuspendedMusicContext != NULL) {
        mask = ChannelMaskToVoiceMask(
            g_pSecondaryMusicChannels, g_pSuspendedMusicContext->ActiveChannelMask);
    } else {
        mask = 0;
    }

    pConfig = g_pActiveMusicContext;
    pConfig->PendingKeyOffMask = 0;
    g_SuspendedMusicContext.MusicId = 0;
    g_Sound_SfxState.KeyOffFlags |=
        ~mask & 0xFFFFFF & ~(g_Sound_SfxState.ActiveVoiceMask | D_80039B14);
    g_Sound_GlobalFlags.UpdateFlags |= 0x100;

    if (in_SwapWithSavedState != 0) {
        delta = pConfig->RevDepth
              + pConfig->ReverbDepthSlideStep * pConfig->ReverbDepthSlideLength;
        channelBit = 48;
        delta &= ~0xFFF;

        if (pConfig->ReverbDepthSlideLength != 0) {
            channelBit = pConfig->ReverbDepthSlideLength;
        }

        if (g_pSuspendedMusicContext != NULL) {
            pConfig->RevDepth = g_pSuspendedMusicContext->RevDepth;
        }

        g_pActiveMusicContext->RevDepth &= ~0xFFF;
        delta -= g_pActiveMusicContext->RevDepth;

        if (delta != 0) {
            g_pActiveMusicContext->ReverbDepthSlideStep = delta / (int)channelBit;
            g_pActiveMusicContext->ReverbDepthSlideLength = channelBit;
        } else {
            g_pActiveMusicContext->ReverbDepthSlideLength = 0;
        }
    }

    if (D_80039B64 & 1) {
        g_pActiveMusicContext->SuspendedChannelMask =
            g_pActiveMusicContext->ActiveChannelMask;
        g_pActiveMusicContext->ActiveChannelMask = 0;
    }
}

int func_80016DA8(int flags)
{
    int var_v1 = 0;

    flags &= 0x7FFF;

    if (flags == 0) {
        return 0;
    }
    if (flags == D_800377E0[1]) {
        var_v1 = 1;
    } else if (flags == D_800377E0[2]) {
        var_v1 = 2;
    }
    return var_v1;
}

void Sound_Cmd_10_StartFieldMusic(FSoundCommandParams* in_Params)
{
    if ((g_SuspendedMusicContext.MusicId != 0)
        && (g_SuspendedMusicContext.MusicId == in_Params->Param3)) {
        Sound_SetMusicSequence((FAkaoSequence*)in_Params->Param1, 0);
        return;
    }
    Sound_LoadAkaoSequence((FAkaoSequence*)in_Params->Param1);
    g_pActiveMusicContext->MusicId = in_Params->Param3;
}

void Sound_Cmd_40_PushMusicState(void)
{
    u_int i;

    if (g_pActiveMusicContext->ActiveChannelMask != 0) {
        FSoundChannel* c;
        memcpy32(&g_PrimaryMusicContext, &g_SuspendedMusicContext, 0x80);
        memcpy32(
            g_ActiveMusicChannels, (FSoundMusicContext*)g_PushedMusicChannels, 0x2200);
        for (i = 0, c = g_PushedMusicChannels; i < 32; ++i, ++c) {
            Sound_MapInstrumentToBaseSampleBank(g_SuspendedMusicContext.StatusFlags, c);
        }
    }
}

void Sound_Cmd_19_SetMusicLevelImmediate(FSoundCommandParams* arg0)
{
    if ((g_pActiveMusicContext->ActiveChannelMask != 0)
        && ((g_pSuspendedMusicContext == NULL)
            || (g_pSuspendedMusicContext->MusicId == 0))) {
        g_pSuspendedMusicContext = &g_SuspendedMusicContext;
        g_pSecondaryMusicChannels = g_PushedMusicChannels;
        memcpy32(&g_PrimaryMusicContext, &g_SuspendedMusicContext, 0x80);
        memcpy32(g_ActiveMusicChannels, (FSoundMusicContext*)g_pSecondaryMusicChannels,
            0x2200);
    }
    Sound_LoadAkaoSequence((FAkaoSequence*)arg0->Param1);
    g_pActiveMusicContext->MasterVolume = (arg0->ExtParam1 & 0x7F) << 0x10;
    g_pActiveMusicContext->MasterVolumeStepsRemaining = 0;
    g_pActiveMusicContext->MusicId = arg0->Param3;
    Sound_ReconcileSavedMusicVoices();
    g_Sound_GlobalFlags.MixBehavior &= ~0x100;
}

void Sound_Cmd_1A_StartMasterAndMusicVolumeFade(FSoundCommandParams* arg0)
{
    if ((g_SuspendedMusicContext.MusicId != 0)
        && (g_SuspendedMusicContext.MusicId == arg0->Param3)) {
        g_pSuspendedMusicContext = &g_SuspendedMusicContext;
        g_pSecondaryMusicChannels = g_PushedMusicChannels;
        Sound_SetMusicSequence((FAkaoSequence*)arg0->Param1, 1);
    } else {
        if ((g_pActiveMusicContext->ActiveChannelMask != 0)
            && ((g_pSuspendedMusicContext == NULL)
                || (g_pSuspendedMusicContext->MusicId == 0))) {
            g_pSuspendedMusicContext = &g_SuspendedMusicContext;
            g_pSecondaryMusicChannels = g_PushedMusicChannels;
            memcpy32(&g_PrimaryMusicContext, &g_SuspendedMusicContext, 0x80);
            memcpy32(g_ActiveMusicChannels,
                (FSoundMusicContext*)g_pSecondaryMusicChannels, 0x2200);
        }
        Sound_LoadAkaoSequence((FAkaoSequence*)arg0->Param1);
        g_pActiveMusicContext->MusicId = arg0->Param3;
    }
    g_Sound_GlobalFlags.MixBehavior &= ~0x100;
    if (g_pSuspendedMusicContext != NULL) {
        int temp_a1 = arg0->ExtParam1;
        g_Sound_MasterFadeTimer.Value = 0x7F0000;
        g_Sound_GlobalFlags.MixBehavior |= 0x100;
        g_Sound_MasterFadeTimer.TicksRemaining = temp_a1;
        g_Sound_MasterFadeTimer.Step = (int)0xFF810000 / temp_a1;
    }
    g_pActiveMusicContext->MasterVolume = 0;
    g_pActiveMusicContext->MasterVolumeStepsRemaining = arg0->ExtParam1;
    g_pActiveMusicContext->MasterVolumeStep =
        ((arg0->ExtParam2 & 0x7F) << 0x10) / arg0->ExtParam1;
    Sound_ReconcileSavedMusicVoices();
}

void Sound_Cmd_12_PlayFieldMusicLooped(FSoundCommandParams* in_Params)
{
    int LoopCounter;

    Sound_Cmd_10_StartFieldMusic(in_Params);
    LoopCounter = 0;
    if (in_Params->Param4 != 0) {
        LoopCounter = in_Params->Param4 - 1;
    }
    g_Music_LoopCounter = LoopCounter;
}

void Sound_Cmd_34_PlaySfxDirect(FSoundCommandParams* arg0)
{
    char* temp_a1;
    char* temp_a2;

    temp_a1 = (char*)arg0->Param1;
    temp_a2 = (char*)arg0->Param2;
    arg0->Param1 = 0x400;
    arg0->Param2 = 0x01000000;
    arg0->Param3 = 0x80;
    arg0->Param4 = 0x7F;
    arg0->ExtParam1 = 0;
    Sound_PlaySfxProgram(arg0, temp_a1, temp_a2, 0);
}

void Sound_Cmd_30_PlaySfxProtected(FSoundCommandParams* arg0)
{
    char* sp10;
    char* sp14;

    Sound_GetProgramCounters(&sp10, &sp14, arg0->Param1);
    arg0->Param2 = 0x02000000;
    arg0->Param3 = 0x80;
    arg0->Param4 = 0x7F;
    arg0->ExtParam1 = func_80016DA8(g_Sound_Sfx_MetadataTableA[arg0->Param1]);
    Sound_PlaySfxProgram(arg0, sp10, sp14, 0);
}

void Sound_Cmd_20_PlaySfx(FSoundCommandParams* arg0)
{
    char* akaoOffset;
    char* akaoData;

    Sound_GetProgramCounters(&akaoOffset, &akaoData, arg0->Param1);
    arg0->ExtParam1 = func_80016DA8(g_Sound_Sfx_MetadataTableA[arg0->Param1]);
    Sound_PlaySfxProgram(arg0, akaoOffset, akaoData, 0);
}

void Sound_Cmd_24_PlaySfxFromPointer(FSoundCommandParams* in_Params)
{
    func_8001733C_t* header;
    int* offsets;
    char* data;
    u_short* entry;
    char* programCounter1;
    char* programCounter2;
    int count;

    in_Params->ExtParam1 = func_80016DA8(((func_8001733C_t*)in_Params->Param1)->flags);
    header = (func_8001733C_t*)in_Params->Param1;
    offsets = header->offsets;
    count = header->count;
    data = (char*)header;
    data += sizeof *header;

    entry = (u_short*)(data + *offsets);
    programCounter1 = *entry == 65535 ? NULL : (char*)(*entry + (int)entry + 4);
    ++entry;
    programCounter2 = *entry == 65535 ? NULL : (char*)(*entry + (int)entry + 2);
    Sound_PlaySfxProgram(in_Params, programCounter1, programCounter2, 0);

    while (--count != 0) {
        ++offsets;
        entry = (u_short*)(data + *offsets);
        programCounter1 = *entry == 65535 ? NULL : (char*)(*entry + (int)entry + 4);
        ++entry;
        programCounter2 = *entry == 65535 ? NULL : (char*)(*entry + (int)entry + 2);
        Sound_PlaySfxProgram(in_Params, programCounter1, programCounter2, 1);
    }
}

void Sound_Cmd_21_EvictSfxVoice(FSoundCommandParams* arg0)
{
    Sound_EvictSfxVoice(arg0->Param1, arg0->Param2);
}

void Sound_Cmd_C0_SetMasterVolumeByMusicId(FSoundCommandParams* arg0)
{
    FSoundChannel* var_a1;
    FSoundMusicContext* var_a0;
    int temp_v1;

    temp_v1 = arg0->Param1;
    if ((temp_v1 == 0) || (temp_v1 == g_pActiveMusicContext->MusicId)) {
        var_a0 = g_pActiveMusicContext;
        var_a1 = g_ActiveMusicChannels;
        var_a0->MasterVolume = (arg0->Param2 & 0x7F) << 0x10;
        var_a0->MasterVolumeStepsRemaining = 0;
        Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
    } else {
        var_a0 = g_pSuspendedMusicContext;
        if ((var_a0 != NULL) && (temp_v1 != 0) && (temp_v1 == var_a0->MusicId)) {
            var_a1 = g_pSecondaryMusicChannels;
            var_a0->MasterVolume = (arg0->Param2 & 0x7F) << 0x10;
            var_a0->MasterVolumeStepsRemaining = 0;
            Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
        }
    }
}

void Sound_Cmd_C1_FadeMasterVolumeByMusicId(FSoundCommandParams* arg0)
{
    FSoundChannel* var_a1;
    FSoundMusicContext* var_a0;
    int temp_a1;
    int var_v1;

    int var_a2 = 1;

    if (arg0->Param2 != 0) {
        var_a2 = arg0->Param2;
    }

    temp_a1 = arg0->Param1;
    var_v1 = (arg0->Param3 & 0x7F) << 0x10;

    if ((temp_a1 == 0) || (temp_a1 == g_pActiveMusicContext->MusicId)) {
        var_a0 = g_pActiveMusicContext;
        var_v1 = (int)(var_v1 - var_a0->MasterVolume);
        var_v1 = var_v1 / var_a2;
        var_a1 = g_ActiveMusicChannels;
        var_a0->MasterVolumeStepsRemaining = var_a2;
        var_a0->MasterVolumeStep = var_v1;
        Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
    } else {
        var_a0 = g_pSuspendedMusicContext;
        if ((var_a0 != NULL) && (temp_a1 != 0) && (temp_a1 == var_a0->MusicId)) {
            var_v1 = (int)(var_v1 - var_a0->MasterVolume);
            var_v1 = var_v1 / var_a2;
            var_a1 = g_pSecondaryMusicChannels;
            var_a0->MasterVolumeStepsRemaining = var_a2;
            var_a0->MasterVolumeStep = var_v1;
            Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
        }
    }
}

void Sound_Cmd_C2_FadeMasterVolumeFromByMusicId(FSoundCommandParams* arg0)
{
    FSoundChannel* var_a1;
    FSoundMusicContext* var_a0;
    int temp_v0;
    int temp_v1;
    int var_a2;
    u_int temp_v1_2;

    temp_v0 = arg0->Param2;
    var_a2 = 1;
    if (temp_v0 != 0) {
        var_a2 = temp_v0;
    }
    temp_v1 = arg0->Param1;
    if ((temp_v1 == 0) || (temp_v1 == g_pActiveMusicContext->MusicId)) {
        var_a0 = g_pActiveMusicContext;
        var_a1 = g_ActiveMusicChannels;
    } else {
        var_a0 = g_pSuspendedMusicContext;
        if ((var_a0 == NULL) || (temp_v1 == 0) || (temp_v1 != var_a0->MusicId)) {
            return;
        }
        var_a1 = g_pSecondaryMusicChannels;
    }
    temp_v1_2 = (arg0->Param3 & 0x7F) << 0x10;
    var_a0->MasterVolume = temp_v1_2;
    var_a0->MasterVolumeStep =
        (int)(((arg0->Param4 & 0x7F) << 0x10) - temp_v1_2) / var_a2;
    var_a0->MasterVolumeStepsRemaining = var_a2;
    Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
}

void Sound_Cmd_C8_SetCdVolume(FSoundCommandParams* arg0)
{
    g_Sound_CdVolumeFadeLength = 0;
    g_CdVolume = (u_short)arg0->Param1 << 0x10;
    Sound_UpdateCdVolume();
}

void Sound_Cmd_C9_FadeCdVolume(FSoundCommandParams* arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = arg0->Param1;
    var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    g_Sound_CdVolumeFadeLength = var_a1;
    g_Sound_CdVolumeFadeStep = (((u_short)arg0->Param2 << 0x10) - g_CdVolume) / var_a1;
}

void Sound_Cmd_CA_FadeCdVolumeFrom(FSoundCommandParams* arg0)
{
    unsigned int new_var;
    int var_a1 = 1;
    if (arg0->Param1 != 0) {
        var_a1 = arg0->Param1;
    }
    g_Sound_CdVolumeFadeLength = var_a1;
    new_var = ((u_short)arg0->Param3) << 0x10;
    g_CdVolume = (u_short)arg0->Param2 << 0x10;
    g_Sound_CdVolumeFadeStep = (int)(new_var - g_CdVolume) / var_a1;
}

void Sound_Cmd_A0_SetSfxVolumeMod(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a1 = g_SfxSoundChannels;
    u_int mask = g_Sound_SfxState.ActiveVoiceMask;
    int var_a3 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk_Flags & arg0->Param2)) {
                var_a1->VolumeMod = (arg0->Param3 & 0x7F) << 8;
                var_a1->VolumeModStepsRemaining = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 3;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->AkaoProgramIndex == arg0->Param1)) {
                var_a1->VolumeMod = (arg0->Param3 & 0x7F) << 8;
                var_a1->VolumeModStepsRemaining = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 3;
            }
        }
    }
}

void Sound_Cmd_A1_FadeSfxVolumeMod(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a2 = g_SfxSoundChannels;
    int mask = g_Sound_SfxState.ActiveVoiceMask;
    int var_t0 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk_Flags & arg0->Param2)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->VolumeModStep =
                    (short)(((arg0->Param4 & 0x7F) << 8) - var_a2->VolumeMod) / v;
                var_a2->VolumeModStepsRemaining = v;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->AkaoProgramIndex == arg0->Param1)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->VolumeModStep =
                    (short)(((arg0->Param4 & 0x7F) << 8) - var_a2->VolumeMod) / v;
                var_a2->VolumeModStepsRemaining = v;
            }
        }
    }
}

void Sound_Cmd_A8_SetAllSfxVolumeMod(FSoundCommandParams* arg0)
{
    int var_a3 = 0x1000;
    int mask = g_Sound_SfxState.ActiveVoiceMask;
    u_int i;
    FSoundChannel* var_a1;

    for (i = 0, var_a1 = g_SfxSoundChannels; i < 12; ++i, ++var_a1, var_a3 *= 2) {
        if ((mask & var_a3) && !(var_a1->unk_Flags & 0x02000000)) {
            var_a1->VolumeMod = (arg0->Param1 & 0x7F) << 8;
            var_a1->VolumeModStepsRemaining = 0;
            var_a1->VoiceParams.VoiceParamFlags |= 3;
        }
    }
}

void Sound_Cmd_A9_FadeAllSfxVolumeMod(FSoundCommandParams* arg0)
{
    short var_a1;
    int var_t0 = 0x1000;
    int mask = g_Sound_SfxState.ActiveVoiceMask;
    u_int i;
    FSoundChannel* var_a2;

    for (i = 0, var_a2 = g_SfxSoundChannels; i < 12; ++i, ++var_a2, var_t0 *= 2) {
        if ((mask & var_t0) && !(var_a2->unk_Flags & 0x02000000)) {
            var_a1 = 1;
            if (arg0->Param1 != 0) {
                var_a1 = arg0->Param1;
            }
            var_a2->VolumeModStep =
                ((short)(((arg0->Param2 & 0x7F) << 8) - var_a2->VolumeMod) / var_a1);
            var_a2->VolumeModStepsRemaining = var_a1;
        }
    }
}

void Sound_Cmd_A2_SetSfxPanMod(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a1 = g_SfxSoundChannels;
    u_int mask = g_Sound_SfxState.ActiveVoiceMask;
    int var_a3 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk_Flags & arg0->Param2)) {
                var_a1->PanMod = ((char)arg0->Param3) << 8;
                var_a1->PanModStepsRemaining = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 3;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->AkaoProgramIndex == arg0->Param1)) {
                var_a1->PanMod = ((char)arg0->Param3) << 8;
                var_a1->PanModStepsRemaining = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 3;
            }
        }
    }
}

void Sound_Cmd_A3_FadeSfxPanMod(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a2 = g_SfxSoundChannels;
    int mask = g_Sound_SfxState.ActiveVoiceMask;
    int var_t0 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk_Flags & arg0->Param2)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->PanModStep =
                    (short)((((char)arg0->Param4) << 8) - var_a2->PanMod) / v;
                var_a2->PanModStepsRemaining = v;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->AkaoProgramIndex == arg0->Param1)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->PanModStep =
                    (short)((((char)arg0->Param4) << 8) - var_a2->PanMod) / v;
                var_a2->PanModStepsRemaining = v;
            }
        }
    }
}

void Sound_Cmd_AA_SetAllSfxPanMod(FSoundCommandParams* arg0)
{
    int var_a3 = 0x1000;
    int mask = g_Sound_SfxState.ActiveVoiceMask;
    u_int i;
    FSoundChannel* var_a1;

    for (i = 0, var_a1 = g_SfxSoundChannels; i < 12; ++i, ++var_a1, var_a3 *= 2) {
        if ((mask & var_a3) && !(var_a1->unk_Flags & 0x02000000)) {
            var_a1->PanMod = ((char)arg0->Param1) << 8;
            var_a1->PanModStepsRemaining = 0;
            var_a1->VoiceParams.VoiceParamFlags |= 3;
        }
    }
}

void Sound_Cmd_AB_FadeAllSfxPanMod(FSoundCommandParams* arg0)
{
    short var_a1;
    int var_t0 = 0x1000;
    int mask = g_Sound_SfxState.ActiveVoiceMask;
    u_int i;
    FSoundChannel* var_a2;

    for (i = 0, var_a2 = g_SfxSoundChannels; i < 12; ++i, ++var_a2, var_t0 *= 2) {
        if ((mask & var_t0) && !(var_a2->unk_Flags & 0x02000000)) {
            var_a1 = 1;
            if (arg0->Param1 != 0) {
                var_a1 = arg0->Param1;
            }
            var_a2->PanModStep =
                (short)((((char)arg0->Param2) << 8) - var_a2->PanMod) / var_a1;
            var_a2->PanModStepsRemaining = var_a1;
        }
    }
}

void Sound_Cmd_A4_SetSfxPitchMod(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a1 = g_SfxSoundChannels;
    u_int mask = g_Sound_SfxState.ActiveVoiceMask;
    int var_a3 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk_Flags & arg0->Param2)) {
                var_a1->PitchMod = ((char)arg0->Param3) << 8;
                var_a1->PitchModStepsRemaining = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 16;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->AkaoProgramIndex == arg0->Param1)) {
                var_a1->PitchMod = ((char)arg0->Param3) << 8;
                var_a1->PitchModStepsRemaining = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 16;
            }
        }
    }
}

void Sound_Cmd_A5_FadeSfxPitchMod(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a2 = g_SfxSoundChannels;
    int mask = g_Sound_SfxState.ActiveVoiceMask;
    int var_t0 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk_Flags & arg0->Param2)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->PitchModStep =
                    (short)((short)((((char)arg0->Param4) << 8) - var_a2->PitchMod) / v);
                var_a2->PitchModStepsRemaining = v;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->AkaoProgramIndex == arg0->Param1)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->PitchModStep =
                    (short)((short)((((char)arg0->Param4) << 8) - var_a2->PitchMod) / v);
                var_a2->PitchModStepsRemaining = v;
            }
        }
    }
}

void Sound_Cmd_AC_SetAllSfxPitchMod(FSoundCommandParams* arg0)
{
    int i;
    FSoundChannel* var_a1 = g_SfxSoundChannels;
    for (i = 12; i != 0; --i, ++var_a1) {
        if (!(var_a1->unk_Flags & 0x02000000)) {
            var_a1->PitchMod = (char)arg0->Param1 << 8;
            var_a1->PitchModStepsRemaining = 0;
            var_a1->VoiceParams.VoiceParamFlags |= 0x10;
        }
    }
}

void Sound_Cmd_AD_FadeAllSfxPitchMod(FSoundCommandParams* arg0)
{
    short var_a1;
    int var_t0 = 0x1000;
    int mask = g_Sound_SfxState.ActiveVoiceMask;
    u_int i;
    FSoundChannel* var_a2;

    for (i = 0, var_a2 = g_SfxSoundChannels; i < 12; ++i, ++var_a2, var_t0 *= 2) {
        if ((mask & var_t0) && !(var_a2->unk_Flags & 0x02000000)) {
            var_a1 = 1;
            if (arg0->Param1 != 0) {
                var_a1 = arg0->Param1;
            }
            var_a2->PitchModStep =
                (short)((short)((((char)arg0->Param2) << 8) - var_a2->PitchMod) / var_a1);
            var_a2->PitchModStepsRemaining = var_a1;
        }
    }
}

void Sound_Cmd_D0_SetTempoScale(signed char* arg0)
{
    g_Sound_TempoScale = *arg0 << 0x10;
    g_Sound_TempoScaleStepsRemaining = 0;
}

void Sound_Cmd_D1_FadeTempoScale(FSoundCommandParams* arg0)
{
    int temp_v0 = arg0->Param1;
    int var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    g_Sound_TempoScaleStep =
        (((signed char)arg0->Param2 << 0x10) - g_Sound_TempoScale) / var_a1;
    g_Sound_TempoScaleStepsRemaining = var_a1;
}

void Sound_Cmd_D2_FadeTempoScaleFrom(FSoundCommandParams* arg0)
{
    int var_a1;

    var_a1 = 1;
    if (arg0->Param2 != 0) {
        var_a1 = arg0->Param1;
    }
    g_Sound_TempoScale = (signed char)arg0->Param2 << 0x10;
    g_Sound_TempoScaleStep =
        (int)(((signed char)arg0->Param3 << 0x10) - g_Sound_TempoScale) / var_a1;
    g_Sound_TempoScaleStepsRemaining = var_a1;
}

void Sound_Cmd_D4_SetMasterPitchScale(signed char* arg0)
{
    g_Sound_MasterPitchScaleQ16_16 = *arg0 << 0x10;
    g_Sound_MasterPitchScaleStepsRemaining = 0;
}

void Sound_Cmd_D5_FadeMasterPitchScale(FSoundCommandParams* arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = arg0->Param1;
    var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    g_Sound_MasterPitchScaleStep =
        (int)(((signed char)arg0->Param2 << 0x10) - g_Sound_MasterPitchScaleQ16_16)
        / var_a1;
    g_Sound_MasterPitchScaleStepsRemaining = (short)var_a1;
}

void Sound_Cmd_D6_FadeMasterPitchScaleFrom(FSoundCommandParams* arg0)
{
    int var_a1;

    var_a1 = 1;
    if (arg0->Param2 != 0) {
        var_a1 = arg0->Param1;
    }
    g_Sound_MasterPitchScaleQ16_16 = (signed char)arg0->Param2 << 0x10;
    g_Sound_MasterPitchScaleStep =
        (((signed char)arg0->Param3 << 0x10) - g_Sound_MasterPitchScaleQ16_16) / var_a1;
    g_Sound_MasterPitchScaleStepsRemaining = var_a1;
}

void Sound_Cmd_F0_StopMusic(void)
{
    Sound_KillMusicContext(g_pActiveMusicContext, g_ActiveMusicChannels, 0);

    if (g_pSuspendedMusicContext != NULL) {
        Sound_KillMusicContext(g_pSuspendedMusicContext, g_pSecondaryMusicChannels, 0);
    }

    g_pActiveMusicContext->StatusFlags &= 0xFFFEFFFF;
    *(int*)&D_80037788.Param1 = 0;
}

void Sound_Cmd_11_StopMusicById(FSoundCommandParams* in_Params)
{
    Sound_KillMusicContext(
        g_pActiveMusicContext, g_ActiveMusicChannels, in_Params->Param1);
    if (g_pSuspendedMusicContext != NULL) {
        if (in_Params->Param1 != 0) {
            Sound_KillMusicContext(
                g_pSuspendedMusicContext, g_pSecondaryMusicChannels, in_Params->Param1);
        }
    }
}

void Sound_ClearVoiceFromSfxState(FSoundChannel* arg0, int arg1);

void Sound_Cmd_F1_StopSfx(void)
{
    FSoundChannel* var_s2;
    int var_s1;
    u_int i;

    var_s2 = g_SfxSoundChannels;
    var_s1 = 0x1000;
    for (i = 0; i < 12; ++i, ++var_s2, var_s1 *= 2) {
        if ((g_Sound_SfxState.ActiveVoiceMask & var_s1)
            && !(var_s2->unk_Flags & 0x02000000)) {
            g_Sound_SfxState.KeyOffFlags |= var_s1;
            Sound_ClearVoiceFromSfxState(var_s2, var_s1);
            var_s2->UpdateFlags = 0;
        }
    }
    g_Sound_GlobalFlags.UpdateFlags |= 0x110;
}

void Sound_Cmd_80_SetModeStereo(FSoundCommandParams* in_Params __attribute__((unused)))
{
    D_80039AFC = 1;
    Sound_MarkActiveChannelsVolumeDirty(g_pActiveMusicContext, g_ActiveMusicChannels);
    if (g_pSuspendedMusicContext != NULL) {
        Sound_MarkActiveChannelsVolumeDirty(
            g_pSuspendedMusicContext, g_pSecondaryMusicChannels);
    }
    Sound_MarkScheduledSfxChannelsVolumeDirty();
}

void Sound_Cmd_81_SetModeMono(FSoundCommandParams* in_Params __attribute__((unused)))
{
    D_80039AFC = 2;
    Sound_MarkActiveChannelsVolumeDirty(g_pActiveMusicContext, g_ActiveMusicChannels);
    if (g_pSuspendedMusicContext != NULL) {
        Sound_MarkActiveChannelsVolumeDirty(
            g_pSuspendedMusicContext, g_pSecondaryMusicChannels);
    }
    Sound_MarkScheduledSfxChannelsVolumeDirty();
}

void Sound_Cmd_90_SetMutedMusicChannelMask(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* c;

    g_Sound_MutedMusicChannelMask = arg0->Param1;

    for (i = 0, c = g_ActiveMusicChannels; i < 32; ++i, ++c) {
        c->VoiceParams.VoiceParamFlags |= 3;
    }
}

void Sound_Cmd_92_SetMusicJumpThreshold(FSoundCommandParams* arg0)
{
    g_pActiveMusicContext->JumpThreshold = arg0->Param1;
}

void Sound_Cmd_9B_SuspendMusic(FSoundCommandParams* arg0 __attribute__((unused)))
{
    int temp_v1;
    int var_s0;
    int var_s1;
    int var_s2;

    if (g_pActiveMusicContext->ActiveChannelMask != 0) {
        int v0 = ~(g_Sound_SfxState.ActiveVoiceMask | D_80039B14);
        var_s2 = 1;
        var_s1 = v0 & 0xFFFFFF;

        if (var_s1 != 0) {
            var_s0 = 0;
            while (var_s1 != 0) {
                if (var_s1 & var_s2) {
                    SetVoiceVolume(var_s0, 0, 0, 0);
                    SetVoiceSampleRate(var_s0, 0);
                    SetVoiceAdsrAttackRateAndMode(var_s0, 0x7F, 1);
                    SetVoiceAdsrSustainRateAndDirection(var_s0, 0x7F, 3);
                    var_s1 &= ~var_s2;
                }
                var_s2 *= 2;
                var_s0 += 1;
            }
        }
        temp_v1 = g_pActiveMusicContext->ActiveChannelMask;
        g_pActiveMusicContext->ActiveChannelMask = 0;
        g_pActiveMusicContext->SuspendedChannelMask = temp_v1;
    }
    D_80039B64 |= 1;
}

void Sound_Cmd_9A_RestoreMusic(FSoundCommandParams* in_Params __attribute__((unused)))
{
    if (g_pActiveMusicContext->SuspendedChannelMask != 0) {
        FSoundChannel* c = g_ActiveMusicChannels;
        int var_a2 = g_pActiveMusicContext->SuspendedChannelMask;
        int var_a1 = 1;
        u_int temp_v1;
        do {
            if (var_a2 & var_a1) {
                var_a2 &= ~var_a1;
                c->VoiceParams.VoiceParamFlags |= 0x2B13;
            }
            var_a1 *= 2;
            ++c;
        } while (var_a2 != 0);

        temp_v1 = g_pActiveMusicContext->SuspendedChannelMask;
        g_pActiveMusicContext->SuspendedChannelMask = 0;
        g_pActiveMusicContext->ActiveChannelMask = temp_v1;
        g_Sound_GlobalFlags.UpdateFlags |= 0x100;
    }
    D_80039B64 &= ~1;
}

void Sound_Cmd_9D_SuspendSfx(FSoundCommandParams* in_Params __attribute__((unused)))
{
    FSoundChannel* var_a0;
    int var_s0;
    int var_s2;
    int var_s1;
    u_int i;

    if (g_Sound_SfxState.ActiveVoiceMask != 0) {
        var_s1 = g_Sound_SfxState.ActiveVoiceMask;
        var_a0 = g_SfxSoundChannels;
        var_s0 = 0x1000;

        for (i = 0; i < 12; ++i, ++var_a0, var_s0 *= 2) {
            if ((var_s1 & var_s0) && (var_a0->unk_Flags & 0x02000000)) {
                var_s1 &= ~var_s0;
            }
        }

        var_s0 = 0x1000;
        var_s2 = 0xC;
        g_Sound_SfxState.SuspendedVoiceMask = var_s1;
        g_Sound_SfxState.ActiveVoiceMask &= ~var_s1;

        while (var_s1 != 0) {
            if (var_s1 & var_s0) {
                SetVoiceVolume(var_s2, 0, 0, 0);
                SetVoiceSampleRate(var_s2, 0);
                SetVoiceAdsrAttackRateAndMode(var_s2, 0x7F, 1);
                SetVoiceAdsrSustainRateAndDirection(var_s2, 0x7F, 3);
                var_s1 &= ~var_s0;
            }
            var_s0 *= 2;
            var_s2 += 1;
        }
    }
    D_80039B64 |= 2;
}

void Sound_Cmd_9C_RestoreSfx(FSoundCommandParams* in_Params __attribute__((unused)))
{
    if (D_800378A0 != 0) {
        u_int temp_a2;
        FSoundChannel* c = g_SfxSoundChannels;
        int var_a2 = D_800378A0;
        int var_a1 = 0x1000;

        do {
            if (var_a2 & var_a1) {
                var_a2 &= ~var_a1;
                c->VoiceParams.VoiceParamFlags |= 0x2B13;
            }
            var_a1 *= 2;
            ++c;
        } while (var_a2 != 0);

        temp_a2 = g_Sound_SfxState.SuspendedVoiceMask;
        g_Sound_SfxState.SuspendedVoiceMask = 0;
        g_Sound_SfxState.ActiveVoiceMask |= temp_a2;
        g_Sound_GlobalFlags.UpdateFlags |= 0x100;
    }
    D_80039B64 &= ~2;
}

void Sound_Cmd_9F_SuspendCutsceneAudio(
    FSoundCommandParams* in_Params __attribute__((unused)))
{
    if (g_Sound_Cutscene_StreamState.VoicesInUseFlags != 0) {
        SetVoiceSampleRate(g_Sound_Cutscene_StreamState.VoiceIndex, 0);
        SetVoiceSampleRate(g_Sound_Cutscene_StreamState.VoiceIndex + 1, 0);
    }
}

void Sound_Cmd_9E_RestoreCutsceneAudio(
    FSoundCommandParams* in_Params __attribute__((unused)))
{
    if (g_Sound_Cutscene_StreamState.VoicesInUseFlags != 0) {
        SetVoiceSampleRate(g_Sound_Cutscene_StreamState.VoiceIndex,
            g_Sound_Cutscene_StreamState.VoiceSampleRate);
        SetVoiceSampleRate(g_Sound_Cutscene_StreamState.VoiceIndex + 1,
            g_Sound_Cutscene_StreamState.VoiceSampleRate);
    }
}

void Sound_Cmd_11_Nop(FSoundCommandParams* in_Params __attribute__((unused))) { }

void Sound_SetReverbMode(int in_ReverbMode)
{
    long curMode;

    SpuGetReverbModeType(&curMode);
    if (curMode != in_ReverbMode) {
        SpuSetReverb(SPU_OFF);
        SpuSetReverbModeType(in_ReverbMode | SPU_REV_MODE_CLEAR_WA);
        SpuSetReverb(SPU_ON);
    }
}

u_int Sound_ExecuteSoundVm2Function(u_int in_Command)
{
    AkaoSeqHeader* pSequence;
    FSoundCommandParams* pParams;
    int fadeLength;
    void* pData;
    u_int result = 0;

    DisableEvent(g_Sound_EventDescriptor);
    in_Command &= 0xFF;
    pParams = &g_Sound_CommandContext;

    switch (in_Command) {
    case 0x10:
    case 0x12:
    case 0x19:
    case 0x1A:
        pSequence = g_Sound_Vm2Params.unk0;

        if (pSequence->magic == AKAO_MAGIC) {
            g_Sound_GlobalFlags.ControlLatches &= ~0x7700;

            if (g_pActiveMusicContext->MusicId != pSequence->id
                || (g_pSuspendedMusicContext != NULL
                    && g_pSuspendedMusicContext->MusicId
                           != g_pActiveMusicContext->MusicId)) {
                Sound_SetReverbMode(pSequence->reverb_type);
                pParams->Param1 = (u_int)pSequence;
                pParams->Param3 = pSequence->id;

                switch (in_Command) {
                case 0x12:
                    pParams->Param4 = g_Sound_Vm2Params.unk4;
                    break;

                case 0x19:
                    pParams->ExtParam1 = g_Sound_Vm2Params.unk4;
                    break;

                case 0x1A:
                    fadeLength = g_Sound_Vm2Params.unk4;

                    if (fadeLength == 0) {
                        fadeLength = 1;
                    }

                    pParams->ExtParam1 = fadeLength;
                    pParams->ExtParam2 = g_Sound_Vm2Params.unk8;
                    break;
                }

                result = pSequence->id;
            } else {
                in_Command = 0;
                result = 0;
            }
        } else {
            in_Command = 0;
            result = -1;
        }
        break;

    case 0x14:
        if (Sound_IsNotAkaoFile(g_Sound_Vm2Params.unk0) != 0) {
            result = -1;
            break;
        }

        pData = g_Sound_Vm2Params.unk0;
        g_pActiveMusicContext->StatusFlags |= 0x10000;
        D_80037788.Param1 = (u_int)pData;
        result = ((AkaoSeqHeader*)g_Sound_Vm2Params.unk0)->id;
        break;

    case 0x16:
        if (*(int*)g_Sound_Vm2Params.unk0 == AKAO_MAGIC
            && *(int*)g_Sound_Vm2Params.unk4 == AKAO_MAGIC) {
            pSequence = (AkaoSeqHeader*)g_Sound_Vm2Params.unk4;
            g_Sound_GlobalFlags.ControlLatches &= ~0x7700;
            Sound_SetReverbMode(pSequence->reverb_type);
            g_Sound_Vm2Params.unk4 = pSequence->id;
            Sound_LoadAkaoSequence((FAkaoSequence*)pSequence);
            g_pActiveMusicContext->MusicId = pSequence->id;
            memcpy32(g_ActiveMusicChannels, g_PushedMusicChannels,
                sizeof g_ActiveMusicChannels);
            memcpy32(&g_PrimaryMusicContext, &g_SuspendedMusicContext, 0x80);
            pSequence = g_Sound_Vm2Params.unk0;
            g_Sound_Vm2Params.unk0 = (void*)(u_int)pSequence->id;
            Sound_LoadAkaoSequence((FAkaoSequence*)pSequence);
            g_pSuspendedMusicContext = &g_SuspendedMusicContext;
            g_pSecondaryMusicChannels = g_PushedMusicChannels;
            g_pActiveMusicContext->MusicId = pSequence->id;
            g_SuspendedMusicContext.ActiveChannelMask &= ~g_SuspendedMusicContext.unk30;
            g_Sound_GlobalFlags.ControlLatches |= 0x100;
        }

        in_Command = 0;
        break;

    case 0x17:
        if (g_Sound_GlobalFlags.ControlLatches & 0x1100) {
            if (g_Sound_GlobalFlags.ControlLatches & 0x100) {
                g_Sound_GlobalFlags.ControlLatches |= 0x4000;
            } else {
                g_Sound_GlobalFlags.ControlLatches |= 0x400;
            }
        }

        in_Command = 0;
        break;

    case 0xD8:
        pParams->Param1 = (u_int)g_Sound_Vm2Params.unk0;
        g_Sound_CommandHandlers[0xD0](pParams);
        in_Command = 0xD4;
        break;

    case 0xD9:
        pParams->Param1 = (u_int)g_Sound_Vm2Params.unk0;
        pParams->Param2 = g_Sound_Vm2Params.unk4;
        g_Sound_CommandHandlers[0xD1](pParams);
        in_Command = 0xD5;
        break;

    case 0xDA:
        pParams->Param1 = (u_int)g_Sound_Vm2Params.unk0;
        pParams->Param2 = g_Sound_Vm2Params.unk4;
        pParams->Param3 = g_Sound_Vm2Params.unk8;
        g_Sound_CommandHandlers[0xD2](pParams);
        in_Command = 0xD6;
        break;

    case 0x99:
        g_Sound_CommandHandlers[0x9B](pParams);
        g_Sound_CommandHandlers[0x9D](pParams);
        in_Command = 0x9F;
        break;

    case 0x98:
        g_Sound_CommandHandlers[0x9A](pParams);
        g_Sound_CommandHandlers[0x9C](pParams);
        in_Command = 0x9E;
        break;

    default:
        pParams->Param1 = (u_int)g_Sound_Vm2Params.unk0;
        pParams->Param2 = g_Sound_Vm2Params.unk4;
        pParams->Param3 = g_Sound_Vm2Params.unk8;
        pParams->Param4 = g_Sound_Vm2Params.unkC;
        pParams->ExtParam1 = g_Sound_Vm2Params.unk10;
        pParams->ExtParam2 = g_Sound_Vm2Params.unk14;
        break;
    }

    g_Sound_CommandHandlers[in_Command](pParams);
    EnableEvent(g_Sound_EventDescriptor);
    return result;
}

void Sound_UpdateCdVolume(void)
{
    int v = D_800378E2;
    *CD_VOL_L = v;
    *CD_VOL_R = v;
}

void memcpy32(void* in_Src, void* in_Dst, u_int in_Size)
{
    int w0, w1, w2, w3;

    in_Size >>= 2;

    while ((in_Size >> 2) != 0) {
        w0 = ((int*)in_Src)[0];
        w1 = ((int*)in_Src)[1];
        w2 = ((int*)in_Src)[2];
        w3 = ((int*)in_Src)[3];
        ((int*)in_Dst)[0] = w0;
        ((int*)in_Dst)[1] = w1;
        ((int*)in_Dst)[2] = w2;
        ((int*)in_Dst)[3] = w3;
        in_Src += 0x10;
        in_Dst += 0x10;
        in_Size -= 4;
    }

    while (in_Size != 0) {
        *(int*)in_Dst = *(int*)in_Src;
        in_Dst += 4;
        in_Src += 4;
        in_Size--;
    }
}

void memswap32(void* in_A, void* in_B, u_int in_Size)
{
    int a0, a1, b0, b1;

    in_Size >>= 2;

    while ((in_Size >> 1) != 0) {
        a0 = ((int*)in_A)[0];
        b0 = ((int*)in_B)[0];
        a1 = ((int*)in_A)[1];
        b1 = ((int*)in_B)[1];

        ((int*)in_B)[0] = a0;
        ((int*)in_B)[1] = a1;
        ((int*)in_A)[0] = b0;
        ((int*)in_A)[1] = b1;

        in_A += 8;
        in_B += 8;

        in_Size -= 2;
    }

    if (in_Size != 0) {
        a0 = *(int*)in_A;
        b0 = *(int*)in_B;
        *(int*)in_B = a0;
        *(int*)in_A = b0;
    }
}

void func_8001924C(void)
{
    int temp_s1;
    int var_a2;
    FSoundChannel* var_a1_2;
    int var_a3;
    FSoundChannel* var_v1;

    g_Sound_LfoPhase = (g_Sound_LfoPhase + 1) & 0xFF;
    if (g_Sound_CdVolumeFadeLength != 0) {
        --g_Sound_CdVolumeFadeLength;
        g_CdVolume += g_Sound_CdVolumeFadeStep;
        Sound_UpdateCdVolume();
    }
    if ((g_Sound_Cutscene_StreamState.VoicesInUseFlags != 0)
        && (g_Sound_Cutscene_StreamState.VolFadeStepsRemaining != 0)) {
        --g_Sound_Cutscene_StreamState.VolFadeStepsRemaining;
        temp_s1 = g_Sound_Cutscene_StreamState.Volume
                + g_Sound_Cutscene_StreamState.VolFadeStepSize;
        if ((temp_s1 & 0xFF00) != (g_Sound_Cutscene_StreamState.Volume & 0xFF00)) {
            if (D_80039AFC & 2) {
                int temp_s0 = (g_Sound_Cutscene_StreamState.Volume * D_8002F89C) >> 0x10;
                SetVoiceVolume(
                    g_Sound_Cutscene_StreamState.VoiceIndex, temp_s0, temp_s0, 0);
                SetVoiceVolume(
                    g_Sound_Cutscene_StreamState.VoiceIndex + 1, temp_s0, temp_s0, 0);
            } else {
                int temp_s0 = (temp_s1 << 0xF) >> 0x10;
                SetVoiceVolume(g_Sound_Cutscene_StreamState.VoiceIndex, temp_s0, 0, 0);
                SetVoiceVolume(
                    g_Sound_Cutscene_StreamState.VoiceIndex + 1, 0, temp_s0, 0);
            }
        }
        D_80039B48 = temp_s1 & 0xFFFF;
    }
    if (g_Sound_TempoScaleStepsRemaining != 0) {
        --g_Sound_TempoScaleStepsRemaining;
        g_Sound_TempoScale += g_Sound_TempoScaleStep;
    }
    if (g_Sound_MasterPitchScaleStepsRemaining != 0) {
        --g_Sound_MasterPitchScaleStepsRemaining;
        temp_s1 = g_Sound_MasterPitchScaleQ16_16 + g_Sound_MasterPitchScaleStep;

        if ((temp_s1 & 0xFF0000) != (g_Sound_MasterPitchScaleQ16_16 & 0xFF0000)) {
            var_v1 = g_ActiveMusicChannels;
            for (var_a2 = 0x20; var_a2 != 0; --var_a2, ++var_v1) {
                var_v1->VoiceParams.VoiceParamFlags |= 0x10;
            }
        }
        g_Sound_MasterPitchScaleQ16_16 = temp_s1;
    }
    if ((g_pActiveMusicContext->ActiveChannelMask != 0)
        && (g_pActiveMusicContext->MasterVolumeStepsRemaining != 0)) {
        --g_pActiveMusicContext->MasterVolumeStepsRemaining;
        temp_s1 =
            g_pActiveMusicContext->MasterVolume + g_pActiveMusicContext->MasterVolumeStep;
        if ((temp_s1 & 0x7F0000) != (g_pActiveMusicContext->MasterVolume & 0x7F0000)) {
            Sound_MarkActiveChannelsVolumeDirty(
                g_pActiveMusicContext, g_ActiveMusicChannels);
        }
        g_pActiveMusicContext->MasterVolume = temp_s1;
    }
    if ((g_pSuspendedMusicContext != NULL)
        && (g_pSuspendedMusicContext->ActiveChannelMask != 0)) {
        if (g_pSuspendedMusicContext->MasterVolumeStepsRemaining != 0) {
            --g_pSuspendedMusicContext->MasterVolumeStepsRemaining;
            temp_s1 = g_pSuspendedMusicContext->MasterVolume
                    + g_pSuspendedMusicContext->MasterVolumeStep;
            if ((temp_s1 & 0x7F0000)
                != (g_pSuspendedMusicContext->MasterVolume & 0x7F0000)) {
                Sound_MarkActiveChannelsVolumeDirty(
                    g_pSuspendedMusicContext, g_pSecondaryMusicChannels);
            }
            g_pSuspendedMusicContext->MasterVolume = temp_s1;
        }
    }
    if (g_Sound_SfxState.ActiveVoiceMask != 0) {
        var_a3 = g_Sound_SfxState.ActiveVoiceMask;
        var_a1_2 = g_SfxSoundChannels;
        do {
        } while (0);
        for (var_a2 = 0x1000; var_a3 != 0; var_a2 <<= 1, ++var_a1_2) {
            if (!(var_a3 & var_a2)) {
                continue;
            }

            if (var_a1_2->VolumeModStepsRemaining != 0) {
                --var_a1_2->VolumeModStepsRemaining;
                temp_s1 = var_a1_2->VolumeMod + var_a1_2->VolumeModStep;
                if ((temp_s1 & 0xFF00) != (var_a1_2->VolumeMod & 0xFF00)) {
                    var_a1_2->VoiceParams.VoiceParamFlags |= 3;
                }
                var_a1_2->VolumeMod = temp_s1;
            }

            if (var_a1_2->PanModStepsRemaining != 0) {
                --var_a1_2->PanModStepsRemaining;
                temp_s1 = var_a1_2->PanMod + var_a1_2->PanModStep;
                if ((temp_s1 & 0xFF00) != (var_a1_2->PanMod & 0xFF00)) {
                    var_a1_2->VoiceParams.VoiceParamFlags |= 3;
                }
                var_a1_2->PanMod = temp_s1;
            }

            if (var_a1_2->PitchModStepsRemaining != 0) {
                --var_a1_2->PitchModStepsRemaining;
                temp_s1 = var_a1_2->PitchMod + var_a1_2->PitchModStep;
                if ((temp_s1 & 0xFF00) != (var_a1_2->PitchMod & 0xFF00)) {
                    var_a1_2->VoiceParams.VoiceParamFlags |= 0x10;
                }
                var_a1_2->PitchMod = temp_s1;
            }
            var_a3 ^= var_a2;
        }
    }
}

void func_80019614(void)
{
    int temp_v1;
    if (g_Sound_GlobalFlags.ControlLatches & 0x6600) {
        temp_v1 = g_pActiveMusicContext->TimerLowerCurrent
                + (g_pActiveMusicContext->TimerUpperCurrent << 0x10);
        D_800378D4 = temp_v1;
        if (D_800378D4 == 0) {
            if (g_Sound_GlobalFlags.ControlLatches & 0x100) {
                if (g_Sound_GlobalFlags.ControlLatches & 0x4000) {
                    g_Sound_GlobalFlags.ControlLatches =
                        (g_Sound_GlobalFlags.ControlLatches & ~0x4000) | 0x2000;
                    return;
                }
                g_Sound_GlobalFlags.ControlLatches =
                    (g_Sound_GlobalFlags.ControlLatches & ~0x2100) | 0x1000;
                g_pActiveMusicContext->PendingKeyOffMask |=
                    g_pActiveMusicContext->ActiveChannelMask
                    & ~g_pActiveMusicContext->unk30;
                g_pActiveMusicContext->ActiveNoteMask &= g_pActiveMusicContext->unk30;
                return;
            }
            if (g_Sound_GlobalFlags.ControlLatches & 0x400) {
                g_Sound_GlobalFlags.ControlLatches =
                    (g_Sound_GlobalFlags.ControlLatches & ~0x400) | 0x200;
                return;
            }
            g_Sound_GlobalFlags.ControlLatches =
                (g_Sound_GlobalFlags.ControlLatches & ~0x1200) | 0x100;
            g_pSuspendedMusicContext->ActiveNoteMask = 0;
            g_pSuspendedMusicContext->PendingKeyOffMask |=
                g_pSuspendedMusicContext->ActiveChannelMask;
        }
    }
}

int Music_UpdateChannels(FSoundChannel* arg0, int arg1)
{
    FSoundChannel* var_s2;
    int var_s3;
    u_int var_s1;

    int var_a0 = (u_short)(g_pActiveMusicContext->Tempo >> 16);
    u_int tempoScale = D_80039AF2;

    if (tempoScale != 0) {
        if (tempoScale < 0x80) {
            var_a0 += (var_a0 * tempoScale) >> 7;
        } else {
            var_a0 = (var_a0 * tempoScale) >> 8;
        }
    }

    g_pActiveMusicContext->TempoUpdate += var_a0;

    if ((g_pActiveMusicContext->TempoUpdate & 0xFFFF0000) || (D_80039B64 & 4)) {
        g_pActiveMusicContext->TempoUpdate = g_pActiveMusicContext->TempoUpdate & 0xFFFF;

        do {
            var_s2 = arg0;
            var_s1 = 1;
            var_s3 = g_pActiveMusicContext->ActiveChannelMask;

            do {
                if (var_s3 & var_s1) {
                    --var_s2->NoteLength;
                    --var_s2->KeyLength;
                    if (var_s2->NoteLength == 0) {
                        Sound_ProcessAkaoVM(var_s2, var_s1);
                    } else if (var_s2->KeyLength == 0) {
                        g_pActiveMusicContext->PendingKeyOffMask |= var_s1;
                    }
                    Sound_UpdateSlidesAndDelays(var_s2, var_s1, 0);
                    var_s3 &= ~var_s1;
                }
                ++var_s2;
                var_s1 *= 2;
            } while (var_s3 != 0);

            if (g_pActiveMusicContext->TempoSlideLength != 0) {
                --g_pActiveMusicContext->TempoSlideLength;
                g_pActiveMusicContext->Tempo += g_pActiveMusicContext->TempoSlideStep;
            }

            if (g_pActiveMusicContext->ReverbDepthSlideLength != 0) {
                --g_pActiveMusicContext->ReverbDepthSlideLength;
                g_pActiveMusicContext->RevDepth +=
                    g_pActiveMusicContext->ReverbDepthSlideStep;
                g_Sound_GlobalFlags.UpdateFlags |= (arg1 == 0) ? 0x80 : 0;
            }

            if (g_pActiveMusicContext->TimerLower == 0) {
                continue;
            }

            ++g_pActiveMusicContext->TimerLowerCurrent;

            if (g_pActiveMusicContext->TimerLowerCurrent
                != g_pActiveMusicContext->TimerLower) {
                continue;
            }

            g_pActiveMusicContext->TimerLowerCurrent = 0;
            ++g_pActiveMusicContext->TimerUpperCurrent;

            if (g_pActiveMusicContext->TimerUpperCurrent
                != g_pActiveMusicContext->TimerUpper) {
                continue;
            }

            g_pActiveMusicContext->TimerUpperCurrent = 0;
            ++g_pActiveMusicContext->TimerTopCurrent;

            if ((arg1 == 0) && (g_Music_LoopCounter != 0)) {
                --g_Music_LoopCounter;
            }

            if (g_pActiveMusicContext == &g_PrimaryMusicContext) {
                func_80019614();
            }
        } while (arg1 == 0 && g_Music_LoopCounter != 0);
    }
    while (0)
        ;
    return g_pActiveMusicContext->ActiveChannelMask;
}

void func_800199C4(FSoundMusicContext* arg0, FSoundChannel* arg1)
{
    int temp_s0;

    if (g_Sound_MasterFadeTimer.TicksRemaining != 0) {
        --g_Sound_MasterFadeTimer.TicksRemaining;
        if (g_Sound_MasterFadeTimer.TicksRemaining == 0) {
            int temp_v0 = arg0->ActiveChannelMask;
            arg0->MusicId = 0;
            arg0->ActiveChannelMask = 0;
            arg0->PendingKeyOnMask = 0;
            arg0->ActiveNoteMask = 0;
            arg0->PendingKeyOffMask = temp_v0;
            return;
        }
        temp_s0 = g_Sound_MasterFadeTimer.Value + g_Sound_MasterFadeTimer.Step;
        if ((temp_s0 & 0xFFFF0000) != (g_Sound_MasterFadeTimer.Value & 0xFFFF0000)) {
            Sound_MarkActiveChannelsVolumeDirty(arg0, arg1);
        }
        g_Sound_MasterFadeTimer.Value = temp_s0;
    }
}

long Sound_MainLoop(void)
{
    FSoundChannel* var_s2_2;
    FSoundMusicContext* temp_v0;
    FSoundMusicContext* var_a0;
    int var_s5;
    int var_s1;
    int i;
    u_short* p;

    var_s5 = GetRCnt(RCntCNT2);
    ++D_8002F54C;
    if (g_Sound_GlobalFlags.ControlLatches & 0x1100) {
        if (g_Sound_GlobalFlags.ControlLatches & 0x100) {
            if (g_Sound_GlobalFlags.ControlLatches & 0x6000) {
                g_pSuspendedMusicContext->PendingKeyOnMask &=
                    g_pSuspendedMusicContext->unk2C;
                g_pSuspendedMusicContext->ActiveNoteMask &=
                    g_pSuspendedMusicContext->unk2C;
            } else {
                g_pSuspendedMusicContext->PendingKeyOnMask = 0;
                g_pSuspendedMusicContext->ActiveNoteMask = 0;
            }
            var_a0 = g_pActiveMusicContext;
        } else {
            if (g_Sound_GlobalFlags.ControlLatches & 0x600) {
                g_pActiveMusicContext->PendingKeyOnMask &=
                    g_pActiveMusicContext->unk2C | g_pActiveMusicContext->unk30;
                g_pActiveMusicContext->ActiveNoteMask &=
                    g_pActiveMusicContext->unk2C | g_pActiveMusicContext->unk30;
            } else {
                g_pActiveMusicContext->PendingKeyOnMask &= g_pActiveMusicContext->unk30;
                g_pActiveMusicContext->ActiveNoteMask &= g_pActiveMusicContext->unk30;
            }
            var_a0 = g_pSuspendedMusicContext;
        }
        var_a0->PendingKeyOnMask &= ~var_a0->unk2C;
        var_a0->ActiveNoteMask &= ~var_a0->unk2C;
    }
    if ((g_pActiveMusicContext->PendingKeyOffMask != 0) || (D_8003789C != 0)
        || (g_pSuspendedMusicContext != NULL
            && g_pSuspendedMusicContext->PendingKeyOffMask != 0)) {
        Sound_ProcessKeyOffRequests();
    }

    if (g_pSuspendedMusicContext != NULL) {
        if (g_pSuspendedMusicContext->ActiveChannelMask == 0) {
            g_pSuspendedMusicContext = NULL;
        } else if ((g_pActiveMusicContext->ActiveChannelMask
                       | g_pActiveMusicContext->SuspendedChannelMask)
                   == 0) {
            memcpy32(g_pSuspendedMusicContext, g_pActiveMusicContext, 0x80);
            memcpy32(g_pSecondaryMusicChannels, g_ActiveMusicChannels, 0x2200);
            temp_v0 = g_pSuspendedMusicContext;
            g_pSuspendedMusicContext = NULL;
            temp_v0->MusicId = 0;
            temp_v0->ActiveChannelMask = 0;
        }
    }
    p = (u_short*)D_80037788.Param1;
    if (p != 0) {
        if (g_pActiveMusicContext->ActiveChannelMask == 0) {
            g_Sound_CommandParams_Vm_FE08.Param1 = (u_int)p;
            g_Sound_CommandParams_Vm_FE08.Param3 = p[2];
            Sound_Cmd_10_StartFieldMusic(&g_Sound_CommandParams_Vm_FE08);

            var_s2_2 = g_ActiveMusicChannels;
            for (i = 32; i != 0; --i) {
                var_s2_2->NoteLength = 1;
                ++var_s2_2;
            }

            D_80037788.Param1 = 0;
        }
    }
    if (((D_80039B00 | g_pActiveMusicContext->ActiveNoteMask | D_80037898) != 0)
        || ((g_pSuspendedMusicContext != NULL)
            && (g_pSuspendedMusicContext->ActiveNoteMask != 0))) {
        func_80015220();
    }
    if (g_pActiveMusicContext->ActiveChannelMask != 0) {
        Music_UpdateChannels(g_ActiveMusicChannels, 0);
    }
    if (g_pSuspendedMusicContext != NULL) {
        if (g_pSuspendedMusicContext->ActiveChannelMask != 0) {
            g_pActiveMusicContext = g_pSuspendedMusicContext;
            Music_UpdateChannels(g_pSecondaryMusicChannels, 1);
            g_pActiveMusicContext = &g_PrimaryMusicContext;
        }
        if (g_Sound_GlobalFlags.MixBehavior & 0x100) {
            if (!(D_8002F54C & 3)) {
                func_800199C4(g_pSuspendedMusicContext, g_pSecondaryMusicChannels);
                if (g_pSuspendedMusicContext->ActiveChannelMask == 0) {
                    g_Sound_GlobalFlags.MixBehavior &= ~0x100;
                }
            }
        }
    }
    if (g_Sound_SfxState.ActiveVoiceMask != 0) {
        i = g_Sound_SfxState.ActiveVoiceMask;
        g_Sound_SfxState.TempoAccumulator +=
            (g_Sound_SfxState.TempoBase >> 0x10) & 0xFFFF;
        if ((g_Sound_SfxState.TempoAccumulator & 0xFFFF0000) || (D_80039B64 & 4)) {
            g_Sound_SfxState.TempoAccumulator &= 0xFFFF;
            var_s1 = 0x1000;
            var_s2_2 = g_SfxSoundChannels;
            do {
                if (i & var_s1) {
                    if (!(D_80039B64 & 2) || (var_s2_2->unk_Flags & 0x02000000)) {
                        ++var_s2_2->Priority;
                        --var_s2_2->NoteLength;
                        --var_s2_2->KeyLength;
                        if (var_s2_2->NoteLength == 0) {
                            Sound_ProcessAkaoVM(var_s2_2, var_s1);
                        } else if (var_s2_2->KeyLength == 0) {
                            g_Sound_SfxState.KeyOffFlags |= var_s1;
                            g_Sound_SfxState.KeyedFlags &= ~var_s1;
                        }
                        Sound_UpdateSlidesAndDelays(var_s2_2, var_s1, 1);
                    }
                    i ^= var_s1;
                }
                ++var_s2_2;
                var_s1 *= 2;
            } while (i != 0);
        }
    }
    if (!(D_8002F54C & 3)) {
        func_8001924C();
    }
    var_s5 = GetRCnt(RCntCNT2) - var_s5;
    if (var_s5 <= 0) {
        var_s5 += 0x44E8;
    }

    D_8002F550[0] = D_8002F550[1];
    D_8002F550[1] = D_8002F550[2];
    D_8002F550[2] = D_8002F550[3];
    D_8002F550[3] = var_s5;
    D_8002F548 = D_8002F550[0] + D_8002F550[1] + D_8002F550[2] + D_8002F550[3];
    return var_s5;
}

char Sound_PeekNextOpcode(FSoundChannel* channel)
{
    u_char* pc = channel->ProgramCounter;
    u_int loopTop = channel->LoopStackTop;
    FSoundMusicContext* config = g_pActiveMusicContext;
    int length;
    int jumpOffset;

    for (;;) {
        if (*pc < 0x9A) {
            if (*pc >= 0x8F) {
                channel->Articulation &= ~5;
            }
            return *pc;
        }
        if (*pc < 0xA0) {
            return 0xA0;
        }
        length = D_8002F5A0[*pc - 0xA0];
        if (length != 0) {
            pc += length;
            continue;
        }
        switch (*pc) {
        case 0xF0:
        case 0xF1:
        case 0xF2:
        case 0xF3:
        case 0xF4:
        case 0xF5:
        case 0xF6:
        case 0xF7:
        case 0xF8:
        case 0xF9:
        case 0xFA:
        case 0xFB:
            return 0x83;
        case 0xFC:
            return 0x84;
        case 0xFD:
            return 0x8F;
        case 0xFE:
            pc++;
            length = D_8002F600[*pc];
            if (length != 0) {
                pc += length;
                break;
            }
            switch (*pc) {
            case 0x08:
            case 0x09:
                pc++;
                if (*pc == channel->LoopIterationCount[loopTop] + 1) {
                    pc++;
                    loopTop--;
                    loopTop &= 3;
                    jumpOffset = pc[0];
                    jumpOffset += pc[1] << 8;
                    pc += (short)jumpOffset;
                } else {
                    pc += 3;
                }
                break;
            case 0x06:
            case 0x0E:
                pc++;
                jumpOffset = pc[0];
                jumpOffset += pc[1] << 8;
                pc += (short)jumpOffset;
                break;
            case 0x07:
                pc++;
                if (*pc++ <= config->JumpThreshold) {
                    jumpOffset = pc[0];
                    jumpOffset += pc[1] << 8;
                    pc += (short)jumpOffset;
                } else {
                    pc += 2;
                }
                break;
            case 0x0F:
                pc = channel->ReturnProgramCounter;
                break;
            case 0x1F:
                pc++;
                if (config->StatusFlags & 0x10000) {
                    return 0xA0;
                }
                break;
            }
            break;
        case 0xC9:
            pc++;
            if (*pc == channel->LoopIterationCount[loopTop] + 1) {
                pc++;
                loopTop--;
                loopTop &= 3;
            } else {
                pc = channel->LoopStartPc[loopTop];
            }
            break;
        case 0xCB:
        case 0xCD:
        case 0xD1:
        case 0xDB:
            channel->Articulation &= ~5;
            pc++;
            break;
        case 0xCA:
            if (!(channel->UpdateFlags & 0x200000)) {
                pc = channel->LoopStartPc[loopTop];
                break;
            }
        default:
            channel->Articulation &= ~5;
            return 0xA0;
        }
    }
}

int func_8001A1F4(int arg0, int arg1)
{
    if ((arg1 - 0x80u) < 0x20) {
        if (arg0 & 2) {
            return arg1 + 0x20;
        }
        if (arg0 & 4) {
            return arg1 + 0x40;
        }
    }
    return arg1;
}

int func_8001A22C(int arg0, u_int arg1)
{
    if ((arg0 & 0x40) && (arg1 >= 0x40) && (arg1 < 0x80)) {
        return arg1 + 0x20;
    }
    return arg1;
}

void func_8001A258(FSoundChannel* arg0, u_int arg1)
{
    FSoundInstrumentInfo* temp_a0;
    char* var_s0;
    int temp_v0;
    int temp_s2;

    if ((arg0->Key < arg1) || (arg0->Key == 0xFF)) {
        var_s0 = arg0->Keymap;
        while (var_s0[13] != 0 && var_s0[2] < arg1) {
            var_s0 += 8;
        }
    } else {
        if (arg1 >= arg0->Key) {
            return;
        }
        var_s0 = arg0->Keymap;
        while (var_s0[13] != 0 && arg1 >= var_s0[9]) {
            var_s0 += 8;
        }
    }

    temp_s2 = arg0->UpdateFlags;

    temp_v0 = func_8001A22C(g_pActiveMusicContext->StatusFlags, var_s0[0]);
    arg0->InstrumentIndex = temp_v0;
    temp_a0 = &g_InstrumentInfo[temp_v0];
    arg0->VoiceParams.StartAddress = temp_a0->StartAddr;
    arg0->VoiceParams.LoopAddress = temp_a0->LoopAddr;

    if (!(temp_s2 & 0x01000000)) {
        arg0->VoiceParams.AdsrLower = var_s0[3] << 8;
    } else {
        arg0->VoiceParams.AdsrLower &= 0x7F00;
    }

    arg0->VoiceParams.AdsrLower |= temp_a0->AdsrLower & 0x80FF;

    if (!(temp_s2 & 0x08000000)) {
        arg0->VoiceParams.AdsrUpper &= 0x201F;
        arg0->VoiceParams.AdsrUpper |= var_s0[4] << 6;
    } else {
        arg0->VoiceParams.AdsrUpper &= 0x3FDF;
    }

    switch (var_s0[5]) {
    case 3:
        arg0->VoiceParams.AdsrUpper |= 0x4000;
        break;
    case 5:
        arg0->VoiceParams.AdsrUpper |= 0x8000;
        break;
    case 7:
        arg0->VoiceParams.AdsrUpper |= 0xC000;
        break;
    }

    if ((temp_s2 & 0x10000000) == 0) {
        arg0->VoiceParams.AdsrUpper &= 0xFFE0;
        arg0->VoiceParams.AdsrUpper |= var_s0[6];
    }

    arg0->VoiceParams.AdsrUpper |= temp_a0->AdsrUpper & 0x20;
    arg0->VoiceParams.VolumeScale = var_s0[7];
}

int Sound_CalculatePitch(FSoundInstrumentInfo* arg0, int arg1, u_int arg2, int* arg3)
{
    int var_a0;
    int var_t0;

    var_a0 = arg1 - arg0->SampleNote;

    while (var_a0 < 0) {
        var_a0 += 0xC;
    }

    var_a0 %= 12;

    if (arg0->FineTune == 0) {
        var_t0 = D_8002F63C[var_a0] << 8;
    } else if (arg0->FineTune < 0) {
        var_t0 = (D_8002F63C[var_a0] * (u_short)arg0->FineTune) >> 8;
    } else {
        var_t0 = (D_8002F63C[var_a0] * arg0->FineTune) >> 7;
        var_t0 += D_8002F63C[var_a0] << 8;
    }

    arg2 &= 0xFF;

    if (arg2 != 0) {
        if (arg2 < 0x80) {
            *arg3 = (var_t0 * arg2) >> 7;
        } else {
            *arg3 = ((var_t0 * arg2) >> 8) - var_t0;
        }
    }

    if (arg1 < arg0->SampleNote) {
        for (; arg1 < arg0->SampleNote; arg1 += 0xC) {
            *arg3 = *arg3 >> 1;
            var_t0 = (var_t0 >> 1);
        }
    } else {
        var_a0 = (arg1 - arg0->SampleNote) / 12;
        if (var_a0 != 0) {
            var_t0 <<= var_a0;
            *arg3 <<= var_a0;
        }
    }
    var_t0 >>= 8;
    *arg3 >>= 8;
    return (u_short)var_t0;
}

int Sound_PlayKeymapNote(FSoundChannel* arg0, int arg1, int arg2)
{
    FSoundInstrumentInfo* temp_a0;
    int temp_v0;
    int temp_v0_2;
    int temp_s2;
    char* temp_s1;

    temp_s1 = (char*)g_pActiveMusicContext->KeymapTable;
    temp_s1 += arg2 * 8;
    g_pActiveMusicContext->PendingKeyOnMask |= arg1;

    if (g_pActiveMusicContext->ActiveNoteMask & arg1) {
        g_pActiveMusicContext->PendingKeyOffMask |= arg1;
    }

    temp_s2 = arg0->UpdateFlags;
    temp_v0_2 = func_8001A22C(g_pActiveMusicContext->StatusFlags, (u_int)temp_s1[0]);
    arg0->InstrumentIndex = temp_v0_2;
    temp_a0 = &g_InstrumentInfo[temp_v0_2];
    arg0->VoiceParams.StartAddress = temp_a0->StartAddr;
    arg0->VoiceParams.LoopAddress = temp_a0->LoopAddr;

    if (!(temp_s2 & 0x01000000)) {
        arg0->VoiceParams.AdsrLower = temp_s1[2] << 8;
    } else {
        arg0->VoiceParams.AdsrLower &= 0x7F00;
    }

    arg0->VoiceParams.AdsrLower |= temp_a0->AdsrLower & 0x80FF;

    if (!(temp_s2 & 0x08000000)) {
        arg0->VoiceParams.AdsrUpper &= 0x201F;
        arg0->VoiceParams.AdsrUpper |= temp_s1[3] << 6;
    } else {
        arg0->VoiceParams.AdsrUpper &= 0x3FDF;
    }

    switch (temp_s1[4]) {
    case 3:
        arg0->VoiceParams.AdsrUpper |= 0x4000;
        break;
    case 5:
        arg0->VoiceParams.AdsrUpper |= 0x8000;
        break;
    case 7:
        arg0->VoiceParams.AdsrUpper |= 0xC000;
        break;
    }

    if ((temp_s2 & 0x10000000) == 0) {
        arg0->VoiceParams.AdsrUpper &= 0xFFE0;
        arg0->VoiceParams.AdsrUpper |= temp_s1[5];
    }

    arg0->VoiceParams.AdsrUpper |= temp_a0->AdsrUpper & 0x20;
    temp_v0 =
        Sound_CalculatePitch(temp_a0, temp_s1[1], arg0->FineTune, &arg0->FinePitchDelta);
    arg0->VoiceParams.VolumeScale = temp_s1[6];
    arg0->ChannelPan = ((temp_s1[7] & 0x7F) + 0x40) << 8;

    if (temp_s1[7] & 0x80) {
        g_pActiveMusicContext->ReverbChannelFlags |= arg1;
    } else {
        g_pActiveMusicContext->ReverbChannelFlags &= ~arg1;
    }
    g_Sound_GlobalFlags.UpdateFlags |= 0x100;
    return temp_v0;
}

extern u_short D_8002F620[];
extern char D_8002F69C[];
extern void (*D_800305E0[])(FSoundChannel*, int);
extern void (*D_80030760[])(FSoundChannel*, int);

void Sound_ProcessAkaoVM(FSoundChannel* arg0, int arg1)
{
    u_int sp10;
    u_int temp_a2_2;
    u_int temp_s0;
    u_int temp_v0;
    u_char* temp_a1;
    int var_v1;
    u_int temp_a1_2;
    u_int temp_v1;
    u_int temp_v1_6;
    u_int var_s0;

    do {
        temp_a1 = arg0->ProgramCounter;
        var_s0 = temp_a1[0];
        arg0->ProgramCounter = ++temp_a1;

        if (var_s0 >= 0xA0) {
            temp_v1 = var_s0 - 0xF0;
            if (var_s0 == 0xFE) {
                temp_a2_2 = temp_a1[0];
                arg0->ProgramCounter = temp_a1 + 1;
                D_80030760[temp_a2_2](arg0, arg1);
            } else {
                if (temp_v1 < 0xE) {
                    var_s0 = temp_v1 * 0xB;
                    arg0->NoteLength = temp_a1[0];
                    arg0->ProgramCounter = temp_a1 + 1;
                } else {
                    if (var_s0 == 0xFF) {
                        var_s0 = 0xA0;
                    } else if ((var_s0 == 0xCA) && (arg0->UpdateFlags & 0x200000)) {
                        var_s0 = 0xA0;
                        g_Sound_SfxState.KeyOffFlags |= arg1;
                    }
                    D_800305E0[var_s0 - 0xA0](arg0, arg1);
                }
            }
        }
        ++arg0->OpcodeStepCounter;
    } while (var_s0 > 0xA0);

    if (var_s0 == 0xA0) {
        if (arg0->Type == 0) {
            g_pActiveMusicContext->PendingKeyOffMask |= arg1;
        }
    } else {
        temp_a2_2 = Sound_PeekNextOpcode(arg0);
        if (arg0->FixedNoteLength != 0) {
            arg0->NoteLength = arg0->KeyLength = arg0->FixedNoteLength;
        }
        if (arg0->NoteLength != 0) {
            if ((temp_a2_2 >= 0x8F)
                || ((temp_a2_2 < 0x84) && !(arg0->Articulation & 5))) {
                arg0->KeyLength -= 2;
            }
        } else {
            int tmp = D_8002F620[var_s0 % 11];
            arg0->NoteLength = tmp;
            var_v1 = tmp;
            if (((temp_a2_2 - 0x84) >= 0xB) && !(arg0->Articulation & 5)) {
                var_v1 -= 2;
            }
            arg0->KeyLength = var_v1;
        }
        if ((arg0->Type == 0) && (arg0->UpdateFlags & 0x40)) {
            arg0->KeyLength = arg0->NoteLength;
        }

        arg0->LengthStored = arg0->NoteLength;
        arg0->VoiceParams.VoiceParamFlags |= 0x4000;

        if (var_s0 >= 0x8F) {
            if (arg0->Type == 0) {
                g_pActiveMusicContext->ActiveNoteMask &= ~arg1;
                if (arg0->VoiceParams.AssignedVoiceNumber < 0x18) {
                    g_pActiveMusicContext->PendingKeyOffMask |= arg1;
                }
            }
            arg0->PortamentoSteps = 0;
            arg0->VibratoPitch = 0;
            arg0->TremeloVolume = 0;
            arg0->Articulation &= 0xFFFD;
            return;
        }
        if (var_s0 < 0x84) {
            temp_a1_2 = arg0->UpdateFlags;
            temp_v0 = arg0->Octave * 0xC;
            temp_s0 = var_s0 / 11;
            temp_s0 += temp_v0;
            if (temp_a1_2 & 8) {
                temp_a2_2 = Sound_PlayKeymapNote(arg0, arg1, temp_s0);
            } else {
                if (!(arg0->Articulation & 2)) {
                    if (arg0->Type == 0) {
                        if (D_80039AFC & 0x10) {
                            temp_s0 += *((signed char*)g_pActiveMusicContext->unk44
                                         + ((temp_s0) % 12));
                        }
                        if (temp_a1_2 & 0x1000) {
                            func_8001A258(arg0, temp_s0);
                        }
                        g_pActiveMusicContext->PendingKeyOnMask |= arg1;
                        if ((g_pActiveMusicContext->ActiveNoteMask & arg1)
                            && (arg0->VoiceParams.AssignedVoiceNumber < 0x18)) {
                            g_pActiveMusicContext->PendingKeyOffMask |= arg1;
                        }

                        if (arg0->KeyOnVolumeSlideLength != 0) {
                            arg0->ChannelVolumeSlideLength = arg0->KeyOnVolumeSlideLength;
                            arg0->Volume = arg0->KeyOnVolume;
                            arg0->VolumeSlideStep = arg0->KeyOnVolumeSlideStep;
                        }
                    } else {
                        g_Sound_SfxState.KeyOnFlags |= arg1;
                    }
                    arg0->PitchSlideStepsCurrent = 0;
                }

                if ((arg0->PortamentoSteps != 0) && (arg0->KeyStored != 0)) {
                    arg0->PitchBendSlideLength = arg0->PortamentoSteps;
                    arg0->PitchBendSlideTranspose =
                        ((arg0->Transpose + temp_s0) - arg0->KeyStored)
                        - arg0->TransposeStored;
                    arg0->Key =
                        arg0->KeyStored - (arg0->Transpose - arg0->TransposeStored);
                    temp_s0 = arg0->KeyStored + arg0->TransposeStored;
                } else {
                    arg0->Key = temp_s0;
                    temp_s0 = temp_s0 + arg0->Transpose;
                }

                temp_a2_2 = Sound_CalculatePitch(&g_InstrumentInfo[arg0->InstrumentIndex],
                    temp_s0, arg0->FineTune, &arg0->FinePitchDelta);
                if (arg0->RandomPitchDepth != 0) {
                    sp10 = (temp_a2_2 * arg0->RandomPitchDepth) >> 8;
                    sp10 *= D_8002F69C[g_Sound_LfoPhase];
                    if (D_8002F69C[g_Sound_LfoPhase] & 0x80) {
                        sp10 >>= 9;
                        temp_a2_2 -= sp10;
                    } else {
                        sp10 >>= 7;
                        temp_a2_2 += sp10;
                    }
                }
            }
            arg0->PitchBase = temp_a2_2;
            if (arg0->Type == 0) {
                g_pActiveMusicContext->ActiveNoteMask |= arg1;
            } else {
                g_Sound_SfxState.KeyedFlags |= arg1;
            }
            temp_s0 = arg0->UpdateFlags;
            arg0->VoiceParams.VoiceParamFlags |= 0x13;
            if (temp_s0 & 1) {
                temp_v1_6 = ((arg0->VibratoDepth & 0x7F00) >> 8);
                arg0->VibratoBase = (!(arg0->VibratoDepth & 0x8000)
                                            ? (temp_v1_6 * ((temp_a2_2 * 0xF) >> 8))
                                            : (temp_v1_6 * temp_a2_2))
                                 >> 7;
                if (!(arg0->Articulation & 2)) {
                    arg0->VibratoWave = g_Sound_LfoTable[arg0->VibratoType];
                    arg0->VibratoDelayCurrent = arg0->VibratoDelay;
                    arg0->VibratoRateCurrent = 1;
                }
            }
            if ((temp_s0 & 2) && !(arg0->Articulation & 2)) {
                arg0->TremeloWave = g_Sound_LfoTable[arg0->TremeloType];
                arg0->TremeloDelayCurrent = arg0->TremeloDelay;
                arg0->TremeloRateCurrent = 1;
            }
            arg0->VibratoPitch = 0;
            arg0->TremeloVolume = 0;
            arg0->PitchSlide = 0;
        }

        arg0->Articulation =
            (arg0->Articulation & 0xFFFD) | ((arg0->Articulation & 1) * 2);
        if (arg0->PitchBendSlideTranspose != 0) {
            arg0->Key += arg0->PitchBendSlideTranspose;
            temp_a2_2 = Sound_CalculatePitch(&g_InstrumentInfo[arg0->InstrumentIndex],
                arg0->Key + arg0->Transpose, arg0->FineTune, (int*)&sp10);
            temp_a2_2 <<= 0x10;
            arg0->PitchSlideStepsCurrent = arg0->PitchBendSlideLength;
            arg0->PitchBendSlideTranspose = 0;
            arg0->PitchSlideStep =
                ((int)temp_a2_2 - ((arg0->PitchBase << 0x10) + arg0->PitchSlide))
                / arg0->PitchSlideStepsCurrent;
        }
        arg0->KeyStored = arg0->Key;
        arg0->TransposeStored = arg0->Transpose;
    }
}

void Sound_CopyInstrumentInfoToChannel(
    FSoundChannel* arg0, FSoundInstrumentInfo* arg1, int arg2)
{
    arg0->VoiceParams.StartAddress = arg2;
    arg0->VoiceParams.LoopAddress = arg1->LoopAddr;
    arg0->VoiceParams.AdsrLower = arg1->AdsrLower;
    arg0->VoiceParams.AdsrUpper = arg1->AdsrUpper;
    arg0->VoiceParams.VoiceParamFlags |= 0x1FF80;
}

void Sound_SetInstrumentToChannel(FSoundChannel* arg0, int arg1)
{
    arg0->InstrumentIndex = arg1;
    Sound_CopyInstrumentInfoToChannel(
        arg0, &g_InstrumentInfo[arg1], g_InstrumentInfo[arg1].StartAddr);
}

void Sound_ClearVoiceFromSfxState(FSoundChannel* arg0, int arg1)
{
    int temp_a1 = ~arg1;
    g_Sound_SfxState.ActiveVoiceMask &= temp_a1;
    g_Sound_SfxState.SuspendedVoiceMask &= temp_a1;
    g_Sound_SfxState.NoiseVoiceFlags &= temp_a1;
    g_Sound_SfxState.ReverbVoiceFlags &= temp_a1;
    g_Sound_SfxState.FmVoiceFlags &= temp_a1;
    g_Sound_SfxState.KeyOnFlags &= temp_a1;
    g_Sound_SfxState.KeyedFlags &= temp_a1;
    arg0->unk_Flags = 0;
    arg0->AkaoProgramIndex = 0;
}

#define SOUND_DEFAULT_PORTAMENTO_STEPS (0x100) // 256 steps
#define SOUND_DEFAULT_DELAY_TIME (0x101) // 256 + 1

#define READ_16LE_PC(pc) ((pc[0]) | (pc[1] << 8))

void SoundVM_A0_FinishChannel(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicContext->ActiveChannelMask &= ~in_VoiceFlags;
        if (g_pActiveMusicContext->ActiveChannelMask == 0) {
            g_Music_LoopCounter = 0;
            g_pActiveMusicContext->MusicId = 0;
            g_pActiveMusicContext->StatusFlags = 0;
        }
        g_pActiveMusicContext->ActiveNoteMask &= ~in_VoiceFlags;
        g_pActiveMusicContext->KeyedMask &= ~in_VoiceFlags;
        g_pActiveMusicContext->AllocatedVoiceMask &= ~in_VoiceFlags;
        g_pActiveMusicContext->NoiseChannelFlags &= ~in_VoiceFlags;
        g_pActiveMusicContext->ReverbChannelFlags &= ~in_VoiceFlags;
        g_pActiveMusicContext->FmChannelFlags &= ~in_VoiceFlags;
    } else {
        Sound_ClearVoiceFromSfxState(in_pChannel, in_VoiceFlags);
    }
    in_pChannel->UpdateFlags = 0;
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_04 | SOUND_GLOBAL_UPDATE_08;
}

void SoundVM_FE1F_unk(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (g_pActiveMusicContext->StatusFlags & 0x10000) {
        SoundVM_A0_FinishChannel(in_pChannel, in_VoiceFlags);
    }
}

void SoundVM_FE00_SetTempo(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    g_pActiveMusicContext->Tempo = in_pChannel->ProgramCounter[0] << 0x10;
    g_pActiveMusicContext->Tempo |= in_pChannel->ProgramCounter[1] << 0x18;
    in_pChannel->ProgramCounter += sizeof(short);
    g_pActiveMusicContext->TempoSlideLength = 0;
}

void SoundVM_FE01_SetTempoSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    char* pc;
    int Dest;
    int Prev;
    int Delta;

    if ((g_pActiveMusicContext->TempoSlideLength = *in_pChannel->ProgramCounter++) == 0) {
        g_pActiveMusicContext->TempoSlideLength = 0x100;
    }
    pc = in_pChannel->ProgramCounter;
    Dest = pc[0] << 0x10;
    Dest |= pc[1] << 0x18;
    in_pChannel->ProgramCounter += 2;
    Prev = g_pActiveMusicContext->Tempo & 0xFFFF0000;
    Delta = Dest - Prev;
    g_pActiveMusicContext->TempoSlideStep =
        Delta / g_pActiveMusicContext->TempoSlideLength;
    g_pActiveMusicContext->Tempo = Prev;
}

void SoundVM_FE02_SetMasterReverbDepth(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    char* pc;
    u_int Depth;

    pc = in_pChannel->ProgramCounter;
    Depth = (signed char)pc[1] << 0x14;
    Depth |= pc[0] << 0xC;
    in_pChannel->ProgramCounter += sizeof(short);
    g_pActiveMusicContext->ReverbDepthSlideLength = 0;
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_07;
    g_pActiveMusicContext->RevDepth = Depth;
}

void SoundVM_FE03_SetMasterReverbSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int Prev;
    int Dest;
    int Delta;
    char* pc;

    g_pActiveMusicContext->ReverbDepthSlideLength = *in_pChannel->ProgramCounter++;
    if (g_pActiveMusicContext->ReverbDepthSlideLength == 0) {
        g_pActiveMusicContext->ReverbDepthSlideLength = 0x100;
    }
    pc = in_pChannel->ProgramCounter;
    Dest = (signed char)pc[1] << 0x14;
    Dest |= (char)pc[0] << 0xC;
    in_pChannel->ProgramCounter += 2;
    Prev = g_pActiveMusicContext->RevDepth & ~0xFFF;
    g_pActiveMusicContext->RevDepth = Prev;
    Delta = Dest - Prev;
    g_pActiveMusicContext->ReverbDepthSlideStep =
        Delta / g_pActiveMusicContext->ReverbDepthSlideLength;
}

void SoundVM_FE06_JumpRelativeOffset(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    short Offset = READ_16LE_PC(in_pChannel->ProgramCounter);
    in_pChannel->ProgramCounter += Offset;
}

void SoundVM_FE07_JumpRelativeWithThreshold(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    short Threshold;
    short Offset;

    Threshold = *in_pChannel->ProgramCounter++;

    if (g_pActiveMusicContext->JumpThreshold >= Threshold) {
        // Read signed 16-bit LE offset at current pc, jump relative to pc
        Offset = READ_16LE_PC(in_pChannel->ProgramCounter);
        in_pChannel->ProgramCounter += Offset;
        return;
    }

    // Skip over the 16-bit offset operand
    in_pChannel->ProgramCounter += sizeof(short);
}

void SoundVM_FE0E_CallRelativeOffset(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    short Offset = READ_16LE_PC(in_pChannel->ProgramCounter);
    in_pChannel->ReturnProgramCounter = in_pChannel->ProgramCounter + sizeof(short);
    in_pChannel->ProgramCounter += Offset;
}

void SoundVM_FE0F_Return(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->ProgramCounter = in_pChannel->ReturnProgramCounter;
}

void SoundVM_A3_ChannelMasterVolume(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->VolumeBalance = *in_pChannel->ProgramCounter++ << 8;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
}

void SoundVM_FE12_VolumeBalanceSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short VolumeBalance;
    u_short Length;
    int Target;
    int Delta;

    Length = *in_pChannel->ProgramCounter++;
    in_pChannel->VolumeBalanceSlideLength = Length;
    if (Length == 0) {
        in_pChannel->VolumeBalanceSlideLength = 0x100;
    }

    Target = *in_pChannel->ProgramCounter++ << 8;

    VolumeBalance = in_pChannel->VolumeBalance & 0x7F00;
    in_pChannel->VolumeBalance = VolumeBalance;
    Delta = Target - VolumeBalance;
    in_pChannel->VolumeBalanceSlideStep = Delta / in_pChannel->VolumeBalanceSlideLength;
}

void SoundVM_A8_ChannelVolume(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->Volume = (signed char)*in_pChannel->ProgramCounter++ << 0x17;
    in_pChannel->ChannelVolumeSlideLength = 0;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
    in_pChannel->KeyOnVolumeSlideLength = 0;
}

void SoundVM_A9_ChannelVolumeSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int Prev;
    int Dest;
    u_short Length;
    int Delta;

    Length = *in_pChannel->ProgramCounter++;
    in_pChannel->ChannelVolumeSlideLength = Length;
    if (Length == 0) {
        in_pChannel->ChannelVolumeSlideLength = 0x100;
    }
    Dest = ((signed char)*in_pChannel->ProgramCounter++ << 0x17);

    Prev = in_pChannel->Volume & 0xFFFF0000;
    in_pChannel->Volume = Prev;

    Delta = Dest - Prev;
    in_pChannel->VolumeSlideStep = Delta / in_pChannel->ChannelVolumeSlideLength;

    in_pChannel->KeyOnVolumeSlideLength = 0;
}

void SoundVM_FE19_KeyOnVolumeSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short pPc1;
    int Dest;
    int Prev;
    int Delta;

    in_pChannel->KeyOnVolume = ((signed char)*in_pChannel->ProgramCounter++) << 0x17;
    pPc1 = *in_pChannel->ProgramCounter++;
    in_pChannel->KeyOnVolumeSlideLength = (short)pPc1;

    if (pPc1 == 0) {
        in_pChannel->KeyOnVolumeSlideLength = 0x100;
    }

    Dest = ((signed char)*in_pChannel->ProgramCounter++) << 0x17;
    Prev = in_pChannel->KeyOnVolume;
    Delta = Dest - Prev;
    in_pChannel->KeyOnVolumeSlideStep = Delta / in_pChannel->KeyOnVolumeSlideLength;
}

void SoundVM_FE1A_SetChannelTenuto(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->UpdateFlags |= SOUND_UPDATE_UNKNOWN_01;
}

void SoundVM_FE1B_UnsetChannelTenuto(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->UpdateFlags &= ~SOUND_UPDATE_UNKNOWN_01;
}

void SoundVM_FE0C_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    g_pActiveMusicContext->unk34 = *in_pChannel->ProgramCounter++;
}

static void SoundVM_nop(FSoundChannel* in_pChannels, u_int in_VoiceFlags)
    __attribute__((unused));
static void SoundVM_nop(FSoundChannel* in_pChannels __attribute__((unused)),
    u_int in_VoiceFlags __attribute__((unused)))
{
}

void SoundVM_unused1(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
    __attribute__((unused));
void SoundVM_unused1(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->VolumeMod = *in_pChannel->ProgramCounter++ << 8;
    in_pChannel->VolumeModStepsRemaining = 0;
    if (in_pChannel->UpdateFlags & 0x100) {
        in_pChannel->VoiceParams.VoiceParamFlags |= 3;
    }
}

void SoundVM_unused2(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
    __attribute__((unused));
void SoundVM_unused2(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    short v;
    int pc;

    if ((in_pChannel->VolumeModStepsRemaining = *in_pChannel->ProgramCounter++) == 0) {
        in_pChannel->VolumeModStepsRemaining = 0x100;
    }

    pc = *(in_pChannel->ProgramCounter++) << 8;
    v = in_pChannel->VolumeMod & 0xFF00;
    in_pChannel->VolumeModStep = ((pc - v) / in_pChannel->VolumeModStepsRemaining);
    in_pChannel->VolumeMod = v;
}

void SoundVM_AA_ChannelPan(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    // Convert signed pan (-64..+63) to unsigned 0..255, center at 0x40 and store as Q8.8
    // pan value
    in_pChannel->ChannelPan = ((*in_pChannel->ProgramCounter++ + 0x40) & 0xFF) << 8;
    in_pChannel->ChannelPanSlideLength = 0;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
}

void SoundVM_AB_ChannelPanSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short Prev;
    u_short Length;
    u_short Dest;
    int Delta;

    Length = *in_pChannel->ProgramCounter++;
    in_pChannel->ChannelPanSlideLength = Length;
    if (Length == 0) {
        in_pChannel->ChannelPanSlideLength = 0x100;
    }

    Dest = *in_pChannel->ProgramCounter++;
    Dest = ((Dest + 0x40) & 0xFF) << 8; // Center it
    Prev = in_pChannel->ChannelPan & 0xFF00;
    Delta = Dest - Prev;
    in_pChannel->PanSlideStep = Delta / in_pChannel->ChannelPanSlideLength;
    in_pChannel->ChannelPan = Prev;
}

void SoundVM_A5_SetOctave(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->Octave = *in_pChannel->ProgramCounter++;
}

void SoundVM_A6_IncreaseOctave(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->Octave = (in_pChannel->Octave + 1) & 0xF;
}

void SoundVM_A7_DecreaseOctave(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->Octave = (in_pChannel->Octave - 1) & 0xF;
}

void SoundVM_A1_LoadInstrument(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int pc = *in_pChannel->ProgramCounter++;

    int var_s0 = in_pChannel->Type == 0
                   ? func_8001A22C(g_pActiveMusicContext->StatusFlags, pc)
                   : func_8001A1F4(in_pChannel->unk38, pc);
    Sound_CopyInstrumentInfoToChannel(
        in_pChannel, &g_InstrumentInfo[var_s0], g_InstrumentInfo[var_s0].StartAddr);
    in_pChannel->InstrumentIndex = var_s0;
    in_pChannel->VoiceParams.VolumeScale = 0;
    in_pChannel->UpdateFlags &= 0xE6FFEFF7;
}

void SoundVM_FE0A_ClearInstrument(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short Index;

    Index = *in_pChannel->ProgramCounter++;
    Sound_CopyInstrumentInfoToChannel(in_pChannel, &g_InstrumentInfo[Index], 0x1010);
    in_pChannel->InstrumentIndex = Index;
    in_pChannel->VoiceParams.VolumeScale = 0;
    in_pChannel->UpdateFlags &=
        ~(SOUND_UPDATE_DRUM_MODE | SOUND_UPDATE_UNKNOWN_12 | SOUND_UPDATE_UNKNOWN_24
            | SOUND_UPDATE_UNKNOWN_27 | SOUND_UPDATE_UNKNOWN_28);
}

void SoundVM_FE14_ChangePatch(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short* pPatchTable;
    u_char PatchIndex;

    PatchIndex = *in_pChannel->ProgramCounter++;
    if (g_pActiveMusicContext->SequencePatchTable != NULL) {
        pPatchTable = (u_short*)g_pActiveMusicContext->SequencePatchTable;
        if (pPatchTable[PatchIndex] > 0x8000) {
            in_pChannel->VoiceParams.VolumeScale = 0;
            in_pChannel->UpdateFlags &= ~SOUND_UPDATE_UNKNOWN_12;
            return;
        }
        in_pChannel->Keymap = (char*)((int)pPatchTable + pPatchTable[PatchIndex] + 0x20);
        in_pChannel->UpdateFlags &=
            ~(SOUND_UPDATE_DRUM_MODE | SOUND_UPDATE_UNKNOWN_12 | SOUND_UPDATE_UNKNOWN_24
                | SOUND_UPDATE_UNKNOWN_27 | SOUND_UPDATE_UNKNOWN_28);
        in_pChannel->UpdateFlags |= SOUND_UPDATE_UNKNOWN_12;
        in_pChannel->Key = 0xFF;
    }
}

void SoundVM_B3_ResetAdsr(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    FSoundInstrumentInfo* InstrumentInfo =
        &g_InstrumentInfo[in_pChannel->InstrumentIndex];
    in_pChannel->VoiceParams.AdsrLower = InstrumentInfo->AdsrLower;
    in_pChannel->VoiceParams.AdsrUpper = InstrumentInfo->AdsrUpper;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_ADSR_FULL;
    in_pChannel->UpdateFlags &=
        ~(SOUND_UPDATE_UNKNOWN_24 | SOUND_UPDATE_UNKNOWN_27 | SOUND_UPDATE_UNKNOWN_28);
}

void SoundVM_C0_ChannelTranspose_Absolute(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->Transpose = (signed char)*in_pChannel->ProgramCounter++;
}

void SoundVM_C1_ChannelTranspose_Relative(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->Transpose += (signed char)*in_pChannel->ProgramCounter++;
}

void SoundVM_A4_PitchBendSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int Length = *in_pChannel->ProgramCounter++;
    in_pChannel->PitchBendSlideLength = Length;
    if (Length == 0) {
        in_pChannel->PitchBendSlideLength = 0x100;
    }

    in_pChannel->PitchBendSlideTranspose = (signed char)*in_pChannel->ProgramCounter++;
}

void SoundVM_DA_EnablePortamento(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int Steps = *in_pChannel->ProgramCounter++;
    in_pChannel->PortamentoSteps = Steps;

    if (Steps == 0) {
        in_pChannel->PortamentoSteps = SOUND_DEFAULT_PORTAMENTO_STEPS;
    }

    in_pChannel->TransposeStored = 0;
    in_pChannel->KeyStored = 0;
    in_pChannel->Articulation = 1;
}

void SoundVM_DB_DisablePortamento(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->PortamentoSteps = 0;
}

void SoundVM_D8_ChannelFineTune_Absolute(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_int ScaledFineTune;
    int FinePitchDelta;

    in_pChannel->FineTune = (signed char)*in_pChannel->ProgramCounter++;
    ScaledFineTune = in_pChannel->PitchBase * (char)in_pChannel->FineTune;

    if (in_pChannel->FineTune < 0) {
        FinePitchDelta = (ScaledFineTune >> 8) - in_pChannel->PitchBase;
    } else {
        FinePitchDelta = ScaledFineTune >> 7;
    }

    in_pChannel->FinePitchDelta = FinePitchDelta;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_SAMPLE_RATE;
}

void SoundVM_D9_ChannelFineTune_Relative(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_int ScaledFineTune;
    int FinePitchDelta;

    in_pChannel->FineTune =
        in_pChannel->FineTune + (signed char)*in_pChannel->ProgramCounter++;
    ScaledFineTune = in_pChannel->PitchBase * (char)in_pChannel->FineTune;

    if (in_pChannel->FineTune < 0) {
        FinePitchDelta = (ScaledFineTune >> 8) - in_pChannel->PitchBase;
    } else {
        FinePitchDelta = ScaledFineTune >> 7;
    }

    in_pChannel->FinePitchDelta = FinePitchDelta;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_SAMPLE_RATE;
}

void SoundVM_B4_Vibrato(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short PitchBase;
    int DepthHigh;
    u_int VibratoBase;
    int VibratoDepth;
    int VibratoRatePhase;
    int new_var;

    in_pChannel->UpdateFlags |= 1;

    if (in_pChannel->Type != 0) {
        in_pChannel->VibratoDelay = 0;
        VibratoDepth = *in_pChannel->ProgramCounter++;
        if (VibratoDepth != 0) {
            in_pChannel->VibratoDepth = VibratoDepth << 8;
        }
    } else {
        in_pChannel->VibratoDelay = *in_pChannel->ProgramCounter++;
    }

    VibratoRatePhase = *in_pChannel->ProgramCounter++;
    in_pChannel->VibratoRatePhase = VibratoRatePhase;

    if (VibratoRatePhase == 0) {
        in_pChannel->VibratoRatePhase = 0x100;
    }

    in_pChannel->VibratoType = *in_pChannel->ProgramCounter++;
    PitchBase = in_pChannel->PitchBase;
    new_var = PitchBase;
    DepthHigh = (in_pChannel->VibratoDepth & 0x7F00) >> 8;

    if (!(in_pChannel->VibratoDepth & 0x8000)) {
        VibratoBase = DepthHigh * ((new_var * 0xF) >> 8);
    } else {
        VibratoBase = DepthHigh * new_var;
    }
    in_pChannel->VibratoBase = VibratoBase >> 7;
    in_pChannel->VibratoWave = g_Sound_LfoTable[in_pChannel->VibratoType];
    in_pChannel->VibratoDelayCurrent = in_pChannel->VibratoDelay;
    in_pChannel->VibratoRateCurrent = 1;
}

void SoundVM_B5_VibratoDepth(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int PitchBase; // Base pitch around which the vibrato will oscillate
    u_int DepthAmount; // This is just the magnitude part of the vibrato depth parameter,
                       // 0-127 depth scalar
    u_int VibratoProduct; // Intermediate scaled value

    PitchBase = in_pChannel->PitchBase;

    // Read vibrato depth parameter from the sequence.
    // Stored in the high byte so bit 15 can act as a mode flag.
    in_pChannel->VibratoDepth = *in_pChannel->ProgramCounter++ << 8;

    // Extract the depth magnitude (bits 8–14)
    DepthAmount = (in_pChannel->VibratoDepth & 0x7F00) >> 8;
    if (!(in_pChannel->VibratoDepth & VIBRATO_FLAG_ABSOLUTE)) {
        // Relative mode:
        // Vibrato depth is scaled down relative to pitch so higher notes
        // don’t produce excessively wide vibrato.
        // (PitchBase * 15) >> 8 ≈ PitchBase * 0.0586
        VibratoProduct = DepthAmount * ((PitchBase * 15) >> 8);
    } else {
        // Absolute mode:
        // Vibrato depth is directly proportional to pitch.
        VibratoProduct = DepthAmount * PitchBase;
    }

    // Final vibrato amplitude in pitch units.
    // The >> 7 normalizes the multiplication into a usable range.
    in_pChannel->VibratoBase = VibratoProduct >> 7;
}

void SoundVM_DD_VibratoDepthSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short Length;
    u_short Prev;
    u_short Dest;
    int Delta;

    Length = *in_pChannel->ProgramCounter++;
    if (Length == 0) {
        Length = 0x100;
    }
    Dest = *in_pChannel->ProgramCounter++;
    Dest = Dest << 8;
    Prev = in_pChannel->VibratoDepth;
    Delta = Dest - Prev;
    in_pChannel->VibratoDepthSlideStep = Delta / Length;
    in_pChannel->VibratoDepthSlideLength = Length;
}

void SoundVM_B6_DisableVibrato(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->VibratoPitch = 0;
    in_pChannel->UpdateFlags &= ~SOUND_UPDATE_VIBRATO;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_SAMPLE_RATE;
}

void SoundVM_B8_Tremelo(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int Delay;
    int Rate;

    in_pChannel->UpdateFlags |= SOUND_UPDATE_TREMOLO;
    Delay = *in_pChannel->ProgramCounter++;
    if (in_pChannel->Type != 0) {
        in_pChannel->TremeloDelay = 0;
        if (Delay != 0) {
            in_pChannel->TremeloDepth = (Delay & 0x7F) << 8;
        }
    } else {
        in_pChannel->TremeloDelay = Delay;
    }

    Rate = *in_pChannel->ProgramCounter++;
    in_pChannel->TremeloRatePhase = Rate;

    if (Rate == 0) {
        in_pChannel->TremeloRatePhase = 0x100;
    }

    in_pChannel->TremeloType = *in_pChannel->ProgramCounter++;
    in_pChannel->TremeloWave = g_Sound_LfoTable[in_pChannel->TremeloType];
    in_pChannel->TremeloDelayCurrent = in_pChannel->TremeloDelay;
    in_pChannel->TremeloRateCurrent = 1;
}

void SoundVM_B9_TremeloDepth(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->TremeloDepth = (*in_pChannel->ProgramCounter++ & 0x7F) << 8;
}

void SoundVM_DE_TremeloDepthSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int Length;
    int Prev;
    u_int Dest;
    int Delta;

    Length = *in_pChannel->ProgramCounter++;
    if (Length == 0) {
        Length = 0x100;
    }
    Dest = (*in_pChannel->ProgramCounter++ & 0x7f) << 8;
    Prev = in_pChannel->TremeloDepth;
    Delta = Dest - Prev;
    in_pChannel->TremeloDepthSlideStep = Delta / Length;
    in_pChannel->TremeloDepthSlideLength = Length;
}

void SoundVM_BA_DisableTremelo(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->TremeloVolume = 0;
    in_pChannel->UpdateFlags &= ~SOUND_UPDATE_TREMOLO;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
}

void SoundVM_BC_AutoPan(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int Rate;

    in_pChannel->UpdateFlags |= SOUND_UPDATE_PAN_LFO;
    Rate = *in_pChannel->ProgramCounter++;
    in_pChannel->AutoPanRatePhase = Rate;

    if (Rate == 0) {
        in_pChannel->AutoPanRatePhase = 0x100;
    }

    in_pChannel->AutoPanType = *in_pChannel->ProgramCounter++;
    in_pChannel->AutoPanWave = g_Sound_LfoTable[in_pChannel->AutoPanType];
    in_pChannel->AutoPanRateCurrent = 1;
}

void SoundVM_BD_AutoPanDepth(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->AutoPanDepth = *in_pChannel->ProgramCounter++ << 7;
}

void SoundVM_DF_AutoPanDepthSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short Length;
    u_short Prev;
    u_short Dest;
    int Delta;

    Length = *in_pChannel->ProgramCounter++;
    if (Length == 0) {
        Length = 0x100;
    }
    Dest = *in_pChannel->ProgramCounter++;
    Dest = Dest << 7;
    Prev = in_pChannel->AutoPanDepth;

    Delta = Dest - Prev;
    in_pChannel->AutoPanDepthSlideStep = Delta / Length;
    in_pChannel->AutoPanDepthSlideLength = Length;
}

void SoundVM_BE_DisableAutoPan(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->AutoPanVolume = 0;
    in_pChannel->UpdateFlags &= ~SOUND_UPDATE_PAN_LFO;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_VOLUME;
}

void SoundVM_C4_EnableNoiseVoices(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicContext->NoiseChannelFlags |= in_VoiceFlags;
    } else {
        g_Sound_SfxState.NoiseVoiceFlags |= in_VoiceFlags;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_04 | SOUND_GLOBAL_UPDATE_08;
}

void SoundVM_C5_DisableNoiseVoices(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicContext->NoiseChannelFlags &= ~in_VoiceFlags;
    } else {
        g_Sound_SfxState.NoiseVoiceFlags &= ~in_VoiceFlags;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_04 | SOUND_GLOBAL_UPDATE_08;
    in_pChannel->NoiseTimer = 0;
}

void SoundVM_C6_EnableFmVoices(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicContext->FmChannelFlags |= in_VoiceFlags;
    } else if (in_pChannel->UpdateFlags & SOUND_UPDATE_UNKNOWN_16) {
        g_Sound_SfxState.FmVoiceFlags |= in_VoiceFlags;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_08;
}

void SoundVM_C7_DisableFmVoices(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicContext->FmChannelFlags &= ~in_VoiceFlags;
    } else {
        g_Sound_SfxState.FmVoiceFlags &= ~in_VoiceFlags;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_08;
    in_pChannel->FmTimer = 0;
}

void SoundVM_C2_EnableReverbVoices(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicContext->ReverbChannelFlags |= in_VoiceFlags;
    } else {
        g_Sound_SfxState.ReverbVoiceFlags |= in_VoiceFlags;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_08;
}

void SoundVM_C3_DisableReverbVoices(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicContext->ReverbChannelFlags &= ~in_VoiceFlags;
    } else {
        g_Sound_SfxState.ReverbVoiceFlags &= ~in_VoiceFlags;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_08;
}

void SoundVM_CC_EnableLegato(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->Articulation = SOUND_SFX_LEGATO;
}

void SoundVM_CD_DEBUG(FSoundChannel* in_pChannel __attribute__((unused)),
    u_int in_VoiceFlags __attribute__((unused)))
{
}

void SoundVM_D0_EnableSustainedNote(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    if (in_pChannel->Type != SOUND_CHANNEL_TYPE_MUSIC) {
        in_pChannel->Articulation = SOUND_SFX_FULL_LENGTH;
    }
}

void SoundVM_D1_DEBUG(FSoundChannel* in_pChannel __attribute__((unused)),
    u_int in_VoiceFlags __attribute__((unused)))
{
}

void SoundVM_AC_NoiseClockFrequency(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int Frequency = *in_pChannel->ProgramCounter++;
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        if (Frequency & 0xC0) {
            g_pActiveMusicContext->NoiseClock =
                (g_pActiveMusicContext->NoiseClock + (Frequency & 0x3F)) & 0x3F;
        } else {
            g_pActiveMusicContext->NoiseClock = Frequency;
        }
    } else if (Frequency & 0xC0) {
        g_Sound_SfxState.NoiseClock =
            (g_Sound_SfxState.NoiseClock + (Frequency & 0x3F)) & 0x3F;
    } else {
        g_Sound_SfxState.NoiseClock = Frequency;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_04;
}

void SoundVM_AD_AttackRate(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short AttackRate = *in_pChannel->ProgramCounter++;
    in_pChannel->VoiceParams.AdsrLower &= ~SOUND_ADSR_ATTACK_RATE_MASK;
    in_pChannel->VoiceParams.AdsrLower |= AttackRate << SOUND_ADSR_ATTACK_RATE_SHIFT;
    in_pChannel->VoiceParams.VoiceParamFlags |=
        (VOICE_PARAM_ADSR_AMODE | VOICE_PARAM_ADSR_AR);
    in_pChannel->UpdateFlags |= SOUND_UPDATE_UNKNOWN_24;
}

void SoundVM_AE_DecayRate(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short DecayRate = *in_pChannel->ProgramCounter++;
    in_pChannel->VoiceParams.AdsrLower &= ~SOUND_ADSR_DECAY_RATE_MASK;
    in_pChannel->VoiceParams.AdsrLower |= DecayRate << SOUND_ADSR_DECAY_RATE_SHIFT;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_ADSR_DR;
}

void SoundVM_AF_SustainLevel(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short SustainLevel = *in_pChannel->ProgramCounter++;
    in_pChannel->VoiceParams.AdsrLower &= ~SOUND_ADSR_SUS_LEVEL_MASK;
    in_pChannel->VoiceParams.AdsrLower |= SustainLevel;
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_ADSR_SL;
}

void SoundVM_B1_SustainRate(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short SustainRate = *in_pChannel->ProgramCounter++;
    in_pChannel->VoiceParams.AdsrUpper &= ~SOUND_ADSR_SUS_RATE_MASK;
    in_pChannel->VoiceParams.AdsrUpper |= SustainRate << SOUND_ADSR_SUS_RATE_SHIFT;
    in_pChannel->VoiceParams.VoiceParamFlags |=
        (VOICE_PARAM_ADSR_SR | VOICE_PARAM_ADSR_SMODE);
    in_pChannel->UpdateFlags |= SOUND_UPDATE_UNKNOWN_27;
}

void SoundVM_B2_ReleaseRate(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short ReleaseRate = *in_pChannel->ProgramCounter++;
    in_pChannel->VoiceParams.AdsrUpper &= ~SOUND_ADSR_RELEASE_RATE_MASK;
    in_pChannel->VoiceParams.AdsrUpper |= ReleaseRate << SOUND_ADSR_RELEASE_RATE_SHIFT;
    in_pChannel->VoiceParams.VoiceParamFlags |=
        (VOICE_PARAM_ADSR_RR | VOICE_PARAM_ADSR_RMODE);
    in_pChannel->UpdateFlags |= SOUND_UPDATE_UNKNOWN_28;
}

void SoundVM_B7_AttackMode(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short Mode = *in_pChannel->ProgramCounter++;

    in_pChannel->VoiceParams.AdsrLower &= ~SOUND_ADSR_ATTACK_MODE_MASK;

    if (Mode == SOUND_AMODE_5) {
        in_pChannel->VoiceParams.AdsrLower |= SOUND_ADSR_ATTACK_MODE_MASK;
    }
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_ADSR_AMODE;
}

void SoundVM_BB_SustainMode(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short mode = *(in_pChannel->ProgramCounter++);
    in_pChannel->VoiceParams.AdsrUpper &= ~((1 << 14) | (1 << 15));

    switch (mode) {
    case 3:
        in_pChannel->VoiceParams.AdsrUpper |= 0x4000;
        break;
    case 5:
        in_pChannel->VoiceParams.AdsrUpper |= 0x8000;
        break;
    case 7:
        in_pChannel->VoiceParams.AdsrUpper |= 0xC000;
        break;
    }
    in_pChannel->VoiceParams.VoiceParamFlags |= 0x200;
}

void SoundVM_BF_ReleaseMode(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short Value = *in_pChannel->ProgramCounter++;

    in_pChannel->VoiceParams.AdsrUpper &= ~SOUND_ADSR_RELEASE_MODE_MASK;
    if (Value == SOUND_RMODE_7) {
        in_pChannel->VoiceParams.AdsrUpper |= SOUND_ADSR_RELEASE_MODE_MASK;
    }
    in_pChannel->VoiceParams.VoiceParamFlags |= VOICE_PARAM_ADSR_RMODE;
}

void SoundVM_FE10_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    g_pActiveMusicContext->SomeIndexRelatedToSpuVoiceInfo =
        *in_pChannel->ProgramCounter++;
}

void SoundVM_FE11_unk(FSoundChannel* in_pChannel __attribute__((unused)),
    u_int in_VoiceFlags __attribute__((unused)))
{
    g_pActiveMusicContext->SomeIndexRelatedToSpuVoiceInfo = 0;
}

void SoundVM_C8_LoopPoint(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->LoopStackTop = (in_pChannel->LoopStackTop + 1) & 3;
    in_pChannel->LoopStartPc[in_pChannel->LoopStackTop] = in_pChannel->ProgramCounter;
    in_pChannel->LoopIterationCount[in_pChannel->LoopStackTop] = 0;
    in_pChannel->LoopStepCounterSnapshot[in_pChannel->LoopStackTop] =
        in_pChannel->OpcodeStepCounter;
}

void SoundVM_C9_LoopN(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short NewCount;
    u_short TopIndex;
    u_short DesiredLoopCount;

    DesiredLoopCount = *in_pChannel->ProgramCounter++;
    if (DesiredLoopCount == 0) {
        DesiredLoopCount = 0x100;
    }

    TopIndex = in_pChannel->LoopStackTop;
    NewCount = in_pChannel->LoopIterationCount[TopIndex] + 1;
    in_pChannel->LoopIterationCount[TopIndex] = NewCount;

    if (NewCount != DesiredLoopCount) {
        in_pChannel->ProgramCounter = in_pChannel->LoopStartPc[in_pChannel->LoopStackTop];
        in_pChannel->OpcodeStepCounter =
            in_pChannel->LoopStepCounterSnapshot[in_pChannel->LoopStackTop];
        return;
    }

    in_pChannel->LoopStackTop =
        (in_pChannel->LoopStackTop - 1) & SOUND_LOOP_STACK_MAX_INDEX;
}

void SoundVM_FE08_JumpOnNthLoopPass(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short N;
    short JumpOffset;

    // pLoopCount   pOffset
    // 0x01         0x02          0x03         0x04

    N = *in_pChannel->ProgramCounter++;
    if (N == 0) {
        N = 0x100;
    }

    // If current loop's iteration + 1 != N
    if ((in_pChannel->LoopIterationCount[in_pChannel->LoopStackTop] + 1) != N) {
        // Jumps to next program instruction
        in_pChannel->ProgramCounter = in_pChannel->ProgramCounter + sizeof(u_short);
        return;
    }

    // Read the relative offset
    JumpOffset = READ_16LE_PC(in_pChannel->ProgramCounter);

    // Jump from pOffset to the relative offset
    in_pChannel->ProgramCounter += JumpOffset;
}

void SoundVM_FE09_JumpAndPopStackOnNthLoopPass(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short N;
    short JumpOffset;

    N = *in_pChannel->ProgramCounter++;
    if (N == 0) {
        N = 0x100;
    }

    if ((in_pChannel->LoopIterationCount[in_pChannel->LoopStackTop] + 1) != N) {
        in_pChannel->ProgramCounter += sizeof(u_short);
        return;
    }

    JumpOffset = READ_16LE_PC(in_pChannel->ProgramCounter);

    in_pChannel->ProgramCounter += JumpOffset;
    in_pChannel->LoopStackTop =
        (in_pChannel->LoopStackTop - 1) & SOUND_LOOP_STACK_MAX_INDEX;
}

void SoundVM_CA_LoopInf(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->LoopIterationCount[in_pChannel->LoopStackTop] += 1;
    in_pChannel->ProgramCounter = in_pChannel->LoopStartPc[in_pChannel->LoopStackTop];
    in_pChannel->OpcodeStepCounter =
        in_pChannel->LoopStepCounterSnapshot[in_pChannel->LoopStackTop];
}

void SoundVM_A2_OverwriteNextNoteLength(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short Length;

    Length = *in_pChannel->ProgramCounter++;
    in_pChannel->FixedNoteLength = 0;
    in_pChannel->KeyLength = Length;
    in_pChannel->NoteLength = Length;
    in_pChannel->LengthStored = Length;
}

// Set the duration for all the upcoming notes (same as A2 except it doesn't apply only to
// the next note)
void SoundVM_DC_FixNoteLength(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int NoteLength;

    NoteLength = *(signed char*)in_pChannel->ProgramCounter++;
    if (NoteLength != 0) {
        NoteLength += in_pChannel->LengthStored;
        if (NoteLength <= 0) {
            NoteLength = 1;
        } else if (NoteLength >= 256) {
            NoteLength = 255;
        }
    }
    in_pChannel->FixedNoteLength = NoteLength;
}

void SoundVM_FE04_ClearKeymapTable(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    if (g_pActiveMusicContext->KeymapTable != NULL) {
        in_pChannel->UpdateFlags &=
            ~(SOUND_UPDATE_DRUM_MODE | SOUND_UPDATE_UNKNOWN_12 | SOUND_UPDATE_UNKNOWN_24
                | SOUND_UPDATE_UNKNOWN_27 | SOUND_UPDATE_UNKNOWN_28);
        in_pChannel->UpdateFlags |= SOUND_UPDATE_DRUM_MODE;
    }
}

void SoundVM_FE05_MuteVoice(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->VoiceParams.VolumeScale = 0;
    in_pChannel->UpdateFlags &= ~SOUND_UPDATE_DRUM_MODE;
}

void SoundVM_FE15_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    g_pActiveMusicContext->TimerLower = *in_pChannel->ProgramCounter++;
    g_pActiveMusicContext->TimerUpper = *in_pChannel->ProgramCounter++;
    g_pActiveMusicContext->TimerLowerCurrent = 0;
    g_pActiveMusicContext->TimerUpperCurrent = 0;
}

void SoundVM_FE16_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    g_pActiveMusicContext->TimerTopCurrent = *in_pChannel->ProgramCounter++;
    g_pActiveMusicContext->TimerTopCurrent |= *in_pChannel->ProgramCounter++ << 8;
}

void SoundVM_B0_DecayRateAndSustainLevel(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    SoundVM_AE_DecayRate(in_pChannel, in_VoiceFlags);
    SoundVM_AF_SustainLevel(in_pChannel, in_VoiceFlags);
}

void SoundVM_CE_EnableNoiseAndDelayToggle(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    u_short Timer;
    u_short Value;

    Value = *in_pChannel->ProgramCounter++;
    if (Value != 0) {
        Timer = Value + 1;
    } else {
        Timer = SOUND_DEFAULT_DELAY_TIME;
    }

    in_pChannel->NoiseTimer = Timer;

    SoundVM_C4_EnableNoiseVoices(in_pChannel, in_VoiceFlags);
}

void SoundVM_CF_ToggleNoiseOnDelay(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short Delay = *in_pChannel->ProgramCounter++;
    if (Delay != 0) {
        in_pChannel->NoiseTimer = Delay + 1;
        return;
    }
    in_pChannel->NoiseTimer = SOUND_DEFAULT_DELAY_TIME;
}

void SoundVM_D2_EnableFmAndDelayToggle(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    u_short Timer;
    u_short Value;

    Value = *in_pChannel->ProgramCounter++;
    if (Value != 0) {
        Timer = Value + 1;
    } else {
        Timer = SOUND_DEFAULT_DELAY_TIME;
    }

    in_pChannel->FmTimer = Timer;
    SoundVM_C6_EnableFmVoices(in_pChannel, in_VoiceFlags);
}

void SoundVM_D3_ToggleFmDelay(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short Delay = *in_pChannel->ProgramCounter++;
    if (Delay != 0) {
        in_pChannel->FmTimer = Delay + 1;
        return;
    }
    in_pChannel->FmTimer = SOUND_DEFAULT_DELAY_TIME;
}

void SoundVM_CB_DisableVoiceModes(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    in_pChannel->UpdateFlags &=
        ~(SOUND_UPDATE_SIDE_CHAIN_PITCH | SOUND_UPDATE_SIDE_CHAIN_VOL
            | SOUND_UPDATE_PAN_LFO | SOUND_UPDATE_TREMOLO | SOUND_UPDATE_VIBRATO);
    SoundVM_C5_DisableNoiseVoices(in_pChannel, in_VoiceFlags);
    SoundVM_C7_DisableFmVoices(in_pChannel, in_VoiceFlags);
    SoundVM_C3_DisableReverbVoices(in_pChannel, in_VoiceFlags);
    in_pChannel->Articulation &= ~(SOUND_SFX_LEGATO | SOUND_SFX_FULL_LENGTH);
}

void SoundVM_D4_EnablePlaybackRateSidechain(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->UpdateFlags |= SOUND_UPDATE_SIDE_CHAIN_PITCH;
}

void SoundVM_D5_DisablePlaybackRateSidechain(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->UpdateFlags &= ~SOUND_UPDATE_SIDE_CHAIN_PITCH;
}

void SoundVM_D6_EnablePitchVolumeSidechain(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->UpdateFlags |= SOUND_UPDATE_SIDE_CHAIN_VOL;
}

void SoundVM_D7_DisablePitchVolumeSidechain(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->UpdateFlags &= ~SOUND_UPDATE_SIDE_CHAIN_VOL;
}

void SoundVM_FE0B_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int temp_v0;
    char* pc;
    char* var_a1;
    char* var_a2;

    pc = in_pChannel->ProgramCounter;
    temp_v0 = (pc[1] << 8) | pc[0];

    if (temp_v0 != 0) {
        var_a1 = &pc[temp_v0] + 2;
    } else {
        var_a1 = NULL;
    }

    pc += 2;
    temp_v0 = (pc[1] << 8) | pc[0];

    if (temp_v0 != 0) {
        var_a2 = &pc[temp_v0] + 2;
    } else {
        var_a2 = NULL;
    }

    g_Sound_CommandParams_Vm_FE08.Param1 = 0;
    g_Sound_CommandParams_Vm_FE08.Param2 = 0;
    g_Sound_CommandParams_Vm_FE08.Param3 = in_pChannel->ChannelPan >> 8;
    g_Sound_CommandParams_Vm_FE08.Param4 = in_pChannel->Volume >> 0x17;
    Sound_PlaySfxProgram(&g_Sound_CommandParams_Vm_FE08, var_a1, var_a2, 0);
    in_pChannel->ProgramCounter += 4;
}

void SoundVM_E0_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->UpdateFlags |= SOUND_UPDATE_UNKNOWN_20;
}

void SoundVM_FE1C_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int temp_v0 = *in_pChannel->ProgramCounter++;
    g_pActiveMusicContext->unk44 = (FSoundKeymapEntry8*)&D_8002F66C[temp_v0];
}

void SoundVM_FE1D_MarkVoicesKeyed(
    FSoundChannel* in_pChannel __attribute__((unused)), u_int in_VoiceFlags)
{
    g_pActiveMusicContext->KeyedMask |= in_VoiceFlags;
}

void SoundVM_FE1E_ClearVoicesKeyed(
    FSoundChannel* in_pChannel __attribute__((unused)), u_int in_VoiceFlags)
{
    g_pActiveMusicContext->KeyedMask &= ~in_VoiceFlags;
}

void SoundVM_E1_SetRandomPitchDepth(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->RandomPitchDepth = *in_pChannel->ProgramCounter++;
}

void SoundVM_E2_ResetRandomPitchDepth(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->RandomPitchDepth = 0;
}

void SoundVM_XX_Unimplemented(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    SoundVM_A0_FinishChannel(in_pChannel, in_VoiceFlags);
}

void Sound_Cutscene_StopStream(void)
{
    int temp_a2;

    if (g_Sound_Cutscene_StreamState.VoicesInUseFlags != 0) {
        SpuSetIRQ(0);
        SpuSetIRQCallback(NULL);
        SetVoiceKeyOff(g_Sound_Cutscene_StreamState.VoicesInUseFlags);
        temp_a2 = g_Sound_Cutscene_StreamState.VoicesInUseFlags;
        g_Sound_Cutscene_StreamState.VoicesInUseFlags = 0;
        g_Sound_SfxState.ReverbVoiceFlags &= ~temp_a2;
        g_Sound_GlobalFlags.UpdateFlags |= 0x100;
    }
}

// Scans voice pairs 22/23 down to 12/13 for one with no busy voice
int Sound_Cutscene_FindFreeVoicePair(void)
{
    u_int BusyMask;
    int VoiceIndex;
    u_int Bit;

    do {
        Bit = 0x00C00000;
        VoiceIndex = 12;
        BusyMask = g_Sound_SfxState.ActiveVoiceMask | g_Sound_SfxState.SuspendedVoiceMask;

        while (VoiceIndex != 0 && (BusyMask & Bit)) {
            VoiceIndex -= 2;
            Bit >>= 2;
        }

        if (VoiceIndex != 0) {
            return VoiceIndex + 10;
        }

        // No free pair: evict the lowest priority SFX voice and retry
        Sound_EvictSfxVoice(0, 0x40000000);
    } while (BusyMask
             != (g_Sound_SfxState.ActiveVoiceMask | g_Sound_SfxState.SuspendedVoiceMask));

    return -1;
}

void func_8001CE60(void)
{
    u_char* temp_s0 = g_Sound_Cutscene_StreamState.pCurrentChunk + 0x800;
    SpuSetTransferStartAddr(0x2100);
    SpuSetTransferCallback(Sound_Cutscene_OnInitialTransferComplete);
    SpuWrite(temp_s0, 0x800);
}

void func_8001D3D4(void);

void Sound_Cutscene_StartStream(u_int* arg0, int arg1, int arg2)
{
    int VoiceIndex;
    u_int transferSize;

    VoiceIndex = Sound_Cutscene_FindFreeVoicePair();
    if (VoiceIndex != -1) {
        u_int* s3;
        g_Sound_Cutscene_StreamState.field19_0x4c.s32 = arg1;
        SpuSetIRQ(0);
        SpuSetIRQCallback(NULL);
        s3 = arg0;
        g_Sound_Cutscene_StreamState.pCurrentChunk = s3 + 0x10;
        g_Sound_Cutscene_StreamState.TotalPages = s3[4];
        g_Sound_Cutscene_StreamState.CurrentPage = s3[8];
        g_Sound_Cutscene_StreamState.VoiceIndex = VoiceIndex;
        g_Sound_Cutscene_StreamState.VoicesInUseFlags =
            (1 << VoiceIndex) | (1 << (VoiceIndex + 1));
        SetVoiceKeyOff(g_Sound_Cutscene_StreamState.VoicesInUseFlags);
        g_Sound_Cutscene_StreamState.field2_0x8 = s3[6];
        g_Sound_Cutscene_StreamState.VoiceSampleRate = (u_short)s3[7];
        g_Sound_Cutscene_StreamState.VoiceIndex = VoiceIndex;
        g_Sound_Cutscene_StreamState.VoicesInUseFlags =
            (1 << VoiceIndex) | (1 << (VoiceIndex + 1));
        SetVoiceKeyOff(g_Sound_Cutscene_StreamState.VoicesInUseFlags);
        SpuSetTransferMode(0);
        SpuSetTransferStartAddr(0x1100U);
        g_bSpuTransferring = 1;

        g_Sound_Cutscene_StreamState.unk_Mask_0x4 =
            (g_Sound_Cutscene_StreamState.field2_0x8 & 2)
                ? g_Sound_Cutscene_StreamState.pCurrentChunk + s3[5]
                : NULL;
        if (g_Sound_Cutscene_StreamState.field2_0x8 & 1) {
            g_Sound_Cutscene_StreamState.field7_0x1c =
                (g_Sound_Cutscene_StreamState.field2_0x8 & 2)
                    ? g_Sound_Cutscene_StreamState.TotalPages - (s3[5] >> 1)
                    : 0;
            SpuSetTransferCallback(func_8001D3D4);
            transferSize = 0x2000;
        } else {
            g_Sound_Cutscene_StreamState.field7_0x1c =
                (g_Sound_Cutscene_StreamState.field2_0x8 & 2)
                    ? g_Sound_Cutscene_StreamState.TotalPages - s3[5]
                    : 0;
            SpuSetTransferCallback(func_8001CE60);
            transferSize = 0x800;
        }
        SpuWrite((u_char*)g_Sound_Cutscene_StreamState.pCurrentChunk, transferSize);
        if (arg2 != 0) {
            g_Sound_SfxState.ReverbVoiceFlags |=
                g_Sound_Cutscene_StreamState.VoicesInUseFlags;
        } else {
            g_Sound_SfxState.ReverbVoiceFlags &=
                ~g_Sound_Cutscene_StreamState.VoicesInUseFlags;
        }
        g_Sound_SfxState.FmVoiceFlags &= ~g_Sound_Cutscene_StreamState.VoicesInUseFlags;
        g_Sound_SfxState.NoiseVoiceFlags &=
            ~g_Sound_Cutscene_StreamState.VoicesInUseFlags;
        g_Sound_GlobalFlags.UpdateFlags |= 0x100;
    }
}

void Sound_Cutscene_InitVoice(
    int in_Voice, int in_PanMode, int in_StartAddr, int in_RepeatAddr)
{
    short VolR;
    short VolL;

    if (D_80039AFC & 2) {
        int volume = (g_Sound_Cutscene_StreamState.Volume
                         * g_Sound_StereoPanGainTableQ15[PAN_CENTER_INDEX])
                  >> 0x10;
        VolR = volume;
        VolL = volume;
    } else {
        if (in_PanMode == 1) {
            VolR = 0;
            VolL = g_Sound_Cutscene_StreamState.Volume >> 1;
        } else if (in_PanMode == 2) {
            VolL = 0;
            VolR = g_Sound_Cutscene_StreamState.Volume >> 1;
        } else if (in_PanMode == 3) {
            int VolHalfQ16 = (g_Sound_Cutscene_StreamState.Volume >> 1) << 0x10;
            VolR = (VolHalfQ16 >> 0x11) + (VolHalfQ16 >> 0x12);
            VolL = VolR;
        } else {
            char Mask = 0xFF;
            VolL = ((g_Sound_Cutscene_StreamState.Volume
                        * g_Sound_StereoPanGainTableQ15[g_Sound_Cutscene_StreamState
                                .field19_0x4c.u8[1]])
                    >> 0x10);
            VolR = ((g_Sound_Cutscene_StreamState.Volume
                        * g_Sound_StereoPanGainTableQ15
                            [g_Sound_Cutscene_StreamState.field19_0x4c.u8[1] ^ Mask])
                    >> 0x10);
        }
    }
    SetVoiceVolume(in_Voice, VolL, VolR, 0);
    SetVoiceSampleRate(in_Voice, g_Sound_Cutscene_StreamState.VoiceSampleRate);
    SetVoiceStartAddr(in_Voice, in_StartAddr);
    SetVoiceRepeatAddr(in_Voice, in_RepeatAddr);
    SetVoiceAdsrAttackRateAndMode(in_Voice, 0, 1);
    SetVoiceAdsrDecayRate(in_Voice, 0xF);
    SetVoiceAdsrSustainLevel(in_Voice, 0xF);
    SetVoiceAdsrSustainRateAndDirection(in_Voice, 0x7F, 3);
    SetVoiceAdsrReleaseRateAndMode(in_Voice, 6, 3);
}

void Sound_Cutscene_BeginPlayback(
    int in_SomeIndex, int in_SampleAddr, void (*in_Callback)())
{
    int var_s2 = in_SampleAddr;
    if (g_Sound_Cutscene_StreamState.VoicesInUseFlags != 0) {
        SpuSetTransferCallback(NULL);
        g_bSpuTransferring = 0;
        if (g_Sound_Cutscene_StreamState.TotalPages >= 0x1001) {
            g_Sound_Cutscene_StreamState.TotalPages -= 0x1000;
            g_Sound_Cutscene_StreamState.pCurrentChunk += in_SomeIndex;
            SpuSetIRQCallback(in_Callback);
        } else {
            SpuSetIRQCallback(Sound_Cutscene_StopStream);
            var_s2 = 0x1030;
            g_Sound_Cutscene_StreamState.TotalPages = 0;
        }
        SpuSetIRQAddr(var_s2 + 8);
        SetVoiceKeyOn(g_Sound_Cutscene_StreamState.VoicesInUseFlags);
        SpuSetIRQ(1);
    }
}

void Sound_Cutscene_OnInitialTransferComplete(void)
{
    Sound_Cutscene_InitVoice(g_Sound_Cutscene_StreamState.VoiceIndex, 0, 0x1100, 0x2100);
    Sound_Cutscene_InitVoice(
        g_Sound_Cutscene_StreamState.VoiceIndex + 1, 0, 0x1100, 0x2100);
    Sound_Cutscene_BeginPlayback(0x1000, 0x2100, Sound_Cutscene_OnBufferAComplete);
}

void func_8001D5E4(void);

void func_8001D3D4(void)
{
    Sound_Cutscene_InitVoice(g_Sound_Cutscene_StreamState.VoiceIndex, 1, 0x1100, 0x2100);
    Sound_Cutscene_InitVoice(
        g_Sound_Cutscene_StreamState.VoiceIndex + 1, 2, 0x1900, 0x2900);
    Sound_Cutscene_BeginPlayback(0x2000, 0x2100, func_8001D5E4);
}

void Sound_Cutscene_LoadNextBuffer(
    int in_RepeatAddressL, int in_RepeatAddressR, int in_Param3, void (*in_IrqCallback)())
{
    if ((g_Sound_Cutscene_StreamState.VoicesInUseFlags != 0)
        && (g_Sound_Cutscene_StreamState.TotalPages != 0)) {
        SpuSetTransferStartAddr(in_RepeatAddressL);
        SetSpuTransferCallback();
        SpuWrite((u_char*)g_Sound_Cutscene_StreamState.pCurrentChunk, in_Param3);
        SpuSetIRQ(0);
        if (g_Sound_Cutscene_StreamState.TotalPages > 0x800) {
            SpuSetIRQCallback(in_IrqCallback);
            g_Sound_Cutscene_StreamState.TotalPages -= 0x800;
            g_Sound_Cutscene_StreamState.pCurrentChunk += in_Param3;
        } else if (g_Sound_Cutscene_StreamState.unk_Mask_0x4 != 0) {
            SpuSetIRQCallback(in_IrqCallback);
            g_Sound_Cutscene_StreamState.pCurrentChunk =
                g_Sound_Cutscene_StreamState.unk_Mask_0x4;
            g_Sound_Cutscene_StreamState.TotalPages =
                g_Sound_Cutscene_StreamState.field7_0x1c;
        } else {
            SpuSetIRQCallback(Sound_Cutscene_StopStream);
            in_RepeatAddressR = 0x1030;
            in_RepeatAddressL = 0x1030;
            g_Sound_Cutscene_StreamState.TotalPages = 0;
        }
        SetVoiceRepeatAddr(g_Sound_Cutscene_StreamState.VoiceIndex, in_RepeatAddressL);
        SetVoiceRepeatAddr(
            g_Sound_Cutscene_StreamState.VoiceIndex + 1, in_RepeatAddressR);
        SpuSetIRQAddr(in_RepeatAddressL + 8);
        SpuSetIRQ(1);
    }
}

void Sound_Cutscene_OnBufferAComplete(void)
{
    Sound_Cutscene_LoadNextBuffer(
        0x1100, 0x1100, 0x800, Sound_Cutscene_OnBufferBComplete);
}

void Sound_Cutscene_OnBufferBComplete(void)
{
    Sound_Cutscene_LoadNextBuffer(
        0x2100, 0x2100, 0x800, Sound_Cutscene_OnBufferAComplete);
}

void func_8001D614();

void func_8001D5E4(void)
{
    Sound_Cutscene_LoadNextBuffer(0x1100, 0x1900, 0x1000, func_8001D614);
}

void func_8001D614(void)
{
    Sound_Cutscene_LoadNextBuffer(0x2100, 0x2900, 0x1000, func_8001D5E4);
}

void Sound_Cutscene_StartStream(u_int*, int, int);

void func_8001D644(int* arg0)
{
    Sound_Cutscene_StopStream();
    Sound_Cutscene_StartStream((u_int*)arg0[0], arg0[1], arg0[2]);
    g_Sound_SfxState.ActiveVoiceMask &= ~g_Sound_Cutscene_StreamState.VoicesInUseFlags;
}

void Sound_Cmd_E2_StopCutsceneStream(void) { Sound_Cutscene_StopStream(); }

void Sound_Cmd_E4_SetCutsceneVolume(FSoundCommandParams* in_Params)
{
    g_Sound_Cutscene_StreamState.Volume = in_Params->Param1;
    g_Sound_Cutscene_StreamState.VolFadeStepsRemaining = 0;
    if (g_Sound_Cutscene_StreamState.VoicesInUseFlags != 0) {
        SetVoiceVolume(g_Sound_Cutscene_StreamState.VoiceIndex,
            ((g_Sound_Cutscene_StreamState.Volume << 15) >> 16), 0, 0);
        SetVoiceVolume(g_Sound_Cutscene_StreamState.VoiceIndex + 1, 0,
            ((g_Sound_Cutscene_StreamState.Volume << 15) >> 16), 0);
    }
}

void Sound_Cmd_E5_FadeOutCutscene(FSoundCommandParams* in_Params)
{
    short var_a1 = 1;
    if (in_Params->Param1 != 0) {
        var_a1 = in_Params->Param1;
    }
    g_Sound_Cutscene_StreamState.VolFadeStepSize =
        (short)((short)(in_Params->Param2 - g_Sound_Cutscene_StreamState.Volume)
                / var_a1);
    g_Sound_Cutscene_StreamState.VolFadeStepsRemaining = var_a1;
}

void func_8001D7A8(int* arg0)
{
    g_Sound_Cutscene_StreamState.field19_0x4c.s32 = *arg0;

    if (g_Sound_Cutscene_StreamState.VoicesInUseFlags != 0) {
        if (D_80039AFC & 2) {
            int var_s0 = (g_Sound_Cutscene_StreamState.Volume * D_8002F89C) >> 0x10;
            SetVoiceVolume(g_Sound_Cutscene_StreamState.VoiceIndex, var_s0, var_s0, 0);
            SetVoiceVolume(
                g_Sound_Cutscene_StreamState.VoiceIndex + 1, var_s0, var_s0, 0);
        } else if (g_Sound_Cutscene_StreamState.field2_0x8 & 1) {
            int var_s0 = g_Sound_Cutscene_StreamState.Volume;
            var_s0 <<= 0xF;
            var_s0 >>= 0x10;
            SetVoiceVolume(g_Sound_Cutscene_StreamState.VoiceIndex, var_s0, 0, 0);
            SetVoiceVolume(g_Sound_Cutscene_StreamState.VoiceIndex + 1, 0, var_s0, 0);
        } else {
            int var_s0;
            int v1 = (g_Sound_Cutscene_StreamState.field19_0x4c.s32 >> 8) & 0xFF;
            short temp_s1 = g_Sound_StereoPanGainTableQ15[v1];
            temp_s1 = (g_Sound_Cutscene_StreamState.Volume * temp_s1) >> 0x10;
            var_s0 =
                (g_Sound_Cutscene_StreamState.Volume
                    * *(((((g_Sound_Cutscene_StreamState.field19_0x4c.s32 >> 8) & 0xFF)
                            ^ 0xFF))
                        + g_Sound_StereoPanGainTableQ15))
                >> 0x10;
            SetVoiceVolume(g_Sound_Cutscene_StreamState.VoiceIndex, temp_s1, var_s0, 0);
            SetVoiceVolume(
                g_Sound_Cutscene_StreamState.VoiceIndex + 1, temp_s1, var_s0, 0);
        }
    }
}
