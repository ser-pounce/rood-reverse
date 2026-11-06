#define VS_MAIN_INCLUDE
#include "main.h"
#undef VS_MAIN_INCLUDE
#include "common.h"
#include "overlay.h"
#include "src/BATTLE/BATTLE.PRG/actor.h"
#include "src/BATTLE/BATTLE.PRG/camera.h"
#include "src/BATTLE/BATTLE.PRG/entity.h"
#include "src/BATTLE/BATTLE.PRG/mainInterface.h"
#include "src/BATTLE/BATTLE.PRG/mpd.h"
#include "src/TITLE/TITLE.PRG/22C.h"
#include "src/ENDING/ENDING.PRG/D4.h"
#include "build/src/include/lbas.h"
#include <libapi.h>
#include <libetc.h>
#include <libpad.h>
#include <libsnd.h>
#include <libspu.h>
#include <libgpu.h>
#include <rand.h>

enum diskState_e {
    diskIdle = 0,
    diskSeekReady = 1,
    diskReadReady = 2,
    diskReadError = 4,
    diskReadInit = 5,
    diskReadXaInit = 6,
    diskStreamXa = 7,
    diskCommandFailed = 8,
    diskStreamXaEnd = 9,
};

typedef struct {
    int unk0[2];
    u_short unk8;
    u_short unkA;
    char* unkC;
    int unk10[10];
} padAct_t;

typedef struct {
    char active;
    char frame;
    char tick;
    char speed;
    char mode;
    char unk5;
    short pulseTarget[3];
    short grayAmount;
    short grayStep;
    int color[3];
    int colorStep[3];
    CVECTOR baseColor;
} _colorSlot_t;

typedef struct {
    char unk4;
    char locked;
    struct clutAnimState_t {
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
} _clutSlot;

typedef struct {
    u_short uploadPending;
    u_short active;
    _clutSlot slots[14];
    u_char bgAnimActive;
    u_char bgAnimFrame;
    u_char bgAnimTick;
    u_char bgAnimSpeed;
    u_char bgTransitionMode;
    u_char unk7E95;
    short bgTransitionTargetR;
    short bgTransitionTargetG;
    short bgTransitionTargetB;
    int bgColors[5][6];
    CVECTOR bgBaseColors[5];
    _colorSlot_t colorSlots[17];
    u_char unk8214[0x54];
} _clutState_t;

void __main(void);
static void _unlockPadModeSwitch(void);
static void _padResetDefaults(int, char[34]);
static void _padSetActData(int arg0, int arg1, int arg2);
static void _initCdQueue(void);
static void _diskReset(void);
static void _processCdQueue(void);
static void _loadMenuSound(void);
void _asmNop(void);

typedef struct {
    char wLo;
    char wHi;
    char hLo;
    char hHi;
} imgHeader_t;

extern imgHeader_t _nowLoading_header;
extern u_long _nowLoading_data[];

char _vibrationOnBank[] = { 1, 0, 0, 0, 8, 0, 0, 0, 7, 6, 0, 4, 1, 0, 0, 1, 17, 8, 2, 6,
    255, 0, 0, 0 };
char _actParams[] = { 0, 1, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0 };
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

int _soundLBAs[] = { WAVE_FILES(WAVE_LBA) };
int _musicLBAs[] = { MUSIC_FILES(MUSIC_LBA) };
int _seLBAs[] = { SEP_FILES(SEP_LBA) };
int _soundFileSizes[] = { WAVE_FILES(WAVE_SIZE) };
int _musicFileSizes[] = { MUSIC_FILES(MUSIC_SIZE) };
int _seFileSizes[] = { SEP_FILES(SEP_SIZE) };

#undef WAVE_FILES
#undef MUSIC_FILES
#undef SEP_FILES
#undef WAVE_LBA
#undef WAVE_SIZE
#undef MUSIC_LBA
#undef MUSIC_SIZE
#undef SEP_LBA
#undef SEP_SIZE

char _soundFileMap[] = { 0, 65, 66, 66, 68, 69, 67, 85, 68, 93, 69, 68, 0, 69, 69, 0, 69,
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

signed char _animOffset16[][16] = { ANIM_ROWS(ANIM_ROW16) };
signed char _animOffset8[][8] = { ANIM_ROWS(ANIM_ROW8) };
signed char _animOffset4[][4] = { ANIM_ROWS(ANIM_ROW4) };
signed char _animOffset2[][2] = { ANIM_ROWS(ANIM_ROW2) };

#undef ANIM_PROGRESS
#undef ANIM_STEP
#undef ANIM_ROW2
#undef ANIM_ROW4
#undef ANIM_ROW8
#undef ANIM_ROW16
#undef ANIM_ROWS

#include "build/assets/SLUS_010.40/vs_main_actions.h"

material_modifiers_t vs_main_materialModifiers[] = {
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

vs_main_statusEffectParams_t vs_main_statusEffectParams[] = {
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

vs_main_CdFile vs_main_zndFiles[] = { ZNDLBA(000), ZNDLBA(001), ZNDLBA(002), ZNDLBA(003),
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

static u_short vs_main_unkStrings[] = {
#include "build/assets/SLUS_010.40/vs_main_unkStrings.vsString"
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

static UNUSED u_char _artsActionIds[][4] = {
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

static void _loadBattlePrg(void)
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* slot;

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

static void _loadTitlePrg(void)
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* slot;

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

static void _loadEndingPrg(void)
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* slot;

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

static int _randArr[97];
static int _randIndex;
static vs_main_HeapHeader* _cdReadBuffer;
static UNUSED int _0;
static padAct_t _padAct[2];
static UNUSED int _1[2];
portInfo_t vs_main_portInfo[2];
static UNUSED u_char _2[2];
static vs_main_HeapHeader _heapA;
static vs_main_HeapHeader _heapB;
static DslLOC _cdReadLoc;
static int _cdaTrack;
static int _cdaMinute;
static int _cdaSecond;
static int _cdaPeak;
static UNUSED int _3;
static vs_main_CdQueueSlot _cdQueue[32];
static struct {
    short processing;
    short queued;
} _cdQueueCount;
static UNUSED int _4;
vs_main_battleTimer_t vs_main_battleTimer;
int vs_main_startState;
static int _sp2;
static u_short _sfxData[0x2C00];
int vs_main_buttonsReleased;
static UNUSED int _5;
void* vs_main_ot[2];
static int _resetEnabled;
static UNUSED int _6;
static u_int _buttonHeldFrameCount[32];
vs_main_disk_t vs_main_disk;
static _clutState_t _clutState;
vs_main_stickPos vs_main_stickPosBuf;
static int _sp;
short vs_main_screenX;
short vs_main_screenWidth;
short vs_main_screenY;
u_short vs_main_screenHeight;
int vs_main_buttonRepeat;
static UNUSED int _7[4];
char vs_main_padBuffer[2][34];
static UNUSED int _8;
soundData_t vs_main_soundData;
void* vs_main_prims[2];
int vs_main_nearClip;
static UNUSED int _9;
DRAWENV vs_main_drawEnv[2];
DISPENV vs_main_dispEnv[2];
static UNUSED int _10[4];

static void _initScreen(
    int w, int h, UNUSED int arg2, UNUSED int arg3, UNUSED int arg4, UNUSED int arg5)
{
    SetDefDispEnv(vs_main_dispEnv, 0, 0, w, h - 16);
    setRECT(&vs_main_dispEnv[0].screen, 0, 8, 256, 224);
    PutDispEnv(vs_main_dispEnv);
}

#define IMG_W(header) (header.wLo + (header.wHi << 8))
#define IMG_H(header) (header.hLo + (header.hHi << 8))

int vs_main_buttonsPreviousState;
int vs_main_unused0;
static UNUSED int _11[2];
vs_main_buttonsPressed_t vs_main_buttonsPressed;
int vs_main_unused1;
u_int vs_main_frameDuration;
static UNUSED int _12[13];
int vs_main_frameBuf;
int vs_main_saveGameClearData;
MATRIX vs_main_cameraBasis;
int vs_main_buttonsState;
static UNUSED int _14;
static int _inGame;
int vs_main_unused2;
int vs_main_projectionDistance;

static void _displayLoadingScreen(void)
{
    RECT rect;

    _initScreen(0x140, 0xF0, vs_main_projectionDistance, 0, 0, 0);
    setRECT(&rect, 0, 0, 1024, 512);
    ClearImage2(&rect, 0, 0, 0);
    DrawSync(0);
    VSync(2);
    setRECT(&rect, (320 - IMG_W(_nowLoading_header)) / 2,
        (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
        IMG_H(_nowLoading_header));
    LoadImage(&rect, (u_long*)&_nowLoading_header + 1);
    setRECT(&rect, ((320 - IMG_W(_nowLoading_header)) / 2) + 320,
        (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
        IMG_H(_nowLoading_header));
    LoadImage(&rect, (u_long*)&_nowLoading_header + 1);
    DrawSync(0);
    SetDispMask(1);
}

static void _bufferLoadingScreen(void)
{
    RECT rect;

    if (vs_main_frameBuf != 0) {
        setRECT(&rect, (320 - IMG_W(_nowLoading_header)) / 2,
            (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
            IMG_H(_nowLoading_header));
    } else {
        setRECT(&rect, (320 - IMG_W(_nowLoading_header)) / 2 + 320,
            (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
            IMG_H(_nowLoading_header));
    }
    LoadImage(&rect, _nowLoading_data);
    DrawSync(0);
}

void vs_main_resetGame(void)
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(0x10, vs_main_padBuffer[1]);
    TeardownSound();
    SpuQuit();
    ResetGraph(3);
    VSync(10);
    vs_overlay_jumpToTitle(&_sp2);
}

void vs_main_jumpToBattle(void)
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(0x10, vs_main_padBuffer[1]);
    ResetGraph(3);
    Sound_StopMusic();
    Sound_StopSfx();
    Sound_ClearSuspendedMusic();
    Sound_ResetMusicBankIds();
    _displayLoadingScreen();
    _loadBattlePrg();
    vs_main_startState = 1;
    vs_overlay_jumpToBattle(&_sp);
}

void vs_main_showEndingAndReturnToTitle(void)
{
    _inGame = 0;
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(0x10, vs_main_padBuffer[1]);
    ResetGraph(3);
    Sound_StopMusic();
    Sound_StopSfx();
    vs_main_captureSaveState();
    _loadEndingPrg();
    vs_ending_exec();
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(0x10, vs_main_padBuffer[1]);
    TeardownSound();
    SpuQuit();
    ResetGraph(3);
    vs_main_saveGameClearData = 1;
    vs_overlay_jumpToTitle(&_sp2);
}

int vs_gametime_tickspeed;
static u_short _clutBuffer[14][256];
static UNUSED int _15[8];
static int _nextVoicePool0;
static int _nextVoicePool1;
static int _nextVoicePool2;
static int _nextVoicePool3;
static int _nextVoicePool4;
static int _nextVoicePool5;
static UNUSED int _16[6];
vs_main_scoredata_t vs_main_scoredata;
static UNUSED int _17;
char vs_main_actionsLearned[32];
vs_main_mapStatus_t vs_main_mapStatus;
vs_main_settings_t vs_main_settings;
vs_main_artsStatus_t vs_main_artsStatus;
int vs_main_zoneEnemyCacheIndex;
vs_main_characterSnapshot_t vs_main_characterSnapshot;
vs_main_inventory_t vs_main_inventory;
_mpdRoomDoorSection_t vs_main_spawnPoint;
vs_Gametime_t vs_main_gametime;

int vs_main_gametimeUpdate(int vsync)
{
    int vs = VSync(vsync);
    if (vsync != 1) {
        _asmNop();
    }

    _processCdQueue();

    if (vs_main_gametime.t.h >= 100) {
        return vs;
    }

    vs_main_gametime.t.f += vs_gametime_tickspeed;

    if (vs_main_gametime.t.f < 60) {
        return vs;
    }

    vs_main_gametime.t.f = 0;

    if (++vs_main_gametime.t.s < 60) {
        return vs;
    }

    vs_main_gametime.t.s = 0;

    if (++vs_main_gametime.t.m < 60) {
        return vs;
    }

    vs_main_gametime.t.m = 0;

    if (++vs_main_gametime.t.h >= 100) {
        vs_main_gametime.t.h = 100;
    }
    return vs;
}

static void _gpuSyncVoidCallback(void) { }

static void _vSyncVoidCallback(void) { }

static void _nop0(void) { }

static void _nop1(void) { }

static void _mainNop2(void) { }

static void _nop3(void) { }

static void _initRand(void)
{
    int i;

    srand(1);

    for (i = 0; i < (int)(sizeof _randArr / sizeof _randArr[0]); ++i) {
        _randArr[i] = rand();
    }
    _randIndex = (sizeof _randArr / sizeof _randArr[0]) - 1;
}

int vs_main_getRand(int max)
{
    int temp_s0;
    int var_a0;
    int var_v0;

    var_v0 = _randArr[_randIndex] * (sizeof _randArr / sizeof _randArr[0]);

    if (var_v0 < 0) {
        var_v0 += 0x7FFF;
    }

    _randIndex = var_v0 >> 0xF;

    temp_s0 = 0x7FFF - _randArr[_randIndex];
    _randArr[_randIndex] = rand();

    var_a0 = temp_s0 * max;

    if (var_a0 < 0) {
        var_a0 += 0x7FFF;
    }

    return var_a0 >> 0xF;
}

int vs_main_getRandSmoothed(int arg0)
{
    return (vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0)
               + vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0)
               + vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0)
               + vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0))
         / 12;
}

static void _sysInit(void)
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
    _padResetDefaults(0, vs_main_padBuffer[0]);
    _padResetDefaults(0x10, vs_main_padBuffer[1]);
    PadStartCom();
    _unlockPadModeSwitch();
    vs_main_resetPadAct();
    SsUtReverbOff();
    DsInit();
    _initRand();
    _resetEnabled = 1;
    vs_main_saveGameClearData = 0;
}

static void _sysReinit(void)
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
    _displayLoadingScreen();
    SsUtReverbOn();
    InitGeom();
    DrawSyncCallback(_gpuSyncVoidCallback);
    VSyncCallback(_vSyncVoidCallback);
    vs_main_initHeap((vs_main_HeapHeader*)0x8010C000, 0xF2000);
    _initCdQueue();
    _diskReset();
    _loadMenuSound();
    vs_main_resetPadAct();
    _inGame = 0;
    _unlockPadModeSwitch();

    for (i = 31; i >= 0; --i) {
        _buttonHeldFrameCount[i] = 0;
    }
    vs_main_gametime.t.h = 0;
    vs_main_gametime.t.m = 0;
    vs_main_gametime.t.s = 0;
    vs_main_gametime.t.f = 0;
    vs_main_characterSnapshot.stats.restorePending = 0;
}

int vs_main_execTitle(void)
{
    vs_overlay_getSp(&_sp);
    _sysReinit();
    _loadTitlePrg();
    vs_main_startState = vs_title_exec();
    vs_main_saveGameClearData = 0;
    _displayLoadingScreen();
    _loadBattlePrg();
    vs_overlay_getSp(&_sp);
    _inGame = 1;
    vs_battle_exec();
    SetDispMask(0);
    vs_main_stopMusic();
    return 0;
}

void vs_main_exec(void)
{
    __main();
    _sysInit();
    vs_overlay_getSp(&_sp2);
    vs_main_execTitle();
}

void vs_main_wait(void) { vs_overlay_wait(); }

void vs_main_enableReset(int enable) { _resetEnabled = enable; }

void vs_main_setCharacterRestorePending(void)
{
    vs_main_characterSnapshot.stats.restorePending = 1;
}

void vs_main_captureSaveState(void)
{
    func_8006EBF8_t sp10;
    int j;
    int i;
    int var_s1;
    int var_t3;
    int new_var;
    int var_t4;
    signed char actionsLearned;
    vs_battle_actor2* temp_t0;
    vs_main_characterSnapshot_t* temp_t5;
    int v0;
    int v0_2;
    int v1;
    int v1_2;

    vs_main_spawnPoint = D_800F1AB0;
    func_800A1108(0, &sp10);

    vs_main_spawnPoint.x = sp10.unk0.unk0.x;
    vs_main_spawnPoint.z = sp10.unk0.unk0.z;
    vs_main_spawnPoint.unk2.unk0_13 = sp10.unk0.unk0.y;
    vs_main_spawnPoint.facing = sp10.unk0.unk0.status >> 6;
    vs_main_spawnPoint.unk6_0 = D_800F18E8.unk0_0;

    for (var_s1 = 0; var_s1 < 32; ++var_s1) {
        for (actionsLearned = 0, i = 0; i < 8; ++i) {
            actionsLearned =
                (*(int*)&actionsLearned * 2) | vs_main_actions[var_s1 * 8 + i].unlocked;
        }
        vs_main_actionsLearned[var_s1] = actionsLearned;
    }
    temp_t0 = vs_battle_characterState->unk3C;
    temp_t5 = &vs_main_characterSnapshot;
    temp_t5->stats.currentHP = temp_t0->currentHP;
    temp_t5->stats.maxHP = temp_t0->maxHP;
    temp_t5->stats.currentMP = temp_t0->currentMP;
    temp_t5->stats.maxMP = temp_t0->maxMP;
    temp_t5->stats.strength = temp_t0->strength;
    temp_t5->stats.totalStrength = temp_t0->totalStrength;
    temp_t5->stats.intelligence = temp_t0->intelligence;
    temp_t5->stats.totalIntelligence = temp_t0->totalIntelligence;
    temp_t5->stats.agility = temp_t0->agility;
    temp_t5->stats.totalAgility = temp_t0->totalAgility;
    temp_t5->stats.risk = temp_t0->risk;
    temp_t5->stats.flags = temp_t0->unk954;
    temp_t5->stats.statuses = temp_t0->statuses;

    for (i = 0; i < 8; ++i) {
        temp_t5->stats.statusTimers[i] = temp_t0->statusTimers[i];
    }

    var_t4 = 0;
    var_t3 = 0;

    for (i = 0; i < 6; ++i) {
        temp_t5->stats.limbs[i].hp = temp_t0->limbs[i].hp;
        temp_t5->stats.limbs[i].maxHp = temp_t0->limbs[i].maxHp;

        for (j = 0; j < 4; ++j) {
            temp_t5->stats.limbs[i].types[j] = temp_t0->limbs[i].types[j];
        }

        for (j = 0; j < 8; ++j) {
            temp_t5->stats.limbs[i].affinities[j] = temp_t0->limbs[i].affinities[j];
        }
    }

    temp_t5->stats.weaponDrawn = vs_battle_characterState->weaponDrawn;
    temp_t5->stats.cameraPitch = vs_battle_cameraCurrentSpherical.delta.pitch;
    temp_t5->stats.cameraDistance = vs_battle_cameraCurrentSpherical.initialDistance;

    for (var_s1 = 0; var_s1 < 16; ++var_s1) {
        vs_battle_saveEnemyState(var_s1, 0);
    }
    vs_battle_setDoorEntered();
}

void vs_main_padDisconnectAll(void)
{
    vs_main_portInfo[0].connected = 0;
    vs_main_portInfo[1].connected = 0;
}

static void _unlockPadModeSwitch(void)
{
    vs_main_padDisconnectAll();
    if (PadInfoMode(0, InfoModeCurExID, 0) != 0) {
        PadSetMainMode(0, 1, 2);
    }
}

static void _padResetDefaults(int portID, UNUSED char padBuf[34])
{
    portInfo_t* port = &vs_main_portInfo[portID >> 4];
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
    PadSetActAlign(portID, _actParams);
}

int vs_main_updatePadState(int portID, char padBuf[34])
{
    portInfo_t* port;
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

void vs_main_padConnect(int portID, char padBuf[34])
{
    UNUSED int dummy[5];

    portInfo_t* port = &vs_main_portInfo[portID >> 4];
    int state = PadGetState(portID);

    if (state == PadStateFindPad) {
        port->connected = 0;
    }
    if (port->connected == 0) {
        PadSetAct(portID, port->actData, sizeof port->actData);
        if ((state == PadStateFindCTP1)
            || ((state == PadStateStable) && (PadSetActAlign(portID, _actParams) != 0))) {
            _padResetDefaults(portID, padBuf);
            port->connected = 1;
        }
    }
}

static void _padSetActData(int port, int pos, int val)
{
    if (pos != 0) {
        vs_main_portInfo[port].actData[pos] = val;
    } else if (vs_main_portInfo[port].exId) {
        vs_main_portInfo[port].actData[0] = val;
    } else {
        vs_main_portInfo[port].actData[0] = 0x40;
    }
}

static char _padGetActData(int port, int pos)
{
    return vs_main_portInfo[port].actData[pos];
}

int vs_main_setVibrationBank(char* arg0, u_int arg1, int arg2)
{
    int i;
    int ret = 0;

    if (arg1 == 0xFF) {
        for (i = 0; i < 2; ++i) {
            if (_padAct[i].unk8 == 0) {
                ret = i + 1;
                break;
            }
        }
    } else if ((arg1 - 1) < 2) {
        ret = arg1;
    }

    if (ret != 0) {
        i = ret - 1;
        _padAct[i].unkC = arg0;
        _padAct[i].unk10[4] = 1;
        _padAct[i].unk10[10] = *arg0;
        _padAct[i].unk10[11] = 0;
        _padAct[i].unk10[5] = 0;
        _padAct[i].unk10[7] = 0;
        _padAct[i].unk10[1] = 0;
        _padAct[i].unk8 = 1;
        _padAct[i].unkA = arg2;
        return ret;
    }
    return 0;
}

static int _clearVibrationSlot(int arg0)
{
    int i = arg0 - 1;
    _padAct[i].unk10[7] = 0;
    _padAct[i].unk10[1] = 0;
    _padAct[i].unkC = 0;
    _padAct[i].unk8 = 0;

    return arg0;
}

int vs_main_stopVibration(u_int arg0, int arg1)
{
    int i;
    if (arg0 - 1 < 2) {
        return _clearVibrationSlot(arg0);
    }
    if (arg0 != 0) {
        return 0;
    }
    if (arg1 != 0) {
        for (i = 0; i < 2; ++i) {
            if (_padAct[i].unkA == arg1) {
                _clearVibrationSlot(i + 1);
            }
        }
    } else {
        for (i = 0; i < 2;) {
            _clearVibrationSlot(++i);
        }
    }
    return 1;
}

static int _pauseVibrationSlot(int arg0)
{
    int v0 = arg0 - 1;
    _padAct[v0].unk8 = 0;
    return arg0;
}

static UNUSED int _pauseVibration(int arg0)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return _pauseVibrationSlot(arg0);
    }

    if (arg0 != 0) {
        return 0;
    }

    for (i = 0; i < 2;) {
        _pauseVibrationSlot(++i);
    }

    return 1;
}

static int _resumeVibrationSlot(int arg0)
{
    int v0 = arg0 - 1;
    _padAct[v0].unk8 = 1;
    return arg0;
}

static UNUSED int _resumeVibration(int arg0)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return _resumeVibrationSlot(arg0);
    }

    if (arg0 != 0) {
        return 0;
    }

    for (i = 0; i < 2;) {
        _resumeVibrationSlot(++i);
    }

    return 1;
}

