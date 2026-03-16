// From
// https://github.com/jdperos/chrono-cross-decomp/blob/ecef6eeac85fe573c08644041d7098beed1a9bf5/include/system/sound.h

#include "common.h"
#include <libspu.h>

#define VOICE_COUNT 24
#define VOICE_MASK_ALL (0x3FF)

#define SOUND_CHANNEL_COUNT 0x20
#define SOUND_LFO_COUNT (0x10)

// Voice parameter update flags
#define VOICE_PARAM_VOLUME_L (1 << 0) /* volume (left) */
#define VOICE_PARAM_VOLUME_R (1 << 1) /* volume (right) */
#define VOICE_PARAM_VOLUME (VOICE_PARAM_VOLUME_L | VOICE_PARAM_VOLUME_R)
#define VOICE_PARAM_VOLMODE_L (1 << 2) /* volume mode (left) */
#define VOICE_PARAM_VOLMODE_R (1 << 3) /* volume mode (right) */
#define VOICE_PARAM_SAMPLE_RATE (1 << 4) /* tone (pitch setting)  */
#define VOICE_PARAM_NOTE (1 << 5) /* tone (note setting)  */
#define VOICE_PARAM_SAMPLE_NOTE (1 << 6) /* waveform data sample note */
#define VOICE_PARAM_START_ADDR (1 << 7) /* waveform data start address */
#define VOICE_PARAM_ADSR_AMODE (1 << 8) /* ADSR Attack rate mode */
#define VOICE_PARAM_ADSR_SMODE (1 << 9) /* ADSR Sustain rate mode */
#define VOICE_PARAM_ADSR_RMODE (1 << 10) /* ADSR Release rate mode */
#define VOICE_PARAM_ADSR_AR (1 << 11) /* ADSR Attack rate */
#define VOICE_PARAM_ADSR_DR (1 << 12) /* ADSR Decay rate */
#define VOICE_PARAM_ADSR_SR (1 << 13) /* ADSR Sustain rate */
#define VOICE_PARAM_ADSR_RR (1 << 14) /* ADSR Release rate */
#define VOICE_PARAM_ADSR_SL (1 << 15) /* ADSR Sustain level */
#define VOICE_PARAM_ADSR_LOWER                                                           \
    (VOICE_PARAM_ADSR_AMODE | VOICE_PARAM_ADSR_AR | VOICE_PARAM_ADSR_DR                  \
        | VOICE_PARAM_ADSR_SL)
#define VOICE_PARAM_ADSR_UPPER                                                           \
    (VOICE_PARAM_ADSR_SMODE | VOICE_PARAM_ADSR_RMODE | VOICE_PARAM_ADSR_SR               \
        | VOICE_PARAM_ADSR_RR)
#define VOICE_PARAM_ADSR_FULL (VOICE_PARAM_ADSR_LOWER | VOICE_PARAM_ADSR_UPPER)
#define VOICE_PARAM_LOOP_ADDR (1 << 16) /* start address for loop */
#define VOICE_PARAM_ADSR_ADSR1 (1 << 17) /* ADSR adsr1 for `VagAtr'  */
#define VOICE_PARAM_ADSR_ADSR2 (1 << 18) /* ADSR adsr2 for `VagAtr'  */

#define SOUND_CHANNEL_TYPE_MUSIC 0x0
#define SOUND_CHANNEL_TYPE_SOUND 0x1
#define SOUND_CHANNEL_TYPE_MENU 0x2

#define SOUND_CHANNEL_CONFIG_STEREO (1 << 0)
#define SOUND_CHANNEL_CONFIG_MONO (1 << 1)
#define SOUND_CHANNEL_CONFIG_STEREO_CHANNELS (1 << 2)

#define SOUND_SFX_LEGATO 0x1
#define SOUND_SFX_FULL_LENGTH 0x4

