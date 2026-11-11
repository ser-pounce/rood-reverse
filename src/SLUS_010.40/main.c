#define VS_MAIN_INCLUDE
#include "mainPrivate.h"
#include "gameFlags.h"
#include "gameState.h"
#include "graphics.h"
#include "pad.h"
#include "sound.h"
#include "zoneState.h"
#undef VS_MAIN_INCLUDE
#include "common.h"
#include "25ACPrivate.h"
#include "actions.h"
#include "cd.h"
#include "clut.h"
#include "inventory.h"
#include "memory.h"
#include "modifiers.h"
#include "overlayPrivate.h"
#include "zones.h"
#include "src/BATTLE/BATTLE.PRG/actor.h"
#include "src/BATTLE/BATTLE.PRG/camera.h"
#include "src/BATTLE/BATTLE.PRG/entity.h"
#include "src/BATTLE/BATTLE.PRG/mainInterface.h"
#include "src/BATTLE/BATTLE.PRG/mpd.h"
#include "src/TITLE/TITLE.PRG/22C.h"
#include "src/ENDING/ENDING.PRG/D4.h"
#include "build/src/include/lbas.h"
#include <libds.h>
#include <libapi.h>
#include <libetc.h>
#include <libpad.h>
#include <libsnd.h>
#include <libspu.h>
#include <libgpu.h>
#include <limits.h>
#include <rand.h>

// SECTOR_SIZE (libds) is in 32-bit words
#define SECTOR_BYTES (SECTOR_SIZE * 4)

enum diskState_e {
    diskIdle = 0,
    diskSeekReady = 1,
    diskReadReady = 2,
    // Never assigned; only checked by vs_main_diskLoadFile's wait loop
    diskUnused3 = 3,
    diskReadError = 4,
    diskReadInit = 5,
    diskReadXaInit = 6,
    diskStreamXa = 7,
    diskCommandFailed = 8,
    diskStreamXaEnd = 9,
};

enum cdBufferModes_e {
    cdBufferModeNone = 0,
    cdBufferModeBuffered = 1,
    cdBufferModeManual = 2,
};

typedef struct {
    u_char state;
    UNUSED u_char mode;
    UNUSED u_char _0;
    u_char errorCount;
    u_int sectorsFetched;
    u_int sectorsRequested;
    int cdSector;
    union {
        u_int byteCount; // data reads
        int cdVolume; // XA streams: target CD volume
    } request;
    void* vram;
    DslFILTER pcm;
    union {
        DslLOC loc; // seek/read position
        u_char mode; // DslSetmode parameter (aliases loc.minute)
    } cd;
    int commandId;
    UNUSED int _1;
    UNUSED int _2;
    enum cdBufferModes_e bufferMode;
    u_int sectorBufIndex;
    int sectorsPending;
    u_int sectorsReceived;
    u_int ringWriteIndex;
    u_int ringBufIndex;
    int framesSinceLastRead;
} Disk;

typedef struct {
    int active;
    int value;
    int step;
    int target;
    int scriptPos;
    int framesLeft;
} PadMotor;

typedef struct {
    u_short active;
    u_short id;
    char const* script;
    PadMotor motors[2];
} PadVibration;

// A colour with 16.16 fixed point channels
typedef struct {
    int r;
    int g;
    int b;
} FixedColor;

// A fixed point colour and the step added to it every update while it fades
typedef struct {
    FixedColor current;
    FixedColor step;
} Fade;

typedef struct {
    char active;
    char frame;
    char tick;
    char speed;
    char mode;
    short pulseTarget[3];
    short grayAmount;
    short grayStep;
    Fade fade;
    CVECTOR baseColor;
} ColorSlot;

typedef struct {
    UNUSED char _;
    char locked;
    struct ClutAnimState {
        u_char active;
        u_char frame;
        u_char tick;
        u_char speed;
        u_char transitionMode;
        signed char transitionTargetR;
        signed char transitionTargetG;
        signed char transitionTargetB;
    } animState;
    struct ColorInfo {
        char r;
        char g;
        char b;
        char a;
        u_char rindex;
        u_char gindex;
        u_char bindex;
    } colorInfo[256];
    u_short clutBase[256];
} ClutSlot;

typedef struct {
    u_short uploadPending;
    u_short active;
    ClutSlot slots[14];
    u_char bgAnimActive;
    u_char bgAnimFrame;
    u_char bgAnimTick;
    u_char bgAnimSpeed;
    u_char bgTransitionMode;
    short bgTransitionTargetR;
    short bgTransitionTargetG;
    short bgTransitionTargetB;
    Fade bgColors[5];
    CVECTOR bgBaseColors[5];
    ColorSlot colorSlots[17];
    UNUSED u_char _[0x54];
} ClutState;

typedef struct vs_Main_HeapHeader {
    struct vs_Main_HeapHeader* prev;
    struct vs_Main_HeapHeader* next;
    u_int blockSz;
} __attribute__((aligned(16))) vs_Main_HeapHeader;

void __main(void);
static void unlockPadModeSwitch(void);
static void padResetDefaults(int, void const*);
static void padSetActData(int port, int pos, int val);
static void initCdQueue(void);
static void diskReset(void);
static void processCdQueue(void);
static void loadMenuSound(void);
void asmNop(void);

typedef struct {
    char wLo;
    char wHi;
    char hLo;
    char hHi;
} ImgHeader;

typedef struct {
    int processing : 16;
    int queued : 16;
} CdQueueCount;

extern ImgHeader nowLoading_header;
extern u_long nowLoading_data[];

// vibrationOnBank starts with an effect count, followed by a table of four-byte
// little-endian offsets, one per effect, that locate each effect's script.
char vibrationOnBank[] = { 1, 0, 0, 0, 8, 0, 0, 0, 7, 6, 0, 4, 1, 0, 0, 1, 17, 8, 2, 6,
    255, 0, 0, 0 };
char actParams[] = { 0, 1, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0 };
int vs_main_titleScreenCount = 0;
int vs_main_debugPause = 0;

#define WAVE_FILES(X) \
    X(0000), X(0001), X(0002), X(0003), X(0004), X(0005), X(0006), X(0007), \
    X(0008), X(0009), X(0010), X(0011), X(0012), X(0013), X(0014), X(0015), \
    X(0016), X(0017), X(0018), X(0019), X(0020), X(0021), X(0022), X(0023), \
    X(0024), X(0025), X(0026), X(0027), X(0028), X(0029), X(0030), X(0031), \
    X(0032), X(0033), X(0034), X(0035), X(0036), X(0037), X(0038), X(0039), \
    X(0040), X(0041), X(0042), X(0043), X(0044), X(0045), X(0046), X(0047), \
    X(0048), X(0049), X(0050), X(0051), X(0052), X(0053), X(0054), X(0055), \
    X(0056), X(0057), X(0058), X(0059), X(0060), X(0061), X(0062), X(0063), \
    X(0064), X(0065), X(0066), X(0067), X(0068), X(0069), X(0070), X(0071), \
    X(0072), X(0073), X(0074), X(0075), X(0076), X(0077), X(0078), X(0079), \
    X(0080), X(0081), X(0082), X(0083), X(0084), X(0085), X(0086), X(0087), \
    X(0088), X(0089), X(0090), X(0091), X(0092), X(0093), X(0094), X(0095), \
    X(0096), X(0097), X(0098), X(0099)

// MUSIC102..109 do not exist, their slots point at MUSIC100
#define MUSIC_FILES(X) \
    X(000), X(001), X(002), X(003), X(004), X(005), X(006), X(007), X(008), X(009), \
    X(010), X(011), X(012), X(013), X(014), X(015), X(016), X(017), X(018), X(019), \
    X(020), X(021), X(022), X(023), X(024), X(025), X(026), X(027), X(028), X(029), \
    X(030), X(031), X(032), X(033), X(034), X(035), X(036), X(037), X(038), X(039), \
    X(040), X(041), X(042), X(043), X(044), X(045), X(046), X(047), X(048), X(049), \
    X(050), X(051), X(052), X(053), X(054), X(055), X(056), X(057), X(058), X(059), \
    X(060), X(061), X(062), X(063), X(064), X(065), X(066), X(067), X(068), X(069), \
    X(070), X(071), X(072), X(073), X(074), X(075), X(076), X(077), X(078), X(079), \
    X(080), X(081), X(082), X(083), X(084), X(085), X(086), X(087), X(088), X(089), \
    X(090), X(091), X(092), X(093), X(094), X(095), X(096), X(097), X(098), X(099), \
    X(100), X(101), X(100), X(100), X(100), X(100), X(100), X(100), X(100), X(100), \
    X(110), X(111), X(112), X(113), X(114), X(115), X(116), X(117), X(118), X(119), \
    X(120), X(121), X(122), X(123), X(124), X(125), X(126), X(127), X(128), X(129), \
    X(130), X(131), X(132), X(133), X(134), X(135), X(136), X(137), X(138), X(139), \
    X(140), X(141), X(142), X(143), X(144), X(145), X(146), X(147), X(148), X(149), \
    X(150), X(151), X(152), X(153), X(154), X(155), X(156), X(157), X(158), X(159), \
    X(160), X(161), X(162), X(163), X(164), X(165), X(166), X(167), X(168), X(169), \
    X(170), X(171), X(172), X(173), X(174), X(175), X(176), X(177), X(178), X(179), \
    X(180), X(181), X(182), X(183), X(184), X(185), X(186), X(187), X(188), X(189), \
    X(190), X(191), X(192), X(193), X(194), X(195), X(196), X(197), X(198), X(199)

#define SEP_FILES(X) \
    X(00000), X(00001), X(00002), X(00003), X(00004), X(00005), X(00006), X(00007), \
    X(00008), X(00009), X(00010), X(00011), X(00012), X(00013), X(00014), X(00015), \
    X(00016), X(00017), X(00018), X(00019), X(00020), X(00021), X(00022), X(00023), \
    X(00024), X(00025), X(00026), X(00027), X(00028), X(00029), X(00030), X(00031), \
    X(00032), X(00033), X(00034), X(00035), X(00036), X(00037), X(00038), X(00039), \
    X(00040), X(00041), X(00042), X(00043), X(00044), X(00045), X(00046), X(00047), \
    X(00048), X(00049), X(00050), X(00051), X(00052), X(00053), X(00054), X(00055), \
    X(00056), X(00057), X(00058), X(00059), X(00060), X(00061), X(00062), X(00063), \
    X(00064), X(00065), X(00066), X(00067), X(00068), X(00069), X(00070), X(00071), \
    X(00072), X(00073), X(00074), X(00075), X(00076), X(00077), X(00078), X(00079), \
    X(00080), X(00081), X(00082), X(00083), X(00084), X(00085), X(00086), X(00087), \
    X(00088), X(00089), X(00090), X(00091), X(00092), X(00093), X(00094), X(00095), \
    X(00096), X(00097), X(00098), X(00099)

#define WAVE_LBA(n) VS_WAVE##n##_DAT_LBA
#define WAVE_SIZE(n) VS_WAVE##n##_DAT_SIZE
#define MUSIC_LBA(n) VS_MUSIC##n##_DAT_LBA
#define MUSIC_SIZE(n) VS_MUSIC##n##_DAT_SIZE
#define SEP_LBA(n) VS_SEP##n##_DAT_LBA
#define SEP_SIZE(n) VS_SEP##n##_DAT_SIZE

int soundLBAs[] = { WAVE_FILES(WAVE_LBA) };
int musicLBAs[] = { MUSIC_FILES(MUSIC_LBA) };
int seLBAs[] = { SEP_FILES(SEP_LBA) };
int soundFileSizes[] = { WAVE_FILES(WAVE_SIZE) };
int musicFileSizes[] = { MUSIC_FILES(MUSIC_SIZE) };
int seFileSizes[] = { SEP_FILES(SEP_SIZE) };

#undef WAVE_FILES
#undef MUSIC_FILES
#undef SEP_FILES
#undef WAVE_LBA
#undef WAVE_SIZE
#undef MUSIC_LBA
#undef MUSIC_SIZE
#undef SEP_LBA
#undef SEP_SIZE

char soundFileMap[] = { 0, 65, 66, 66, 68, 69, 67, 85, 68, 93, 69, 68, 0, 69, 69, 0, 69,
    69, 69, 69, 69, 68, 62, 61, 68, 68, 68, 68, 68, 57, 56, 72, 74, 77, 76, 86, 87, 80,
    88, 55, 70, 81, 70, 73, 75, 78, 89, 90, 79, 84, 10, 10, 10, 10, 11, 11, 11, 11, 12,
    12, 12, 12, 13, 13, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 18, 18, 19, 19,
    19, 19, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 24, 24, 25, 25, 25,
    25, 0, 0, 0, 0, 0, 85, 0, 0, 91, 91, 91, 91, 91, 91, 91, 0, 60, 94, 98, 95, 96, 97,
    97, 82, 83, 0, 0, 59, 58, 72, 74, 77, 76, 86, 87, 80, 88, 0, 0, 0, 0, 0, 0, 78, 89,
    90, 79, 84, 0, 99, 99, 99, 99, 92, 64, 64, 64, 54, 53, 53, 53, 53, 53, 63, 63, 63, 52,
    51, 50, 52, 49, 47, 46, 45, 45, 45, 44, 44, 43, 42, 41, 40, 39, 38, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0 };

// Per-frame channel offsets for a CLUT fade of N frames. A row is indexed by the total
// change d (target - current) plus 31 and spreads d over the frames; each table is the
// previous one sampled at every second frame. ANIM_PROGRESS is the part of d applied
// after k of the N frames.
#define ANIM_PROGRESS(d, N, k) \
    ((k) == 0 ? 0 \
              : (k) == (N) ? (d) \
                           : (d) >= 0 ? ((k) * (d)) / (N) : -(((k) * -(d)) / (N)) - 1)
#define ANIM_STEP(d, N, k) (ANIM_PROGRESS(d, N, (k) + 1) - ANIM_PROGRESS(d, N, (k)))
#define ANIM_ROW2(d) { ANIM_STEP(d, 2, 0), ANIM_STEP(d, 2, 1) }
#define ANIM_ROW4(d) \
    { ANIM_STEP(d, 4, 0), ANIM_STEP(d, 4, 1), ANIM_STEP(d, 4, 2), ANIM_STEP(d, 4, 3) }
#define ANIM_ROW8(d) \
    { ANIM_STEP(d, 8, 0), ANIM_STEP(d, 8, 1), ANIM_STEP(d, 8, 2), ANIM_STEP(d, 8, 3), \
        ANIM_STEP(d, 8, 4), ANIM_STEP(d, 8, 5), ANIM_STEP(d, 8, 6), ANIM_STEP(d, 8, 7) }
#define ANIM_ROW16(d) \
    { ANIM_STEP(d, 16, 0), ANIM_STEP(d, 16, 1), ANIM_STEP(d, 16, 2), \
        ANIM_STEP(d, 16, 3), ANIM_STEP(d, 16, 4), ANIM_STEP(d, 16, 5), \
        ANIM_STEP(d, 16, 6), ANIM_STEP(d, 16, 7), ANIM_STEP(d, 16, 8), \
        ANIM_STEP(d, 16, 9), ANIM_STEP(d, 16, 10), ANIM_STEP(d, 16, 11), \
        ANIM_STEP(d, 16, 12), ANIM_STEP(d, 16, 13), ANIM_STEP(d, 16, 14), \
        ANIM_STEP(d, 16, 15) }

// d = -31..31
#define ANIM_ROWS(R)                                                                     \
    R(-31), R(-30), R(-29), R(-28), R(-27), R(-26), R(-25), R(-24), R(-23), R(-22),      \
        R(-21), R(-20), R(-19), R(-18), R(-17), R(-16), R(-15), R(-14), R(-13),          \
        R(-12), R(-11), R(-10), R(-9), R(-8), R(-7), R(-6), R(-5), R(-4), R(-3), R(-2),  \
        R(-1), R(0), R(1), R(2), R(3), R(4), R(5), R(6), R(7), R(8), R(9), R(10), R(11), \
        R(12), R(13), R(14), R(15), R(16), R(17), R(18), R(19), R(20), R(21), R(22),     \
        R(23), R(24), R(25), R(26), R(27), R(28), R(29), R(30), R(31)

signed char animOffset16[][16] = { ANIM_ROWS(ANIM_ROW16) };
signed char animOffset8[][8] = { ANIM_ROWS(ANIM_ROW8) };
signed char animOffset4[][4] = { ANIM_ROWS(ANIM_ROW4) };
signed char animOffset2[][2] = { ANIM_ROWS(ANIM_ROW2) };

#undef ANIM_PROGRESS
#undef ANIM_STEP
#undef ANIM_ROW2
#undef ANIM_ROW4
#undef ANIM_ROW8
#undef ANIM_ROW16
#undef ANIM_ROWS

#include "build/assets/SLUS_010.40/vs_main_actions.h"

MaterialModifiers vs_main_materialModifiers[] = {
    // None
    { 0 },
    // Wood
    {
        .attackAffinities = { .phys = 4,
            .wind = 6,
            .fire = -8,
            .earth = -8,
            .water = 6,
            .light = 4,
            .dark = 4 },
        .defenseAffinities = { .phys = 4,
            .wind = -6,
            .fire = 8,
            .earth = 8,
            .water = -6,
            .light = -4,
            .dark = -4 },
        .maxDp = 3500,
        .strength = 1,
        .intelligence = 6,
    },
    // Leather
    {
        .attackAffinities = { .phys = 2,
            .wind = -5,
            .fire = -5,
            .earth = 1,
            .water = 1,
            .light = 5,
            .dark = 5 },
        .defenseAffinities = { .phys = 2,
            .wind = 5,
            .fire = 5,
            .earth = -1,
            .water = -1,
            .light = -5,
            .dark = -5 },
        .maxDp = 2000,
        .intelligence = 5,
    },
    // Bronze
    {
        .human = -1,
        .beast = -1,
        .undead = -2,
        .phantom = -1,
        .dragon = -1,
        .evil = -5,
        .attackAffinities = { .phys = 8,
            .wind = 5,
            .fire = 5,
            .earth = -3,
            .water = -3,
            .light = 2,
            .dark = 2 },
        .defenseAffinities = { .phys = 8,
            .wind = -5,
            .fire = -5,
            .earth = 3,
            .water = 3,
            .light = -2,
            .dark = -2 },
        .maxDp = 5000,
        .strength = 2,
        .intelligence = 1,
        .agility = -2,
    },
    // Iron
    {
        .human = 1,
        .beast = 1,
        .undead = -2,
        .phantom = 1,
        .dragon = 1,
        .attackAffinities = { .phys = 10, .fire = 4, .earth = 4, .light = 1, .dark = 1 },
        .defenseAffinities = { .phys = 10,
            .fire = -4,
            .earth = -4,
            .light = -1,
            .dark = -1 },
        .maxDp = 6500,
        .strength = 4,
        .intelligence = 1,
        .agility = -2,
    },
    // Hagane
    {
        .human = 5,
        .beast = 5,
        .undead = 1,
        .dragon = 5,
        .evil = 5,
        .attackAffinities = { .phys = 14,
            .wind = -3,
            .fire = -3,
            .earth = 5,
            .water = 5,
            .light = 5,
            .dark = 5 },
        .defenseAffinities = { .phys = 14,
            .wind = 3,
            .fire = 3,
            .earth = -5,
            .water = -5,
            .light = -5,
            .dark = -5 },
        .maxDp = 7000,
        .strength = 6,
        .intelligence = 2,
        .agility = -1,
    },
    // Silver
    {
        .undead = 20,
        .phantom = 15,
        .evil = 5,
        .attackAffinities = { .phys = 5,
            .wind = 5,
            .fire = 5,
            .earth = 5,
            .water = 5,
            .light = 20,
            .dark = -5 },
        .defenseAffinities = { .phys = 5,
            .wind = -5,
            .fire = -5,
            .earth = -5,
            .water = -5,
            .light = -5,
            .dark = 20 },
        .maxDp = 4000,
        .strength = 3,
        .intelligence = 1,
        .agility = -1,
    },
    // Damascus
    {
        .human = 10,
        .beast = 10,
        .undead = -2,
        .dragon = 10,
        .evil = 10,
        .attackAffinities = { .phys = 20,
            .wind = 5,
            .fire = 5,
            .earth = 5,
            .water = 5,
            .light = -10,
            .dark = 10 },
        .defenseAffinities = { .phys = 20,
            .wind = -5,
            .fire = -5,
            .earth = -5,
            .water = -5,
            .light = 20,
            .dark = -20 },
        .maxDp = 8000,
        .strength = 8,
        .intelligence = 3,
        .agility = -1,
    },
};

