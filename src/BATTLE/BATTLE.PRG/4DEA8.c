#include "common.h"
#include "actorPrivate.h"
#include "4DEA8Private.h"
#include "146CPrivate.h"
#include "2842CPrivate.h"
#include "2EA3CPrivate.h"
#include "30DB0Private.h"
#include "38C1C.h"
#include "40564Private.h"
#include "44F14.h"
#include "573B8Private.h"
#include "5BF94Private.h"
#include "battleUnk.h"
#include "cameraPrivate.h"
#include "entity.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/cd.h"
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/graphics.h"
#include "src/SLUS_010.40/memory.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sfx.h"
#include "src/SLUS_010.40/sound.h"
#include "src/SLUS_010.40/zoneState.h"
#include "src/GIM/SCREFF2.PRG/0.h"
#include "scratch.h"
#include "tilePosition.h"
#include "vs_inline_c.h"
#include <stdio.h>
#include <memory.h>
#include <stddef.h>
#include <abs.h>
#include <inline_c.h>

typedef struct {
    u_char mode;
    u_char ease1;
    u_char ease2;
    u_char ease3;
    u_char time;
    u_char duration;
    u_char follow;
    u_char following;
    int value;
    int delta;
    short angle;
    short angleDelta;
    VECTOR start;
    VECTOR position;
    VECTOR velocity;
    VECTOR aux;
    VECTOR followDelta;
    VECTOR followPosition;
    VECTOR previousCamera;
    VECTOR computed;
    VECTOR current;
    VECTOR target;
} D_800F4BA4_t2;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
} func_800BD57C_t;

typedef struct {
    union {
        u_char u8[2];
        short s16;
    } unk0;
    short unk2;
    short unk4;
    short unk6;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
} func_800BDF6C_t;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    short unk4;
    short unk6;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
} func_800BDF6C_unk180_t;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    short unk14;
    short unk16;
    short unk18;
    short unk1A;
    short unk1C;
    short unk1E;
} func_800BDBB4_t;

typedef struct {
    D_800F4BA4_t2 lookAt;
    D_800F4BA4_t2 eye;
    func_800BD57C_t unk168;
    func_800BD57C_t unk174;
    func_800BDF6C_unk180_t projectionDistance;
    func_800BDF6C_unk180_t nearClip;
    func_800BDF6C_unk180_t farClip;
    func_800BDF6C_t unk1A4;
    func_800BDF6C_t unk1B0;
    short unk1BC;
    short unk1BE;
    short unk1C0;
    short unk1C2;
    short unk1C4;
    short unk1C6;
    short unk1C8;
    short unk1CA;
    int unk1CC;
    vs_ActorPosition unk1D0;
    int unk1E0[2];
    u_short unk1E8;
    u_short unk1EA;
    VECTOR unk1EC;
    func_800BDBB4_t unk1FC;
    func_800BDBB4_t unk21C;
    func_800BDBB4_t unk23C;
    func_800BDBB4_t unk25C;
    VECTOR unk27C;
} D_800F4BA4_t;

typedef struct {
    u_int visible : 1;
    u_int loading : 1;
    u_int unk0_2 : 1;
    u_int drawMode : 3;
    u_int unk0_6 : 18;
    u_int brightness : 8;
    int unk4;
    short x;
    short y;
    short scale;
    int unk10[0xFA];
} Gim;

typedef struct {
    char unk0;
    char curve;
    char elapsed;
    char duration;
    short startX;
    short startY;
    short deltaX;
    short deltaY;
    short startScale;
    short deltaScale;
    short startBrightness;
    short deltaBrightness;
} GimTween;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    short unk14;
} D_800F4B88_t;

typedef struct {
    int unk0;
} func_800BDBB4_t2;

typedef struct {
    char remaining;
    char next;
    char actors[17];
} ActorList;

typedef struct {
    TextOffset offset;
    short x;
    short y;
    int distance;
} TextPlacement;

typedef struct {
    int value;
    int distance;
    char unk8[8];
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;
    char unk40[16];
    SVECTOR rotation;
    SVECTOR rotation2;
    char unk60[16];
    MATRIX matrix;
} CameraScratch;

typedef struct {
    int distance;
    int steps;
    char unk8[8];
    VECTOR delta;
    VECTOR candidate;
    VECTOR direction;
    char unk40[0x30];
    MATRIX matrix;
} CameraMotionScratch;

typedef struct {
    char unk0[0x50];
    SVECTOR a;
    SVECTOR b;
    SVECTOR c;
} CameraShakeScratch;

typedef struct {
    u_char low;
    u_char high;
} ScriptBytePair;

// Comparison selected by the high nibble of a conditional opcode's second byte, applied
// as `flag <op> operand`
enum flagComparison {
    flagComparisonLe = 0x00,
    flagComparisonGe = 0x10,
    flagComparisonEq = 0x20,
    flagComparisonNe = 0x30,
    flagComparisonLt = 0x40,
    flagComparisonGt = 0x50,
    flagComparisonAnd = 0x60
};

// Operation selected by the high nibble of a flag modifying opcode's second byte,
// applied as `flag = flag <op> operand`
enum flagOperation {
    flagOperationAdd = 0x00,
    flagOperationSubtract = 0x10,
    flagOperationMultiply = 0x20,
    flagOperationDivide = 0x30,
    flagOperationModulo = 0x40,
    flagOperationAnd = 0x50,
    flagOperationOr = 0x60,
    flagOperationAssign = 0x70,
    flagOperationAbsDifference = 0x80,
    flagOperationSwap = 0x90
};

static int tryTextBoxPlacement(
    SVECTOR* origin, u_char* script, TextPlacement* result, u_char direction);
void expandActorSelector(u_short, ActorList*);
u_short nextActor(ActorList* arg0);
int getActorScreenPosition(int arg0, SVECTOR* arg1);
void func_800BBE10(u_short);
void func_800BBE04(int arg0);
void func_800BBE94(void);
void func_800BCA8C(D_800F4BA4_t2*, D_800F4BA4_t2*);
void func_800BCFB4(D_800F4BA4_t2*);
void func_800BC1CC(short, int);
int func_800BD2B8(MATRIX*);
void func_800BD57C(func_800BD57C_t* arg0);
int func_800BD610(void);
int func_800BDBB4(func_800BDBB4_t* arg0);
void func_800BDF6C(func_800BDF6C_unk180_t* arg0);
void func_800BE180(void);
void func_800BE36C(int, int);
void func_800BE3A0(void);
void func_800BE3D0(char arg0);
void func_800BE5A4(short arg0);
VECTOR* vectorAdd(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2);
VECTOR* vectorSubtract(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2);
VECTOR* setVectorImm(VECTOR*, u_char*);
VECTOR* vectorFixedPointMult(VECTOR*, VECTOR*, int);
void vecToRotMatrix(VECTOR*, MATRIX*);
int atan2FixedPoint(int arg0, int arg1);
static int fixedPointMult(int a, int b);
static int vectorMagnitude(VECTOR*);
static VECTOR* vectorCopy(VECTOR* arg0, VECTOR* arg1);
static VECTOR* sVectorToFixedPointVector(VECTOR* arg0, SVECTOR* arg1);
static void toNormalIntegerVector(VECTOR*, VECTOR*);

extern int D_800E9B34[];
extern int weaponDrawnModes[];
extern char animationBankBase[];
extern char skipResetPaletteOp[];
extern char skipTailMarkerOp[];
extern u_char D_800E9BEC[];
extern u_char D_800E9BF0[];
extern short D_800E9BF4[];
extern short D_800E9BF8[];
extern void sceneResetScript;
extern short D_800E9C00[];
extern u_char D_800E9C1C[];
extern short D_800E9C24[];
extern u_char D_800E9C28;
extern u_char D_800E9C2C;
extern u_short D_800F4B20;
extern GimTween gimTweens[];
extern D_800F4B88_t D_800F4B88;
extern char D_800F4B8B;
extern char D_800F4BA0;
extern D_800F4BA4_t* D_800F4BA4;
extern char D_800F4BA8;
extern void* mpdClearedSection;
extern u_short* scriptStrings;
extern char switchValue;
extern short D_800F4BB6;
extern char D_800F4BB8;
extern u_char D_800F4BB9;
extern char* D_800F4BC0[];
extern short D_800F4BE0;
extern char D_800F4BE4;
extern void* mpdRoomDoorSection;
extern char D_800F4BF8;
extern char loopCounters[];
extern short D_800F4C22;
extern void* D_800F4C24;
extern char D_800F4C34;
extern u_char* D_800F4C38[];
extern short D_800F4C4C;
extern char D_800F4C4E;
extern short mpdScriptSection;
extern short D_800F4C54;
extern char textBoxSelectionPending;
extern int scriptReturnAddress;
extern char D_800F4C69;
extern char D_800F4C6A;

extern char D_800F4B70[];
extern u_short D_800F4B28[];
extern Gim* gims;

int vs_battle_script_invalidOpcode(u_char* arg0, short arg1)
{
    char buf[64];

    sprintf(buf, "unknown code detected:%d,$%08x,$%02x", arg1, (u_int)arg0, *arg0);
    // Debug printing presumably ifdef'd out
    return scriptNext;
}

int vs_battle_script_nop(UNUSED u_char* arg0, UNUSED short arg1) { return scriptNext; }

int vs_battle_script_yield(UNUSED u_char* arg0, UNUSED short arg1) { return scriptYield; }

int vs_battle_script_0A_waitEvtLoad(UNUSED u_char* arg0, UNUSED short arg1)
{
    if ((evtCdSlot != 0) && (evtCdSlot->state != CdQueueStateLoaded)) {
        return scriptRepeat;
    }

    return scriptNext;
}

int vs_battle_script_0C_waitGimLoad(UNUSED u_char* arg0, UNUSED short arg1)
{
    return gims->loading;
}

/**
 * @param script Opcode bytes:
 *   - [1] bit 0 = keep the music playing if the section is skipped
 */
int vs_battle_script_0D_beginSkippable(u_char* script, UNUSED short arg1)
{
    scriptSkipMode = scriptSkippable;
    stopMusicOnSkip = !(script[1] & 1);
    return (skipRequested != 0) ? scriptYield : scriptNext;
}

static void endScriptSkip(u_char* script)
{
    short i;
    short endOpcode;

    for (i = 0; i < 3; ++i) {
        skipResetPaletteOp[1] = (i << 4) | 8;
        vs_battle_script_70(skipResetPaletteOp, 0);
    }

    func_800AACDC();

    endOpcode = 0xF;

    while (*script != endOpcode) {
        if (memcmp(script, skipTailMarkerOp, 4) == 0) {
            vs_battle_setStateFlag(0xA8, 0);
            return;
        }
        script = &script[D_800E9C30[*script]];
    }

    func_80093A70();
    vs_battle_setStateFlag(0xA8, 0);
}

/**
 * @param script Opcode bytes:
 *   - [1-2] offset from this opcode to jump to if the section was not skipped
 * @return scriptYield if the section was skipped, otherwise the address to
 * jump to.
 */
int vs_battle_script_0E_endSkippableBody(u_char* script, UNUSED short arg1)
{
    char prevMode = scriptSkipMode;
    scriptSkipMode = scriptSkipOff;

    if (prevMode == scriptSkipping) {
        endScriptSkip(script);
        return scriptYield;
    }

    return (int)&script[getShort(script + 1)];
}

int vs_battle_script_0F_endSkipHandler(u_char* arg0, UNUSED short arg1)
{
    char prevMode = scriptSkipMode;
    scriptSkipMode = scriptSkipOff;

    if (prevMode == scriptSkipping) {
        endScriptSkip(arg0);
        return scriptYield;
    }

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1] = (parentBoxId << 4) | boxId
 *   - [2-3] = flags/type (passed to arg1 of initTextBox)
 *   - [4] = x (in some unit, scaled *2 - 0x20)
 *   - [5] = y (scaled - 0x20)
 *   - [6] = width in characters
 *   - [7] = height in lines
 *   - [8-9] = speaker actor (>= 0x2000: none)
 *   - [10] = speaker animation
 */
int vs_battle_script_10_initTextBox(u_char* script, UNUSED short arg1)
{
    vs_TextBox* box;
    short speakerSelector;
    short centerY;
    short centerX;

    if ((script[1] & 0xF) == (script[1] >> 4)) {
        centerX = 32;
        centerX = (script[4] * 2) + ((((script[6] * 12) + 8) >> 1) - centerX);
        centerY = script[5] + 0xFFE0 + (((script[7] * 13) + 4) >> 1);
    } else {
        box = vs_battle_getTextBox((script[1] >> 4));
        centerX = box->x + 4;
        centerX += box->charsPerLine * 6;
        centerY = box->y + (((box->lineCount * 13) + 4) >> 1);
    }

    vs_battle_initTextBox(script[1] & 0xF, getShort(script + 2), (script[4] * 2) - 32,
        script[5] - 32, script[6], script[7], centerX, centerY);

    box = vs_battle_getTextBox(script[1] & 0xF);
    box->speakerAnimation = script[10];

    speakerSelector = getShort(&script[8]);

    if (speakerSelector < 0x2000) {
        box->unk0.speakerActor = resolveActorId(speakerSelector);
    }

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1] = boxId
 *   - [2] = string index
 *   - [3] = nonzero: do not wait for the player to advance the text
 */
int vs_battle_script_11_showTextBox(u_char* script, UNUSED short arg1)
{
    int printStatus;

    if (textBoxStatuses[script[1]] == 0) {

        vs_battle_setTextBox(script[1], (char*)&scriptStrings[scriptStrings[script[2]]]);

        if (script[3] == 0) {
            textBoxStatuses[script[1]] = 1;
            return scriptRepeat;
        }

        return scriptNext;
    }

    printStatus = vs_battle_setTextBox(script[1], NULL);

    if (printStatus >= 0) {

        // Dead code: vs_battle_setTextBox only returns 0 or -1
        if (printStatus > 0) {
            vs_main_stateFlags.scriptScratch[0] = printStatus;
        }

        textBoxStatuses[script[1]] = 0;

        return scriptNext;
    }

    return scriptRepeat;
}

/**
 * @param script Opcode bytes:
 *   - [1] = boxId
 */
int vs_battle_script_12_dismissTextBox(u_char* script, UNUSED short arg1)
{
    vs_battle_dismissTextBox(script[1]);

    return scriptNext;
}

static int tryTextBoxPlacement(
    SVECTOR* origin, u_char* script, TextPlacement* result, u_char direction)
{
    short dx = 0;
    short dy = 0;
    short width;
    short height;
    int delta;
    short x;
    short y;

    result->offset = func_800CCE10(
        script[5] & 0xF, (origin->vz ^ direction) * 4, script[6], script[7]);
    result->x = x = origin->vx + result->offset.x;
    result->y = y = origin->vy + result->offset.y;
    height = script[7] * 13 + 4;
    width = script[6] * 12 + 8;

    if (x < 4) {
        result->x = 4;
        delta = 4 - x;
        dx = delta;
    } else if (x + width > 320) {
        result->x = width = 320 - width;
        dx = width - x;
    }

    if (y < 4) {
        result->y = 4;
        delta = 4 - y;
        dy = delta;
    } else if (y + height > 216) {
        result->y = height = 216 - height;
        dy = height - y;
    }

    if (dx == 0 && dy == 0) {
        return 1;
    }

    result->distance = vs_gte_rsqrt(dx * dx + dy * dy);

    return 0;
}

/**
 * @param script Opcode bytes:
 *   - [1] = boxId
 *   - [2-3] = actor to place the box next to (resolved by resolveActorId)
 *   - [4-5] = flags (passed to initTextBox); [5] & 0xF is the box shape, which also
 *     selects the placement preset
 *   - [6] = width in characters
 *   - [7] = height in lines
 *   - [8] = speaker animation
 */
int vs_battle_script_13_initTextBoxNearActor(u_char* script, UNUSED short arg1)
{
    TextPlacement placements[4];
    SVECTOR origin;
    vs_TextBox* box;
    TextPlacement* best = NULL;
    u_int width;
    u_int height;
    int speakerActor;
    short i;

    getActorScreenPosition(resolveActorId(getShort(script + 2)), &origin);

    origin.vz = ((origin.vz - ONE / 4) & 0xC00) >> 10;

    for (i = 0; i < 4; ++i) {
        if (tryTextBoxPlacement(&origin, script, &placements[i], D_800E9BEC[i])) {
            best = &placements[i];
            break;
        }
    }

    if (best == NULL) {
        best = placements;
        for (i = 1; i < 4; ++i) {
            if (best->distance > placements[i].distance) {
                best = &placements[i];
            }
        }
    }

    width = script[6] * 12 + 8;
    height = script[7] * 13 + 4;

    vs_battle_initTextBox(script[1], getShort(script + 4), best->x, best->y, script[6],
        script[7], best->x + (width >> 1), best->y + (height >> 1));

    box = vs_battle_getTextBox(script[1]);
    // BUG: speakerActor is never initialized, this overwrites the "none" (32) default
    // that vs_battle_initTextBox just set
    box->unk0.speakerActor = speakerActor;
    box->unk0.flip = best->offset.flip;
    box->unk0.tail = best->offset.tail;
    box->speakerAnimation = script[8];

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1] = boxId
 */
int vs_battle_script_14_dismissTextBoxAndWait(u_char* script, UNUSED short arg1)
{
    return vs_battle_dismissTextBox(script[1]) != 0 ? scriptRepeat : scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1] = mask of pad buttons, only the low byte (L2, R2, L1, R1 and the face buttons)
 */
int vs_battle_script_15_waitButtonPressed(u_char* script, UNUSED short arg1)
{
    if (vs_main_buttonsPressed.all & script[1]) {
        return scriptYield;
    }

    return scriptRepeat;
}

/**
 * @param script Opcode bytes:
 *   - [1-2] = GIM index
 *   - [3] = first VRAM page slot
 */
int vs_battle_script_16_loadGim(u_char* script, UNUSED short arg1)
{
    loadGim(getShort(script + 1), script[3]);

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1] = (image << 6) | mode, image is 0-2 within the GIM and mode selects the draw
 *     function
 *   - [2] = x offset from the screen centre, signed, in units of 2 pixels
 *   - [3] = y offset from the screen centre, signed, in units of 2 pixels
 *   - [4] = scale, 0x20 is full size
 *   - [5] = brightness, 0x80 is normal
 */
int vs_battle_script_17_showGimImage(u_char* script, UNUSED short arg1)
{
    GimTween* tween;

    Gim* gim = gims;

    if (gim == NULL) {
        return scriptNext;
    }

    tween = &gimTweens[script[1] >> 6];
    tween->duration = 0;

    gim += script[1] >> 6;

    gim->drawMode = script[1] & 3;
    gim->x = (signed char)script[2] * 2;
    gim->y = (signed char)script[3] * 2;
    gim->scale = script[4] << 7;
    gim->brightness = script[5];

    activateGimImage(script[1] >> 6, gim, script);

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1] = x offset from the screen centre, signed, in units of 2 pixels
 *   - [2] = y offset from the screen centre, signed, in units of 2 pixels
 *   - [3] = target scale, 0x20 is full size
 *   - [4] = target brightness
 *   - [5] = (image << 6) | curve, curve 0-3 are built in and 4-7 are set up by script
 *   - [6] = duration
 */
int vs_battle_script_18_tweenGimImage(u_char* script, UNUSED short arg1)
{
    Gim* gim = gims;
    GimTween* tween = &gimTweens[script[5] >> 6];

    if (gim == NULL) {
        return scriptNext;
    }

    gim += script[5] >> 6;

    if (tween->duration != 0) {
        return scriptRepeat;
    }

    tween->deltaX = (((signed char)script[1] * 2) - (tween->startX = gim->x));
    tween->deltaY = (((signed char)script[2] * 2) - (tween->startY = gim->y));
    tween->deltaScale = ((script[3] << 7) - (tween->startScale = gim->scale));
    tween->deltaBrightness = script[4] - (tween->startBrightness = gim->brightness);
    tween->curve = script[5] & 7;
    tween->duration = script[6];
    tween->elapsed = 0;

    return scriptNext;
}