#define SOUND_UPDATE_SPU_VOICE (SPU_VOICE_VOLL | SPU_VOICE_VOLR)
#define SOUND_UPDATE_SPU_ADSR                                                            \
    (SPU_VOICE_ADSR_AMODE | SPU_VOICE_ADSR_SMODE | SPU_VOICE_ADSR_RMODE                  \
        | SPU_VOICE_ADSR_AR | SPU_VOICE_ADSR_DR | SPU_VOICE_ADSR_SR | SPU_VOICE_ADSR_RR  \
        | SPU_VOICE_ADSR_SL)
#define SOUND_UPDATE_SPU_BASE_WOR                                                        \
    (SPU_VOICE_WDSA | SPU_VOICE_ADSR_AMODE | SPU_VOICE_ADSR_SMODE | SPU_VOICE_ADSR_AR    \
        | SPU_VOICE_ADSR_DR | SPU_VOICE_ADSR_SR | SPU_VOICE_ADSR_SL | SPU_VOICE_LSAX)
#define SOUND_UPDATE_SPU_BASE                                                            \
    (SOUND_UPDATE_SPU_BASE_WOR | SPU_VOICE_ADSR_RMODE | SPU_VOICE_ADSR_RR)
#define SOUND_UPDATE_SPU_ALL                                                             \
    (SOUND_UPDATE_SPU_BASE | SOUND_UPDATE_SPU_VOICE | SPU_VOICE_PITCH)

#define SOUND_UPDATE_VIBRATO (1 << 0)
#define SOUND_UPDATE_TREMOLO (1 << 1)
#define SOUND_UPDATE_PAN_LFO (1 << 2)
#define SOUND_UPDATE_DRUM_MODE (1 << 3)
#define SOUND_UPDATE_SIDE_CHAIN_PITCH (1 << 4)
#define SOUND_UPDATE_SIDE_CHAIN_VOL (1 << 5)
#define SOUND_UPDATE_UNKNOWN_01 (1 << 6)
#define SOUND_UPDATE_OVERLAY (1 << 8)
#define SOUND_UPDATE_ALTERNATIVE (1 << 9)
#define SOUND_UPDATE_UNKNOWN_12 (1 << 12)
#define SOUND_UPDATE_UNKNOWN_16 (1 << 16)
#define SOUND_UPDATE_UNKNOWN_17 (1 << 17)
#define SOUND_UPDATE_UNKNOWN_20 (1 << 20)
#define SOUND_UPDATE_UNKNOWN_24 (1 << 24)
#define SOUND_UPDATE_UNKNOWN_27 (1 << 27)
#define SOUND_UPDATE_UNKNOWN_28 (1 << 28)

#define SOUND_GLOBAL_UPDATE_00 (1 << 0)
#define SOUND_GLOBAL_UPDATE_01 (1 << 1)
#define SOUND_GLOBAL_UPDATE_02 (1 << 2)
#define SOUND_GLOBAL_UPDATE_03 (1 << 3)
#define SOUND_GLOBAL_UPDATE_04 (1 << 4)
#define SOUND_GLOBAL_UPDATE_05 (1 << 5)
#define SOUND_GLOBAL_UPDATE_06 (1 << 6)
#define SOUND_GLOBAL_UPDATE_07 (1 << 7)
#define SOUND_GLOBAL_UPDATE_08 (1 << 8)
#define SOUND_GLOBAL_UPDATE_09 (1 << 9)
#define SOUND_GLOBAL_UPDATE_10 (1 << 10)
#define SOUND_GLOBAL_UPDATE_11 (1 << 11)
#define SOUND_GLOBAL_UPDATE_12 (1 << 12)
#define SOUND_GLOBAL_UPDATE_13 (1 << 13)
#define SOUND_GLOBAL_UPDATE_14 (1 << 14)
#define SOUND_GLOBAL_UPDATE_15 (1 << 15)
#define SOUND_GLOBAL_UPDATE_16 (1 << 16)
#define SOUND_GLOBAL_UPDATE_17 (1 << 17)
#define SOUND_GLOBAL_UPDATE_18 (1 << 18)
#define SOUND_GLOBAL_UPDATE_19 (1 << 19)
#define SOUND_GLOBAL_UPDATE_20 (1 << 20)
#define SOUND_GLOBAL_UPDATE_21 (1 << 21)
#define SOUND_GLOBAL_UPDATE_22 (1 << 22)
#define SOUND_GLOBAL_UPDATE_23 (1 << 23)
#define SOUND_GLOBAL_UPDATE_24 (1 << 24)
#define SOUND_GLOBAL_UPDATE_25 (1 << 25)
#define SOUND_GLOBAL_UPDATE_26 (1 << 26)
#define SOUND_GLOBAL_UPDATE_27 (1 << 27)
#define SOUND_GLOBAL_UPDATE_28 (1 << 28)
#define SOUND_GLOBAL_UPDATE_29 (1 << 29)
#define SOUND_GLOBAL_UPDATE_30 (1 << 30)
#define SOUND_GLOBAL_UPDATE_31 (1 << 31)
#define SOUND_GLOBAL_UPDATE_32 (1 << 32)
#define SOUND_GLOBAL_UPDATE_VOICES_CHANGED (0x110)