#define STAT_MODS                                                                        \
    (vsBattleStatusStrDown | vsBattleStatusStrUp | vsBattleStatusIntDown                 \
        | vsBattleStatusIntUp | vsBattleStatusAgiDown | vsBattleStatusAgiUp)
#define EQUIP_MODS                                                                       \
    (vsBattleStatusEquDown | vsBattleStatusEquUp | vsBattleStatusAirAtkUp                \
        | vsBattleStatusFireAtkUp | vsBattleStatusEarthAtkUp | vsBattleStatusWaterAtkUp  \
        | vsBattleStatusAirDefUp | vsBattleStatusFireDefUp | vsBattleStatusEarthDefUp    \
        | vsBattleStatusWaterDefUp)

vs_StatusEffectParams vs_main_statusEffectParams[] = {
    { .status = vsBattleStatusHeadDown, .replacesMask = vsBattleStatusSilent },
    { .status = vsBattleStatusRightArmDown },
    { .status = vsBattleStatusLeftArmDown },
    { .status = vsBattleStatusBodyDown },
    { .status = vsBattleStatusLegsDown, .replacesMask = vsBattleStatusQuicken },
    {
        .status = vsBattleStatusStrDown,
        .duration = 15,
        .replacesMask = STAT_MODS,
        .blockedByMask = vsBattleStatusCurse,
    },
    {
        .status = vsBattleStatusStrUp,
        .duration = 15,
        .replacesMask = STAT_MODS,
        .blockedByMask = vsBattleStatusCurse,
    },
    {
        .status = vsBattleStatusIntDown,
        .duration = 15,
        .replacesMask = STAT_MODS,
        .blockedByMask = vsBattleStatusCurse,
    },
    {
        .status = vsBattleStatusIntUp,
        .duration = 15,
        .replacesMask = STAT_MODS,
        .blockedByMask = vsBattleStatusCurse,
    },
    {
        .status = vsBattleStatusAgiDown,
        .duration = 15,
        .replacesMask = STAT_MODS,
        .blockedByMask = vsBattleStatusCurse,
    },
    {
        .status = vsBattleStatusAgiUp,
        .duration = 15,
        .replacesMask = STAT_MODS,
        .blockedByMask = vsBattleStatusCurse,
    },
    {
        .status = vsBattleStatusQuicken,
        .duration = 20,
        .replacesMask = vsBattleStatusQuicken,
        .blockedByMask = vsBattleStatusLegsDown | vsBattleStatusNumbness,
    },
    { .status = vsBattleStatusSilent, .replacesMask = vsBattleStatusSilent },
    {
        .status = vsBattleStatusParalysis,
        .duration = 15,
        .replacesMask = vsBattleStatusParalysis,
    },
    {
        .status = vsBattleStatusPoison,
        .tickInterval = 2,
        .replacesMask = vsBattleStatusRegen,
    },
    {
        .status = vsBattleStatusNumbness,
        .duration = 15,
        .replacesMask = vsBattleStatusQuicken | vsBattleStatusNumbness,
        .blockedByMask = vsBattleStatusLegsDown,
    },
    {
        .status = vsBattleStatusCurse,
        .replacesMask = STAT_MODS,
        .blockedByMask = vsBattleStatusCurse,
    },
    {
        .status = vsBattleStatusRegen,
        .tickInterval = 5,
        .blockedByMask = vsBattleStatusPoison,
    },
    { .status = vsBattleStatusWard, .blockedByMask = vsBattleStatusWard },
    { .status = vsBattleStatusEquDown, .duration = 15, .replacesMask = EQUIP_MODS },
    { .status = vsBattleStatusEquUp, .duration = 20, .replacesMask = EQUIP_MODS },
    { .status = vsBattleStatusAirAtkUp, .duration = 25, .replacesMask = EQUIP_MODS },
    { .status = vsBattleStatusFireAtkUp, .duration = 25, .replacesMask = EQUIP_MODS },
    { .status = vsBattleStatusEarthAtkUp, .duration = 25, .replacesMask = EQUIP_MODS },
    { .status = vsBattleStatusWaterAtkUp, .duration = 25, .replacesMask = EQUIP_MODS },
    { .status = vsBattleStatusAirDefUp, .duration = 25, .replacesMask = EQUIP_MODS },
    { .status = vsBattleStatusFireDefUp, .duration = 25, .replacesMask = EQUIP_MODS },
    { .status = vsBattleStatusEarthDefUp, .duration = 25, .replacesMask = EQUIP_MODS },
    { .status = vsBattleStatusWaterDefUp, .duration = 25, .replacesMask = EQUIP_MODS },
    { .status = 1 << 29 },
    { .status = 1 << 30 },
    { .status = 1 << 31 },
};

#undef STAT_MODS
#undef EQUIP_MODS

u_char vs_main_locationZoneMapIds[] = { 100, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0,
    8, 0, 9, 0, 9, 1, 9, 2, 9, 3, 9, 4, 9, 5, 9, 6, 9, 7, 9, 8, 9, 9, 9, 10, 9, 11, 9, 12,
    9, 13, 9, 14, 9, 15, 11, 0, 12, 0, 9, 16, 13, 0, 13, 1, 13, 2, 13, 3, 13, 4, 13, 5,
    13, 6, 13, 7, 13, 8, 13, 9, 13, 10, 13, 11, 13, 12, 13, 13, 13, 14, 13, 15, 13, 16,
    13, 17, 14, 0, 15, 0, 15, 1, 15, 2, 15, 3, 15, 4, 15, 5, 15, 6, 15, 7, 15, 8, 15, 9,
    15, 10, 15, 11, 15, 12, 16, 0, 17, 0, 18, 0, 22, 0, 22, 1, 22, 2, 22, 3, 22, 4, 22, 5,
    22, 6, 22, 7, 22, 8, 22, 9, 23, 0, 23, 1, 23, 2, 23, 3, 23, 4, 23, 5, 24, 0, 24, 1,
    24, 2, 24, 3, 24, 4, 24, 5, 24, 6, 24, 7, 24, 8, 24, 9, 24, 10, 24, 11, 24, 12, 24,
    13, 24, 14, 24, 15, 25, 0, 25, 1, 25, 2, 25, 3, 25, 4, 26, 0, 27, 0, 27, 1, 57, 0, 58,
    0, 28, 0, 28, 1, 28, 2, 28, 3, 28, 4, 28, 5, 28, 6, 28, 7, 28, 8, 28, 9, 28, 10, 28,
    11, 28, 12, 28, 13, 28, 14, 28, 15, 28, 16, 28, 17, 28, 18, 29, 0, 29, 1, 29, 2, 29,
    3, 29, 4, 29, 5, 29, 6, 60, 0, 61, 0, 62, 0, 63, 0, 64, 0, 65, 0, 66, 0, 67, 0, 30, 0,
    30, 1, 30, 2, 30, 3, 30, 4, 30, 5, 31, 0, 31, 1, 32, 0, 32, 1, 32, 2, 32, 3, 32, 4,
    32, 5, 32, 6, 32, 7, 32, 8, 32, 9, 32, 10, 32, 11, 32, 12, 32, 13, 32, 14, 32, 15, 32,
    16, 32, 17, 32, 18, 32, 19, 32, 20, 32, 21, 32, 22, 32, 23, 39, 0, 33, 0, 34, 0, 35,
    0, 36, 0, 37, 0, 38, 0, 68, 0, 40, 0, 40, 1, 40, 2, 40, 3, 40, 4, 40, 5, 40, 6, 40, 7,
    40, 8, 40, 9, 40, 10, 40, 11, 40, 12, 40, 13, 40, 14, 40, 15, 40, 16, 40, 17, 40, 18,
    40, 19, 40, 20, 40, 21, 40, 22, 40, 23, 40, 24, 40, 25, 42, 0, 43, 0, 44, 0, 45, 0,
    46, 0, 47, 0, 10, 0, 19, 0, 20, 0, 21, 0, 1, 1, 2, 1, 3, 1, 4, 1, 5, 1, 48, 0, 48, 1,
    48, 2, 48, 3, 48, 4, 48, 5, 48, 6, 48, 7, 48, 8, 48, 9, 48, 10, 48, 11, 48, 12, 48,
    13, 48, 14, 48, 15, 48, 16, 48, 17, 48, 18, 48, 19, 48, 20, 48, 21, 48, 22, 48, 23,
    48, 24, 48, 25, 48, 26, 49, 0, 49, 1, 49, 2, 49, 3, 49, 4, 49, 5, 49, 6, 49, 7, 49, 8,
    49, 9, 49, 10, 49, 11, 49, 12, 50, 0, 50, 1, 50, 2, 50, 3, 50, 4, 50, 5, 50, 6, 50, 7,
    50, 8, 50, 9, 50, 10, 50, 11, 50, 12, 50, 13, 50, 14, 50, 15, 50, 16, 50, 17, 50, 18,
    50, 19, 50, 20, 50, 21, 50, 22, 50, 23, 51, 0, 51, 1, 51, 2, 51, 3, 51, 4, 51, 5, 51,
    6, 51, 7, 51, 8, 51, 9, 51, 10, 51, 11, 51, 12, 51, 13, 51, 14, 51, 15, 51, 16, 51,
    17, 51, 18, 51, 19, 51, 20, 51, 21, 51, 22, 51, 23, 51, 24, 51, 25, 51, 26, 53, 0, 53,
    1, 53, 2, 53, 3, 53, 4, 53, 5, 53, 6, 53, 7, 53, 8, 53, 9, 53, 10, 53, 11, 53, 12, 53,
    13, 53, 14, 53, 15, 53, 16, 53, 17, 53, 18, 53, 19, 53, 20, 53, 21, 53, 22, 53, 23,
    53, 24, 53, 25, 53, 26, 53, 27, 53, 28, 53, 29, 53, 30, 53, 31, 54, 0, 54, 1, 54, 2,
    54, 3, 54, 4, 41, 0, 41, 1, 41, 2, 52, 0, 52, 1, 52, 2, 52, 3, 52, 4, 52, 5, 52, 6,
    52, 7, 55, 0, 55, 1, 55, 2, 55, 3, 55, 4, 55, 5, 55, 6, 55, 7, 55, 8, 55, 9, 55, 10,
    55, 11, 55, 12, 55, 13, 55, 14, 55, 15, 55, 16, 55, 17, 55, 18, 55, 19, 55, 20, 55,
    21, 55, 22, 56, 0, 56, 1, 56, 2, 56, 3, 56, 4, 56, 5, 56, 6, 56, 7, 56, 8, 56, 9, 56,
    10, 56, 11, 56, 12, 56, 13, 56, 14, 56, 15, 56, 16, 56, 17, 56, 18, 56, 19, 56, 20,
    56, 21, 56, 22, 56, 23, 56, 24, 56, 25, 12, 1, 9, 17, 51, 27, 51, 28, 9, 18, 59, 0,
    69, 0, 70, 0, 0, 160, 0, 161, 0, 162, 0, 163, 0, 164, 0, 165, 0, 166, 0, 167, 0, 168,
    0, 169, 0, 170, 96, 0, 97, 0, 98, 0, 99, 0, 0, 175, 0, 176, 0, 177, 0, 178, 0, 179, 0,
    180, 0, 181, 0, 182, 0, 183, 0, 184, 0, 185, 0, 186, 0, 187, 0, 188, 0, 189, 0, 190,
    0, 191, 0, 192, 0, 193, 0, 194, 0, 195, 0, 196, 0, 197, 0, 198, 0, 199, 0, 200, 0,
    201, 0, 202, 0, 203, 0, 204, 0, 205, 0, 206, 0, 207, 0, 208, 0, 209, 0, 210, 0, 211,
    0, 212, 0, 213, 0, 214, 0, 215, 0, 216, 0, 217, 0, 218, 0, 219, 0, 220, 0, 221, 0,
    222, 0, 223, 0, 224, 0, 225, 0, 226, 0, 227, 0, 228, 0, 229, 0, 230, 0, 231, 0, 232,
    0, 233, 0, 234, 0, 235, 0, 236, 0, 237, 0, 238, 0, 239, 0, 240, 0, 241, 0, 242, 0,
    243, 0, 244, 0, 245, 0, 246, 0, 247, 0, 248, 0, 249, 250, 0, 0, 251, 0, 252, 0, 253,
    0, 254, 0, 255 };

#define ZNDLBA(file)                                    \
    {                                                     \
        VS_ZONE##file##_ZND_LBA, VS_ZONE##file##_ZND_SIZE \
    }

vs_Main_CdFile vs_main_zndFiles[] = { ZNDLBA(000), ZNDLBA(001), ZNDLBA(002), ZNDLBA(003),
    ZNDLBA(004), ZNDLBA(005), ZNDLBA(006), ZNDLBA(007), ZNDLBA(008), ZNDLBA(009),
    ZNDLBA(010), ZNDLBA(011), ZNDLBA(012), ZNDLBA(013), ZNDLBA(014), ZNDLBA(015),
    ZNDLBA(016), ZNDLBA(017), ZNDLBA(018), ZNDLBA(019), ZNDLBA(020), ZNDLBA(021),
    ZNDLBA(022), ZNDLBA(023), ZNDLBA(024), ZNDLBA(025), ZNDLBA(026), ZNDLBA(027),
    ZNDLBA(028), ZNDLBA(029), ZNDLBA(030), ZNDLBA(031), ZNDLBA(032), ZNDLBA(033),
    ZNDLBA(034), ZNDLBA(035), ZNDLBA(036), ZNDLBA(037), ZNDLBA(038), ZNDLBA(039),
    ZNDLBA(040), ZNDLBA(041), ZNDLBA(042), ZNDLBA(043), ZNDLBA(044), ZNDLBA(045),
    ZNDLBA(046), ZNDLBA(047), ZNDLBA(048), ZNDLBA(049), ZNDLBA(050), ZNDLBA(051),
    ZNDLBA(052), ZNDLBA(053), ZNDLBA(054), ZNDLBA(055), ZNDLBA(056), ZNDLBA(057),
    ZNDLBA(058), ZNDLBA(059), ZNDLBA(060), ZNDLBA(061), ZNDLBA(062), ZNDLBA(063),
    ZNDLBA(064), ZNDLBA(065), ZNDLBA(066), ZNDLBA(067), ZNDLBA(068), ZNDLBA(069),
    ZNDLBA(070), ZNDLBA(071), ZNDLBA(072), ZNDLBA(073), ZNDLBA(074), ZNDLBA(075),
    ZNDLBA(076), ZNDLBA(077), ZNDLBA(078), ZNDLBA(079), ZNDLBA(080), ZNDLBA(081),
    ZNDLBA(082), ZNDLBA(083), ZNDLBA(084), ZNDLBA(085), ZNDLBA(086), ZNDLBA(087),
    ZNDLBA(088), ZNDLBA(089), ZNDLBA(090), ZNDLBA(091), ZNDLBA(092), ZNDLBA(093),
    ZNDLBA(094), ZNDLBA(095), ZNDLBA(096), ZNDLBA(097), ZNDLBA(098), ZNDLBA(099),
    ZNDLBA(100), ZNDLBA(101), ZNDLBA(102), ZNDLBA(103), ZNDLBA(104), ZNDLBA(105),
    ZNDLBA(106), ZNDLBA(107), ZNDLBA(108), ZNDLBA(109), ZNDLBA(110), ZNDLBA(111),
    ZNDLBA(112), ZNDLBA(113), ZNDLBA(114), ZNDLBA(115), ZNDLBA(116), ZNDLBA(117),
    ZNDLBA(118), ZNDLBA(119), ZNDLBA(120), ZNDLBA(121), ZNDLBA(122), ZNDLBA(123),
    ZNDLBA(124), ZNDLBA(125), ZNDLBA(126), ZNDLBA(127), ZNDLBA(128), ZNDLBA(129),
    ZNDLBA(130), ZNDLBA(131), ZNDLBA(132), ZNDLBA(133), ZNDLBA(134), ZNDLBA(135),
    ZNDLBA(136), ZNDLBA(137), ZNDLBA(138), ZNDLBA(139), ZNDLBA(140), ZNDLBA(141),
    ZNDLBA(142), ZNDLBA(143), ZNDLBA(144), ZNDLBA(145), ZNDLBA(146), ZNDLBA(147),
    ZNDLBA(148), ZNDLBA(149), ZNDLBA(150), ZNDLBA(151), ZNDLBA(152), ZNDLBA(153),
    ZNDLBA(154), ZNDLBA(155), ZNDLBA(156), ZNDLBA(157), ZNDLBA(158), ZNDLBA(159),
    ZNDLBA(160), ZNDLBA(161), ZNDLBA(162), ZNDLBA(163), ZNDLBA(164), ZNDLBA(165),
    ZNDLBA(166), ZNDLBA(167), ZNDLBA(168), ZNDLBA(169), ZNDLBA(170), ZNDLBA(171),
    ZNDLBA(172), ZNDLBA(173), ZNDLBA(174), ZNDLBA(175), ZNDLBA(176), ZNDLBA(177),
    ZNDLBA(178), ZNDLBA(179), ZNDLBA(180), ZNDLBA(181), ZNDLBA(182), ZNDLBA(183),
    ZNDLBA(184), ZNDLBA(185), ZNDLBA(186), ZNDLBA(187), ZNDLBA(188), ZNDLBA(189),
    ZNDLBA(190), ZNDLBA(191), ZNDLBA(192), ZNDLBA(193), ZNDLBA(194), ZNDLBA(195),
    ZNDLBA(196), ZNDLBA(197), ZNDLBA(198), ZNDLBA(199), ZNDLBA(200), ZNDLBA(201),
    ZNDLBA(202), ZNDLBA(203), ZNDLBA(204), ZNDLBA(205), ZNDLBA(206), ZNDLBA(207),
    ZNDLBA(208), ZNDLBA(209), ZNDLBA(210), ZNDLBA(211), ZNDLBA(212), ZNDLBA(213),
    ZNDLBA(214), ZNDLBA(215), ZNDLBA(216), ZNDLBA(217), ZNDLBA(218), ZNDLBA(219),
    ZNDLBA(220), ZNDLBA(221), ZNDLBA(222), ZNDLBA(223), ZNDLBA(224), ZNDLBA(225),
    ZNDLBA(226), ZNDLBA(227), ZNDLBA(228), ZNDLBA(229), ZNDLBA(230), ZNDLBA(231),
    ZNDLBA(232), ZNDLBA(233), ZNDLBA(234), ZNDLBA(235), ZNDLBA(236), ZNDLBA(237),
    ZNDLBA(238), ZNDLBA(239), ZNDLBA(240), ZNDLBA(241), ZNDLBA(242), ZNDLBA(243),
    ZNDLBA(244), ZNDLBA(245), ZNDLBA(246), ZNDLBA(247), ZNDLBA(248), ZNDLBA(249),
    ZNDLBA(250), ZNDLBA(251), ZNDLBA(252), ZNDLBA(253), ZNDLBA(254), ZNDLBA(255) };