void vs_main_resetPadAct(void)
{
    int i;

    vs_main_padDisconnectAll();

    for (i = 0; i < 2; ++i) {
        _padAct[i].unkC = NULL;
        _padAct[i].unk10[7] = 0;
        _padAct[i].unk10[1] = 0;
        _padAct[i].unk8 = 0;
    }
}

static inline int _abs2(int arg) { return arg < 0 ? arg += 0xFF : arg; }

void vs_main_setVibrateParams(void)
{
    int temp_a0;
    int var_a2_2;
    int i;
    int j;
    int var_v0;
    char* temp_t1;
    int new_var;

    _padAct[0].unk0[1] = 0;
    _padAct[0].unk0[0] = 0;

    for (j = 0; j < 2; ++j) {
        if (_padAct[j].unk8 == 0) {
            continue;
        }

        temp_t1 = _padAct[j].unkC;

        if (temp_t1 != 0) {
            for (i = 0; i < 2; ++i) {
                int (*a1)[6] = (int (*)[6])_padAct[j].unk10;
                if (a1[i][5] == 0) {
                    temp_a0 = a1[i][4];
                    a1[i][5] = temp_t1[temp_a0++];
                    a1[i][1] = a1[i][3] = temp_t1[temp_a0++] << 8;
                    if (a1[i][5] == 0) {
                        a1[i][1] = 0;
                        a1[i][0] = 0;
                    } else {
                        new_var = i != 0;
                        a1[i][3] = temp_t1[temp_a0 + 1] << 8;
                        if (new_var) {
                            a1[i][2] = ((a1[i][3] - a1[i][1]) / a1[i][5]);
                        } else {
                            a1[i][2] = 0;
                        }
                        a1[i][0] = 1;
                        a1[i][4] += 2;
                    }
                }
                if (a1[i][5] != 0) {
                    a1[i][1] += a1[i][2];
                    a1[i][5] -= 1;
                } else {
                    a1[i][1] = a1[i][3];
                }

                _padAct[0].unk0[i] += a1[i][1];
                if (_padAct[0].unk0[i] > 0xFF00) {
                    _padAct[0].unk0[i] = 0xFF00;
                } else if (_padAct[0].unk0[i] < 0) {
                    _padAct[0].unk0[i] = 0;
                }
            }
            _padAct[j].unk8 = _padAct[j].unk10[0] | _padAct[j].unk10[6];
            if (_padAct[j].unk8 == 0) {
                _padAct[j].unkC = 0;
            }
            continue;
        }
        _padAct[j].unk8 = 0;
    }

    if (vs_main_settings.vibrationOn != 0) {
        _padSetActData(0, 0, _abs2(_padAct[0].unk0[0]) >> 8);
        _padSetActData(0, 1, _abs2(_padAct[0].unk0[1]) >> 8);
    }
}

void vs_main_vibrationOnEffect(int arg0)
{
    if (arg0 < _vibrationOnBank[0]) {
        int new_var = 5;
        int new_var3 = 4;
        int new_var4 = 6;
        int new_var2 = 7;
        vs_main_setVibrationBank(
            &_vibrationOnBank[_vibrationOnBank[arg0 * new_var3 + new_var3]
                              + (_vibrationOnBank[arg0 * new_var3 + new_var] << 8)
                              + (_vibrationOnBank[arg0 * new_var3 + new_var4] << 16)
                              + (_vibrationOnBank[arg0 * new_var3 + new_var2] << 24)],
            0xFF, 0x80);
    }
}

int vs_main_processPadState(void)
{
    UNUSED int dummy[2];
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
            _buttonHeldFrameCount[i] += vs_gametime_tickspeed;
        } else {
            _buttonHeldFrameCount[i] = 0;
        }
    }

    vs_main_buttonRepeat = vs_main_buttonsPressed.all;

    for (i = 0; i < 32; ++i) {
        if ((_buttonHeldFrameCount[i] >= 20) && !((_buttonHeldFrameCount[i] - 20) & 3)) {
            vs_main_buttonRepeat |= 1 << i;
        }
    }

