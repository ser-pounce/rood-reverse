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
    char magic[4];
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
} D_800378C0_t;

static int Sound_IsNotAkaoFile(int*);
int func_80013588(void*, int);
int func_800135D8(void*, int, int, int);
void func_8001369C(void);
static void StartSound(void);
static void SetVoiceKeyOff(u_int);
void func_800161C4(int, int);
void func_8001653C(FSoundChannel*, FSoundCommandParams*, int, char*);
void Sound_PlaySfxProgram(FSoundCommandParams*, char*, char*, int);
int func_80016DA8(int);
u_int func_80018C30(int);
long func_80019A58(void);
static void StopSound(void);
static void _writeSpu(char* data, u_int len);
void Sound_Cutscene_OnInitialTransferComplete(void);
void Sound_Cutscene_InitVoice(int, int, int, int);
void Sound_Cutscene_BeginPlayback(int, int, void (*)(void));
void Sound_Cutscene_LoadNextBuffer(int, int, int, void (*)(void));
void Sound_Cutscene_OnBufferAComplete(void);
void Sound_Cutscene_OnBufferBComplete(void);
void IRQCallbackProc(void);
void Sound_LoadAkaoSequence(FAkaoSequence* in_Sequence);
void Sound_SetMusicSequence(FAkaoSequence* in_Sequence, int in_SwapWithSavedState);
void func_80015BAC(void);
void Sound_memcpy32(void*, void*, int);
void UpdateCdVolume(void);
int func_8001A1F4(int, int);
int func_8001A22C(int, int);
void Sound_CopyInstrumentInfoToChannel(FSoundChannel*, FSoundInstrumentInfo*, int);

extern int _soundEvent;
extern char _soundFlush[64];
extern short D_800358FE;
extern CdlATV _cdlAtv;
extern D_80036770_t D_80036770;
extern int D_800377E0[3];
extern u_short* g_Sound_SfxProgramOffsets;
extern u_short* g_Sound_SfxMetadataTable;
extern char* g_Sound_SfxProgramData;
extern int D_800378A0;
extern D_800378C0_t D_800378C0;
extern int D_800378E4;
extern char _spuMemInfo;
extern volatile int _isSpuTransfer;
extern FSoundChannel D_80035910[10];
extern int D_80039AFC;
extern int D_80039B14;
extern int D_80039B64;
extern int D_80037848;
extern short D_8003784C;
extern int D_800378E0;
extern short D_800378E2;

extern FSoundChannelConfig* g_pActiveMusicConfig;
extern FSoundVoiceSchedulerState g_Sound_VoiceSchedulerState;
extern FSoundGlobalFlags g_Sound_GlobalFlags;
extern FSpuVoiceInfo g_SpuVoiceInfo[VOICE_COUNT];
extern FSoundChannel g_ActiveMusicChannels[0x20];
extern FSoundChannelConfig* g_pSavedMousicConfig;
extern FSoundChannel* g_pSecondaryMusicChannels;
extern FSoundFadeTimer g_Sound_MasterFadeTimer;
extern FSoundCutsceneStreamState g_Sound_Cutscene_StreamState;
extern u_int g_Sound_ProgramCounter;
extern FSoundChannelConfig* g_Sound_VoiceChannelConfigs[VOICE_COUNT];
extern FSoundChannel SfxSoundChannels[12];
extern volatile int g_bSpuTransferring;
#define SPU_PAN_TABLE_SIZE (0x100)
#define PAN_CENTER_INDEX (SPU_PAN_TABLE_SIZE / 2)
extern short g_Sound_StereoPanGainTableQ15[SPU_PAN_TABLE_SIZE];
extern short D_8002F89C;
extern FSoundChannelConfig g_PushedMusicConfig;
extern u_int g_Music_LoopCounter;
extern FSoundChannel D_800366F0;
extern FSoundChannel D_800378E8[];
extern FSoundInstrumentInfo g_InstrumentInfo[256];
extern short* g_Sound_LfoTable[];

int InitSound(void)
{
    StartSound();
    return 0;
}

int TeardownSound(void)
{
    StopSound();
    return 0;
}

int Sound_BindAkaoSfxBlob(void* in_Blob)
{
    int notAkao = Sound_IsNotAkaoFile(in_Blob);

    in_Blob += sizeof(AkaoSeqHeader);

    if (notAkao == 0) {
        g_Sound_SfxProgramOffsets = in_Blob;
        in_Blob += 0x600;
        g_Sound_SfxMetadataTable = in_Blob;
        in_Blob += 0x300;
        g_Sound_SfxProgramData = in_Blob;
    }
    return notAkao;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011E40);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011EBC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011F08);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011F24);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011F90);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011FB4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011FDC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012004);

int func_80012024(void)
{
    D_800358FE = 0;
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012034);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012080);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800120B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800120E8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012110);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001215C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001217C);

int func_800121F0(void* arg0, int arg1, int arg2, int arg3)
{
    void* var_v0;

    var_v0 = (void*)-1;
    if (Sound_IsNotAkaoFile(arg0) == 0) {
        D_800378C0.unk0 = arg0;
        D_800378C0.unk4 = (int)(arg1 & 0xFFFFFF);
        D_800378C0.unk8 = (int)(arg2 & 0xFF);
        D_800378C0.unkC = (int)(arg3 & 0x7F);
        func_80018C30(0x24);
        var_v0 = arg0;
    }
    return (u_long)var_v0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012288);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800122C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800122F0);

int func_80012358(int arg0)
{
    FSoundChannel* var_a1;
    int var_v1;
    int a2;
    if ((arg0 == 0) || ((a2 = g_Sound_VoiceSchedulerState.ActiveChannelMask) == 0)) {
        return 0;
    }
    for (var_a1 = SfxSoundChannels - 10, var_v1 = 0x1000; var_v1 & 0xFFFFFF;
         var_v1 *= 2, ++var_a1) {
        if ((a2 & var_v1) && (arg0 == var_a1->unk28)) {
            return var_a1->unk3C;
        }
    }

    return 0;
}