u_char vs_main_zndMusicMap[256] = { 0, 16, 0, 0, 0, 0, 0, 0, 0, 54, 0, 57, 57, 119, 65,
    120, 65, 0, 0, 0, 0, 0, 41, 41, 41, 41, 0, 0, 51, 66, 22, 22, 88, 0, 66, 66, 66, 66,
    66, 88, 44, 79, 40, 40, 40, 40, 40, 40, 121, 118, 43, 126, 129, 125, 130, 29, 30 };

u_short vs_main_actorNames[] = {
#include "build/assets/SLUS_010.40/vs_main_actorNames.vsString"
};

u_short vs_main_artsPointsRequirements[][4] = {
    { 10, 65, 175, 340 },
    { 20, 90, 235, 425 },
    { 25, 110, 260, 485 },
    { 18, 80, 210, 420 },
    { 20, 100, 245, 465 },
    { 15, 90, 215, 410 },
    { 20, 95, 205, 385 },
    { 15, 95, 220, 405 },
    { 20, 95, 230, 430 },
    { 30, 105, 250, 460 },
};

static UNUSED u_char artsActionIds[][4] = {
    { 220, 221, 222, 223 },
    { 184, 185, 186, 187 },
    { 188, 189, 190, 191 },
    { 192, 193, 194, 195 },
    { 196, 197, 198, 199 },
    { 200, 201, 202, 203 },
    { 204, 205, 206, 207 },
    { 208, 209, 210, 211 },
    { 212, 213, 214, 215 },
    { 216, 217, 218, 219 },
};

// Points needed for each battle ability. Each step is increased by about 1.3 of the
// previous one, the first value is an anomaly and was probably changed after the curve
// was defined, 40 would fit.
u_short vs_main_battleAbilitiesPointsRequirements[] = { 20, 54, 72, 95, 125, 165, 216,
    283, 369, 482, 628, 818, 1066, 1387, 1805, 2349, 3055, 3973, 5167, 6719, 8737,
    11359 };

u_char vs_main_actorExtraShp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

static void loadBattlePrg(void)
{
    vs_Main_CdFile cdFile;
    vs_Main_CdQueueSlot* slot;

    cdFile.lba = VS_BATTLE_PRG_LBA;
    cdFile.size = VS_BATTLE_PRG_SIZE;

    slot = vs_main_allocateCdQueueSlot(&cdFile);
    vs_main_cdEnqueuePriority(slot, vs_overlay_slots[0]);

    while (slot->state != vs_main_CdQueueStateLoaded) {
        vs_main_gametimeUpdate(0);
    }

    vs_main_freeCdQueueSlot(slot);

    cdFile.lba = VS_INITBTL_PRG_LBA;
    cdFile.size = VS_INITBTL_PRG_SIZE;

    slot = vs_main_allocateCdQueueSlot(&cdFile);
    vs_main_cdEnqueuePriority(slot, vs_overlay_slots[1]);

    while (slot->state != vs_main_CdQueueStateLoaded) {
        vs_main_gametimeUpdate(0);
    }

    vs_main_freeCdQueueSlot(slot);
    vs_main_wait();
}

static void loadTitlePrg(void)
{
    vs_Main_CdFile cdFile;
    vs_Main_CdQueueSlot* slot;

    cdFile.lba = VS_TITLE_PRG_LBA;
    cdFile.size = VS_TITLE_PRG_SIZE;

    slot = vs_main_allocateCdQueueSlot(&cdFile);
    vs_main_cdEnqueuePriority(slot, vs_overlay_slots[0]);

    while (slot->state != vs_main_CdQueueStateLoaded) {
        vs_main_gametimeUpdate(0);
    }

    vs_main_freeCdQueueSlot(slot);
    vs_main_wait();
}

static void loadEndingPrg(void)
{
    vs_Main_CdFile cdFile;
    vs_Main_CdQueueSlot* slot;

    cdFile.lba = VS_ENDING_PRG_LBA;
    cdFile.size = VS_ENDING_PRG_SIZE;

    slot = vs_main_allocateCdQueueSlot(&cdFile);
    vs_main_cdEnqueuePriority(slot, vs_overlay_slots[0]);

    while (slot->state != vs_main_CdQueueStateLoaded) {
        vs_main_gametimeUpdate(0);
    }

    vs_main_freeCdQueueSlot(slot);
    vs_main_wait();
}

static int randArr[97];
static int randIndex;
static void* cdReadBuffer;
static UNUSED int _0;
static struct {
    int strength[2];
    PadVibration port[2];
} padAct;
PortInfo vs_main_portInfo[2];
static UNUSED u_char _2[2];
static vs_Main_HeapHeader heapList;
static UNUSED vs_Main_HeapHeader unusedHeap;
static DslLOC cdReadLoc;
static int cdaTrack;
static int cdaMinute;
static int cdaSecond;
static int cdaPeak;
static UNUSED int _3;
static vs_Main_CdQueueSlot cdQueue[32];
static CdQueueCount cdQueueCount;
static UNUSED int _4;
vs_BattleTimer vs_main_battleTimer;
int vs_main_startState;
static int sp2;
static u_short sfxData[0x2C00];
u_int vs_main_buttonsReleased;
static UNUSED int _5;
void* vs_main_ot[2];
static int resetEnabled;
static UNUSED int _6;
static u_int buttonHeldFrameCount[32];
static Disk disk;
static ClutState clutState;
vs_StickPos vs_main_stickPosBuf;
static int savedSp;
short vs_main_screenX;
short vs_main_screenWidth;
short vs_main_screenY;
u_short vs_main_screenHeight;
u_int vs_main_buttonRepeat;
static UNUSED int _7[4];
char vs_main_padBuffer[2][34];
static UNUSED int _8;
SoundData vs_main_soundData;
void* vs_main_prims[2];
int vs_main_nearClip;
static UNUSED int _9;
DRAWENV vs_main_drawEnv[2];
DISPENV vs_main_dispEnv[2];
static UNUSED int _10[4];

static void initScreen(int w, int h, UNUSED int projectionDistance, UNUSED int unused3,
    UNUSED int unused4, UNUSED int unused5)
{
    SetDefDispEnv(vs_main_dispEnv, 0, 0, w, h - 16);

    setRECT(&vs_main_dispEnv[0].screen, 0, 8, 256, 224);

    PutDispEnv(vs_main_dispEnv);
}

#define IMG_W(header) (header.wLo + (header.wHi << 8))
#define IMG_H(header) (header.hLo + (header.hHi << 8))

#define LOADING_RECT(rect, x)                                                          \
    setRECT(rect, (320 - IMG_W(nowLoading_header)) / 2 + (x),                         \
        (224 - IMG_H(nowLoading_header)) / 2, IMG_W(nowLoading_header),              \
        IMG_H(nowLoading_header))

u_int vs_main_buttonsPreviousState;
int vs_main_unused0;
static UNUSED int _11[2];
vs_ButtonsPressed vs_main_buttonsPressed;
int vs_main_unused1;
u_int vs_main_frameDuration;
static UNUSED int _12[13];
int vs_main_frameBuf;
int vs_main_saveGameClearData;
MATRIX vs_main_cameraBasis;
u_int vs_main_buttonsState;
static UNUSED int _14;
static int inGame;
int vs_main_unused2;
int vs_main_projectionDistance;

static void displayLoadingScreen(void)
{
    RECT rect;

    initScreen(320, 240, vs_main_projectionDistance, 0, 0, 0);

    setRECT(&rect, 0, 0, 1024, 512);

    ClearImage2(&rect, 0, 0, 0);
    DrawSync(0);
    VSync(2);

    LOADING_RECT(&rect, 0);

    LoadImage(&rect, (u_long*)&nowLoading_header + 1);

    LOADING_RECT(&rect, 320);

    LoadImage(&rect, (u_long*)&nowLoading_header + 1);
    DrawSync(0);
    SetDispMask(1);
}

static UNUSED void bufferLoadingScreen(void)
{
    RECT rect;

    if (vs_main_frameBuf != 0) {
        LOADING_RECT(&rect, 0);
    } else {
        LOADING_RECT(&rect, 320);
    }

    LoadImage(&rect, nowLoading_data);
    DrawSync(0);
}

static inline void blankScreen(void)
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
}

static inline void stopVibrationAndReconnectPads(void)
{
    padSetActData(0, 0, 0);
    padSetActData(0, 1, 0);
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(0x10, vs_main_padBuffer[1]);
}

void vs_main_resetGame(void)
{
    blankScreen();

    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;

    DsFlush();
    stopVibrationAndReconnectPads();
    TeardownSound();
    SpuQuit();
    ResetGraph(3);
    VSync(10);
    vs_overlay_jumpToTitle(&sp2);
}

void vs_main_jumpToBattle(void)
{
    blankScreen();
    stopVibrationAndReconnectPads();
    ResetGraph(3);
    Sound_StopMusic();
    Sound_StopSfx();
    Sound_ClearSuspendedMusic();
    Sound_ResetMusicBankIds();
    displayLoadingScreen();
    loadBattlePrg();

    vs_main_startState = 1;

    vs_overlay_jumpToBattle(&savedSp);
}

void vs_main_showEndingAndReturnToTitle(void)
{
    inGame = 0;

    blankScreen();
    stopVibrationAndReconnectPads();
    ResetGraph(3);
    Sound_StopMusic();
    Sound_StopSfx();
    vs_main_captureSaveState();
    loadEndingPrg();
    vs_ending_exec();
    blankScreen();
    stopVibrationAndReconnectPads();
    TeardownSound();
    SpuQuit();
    ResetGraph(3);

    vs_main_saveGameClearData = 1;

    vs_overlay_jumpToTitle(&sp2);
}

int vs_gametime_tickspeed;
static u_short clutBuffer[14][256];
static UNUSED int _15[8];
static int nextVoicePool0;
static int nextVoicePool1;
static int nextVoicePool2;
static int nextVoicePool3;
static int nextVoicePool4;
static int nextVoicePool5;
static UNUSED int _16[6];
vs_Scoredata vs_main_scoredata;
static UNUSED int _17;
char vs_main_actionsLearned[32];
vs_MapStatus vs_main_mapStatus;
vs_Settings vs_main_settings;
vs_ArtsStatus vs_main_artsStatus;
int vs_main_zoneEnemyCacheIndex;
vs_CharacterSnapshot vs_main_characterSnapshot;
vs_Inventory vs_main_inventory;
vs_Warp vs_main_spawnPoint;
vs_Gametime vs_main_gametime;

int vs_main_gametimeUpdate(int mode)
{
    int vsync = VSync(mode);

    if (mode != 1) {
        asmNop();
    }

    processCdQueue();

    if (vs_main_gametime.t.h >= 100) {
        return vsync;
    }

    vs_main_gametime.t.f += vs_gametime_tickspeed;

    if (vs_main_gametime.t.f < 60) {
        return vsync;
    }

    vs_main_gametime.t.f = 0;

    if (++vs_main_gametime.t.s < 60) {
        return vsync;
    }

    vs_main_gametime.t.s = 0;

    if (++vs_main_gametime.t.m < 60) {
        return vsync;
    }

    vs_main_gametime.t.m = 0;

    if (++vs_main_gametime.t.h >= 100) {
        vs_main_gametime.t.h = 100;
    }

    return vsync;
}

static void gpuSyncVoidCallback(void) { }

static void vSyncVoidCallback(void) { }

static UNUSED void nop0(void) { }

static UNUSED void nop1(void) { }

static UNUSED void nop2(void) { }

static UNUSED void nop3(void) { }

static void initRand(void)
{
    int i;

    srand(1);

    for (i = 0; i < (int)(sizeof randArr / sizeof randArr[0]); ++i) {
        randArr[i] = rand();
    }

    randIndex = (sizeof randArr / sizeof randArr[0]) - 1;
}

int vs_main_getRand(int max)
{
    int value;
    int slot = randArr[randIndex] * (sizeof randArr / sizeof randArr[0]);
    randIndex = slot / -SHRT_MIN;
    value = SHRT_MAX - randArr[randIndex];
    randArr[randIndex] = rand();

    return value * max / -SHRT_MIN;
}

int vs_main_getRandSmoothed(int max)
{
    return (vs_main_getRand(max) + vs_main_getRand(max) + vs_main_getRand(max)
               + vs_main_getRand(max) + vs_main_getRand(max) + vs_main_getRand(max)
               + vs_main_getRand(max) + vs_main_getRand(max) + vs_main_getRand(max)
               + vs_main_getRand(max) + vs_main_getRand(max) + vs_main_getRand(max))
         / 12;
}

static void sysInit(void)
{
    SetVideoMode(MODE_NTSC);
    SetDispMask(0);
    ResetCallback();
    ResetGraph(0);
    SetGraphDebug(0);
    InitCARD(0);
    StartCARD();
    _bu_init();
    PadInitDirect(vs_main_padBuffer[0], vs_main_padBuffer[1]);
    padResetDefaults(0, vs_main_padBuffer[0]);
    padResetDefaults(0x10, vs_main_padBuffer[1]);
    PadStartCom();
    unlockPadModeSwitch();
    vs_main_resetPadAct();
    SsUtReverbOff();
    DsInit();
    initRand();

    resetEnabled = 1;
    vs_main_saveGameClearData = 0;
}

static void sysReinit(void)
{
    int i;
    UNUSED RECT rect0;
    UNUSED RECT rect1 = { .x = 819, .y = 819, .w = 819, .h = 0 };
    RECT rect2 = { .x = 0, .y = 0, .w = 1024, .h = 512 };

    ResetCallback();
    ResetGraph(1);
    SetGraphDebug(0);
    ClearImage(&rect2, 0, 0, 0);
    DrawSync(0);
    displayLoadingScreen();
    SsUtReverbOn();
    InitGeom();
    DrawSyncCallback(gpuSyncVoidCallback);
    VSyncCallback(vSyncVoidCallback);
    vs_main_initHeap((void*)0x8010C000, 0xF2000);
    initCdQueue();
    diskReset();
    loadMenuSound();
    vs_main_resetPadAct();

    inGame = 0;

    unlockPadModeSwitch();

    for (i = 0; i < 32; ++i) {
        buttonHeldFrameCount[i] = 0;
    }

    vs_main_gametime.t.h = 0;
    vs_main_gametime.t.m = 0;
    vs_main_gametime.t.s = 0;
    vs_main_gametime.t.f = 0;
    vs_main_characterSnapshot.stats.restorePending = 0;
}

int vs_main_execTitle(void)
{
    vs_overlay_getSp(&savedSp);
    sysReinit();
    loadTitlePrg();

    vs_main_startState = vs_title_exec();
    vs_main_saveGameClearData = 0;

    displayLoadingScreen();
    loadBattlePrg();
    vs_overlay_getSp(&savedSp);

    inGame = 1;

    vs_battle_exec();
    SetDispMask(0);
    vs_main_stopMusic();

    return 0;
}

void vs_main_exec(void)
{
    __main();
    sysInit();
    vs_overlay_getSp(&sp2);
    vs_main_execTitle();
}

void vs_main_wait(void) { vs_overlay_wait(); }

void vs_main_enableReset(int enable) { resetEnabled = enable; }

void vs_main_setCharacterRestorePending(void)
{
    vs_main_characterSnapshot.stats.restorePending = 1;
}

void vs_main_captureSaveState(void)
{
    vs_ActorPosition position;
    int i;
    int actionByte;
    vs_ActorStats const* stats;
    vs_CharacterSnapshot* snapshot;

    vs_main_spawnPoint = vs_battle_spawnPoint;

    func_800A1108(0, &position);

    vs_main_spawnPoint.x = position.unk0.unk0.x;
    vs_main_spawnPoint.z = position.unk0.unk0.z;
    vs_main_spawnPoint.targetTile.arrivalSurface = position.unk0.unk0.surface;
    vs_main_spawnPoint.facing = position.unk0.unk0.status >> 6;
    // On a saved spawn point this field holds the scene id, not an unlock flag.
    vs_main_spawnPoint.unlockFlag = D_800F18E8.unk0_0;

    for (actionByte = 0; actionByte < 256 / CHAR_BIT; ++actionByte) {
        u_char actionsLearned = 0;

        for (i = 0; i < CHAR_BIT; ++i) {
            actionsLearned = (actionsLearned << 1)
                           | vs_main_actions[actionByte * CHAR_BIT + i].unlocked;
        }
        vs_main_actionsLearned[actionByte] = actionsLearned;
    }

    stats = vs_battle_characterState->stats;
    snapshot = &vs_main_characterSnapshot;
    snapshot->stats.currentHP = stats->currentHP;
    snapshot->stats.maxHP = stats->maxHP;
    snapshot->stats.currentMP = stats->currentMP;
    snapshot->stats.maxMP = stats->maxMP;
    snapshot->stats.strength = stats->strength;
    snapshot->stats.totalStrength = stats->totalStrength;
    snapshot->stats.intelligence = stats->intelligence;
    snapshot->stats.totalIntelligence = stats->totalIntelligence;
    snapshot->stats.agility = stats->agility;
    snapshot->stats.totalAgility = stats->totalAgility;
    snapshot->stats.risk = stats->risk;
    snapshot->stats.actionDelay = stats->actionDelay;
    snapshot->stats.statuses = stats->statuses;

    for (i = 0; i < 8; ++i) {
        snapshot->stats.statusTimers[i] = stats->statusTimers[i];
    }

    for (i = 0; i < 6; ++i) {

        int j;

        snapshot->stats.limbs[i].hp = stats->limbs[i].hp;
        snapshot->stats.limbs[i].maxHp = stats->limbs[i].maxHp;

        for (j = 0; j < 4; ++j) {
            snapshot->stats.limbs[i].types[j] = stats->limbs[i].types[j];
        }

        for (j = 0; j < 8; ++j) {
            snapshot->stats.limbs[i].affinities[j] = stats->limbs[i].affinities[j];
        }
    }

    snapshot->stats.weaponDrawn = vs_battle_characterState->weaponDrawn;
    snapshot->stats.cameraPitch = vs_battle_cameraCurrentSpherical.delta.pitch;
    snapshot->stats.cameraDistance = vs_battle_cameraCurrentSpherical.initialDistance;

    for (actionByte = 0; actionByte < 16; ++actionByte) {
        vs_battle_saveEnemyState(actionByte, 0);
    }

    vs_battle_setDoorEntered();
}