#define VS_RESET (PADstart | PADselect | PADR1 | PADR2 | PADL1 | PADL2)

    if ((_resetEnabled != 0) && ((vs_main_buttonsPreviousState & VS_RESET) == VS_RESET)
        && (vs_main_buttonsPressed.all & VS_RESET)) {
        vs_main_settings.monoSound = 0;
        vs_main_settings.vibrationOn = 1;
        vs_main_resetGame();
    }

#undef VS_RESET

    return 1;
}

void vs_main_freeHeapR(void* block)
{
    vs_main_HeapHeader* var_a1 = _heapA.prev;
    vs_main_HeapHeader* target = (vs_main_HeapHeader*)block - 1;

    for (; var_a1 >= target || target >= var_a1->next; var_a1 = var_a1->prev) {
        if (var_a1 >= var_a1->next && ((var_a1 < target) || (target < var_a1->next))) {
            break;
        }
    }

    if ((target + target->blockSz) == var_a1->next) {
        target->blockSz += var_a1->next->blockSz;
        target->next = var_a1->next->next;
        target->next->prev = target;
    } else {
        target->next = var_a1->next;
        target->next->prev = target;
    }

    if ((var_a1 + var_a1->blockSz) == target) {
        var_a1->blockSz += target->blockSz;
        var_a1->next = target->next;
        var_a1->next->prev = var_a1;
        return;
    }
    var_a1->next = target;
    target->prev = var_a1;
}

void vs_main_freeHeap(void* block)
{
    vs_main_HeapHeader* var_a1 = _heapA.next;
    vs_main_HeapHeader* target = (vs_main_HeapHeader*)block - 1;

    for (; var_a1 >= target || target >= var_a1->next; var_a1 = var_a1->next) {
        if (var_a1 >= var_a1->next && ((var_a1 < target) || (target < var_a1->next))) {
            break;
        }
    }

    if ((target + target->blockSz) == var_a1->next) {
        target->blockSz += var_a1->next->blockSz;
        target->next = var_a1->next->next;
        target->next->prev = target;
    } else {
        target->next = var_a1->next;
        target->next->prev = target;
    }

    if ((var_a1 + var_a1->blockSz) == target) {
        var_a1->blockSz += target->blockSz;
        var_a1->next = target->next;
        var_a1->next->prev = var_a1;
        return;
    }
    var_a1->next = target;
    target->prev = var_a1;
}

void* vs_main_allocHeapR(u_int size)
{
    vs_main_HeapHeader* var_a1;
    vs_main_HeapHeader* var_a2;
    u_int blockSz;

    blockSz = ((size + 15) >> 4) + 1;
    var_a2 = &_heapA;
    var_a1 = _heapA.prev;

    while (1) {
        if (var_a1->blockSz >= blockSz) {
            if (var_a1->blockSz == blockSz) {
                var_a2->prev = var_a1->prev;
                var_a1->prev->next = var_a1->next;
            } else {
                var_a1->blockSz = var_a1->blockSz - blockSz;
                var_a1 += var_a1->blockSz;
                var_a1->blockSz = blockSz;
            }
            return (u_long*)(var_a1 + 1);
        }
        var_a2 = var_a1;
        if (var_a1 == &_heapA) {
            return 0;
        }
        var_a1 = var_a1->prev;
    }
}

void* vs_main_allocHeap(u_int size)
{
    u_int blockSz;
    vs_main_HeapHeader* var_a1;
    vs_main_HeapHeader* var_v1;

    var_v1 = &_heapA;
    var_a1 = _heapA.next;
    blockSz = ((size + 0xF) >> 4) + 1;

    while (1) {
        if (var_a1->blockSz >= blockSz) {
            if (var_a1->blockSz == blockSz) {
                var_v1->next = var_a1->next;
                var_a1->next->prev = var_a1->prev;
            } else {
                vs_main_HeapHeader* temp_v1 = var_a1 + blockSz;
                temp_v1->blockSz = var_a1->blockSz - blockSz;
                temp_v1->prev = var_a1->prev;
                temp_v1->next = var_a1->next;
                temp_v1->prev->next = temp_v1;
                temp_v1->next->prev = temp_v1;
                var_a1->blockSz = blockSz;
            }
            return (u_long*)(var_a1 + 1);
        }
        var_v1 = var_a1;
        if (var_a1 == &_heapA) {
            return 0;
        }
        var_a1 = var_a1->next;
    }
}

void vs_main_initHeap(vs_main_HeapHeader* node, u_int value)
{
    _heapA.prev = node;
    _heapA.next = node;
    _heapA.blockSz = 0;
    node->prev = &_heapA;
    node->next = &_heapA;
    node->blockSz = value / 16 - 1;
    _heapB.prev = &_heapB;
    _heapB.next = &_heapB;
    _heapB.blockSz = 0;
}

static void _diskReadCallback(u_char intr, UNUSED u_char result[], UNUSED u_long* arg2)
{

    if ((intr == DslDiskError) || (intr == DslNoIntr)
        || (vs_main_disk.state == diskReadError)) {
        DsReadyCallback(0);
        DsEndReadySystem();
        vs_main_disk.state = diskReadError;
        return;
    }

    if (intr != DslDataReady) {
        return;
    }

    vs_main_disk.state = diskReadReady;

    if (vs_main_disk.bufferMode == cdBufferModeNone) {
        DsGetSector(vs_main_disk.vram + vs_main_disk.sectorBufIndex * 2048, 512);
    } else {
        DsGetSector(_cdReadBuffer + vs_main_disk.unk3C * 128, 512);
        if (++vs_main_disk.unk3C >= 16) {
            vs_main_disk.unk3C = 0;
        }
    }

    switch (vs_main_disk.bufferMode) {
    case cdBufferModeNone:
        if (++vs_main_disk.sectorBufIndex >= vs_main_disk.sectorCount) {
            vs_main_disk.state = diskIdle;
        }
        break;
    case cdBufferModeBuffered:
        ++vs_main_disk.unk38;
        ++vs_main_disk.unk34;
        break;
    case cdBufferModeManual:
        ++vs_main_disk.unk38;
        if (++vs_main_disk.ringBufIndex >= 16) {
            vs_main_disk.ringBufIndex = 0;
        }
        break;
    default:
        break;
    }

    if (++vs_main_disk.unk4 >= vs_main_disk.sectorCount) {
        DsEndReadySystem();
    }
}

static void _diskReadCommandCallback(u_char intr, UNUSED u_char result[])
{
    switch (intr) {
    case DslComplete:
        DsStartReadySystem(_diskReadCallback, -1);
        return;
    case DslDiskError:
        break;
    default:
        break;
    case DslNoResult:
    case DslNoIntr:
        return;
    }
    vs_main_disk.state = diskReadError;
}

static void _diskSeekCommandCallback(u_char intr, UNUSED u_char result[])
{
    switch (intr) {
    case DslNoIntr:
        break;
    case DslComplete:
        vs_main_disk.state = diskIdle;
        break;
    case DslDiskError:
        vs_main_disk.state = diskReadError;
        break;
    case DslNoResult:
        break;
    default:
        vs_main_disk.state = diskReadError;
        break;
    }
}

static void _diskPcmReadReady(u_char intr, u_char result[])
{
    switch (intr) {
    case DslComplete:
        DsReadyCallback(NULL);
        vs_main_disk.state = diskIdle;
        break;
    case DslDataReady:
        if (!(result[4] & 0x80)) {
            _cdaTrack = ((result[1] >> 4) * 0xA) + (result[1] & 0xF);
            _cdaMinute = result[3];
            _cdaSecond = result[4];
            _cdaPeak = (result[6] << 8) | result[7];
        }
        break;
    case DslDiskError:
        DsReadyCallback(NULL);
        vs_main_disk.state = diskCommandFailed;
        break;
    }
}

static int _diskGetState(void) { return vs_main_disk.state; }

static void _diskClearError(void)
{
    if (vs_main_disk.state == diskReadError) {
        vs_main_disk.state = diskIdle;
    }
}

static int _diskInitRead(int sector, u_int bytes, void* vram)
{
    if (vs_main_disk.state == diskIdle) {
        vs_main_disk.cdSector = sector;
        vs_main_disk.request.byteCount = bytes;
        vs_main_disk.vram = vram;
        vs_main_disk.ringBufIndex = 0;
        vs_main_disk.unk3C = 0;
        vs_main_disk.sectorBufIndex = 0;
        vs_main_disk.unk34 = 0;
        vs_main_disk.unk4 = 0;
        vs_main_disk.unk3 = 0;
        vs_main_disk.unk38 = 0;
        vs_main_disk.sectorCount = bytes / 2048;
        if (bytes % 2048) {
            ++vs_main_disk.sectorCount;
        }
        DsIntToPos(sector, &vs_main_disk.cdLoc);
        vs_main_disk.state = diskReadInit;
        return 1;
    }
    return 0;
}

static void _diskUpdate(void)
{
    DslATV vol;
    int i;
    u_int seconds;

    switch (vs_main_disk.state) {
    case diskIdle:
    default:
        break;
    case diskReadXaInit:
        if (DsSystemStatus() == DslReady) {
            vs_main_disk.unk1 = 0;
            vs_main_disk.cdLoc.minute = 0;
            while (DsControlB(DslSetmode, (u_char*)&vs_main_disk.cdLoc, NULL) == 0)
                ;
            VSync(3);
            vol.val2 = 0x80;
            vol.val0 = 0x80;
            vol.val3 = 0;
            vol.val1 = 0;
            DsMix(&vol);
            Sound_SetCdVolume(vs_main_disk.request.cdVolume);
            Sound_SetCdMixVolume(0x7F);
            vs_main_disk.pcm.file = 1;
            vs_main_disk.pcm.chan = 0;
            DsControl(DslSetfilter, (char*)&vs_main_disk.pcm, NULL);
            DsIntToPos(vs_main_disk.cdSector, &vs_main_disk.cdLoc);
            vs_main_disk.commandId =
                DsPacket(DslModeRT | DslModeSF, &vs_main_disk.cdLoc, DslReadS, NULL, -1);
            DsReadyCallback(_diskPcmReadReady);
            vs_main_disk.state = diskStreamXa;
        }
        if (vs_main_disk.commandId == 0) {
            DsReadyCallback(0);
            vs_main_disk.state = diskCommandFailed;
            ++vs_main_disk.unk3;
        }
        break;
    case diskReadInit: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            vs_main_disk.unk4 = 0;
            vs_main_disk.sectorBufIndex = 0;
            if (vs_main_disk.request.byteCount != 0) {
                vs_main_disk.state = diskReadReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslReadN, _diskReadCommandCallback, -1);
            } else {
                vs_main_disk.state = diskSeekReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslSeekL, _diskSeekCommandCallback, -1);
            }

            if (vs_main_disk.commandId == 0) {
                vs_main_disk.state = diskReadError;
                ++vs_main_disk.unk3;
            }
        }
        break;
    }
    case diskCommandFailed: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            vs_main_disk.unk4 = 0;
            ++vs_main_disk.unk3;
            seconds = vs_main_frameDuration / 60;
            if (seconds < 420) {
                DsIntToPos(
                    vs_main_disk.cdSector + (seconds * 75) + (vs_main_frameDuration % 60),
                    &_cdReadLoc);
                vol.val2 = 0x80;
                vol.val0 = 0x80;
                vol.val3 = 0;
                vol.val1 = 0;
                DsMix(&vol);
                Sound_SetCdVolume(0);
                Sound_FadeCdVolume(0x3C, vs_main_disk.request.cdVolume);
                vs_main_disk.pcm.file = 1;
                vs_main_disk.pcm.chan = 0;
                DsControl(DslSetfilter, (char*)&vs_main_disk.pcm, NULL);
                vs_main_disk.commandId =
                    DsPacket(DslModeRT | DslModeSF, &_cdReadLoc, DslReadS, NULL, -1);
                DsReadyCallback(_diskPcmReadReady);
                vs_main_disk.state = diskStreamXa;
            } else {
                vs_main_disk.commandId = DsCommand(DslModeSF | DslModeDA, NULL, NULL, -1);
                vs_main_disk.state = diskIdle;
                DsReadyCallback(0);
            }
        }
        if (vs_main_disk.commandId == 0) {
            vs_main_disk.state = diskCommandFailed;
            ++vs_main_disk.unk3;
        }
        break;
    }
    case diskReadError: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            vs_main_disk.unk4 = 0;
            vs_main_disk.sectorBufIndex = 0;
            ++vs_main_disk.unk3;

            if (vs_main_disk.request.byteCount != 0) {
                vs_main_disk.state = diskReadReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslReadN, _diskReadCommandCallback, -1);
            } else {
                vs_main_disk.state = diskSeekReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslSeekL, _diskSeekCommandCallback, -1);
            }

            if (vs_main_disk.commandId == 0) {
                vs_main_disk.state = diskReadError;
                ++vs_main_disk.unk3;
            }
        }
        break;
    }
    case diskStreamXaEnd:
        Sound_SetCdVolume(0);
        vs_main_disk.commandId = DsCommand(DslPause, NULL, NULL, -1);
        if (vs_main_disk.commandId > 0) {
            vs_main_disk.state = diskIdle;
        }
        DsReadyCallback(NULL);
        vs_main_disk.unk1 = 128;
        vs_main_disk.cdLoc.minute = 128;
        while (DsControlB(DslSetmode, (u_char*)&vs_main_disk.cdLoc, NULL) == 0)
            ;
        VSync(3);
        break;
    }

    if (vs_main_disk.bufferMode != cdBufferModeNone) {
        for (i = 0; i < 16; ++i) {
            if (vs_main_disk.sectorBufIndex >= vs_main_disk.unk38) {
                return;
            }
            if (vs_main_disk.bufferMode == cdBufferModeBuffered) {
                vs_main_memcpy(
                    ((char*)vs_main_disk.vram + (vs_main_disk.sectorBufIndex * 2048)),
                    _cdReadBuffer + (vs_main_disk.ringBufIndex * 128), 2048);

                ++vs_main_disk.ringBufIndex;
                if (vs_main_disk.ringBufIndex >= 16) {
                    vs_main_disk.ringBufIndex = 0;
                }
                --vs_main_disk.unk34;
                ++vs_main_disk.sectorBufIndex;
                if (vs_main_disk.sectorBufIndex >= vs_main_disk.sectorCount) {
                    vs_main_disk.state = diskIdle;
                    vs_main_freeHeapR(_cdReadBuffer);
                    _cdReadBuffer = NULL;
                }
            } else if (vs_main_disk.bufferMode == cdBufferModeManual) {
                ++vs_main_disk.sectorBufIndex;
                if ((vs_main_disk.sectorBufIndex >= vs_main_disk.sectorCount)
                    && (IsSpuTransferring() == 0)) {
                    vs_main_disk.state = diskIdle;
                    vs_main_freeHeapR(_cdReadBuffer);
                    _cdReadBuffer = NULL;
                }
            }
        }
    }
}