int func_800123C8(vs_main_sfxContext* arg0)
{
    int ret = 0;
    if ((long)arg0 >= 0x80000000) {
        ret = arg0->unk9 >> 7;
    } else if (g_Sound_SfxMetadataTable[(long)arg0] & 0x8000) {
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", vs_sound_setMonoSound);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012440);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012468);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012490);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800124FC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012568);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800125A8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800125D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012608);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001264C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012694);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800126C0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800126F4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012738);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012780);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800127AC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800127E0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012824);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001286C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800128A0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800128D8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012918);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012940);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012970);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800129A4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800129D0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012A04);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012A40);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012A6C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012AA0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012ADC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012B08);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012B3C);

void func_80012B78(void) { func_80018C30(240); }

void func_80012B98(void) { func_80018C30(241); }

void func_80012BB8(void* arg0, int arg1)
{
    while (func_80013588(arg0, arg1) == 1)
        ;
}

int vs_sound_spuTransferring(void) { return _isSpuTransfer; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012C14);

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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012E50);

int func_80012EBC(void)
{
    g_Sound_GlobalFlags.MixBehavior &= ~0x10000;
    D_80036770.unk4 = 0;
    D_80036770.unk0 = 0;
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012EF0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012F10);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013188);

int func_800131DC(void* arg0, int arg1, int arg2)
{
    int sp10;
    int sp14;

    func_80012D9C((int*)arg0, &sp10, &sp14, arg1);
    func_800135D8(arg0, arg2, sp10, sp14);
    return 0;
}

int vs_sound_setCdVol(u_int arg0)
{
    if (D_80039AFC & 2) {
        _cdlAtv.val0 = _cdlAtv.val2 = _cdlAtv.val1 = _cdlAtv.val3 =
            (arg0 * 0xB570) >> 0x11;
    } else {
        _cdlAtv.val2 = arg0;
        _cdlAtv.val0 = arg0;
        _cdlAtv.val3 = 0;
        _cdlAtv.val1 = 0;
    }
    CdMix(&_cdlAtv);
    return 0;
}

void func_800132C4(void* arg0, int arg1, int arg2)
{
    if (Sound_IsNotAkaoFile(arg0) == 0) {
        D_800378C0.unk0 = arg0;
        D_800378C0.unk4 = (arg1 & 0xFF) << 8;
        D_800378C0.unk8 = arg2;
        func_80018C30(0xE0);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013328);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013348);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013378);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800133B0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800133E0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013418);

static int Sound_IsNotAkaoFile(int* data)
{
    return data[0] - ('A' | ('K' << 8) | ('A' << 16) | ('O' << 24));
}

static void _spuWriteComplete(void)
{
    SpuSetTransferCallback(NULL);
    _isSpuTransfer = 0;
}

void spuSetTransferCallback(void)
{
    _isSpuTransfer = 1;
    SpuSetTransferCallback(_spuWriteComplete);
}

static void _writeSpu(char* data, u_int len)
{
    _isSpuTransfer = 1;
    SpuSetTransferCallback(_spuWriteComplete);
    SpuWrite(data, len);
}

static void _readSpu(char* data, u_int len)
{
    spuSetTransferCallback();
    SpuRead(data, len);
}

static void _waitTransferAvailable(void)
{
    if (_isSpuTransfer == 1) {
        do {

        } while (_isSpuTransfer == 1);
    }
}

int func_80013588(void* arg0, int arg1)
{
    if (Sound_IsNotAkaoFile(arg0) == 0) {
        func_800135D8(arg0, arg1, ((int*)arg0)[6], ((int*)arg0)[4]);
        return 0;
    }
    return -1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800135D8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001369C);

static void StartSound(void)
{
    int event;

    SpuStart();
    SpuInitMalloc(4, &_spuMemInfo);
    SpuSetTransferMode(SPU_TRANSFER_BY_DMA);
    SpuSetTransferStartAddr(0x1010);
    _writeSpu(_soundFlush, 64);
    _waitTransferAvailable();
    func_8001369C();
    SpuSetIRQ(SPU_OFF);
    SpuSetIRQCallback(NULL);
    while (SetRCnt(RCntCNT2, 0x44E8, RCntMdINTR) == 0)
        ;
    while (StartRCnt(RCntCNT2) == 0)
        ;
    do {
        event = OpenEvent(RCntCNT2, EvSpINT, EvMdINTR, func_80019A58);
        _soundEvent = event;
    } while (event == -1);
    while (EnableEvent(_soundEvent) == 0)
        ;
}

static void StopSound(void)
{
    if (_isSpuTransfer == 1) {
        _writeSpu(_soundFlush, 64);
        _waitTransferAvailable();
    }
    while (StopRCnt(RCntCNT2) == 0)
        ;
    UnDeliverEvent(RCntCNT2, EvSpINT);
    while (DisableEvent(_soundEvent) == 0)
        ;
    while (CloseEvent(_soundEvent) == 0)
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

void SetVoiceParamsByFlags(u_int in_VoiceIndex, FSoundVoiceParams* in_VoiceParams)
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
        if (flags == 0)
            return;
    }

    if (flags & VOICE_PARAM_VOLUME) {
        flags &= ~VOICE_PARAM_VOLUME;
        SetVoiceVolume(in_VoiceIndex, in_VoiceParams->Volume.left,
            in_VoiceParams->Volume.right, in_VoiceParams->VolumeScale);
        if (flags == 0)
            return;
    }

    if (flags & VOICE_PARAM_START_ADDR) {
        flags &= ~VOICE_PARAM_START_ADDR;
        SetVoiceStartAddr(in_VoiceIndex, in_VoiceParams->StartAddress);
        if (flags == 0)
            return;
    }

    if (flags & VOICE_PARAM_LOOP_ADDR) {
        flags &= ~VOICE_PARAM_LOOP_ADDR;
        SetVoiceRepeatAddr(in_VoiceIndex, in_VoiceParams->LoopAddress);
        if (flags == 0)
            return;
    }

    if (flags & VOICE_PARAM_ADSR_UPPER) {
        flags &= ~VOICE_PARAM_ADSR_UPPER;
        SetVoiceAdsrUpper(in_VoiceIndex, in_VoiceParams->AdsrUpper);
        if (flags == 0)
            return;
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
                g_pActiveMusicConfig->NoiseChannelFlags ^= in_VoiceFlags;
            } else {
                g_Sound_VoiceSchedulerState.NoiseVoiceFlags ^= in_VoiceFlags;
            }
            g_Sound_GlobalFlags.UpdateFlags |=
                (SOUND_GLOBAL_UPDATE_04 | SOUND_GLOBAL_UPDATE_08);
        }
    }

    if (in_pChannel->FmTimer != 0) {
        in_pChannel->FmTimer--;
        if (!(in_pChannel->FmTimer & 0xFFFF)) {
            if (in_Arg2 == 0) {
                g_pActiveMusicConfig->FmChannelFlags ^= in_VoiceFlags;
            } else {
                g_Sound_VoiceSchedulerState.FmVoiceFlags ^= in_VoiceFlags;
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

        if ((in_pChannel->VibratoDelayCurrent == 0) && (in_pChannel->unkA4 != 1)) {
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
            && ((u_short)in_pChannel->unkB6 != 1)) {
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001436C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800147CC);

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
        i = g_pActiveMusicConfig->SomeIndexRelatedToSpuVoiceInfo;
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80014D08);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80014D70);

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

    if (g_pSavedMousicConfig != NULL) {
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001503C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015080);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800151C0);