void vs_main_padDisconnectAll(void)
{
    vs_main_portInfo[0].connected = 0;
    vs_main_portInfo[1].connected = 0;
}

static void unlockPadModeSwitch(void)
{
    vs_main_padDisconnectAll();

    if (PadInfoMode(0, InfoModeCurExID, 0) != 0) {
        PadSetMainMode(0, 1, 2);
    }
}

static void padResetDefaults(int portID, UNUSED void const* _)
{
    PortInfo* port = &vs_main_portInfo[portID >> 4];

    port->exId = PadInfoMode(portID, InfoModeCurExID, 0);

    if (port->exId) {
        port->actData[0] = 0;
        port->actData[1] = 0;
        port->lock = 2;

        PadSetMainMode(portID, PadInfoMode(portID, InfoModeCurExOffs, 0), port->lock);
    } else {
        port->actData[0] = 0x40;
        port->actData[1] = 0;
    }

    PadSetAct(portID, port->actData, sizeof port->actData);
    PadSetActAlign(portID, actParams);
}

u_int vs_main_updatePadState(int portID, char const padBuf[34])
{
    PortInfo* port;
    char mode;
    int btnStates;

    if (padBuf[0] != 0) {
        port = &vs_main_portInfo[portID >> 4];
        port->lStickY = 128;
        port->lStickX = 128;
        port->rStickY = 128;
        port->rStickX = 128;

        return 0;
    }

    port = &vs_main_portInfo[portID >> 4];
    mode = PadInfoMode(portID, InfoModeCurID, 0);
    port->mode = mode;

    switch (mode) {
    case 1:
    case 2:
    case 3:
    case 6:
        btnStates = 0;
        break;

    default:
        btnStates = ~((padBuf[2] << 8) | padBuf[3]);
        break;
    }

    port->mode = PadInfoMode(portID, InfoModeCurID, 0);

    if ((port->mode == 5) || (port->mode == 7)) {
        port->rStickX = padBuf[6];
        port->rStickY = padBuf[7];
        port->lStickX = padBuf[4];
        port->lStickY = padBuf[5];
    } else {
        port->lStickY = 128;
        port->lStickX = 128;
        port->rStickY = 128;
        port->rStickX = 128;
    }
    port->states = btnStates;

    return btnStates;
}

void vs_main_padConnect(int portID, char const padBuf[34])
{
    UNUSED int dummy[5];

    PortInfo* port = &vs_main_portInfo[portID >> 4];
    int state = PadGetState(portID);

    if (state == PadStateFindPad) {
        port->connected = 0;
    }

    if (port->connected != 0) {
        return;
    }

    PadSetAct(portID, port->actData, sizeof port->actData);

    if ((state == PadStateFindCTP1)
        || ((state == PadStateStable) && (PadSetActAlign(portID, actParams) != 0))) {

        padResetDefaults(portID, padBuf);

        port->connected = 1;
    }
}

static void padSetActData(int port, int pos, int val)
{
    if (pos != 0) {
        vs_main_portInfo[port].actData[pos] = val;
    } else if (vs_main_portInfo[port].exId) {
        vs_main_portInfo[port].actData[0] = val;
    } else {
        vs_main_portInfo[port].actData[0] = 0x40;
    }
}

static UNUSED char padGetActData(int port, int pos)
{
    return vs_main_portInfo[port].actData[pos];
}

int vs_main_setVibrationBank(char const* script, u_int requestedSlot, int id)
{
    int i;
    int slot = 0;

    if (requestedSlot == 0xFF) {
        for (i = 0; i < 2; ++i) {
            if (padAct.port[i].active == 0) {
                slot = i + 1;
                break;
            }
        }
    } else if ((requestedSlot - 1) < 2) {
        slot = requestedSlot;
    }

    if (slot != 0) {
        i = slot - 1;
        padAct.port[i].script = script;
        padAct.port[i].motors[0].scriptPos = 1;
        padAct.port[i].motors[1].scriptPos = *script;
        padAct.port[i].motors[1].framesLeft = 0;
        padAct.port[i].motors[0].framesLeft = 0;
        padAct.port[i].motors[1].value = 0;
        padAct.port[i].motors[0].value = 0;
        padAct.port[i].active = 1;
        padAct.port[i].id = id;

        return slot;
    }

    return 0;
}

static int clearVibrationSlot(int slot)
{
    int i = slot - 1;
    padAct.port[i].motors[1].value = 0;
    padAct.port[i].motors[0].value = 0;
    padAct.port[i].script = 0;
    padAct.port[i].active = 0;

    return slot;
}

int vs_main_stopVibration(u_int slot, int id)
{
    int i;

    if (slot - 1 < 2) {
        return clearVibrationSlot(slot);
    }

    if (slot != 0) {
        return 0;
    }

    if (id != 0) {
        for (i = 0; i < 2; ++i) {
            if (padAct.port[i].id == id) {
                clearVibrationSlot(i + 1);
            }
        }
    } else {
        for (i = 0; i < 2; ++i) {
            clearVibrationSlot(i + 1);
        }
    }

    return 1;
}

static int pauseVibrationSlot(int slot)
{
    int i = slot - 1;
    padAct.port[i].active = 0;

    return slot;
}

static UNUSED int pauseVibration(int slot)
{
    int i;

    if ((slot - 1u) < 2) {
        return pauseVibrationSlot(slot);
    }

    if (slot != 0) {
        return 0;
    }

    for (i = 0; i < 2;) {
        pauseVibrationSlot(++i);
    }

    return 1;
}

static int resumeVibrationSlot(int slot)
{
    int i = slot - 1;
    padAct.port[i].active = 1;

    return slot;
}

static UNUSED int resumeVibration(int slot)
{
    int i;

    if ((slot - 1u) < 2) {
        return resumeVibrationSlot(slot);
    }

    if (slot != 0) {
        return 0;
    }

    for (i = 0; i < 2;) {
        resumeVibrationSlot(++i);
    }

    return 1;
}

void vs_main_resetPadAct(void)
{
    int i;

    vs_main_padDisconnectAll();

    for (i = 0; i < 2; ++i) {
        padAct.port[i].script = NULL;
        padAct.port[i].motors[1].value = 0;
        padAct.port[i].motors[0].value = 0;
        padAct.port[i].active = 0;
    }
}

void vs_main_setVibrateParams(void)
{
    int j;

    padAct.strength[1] = 0;
    padAct.strength[0] = 0;

    for (j = 0; j < 2; ++j) {

        char const* script;

        if (padAct.port[j].active == 0) {
            continue;
        }

        script = padAct.port[j].script;

        if (script != 0) {
            int i;

            for (i = 0; i < 2; ++i) {

                PadMotor* motors = padAct.port[j].motors;

                if (motors[i].framesLeft == 0) {

                    int pos = motors[i].scriptPos;

                    motors[i].framesLeft = script[pos++];
                    motors[i].value = motors[i].target = script[pos++] << 8;

                    if (motors[i].framesLeft == 0) {
                        motors[i].value = 0;
                        motors[i].active = 0;
                    } else {
                        motors[i].target = script[pos + 1] << 8;
                        motors[i].step = i != 0 ? (motors[i].target - motors[i].value)
                                                      / motors[i].framesLeft
                                                : 0;
                        motors[i].active = 1;
                        motors[i].scriptPos += 2;
                    }
                }

                if (motors[i].framesLeft != 0) {
                    motors[i].value += motors[i].step;
                    motors[i].framesLeft -= 1;
                } else {
                    motors[i].value = motors[i].target;
                }

                padAct.strength[i] += motors[i].value;

                if (padAct.strength[i] > 0xFF00) {
                    padAct.strength[i] = 0xFF00;
                } else if (padAct.strength[i] < 0) {
                    padAct.strength[i] = 0;
                }
            }

            padAct.port[j].active =
                padAct.port[j].motors[0].active | padAct.port[j].motors[1].active;

            if (padAct.port[j].active == 0) {
                padAct.port[j].script = 0;
            }
        } else {
            padAct.port[j].active = 0;
        }
    }

    if (vs_main_settings.vibrationOn != 0) {
        padSetActData(0, 0, padAct.strength[0] / 256);
        padSetActData(0, 1, padAct.strength[1] / 256);
    }
}

void vs_main_vibrationOnEffect(int effect)
{
    if (effect < vibrationOnBank[0]) {
        vs_main_setVibrationBank(
            &vibrationOnBank[vibrationOnBank[effect * 4 + 4]
                             + (vibrationOnBank[effect * 4 + 5] << 8)
                             + (vibrationOnBank[effect * 4 + 6] << 16)
                             + (vibrationOnBank[effect * 4 + 7] << 24)],
            0xFF, 0x80);
    }
}

int vs_main_processPadState(void)
{
    UNUSED int _[2];
    int i;
    u_int btnState;

    vs_main_buttonsState = vs_main_updatePadState(0, vs_main_padBuffer[0]) & 0xFFFF;
    vs_main_buttonsState |= vs_main_updatePadState(16, vs_main_padBuffer[1]) << 16;
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(16, vs_main_padBuffer[1]);

    switch (vs_main_portInfo[0].mode) {
    case 4:
        vs_main_stickPosBuf.lStickY = 128;
        vs_main_stickPosBuf.lStickX = 128;
        vs_main_stickPosBuf.rStickY = 128;
        vs_main_stickPosBuf.rStickX = 128;
        break;

    case 7:
        vs_main_stickPosBuf.rStickX = vs_main_portInfo[0].rStickX;
        vs_main_stickPosBuf.rStickY = vs_main_portInfo[0].rStickY;
        vs_main_stickPosBuf.lStickX = vs_main_portInfo[0].lStickX;
        vs_main_stickPosBuf.lStickY = vs_main_portInfo[0].lStickY;

        if (vs_main_portInfo[0].rStickX < 16) {
            vs_main_buttonsState |= PADLleft;
        }

        if (vs_main_portInfo[0].rStickX >= 241) {
            vs_main_buttonsState |= PADLright;
        }

        if (vs_main_portInfo[0].rStickY < 16) {
            vs_main_buttonsState |= PADLup;
        }

        if (vs_main_portInfo[0].rStickY >= 241) {
            vs_main_buttonsState |= PADLdown;
        }

        if (vs_main_portInfo[0].lStickX < 32) {
            vs_main_buttonsState |= PADj;
        }

        if (vs_main_portInfo[0].lStickX >= 225) {
            vs_main_buttonsState |= PADj;
        }

        if (vs_main_portInfo[0].lStickY < 32) {
            vs_main_buttonsState |= PADj;
        }

        if (vs_main_portInfo[0].lStickY >= 225) {
            vs_main_buttonsState |= PADj;
        }

        break;

    default:
        vs_main_stickPosBuf.lStickY = 128;
        vs_main_stickPosBuf.lStickX = 128;
        vs_main_stickPosBuf.rStickY = 128;
        vs_main_stickPosBuf.rStickX = 128;
        break;
    }

    vs_main_buttonsPressed.all = ~vs_main_buttonsPreviousState & vs_main_buttonsState;
    vs_main_buttonsReleased = vs_main_buttonsPreviousState & ~vs_main_buttonsState;
    vs_main_buttonsPreviousState = vs_main_buttonsState;

    btnState = vs_main_buttonsState;

    for (i = 0; i < 32; ++i, btnState >>= 1) {
        if (btnState & 1) {
            buttonHeldFrameCount[i] += vs_gametime_tickspeed;
        } else {
            buttonHeldFrameCount[i] = 0;
        }
    }

    vs_main_buttonRepeat = vs_main_buttonsPressed.all;

    for (i = 0; i < 32; ++i) {
        if ((buttonHeldFrameCount[i] >= 20) && !((buttonHeldFrameCount[i] - 20) & 3)) {
            vs_main_buttonRepeat |= 1 << i;
        }
    }

#define VS_RESET (PADstart | PADselect | PADR1 | PADR2 | PADL1 | PADL2)

    if ((resetEnabled != 0) && ((vs_main_buttonsPreviousState & VS_RESET) == VS_RESET)
        && (vs_main_buttonsPressed.all & VS_RESET)) {
        vs_main_settings.monoSound = 0;
        vs_main_settings.vibrationOn = 1;
        vs_main_resetGame();
    }

#undef VS_RESET

    return 1;
}

static inline void insertFreeBlock(
    vs_Main_HeapHeader* freeNode, vs_Main_HeapHeader* target)
{
    if ((target + target->blockSz) == freeNode->next) {
        target->blockSz += freeNode->next->blockSz;
        target->next = freeNode->next->next;
        target->next->prev = target;
    } else {
        target->next = freeNode->next;
        target->next->prev = target;
    }

    if ((freeNode + freeNode->blockSz) == target) {
        freeNode->blockSz += target->blockSz;
        freeNode->next = target->next;
        freeNode->next->prev = freeNode;
        return;
    }

    freeNode->next = target;
    target->prev = freeNode;
}

void vs_main_freeHeapR(void* block)
{
    vs_Main_HeapHeader* freeNode = heapList.prev;
    vs_Main_HeapHeader* target = (vs_Main_HeapHeader*)block - 1;

    for (; freeNode >= target || target >= freeNode->next; freeNode = freeNode->prev) {
        if (freeNode >= freeNode->next
            && ((freeNode < target) || (target < freeNode->next))) {
            break;
        }
    }

    insertFreeBlock(freeNode, target);
}

void vs_main_freeHeap(void* block)
{
    vs_Main_HeapHeader* freeNode = heapList.next;
    vs_Main_HeapHeader* target = (vs_Main_HeapHeader*)block - 1;

    for (; freeNode >= target || target >= freeNode->next; freeNode = freeNode->next) {
        if (freeNode >= freeNode->next
            && ((freeNode < target) || (target < freeNode->next))) {
            break;
        }
    }

    insertFreeBlock(freeNode, target);
}

void* vs_main_allocHeapR(u_int size)
{
    u_int blockSz = ((size + 15) >> 4) + 1;
    vs_Main_HeapHeader* lastNode = &heapList;
    vs_Main_HeapHeader* freeNode = heapList.prev;

    while (1) {
        if (freeNode->blockSz >= blockSz) {

            if (freeNode->blockSz == blockSz) {
                lastNode->prev = freeNode->prev;
                freeNode->prev->next = freeNode->next;
            } else {
                freeNode->blockSz = freeNode->blockSz - blockSz;
                freeNode += freeNode->blockSz;
                freeNode->blockSz = blockSz;
            }

            return freeNode + 1;
        }

        lastNode = freeNode;

        if (freeNode == &heapList) {
            return 0;
        }

        freeNode = freeNode->prev;
    }
}

void* vs_main_allocHeap(u_int size)
{
    vs_Main_HeapHeader* lastNode = &heapList;
    vs_Main_HeapHeader* freeNode = heapList.next;
    u_int blockSz = ((size + 0xF) >> 4) + 1;

    while (1) {
        if (freeNode->blockSz >= blockSz) {

            if (freeNode->blockSz == blockSz) {
                lastNode->next = freeNode->next;
                freeNode->next->prev = freeNode->prev;
            } else {
                vs_Main_HeapHeader* remainder = freeNode + blockSz;
                remainder->blockSz = freeNode->blockSz - blockSz;
                remainder->prev = freeNode->prev;
                remainder->next = freeNode->next;
                remainder->prev->next = remainder;
                remainder->next->prev = remainder;
                freeNode->blockSz = blockSz;
            }

            return freeNode + 1;
        }

        lastNode = freeNode;

        if (freeNode == &heapList) {
            return 0;
        }

        freeNode = freeNode->next;
    }
}

void vs_main_initHeap(void* heap, u_int size)
{
    vs_Main_HeapHeader* node = heap;

    heapList.prev = node;
    heapList.next = node;
    heapList.blockSz = 0;
    node->prev = &heapList;
    node->next = &heapList;
    node->blockSz = size / 16 - 1;
    unusedHeap.prev = &unusedHeap;
    unusedHeap.next = &unusedHeap;
    unusedHeap.blockSz = 0;
}

static void diskReadCallback(u_char intr, UNUSED u_char result[], UNUSED u_long* _)
{
    if ((intr == DslDiskError) || (intr == DslNoIntr) || (disk.state == diskReadError)) {
        DsReadyCallback(0);
        DsEndReadySystem();

        disk.state = diskReadError;

        return;
    }

    if (intr != DslDataReady) {
        return;
    }

    disk.state = diskReadReady;

    if (disk.bufferMode == cdBufferModeNone) {
        DsGetSector(disk.vram + disk.sectorBufIndex * SECTOR_BYTES, SECTOR_SIZE);
    } else {
        DsGetSector(cdReadBuffer + disk.ringWriteIndex * SECTOR_BYTES, SECTOR_SIZE);

        if (++disk.ringWriteIndex >= 16) {
            disk.ringWriteIndex = 0;
        }
    }

    switch (disk.bufferMode) {
    case cdBufferModeNone:
        if (++disk.sectorBufIndex >= disk.sectorsRequested) {
            disk.state = diskIdle;
        }
        break;

    case cdBufferModeBuffered:
        ++disk.sectorsReceived;
        ++disk.sectorsPending;
        break;

    case cdBufferModeManual:
        ++disk.sectorsReceived;

        if (++disk.ringBufIndex >= 16) {
            disk.ringBufIndex = 0;
        }

        break;

    default:
        break;
    }

    if (++disk.sectorsFetched >= disk.sectorsRequested) {
        DsEndReadySystem();
    }
}

static void diskReadCommandCallback(u_char intr, UNUSED u_char result[])
{
    switch (intr) {
    case DslComplete:
        DsStartReadySystem(diskReadCallback, -1);
        return;

    case DslDiskError:
        break;

    default:
        break;

    case DslNoResult:
    case DslNoIntr:
        return;
    }

    disk.state = diskReadError;
}

static void diskSeekCommandCallback(u_char intr, UNUSED u_char result[])
{
    switch (intr) {
    case DslNoIntr:
        break;

    case DslComplete:
        disk.state = diskIdle;
        break;

    case DslDiskError:
        disk.state = diskReadError;
        break;

    case DslNoResult:
        break;

    default:
        disk.state = diskReadError;
        break;
    }
}

static void diskPcmReadReady(u_char intr, u_char result[])
{
    switch (intr) {
    case DslComplete:
        DsReadyCallback(NULL);
        disk.state = diskIdle;
        break;

    case DslDataReady:
        if (!(result[4] & 0x80)) {
            cdaTrack = ((result[1] >> 4) * 10) + (result[1] & 0xF);
            cdaMinute = result[3];
            cdaSecond = result[4];
            cdaPeak = (result[6] << 8) | result[7];
        }

        break;

    case DslDiskError:
        DsReadyCallback(NULL);
        disk.state = diskCommandFailed;

        break;

    default:
        break;
    }
}

static int diskGetState(void) { return disk.state; }

static UNUSED void diskClearError(void)
{
    if (disk.state == diskReadError) {
        disk.state = diskIdle;
    }
}