#define BIT_MASK(width) ((1u << (width)) - 1u)
#define FIELD_MASK(width, shift) (BIT_MASK(width) << (shift))

/*
 * ADSR1 (Lower)
 * 15 14 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0
 *  ---------------------+---------+--------
 *   Attack Rate / Mode  | Decay   | Sustain Level
 */
#define SOUND_ADSR_ATTACK_MODE_MASK                                                      \
    (BIT_MASK(SOUND_ADSR_ATTACK_MODE_WIDTH)                                              \
        << SOUND_ADSR_ATTACK_MODE_SHIFT) // 0x8000  // bit 15
#define SOUND_ADSR_ATTACK_RATE_MASK                                                      \
    (BIT_MASK(SOUND_ADSR_ATTACK_RATE_WIDTH)                                              \
        << SOUND_ADSR_ATTACK_RATE_SHIFT) // 0x7F00  // bits 14–8
#define SOUND_ADSR_DECAY_RATE_MASK                                                       \
    (BIT_MASK(SOUND_ADSR_DECAY_RATE_WIDTH)                                               \
        << SOUND_ADSR_DECAY_RATE_SHIFT) // 0x00F0  // bits 7–4
#define SOUND_ADSR_SUS_LEVEL_MASK                                                        \
    (BIT_MASK(SOUND_ADSR_SUS_LEVEL_WIDTH)                                                \
        << SOUND_ADSR_SUS_LEVEL_SHIFT) // 0x000F  // bits 3–0

#define SOUND_ADSR_ATTACK_MODE_SHIFT 15
#define SOUND_ADSR_ATTACK_RATE_SHIFT 8
#define SOUND_ADSR_DECAY_RATE_SHIFT 4
#define SOUND_ADSR_SUS_LEVEL_SHIFT 0

#define SOUND_ADSR_ATTACK_MODE_WIDTH 1
#define SOUND_ADSR_ATTACK_RATE_WIDTH 7
#define SOUND_ADSR_DECAY_RATE_WIDTH 4
#define SOUND_ADSR_SUS_LEVEL_WIDTH 4

/*
 * ADSR2 (Upper)
 TODO(jperos) THESE GRAPHS ARE WRONG
 * 15 14 | 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0
 * ------+-----------------+---------+---------
 * SMode | Sustain Rate    | Rel.    | RR
 */
#define SOUND_ADSR_SUS_MODE_MASK                                                         \
    (BIT_MASK(SOUND_ADSR_SUS_MODE_WIDTH) << SOUND_ADSR_SUS_MODE_SHIFT) //   0xC000
#define SOUND_ADSR_SUS_RATE_MASK                                                         \
    (BIT_MASK(SOUND_ADSR_SUS_RATE_WIDTH) << SOUND_ADSR_SUS_RATE_SHIFT) //   0x3F00
#define SOUND_ADSR_RELEASE_MODE_MASK                                                     \
    (BIT_MASK(SOUND_ADSR_RELEASE_MODE_WIDTH) << SOUND_ADSR_RELEASE_MODE_SHIFT) //   0x00E0
#define SOUND_ADSR_RELEASE_RATE_MASK                                                     \
    (BIT_MASK(SOUND_ADSR_RELEASE_RATE_WIDTH) << SOUND_ADSR_RELEASE_RATE_SHIFT) //   0x00E0