void Sound_RestoreChannelVolumeFromMasterFade(FSoundChannelConfig* in_Config)
{
    in_Config->A_Volume = g_Sound_MasterFadeTimer.SavedValue;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015220);

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

    Filter = ~(g_Sound_VoiceSchedulerState.ActiveChannelMask
               | g_Sound_VoiceSchedulerState.unk_Flags_0x10
               | g_Sound_Cutscene_StreamState.VoicesInUseFlags);
    VoiceMask = 0;
    SavedOffMask = 0;

    if (g_pSavedMousicConfig) {
        SavedOffMask = g_pSavedMousicConfig->PendingKeyOffMask;
        SavedConfigKeyedMask = SavedOffMask & g_pSavedMousicConfig->KeyedMask;

        if (SavedConfigKeyedMask != 0) {
            ChannelMaskToVoiceMaskFiltered(
                g_pSecondaryMusicChannels, &VoiceMask, SavedConfigKeyedMask, Filter);
            g_pSavedMousicConfig->PendingKeyOffMask &= ~g_pSavedMousicConfig->KeyedMask;
            SavedOffMask &= ~g_pSavedMousicConfig->KeyedMask;
        }
    }

    ActiveOffMask = g_pActiveMusicConfig->PendingKeyOffMask;
    ActiveKeyedMask = ActiveOffMask & g_pActiveMusicConfig->KeyedMask;

    if (ActiveKeyedMask != 0) {
        ChannelMaskToVoiceMaskFiltered(
            g_ActiveMusicChannels, &VoiceMask, ActiveKeyedMask, Filter);
        g_pActiveMusicConfig->PendingKeyOffMask &= ~g_pActiveMusicConfig->KeyedMask;
        ActiveOffMask &= ~g_pActiveMusicConfig->KeyedMask;
    }

    if (g_pSavedMousicConfig && (SavedOffMask != 0)) {
        ChannelMaskToVoiceMaskFiltered(
            g_pSecondaryMusicChannels, &VoiceMask, SavedOffMask, Filter);
        g_pSavedMousicConfig->PendingKeyOffMask = 0;
    }

    if (ActiveOffMask != 0) {
        ChannelMaskToVoiceMaskFiltered(
            g_ActiveMusicChannels, &VoiceMask, ActiveOffMask, Filter);
        g_pActiveMusicConfig->PendingKeyOffMask = 0;
    }

    VoiceMask |= g_Sound_VoiceSchedulerState.KeyOffFlags;
    g_Sound_VoiceSchedulerState.KeyOffFlags = 0;

    if (VoiceMask != 0) {
        SetVoiceKeyOff(VoiceMask);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015970);

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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015BAC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015C9C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015D38);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", Sound_LoadAkaoSequence);

