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
void func_80019154(FSoundChannel*, FSoundChannelConfig*, int);

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

        if ((in_pChannel->VibratoDelayCurrent == 0) && (in_pChannel->field72_0xb8 != 1)) {
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
            && ((u_short)in_pChannel->field81_0xca != 1)) {
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
        func_80019154(&D_800366F0, &g_PushedMusicConfig, 0x80);
        func_80019154(g_ActiveMusicChannels, (FSoundChannelConfig*)D_800378E8, 0x2200);
        for (i = 0, c = D_800378E8; i < 32; ++i, ++c) {
            Sound_MapInstrumentToBaseSampleBank(g_PushedMusicConfig.unk0, c);
        }
    }
}

void Sound_Cmd_19_Unk(FSoundCommandParams* arg0)
{
    if ((g_pActiveMusicConfig->ActiveChannelMask != 0)
        && ((g_pSavedMousicConfig == NULL) || (g_pSavedMousicConfig->MusicId == 0))) {
        g_pSavedMousicConfig = &g_PushedMusicConfig;
        g_pSecondaryMusicChannels = D_800378E8;
        func_80019154(&D_800366F0, &g_PushedMusicConfig, 0x80);
        func_80019154(g_ActiveMusicChannels,
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
            func_80019154(&D_800366F0, &g_PushedMusicConfig, 0x80);
            func_80019154(g_ActiveMusicChannels,
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017498);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001754C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001766C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017764);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017798);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017800);

void Sound_Cmd_A0_unk(FSoundCommandParams* arg0)
{
    u_int i;
    FSoundChannel* var_a1 = D_80035910;
    u_int mask = g_Sound_VoiceSchedulerState.ActiveChannelMask;
    int var_a3 = 0x1000;

    if (arg0->Param2 != 0) {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk28 & arg0->Param2)) {
                var_a1->unkD6 = (arg0->Param3 & 0x7F) << 8;
                var_a1->unk86 = 0;
                var_a1->VoiceParams.VoiceParamFlags |= 3;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a1, var_a3 *= 2) {
            if ((mask & var_a3) && (var_a1->unk3C == arg0->Param1)) {
                var_a1->unkD6 = (arg0->Param3 & 0x7F) << 8;
                var_a1->unk86 = 0;
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
                var_a2->unkD8 = (short)(((arg0->Param4 & 0x7F) << 8) - var_a2->unkD6) / v;
                var_a2->unk86 = v;
            }
        }
    } else {
        for (i = 0; i < 12; ++i, ++var_a2, var_t0 *= 2) {
            if ((mask & var_t0) && (var_a2->unk3C == arg0->Param1)) {
                short v = arg0->Param3 != 0 ? arg0->Param3 : 1;
                var_a2->unkD8 = (short)(((arg0->Param4 & 0x7F) << 8) - var_a2->unkD6) / v;
                var_a2->unk86 = v;
            }
        }
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017AD8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017B54);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017C1C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017CFC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017E74);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017EEC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017FB0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018090);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018218);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018270);

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
    g_pActiveMusicConfig->unk70 = arg0->Param1;
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019134);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019154);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800191D4);

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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B060);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B094);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B0CC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B138);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B20C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B248);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B294);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B334);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B37C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B424);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B450);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B4A8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B4E0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B4EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B514);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B598);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B5C8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B654);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B6E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B6F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B70C);

static void func_8001B72C(void) { }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B734);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B778);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B804);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B838);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B8C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B8E0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B8F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B910);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B9B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BA24);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BAB8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB00);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB24);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB50);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB98);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BBD0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BBD8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BC38);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BC9C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BD94);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BDF4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BE60);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BE84);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BF34);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BF58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BFC8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BFEC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C058);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C078);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C0E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C108);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C168);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C1D0);

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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C5B0);

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