#define SOUND_ADSR_SUS_MODE_SHIFT 14
#define SOUND_ADSR_SUS_RATE_SHIFT 6
#define SOUND_ADSR_RELEASE_MODE_SHIFT 5
#define SOUND_ADSR_RELEASE_RATE_SHIFT 0

#define SOUND_ADSR_SUS_MODE_WIDTH 2
#define SOUND_ADSR_SUS_RATE_WIDTH 7
#define SOUND_ADSR_RELEASE_MODE_WIDTH 1
#define SOUND_ADSR_RELEASE_RATE_WIDTH 5

#define SOUND_AMODE_1 1
#define SOUND_AMODE_5 5
#define SOUND_RMODE_7 7

#define VIBRATO_FLAG_ABSOLUTE (1 << 15)

#define SOUND_UPDATE_NOISE_CLOCK 0x10
#define SOUND_UPDATE_REVERB 0x80

#define AKAO_FILE_MAGIC                                                                  \
    (0x4F414B41U) // AKAO in ASCII
                  //
typedef struct FAkaoFileBlob {
    /* 0x000 */ int Magic; // AKAO
    /* 0x004 */ char unk_0x4[0xC]; // Padding? Version? Counts? Music Akao blobs have a
                                   // different flag in here...
    /* 0x010 */ u_short ProgramOffsets[0x100]
                                      [2]; // Offsets into bytecode - indexed by Sfx ID
    /* 0x410 */ u_short MetadataTableA[0x100]; // Some per sfx table
    /* 0x610 */ u_short MetadataTableB[0x100]; // Some per sfx table
    /* 0x810 */ char ProgramData[1]; // Sfx bytecode
} FAkaoFileBlob;

typedef struct {
    u_int ControlLatches; // one-shot / transactional engine state flags
    u_int MixBehavior; // global mixing & music-stack behavior flags
    u_int UpdateFlags; // deferred SPU / voice-mode update flags
} FSoundGlobalFlags;

/* =========================
 * ControlLatches
 * ========================= */

/* SPU instrument upload / relocation transaction in progress.
 * - Set before streaming instrument data
 * - Cleared when transfer finishes
 * - Gates unk_Spu_8004ac2c()
 */
#define SOUND_CTL_INSTRUMENT_TRANSFER_ACTIVE (1u << 0)

/* Last-active SFX channel fade completion should trigger VM command.
 * - Set when a global SFX fade starts
 * - Checked when C_StepsRemaining reaches 0 on final channel
 * - Causes Sound_Cmd_80050dd4()
 */
#define SOUND_CTL_SFX_FADE_END_CALLBACK_PENDING (1u << 16)

/* =========================
 * MixBehavior
 * ========================= */

/* Force dual-mono output.
 * - Bypasses pan law table
 * - L = R using 0x440a scale
 * - Affects:
 *     - Music voices
 *     - SFX voices
 *     - CD audio mixing
 */
#define SOUND_MIX_FORCE_MONO (1u << 1)

/* Secondary (pushed) music is in fade / teardown phase.
 * - Enables periodic fade processing
 * - Delays cleanup until fade completes
 * - Cleared automatically when channels die
 */
#define SOUND_MIX_SECONDARY_MUSIC_FADING (1u << 8)

/* Legacy / initialization bit.
 * - Written (set to 1) but not meaningfully read in observed paths
 * - Likely historical or reserved
 */
#define SOUND_MIX_LEGACY_ENABLE (1u << 0)

typedef struct {
    /* 0x00 */ u_int StartAddr;
    /* 0x04 */ u_int LoopAddr;
    /* 0x08 */ short FineTune;
    /* 0x0A */ short SampleNote;
    /* 0x0C */ u_short AdsrLower;
    /* 0x0E */ u_short AdsrUpper;
} FSoundInstrumentInfo; /* size 0x10 */