int vs_main_diskLoadFile(int sector, int bytes, void* vram)
{
    int result = _diskInitRead(sector, bytes, vram);
    if (result != 0) {
        int seekReady = diskSeekReady;
        int readReady = diskReadReady;

        while (1) {
            if (_diskGetState() == seekReady) {
                vs_main_gametimeUpdate(0);
            } else if (_diskGetState() == readReady) {
                vs_main_gametimeUpdate(0);
            } else if (_diskGetState() == 3) {
                vs_main_gametimeUpdate(0);
            } else if (_diskGetState() == diskReadInit) {
                vs_main_gametimeUpdate(0);
            } else {
                break;
            }
        }
    }
    return result;
}

int vs_main_streamXa(int sector, int cdVolume)
{
    if (vs_main_disk.state == diskIdle) {
        vs_main_disk.cdSector = sector;
        vs_main_disk.request.cdVolume = cdVolume;
        vs_main_disk.ringBufIndex = 0;
        vs_main_disk.unk3C = 0;
        vs_main_disk.sectorBufIndex = 0;
        vs_main_disk.unk34 = 0;
        vs_main_disk.unk4 = 0;
        vs_main_disk.unk3 = 0;
        vs_main_disk.unk38 = 0;
        vs_main_disk.state = diskReadXaInit;
        return 1;
    }
    return 0;
}

int vs_main_checkStreamXaEnd(void)
{
    if (vs_main_disk.state == diskStreamXa) {
        vs_main_disk.state = diskStreamXaEnd;
        return 1;
    }
    return 0;
}

static void _diskReset(void)
{
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    vs_main_disk.unk1 = 128;
    vs_main_disk.cdLoc.minute = 128;
    vs_main_disk.unk2 = 0;
    vs_main_disk.state = diskIdle;
    vs_main_disk.bufferMode = cdBufferModeNone;
    _cdReadBuffer = NULL;
    while (DsControlB(DslSetmode, (u_char*)&vs_main_disk.cdLoc, NULL) == 0)
        ;
    VSync(3);
}

static void _initCdQueue(void)
{
    int i;

    for (i = 31; i >= 0; --i) {
        _cdQueue[i].state = vs_main_CdQueueStateFree;
    }
    *(int*)&_cdQueueCount = 0;
}

vs_main_CdQueueSlot* vs_main_allocateCdQueueSlot(vs_main_CdFile const* file)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (_cdQueue[i].state == vs_main_CdQueueStateFree) {
            _cdQueue[i].state = vs_main_CdQueueStateAllocated;
            _cdQueue[i].cdFile = *file;
            return &_cdQueue[i];
        }
    }
    vs_main_nop9(162, 0);
}

void vs_main_freeCdQueueSlot(vs_main_CdQueueSlot* slot)
{
    u_short state = slot->state - 2;
    if (state < vs_main_CdQueueStateLoaded - 2) {
        vs_main_nop9(163, 0);
    }
    slot->state = vs_main_CdQueueStateFree;
}

void vs_main_cdEnqueue(vs_main_CdQueueSlot* slot, void* vram)
{
    slot->state = vs_main_CdQueueStateEnqueued;
    slot->vram = vram;
    slot->unkC = 0;
    slot->priority = _cdQueueCount.queued++;
}

void vs_main_cdEnqueuePriority(vs_main_CdQueueSlot* slot, void* vram)
{
    int i;
    vs_main_CdQueueSlot* queue = _cdQueue;

    for (i = 0; i < 32; ++i, ++queue) {
        if (queue->state == vs_main_CdQueueStateEnqueued) {
            ++queue->priority;
        }
    }
    slot->state = vs_main_CdQueueStateEnqueued;
    slot->vram = vram;
    slot->unkC = 0;
    slot->priority = 0;
    ++_cdQueueCount.queued;
}

static void _nop4(void) { }

static void _processCdQueue(void)
{
    ++vs_main_disk.framesSinceLastRead;

    if (*(int*)&_cdQueueCount != 0) {
        vs_main_CdQueueSlot* slot = _cdQueue;
        int i = _diskGetState();
        if (i == diskIdle) {
            for (i = 0; i < 32; ++i, ++slot) {
                if (slot->state == vs_main_CdQueueStateEnqueued) {
                    if (slot->priority == 0) {
                        slot->state = vs_main_CdQueueStateReading;
                        _diskInitRead(slot->cdFile.lba, slot->cdFile.size, slot->vram);
                        vs_main_disk.framesSinceLastRead = 0;
                        --_cdQueueCount.queued;
                        ++_cdQueueCount.processing;
                    } else {
                        --slot->priority;
                    }
                } else if (slot->state == vs_main_CdQueueStateReading) {
                    slot->state = vs_main_CdQueueStateLoaded;
                    --_cdQueueCount.processing;
                }
            }
        }
    }
    _diskUpdate();
}

int vs_main_getMusicPosition(void) { return Sound_GetMusicPosition(); }

void vs_main_pushMusicState(void) { Sound_PushMusicState(); }

void vs_main_setMusicJumpThreshold(int arg0) { Sound_SetMusicJumpThreshold((void*)arg0); }

int vs_main_stopMusicSlot(int id)
{
    u_int new_var;
    int var_a1;

    if (id != 0) {
        if (vs_main_soundData.unk14[id - 1] != 0xFFFF) {
            Sound_StopMusicById(vs_main_soundData.unk14[id - 1]);
            vs_main_soundData.unk14[id - 1] = 0xFFFF;
        }
        if (vs_main_soundData.currentMusicSlot == id) {
            vs_main_soundData.currentMusicSlot = 0;
            vs_main_soundData.currentMusicData = NULL;
            vs_main_soundData.unk4 = 0xFFFF;
        }
        return 1;
    }
    Sound_StopMusic();
    vs_main_soundData.currentMusicSlot = 0;
    vs_main_soundData.currentMusicData = NULL;
    vs_main_soundData.unk4 = 0xFFFF;

    new_var = 0xFFFF;
    for (var_a1 = 3; var_a1 >= 0; --var_a1) {
        vs_main_soundData.unk14[var_a1] = new_var;
    }
    return 1;
}

int vs_main_queueMusicSlot(int id)
{
    u_int temp_v0;

    if (id != 0) {
        if (vs_main_soundData.musicData[id - 1] != 0) {
            vs_main_soundData.currentMusicSlot = id;
            vs_main_soundData.currentMusicData = vs_main_soundData.musicData[id - 1];
            temp_v0 = Sound_QueueMusic(vs_main_soundData.currentMusicData);
            if (temp_v0 != 0) {
                vs_main_soundData.unk14[id - 1] = temp_v0;
                vs_main_soundData.unk4 = temp_v0;
            }
            vs_main_soundData.unk8 = vs_main_soundData.musicIds[id - 1];
        }
        return vs_main_soundData.unk4;
    }
    return 0;
}

int vs_main_playMusicSlotFadeIn(int id, int arg1, u_int arg2)
{
    u_int temp_v0;

    if (id != 0) {
        if (vs_main_soundData.musicData[id - 1] != 0) {
            vs_main_soundData.currentMusicSlot = id;
            vs_main_soundData.currentMusicData = vs_main_soundData.musicData[id - 1];
            temp_v0 = Sound_StartMasterAndMusicVolumeFade(
                vs_main_soundData.currentMusicData, arg2, arg1);
            if (temp_v0 != 0) {
                vs_main_soundData.unk14[id - 1] = temp_v0;
                vs_main_soundData.unk4 = temp_v0;
            }
            vs_main_soundData.unk8 = vs_main_soundData.musicIds[id - 1];
        }
        return vs_main_soundData.unk4;
    }
    return 0;
}

int vs_main_playMusicSlot(int id, int arg1, int arg2)
{
    u_int temp_v0;

    if (id != 0) {
        if (vs_main_soundData.musicData[id - 1] != 0) {
            vs_main_soundData.currentMusicSlot = id;
            vs_main_soundData.currentMusicData = vs_main_soundData.musicData[id - 1];
            Sound_FadeMasterVolumeByMusicId(0, arg2, arg1);
            temp_v0 = Sound_StartFieldMusic(vs_main_soundData.currentMusicData);
            if (temp_v0 != 0) {
                vs_main_soundData.unk14[id - 1] = temp_v0;
                vs_main_soundData.unk4 = temp_v0;
                Sound_FadeMasterVolumeByMusicId(0, arg2, arg1);
            }
            vs_main_soundData.unk8 = vs_main_soundData.musicIds[id - 1];
        }
        return vs_main_soundData.unk4;
    }
    return 0;
}