void Sound_KillMusicConfig(
    FSoundChannelConfig* in_Config, FSoundChannel* in_pChannel, u_int arg2)
{
    FSoundChannel* pChannel;
    FSoundChannelConfig** ppThisChannelConfig;
    u_int Count;

    pChannel = in_pChannel;
    if ((in_Config->ActiveChannelMask != 0)
        && ((arg2 == 0) || (arg2 == in_Config->MusicId))) {
        in_Config->PendingKeyOffMask = -1;
        for (Count = SOUND_CHANNEL_COUNT; Count != 0; Count--) {
            pChannel->Length1 = 3;
            pChannel->Length2 = 1;
            pChannel->ProgramCounter = (char*)&g_Sound_ProgramCounter;
            pChannel++;
        };

        ppThisChannelConfig = g_Sound_VoiceChannelConfigs;
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800161C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001653C);

void FreeVoiceChannels(FSoundChannel* in_Channel, u_int in_Voice)
{
    u_int VoiceIndex;

    if (in_Voice < VOICE_COUNT) {
        VoiceIndex = 0;
        while (VoiceIndex < SOUND_CHANNEL_COUNT) {
            if (in_Channel->VoiceParams.AssignedVoiceNumber == in_Voice) {
                in_Channel->VoiceParams.AssignedVoiceNumber = VOICE_COUNT;
                g_pActiveMusicConfig->ActiveNoteMask &= ~(1 << VoiceIndex);
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
        func_800161C4(0, in_CommandParams->Param2);
    }

    while (1) {
        channel = SfxSoundChannels;
        voiceBit = 0x400000;

        activeVoices = g_Sound_VoiceSchedulerState.ActiveChannelMask
                     | g_Sound_VoiceSchedulerState.unk_Flags_0x10
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

        func_800161C4(0, 0x40000000);

        if (activeVoices
            == (g_Sound_VoiceSchedulerState.ActiveChannelMask
                | g_Sound_VoiceSchedulerState.unk_Flags_0x10
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
    block2 = g_Sound_SfxProgramData;
    block0 = g_Sound_SfxProgramOffsets;

    *out_ProgramCounter1 =
        block0[in_SfxIndex] == 0xFFFF ? NULL : block2 + block0[in_SfxIndex];

    ++in_SfxIndex;

    *out_ProgramCounter2 =
        block0[in_SfxIndex] == 0xFFFF ? NULL : block2 + block0[in_SfxIndex];
}

void Sound_MarkActiveChannelsVolumeDirty(
    FSoundChannelConfig* in_pChannelConfig, FSoundChannel* in_pChannel)
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
    FSoundChannel* pChannel = SfxSoundChannels - 10;

    if (g_Sound_VoiceSchedulerState.ActiveChannelMask == 0) {
        return;
    }

    ActiveChannelMask = g_Sound_VoiceSchedulerState.ActiveChannelMask;

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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", Sound_SetMusicSequence);

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
    if ((g_PushedMusicConfig.MusicId != 0)
        && (g_PushedMusicConfig.MusicId == in_Params->Param3)) {
        Sound_SetMusicSequence((FAkaoSequence*)in_Params->Param1, 0);
        return;
    }
    Sound_LoadAkaoSequence((FAkaoSequence*)in_Params->Param1);
    g_pActiveMusicConfig->MusicId = in_Params->Param3;
}

void Sound_Cmd_40_PushMusicState(void)
{
    u_int i;

    if (g_pActiveMusicConfig->ActiveChannelMask != 0) {
        FSoundChannel* c;
        Sound_memcpy32(&D_800366F0, &g_PushedMusicConfig, 0x80);
        Sound_memcpy32(g_ActiveMusicChannels, (FSoundChannelConfig*)D_800378E8, 0x2200);
        for (i = 0, c = D_800378E8; i < 32; ++i, ++c) {
            Sound_MapInstrumentToBaseSampleBank(g_PushedMusicConfig.StatusFlags, c);
        }
    }
}

void Sound_Cmd_19_Unk(FSoundCommandParams* arg0)
{
    if ((g_pActiveMusicConfig->ActiveChannelMask != 0)
        && ((g_pSavedMousicConfig == NULL) || (g_pSavedMousicConfig->MusicId == 0))) {
        g_pSavedMousicConfig = &g_PushedMusicConfig;
        g_pSecondaryMusicChannels = D_800378E8;
        Sound_memcpy32(&D_800366F0, &g_PushedMusicConfig, 0x80);
        Sound_memcpy32(g_ActiveMusicChannels,
            (FSoundChannelConfig*)g_pSecondaryMusicChannels, 0x2200);
    }
    Sound_LoadAkaoSequence((FAkaoSequence*)arg0->Param1);
    g_pActiveMusicConfig->A_Volume = (arg0->ExtParam1 & 0x7F) << 0x10;
    g_pActiveMusicConfig->unk68 = 0;
    g_pActiveMusicConfig->MusicId = arg0->Param3;
    func_80015BAC();
    g_Sound_GlobalFlags.MixBehavior &= ~0x100;
}

void Sound_Cmd_1A_Unk(FSoundCommandParams* arg0)
{
    if ((g_PushedMusicConfig.MusicId != 0)
        && (g_PushedMusicConfig.MusicId == arg0->Param3)) {
        g_pSavedMousicConfig = &g_PushedMusicConfig;
        g_pSecondaryMusicChannels = D_800378E8;
        Sound_SetMusicSequence((FAkaoSequence*)arg0->Param1, 1);
    } else {
        if ((g_pActiveMusicConfig->ActiveChannelMask != 0)
            && ((g_pSavedMousicConfig == NULL) || (g_pSavedMousicConfig->MusicId == 0))) {
            g_pSavedMousicConfig = &g_PushedMusicConfig;
            g_pSecondaryMusicChannels = D_800378E8;
            Sound_memcpy32(&D_800366F0, &g_PushedMusicConfig, 0x80);
            Sound_memcpy32(g_ActiveMusicChannels,
                (FSoundChannelConfig*)g_pSecondaryMusicChannels, 0x2200);
        }
        Sound_LoadAkaoSequence((FAkaoSequence*)arg0->Param1);
        g_pActiveMusicConfig->MusicId = arg0->Param3;
    }
    g_Sound_GlobalFlags.MixBehavior &= ~0x100;
    if (g_pSavedMousicConfig != NULL) {
        int temp_a1 = arg0->ExtParam1;
        g_Sound_MasterFadeTimer.Value = 0x7F0000;
        g_Sound_GlobalFlags.MixBehavior |= 0x100;
        g_Sound_MasterFadeTimer.TicksRemaining = temp_a1;
        g_Sound_MasterFadeTimer.Step = (int)0xFF810000 / temp_a1;
    }
    g_pActiveMusicConfig->A_Volume = 0;
    g_pActiveMusicConfig->unk68 = arg0->ExtParam1;
    g_pActiveMusicConfig->unk64 = ((arg0->ExtParam2 & 0x7F) << 0x10) / arg0->ExtParam1;
    func_80015BAC();
}

void Sound_Cmd_12_unk(FSoundCommandParams* in_Params)
{
    int LoopCounter;

    Sound_Cmd_10_StartFieldMusic(in_Params);
    LoopCounter = 0;
    if (in_Params->Param4 != 0) {
        LoopCounter = in_Params->Param4 - 1;
    }
    g_Music_LoopCounter = LoopCounter;
}

void Sound_Cmd_34_unk(FSoundCommandParams* arg0)
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

void Sound_Cmd_30_unk(FSoundCommandParams* arg0)
{
    char* sp10;
    char* sp14;

    Sound_GetProgramCounters(&sp10, &sp14, arg0->Param1);
    arg0->Param2 = 0x02000000;
    arg0->Param3 = 0x80;
    arg0->Param4 = 0x7F;
    arg0->ExtParam1 = func_80016DA8(g_Sound_SfxMetadataTable[arg0->Param1]);
    Sound_PlaySfxProgram(arg0, sp10, sp14, 0);
}

void Sound_Cmd_20_unk(FSoundCommandParams* arg0)
{
    char* akaoOffset;
    char* akaoData;

    Sound_GetProgramCounters(&akaoOffset, &akaoData, arg0->Param1);
    arg0->ExtParam1 = func_80016DA8(g_Sound_SfxMetadataTable[arg0->Param1]);
    Sound_PlaySfxProgram(arg0, akaoOffset, akaoData, 0);
}

// https://decomp.me/scratch/wOmFh
INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001733C);

void Sound_Cmd_21_unk(FSoundCommandParams* arg0)
{
    func_800161C4(arg0->Param1, arg0->Param2);
}

void Sound_Cmd_C0_unk(FSoundCommandParams* arg0)
{
    FSoundChannel* var_a1;
    FSoundChannelConfig* var_a0;
    int temp_v1;

    temp_v1 = arg0->Param1;
    if ((temp_v1 == 0) || (temp_v1 == g_pActiveMusicConfig->MusicId)) {
        var_a0 = g_pActiveMusicConfig;
        var_a1 = g_ActiveMusicChannels;
        var_a0->A_Volume = (arg0->Param2 & 0x7F) << 0x10;
        var_a0->unk68 = 0;
        Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
    } else {
        var_a0 = g_pSavedMousicConfig;
        if ((var_a0 != NULL) && (temp_v1 != 0) && (temp_v1 == var_a0->MusicId)) {
            var_a1 = g_pSecondaryMusicChannels;
            var_a0->A_Volume = (arg0->Param2 & 0x7F) << 0x10;
            var_a0->unk68 = 0;
            Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
        }
    }
}

void Sound_Cmd_C1_unk(FSoundCommandParams* arg0)
{
    FSoundChannel* var_a1;
    FSoundChannelConfig* var_a0;
    int temp_a1;
    int var_v1;

    int var_a2 = 1;

    if (arg0->Param2 != 0) {
        var_a2 = arg0->Param2;
    }

    temp_a1 = arg0->Param1;
    var_v1 = (arg0->Param3 & 0x7F) << 0x10;

    if ((temp_a1 == 0) || (temp_a1 == g_pActiveMusicConfig->MusicId)) {
        var_a0 = g_pActiveMusicConfig;
        var_v1 = (int)(var_v1 - var_a0->A_Volume);
        var_v1 = var_v1 / var_a2;
        var_a1 = g_ActiveMusicChannels;
        var_a0->unk68 = var_a2;
        var_a0->unk64 = var_v1;
        Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
    } else {
        var_a0 = g_pSavedMousicConfig;
        if ((var_a0 != NULL) && (temp_a1 != 0) && (temp_a1 == var_a0->MusicId)) {
            var_v1 = (int)(var_v1 - var_a0->A_Volume);
            var_v1 = var_v1 / var_a2;
            var_a1 = g_pSecondaryMusicChannels;
            var_a0->unk68 = var_a2;
            var_a0->unk64 = var_v1;
            Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
        }
    }
}

void Sound_Cmd_C2_unk(FSoundCommandParams* arg0)
{
    FSoundChannel* var_a1;
    FSoundChannelConfig* var_a0;
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
    if ((temp_v1 == 0) || (temp_v1 == g_pActiveMusicConfig->MusicId)) {
        var_a0 = g_pActiveMusicConfig;
        var_a1 = g_ActiveMusicChannels;
    } else {
        var_a0 = g_pSavedMousicConfig;
        if ((var_a0 == NULL) || (temp_v1 == 0) || (temp_v1 != var_a0->MusicId)) {
            return;
        }
        var_a1 = g_pSecondaryMusicChannels;
    }
    temp_v1_2 = (arg0->Param3 & 0x7F) << 0x10;
    var_a0->A_Volume = temp_v1_2;
    var_a0->unk64 = (int)(((arg0->Param4 & 0x7F) << 0x10) - temp_v1_2) / var_a2;
    var_a0->unk68 = var_a2;
    Sound_MarkActiveChannelsVolumeDirty(var_a0, var_a1);
}

void Sound_Cmd_C8_unk(FSoundCommandParams* arg0)
{
    D_8003784C = 0;
    D_800378E0 = (u_short)arg0->Param1 << 0x10;
    UpdateCdVolume();
}

void Sound_Cmd_C9_unk(FSoundCommandParams* arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = arg0->Param1;
    var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    D_8003784C = var_a1;
    D_80037848 = (((u_short)arg0->Param2 << 0x10) - D_800378E0) / var_a1;
}

void Sound_Cmd_CA_unk(FSoundCommandParams* arg0)
{
    unsigned int new_var;
    int var_a1 = 1;
    if (arg0->Param1 != 0) {
        var_a1 = arg0->Param1;
    }
    D_8003784C = var_a1;
    new_var = ((u_short)arg0->Param3) << 0x10;
    D_800378E0 = (u_short)arg0->Param2 << 0x10;
    D_80037848 = (int)(new_var - D_800378E0) / var_a1;
}

void Sound_Cmd_A0_unk(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a1 = D_80035910;
    u_int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    int var_a3 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk28 & arg0->Param2)) {
                var_a1->unkDC = (arg0->Param3 & 0x7F) << 8;
                var_a1->unk8C = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 3;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk3C == arg0->Param1)) {
                var_a1->unkDC = (arg0->Param3 & 0x7F) << 8;
                var_a1->unk8C = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 3;
            }
        }
    }
}