typedef struct {
    u_int ActiveChannelMask;
    u_int KeyOnFlags;
    u_int KeyedFlags;
    u_int KeyOffFlags;
    u_int unk_Flags_0x10;
    u_int field5_0x14;
    u_int TempoAccumumulator;
    u_int NoiseVoiceFlags;
    u_int ReverbVoiceFlags;
    u_int FmVoiceFlags;
    u_short NoiseClock;
    char field11_0x2a;
    char field12_0x2b;
    u_int field13_0x2c;
} FSoundVoiceSchedulerState;

typedef struct {
    /* 0x00 */ int field0_0x0;
    /* 0x04 */ int unk_Mask_0x4;
    /* 0x08 */ int field2_0x8;
    /* 0x0C */ int VoicesInUseFlags;
    /* 0x10 */ int VoiceIndex;
    /* 0x14 */ u_int ChannelFlags;
    /* 0x18 */ int field6_0x18;
    /* 0x1C */ int field7_0x1c;
    /* 0x20 */ int field8_0x20;
    /* 0x24 */ int field9_0x24;
    /* 0x28 */ int field10_0x28;
    /* 0x2C */ int field11_0x2c;
    /* 0x30 */ int field12_0x30;
    /* 0x34 */ int field13_0x34;
    /* 0x38 */ int field14_0x38;
    /* 0x3C */ int field15_0x3c;
    /* 0x40 */ int Volume;
    /* 0x44 */ int field17_0x44;
    /* 0x48 */ int field18_0x48;
    /* 0x4C */ char field19_0x4c;
    /* 0x4D */ char field20_0x4d;
    /* 0x4E */ char field21_0x4e;
    /* 0x4F */ char field22_0x4f;
    /* 0x50 */ int field23_0x50;
    /* 0x54 */ int field24_0x54;
    /* 0x58 */ int VoiceSampleRate;
    /* 0x5C */ int ControlFlags;
} FSound80094FA0; /* size 0x60 */

typedef struct {
    /* 0x00 */ u_int AssignedVoiceNumber;
    /* 0x04 */ u_int VoiceParamFlags;
    /* 0x08 */ u_int StartAddress;
    /* 0x0C */ u_int LoopAddress;
    /* 0x10 */ u_short SampleRate;
    /* 0x12 */ u_short AdsrLower;
    /* 0x14 */ u_short AdsrUpper;
    /* 0x16 */ u_short VolumeScale;
    /* 0x18 */ SpuVolume Volume;
} FSoundVoiceParams; /* size 0x1C */

#define SOUND_LOOP_STACK_SIZE (4)
#define SOUND_LOOP_STACK_MAX_INDEX (SOUND_LOOP_STACK_SIZE - 1)

typedef struct {
    char* ProgramCounter;
    char* unk4[(4)];
    char* ReturnProgramCounter;
    char* Keymap;
    short* VibratoWave;
    short* TremeloWave;
    short* AutoPanWave;
    int unk28;
    int PitchBase;
    int PitchSlide;
    u_int UpdateFlags;
    int unk38;
    u_int unk3C;
    int unk40;
    u_int unk44;
    int Volume;
    int VolumeSlideStep;
    int PitchSlideStep;
    int FinePitchDelta;
    u_int unk58;
    int unk5C;
    int unk60;
    u_short Type;
    short Length1;
    short Length2;
    u_short InstrumentIndex;
    u_short unk6C;
    short unk6E;
    u_short unk70;
    u_short unk72[(4)];
    short unk7A[(4)];
    u_short VolumeBalance;
    u_short VolumeBalanceSlideLength;
    short unk86;
    u_short ChannelVolumeSlideLength;
    u_short KeyOnVolumeSlideLength;
    u_short unk8C;
    u_short ChannelPan;
    u_short ChannelPanSlideLength;
    u_short PitchSlideStepsCurrent;
    u_short Octave;
    short PitchBendSlideLength;
    u_short KeyStored;
    short PortamentoSteps;
    u_short SfxMask;
    short VibratoDelay;
    u_short VibratoDelayCurrent;
    u_short VibratoRatePhase;
    u_short unkA4;
    u_short VibratoType;
    u_short VibratoBase;
    u_short VibratoDepth;
    u_short VibratoDepthSlideLength;
    u_short VibratoDepthSlideStep;
    short TremeloDelay;
    u_short TremeloDelayCurrent;
    u_short TremeloRatePhase;
    short unkB6;
    u_short TremeloType;
    u_short TremeloDepth;
    u_short TremeloDepthSlideLength;
    short TremeloDepthSlideStep;
    u_short AutoPanRatePhase;
    u_short AutoPanRateCurrent;
    u_short AutoPanType;
    u_short AutoPanDepth;
    u_short AutoPanDepthSlideLength;
    short AutoPanDepthSlideStep;
    u_short NoiseTimer;
    u_short FmTimer;
    u_short unkD0;
    u_short unkD2;
    short unkD4;
    u_short unkD6;
    short VolumeBalanceSlideStep;
    short unkDA;
    short unkDC;
    short unkDE;
    short PanSlideStep;
    short Transpose;
    short FineTune;
    short Key;
    short PitchBendSlideTranspose;
    short TransposeStored;
    short VibratoPitch;
    short TremeloVolume;
    short AutoPanVolume;
    FSoundVoiceParams VoiceParams;
} FSoundChannel;