static inline void diskResetReadState(void)
{
    disk.ringBufIndex = 0;
    disk.ringWriteIndex = 0;
    disk.sectorBufIndex = 0;
    disk.sectorsPending = 0;
    disk.sectorsFetched = 0;
    disk.errorCount = 0;
    disk.sectorsReceived = 0;
}

static int diskInitRead(int sector, u_int bytes, void* vram)
{
    if (disk.state == diskIdle) {

        disk.cdSector = sector;
        disk.request.byteCount = bytes;
        disk.vram = vram;

        diskResetReadState();

        disk.sectorsRequested = bytes / SECTOR_BYTES;

        if (bytes % SECTOR_BYTES) {
            ++disk.sectorsRequested;
        }

        DsIntToPos(sector, &disk.cd.loc);

        disk.state = diskReadInit;

        return 1;
    }

    return 0;
}

static void diskUpdate(void)
{
    DslATV vol;
    int i;

    switch (disk.state) {
    case diskIdle:
    default:
        break;

    case diskReadXaInit:
        if (DsSystemStatus() == DslReady) {

            disk.mode = 0;
            disk.cd.mode = 0;

            while (DsControlB(DslSetmode, &disk.cd.mode, NULL) == 0)
                ;

            VSync(3);

            vol.val2 = 0x80;
            vol.val0 = 0x80;
            vol.val3 = 0;
            vol.val1 = 0;

            DsMix(&vol);
            Sound_SetCdVolume(disk.request.cdVolume);
            Sound_SetCdMixVolume(0x7F);

            disk.pcm.file = 1;
            disk.pcm.chan = 0;

            DsControl(DslSetfilter, (char*)&disk.pcm, NULL);
            DsIntToPos(disk.cdSector, &disk.cd.loc);

            disk.commandId =
                DsPacket(DslModeRT | DslModeSF, &disk.cd.loc, DslReadS, NULL, -1);
            DsReadyCallback(diskPcmReadReady);

            disk.state = diskStreamXa;
        }

        if (disk.commandId == 0) {
            DsReadyCallback(0);
            disk.state = diskCommandFailed;

            ++disk.errorCount;
        }
        break;

    case diskReadInit: {

        int status = DsSystemStatus();

        if (status == DslReady) {

            disk.sectorsFetched = 0;
            disk.sectorBufIndex = 0;

            if (disk.request.byteCount != 0) {
                disk.state = diskReadReady;
                disk.commandId = DsPacket(DslModeSpeed | DslModeSize1, &disk.cd.loc,
                    DslReadN, diskReadCommandCallback, -1);
            } else {
                disk.state = diskSeekReady;
                disk.commandId = DsPacket(DslModeSpeed | DslModeSize1, &disk.cd.loc,
                    DslSeekL, diskSeekCommandCallback, -1);
            }

            if (disk.commandId == 0) {
                disk.state = diskReadError;
                ++disk.errorCount;
            }
        }
        break;
    }

    case diskCommandFailed: {

        int status = DsSystemStatus();

        if (status == DslReady) {

            u_int seconds;

            disk.sectorsFetched = 0;
            ++disk.errorCount;
            seconds = vs_main_frameDuration / 60;

            if (seconds < 420) {
                DsIntToPos(disk.cdSector + (seconds * 75) + (vs_main_frameDuration % 60),
                    &cdReadLoc);

                vol.val2 = 0x80;
                vol.val0 = 0x80;
                vol.val3 = 0;
                vol.val1 = 0;

                DsMix(&vol);
                Sound_SetCdVolume(0);
                Sound_FadeCdVolume(0x3C, disk.request.cdVolume);

                disk.pcm.file = 1;
                disk.pcm.chan = 0;

                DsControl(DslSetfilter, (char*)&disk.pcm, NULL);
                disk.commandId =
                    DsPacket(DslModeRT | DslModeSF, &cdReadLoc, DslReadS, NULL, -1);
                DsReadyCallback(diskPcmReadReady);

                disk.state = diskStreamXa;

            } else {
                disk.commandId = DsCommand(DslModeSF | DslModeDA, NULL, NULL, -1);
                disk.state = diskIdle;

                DsReadyCallback(0);
            }
        }

        if (disk.commandId == 0) {
            disk.state = diskCommandFailed;
            ++disk.errorCount;
        }

        break;
    }

    case diskReadError: {

        int status = DsSystemStatus();

        if (status == DslReady) {

            disk.sectorsFetched = 0;
            disk.sectorBufIndex = 0;
            ++disk.errorCount;

            if (disk.request.byteCount != 0) {
                disk.state = diskReadReady;
                disk.commandId = DsPacket(DslModeSpeed | DslModeSize1, &disk.cd.loc,
                    DslReadN, diskReadCommandCallback, -1);
            } else {
                disk.state = diskSeekReady;
                disk.commandId = DsPacket(DslModeSpeed | DslModeSize1, &disk.cd.loc,
                    DslSeekL, diskSeekCommandCallback, -1);
            }

            if (disk.commandId == 0) {
                disk.state = diskReadError;
                ++disk.errorCount;
            }
        }
        break;
    }

    case diskStreamXaEnd:
        Sound_SetCdVolume(0);

        disk.commandId = DsCommand(DslPause, NULL, NULL, -1);

        if (disk.commandId > 0) {
            disk.state = diskIdle;
        }

        DsReadyCallback(NULL);

        disk.mode = 128;
        disk.cd.mode = 128;

        while (DsControlB(DslSetmode, &disk.cd.mode, NULL) == 0)
            ;

        VSync(3);

        break;
    }

    if (disk.bufferMode == cdBufferModeNone) {
        return;
    }

    for (i = 0; i < 16; ++i) {

        if (disk.sectorBufIndex >= disk.sectorsReceived) {
            return;
        }

        if (disk.bufferMode == cdBufferModeBuffered) {

            vs_main_memcpy(((char*)disk.vram + (disk.sectorBufIndex * SECTOR_BYTES)),
                cdReadBuffer + (disk.ringBufIndex * SECTOR_BYTES), SECTOR_BYTES);

            ++disk.ringBufIndex;

            if (disk.ringBufIndex >= 16) {
                disk.ringBufIndex = 0;
            }

            --disk.sectorsPending;
            ++disk.sectorBufIndex;

            if (disk.sectorBufIndex >= disk.sectorsRequested) {
                disk.state = diskIdle;

                vs_main_freeHeapR(cdReadBuffer);

                cdReadBuffer = NULL;
            }
        } else if (disk.bufferMode == cdBufferModeManual) {

            ++disk.sectorBufIndex;

            if ((disk.sectorBufIndex >= disk.sectorsRequested)
                && (IsSpuTransferring() == 0)) {

                disk.state = diskIdle;

                vs_main_freeHeapR(cdReadBuffer);

                cdReadBuffer = NULL;
            }
        }
    }
}

int vs_main_diskLoadFile(int sector, u_int bytes, void* vram)
{
    int result = diskInitRead(sector, bytes, vram);

    if (result != 0) {
        while (diskGetState() == diskSeekReady || diskGetState() == diskReadReady
               || diskGetState() == diskUnused3 || diskGetState() == diskReadInit) {
            vs_main_gametimeUpdate(0);
        }
    }

    return result;
}

int vs_main_streamXa(int sector, int cdVolume)
{
    if (disk.state == diskIdle) {

        disk.cdSector = sector;
        disk.request.cdVolume = cdVolume;

        diskResetReadState();

        disk.state = diskReadXaInit;

        return 1;
    }

    return 0;
}

int vs_main_checkStreamXaEnd(void)
{
    if (disk.state == diskStreamXa) {
        disk.state = diskStreamXaEnd;
        return 1;
    }

    return 0;
}

static void diskReset(void)
{
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();

    disk.mode = 128;
    disk.cd.mode = 128;
    disk._0 = 0;
    disk.state = diskIdle;
    disk.bufferMode = cdBufferModeNone;
    cdReadBuffer = NULL;

    while (DsControlB(DslSetmode, &disk.cd.mode, NULL) == 0)
        ;

    VSync(3);
}

static void initCdQueue(void)
{
    int i;

    for (i = 31; i >= 0; --i) {
        cdQueue[i].state = vs_main_CdQueueStateFree;
    }

    cdQueueCount = (CdQueueCount) { 0, 0 };
}

vs_Main_CdQueueSlot* vs_main_allocateCdQueueSlot(vs_Main_CdFile const* file)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (cdQueue[i].state == vs_main_CdQueueStateFree) {
            cdQueue[i].state = vs_main_CdQueueStateAllocated;
            cdQueue[i].cdFile = *file;
            return &cdQueue[i];
        }
    }

    vs_main_nop9(162, 0);
}

void vs_main_freeCdQueueSlot(vs_Main_CdQueueSlot* slot)
{
    u_short state = slot->state - 2;

    if (state < vs_main_CdQueueStateLoaded - 2) {
        vs_main_nop9(163, 0);
    }

    slot->state = vs_main_CdQueueStateFree;
}

void vs_main_cdEnqueue(vs_Main_CdQueueSlot* slot, void* vram)
{
    slot->state = vs_main_CdQueueStateEnqueued;
    slot->vram = vram;
    slot->unused = 0;
    slot->priority = cdQueueCount.queued++;
}

void vs_main_cdEnqueuePriority(vs_Main_CdQueueSlot* slot, void* vram)
{
    int i;
    vs_Main_CdQueueSlot* queue = cdQueue;

    for (i = 0; i < 32; ++i, ++queue) {
        if (queue->state == vs_main_CdQueueStateEnqueued) {
            ++queue->priority;
        }
    }

    slot->state = vs_main_CdQueueStateEnqueued;
    slot->vram = vram;
    slot->unused = 0;
    slot->priority = 0;
    ++cdQueueCount.queued;
}

static UNUSED void nop4(void) { }

static void processCdQueue(void)
{
    ++disk.framesSinceLastRead;

    if (cdQueueCount.processing || cdQueueCount.queued) {

        vs_Main_CdQueueSlot* slot = cdQueue;

        int i = diskGetState();

        if (i == diskIdle) {

            for (i = 0; i < 32; ++i, ++slot) {
                if (slot->state == vs_main_CdQueueStateEnqueued) {
                    if (slot->priority == 0) {

                        slot->state = vs_main_CdQueueStateReading;

                        diskInitRead(slot->cdFile.lba, slot->cdFile.size, slot->vram);

                        disk.framesSinceLastRead = 0;
                        --cdQueueCount.queued;
                        ++cdQueueCount.processing;
                    } else {
                        --slot->priority;
                    }

                } else if (slot->state == vs_main_CdQueueStateReading) {
                    slot->state = vs_main_CdQueueStateLoaded;
                    --cdQueueCount.processing;
                }
            }
        }
    }

    diskUpdate();
}

int vs_main_getMusicPosition(void) { return Sound_GetMusicPosition(); }

void vs_main_pushMusicState(void) { Sound_PushMusicState(); }

void vs_main_setMusicJumpThreshold(int threshold)
{
    Sound_SetMusicJumpThreshold(threshold);
}

int vs_main_stopMusicSlot(int slot)
{
    int i;

    if (slot != 0) {
        if (vs_main_soundData.musicHandleBySlot[slot - 1] != 0xFFFF) {

            Sound_StopMusicById(vs_main_soundData.musicHandleBySlot[slot - 1]);

            vs_main_soundData.musicHandleBySlot[slot - 1] = 0xFFFF;
        }

        if (vs_main_soundData.currentMusicSlot == slot) {
            vs_main_soundData.currentMusicSlot = 0;
            vs_main_soundData.currentMusicData = NULL;
            vs_main_soundData.currentMusicHandle = 0xFFFF;
        }

        return 1;
    }

    Sound_StopMusic();

    vs_main_soundData.currentMusicSlot = 0;
    vs_main_soundData.currentMusicData = NULL;
    vs_main_soundData.currentMusicHandle = 0xFFFF;

    for (i = 0; i < 4; ++i) {
        vs_main_soundData.musicHandleBySlot[i] = 0xFFFF;
    }

    return 1;
}

int vs_main_queueMusicSlot(int slot)
{
    if (slot != 0) {
        if (vs_main_soundData.musicData[slot - 1] != 0) {

            u_int handle;

            vs_main_soundData.currentMusicSlot = slot;
            vs_main_soundData.currentMusicData = vs_main_soundData.musicData[slot - 1];
            handle = Sound_QueueMusic(vs_main_soundData.currentMusicData);

            if (handle != 0) {
                vs_main_soundData.musicHandleBySlot[slot - 1] = handle;
                vs_main_soundData.currentMusicHandle = handle;
            }

            vs_main_soundData.unk8 = vs_main_soundData.musicIds[slot - 1];
        }

        return vs_main_soundData.currentMusicHandle;
    }

    return 0;
}

int vs_main_playMusicSlotFadeIn(int slot, int volume, u_int duration)
{
    if (slot != 0) {

        if (vs_main_soundData.musicData[slot - 1] != 0) {
            u_int handle;

            vs_main_soundData.currentMusicSlot = slot;
            vs_main_soundData.currentMusicData = vs_main_soundData.musicData[slot - 1];

            handle = Sound_StartMasterAndMusicVolumeFade(
                vs_main_soundData.currentMusicData, duration, volume);

            if (handle != 0) {
                vs_main_soundData.musicHandleBySlot[slot - 1] = handle;
                vs_main_soundData.currentMusicHandle = handle;
            }

            vs_main_soundData.unk8 = vs_main_soundData.musicIds[slot - 1];
        }

        return vs_main_soundData.currentMusicHandle;
    }

    return 0;
}

int vs_main_playMusicSlot(int slot, int volume, int duration)
{
    if (slot != 0) {
        if (vs_main_soundData.musicData[slot - 1] != 0) {
            u_int handle;

            vs_main_soundData.currentMusicSlot = slot;
            vs_main_soundData.currentMusicData = vs_main_soundData.musicData[slot - 1];

            Sound_FadeMasterVolumeByMusicId(0, duration, volume);
            handle = Sound_StartFieldMusic(vs_main_soundData.currentMusicData);

            if (handle != 0) {
                vs_main_soundData.musicHandleBySlot[slot - 1] = handle;
                vs_main_soundData.currentMusicHandle = handle;
                Sound_FadeMasterVolumeByMusicId(0, duration, volume);
            }

            vs_main_soundData.unk8 = vs_main_soundData.musicIds[slot - 1];
        }

        return vs_main_soundData.currentMusicHandle;
    }

    return 0;
}

static UNUSED int vs_main_getcurrentMusicSlot(void)
{
    return vs_main_soundData.currentMusicSlot;
}

int vs_main_getCurrentMusicId(void)
{
    if (vs_main_soundData.currentMusicSlot != 0) {
        return vs_main_soundData.musicIds[vs_main_soundData.currentMusicSlot - 1];
    }
    return 0;
}

int vs_main_loadMusicSlot(int id, int targetSlot)
{
    if (id > 0 && targetSlot > 0) {
        int slot = targetSlot - 1;

        if (targetSlot < 5) {
            if (vs_main_soundData.musicIds[slot] != id) {

                vs_Main_CdFile cdFile;

                if (vs_main_soundData.musicData[slot] != 0) {
                    vs_main_nop10(142, 0);
                    vs_main_freeMusic(targetSlot);
                }

                cdFile.lba = musicLBAs[id];
                cdFile.size = musicFileSizes[id];

                if ((vs_main_soundData.musicQueueSlot[slot] != 0)
                    && (vs_main_soundData.musicQueueSlot[slot]
                        != (vs_Main_CdQueueSlot*)-1)) {
                    vs_main_nop9(0x98, 0);
                }

                vs_main_soundData.musicQueueSlot[slot] =
                    vs_main_allocateCdQueueSlot(&cdFile);

                if (vs_main_soundData.musicData[slot] != 0) {
                    vs_main_nop9(0x8E, 0);
                }

                vs_main_soundData.musicData[slot] = vs_main_allocHeapR(cdFile.size);
                vs_main_cdEnqueue(vs_main_soundData.musicQueueSlot[slot],
                    vs_main_soundData.musicData[slot]);

                vs_main_soundData.musicIds[slot] = id;
            }

            return targetSlot;
        }
    }

    vs_main_nop9(0x8E, 0);

    return 0;
}

static int loadMusicIntoFreeSlot(int id)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (vs_main_soundData.musicData[i] == 0) {
            return vs_main_loadMusicSlot(id, i + 1);
        }
    }

    return 0;
}

int vs_main_clearMusicLoadSlot(u_int slot)
{
    if ((slot - 1) < 4) {
        if (vs_main_soundData.musicQueueSlot[slot - 1] != 0) {

            if (vs_main_soundData.musicQueueSlot[slot - 1]->state
                == vs_main_CdQueueStateLoaded) {

                vs_main_freeCdQueueSlot(vs_main_soundData.musicQueueSlot[slot - 1]);
                vs_main_soundData.musicQueueSlot[slot - 1] = NULL;

                return 0;
            }

            if (vs_main_soundData.musicQueueSlot[slot - 1]->state
                == vs_main_CdQueueStateError) {

                vs_main_freeCdQueueSlot(vs_main_soundData.musicQueueSlot[slot - 1]);
                vs_main_soundData.musicQueueSlot[slot - 1] = (vs_Main_CdQueueSlot*)-1;

                return -1;
            }

            return 1;
        }
    }

    return 0;
}

int vs_main_clearMusicLoadQueue(void)
{
    int i;
    int ret = 0;

    for (i = 0; i < 4; ++i) {
        ret |= vs_main_clearMusicLoadSlot(i + 1);
    }

    return ret;
}

int vs_main_loadAndWaitMusicSlot(int id, int targetSlot)
{
    int ret = vs_main_loadMusicSlot(id, targetSlot);

    if (ret != 0) {
        while (vs_main_clearMusicLoadSlot(targetSlot) != 0) {
            vs_main_gametimeUpdate(0);
        }
    }

    return ret;
}

static UNUSED int loadMusicIntoFreeSlotAndClearQueue(int id)
{
    int ret = loadMusicIntoFreeSlot(id);

    if (ret != 0) {
        while (vs_main_clearMusicLoadQueue() != 0) {
            vs_main_gametimeUpdate(0);
        }
    }

    return ret;
}

int vs_main_freeMusic(int slotId)
{
    vs_main_stopMusicSlot(slotId);

    if (vs_main_soundData.musicData[slotId - 1] == 0) {
        return 0;
    }

    vs_main_freeHeapR(vs_main_soundData.musicData[slotId - 1]);

    vs_main_soundData.musicData[slotId - 1] = 0;
    vs_main_soundData.musicIds[slotId - 1] = 0;

    return 1;
}

static UNUSED int nop5(void) { return 0; }

int vs_main_getMusicSlotVolume(int slot)
{
    if (slot != 0) {
        if (vs_main_soundData.musicHandleBySlot[slot - 1] != 0xFFFF) {
            return Sound_GetMusicVolumeById(
                vs_main_soundData.musicHandleBySlot[slot - 1]);
        }
    }

    return 0;
}

int vs_main_getMusicSlotVolume2(int slot) { return vs_main_getMusicSlotVolume(slot); }