void Sound_Cmd_A1_unk(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a2 = D_80035910;
    int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    int var_t0 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk28 & arg0->Param2)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->unkDE = (short)(((arg0->Param4 & 0x7F) << 8) - var_a2->unkDC) / v;
                var_a2->unk8C = v;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk3C == arg0->Param1)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->unkDE = (short)(((arg0->Param4 & 0x7F) << 8) - var_a2->unkDC) / v;
                var_a2->unk8C = v;
            }
        }
    }
}

void Sound_Cmd_A8_unk(FSoundCommandParams* arg0)
{
    int var_a3 = 0x1000;
    int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    u_int i;
    FSoundChannel* var_a1;

    for (i = 0, var_a1 = D_80035910; i < 12; ++i, ++var_a1, var_a3 *= 2) {
        if ((mask & var_a3) && !(var_a1->unk28 & 0x02000000)) {
            var_a1->unkDC = (arg0->Param1 & 0x7F) << 8;
            var_a1->unk8C = 0;
            var_a1->VoiceParams.VoiceParamFlags |= 3;
        }
    }
}

void Sound_Cmd_A9_unk(FSoundCommandParams* arg0)
{
    short var_a1;
    int var_t0 = 0x1000;
    int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    u_int i;
    FSoundChannel* var_a2;

    for (i = 0, var_a2 = D_80035910; i < 12; ++i, ++var_a2, var_t0 *= 2) {
        if ((mask & var_t0) && !(var_a2->unk28 & 0x02000000)) {
            var_a1 = 1;
            if (arg0->Param1 != 0) {
                var_a1 = arg0->Param1;
            }
            var_a2->unkDE =
                ((short)(((arg0->Param2 & 0x7F) << 8) - var_a2->unkDC) / var_a1);
            var_a2->unk8C = var_a1;
        }
    }
}

void Sound_Cmd_A2_unk(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a1 = D_80035910;
    u_int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    int var_a3 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk28 & arg0->Param2)) {
                var_a1->unk6C = ((char)arg0->Param3) << 8;
                var_a1->unk6E = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 3;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk3C == arg0->Param1)) {
                var_a1->unk6C = ((char)arg0->Param3) << 8;
                var_a1->unk6E = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 3;
            }
        }
    }
}

void Sound_Cmd_A3_unk(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a2 = D_80035910;
    int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    int var_t0 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk28 & arg0->Param2)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->unkDA = (short)((((char)arg0->Param4) << 8) - var_a2->unk6C) / v;
                var_a2->unk6E = v;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk3C == arg0->Param1)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->unkDA = (short)((((char)arg0->Param4) << 8) - var_a2->unk6C) / v;
                var_a2->unk6E = v;
            }
        }
    }
}