typedef struct {
    char InstrumentIndex;
    char Note;
    char AdsrAttackRate;
    char AdsrSustainRate;
    char SustainModeCode; /* values 3/5/7 map to 0x4000/0x8000/0xC000 */
    char ReleaseRate;
    char VolumeScale;
    char PanAndReverb; /* low 7 bits pan, high bit reverb-enable */
} FSoundKeymapEntry8;

typedef struct {
    /* 0x00 */ u_int unk00;
    /* 0x04 */ u_int unk04;
    /* 0x08 */ u_int unk08;
    /* 0x0C */ u_int unk0C;

    /* 0x10 */ u_int unk10;
    /* 0x14 */ u_int unk14;
    /* 0x18 */ u_int unk18;
    /* 0x1C */ u_int unk1C;

    /* 0x20 */ u_int ChannelEnableMask;
    /* 0x24 */ u_int KeyedMask;
    /* 0x28 */ u_int AllocatedVoiceMask;
    /* 0x2C */ u_int unk2C;

    /* 0x30 */ int PatchRegionOffset; // field-relative
    /* 0x34 */ int KeymapRegionOffset; // field-relative
    /* 0x38 */ u_int unk38;
    /* 0x3C */ u_int unk3C;
    /* 0x40 */ char Payload[1]; // starts at 0x40 (variable length)
} FAkaoSequence; // size 0x40 (header), data blob variable

typedef struct {
    int StatusFlags;
    int ActiveChannelMask;
    u_int KeyedMask;
    int AllocatedVoiceMask;
    int PendingKeyOnMask;
    u_int ActiveNoteMask;
    int PendingKeyOffMask;
    u_int unk1C;
    int Tempo;
    int TempoSlideStep;
    u_int unk28;
    u_int unk2C;
    int unk30;
    int unk34;
    int unk38;
    FAkaoSequence* SequencePatchTable;
    u_short* unk40;
    FSoundKeymapEntry8* unk44;
    int SomeIndexRelatedToSpuVoiceInfo;
    u_int NoiseChannelFlags;
    u_int ReverbChannelFlags;
    u_int FmChannelFlags;
    int RevDepth;
    int unk5C;
    u_int A_Volume;
    int unk64;
    short unk68;
    short ReverbDepthSlideLength;
    u_short TempoSlideLength;
    u_short MusicId;
    u_short JumpThresholdValue;
    u_short unk72;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
} FSoundChannelConfig;

typedef struct {
    u_int Param1;
    u_int Param2;
    u_int Param3; // Seems to be usually flags
    u_int Param4;
    u_int ExtParam1;
    u_int ExtParam2;
} FSoundCommandParams;

typedef struct {
    /* 0x0 */ int unk0; // Seems unused
    /* 0x4 */ short pEnvx;
    /* 0x6 */ short unk6;
} FSpuVoiceInfo; /* size 0x8 */

typedef struct {
    /* 0x00 */ int Value;
    /* 0x04 */ int Step;
    /* 0x08 */ int TicksRemaining;
    /* 0x0C */ int SavedValue;
} FSoundFadeTimer; /* size 0x10 */