int vs_main_fadeMusicVolume(int slot, int volume, int duration)
{
    if (vs_main_soundData.currentMusicSlot == slot) {
        Sound_FadeMasterVolumeByMusicId(
            vs_main_soundData.currentMusicHandle, duration, volume);
        return 1;
    }

    return 0;
}

int vs_main_fadeMusicTempo(int slot, int tempo, int duration)
{
    if (vs_main_soundData.currentMusicSlot == slot) {
        Sound_FadeTempoScale(duration, tempo);
        return 1;
    }

    return 0;
}

int vs_main_fadeMusicPitch(int slot, int pitch, int duration)
{
    if (vs_main_soundData.currentMusicSlot == slot) {
        Sound_FadeMasterPitchScale(duration, pitch);
        return 1;
    }

    return 0;
}

static UNUSED int nop6(void) { return 0; }

static UNUSED int nop7(void) { return 0; }

void vs_main_stopMusic(void)
{
    int id = vs_main_soundData.currentMusicSlot;

    if (id != 0) {
        vs_main_stopMusicSlot(id);
        vs_main_freeMusic(id);
    }
}

static UNUSED void playSfxPool0Default(int id)
{
    Sound_PlaySfx(id & 0xFFFF, nextVoicePool0, 0x80, 0x7F);

    if (!((nextVoicePool0 *= 2) & 1)) {
        nextVoicePool0 = 1;
    }
}

static void playSfxById(int id, int voice, int pan, int volume)
{
    if (voice == 0x200) {
        if (id != Sound_GetPlayingSfxByGroup(0x200)) {
            Sound_PlaySfx(id, 0x200, pan, volume);
        }
    } else {
        Sound_PlaySfx(id, voice, pan, volume);
    }
}

static void playSfxFromPointer(void* data, int voice, int pan, int volume)
{
    if (voice == 0x200) {
        if (data != (void*)Sound_GetPlayingSfxByGroup(0x200)) {
            Sound_PlaySfxFromPointer(data, 0x200, pan, volume);
        }
    } else {
        Sound_PlaySfxFromPointer(data, voice, pan, volume);
    }
}

void vs_main_playSfx(int group, int id, int pan, int volume)
{
    void* sfx;
    int* bank;

    switch (group) {
    case 0x7E:
    case 0xFE:
        if (Sound_SfxHasVoiceFlag(id & 0xFFFF) != 0) {

            playSfxById(id & 0xFFFF, nextVoicePool1, pan, volume);

            nextVoicePool1 *= 2;

            if (!(nextVoicePool1 & 0x7E)) {
                nextVoicePool1 = 2;
            }

        } else {
            playSfxById(id & 0xFFFF, 0, pan, volume);
        }

        break;

    case 0x100:
    case 0x200:
        if (Sound_SfxHasVoiceFlag(id & 0xFFFF) != 0) {
            playSfxById(id & 0xFFFF, nextVoicePool3, pan, volume);
        } else {
            playSfxById(id & 0xFFFF, 0, pan, volume);
        }

        break;

    case 0xFF000:
        sfx = bank = vs_main_soundData.sfxData[vs_main_soundData.currentSfxId - 1];
        sfx += bank[id + 1];

        if (Sound_SfxHasVoiceFlag((u_long)sfx) != 0) {

            playSfxFromPointer(sfx, nextVoicePool4, pan, volume);

            nextVoicePool4 *= 2;

            if (!(nextVoicePool4 & group)) {
                nextVoicePool4 = 0x1000;
            }

        } else {
            playSfxFromPointer(sfx, 0, pan, volume);
        }

        break;

    case 0xF00000:
        sfx = bank = vs_main_soundData.sfxData[2];
        sfx += bank[id + 1];

        if (Sound_SfxHasVoiceFlag((u_long)sfx) != 0) {

            playSfxFromPointer(sfx, nextVoicePool5, pan, volume);

            nextVoicePool5 *= 2;

            if (!(nextVoicePool5 & group)) {
                nextVoicePool5 = 0x100000;
            }

        } else {
            playSfxFromPointer(sfx, 0, pan, volume);
        }

        break;

    default:
        vs_main_nop10(0x95, 0);
        break;
    }
}

void vs_main_playSfxDefault(int group, int id) { vs_main_playSfx(group, id, 0x80, 0x7F); }

int vs_main_computeSfxPan(int pan, int depth)
{
    int tmp = pan;
    int volume;
    int limit;

    if (pan < 0) {
        tmp += 0xFFFF;
    }

    tmp = (tmp >> 16) << 16;
    pan = (short)(pan - tmp) - 160;
    pan = (pan * 3) / 10;

    if (pan < -96) {
        pan = -96;
    }

    if (pan > 96) {
        pan = 96;
    }

    pan += 128;
    limit = depth - 768;

    if (limit < 0) {
        limit = 0;
    }

    if (limit > 4095) {
        limit = 4095;
    }

    tmp = limit;

    if (limit < 0) {
        tmp = limit + 31;
    }

    tmp >>= 5;
    limit = 127;

    volume = limit - tmp;
    return (pan << 16) + volume;
}

static void do_panSfx(int group, int id, int screenXY, int depth)
{
    int panAndVolume = vs_main_computeSfxPan(screenXY, depth);
    int pan = panAndVolume >> 16;
    int volume = panAndVolume & 0xFFFF;

    if (volume > 0) {
        vs_main_playSfx(group, id, pan, volume);
    }
}

void vs_main_panSfx(int group, int id, SVECTOR* position)
{
    int depth;
    long screenXY;
    long interpolation;
    long flag;

    SetRotMatrix(&vs_scratch.viewMatrix);
    SetTransMatrix(&vs_scratch.viewMatrix);
    depth = RotTransPers(position, &screenXY, &interpolation, &flag);
    do_panSfx(group, id, screenXY, depth);
}

// Returns the address of effect `id` inside its bank for the bank groups, or NULL when
// the group plays effects by id
static void const* resolveSfxData(int group, int id)
{
    void const* sfx;
    int const* bank;

    switch (group) {
    case 0x1:
    case 0x7E:
    case 0xFE:
    case 0x100:
    case 0x200:
        sfx = NULL;
        break;

    case 0xFF000:
    case 0xF00000:
        sfx = bank = vs_main_soundData.sfxData[vs_main_soundData.currentSfxId - 1];
        sfx += bank[id + 1];

        break;

    default:
        vs_main_nop10(0x95, 0);
        sfx = NULL;

        break;
    }

    return sfx;
}

void vs_main_fadeSfxVolume(int group, int id, int volume, char duration)
{
    if (id != 0) {
        void const* sfx = resolveSfxData(group, id);

        if (sfx != NULL) {
            Sound_FadeSfxVolumeMod((u_long)sfx, 0, duration, volume);
        } else {
            Sound_FadeSfxVolumeMod(id, 0, duration, volume);
        }
    } else {
        Sound_FadeSfxVolumeMod(0, group, duration, volume);
    }
}

void vs_main_fadeSfxPitch(int group, int id, int pitch, char duration)
{
    if (id != 0) {
        void const* sfx = resolveSfxData(group, id);

        if (sfx != NULL) {
            Sound_FadeSfxPitchMod((u_long)sfx, 0, duration, pitch);
        } else {
            Sound_FadeSfxPitchMod(id, 0, duration, pitch);
        }

    } else {
        Sound_FadeSfxPitchMod(0, group, duration, pitch);
    }
}

void vs_main_fadeSfxPan(int group, int id, int pan, char duration)
{
    if (id != 0) {
        void const* sfx = resolveSfxData(group, id);

        if (sfx != NULL) {
            Sound_FadeSfxPanMod((u_long)sfx, 0, duration, pan);
        } else {
            Sound_FadeSfxPanMod(id, 0, duration, pan);
        }

    } else {
        Sound_FadeSfxPanMod(0, group, duration, pan);
    }
}

void vs_main_evictSfx(int group, int id)
{
    if (id != 0) {
        void const* sfx = resolveSfxData(group, id);

        if (sfx != NULL) {
            Sound_EvictSfx((u_long)sfx, 0);
        } else {
            Sound_EvictSfx(id, 0);
        }

    } else {
        Sound_EvictSfx(0, group);
    }
}

void vs_main_stopAllSfx(void) { Sound_StopSfx(); }

int vs_main_loadSfxSlot(int id, u_int slot)
{
    if (slot - 1 < 3) {
        if (vs_main_soundData.sfxData[slot - 1] == NULL) {

            vs_Main_CdFile cdFile;
            u_int index = slot - 1;
            cdFile.lba = seLBAs[id];
            cdFile.size = seFileSizes[id];

            if ((vs_main_soundData.sfxQueueSlot[index] != NULL)
                && (vs_main_soundData.sfxQueueSlot[index] != (vs_Main_CdQueueSlot*)-1)) {
                vs_main_nop9(0x8F, 0);
            }

            vs_main_soundData.sfxQueueSlot[index] = vs_main_allocateCdQueueSlot(&cdFile);

            if (vs_main_soundData.sfxData[index] != NULL) {
                vs_main_nop9(0x90, 0);
            }

            vs_main_soundData.sfxIds[index] = id;
            vs_main_soundData.sfxData[index] = vs_main_allocHeapR(cdFile.size);

            vs_main_cdEnqueue(
                vs_main_soundData.sfxQueueSlot[index], vs_main_soundData.sfxData[index]);

            return slot;
        }
    }

    return 0;
}

static int loadSfx(int id)
{
    int i;

    for (i = 0; i < 3; ++i) {
        if (vs_main_soundData.sfxData[i] == NULL) {
            return vs_main_loadSfxSlot(id, i + 1);
        }
    }

    return 0;
}

int vs_main_freeSfxQueueSlot(u_int slot)
{
    if ((slot - 1) < 3) {
        if (vs_main_soundData.sfxQueueSlot[slot - 1] != NULL) {

            if (vs_main_soundData.sfxQueueSlot[slot - 1]->state
                == vs_main_CdQueueStateLoaded) {

                vs_main_freeCdQueueSlot(vs_main_soundData.sfxQueueSlot[slot - 1]);
                vs_main_soundData.sfxQueueSlot[slot - 1] = NULL;

                return 0;
            }

            if (vs_main_soundData.sfxQueueSlot[slot - 1]->state
                == vs_main_CdQueueStateError) {

                vs_main_freeCdQueueSlot(vs_main_soundData.sfxQueueSlot[slot - 1]);
                vs_main_soundData.sfxQueueSlot[slot - 1] = (vs_Main_CdQueueSlot*)-1;

                return -1;
            }

            return 1;
        }
    }

    return 0;
}

static int freeSfxSlots(void)
{
    int i;
    int ret = 0;

    for (i = 0; i < 3; ++i) {
        ret |= vs_main_freeSfxQueueSlot(i + 1);
    }

    return ret;
}

static UNUSED int loadAndFreeSfx(int id)
{
    int slot = loadSfx(id);

    if (slot != 0) {
        while (freeSfxSlots() != 0) {
            vs_main_gametimeUpdate(0);
        }
    }

    return slot;
}

int vs_main_setCurrentSfx(int slot)
{
    if ((slot - 1u < 3) && vs_main_soundData.sfxData[slot - 1] != NULL) {
        vs_main_soundData.currentSfxId = slot;

        return 1;
    }

    return 0;
}

int vs_main_freeSfx(u_int slot)
{
    if ((slot - 1) < 3) {
        if (vs_main_soundData.sfxData[slot - 1] != NULL) {

            if (vs_main_soundData.currentSfxId == slot) {
                vs_main_soundData.currentSfxId = 0;
            }

            Sound_EvictSfx(-2, 0);
            Sound_EvictSfx(0, 0xFF000);
            vs_main_freeHeapR(vs_main_soundData.sfxData[slot - 1]);

            vs_main_soundData.sfxIds[slot - 1] = 0;
            vs_main_soundData.sfxData[slot - 1] = 0;

            return 1;
        }
    }
    return 0;
}

int vs_main_setSfxSlot3Data(void* bank)
{
    if (vs_main_soundData.sfxData[2] == 0) {
        vs_main_soundData.sfxData[2] = bank;
        return 1;
    }

    return 0;
}

int vs_main_clearSfxSlot3(void)
{
    Sound_EvictSfx(-2, 0);
    Sound_EvictSfx(0, 0xF00000);

    vs_main_soundData.sfxData[2] = NULL;

    return 1;
}

void vs_main_playBankSfx(int group, u_int bank[], u_int index, int pan, int volume)
{
    int voice;
    void* sfx = bank;

    if (index >= bank[0]) {
        return;
    }

    sfx += bank[index + 1];
    voice = 0;

    if (group == 0x180) {

        voice = nextVoicePool2;
        nextVoicePool2 *= 2;

        if (!(nextVoicePool2 & 0x180)) {
            nextVoicePool2 = 0x80;
        }

    } else if (group == 0x200) {

        voice = nextVoicePool3;
        nextVoicePool3 *= 2;

        if (!(nextVoicePool3 & 0x200)) {
            nextVoicePool3 = group;
        }

    } else if (group == 0xF00000) {

        voice = nextVoicePool5;
        nextVoicePool5 *= 2;

        if (!(nextVoicePool5 & group)) {
            nextVoicePool5 = 0x100000;
        }

    } else if (group != 0x7E) {
        vs_main_nop10(0x95, 0);
    }

    playSfxFromPointer(sfx, voice, pan, volume);
}

void vs_main_playBankSfxDefault(int group, int* bank, u_int index)
{
    vs_main_playBankSfx(group, bank, index, 0x80, 0x7F);
}

static void do_panBankSfx(int group, u_int bank[], int index, int pan, int depth)
{
    int volume;
    int sxy = pan;
    int tmp = pan;
    pan = tmp >> 0x10;

    if (sxy < 0) {
        tmp = sxy + 0xFFFF;
    }

    pan = tmp >> 0x10;
    tmp = pan << 0x10;
    pan = sxy - tmp;

    if (pan < 0) {
        pan = 0;
    }

    if (pan > 0x140) {
        pan = 0x140;
    }

    tmp = pan + ((u_int)pan >> 0x1F);
    tmp >>= 1;
    pan = tmp + 0x30;
    volume = depth;

    if (volume < 0) {
        volume = 0;
    }

    if (volume > 0x400) {
        volume = 0x400;
    }

    sxy = volume;

    if (volume < 0) {
        sxy += 7;
    }

    volume = 0x7F - (sxy >> 3);

    if (volume > 0) {
        vs_main_playBankSfx(group, bank, index, pan, volume);
    }
}

static UNUSED void panBankSfx(int group, u_int* bank, int index, SVECTOR* position)
{
    int depth;
    long screenXY;
    long interpolation;
    long flag;

    SetRotMatrix(&vs_scratch.viewMatrix);
    SetTransMatrix(&vs_scratch.viewMatrix);
    depth = RotTransPers(position, &screenXY, &interpolation, &flag);
    do_panBankSfx(group, bank, index, screenXY, depth);
}

void vs_main_evictBankSfx(int group, int const* bank, int index)
{
    int mask;
    void const* sfx = (u_char const*)bank + (bank + index)[1];

    if (index != 0) {
        mask = 0;
    } else {
        sfx = NULL;
        mask = group;
    }

    Sound_EvictSfx((u_long)sfx, mask);
}

void vs_main_fadeBankSfxVolume(
    int group, int const* bank, int index, int volume, int duration)
{
    void const* sfx = (u_char const*)bank + (bank + index)[1];

    if (index == 0) {
        Sound_FadeSfxVolumeMod(0, group, duration & 0xFF, volume);
    } else {
        Sound_FadeSfxVolumeMod((u_long)sfx, 0, duration & 0xFF, volume);
    }
}

static UNUSED void stopCutsceneStream(void) { Sound_StopCutsceneStream(); }

static int startCutsceneStream(int slot, int pan, int volume)
{
    if ((slot - 1u) >= 3) {
        return 0;
    }

    if (vs_main_soundData.unk64[slot - 1] == 0) {
        return 0;
    }

    Sound_FadeOutCutscene(0, volume);
    Sound_StartCutsceneStream(vs_main_soundData.unk64[slot - 1], pan, 1);

    return 1;
}

void vs_main_startCutsceneStreamDefault(int slot)
{
    startCutsceneStream(slot, 0x80, 0x7F);
}

static UNUSED int freeCutsceneStream(int slot)
{
    if ((slot - 1u) >= 3) {
        return 0;
    }

    if (vs_main_soundData.unk64[slot - 1] == 0) {
        return 0;
    }

    Sound_StopCutsceneStream();
    vs_main_freeHeapR(vs_main_soundData.unk64[slot - 1]);

    vs_main_soundData.unk64[slot - 1] = 0;

    return 1;
}

int vs_main_setCutsceneStreamSlot3(void* stream)
{
    if (vs_main_soundData.unk64[2] == 0) {
        vs_main_soundData.unk64[2] = stream;
        return 3;
    }

    return 0;
}

int vs_main_clearCutsceneStreamSlot3(void)
{

    if (vs_main_soundData.unk64[2] != 0) {

        Sound_StopCutsceneStream();
        vs_main_soundData.unk64[2] = 0;

        return 1;
    }

    return 0;
}

static void loadSoundFile(int file)
{
    vs_Main_CdFile cdFile;
    int loadedBanks = Sound_GetLoadedMusicBankIds();

    if (loadedBanks % 0x10000 == file || loadedBanks / 0x10000 == file) {
        return;
    }

    cdFile.lba = soundLBAs[file];
    cdFile.size = soundFileSizes[file];

    if (vs_main_soundData.soundQueueSlot != NULL
        && vs_main_soundData.soundQueueSlot != (vs_Main_CdQueueSlot*)-1) {
        vs_main_nop9(0x93, 0);
    }

    vs_main_soundData.soundQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);

    if (vs_main_soundData.soundData != NULL) {
        vs_main_nop9(0x94, 0);
    }

    vs_main_soundData.soundData = vs_main_allocHeapR(cdFile.size);
    vs_main_soundData.soundFileId = file;

    vs_main_cdEnqueue(vs_main_soundData.soundQueueSlot, vs_main_soundData.soundData);
}

void vs_main_loadSoundFile(int id) { loadSoundFile(soundFileMap[id]); }

static inline void releaseSoundQueue(void)
{
    vs_main_freeCdQueueSlot(vs_main_soundData.soundQueueSlot);

    vs_main_soundData.soundQueueSlot = NULL;

    vs_main_freeHeapR(vs_main_soundData.soundData);

    vs_main_soundData.soundData = NULL;
    vs_main_soundData.soundFileId = 0;
}

int vs_main_processSoundQueue(void)
{
    if (vs_main_soundData.soundQueueSlot != NULL) {
        if (vs_main_soundData.soundQueueSlot->state == vs_main_CdQueueStateDispatched) {

            int isTransferring = IsSpuTransferring();

            if (isTransferring == 0) {
                releaseSoundQueue();

                return 0;
            }

            if (isTransferring == -1) {
                releaseSoundQueue();

                return -1;
            }

            return 1;
        }

        if (vs_main_soundData.soundQueueSlot->state == vs_main_CdQueueStateLoaded) {

            vs_main_soundData.soundQueueSlot->state = vs_main_CdQueueStateDispatched;
            Sound_LoadMusicBank(vs_main_soundData.soundData, 0);

            return 1;
        }

        if (vs_main_soundData.soundQueueSlot->state == vs_main_CdQueueStateError) {
            releaseSoundQueue();

            return -1;
        }

        return 1;
    }

    return 0;
}