void Sound_Cmd_AA_unk(FSoundCommandParams* arg0)
{
    int var_a3 = 0x1000;
    int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    u_int i;
    FSoundChannel* var_a1;

    for (i = 0, var_a1 = D_80035910; i < 12; ++i, ++var_a1, var_a3 *= 2) {
        if ((mask & var_a3) && !(var_a1->unk28 & 0x02000000)) {
            var_a1->unk6C = ((char)arg0->Param1) << 8;
            var_a1->unk6E = 0;
            var_a1->VoiceParams.VoiceParamFlags |= 3;
        }
    }
}

void Sound_Cmd_AB_unk(FSoundCommandParams* arg0)
{
    short var_a1;
    int var_t0 = 0x1000;
    int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    u_int i;
    FSoundChannel* var_a2;

    for (i = 0, var_a2 = D_80035910; i < 12; ++i, ++var_a2, var_t0 *= 2) {
        if ((mask & var_t0) && !(var_a2->unk28 & 0x02000000)) {
            var_a1 = 1;
            if (arg0->Param1 != 0) {
                var_a1 = arg0->Param1;
            }
            var_a2->unkDA = (short)((((char)arg0->Param2) << 8) - var_a2->unk6C) / var_a1;
            var_a2->unk6E = var_a1;
        }
    }
}

void Sound_Cmd_A4_unk(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a1 = D_80035910;
    u_int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    int var_a3 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk28 & arg0->Param2)) {
                var_a1->unk40 = ((char)arg0->Param3) << 8;
                var_a1->unk86 = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 16;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk3C == arg0->Param1)) {
                var_a1->unk40 = ((char)arg0->Param3) << 8;
                var_a1->unk86 = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 16;
            }
        }
    }
}

void Sound_Cmd_A5_unk(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a2 = D_80035910;
    int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    int var_t0 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk28 & arg0->Param2)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->unk44 =
                    (short)((short)((((char)arg0->Param4) << 8) - var_a2->unk40) / v);
                var_a2->unk86 = v;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk3C == arg0->Param1)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->unk44 =
                    (short)((short)((((char)arg0->Param4) << 8) - var_a2->unk40) / v);
                var_a2->unk86 = v;
            }
        }
    }
}

void Sound_Cmd_AC_unk(FSoundCommandParams* arg0)
{
    int i;
    FSoundChannel* var_a1 = D_80035910;
    for (i = 12; i != 0; --i, ++var_a1) {
        if (!(var_a1->unk28 & 0x02000000)) {
            var_a1->unk40 = (char)arg0->Param1 << 8;
            var_a1->unk86 = 0;
            var_a1->VoiceParams.VoiceParamFlags |= 0x10;
        }
    }
}

void Sound_Cmd_AD_unk(FSoundCommandParams* arg0)
{
    short var_a1;
    int var_t0 = 0x1000;
    int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    u_int i;
    FSoundChannel* var_a2;

    for (i = 0, var_a2 = D_80035910; i < 12; ++i, ++var_a2, var_t0 *= 2) {
        if ((mask & var_t0) && !(var_a2->unk28 & 0x02000000)) {
            var_a1 = 1;
            if (arg0->Param1 != 0) {
                var_a1 = arg0->Param1;
            }
            var_a2->unk44 =
                (short)((short)((((char)arg0->Param2) << 8) - var_a2->unk40) / var_a1);
            var_a2->unk86 = var_a1;
        }
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001833C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018358);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800183C0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018434);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018450);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800184B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001852C);

void Sound_Cmd_11_StopAllMusic(FSoundCommandParams* in_Params)
{
    Sound_KillMusicConfig(g_pActiveMusicConfig, g_ActiveMusicChannels, in_Params->Param1);
    if (g_pSavedMousicConfig != NULL) {
        if (in_Params->Param1 != 0) {
            Sound_KillMusicConfig(
                g_pSavedMousicConfig, g_pSecondaryMusicChannels, in_Params->Param1);
        }
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018608);

void Sound_Cmd_80_unk(FSoundCommandParams* in_Params __attribute__((unused)))
{
    D_80039AFC = 1;
    Sound_MarkActiveChannelsVolumeDirty(g_pActiveMusicConfig, g_ActiveMusicChannels);
    if (g_pSavedMousicConfig != NULL) {
        Sound_MarkActiveChannelsVolumeDirty(
            g_pSavedMousicConfig, g_pSecondaryMusicChannels);
    }
    Sound_MarkScheduledSfxChannelsVolumeDirty();
}

void Sound_Cmd_81_unk(FSoundCommandParams* in_Params __attribute__((unused)))
{
    D_80039AFC = 2;
    Sound_MarkActiveChannelsVolumeDirty(g_pActiveMusicConfig, g_ActiveMusicChannels);
    if (g_pSavedMousicConfig != NULL) {
        Sound_MarkActiveChannelsVolumeDirty(
            g_pSavedMousicConfig, g_pSecondaryMusicChannels);
    }
    Sound_MarkScheduledSfxChannelsVolumeDirty();
}

void Sound_Cmd_90_unk(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* c;

    D_800378E4 = arg0->Param1;

    for (i = 0, c = g_ActiveMusicChannels; i < 32; ++i, ++c) {
        c->VoiceParams.VoiceParamFlags |= 3;
    }
}

void Sound_Cmd_92_unk(FSoundCommandParams* arg0)
{
    g_pActiveMusicConfig->JumpThresholdValue = arg0->Param1;
}

void Sound_Cmd_9B_unk(FSoundCommandParams* arg0 __attribute__((unused)))
{
    int temp_v1;
    int var_s0;
    int var_s1;
    int var_s2;

    if (g_pActiveMusicConfig->ActiveChannelMask != 0) {
        int v0 = ~(g_Sound_VoiceSchedulerState.ActiveChannelMask | D_80039B14);
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
        temp_v1 = g_pActiveMusicConfig->ActiveChannelMask;
        g_pActiveMusicConfig->ActiveChannelMask = 0;
        g_pActiveMusicConfig->unk1C = temp_v1;
    }
    D_80039B64 |= 1;
}

void Sound_Cmd_9A_unk(FSoundCommandParams* in_Params __attribute__((unused)))
{
    if (g_pActiveMusicConfig->unk1C != 0) {
        FSoundChannel* c = g_ActiveMusicChannels;
        int var_a2 = g_pActiveMusicConfig->unk1C;
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

        temp_v1 = g_pActiveMusicConfig->unk1C;
        g_pActiveMusicConfig->unk1C = 0;
        g_pActiveMusicConfig->ActiveChannelMask = temp_v1;
        g_Sound_GlobalFlags.UpdateFlags |= 0x100;
    }
    D_80039B64 &= ~1;
}

void Sound_Cmd_9D_unk(FSoundCommandParams* in_Params __attribute__((unused)))
{
    FSoundChannel* var_a0;
    int var_s0;
    int var_s2;
    int var_s1;
    u_int i;

    if (g_Sound_VoiceSchedulerState.ActiveChannelMask != 0) {
        var_s1 = g_Sound_VoiceSchedulerState.ActiveChannelMask;
        var_a0 = D_80035910;
        var_s0 = 0x1000;

        for (i = 0; i < 12; ++i, ++var_a0, var_s0 *= 2) {
            if ((var_s1 & var_s0) && (var_a0->unk28 & 0x02000000)) {
                var_s1 &= ~var_s0;
            }
        }

        var_s0 = 0x1000;
        var_s2 = 0xC;
        g_Sound_VoiceSchedulerState.unk_Flags_0x10 = var_s1;
        g_Sound_VoiceSchedulerState.ActiveChannelMask &= ~var_s1;

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

void Sound_Cmd_9C_unk(FSoundCommandParams* in_Params __attribute__((unused)))
{
    if (D_800378A0 != 0) {
        u_int temp_a2;
        FSoundChannel* c = D_80035910;
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

        temp_a2 = g_Sound_VoiceSchedulerState.unk_Flags_0x10;
        g_Sound_VoiceSchedulerState.unk_Flags_0x10 = 0;
        g_Sound_VoiceSchedulerState.ActiveChannelMask |= temp_a2;
        g_Sound_GlobalFlags.UpdateFlags |= 0x100;
    }
    D_80039B64 &= ~2;
}

void Sound_Cmd_9F_unk(FSoundCommandParams* in_Params __attribute__((unused)))
{
    if (g_Sound_Cutscene_StreamState.VoicesInUseFlags != 0) {
        SetVoiceSampleRate(g_Sound_Cutscene_StreamState.VoiceIndex, 0);
        SetVoiceSampleRate(g_Sound_Cutscene_StreamState.VoiceIndex + 1, 0);
    }
}

void Sound_Cmd_9E_unk(FSoundCommandParams* in_Params __attribute__((unused)))
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018C30);

void UpdateCdVolume(void)
{
    int v = D_800378E2;
    *CD_VOL_L = v;
    *CD_VOL_R = v;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", Sound_memcpy32);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", Sound_memswp32);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001924C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019614);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019704);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800199C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019A58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019FC4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A1F4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A22C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A258);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A4BC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A64C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A8D8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", Sound_CopyInstrumentInfoToChannel);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B094);