int vs_battle_script_19_unloadGim(UNUSED u_char* arg0, UNUSED short arg1)
{
    unloadGim();

    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

int vs_battle_script_1A_waitGimTweens(UNUSED u_char* arg0, UNUSED short arg1)
{
    return (gimTweens[0].duration | gimTweens[1].duration | gimTweens[2].duration) != 0
             ? scriptRepeat
             : scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1] = printf argument integer to set (0-9)
 *   - [2-3] = state flag id in bits 0-9, type in bits 14-15: 0 = unsigned byte,
 *     1 = signed byte, 2 = unsigned 16 bits, 3 = signed 16 bits. 2 and 3 read
 *     two sequential state flags.
 */
int vs_battle_script_1B_setPrintfArgInt(u_char* script, UNUSED short arg1)
{
    int flag = getShort(script + 2) & 0x3FF;

    switch (script[3] >> 6) {
    case 0:
        vs_battle_printfArgs.integers[script[1]] = getStateFlag(flag);
        break;

    case 1:
        vs_battle_printfArgs.integers[script[1]] = (signed char)getStateFlag(flag);
        break;

    case 2:
        vs_battle_printfArgs.integers[script[1]] =
            getStateFlag(flag) | ((getStateFlag(flag + 1)) << 8);
        break;

    case 3:
        vs_battle_printfArgs.integers[script[1]] =
            (short)(getStateFlag(flag) | ((getStateFlag(flag + 1)) << 8));
        break;
    }

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1] = (boxId << 5) | animation duration (0-31)
 */
int vs_battle_script_1D_setTextBoxAnimationDuration(u_char* script, UNUSED short arg1)
{
    vs_battle_getTextBox(script[1] >> 5)->animationDuration = script[1] & 0x1F;

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1] = mask of the text boxes to choose between, bit n is box n
 */
int vs_battle_script_1C_selectTextBox(u_char* script, UNUSED short arg1)
{
    if (scriptSkipMode == scriptSkipping) {
        return scriptNext;
    }

    if (textBoxSelectionPending != 0) {

        short selection = selectTextBox(script[1]);

        if ((selection << 0x10) != 0) {
            // The first scratch flag returns the choice (1-based) to the script
            vs_battle_setStateFlag(scriptScratch, selection);

            textBoxSelectionPending = 0;

            return scriptNext;
        }
    } else {
        selectTextBox(script[1]);
        textBoxSelectionPending = 1;
    }

    return scriptRepeat;
}

/**
 * @param script Opcode bytes:
 *   - [1-2] = actor selector, a single actor or a group
 *   - [3] = nonzero: play the death animation first, 0: start the fade-out directly
 */
int vs_battle_script_1E_actorDeath(u_char* script, UNUSED short arg1)
{
    ActorList actors;

    expandActorSelector(getShort(script + 1), &actors);

    while (1) {
        int actorId = nextActor(&actors);

        if (actorId == 1) {
            break;
        }

        triggerActorDeath(actorId, script[3]);
    }

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = first of three consecutive state flags that receive the actor's tile
 *     x, surface and z. The first flag is set to 0xFF if the actor does not exist.
 */
int vs_battle_script_1F_getActorTile(u_char* script, UNUSED short arg1)
{
    vs_ActorPosition position;
    u_short actor = getShort(script + 1);
    u_short flag = getShort(script + 3);

    if (actor & 0x1000) {

        actor &= 0x1F;

        if (getActor(actor) == NULL) {
            vs_battle_setStateFlag(flag, 0xFF);
            return scriptNext;
        }
    } else {

        actor = func_8007CF18(actor);

        if (actor == 1) {
            vs_battle_setStateFlag(flag, 0xFF);
            return scriptNext;
        }
    }

    vs_battle_getActorPosition(actor, &position);
    vs_battle_setStateFlag(flag, position.unk0.unk0.x);
    vs_battle_setStateFlag(flag + 1, position.unk0.unk0.surface);
    vs_battle_setStateFlag(flag + 2, position.unk0.unk0.z);

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1-2] = actor selector for the empty slot to create the actor in
 *   - [3-4] = model index (OBJ/xx.SHP), doubles as the id the actor is looked up by
 *   - [5-8] = tile to spawn on and facing: x, surface, z and facing (1/256 turn)
 */
int vs_battle_script_20_spawnActor(u_char* script, UNUSED short arg1)
{
    vs_TilePosition tile[3];

    tile[0].x = script[5];
    tile[0].surface = script[6];
    tile[0].z = script[7];
    tile[0].extra = script[8];

    spawnModelActor(resolveActorId(getShort(script + 1)), getShort(script + 3), tile);

    return scriptNext;
}

/**
 * Walks an actor to a tile, with pathfinding.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = tile x
 *   - [4] = unused
 *   - [5] = tile z
 */
int vs_battle_script_21_walkActorToTile(u_char* script, UNUSED short arg1)
{
    SVECTOR destination;
    u_short actor = resolveActorId(getShort(script + 1));

    destination.vx = (script[3] << 7) + 0x40;
    destination.vy = 0;
    destination.vz = (script[5] << 7) + 0x40;

    if (scriptSkipMode == scriptSkipping) {
        destination.pad = -0x8000;
        slideActorToCoordinate(actor, &destination, 0);
    } else {
        walkActorToCoordinate(actor, &destination);
    }

    func_8009DC8C(actor);

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = animation index within the bank
 *   - [4] = unused
 *   - [5] = (bank << 6) | blend frames, the bank selects the base id in animationBankBase
 */
int vs_battle_script_22_playAnimation(u_char* script, UNUSED short arg1)
{
    vs_battle_setActorAnimation(resolveActorId(getShort(script + 1)),
        animationBankBase[script[5] >> 6] + script[3], script[4], script[5] & 0x3F);

    return scriptNext;
}

/**
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = actor flags: bit 0 enabled, bit 1 visible, bit 2 frozen, bit 6 unknown
 *   - [4] = flags for the weapon models and the actor list:
 *     - bit 0: new flag value for the blade model
 *     - bit 1: leave the blade model's flag unchanged (ignores bit 0)
 *     - bit 2: new flag value for the shield model
 *     - bit 3: leave the shield model's flag unchanged (ignores bit 2)
 *     - bit 5: toggle actor deactivation
 */
int vs_battle_script_23_setActorFlags(u_char* script, UNUSED short arg1)
{
    ActorList actors;

    expandActorSelector(getShort(script + 1), &actors);

    while (1) {
        int shieldFlag;
        int bladeFlag;
        int flags;
        u_int options;
        int actor = nextActor(&actors);

        if (actor == 1) {
            break;
        }

        flags = vs_battle_getActorFlags(actor);
        bladeFlag = flags & 0x800;
        shieldFlag = flags & 0x1000;
        options = script[4];

        if (!(options & 2)) {
            bladeFlag = (options & 1) << 0xB;
        }

        if (!(options & 8)) {
            shieldFlag = (options << 0xA) & 0x1000;
        }

        setActorInactive(actor, (options >> 5) & 1);
        vs_battle_setActorFlags(actor, bladeFlag | shieldFlag | script[3]);
        func_8009D88C(actor);
    }

    return scriptNext;
}

/**
 * Overrides the stereo pan and volume used for an actor's sound effects.
 * @param script Opcode bytes:
 *   - [1-2] = actor id
 *   - [3] = mode:
 *     - 0: clear the override, sounds follow the actor's position on screen
 *     - 1: use the pan and volume below, ramped over the duration.
 *     - 2: mute the actor's sounds
 *   - [4] = pan, 0x80 is centered
 *   - [5] = volume, 0x7F is maximum
 *   - [6] = ramp duration in frames, 0 applies immediately
 */
int vs_battle_script_24_setActorSfxPanVolume(u_char* script, UNUSED short arg1)
{
    SfxOverride override;
    int actorId;

    override.mode = script[3];
    override.pan = script[4];
    override.volume = script[5];
    override.duration = script[6];

    actorId = resolveActorId(getShort(script + 1));

    if (actorId == 0x2001) {
        actorId = -1;
    }

    setActorsSfxOverride(actorId, &override);

    return scriptNext;
}

/**
 * Moves an actor to a tile and turns it to a facing, ignoring the tile map.
 * Animated move (non-zero values for the frames) does not seem to be used by the scripts.
 * Does not respect paths; walkActorToTile is used for walking in practice.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-5] = tile x, surface and z
 *   - [6] = final facing (1/256 turn). With frame counts, 0xFF skips the final turn;
 *   - [7] = movement frame count, 0 = immediately, 0xFF = default (from distance and
 *     the actor's unk5C2)
 *   - [8] = turn frame count, 0 = immediately, 0xFF = default (from angle and the
 *     actor's unk5C0)
 */
int vs_battle_script_25_moveActorToTile(u_char* script, UNUSED short arg1)
{
    vs_TilePosition tile[3];
    u_short actor = resolveActorId(getShort(script + 1));

    tile[0].x = script[3];
    tile[0].surface = script[4];
    tile[0].z = script[5];
    tile[0].extra = script[6];

    if (scriptSkipMode == scriptSkipping) {
        moveActorToTile(actor, tile, 0, 0);
    } else {
        moveActorToTile(actor, tile, script[7] != 0xFF ? script[7] : -1,
            script[8] != 0xFF ? script[8] : -1);
    }

    func_8009DC8C(actor);

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * Like moveActorToTile, but to a position given in world coordinates instead of a tile.
 * Does not respect paths; walkActorToCoordinate is used for walking in practice.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = x in bits 1-15 (value >> 1). If bit 0 is set, x, y and z are added to the
 *     actor's current position instead of replacing it
 *   - [5-6] = y (height), 0x8000 = the ground height at the target (absolute only)
 *   - [7-8] = z
 *   - [9] = facing (1/256 turn), 0xFF = none: turn towards the direction of travel
 *   - [10] = movement frame count, 0 = immediately, 0xFF = default
 *   - [11] = turn frame count, 0 = immediately, 0xFF = default
 */
int vs_battle_script_26_moveActorToCoordinate(u_char* arg0, UNUSED short arg1)
{
    vs_ActorPosition position;
    u_short actor = resolveActorId(getShort(arg0 + 1));
    short x = getShort(arg0 + 3) >> 1;
    short y = getShort(arg0 + 5);
    short z = getShort(arg0 + 7);

    if (arg0[3] & 1) {
        vs_battle_getActorPosition(actor, &position);
        applyVector(&position.unk0.unk4, x, y, z, +=);
    } else {
        setVector(&position.unk0.unk4, x, y, z);
    }

    if (arg0[9] != 0xFF) {
        position.unk0.unk4.pad = arg0[9] << 4;
    } else {
        position.unk0.unk4.pad = -0x8000;
    }

    if (scriptSkipMode == scriptSkipping) {
        moveActorToCoordinate(actor, &position.unk0.unk4, 0, 0);
    } else {
        moveActorToCoordinate(actor, &position.unk0.unk4,
            arg0[10] != 0xFF ? arg0[10] : -1, arg0[11] != 0xFF ? arg0[11] : -1);
    }

    func_8009DC8C(actor);

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * Slides an actor to a tile over time, ignoring the tile map. Unlike moveActorToTile
 * the actor only changes position, there is no walk animation and no turning.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-5] = tile x, surface and z
 *   - [6] = frame count, 0xFF = default (from distance and the actor's unk5C2)
 */
int vs_battle_script_27_slideActorToTile(u_char* script, UNUSED short arg1)
{
    vs_TilePosition tile[4];
    u_short actor = resolveActorId(getShort(script + 1));

    tile[0].x = script[3];
    tile[0].surface = script[4];
    tile[0].z = script[5];
    tile[0].extra = 0xFF;

    if (scriptSkipMode == scriptSkipping) {
        slideActorToTile(actor, tile, 0);
    } else {
        slideActorToTile(actor, tile, script[6] != 0xFF ? script[6] : -1);
    }

    func_8009DC8C(actor);

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * Like slideActorToTile, but to a position given in world coordinates instead of a tile.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = x in bits 1-15 (value >> 1). If bit 0 is set, x, y and z are added to the
 *     actor's current position instead of replacing it
 *   - [5-6] = y (height)
 *   - [7-8] = z
 *   - [9] = frame count, 0xFF = default (from distance and the actor's unk5C2)
 */
int vs_battle_script_28_slideActorToCoordinate(u_char* script, UNUSED short arg1)
{
    vs_ActorPosition position;
    u_short actor = resolveActorId(getShort(script + 1));
    short x = getShort(script + 3) >> 1;
    short y = getShort(script + 5);
    short z = getShort(script + 7);

    if (script[3] & 1) {
        vs_battle_getActorPosition(actor, &position);
        applyVector(&position.unk0.unk4, x, y, z, +=);
    } else {
        setVector(&position.unk0.unk4, x, y, z);
    }

    position.unk0.unk4.pad = -0x8000;

    if (scriptSkipMode == scriptSkipping) {
        slideActorToCoordinate(actor, &position.unk0.unk4, 0);
    } else {
        slideActorToCoordinate(
            actor, &position.unk0.unk4, script[9] != 0xFF ? script[9] : -1);
    }

    func_8009DC8C(actor);

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * Attaches an actor to a bone of a parent actor. A parent selector >= 0x2000 detaches it.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = parent actor selector
 *   - [5] = bone index in the parent
 *   - [6] = unused
 */
int vs_battle_script_29_attachActor(u_char* script, UNUSED short arg1)
{
    u_short actor = resolveActorId(getShort(script + 1));
    u_short parent = resolveActorId(getShort(script + 3));

    if (parent >= 0x2000) {
        detachActor(actor, parent);
    } else {
        attachActor(actor, parent, script[5], script[6]);
    }

    return scriptNext;
}

/**
 * Like walkActorToTile, but to a position given in world coordinates instead of a tile.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = x
 *   - [5-6] = z
 */
int vs_battle_script_2A_walkActorToCoordinate(u_char* script, UNUSED short arg1)
{
    SVECTOR destination;
    u_short actor = resolveActorId(getShort(script + 1));
    destination.vx = getShort(script + 3);
    destination.vy = 0;
    destination.vz = getShort(script + 5);

    if (scriptSkipMode == scriptSkipping) {
        destination.pad = -0x8000;
        slideActorToCoordinate(actor, &destination, 0);
    } else {
        walkActorToCoordinate(actor, &destination);
    }

    func_8009DC8C(actor);

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * Turns an actor to face a direction.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = facing (1/256 turn)
 *   - [4] = turn direction: 0 = shortest, 1 = positive, -1 = negative
 *   - [5] = frame count, 0 = immediately, 0xFF = default (from angle and the actor's
 *     unk5C0)
 */
int vs_battle_script_2B_turnActorToFacing(u_char* script, UNUSED short arg1)
{
    vs_ActorPosition position;
    u_short actor = resolveActorId(getShort(script + 1));
    short frames = script[5] != 0xFF ? script[5] : -1;

    if (script[4] != 0) {
        int angle;

        vs_battle_getActorPosition(actor, &position);

        angle = (script[3] << 4) - position.unk0.unk4.pad;

        if (angle < -ONE / 2) {
            angle += ONE;
        }

        if (angle > ONE / 2) {
            angle -= ONE;
        }

        switch ((signed char)script[4]) {
        case -1:
            if (angle > 0) {
                angle -= ONE;
            }
            break;
        case 1:
            if (angle < 0) {
                angle += ONE;
            }
            break;
        }

        turnActorToRelativeFacing(actor, angle, frames);
    } else {
        turnActorToFacing(actor, script[3] << 4, frames);
    }

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * Turns an actor to face the tile another actor is standing on.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = target actor selector
 *   - [5] = frame count, 0 = immediately, 0xFF = default (from angle and the actor's
 *     unk5C0)
 */
int vs_battle_script_2C_turnActorToFaceActor(u_char* script, UNUSED short arg1)
{
    vs_ActorPosition position;
    u_short actor = resolveActorId(getShort(script + 1));

    vs_battle_getActorPosition(resolveActorId(getShort(script + 3)), &position);
    turnActorToFaceTile(actor, &position.unk0.unk0, script[5] != 0xFF ? script[5] : -1);

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * Turns an actor to face a tile.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-5] = tile x, surface and z
 *   - [6] = frame count, 0 = immediately, 0xFF = default (from angle and the actor's
 *     unk5C0)
 */
int vs_battle_script_2D_turnActorToFaceTile(u_char* script, UNUSED short arg1)
{
    vs_TilePosition tile;
    u_short actor = resolveActorId(getShort(script + 1));

    tile.x = script[3];
    tile.surface = script[4];
    tile.z = script[5];

    // BUG: tile.extra is uninitialised, but used as the facing if already on the tile
    turnActorToFaceTile(actor, &tile, script[6] != 0xFF ? script[6] : -1);

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * Sets the scale of an actor, per axis.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = x scale (0x1000 = normal size)
 *   - [5-6] = y scale
 *   - [7-8] = z scale
 *   - [9] = frame count to change over, 0 = immediately
 */
int vs_battle_script_2E_setActorScale(u_char* script, UNUSED short arg1)
{
    SVECTOR scale;
    setVector(&scale, getShort(script + 3), getShort(script + 5), getShort(script + 7));

    setActorScale(resolveActorId(getShort(script + 1)), &scale, script[9]);

    return scriptNext;
}

/**
 * Removes actors, the counterpart of spawnActor. Enemies have their state saved and are
 * not marked as hidden, so they return when the room is reloaded.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 */
int vs_battle_script_2F_despawnActor(u_char* script, UNUSED short arg1)
{
    ActorList actors;

    expandActorSelector(getShort(script + 1), &actors);

    while (1) {
        int actor = nextActor(&actors);

        if (actor == 1) {
            break;
        }

        despawnActor(actor);
    }

    return scriptNext;
}

/**
 * Waits until the selected activities of an actor have finished.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = mask of the vs_battle_getActorFlags bits to wait for
 */
int vs_battle_script_30_waitActorActivity(u_char* script, UNUSED short arg1)
{
    u_short actor = resolveActorId(getShort(script + 1)) & 0xFFFF;
    u_short status = vs_battle_getActorFlags(actor) ^ 0x81;
    u_short mask = getShort(script + 3);

    if (mask & 1) {
        if (isActorWalkDone(actor) == 0) {
            status |= 1;
        }
    }

    return (status & mask) != 0 ? scriptRepeat : scriptNext;
}

/**
 * Overrides the ambient light colour of an actor. Black (0, 0, 0) restores the colour
 * taken from the map lighting at the actor's position.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-5] = red, green and blue (0x80 = neutral)
 */
int vs_battle_script_31_setActorLightColor(u_char* script, UNUSED short arg1)
{
    CVECTOR color;

    color.r = script[3];
    color.g = script[4];
    color.b = script[5];

    if (color.r | color.g | color.b) {
        setActorLightColor(resolveActorId(getShort(script + 1)), &color);
    } else {
        setActorLightColor(resolveActorId(getShort(script + 1)), NULL);
    }

    return scriptNext;
}

/**
 * Queues an animation to play when the actor's current animation ends.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = animation index within the bank
 *   - [4] = unused
 *   - [5] = (bank << 6) | blend frames, as for playAnimation
 */
int vs_battle_script_32_queueAnimation(u_char* script, UNUSED short arg1)
{
    queueActorAnimation(resolveActorId(getShort(script + 1)),
        animationBankBase[script[5] >> 6] + script[3], script[5] & 0x3F, 0);

    return scriptNext;
}

/**
 * Rotates an actor, either absolutely or relative to its current one.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = 0: rotate to the given absolute rotation, otherwise rotate by it
 *   - [4-5] = x rotation (1/4096 turn)
 *   - [6-7] = y rotation (the facing)
 *   - [8-9] = z rotation
 *   - [10] = frame count, 0 = immediately, 0xFF = default (from angle and the actor's
 *     unk5C0)
 */
int vs_battle_script_33_rotateActor(u_char* script, UNUSED short arg1)
{
    SVECTOR rotation;
    u_short actor = resolveActorId(getShort(script + 1));
    short frames = script[10] != 0xFF ? script[10] : -1;

    rotation.vx = getShort(script + 4);
    rotation.vy = getShort(script + 6);
    rotation.vz = getShort(script + 8);

    if (script[3] != 0) {
        func_800A9F64(actor, &rotation, frames);
    } else {
        func_800A9FD0(actor, &rotation, frames);
    }

    D_800F4B70[actor] = 1;

    return scriptNext;
}

/**
 * Turns the actor's head to the given angles.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = pitch (1/4096 turn)
 *   - [5-6] = yaw
 *   - [7] = speed, 0 = unlimited
 */
int vs_battle_script_34_setActorLookAngles(u_char* script, UNUSED short arg1)
{
    SVECTOR angles;
    int actor;
    int speed;

    angles.vx = getShort(script + 3);
    angles.vy = getShort(script + 5);
    angles.vz = 0;
    actor = resolveActorId(getShort(script + 1));
    speed = ONE;

    if (script[7] != 0) {
        speed = script[7];
    }

    setActorLook(actor, -4, &angles, speed);

    return scriptNext;
}

/**
 * Like playAnimation, but starts the animation part way through.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = animation index within the bank
 *   - [4] = frame to start at
 *   - [5] = unused
 *   - [6] = (bank << 6) | blend frames
 */
int vs_battle_script_35_playAnimationFromFrame(u_char* script, UNUSED short arg1)
{
    setActorAnimationFromFrame(resolveActorId(getShort(script + 1)),
        animationBankBase[script[6] >> 6] + script[3], script[6] & 0x3F, script[4]);

    return scriptNext;
}

/**
 * Like queueAnimation, but the queued animation starts part way through.
 * @param script Opcode bytes: as for playAnimationFromFrame
 */
int vs_battle_script_36_queueAnimationFromFrame(u_char* script, UNUSED short arg1)
{
    queueActorAnimation(resolveActorId(getShort(script + 1)),
        animationBankBase[script[6] >> 6] + script[3], script[6] & 0x3F, script[4]);

    return scriptNext;
}

/**
 * Sets the animation an actor plays while moving with moveActorToTile or
 * moveActorToCoordinate.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = animation bank, selects the base id in animationBankBase
 *   - [4] = animation index within the bank, 0xFF = the default
 */
int vs_battle_script_37_setActorMoveAnimation(u_char* script, UNUSED short arg1)
{
    int actor = resolveActorId(getShort(script + 1));

    if (script[4] == 0xFF) {
        setActorMoveAnimation(actor, -1);
    } else {
        setActorMoveAnimation(actor, animationBankBase[script[3]] + script[4]);
    }

    return scriptNext;
}

/**
 * Turns the actor's head towards another actor.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = target actor selector, 0x2000 = stop looking at anything
 *   - [5] = speed, 0 = unlimited
 */
int vs_battle_script_38_setActorLookTarget(u_char* script, UNUSED short arg1)
{
    int speed;

    int target = resolveActorId(getShort(script + 3));
    int actor = resolveActorId(getShort(script + 1));

    int mode = -2;

    if (target != 0x2000) {
        mode = target;
    }

    speed = ONE;

    if (script[5] != 0) {
        speed = script[5];
    }

    setActorLook(actor, mode, NULL, speed);

    return scriptNext;
}

/**
 * Turns the actor's head towards a world position.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = x
 *   - [5-6] = y
 *   - [7-8] = z
 *   - [9] = speed, 0 = unlimited
 */
int vs_battle_script_39_setActorLookPosition(u_char* script, UNUSED short arg1)
{
    SVECTOR position;
    int actor;
    int speed;

    setVector(
        &position, getShort(script + 3), getShort(script + 5), getShort(script + 7));

    actor = resolveActorId(getShort(script + 1));
    speed = ONE;

    if (script[9] != 0) {
        speed = script[9];
    }

    setActorLook(actor, -1, &position, speed);

    return scriptNext;
}

/**
 * Enqueues event data: an event sequence (ESQ), which provides
 * the animations in bank 1 of animationBankBase, and an event texture map (ETM), which
 * holds facial animation frames.
 * @param script Opcode bytes:
 *   - [1-2] = event data id (E<id>.ESQ and E<id>.ETM)
 *   - [3] = bits 0-1: slot, bits 2-3: what to load (0 the ESQ, 1 the ESQ and then the
 *     ETM, 2 the ETM), bits 4-7: selects the VRAM slot of the ETM
 */
int vs_battle_script_3A_enqueueEventData(u_char* script, UNUSED short arg1)
{
    switch ((script[3] >> 2) & 3) {
    case 0:
        enqueueEsq(script[3] & 3, getShort(script + 1));
        break;

    case 1:
        enqueueEsqAndEtm(script[3] & 3, getShort(script + 1), (script[3] >> 4) + 0x1A);
        break;

    case 2:
        enqueueEtm(script[3] & 3, getShort(script + 1), (script[3] >> 4) + 0x1A);
        break;
    }

    return scriptNext;
}

/**
 * Waits until the object data queue is empty.
 */
int vs_battle_script_3B_waitDataQueueEmpty(UNUSED u_char* script, UNUSED short arg1)
{
    // BUG: a full queue has no empty slot (-1), so this does not wait
    return getEmptyObjectDataSlot() > 0 ? scriptRepeat : scriptNext;
}

/**
 * Unloads event data.
 * @param script Opcode bytes:
 *   - [1] = bits 0-1: slot, bit 2: unload only the ETM, otherwise the ESQ and its ETM
 */
int vs_battle_script_3C_unloadEventData(u_char* script, UNUSED short arg1)
{
    if (script[1] & 4) {
        unloadEtm(script[1] & 3);
    } else {
        unloadEsqAndEtm(script[1]);
    }

    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

/**
 * Selects the slot of the loaded event data used by actors.
 * @param script Opcode bytes:
 *   - [1] = slot (1-3)
 */
int vs_battle_script_3D_selectEventData(u_char* script, UNUSED short arg1)
{
    selectEventData(script[1]);

    return scriptNext;
}

/**
 * Sets an edge highlight for an actor: a second copy of the actor in a flat colour,
 * displaced and pushed back in the ordering table.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-5] = offset x, y and z of the copy
 *   - [6] = number of ordering table entries to push the copy back
 *   - [7-9] = red, green and blue of the copy, all zero = no edge highlight
 */
int vs_battle_script_3E_setActorEdgeHighlight(u_char* script, UNUSED short arg1)
{
// `offset` below appers to have been defined as a flat array of bytes in the original
#ifdef NON_MATCHING
    typedef EdgeHighlight EdgeHighlightBytes;
#else
    typedef struct {
        signed char x;
        signed char y;
        signed char z;
        u_char otDepth;
    } EdgeHighlightBytes;
#endif

    CVECTOR color;
    EdgeHighlightBytes offset;
    UNUSED int _[2];

    color.r = script[7];
    color.g = script[8];
    color.b = script[9];

    if (color.r | color.g | color.b) {

        offset.x = script[3];
        offset.y = script[4];
        offset.z = script[5];
        offset.otDepth = script[6];

        vs_battle_setActorEdgeHighlight(
            resolveActorId(getShort(script + 1)), 1, (EdgeHighlight*)&offset, &color);
    } else {
        vs_battle_setActorEdgeHighlight(
            resolveActorId(getShort(script + 1)), 0, NULL, NULL);
    }

    return scriptNext;
}

/**
 * Draws, sheathes or toggles the weapons of the selected actors.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = 0 = sheathe, 1 = draw, 2 = toggle
 */
int vs_battle_script_3F_setWeaponDrawn(u_char* script, UNUSED short arg1)
{
    ActorList actors;

    expandActorSelector(getShort(script + 1), &actors);

    while (1) {
        int actor = nextActor(&actors);

        if (actor == 1) {
            break;
        }

        setWeaponDrawn(actor, weaponDrawnModes[script[3]]);
    }

    return scriptNext;
}

/**
 * Continues if a state flag compares true against an immediate value, otherwise jumps.
 * @param script Opcode bytes:
 *   - [1] = comparison in the high nibble (flagComparison*), bits 6-9 of the flag id in
 *     the low nibble
 *   - [2] = bits 0-5 of the flag id in bits 2-7
 *   - [3] = value to compare with (signed)
 *   - [4-5] = offset from this opcode to jump to if the comparison is false
 */
int vs_battle_script_40_jumpFwdUnlessFlagImm(u_char* script, UNUSED short arg1)
{
    char flag = getStateFlag(((u_char)script[2] >> 2) | ((script[1] & 0xF) << 6));
    char value = script[3];

    switch (script[1] & 0xF0) {
    case flagComparisonLe:
        if (flag <= value) {
            return scriptNext;
        }
        break;

    case flagComparisonGe:
        if (flag >= value) {
            return scriptNext;
        }
        break;

    case flagComparisonEq:
        if (flag == value) {
            return scriptNext;
        }
        break;

    case flagComparisonNe:
        if (flag != value) {
            return scriptNext;
        }
        break;

    case flagComparisonLt:
        if (flag < value) {
            return scriptNext;
        }
        break;

    case flagComparisonGt:
        if (flag > value) {
            return scriptNext;
        }
        break;

    case flagComparisonAnd:
        if (flag & value) {
            return scriptNext;
        }
        break;
    }

    return (long)&script[getShort(script + 4)];
}

/**
 * Continues if a state flag compares true against another state flag, otherwise jumps.
 * Like jumpFwdUnlessFlagImm, but the value to compare with is a state flag (also there
 *  is no AND op)
 * @param script Opcode bytes:
 *   - [1] = comparison in the high nibble (flagComparison*), bits 6-9 of the first flag
 *     id in the low nibble
 *   - [2] = bits 0-5 of the first flag id in bits 2-7, bits 8-9 of the second flag id in
 *     bits 0-1
 *   - [3] = bits 0-7 of the second flag id
 *   - [4-5] = offset from this opcode to jump to if the comparison is false
 */
int vs_battle_script_41_jumpFwdUnlessFlag(u_char* script, UNUSED short arg1)
{
    char flag = getStateFlag(((u_char)script[2] >> 2) | ((script[1] & 0xF) << 6));
    char other = getStateFlag(script[3] | ((script[2] & 3) << 8));

    switch (script[1] & 0xF0) {
    case flagComparisonLe:
        if (flag <= other) {
            return scriptNext;
        }
        break;

    case flagComparisonGe:
        if (flag >= other) {
            return scriptNext;
        }
        break;

    case flagComparisonEq:
        if (flag == other) {
            return scriptNext;
        }
        break;

    case flagComparisonNe:
        if (flag != other) {
            return scriptNext;
        }
        break;

    case flagComparisonLt:
        if (flag < other) {
            return scriptNext;
        }
        break;

    case flagComparisonGt:
        if (flag > other) {
            return scriptNext;
        }
        break;
    }

    return (long)&script[getShort(script + 4)];
}

/**
 * Jumps over the else branch, the opcode after it is always the target
 * of a conditional jump (40, 41 or 47).
 * @param script Opcode bytes:
 *   - [1-2] = target offset from this opcode
 */
int vs_battle_script_42_jumpFwdElse(u_char* script, UNUSED short arg1)
{
    return (long)&script[getShort(script + 1)];
}

/**
 * Presumably for jumping to a label.
 * @param script Opcode bytes:
 *   - [1-2] = target offset from this opcode
 */
int vs_battle_script_45_jumpFwd(u_char* script, UNUSED short arg1)
{
    return (long)&script[getShort(script + 1)];
}

/**
 * Starts a switch: stores the value of a state flag, for the jumpFwdCase opcodes that
 * follow to compare against.
 * @param script Opcode bytes:
 *   - [1-2] = state flag id
 */
int vs_battle_script_46_switchOnFlag(u_char* script, UNUSED short arg1)
{
    switchValue = getStateFlag(getShort(script + 1));

    return scriptNext;
}

/**
 * A case of a switch: jumps forward if the value stored by switchOnFlag matches.
 * @param script Opcode bytes:
 *   - [1] = value to compare
 *   - [2-3] = target offset from this opcode
 */
int vs_battle_script_47_jumpFwdCase(u_char* script, UNUSED short arg1)
{
    if (switchValue == script[1]) {
        return (long)&script[getShort(script + 2)];
    }

    return scriptNext;
}

/**
 * Ends sceneResetScript.
 */
int vs_battle_script_48_endSceneReset(UNUSED u_char* script, UNUSED short arg1)
{
    return scriptReturnAddress;
}

/**
 * Sets a loop counter. Using 0xFF as the counter is a marker for
 * the start of an infinite loop.
 * @param script Opcode bytes:
 *   - [1] = counter index (0-15), 0xFF = none
 *   - [2] = number of times to loop
 */
int vs_battle_script_49_setLoopCounter(u_char* script, UNUSED short arg1)
{
    if (script[1] != 0xFF) {
        loopCounters[script[1]] = script[2];
    }

    return scriptNext;
}

/**
 * Checks a loop condition and jumps back accordingly.
 * @param script Opcode bytes:
 *   - [1] = counter index (0-15), 0xFF = unconditional jump back (i.e. infinite loop)
 *   - [2-3] = target offset before this opcode
 */
int vs_battle_script_4A_loopCondition(u_char* script, UNUSED short arg1)
{
    if (script[1] == 0xFF) {
        return (long)&script[-getShort(script + 2)];
    }

    if (--loopCounters[script[1]] != 0) {
        return (long)&script[-getShort(script + 2)];
    }

    return scriptNext;
}

/**
 * Not used by any event script.
 * @param script Opcode bytes:
 *   - [1-2] = target offset from this opcode
 */
int vs_battle_script_4C_jumpFwdUnused(u_char* script, UNUSED short arg1)
{
    return (long)&script[getShort(script + 1)];
}

/**
 * Breaks out of a loop, jumping past the loopCondition that closes the loop.
 * @param script Opcode bytes:
 *   - [1-2] = target offset from this opcode
 */
int vs_battle_script_4B_break(u_char* script, UNUSED short arg1)
{
    return (long)&script[getShort(script + 1)];
}

/**
 * Modifies a state flag using an immediate value: the flag is replaced by the result of
 * `flag <operation> value`.
 * @param script Opcode bytes:
 *   - [1] = operation in the high nibble (flagOperation*, up to Assign), bits 6-9 of the
 *     flag id in the low nibble
 *   - [2] = bits 0-5 of the flag id in bits 2-7
 *   - [3] = value
 */
int vs_battle_script_50_modifyFlagImm(u_char* script, UNUSED short arg1)
{
    int operationAndFlag = script[1];
    short value = script[3];
    int flag = (script[2] >> 2) + ((operationAndFlag & 0xF) << 6);

    switch (operationAndFlag & 0xF0) {
    case flagOperationAdd:
        vs_battle_setStateFlag(flag, getStateFlag(flag) + value);
        break;

    case flagOperationSubtract:
        vs_battle_setStateFlag(flag, getStateFlag(flag) - value);
        break;

    case flagOperationMultiply:
        vs_battle_setStateFlag(flag, getStateFlag(flag) * value);
        break;

    case flagOperationDivide:
        vs_battle_setStateFlag(flag, getStateFlag(flag) / value);
        break;

    case flagOperationModulo:
        vs_battle_setStateFlag(flag, getStateFlag(flag) % value);
        break;

    case flagOperationAnd:
        vs_battle_setStateFlag(flag, getStateFlag(flag) & value);
        break;

    case flagOperationOr:
        vs_battle_setStateFlag(flag, getStateFlag(flag) | value);
        break;

    case flagOperationAssign:
        vs_battle_setStateFlag(flag, value);
        break;
    }

    return scriptNext;
}

/**
 * Like modifyFlagImm, but the value is another state flag, and there are two more
 * operations: absolute difference and swap.
 * @param script Opcode bytes:
 *   - [1] = operation in the high nibble (flagOperation*), bits 6-9 of the first flag id
 *     in the low nibble
 *   - [2] = bits 0-5 of the first flag id in bits 2-7, bits 8-9 of the second flag id in
 *     bits 0-1
 *   - [3] = bits 0-7 of the second flag id
 */
int vs_battle_script_51_modifyFlag(u_char* script, UNUSED short arg1)
{
    int tmp;
    char prev;

    int flag0 = (script[2] >> 2) + ((script[1] & 0xF) << 6);
    int flag1 = script[3] + ((script[2] & 3) << 8);

    switch (script[1] & 0xF0) {
    case flagOperationAdd:
        vs_battle_setStateFlag(flag0, getStateFlag(flag0) + getStateFlag(flag1));
        break;

    case flagOperationSubtract:
        vs_battle_setStateFlag(flag0, getStateFlag(flag0) - getStateFlag(flag1));
        break;

    case flagOperationMultiply:
        vs_battle_setStateFlag(flag0, getStateFlag(flag0) * getStateFlag(flag1));
        break;

    case flagOperationDivide:
        vs_battle_setStateFlag(flag0, getStateFlag(flag0) / getStateFlag(flag1));
        break;

    case flagOperationModulo:
        vs_battle_setStateFlag(flag0, getStateFlag(flag0) % getStateFlag(flag1));
        break;

    case flagOperationAnd:
        vs_battle_setStateFlag(flag0, getStateFlag(flag0) & getStateFlag(flag1));
        break;

    case flagOperationOr:
        vs_battle_setStateFlag(flag0, getStateFlag(flag0) | getStateFlag(flag1));
        break;

    case flagOperationAssign:
        vs_battle_setStateFlag(flag0, getStateFlag(flag1));
        break;

    case flagOperationAbsDifference:
        tmp = getStateFlag(flag0) - getStateFlag(flag1);
        vs_battle_setStateFlag(flag0, abs(tmp));
        break;

    case flagOperationSwap:
        prev = getStateFlag(flag0);
        vs_battle_setStateFlag(flag0, getStateFlag(flag1));
        vs_battle_setStateFlag(flag1, prev);
        break;
    }

    return scriptNext;
}

/**
 * Gets the count of a given item.
 * @param script Opcode bytes:
 *   - [1-2] = item id
 *   - [3-4] = state flag id
 */
int vs_battle_script_52_setFlagToItemCount(u_char* script, UNUSED short arg1)
{
    vs_battle_setStateFlag(
        getShort(script + 3), itemIdIsInInventory(getShort(script + 1)));

    return scriptNext;
}

/**
 * Forgets the saved state of the enemies of a zone and map, so they are in their initial
 * state the next time it is loaded (see despawnActor, which saves it).
 * @param script Opcode bytes:
 *   - [1] = zone id (ZND)
 *   - [2] = map id (MPD)
 */
int vs_battle_script_53_forgetZoneEnemies(u_char* script, UNUSED short arg1)
{
    vs_battle_forgetZoneEnemies(script[2], script[1]);

    return scriptNext;
}

/**
 * Plays the sound of an actor drawing or sheathing its weapon, without changing its
 * weapon state.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = 0 = draw, 1 = sheathe
 */
int vs_battle_script_54_playWeaponSfx(u_char* script, UNUSED short arg1)
{
    playWeaponSfx(resolveActorId(getShort(script + 1)), script[3]);

    return scriptNext;
}

int vs_battle_script_55(u_char* arg0, UNUSED short arg1)
{
    func_8007D15C(arg0[1]);
    return scriptNext;
}

int vs_battle_script_56_setFlagIfButton(u_char* arg0, UNUSED short arg1)
{
    short temp_v0 = getShort(arg0 + 1);
    vs_battle_setStateFlag(temp_v0 & 0x3FF, temp_v0 & 0x8000
                                                ? vs_main_buttonsPressed.pad[0].low
                                                : vs_main_buttonsPreviousState);
    return scriptNext;
}

int vs_battle_script_57(u_char* arg0, UNUSED short arg1)
{
    func_8007C28C(resolveActorId(getShort(arg0 + 1)));
    return scriptNext;
}

int vs_battle_script_58(u_char* arg0, UNUSED short arg1)
{
    func_8007BD8C(arg0[1] ^ 1);
    return scriptNext;
}

int vs_battle_script_59(u_char* script, UNUSED short arg1)
{
    switch (script[1]) {
    case 10:
    case 11:
    case 12:
        if (D_800F4BF8 == 0) {
            vs_battle_setStateFlag(0xB6, D_800E9BF0[script[1] - 10]);
            func_8007B9A0();
            D_800F4BF8 = 1;
            return scriptRepeat;
        }

        goto finishState;

    case 14:
        if (D_800F4BF8 == 0) {
            if (getStateFlag(0xB6) == 1) {
                vs_battle_setStateFlag(0xB6, 2);
            }

            func_8007B9A0();
            D_800F4C69 = 2;
            D_800F4BF8 = 1;
            return scriptRepeat;
        }

    finishState:
        if (func_8007B9FC() != 0) {
            return scriptRepeat;
        }

        vs_battle_setStateFlag(0xB6, 0);
        D_800F4BF8 = 0;
        return scriptYield;

    case 13:
        if (D_800F4BF8 == 0) {
            vs_battle_setStateFlag(0xB6, 1);
            func_8007B9A0();
            D_800F4BF8 = 1;
            return scriptRepeat;
        }

        goto finishTransition;

    case 15:
        if (D_800F4BF8 == 0) {
            func_8007B9CC();
            D_800F4BF8 = 1;
            return scriptRepeat;
        }

    finishTransition:
        if (func_8007B9FC() == 0) {
            D_800F4BF8 = 0;
            return scriptYield;
        }

        return scriptRepeat;

    default:
        if (D_800F4BF8 == 0) {
            func_800CACD0(script[1], 2);
            D_800F4BF8 = 1;
            return scriptRepeat;
        }

        func_800C97BC();

        if (func_800CB66C()->unk0 == 2) {
            func_800CB114();
            D_800F4BF8 = 0;
            break;
        }

        return scriptRepeat;
    }

    return scriptYield;
}

int vs_battle_script_5A(u_char* arg0, UNUSED short arg1)
{
    if (arg0[1] != 0) {
        func_8007BBD8(D_800E9BF4[arg0[3]], D_800E9BF8[arg0[2]],
            (arg0[4] << 0x18) | (arg0[5] << 0x10) | (arg0[6] << 8));
    } else {
        func_8007BCCC();
    }
    return scriptNext;
}

int vs_battle_script_5B_setTextBoxSpeaker(u_char* arg0, UNUSED short arg1)
{
    vs_TextBox* temp_s1;
    u_short temp_s0;
    int var_a0;

    temp_s0 = getShort(arg0 + 2);
    temp_s1 = vs_battle_getTextBox(arg0[1] & 0xF);

    if (temp_s0 < 0x2000) {
        var_a0 = resolveActorId(temp_s0);
    } else {
        var_a0 = 0x20;
    }
    temp_s1->unk0.speakerActor = var_a0;
    temp_s1->speakerAnimation = arg0[1] >> 4;
    return scriptNext;
}

int vs_battle_script_5C(u_char* arg0, UNUSED short arg1)
{
    u_short temp_a0 = resolveActorId(getShort(arg0 + 1));

    if (arg0[3] == 0xFE) {
        func_8007CAA4(temp_a0);
    } else {
        func_8007CA20(temp_a0, arg0[3], arg0[5]);
    }
    return scriptNext;
}

int vs_battle_script_5D(u_char* arg0, UNUSED short arg1)
{
    func_8009D7E8(resolveActorId(getShort(arg0 + 1)), arg0[3]);
    return scriptNext;
}

int vs_battle_script_5E(u_char* arg0, short arg1)
{
    if (D_800F4C58[arg1] == 0) {
        D_800F4C58[arg1] = arg0[2];
        return scriptRepeat;
    }
    if ((vs_main_buttonsPressed.all & arg0[1]) || (--D_800F4C58[arg1] <= 0)) {
        D_800F4C58[arg1] = 0;
        vs_main_buttonsPressed.all = 0;
        return scriptNext;
    }
    return scriptRepeat;
}

int vs_battle_script_5F(u_char* arg0, UNUSED short arg1)
{
    int var_v1;
    u_char* temp_a1;
    u_short* new_var;

    new_var = D_800F4B28;
    temp_a1 = (u_char*)((arg0[1] >> 6) + new_var);
    temp_a1[0] = ((arg0[1] >> 4) & 3);

    var_v1 = arg0[1] & 7;
    if (arg0[1] & 8) {
        var_v1 |= 0xF8;
    }
    temp_a1[1] = var_v1;
    return scriptNext;
}

int vs_battle_script_60(u_char* arg0, UNUSED short arg1)
{
    func_8008E224(arg0[1], arg0[2]);
    return scriptNext;
}

int vs_battle_script_61(u_char* arg0, UNUSED short arg1)
{
    short temp_v0 = getShort(arg0 + 1);
    D_800F4C6A = (temp_v0 << 0x10) >> 0x1F;
    if (D_800F4C6A) {
        func_80098194(temp_v0 & 0x7FF);
    }
    return scriptNext;
}

int vs_battle_script_62(u_char* arg0, UNUSED short arg1)
{
    D_800F19C8 = arg0[1];
    return scriptNext;
}

int vs_battle_script_63(UNUSED u_char* arg0, UNUSED short arg1)
{
    func_8007C31C();
    return scriptNext;
}

int vs_battle_script_64(u_char* arg0, UNUSED short arg1)
{
    func_80091998(arg0[1]);
    return scriptNext;
}

int vs_battle_script_65(u_char* arg0, UNUSED short arg1)
{
    func_800919D8(arg0[1]);
    return scriptNext;
}

int vs_battle_script_66(u_char* arg0, UNUSED short arg1)
{
    func_80091A1C(arg0[1], arg0[2]);
    return scriptNext;
}

int vs_battle_script_67(u_char* arg0, UNUSED short arg1)
{
    func_8008B808(arg0[1], arg0[3], arg0[2], arg0[4]);
    return scriptNext;
}

int vs_battle_script_68(u_char* arg0, UNUSED short arg1)
{
    vs_Warp sp10;

    if (D_800F4BE2 == 0) {

        sp10.zndId = arg0[1];
        sp10.mpdId = arg0[2];
        sp10.x = arg0[3];
        sp10.z = arg0[5];
        sp10.targetTile.arrivalSurface = arg0[4];
        sp10.facing = arg0[6];
        sp10.walkForward = arg0[7];
        sp10.faceCamera = arg0[7] >> 1;

        if (arg0[1] == 0) {
            func_8007C580(&sp10, arg0[8], arg0[9]);
        } else {
            func_8007BE10((arg0[7] >> 3) & 1);
            func_8007C654(&sp10, arg0[8], arg0[9]);
        }
        D_800F4BE2 = arg0[7] & 4 ? 1 : 3;
    }

    if (D_800F4BE2 == 2) {
        D_800F4BE2 = 0;
        return scriptNext;
    }
    return scriptRepeat;
}

int vs_battle_script_69(u_char* arg0, UNUSED short arg1)
{
    int temp_v0 = func_8007C398();
    if (temp_v0 != 5) {
        if (temp_v0 == 0) {
            func_8007C46C(arg0[1], arg0[2], arg0[3] * 0x10);
        }
        return scriptRepeat;
    }
    return scriptNext;
}

int vs_battle_script_6A(u_char* arg0, UNUSED short arg1)
{
    func_8007C4AC(arg0[1], arg0[2], arg0[3] * 0x10);
    return scriptNext;
}

int vs_battle_script_6B(u_char* arg0, UNUSED short arg1)
{
    setScreenTransitionWipeAngle(arg0[1] * 0x10);
    return scriptNext;
}

int vs_battle_script_6C(u_char* arg0, UNUSED short arg1)
{
    setScreenTransition(arg0[1], arg0[2], arg0[3] * 0x10);
    return scriptNext;
}

int vs_battle_script_6D(u_char* arg0, UNUSED short arg1)
{
    switch (arg0[1] & 3) {
    case 0:
        vs_battle_disableDispMask();
        break;
    case 1:
        vs_battle_enableDispMask();
        break;
    }

    switch ((arg0[1] >> 2) & 3) {
    case 0:
        func_8007BF4C();
        break;
    case 1:
        func_8007BF2C();
        break;
    }

    switch ((arg0[1] >> 4) & 3) {
    case 0:
        func_8007C050();
        break;
    case 1:
        func_8007BFC0();
        break;
    }
    return scriptNext;
}

int vs_battle_script_6E(UNUSED u_char* arg0, UNUSED short arg1)
{
    return func_8007C398() != 0 ? scriptRepeat : scriptNext;
}

int vs_battle_script_6F(u_char* arg0, UNUSED short arg1)
{
    if (arg0[1] != 0) {
        func_8007B104();
    } else {
        func_8007B0FC();
    }
    return scriptNext;
}

int vs_battle_script_70(u_char* arg0, UNUSED short arg1)
{
    ActorList sp18;
    int temp_a2;

    switch (arg0[1] >> 4) {
    case 0:
        expandActorSelector(getShort(arg0 + 2), &sp18);
        while (1) {
            temp_a2 = nextActor(&sp18);
            if (temp_a2 == 1) {
                break;
            }
            func_8007B29C(arg0[1] & 0xF, (1 << arg0[4]) & 0x1F, temp_a2,
                (signed char)arg0[5], (signed char)arg0[6], (signed char)arg0[7]);
        }
        break;
    case 1:
        func_8007B1B8(arg0[1] & 0xF, (1 << arg0[4]) & 0x1F, (signed char)arg0[5],
            (signed char)arg0[6], (signed char)arg0[7]);
        break;
    case 2:
        func_8007B344(arg0[1] & 0xF, (1 << arg0[4]) & 0x1F, (signed char)arg0[5],
            (signed char)arg0[6], (signed char)arg0[7]);
        break;
    }
    return scriptNext;
}

int vs_battle_script_71(u_char* arg0, UNUSED short arg1)
{
    func_800AC37C(resolveActorId(getShort(arg0 + 1)), arg0[3]);
    return scriptNext;
}

int vs_battle_script_72(u_char* arg0, UNUSED short arg1)
{
    u_int flags;
    int mask;
    int t;
    int u;
    int c;
    int ret;

    if (D_800F4C4E == 0) {
        if (!getStateFlag(0xAC)) {
            return scriptNext;
        }

        setWeaponDrawn(0, weaponDrawnModes[arg0[1]]);

        if (scriptSkipMode == scriptSkipping || arg0[2] == 0) {
        block_5:
            flags = vs_battle_getActorFlags(0);
            c = arg0[1];
            mask = flags;

            if (c != 0) {
                mask = 0x1800;
                mask = (flags | mask) & 0xFFFF;
            } else {
                mask &= 0xE7FF;
            }

            vs_battle_setActorFlags(0, mask);

            func_8009D88C(0);
            return scriptNext;
        }

        t = arg0[2] - 1;
        t *= 2;
        u = (arg0[1] ^ 1) + 0x6D;
        vs_battle_setActorAnimation(0, t + u, 0, 0xA);
        playWeaponSfx(0, arg0[1] ^ 1);
        ret = 1;
        D_800F4C4E = ret;
    } else {
        if (scriptSkipMode == scriptSkipping) {
            D_800F4C4E = 0;
            goto block_5;
        }

        if (vs_battle_getActorFlags(0) & 0x80) {
            vs_battle_setActorAnimation(0, arg0[1] != 0 ? 0x65 : 6, 0, 0xA);
            D_800F4C4E = 0;
            return scriptNext;
        }
    }

    return scriptRepeat;
}

int vs_battle_script_73(u_char* arg0, UNUSED short arg1)
{
    func_8008EAF8(arg0[1]);
    return scriptNext;
}

int vs_battle_script_74(u_char* arg0, UNUSED short arg1)
{
    func_8008EFCC(arg0[1]);
    return scriptNext;
}

int vs_battle_script_75(UNUSED u_char* arg0, UNUSED short arg1)
{
    return func_8008F0FC() == 0 ? scriptRepeat : scriptNext;
}

int vs_battle_script_76(UNUSED u_char* arg0, UNUSED short arg1)
{
    func_8008F234();
    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

int vs_battle_script_77(u_char* arg0, UNUSED short arg1)
{
    func_80090C2C(arg0[1] >> 4);
    if (arg0[4] == 0) {
        D_800F4B88.unk10 = arg0[1] & 0xF;
        func_80091320(D_800F4B88.unk10);
        D_800F4B88.unk4 = arg0[2] * 16;
        D_800F4B88.unkA = arg0[3] * 4 + ONE / 8;
        func_8009134C(D_800F4B88.unk4, D_800F4B88.unkA);
    } else {
        int v = arg0[1] & 0xF;
        short base;
        int delta;

        D_800F4B88.unk12 = D_800F4B88.unk10;
        D_800F4B88.unk14 = v - D_800F4B88.unk10;
        D_800F4B88.unkE =
            arg0[3] * 4 - (base = (D_800F4B88.unkC = D_800F4B88.unkA) - ONE / 8);
        delta = arg0[2] * 16 - (D_800F4B88.unk6 = D_800F4B88.unk4);
        if (delta < -ONE / 2) {
            delta += ONE;
        } else if (delta > ONE / 2) {
            delta -= ONE;
        }
        D_800F4B88.unk8 = delta;
        D_800F4B88.unk3 = arg0[4];
        D_800F4B88.unk2 = 0;
    }
    return scriptNext;
}

int vs_battle_script_78(u_char* arg0, UNUSED short arg1)
{
    func_80091314(arg0[1] ^ 1);
    return scriptNext;
}

int vs_battle_script_7A(u_char* arg0, UNUSED short arg1)
{
    if (arg0[1] != 0) {
        if (D_800F4C08 != 0) {
            return scriptNext;
        }

        D_800F4C08 = func_8008E470();

        if (D_800F4C08) {
            D_800F4C4C = func_800913BC(-1);
        }

    } else if (D_800F4C08 != 0) {
        func_800913BC(D_800F4C4C);
        D_800F4C08 = 0;
    }

    return scriptNext;
}

int vs_battle_script_79(u_char* arg0, UNUSED short arg1)
{
    int temp_s0 = arg0[2];

    switch (arg0[1]) {
    case 0:
        if ((scriptSkipMode == scriptSkipping) && (func_80093764(temp_s0) != 0)) {
            func_80093788(temp_s0);
        }
        func_8009291C(temp_s0);
        break;
    case 1:
        func_800936F8(temp_s0);
        break;
    }
    return scriptNext;
}

int vs_battle_script_7B(u_char* arg0, UNUSED short arg1)
{
    func_80091468(getShort(arg0 + 1), getShort(arg0 + 3));
    return scriptNext;
}

int vs_battle_script_7C(u_char* arg0, UNUSED short arg1)
{
    func_8007BDD8(arg0[1] != 0);
    return scriptNext;
}

int vs_battle_script_7D(u_char* arg0, UNUSED short arg1)
{
    func_80091A78(arg0[1], (signed char)arg0[2]);
    return scriptNext;
}

int vs_battle_script_7E(u_char* arg0, UNUSED short arg1)
{
    func_8008EAE4((signed char)arg0[1] << 7, (signed char)arg0[2] << 7);
    return scriptNext;
}

int vs_battle_script_80_playSfx(u_char* arg0, UNUSED short arg1)
{
    if (arg0[1] == 2 && D_800F4C08 == 0) {
        return scriptNext;
    }
    if (arg0[1] == 2) {
        D_800F4C4C = arg0[2];
    }
    vs_main_playSfx(D_800E9B34[arg0[1]], arg0[2], arg0[3], arg0[4]);
    return scriptNext;
}

int vs_battle_script_81(u_char* arg0, UNUSED short arg1)
{
    func_8007C8A4(resolveActorId(getShort(arg0 + 1)), arg0[3]);
    return scriptNext;
}

int vs_battle_script_82_fadeSfxVolume(u_char* arg0, UNUSED short arg1)
{
    vs_main_fadeSfxVolume(D_800E9B34[arg0[1]], arg0[2], arg0[3], arg0[4]);
    return scriptNext;
}

int vs_battle_script_83_stopAllSfx(UNUSED u_char* arg0, UNUSED short arg1)
{
    vs_main_stopAllSfx();
    return scriptNext;
}

int vs_battle_script_84_evictSfx(u_char* arg0, UNUSED short arg1)
{
    vs_main_evictSfx(D_800E9B34[arg0[1]], arg0[2]);
    return scriptNext;
}

int vs_battle_script_85_loadSfxSlot(u_char* arg0, UNUSED short arg1)
{
    vs_main_loadSfxSlot(arg0[1], arg0[2]);
    return scriptNext;
}

int vs_battle_script_86_freeSfxSlot(u_char* arg0, UNUSED short arg1)
{
    return vs_main_freeSfxQueueSlot(arg0[1]) != 0 ? scriptRepeat : scriptNext;
}

int vs_battle_script_87_freeSfx(u_char* arg0, UNUSED short arg1)
{
    vs_main_freeSfx(arg0[1]);
    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

int vs_battle_script_88_setCurrentSfx(u_char* arg0, UNUSED short arg1)
{
    vs_main_setCurrentSfx(arg0[1]);
    return scriptNext;
}

int vs_battle_script_89_loadSoundFile(UNUSED u_char* arg0, UNUSED short arg1)
{
    short temp_v0 = func_80089104();
    vs_main_loadMusicSlot(temp_v0, 3);
    vs_main_loadSoundFile(temp_v0);
    return scriptNext;
}

int vs_battle_script_8F_crossfadeMusic(u_char* arg0, UNUSED short arg1)
{
    vs_main_fadeMusicVolume(D_800F4C69, 0, arg0[4]);
    vs_main_playMusicSlotFadeIn(D_800F4C69 = arg0[1], arg0[2], arg0[3]);
    return scriptNext;
}

int vs_battle_script_90_loadMusicSlot(u_char* arg0, UNUSED short arg1)
{
    vs_main_loadMusicSlot(arg0[1], arg0[2]);
    return scriptNext;
}

int vs_battle_script_91_freeMusic(u_char* arg0, UNUSED short arg1)
{
    vs_main_freeMusic(arg0[1]);
    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

int vs_battle_script_92_playMusic(u_char* arg0, UNUSED short arg1)
{
    vs_main_playMusicSlot(D_800F4C69 = arg0[1], arg0[2], arg0[3]);
    return scriptNext;
}

int vs_battle_script_93_fadeMusicVolume(u_char* arg0, UNUSED short arg1)
{
    vs_main_fadeMusicVolume(D_800F4C69, arg0[1], arg0[2]);
    return scriptNext;
}

int vs_battle_script_94_fadeMusicTempo(u_char* arg0, UNUSED short arg1)
{
    vs_main_fadeMusicTempo(D_800F4C69, (signed char)arg0[1], arg0[2]);
    return scriptNext;
}

int vs_battle_script_95_fadeMusicPitch(u_char* arg0, UNUSED short arg1)
{
    vs_main_fadeMusicPitch(D_800F4C69, (signed char)arg0[1], arg0[2]);
    return scriptNext;
}

int vs_battle_script_96_stopMusic(UNUSED u_char* arg0, UNUSED short arg1)
{
    vs_main_stopMusicSlot(D_800F4C69);
    return scriptNext;
}

int vs_battle_script_97_waitMusicSilent(u_char* arg0, UNUSED short arg1)
{
    int temp_s0 = arg0[1];
    if (vs_main_getMusicSlotVolume2(temp_s0) != 0) {
        if (vs_main_getMusicSlotVolume(temp_s0) != 0) {
            return scriptRepeat;
        }
        vs_main_stopMusicSlot(temp_s0);
    }
    return scriptNext;
}

int vs_battle_script_98_pushMusicState(UNUSED u_char* arg0, UNUSED short arg1)
{
    vs_main_pushMusicState();
    return scriptNext;
}

int vs_battle_script_99_clearMusicLoadSlot(u_char* arg0, UNUSED short arg1)
{
    return vs_main_clearMusicLoadSlot(arg0[1]) == 1 ? scriptRepeat : scriptNext;
}

int vs_battle_script_9D_loadSoundFile2(u_char* arg0, UNUSED short arg1)
{
    vs_main_loadSoundFile(arg0[1]);
    return scriptNext;
}

int vs_battle_script_9E_processSoundQueue(UNUSED u_char* arg0, UNUSED short arg1)
{
    return vs_main_processSoundQueue() == 1 ? scriptRepeat : scriptNext;
}

int vs_battle_script_9A_waitMusicBar(u_char* arg0, UNUSED short arg1)
{
    int temp_s1 = vs_main_getMusicPosition() >> 0x10;
    return temp_s1 < getShort(arg0 + 1) ? scriptRepeat : scriptNext;
}

int vs_battle_script_9B_fadeSfxPitch(u_char* arg0, UNUSED short arg1)
{
    vs_main_fadeSfxPitch(D_800E9B34[arg0[1]], arg0[2], (signed char)arg0[3], arg0[4]);
    return scriptNext;
}

int vs_battle_script_9C_fadeSfxPan(u_char* arg0, UNUSED short arg1)
{
    vs_main_fadeSfxPan(D_800E9B34[arg0[1]], arg0[2], arg0[3], arg0[4]);
    return scriptNext;
}

int vs_battle_script_9F_queueMusic(u_char* arg0, UNUSED short arg1)
{
    vs_main_queueMusicSlot(D_800F4C69 = arg0[1]);
    return scriptNext;
}

int vs_battle_script_A0(u_char* arg0, UNUSED short arg1)
{
    func_8007BE20(getShort(arg0 + 1), resolveActorId(getShort(arg0 + 3)));
    return scriptNext;
}

int vs_battle_script_A1(u_char* arg0, UNUSED short arg1)
{
    func_8007BEC4(arg0[1]);
    if (scriptSkipMode == scriptSkipping) {
        func_800CF1A8();
    }
    return scriptNext;
}

int vs_battle_script_A2(u_char* arg0, UNUSED short arg1)
{
    if ((scriptSkipMode == scriptSkipping) && ((arg0[1] == 0) || (arg0[1] == 5))) {
        if (D_800F4BB9 != 0) {
            if (func_8007BEE4() == arg0[1]) {
                D_800F4BB9 = 0;
                return scriptNext;
            }
        } else {
            func_800CF1A8();
            D_800F4BB9 = 1;
        }
        return scriptRepeat;
    }
    return func_8007BEE4() != arg0[1] ? scriptRepeat : scriptNext;
}

int vs_battle_script_A3(UNUSED u_char* arg0, UNUSED short arg1)
{
    func_8007BF04();
    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

int vs_battle_script_A4(UNUSED u_char* arg0, UNUSED short arg1)
{
    return func_8007BF0C() != 1 ? scriptRepeat : scriptNext;
}

int vs_battle_script_A5(UNUSED u_char* arg0, UNUSED short arg1)
{
    if (D_800F4BB9 == 0) {
        func_800CF1A8();
        D_800F4BB9 = 1;
    } else if ((func_8007BEE4() == 0) || (func_8007BEE4() == 5)) {
        D_800F4BB9 = 0;
        return scriptNext;
    }
    return scriptRepeat;
}

int vs_battle_script_A6(u_char* arg0, UNUSED short arg1)
{
    func_800CEF38(arg0[1]);
    return scriptNext;
}

int vs_battle_script_A8_setMusicJumpThreshold(u_char* arg0, UNUSED short arg1)
{
    vs_main_setMusicJumpThreshold(arg0[1]);
    return scriptNext;
}

int vs_battle_script_A9(u_char* arg0, UNUSED short arg1)
{
    short a0 = arg0[1];
    if (a0 == 0xFF) {
        vs_main_stopVibration(0, 2);
    } else {
        if (a0 & 8) {
            vs_main_memcpy(D_800F4C48, D_800F4BC0[a0 & 7], 0x80);
            vs_main_setVibrationBank(D_800F4C48 + 8, 0xFF, 2);
        } else {
            if (D_800F4BC0[a0] != 0) {
                vs_main_setVibrationBank(D_800F4BC0[a0] + 8, 0xFF, 2);
            }
        }
    }
    return scriptNext;
}

int vs_battle_script_AA(u_char* arg0, UNUSED short arg1)
{
    short temp_v0 = resolveActorId(getShort(arg0 + 2));

    if (arg0[1] != 0) {
        func_8006C480(temp_v0, arg0[4]);
    } else {
        func_8006C4A4(temp_v0, arg0[4]);
    }
    return scriptNext;
}

int vs_battle_script_B1(u_char* arg0, UNUSED short arg1)
{
    setDoorEntered2(arg0[1]);
    return scriptNext;
}

int vs_battle_script_B2(u_char* arg0, UNUSED short arg1)
{
    vs_ActorPosition sp10;
    vs_ActorPosition sp20;
    short temp_s3;
    short temp_v0;
    short temp_v0_2;
    int temp_lo;

    temp_s3 = getShort(arg0 + 6);
    vs_battle_getActorPosition(resolveActorId(getShort(arg0 + 1)), &sp10);
    vs_battle_getActorPosition(resolveActorId(getShort(arg0 + 3)), &sp20);
    temp_v0 = sp10.unk0.unk4.vx - sp20.unk0.unk4.vx;
    temp_v0_2 = sp10.unk0.unk4.vz - sp20.unk0.unk4.vz;
    temp_lo = vs_gte_rsqrt((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) / arg0[5];
    vs_battle_setStateFlag(temp_s3, temp_lo < 0x100 ? temp_lo & 0xFF : -1);
    vs_battle_setStateFlag(temp_s3 + 1, (ratan2(temp_v0, temp_v0_2) >> 4) & 0xFF);
    return scriptNext;
}

int vs_battle_script_B3(u_char* arg0, UNUSED short arg1)
{
    ActorList sp10;

    expandActorSelector(getShort(arg0 + 1), &sp10);
    while (1) {
        int temp_a0 = nextActor(&sp10);
        if (temp_a0 == 1) {
            break;
        }
        func_8007D08C(temp_a0, arg0[3]);
    }
    return scriptNext;
}

int vs_battle_script_B4(u_char* arg0, UNUSED short arg1)
{
    if (D_800F4BF8 == 0) {
        func_8007BA98(getShort(arg0 + 1), arg0[3], getShort(arg0 + 4), arg0[6]);
        D_800F4BF8 = 1;
        return scriptRepeat;
    }

    if (func_8007B9FC() == 0) {
        D_800F4BF8 = 0;
        return scriptYield;
    }
    return scriptRepeat;
}

int vs_battle_script_B5(u_char* arg0, UNUSED short arg1)
{
    decreaseMiscCount(getShort(arg0 + 1));
    return scriptNext;
}

int vs_battle_script_B6(u_char* arg0, UNUSED short arg1)
{
    vs_ActorPosition sp10;
    vs_ActorPosition sp20;
    short temp_s0;
    int temp_s0_2;
    short temp_s1;
    int var_v0;

    vs_battle_getActorPosition(resolveActorId(getShort(arg0 + 1)), &sp10);
    vs_battle_getActorPosition(resolveActorId(getShort(arg0 + 3)), &sp20);
    temp_s0 = sp10.unk0.unk4.vx - sp20.unk0.unk4.vx;
    temp_s1 = sp10.unk0.unk4.vz - sp20.unk0.unk4.vz;
    temp_s0_2 = getShort(arg0 + 5);
    var_v0 = vs_gte_rsqrt((temp_s0 * temp_s0) + (temp_s1 * temp_s1));
    if (var_v0 < 0) {
        var_v0 += 0x7F;
    }
    vs_battle_setStateFlag(temp_s0_2, (var_v0 >> 7) & 0xFF);
    return scriptNext;
}

void func_800BAF6C(short arg0)
{
    short actorId;

    for (actorId = 1; actorId < 17; ++actorId) {
        if (getActor(actorId) != NULL) {
            if (arg0 != 0) {
                vs_battle_setActorFlags(actorId, vs_battle_getActorFlags(actorId) | 1);
            } else {
                vs_battle_setActorFlags(actorId, vs_battle_getActorFlags(actorId) & ~1);
            }
        }
    }

    func_8007D15C(arg0);
}

int vs_battle_script_B7_specialOp(u_char* arg0, UNUSED short arg1)
{
    char sp10[32];

    switch (arg0[1]) {
    case 0:
        func_8007C8F8(arg0[2]);
        break;
    case 1:
        if (D_800F4BF8 != 0) {
            if (func_8007B9FC() != 0) {
                return scriptRepeat;
            }
            vs_battle_setStateFlag(0xB6, 0);
            D_800F4BF8 = 0;
            vs_main_showEndingAndReturnToTitle();
            break;
        }
        vs_battle_setStateFlag(0xB6, 3);
        func_8007B9A0();
        D_800F4BF8 = 1;
        return scriptRepeat;
    case 2:
        skipRequested = 1;
        break;
    case 3:
        if (isActionUnlocked(arg0[2]) != 0) {
            vs_battle_setStateFlag(0xB1, 0);
        } else {
            setActionUnlocked(arg0[2]);
            vs_battle_setStateFlag(0xB1, 1);
        }
        break;
    case 4:
        vs_battle_setStateFlag(0xB1, func_8007CF80(4));
        break;
    case 5:
        func_800BAF6C(arg0[2]);
        break;
    case 6:
        vs_main_freeHeapR(D_800F4C24);
        break;
    case 7:
        func_800BBE04(arg0[2]);
        break;
    case 8:
        func_8007BD3C(arg0[2]);
        break;
    case 9:
        func_800BE3D0(arg0[2]);
        break;
    case 10:
        func_8007CE74(D_800E9C00[arg0[2]]);
        break;
    case 11:
        func_800BE5A4(arg0[2]);
        break;
    case 12:
        func_8008D5A0(arg0[2]);
        break;
    case 13:
        func_8008C40C();
        break;
    case 14:
        func_8008D594(arg0[2]);
        break;
    case 15:
        func_800F9DE8(arg0[2]);
        break;
    case 16:
        scriptReturnAddress = (long)(arg0 + 6);
        return (long)&sceneResetScript;
    case 17:
        func_8007C4D4();
        break;
    default:
        sprintf(sp10, "<SPECIAL=%d> IS UNDEFINED!", arg0[1]);
        break;
    }
    return scriptNext;
}

int vs_battle_script_B8(UNUSED u_char* arg0, UNUSED short arg1)
{
    if ((D_800EB9B4 != NULL) && (D_800EB9B4->unk0 != 0)) {
        return scriptRepeat;
    }
    return scriptNext;
}

int vs_battle_script_BB(u_char* arg0, UNUSED short arg1)
{
    func_800F9800(getShort(arg0 + 1));
    return scriptNext;
}

int vs_battle_script_BC(UNUSED u_char* arg0, UNUSED short arg1)
{
    func_800CB79C();
    return scriptNext;
}

int vs_battle_script_BD(UNUSED u_char* arg0, UNUSED short arg1) { return scriptNext; }

int vs_battle_script_BE(UNUSED u_char* arg0, UNUSED short arg1)
{
    func_800CB7DC();
    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

int vs_battle_script_DE(UNUSED u_char* arg0, UNUSED short arg1)
{
    func_800BE3A0();
    return scriptNext;
}

int vs_battle_script_DF(u_char* arg0, UNUSED short arg1)
{
    int new_var = arg0[1] & 2;
    func_800BE36C(arg0[1] & 1, new_var != 0);
    return scriptNext;
}

int vs_battle_script_E8(u_char* arg0, UNUSED short arg1)
{
    func_800BBE10(resolveActorId(getShort(arg0 + 1)));
    return scriptNext;
}

int vs_battle_script_E9(u_char* arg0, UNUSED short arg1)
{
    func_800BC1CC(
        arg0[1] != 0xFF ? ((arg0[1] + 4) & 7) : -1, arg0[2] != 0 ? arg0[2] : -1);
    D_800F4BB6 = 1;
    return scriptNext;
}

int vs_battle_script_E0(u_char* arg0, UNUSED short arg1)
{
    return arg0[1] != (arg0[1] & func_800BD610()) ? scriptRepeat : scriptNext;
}

int vs_battle_script_E1(u_char* arg0, UNUSED short arg1)
{
    func_8007DD50(arg0[1]);
    return scriptNext;
}

int vs_battle_script_F0(u_char* arg0, short arg1)
{
    if (D_800F4C58[arg1] == 0) {
        D_800F4C58[arg1] = arg0[1];
        return scriptRepeat;
    }

    --D_800F4C58[arg1];

    if ((D_800F4C58[arg1] << 0x10) <= 0) {
        D_800F4C58[arg1] = 0;
        return scriptNext;
    }
    return scriptRepeat;
}

int vs_battle_script_F1(u_char* arg0, UNUSED short arg1)
{
    func_8007C36C(arg0[1]);
    return scriptNext;
}

int vs_battle_script_F3(u_char* arg0, UNUSED short arg1)
{
    D_800F4BE4 = arg0[1];
    return scriptNext;
}

int vs_battle_script_F4(u_char* arg0, UNUSED short arg1)
{
    u_short temp_a0 = arg0[1] & 3;
    if ((arg0[1] & 0x80)) {
        D_800F4C38[temp_a0] = 0;
        return scriptNext;
    }
    return D_800F4C38[temp_a0] != 0 ? scriptRepeat : scriptNext;
}

int vs_battle_script_F5(u_char* arg0, UNUSED short arg1)
{
    D_800F4C38[arg0[1]] = arg0 + 4;
    return (int)&arg0[getShort(arg0 + 2)];
}

int vs_battle_script_F6(UNUSED u_char* arg0, UNUSED short arg1) { return scriptEnd; }

int vs_battle_script_F7(u_char* arg0, UNUSED short arg1)
{
    evtFile = getShort(arg0 + 1);
    D_800F4C24 = vs_main_allocHeapR(0x1800);
    func_800C00E8(evtFile, D_800F4C24);
    D_800F4C54 = 1;
    return scriptNext;
}

int vs_battle_script_FE_FF(UNUSED u_char* arg0, UNUSED short arg1)
{
    int i;
    int var_s1;

    var_s1 = 0;

    for (i = 0; i < 8; ++i) {
        if (vs_battle_dismissTextBox(i) != 0) {
            ++var_s1;
        }
    }

    if (var_s1 == 0) {
        func_8007C36C(2);
        return 2;
    }
    return scriptRepeat;
}

int vs_battle_script_F2_playMenuSelectSfx(UNUSED u_char* arg0, UNUSED short arg1)
{
    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
    return scriptNext;
}

void expandActorSelector(u_short arg0, ActorList* arg1)
{
    Actor* temp_v0;
    short var_s3 = 0;
    arg1->remaining = 0;
    arg1->next = 0;

    if (arg0 & 0x2000) {
        short i;
        short var_a0 = -1;
        if (arg0 == 0x2003) {
            var_a0 = 4;
        }

        for (i = 0; i < 17; ++i) {
            temp_v0 = getActor(i);
            if (temp_v0 != NULL) {
                if ((var_a0 < 0) || (temp_v0->unk1C == var_a0)) {
                    arg1->actors[var_s3++] = i;
                    ++arg1->remaining;
                }
            }
        }

        return;
    }
    ++arg1->remaining;
    arg1->actors[0] = resolveActorId(arg0);
}

u_short nextActor(ActorList* arg0)
{
    if (arg0->remaining == 0) {
        return 1;
    }

    --arg0->remaining;
    return arg0->actors[(u_int)(arg0->next++)];
}

int getActorScreenPosition(int arg0, SVECTOR* arg1)
{
    MATRIX sp10;
    long sp30[5];

    arg1->vx = 0;
    arg1->vy = -0x3E8;
    arg1->vz = 0;
    func_800A1178(arg0, 1, &sp10, &sp30[2]);
    SetRotMatrix(&sp10);
    SetTransMatrix(&sp10);
    RotTransPers(arg1, sp30, &sp30[3], &sp30[4]);
    func_800A1280(arg0, 1, arg1, sp30[2]);
    arg1->vz = ratan2(((short*)&sp30)[1] - arg1->vy, (short)sp30[0] - arg1->vx);
    return arg1->vz;
}

void func_800BB874(void)
{
    LINE_F2* var_s3;
    short i;
    u_int temp_v0_2;

    void** p = (void**)0x1F800000;
    var_s3 = (LINE_F2*)p[0];

    ++D_800F4B20;

    for (i = 0; i < vs_main_screenHeight; ++i) {
        u_short v;
        temp_v0_2 = (((i + (D_800F4B20 >> 1)) & 1) << 5);
        v = temp_v0_2;
        if (temp_v0_2 != 0) {
            SetLineF2(var_s3);
            var_s3->r0 = var_s3->g0 = var_s3->b0 = v;
            setSemiTrans(var_s3, 1);
            var_s3->x0 = 0;
            var_s3->y0 = var_s3->y1 = i;
            var_s3->x1 = vs_main_screenWidth;
            p = (void**)0x1F800000;
            AddPrim(p[2], var_s3++);
        }
    }

    SetDrawTPage((DR_TPAGE*)var_s3, 1, 1, GetTPage(0, 2, 0, 0));

    p = (void**)0x1F800000;
    AddPrim(p[2], var_s3);
    p[0] = (LINE_F2*)&var_s3->x0;
}

void func_800BB9B0(void)
{
    short i;
    short temp_a0;
    GimTween* tween = gimTweens;
    Gim* gim = gims;

    for (i = 0; i < 3; ++i, ++tween, ++gim) {
        if (tween->duration != 0) {
            tween->elapsed += vs_gametime_tickspeed >> 1;
            temp_a0 = func_800BFEBC(tween->curve, tween->elapsed, tween->duration);
            if (gims != NULL) {
                gim->x = (tween->startX + ((tween->deltaX * temp_a0) >> 0xC));
                gim->y = (tween->startY + ((tween->deltaY * temp_a0) >> 0xC));
                gim->scale = (tween->startScale + ((tween->deltaScale * temp_a0) >> 0xC));
                gim->brightness =
                    tween->startBrightness + ((tween->deltaBrightness * temp_a0) >> 0xC);
            }
            if (tween->elapsed >= tween->duration) {
                tween->duration = 0;
            }
        }
    }
}

void func_800BBAFC(void)
{
    if (D_800F4B88.unk3 != 0) {
        short temp_lo = ((++D_800F4B88.unk2 << 0xC) / D_800F4B88.unk3);
        D_800F4B88.unk4 =
            (D_800F4B88.unk6 + ((D_800F4B88.unk8 * temp_lo) >> 0xC)) & 0xFFF;
        D_800F4B88.unkA = D_800F4B88.unkC + ((D_800F4B88.unkE * temp_lo) >> 0xC);
        D_800F4B88.unk10 = (D_800F4B88.unk12 + ((D_800F4B88.unk14 * temp_lo) >> 0xC));
        func_8009134C(D_800F4B88.unk4, D_800F4B88.unkA);
        func_80091320(D_800F4B88.unk10);
        if (D_800F4B88.unk2 == D_800F4B88.unk3) {
            D_800F4B88.unk3 = 0;
        }
    }
}

extern CVECTOR D_800E9C08;
extern VECTOR D_800E9C0C;

void func_800BBBE8(void)
{
    UNUSED VECTOR _;
    VECTOR sp20;
    VECTOR sp30;

    D_800F4BA4 = vs_main_allocHeapR(sizeof *D_800F4BA4);
    D_800F4BA0 = 0;

    getCameraPosition(&sp20);
    getCameraLookAt(&sp30);
    vectorCopy(&D_800F4BA4->eye.current, &sp20);
    vectorCopy(&D_800F4BA4->lookAt.target, &sp20);
    vectorCopy(&D_800F4BA4->lookAt.current, &sp30);
    vectorCopy(&D_800F4BA4->eye.target, &sp30);

    D_800F4BA4->lookAt.mode = 0xF;
    D_800F4BA4->lookAt.follow = D_800F4BA4->lookAt.following = 0;
    D_800F4BA4->eye.mode = 0xF;
    D_800F4BA4->eye.follow = D_800F4BA4->eye.following = 0;
    D_800F4BA4->unk168.unkA = 0;
    D_800F4BA4->unk168.unk2 = 0;
    D_800F4BA4->unk168.unk0 = 1;

    func_8007DD50(0);

    D_800F4BA4->unk174.unkA = 0;
    D_800F4BA4->unk174.unk2 = 0;

    func_8007DDAC(0);

    D_800F4BA4->unk174.unk0 = 1;
    D_800F4BA4->unk1FC.unk4 = ONE;
    D_800F4BA4->unk1FC.unk2 = ONE;

    func_8007DDB8(&D_800E9C0C);

    D_800F4BA4->unk21C.unk2 = D_800F4BA4->unk21C.unk4 = D_800F4BA4->unk21C.unk6 =
        D_800F4BA4->unk1FC.unk1E = 0;

    func_8007DDD4(&D_800E9C08);

    D_800F4BA4->unk21C.unk1E = 0;
    D_800F4BA4->unk23C.unk4 = ONE;
    D_800F4BA4->unk23C.unk2 = ONE;

    func_8007DDF8(&D_800E9C0C);

    D_800F4BA4->unk23C.unk1E = 0;

    func_8007DE2C(1);

    D_800F4BA4->unk25C.unk2 = ONE;
    D_800F4BA4->unk25C.unk1E = D_800F4BA4->unk25C.unk4 = 0;
    D_800F4BA4->projectionDistance.unk2 = 0x200;
    D_800F4BA4->projectionDistance.unk9 = 0;
    D_800F4BA4->projectionDistance.unk0 = 1;
    D_800F4BA4->nearClip.unk2 = 0x40;
    D_800F4BA4->nearClip.unk9 = 0;
    D_800F4BA4->nearClip.unk0 = 1;
    D_800F4BA4->farClip.unk2 = 0x1000;
    D_800F4BA4->farClip.unk9 = 0;
    D_800F4BA4->farClip.unk0 = 1;
    D_800F4BA4->unk1A4.unk0.s16 = 0;
    D_800F4BA4->unk1A4.unkB = D_800F4BA4->unk1B0.unkB = 0;
    D_800F4BA4->unk1E8 = 0x2000;
}

void func_800BBDDC(void) { vs_main_freeHeapR(D_800F4BA4); }

void func_800BBE04(int arg0) { D_800F4BA0 = arg0; }

void func_800BBE10(u_short arg0)
{
    int _[4];
    if (arg0 == 0x2000) {
        if (D_800F4BA4->unk1E8 != arg0) {
            vectorAdd(
                &D_800F4BA4->eye.current, &D_800F4BA4->eye.current, &D_800F4BA4->unk1EC);
            vectorAdd(&D_800F4BA4->lookAt.current, &D_800F4BA4->lookAt.current,
                &D_800F4BA4->unk1EC);
        }
    }
    D_800F4BA4->unk1E8 = arg0;
    func_800BBE94();
}

void func_800BBE94(void)
{
    vs_ActorPosition sp10;

    if (D_800F4BA4->unk1E8 == 0x2000) {
        D_800F4BA4->unk1EC.vz = 0;
        D_800F4BA4->unk1EC.vy = 0;
        D_800F4BA4->unk1EC.vx = 0;
        return;
    }
    vs_battle_getActorPosition(D_800F4BA4->unk1E8, &sp10);
    D_800F4BA4->unk1EC.vx = sp10.unk0.unk4.vx * ONE;
    D_800F4BA4->unk1EC.vy = sp10.unk0.unk4.vy * ONE;
    D_800F4BA4->unk1EC.vz = sp10.unk0.unk4.vz * ONE;
}

static void applyCameraState(void)
{
    VECTOR cameraLookAt;
    VECTOR cameraPos;
    SVECTOR* vec;

    if (D_800F4BA0 != 0) {
        initialiseCameraFromSpherical(&cameraPos, &cameraLookAt, -1, -1);
        vectorCopy(&D_800F4BA4->lookAt.current, &cameraLookAt);
        vectorCopy(&D_800F4BA4->eye.current, &cameraPos);
    } else {
        vectorCopy(&cameraLookAt, &D_800F4BA4->lookAt.current);
        vectorCopy(&cameraPos, &D_800F4BA4->eye.current);
        if (D_800F4BA4->unk1E8 != 0x2000) {
            vectorAdd(&cameraLookAt, &cameraLookAt, &D_800F4BA4->unk1EC);
            vectorAdd(&cameraPos, &cameraPos, &D_800F4BA4->unk1EC);
        }
    }
    if (*(short*)&D_800F4BA4->unk1A4.unk0 != 0) {
        sVectorToFixedPointVector((VECTOR*)0x1F800098, (SVECTOR*)&D_800F4BA4->unk1BE);
        sVectorToFixedPointVector((VECTOR*)0x1F8000A8, (SVECTOR*)&D_800F4BA4->unk1C6);
        vec = (SVECTOR*)0x1F800088;
        vec[10].vz = 0;
        vec[10].vx = 0;
        vec[10].vy = atan2FixedPoint(
            cameraLookAt.vx - cameraPos.vx, cameraLookAt.vz - cameraPos.vz);
        RotMatrix_gte((SVECTOR*)0x1F8000D8, (MATRIX*)0x1F8000F8);
        ApplyMatrixLV((MATRIX*)0x1F8000F8, (VECTOR*)0x1F800098, (VECTOR*)0x1F800098);
        ApplyMatrixLV((MATRIX*)0x1F8000F8, (VECTOR*)0x1F8000A8, (VECTOR*)0x1F8000A8);
        vectorAdd(&cameraLookAt, &cameraLookAt, (VECTOR*)0x1F800098);
        vectorAdd(&cameraPos, &cameraPos, (VECTOR*)0x1F8000A8);
    }
    setCameraLookAt(&cameraLookAt);
    setCameraPosition(&cameraPos);
    if (D_800F4BA4->unk168.unk0 != 0) {
        setCameraRoll(D_800F4BA4->unk168.unk2);
        D_800F4BA4->unk168.unk0 = 0;
    }
    if (D_800F4BA4->unk174.unk0 != 0) {
        func_8007DDAC(D_800F4BA4->unk174.unk2);
        D_800F4BA4->unk174.unk0 = 0;
    }
    if (D_800F4BA4->projectionDistance.unk0 != 0) {
        vs_battle_setProjectionDistance(D_800F4BA4->projectionDistance.unk2);
        D_800F4BA4->projectionDistance.unk0 = 0;
    }
    if (D_800F4BA4->nearClip.unk0 != 0) {
        setNearClip(D_800F4BA4->nearClip.unk2);
        D_800F4BA4->nearClip.unk0 = 0;
    }
    if (D_800F4BA4->farClip.unk0 != 0) {
        setFarClip(D_800F4BA4->farClip.unk2, D_800F4C6A);
        D_800F4BA4->farClip.unk0 = 0;
    }
}

void func_800BC1CC(short arg0, int arg1)
{
    VECTOR sp10;
    VECTOR sp20;
    int temp_s0;
    short temp_v0;

    if (D_800F4BA0 != 0) {
        D_800F4BA0 = 0;
        return;
    }
    initialiseCameraFromSpherical(&sp10, &sp20, arg0, (short)arg1);
    vectorCopy(&D_800F4BA4->eye.position, &sp10);
    vectorCopy(&D_800F4BA4->lookAt.position, &sp20);
    temp_s0 = vectorMagnitude(vectorSubtract(
        (VECTOR*)0x1F800098, &D_800F4BA4->eye.current, &D_800F4BA4->eye.position));
    temp_v0 = (temp_s0
                  + vectorMagnitude(vectorSubtract((VECTOR*)0x1F800098,
                      &D_800F4BA4->lookAt.current, &D_800F4BA4->lookAt.position)))
            / 0x28000;
    if ((temp_v0 << 0x10) != 0) {
        D_800E9C1C[2] = D_800E9C1C[6] = temp_v0;
        vs_battle_script_Cx_Dx_camera(D_800E9C1C, 0);
        vs_battle_script_Cx_Dx_camera(D_800E9C1C + 3, 0);
    }
}

int vs_battle_script_Cx_Dx_camera(u_char* script, UNUSED short unused)
{
    D_800F4BA4_t2* c;
    D_800F4BA4_t2* other;
    if (!(script[0] & 16)) {
        c = &D_800F4BA4->lookAt;
        other = &D_800F4BA4->eye;
    } else {
        c = &D_800F4BA4->eye;
        other = &D_800F4BA4->lookAt;
    }
    switch (script[0] & 15) {
    case 0:
        setVectorImm(&c->position, script + 1);
        return scriptNext;
    case 1:
        c->mode = 15;
        vectorCopy(&c->current, &c->position);
        vectorCopy(&other->target, &c->position);
        return scriptNext;
    case 2:
        c->mode = 2;
        c->time = 0;
        c->ease1 = script[1];
        c->duration = script[2];
        vectorCopy(&c->start, &c->current);
        vectorSubtract(&c->velocity, &c->position, &c->current);
        return scriptNext;
    case 3:
        c->mode = 3;
        c->time = 0;
        c->ease1 = script[1];
        c->duration = script[2];
        vectorCopy(&c->start, &c->current);
        vectorSubtract(&c->velocity, &c->position, &c->current);
        c->value =
            vectorMagnitude(vectorSubtract((VECTOR*)0x1F800098, &c->target, &c->current));
        return scriptNext;
    case 4: {
        CameraScratch* s;
        c->mode = 4;
        c->time = 0;
        c->duration = script[3];
        c->ease1 = script[1] >> 4;
        c->ease2 = script[2] & 15;
        c->ease3 = script[2] >> 4;
        vectorCopy(&c->start, &c->target);
        s = (CameraScratch*)0x1F800088;
        setVector(&s->v1, c->current.vx - c->target.vx, 0, c->current.vz - c->target.vz);
        c->value = vectorMagnitude((VECTOR*)0x1F800098);
        c->angle = atan2FixedPoint(s->v1.vx, s->v1.vz) & 4095;
        setVector(
            &s->v2, c->position.vx - c->target.vx, 0, c->position.vz - c->target.vz);
        c->delta = vectorMagnitude((VECTOR*)0x1F8000A8) - c->value;
        s->value = (atan2FixedPoint(s->v2.vx, s->v2.vz) & 4095) - c->angle;
        if (s->value < -ONE / 2) {
            s->value += ONE;
        }
        if (s->value > ONE / 2) {
            s->value -= ONE;
        }
        switch (script[1] & 15) {
        case 15:
            if (s->value == 0) {
                s->value = -ONE;
            } else if (s->value > 0) {
                s->value -= ONE;
            }
            break;
        case 1:
            if (s->value == 0) {
                s->value = ONE;
            } else if (s->value < 0) {
                s->value += ONE;
            }
            break;
        }
        c->angleDelta = ((CameraScratch*)0x1F800088)->value;
        c->aux.vy = c->current.vy - c->target.vy;
        c->velocity.vy = c->position.vy - c->target.vy - c->aux.vy;
        return scriptNext;
    }
    case 5: {
        CameraScratch* s;
        int height;
        c->mode = 5;
        c->time = 0;
        c->duration = script[8];
        c->ease1 = script[6] & 15;
        c->ease2 = script[6] >> 4;
        c->ease3 = script[7] & 15;
        vectorCopy(&c->position, &c->target);
        s = (CameraScratch*)0x1F800088;
        setVector(&s->v1, c->current.vx - c->target.vx, 0, c->current.vz - c->target.vz);
        c->value = vectorMagnitude((VECTOR*)0x1F800098);
        c->delta = ((c->value * script[5]) >> 6) - c->value;
        c->angle = atan2FixedPoint(s->v1.vx, s->v1.vz);
        c->angleDelta = getShort(script + 1);
        height = getShort(script + 3) * ONE;
        c->start.vy = c->current.vy;
        c->velocity.vy = height - c->start.vy;
        return scriptNext;
    }
    case 7:
        func_800A190C(
            resolveActorId(getShort(script + 1)), script[3], (SVECTOR*)0x1F8000D8, 2);
        sVectorToFixedPointVector((VECTOR*)0x1F800098, (SVECTOR*)0x1F8000D8);
        setVectorImm((VECTOR*)0x1F8000A8, script + 4);
        vectorAdd(&c->position, (VECTOR*)0x1F800098, (VECTOR*)0x1F8000A8);
        if (D_800F4BA4->unk1E8 != 0x2000) {
            vectorSubtract(&c->position, &c->position, &D_800F4BA4->unk1EC);
        }
        return scriptNext;
    case 8:
        c->mode = 8;
        c->value = resolveActorId(getShort(script + 1));
        c->delta = script[3];
        c->time = 0;
        c->duration = script[10];
        setVectorImm(&c->velocity, script + 4);
        return scriptNext;
    case 9:
        c->mode = 9;
        c->time = 0;
        c->duration = script[1];
        vectorSubtract(&c->velocity, &c->current, &c->target);
        return scriptNext;
    case 10: {
        int id = resolveActorId(getShort(script + 1));
        CameraScratch* s = (CameraScratch*)0x1F800088;
        s->value = id;
        vs_battle_getActorPosition(id, &D_800F4BA4->unk1D0);
        s->rotation2.vz = 0;
        s->rotation2.vx = 0;
        s->rotation2.vy = D_800F4BA4->unk1D0.unk0.unk4.pad;
        RotMatrix_gte((SVECTOR*)0x1F8000E0, (MATRIX*)0x1F8000F8);
        setVectorImm((VECTOR*)0x1F800098, script + 4);
        ApplyMatrixLV((MATRIX*)0x1F8000F8, (VECTOR*)0x1F800098, (VECTOR*)0x1F800098);
        func_800A190C(s->value, script[3], (SVECTOR*)0x1F8000E0, 2);
        vectorAdd(&c->position,
            sVectorToFixedPointVector((VECTOR*)0x1F8000A8, (SVECTOR*)0x1F8000E0),
            (VECTOR*)0x1F800098);
        if (D_800F4BA4->unk1E8 != 0x2000) {
            vectorSubtract(&c->position, &c->position, &D_800F4BA4->unk1EC);
        }
        return scriptNext;
    }
    case 11: {
        CameraScratch* s;
        c->mode = 11;
        c->time = 0;
        c->ease1 = 0;
        c->duration = script[2];
        vectorSubtract((VECTOR*)0x1F800098, &c->target, &c->current);
        vecToRotMatrix((VECTOR*)0x1F800098, (MATRIX*)0x1F8000F8);
        s = (CameraScratch*)0x1F800088;
        s->matrix.t[0] = c->current.vx >> 12;
        s->matrix.t[1] = c->current.vy >> 12;
        s->matrix.t[2] = c->current.vz >> 12;
        c->current.vy = func_800BD2B8((MATRIX*)0x1F8000F8);
        vectorCopy(&c->computed, &c->current);
        c->delta = vectorMagnitude(
            vectorSubtract((VECTOR*)0x1F800098, &c->position, &c->computed));
        c->value = c->delta / script[2];
        D_800F4BA4->unk27C.vx = D_800F4BA4->unk27C.vy = D_800F4BA4->unk27C.vz =
            0x80000000;
        return scriptNext;
    }
    }
}

void func_800BC9E0(void)
{
    D_800F4BA4->eye.target.vx = D_800F4BA4->lookAt.current.vx;
    D_800F4BA4->eye.target.vy = D_800F4BA4->lookAt.current.vy;
    D_800F4BA4->eye.target.vz = D_800F4BA4->lookAt.current.vz;
    D_800F4BA4->lookAt.target.vx = D_800F4BA4->eye.current.vx;
    D_800F4BA4->lookAt.target.vy = D_800F4BA4->eye.current.vy;
    D_800F4BA4->lookAt.target.vz = D_800F4BA4->eye.current.vz;
    func_800BCA8C(&D_800F4BA4->lookAt, &D_800F4BA4->eye);
    func_800BCA8C(&D_800F4BA4->eye, &D_800F4BA4->lookAt);
    func_800BD57C(&D_800F4BA4->unk168);
    func_800BD57C(&D_800F4BA4->unk174);
    func_800BDF6C(&D_800F4BA4->projectionDistance);
    func_800BDF6C(&D_800F4BA4->nearClip);
    func_800BDF6C(&D_800F4BA4->farClip);
    func_800BE180();
}

void func_800BCA8C(D_800F4BA4_t2* c, D_800F4BA4_t2* other)
{
    if (c->mode == 15) {
        return;
    }
    if (c->mode != 11) {
        c->time += vs_gametime_tickspeed >> 1;
        if (c->time > c->duration) {
            c->time = c->duration;
        }
    }
    switch (c->mode) {
    case 2:
        ((CameraScratch*)0x1F800088)->value =
            func_800BFEBC(c->ease1, c->time, c->duration);
        vectorFixedPointMult(
            (VECTOR*)0x1F800098, &c->velocity, ((CameraScratch*)0x1F800088)->value);
        vectorAdd(&c->computed, &c->start, (VECTOR*)0x1F800098);
        break;
    case 3: {
        CameraScratch* s = (CameraScratch*)0x1F800088;
        s->value = func_800BFEBC(c->ease1, c->time, c->duration);
        vectorFixedPointMult((VECTOR*)0x1F800098, &c->velocity, s->value);
        vectorAdd((VECTOR*)0x1F8000A8, &c->start, (VECTOR*)0x1F800098);
        vectorSubtract((VECTOR*)0x1F800098, (VECTOR*)0x1F8000A8, &c->target);
        toNormalIntegerVector((VECTOR*)0x1F800098, (VECTOR*)0x1F800098);
        s->distance = vectorMagnitude(
            vectorSubtract((VECTOR*)0x1F8000A8, &c->target, &c->position));
        s->value = c->value
                 + fixedPointMult(s->distance - c->value,
                     func_800BFEBC(c->ease1, c->time, c->duration));
        vectorFixedPointMult((VECTOR*)0x1F800098, (VECTOR*)0x1F800098, s->value);
        vectorAdd(&c->computed, &c->target, (VECTOR*)0x1F800098);
        break;
    }
    case 4: {
        CameraScratch* s = (CameraScratch*)0x1F800088;
        s->rotation.vz = 0;
        s->rotation.vx = 0;
        s->rotation.vy =
            c->angle
            + ((c->angleDelta * func_800BFEBC(c->ease1, c->time, c->duration)) >> 12);
        RotMatrix_gte((SVECTOR*)0x1F8000D8, (MATRIX*)0x1F8000F8);
        s->v1.vz =
            c->value
            + fixedPointMult(c->delta, func_800BFEBC(c->ease2, c->time, c->duration));
        s->v1.vx = 0;
        s->v1.vy = 0;
        ApplyMatrixLV((MATRIX*)0x1F8000F8, (VECTOR*)0x1F800098, (VECTOR*)0x1F800098);
        s->v1.vy = c->aux.vy
                 + fixedPointMult(
                     c->velocity.vy, func_800BFEBC(c->ease3, c->time, c->duration));
        vectorAdd(&c->computed, &c->start, (VECTOR*)0x1F800098);
        break;
    }
    case 5: {
        CameraScratch* s = (CameraScratch*)0x1F800088;
        s->rotation.vz = 0;
        s->rotation.vx = 0;
        s->rotation.vy =
            c->angle
            + ((c->angleDelta * func_800BFEBC(c->ease1, c->time, c->duration)) >> 12);
        RotMatrix_gte((SVECTOR*)0x1F8000D8, (MATRIX*)0x1F8000F8);
        s->v1.vz =
            c->value
            + fixedPointMult(c->delta, func_800BFEBC(c->ease2, c->time, c->duration));
        s->v1.vx = 0;
        s->v1.vy = 0;
        ApplyMatrixLV((MATRIX*)0x1F8000F8, (VECTOR*)0x1F800098, (VECTOR*)0x1F800098);
        c->computed.vx = c->position.vx + s->v1.vx;
        c->computed.vz = c->position.vz + s->v1.vz;
        c->computed.vy = c->start.vy
                       + fixedPointMult(
                           c->velocity.vy, func_800BFEBC(c->ease3, c->time, c->duration));
        break;
    }
    case 8:
        func_800A190C(c->value, c->delta, (SVECTOR*)0x1F8000D8, 2);
        vectorAdd(&c->computed,
            sVectorToFixedPointVector((VECTOR*)0x1F800098, (SVECTOR*)0x1F8000D8),
            &c->velocity);
        break;
    case 9:
        vectorAdd(&c->computed, &c->velocity, &c->target);
        break;
    case 11:
        func_800BCFB4(c);
        break;
    }
    vectorCopy(&c->previousCamera, &c->current);
    if (c->follow & c->following) {
        int fraction;
        CameraScratch* s;
        vectorAdd(&c->followPosition, &c->followPosition, &c->followDelta);
        fraction = func_800BFEBC(1, c->time, c->duration);
        s = (CameraScratch*)0x1F800088;
        s->value = fraction;
        vectorSubtract((VECTOR*)0x1F800098, &c->computed, &c->followPosition);
        vectorFixedPointMult((VECTOR*)0x1F800098, (VECTOR*)0x1F800098, s->value);
        vectorAdd(&c->current, &c->followPosition, (VECTOR*)0x1F800098);
    } else {
        vectorCopy(&c->current, &c->computed);
    }
    if (c->time == c->duration) {
        c->mode = 15;
        if (c->follow) {
            c->following = 1;
            vectorCopy(&c->followPosition, &c->current);
            vectorSubtract(&c->followDelta, &c->current, &c->previousCamera);
        }
    }
}

void func_800BCFB4(D_800F4BA4_t2* c)
{
    CameraMotionScratch* scratch;
    CameraMotionScratch* finalScratch;
    short i;
    int height;
    vectorSubtract((VECTOR*)0x1F800098, &c->target, &c->position);
    vecToRotMatrix((VECTOR*)0x1F800098, (MATRIX*)0x1F8000F8);
    scratch = (CameraMotionScratch*)0x1F800088;
    scratch->matrix.t[0] = c->position.vx >> 12;
    scratch->matrix.t[1] = c->position.vy >> 12;
    scratch->matrix.t[2] = c->position.vz >> 12;
    setVector(&scratch->delta, c->position.vx - c->computed.vx,
        func_800BD2B8((MATRIX*)0x1F8000F8) - c->computed.vy,
        c->position.vz - c->computed.vz);
    scratch->distance = vectorMagnitude((VECTOR*)0x1F800098);
    scratch->steps = scratch->distance / c->value;
    if (scratch->steps < 2) {
        c->time = c->duration;
    } else if (scratch->steps > 10) {
        scratch->steps = 10;
    }
    toNormalIntegerVector((VECTOR*)0x1F800098, (VECTOR*)0x1F800098);
    vectorFixedPointMult((VECTOR*)0x1F800098, (VECTOR*)0x1F800098, c->value);
    vectorCopy((VECTOR*)0x1F8000A8, &c->computed);
    for (i = 1; i <= ((CameraMotionScratch*)0x1F800088)->steps; ++i) {
        scratch = (CameraMotionScratch*)0x1F800088;
        vectorAdd((VECTOR*)0x1F8000A8, (VECTOR*)0x1F8000A8, (VECTOR*)0x1F800098);
        vectorSubtract((VECTOR*)0x1F8000B8, &c->target, (VECTOR*)0x1F8000A8);
        vecToRotMatrix((VECTOR*)0x1F8000B8, (MATRIX*)0x1F8000F8);
        scratch->matrix.t[0] = scratch->candidate.vx >> 12;
        scratch->matrix.t[1] = scratch->candidate.vy >> 12;
        scratch->matrix.t[2] = scratch->candidate.vz >> 12;
        height = func_800BD2B8((MATRIX*)0x1F8000F8);
        if (height < scratch->candidate.vy) {
            setVector(&scratch->delta, scratch->candidate.vx - c->computed.vx,
                height - c->computed.vy, scratch->candidate.vz - c->computed.vz);
            toNormalIntegerVector((VECTOR*)0x1F800098, (VECTOR*)0x1F800098);
            vectorFixedPointMult((VECTOR*)0x1F800098, (VECTOR*)0x1F800098, c->value);
            break;
        }
    }
    vectorAdd((VECTOR*)0x1F8000A8, (VECTOR*)0x1F800098, &c->computed);
    finalScratch = (CameraMotionScratch*)0x1F800088;
    if (finalScratch->candidate.vx == D_800F4BA4->unk27C.vx
        && finalScratch->candidate.vy == D_800F4BA4->unk27C.vy
        && finalScratch->candidate.vz == D_800F4BA4->unk27C.vz) {
        c->time = c->duration;
    } else {
        vectorCopy(&D_800F4BA4->unk27C, &c->computed);
        vectorCopy(&c->computed, (VECTOR*)0x1F8000A8);
    }
}

int func_800BD2B8(MATRIX* arg0)
{
    VECTOR pos;
    SVECTOR offset;
    long flag;
    int first;
    int second;
    int h;
    short lowest;

    SetRotMatrix(arg0);
    SetTransMatrix(arg0);

    setVector(&offset, 80, 80, 150);
    RotTrans(&offset, &pos, &flag);
    first = ((func_8008DC7C(pos.vx, pos.vz) << 0x11) >> 0x11) - 200;
    lowest = first;

    setVector(&offset, -80, 80, 150);
    RotTrans(&offset, &pos, &flag);
    second = ((func_8008DC7C(pos.vx, pos.vz) << 0x11) >> 0x11) - 200;

    if (second < first) {
        lowest = second;
    }

    setVector(&offset, 80, -80, 150);
    RotTrans(&offset, &pos, &flag);
    h = ((func_8008DC7C(pos.vx, pos.vz) << 0x11) >> 0x11) - 200;

    if (h < lowest) {
        lowest = h;
    }

    setVector(&offset, -80, -80, 150);
    RotTrans(&offset, &pos, &flag);
    h = ((func_8008DC7C(pos.vx, pos.vz) << 0x11) >> 0x11) - 200;

    if (h < lowest) {
        lowest = h;
    }

    return lowest * ONE;
}

int vs_battle_script_E2_E3_camera(u_char* arg0, UNUSED short arg1)
{
    func_800BD57C_t* var_s0;

    switch (arg0[0]) {
    case 0xE2:
        var_s0 = &D_800F4BA4->unk168;
        break;
    case 0xE3:
        var_s0 = &D_800F4BA4->unk174;
        break;
    }

    var_s0->unkA = arg0[4];

    if (var_s0->unkA == 0) {
        var_s0->unk2 = getShort(arg0 + 1);
        var_s0->unk0 = 1;
    } else {
        var_s0->unk4 = var_s0->unk2;
        var_s0->unk6 = getShort(arg0 + 1) - var_s0->unk2;
        if (var_s0->unk6 < -(ONE / 2)) {
            var_s0->unk6 += ONE;
        } else if (var_s0->unk6 > (ONE / 2)) {
            var_s0->unk6 -= ONE;
        }

        switch (arg0[3] >> 4) {
        case 0:
            if (var_s0->unk6 > 0) {
                var_s0->unk6 -= ONE;
            }
            break;
        case 2:
            if (var_s0->unk6 < 0) {
                var_s0->unk6 += ONE;
            }
            break;
        }

        var_s0->unk1 = arg0[3] & 0xF;
        var_s0->unk8 = 0;
    }
    return scriptNext;
}

void func_800BD57C(func_800BD57C_t* arg0)
{
    if (arg0->unkA > 0) {
        arg0->unk8 += vs_gametime_tickspeed >> 1;

        arg0->unk2 = (arg0->unk4
                      + ((arg0->unk6 * func_800BFEBC(arg0->unk1, arg0->unk8, arg0->unkA))
                          >> 0xC));

        if (arg0->unk8 >= arg0->unkA) {
            arg0->unkA = 0;
        }
        arg0->unk0 = 1;
    }
}

int func_800BD610(void)
{
    char temp_a2 = D_800F4BA4->lookAt.mode == 0xF;

    if (D_800F4BA4->eye.mode == 0xF) {
        temp_a2 = temp_a2 | 2;
    }
    if (D_800F4BA4->unk168.unkA == 0) {
        temp_a2 |= 4;
    }
    if (D_800F4BA4->projectionDistance.unk9 == 0) {
        temp_a2 |= 8;
    }
    if (D_800F4BA4->nearClip.unk9 == 0) {
        temp_a2 |= 0x10;
    }
    if (D_800F4BA4->farClip.unk9 == 0) {
        temp_a2 |= 0x20;
    }
    if (D_800F4BA4->unk25C.unk1E == 0) {
        temp_a2 |= 0x40;
    }
    if ((D_800F4BA4->unk1A4.unkB + D_800F4BA4->unk1B0.unkB) == 0) {
        temp_a2 |= 0x80;
    }
    return temp_a2;
}

int vs_battle_script_B9_BA_BF_E4_E5_E6_E7_ED(u_char* script, UNUSED short arg1)
{
    VECTOR values;
    CVECTOR color;
    short mode;
    short effectValue;
    switch (script[0]) {
    case 185:
        func_8007DE44(getShort(script + 1));
        return scriptNext;

    case 186:
        func_8007DE5C(script[1]);
        return scriptNext;

    case 228:
        D_800F4BA4->unk1FC.unk1E = script[4];
        if (D_800F4BA4->unk1FC.unk1E == 0) {
            values.vx = (script[1] << 7);
            values.vy = (script[2] << 7);
            func_8007DDB8(&values);
        } else {
            D_800F4BA4->unk1FC.unk1C = 0;
            func_8007DE88(&values);
            D_800F4BA4->unk1FC.unk12 =
                (script[1] << 7) - (D_800F4BA4->unk1FC.unkA = values.vx);
            D_800F4BA4->unk1FC.unk14 =
                (script[2] << 7) - (D_800F4BA4->unk1FC.unkC = values.vy);
            D_800F4BA4->unk1FC.unk1 = script[3];
        }
        return scriptNext;

    case 229:
        D_800F4BA4->unk21C.unk1E = script[5];
        if (D_800F4BA4->unk21C.unk1E == 0) {
            color.r = script[1];
            color.g = script[2];
            color.b = script[3];
            func_8007DDD4(&color);
        } else {
            D_800F4BA4->unk21C.unk1C = 0;
            func_8007DEA8(&color);
            D_800F4BA4->unk21C.unk12 = script[1] - (D_800F4BA4->unk21C.unkA = color.r);
            D_800F4BA4->unk21C.unk14 = script[2] - (D_800F4BA4->unk21C.unkC = color.g);
            D_800F4BA4->unk21C.unk16 = script[3] - (D_800F4BA4->unk21C.unkE = color.b);
            D_800F4BA4->unk21C.unk1 = script[4];
        }
        return scriptNext;

    case 230:
        D_800F4BA4->unk23C.unk1E = script[4];
        if (D_800F4BA4->unk23C.unk1E == 0) {
            values.vx = (signed char)script[1];
            values.vy = (signed char)script[2];
            func_8007DDF8(&values);
        } else {
            D_800F4BA4->unk23C.unk1C = 0;
            func_8007DECC(&values);
            D_800F4BA4->unk23C.unk12 =
                (signed char)script[1] - (D_800F4BA4->unk23C.unkA = values.vx);
            D_800F4BA4->unk23C.unk14 =
                (signed char)script[2] - (D_800F4BA4->unk23C.unkC = values.vy);
            D_800F4BA4->unk23C.unk1 = script[3];
        }
        return scriptNext;

    case 231:
        func_8007DE2C(script[1]);
        return scriptNext;

    case 237:
        if (D_800F4BA4->unk25C.unk1E > 0) {
            return scriptRepeat;
        }

        D_800F4BA4->unk25C.unk1E = script[4];
        if (D_800F4BA4->unk25C.unk1E == 0) {
            D_800F4BA4->unk25C.unk2 = effectValue = script[1] << 6;
            D_800F4BA4->unk25C.unk4 = (signed char)script[2];
            func_800F9BC0(effectValue, D_800F4BA4->unk25C.unk4);
        } else {
            D_800F4BA4->unk25C.unk1C = 0;
            D_800F4BA4->unk25C.unk12 =
                (script[1] << 6) - (D_800F4BA4->unk25C.unkA = D_800F4BA4->unk25C.unk2);
            D_800F4BA4->unk25C.unk14 =
                (signed char)script[2]
                - (D_800F4BA4->unk25C.unkC = D_800F4BA4->unk25C.unk4);
            D_800F4BA4->unk25C.unk1 = script[3];
        }
        return scriptNext;

    case 191:
        mode = getShort(script + 1);
        if (!mode) {
            func_8007DE2C(0);
            values.vx = values.vy = 0;
            func_8007DDF8(&values);
            values.vx = values.vy = ONE;
            func_8007DDB8(&values);
            color.r = color.g = color.b = 128;
            func_8007DDD4(&color);
            func_8007DE44(0);
            func_8007DE5C(0);
            func_8007DD50(0);
        } else {
            func_8007DD50(1);
            func_8007DE2C(0);
            values.vx = 0;
            values.vy = 2;
            func_8007DDF8(&values);
            values.vx = values.vy = ONE;
            func_8007DDB8(&values);
            color.r = color.g = color.b = 144;
            func_8007DE5C(1);
            func_8007DDD4(&color);
            func_8007DE44(mode);
        }
        return scriptNext;
    }
}

void func_800BDAB4(void)
{
    VECTOR sp10;
    CVECTOR sp20;

    if (func_800BDBB4(&D_800F4BA4->unk1FC) != 0) {
        sp10.vx = D_800F4BA4->unk1FC.unk2;
        sp10.vy = D_800F4BA4->unk1FC.unk4;
        func_8007DDB8(&sp10);
    }
    if (func_800BDBB4(&D_800F4BA4->unk21C) != 0) {
        sp20.r = D_800F4BA4->unk21C.unk2;
        sp20.g = D_800F4BA4->unk21C.unk4;
        sp20.b = D_800F4BA4->unk21C.unk6;
        func_8007DDD4(&sp20);
    }
    if (func_800BDBB4(&D_800F4BA4->unk23C) != 0) {
        sp10.vx = D_800F4BA4->unk23C.unk2;
        sp10.vy = D_800F4BA4->unk23C.unk4;
        func_8007DDF8(&sp10);
    }
    if (func_800BDBB4(&D_800F4BA4->unk25C) != 0) {
        func_800F9BC0(D_800F4BA4->unk25C.unk2, D_800F4BA4->unk25C.unk4);
    }
}

int func_800BDBB4(func_800BDBB4_t* arg0)
{
    func_800BDBB4_t2* a0;
    int v0;

    if (arg0->unk1E == 0) {
        return 0;
    }

    arg0->unk1C = arg0->unk1C + (vs_gametime_tickspeed >> 1);

    v0 = func_800BFEBC(arg0->unk1, arg0->unk1C, arg0->unk1E);
    a0 = (func_800BDBB4_t2*)0x1F800088;
    a0->unk0 = v0;
    arg0->unk2 = (arg0->unkA + ((arg0->unk12 * a0->unk0) >> 0xC));
    arg0->unk4 = (arg0->unkC + ((arg0->unk14 * a0->unk0) >> 0xC));
    arg0->unk6 = (arg0->unkE + ((arg0->unk16 * a0->unk0) >> 0xC));

    if (arg0->unk1C == arg0->unk1E) {
        arg0->unk1E = 0;
    }
    return 1;
}

int vs_battle_script_EA_EB_EC_EE_EF_camera(u_char* script, UNUSED short arg1)
{
    func_800BDF6C_t* entry;
    short i;
    switch (script[0]) {
    case 234:
        if ((D_800F4BA4->projectionDistance.unk9 = script[3]) == 0) {
            D_800F4BA4->projectionDistance.unk2 = script[1] ? (script[1] << 2) : ONE / 8;
            D_800F4BA4->projectionDistance.unk0 = 1;
        } else {
            D_800F4BA4->projectionDistance.unk6 =
                script[1] ? (script[1] << 2)
                                - (D_800F4BA4->projectionDistance.unk4 =
                                        D_800F4BA4->projectionDistance.unk2)
                          : ONE / 8;
            D_800F4BA4->projectionDistance.unk1 = script[2];
            D_800F4BA4->projectionDistance.unk8 = 0;
        }
        return scriptNext;
    case 235:
        if ((D_800F4BA4->nearClip.unk9 = script[3]) == 0) {
            D_800F4BA4->nearClip.unk2 = script[1] ? script[1] : 64;
            D_800F4BA4->nearClip.unk0 = 1;
        } else {
            D_800F4BA4->nearClip.unk6 =
                (script[1] ? script[1] : 64)
                - (D_800F4BA4->nearClip.unk4 = D_800F4BA4->nearClip.unk2);
            D_800F4BA4->nearClip.unk1 = script[2];
            D_800F4BA4->nearClip.unk8 = 0;
        }
        return scriptNext;
    case 236:
        if ((D_800F4BA4->farClip.unk9 = script[3]) == 0) {
            D_800F4BA4->farClip.unk2 = script[1] ? (script[1] << 7) : ONE;
            D_800F4BA4->farClip.unk0 = 1;
        } else {
            D_800F4BA4->farClip.unk6 =
                script[1] ? (script[1] << 7)
                                - (D_800F4BA4->farClip.unk4 = D_800F4BA4->farClip.unk2)
                          : ONE;
            D_800F4BA4->farClip.unk1 = script[2];
            D_800F4BA4->farClip.unk8 = 0;
        }
        return scriptNext;
    case 239:
        entry = (func_800BDF6C_t*)&D_800F4BA4->unk1A4.unk2;
        if (script[2] == 0) {
            entry[0].unk9 = entry[1].unk9 = 0;
            return scriptNext;
        }
        for (i = 0; i < 2; ++i, ++entry) {
            if (entry->unk9 == 0) {
                entry->unk4 = script[1];
                entry->unk6 = script[2];
                entry->unkA = script[3];
                entry->unk0.u8[1] = script[4];
                entry->unk9 = script[5];
                entry->unk8 = 0;
                break;
            }
        }
        return scriptNext;
    }
}

void func_800BDF6C(func_800BDF6C_unk180_t* arg0)
{
    if (arg0->unk9 != 0) {
        short* new_var;
        arg0->unk8 += vs_gametime_tickspeed >> 1;
        if (arg0->unk9 < arg0->unk8) {
            arg0->unk8 = arg0->unk9;
        }
        *(int*)0x1F800088 = func_800BFEBC(arg0->unk1, arg0->unk8, arg0->unk9);
        new_var = &arg0->unk6;
        arg0->unk2 = arg0->unk4 + ((*new_var * *(int*)0x1F800088) >> 0xC);
        if (arg0->unk8 == arg0->unk9) {
            arg0->unk9 = 0;
        }
        arg0->unk0 = 1;
    }
}

int func_800BE01C(func_800BDF6C_t* arg0)
{
    int temp_s1 = arg0->unk4 << 0xC;

    if (arg0->unk9 == 0) {
        return 0;
    }

    arg0->unk8 += vs_gametime_tickspeed >> 1;

    if (arg0->unk9 < arg0->unk8) {
        arg0->unk8 = arg0->unk9;
    }

    switch (arg0->unk0.u8[1]) {
    case 0:
        *(int*)0x1F800088 = 0x1000;
        break;
    case 1:
        *(int*)0x1F800088 = rsin(((arg0->unk8 << 0xA) / arg0->unk9) + 0x400);
        break;
    case 2:
        *(int*)0x1F800088 = rsin((arg0->unk8 << 0xB) / arg0->unk9);
        break;
    case 3:
        *(int*)0x1F800088 = rsin((arg0->unk8 << 0xA) / arg0->unk9);
        break;
    }
    arg0->unk2 = (((rsin((temp_s1 * arg0->unk8) / arg0->unk9) * arg0->unk6) >> 0xC)
                     * *(int*)0x1F800088)
              >> 0xC;
    if (arg0->unk8 == arg0->unk9) {
        arg0->unk9 = 0;
    }
    return 1;
}

// https://decomp.me/scratch/3pQUE
void func_800BE180(void)
{
    short count = 0;
    CameraShakeScratch* clear = (CameraShakeScratch*)0x1F800088;
    short i = 0;
    int x, y, z;
    CameraShakeScratch* scratch;
    func_800BDF6C_t* entry = (func_800BDF6C_t*)&D_800F4BA4->unk1A4.unk2;
    clear->a.vx = clear->a.vy = clear->a.vz = clear->b.vx = clear->b.vy = clear->b.vz = 0;
    scratch = (CameraShakeScratch*)0x1F800088;
    for (; i < 2; ++entry, ++i) {
        if (func_800BE01C(entry)) {
            setVector(&scratch->c, x = entry->unk2 * (((entry->unkA >> 2) & 3) - 1),
                y = entry->unk2 * (((entry->unkA >> 4) & 3) - 1),
                z = entry->unk2 * ((entry->unkA >> 6) - 1));
            if (entry->unkA & 1) {
                applyVector(&scratch->a, x, y, z, +=);
            }
            if (entry->unkA & 2) {
                addVector(&scratch->b, &scratch->c);
            }
            ++count;
        }
    }
    D_800F4BA4->unk1A4.unk0.s16 = count;
    if (count) {
        D_800F4BA4->unk1BE = ((SVECTOR*)0x1F8000D8)->vx;
        D_800F4BA4->unk1C0 = ((SVECTOR*)0x1F8000D8)->vy;
        D_800F4BA4->unk1C2 = ((SVECTOR*)0x1F8000D8)->vz;
        D_800F4BA4->unk1C6 = ((SVECTOR*)0x1F8000E0)->vx;
        D_800F4BA4->unk1C8 = ((SVECTOR*)0x1F8000E0)->vy;
        D_800F4BA4->unk1CA = ((SVECTOR*)0x1F8000E0)->vz;
    }
}

void func_800BE36C(int arg0, int arg1)
{
    D_800F4BA4->lookAt.follow = arg0;
    D_800F4BA4->lookAt.following = 0;
    D_800F4BA4->eye.follow = arg1;
    D_800F4BA4->eye.following = 0;
}

void func_800BE3A0(void)
{
    D_800F4BA4_t* c1 = D_800F4BA4;
    D_800F4BA4_t* c2;
    c1->eye.mode = 0xF;
    c1->lookAt.mode = 0xF;
    c2 = D_800F4BA4;
    c2->eye.following = 0;
    c2->eye.follow = 0;
    c2->lookAt.following = 0;
    c2->lookAt.follow = 0;
}

void func_800BE3D0(char arg0)
{
    VECTOR sp10;
    VECTOR sp20;
    VECTOR sp30;
    VECTOR sp40;
    u_char temp_s0;
    u_char temp_s3;
    int new_var;

    temp_s3 = getStateFlag(0xAF);
    temp_s0 = getStateFlag(0xB0);
    new_var = temp_s3 - 1;
    initialiseCameraFromSpherical(&sp30, &sp10, (new_var + (arg0 * 2)) & 7, temp_s0 + 1);

    sp30.vy += D_800E9C24[temp_s0] << 0xC;
    sp10.vy += D_800E9C24[temp_s0] << 0xC;

    vectorCopy(&D_800F4BA4->lookAt.current, &sp10);
    vectorCopy(&D_800F4BA4->lookAt.target, &sp30);
    vectorCopy(&D_800F4BA4->eye.target, &sp10);
    vectorCopy(&D_800F4BA4->eye.current, &sp30);

    D_800F4BA4->lookAt.mode = 0xF;

    initialiseCameraFromSpherical(&sp40, &sp20, temp_s3, temp_s0 + 1);

    vectorCopy(&D_800F4BA4->eye.position, &sp40);
    vectorCopy(&D_800F4BA4->lookAt.position, &sp20);

    vs_battle_script_Cx_Dx_camera(&D_800E9C28, 0);
    vs_battle_script_Cx_Dx_camera(&D_800E9C2C, 0);
}

void func_800BE53C(D_800F4BA4_t2* arg0)
{
    VECTOR sp10;

    vectorSubtract(&sp10, &arg0->current, &arg0->position);
    arg0->duration = ((vectorMagnitude(&sp10) >> 0xC) * arg0->duration) / 1000;
}

void func_800BE5A4(short arg0)
{
    D_800F4BA4_t2* temp_s0;
    D_800F4BA4_t2* var_a0;
    D_800F4BA4_t2* temp_s1;

    temp_s0 = &D_800F4BA4->lookAt;
    temp_s1 = &D_800F4BA4->eye;

    if (arg0 == 2) {
        func_800BE53C(temp_s0);
        func_800BE53C(temp_s1);
        temp_s0->duration = temp_s1->duration =
            (temp_s0->duration + temp_s1->duration) >> 1;

        return;
    }
    var_a0 = temp_s0;
    if (arg0 != 0) {
        var_a0 = temp_s1;
    }
    func_800BE53C(var_a0);
}

VECTOR* vectorAdd(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2)
{
    setVector(arg0, arg1->vx + arg2->vx, arg1->vy + arg2->vy, arg1->vz + arg2->vz);
    return arg0;
}

VECTOR* vectorSubtract(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2)
{
    setVector(arg0, arg1->vx - arg2->vx, arg1->vy - arg2->vy, arg1->vz - arg2->vz);
    return arg0;
}

VECTOR* vectorFixedPointMult(VECTOR* arg0, VECTOR* arg1, int arg2)
{
    setVector(arg0, fixedPointMult(arg1->vx, arg2), fixedPointMult(arg1->vy, arg2),
        fixedPointMult(arg1->vz, arg2));
    return arg0;
}

static VECTOR* vectorCopy(VECTOR* arg0, VECTOR* arg1)
{
    copyVector(arg0, arg1);
    return arg0;
}

static int vectorMagnitude(VECTOR* arg0)
{
    VECTOR sp10;
    int temp_lo;
    int temp_lo_2;
    int temp_v0;

    vectorCopy(&sp10, arg0);
    temp_lo = (sp10.vx >> 0xC) * (sp10.vx >> 0xC);
    temp_lo_2 = (sp10.vy >> 0xC) * (sp10.vy >> 0xC);
    temp_v0 = (sp10.vz >> 0xC) * (sp10.vz >> 0xC);
    sp10.vx = sp10.vx >> 0xC;
    sp10.vy = sp10.vy >> 0xC;
    sp10.vz = sp10.vz >> 0xC;
    return vs_gte_rsqrt(temp_lo + temp_lo_2 + temp_v0) * ONE;
}

VECTOR* setVectorImm(VECTOR* arg0, u_char* arg1)
{
    setVector(
        arg0, getShort(arg1) * ONE, getShort(arg1 + 2) * ONE, getShort(arg1 + 4) * ONE);
    return arg0;
}

static VECTOR* sVectorToFixedPointVector(VECTOR* arg0, SVECTOR* arg1)
{
    arg0->vx = arg1->vx * ONE;
    arg0->vy = arg1->vy * ONE;
    arg0->vz = arg1->vz * ONE;
    return arg0;
}

static int fixedPointMult(int a, int b)
{
    int result;
    __asm__("mult       %1, %2;"
            "mflo       $t0;"
            "mfhi       $t1;"
            "srl        $t0, 12;"
            "sll        $t1, 20;"
            "or         %0, $t0, $t1;"
        : "=r"(result)
        : "r"(a), "r"(b));
    return result;
}

int atan2FixedPoint(int arg0, int arg1) { return ratan2(arg0 >> 6, arg1 >> 6); }

void vecToRotMatrix(VECTOR* arg0, MATRIX* arg1)
{
    SVECTOR sp10;
    SVECTOR sp18;

    sp18.vx = arg0->vx >> 0xC;
    sp18.vy = arg0->vy >> 0xC;
    sp18.vz = arg0->vz >> 0xC;
    sp10.vy = ratan2(sp18.vx, sp18.vz);
    sp10.vx = ratan2(sp18.vy, vs_gte_rsqrt((sp18.vx * sp18.vx) + (sp18.vz * sp18.vz)));
    sp10.vz = 0;
    RotMatrix_gte(&sp10, arg1);
}

static void toNormalIntegerVector(VECTOR* arg0, VECTOR* arg1)
{
    VECTOR sp10;

    setVector(&sp10, arg0->vx >> 0xC, arg0->vy >> 0xC, arg0->vz >> 0xC);
    VectorNormal(&sp10, arg1);
}

int loadMpdClearedScriptDoorSections(void* clearedSection, u_short clearedSectionLen,
    void* scriptSection, u_short scriptSectionLen, void* doorSection,
    u_short doorSectionLen, int startState)
{
    vs_battle_setStateFlag(0xA9, 0);
    if (startState == 0) {
        short i;
        for (i = 32; i < 64; ++i) {
            vs_battle_setStateFlag(i, 0);
        }
    }

    if (clearedSectionLen != 0) {
        mpdClearedSection = vs_main_allocHeap(clearedSectionLen);
        memcpy(mpdClearedSection, clearedSection, clearedSectionLen);
    } else {
        mpdClearedSection = NULL;
    }

    if (doorSectionLen != 0) {
        mpdRoomDoorSection = vs_main_allocHeap(doorSectionLen);
        memcpy(mpdRoomDoorSection, doorSection, doorSectionLen);
    } else {
        mpdRoomDoorSection = NULL;
    }

    if (D_800F4BE2 == 1) {
        D_800F4BE2 = 2;
        return 1;
    }

    if (D_800F4BE2 == 3) {
        D_800F4C34 = 0;
        D_800F4BE2 = 0;
        D_800F4BB8 = 0;
    }

    mpdScriptSection = scriptSectionLen != 0;

    if (mpdScriptSection != 0) {
        memcpy(D_800F4C30, scriptSection, scriptSectionLen);
    }
    return 0;
}

short func_800BEB00(void) { return D_800F4C34; }

short func_800BEB10(void) { return (D_800F4BE0 << 0xC) | evtFile; }

void func_800BEB34(void)
{
    if (D_800F4BE2 == 3) {
        func_800BFD9C();
    }
    if (mpdClearedSection != 0) {
        vs_main_freeHeap(mpdClearedSection);
    }
    if (mpdRoomDoorSection != 0) {
        vs_main_freeHeap(mpdRoomDoorSection);
    }
}

void func_800BEB9C(int arg0)
{
    if (arg0 == 0) {
        short i;
        for (i = 64; i < 128; ++i) {
            vs_battle_setStateFlag(i, 0);
        }
    }
}

void func_800BEBEC(void) { }

char getStateFlag(short arg0)
{
    char* flags = (char*)&vs_main_stateFlags;
    return flags[arg0];
}

void vs_battle_setStateFlag(short id, char value)
{
    char* flags = (char*)&vs_main_stateFlags;
    flags[id] = value;
}

int func_800BEC30(void)
{
    if (D_800F4C34 == 1) {
        D_800F4BB8 = D_800F4C34;
        return 1;
    }
    return 1;
}

short func_800BEC58(short type, int arg1, int arg2, short mode)
{
    char buf[64];
    vs_ActorPosition position;
    short i;
    short otherActorId;
    short flagId;
    short actorId;
    short flagValue;
    int result;
    short negate;
    short eventId;
    u_char* p;
    short left;
    int right;

    if (type == 255) {
        if (D_800F4C34 == 0) {
            return 0;
        }

        return 2;
    }

    if (type == 1) {
        int scriptSection = mpdScriptSection;

        if (scriptSection & 1) {
            mpdScriptSection = 0;
            D_800F4C34 = 1;
            D_800F4BE0 = 1;
            D_800F4BA8 = 1;
            return 1;
        }
    }

    if (type == 64) {
        evtFile = arg1;
        D_800F4BE0 = 0;
        D_800F4C34 = 1;
        D_800F4BA8 = 1;
        return 1;
    }

    if (D_800F4C34 != 0 && D_800F4BA8 != 0) {
        return 2;
    }

    for (i = 0; i < 16; ++i) {
        u_short offset = ((u_short*)mpdClearedSection)[i];

        if (offset == 0xFFFF) {
            return 0;
        }

        p = mpdClearedSection + offset;

        if (!(*p & type)) {
            continue;
        }

        ++p;
        eventId = getShort(p);
        p += 2;
        negate = 0;

        while (1) {
            result = 0;

            switch (*p) {
            case 0xFF:
                if (eventId & 0x8000) {
                    evtFile = eventId & 0xF;
                    D_800F4BE0 = 2;
                } else {
                    evtFile = eventId;
                    D_800F4BE0 = 0;
                }

                D_800F4C34 = 1;
                D_800F4BA8 = 0;
                return 1;

            case 1:
                vs_battle_getActorPosition(0, &position);

                if (position.unk0.unk0.x == p[1] && position.unk0.unk0.z == p[2]) {
                    result = 1;
                }

                p += 3;
                break;

            case 2:
                vs_battle_getActorPosition(0, &position);

                if (position.unk0.unk0.x >= p[1] && position.unk0.unk0.x < p[1] + p[3]
                    && position.unk0.unk0.z >= p[2]
                    && position.unk0.unk0.z < p[2] + p[4]) {
                    result = 1;
                }

                p += 5;
                break;

            case 3:
                left = getStateFlag(((p[1] & 0xF) << 6) | (p[2] >> 2));
                right = p[3];
                goto compare;

            case 15:
                left = getStateFlag(((p[1] & 0xF) << 6) | (p[2] >> 2));
                right = getStateFlag(((p[2] & 3) << 8) | p[3]);
            compare:
                switch (p[1] & 0xF0) {
                case 0x00:
                    if (left <= right) {
                        result = 1;
                    }
                    break;

                case 0x10:
                    if (left >= right) {
                        result = 1;
                    }
                    break;

                case 0x20:
                    if (left == right) {
                        result = 1;
                    }
                    break;

                case 0x30:
                    if (left != right) {
                        result = 1;
                    }
                    break;

                case 0x40:
                    if (left < right) {
                        result = 1;
                    }
                    break;

                case 0x50:
                    if (left > right) {
                        result = 1;
                    }
                    break;
                }

                p += 4;
                break;

            case 4:
                left = getShort(p + 1);

                if (left & 0x1000) {
                    if (getActor(left & 0x1F) != NULL) {
                        result = 1;
                    }
                } else if (func_8007CF18(left) != 1) {
                    result = 1;
                }

                p += 3;
                break;

            case 5:
                left = flagValue = func_8007CF80(p[1]);
                flagId = getShort(p + 2);

                if (flagId != 0) {
                    vs_battle_setStateFlag(flagId, flagValue);
                    result = 1;
                } else if (left != 0) {
                    result = 1;
                }

                p += 4;
                break;

            case 6:
                if (mode == 0) {
                    actorId = resolveActorId(getShort(p + 1));
                    otherActorId = resolveActorId(getShort(p + 3));

                    if (actorId != 1 && otherActorId != 1 && arg1 == actorId
                        && arg2 == otherActorId) {
                        result = 1;
                    }
                }

                p += 5;
                break;

            case 7:
                actorId = resolveActorId(getShort(p + 1));

                if (actorId == 1) {
                    negate = 0;
                    break;
                }

                left = flagValue = func_8007C218(actorId);
                flagId = getShort(p + 3);

                if (flagId != 0) {
                    vs_battle_setStateFlag(flagId, flagValue);
                    result = 1;
                } else if (left != 0) {
                    result = 1;
                }

                p += 5;
                break;

            case 8:
                if (mode == 1 && ((u_char*)arg2)[0] == p[1]
                    && ((u_char*)arg2)[2] == p[2]) {
                    result = 1;
                }

                p += 3;
                break;

            case 9:
                if (!(vs_battle_getActorFlags(0) & 0x104000)) {
                    result = 1;
                }

                ++p;
                break;

            case 10:
                left = flagValue = itemIdIsInInventory(getShort(p + 1));
                flagId = getShort(p + 3);

                if (flagId != 0) {
                    vs_battle_setStateFlag(flagId, flagValue);
                    result = 1;
                } else if (left != 0) {
                    result = 1;
                }

                p += 5;
                break;

            case 11:
                if ((short)func_800A0024(p[1], &position.unk0) >= 0
                    && position.unk0.unk0.x == p[2] && position.unk0.unk0.z == p[3]
                    && (p[4] == 0 || -(position.unk0.unk4.vy / 128) + 1 == p[4])
                    && (p[5] == 0 || (position.unk0.unk0.extra >> 2) + 1 == p[5])) {
                    result = 1;
                }

                p += 6;
                break;

            case 12:
                left = flagValue = -func_800A92B8(p[1], p[2]) / 128;
                flagId = getShort(p + 3);

                if (flagId != 0) {
                    vs_battle_setStateFlag(flagId, flagValue);
                    result = 1;
                } else if (left != 0) {
                    result = 1;
                }

                p += 5;
                break;

            case 13:
                actorId = resolveActorId(getShort(p + 1));

                if (actorId == 1) {
                    negate = 0;
                    break;
                }

                vs_battle_getActorPosition(actorId, &position);

                if (position.unk0.unk0.x == p[3] && position.unk0.unk0.z == p[4]) {
                    result = 1;
                }

                p += 5;
                break;

            case 14:
                actorId = resolveActorId(getShort(p + 1));

                if (actorId == 1) {
                    negate = 0;
                    break;
                }

                vs_battle_getActorPosition(actorId, &position);

                if (position.unk0.unk0.x >= p[3] && position.unk0.unk0.x < p[3] + p[5]
                    && position.unk0.unk0.z >= p[4]
                    && position.unk0.unk0.z < p[4] + p[6]) {
                    result = 1;
                }

                p += 7;
                break;

            case 16:
                actorId = resolveActorId(getShort(p + 1));

                if (actorId == 1) {
                    negate = 0;
                    break;
                }

                if (func_8007CFCC(actorId) != 0) {
                    result = 1;
                }

                p += 3;
                break;

            case 0xFE:
                negate = 1;
                ++p;
                continue;

            default:
                sprintf(buf, "UNKNOWN TRIGGER DETECTED:%02x", *p);
                break;
            }

            if (result == negate) {
                break;
            }

            negate = 0;
        }
    }
}

void parseEvt(u_char* data)
{
    short i;
    u_char* table;

    scriptStrings = (u_short*)(data + *(u_short*)(data + 2));
    table = data + *(u_short*)(data + 4);

    for (i = 9; i < 16; ++i) {
        D_800EB588[i] = ((u_short*)table)[i - 8] ? table + ((u_short*)table)[i - 8] : 0;
    }

    table = data + *(u_short*)(data + 6);

    for (i = 0; i < 8; ++i) {
        D_800F4BC0[i] = ((u_short*)table)[i] ? (char*)table + ((u_short*)table)[i] : 0;
    }

    D_800F4C38[0] = data + 16;
    D_800F4C38[1] = D_800F4C38[2] = D_800F4C38[3] = 0;
    scriptSkipMode = scriptSkipOff;
    skipRequested = 0;

    vs_battle_setStateFlag(168, 0);

    D_800F4C58[1] = D_800F4C58[2] = D_800F4C58[3] = 0;
    D_800F4BB9 = 0;
    D_800F4C4E = 0;
    textBoxSelectionPending = 0;
    D_800F4BE4 = 0;
    D_800F4BF8 = 0;
    D_800F4BE2 = 0;
    D_800F4BB6 = 0;
    D_800F4C58[0] = 0;
    D_800F4C22 = 0;

    for (i = 0; i < 8; ++i) {
        textBoxStatuses[i] = 0;
    }

    for (i = 0; i < 4; ++i) {
        ((ScriptBytePair*)D_800F4B28)[i].low = ((ScriptBytePair*)D_800F4B28)[i].high = 0;
    }

    D_800F4B8B = 0;
    gimTweens[0].duration = gimTweens[1].duration = gimTweens[2].duration = 0;
    D_800F4C69 = vs_main_getcurrentMusicSlot();
    evtCdSlot = NULL;

    for (i = 16; i < 32; ++i) {
        vs_battle_setStateFlag(i, 0);
    }
}

int func_800BF850(void)
{
    short i;
    UNUSED int _[2];

    if (D_800F4C34 == 0) {
        return 0;
    }

    if (D_800F4C34 == 1) {
        if (D_800F4BB8 != 0) {
            D_800F4C34 = 2;
            D_800F4BB8 = 0;
            func_800BBBE8();
            func_8007CEC0();

            for (i = 0; i < 17; ++i) {
                D_800F4B70[i] = 0;
            }

            return 2;
        }

        return 0;
    }

    if (D_800F4C34 == 2) {
        D_800F4C6A = 0;
        D_800F4C54 = 0;

        switch (D_800F4BE0) {
        case 1:
            parseEvt(D_800F4C30);
            D_800F4C34 = 4;
            break;

        case 2:
            parseEvt(mpdRoomDoorSection + ((short*)mpdRoomDoorSection)[evtFile]);
            D_800F4C34 = 4;
            break;

        case 0:
            func_800C00E8(evtFile, D_800F4C30);
            D_800F4C34 = 3;
            break;
        }

        return 2;
    }

    if (D_800F4C34 == 3) {
        if (evtCdSlot->state == CdQueueStateLoaded) {
            vs_main_freeCdQueueSlot(evtCdSlot);

            if (D_800F4C54 != 0) {
                vs_main_memcpy(D_800F4C30, D_800F4C24, 0x1800);
                vs_main_freeHeapR(D_800F4C24);
                D_800F4C54 = 0;
            }

            parseEvt(D_800F4C30);
            D_800F4C34 = 4;
        }

        return 2;
    }

    func_800BBE94();

    if (D_800F4C22 == 0) {
        if (func_800BFBB8(D_800F4C38, 0) != 0) {
            if (D_800F4BB6 == 0 && D_800F4C54 == 0 && D_800F4BE2 == 0) {
                func_800BC1CC(-1, -1);
            }

            D_800F4C22 = 1;
        }

        for (i = 1; i < 4; ++i) {
            if (D_800F4C38[i] != NULL) {
                func_800BFBB8(&D_800F4C38[i], i);
            }
        }
    }

    func_800BC9E0();
    func_800BDAB4();
    applyCameraState();
    func_800BB9B0();
    func_800BBAFC();

    if (D_800F4BE4 != 0) {
        func_800BB874();
    }

    if (D_800F4C22 != 0 && (u_char)func_800BD610() == 255) {
        if (D_800F4C54 != 0) {
            D_800F4C34 = 3;
            D_800F4BE0 = 0;
        } else {
            func_800BFD9C();
            D_800F4C34 = 0;
        }

        D_800F4C22 = 0;
    }

    return 2;
}