void vs_main_loadAndWaitSoundSlot(int id)
{
    vs_main_loadSoundFile(id);

    while (vs_main_processSoundQueue() != 0) {
        vs_main_gametimeUpdate(0);
    }
}

void vs_main_setMonoSound(int set) { Sound_SetSpeakerMode(set); }

static UNUSED void setCdVolumeMax(void) { Sound_SetCdVolume(0x7FFF); }

static inline void resetVoicePools(void)
{
    nextVoicePool0 = 1;
    nextVoicePool1 = 2;
    nextVoicePool2 = 0x80;
    nextVoicePool3 = 0x200;
    nextVoicePool4 = 0x1000;
    nextVoicePool5 = 0x100000;
}

static void loadMenuSound(void)
{
    void* buf;

    InitSound();
    Sound_SetCdMixVolume(0x7F);

    buf = vs_main_allocHeapR(VS_WAVE0000_DAT_SIZE);
    vs_main_diskLoadFile(VS_WAVE0000_DAT_LBA, VS_WAVE0000_DAT_SIZE, buf);
    Sound_LoadAkaoBankBlocking(buf, 1);
    vs_main_freeHeapR(buf);

    buf = vs_main_allocHeapR(VS_WAVE0005_DAT_SIZE);
    vs_main_diskLoadFile(VS_WAVE0005_DAT_LBA, VS_WAVE0005_DAT_SIZE, buf);
    Sound_LoadAkaoBankBlocking(buf, 1);
    vs_main_freeHeapR(buf);

    buf = vs_main_allocHeapR(VS_WAVE0200_DAT_SIZE);
    vs_main_diskLoadFile(VS_WAVE0200_DAT_LBA, VS_WAVE0200_DAT_SIZE, buf);
    Sound_LoadSfxBank(buf, 0, 1);
    vs_main_freeHeapR(buf);

    vs_main_diskLoadFile(VS_EFFECT00_DAT_LBA, VS_EFFECT00_DAT_SIZE, sfxData);
    Sound_BindAkaoSfxBlob(sfxData);

    resetVoicePools();
}

void vs_main_resetSound(void)
{
    int i;

    vs_main_soundData.currentMusicSlot = 0;
    vs_main_soundData.currentMusicData = NULL;
    vs_main_soundData.unk8 = 0xFFFF;
    vs_main_soundData.currentMusicHandle = 0xFFFF;
    vs_main_soundData.currentSfxId = 0;

    for (i = 0; i < 4; ++i) {
        vs_main_soundData.musicIds[i] = 0;
        vs_main_soundData.musicHandleBySlot[i] = 0xFFFF;
        vs_main_soundData.musicData[i] = NULL;
        vs_main_soundData.musicQueueSlot[i] = NULL;
    }

    for (i = 0; i < 3; ++i) {
        vs_main_soundData.sfxIds[i] = 0;
        vs_main_soundData.sfxData[i] = NULL;
        vs_main_soundData.sfxQueueSlot[i] = NULL;
    }

    for (i = 0; i < 3; ++i) {
        vs_main_soundData.unk64[i] = NULL;
        vs_main_soundData.unused[i] = NULL;
    }

    vs_main_soundData.soundFileId = 0;
    vs_main_soundData.soundData = NULL;
    vs_main_soundData.soundQueueSlot = NULL;

    resetVoicePools();
}

static inline int maskR(short color) { return color & 0x1F; }
static inline int maskG(short color) { return color & 0x3E0; }
static inline int maskB(short color) { return color & 0x7C00; }
static inline int colorR(short color) { return maskR(color); }
static inline int colorG(short color) { return maskG(color) >> 5; }
static inline int colorB(short color) { return maskB(color) >> 10; }

// Packs 5:5:5 channels and the semi-transparency bit to a PlayStation 16-bit colour
#define PACK_COLOR(r, g, b, stp) ((r) + ((g) << 5) + ((b) << 10) + ((stp) << 15))

static void loadClutTransition(int duration, int slot, u_short const* sourceClut)
{
    int i;

    for (i = 0; i < 256; ++i) {
        u_short r = colorR(sourceClut[i]);
        u_short g = colorG(sourceClut[i]);
        u_short b = colorB(sourceClut[i]);

        struct ColorInfo* colors = clutState.slots[slot].colorInfo;

        if (duration != 0) {
            colors[i].rindex = (r - colors[i].r) + 31;
            colors[i].gindex = (g - colors[i].g) + 31;
            colors[i].bindex = (b - colors[i].b) + 31;
        } else {
            colors[i].r = r;
            colors[i].g = g;
            colors[i].b = b;
            clutBuffer[slot][i] = PACK_COLOR(r, g, b, colors[i].a);
        }
    }

    if (duration != 0) {
        struct ClutAnimState* state = &clutState.slots[slot].animState;
        state->active = 1;
        state->frame = 0;
        state->tick = 0;
        state->speed = duration;
    } else {
        clutState.slots[slot].animState.active = 0;
    }
}

void vs_main_loadClutTransition(
    int duration, int slot, u_short const* sourceClut, int clutOffset)
{
    if (clutState.active != 0) {
        loadClutTransition(duration, slot, sourceClut + (clutOffset * 16));
        clutState.uploadPending = 1;
    }
}

static UNUSED void loadClutTransitionWithBase(
    int duration, int slot, u_short const* sourceClut, int clutOffset)
{
    if (clutState.active != 0) {
        int i;

        vs_main_loadClutTransition(duration, slot, sourceClut, clutOffset);

        for (i = 0; i < 256; ++i) {
            clutState.slots[slot].clutBase[i] = sourceClut[i];
        }
    }
}

static UNUSED void saveClutBase(int slot)
{
    if (clutState.active != 0) {
        int i;

        for (i = 0; i < 256; ++i) {
            clutState.slots[slot].clutBase[i] = clutBuffer[slot][i];
        }
    }
}

static inline int weightedLuminance(short g, short b, short r)
{
    return r * 2 + (g >> 5) * 3 + (b >> 10);
}

static inline int colorLuminance(short color)
{
    return weightedLuminance(maskG(color), maskB(color), maskR(color));
}

static inline int luminance(int r, int g, int b) { return r * 2 + g * 3 + b; }

static inline int colorInfoLuminance(struct ColorInfo const* color)
{
    return luminance(color->r, color->g, color->b);
}

// Clamp a 5-bit channel to 0..31; both tests look at the low 16 bits only
#define CLAMP_CLUT_HIGH(c) \
    if ((short)(c) > 31) { \
        (c) = 31;          \
    }
#define CLAMP_CLUT_LOW(c)   \
    if (((c) << 16) <= 0) { \
        (c) = 0;            \
    }

// r/g/b are the locals of the loop below: each channel gets its own offset added
#define OFFSET_RGB3(rv, gv, bv)                                                        \
    r = rOffset + (rv);                                                                \
    g = gOffsetU + (gv);                                                               \
    b = bOffsetU + (bv)
#define OFFSET_RGB(value) OFFSET_RGB3(value, value, value)

static void transformClutSlot(
    int mode, int duration, int slot, int rOffset, short gOffset, short bOffset)
{
    int i;
    int gOffsetU = (u_short)gOffset;
    int bOffsetU = (u_short)bOffset;
    struct ColorInfo* colors = clutState.slots[slot].colorInfo;

    for (i = 0; i < 256; ++i) {

        int r;
        int g;
        int b;
        short baseEntry = clutState.slots[slot].clutBase[i];

        if ((colors[i].r + colors[i].g + colors[i].b + colors[i].a) != 0) {
            switch (mode) {
            case 1: {
                int rTmp = colors[i].r;
                int gTmp = colors[i].g;
                int bTmp = colors[i].b;
                OFFSET_RGB3(rTmp / 2, gTmp / 2, bTmp / 2);
                break;
            }

            case 2:
                OFFSET_RGB(colorInfoLuminance(&colors[i]) / 6);
                break;

            case 3:
                OFFSET_RGB(colorInfoLuminance(&colors[i]) / 12);
                break;

            case 4:
            case 9:
                OFFSET_RGB3(colorR(baseEntry), colorG(baseEntry), colorB(baseEntry));
                break;

            case 5:
                OFFSET_RGB3(
                    colorR(baseEntry) / 2, colorG(baseEntry) / 2, colorB(baseEntry) / 2);
                break;

            case 6:
                OFFSET_RGB(colorLuminance(baseEntry) / 6);
                break;

            case 7:
                OFFSET_RGB(colorLuminance(baseEntry) / 12);
                break;

            case 8:
            case 15:
                r = colorR(baseEntry);
                g = colorG(baseEntry);
                b = colorB(baseEntry);
                break;

            case 11:
                clutState.slots[slot].animState.transitionMode = 0;
                return;

            case 12:
                r = rOffset + 0x1F - colors[i].r;
                g = gOffsetU + 0x1F - colors[i].g;
                b = bOffsetU + 0x1F - colors[i].b;
                break;

            case 13:
                OFFSET_RGB3(colorR(baseEntry) * 3 / 4, colorG(baseEntry) * 3 / 4,
                    colorB(baseEntry) * 3 / 4);
                break;

            default:
                r = colors[i].r + rOffset;
                g = colors[i].g + gOffsetU;
                b = colors[i].b + bOffsetU;
                break;
            }

            CLAMP_CLUT_HIGH(r);
            CLAMP_CLUT_HIGH(g);
            CLAMP_CLUT_HIGH(b);
            CLAMP_CLUT_LOW(r);
            CLAMP_CLUT_LOW(g);
            CLAMP_CLUT_LOW(b);

            if (((b | (r | g)) << 16) == 0) {
                b = 1;
            }

            if (duration != 0) {
                colors[i].rindex = ((r - colors[i].r) + 31);
                colors[i].gindex = ((g - colors[i].g) + 31);
                colors[i].bindex = ((b - colors[i].b) + 31);
            } else {
                colors[i].b = b;
                colors[i].r = r;
                colors[i].g = g;
                clutBuffer[slot][i] = PACK_COLOR(r, g, b, colors[i].a);
            }
        } else {
            colors[i].bindex = 31;
            colors[i].gindex = 31;
            colors[i].rindex = 31;
        }
    }

    if (duration != 0) {
        struct ClutAnimState* p = &clutState.slots[slot].animState;
        p->active = 1;
        p->frame = 0;
        p->tick = 0;
        p->speed = duration;
        p->transitionMode = mode;

        if (mode == 9) {
            p->transitionTargetR = rOffset;
            p->transitionTargetG = gOffsetU;
            p->transitionTargetB = bOffsetU;
        }
    } else {
        clutState.slots[slot].animState.active = 0;
        clutState.uploadPending = 1;
    }
}

#undef OFFSET_RGB3
#undef OFFSET_RGB

void vs_main_transformClutSlot(
    int mode, int duration, int slot, short rOffset, int gOffset, int bOffset)
{
    if (clutState.active != 0) {
        do {
            transformClutSlot(mode, duration, slot, rOffset, gOffset, bOffset);
        } while (0);
    }
}

static inline int shift_left(int channel) { return channel << 0x10; }

static inline void startBgAnim(int speed)
{
    clutState.bgAnimActive = 1;
    clutState.bgAnimFrame = 0;
    clutState.bgAnimTick = 0;
    clutState.bgAnimSpeed = speed;
}

// Per-update step from a 16.16 colour towards a target over frames * 2 updates
static inline int bgStep(int target, int current, int frames)
{
    return (int)(target - (current & 0xFFFF0000)) / (frames * 2);
}

// Packs the background colours (16.16 fixed point) to 8-bit r/g/b words in `position`
// (using `i` as the loop counter) and uploads them
#define UPLOAD_BG_COLORS(bg, position, i)                                              \
    for ((i) = 0; (i) < 5; ++(i)) {                                                    \
        (position)[i] = (((bg)[i].current.r / 65536) + (((bg)[i].current.g / 65536) << 8))         \
                      + ((((bg)[i].current.b / 65536)) << 0x10);                              \
    }                                                                                  \
    func_8008EB30(position)

void vs_main_fadeBgColors(int frames, CVECTOR const* target)
{
    int position[5];
    int i;
    Fade* bg;

    if (clutState.active == 0) {
        return;
    }

    bg = clutState.bgColors;

    for (i = 0; i < 5; ++i) {

        int r = shift_left(target[i].r);
        int g = shift_left(target[i].g);
        int b = shift_left(target[i].b);

        if (frames != 0) {
            bg[i].step.r = bgStep(r, bg[i].current.r, frames);
            bg[i].step.g = bgStep(g, bg[i].current.g, frames);
            bg[i].step.b = bgStep(b, bg[i].current.b, frames);
        } else {
            bg[i].current.r = r;
            bg[i].current.g = g;
            bg[i].current.b = b;
        }
    }

    if (frames != 0) {
        startBgAnim(frames);
        return;
    }

    clutState.bgAnimActive = 0;

    UPLOAD_BG_COLORS(bg, position, i);
}

static UNUSED void fadeBgColorsStore(int frames, CVECTOR const* target)
{
    if (clutState.active != 0) {

        int i;

        vs_main_fadeBgColors(frames, target);

        for (i = 0; i < 5; ++i) {
            clutState.bgBaseColors[i] = target[i];
        }
    }
}

// Clamp a 16.16 fixed point channel to 0..max
#define CLAMP_FIXED_HIGH(c, max) \
    if ((c) > (max)) {           \
        (c) = (max);             \
    }
#define CLAMP_FIXED_LOW(c) \
    if ((c) < 0) {         \
        (c) = 0;           \
    }

// sum = (2 * r + 3 * g + b) << 16 for a base colour. `scratch` is written (with g << 16)
// and not read again; the compiled code depends on that assignment.
#define BASE_COLOR_SUM(sum, scratch, color)                                            \
    {                                                                                  \
        int g_ = (color).g;                                                            \
        int b_ = (color).b;                                                            \
        (sum) = (color).r;                                                             \
        (scratch) = g_ << 0x10;                                                        \
        b_ <<= 0x10;                                                                   \
        (sum) <<= 0x11;                                                                \
        g_ <<= 0x11;                                                                   \
        (sum) += g_ + (scratch);                                                       \
        (sum) += b_;                                                                   \
    }

// r/g/b are the locals below: each channel (16.16 fixed point) gets its offset added
#define OFFSET_BG_RGB(rv, gv, bv)           \
    r = (rv) + (rOffset << 0x10);           \
    g = (gv) + (gOffset << 0x10);           \
    b = (bv) + (bOffset << 0x10)

static void transformBgColors(int mode, int frames, int rOffset, int gOffset, int bOffset)
{
    int i;
    Fade* bg = clutState.bgColors;

    for (i = 0; i < 5; ++i) {
        int lum;
        int b;
        int g;
        int r;

        switch (mode) {

        // 1: half of the current colours, plus offset
        case 1:
            OFFSET_BG_RGB(bg[i].current.r / 2, bg[i].current.g / 2, bg[i].current.b / 2);
            break;

        // 2, 3: current colours as a grey level (weighted average), plus offset
        case 2:
            OFFSET_BG_RGB(
                luminance(bg[i].current.r, bg[i].current.g, bg[i].current.b) / 6,
                luminance(bg[i].current.r, bg[i].current.g, bg[i].current.b) / 6,
                luminance(bg[i].current.r, bg[i].current.g, bg[i].current.b) / 6);
            break;

        case 3:
            lum = luminance(bg[i].current.r, bg[i].current.g, bg[i].current.b) / 12;
            OFFSET_BG_RGB(lum, lum, lum);
            break;

        // 4, 9: base colours plus offset
        case 4:
        case 9:
            r = (clutState.bgBaseColors[i].r + rOffset) << 0x10;
            g = (clutState.bgBaseColors[i].g + gOffset) << 0x10;
            b = (clutState.bgBaseColors[i].b + bOffset) << 0x10;
            break;

        // 5: half of the base colours, plus offset
        case 5:
            OFFSET_BG_RGB(clutState.bgBaseColors[i].r << 0xF,
                clutState.bgBaseColors[i].g << 0xF, clutState.bgBaseColors[i].b << 0xF);
            break;

        // 6, 7: base colours as a grey level, plus offset
        case 6: {
            int sum;
            BASE_COLOR_SUM(sum, b, clutState.bgBaseColors[i]);
            OFFSET_BG_RGB(sum / 6, sum / 6, sum / 6);
        } break;

        case 7: {
            int sum;
            BASE_COLOR_SUM(sum, b, clutState.bgBaseColors[i]);
            OFFSET_BG_RGB(sum / 12, sum / 12, sum / 12);
        } break;

        // 8: the base colours
        case 8:
            r = clutState.bgBaseColors[i].r << 0x10;
            g = clutState.bgBaseColors[i].g << 0x10;
            b = clutState.bgBaseColors[i].b << 0x10;
            break;

        // 11: cancel the transition
        case 11:
            clutState.bgTransitionMode = 0;
            return;

        // 0: the current colours plus offset
        case 0:
        default:
            OFFSET_BG_RGB(bg[i].current.r, bg[i].current.g, bg[i].current.b);
            break;
        }

        // Keep the integer part of each channel and clamp it to 0..255
        r &= 0xFFFF0000;
        g &= 0xFFFF0000;
        b &= 0xFFFF0000;

        CLAMP_FIXED_HIGH(r, 0xFF0000);
        CLAMP_FIXED_HIGH(g, 0xFF0000);
        CLAMP_FIXED_HIGH(b, 0xFF0000);
        CLAMP_FIXED_LOW(r);
        CLAMP_FIXED_LOW(g);
        CLAMP_FIXED_LOW(b);

        // Either fade towards the result over `frames`, or set it right away
        if (frames != 0) {
            bg[i].step.r = bgStep(r, bg[i].current.r, frames);
            bg[i].step.g = bgStep(g, bg[i].current.g, frames);
            bg[i].step.b = bgStep(b, bg[i].current.b, frames);
        } else {
            bg[i].current.r = r;
            bg[i].current.g = g;
            bg[i].current.b = b;
        }
    }

    if (frames != 0) {

        startBgAnim(frames);
        clutState.bgTransitionMode = mode;

        if (mode == 9) {
            clutState.bgTransitionTargetR = rOffset;
            clutState.bgTransitionTargetG = gOffset;
            clutState.bgTransitionTargetB = bOffset;
        }
    } else {
        int position[5];

        clutState.bgAnimActive = 0;
        UPLOAD_BG_COLORS(bg, position, i);
    }
}

void vs_main_transformBgColors(
    int mode, int frames, int rOffset, int gOffset, int bOffset)
{
    if (clutState.active != 0) {
        transformBgColors(mode, frames, rOffset, gOffset, bOffset);
    }
}

// Converts a 16.16 colour slot colour (`fade` is a Fade*) to the signed byte offsets
// the lighting code takes, stored in the CVECTOR `position`
#define SLOT_POSITION(position, fade)                  \
    (position).r = ((fade)->current.r / 65536) - 0x40;         \
    (position).g = ((fade)->current.g / 65536) - 0x40;         \
    (position).b = ((fade)->current.b / 65536) - 0x40;         \
    (position).cd = 0