typedef struct {
    int Reverb;
    int Noise;
    int Fm;
} FSoundVoiceModeFlags;

#define SEMITONES_IN_OCTAVE (12)

// Semitone pitch multipliers (fixed-point, 0x1000 = 1.0)
// extern const int g_SemitonePitchTable[SEMITONES_IN_OCTAVE];
// Only referenced in SoundVM functions - maybe move there if we process the sound VM in
// that source file
/* {
    0x00001000,  // C  - base pitch (1.0)
    0x000010F3,  // C# - 2^(1/12)
    0x000011F5,  // D  - 2^(2/12)
    0x00001306,  // D# - 2^(3/12)
    0x00001428,  // E  - 2^(4/12)
    0x0000155B,  // F  - 2^(5/12)
    0x000016A0,  // F# - 2^(6/12)
    0x000017F9,  // G  - 2^(7/12)
    0x00001966,  // G# - 2^(8/12)
    0x00001AE8,  // A  - 2^(9/12)
    0x00001C82,  // A# - 2^(10/12)
    0x00001E34   // B  - 2^(11/12)
}; */

// Sound API - IDK I'm just picking names right now....

#define SPU_MALLOC_NUM_BLOCKS 4
char g_SpuMallocRecTable[SPU_MALLOC_RECSIZ * (SPU_MALLOC_NUM_BLOCKS + 1)];

typedef struct FAkaoHeader {
    /* 0x00 */ u_int Magic;
    /* 0x04 */ int unk_0x04; // -> StreamState.field8_0x20
    /* 0x08 */ char unk_0x08[0x8];
    /* 0x10 */ u_int TotalPages;
    /* 0x14 */ char unk_0x14[0x4];
    /* 0x18 */ int unk_0x18; // -> StreamState.field2_0x8
    /* 0x1C */ u_short SampleRate;
    /* 0x1E */ char unk_0x1E[0x2];
    /* 0x20 */ u_int CurrentPage;
    /* 0x24 */ char unk_0x24[0x4];
    /* 0x28 */ int unk_0x28; // outgoing voice reference for volume handoff
} FAkaoHeader; /* size 0x2C */

typedef struct FSoundCutsceneStreamData {
    /* 0x00 */ char unk_0x00[0x80]; // Probably some pointers to Chunks
    /* 0x80 */ FAkaoHeader AkaoHeader;
    /* 0xAC */ char unk_0xAC[0x24];
    /* 0xD0 */ char AudioData[1];
} FSoundCutsceneStreamData; /** size 0x80 + DataBlob */

typedef struct FSoundCutsceneStreamState {
    /* 0x00 */ void* pCurrentChunk;
    /* 0x04 */ void* unk_Mask_0x4;
    /* 0x08 */ int field2_0x8;
    /* 0x0C */ int VoicesInUseFlags;
    /* 0x10 */ int VoiceIndex;
    /* 0x14 */ u_int TotalPages; // Probably a bad name judged on the usage in
                                 // Sound_Cutscene_BeginPlayback
    /* 0x18 */ int CurrentPage;
    /* 0x1C */ int field7_0x1c;
    /* 0x20 */ int field8_0x20;
    /* 0x24 */ int field9_0x24;
    /* 0x28 */ int PageIndex;
    /* 0x2C */ FSoundCutsceneStreamData* pStreamBase;
    /* 0x30 */ int field12_0x30;
    /* 0x34 */ u_int StreamPageIndex;
    /* 0x38 */ int field14_0x38;
    /* 0x3C */ u_int PageRingBufferSize;
    /* 0x40 */ int Volume;
    /* 0x44 */ int VolFadeStepSize;
    /* 0x48 */ int VolFadeStepsRemaining;
    /* 0x4C */ union {
        int s32;
        u_char u8[4];
    } field19_0x4c;
    /* 0x50 */ int field23_0x50;
    /* 0x54 */ int field24_0x54;
    /* 0x58 */ int VoiceSampleRate;
    /* 0x5C */ int ControlFlags;
} FSoundCutsceneStreamState; /* size 0x60 */