void Sound_ClearVoiceFromSchedulerState(FSoundChannel*, int);
INCLUDE_ASM(
    "build/src/SLUS_010.40/nonmatchings/25AC", Sound_ClearVoiceFromSchedulerState);

#define SOUND_DEFAULT_PORTAMENTO_STEPS (0x100) // 256 steps
#define SOUND_DEFAULT_DELAY_TIME (0x101) // 256 + 1

#define READ_16LE_PC(pc) ((pc[0]) | (pc[1] << 8))

void SoundVM_A0_FinishChannel(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicConfig->ActiveChannelMask &= ~in_VoiceFlags;
        if (g_pActiveMusicConfig->ActiveChannelMask == 0) {
            g_Music_LoopCounter = 0;
            g_pActiveMusicConfig->MusicId = 0;
            g_pActiveMusicConfig->StatusFlags = 0;
        }
        g_pActiveMusicConfig->ActiveNoteMask &= ~in_VoiceFlags;
        g_pActiveMusicConfig->KeyedMask &= ~in_VoiceFlags;
        g_pActiveMusicConfig->AllocatedVoiceMask &= ~in_VoiceFlags;
        g_pActiveMusicConfig->NoiseChannelFlags &= ~in_VoiceFlags;
        g_pActiveMusicConfig->ReverbChannelFlags &= ~in_VoiceFlags;
        g_pActiveMusicConfig->FmChannelFlags &= ~in_VoiceFlags;
    } else {
        Sound_ClearVoiceFromSchedulerState(in_pChannel, in_VoiceFlags);
    }
    in_pChannel->UpdateFlags = 0;
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_04 | SOUND_GLOBAL_UPDATE_08;
}

void SoundVM_FE1F_unk(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (g_pActiveMusicConfig->StatusFlags & 0x10000) {
        SoundVM_A0_FinishChannel(in_pChannel, in_VoiceFlags);
    }
}

void SoundVM_FE00_SetTempo(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    g_pActiveMusicConfig->Tempo = in_pChannel->ProgramCounter[0] << 0x10;
    g_pActiveMusicConfig->Tempo |= in_pChannel->ProgramCounter[1] << 0x18;
    in_pChannel->ProgramCounter += sizeof(short);
    g_pActiveMusicConfig->TempoSlideLength = 0;
}

void SoundVM_FE01_SetTempoSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    char* pc;
    int Dest;
    int Prev;
    int Delta;

    if ((g_pActiveMusicConfig->TempoSlideLength = *in_pChannel->ProgramCounter++) == 0) {
        g_pActiveMusicConfig->TempoSlideLength = 0x100;
    }
    pc = in_pChannel->ProgramCounter;
    Dest = pc[0] << 0x10;
    Dest |= pc[1] << 0x18;
    in_pChannel->ProgramCounter += 2;
    Prev = g_pActiveMusicConfig->Tempo & 0xFFFF0000;
    Delta = Dest - Prev;
    g_pActiveMusicConfig->TempoSlideStep = Delta / g_pActiveMusicConfig->TempoSlideLength;
    g_pActiveMusicConfig->Tempo = Prev;
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
    g_pActiveMusicConfig->ReverbDepthSlideLength = 0;
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_07;
    g_pActiveMusicConfig->RevDepth = Depth;
}