static inline void startColorSlotAnim(ColorSlot* slot, int speed)
{
    slot->active = 1;
    slot->frame = 0;
    slot->tick = 0;
    slot->speed = speed;
}

static void fadeColorSlot(int frames, int slot, CVECTOR const* color)
{
    CVECTOR position;
    ColorSlot* cs;
    int r;
    int g;
    int b;
    Fade* fade;

    if (clutState.active == 0) {
        return;
    }

    cs = &clutState.colorSlots[slot];
    fade = &clutState.colorSlots[slot].fade;
    r = shift_left(color->r);
    g = shift_left(color->g);
    b = shift_left(color->b);

    if (frames != 0) {
        fade->step.r = bgStep(r, fade->current.r, frames);
        fade->step.g = bgStep(g, fade->current.g, frames);
        fade->step.b = bgStep(b, fade->current.b, frames);
    } else {
        fade->current.r = r;
        fade->current.g = g;
        fade->current.b = b;
    }
    if (frames != 0) {
        startColorSlotAnim(cs, frames);
        return;
    }

    cs->active = 0;
    SLOT_POSITION(position, fade);

    if (slot != 0) {
        func_800A0768(slot - 1, &position);
    } else {
        func_8008B430(&position, cs->grayAmount >> 2);
    }
}

static UNUSED void fadeColorSlotStore(int frames, int slot, CVECTOR const* color)
{
    if (clutState.active != 0) {
        fadeColorSlot(frames, slot, color);
        clutState.colorSlots[slot].baseColor = *color;
    }
}

static void transformColorSlot(
    int mode, int frames, int slot, int rOffset, int gOffset, int bOffset)
{
    short gray;
    int lum;
    int r;
    int b;
    int g;
    ColorSlot* cs = &clutState.colorSlots[slot];
    Fade* fade = &cs->fade;

    // gray is the target grey amount: modes that average the channels fade it in
    gray = 0;

    switch (mode) {

    // 1: half of the current colour, plus offset
    case 1:
        OFFSET_BG_RGB(fade->current.r / 2, fade->current.g / 2, fade->current.b / 2);
        break;

    // 2, 3: current colour as a grey level, plus offset
    case 2:
        gray = 0x4000;
        OFFSET_BG_RGB(luminance(fade->current.r, fade->current.g, fade->current.b) / 6,
            luminance(fade->current.r, fade->current.g, fade->current.b) / 6,
            luminance(fade->current.r, fade->current.g, fade->current.b) / 6);
        break;

    case 3:
        gray = 0x4000;
        lum = luminance(fade->current.r, fade->current.g, fade->current.b) / 12;
        OFFSET_BG_RGB(lum, lum, lum);
        break;

    // 4, 9: base colour plus offset
    case 4:
    case 9:
        r = (cs->baseColor.r + rOffset) << 0x10;
        g = (cs->baseColor.g + gOffset) << 0x10;
        b = (cs->baseColor.b + bOffset) << 0x10;
        break;

    // 5: half of the base colour, plus offset
    case 5:
        gray = 0x4000;
        OFFSET_BG_RGB(
            cs->baseColor.r << 0xF, cs->baseColor.g << 0xF, cs->baseColor.b << 0xF);
        break;

    // 6, 7: base colour as a grey level, plus offset
    case 6:
        gray = 0x4000;
        {
            int sum;
            BASE_COLOR_SUM(sum, b, cs->baseColor);
            OFFSET_BG_RGB(sum / 6, sum / 6, sum / 6);
        }
        break;

    case 7:
        gray = 0x4000;
        {
            int sum;
            BASE_COLOR_SUM(sum, b, cs->baseColor);
            OFFSET_BG_RGB(sum / 12, sum / 12, sum / 12);
        }
        break;

    // 8, 15: the base colour
    case 8:
    case 15:
        r = cs->baseColor.r << 0x10;
        g = cs->baseColor.g << 0x10;
        b = cs->baseColor.b << 0x10;
        break;

    // 11: cancel the transition
    case 11:
        cs->mode = 0;
        return;

    // anything else: the current colour plus offset
    default:
        OFFSET_BG_RGB(fade->current.r, fade->current.g, fade->current.b);
        break;
    }

    // Keep the integer part of each channel and clamp it to 0..128
    r &= 0xFFFF0000;
    g &= 0xFFFF0000;
    b &= 0xFFFF0000;

    CLAMP_FIXED_HIGH(r, 0x800000);
    CLAMP_FIXED_HIGH(g, 0x800000);
    CLAMP_FIXED_HIGH(b, 0x800000);
    CLAMP_FIXED_LOW(r);
    CLAMP_FIXED_LOW(g);
    CLAMP_FIXED_LOW(b);

    if (frames != 0) {
        fade->step.r = bgStep(r, fade->current.r, frames);
        fade->step.g = bgStep(g, fade->current.g, frames);
        fade->step.b = bgStep(b, fade->current.b, frames);
        cs->grayStep = ((gray - cs->grayAmount) / (frames * 2));
    } else {
        fade->current.r = r;
        fade->current.g = g;
        fade->current.b = b;
        cs->grayAmount = gray;
    }

    if (frames != 0) {

        startColorSlotAnim(cs, frames);

        cs->mode = mode;

        if (mode == 9) {
            cs->pulseTarget[0] = rOffset;
            cs->pulseTarget[1] = gOffset;
            cs->pulseTarget[2] = bOffset;
        }
    } else {
        CVECTOR position;

        cs->active = 0;
        SLOT_POSITION(position, fade);

        if (slot != 0) {
            func_800A0768(slot - 1, &position);
        } else {
            func_8008B430(&position, cs->grayAmount >> 2);
        }
    }
}

void vs_main_transformColorSlot(
    int mode, int frames, int slot, int rOffset, int gOffset, int bOffset)
{
    if (clutState.active != 0) {
        transformColorSlot(mode, frames, slot, rOffset, gOffset, bOffset);
    }
}

#undef OFFSET_BG_RGB
#undef CLAMP_FIXED_LOW
#undef CLAMP_FIXED_HIGH
#undef BASE_COLOR_SUM

void vs_main_updateBgColors(void)
{
    int position[5];
    int i;
    Fade* bg;

    if (clutState.bgAnimActive == 0) {
        return;
    }

    bg = clutState.bgColors;

    // Advance each colour by its step
    for (i = 0; i < 5; ++i) {
        bg[i].current.r += bg[i].step.r;
        bg[i].current.g += bg[i].step.g;
        bg[i].current.b += bg[i].step.b;
    }

    UPLOAD_BG_COLORS(bg, position, i);
    ++clutState.bgAnimFrame;

    if (clutState.bgAnimFrame < (clutState.bgAnimSpeed * 2)) {
        return;
    }

    // Modes 9 and 10 pulse: fade to half the target colour, then back to the full target
    if (clutState.bgTransitionMode == 9) {

        transformBgColors(4, clutState.bgAnimSpeed, clutState.bgTransitionTargetR / 2,
            clutState.bgTransitionTargetG / 2, clutState.bgTransitionTargetB / 2);

        clutState.bgTransitionMode = 10;

        return;
    }

    if (clutState.bgTransitionMode == 10) {

        transformBgColors(9, clutState.bgAnimSpeed, clutState.bgTransitionTargetR,
            clutState.bgTransitionTargetG, clutState.bgTransitionTargetB);

        clutState.bgTransitionMode = 9;

        return;
    }

    clutState.bgAnimActive = 0;
}

#undef UPLOAD_BG_COLORS

void vs_main_updateColorSlots(void)
{
    int i;

    for (i = 0; i < 17; ++i) {

        CVECTOR position;
        ColorSlot* slots = clutState.colorSlots;
        ColorSlot* slot = &slots[i];
        Fade* fade = &slot->fade;

        if (slot->active == 0) {
            continue;
        }

        // Advance the colour by its step
        fade->current.r += fade->step.r;
        fade->current.g += fade->step.g;
        fade->current.b += fade->step.b;

        SLOT_POSITION(position, fade);

        if (i != 0) {
            func_800A0768(i - 1, &position);
        } else {
            slots[0].grayAmount += slots[0].grayStep;
            func_8008B430(&position, slots[0].grayAmount >> 2);
        }

        ++slot->frame;

        if (slot->frame < (slot->speed * 2)) {
            continue;
        }

        // Modes 9 and 10 pulse (half the target, then the full target); 14 fades to 15
        if (slot->mode == 9) {

            vs_main_transformColorSlot(4, slot->speed, i, slot->pulseTarget[0] / 2,
                slot->pulseTarget[1] / 2, slot->pulseTarget[2] / 2);

            slot->mode = 10;

        } else if (slot->mode == 10) {

            transformColorSlot(9, slot->speed, i, slot->pulseTarget[0],
                slot->pulseTarget[1], slot->pulseTarget[2]);

            slot->mode = 9;

        } else if (slot->mode == 14) {

            transformColorSlot(15, slot->speed, i, 0, 0, 0);
            slot->mode = 15;

        } else {
            slot->active = 0;
        }
    }
}

#undef SLOT_POSITION

void vs_main_updateClutSlots(void)
{
    int i;

    for (i = 0; i < 14; ++i) {

        if (clutState.slots[i].animState.active == 0) {
            continue;
        }

        if (++clutState.slots[i].animState.tick
            >= (clutState.slots[i].animState.speed / 8)) {

            int j;
            u_int frameStride;
            u_short g;
            u_short r;
            u_short b;
            struct ColorInfo* index;
            int c;

            clutState.slots[i].animState.tick = 0;

            if (clutState.slots[i].animState.speed >= 8) {

                frameStride = 1;
                c = clutState.slots[i].animState.frame;
                index = clutState.slots[i].colorInfo;

                for (j = 0; j < 256; ++j) {

                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }

                    r = index[j].r + animOffset16[index[j].rindex][c];
                    g = index[j].g + animOffset16[index[j].gindex][c];
                    b = index[j].b + animOffset16[index[j].bindex][c];

                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }

                    index[j].g = g;
                    index[j].b = b;
                    index[j].r = r;
                    clutBuffer[i][j] = PACK_COLOR(r, g, b, index[j].a);
                }
            } else if (clutState.slots[i].animState.speed >= 4) {

                frameStride = 2;
                c = clutState.slots[i].animState.frame;
                index = clutState.slots[i].colorInfo;

                for (j = 0; j < 256; ++j) {

                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }

                    r = index[j].r + animOffset8[index[j].rindex][c];
                    g = index[j].g + animOffset8[index[j].gindex][c];
                    b = index[j].b + animOffset8[index[j].bindex][c];

                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }

                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    clutBuffer[i][j] = PACK_COLOR(r, g, b, index[j].a);
                }
            } else if (clutState.slots[i].animState.speed >= 2) {

                frameStride = 4;
                c = clutState.slots[i].animState.frame;
                index = clutState.slots[i].colorInfo;

                for (j = 0; j < 256; ++j) {

                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }

                    r = index[j].r + animOffset4[index[j].rindex][c];
                    g = index[j].g + animOffset4[index[j].gindex][c];
                    b = index[j].b + animOffset4[index[j].bindex][c];

                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }

                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    clutBuffer[i][j] = PACK_COLOR(r, g, b, index[j].a);
                }
            } else {

                frameStride = 8;
                c = clutState.slots[i].animState.frame;
                index = clutState.slots[i].colorInfo;

                for (j = 0; j < 256; ++j) {

                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }

                    r = index[j].r + animOffset2[index[j].rindex][c];
                    g = index[j].g + animOffset2[index[j].gindex][c];
                    b = index[j].b + animOffset2[index[j].bindex][c];

                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }

                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    clutBuffer[i][j] = PACK_COLOR(r, g, b, index[j].a);
                }
            }
            if (++clutState.slots[i].animState.frame >= (16 / frameStride)) {
                if (clutState.slots[i].animState.transitionMode == 9) {

                    transformClutSlot(4, clutState.slots[i].animState.speed, i,
                        clutState.slots[i].animState.transitionTargetR / 2,
                        clutState.slots[i].animState.transitionTargetG / 2,
                        clutState.slots[i].animState.transitionTargetB / 2);

                    clutState.slots[i].animState.transitionMode = 10;

                } else if (clutState.slots[i].animState.transitionMode == 10) {

                    transformClutSlot(9, clutState.slots[i].animState.speed, i,
                        clutState.slots[i].animState.transitionTargetR,
                        clutState.slots[i].animState.transitionTargetG,
                        clutState.slots[i].animState.transitionTargetB);

                    clutState.slots[i].animState.transitionMode = 9;

                } else if (clutState.slots[i].animState.transitionMode == 14) {

                    transformClutSlot(15, clutState.slots[i].animState.speed, i, 0, 0, 0);

                    clutState.slots[i].animState.transitionMode = 15;

                } else {
                    clutState.slots[i].animState.active = 0;
                }
            }
        }
        clutState.uploadPending = 1;
    }
}

static UNUSED void stopClutSlotAnim(int slot)
{
    clutState.slots[slot].animState.active = 0;
}

void vs_main_loadClut(u_short const* img, u_int slot, u_int colorOffset, u_int count)
{
    u_int i;

    if (slot >= 14) {
        RECT rect;

        setRECT(&rect, colorOffset + 768, slot + 224, count, 1);
        LoadImage(&rect, (u_long*)img);

        return;
    }

    if (clutState.slots[slot].locked != 0) {
        return;
    }

    clutState.slots[slot].animState.active = 0;

    for (i = 0; i < count; ++i) {

        u_short px = img[i];
        struct ColorInfo* dst = &clutState.slots[slot].colorInfo[colorOffset + i];

        clutBuffer[slot][colorOffset + i] = px;
        clutState.slots[slot].clutBase[colorOffset + i] = px;

        dst->r = colorR(px);
        dst->g = colorG(px);
        dst->b = colorB(px);
        dst->a = ((px & 0x8000) >> 15);
    }

    clutState.uploadPending = 1;
}

static void loadClutBase(int mode, u_short const* srcClut, int slot, short rOffset,
    short gOffset, short bOffset, int applyNow)
{
    int i;

    for (i = 0; i < 256; ++i) {

        short r;
        short g;
        short b;
        u_short stp;
        short value = srcClut[i];

        if (value != 0) {
            int red;
            int green;
            int blue;

            switch (mode) {
            // 5: half of the colour, plus offset
            case 5:
                r = rOffset + colorR(value) / 2;
                g = gOffset + colorG(value) / 2;
                b = bOffset + colorB(value) / 2;
                break;

            // 6, 7: the colour as a grey level, plus offset
            case 6:
                red = colorR(value);
                green = colorG(value);
                blue = colorB(value);
                r = rOffset + luminance(red, green, blue) / 6;
                g = gOffset + luminance(red, green, blue) / 6;
                b = bOffset + luminance(red, green, blue) / 6;
                break;

            case 7:
                red = colorR(value);
                green = colorG(value);
                blue = colorB(value);
                r = rOffset + luminance(red, green, blue) / 12;
                g = gOffset + luminance(red, green, blue) / 12;
                b = bOffset + luminance(red, green, blue) / 12;
                break;

            // 0 (and 8, the offset-only load): the colour plus offset
            case 0:
            default:
                r = rOffset + (value & 0x1F);
                g = gOffset + ((value & 0x3E0) >> 5);
                b = bOffset + ((value & 0x7C00) >> 10);
                break;
            }

        } else {
            // A zero entry stays zero (fully transparent)
            r = value & 0x1F;
            g = (value & 0x3E0) >> 5;
            b = (value & 0x7C00) >> 10;
        }

        stp = (u_short)value >> 15;

        CLAMP_CLUT_HIGH(r);
        CLAMP_CLUT_HIGH(g);
        CLAMP_CLUT_HIGH(b);
        CLAMP_CLUT_LOW(r);
        CLAMP_CLUT_LOW(g);
        CLAMP_CLUT_LOW(b);

        // A non-black source colour never turns fully black
        if ((((r | g | b) << 16) == 0) && (value & 0x7FFF)) {
            b = 1;
        }

        if (applyNow != 0) {
            clutBuffer[slot][i] = PACK_COLOR(r, g, b, stp);

            if (clutState.slots[slot].animState.active == 0) {
                struct ColorInfo* colors = &clutState.slots[slot].colorInfo[i];
                colors->r = r;
                colors->g = g;
                colors->b = b;
                colors->a = stp;
            }
        }

        clutState.slots[slot].clutBase[i] = PACK_COLOR(r, g, b, stp);
    }

    clutState.uploadPending = 1;
}

#undef CLAMP_CLUT_LOW
#undef CLAMP_CLUT_HIGH

static UNUSED void loadClutBaseOffset(u_short const* srcClut, int slot, u_short rOffset,
    u_short gOffset, u_short bOffset, int applyNow)
{
    loadClutBase(8, srcClut, slot, rOffset, gOffset, bOffset, applyNow);
}

void vs_main_loadBgColors(void)
{
    int i;
    Fade* bg = clutState.bgColors;
    int const* position = func_8008EB24();

    for (i = 0; i < 5; ++i) {
        clutState.bgBaseColors[i].r = position[i];
        clutState.bgBaseColors[i].g = (position[i] & 0xFF00) / 256;
        clutState.bgBaseColors[i].b = (position[i] & 0xFF0000) / 65536;

        bg[i].current.r = (position[i] & 0xFF) << 16;
        bg[i].current.g = (position[i] & 0xFF00) << 8;
        bg[i].current.b = position[i] & 0xFF0000;
    }
}

void vs_main_commitClut(void)
{
    if (clutState.uploadPending != 0) {

        RECT rect;

        setRECT(&rect, 768, 224, 256, 14);
        LoadImage(&rect, (u_long*)clutBuffer[0]);

        clutState.uploadPending = 0;
    }
}

void vs_main_setClutState(int active) { clutState.active = active; }

#ifdef NON_MATCHING
#define VS_SET_CVECTOR(color, r, g, b) ((color) = (CVECTOR) { (r), (g), (b), 0 })
#else
#define VS_SET_CVECTOR(color, r, g, b) \
    (*(int*)&(color) = (r) | ((g) << 8) | ((b) << 16))
#endif

void vs_main_clutInit(void)
{
    int i;

    clutState.uploadPending = 0;
    clutState.active = 1;

    for (i = 0; i < 14; ++i) {
        clutState.slots[i].locked = 0;
        clutState.slots[i].animState.active = 0;
        clutState.slots[i].animState.transitionMode = 0;
    }

    clutState.bgAnimActive = 0;
    clutState.bgTransitionMode = 0;

    for (i = 0; i < 17; ++i) {
        clutState.colorSlots[i].active = 0;
        clutState.colorSlots[i].mode = 0;
        clutState.colorSlots[i].grayAmount = 0;
        VS_SET_CVECTOR(clutState.colorSlots[i].baseColor, 0x40, 0x40, 0x40);
        clutState.colorSlots[i].fade.current.b = 0x400000;
        clutState.colorSlots[i].fade.current.g = 0x400000;
        clutState.colorSlots[i].fade.current.r = 0x400000;
    }
}

vs_ZoneEnemyCache vs_main_zoneEnemyCache[4];
vs_Flags vs_main_stateFlags;
vs_InventoryIndices vs_main_inventoryIndices;
static UNUSED int _18[0x15E];