static int vs_main_getcurrentMusicSlot(void)
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
    vs_main_CdFile cdFile;

    if (id > 0 && targetSlot > 0) {
        int slot = targetSlot - 1;

        if (targetSlot < 5) {
            if (vs_main_soundData.musicIds[slot] != id) {
                do {
                    if (vs_main_soundData.musicData[slot] != 0) {
                        vs_main_nop10(142, 0);
                        vs_main_freeMusic(targetSlot);
                    }
                } while (0);

                cdFile.lba = _musicLBAs[id];
                cdFile.size = _musicFileSizes[id];

                if ((vs_main_soundData.musicQueueSlot[slot] != 0)
                    && (vs_main_soundData.musicQueueSlot[slot]
                        != (vs_main_CdQueueSlot*)-1)) {
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

static int _loadMusicIntoFreeSlot(int id)
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
                vs_main_soundData.musicQueueSlot[slot - 1] = (vs_main_CdQueueSlot*)-1;
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
    int ret;

    ret = 0;
    i = 0;
    do {
        ret |= vs_main_clearMusicLoadSlot(++i);
    } while (i < 4);

    return ret;
}

int vs_main_loadAndWaitMusicSlot(int id, int targetSlot)
{
    int ret;

    ret = vs_main_loadMusicSlot(id, targetSlot);
    if (ret != 0) {
        while (vs_main_clearMusicLoadSlot(targetSlot) != 0) {
            vs_main_gametimeUpdate(0);
        }
    }
    return ret;
}

static int _loadMusicIntoFreeSlotAndClearQueue(int id)
{
    int ret;

    ret = _loadMusicIntoFreeSlot(id);
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

static int nop5(void) { return 0; }

int vs_main_getMusicSlotVolume(int arg0)
{
    if (arg0 != 0) {
        if (vs_main_soundData.unk14[arg0 - 1] != 0xFFFF) {
            return Sound_GetMusicVolumeById(vs_main_soundData.unk14[arg0 - 1]);
        }
    }
    return 0;
}

int vs_main_getMusicSlotVolume2(int arg0) { return vs_main_getMusicSlotVolume(arg0); }

int vs_main_fadeMusicVolume(int id, int arg1, int arg2)
{
    if (vs_main_soundData.currentMusicSlot == id) {
        Sound_FadeMasterVolumeByMusicId(vs_main_soundData.unk4, arg2, arg1);
        return 1;
    }
    return 0;
}

int vs_main_fadeMusicTempo(int id, int arg1, int arg2)
{
    if (vs_main_soundData.currentMusicSlot == id) {
        Sound_FadeTempoScale(arg2, arg1);
        return 1;
    }
    return 0;
}

int vs_main_fadeMusicPitch(int id, int arg1, int arg2)
{
    if (vs_main_soundData.currentMusicSlot == id) {
        Sound_FadeMasterPitchScale(arg2, arg1);
        return 1;
    }
    return 0;
}

static int nop6(void) { return 0; }

static int nop7(void) { return 0; }

void vs_main_stopMusic(void)
{
    int id = vs_main_soundData.currentMusicSlot;
    if (id != 0) {
        vs_main_stopMusicSlot(id);
        vs_main_freeMusic(id);
    }
}

static UNUSED void _playSfxPool0Default(int id)
{
    Sound_PlaySfx(id & 0xFFFF, _nextVoicePool0, 0x80, 0x7F);

    if (!((_nextVoicePool0 *= 2) & 1)) {
        _nextVoicePool0 = 1;
    }
}

static void _playSfxById(int id, int arg1, int arg2, int arg3)
{
    if (arg1 == 0x200) {
        if (id != Sound_GetPlayingSfxByGroup(0x200)) {
            Sound_PlaySfx(id, 0x200, arg2, arg3);
        }
    } else {
        Sound_PlaySfx(id, arg1, arg2, arg3);
    }
}

static void _playSfxFromPointer(void* data, int arg1, int arg2, int arg3)
{
    if (arg1 == 0x200) {
        if (data != (void*)Sound_GetPlayingSfxByGroup(0x200)) {
            Sound_PlaySfxFromPointer(data, 0x200, arg2, arg3);
        }
    } else {
        Sound_PlaySfxFromPointer(data, arg1, arg2, arg3);
    }
}

void vs_main_playSfx(int arg0, long id, int arg2, int arg3)
{
    void* var_s0_2;

    switch (arg0) {
    case 0x7E:
    case 0xFE:
        if (func_800123C8((void*)(id & 0xFFFF)) != 0) {
            _playSfxById(id & 0xFFFF, _nextVoicePool1, arg2, arg3);
            _nextVoicePool1 *= 2;
            if (!(_nextVoicePool1 & 0x7E)) {
                _nextVoicePool1 = 2;
            }
        } else {
            _playSfxById(id & 0xFFFF, 0, arg2, arg3);
        }
        break;

    case 0x100:
    case 0x200:
        if (func_800123C8((void*)(id & 0xFFFF)) != 0) {
            _playSfxById(id & 0xFFFF, _nextVoicePool3, arg2, arg3);
        } else {
            _playSfxById(id & 0xFFFF, 0, arg2, arg3);
        }
        break;

    case 0xFF000:
        var_s0_2 = vs_main_soundData.sfxData[vs_main_soundData.currentSfxId - 1];
        var_s0_2 += *((int*)var_s0_2 + id + 1);
        if (func_800123C8(var_s0_2) != 0) {
            _playSfxFromPointer(var_s0_2, _nextVoicePool4, arg2, arg3);
            _nextVoicePool4 *= 2;
            if (!(_nextVoicePool4 & arg0)) {
                _nextVoicePool4 = 0x1000;
            }
        } else {
            _playSfxFromPointer(var_s0_2, 0, arg2, arg3);
        }
        break;

    case 0xF00000:
        var_s0_2 = vs_main_soundData.sfxData[2];
        var_s0_2 += *((int*)var_s0_2 + id + 1);
        if (func_800123C8(var_s0_2) != 0) {
            _playSfxFromPointer(var_s0_2, _nextVoicePool5, arg2, arg3);
            _nextVoicePool5 *= 2;
            if (!(_nextVoicePool5 & arg0)) {
                _nextVoicePool5 = 0x100000;
            }
        } else {
            _playSfxFromPointer(var_s0_2, 0, arg2, arg3);
        }
        break;

    default:
        vs_main_nop10(0x95, 0);
        break;
    }
}

void vs_main_playSfxDefault(int arg0, int id) { vs_main_playSfx(arg0, id, 0x80, 0x7F); }

int vs_main_computeSfxPan(int coords, int z)
{
    int v0;
    int new_var2;
    int v1;

    v0 = coords;

    if (coords < 0) {
        v0 += 0xFFFF;
    }

    v0 = (v0 >> 16) << 16;
    coords = (short)(coords - v0) - 160;
    coords = (coords * 3) / 10;

    if (coords < -96) {
        coords = -96;
    }

    if (coords > 96) {
        coords = 96;
    }

    coords += 128;
    v1 = z - 768;

    if (v1 < 0) {
        v1 = 0;
    }

    if (v1 > 4095) {
        v1 = 4095;
    }

    v0 = v1;

    if (v1 < 0) {
        v0 = v1 + 31;
    }

    v0 >>= 5;
    v1 = 127;

    new_var2 = v1 - v0;
    return (coords << 16) + new_var2;
}

static void _do_panSfx(int arg0, int arg1, int coords, int z)
{
    coords = vs_main_computeSfxPan(coords, z);
    z = coords & 0xFFFF;
    coords = coords >> 0x10;
    if (z > 0) {
        vs_main_playSfx(arg0, arg1, coords, z);
    }
}

void vs_main_panSfx(int arg0, int arg1, SVECTOR* vec)
{
    int z;
    long coords;
    long value;
    long flag;

    SetRotMatrix(&vs_scratch.viewMatrix);
    SetTransMatrix(&vs_scratch.viewMatrix);
    z = RotTransPers(vec, &coords, &value, &flag);
    _do_panSfx(arg0, arg1, coords, z);
}

static int _resolveSfxData(int arg0, int arg1)
{
    int temp_v1;

    switch (arg0) {
    case 0x1:
    case 0x7E:
    case 0xFE:
    case 0x100:
    case 0x200:
        temp_v1 = 0;
        break;
    case 0xFF000:
    case 0xF00000:
        temp_v1 = (int)vs_main_soundData.sfxData[vs_main_soundData.currentSfxId - 1];
        temp_v1 = (int)temp_v1 + (arg1 + (int*)temp_v1)[1];
        break;
    default:
        vs_main_nop10(0x95, 0);
        temp_v1 = 0;
        break;
    }
    return temp_v1;
}

void vs_main_fadeSfxVolume(int arg0, int arg1, int arg2, char arg3)
{
    int temp_v0;

    if (arg1 != 0) {
        temp_v0 = _resolveSfxData(arg0, arg1);

        if (temp_v0 != 0) {
            Sound_FadeSfxVolumeMod(temp_v0, 0, arg3, arg2);
        } else {
            do {
                Sound_FadeSfxVolumeMod(arg1, 0, arg3, arg2);
            } while (0);
        }
    } else {
        Sound_FadeSfxVolumeMod(0, arg0, arg3, arg2);
    }
}

void vs_main_fadeSfxPitch(int arg0, int arg1, int arg2, char arg3)
{
    int temp_v0;

    if (arg1 != 0) {
        temp_v0 = _resolveSfxData(arg0, arg1);
        if (temp_v0 != 0) {
            Sound_FadeSfxPitchMod(temp_v0, 0, arg3, arg2);
        } else {
            do {
                Sound_FadeSfxPitchMod(arg1, 0, arg3, arg2);
            } while (0);
        }
    } else {
        Sound_FadeSfxPitchMod(0, arg0, arg3, arg2);
    }
}

void vs_main_fadeSfxPan(int arg0, int arg1, int arg2, char arg3)
{
    if (arg1 != 0) {
        arg0 = _resolveSfxData(arg0, arg1);
        if (arg0 != 0) {
            Sound_FadeSfxPanMod(arg0, 0, arg3, arg2);
        } else {
            do {
                Sound_FadeSfxPanMod(arg1, 0, arg3, arg2);
            } while (0);
        }
    } else {
        Sound_FadeSfxPanMod(0, arg0, arg3, arg2);
    }
}

void vs_main_evictSfx(int arg0, int arg1)
{
    if (arg1 != 0) {
        arg0 = _resolveSfxData(arg0, arg1);

        if (arg0 != 0) {
            Sound_EvictSfx(arg0, 0);
        } else {
            Sound_EvictSfx(arg1, 0);
        }
    } else {
        Sound_EvictSfx(0, arg0);
    }
}

void vs_main_stopAllSfx(void) { Sound_StopSfx(); }

int vs_main_loadSfxSlot(int id, u_int slot)
{
    vs_main_CdFile cdFile;

    if (slot - 1 < 3) {
        if (vs_main_soundData.sfxData[slot - 1] == NULL) {
            u_int index = slot - 1;
            cdFile.lba = _seLBAs[id];
            cdFile.size = _seFileSizes[id];

            if ((vs_main_soundData.sfxQueueSlot[index] != NULL)
                && (vs_main_soundData.sfxQueueSlot[index] != (vs_main_CdQueueSlot*)-1)) {
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

static int _loadSfx(int id)
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
                vs_main_soundData.sfxQueueSlot[slot - 1] = (vs_main_CdQueueSlot*)-1;
                return -1;
            }
            return 1;
        }
    }
    return 0;
}

static int _freeSfxSlots(void)
{
    int i;
    int ret = 0;
    for (i = 0; i < 3; ++i) {
        ret |= vs_main_freeSfxQueueSlot(i + 1);
    }
    return ret;
}

static int _loadAndFreeSfx(int id)
{
    int slot;

    slot = _loadSfx(id);
    if (slot != 0) {
        while (_freeSfxSlots() != 0) {
            vs_main_gametimeUpdate(0);
        }
    }
    return slot;
}

int vs_main_setCurrentSfx(int id)
{
    if ((id - 1u < 3) && vs_main_soundData.sfxData[id - 1] != NULL) {
        vs_main_soundData.currentSfxId = id;
        return 1;
    }
    return 0;
}

int vs_main_freeSfx(u_int id)
{
    if ((id - 1) < 3) {
        if (vs_main_soundData.sfxData[id - 1] != NULL) {
            if (vs_main_soundData.currentSfxId == id) {
                vs_main_soundData.currentSfxId = 0;
            }
            Sound_EvictSfx(-2, 0);
            Sound_EvictSfx(0, 0xFF000);
            vs_main_freeHeapR(vs_main_soundData.sfxData[id - 1]);
            vs_main_soundData.sfxIds[id - 1] = 0;
            vs_main_soundData.sfxData[id - 1] = 0;
            return 1;
        }
    }
    return 0;
}

int vs_main_setSfxSlot3Data(u_int arg0)
{
    if (vs_main_soundData.unk14[16] == 0) {
        vs_main_soundData.unk14[16] = arg0;
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

void vs_main_playBankSfx(int arg0, u_int arg1[], u_int arg2, int arg3, int arg4)
{
    int var_s0;
    void* temp_s1;

    temp_s1 = arg1;

    if (arg2 < arg1[0]) {
        temp_s1 = (char*)arg1 + (arg1 + arg2)[1];
        var_s0 = 0;

        if (arg0 == 0x180) {
            var_s0 = _nextVoicePool2;
            _nextVoicePool2 *= 2;
            if (!(_nextVoicePool2 & 0x180)) {
                _nextVoicePool2 = 0x80;
            }
        } else if (arg0 == 0x200) {
            var_s0 = _nextVoicePool3;
            _nextVoicePool3 *= 2;
            if (!(_nextVoicePool3 & 0x200)) {
                _nextVoicePool3 = arg0;
            }
        } else if (arg0 == 0xF00000) {
            var_s0 = _nextVoicePool5;
            _nextVoicePool5 *= 2;
            if (!(_nextVoicePool5 & arg0)) {
                _nextVoicePool5 = 0x100000;
            }
        } else if (arg0 == 0x7E) {
        } else {
            vs_main_nop10(0x95, 0);
        }
        _playSfxFromPointer(temp_s1, var_s0, arg3, arg4);
    }
}

void vs_main_playBankSfxDefault(int arg0, int* arg1, u_int arg2)
{
    vs_main_playBankSfx(arg0, arg1, arg2, 0x80, 0x7F);
}

static void _do_panBankSfx(int arg0, u_int arg1[], int arg2, int arg3, int arg4)
{
    int temp_t0;
    int var_v0;
    int var_v1;

    var_v1 = arg3;
    var_v0 = arg3;
    arg3 = var_v0 >> 0x10;

    if (var_v1 < 0) {
        var_v0 = var_v1 + 0xFFFF;
    }

    arg3 = var_v0 >> 0x10;
    var_v0 = arg3 << 0x10;
    arg3 = var_v1 - var_v0;

    if (arg3 < 0) {
        arg3 = 0;
    }

    if (arg3 >= 0x141) {
        arg3 = 0x140;
    }

    var_v0 = arg3 + ((u_int)arg3 >> 0x1F);
    var_v0 >>= 1;
    arg3 = var_v0 + 0x30;
    temp_t0 = arg4;

    if (temp_t0 < 0) {
        temp_t0 = 0;
    }

    if (temp_t0 >= 0x401) {
        temp_t0 = 0x400;
    }

    var_v1 = temp_t0;

    if (temp_t0 < 0) {
        var_v1 += 7;
    }

    temp_t0 = 0x7F - (var_v1 >> 3);

    if (temp_t0 > 0) {
        vs_main_playBankSfx(arg0, arg1, arg2, arg3, temp_t0);
    }
}

static void _panBankSfx(int arg0, u_int* arg1, int arg2, SVECTOR* vec)
{
    int z;
    long sxy;
    long value;
    long flag;

    SetRotMatrix(&vs_scratch.viewMatrix);
    SetTransMatrix(&vs_scratch.viewMatrix);
    z = RotTransPers(vec, &sxy, &value, &flag);
    _do_panBankSfx(arg0, arg1, arg2, sxy, z);
}

void vs_main_evictBankSfx(int arg0, int* arg1, int arg2)
{
    int var_a1;
    char* var_a0 = (char*)arg1 + (arg1 + arg2)[1];

    if (arg2 != 0) {
        var_a1 = 0;
    } else {
        var_a0 = 0;
        var_a1 = arg0;
    }
    Sound_EvictSfx((int)var_a0, var_a1);
}

void vs_main_fadeBankSfxVolume(int arg0, int* arg1, int arg2, int arg3, int arg4)
{
    int a0 = (int)((char*)arg1 + (arg2 + arg1)[1]);

    if (arg2 == 0) {
        Sound_FadeSfxVolumeMod(0, arg0, arg4 & 0xFF, arg3);
    } else {
        Sound_FadeSfxVolumeMod(a0, 0, arg4 & 0xFF, arg3);
    }
}

static void _stopCutsceneStream(void) { Sound_StopCutsceneStream(); }

static int _startCutsceneStream(int arg0, int arg1, int arg2)
{
    if ((arg0 - 1u) < 3) {
        if (vs_main_soundData.unk64[arg0 - 1] != 0) {
            Sound_FadeOutCutscene(0, arg2);
            Sound_StartCutsceneStream(vs_main_soundData.unk64[arg0 - 1], arg1, 1);
            return 1;
        }
    }
    return 0;
}

void vs_main_startCutsceneStreamDefault(int arg0)
{
    _startCutsceneStream(arg0, 0x80, 0x7F);
}

static int _freeCutsceneStream(int arg0)
{
    if ((arg0 - 1u) < 3) {
        if (vs_main_soundData.unk64[arg0 - 1] != 0) {
            Sound_StopCutsceneStream();
            vs_main_freeHeapR(vs_main_soundData.unk64[arg0 - 1]);
            vs_main_soundData.unk64[arg0 - 1] = 0;
            return 1;
        }
    }
    return 0;
}

int vs_main_setCutsceneStreamSlot3(u_int arg0)
{
    if (vs_main_soundData.unk14[22] == 0) {
        vs_main_soundData.unk14[22] = arg0;
        return 3;
    }
    return 0;
}

int vs_main_clearCutsceneStreamSlot3(void)
{

    if (vs_main_soundData.unk14[22] != 0) {
        Sound_StopCutsceneStream();
        vs_main_soundData.unk14[22] = 0;
        return 1;
    }
    return 0;
}

static void _loadSoundFile(int file)
{
    vs_main_CdFile cdFile;
    int new_var;
    int temp_v1;
    int var_a0;

    temp_v1 = Sound_GetLoadedMusicBankIds();
    var_a0 = temp_v1 >> 0x10;
    new_var = temp_v1;

    if (temp_v1 < 0) {
        var_a0 = (temp_v1 + 0xFFFF) >> 0x10;
    }
    if (((new_var - (var_a0 << 0x10)) == file) || (var_a0 == file)) {
        return;
    }
    cdFile.lba = _soundLBAs[file];
    cdFile.size = _soundFileSizes[file];

    if (vs_main_soundData.soundQueueSlot) {
        if ((long)vs_main_soundData.soundQueueSlot != -1) {
            vs_main_nop9(0x93 & 0xFFu, 0);
        }
    }
    vs_main_soundData.soundQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
    if (vs_main_soundData.soundData != 0) {
        vs_main_nop9(0x94, 0);
    }
    new_var = 1;
    vs_main_soundData.soundData = vs_main_allocHeapR(cdFile.size);
    vs_main_soundData.soundFileId = file;
    vs_main_cdEnqueue(vs_main_soundData.soundQueueSlot, vs_main_soundData.soundData);
}

void vs_main_loadSoundFile(int id) { _loadSoundFile(_soundFileMap[id]); }

int vs_main_processSoundQueue(void)
{
    int temp_v0;

    if (vs_main_soundData.soundQueueSlot != NULL) {
        if (vs_main_soundData.soundQueueSlot->state == vs_main_CdQueueStateDispatched) {
            temp_v0 = IsSpuTransferring();
            if (temp_v0 == 0) {
                vs_main_freeCdQueueSlot(vs_main_soundData.soundQueueSlot);
                vs_main_soundData.soundQueueSlot = NULL;
                vs_main_freeHeapR(vs_main_soundData.soundData);
                vs_main_soundData.soundData = NULL;
                vs_main_soundData.soundFileId = 0;
                return 0;
            }
            if (temp_v0 == -1) {
                vs_main_freeCdQueueSlot(vs_main_soundData.soundQueueSlot);
                vs_main_soundData.soundQueueSlot = NULL;
                vs_main_freeHeapR(vs_main_soundData.soundData);
                vs_main_soundData.soundData = NULL;
                vs_main_soundData.soundFileId = 0;
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
            vs_main_freeCdQueueSlot(vs_main_soundData.soundQueueSlot);
            vs_main_soundData.soundQueueSlot = NULL;
            vs_main_freeHeapR(vs_main_soundData.soundData);
            vs_main_soundData.soundData = NULL;
            vs_main_soundData.soundFileId = 0;
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

static UNUSED void _setCdVolumeMax(void) { Sound_SetCdVolume(0x7FFF); }

static void _loadMenuSound(void)
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
    vs_main_diskLoadFile(VS_EFFECT00_DAT_LBA, VS_EFFECT00_DAT_SIZE, _sfxData);
    Sound_BindAkaoSfxBlob(_sfxData);
    _nextVoicePool0 = 1;
    _nextVoicePool1 = 2;
    _nextVoicePool2 = 0x80;
    _nextVoicePool3 = 0x200;
    _nextVoicePool4 = 0x1000;
    _nextVoicePool5 = 0x100000;
}

void vs_main_resetSound(void)
{
    int i;

    vs_main_soundData.currentMusicSlot = 0;
    vs_main_soundData.currentMusicData = NULL;
    vs_main_soundData.unk8 = 0xFFFF;
    vs_main_soundData.unk4 = 0xFFFF;
    vs_main_soundData.currentSfxId = 0;

    for (i = 0; i < 4; ++i) {
        vs_main_soundData.musicIds[i] = 0;
        vs_main_soundData.unk14[i] = 0xFFFF;
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
        vs_main_soundData.unk70[i] = NULL;
    }

    vs_main_soundData.soundFileId = 0;
    vs_main_soundData.soundData = NULL;
    vs_main_soundData.soundQueueSlot = NULL;
    _nextVoicePool0 = 1;
    _nextVoicePool1 = 2;
    _nextVoicePool2 = 0x80;
    _nextVoicePool3 = 0x200;
    _nextVoicePool4 = 0x1000;
    _nextVoicePool5 = 0x100000;
}

static void _loadClutTransition(int duration, int slot, u_short* sourceClut)
{
    int i;

    for (i = 0; i < 256; ++i) {
        u_short r = sourceClut[i] & 0x1F;
        u_short g = (sourceClut[i] & 0x3E0) >> 5;
        u_short b = (sourceClut[i] & 0x7C00) >> 10;

        struct ColorInfo* colors = _clutState.slots[slot].colorInfo;

        if (duration != 0) {
            colors[i].rindex = (r - colors[i].r) + 31;
            colors[i].gindex = (g - colors[i].g) + 31;
            colors[i].bindex = (b - colors[i].b) + 31;
        } else {
            colors[i].r = r;
            colors[i].g = g;
            colors[i].b = b;
            _clutBuffer[slot][i] = r + (g << 5) + (b << 10) + (colors[i].a << 15);
        }
    }

    if (duration != 0) {
        struct clutAnimState_t* state = &_clutState.slots[slot].animState;
        state->active = 1;
        state->frame = 0;
        state->tick = 0;
        state->speed = duration;
    } else {
        _clutState.slots[slot].animState.active = 0;
    }
}

void vs_main_loadClutTransition(
    int duration, int slot, u_short* sourceClut, int clutOffset)
{
    if (_clutState.active != 0) {
        _loadClutTransition(duration, slot, sourceClut + (clutOffset * 16));
        _clutState.uploadPending = 1;
    }
}

static UNUSED void _loadClutTransitionWithBase(
    int duration, int slot, u_short* sourceClut, int clutOffset)
{
    int i;

    if (_clutState.active != 0) {
        vs_main_loadClutTransition(duration, slot, sourceClut, clutOffset);

        for (i = 0; i < 256; ++i) {
            _clutState.slots[slot].clutBase[i] = sourceClut[i];
        }
    }
}

static UNUSED void _saveClutBase(int slot)
{
    int i;

    if (_clutState.active != 0) {
        for (i = 0; i < 256; ++i) {
            _clutState.slots[slot].clutBase[i] = _clutBuffer[slot][i];
        }
    }
}

static inline int _weightedLuminance(short g, short b, short r)
{
    return r * 2 + (g >> 5) * 3 + (b >> 10);
}

static void _transformClutSlot(
    int mode, int duration, int slot, int rOffset, short gOffset, short bOffset)
{
    int i;
    int gOffsetU = (u_short)gOffset;
    int bOffsetU = (u_short)bOffset;
    struct ColorInfo* colors = _clutState.slots[slot].colorInfo;

    for (i = 0; i < 256; ++i) {

        int r;
        int g;
        int b;
        short baseEntry = _clutState.slots[slot].clutBase[i];

        if ((colors[i].r + colors[i].g + colors[i].b + colors[i].a) != 0) {
            switch (mode) {
            case 1: {
                int rTmp = colors[i].r;
                int gTmp = colors[i].g;
                int bTmp = colors[i].b;
                r = rOffset + rTmp / 2;
                g = gOffsetU + gTmp / 2;
                b = bOffsetU + bTmp / 2;
                break;
            }
            case 2:
                r = rOffset + ((colors[i].r * 2) + (colors[i].g * 3) + colors[i].b) / 6;
                g = gOffsetU + ((colors[i].r * 2) + (colors[i].g * 3) + colors[i].b) / 6;
                b = bOffsetU + ((colors[i].r * 2) + (colors[i].g * 3) + colors[i].b) / 6;
                break;
            case 3:
                r = rOffset + ((colors[i].r * 2) + (colors[i].g * 3) + colors[i].b) / 12;
                g = gOffsetU + ((colors[i].r * 2) + (colors[i].g * 3) + colors[i].b) / 12;
                b = bOffsetU + ((colors[i].r * 2) + (colors[i].g * 3) + colors[i].b) / 12;
                break;
            case 4:
            case 9:
                r = rOffset + (baseEntry & 0x1F);
                g = gOffsetU + ((baseEntry & 0x3E0) >> 5);
                b = bOffsetU + ((baseEntry & 0x7C00) >> 10);
                break;
            case 5: {
                int tmp = 0x1F;
                r = rOffset + ((baseEntry & tmp) / 2);
                g = gOffsetU + ((baseEntry & 0x3E0) >> 5) / 2;
                b = bOffsetU + ((baseEntry & 0x7C00) >> 10) / 2;
                break;
            }
            case 6:
                r = rOffset
                  + _weightedLuminance(
                        baseEntry & 0x3E0, baseEntry & 0x7C00, baseEntry & 0x1F)
                        / 6;
                g = gOffsetU
                  + _weightedLuminance(
                        baseEntry & 0x3E0, baseEntry & 0x7C00, baseEntry & 0x1F)
                        / 6;
                b = bOffsetU
                  + _weightedLuminance(
                        baseEntry & 0x3E0, baseEntry & 0x7C00, baseEntry & 0x1F)
                        / 6;
                break;
            case 7:
                r = rOffset
                  + _weightedLuminance(
                        baseEntry & 0x3E0, baseEntry & 0x7C00, baseEntry & 0x1F)
                        / 12;
                g = gOffsetU
                  + _weightedLuminance(
                        baseEntry & 0x3E0, baseEntry & 0x7C00, baseEntry & 0x1F)
                        / 12;
                b = bOffsetU
                  + _weightedLuminance(
                        baseEntry & 0x3E0, baseEntry & 0x7C00, baseEntry & 0x1F)
                        / 12;
                break;
            case 8:
            case 15:
                r = baseEntry & 0x1F;
                g = (baseEntry & 0x3E0) >> 5;
                b = (baseEntry & 0x7C00) >> 10;
                break;
            case 11:
                _clutState.slots[slot].animState.transitionMode = 0;
                return;
            case 12: {
                int tmp = 0x1F;
                r = rOffset - (colors[i].r - tmp);
                g = gOffsetU - (colors[i].g - tmp);
                b = bOffsetU - (colors[i].b - tmp);
                break;
            }
            case 13: {
                int tmp = (baseEntry & 0x1F) * 3;
                if (tmp < 0) {
                    tmp += 3;
                }
                r = rOffset + (tmp >> 2);
                tmp = ((baseEntry & 0x3E0) >> 5) * 3;
                if (tmp < 0) {
                    tmp += 3;
                }
                g = gOffsetU + (tmp >> 2);
                tmp = ((baseEntry & 0x7C00) >> 10) * 3;
                if (tmp < 0) {
                    tmp += 3;
                }
                b = bOffsetU + (tmp >> 2);
                break;
            }
            default:
                r = colors[i].r + rOffset;
                g = colors[i].g + gOffsetU;
                b = colors[i].b + bOffsetU;
                break;
            }

            if ((short)r > 31) {
                r = 31;
            }
            if ((short)g > 31) {
                g = 31;
            }
            if ((short)b > 31) {
                b = 31;
            }
            if ((r << 16) <= 0) {
                r = 0;
            }
            if ((g << 16) <= 0) {
                g = 0;
            }
            if ((b << 16) <= 0) {
                b = 0;
            }
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
                _clutBuffer[slot][i] = r + (g << 5) + (b << 10) + (colors[i].a << 15);
            }
        } else {
            colors[i].bindex = 31;
            colors[i].gindex = 31;
            colors[i].rindex = 31;
        }
    }
    if (duration != 0) {
        struct clutAnimState_t* p = &_clutState.slots[slot].animState;
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
        _clutState.slots[slot].animState.active = 0;
        _clutState.uploadPending = 1;
    }
}

void vs_main_transformClutSlot(
    int mode, int duration, int slot, short rOffset, int gOffset, int bOffset)
{
    if (_clutState.active != 0) {
        do {
            _transformClutSlot(mode, duration, slot, rOffset, gOffset, bOffset);
        } while (0);
    }
}

static inline int _shift_left(int arg0) { return arg0 << 0x10; }

void vs_main_fadeBgColors(int arg0, CVECTOR* arg1)
{
    int sp10[5];
    int i;

    if (_clutState.active != 0) {
        int (*temp_t6)[6] = _clutState.bgColors;
        for (i = 0; i < 5; ++i) {
            int r;
            int g;
            int b;
            r = _shift_left(arg1[i].r);
            g = _shift_left(arg1[i].g);
            b = _shift_left(arg1[i].b);

            if (arg0 != 0) {
                temp_t6[i][3] = ((int)(r - (temp_t6[i][0] & 0xFFFF0000)) / (arg0 * 2));
                temp_t6[i][4] = ((int)(g - (temp_t6[i][1] & 0xFFFF0000)) / (arg0 * 2));
                temp_t6[i][5] = ((int)(b - (temp_t6[i][2] & 0xFFFF0000)) / (arg0 * 2));
            } else {
                temp_t6[i][0] = r;
                temp_t6[i][1] = g;
                temp_t6[i][2] = b;
            }
        }
        if (arg0 != 0) {
            _clutState.bgAnimActive = 1;
            _clutState.bgAnimFrame = 0;
            _clutState.bgAnimTick = 0;
            _clutState.bgAnimSpeed = arg0;
            return;
        }
        _clutState.bgAnimActive = 0;

        for (i = 0; i < 5; ++i) {
            sp10[i] = ((temp_t6[i][0] / 65536) + ((temp_t6[i][1] / 65536) << 8))
                    + (((temp_t6[i][2] / 65536)) << 0x10);
        }
        func_8008EB30(sp10);
    }
}

static UNUSED void _fadeBgColorsStore(int arg0, CVECTOR* arg1)
{
    int i;

    if (_clutState.active != 0) {
        vs_main_fadeBgColors(arg0, arg1);
        for (i = 0; i < 5; ++i) {
            _clutState.bgBaseColors[i] = arg1[i];
        }
    }
}

void _transformBgColors(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int sp10[5];
    int temp_v0;
    int var_a1;
    int var_t0;
    int var_t1;
    int i;
    int (*p)[6] = _clutState.bgColors;

    for (i = 0; i < 5; ++i) {
        switch (arg0) {
        case 1:
            var_t1 = (p[i][0] / 2) + (arg2 << 0x10);
            var_t0 = p[i][1] / 2 + (arg3 << 0x10);
            var_a1 = (p[i][2] / 2) + (arg4 << 0x10);
            break;
        case 2:
            var_t1 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 6 + (arg2 << 0x10);
            var_t0 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 6 + (arg3 << 0x10);
            var_a1 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 6 + (arg4 << 0x10);
            break;
        case 3:
            temp_v0 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 12;
            var_t1 = temp_v0 + (arg2 << 0x10);
            var_t0 = temp_v0 + (arg3 << 0x10);
            var_a1 = temp_v0 + (arg4 << 0x10);
            break;
        case 4:
        case 9:
            var_t1 = (_clutState.bgBaseColors[i].r + arg2) << 0x10;
            var_t0 = (_clutState.bgBaseColors[i].g + arg3) << 0x10;
            var_a1 = (_clutState.bgBaseColors[i].b + arg4) << 0x10;
            break;
        case 5:
            var_t1 = (_clutState.bgBaseColors[i].r << 0xF) + (arg2 << 0x10);
            var_t0 = (_clutState.bgBaseColors[i].g << 0xF) + (arg3 << 0x10);
            var_a1 = (_clutState.bgBaseColors[i].b << 0xF) + (arg4 << 0x10);
            break;
        case 6: {
            int v1 = _clutState.bgBaseColors[i].g;
            int a0 = _clutState.bgBaseColors[i].b;
            int v0 = _clutState.bgBaseColors[i].r;
            var_a1 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a1;
            v0 += a0;
            var_t1 = v0 / 6 + (arg2 << 0x10);
            var_t0 = v0 / 6 + (arg3 << 0x10);
            var_a1 = v0 / 6 + (arg4 << 0x10);
        } break;
        case 7: {
            int v1 = _clutState.bgBaseColors[i].g;
            int a0 = _clutState.bgBaseColors[i].b;
            int v0 = _clutState.bgBaseColors[i].r;
            var_a1 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a1;
            v0 += a0;
            var_t1 = v0 / 12 + (arg2 << 0x10);
            var_t0 = v0 / 12 + (arg3 << 0x10);
            var_a1 = v0 / 12 + (arg4 << 0x10);
        } break;
        case 8:
            var_t1 = _clutState.bgBaseColors[i].r << 0x10;
            var_t0 = _clutState.bgBaseColors[i].g << 0x10;
            var_a1 = _clutState.bgBaseColors[i].b << 0x10;
            break;
        case 11:
            _clutState.bgTransitionMode = 0;
            return;
        case 0:
        default:
            var_t1 = p[i][0] + (arg2 << 0x10);
            var_t0 = p[i][1] + (arg3 << 0x10);
            var_a1 = p[i][2] + (arg4 << 0x10);
            break;
        }

        var_t1 &= 0xFFFF0000;
        var_t0 &= 0xFFFF0000;
        var_a1 &= 0xFFFF0000;

        if (var_t1 > 0xFF0000) {
            var_t1 = 0xFF0000;
        }
        if (var_t0 > 0xFF0000) {
            var_t0 = 0xFF0000;
        }
        if (var_a1 > 0xFF0000) {
            var_a1 = 0xFF0000;
        }
        if (var_t1 < 0) {
            var_t1 = 0;
        }
        if (var_t0 < 0) {
            var_t0 = 0;
        }
        if (var_a1 < 0) {
            var_a1 = 0;
        }
        if (arg1 != 0) {
            p[i][3] = (int)(var_t1 - (p[i][0] & 0xFFFF0000)) / (arg1 * 2);
            p[i][4] = (int)(var_t0 - (p[i][1] & 0xFFFF0000)) / (arg1 * 2);
            p[i][5] = (int)(var_a1 - (p[i][2] & 0xFFFF0000)) / (arg1 * 2);
        } else {
            p[i][0] = var_t1;
            p[i][1] = var_t0;
            p[i][2] = var_a1;
        }
    }

    if (arg1 != 0) {
        _clutState.bgAnimActive = 1;
        _clutState.bgAnimFrame = 0;
        _clutState.bgAnimTick = 0;
        _clutState.bgAnimSpeed = arg1;
        _clutState.bgTransitionMode = arg0;
        if (arg0 == 9) {
            _clutState.bgTransitionTargetR = arg2;
            _clutState.bgTransitionTargetG = arg3;
            _clutState.bgTransitionTargetB = arg4;
        }
    } else {
        _clutState.bgAnimActive = 0;
        for (i = 0; i < 5; ++i) {
            int temp_a1, var_v0, new_var;
            temp_v0 = p[i][0];

            if (temp_v0 < 0) {
                temp_v0 += 0xFFFF;
            }

            temp_a1 = (temp_v0 >> 0x10);
            var_v0 = p[i][1];

            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }

            new_var = temp_a1 + ((var_v0 >> 0x10) << 8);
            temp_v0 = p[i][2];

            if (temp_v0 < 0) {
                temp_v0 += 0xFFFF;
            }
            sp10[i] = new_var + ((temp_v0 >> 0x10) << 0x10);
        }
        func_8008EB30(sp10);
    }
}

void vs_main_transformBgColors(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    if (_clutState.active != 0) {
        _transformBgColors(arg0, arg1, arg2, arg3, arg4);
    }
}

static void _fadeColorSlot(int frames, int slot, CVECTOR* color)
{
    CVECTOR sp10;
    _colorSlot_t* temp_t0;
    int temp_a1;
    int temp_t1;
    int temp_t2;
    int v0;
    int* temp_a3;

    if (_clutState.active == 0) {
        return;
    }

    temp_t0 = &_clutState.colorSlots[slot];
    temp_a3 = _clutState.colorSlots[slot].color;
    temp_a1 = _shift_left(color->r);
    temp_t1 = _shift_left(color->g);
    temp_t2 = _shift_left(color->b);

    if (frames != 0) {
        temp_a3[3] = ((int)(temp_a1 - (temp_a3[0] & 0xFFFF0000)) / (frames * 2));
        temp_a3[4] = ((int)(temp_t1 - (temp_a3[1] & 0xFFFF0000)) / (frames * 2));
        temp_a3[5] = ((int)(temp_t2 - (temp_a3[2] & 0xFFFF0000)) / (frames * 2));
    } else {
        temp_a3[0] = temp_a1;
        temp_a3[1] = temp_t1;
        temp_a3[2] = temp_t2;
    }
    if (frames != 0) {
        temp_t0->active = 1;
        temp_t0->frame = 0;
        temp_t0->tick = 0;
        temp_t0->speed = frames;
        return;
    }

    temp_t0->active = 0;
    sp10.r = (temp_a3[0] / 65536) - 64;
    sp10.g = (temp_a3[1] / 65536) - 64;
    sp10.b = (temp_a3[2] / 65536) - 64;
    sp10.cd = 0;

    if (slot != 0) {
        func_800A0768(slot - 1, &sp10);
    } else {
        func_8008B430(&sp10, temp_t0->grayAmount >> 2);
    }
}

static UNUSED void _fadeColorSlotStore(int frames, int slot, CVECTOR* color)
{
    if (_clutState.active != 0) {
        _fadeColorSlot(frames, slot, color);
        _clutState.colorSlots[slot].baseColor = *color;
    }
}

static void _transformColorSlot(int mode, int frames, int slot, int r, int g, int b)
{
    CVECTOR sp10;
    short var_t4;
    int var_a1;
    int var_a2;
    int var_t0;
    int var_v0;
    int var_v1;
    _colorSlot_t* t1 = &_clutState.colorSlots[slot];
    int* t2 = t1->color;

    var_t4 = 0;
    switch (mode) {
    case 1:
        var_a1 = (t2[0] / 2) + (r << 16);
        var_t0 = (t2[1] / 2) + (g << 16);
        var_a2 = (t2[2] / 2) + (b << 16);
        break;
    case 2:
        var_t4 = 0x4000;
        var_a1 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 6 + (r << 0x10);
        var_t0 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 6 + (g << 0x10);
        var_a2 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 6 + (b << 0x10);
        break;
    case 3:
        var_t4 = 0x4000;
        var_v1 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 12;
        var_a1 = var_v1 + (r << 0x10);
        var_t0 = var_v1 + (g << 0x10);
        var_a2 = var_v1 + (b << 0x10);
        break;
    case 4:
    case 9:
        var_a1 = (t1->baseColor.r + r) << 0x10;
        var_t0 = (t1->baseColor.g + g) << 0x10;
        var_a2 = (t1->baseColor.b + b) << 0x10;
        break;
    case 5:
        var_t4 = 0x4000;
        var_a1 = (t1->baseColor.r << 0xF) + (r << 0x10);
        var_t0 = (t1->baseColor.g << 0xF) + (g << 0x10);
        var_a2 = (t1->baseColor.b << 0xF) + (b << 0x10);
        break;
    case 6:
        var_t4 = 0x4000;
        {
            int v1 = t1->baseColor.g;
            int a0 = t1->baseColor.b;
            int v0 = t1->baseColor.r;
            var_a2 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a2;
            v0 += a0;
            var_a1 = v0 / 6 + (r << 0x10);
            var_t0 = v0 / 6 + (g << 0x10);
            var_a2 = v0 / 6 + (b << 0x10);
        }
        break;
    case 7:
        var_t4 = 0x4000;
        {
            int v1 = t1->baseColor.g;
            int a0 = t1->baseColor.b;
            int v0 = t1->baseColor.r;
            var_a2 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a2;
            v0 += a0;
            var_a1 = v0 / 12 + (r << 0x10);
            var_t0 = v0 / 12 + (g << 0x10);
            var_a2 = v0 / 12 + (b << 0x10);
        }
        break;
    case 8:
    case 15:
        var_a1 = t1->baseColor.r << 0x10;
        var_t0 = t1->baseColor.g << 0x10;
        var_a2 = t1->baseColor.b << 0x10;
        break;
    case 11:
        t1->mode = 0;
        return;
    default:
        var_a1 = t2[0] + (r << 0x10);
        var_t0 = t2[1] + (g << 0x10);
        var_a2 = t2[2] + (b << 0x10);
        break;
    }
    var_a1 = var_a1 & 0xFFFF0000;
    var_t0 = var_t0 & 0xFFFF0000;
    var_a2 = var_a2 & 0xFFFF0000;

    if (var_a1 > 0x800000) {
        var_a1 = 0x800000;
    }
    if (var_t0 > 0x800000) {
        var_t0 = 0x800000;
    }
    if (var_a2 > 0x800000) {
        var_a2 = 0x800000;
    }
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    if (var_t0 < 0) {
        var_t0 = 0;
    }
    if (var_a2 < 0) {
        var_a2 = 0;
    }
    if (frames != 0) {
        t2[3] = ((int)(var_a1 - (t2[0] & 0xFFFF0000)) / (frames * 2));
        t2[4] = ((int)(var_t0 - (t2[1] & 0xFFFF0000)) / (frames * 2));
        t2[5] = ((int)(var_a2 - (t2[2] & 0xFFFF0000)) / (frames * 2));
        t1->grayStep = ((var_t4 - t1->grayAmount) / (frames * 2));
    } else {
        t2[0] = var_a1;
        t2[1] = var_t0;
        t2[2] = var_a2;
        t1->grayAmount = var_t4;
    }
    var_v0 = 1;
    if (frames != 0) {
        t1->active = 1;
        t1->frame = 0;
        t1->tick = 0;
        t1->speed = frames;
        t1->mode = mode;
        if (mode == 9) {
            t1->pulseTarget[0] = r;
            t1->pulseTarget[1] = g;
            t1->pulseTarget[2] = b;
        }
    } else {
        t1->active = 0;
        var_v0 = t2[0] >> 0x10;
        if (t2[0] < 0) {
            var_v1 = t2[0] + 0xFFFF;
            var_v0 = var_v1 >> 0x10;
        }
        sp10.r = var_v0 - 0x40;
        var_v0 = t2[1] >> 0x10;
        if (t2[1] < 0) {
            var_v1 = t2[1] + 0xFFFF;
            var_v0 = var_v1 >> 0x10;
        }
        sp10.g = var_v0 - 0x40;
        var_v0 = t2[2] >> 0x10;
        if (t2[2] < 0) {
            var_v1 = t2[2] + 0xFFFF;
            var_v0 = var_v1 >> 0x10;
        }
        sp10.b = var_v0 - 0x40;
        sp10.cd = 0;
        if (slot != 0) {
            func_800A0768(slot - 1, &sp10);
        } else {
            func_8008B430(&sp10, ((u_short)t1->grayAmount << 0x10) >> 0x12);
        }
    }
}

void vs_main_transformColorSlot(int mode, int frames, int slot, int r, int g, int b)
{
    if (_clutState.active != 0) {
        _transformColorSlot(mode, frames, slot, r, g, b);
    }
}

void vs_main_updateBgColors(void)
{
    int sp18[5];
    int i;
    int var_v0;
    int new_var;
    int new_var2;
    int var_v1;
    int (*t1)[6];

    if (_clutState.bgAnimActive == 0) {
        return;
    }

    t1 = _clutState.bgColors;

    for (i = 0; i < 5; ++i) {
        t1[i][0] += t1[i][3];
        t1[i][1] += t1[i][4];
        t1[i][2] += t1[i][5];
    }

    for (i = 0; i < 5; ++i) {
        var_v1 = t1[i][0];
        if (var_v1 < 0) {
            var_v1 += 0xFFFF;
        }
        var_v0 = t1[i][1];
        new_var2 = var_v1 >> 16;
        if (var_v0 < 0) {
            var_v0 += 0xFFFF;
        }
        var_v1 = t1[i][2];
        new_var = new_var2 + ((var_v0 >> 16) << 8);
        if (var_v1 < 0) {
            var_v1 += 0xFFFF;
        }
        sp18[i] = new_var + ((var_v1 >> 16) << 16);
    }
    func_8008EB30(sp18);
    _clutState.bgAnimFrame += 1;
    if (_clutState.bgAnimFrame >= (_clutState.bgAnimSpeed * 2)) {
        if (_clutState.bgTransitionMode == 9) {
            _transformBgColors(4, _clutState.bgAnimSpeed,
                _clutState.bgTransitionTargetR / 2, _clutState.bgTransitionTargetG / 2,
                _clutState.bgTransitionTargetB / 2);
            _clutState.bgTransitionMode = 10;
            return;
        }
        if (_clutState.bgTransitionMode == 10) {
            _transformBgColors(9, _clutState.bgAnimSpeed, _clutState.bgTransitionTargetR,
                _clutState.bgTransitionTargetG, _clutState.bgTransitionTargetB);
            _clutState.bgTransitionMode = 9;
            return;
        }
        _clutState.bgAnimActive = 0;
    }
}

void vs_main_updateColorSlots(void)
{
    CVECTOR sp18;
    int i;
    int var_v0;
    _colorSlot_t* p = _clutState.colorSlots;

    for (i = 0; i < 17; ++i) {
        int* a2 = p[i].color;
        if (p[i].active != 0) {
            a2[0] += a2[3];
            a2[1] += a2[4];
            a2[2] += a2[5];

            var_v0 = a2[0];
            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }
            sp18.r = (var_v0 >> 16) - 0x40;
            var_v0 = a2[1];
            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }
            sp18.g = (var_v0 >> 16) - 0x40;
            var_v0 = a2[2];
            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }
            sp18.b = (var_v0 >> 16) - 0x40;
            sp18.cd = 0;

            if (i != 0) {
                func_800A0768(i - 1, &sp18);
            } else {
                p[0].grayAmount += p[0].grayStep;
                func_8008B430(&sp18, p[0].grayAmount >> 2);
            }
            ++p[i].frame;
            if (p[i].frame >= (p[i].speed * 2)) {
                if (p[i].mode == 9) {
                    vs_main_transformColorSlot(4, p[i].speed, i, p[i].pulseTarget[0] / 2,
                        p[i].pulseTarget[1] / 2, p[i].pulseTarget[2] / 2);
                    p[i].mode = 10;
                } else if (p[i].mode == 10) {
                    _transformColorSlot(9, p[i].speed, i, p[i].pulseTarget[0],
                        p[i].pulseTarget[1], p[i].pulseTarget[2]);
                    p[i].mode = 9;
                } else if (p[i].mode == 14) {
                    _transformColorSlot(15, p[i].speed, i, 0, 0, 0);
                    p[i].mode = 15;
                } else {
                    p[i].active = 0;
                }
            }
        }
    }
}

void vs_main_updateClutSlots(void)
{
    int i;
    int j;
    u_int var_t5;
    u_short g;
    u_short r;
    u_short b;
    struct ColorInfo* index;
    int c;

    for (i = 0; i < 14; ++i) {
        if (_clutState.slots[i].animState.active == 0) {
            continue;
        }
        if (++_clutState.slots[i].animState.tick
            >= (_clutState.slots[i].animState.speed / 8)) {

            _clutState.slots[i].animState.tick = 0;

            if (_clutState.slots[i].animState.speed >= 8) {
                var_t5 = 1;
                c = _clutState.slots[i].animState.frame;
                index = _clutState.slots[i].colorInfo;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset16[index[j].rindex][c];
                    g = index[j].g + _animOffset16[index[j].gindex][c];
                    b = index[j].b + _animOffset16[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].g = g;
                    index[j].b = b;
                    index[j].r = r;
                    _clutBuffer[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            } else if (_clutState.slots[i].animState.speed >= 4) {
                var_t5 = 2;
                c = _clutState.slots[i].animState.frame;
                index = _clutState.slots[i].colorInfo;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset8[index[j].rindex][c];
                    g = index[j].g + _animOffset8[index[j].gindex][c];
                    b = index[j].b + _animOffset8[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    _clutBuffer[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            } else if (_clutState.slots[i].animState.speed >= 2) {
                var_t5 = 4;
                c = _clutState.slots[i].animState.frame;
                index = _clutState.slots[i].colorInfo;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset4[index[j].rindex][c];
                    g = index[j].g + _animOffset4[index[j].gindex][c];
                    b = index[j].b + _animOffset4[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    _clutBuffer[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            } else {
                var_t5 = 8;
                c = _clutState.slots[i].animState.frame;
                index = _clutState.slots[i].colorInfo;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset2[index[j].rindex][c];
                    g = index[j].g + _animOffset2[index[j].gindex][c];
                    b = index[j].b + _animOffset2[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    _clutBuffer[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            }
            if (++_clutState.slots[i].animState.frame >= (16 / var_t5)) {
                if (_clutState.slots[i].animState.transitionMode == 9) {
                    _transformClutSlot(4, _clutState.slots[i].animState.speed, i,
                        _clutState.slots[i].animState.transitionTargetR / 2,
                        _clutState.slots[i].animState.transitionTargetG / 2,
                        _clutState.slots[i].animState.transitionTargetB / 2);
                    _clutState.slots[i].animState.transitionMode = 10;
                } else if (_clutState.slots[i].animState.transitionMode == 10) {
                    _transformClutSlot(9, _clutState.slots[i].animState.speed, i,
                        _clutState.slots[i].animState.transitionTargetR,
                        _clutState.slots[i].animState.transitionTargetG,
                        _clutState.slots[i].animState.transitionTargetB);
                    _clutState.slots[i].animState.transitionMode = 9;
                } else if (_clutState.slots[i].animState.transitionMode == 14) {
                    _transformClutSlot(
                        15, _clutState.slots[i].animState.speed, i, 0, 0, 0);
                    _clutState.slots[i].animState.transitionMode = 15;
                } else {
                    _clutState.slots[i].animState.active = 0;
                }
            }
        }
        _clutState.uploadPending = 1;
    }
}

static UNUSED void _stopClutSlotAnim(int arg0)
{
    _clutState.slots[arg0].animState.active = 0;
}

void vs_main_loadClut(u_short const* img, u_int slot, u_int colorOffset, u_int count)
{
    RECT rect;
    u_short px;
    u_int i;
    struct ColorInfo* dst;

    if (slot >= 14) {
        setRECT(&rect, colorOffset + 768, slot + 224, count, 1);
        LoadImage(&rect, (u_long*)img);
        return;
    }

    if (_clutState.slots[slot].locked == 0) {
        _clutState.slots[slot].animState.active = 0;
        for (i = 0; i < count; ++i) {
            px = img[i];
            dst = &_clutState.slots[slot].colorInfo[colorOffset + i];
            _clutBuffer[slot][colorOffset + i] = px;
            _clutState.slots[slot].clutBase[colorOffset + i] = px;
            dst->r = (px & 0x1F);
            dst->g = ((px & 0x3E0) >> 5);
            dst->b = ((px & 0x7C00) >> 10);
            dst->a = ((px & 0x8000) >> 15);
        }
        _clutState.uploadPending = 1;
    }
}

static void _loadClutBase(int mode, u_short* srcClut, int slot, short rOffset,
    short gOffset, short bOffset, int applyNow)
{
    int i;
    int new_var;
    int new_var2;
    int new_var3;
    short r;
    short g;
    short b;
    short value;
    u_short stp;

    for (i = 0; i < 256; ++i) {
        value = srcClut[i];
        if (value != 0) {
            switch (mode) {
            case 5:
                r = rOffset + (value & 0x1F) / 2;
                g = gOffset + ((value & 0x3E0) >> 5) / 2;
                b = bOffset + ((value & 0x7C00) >> 10) / 2;
                break;

            case 6:
                new_var = value & 0x1F;
                new_var2 = (value & 0x3E0) >> 5;
                new_var3 = (value & 0x7C00) >> 10;
                r = rOffset + ((new_var * 2) + (new_var2 * 3) + new_var3) / 6;
                g = gOffset + ((new_var * 2) + (new_var2 * 3) + new_var3) / 6;
                b = bOffset + ((new_var * 2) + (new_var2 * 3) + new_var3) / 6;
                break;

            case 7:
                new_var = value & 0x1F;
                new_var2 = (value & 0x3E0) >> 5;
                new_var3 = (value & 0x7C00) >> 10;
                r = rOffset + ((new_var * 2) + (new_var2 * 3) + new_var3) / 12;
                g = gOffset + ((new_var * 2) + (new_var2 * 3) + new_var3) / 12;
                b = bOffset + ((new_var * 2) + (new_var2 * 3) + new_var3) / 12;
                break;

            case 0:
            default:
                r = rOffset + (value & 0x1F);
                g = gOffset + ((value & 0x3E0) >> 5);
                b = bOffset + ((value & 0x7C00) >> 10);
                break;
            }

        } else {
            r = value & 0x1F;
            g = (value & 0x3E0) >> 5;
            b = (value & 0x7C00) >> 10;
        }

        stp = value;
        stp >>= 15;

        if (r >= 32) {
            r = 31;
        }
        if (g >= 32) {
            g = 31;
        }
        if (b >= 32) {
            b = 31;
        }
        if ((r << 16) < 1) {
            r = 0;
        }
        if ((g << 16) <= 0) {
            g = 0;
        }
        if ((b << 16) <= 0) {
            b = 0;
        }

        if ((((r | g | b) << 16) == 0) && (value & 0x7FFF)) {
            b = 1;
        }

        if (applyNow != 0) {
            _clutBuffer[slot][i] = r + (g << 5) + (b << 10) + (stp << 15);

            if (_clutState.slots[slot].animState.active == 0) {
                struct ColorInfo* colors = &_clutState.slots[slot].colorInfo[i];
                colors->r = r;
                colors->g = g;
                colors->b = b;
                colors->a = stp;
            }
        }

        _clutState.slots[slot].clutBase[i] = r + (g << 5) + (b << 10) + (stp << 15);
    }

    _clutState.uploadPending = 1;
}

static UNUSED void _loadClutBaseOffset(u_short* srcClut, int slot, u_short rOffset,
    u_short gOffset, u_short bOffset, int applyNow)
{
    _loadClutBase(8, srcClut, slot, rOffset, gOffset, bOffset, applyNow);
}

void vs_main_loadBgColors(void)
{
    int i;
    int (*bgColors)[6] = _clutState.bgColors;
    int* var_v1 = func_8008EB24();

    for (i = 0; i < 5; ++i) {
        _clutState.bgBaseColors[i].r = var_v1[i];
        _clutState.bgBaseColors[i].g = (var_v1[i] & 0xFF00) / 256;
        _clutState.bgBaseColors[i].b = (var_v1[i] & 0xFF0000) / 65536;

        bgColors[i][0] = (var_v1[i] & 0xFF) << 16;
        bgColors[i][1] = (var_v1[i] & 0xFF00) << 8;
        bgColors[i][2] = var_v1[i] & 0xFF0000;
    }
}

void vs_main_commitClut(void)
{
    RECT rect;

    if (_clutState.uploadPending != 0) {
        setRECT(&rect, 768, 224, 256, 14);
        LoadImage(&rect, (u_long*)_clutBuffer[0]);
        _clutState.uploadPending = 0;
    }
}

void vs_main_setClutState(int active) { _clutState.active = active; }

void vs_main_clutInit(void)
{
    int i;

    _clutState.uploadPending = 0;
    _clutState.active = 1;

    for (i = 0; i < 14; ++i) {
        _clutState.slots[i].locked = 0;
        _clutState.slots[i].animState.active = 0;
        _clutState.slots[i].animState.transitionMode = 0;
    }

    _clutState.bgAnimActive = 0;
    _clutState.bgTransitionMode = 0;

    for (i = 0; i < 17; ++i) {
        _clutState.colorSlots[i].active = 0;
        _clutState.colorSlots[i].mode = 0;
        _clutState.colorSlots[i].grayAmount = 0;
        *((int*)&_clutState.colorSlots[i].baseColor) = 0x404040;
        _clutState.colorSlots[i].color[2] = 0x400000;
        _clutState.colorSlots[i].color[1] = 0x400000;
        _clutState.colorSlots[i].color[0] = 0x400000;
    }
}

vs_main_zoneEnemyCache_t vs_main_zoneEnemyCache[4];
vs_main_flags_t vs_main_stateFlags;
vs_main_inventoryIndices_t vs_main_inventoryIndices;
static UNUSED int _18[0x15E];