void SoundVM_FE03_SetMasterReverbSlide(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    int Prev;
    int Dest;
    int Delta;
    char* pc;

    g_pActiveMusicConfig->ReverbDepthSlideLength = *in_pChannel->ProgramCounter++;
    if (g_pActiveMusicConfig->ReverbDepthSlideLength == 0) {
        g_pActiveMusicConfig->ReverbDepthSlideLength = 0x100;
    }
    pc = in_pChannel->ProgramCounter;
    Dest = (signed char)pc[1] << 0x14;
    Dest |= (char)pc[0] << 0xC;
    in_pChannel->ProgramCounter += 2;
    Prev = g_pActiveMusicConfig->RevDepth & ~0xFFF;
    g_pActiveMusicConfig->RevDepth = Prev;
    Delta = Dest - Prev;
    g_pActiveMusicConfig->unk5C = Delta / g_pActiveMusicConfig->ReverbDepthSlideLength;
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

    if (g_pActiveMusicConfig->JumpThresholdValue >= Threshold) {
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

void SoundVM_FE19_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    u_short pPc1;
    int Dest;
    int Prev;
    int Delta;

    in_pChannel->unk5C = ((signed char)*in_pChannel->ProgramCounter++) << 0x17;
    pPc1 = *in_pChannel->ProgramCounter++;
    in_pChannel->KeyOnVolumeSlideLength = (short)pPc1;

    if (pPc1 == 0) {
        in_pChannel->KeyOnVolumeSlideLength = 0x100;
    }

    Dest = ((signed char)*in_pChannel->ProgramCounter++) << 0x17;
    Prev = in_pChannel->unk5C;
    Delta = Dest - Prev;
    in_pChannel->unk60 = Delta / in_pChannel->KeyOnVolumeSlideLength;
}

void SoundVM_FE1A_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->UpdateFlags |= SOUND_UPDATE_UNKNOWN_01;
}

void SoundVM_FE1B_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    in_pChannel->UpdateFlags &= ~SOUND_UPDATE_UNKNOWN_01;
}

void SoundVM_FE0C_unk(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    g_pActiveMusicConfig->unk34 = *in_pChannel->ProgramCounter++;
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
    in_pChannel->unkDC = *in_pChannel->ProgramCounter++ << 8;
    in_pChannel->unk8C = 0;
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

    if ((in_pChannel->unk8C = *in_pChannel->ProgramCounter++) == 0) {
        in_pChannel->unk8C = 0x100;
    }

    pc = *(in_pChannel->ProgramCounter++) << 8;
    v = in_pChannel->unkDC & 0xFF00;
    in_pChannel->unkDE = ((pc - v) / in_pChannel->unk8C);
    in_pChannel->unkDC = v;
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
                   ? func_8001A22C(g_pActiveMusicConfig->StatusFlags, pc)
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
    if (g_pActiveMusicConfig->SequencePatchTable != NULL) {
        pPatchTable = (u_short*)g_pActiveMusicConfig->SequencePatchTable;
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
    in_pChannel->SfxMask = 1;
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
    in_pChannel->unkA4 = 1;
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
    in_pChannel->unkB6 = 1;
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

void SoundVM_C4_EnableNoiseVoices(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicConfig->NoiseChannelFlags |= in_VoiceFlags;
    } else {
        g_Sound_VoiceSchedulerState.NoiseVoiceFlags |= in_VoiceFlags;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_04 | SOUND_GLOBAL_UPDATE_08;
}

void SoundVM_C5_DisableNoiseVoices(
    FSoundChannel* in_pChannel, u_int in_VoiceFlags __attribute__((unused)))
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicConfig->NoiseChannelFlags &= ~in_VoiceFlags;
    } else {
        g_Sound_VoiceSchedulerState.NoiseVoiceFlags &= ~in_VoiceFlags;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_04 | SOUND_GLOBAL_UPDATE_08;
    in_pChannel->NoiseTimer = 0;
}

void SoundVM_C6_EnableFmVoices(FSoundChannel* in_pChannel, u_int in_VoiceFlags)
{
    if (in_pChannel->Type == SOUND_CHANNEL_TYPE_MUSIC) {
        g_pActiveMusicConfig->FmChannelFlags |= in_VoiceFlags;
    } else if (in_pChannel->UpdateFlags & SOUND_UPDATE_UNKNOWN_16) {
        g_Sound_VoiceSchedulerState.FmVoiceFlags |= in_VoiceFlags;
    }
    g_Sound_GlobalFlags.UpdateFlags |= SOUND_GLOBAL_UPDATE_08;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C244);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C2AC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C30C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C36C);

void func_8001C378(void) { }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C380);

void func_8001C39C(void) { }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C3A4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C440);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C484);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C4B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C4E8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C52C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C56C);

void SoundVM_BB_SustainMode(FSoundChannel* in_pChannel, int arg)
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C628);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C66C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C68C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C69C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C6EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C780);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C7EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C868);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C8BC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C8E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C92C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C964);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C97C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C9B4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C9F0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CA2C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CA70);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CAA0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CAE4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CB14);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CB7C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CB90);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CBA4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CBB8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CBCC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CC84);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CC98);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CCC8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CCE8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CD08);

void func_8001CD24(short* arg0) { arg0[105] = 0; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CD2C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", IRQCallbackProc);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CDD0);

void func_8001CE60(void)
{
    u_char* temp_s0 = g_Sound_Cutscene_StreamState.pCurrentChunk + 0x800;
    SpuSetTransferStartAddr(0x2100);
    SpuSetTransferCallback(Sound_Cutscene_OnInitialTransferComplete);
    SpuWrite(temp_s0, 0x800);
}

int func_8001CDD0(void);
void func_8001D3D4(void);

void Sound_Cutscene_StartStream(u_int* arg0, int arg1, int arg2)
{
    int VoiceIndex;
    u_int transferSize;

    VoiceIndex = func_8001CDD0();
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
        _isSpuTransfer = 1;

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
            g_Sound_VoiceSchedulerState.ReverbVoiceFlags |=
                g_Sound_Cutscene_StreamState.VoicesInUseFlags;
        } else {
            g_Sound_VoiceSchedulerState.ReverbVoiceFlags &=
                ~g_Sound_Cutscene_StreamState.VoicesInUseFlags;
        }
        g_Sound_VoiceSchedulerState.FmVoiceFlags &=
            ~g_Sound_Cutscene_StreamState.VoicesInUseFlags;
        g_Sound_VoiceSchedulerState.NoiseVoiceFlags &=
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
        _isSpuTransfer = 0;
        if (g_Sound_Cutscene_StreamState.TotalPages >= 0x1001) {
            g_Sound_Cutscene_StreamState.TotalPages -= 0x1000;
            g_Sound_Cutscene_StreamState.pCurrentChunk += in_SomeIndex;
            SpuSetIRQCallback(in_Callback);
        } else {
            SpuSetIRQCallback(IRQCallbackProc);
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
        spuSetTransferCallback();
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
            SpuSetIRQCallback(IRQCallbackProc);
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
    IRQCallbackProc();
    Sound_Cutscene_StartStream((u_int*)arg0[0], arg0[1], arg0[2]);
    g_Sound_VoiceSchedulerState.ActiveChannelMask &=
        ~g_Sound_Cutscene_StreamState.VoicesInUseFlags;
}

void func_8001D698(void) { IRQCallbackProc(); }

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
