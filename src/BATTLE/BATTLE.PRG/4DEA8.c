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
#include "gim.h"
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
    u_char changed;
    u_char ease;
    short value;
    short start;
    short delta;
    short elapsed;
    short duration;
} AngleTween;

typedef struct {
    u_char changed;
    u_char ease;
    short value;
    short start;
    short delta;
    u_char elapsed;
    u_char duration;
    UNUSED u_char _;
} ProjectionTween;

typedef struct {
    UNUSED u_char _0;
    u_char ease;
    SVECTOR value;
    SVECTOR start;
    SVECTOR delta;
    UNUSED short _1;
    short elapsed;
    short duration;
} ScreenEffectTween;

typedef struct {
    UNUSED u_char _;
    u_char curve;
    u_char elapsed;
    u_char duration;
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
    UNUSED u_char _0;
    UNUSED u_char _1;
    u_char elapsed;
    u_char duration;
    short direction;
    short startDirection;
    short deltaDirection;
    short fallAngle;
    short startFallAngle;
    short deltaFallAngle;
    short intensity;
    short startIntensity;
    short deltaIntensity;
} ParticleTween;

typedef struct {
    u_char mode;
    u_char ease1;
    u_char ease2;
    u_char ease3;
    u_char time;
    u_char duration;
    u_char carryMomentum;
    u_char carrying;
    int value;
    int delta;
    short angle;
    short angleDelta;
    VECTOR start;
    VECTOR position;
    VECTOR velocity;
    VECTOR aux;
    VECTOR momentumStep;
    VECTOR momentumPosition;
    VECTOR previousCamera;
    VECTOR computed;
    VECTOR current;
    VECTOR otherPosition;
} CameraChannel;

enum {
    cameraModeLerp = 2,
    cameraModeArc = 3,
    cameraModeOrbitTo = 4,
    cameraModeOrbitBy = 5,
    cameraModeFollowActor = 8,
    cameraModeLockOffset = 9,
    cameraModeTerrainFollow = 11,
    cameraModeIdle = 15
};

enum {
    cameraIdleLookAt = 1 << 0,
    cameraIdleEye = 1 << 1,
    cameraIdleRoll = 1 << 2, // E2
    cameraIdleProjectionDistance = 1 << 3, // EA
    cameraIdleNearClip = 1 << 4, // EB
    cameraIdleFarClip = 1 << 5, // EC
    cameraIdleLensDistortion = 1 << 6, // ED
    cameraIdleShake = 1 << 7, // EF
    cameraIdleAll = 0xFF
};

typedef struct {
    UNUSED u_char _;
    u_char envelope;
    short offset;
    short cycles;
    short amplitude;
    u_char elapsed;
    u_char duration;
    u_char flags;
} ShakeEntry;

typedef struct {
    CameraChannel lookAt;
    CameraChannel eye;
    AngleTween roll;
    AngleTween framebufferSpin;
    ProjectionTween projectionDistance;
    ProjectionTween nearClip;
    ProjectionTween farClip;
    short shakeCount;
    ShakeEntry shakeEntries[2];
    SVECTOR shakeLookAt;
    SVECTOR shakeEye;
    vs_ActorPosition actorPosition;
    UNUSED int _[2];
    u_short attachedActor;
    VECTOR attachedPosition;
    ScreenEffectTween framebufferScale;
    ScreenEffectTween framebufferTint;
    ScreenEffectTween framebufferOffset;
    ScreenEffectTween lensDistortion;
    VECTOR terrainFollowLast;
} ScriptCamera;

typedef struct {
    int i1;
    int i2;
    UNUSED int i3;
    UNUSED int i4;
    VECTOR v1;
    VECTOR v2;
    VECTOR v3;
    UNUSED VECTOR v4;
    SVECTOR s1;
    SVECTOR s2;
    SVECTOR s3;
    UNUSED SVECTOR s4;
    MATRIX matrix;
} CameraScratch;

#define CAMERA_SCRATCH VS_SCRATCH_AT(CameraScratch*, 0x88)

typedef struct {
    u_char remaining;
    u_char next;
    u_char actors[17];
} ActorList;

typedef struct {
    TextOffset offset;
    short x;
    short y;
    int distance;
} TextPlacement;

enum flagComparison {
    flagComparisonLe = 0x00,
    flagComparisonGe = 0x10,
    flagComparisonEq = 0x20,
    flagComparisonNe = 0x30,
    flagComparisonLt = 0x40,
    flagComparisonGt = 0x50,
    flagComparisonAnd = 0x60
};

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
u_short nextActor(ActorList*);
int getActorScreenPositionAndUpAngle(int actorId, SVECTOR* position);
void attachCameraToActor(u_short actor);
void setCameraFollowsAshley(int follows);
void updateCameraAttachment(void);
static void stepCameraChannel(CameraChannel*, CameraChannel*);
static void stepCameraTerrainFollow(CameraChannel*);
void returnToGameplayCamera(short facing, int zoom);
static int getCameraTerrainHeight(MATRIX*);
static void stepAngleTween(AngleTween*);
u_char getCameraIdleFlags(void);
static int stepScreenEffectTween(ScreenEffectTween*);
static void stepProjectionTween(ProjectionTween*);
static void updateCameraShake(void);
void setCameraMomentum(int lookAt, int eye);
static void stopCamera(void);
void sweepCameraToSavedPlayerView(u_char side);
void scaleCameraMoveDurationByDistance(short target);
static VECTOR* vectorAdd(VECTOR* result, VECTOR* a, VECTOR* b);
static VECTOR* vectorSubtract(VECTOR* result, VECTOR* a, VECTOR* b);
static VECTOR* readScriptVector(VECTOR* result, u_char* script);
static VECTOR* vectorFixedPointMult(VECTOR* result, VECTOR* vector, int scalar);
static void vectorToLookMatrix(VECTOR* direction, MATRIX* matrix);
static int yawFromOffset(int x, int z);
static int fixedPointMult(int a, int b);
static int vectorMagnitude(VECTOR* vector);
static VECTOR* vectorCopy(VECTOR* destination, VECTOR* source);
static VECTOR* sVectorToFixedPointVector(VECTOR* result, SVECTOR* integer);
static void normalizeVector(VECTOR* vector, VECTOR* result);

extern int scriptSfxGroups[];
extern int weaponDrawnModes[];
extern u_char animationBankBase[];
extern u_char skipResetPaletteOp[];
extern u_char skipTailMarkerOp[];
extern u_char textBoxPlacementDirections[];
extern u_char cubePuzzleSubmenus[];
extern short battleTimerModes[];
extern short battleTimerLifetimes[];
extern void sceneResetScript;
extern short cameraPitchPresets[];
extern u_char returnCameraScripts[];
extern short sweepHeightOffsets[];
extern u_char sweepEyeScript[];
extern u_char sweepLookAtScript[];
extern u_short scanlinePhase;
extern GimTween gimTweens[];
extern ParticleTween particleTween;
extern u_char D_800F4B8B;
extern u_char cameraFollowsAshley;
extern ScriptCamera* scriptCamera;
extern u_char D_800F4BA8;
extern void* mpdTriggerSection;
extern u_short* scriptStrings;
extern u_char switchValue;
extern short cameraReturned;
extern u_char eventReady;
extern u_char effectCancelled;
extern char* vibrationPatterns[];
extern short eventSource;
extern u_char scanlinesEnabled;
extern void* mpdTriggeredScripts;
extern u_char scriptMenuState;
extern u_char loopCounters[];
extern short mainScriptEnded;
extern void* nextEvtBuffer;
extern u_char eventState;
/** Next opcode of the code running in each script slot, NULL if it isn't running. */
extern u_char* scriptSlots[];
extern short particleEffectSoundToRestore;
extern u_char weaponAnimating;
extern short mpdEntryScriptPending;
extern short nextEvtQueued;
extern u_char textBoxSelectionPending;
extern int scriptReturnAddress;
extern u_char scriptMusicSlot;
extern u_char fogDepthOverridden;

extern u_char actorMoved[];
extern Gim* gims;

/**
 * Handler for opcode values that are not defined.
 */
int vs_battle_script_invalidOpcode(u_char* script, short slot)
{
    char buf[64];

    sprintf(buf, "unknown code detected:%d,$%08x,$%02x", slot, (u_int)script, *script);
    // Debug printing presumably ifdef'd out
    return scriptNext;
}

/**
 * Does nothing.
 */
int vs_battle_script_nop(UNUSED u_char* script, UNUSED short slot) { return scriptNext; }

/**
 * Does nothing and waits until the next frame before carrying on.
 */
int vs_battle_script_yield(UNUSED u_char* script, UNUSED short slot)
{
    return scriptYield;
}

/**
 * Waits until the event file that is being loaded, if any, has finished loading.
 */
int vs_battle_script_0A_waitEvtLoad(UNUSED u_char* script, UNUSED short slot)
{
    if ((evtCdSlot != 0) && (evtCdSlot->state != CdQueueStateLoaded)) {
        return scriptWait;
    }

    return scriptNext;
}

/**
 * Waits until the GIM that is being loaded has finished loading.
 */
int vs_battle_script_0C_waitGimLoad(UNUSED u_char* script, UNUSED short slot)
{
    return gims->loading;
}

/**
 * Begins a section of the script that the player can skip with START.
 * @param script Opcode bytes:
 *   - [1] bit 0 = keep the music playing if the section is skipped
 *   - [2] = unused
 */
int vs_battle_script_0D_beginSkippable(u_char* script, UNUSED short slot)
{
    scriptSkipMode = scriptSkippable;
    stopMusicOnSkip = !(script[1] & 1);
    return (skipRequested != 0) ? scriptYield : scriptNext;
}

/**
 * Cleans up when a skipped section ends. Resets the effects of the skipped part and
 * clears the skipping flag.
 * @param script The opcode that ended the skip, 0E or 0F.
 */
static void endScriptSkip(u_char* script)
{
    short i;
    short endOpcode;

    for (i = 0; i < 3; ++i) {
        skipResetPaletteOp[1] = (i << 4) | 8;
        vs_battle_script_70_transformColors(skipResetPaletteOp, 0);
    }

    func_800AACDC();

    endOpcode = 0xF;

    while (*script != endOpcode) {
        if (memcmp(script, skipTailMarkerOp, 4) == 0) {
            vs_battle_setStateFlag(skippingScene, 0);
            return;
        }
        script = &script[opcodeLengths[*script]];
    }

    func_80093A70();
    vs_battle_setStateFlag(skippingScene, 0);
}

/**
 * Ends the body of a skippable section. The skip handler follows it, up to the 0F opcode.
 * If the section was not skipped, jumps past the handler; if it was, finishes the skip
 * and carries on into the handler.
 * @param script Opcode bytes:
 *   - [1-2] offset from this opcode to jump to if the section was not skipped
 * @return scriptYield if the section was skipped, otherwise the address to
 * jump to.
 */
int vs_battle_script_0E_endSkippableBody(u_char* script, UNUSED short slot)
{
    u_char prevMode = scriptSkipMode;
    scriptSkipMode = scriptSkipOff;

    if (prevMode == scriptSkipping) {
        endScriptSkip(script);
        return scriptYield;
    }

    return (int)&script[getShort(script + 1)];
}

/**
 * Ends the skip handler of a skippable section. Only has an effect if the section was
 * being skipped, in which case it finishes the skip like 0E.
 */
int vs_battle_script_0F_endSkipHandler(u_char* script, UNUSED short slot)
{
    u_char prevMode = scriptSkipMode;
    scriptSkipMode = scriptSkipOff;

    if (prevMode == scriptSkipping) {
        endScriptSkip(script);
        return scriptYield;
    }

    return scriptNext;
}

/**
 * Creates a text box at a fixed position on the screen.
 * @param script Opcode bytes:
 *   - [1] = (parentBoxId << 4) | boxId
 *   - [2-3] = flags/type (passed to arg1 of initTextBox)
 *   - [4] = x (in some unit, scaled *2 - 0x20)
 *   - [5] = y (scaled - 0x20)
 *   - [6] = width in characters
 *   - [7] = height in lines
 *   - [8-9] = speaker actor (actorSelectorNone: none)
 *   - [10] = speaker animation
 */
int vs_battle_script_10_initTextBox(u_char* script, UNUSED short slot)
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

    if (speakerSelector < actorSelectorNone) {
        box->unk0.speakerActor = resolveActorId(speakerSelector);
    }

    return scriptNext;
}

/**
 * Prints a string in a text box, and waits for it to be read unless told not to.
 * @param script Opcode bytes:
 *   - [1] = boxId
 *   - [2] = string index
 *   - [3] = nonzero: do not wait for the player to advance the text
 */
int vs_battle_script_11_showTextBox(u_char* script, UNUSED short slot)
{
    int printStatus;

    if (textBoxStatuses[script[1]] == 0) {

        vs_battle_setTextBox(script[1], (char*)&scriptStrings[scriptStrings[script[2]]]);

        if (script[3] == 0) {
            textBoxStatuses[script[1]] = 1;
            return scriptWait;
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

    return scriptWait;
}

/**
 * Closes a text box.
 * @param script Opcode bytes:
 *   - [1] = boxId
 */
int vs_battle_script_12_dismissTextBox(u_char* script, UNUSED short slot)
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

    result->distance = SquareRoot0(dx * dx + dy * dy);

    return 0;
}

/**
 * Creates a text box next to an actor, using the placement that fits on the screen.
 * @param script Opcode bytes:
 *   - [1] = boxId
 *   - [2-3] = actor to place the box next to (resolved by resolveActorId)
 *   - [4-5] = flags (passed to initTextBox); [5] & 0xF is the box shape, which also
 *     selects the placement preset
 *   - [6] = width in characters
 *   - [7] = height in lines
 *   - [8] = speaker animation
 */
int vs_battle_script_13_initTextBoxNearActor(u_char* script, UNUSED short slot)
{
    TextPlacement placements[4];
    SVECTOR origin;
    vs_TextBox* box;
    TextPlacement* best = NULL;
    u_int width;
    u_int height;
    int speakerActor;
    short i;

    getActorScreenPositionAndUpAngle(resolveActorId(getShort(script + 2)), &origin);

    origin.vz = ((origin.vz - ONE / 4) & 0xC00) >> 10;

    for (i = 0; i < 4; ++i) {
        if (tryTextBoxPlacement(
                &origin, script, &placements[i], textBoxPlacementDirections[i])) {
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
 * Closes a text box and waits until it has finished closing.
 * @param script Opcode bytes:
 *   - [1] = boxId
 */
int vs_battle_script_14_dismissTextBoxAndWait(u_char* script, UNUSED short slot)
{
    return vs_battle_dismissTextBox(script[1]) != 0 ? scriptWait : scriptNext;
}

/**
 * Waits until one of the given buttons is pressed.
 * @param script Opcode bytes:
 *   - [1] = mask of pad buttons, only the low byte (L2, R2, L1, R1 and the face buttons)
 */
int vs_battle_script_15_waitButtonPressed(u_char* script, UNUSED short slot)
{
    if (vs_main_buttonsPressed.all & script[1]) {
        return scriptYield;
    }

    return scriptWait;
}

/**
 * Loads a GIM image file.
 * @param script Opcode bytes:
 *   - [1-2] = GIM index
 *   - [3] = first VRAM page slot
 */
int vs_battle_script_16_loadGim(u_char* script, UNUSED short slot)
{
    loadGim(getShort(script + 1), script[3]);

    return scriptNext;
}

/**
 * Shows an image of the loaded GIM, setting its position, scale and brightness.
 * @param script Opcode bytes:
 *   - [1] = (image << 6) | mode, image is 0-2 within the GIM and mode selects the draw
 *     function
 *   - [2] = x offset from the screen centre, signed, in units of 2 pixels
 *   - [3] = y offset from the screen centre, signed, in units of 2 pixels
 *   - [4] = scale, 0x20 is full size
 *   - [5] = brightness, 0x80 is normal
 */
int vs_battle_script_17_showGimImage(u_char* script, UNUSED short slot)
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
 * Smoothly changes a shown GIM image's position, scale and brightness. Waits first if
 * the image is still being tweened.
 * @param script Opcode bytes:
 *   - [1] = x offset from the screen centre, signed, in units of 2 pixels
 *   - [2] = y offset from the screen centre, signed, in units of 2 pixels
 *   - [3] = target scale, 0x20 is full size
 *   - [4] = target brightness
 *   - [5] = (image << 6) | curve, curve 0-3 are built in and 4-7 are set up by script
 *   - [6] = duration
 */
int vs_battle_script_18_tweenGimImage(u_char* script, UNUSED short slot)
{
    Gim* gim = gims;
    GimTween* tween = &gimTweens[script[5] >> 6];

    if (gim == NULL) {
        return scriptNext;
    }

    gim += script[5] >> 6;

    if (tween->duration != 0) {
        return scriptWait;
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

/**
 * Unloads the GIM.
 */
int vs_battle_script_19_unloadGim(UNUSED u_char* script, UNUSED short slot)
{
    unloadGim();

    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

/**
 * Waits until all the GIM image tweens have finished.
 */
int vs_battle_script_1A_waitGimTweens(UNUSED u_char* script, UNUSED short slot)
{
    return (gimTweens[0].duration | gimTweens[1].duration | gimTweens[2].duration) != 0
             ? scriptWait
             : scriptNext;
}

/**
 * Sets an integer argument of the printf-style text in the text boxes from state flags.
 * @param script Opcode bytes:
 *   - [1] = printf argument integer to set (0-9)
 *   - [2-3] = state flag id in bits 0-9, type in bits 14-15: 0 = unsigned byte,
 *     1 = signed byte, 2 = unsigned 16 bits, 3 = signed 16 bits. 2 and 3 read
 *     two sequential state flags.
 */
int vs_battle_script_1B_setPrintfArgInt(u_char* script, UNUSED short slot)
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
 * Sets the duration of a text box's animation.
 * @param script Opcode bytes:
 *   - [1] = (boxId << 5) | animation duration (0-31)
 */
int vs_battle_script_1D_setTextBoxAnimationDuration(u_char* script, UNUSED short slot)
{
    vs_battle_getTextBox(script[1] >> 5)->animationDuration = script[1] & 0x1F;

    return scriptNext;
}

/**
 * Lets the player choose between text boxes, and stores the choice in the first scratch
 * flag. Waits until a choice is made.
 * @param script Opcode bytes:
 *   - [1] = mask of the text boxes to choose between, bit n is box n
 */
int vs_battle_script_1C_selectTextBox(u_char* script, UNUSED short slot)
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

    return scriptWait;
}

/**
 * Kills an actor or a group of actors.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector, a single actor or a group
 *   - [3] = nonzero: play the death animation first, 0: start the fade-out directly
 */
int vs_battle_script_1E_actorDeath(u_char* script, UNUSED short slot)
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
 * Stores the tile an actor is standing on in state flags.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = first of three consecutive state flags that receive the actor's tile
 *     x, surface and z. The first flag is set to 0xFF if the actor does not exist.
 */
int vs_battle_script_1F_getActorTile(u_char* script, UNUSED short slot)
{
    vs_ActorPosition position;
    u_short actor = getShort(script + 1);
    u_short flag = getShort(script + 3);

    if (actor & actorSelectorSlot) {

        actor &= 0x1F;

        if (getActor(actor) == NULL) {
            vs_battle_setStateFlag(flag, 0xFF);
            return scriptNext;
        }
    } else {

        actor = getActorSlotById(actor);

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
 * Creates an actor from a model on a tile.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector for the empty slot to create the actor in
 *   - [3-4] = model index (OBJ/xx.SHP), doubles as the id the actor is looked up by
 *   - [5-8] = tile to spawn on and facing: x, surface, z and facing (1/256 turn)
 */
int vs_battle_script_20_spawnActor(u_char* script, UNUSED short slot)
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
int vs_battle_script_21_walkActorToTile(u_char* script, UNUSED short slot)
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

    resetActorMotionState(actor);

    actorMoved[actor] = 1;

    return scriptNext;
}

/**
 * Plays an animation on an actor.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = animation index within the bank
 *   - [4] = unused
 *   - [5] = (bank << 6) | blend frames, the bank selects the base id in animationBankBase
 */
int vs_battle_script_22_playAnimation(u_char* script, UNUSED short slot)
{
    vs_battle_setActorAnimation(resolveActorId(getShort(script + 1)),
        animationBankBase[script[5] >> 6] + script[3], script[4], script[5] & 0x3F);

    return scriptNext;
}

/**
 * Sets the flags of an actor or a group of actors, including whether it is active (see
 * setActorInactive).
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
int vs_battle_script_23_setActorFlags(u_char* script, UNUSED short slot)
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
        bladeFlag = flags & vsBattleActorFlagBladeVisible;
        shieldFlag = flags & vsBattleActorFlagShieldVisible;
        options = script[4];

        if (!(options & 2)) {
            bladeFlag = (options & 1) << 0xB;
        }

        if (!(options & 8)) {
            shieldFlag = (options << 0xA) & vsBattleActorFlagShieldVisible;
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
int vs_battle_script_24_setActorSfxPanVolume(u_char* script, UNUSED short slot)
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
int vs_battle_script_25_moveActorToTile(u_char* script, UNUSED short slot)
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

    resetActorMotionState(actor);

    actorMoved[actor] = 1;

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
int vs_battle_script_26_moveActorToCoordinate(u_char* script, UNUSED short slot)
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

    if (script[9] != 0xFF) {
        position.unk0.unk4.pad = script[9] << 4;
    } else {
        position.unk0.unk4.pad = -0x8000;
    }

    if (scriptSkipMode == scriptSkipping) {
        moveActorToCoordinate(actor, &position.unk0.unk4, 0, 0);
    } else {
        moveActorToCoordinate(actor, &position.unk0.unk4,
            script[10] != 0xFF ? script[10] : -1, script[11] != 0xFF ? script[11] : -1);
    }

    resetActorMotionState(actor);

    actorMoved[actor] = 1;

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
int vs_battle_script_27_slideActorToTile(u_char* script, UNUSED short slot)
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

    resetActorMotionState(actor);

    actorMoved[actor] = 1;

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
int vs_battle_script_28_slideActorToCoordinate(u_char* script, UNUSED short slot)
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

    resetActorMotionState(actor);

    actorMoved[actor] = 1;

    return scriptNext;
}

/**
 * Attaches an actor to a bone of a parent actor. A parent selector of actorSelectorNone
 * detaches it.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = parent actor selector
 *   - [5] = bone index in the parent
 *   - [6] = unused
 */
int vs_battle_script_29_attachActor(u_char* script, UNUSED short slot)
{
    u_short actor = resolveActorId(getShort(script + 1));
    u_short parent = resolveActorId(getShort(script + 3));

    if (parent >= actorSelectorNone) {
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
int vs_battle_script_2A_walkActorToCoordinate(u_char* script, UNUSED short slot)
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

    resetActorMotionState(actor);

    actorMoved[actor] = 1;

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
int vs_battle_script_2B_turnActorToFacing(u_char* script, UNUSED short slot)
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

    actorMoved[actor] = 1;

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
int vs_battle_script_2C_turnActorToFaceActor(u_char* script, UNUSED short slot)
{
    vs_ActorPosition position;
    u_short actor = resolveActorId(getShort(script + 1));

    vs_battle_getActorPosition(resolveActorId(getShort(script + 3)), &position);
    turnActorToFaceTile(actor, &position.unk0.unk0, script[5] != 0xFF ? script[5] : -1);

    actorMoved[actor] = 1;

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
int vs_battle_script_2D_turnActorToFaceTile(u_char* script, UNUSED short slot)
{
    vs_TilePosition tile;
    u_short actor = resolveActorId(getShort(script + 1));

    tile.x = script[3];
    tile.surface = script[4];
    tile.z = script[5];

    // BUG: tile.extra is uninitialised, but used as the facing if already on the tile
    turnActorToFaceTile(actor, &tile, script[6] != 0xFF ? script[6] : -1);

    actorMoved[actor] = 1;

    return scriptNext;
}

/**
 * Sets the scale of an actor, per axis.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = x scale (ONE = normal size)
 *   - [5-6] = y scale
 *   - [7-8] = z scale
 *   - [9] = frame count to change over, 0 = immediately
 */
int vs_battle_script_2E_setActorScale(u_char* script, UNUSED short slot)
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
int vs_battle_script_2F_despawnActor(u_char* script, UNUSED short slot)
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
 *   - [5] = unused
 */
int vs_battle_script_30_waitActorActivity(u_char* script, UNUSED short slot)
{
    u_short actor = resolveActorId(getShort(script + 1)) & 0xFFFF;
    u_short status = vs_battle_getActorFlags(actor) ^ 0x81;
    u_short mask = getShort(script + 3);

    if (mask & 1) {
        if (isActorWalkDone(actor) == 0) {
            status |= 1;
        }
    }

    return (status & mask) != 0 ? scriptWait : scriptNext;
}

/**
 * Overrides the ambient light colour of an actor. Black (0, 0, 0) restores the colour
 * taken from the map lighting at the actor's position.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-5] = red, green and blue (0x80 = neutral)
 */
int vs_battle_script_31_setActorLightColor(u_char* script, UNUSED short slot)
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
int vs_battle_script_32_queueAnimation(u_char* script, UNUSED short slot)
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
 *   - [4-5] = x rotation (1/ONE turn)
 *   - [6-7] = y rotation (the facing)
 *   - [8-9] = z rotation
 *   - [10] = frame count, 0 = immediately, 0xFF = default (from angle and the actor's
 *     unk5C0)
 */
int vs_battle_script_33_rotateActor(u_char* script, UNUSED short slot)
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

    actorMoved[actor] = 1;

    return scriptNext;
}

/**
 * Turns the actor's head to the given angles.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3-4] = pitch (1/ONE turn)
 *   - [5-6] = yaw
 *   - [7] = speed, 0 = unlimited
 */
int vs_battle_script_34_setActorLookAngles(u_char* script, UNUSED short slot)
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
int vs_battle_script_35_playAnimationFromFrame(u_char* script, UNUSED short slot)
{
    setActorAnimationFromFrame(resolveActorId(getShort(script + 1)),
        animationBankBase[script[6] >> 6] + script[3], script[6] & 0x3F, script[4]);

    return scriptNext;
}

/**
 * Like queueAnimation, but the queued animation starts part way through.
 * @param script Opcode bytes: as for playAnimationFromFrame
 */
int vs_battle_script_36_queueAnimationFromFrame(u_char* script, UNUSED short slot)
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
int vs_battle_script_37_setActorMoveAnimation(u_char* script, UNUSED short slot)
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
 *   - [3-4] = target actor selector, actorSelectorNone = stop looking at anything
 *   - [5] = speed, 0 = unlimited
 */
int vs_battle_script_38_setActorLookTarget(u_char* script, UNUSED short slot)
{
    int speed;

    int target = resolveActorId(getShort(script + 3));
    int actor = resolveActorId(getShort(script + 1));

    int mode = -2;

    if (target != actorSelectorNone) {
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
int vs_battle_script_39_setActorLookPosition(u_char* script, UNUSED short slot)
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
int vs_battle_script_3A_enqueueEventData(u_char* script, UNUSED short slot)
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
int vs_battle_script_3B_waitDataQueueEmpty(UNUSED u_char* script, UNUSED short slot)
{
    // BUG: a full queue has no empty slot (-1), so this does not wait
    return getEmptyObjectDataSlot() > 0 ? scriptWait : scriptNext;
}

/**
 * Unloads event data.
 * @param script Opcode bytes:
 *   - [1] = bits 0-1: slot, bit 2: unload only the ETM, otherwise the ESQ and its ETM
 */
int vs_battle_script_3C_unloadEventData(u_char* script, UNUSED short slot)
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
int vs_battle_script_3D_selectEventData(u_char* script, UNUSED short slot)
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
int vs_battle_script_3E_setActorEdgeHighlight(u_char* script, UNUSED short slot)
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
int vs_battle_script_3F_setWeaponDrawn(u_char* script, UNUSED short slot)
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
int vs_battle_script_40_jumpFwdUnlessFlagImm(u_char* script, UNUSED short slot)
{
    char flag = getStateFlag(((u_char)script[2] >> 2) | ((script[1] & 0xF) << 6));
    u_char value = script[3];

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
int vs_battle_script_41_jumpFwdUnlessFlag(u_char* script, UNUSED short slot)
{
    char flag = getStateFlag(((u_char)script[2] >> 2) | ((script[1] & 0xF) << 6));
    u_char other = getStateFlag(script[3] | ((script[2] & 3) << 8));

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
int vs_battle_script_42_jumpFwdElse(u_char* script, UNUSED short slot)
{
    return (long)&script[getShort(script + 1)];
}

/**
 * Presumably for jumping to a label.
 * @param script Opcode bytes:
 *   - [1-2] = target offset from this opcode
 */
int vs_battle_script_45_jumpFwd(u_char* script, UNUSED short slot)
{
    return (long)&script[getShort(script + 1)];
}

/**
 * Starts a switch: stores the value of a state flag, for the jumpFwdCase opcodes that
 * follow to compare against.
 * @param script Opcode bytes:
 *   - [1-2] = state flag id
 */
int vs_battle_script_46_switchOnFlag(u_char* script, UNUSED short slot)
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
int vs_battle_script_47_jumpFwdCase(u_char* script, UNUSED short slot)
{
    if (switchValue == script[1]) {
        return (long)&script[getShort(script + 2)];
    }

    return scriptNext;
}

/**
 * Ends sceneResetScript.
 */
int vs_battle_script_48_endSceneReset(UNUSED u_char* script, UNUSED short slot)
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
int vs_battle_script_49_setLoopCounter(u_char* script, UNUSED short slot)
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
int vs_battle_script_4A_loopCondition(u_char* script, UNUSED short slot)
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
int vs_battle_script_4C_jumpFwdUnused(u_char* script, UNUSED short slot)
{
    return (long)&script[getShort(script + 1)];
}

/**
 * Breaks out of a loop, jumping past the loopCondition that closes the loop.
 * @param script Opcode bytes:
 *   - [1-2] = target offset from this opcode
 */
int vs_battle_script_4B_break(u_char* script, UNUSED short slot)
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
int vs_battle_script_50_modifyFlagImm(u_char* script, UNUSED short slot)
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
int vs_battle_script_51_modifyFlag(u_char* script, UNUSED short slot)
{
    int tmp;
    u_char prev;

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
int vs_battle_script_52_setFlagToItemCount(u_char* script, UNUSED short slot)
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
int vs_battle_script_53_forgetZoneEnemies(u_char* script, UNUSED short slot)
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
int vs_battle_script_54_playWeaponSfx(u_char* script, UNUSED short slot)
{
    playWeaponSfx(resolveActorId(getShort(script + 1)), script[3]);

    return scriptNext;
}

/**
 * Wakes every actor except actor 0 (the player), or puts them all into the dormant state:
 * inert, no AI, not targetable (see setActorAwake).
 * @param script Opcode bytes:
 *   - [1] = 0 = dormant, nonzero = awake
 */
int vs_battle_script_55_setActorsAwake(u_char* script, UNUSED short slot)
{
    setActorsAwake(script[1]);

    return scriptNext;
}

/**
 * Stores the pad state of the first controller in a state flag. Only the low byte of the
 * pad is read: L2, R2, L1, R1, triangle, circle, cross and square.
 * @param script Opcode bytes:
 *   - [1-2] = bits 0-9: state flag id, bit 15: 1 = buttons newly pressed this frame,
 *     0 = buttons held
 */
int vs_battle_script_56_setFlagToButtons(u_char* script, UNUSED short slot)
{
    short flagAndMode = getShort(script + 1);

    vs_battle_setStateFlag(flagAndMode & 0x3FF, flagAndMode & 0x8000
                                                    ? vs_main_buttonsPressed.pad[0].low
                                                    : vs_main_buttonsPreviousState);

    return scriptNext;
}

/**
 * Fully restores an actor: HP, MP and every limb's HP to their maximums, risk and action
 * delay to 0, and all status effects removed.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = unused
 */
int vs_battle_script_57_fullyRestoreActor(u_char* script, UNUSED short slot)
{
    fullyRestoreActor(resolveActorId(getShort(script + 1)));

    return scriptNext;
}

/**
 * Shows or hides the UI (HP, MP and risk bars, limb and status
 * panel) and the minimap.
 * @param script Opcode bytes:
 *   - [1] = 0 = hide, 1 = show
 */
int vs_battle_script_58_setUiVisible(u_char* script, UNUSED short slot)
{
    setUiHidden(script[1] ^ 1);

    return scriptNext;
}

/**
 * Opens a menu and waits for it to finish. Values 10-14 open MENUF.PRG (not really a
 * menu: it shows the cube puzzle and boss time attack screens, selected by state flag
 * menuFSubmenu); 15 opens the loot or unlock screens; any other value opens the menu
 * screen with that id.
 * @param script Opcode bytes:
 *   - [1] = menu selector
 *   - [2-3] = unused
 */
int vs_battle_script_59_openMenu(u_char* script, UNUSED short slot)
{
    // Values of script[1]. The first three are in the order of cubePuzzleSubmenus.
    enum {
        cubePuzzleQuit = 10,
        cubePuzzleStart,
        cubePuzzleEnd,
        timeAttackStart,
        timeAttackEnd,
        loot,
    };

    switch (script[1]) {
    case cubePuzzleQuit:
    case cubePuzzleStart:
    case cubePuzzleEnd:
        if (scriptMenuState == scriptMenuClosed) {
            vs_battle_setStateFlag(
                menuFSubmenu, cubePuzzleSubmenus[script[1] - cubePuzzleQuit]);
            func_8007B9A0();
            scriptMenuState = scriptMenuOpen;

            return scriptWait;
        }

        // Fallthrough
    case timeAttackEnd:
        if (scriptMenuState == scriptMenuClosed) {

            if (getStateFlag(menuFSubmenu) == menuFTimeAttackStart) {
                vs_battle_setStateFlag(menuFSubmenu, menuFTimeAttackEnd);
            }

            func_8007B9A0();

            scriptMusicSlot = 2;
            scriptMenuState = scriptMenuOpen;

            return scriptWait;
        }

        if (updateScriptMenu() != 0) {
            return scriptWait;
        }

        vs_battle_setStateFlag(menuFSubmenu, 0);
        scriptMenuState = scriptMenuClosed;

        return scriptYield;

    case timeAttackStart:
        if (scriptMenuState == scriptMenuClosed) {
            vs_battle_setStateFlag(menuFSubmenu, menuFTimeAttackStart);
            func_8007B9A0();
            scriptMenuState = scriptMenuOpen;

            return scriptWait;
        }

        // Fallthrough
    case loot:
        if (scriptMenuState == scriptMenuClosed) {
            func_8007B9CC();
            scriptMenuState = scriptMenuOpen;

            return scriptWait;
        }

        if (updateScriptMenu() == 0) {
            scriptMenuState = scriptMenuClosed;

            return scriptYield;
        }

        return scriptWait;

    default:
        if (scriptMenuState == scriptMenuClosed) {
            openMenu(script[1], 2);
            scriptMenuState = scriptMenuOpen;

            return scriptWait;
        }

        updateMenu();

        if (func_800CB66C()->unk0 == 2) {
            freeMenuItems();
            scriptMenuState = scriptMenuClosed;

            return scriptYield;
        }

        return scriptWait;
    }
}

/**
 * Starts or stops the on-screen timer.
 * @param script Opcode bytes:
 *   - [1] = 0 = stop and clear the timer, nonzero = start
 *   - [2] = lifetime index (see startBattleTimer)
 *   - [3] = mode index, 0 = counts up, 1 = counts down
 *   - [4-6] = hours, minutes and seconds to count down from
 */
int vs_battle_script_5A_setBattleTimer(u_char* script, UNUSED short slot)
{
    if (script[1] != 0) {
        startBattleTimer(battleTimerModes[script[3]], battleTimerLifetimes[script[2]],
            (script[4] << 24) | (script[5] << 16) | (script[6] << 8));
    } else {
        stopBattleTimer();
    }

    return scriptNext;
}

/**
 * Sets which actor speaks a text box and their animation.
 * @param script Opcode bytes:
 *   - [1] = box id in the low nibble, speaker animation in the high nibble
 *   - [2-3] = actor selector, or actorSelectorNone for no speaker
 */
int vs_battle_script_5B_setTextBoxSpeaker(u_char* script, UNUSED short slot)
{
    u_short speakerSelector = getShort(script + 2);
    vs_TextBox* box = vs_battle_getTextBox(script[1] & 0xF);

    box->unk0.speakerActor =
        speakerSelector < actorSelectorNone ? resolveActorId(speakerSelector) : 0x20;
    box->speakerAnimation = script[1] >> 4;

    return scriptNext;
}

/**
 * Changes the weapon models an actor holds.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = blade model id, 0 = none, 0xFF = leave unchanged, 0xFE = take both weapons
 *     from the actor's equipment
 *   - [4] = unused
 *   - [5] = shield model id, 0 = none, 0xFF = leave unchanged
 *   - [6] = unused
 */
int vs_battle_script_5C_setActorWeaponModels(u_char* script, UNUSED short slot)
{
    u_short actor = resolveActorId(getShort(script + 1));

    if (script[3] == 0xFE) {
        restoreActorWeaponModels(actor);
    } else {
        setActorWeaponModels(actor, script[3], script[5]);
    }

    return scriptNext;
}

/**
 * Gives an actor a slight swaying motion.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = sway angle at its peak, in 1/ONE of a full turn, 0 = stop swaying
 */
int vs_battle_script_5D_setActorSway(u_char* script, UNUSED short slot)
{
    setActorSway(resolveActorId(getShort(script + 1)), script[3]);

    return scriptNext;
}

/**
 * Waits for a number of frames, or until one of the given buttons is pressed.
 * @param script Opcode bytes:
 *   - [1] = mask of pad buttons, only the low byte (L2, R2, L1, R1 and the face buttons)
 *   - [2] = frames to wait, must not be 0
 * @param slot Script slot running the opcode.
 */
int vs_battle_script_5E_waitFramesOrButton(u_char* script, short slot)
{
    if (scriptWaitFrames[slot] == 0) {
        scriptWaitFrames[slot] = script[2];

        return scriptWait;
    }

    if ((vs_main_buttonsPressed.all & script[1]) || (--scriptWaitFrames[slot] <= 0)) {
        scriptWaitFrames[slot] = 0;
        vs_main_buttonsPressed.all = 0;

        return scriptNext;
    }

    return scriptWait;
}

/**
 * Defines one of the four easing curves, numbered 4-7, that tweens can use. It is one of
 * the built-in curves 0-3 with its progress squared a number of times first.
 * @param script Opcode bytes:
 *   - [1] = (slot << 6) | (base curve << 4) | squarings, where squarings is a signed 4
 *     bit number, an ease-in if positive and an ease-out if negative
 */
int vs_battle_script_5F_defineEasing(u_char* script, UNUSED short slot)
{
    int power;
    CustomEasing* base = customEasings;
    CustomEasing* easing = &base[script[1] >> 6];

    easing->curve = (script[1] >> 4) & 3;

    power = script[1] & 7;

    if (script[1] & 8) {
        power |= 0xF8;
    }

    easing->power = power;

    return scriptNext;
}

/**
 * Starts or stops a cloudstone.
 * @param script Opcode bytes:
 *   - [1] = index of the cloudstone in the room data
 *   - [2] = 1 = moving, 0 = stopped
 */
int vs_battle_script_60_setCloudstoneMoving(u_char* script, UNUSED short slot)
{
    setCloudstoneMoving(script[1], script[2]);

    return scriptNext;
}

/**
 * Sets the depth beyond which polygons are dimmed, overriding current setting.
 * @param script Opcode bytes:
 *   - [1..2] = depth, with bit 15 toggling the override
 */
int vs_battle_script_61_overrideFogDepth(u_char* script, UNUSED short slot)
{
    short depth = getShort(script + 1);

    fogDepthOverridden = depth >> 15;

    if (fogDepthOverridden) {
        setFogDepth(depth & 0x7FF);
    }

    return scriptNext;
}

/**
 * Enables or disables the close-up render mode used for first person view, which
 * subdivides large polygons, renders geometry usually culled in 3rd person view,
 * and skips geometry flagged as hidden in first person.
 * @param script Opcode bytes:
 *   - [1] = 1 = enabled, 0 = disabled
 */
int vs_battle_script_62_setFirstPersonRendering(u_char* script, UNUSED short slot)
{
    firstPersonRendering = script[1];

    return scriptNext;
}

/** Clears no statuses (empty mask), so it has no effect. Probably unused. */
int vs_battle_script_63_statusUnk(UNUSED u_char* script, UNUSED short slot)
{
    func_8007C31C();

    return scriptNext;
}

/**
 * Shows a room geometry object.
 * @param script Opcode bytes:
 *   - [1] = geometry object id
 */
int vs_battle_script_64_showGeometry(u_char* script, UNUSED short slot)
{
    showGeometryObject(script[1]);

    return scriptNext;
}

/**
 * Hides a room geometry object.
 * @param script Opcode bytes:
 *   - [1] = geometry object id
 */
int vs_battle_script_65_hideGeometry(u_char* script, UNUSED short slot)
{
    hideGeometryObject(script[1]);

    return scriptNext;
}

/**
 * Swaps the render flags of two room geometry objects.
 * @param script Opcode bytes:
 *   - [1], [2] = geometry object ids
 */
int vs_battle_script_66_swapGeometryFlags(u_char* script, UNUSED short slot)
{
    swapGeometryFlags(script[1], script[2]);

    return scriptNext;
}

/**
 * Blocks or unblocks a tile in the room's walkable area.
 * @param script Opcode bytes:
 *   - [1] = tile column
 *   - [2] = layer, 0 or 1 = layer of the tile grid, 2 and above = cloudstone (layer - 2)
 *   - [3] = tile row
 *   - [4] = 1 = blocked, 0 = open
 */
int vs_battle_script_67_setTileBlocked(u_char* script, UNUSED short slot)
{
    setTileBlocked(script[1], script[3], script[2], script[4]);

    return scriptNext;
}

/**
 * Warps the player to another room with a screen transition, waiting until it has loaded.
 * @param script Opcode bytes:
 *   - [1] = zone, 0 = the current zone
 *   - [2] = map within the zone
 *   - [3] = tile column
 *   - [4] = arrival surface
 *   - [5] = tile row
 *   - [6] = facing
 *   - [7] = bit 0 walk forward, bit 1 face the camera, bit 2 continue script in the
 *     new room (otherwise the event ends), bit 3 switch to the new zone's music
 *   - [8] = screen transition effect
 *   - [9] = screen transition speed
 */
int vs_battle_script_68_warp(u_char* script, UNUSED short slot)
{
    if (scriptWarpState == scriptWarpIdle) {
        vs_Warp warp;

        warp.zndId = script[1];
        warp.mpdId = script[2];
        warp.x = script[3];
        warp.z = script[5];
        warp.targetTile.arrivalSurface = script[4];
        warp.facing = script[6];
        warp.walkForward = script[7];
        warp.faceCamera = script[7] >> 1;

        if (script[1] == 0) {
            warpToMapThroughDoor(&warp, script[8], script[9]);
        } else {
            setSwitchZoneMusic((script[7] >> 3) & 1);
            warpToZoneThroughDoor(&warp, script[8], script[9]);
        }

        scriptWarpState = (script[7] & 4) ? scriptWarpResume : scriptWarpEnd;
    }

    if (scriptWarpState == scriptWarpArrived) {
        scriptWarpState = scriptWarpIdle;

        return scriptNext;
    }

    return scriptWait;
}

/**
 * Transitions the screen out with a fade or wipe, waiting for it to finish.
 * @param script Opcode bytes:
 *   - [1] = effect
 *   - [2] = speed
 *   - [3] = wipe angle, in 1/256ths of a turn
 */
int vs_battle_script_69_screenTransitionOut(u_char* script, UNUSED short slot)
{
    int phase = getScreenTransitionPhase();

    if (phase != screenTransitionOutDone) {
        if (phase == screenTransitionIdle) {
            startScreenTransitionOut(script[1], script[2], script[3] * ONE / 256);
        }

        return scriptWait;
    }

    return scriptNext;
}

/**
 * Transitions the screen back in from a fade or wipe, without waiting for it to finish.
 * @param script Opcode bytes:
 *   - [1] = effect
 *   - [2] = speed
 *   - [3] = wipe angle, in 1/256ths of a turn
 */
int vs_battle_script_6A_screenTransitionIn(u_char* script, UNUSED short slot)
{
    startScreenTransitionIn(script[1], script[2], script[3] * ONE / 256);

    return scriptNext;
}

/**
 * Sets the wipe angle of the screen transition, without starting one. Unused.
 * @param script Opcode bytes:
 *   - [1] = wipe angle, in 1/256ths of a turn
 */
int vs_battle_script_6B_setScreenTransitionWipeAngle(u_char* script, UNUSED short slot)
{
    setScreenTransitionWipeAngle(script[1] * ONE / 256);

    return scriptNext;
}

/**
 * Sets the effect, speed and wipe angle of the screen transition, without starting one.
 * @param script Opcode bytes:
 *   - [1] = effect
 *   - [2] = speed
 *   - [3] = wipe angle, in 1/256ths of a turn
 */
int vs_battle_script_6C_setScreenTransition(u_char* script, UNUSED short slot)
{
    setScreenTransition(script[1], script[2], script[3] * ONE / 256);

    return scriptNext;
}

/**
 * Switches the screen, the room and the actors on or off. Each takes a 2-bit field of the
 * operand, 0 = off, 1 = on, 2 or 3 = leave as is.
 * @param script Opcode bytes:
 *   - [1] = bits 0-1 screen output, bits 2-3 room geometry, bits 4-5 all actors
 */
int vs_battle_script_6D_setSceneVisibility(u_char* script, UNUSED short slot)
{
    switch (script[1] & 3) {
    case 0:
        vs_battle_disableDispMask();
        break;
    case 1:
        vs_battle_enableDispMask();
        break;
    }

    switch ((script[1] >> 2) & 3) {
    case 0:
        hideCurrentRoom();
        break;
    case 1:
        showCurrentRoom();
        break;
    }

    switch ((script[1] >> 4) & 3) {
    case 0:
        disableAllActors();
        break;
    case 1:
        enableAllActors();
        break;
    }

    return scriptNext;
}

/**
 * Waits until the screen transition has finished.
 */
int vs_battle_script_6E_waitForScreenTransition(UNUSED u_char* script, UNUSED short slot)
{
    return getScreenTransitionPhase() != screenTransitionIdle ? scriptWait : scriptNext;
}

/**
 * Turns something unknown on (nonzero operand) or off. Both handlers are empty, so it has
 * no effect. Only used with [1] = 0xF6, in events 5, 14 and 15.
 */
int vs_battle_script_6F_setUnk(u_char* script, UNUSED short slot)
{
    if (script[1] != 0) {
        func_8007B104();
    } else {
        func_8007B0FC();
    }

    return scriptNext;
}

/**
 * Adds a colour offset to the palettes of actors, the scene or the background, either
 * at once or over a few frames.
 * @param script Opcode bytes:
 *   - [1] = target in the high nibble, 0 = actors, 1 = scene, 2 = background, and the
 *     colour transform mode in the low nibble, 8 = restore the original colours
 *   - [2-3] = actors to transform, if the target is actors
 *   - [4] = duration in frames as a power of two, 0 to 4, anything higher is instant
 *   - [5-7] = signed red, green and blue offsets
 */
int vs_battle_script_70_transformColors(u_char* script, UNUSED short slot)
{
    ActorList actors;

    switch (script[1] >> 4) {
    case 0:
        expandActorSelector(getShort(script + 2), &actors);
        while (1) {
            int actor = nextActor(&actors);

            if (actor == 1) {
                break;
            }

            transformActorColors(script[1] & 0xF, (1 << script[4]) & 0x1F, actor,
                (signed char)script[5], (signed char)script[6], (signed char)script[7]);
        }
        break;

    case 1:
        transformSceneColors(script[1] & 0xF, (1 << script[4]) & 0x1F,
            (signed char)script[5], (signed char)script[6], (signed char)script[7]);
        break;

    case 2:
        transformBackgroundColors(script[1] & 0xF, (1 << script[4]) & 0x1F,
            (signed char)script[5], (signed char)script[6], (signed char)script[7]);
        break;
    }

    return scriptNext;
}

/** Fades an actor out or in with a flash. Used in cutscenes when an actor teleports.
 * @param script Opcode bytes:
 *   - [1-2] = actor
 *   - [3] = 1 fades out, 2 fades in. 0 is not used by any script (renders invisible).
 */
int vs_battle_script_71_fadeActor(u_char* script, UNUSED short slot)
{
    fadeActor(resolveActorId(getShort(script + 1)), script[3]);

    return scriptNext;
}

static inline void setWeaponAnimating(int animating) { weaponAnimating = animating; }

/**
 * Makes Ashley draw or sheathe his weapon, waiting for the animation to finish. Does
 * nothing if his weapon was not drawn when the event began (state flag 0xAC).
 * Cutscenes sheathe at the start and draw again at the end.
 * @param script Opcode bytes:
 *   - [1] = 0 sheathes, 1 draws
 *   - [2] = 0 changes at once, 1 plays the quick animation the player uses, 2 plays
 *     a slower one seen only in cutscenes
 */
int vs_battle_script_72_drawSheatheAshleyWeapon(u_char* script, UNUSED short slot)
{
    if (weaponAnimating == 0) {
        int variantOffset;
        int animation;

        if (!getStateFlag(savedWeaponDrawn)) {
            return scriptNext;
        }

        setWeaponDrawn(0, weaponDrawnModes[script[1]]);

        if (scriptSkipMode == scriptSkipping || script[2] == 0) {
            u_short flags;

        applyAtOnce:
            flags = vs_battle_getActorFlags(0);
            vs_battle_setActorFlags(0, script[1] != 0
                                           ? flags | vsBattleActorFlagWeaponsVisible
                                           : flags & ~vsBattleActorFlagWeaponsVisible);
            func_8009D88C(0);

            return scriptNext;
        }

        variantOffset = (script[2] - 1) * 2;
        animation = (script[1] ^ 1) + 0x6D;

        vs_battle_setActorAnimation(0, variantOffset + animation, 0, 0xA);
        playWeaponSfx(0, script[1] ^ 1);
        setWeaponAnimating(1);

    } else {

        if (scriptSkipMode == scriptSkipping) {
            setWeaponAnimating(0);

            goto applyAtOnce;
        }

        if (vs_battle_getActorFlags(0) & 0x80) {
            vs_battle_setActorAnimation(0, script[1] != 0 ? 0x65 : 6, 0, 0xA);
            setWeaponAnimating(0);

            return scriptNext;
        }
    }

    return scriptWait;
}

/**
 * Shows or hides the background texture.
 * @param script Opcode bytes:
 *   - [1] = 0 == hide, !0 == show
 */
int vs_battle_script_73_setBackgroundVisible(u_char* script, UNUSED short slot)
{
    setBackgroundVisible(script[1]);

    return scriptNext;
}

/**
 * Starts loading the room's background image into a texture page slot.
 * @param script Opcode bytes:
 *   - [1] = texture page slot
 */
int vs_battle_script_74_loadBackground(u_char* script, UNUSED short slot)
{
    loadBackground(script[1]);

    return scriptNext;
}

/**
 * Waits until the background image started by opcode 74 has finished loading.
 */
int vs_battle_script_75_waitBackgroundLoad(UNUSED u_char* script, UNUSED short slot)
{
    return pollBackgroundLoad() == 0 ? scriptWait : scriptNext;
}

/**
 * Hides the background image and frees its texture page(s).
 */
int vs_battle_script_76_unloadBackground(UNUSED u_char* script, UNUSED short slot)
{
    unloadBackground();

    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

/**
 * Sets the particle effect, either at once or ramping over a number of frames.
 * The values are only a starting point, as they then drift within the limits set by the
 * room.
 * @param script Opcode bytes:
 *   - [1] = effect in the high nibble (0 none, 1 rain, 2 snow, 3 heavy snow, 4 dark
 *     particles rising from the floor), intensity in the low nibble
 *   - [2] = direction the particles are blown, 256 steps per turn
 *   - [3] = fall angle, 0x80 falls straight down
 *   - [4] = 0 sets the values at once, otherwise the number of frames to blend over
 */
int vs_battle_script_77_setParticleEffect(u_char* script, UNUSED short slot)
{
    setParticleEffect(script[1] >> 4);

    if (script[4] == 0) {

        particleTween.intensity = script[1] & 0xF;

        setParticleEffectIntensity(particleTween.intensity);

        particleTween.direction = script[2] * 16;
        particleTween.fallAngle = script[3] * 4 + ONE / 8;

        setParticleEffectDirection(particleTween.direction, particleTween.fallAngle);
    } else {
        int targetIntensity = script[1] & 0xF;
        short currentDirection = particleTween.direction;
        int directionDelta;

        particleTween.startIntensity = particleTween.intensity;
        particleTween.deltaIntensity = targetIntensity - particleTween.intensity;
        particleTween.deltaFallAngle = script[3] * 4 + ONE / 8 - particleTween.fallAngle;
        particleTween.startFallAngle = particleTween.fallAngle;

        directionDelta = script[2] * 16 - currentDirection;
        particleTween.startDirection = currentDirection;

        if (directionDelta < -ONE / 2) {
            directionDelta += ONE;
        } else if (directionDelta > ONE / 2) {
            directionDelta -= ONE;
        }

        particleTween.deltaDirection = directionDelta;
        particleTween.duration = script[4];
        particleTween.elapsed = 0;
    }

    return scriptNext;
}

/**
 * Stops or resumes the particle effect drifting within the room's limits.
 * @param script Opcode bytes:
 *   - [1] = 1 stops the drift, 0 resumes it
 */
int vs_battle_script_78_freezeParticleEffect(u_char* script, UNUSED short slot)
{
    setParticleEffectDrift(script[1] ^ 1);

    return scriptNext;
}

/**
 * Acquires or relinquishes control of the particle effect sound, such as the rain loop.
 * Scripts must call this before using 0x80 with bank 2.
 * @param script Opcode bytes:
 *   - [1] = !0 acquires control, 0 returns control
 */
int vs_battle_script_7A_setParticleEffectSoundScripted(u_char* script, UNUSED short slot)
{
    if (script[1] != 0) {

        if (particleEffectSoundScripted != 0) {
            return scriptNext;
        }

        particleEffectSoundScripted = roomHasNoSoundBank();

        if (particleEffectSoundScripted) {
            particleEffectSoundToRestore = setParticleEffectSound(-1);
        }

    } else if (particleEffectSoundScripted != 0) {
        setParticleEffectSound(particleEffectSoundToRestore);
        particleEffectSoundScripted = 0;
    }

    return scriptNext;
}

/**
 * Starts a room task, or pauses and resumes it. Room tasks run every frame, animating
 * textures, moving geometry objects and playing the room's sounds. Some start running
 * when the room loads.
 * @param script Opcode bytes:
 *   - [1] = 0 starts the task (if the same task is already executing it is completed
 *     first), 1 pauses or resumes
 *   - [2] = task index, with the room's scripted tasks starting at 0x40
 */
int vs_battle_script_79_controlRoomTask(u_char* script, UNUSED short slot)
{
    int task = script[2];

    switch (script[1]) {
    case 0:
        if ((scriptSkipMode == scriptSkipping) && (isRoomTaskRunning(task) != 0)) {
            finishRoomTask(task);
        }

        startRoomTask(task);
        break;

    case 1:
        toggleRoomTaskPaused(task);
        break;
    }

    return scriptNext;
}

/**
 * Offsets the background image loaded by opcode 74, in pixels.
 * @param script Opcode bytes:
 *   - [1..2] = horizontal offset (signed)
 *   - [3..4] = vertical offset (signed)
 */
int vs_battle_script_7B_setBackgroundOffset(u_char* script, UNUSED short slot)
{
    setBackgroundOffset(getShort(script + 1), getShort(script + 3));

    return scriptNext;
}

/**
 * Culls room geometry that occludes the view depending on the camera angle.
 * Usually disabled and renabled at the start and end of cutscenes.
 * @param script Opcode bytes:
 *   - [1] = 0 renders all geometry, anything else culls by camera angle
 */
int vs_battle_script_7C_cullOccludingGeometry(u_char* script, UNUSED short slot)
{
    cullOccludingGeometry(script[1] != 0);

    return scriptNext;
}

/**
 * Offsets the ordering table position of a geometry object. Can be undone by negating
 * the original amount.
 * @param script Opcode bytes:
 *   - [1] = geometry object index
 *   - [2] = amount to add (signed)
 */
int vs_battle_script_7D_adjustGeometryDepth(u_char* script, UNUSED short slot)
{
    adjustGeometryObjectDepth(script[1], (signed char)script[2]);

    return scriptNext;
}

/**
 * Sets how far the background image shifts as the camera turns and tilts.
 * @param script Opcode bytes:
 *   - [1] = shift for horizontal turning (signed)
 *   - [2] = shift for vertical tilting (signed)
 *   - [3] = unused
 */
int vs_battle_script_7E_setBackgroundParallax(u_char* script, UNUSED short slot)
{
    setBackgroundParallax(
        (signed char)script[1] * (ONE / 32), (signed char)script[2] * (ONE / 32));

    return scriptNext;
}

/**
 * Plays a sound effect. Group 2 is ignored unless opcode 7A has taken control of the
 * particle effect sound.
 * @param script Opcode bytes:
 *   - [1] = sound group: 1 = general sound effects, 2 = the particle effect sound,
 *     3 = effects from the bank selected by opcode 88
 *   - [2] = sound ID, or the index within the bank for group 3
 *   - [3] = pan, 0x80 is centre
 *   - [4] = volume, up to 0x7F
 */
int vs_battle_script_80_playSfx(u_char* script, UNUSED short slot)
{
    if (script[1] == 2 && particleEffectSoundScripted == 0) {
        return scriptNext;
    }

    if (script[1] == 2) {
        particleEffectSoundToRestore = script[2];
    }

    vs_main_playSfx(scriptSfxGroups[script[1]], script[2], script[3], script[4]);

    return scriptNext;
}

/**
 * Plays one of an actor's sound effects.
 * @param script Opcode bytes:
 *   - [1..2] = actor ID
 *   - [3] = sound effect type
 */
int vs_battle_script_81_playActorSfx(u_char* script, UNUSED short slot)
{
    playActorSfx(resolveActorId(getShort(script + 1)), script[3]);

    return scriptNext;
}

/**
 * Fades a sound effect to a volume. An ID of 0 fades every sound in the group.
 * @param script Opcode bytes:
 *   - [1] = sound group, as in opcode 80
 *   - [2] = sound ID
 *   - [3] = target volume
 *   - [4] = fade duration
 */
int vs_battle_script_82_fadeSfxVolume(u_char* script, UNUSED short slot)
{
    vs_main_fadeSfxVolume(scriptSfxGroups[script[1]], script[2], script[3], script[4]);

    return scriptNext;
}

/** Stops all sound effects. */
int vs_battle_script_83_stopAllSfx(UNUSED u_char* script, UNUSED short slot)
{
    vs_main_stopAllSfx();

    return scriptNext;
}

/**
 * Stops a sound effect. An ID of 0 stops every sound in the group.
 * @param script Opcode bytes:
 *   - [1] = sound group, as in opcode 80
 *   - [2] = sound ID
 */
int vs_battle_script_84_stopSfx(u_char* script, UNUSED short slot)
{
    vs_main_stopSfx(scriptSfxGroups[script[1]], script[2]);

    return scriptNext;
}

/**
 * Starts loading a sound effect file from disc into a slot. Opcode 86 waits for the
 * load to finish.
 * @param script Opcode bytes:
 *   - [1] = sound effect file ID
 *   - [2] = slot, 1 to 3
 */
int vs_battle_script_85_loadSfxSlot(u_char* script, UNUSED short slot)
{
    vs_main_loadSfxSlot(script[1], script[2]);

    return scriptNext;
}

/**
 * Waits until the sound effect file being loaded into a slot by opcode 85 is ready.
 * @param script Opcode bytes:
 *   - [1] = slot, 1 to 3
 */
int vs_battle_script_86_waitSfxLoad(u_char* script, UNUSED short slot)
{
    return vs_main_finishSfxLoad(script[1]) != 0 ? scriptWait : scriptNext;
}

/**
 * Stops the sounds from a slot's sound effect file and unloads it.
 * @param script Opcode bytes:
 *   - [1] = slot, 1 to 3
 */
int vs_battle_script_87_freeSfx(u_char* script, UNUSED short slot)
{
    vs_main_freeSfx(script[1]);

    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

/**
 * Selects the loaded sound effect slot that sound group 3 plays from.
 * @param script Opcode bytes:
 *   - [1] = slot, 1 to 3
 */
int vs_battle_script_88_setCurrentSfx(u_char* script, UNUSED short slot)
{
    vs_main_setCurrentSfx(script[1]);

    return scriptNext;
}

/**
 * Starts loading the area's music into music slot 3, along with its instrument bank.
 * Scripts use it to bring the area music back after a cutscene track.
 */
int vs_battle_script_89_loadAreaMusic(UNUSED u_char* script, UNUSED short slot)
{
    short musicId = func_80089104();
    vs_main_loadMusicSlot(musicId, 3);
    vs_main_loadInstrumentBank(musicId);

    return scriptNext;
}

/**
 * Fades out the current script music and fades in the music in another slot.
 * @param script Opcode bytes:
 *   - [1] = music slot to play
 *   - [2] = volume
 *   - [3] = fade in duration
 *   - [4] = fade out duration
 */
int vs_battle_script_8F_crossfadeMusic(u_char* script, UNUSED short slot)
{
    vs_main_fadeMusicVolume(scriptMusicSlot, 0, script[4]);
    vs_main_playMusicSlotFadeIn(scriptMusicSlot = script[1], script[2], script[3]);

    return scriptNext;
}

/**
 * Starts loading a music track from disc into a music slot. Opcode 99 waits for the
 * load to finish.
 * @param script Opcode bytes:
 *   - [1] = music ID
 *   - [2] = slot, 1 to 4
 */
int vs_battle_script_90_loadMusicSlot(u_char* script, UNUSED short slot)
{
    vs_main_loadMusicSlot(script[1], script[2]);

    return scriptNext;
}

/**
 * Stops the music in a slot and unloads it.
 * @param script Opcode bytes:
 *   - [1] = slot, 1 to 4
 */
int vs_battle_script_91_freeMusic(u_char* script, UNUSED short slot)
{
    vs_main_freeMusic(script[1]);

    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

/**
 * Plays the music in a slot.
 * @param script Opcode bytes:
 *   - [1] = slot, 1 to 4
 *   - [2] = volume
 *   - [3] = fade duration
 */
int vs_battle_script_92_playMusic(u_char* script, UNUSED short slot)
{
    vs_main_playMusicSlot(scriptMusicSlot = script[1], script[2], script[3]);

    return scriptNext;
}

/**
 * Fades the script music's volume.
 * @param script Opcode bytes:
 *   - [1] = target volume
 *   - [2] = fade duration
 */
int vs_battle_script_93_fadeMusicVolume(u_char* script, UNUSED short slot)
{
    vs_main_fadeMusicVolume(scriptMusicSlot, script[1], script[2]);

    return scriptNext;
}

/**
 * Ramps the script music's tempo.
 * @param script Opcode bytes:
 *   - [1] = target tempo adjustment (signed), 0 leaves the tempo unchanged, negative is
 *     slower and positive is faster
 *   - [2] = ramp duration
 */
int vs_battle_script_94_rampMusicTempo(u_char* script, UNUSED short slot)
{
    vs_main_rampMusicTempo(scriptMusicSlot, (signed char)script[1], script[2]);

    return scriptNext;
}

/**
 * Ramps the script music's pitch.
 * @param script Opcode bytes:
 *   - [1] = target pitch (signed)
 *   - [2] = ramp duration
 */
int vs_battle_script_95_rampMusicPitch(u_char* script, UNUSED short slot)
{
    vs_main_rampMusicPitch(scriptMusicSlot, (signed char)script[1], script[2]);

    return scriptNext;
}

/**
 * Stops the script music.
 */
int vs_battle_script_96_stopMusic(UNUSED u_char* script, UNUSED short slot)
{
    vs_main_stopMusicSlot(scriptMusicSlot);

    return scriptNext;
}

/**
 * Waits until the music in a slot has faded to silence.
 * @param script Opcode bytes:
 *   - [1] = slot, 1 to 4
 */
int vs_battle_script_97_waitMusicSilent(u_char* script, UNUSED short slot)
{
    int musicSlot = script[1];

    if (vs_main_getMusicSlotVolume2(musicSlot) != 0) {
        if (vs_main_getMusicSlotVolume(musicSlot) != 0) {
            return scriptWait;
        }

        vs_main_stopMusicSlot(musicSlot);
    }

    return scriptNext;
}

/**
 * Saves a copy of the playing music's state.
 */
int vs_battle_script_98_pushMusicState(UNUSED u_char* script, UNUSED short slot)
{
    vs_main_pushMusicState();

    return scriptNext;
}

/**
 * Waits until the music being loaded into a slot by opcode 90 is ready.
 * @param script Opcode bytes:
 *   - [1] = slot, 1 to 4
 */
int vs_battle_script_99_waitMusicLoad(u_char* script, UNUSED short slot)
{
    return vs_main_finishMusicLoad(script[1]) == 1 ? scriptWait : scriptNext;
}

/**
 * Starts loading the instrument bank a music track plays with, unless it is already
 * loaded. Opcode 9E waits for it to be ready.
 * @param script Opcode bytes:
 *   - [1] = music ID
 */
int vs_battle_script_9D_loadInstrumentBank(u_char* script, UNUSED short slot)
{
    vs_main_loadInstrumentBank(script[1]);
    return scriptNext;
}

/** Waits until the instrument bank started by opcode 9D or 89 is loaded and ready. */
int vs_battle_script_9E_waitInstrumentBankLoad(UNUSED u_char* script, UNUSED short slot)
{
    return vs_main_processInstrumentBankLoad() == 1 ? scriptWait : scriptNext;
}

/**
 * Waits until the music has played up to a bar.
 * @param script Opcode bytes:
 *   - [1..2] = bar number
 */
int vs_battle_script_9A_waitMusicBar(u_char* script, UNUSED short slot)
{
    int bar = vs_main_getMusicPosition() >> 0x10;

    return bar < getShort(script + 1) ? scriptWait : scriptNext;
}

/**
 * Ramps a sound effect's pitch. An ID of 0 ramps every sound in the group.
 * @param script Opcode bytes:
 *   - [1] = sound group, as in opcode 80
 *   - [2] = sound ID
 *   - [3] = target pitch (signed)
 *   - [4] = ramp duration
 */
int vs_battle_script_9B_rampSfxPitch(u_char* script, UNUSED short slot)
{
    vs_main_rampSfxPitch(
        scriptSfxGroups[script[1]], script[2], (signed char)script[3], script[4]);

    return scriptNext;
}

/**
 * Ramps a sound effect's pan. An ID of 0 ramps every sound in the group.
 * @param script Opcode bytes:
 *   - [1] = sound group, as in opcode 80
 *   - [2] = sound ID
 *   - [3] = target pan, 0x80 is centre
 *   - [4] = ramp duration
 */
int vs_battle_script_9C_rampSfxPan(u_char* script, UNUSED short slot)
{
    vs_main_rampSfxPan(scriptSfxGroups[script[1]], script[2], script[3], script[4]);

    return scriptNext;
}

/**
 * Queues the script music to start once the current music reaches its end.
 * @param script Opcode bytes:
 *   - [1] = slot, 1 to 4
 */
int vs_battle_script_9F_queueMusic(u_char* script, UNUSED short slot)
{
    vs_main_queueMusicSlot(scriptMusicSlot = script[1]);

    return scriptNext;
}

/**
 * Loads and starts a visual effect (EFFECT/E###.P: sprites, particles, camera and sound,
 * as used for spell animations) targeting an actor. Its stages are started by opcode
 * A1.
 * @param script Opcode bytes:
 *   - [1-2] = effect ID
 *   - [3-4] = target actor
 */
int vs_battle_script_A0_startEffect(u_char* script, UNUSED short slot)
{
    startEffect(getShort(script + 1), resolveActorId(getShort(script + 3)));

    return scriptNext;
}

/**
 * Starts one stage of the visual effect. When skipping, cancels the effect instead.
 * @param script Opcode bytes:
 *   - [1] = stage index
 */
int vs_battle_script_A1_triggerEffectStage(u_char* script, UNUSED short slot)
{
    triggerEffectStage(script[1]);

    if (scriptSkipMode == scriptSkipping) {
        cancelEffects();
    }

    return scriptNext;
}

/**
 * Waits until the visual effect system is in the given state. Scripts use it to wait for
 * the effect to finish, or to be ready for its next stage. Skipping cancels the effect
 * first.
 * @param script Opcode bytes:
 *   - [1] = state to wait for
 */
int vs_battle_script_A2_waitEffectState(u_char* script, UNUSED short slot)
{
    if ((scriptSkipMode == scriptSkipping) && ((script[1] == 0) || (script[1] == 5))) {

        if (effectCancelled != 0) {
            if (getEffectState() == script[1]) {
                effectCancelled = 0;
                return scriptNext;
            }
        } else {
            cancelEffects();
            effectCancelled = 1;
        }

        return scriptWait;
    }

    return getEffectState() != script[1] ? scriptWait : scriptNext;
}

/**
 * Yields for a frame while skipping, otherwise does nothing.
 * @param script Opcode bytes: none
 */
int vs_battle_script_A3_yieldIfSkipping(UNUSED u_char* script, UNUSED short slot)
{
    effectNop();

    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

/**
 * Waits until the visual effect is loaded and has stages left to trigger.
 * @param script Opcode bytes: none
 */
int vs_battle_script_A4_waitEffectStageReady(UNUSED u_char* script, UNUSED short slot)
{
    return isEffectStageReady() != 1 ? scriptWait : scriptNext;
}

/**
 * Cancels the running visual effect and waits until the effect system is idle or
 * waiting for a stage to be triggered.
 * @param script Opcode bytes: none
 */
int vs_battle_script_A5_cancelEffect(UNUSED u_char* script, UNUSED short slot)
{
    if (effectCancelled == 0) {
        cancelEffects();
        effectCancelled = 1;
    } else if ((getEffectState() == 0) || (getEffectState() == 5)) {
        effectCancelled = 0;
        return scriptNext;
    }

    return scriptWait;
}

/**
 * Makes a stage that was already triggered available to trigger again.
 * @param script Opcode bytes:
 *   - [1] = stage index
 */
int vs_battle_script_A6_rearmEffectStage(u_char* script, UNUSED short slot)
{
    rearmEffectStage(script[1]);

    return scriptNext;
}

/**
 * Sets the cue the playing music should reach. The music does not jump at once, but
 * takes its own route there at its next branch point.
 * @param script Opcode bytes:
 *   - [1] = cue
 */
int vs_battle_script_A8_setMusicTargetCue(u_char* script, UNUSED short slot)
{
    vs_main_setMusicTargetCue(script[1]);

    return scriptNext;
}

/**
 * Starts a controller vibration pattern from the script's pattern table, or stops
 * vibration. Adding 8 to the index copies the pattern before playing.
 * @param script Opcode bytes:
 *   - [1] = pattern index, or 0xFF to stop vibration
 */
int vs_battle_script_A9_playVibration(u_char* script, UNUSED short slot)
{
    short pattern = script[1];

    if (pattern == 0xFF) {
        vs_main_stopVibration(0, 2);
    } else if (pattern & 8) {
        vs_main_memcpy(vibrationPatternCopy, vibrationPatterns[pattern & 7], 0x80);
        vs_main_setVibrationBank(vibrationPatternCopy + 8, 0xFF, 2);
    } else if (vibrationPatterns[pattern] != NULL) {
        vs_main_setVibrationBank(vibrationPatterns[pattern] + 8, 0xFF, 2);
    }

    return scriptNext;
}

/**
 * Starts or stops a motion trail following one of an actor's bones. Stopping fades out
 * every active trail, not only the actor's.
 * @param script Opcode bytes:
 *   - [1] = 1 to start, 0 to stop
 *   - [2-3] = actor
 *   - [4] = bone
 */
int vs_battle_script_AA_setActorTrail(u_char* script, UNUSED short slot)
{
    short actor = resolveActorId(getShort(script + 2));

    if (script[1] != 0) {
        startActorTrail(actor, script[4]);
    } else {
        stopActorTrails(actor, script[4]);
    }

    return scriptNext;
}

/**
 * Overrides which door the player entered the room through.
 * @param script Opcode bytes:
 *   - [1] = door index
 */
int vs_battle_script_B1_setEnteredDoor(u_char* script, UNUSED short slot)
{
    setEnteredDoor(script[1]);

    return scriptNext;
}

/**
 * Stores the distance and angle between two actors in two consecutive state flags.
 * @param script Opcode bytes:
 *   - [1-2] = first actor
 *   - [3-4] = second actor
 *   - [5] = distance scale
 *   - [6-7] = state flag id for the distance, the angle is placed in the following flag
 */
int vs_battle_script_B2_setFlagsToActorDistanceAndAngle(u_char* script, UNUSED short slot)
{
    vs_ActorPosition first;
    vs_ActorPosition second;
    short dx;
    short dz;
    int distance;

    short flag = getShort(script + 6);
    vs_battle_getActorPosition(resolveActorId(getShort(script + 1)), &first);
    vs_battle_getActorPosition(resolveActorId(getShort(script + 3)), &second);

    dx = first.unk0.unk4.vx - second.unk0.unk4.vx;
    dz = first.unk0.unk4.vz - second.unk0.unk4.vz;
    distance = SquareRoot0((dx * dx) + (dz * dz)) / script[5];

    vs_battle_setStateFlag(flag, distance < ONE / 16 ? distance : -1);
    vs_battle_setStateFlag(flag + 1, ratan2(dx, dz) >> 4);

    return scriptNext;
}

/**
 * Wakes the selected actors, or puts them into the dormant state.
 * @param script Opcode bytes:
 *   - [1-2] = actor selector
 *   - [3] = 0 = dormant, nonzero = awake
 */
int vs_battle_script_B3_setActorAwake(u_char* script, UNUSED short slot)
{
    ActorList actors;

    expandActorSelector(getShort(script + 1), &actors);

    while (1) {
        int actor = nextActor(&actors);

        if (actor == 1) {
            break;
        }

        setActorAwake(actor, script[3]);
    }

    return scriptNext;
}

/**
 * Shows the loot screen with up to two consumable or key items and waits for it to
 * close. An item id of 0 leaves that item out. No script uses this opcode.
 * @param script Opcode bytes:
 *   - [1-2] = first item id
 *   - [3] = first item count
 *   - [4-5] = second item id
 *   - [6] = second item count
 */
int vs_battle_script_B4_showMiscLoot(u_char* script, UNUSED short slot)
{
    if (scriptMenuState == scriptMenuClosed) {
        showMiscLoot(getShort(script + 1), script[3], getShort(script + 4), script[6]);
        scriptMenuState = scriptMenuOpen;

        return scriptWait;
    }

    if (updateScriptMenu() == 0) {
        scriptMenuState = scriptMenuClosed;

        return scriptYield;
    }

    return scriptWait;
}

/**
 * Removes one of a misc item from the inventory.
 * @param script Opcode bytes:
 *   - [1-2] = item id
 */
int vs_battle_script_B5_removeMiscItem(u_char* script, UNUSED short slot)
{
    removeMiscItem(getShort(script + 1));

    return scriptNext;
}

/**
 * Stores the distance between two actors, in whole tiles, in a state flag.
 * @param script Opcode bytes:
 *   - [1-2] = first actor
 *   - [3-4] = second actor
 *   - [5-6] = state flag id
 */
int vs_battle_script_B6_setFlagToActorDistance(u_char* script, UNUSED short slot)
{
    vs_ActorPosition first;
    vs_ActorPosition second;
    short dx;
    short dz;

    vs_battle_getActorPosition(resolveActorId(getShort(script + 1)), &first);
    vs_battle_getActorPosition(resolveActorId(getShort(script + 3)), &second);

    dx = first.unk0.unk4.vx - second.unk0.unk4.vx;
    dz = first.unk0.unk4.vz - second.unk0.unk4.vz;

    vs_battle_setStateFlag(
        getShort(script + 5), SquareRoot0((dx * dx) + (dz * dz)) / 128);

    return scriptNext;
}

/**
 * Enables and wakes every actor except Ashley, or disables them and makes them dormant.
 * @param awake Nonzero = enable and wake, 0 = disable and make dormant.
 */
void setAllActorsEnabledAndAwake(short awake)
{
    short actorId;

    for (actorId = 1; actorId < 17; ++actorId) {
        if (getActor(actorId) != NULL) {
            if (awake != 0) {
                vs_battle_setActorFlags(actorId, vs_battle_getActorFlags(actorId) | 1);
            } else {
                vs_battle_setActorFlags(actorId, vs_battle_getActorFlags(actorId) & ~1);
            }
        }
    }

    setActorsAwake(awake);
}

/**
 * Runs one of a set of miscellaneous scene commands, chosen by the sub-opcode.
 * @param script Opcode bytes:
 *   - [1] = sub-opcode
 *   - [2] = argument, if the sub-opcode takes one
 *   - [3-5] = unused, the script resumes at [6]
 */
int vs_battle_script_B7_specialOp(u_char* script, UNUSED short slot)
{
    enum {
        // Starts loading an SHP model. [2] = model id. Unused.
        specialLoadShp = 0,
        // Shows the ending, and returns to the title.
        specialShowEnding = 1,
        // Skips the scene as if the player had pushed start.
        specialSkipScene = 2,
        // Unlocks an action and sets flag 0xB1 to 1 if it was locked, else 0. [2] =
        // action.
        specialUnlockAction = 3,
        // Sets flag 0xB1 to the number of engaged enemies.
        specialCountEngagedEnemies = 4,
        // Enables and wakes every actor except Ashley, or disables them and makes them
        // dormant. [2] = 1 to enable, 0 to disable.
        specialSetAllActorsEnabledAndAwake = 5,
        // Frees the next EVT file queued by opcode F7 without running it.
        specialDiscardNextEvt = 6,
        // Makes the scripted camera follow Ashley with the gameplay camera's view. [2] =
        // 1 to follow, 0 to stop.
        specialSetCameraFollowsAshley = 7,
        // Pauses or resumes the battle timer. [2] = 1 to pause, 0 to resume.
        specialPauseBattleTimer = 8,
        // Sweeps the camera into the player view saved before the scene.
        // [2] = sweep from left or right.
        specialSweepCameraToSavedPlayerView = 9,
        // Sets the pitch of the gameplay camera. [2] = 1 shallow, 2 steep, else the
        // default.
        specialSetCameraPitchPreset = 10,
        // Scales the duration of a running camera move by the distance it has left.
        // [2] = the move to scale: 0 look-at, 1 eye, 2 both. Unused.
        specialScaleCameraMoveDurationByDistance = 11,
        // Freezes the cloudstones, then thaws them. [2] = ticks, 0 thaws
        // immediately (scripts only seem to use 0).
        specialSetCloudstoneFreezeTimer = 12,
        // Shows the geometry hidden by the view culling. Unused.
        specialClearCulledGeometry = 13,
        // Stops the cloudstones indefintely. [2] = 1 to stop, 0 to resume.
        specialSetCloudstonesPaused = 14,
        // Toggles the bright haze around the edges of the screen.
        // [2] = 1 for on, 0 for off.
        specialSetScreenEdgeGlow = 15,
        // Runs the scene reset script, then continues with the next opcode.
        specialRunSceneReset = 16,
        // Stops the room being marked as seen on the map.
        specialSkipRoomSeen = 17,
    };

    char message[32];

    switch (script[1]) {
    case specialLoadShp:
        queueShpLoad(script[2]);
        break;

    case specialShowEnding:
        if (scriptMenuState != scriptMenuClosed) {

            if (updateScriptMenu() != 0) {
                return scriptWait;
            }

            vs_battle_setStateFlag(menuFSubmenu, 0);

            scriptMenuState = scriptMenuClosed;

            vs_main_showEndingAndReturnToTitle();

            break;
        }

        vs_battle_setStateFlag(menuFSubmenu, menuFHealBonus);
        func_8007B9A0();

        scriptMenuState = scriptMenuOpen;

        return scriptWait;

    case specialSkipScene:
        skipRequested = 1;
        break;

    case specialUnlockAction:
        if (isActionUnlocked(script[2]) != 0) {
            vs_battle_setStateFlag(specialOpResult, 0);
        } else {
            setActionUnlocked(script[2]);
            vs_battle_setStateFlag(specialOpResult, 1);
        }
        break;

    case specialCountEngagedEnemies:
        vs_battle_setStateFlag(specialOpResult, countActorsByRole(actorRoleEngagedEnemy));
        break;

    case specialSetAllActorsEnabledAndAwake:
        setAllActorsEnabledAndAwake(script[2]);
        break;

    case specialDiscardNextEvt:
        vs_main_freeHeapR(nextEvtBuffer);
        break;

    case specialSetCameraFollowsAshley:
        setCameraFollowsAshley(script[2]);
        break;

    case specialPauseBattleTimer:
        pauseBattleTimer(script[2]);
        break;

    case specialSweepCameraToSavedPlayerView:
        sweepCameraToSavedPlayerView(script[2]);
        break;

    case specialSetCameraPitchPreset:
        setCameraPitchPreset(cameraPitchPresets[script[2]]);
        break;

    case specialScaleCameraMoveDurationByDistance:
        scaleCameraMoveDurationByDistance(script[2]);
        break;

    case specialSetCloudstoneFreezeTimer:
        setCloudstoneFreezeTimer(script[2]);
        break;

    case specialClearCulledGeometry:
        clearCulledGeometry();
        break;

    case specialSetCloudstonesPaused:
        setCloudstonesPaused(script[2]);
        break;

    case specialSetScreenEdgeGlow:
        setScreenEdgeGlow(script[2]);
        break;

    case specialRunSceneReset:
        scriptReturnAddress = (long)(script + 6);
        return (long)&sceneResetScript;

    case specialSkipRoomSeen:
        skipRoomSeen();
        break;

    default:
        sprintf(message, "<SPECIAL=%d> IS UNDEFINED!", script[1]);
        break;
    }

    return scriptNext;
}

/**
 * Waits until the screen effects overlay, started by opcode BC, has finished loading.
 */
int vs_battle_script_B8_waitScreenEffectsLoaded(UNUSED u_char* script, UNUSED short slot)
{
    if ((screenEffects != NULL) && (screenEffects->loading != 0)) {
        return scriptWait;
    }

    return scriptNext;
}

/**
 * Blurs the screen from a given depth in the drawing order, or turns the blur off.
 * Needs the screen effects overlay loaded by opcode BC.
 * @param script Opcode bytes:
 *   - [1-2] = depth in the ordering table, 0 = off
 */
int vs_battle_script_BB_setScreenBlur(u_char* script, UNUSED short slot)
{
    setScreenBlurDepth(getShort(script + 1));

    return scriptNext;
}

/**
 * Starts loading the screen effects overlay (SCREFF2.PRG).
 */
int vs_battle_script_BC_loadScreenEffects(UNUSED u_char* script, UNUSED short slot)
{
    loadScreenEffects();

    return scriptNext;
}

/**
 * Does nothing. Only the room scripts of MAP101 and MAP213 use it, with the byte 0x0C,
 * right after setEnteredDoor.
 */
int vs_battle_script_BD_nop(UNUSED u_char* script, UNUSED short slot)
{
    return scriptNext;
}

/**
 * Releases the screen effects overlay.
 */
int vs_battle_script_BE_unloadScreenEffects(UNUSED u_char* script, UNUSED short slot)
{
    unloadScreenEffects();

    return (scriptSkipMode == scriptSkipping) ? scriptYield : scriptNext;
}

/**
 * Interrupts camera movement and drops the momentum carried over from the last move
 * (see opcode DF).
 * @param script Opcode bytes:
 *   - [1] = unused
 */
int vs_battle_script_DE_stopCamera(UNUSED u_char* script, UNUSED short slot)
{
    stopCamera();

    return scriptNext;
}

/**
 * Chooses whether the camera carries its speed over from the end of a move into the
 * next one: it keeps going past the target and curves into the next move instead of
 * stopping first.
 * @param script Opcode bytes:
 *   - [1] = bit 0 for the look-at, bit 1 for the eye
 */
int vs_battle_script_DF_setCameraMomentum(u_char* script, UNUSED short slot)
{
    int eye = script[1] & 2;
    setCameraMomentum(script[1] & 1, eye != 0);

    return scriptNext;
}

/**
 * Attaches the camera to an actor.
 * @param script Opcode bytes:
 *   - [1-2] = actor id, 0x2000 = detach
 */
int vs_battle_script_E8_attachCameraToActor(u_char* script, UNUSED short slot)
{
    attachCameraToActor(resolveActorId(getShort(script + 1)));

    return scriptNext;
}

/**
 * Moves the camera back to the gameplay view of Ashley, optionally turning it to a new
 * facing and zoom. To restore the view saved before the scene, see
 * sweepCameraToSavedPlayerView (special opcode B7, sub-opcode 9).
 * @param script Opcode bytes:
 *   - [1] = facing of the camera in 45 degree steps, 0xFF = unchanged
 *   - [2] = zoom, 1 = normal, 2 = zoomed out, 0 = unchanged
 */
int vs_battle_script_E9_returnToGameplayCamera(u_char* script, UNUSED short slot)
{
    returnToGameplayCamera(
        script[1] != 0xFF ? ((script[1] + 4) & 7) : -1, script[2] != 0 ? script[2] : -1);

    cameraReturned = 1;

    return scriptNext;
}

/**
 * Waits until the camera channels in a mask have finished moving, see getCameraIdleFlags.
 * The look-at and eye moves are started by vs_battle_script_Cx_Dx_camera.
 * @param script Opcode bytes:
 *   - [1] = mask of the channels to wait for
 */
int vs_battle_script_E0_waitCameraIdle(u_char* script, UNUSED short slot)
{
    return script[1] != (script[1] & getCameraIdleFlags()) ? scriptWait : scriptNext;
}

/**
 * Turns the frame buffer effect on or off.
 * @param script Opcode bytes:
 *   - [1] = 1 for on, 0 for off
 */
int vs_battle_script_E1_setFramebufferEffect(u_char* script, UNUSED short slot)
{
    setFramebufferEffect(script[1]);

    return scriptNext;
}

/**
 * Waits for a number of frames.
 * @param script Opcode bytes:
 *   - [1] = frames to wait, must not be 0
 * @param slot Script slot running the opcode.
 */
int vs_battle_script_F0_waitFrames(u_char* script, short slot)
{
    if (scriptWaitFrames[slot] == 0) {
        scriptWaitFrames[slot] = script[1];

        return scriptWait;
    }

    --scriptWaitFrames[slot];

    if ((scriptWaitFrames[slot] << 0x10) <= 0) {
        scriptWaitFrames[slot] = 0;

        return scriptNext;
    }

    return scriptWait;
}

/**
 * Sets the frame rate, see setFrameRate.
 * @param script Opcode bytes:
 *   - [1] = 2 for full rate, 4 for half, else ignored
 */
int vs_battle_script_F1_setFrameRate(u_char* script, UNUSED short slot)
{
    setFrameRate(script[1]);

    return scriptNext;
}

/**
 * Toggles the scanline effect, see drawScanlines.
 * @param script Opcode bytes:
 *   - [1] = 1 for on, 0 for off
 */
int vs_battle_script_F3_setScanlines(u_char* script, UNUSED short slot)
{
    scanlinesEnabled = script[1];

    return scriptNext;
}

/**
 * Joins the code forked into a script slot by opcode F5.
 * @param script Opcode bytes:
 *   - [1] = slot in the low 2 bits, bit 7 set to stop the slot instead of waiting
 */
int vs_battle_script_F4_joinScript(u_char* script, UNUSED short slot)
{
    u_short joinSlot = script[1] & 3;

    if ((script[1] & 0x80)) {
        scriptSlots[joinSlot] = 0;

        return scriptNext;
    }

    return scriptSlots[joinSlot] != 0 ? scriptWait : scriptNext;
}

/**
 * Starts the script immediately following this opcode in a separate script slot,
 * and jumps the current script ahead.
 * @param script Opcode bytes:
 *   - [1] = slot to run the forked script in, 1 to 3
 *   - [2-3] = Current script continues from this offset
 */
int vs_battle_script_F5_forkAndJump(u_char* script, UNUSED short slot)
{
    scriptSlots[script[1]] = script + 4;

    return (long)&script[getShort(script + 2)];
}

/**
 * Ends the current script. In practice only used by forked scripts.
 * @param script Opcode bytes:
 *   - [1] = slot identifier, unused
 */
int vs_battle_script_F6_endScript(UNUSED u_char* script, UNUSED short slot)
{
    return scriptEnd;
}

/**
 * Starts loading an EVT file to continue into once the running script ends.
 * @param script Opcode bytes:
 *   - [1-2] = EVT file number
 */
int vs_battle_script_F7_queueNextEvt(u_char* script, UNUSED short slot)
{
    evtFile = getShort(script + 1);
    nextEvtBuffer = vs_main_allocHeapR(0x1800);

    loadEvt(evtFile, nextEvtBuffer);

    nextEvtQueued = 1;

    return scriptNext;
}

/**
 * Waits until every text box has closed, then ends the scene.
 * Restores the full frame rate. No discernable difference in usage
 * between 0xFE and 0xFF.
 */
int vs_battle_script_FE_FF_endScene(UNUSED u_char* script, UNUSED short slot)
{
    int i;
    int boxesClosing = 0;

    for (i = 0; i < 8; ++i) {
        if (vs_battle_dismissTextBox(i) != 0) {
            ++boxesClosing;
        }
    }

    if (boxesClosing == 0) {
        setFrameRate(frameRateFull);

        return scriptFinish;
    }

    return scriptWait;
}

/**
 * Plays the menu select sound effect. Unused.
 * @param script Opcode bytes:
 *   - [1-4] = unused
 */
int vs_battle_script_F2_playMenuSelectSfx(UNUSED u_char* script, UNUSED short slot)
{
    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
    return scriptNext;
}

/**
 * 0x2001 selects every actor and 0x2003 selects only the engaged enemies. Any other
 * selector < 0x2000 is a single actor, see resolveActorId.
 * @param selector Actor selector.
 * @param list List to fill in, to be read with nextActor.
 */
void expandActorSelector(u_short selector, ActorList* list)
{
    short count = 0;

    list->remaining = 0;
    list->next = 0;

    if (selector & actorSelectorAll) {
        short i;
        short role = -1;

        if (selector == 0x2003) {
            role = actorRoleEngagedEnemy;
        }

        for (i = 0; i < 17; ++i) {

            Actor* actor = getActor(i);

            if ((actor != NULL) && ((role < 0) || (actor->role == role))) {
                list->actors[count++] = i;
                ++list->remaining;
            }
        }

        return;
    }

    ++list->remaining;
    list->actors[0] = resolveActorId(selector);
}

/**
 * Takes the next actor from a list filled in by expandActorSelector.
 * @return The actor id, or 1 once the list is empty.
 */
u_short nextActor(ActorList* list)
{
    if (list->remaining == 0) {
        return 1;
    }

    --list->remaining;

    return list->actors[(u_int)(list->next++)];
}

/**
 * Gets an actor's position on the screen, and the angle on the screen of the actor's
 * up direction. Uses the middle of bone 1.
 * @param actorId Actor id.
 * @param position Receives x and y in `vx` and `vy`, and the angle in `vz`.
 * @return The angle.
 */
int getActorScreenPositionAndUpAngle(int actorId, SVECTOR* position)
{
    MATRIX boneMatrix;
    long scratch[5];

    setVector(position, 0, -1000, 0);

    getBoneMatrixById(actorId, 1, &boneMatrix, &scratch[2]);
    SetRotMatrix(&boneMatrix);
    SetTransMatrix(&boneMatrix);
    RotTransPers(position, scratch, &scratch[3], &scratch[4]);
    getActorScreenPoint(actorId, 1, position, scratch[2]);

    position->vz =
        ratan2((scratch[0] >> 16) - position->vy, (short)scratch[0] - position->vx);

    return position->vz;
}

/**
 * Renders an interlaced scanline effect.
 */
void drawScanlines(void)
{
    LINE_F2* prim;
    DR_TPAGE* tpage;
    short y;

    vs_Scratch* scratch = VS_SCRATCH;
    prim = scratch->nextPrim;

    ++scanlinePhase;

    for (y = 0; y < vs_main_screenHeight; ++y) {
        u_int shade = (((y + (scanlinePhase >> 1)) & 1) << 5);
        u_short color = shade;

        if (shade != 0) {
            SetLineF2(prim);

            prim->r0 = prim->g0 = prim->b0 = color;

            setSemiTrans(prim, 1);

            prim->x0 = 0;
            prim->y0 = prim->y1 = y;
            prim->x1 = vs_main_screenWidth;

            scratch = VS_SCRATCH;
            AddPrim(scratch->frontOt, prim++);
        }
    }

    tpage = (DR_TPAGE*)prim;
    SetDrawTPage(tpage, 1, 1, GetTPage(0, 2, 0, 0));

    scratch = VS_SCRATCH;
    AddPrim(scratch->frontOt, tpage++);
    scratch->nextPrim = tpage;
}

/** Steps the tweens of the GIM images by a frame. */
static void updateGimTweens(void)
{
    short i;
    GimTween* tween = gimTweens;
    Gim* gim = gims;

    for (i = 0; i < 3; ++i, ++tween, ++gim) {
        short progress;

        if (tween->duration == 0) {
            continue;
        }

        tween->elapsed += vs_gametime_vblanksPerFrame >> 1;
        progress = evaluateEasing(tween->curve, tween->elapsed, tween->duration);

        if (gims != NULL) {
            gim->x = (tween->startX + ((tween->deltaX * progress) >> 12));
            gim->y = (tween->startY + ((tween->deltaY * progress) >> 12));
            gim->scale = (tween->startScale + ((tween->deltaScale * progress) >> 12));
            gim->brightness =
                tween->startBrightness + ((tween->deltaBrightness * progress) >> 12);
        }

        if (tween->elapsed >= tween->duration) {
            tween->duration = 0;
        }
    }
}

/** Steps the particle effect tween by a frame. */
static void updateParticleTween(void)
{
    short progress;

    if (particleTween.duration == 0) {
        return;
    }

    progress = ((++particleTween.elapsed << 12) / particleTween.duration);
    particleTween.direction =
        (particleTween.startDirection + ((particleTween.deltaDirection * progress) >> 12))
        & 0xFFF;
    particleTween.fallAngle =
        particleTween.startFallAngle + ((particleTween.deltaFallAngle * progress) >> 12);
    particleTween.intensity =
        particleTween.startIntensity + ((particleTween.deltaIntensity * progress) >> 12);

    setParticleEffectDirection(particleTween.direction, particleTween.fallAngle);
    setParticleEffectIntensity(particleTween.intensity);

    if (particleTween.elapsed == particleTween.duration) {
        particleTween.duration = 0;
    }
}

extern CVECTOR neutralTint;
extern VECTOR oneVector;

/** Allocates the scripted camera, starting from the current view. */
static void initScriptCamera(void)
{
    UNUSED VECTOR _;
    VECTOR eye;
    VECTOR lookAt;

    scriptCamera = vs_main_allocHeapR(sizeof *scriptCamera);
    cameraFollowsAshley = 0;

    getCameraPosition(&eye);
    getCameraLookAt(&lookAt);
    vectorCopy(&scriptCamera->eye.current, &eye);
    vectorCopy(&scriptCamera->lookAt.otherPosition, &eye);
    vectorCopy(&scriptCamera->lookAt.current, &lookAt);
    vectorCopy(&scriptCamera->eye.otherPosition, &lookAt);

    scriptCamera->lookAt.mode = cameraModeIdle;
    scriptCamera->lookAt.carryMomentum = scriptCamera->lookAt.carrying = 0;
    scriptCamera->eye.mode = cameraModeIdle;
    scriptCamera->eye.carryMomentum = scriptCamera->eye.carrying = 0;
    scriptCamera->roll.duration = 0;
    scriptCamera->roll.value = 0;
    scriptCamera->roll.changed = 1;

    setFramebufferEffect(0);

    scriptCamera->framebufferSpin.duration = 0;
    scriptCamera->framebufferSpin.value = 0;

    vs_battle_setFramebufferEffectSpin(0);

    scriptCamera->framebufferSpin.changed = 1;
    scriptCamera->framebufferScale.value.vy = ONE;
    scriptCamera->framebufferScale.value.vx = ONE;

    vs_battle_setFramebufferEffectScale(&oneVector);

    scriptCamera->framebufferTint.value.vx = scriptCamera->framebufferTint.value.vy =
        scriptCamera->framebufferTint.value.vz = scriptCamera->framebufferScale.duration =
            0;

    vs_battle_setFramebufferEffectTint(&neutralTint);

    scriptCamera->framebufferTint.duration = 0;
    scriptCamera->framebufferOffset.value.vy = ONE;
    scriptCamera->framebufferOffset.value.vx = ONE;

    vs_battle_setFramebufferEffectOffset(&oneVector);

    scriptCamera->framebufferOffset.duration = 0;

    vs_battle_setFramebufferEffectBlendMode(1);

    scriptCamera->lensDistortion.value.vx = ONE;
    scriptCamera->lensDistortion.duration = scriptCamera->lensDistortion.value.vy = 0;
    scriptCamera->projectionDistance.value = ONE / 8;
    scriptCamera->projectionDistance.duration = 0;
    scriptCamera->projectionDistance.changed = 1;
    scriptCamera->nearClip.value = 64;
    scriptCamera->nearClip.duration = 0;
    scriptCamera->nearClip.changed = 1;
    scriptCamera->farClip.value = ONE;
    scriptCamera->farClip.duration = 0;
    scriptCamera->farClip.changed = 1;
    scriptCamera->shakeCount = 0;
    scriptCamera->shakeEntries[0].duration = scriptCamera->shakeEntries[1].duration = 0;
    scriptCamera->attachedActor = 0x2000;
}

/** Frees the scripted camera. */
void freeScriptCamera(void) { vs_main_freeHeapR(scriptCamera); }

/**
 * Makes the scripted camera follow Ashley with the gameplay camera's view, until the
 * next request to return to it.
 */
void setCameraFollowsAshley(int follows) { cameraFollowsAshley = follows; }

/**
 * Attaches the camera to an actor: camera positions become offsets from the actor and
 * the camera moves with it. Detaching keeps the view where it is.
 * @param actor Actor to attach to, 0x2000 = detach (world coordinates).
 */
void attachCameraToActor(u_short actor)
{
    int _[4];
    if (actor == 0x2000) {
        if (scriptCamera->attachedActor != actor) {
            vectorAdd(&scriptCamera->eye.current, &scriptCamera->eye.current,
                &scriptCamera->attachedPosition);
            vectorAdd(&scriptCamera->lookAt.current, &scriptCamera->lookAt.current,
                &scriptCamera->attachedPosition);
        }
    }
    scriptCamera->attachedActor = actor;
    updateCameraAttachment();
}

/** Updates the attached actor's position. Runs every frame of a script. */
void updateCameraAttachment(void)
{
    vs_ActorPosition sp10;

    if (scriptCamera->attachedActor == 0x2000) {
        scriptCamera->attachedPosition.vz = 0;
        scriptCamera->attachedPosition.vy = 0;
        scriptCamera->attachedPosition.vx = 0;
        return;
    }
    vs_battle_getActorPosition(scriptCamera->attachedActor, &sp10);
    scriptCamera->attachedPosition.vx = sp10.unk0.unk4.vx * ONE;
    scriptCamera->attachedPosition.vy = sp10.unk0.unk4.vy * ONE;
    scriptCamera->attachedPosition.vz = sp10.unk0.unk4.vz * ONE;
}

static void applyCameraState(void)
{
    VECTOR cameraLookAt;
    VECTOR cameraPos;

    if (cameraFollowsAshley != 0) {
        initialiseCameraFromSpherical(&cameraPos, &cameraLookAt, -1, -1);
        vectorCopy(&scriptCamera->lookAt.current, &cameraLookAt);
        vectorCopy(&scriptCamera->eye.current, &cameraPos);
    } else {
        vectorCopy(&cameraLookAt, &scriptCamera->lookAt.current);
        vectorCopy(&cameraPos, &scriptCamera->eye.current);
        if (scriptCamera->attachedActor != 0x2000) {
            vectorAdd(&cameraLookAt, &cameraLookAt, &scriptCamera->attachedPosition);
            vectorAdd(&cameraPos, &cameraPos, &scriptCamera->attachedPosition);
        }
    }
    if (scriptCamera->shakeCount != 0) {
        sVectorToFixedPointVector(&CAMERA_SCRATCH->v1, &scriptCamera->shakeLookAt);
        sVectorToFixedPointVector(&CAMERA_SCRATCH->v2, &scriptCamera->shakeEye);
        CAMERA_SCRATCH->s1.vz = 0;
        CAMERA_SCRATCH->s1.vx = 0;
        CAMERA_SCRATCH->s1.vy =
            yawFromOffset(cameraLookAt.vx - cameraPos.vx, cameraLookAt.vz - cameraPos.vz);
        RotMatrix_gte(&CAMERA_SCRATCH->s1, &CAMERA_SCRATCH->matrix);
        ApplyMatrixLV(&CAMERA_SCRATCH->matrix, &CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v1);
        ApplyMatrixLV(&CAMERA_SCRATCH->matrix, &CAMERA_SCRATCH->v2, &CAMERA_SCRATCH->v2);
        vectorAdd(&cameraLookAt, &cameraLookAt, &CAMERA_SCRATCH->v1);
        vectorAdd(&cameraPos, &cameraPos, &CAMERA_SCRATCH->v2);
    }
    setCameraLookAt(&cameraLookAt);
    setCameraPosition(&cameraPos);
    if (scriptCamera->roll.changed != 0) {
        setCameraRoll(scriptCamera->roll.value);
        scriptCamera->roll.changed = 0;
    }
    if (scriptCamera->framebufferSpin.changed != 0) {
        vs_battle_setFramebufferEffectSpin(scriptCamera->framebufferSpin.value);
        scriptCamera->framebufferSpin.changed = 0;
    }
    if (scriptCamera->projectionDistance.changed != 0) {
        vs_battle_setProjectionDistance(scriptCamera->projectionDistance.value);
        scriptCamera->projectionDistance.changed = 0;
    }
    if (scriptCamera->nearClip.changed != 0) {
        setNearClip(scriptCamera->nearClip.value);
        scriptCamera->nearClip.changed = 0;
    }
    if (scriptCamera->farClip.changed != 0) {
        setFarClip(scriptCamera->farClip.value, fogDepthOverridden);
        scriptCamera->farClip.changed = 0;
    }
}

/**
 * Moves the scripted camera to the gameplay camera's view of Ashley. The time taken
 * depends on how far the camera has to go. Does nothing except stop following Ashley if
 * the camera is following him.
 * @param facing New facing of the gameplay camera, -1 = unchanged.
 * @param zoom 1 = normal, 2 = zoomed out, -1 = unchanged.
 */
void returnToGameplayCamera(short facing, int zoom)
{
    VECTOR sp10;
    VECTOR sp20;
    int temp_s0;
    short temp_v0;

    if (cameraFollowsAshley != 0) {
        cameraFollowsAshley = 0;
        return;
    }
    initialiseCameraFromSpherical(&sp10, &sp20, facing, (short)zoom);
    vectorCopy(&scriptCamera->eye.position, &sp10);
    vectorCopy(&scriptCamera->lookAt.position, &sp20);
    temp_s0 = vectorMagnitude(vectorSubtract(
        &CAMERA_SCRATCH->v1, &scriptCamera->eye.current, &scriptCamera->eye.position));
    temp_v0 = (temp_s0
                  + vectorMagnitude(vectorSubtract(&CAMERA_SCRATCH->v1,
                      &scriptCamera->lookAt.current, &scriptCamera->lookAt.position)))
            / 0x28000;
    if ((temp_v0 << 0x10) != 0) {
        returnCameraScripts[2] = returnCameraScripts[6] = temp_v0;
        vs_battle_script_Cx_Dx_camera(returnCameraScripts, 0);
        vs_battle_script_Cx_Dx_camera(returnCameraScripts + 3, 0);
    }
}

/**
 * Controls the look-at (opcodes 0xC0 to 0xCB) or eye (0xD0 to 0xDB) camera channel, as
 * chosen by bit 4. The low nibble is the sub-opcode. An easing is a value of enum Easing,
 * a duration is in steps of 1/30 s, and an angle is in ONE per turn.
 * @param script Opcode bytes, which depend on the sub-opcode.
 */
int vs_battle_script_Cx_Dx_camera(u_char* script, UNUSED short unused)
{
    enum {
        // Stores a destination for the channel.
        // [1-6] = x, y and z of the destination, as 16-bit world coordinates.
        cameraSetDestination = 0,
        // Cuts the channel to its destination at once.
        cameraCut = 1,
        // Moves the channel to its destination in a straight line.
        // [1] = easing, [2] = duration.
        cameraLerpTo = 2,
        // Moves the channel to its destination in an arc around the other channel.
        // [1] = easing, [2] = duration.
        cameraArcTo = 3,
        // Orbits the channel around the other channel to its destination.
        // [1] = angle easing in the high nibble, turn direction in the low nibble
        // (0 = shortest way, 1 = positive, 15 = negative).
        // [2] = height easing in the high nibble, distance easing in the low nibble.
        // [3] = duration.
        cameraOrbitTo = 4,
        // Orbits the channel around the other channel by an angle. The destination is
        // not used. [1-2] = signed angle.
        // [3-4] = final height, as a world y. [5] = distance scale in 1/64 units.
        // [6] = angle easing in the low nibble, distance easing in the high nibble.
        // [7] = height easing. [8] = duration.
        cameraOrbitBy = 5,
        // Stores a destination that is an offset from a point on an actor.
        // [1-2] = actor selector. [3] = point on the actor, a bone id or an ActorPoint.
        // [4-9] = x, y and z of the offset, as 16-bit world values.
        cameraSetDestinationToActorOffset = 7,
        // Follows an offset from a point on an actor.
        // [1-9] = as for cameraSetDestinationToActorOffset. [10] = duration.
        cameraFollowActor = 8,
        // Holds the channel at its current offset from the other channel.
        // [1] = duration.
        cameraLockOffset = 9,
        // As cameraSetDestinationToActorOffset, with the offset turned by the actor's
        // facing.
        cameraSetDestinationToActorLocalOffset = 10,
        // Moves the channel horizontally to its destination, at a fixed height above the
        // ground. [2] = duration, [1] is not used.
        cameraTerrainFollowTo = 11,
    };

    CameraChannel* channel;
    CameraChannel* otherChannel;

    if (!(script[0] & 16)) {
        channel = &scriptCamera->lookAt;
        otherChannel = &scriptCamera->eye;
    } else {
        channel = &scriptCamera->eye;
        otherChannel = &scriptCamera->lookAt;
    }

    switch (script[0] & 15) {
    case cameraSetDestination:
        readScriptVector(&channel->position, script + 1);

        return scriptNext;

    case cameraCut:
        channel->mode = cameraModeIdle;

        vectorCopy(&channel->current, &channel->position);
        vectorCopy(&otherChannel->otherPosition, &channel->position);

        return scriptNext;

    case cameraLerpTo:
        channel->mode = cameraModeLerp;
        channel->time = 0;
        channel->ease1 = script[1];
        channel->duration = script[2];

        vectorCopy(&channel->start, &channel->current);
        vectorSubtract(&channel->velocity, &channel->position, &channel->current);

        return scriptNext;

    case cameraArcTo:
        channel->mode = cameraModeArc;
        channel->time = 0;
        channel->ease1 = script[1];
        channel->duration = script[2];

        vectorCopy(&channel->start, &channel->current);
        vectorSubtract(&channel->velocity, &channel->position, &channel->current);

        channel->value = vectorMagnitude(vectorSubtract(
            &CAMERA_SCRATCH->v1, &channel->otherPosition, &channel->current));

        return scriptNext;

    case cameraOrbitTo: {
        CameraScratch* s;
        channel->mode = cameraModeOrbitTo;
        channel->time = 0;
        channel->duration = script[3];
        channel->ease1 = script[1] >> 4;
        channel->ease2 = script[2] & 15;
        channel->ease3 = script[2] >> 4;

        vectorCopy(&channel->start, &channel->otherPosition);

        s = CAMERA_SCRATCH;

        setVector(&s->v1, channel->current.vx - channel->otherPosition.vx, 0,
            channel->current.vz - channel->otherPosition.vz);

        channel->value = vectorMagnitude(&CAMERA_SCRATCH->v1);
        channel->angle = yawFromOffset(s->v1.vx, s->v1.vz) & 4095;

        setVector(&s->v2, channel->position.vx - channel->otherPosition.vx, 0,
            channel->position.vz - channel->otherPosition.vz);

        channel->delta = vectorMagnitude(&CAMERA_SCRATCH->v2) - channel->value;
        s->i1 = (yawFromOffset(s->v2.vx, s->v2.vz) & 4095) - channel->angle;

        if (s->i1 < -ONE / 2) {
            s->i1 += ONE;
        }
        if (s->i1 > ONE / 2) {
            s->i1 -= ONE;
        }

        switch (script[1] & 15) {
        case 15:
            if (s->i1 == 0) {
                s->i1 = -ONE;
            } else if (s->i1 > 0) {
                s->i1 -= ONE;
            }
            break;

        case 1:
            if (s->i1 == 0) {
                s->i1 = ONE;
            } else if (s->i1 < 0) {
                s->i1 += ONE;
            }
            break;
        }

        channel->angleDelta = CAMERA_SCRATCH->i1;
        channel->aux.vy = channel->current.vy - channel->otherPosition.vy;
        channel->velocity.vy =
            channel->position.vy - channel->otherPosition.vy - channel->aux.vy;

        return scriptNext;
    }

    case cameraOrbitBy: {
        CameraScratch* s;
        int height;

        channel->mode = cameraModeOrbitBy;
        channel->time = 0;
        channel->duration = script[8];
        channel->ease1 = script[6] & 15;
        channel->ease2 = script[6] >> 4;
        channel->ease3 = script[7] & 15;

        vectorCopy(&channel->position, &channel->otherPosition);

        s = CAMERA_SCRATCH;

        setVector(&s->v1, channel->current.vx - channel->otherPosition.vx, 0,
            channel->current.vz - channel->otherPosition.vz);

        channel->value = vectorMagnitude(&CAMERA_SCRATCH->v1);
        channel->delta = ((channel->value * script[5]) >> 6) - channel->value;
        channel->angle = yawFromOffset(s->v1.vx, s->v1.vz);
        channel->angleDelta = getShort(script + 1);

        height = getShort(script + 3) * ONE;

        channel->start.vy = channel->current.vy;
        channel->velocity.vy = height - channel->start.vy;

        return scriptNext;
    }

    case cameraSetDestinationToActorOffset:
        getActorPoint(
            resolveActorId(getShort(script + 1)), script[3], &CAMERA_SCRATCH->s1, 2);

        sVectorToFixedPointVector(&CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->s1);

        readScriptVector(&CAMERA_SCRATCH->v2, script + 4);
        vectorAdd(&channel->position, &CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v2);

        if (scriptCamera->attachedActor != 0x2000) {
            vectorSubtract(
                &channel->position, &channel->position, &scriptCamera->attachedPosition);
        }

        return scriptNext;

    case cameraFollowActor:
        channel->mode = cameraModeFollowActor;
        channel->value = resolveActorId(getShort(script + 1));
        channel->delta = script[3];
        channel->time = 0;
        channel->duration = script[10];

        readScriptVector(&channel->velocity, script + 4);

        return scriptNext;

    case cameraLockOffset:
        channel->mode = cameraModeLockOffset;
        channel->time = 0;
        channel->duration = script[1];

        vectorSubtract(&channel->velocity, &channel->current, &channel->otherPosition);

        return scriptNext;

    case cameraSetDestinationToActorLocalOffset: {
        int id = resolveActorId(getShort(script + 1));

        CAMERA_SCRATCH->i1 = id;

        vs_battle_getActorPosition(id, &scriptCamera->actorPosition);

        CAMERA_SCRATCH->s2.vz = 0;
        CAMERA_SCRATCH->s2.vx = 0;
        CAMERA_SCRATCH->s2.vy = scriptCamera->actorPosition.unk0.unk4.pad;

        RotMatrix_gte(&CAMERA_SCRATCH->s2, &CAMERA_SCRATCH->matrix);
        readScriptVector(&CAMERA_SCRATCH->v1, script + 4);
        ApplyMatrixLV(&CAMERA_SCRATCH->matrix, &CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v1);
        getActorPoint(CAMERA_SCRATCH->i1, script[3], &CAMERA_SCRATCH->s2, 2);

        vectorAdd(&channel->position,
            sVectorToFixedPointVector(&CAMERA_SCRATCH->v2, &CAMERA_SCRATCH->s2),
            &CAMERA_SCRATCH->v1);

        if (scriptCamera->attachedActor != 0x2000) {
            vectorSubtract(
                &channel->position, &channel->position, &scriptCamera->attachedPosition);
        }

        return scriptNext;
    }

    case cameraTerrainFollowTo: {
        channel->mode = cameraModeTerrainFollow;
        channel->time = 0;
        channel->ease1 = easingLinear;
        channel->duration = script[2];

        vectorSubtract(&CAMERA_SCRATCH->v1, &channel->otherPosition, &channel->current);
        vectorToLookMatrix(&CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->matrix);

        CAMERA_SCRATCH->matrix.t[0] = channel->current.vx >> 12;
        CAMERA_SCRATCH->matrix.t[1] = channel->current.vy >> 12;
        CAMERA_SCRATCH->matrix.t[2] = channel->current.vz >> 12;
        channel->current.vy = getCameraTerrainHeight(&CAMERA_SCRATCH->matrix);

        vectorCopy(&channel->computed, &channel->current);

        channel->delta = vectorMagnitude(
            vectorSubtract(&CAMERA_SCRATCH->v1, &channel->position, &channel->computed));
        channel->value = channel->delta / script[2];
        scriptCamera->terrainFollowLast.vx = scriptCamera->terrainFollowLast.vy =
            scriptCamera->terrainFollowLast.vz = 0x80000000;

        return scriptNext;
    }
    }
}

/** Advances the camera by one frame. */
static void updateCamera(void)
{
    scriptCamera->eye.otherPosition.vx = scriptCamera->lookAt.current.vx;
    scriptCamera->eye.otherPosition.vy = scriptCamera->lookAt.current.vy;
    scriptCamera->eye.otherPosition.vz = scriptCamera->lookAt.current.vz;
    scriptCamera->lookAt.otherPosition.vx = scriptCamera->eye.current.vx;
    scriptCamera->lookAt.otherPosition.vy = scriptCamera->eye.current.vy;
    scriptCamera->lookAt.otherPosition.vz = scriptCamera->eye.current.vz;

    stepCameraChannel(&scriptCamera->lookAt, &scriptCamera->eye);
    stepCameraChannel(&scriptCamera->eye, &scriptCamera->lookAt);
    stepAngleTween(&scriptCamera->roll);
    stepAngleTween(&scriptCamera->framebufferSpin);
    stepProjectionTween(&scriptCamera->projectionDistance);
    stepProjectionTween(&scriptCamera->nearClip);
    stepProjectionTween(&scriptCamera->farClip);
    updateCameraShake();
}

/** Steps one camera channel by a frame, evaluating its current mode. */
static void stepCameraChannel(CameraChannel* channel, UNUSED CameraChannel* other)
{
    if (channel->mode == cameraModeIdle) {
        return;
    }

    if (channel->mode != cameraModeTerrainFollow) {
        channel->time += vs_gametime_vblanksPerFrame >> 1;
        if (channel->time > channel->duration) {
            channel->time = channel->duration;
        }
    }

    switch (channel->mode) {
    case cameraModeLerp:
        CAMERA_SCRATCH->i1 =
            evaluateEasing(channel->ease1, channel->time, channel->duration);

        vectorFixedPointMult(&CAMERA_SCRATCH->v1, &channel->velocity, CAMERA_SCRATCH->i1);
        vectorAdd(&channel->computed, &channel->start, &CAMERA_SCRATCH->v1);

        break;

    case cameraModeArc: {
        CAMERA_SCRATCH->i1 =
            evaluateEasing(channel->ease1, channel->time, channel->duration);

        vectorFixedPointMult(&CAMERA_SCRATCH->v1, &channel->velocity, CAMERA_SCRATCH->i1);
        vectorAdd(&CAMERA_SCRATCH->v2, &channel->start, &CAMERA_SCRATCH->v1);
        vectorSubtract(&CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v2, &channel->otherPosition);
        normalizeVector(&CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v1);

        CAMERA_SCRATCH->i2 = vectorMagnitude(vectorSubtract(
            &CAMERA_SCRATCH->v2, &channel->otherPosition, &channel->position));
        CAMERA_SCRATCH->i1 =
            channel->value
            + fixedPointMult(CAMERA_SCRATCH->i2 - channel->value,
                evaluateEasing(channel->ease1, channel->time, channel->duration));

        vectorFixedPointMult(
            &CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v1, CAMERA_SCRATCH->i1);
        vectorAdd(&channel->computed, &channel->otherPosition, &CAMERA_SCRATCH->v1);

        break;
    }

    case cameraModeOrbitTo: {
        CAMERA_SCRATCH->s1.vz = 0;
        CAMERA_SCRATCH->s1.vx = 0;
        CAMERA_SCRATCH->s1.vy =
            channel->angle
            + ((channel->angleDelta
                   * evaluateEasing(channel->ease1, channel->time, channel->duration))
                >> 12);

        RotMatrix_gte(&CAMERA_SCRATCH->s1, &CAMERA_SCRATCH->matrix);

        CAMERA_SCRATCH->v1.vz =
            channel->value
            + fixedPointMult(channel->delta,
                evaluateEasing(channel->ease2, channel->time, channel->duration));
        CAMERA_SCRATCH->v1.vx = 0;
        CAMERA_SCRATCH->v1.vy = 0;

        ApplyMatrixLV(&CAMERA_SCRATCH->matrix, &CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v1);

        CAMERA_SCRATCH->v1.vy =
            channel->aux.vy
            + fixedPointMult(channel->velocity.vy,
                evaluateEasing(channel->ease3, channel->time, channel->duration));
        vectorAdd(&channel->computed, &channel->start, &CAMERA_SCRATCH->v1);

        break;
    }

    case cameraModeOrbitBy: {
        CAMERA_SCRATCH->s1.vz = 0;
        CAMERA_SCRATCH->s1.vx = 0;
        CAMERA_SCRATCH->s1.vy =
            channel->angle
            + ((channel->angleDelta
                   * evaluateEasing(channel->ease1, channel->time, channel->duration))
                >> 12);

        RotMatrix_gte(&CAMERA_SCRATCH->s1, &CAMERA_SCRATCH->matrix);

        CAMERA_SCRATCH->v1.vz =
            channel->value
            + fixedPointMult(channel->delta,
                evaluateEasing(channel->ease2, channel->time, channel->duration));
        CAMERA_SCRATCH->v1.vx = 0;
        CAMERA_SCRATCH->v1.vy = 0;

        ApplyMatrixLV(&CAMERA_SCRATCH->matrix, &CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v1);

        channel->computed.vx = channel->position.vx + CAMERA_SCRATCH->v1.vx;
        channel->computed.vz = channel->position.vz + CAMERA_SCRATCH->v1.vz;
        channel->computed.vy =
            channel->start.vy
            + fixedPointMult(channel->velocity.vy,
                evaluateEasing(channel->ease3, channel->time, channel->duration));

        break;
    }

    case cameraModeFollowActor:
        getActorPoint(channel->value, channel->delta, &CAMERA_SCRATCH->s1, 2);
        vectorAdd(&channel->computed,
            sVectorToFixedPointVector(&CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->s1),
            &channel->velocity);
        break;

    case cameraModeLockOffset:
        vectorAdd(&channel->computed, &channel->velocity, &channel->otherPosition);
        break;

    case cameraModeTerrainFollow:
        stepCameraTerrainFollow(channel);
        break;
    }

    vectorCopy(&channel->previousCamera, &channel->current);

    if (channel->carryMomentum & channel->carrying) {

        vectorAdd(&channel->momentumPosition, &channel->momentumPosition,
            &channel->momentumStep);

        CAMERA_SCRATCH->i1 =
            evaluateEasing(easingSineOut, channel->time, channel->duration);

        vectorSubtract(
            &CAMERA_SCRATCH->v1, &channel->computed, &channel->momentumPosition);
        vectorFixedPointMult(
            &CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v1, CAMERA_SCRATCH->i1);
        vectorAdd(&channel->current, &channel->momentumPosition, &CAMERA_SCRATCH->v1);
    } else {
        vectorCopy(&channel->current, &channel->computed);
    }

    if (channel->time == channel->duration) {

        channel->mode = cameraModeIdle;

        if (channel->carryMomentum) {
            channel->carrying = 1;

            vectorCopy(&channel->momentumPosition, &channel->current);
            vectorSubtract(
                &channel->momentumStep, &channel->current, &channel->previousCamera);
        }
    }
}

/**
 * Steps a terrain-following channel, keeping its position above the ground.
 */
static void stepCameraTerrainFollow(CameraChannel* channel)
{
    CameraScratch* scratch;
    short i;

    vectorSubtract(&CAMERA_SCRATCH->v1, &channel->otherPosition, &channel->position);
    vectorToLookMatrix(&CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->matrix);

    scratch = CAMERA_SCRATCH;

    scratch->matrix.t[0] = channel->position.vx >> 12;
    scratch->matrix.t[1] = channel->position.vy >> 12;
    scratch->matrix.t[2] = channel->position.vz >> 12;

    setVector(&scratch->v1, channel->position.vx - channel->computed.vx,
        getCameraTerrainHeight(&scratch->matrix) - channel->computed.vy,
        channel->position.vz - channel->computed.vz);

    scratch->i1 = vectorMagnitude(&scratch->v1);
    scratch->i2 = scratch->i1 / channel->value;

    if (scratch->i2 < 2) {
        channel->time = channel->duration;
    } else if (scratch->i2 > 10) {
        scratch->i2 = 10;
    }

    normalizeVector(&CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v1);
    vectorFixedPointMult(&CAMERA_SCRATCH->v1, &CAMERA_SCRATCH->v1, channel->value);
    vectorCopy(&CAMERA_SCRATCH->v2, &channel->computed);

    for (i = 1; i <= CAMERA_SCRATCH->i2; ++i) {
        int height;
        scratch = CAMERA_SCRATCH;

        vectorAdd(&scratch->v2, &scratch->v2, &scratch->v1);
        vectorSubtract(&scratch->v3, &channel->otherPosition, &scratch->v2);
        vectorToLookMatrix(&scratch->v3, &scratch->matrix);

        scratch->matrix.t[0] = scratch->v2.vx >> 12;
        scratch->matrix.t[1] = scratch->v2.vy >> 12;
        scratch->matrix.t[2] = scratch->v2.vz >> 12;

        height = getCameraTerrainHeight(&scratch->matrix);

        if (height < scratch->v2.vy) {
            setVector(&scratch->v1, scratch->v2.vx - channel->computed.vx,
                height - channel->computed.vy, scratch->v2.vz - channel->computed.vz);
            normalizeVector(&scratch->v1, &scratch->v1);
            vectorFixedPointMult(&scratch->v1, &scratch->v1, channel->value);

            break;
        }
    }

    vectorAdd(&CAMERA_SCRATCH->v2, &CAMERA_SCRATCH->v1, &channel->computed);

    if (CAMERA_SCRATCH->v2.vx == scriptCamera->terrainFollowLast.vx
        && CAMERA_SCRATCH->v2.vy == scriptCamera->terrainFollowLast.vy
        && CAMERA_SCRATCH->v2.vz == scriptCamera->terrainFollowLast.vz) {
        channel->time = channel->duration;
    } else {
        vectorCopy(&scriptCamera->terrainFollowLast, &channel->computed);
        vectorCopy(&channel->computed, &CAMERA_SCRATCH->v2);
    }
}

/**
 * Lowest terrain height under a square of four points just ahead of the camera, with
 * some clearance.
 */
static int getCameraTerrainHeight(MATRIX* camera)
{
    VECTOR pos;
    SVECTOR offset;
    long flag;
    int first;
    int second;
    int third;
    int fourth;
    short lowest;

#define SAMPLE_HEIGHT(result, x, y)                                                     \
    setVector(&offset, x, y, 150);                                                      \
    RotTrans(&offset, &pos, &flag);                                                     \
    result = ((getTerrainHeight(pos.vx, pos.vz) << 17) >> 17) - 200

    SetRotMatrix(camera);
    SetTransMatrix(camera);

    SAMPLE_HEIGHT(first, 80, 80);

    lowest = first;

    SAMPLE_HEIGHT(second, -80, 80);

    if (second < first) {
        lowest = second;
    }

    SAMPLE_HEIGHT(third, 80, -80);

    if (third < lowest) {
        lowest = third;
    }

    SAMPLE_HEIGHT(fourth, -80, -80);

    if (fourth < lowest) {
        lowest = fourth;
    }

    return lowest * ONE;

#undef SAMPLE_HEIGHT
}

/**
 * Tweens an angle: the camera roll for E2, the spin of the frame buffer effect for E3.
 * @param script Opcode bytes:
 *   - [1..2] = target angle
 *   - [3] = low nibble the easing, high nibble the direction: 0 negative, 1 shortest,
 *     2 positive
 *   - [4] = duration, 0 sets the angle immediately
 *   - [5] = unused
 */
int vs_battle_script_E2_E3_camera(u_char* script, UNUSED short slot)
{
    AngleTween* tween;

    switch (script[0]) {
    case 0xE2:
        tween = &scriptCamera->roll;
        break;
    case 0xE3:
        tween = &scriptCamera->framebufferSpin;
        break;
    }

    tween->duration = script[4];

    if (tween->duration == 0) {
        tween->value = getShort(script + 1);
        tween->changed = 1;
    } else {

        tween->start = tween->value;
        tween->delta = getShort(script + 1) - tween->value;

        if (tween->delta < -(ONE / 2)) {
            tween->delta += ONE;
        } else if (tween->delta > (ONE / 2)) {
            tween->delta -= ONE;
        }

        switch (script[3] >> 4) {
        case 0:
            if (tween->delta > 0) {
                tween->delta -= ONE;
            }
            break;
        case 2:
            if (tween->delta < 0) {
                tween->delta += ONE;
            }
            break;
        }

        tween->ease = script[3] & 0xF;
        tween->elapsed = 0;
    }

    return scriptNext;
}

/** Steps an angle tween by one frame. */
static void stepAngleTween(AngleTween* tween)
{
    if (tween->duration <= 0) {
        return;
    }

    tween->elapsed += vs_gametime_vblanksPerFrame >> 1;

    tween->value =
        tween->start
        + ((tween->delta * evaluateEasing(tween->ease, tween->elapsed, tween->duration))
            >> 0xC);

    if (tween->elapsed >= tween->duration) {
        tween->duration = 0;
    }

    tween->changed = 1;
}

/**
 * Gets which camera channels are idle.
 * @return Bit mask of the idle channels, see the cameraIdle flags.
 */
u_char getCameraIdleFlags(void)
{
    u_char idle = scriptCamera->lookAt.mode == cameraModeIdle;

    if (scriptCamera->eye.mode == cameraModeIdle) {
        idle |= cameraIdleEye;
    }

    if (scriptCamera->roll.duration == 0) {
        idle |= cameraIdleRoll;
    }

    if (scriptCamera->projectionDistance.duration == 0) {
        idle |= cameraIdleProjectionDistance;
    }

    if (scriptCamera->nearClip.duration == 0) {
        idle |= cameraIdleNearClip;
    }

    if (scriptCamera->farClip.duration == 0) {
        idle |= cameraIdleFarClip;
    }

    if (scriptCamera->lensDistortion.duration == 0) {
        idle |= cameraIdleLensDistortion;
    }

    if ((scriptCamera->shakeEntries[0].duration + scriptCamera->shakeEntries[1].duration)
        == 0) {
        idle |= cameraIdleShake;
    }

    return idle;
}

/**
 * Sets the parameters of the frame buffer effect and the lens distortion.
 * @param script Opcode bytes, see the comments on each opcode.
 */
int vs_battle_script_B9_BA_BF_E4_E5_E6_E7_ED(u_char* script, UNUSED short slot)
{
    VECTOR values;
    CVECTOR color;
    short mode;
    short effectValue;

    switch (script[0]) {
    // Sets the ordering table index the frame buffer effect is drawn at.
    // [1-2] = ordering table index.
    case 0xB9:
        vs_battle_setFramebufferEffectDepth(getShort(script + 1));

        return scriptNext;

    // Sets whether the frame buffer effect reads the previous frame.
    // [1] = 1 for the previous frame, 0 for the current one.
    case 0xBA:
        vs_battle_setFramebufferEffectUsePreviousFrame(script[1]);

        return scriptNext;

    // Tweens the scale of the frame buffer effect.
    // [1-2] = x and y scale (<< 7), [3] = easing, [4] = tween duration, 0 =
    // immediate.
    case 0xE4:
        scriptCamera->framebufferScale.duration = script[4];

        if (scriptCamera->framebufferScale.duration == 0) {
            values.vx = (script[1] << 7);
            values.vy = (script[2] << 7);

            vs_battle_setFramebufferEffectScale(&values);
        } else {
            scriptCamera->framebufferScale.elapsed = 0;

            getFramebufferEffectScale(&values);

            scriptCamera->framebufferScale.delta.vx =
                (script[1] << 7) - (scriptCamera->framebufferScale.start.vx = values.vx);
            scriptCamera->framebufferScale.delta.vy =
                (script[2] << 7) - (scriptCamera->framebufferScale.start.vy = values.vy);
            scriptCamera->framebufferScale.ease = script[3];
        }

        return scriptNext;

    // Tweens the tint of the frame buffer effect.
    // [1-3] = red, green and blue, [4] = easing, [5] = tween duration, 0 = immediate.
    case 0xE5:
        scriptCamera->framebufferTint.duration = script[5];

        if (scriptCamera->framebufferTint.duration == 0) {
            color.r = script[1];
            color.g = script[2];
            color.b = script[3];

            vs_battle_setFramebufferEffectTint(&color);
        } else {
            scriptCamera->framebufferTint.elapsed = 0;

            getFramebufferEffectTint(&color);

            scriptCamera->framebufferTint.delta.vx =
                script[1] - (scriptCamera->framebufferTint.start.vx = color.r);
            scriptCamera->framebufferTint.delta.vy =
                script[2] - (scriptCamera->framebufferTint.start.vy = color.g);
            scriptCamera->framebufferTint.delta.vz =
                script[3] - (scriptCamera->framebufferTint.start.vz = color.b);
            scriptCamera->framebufferTint.ease = script[4];
        }

        return scriptNext;

    // Tweens the offset of the frame buffer effect.
    // [1-2] = signed x and y offset, [3] = easing, [4] = tween duration, 0 =
    // immediate.
    case 0xE6:
        scriptCamera->framebufferOffset.duration = script[4];

        if (scriptCamera->framebufferOffset.duration == 0) {
            values.vx = (signed char)script[1];
            values.vy = (signed char)script[2];

            vs_battle_setFramebufferEffectOffset(&values);
        } else {
            scriptCamera->framebufferOffset.elapsed = 0;

            getFramebufferEffectOffset(&values);

            scriptCamera->framebufferOffset.delta.vx =
                (signed char)script[1]
                - (scriptCamera->framebufferOffset.start.vx = values.vx);
            scriptCamera->framebufferOffset.delta.vy =
                (signed char)script[2]
                - (scriptCamera->framebufferOffset.start.vy = values.vy);
            scriptCamera->framebufferOffset.ease = script[3];
        }

        return scriptNext;

    // Sets the blend mode of the frame buffer effect.
    // [1] = blend mode.
    case 0xE7:
        vs_battle_setFramebufferEffectBlendMode(script[1]);

        return scriptNext;

    // Tweens the lens distortion, waiting for a previous tween to finish.
    // [1] = zoom (<< 6), [2] = distortion (signed), [3] = easing, [4] = tween
    // duration, 0 = immediate. See setScreenLensDistortion.
    case 0xED:
        if (scriptCamera->lensDistortion.duration > 0) {
            return scriptWait;
        }

        scriptCamera->lensDistortion.duration = script[4];

        if (scriptCamera->lensDistortion.duration == 0) {
            scriptCamera->lensDistortion.value.vx = effectValue = script[1] << 6;
            scriptCamera->lensDistortion.value.vy = (signed char)script[2];

            setScreenLensDistortion(effectValue, scriptCamera->lensDistortion.value.vy);
        } else {
            scriptCamera->lensDistortion.elapsed = 0;
            scriptCamera->lensDistortion.delta.vx =
                (script[1] << 6)
                - (scriptCamera->lensDistortion.start.vx =
                        scriptCamera->lensDistortion.value.vx);
            scriptCamera->lensDistortion.delta.vy =
                (signed char)script[2]
                - (scriptCamera->lensDistortion.start.vy =
                        scriptCamera->lensDistortion.value.vy);
            scriptCamera->lensDistortion.ease = script[3];
        }

        return scriptNext;

    // Turns the frame buffer effect on or off with a preset and resets its parameters.
    // [1-2] = 0 to turn off, else the ordering table index of the effect.
    case 0xBF:

        mode = getShort(script + 1);

        if (!mode) {
            vs_battle_setFramebufferEffectBlendMode(0);

            values.vx = values.vy = 0;

            vs_battle_setFramebufferEffectOffset(&values);

            values.vx = values.vy = ONE;

            vs_battle_setFramebufferEffectScale(&values);

            color.r = color.g = color.b = 128;

            vs_battle_setFramebufferEffectTint(&color);
            vs_battle_setFramebufferEffectDepth(0);
            vs_battle_setFramebufferEffectUsePreviousFrame(0);
            setFramebufferEffect(0);
        } else {
            setFramebufferEffect(1);
            vs_battle_setFramebufferEffectBlendMode(0);

            values.vx = 0;
            values.vy = 2;

            vs_battle_setFramebufferEffectOffset(&values);

            values.vx = values.vy = ONE;

            vs_battle_setFramebufferEffectScale(&values);

            color.r = color.g = color.b = 144;

            vs_battle_setFramebufferEffectUsePreviousFrame(1);
            vs_battle_setFramebufferEffectTint(&color);
            vs_battle_setFramebufferEffectDepth(mode);
        }

        return scriptNext;
    }
}

/** Steps the tweens of the frame buffer effect and the lens distortion. */
static void updateScreenEffectTweens(void)
{
    VECTOR vector;
    CVECTOR color;

    if (stepScreenEffectTween(&scriptCamera->framebufferScale) != 0) {
        vector.vx = scriptCamera->framebufferScale.value.vx;
        vector.vy = scriptCamera->framebufferScale.value.vy;

        vs_battle_setFramebufferEffectScale(&vector);
    }

    if (stepScreenEffectTween(&scriptCamera->framebufferTint) != 0) {
        color.r = scriptCamera->framebufferTint.value.vx;
        color.g = scriptCamera->framebufferTint.value.vy;
        color.b = scriptCamera->framebufferTint.value.vz;

        vs_battle_setFramebufferEffectTint(&color);
    }

    if (stepScreenEffectTween(&scriptCamera->framebufferOffset) != 0) {
        vector.vx = scriptCamera->framebufferOffset.value.vx;
        vector.vy = scriptCamera->framebufferOffset.value.vy;

        vs_battle_setFramebufferEffectOffset(&vector);
    }

    if (stepScreenEffectTween(&scriptCamera->lensDistortion) != 0) {
        setScreenLensDistortion(
            scriptCamera->lensDistortion.value.vx, scriptCamera->lensDistortion.value.vy);
    }
}

/** Steps a screen effect tween by one frame, returns whether it has a new value. */
static int stepScreenEffectTween(ScreenEffectTween* tween)
{
    if (tween->duration == 0) {
        return 0;
    }

    tween->elapsed += vs_gametime_vblanksPerFrame >> 1;

    CAMERA_SCRATCH->i1 = evaluateEasing(tween->ease, tween->elapsed, tween->duration);

    tween->value.vx = tween->start.vx + ((tween->delta.vx * CAMERA_SCRATCH->i1) >> 12);
    tween->value.vy = tween->start.vy + ((tween->delta.vy * CAMERA_SCRATCH->i1) >> 12);
    tween->value.vz = tween->start.vz + ((tween->delta.vz * CAMERA_SCRATCH->i1) >> 12);

    if (tween->elapsed == tween->duration) {
        tween->duration = 0;
    }

    return 1;
}

/**
 * Sets the projection distance, clip distances and shake of the camera. Opcode EE also
 * uses this handler, but does nothing and does not return a result.
 * @param script Opcode bytes, see the comments on each opcode.
 */
int vs_battle_script_EA_EB_EC_EE_EF_camera(u_char* script, UNUSED short slot)
{
    ShakeEntry* entry;
    short i;

    switch (script[0]) {
    // Tweens the projection distance.
    // [1] = projection distance (<< 2), 0 = default, [2] = easing, [3] = tween duration,
    // 0 = immediate.
    case 0xEA:
        if ((scriptCamera->projectionDistance.duration = script[3]) == 0) {
            scriptCamera->projectionDistance.value =
                script[1] ? (script[1] << 2) : ONE / 8;
            scriptCamera->projectionDistance.changed = 1;
        } else {
            scriptCamera->projectionDistance.delta =
                script[1] ? (script[1] << 2)
                                - (scriptCamera->projectionDistance.start =
                                        scriptCamera->projectionDistance.value)
                          : ONE / 8;
            scriptCamera->projectionDistance.ease = script[2];
            scriptCamera->projectionDistance.elapsed = 0;
        }

        return scriptNext;

    // Tweens the near clip distance.
    // [1] = distance, 0 = default, [2] = easing, [3] = tween duration, 0 = immediate.
    case 0xEB:
        if ((scriptCamera->nearClip.duration = script[3]) == 0) {
            scriptCamera->nearClip.value = script[1] ? script[1] : 64;
            scriptCamera->nearClip.changed = 1;
        } else {
            scriptCamera->nearClip.delta =
                (script[1] ? script[1] : 64)
                - (scriptCamera->nearClip.start = scriptCamera->nearClip.value);
            scriptCamera->nearClip.ease = script[2];
            scriptCamera->nearClip.elapsed = 0;
        }

        return scriptNext;

    // Tweens the far clip distance.
    // [1] = distance (<< 7), 0 = default, [2] = easing, [3] = tween duration, 0 =
    // immediate.
    case 0xEC:
        if ((scriptCamera->farClip.duration = script[3]) == 0) {
            scriptCamera->farClip.value = script[1] ? (script[1] << 7) : ONE;
            scriptCamera->farClip.changed = 1;
        } else {
            scriptCamera->farClip.delta =
                script[1]
                    ? (script[1] << 7)
                          - (scriptCamera->farClip.start = scriptCamera->farClip.value)
                    : ONE;
            scriptCamera->farClip.ease = script[2];
            scriptCamera->farClip.elapsed = 0;
        }

        return scriptNext;

    // Starts a camera shake in one of the two slots, or stops all shakes.
    // [1] = number of oscillations, [2] = amplitude in world units, 0 stops all shakes,
    // [3] = bit 0 shakes the look-at, bit 1 shakes the eye, bits 2-3, 4-5 and 6-7 are the
    // weights of the shake along x, y and z, minus 1. The shake is turned by the heading
    // of the camera, so x is sideways and z along the view.
    // [4] = envelope, 0 = constant, 1 = fades out, 2 = swells then fades, 3 = fades in,
    // [5] = duration.
    case 0xEF:
        entry = scriptCamera->shakeEntries;

        if (script[2] == 0) {
            entry[0].duration = entry[1].duration = 0;

            return scriptNext;
        }

        for (i = 0; i < 2; ++i, ++entry) {
            if (entry->duration == 0) {
                entry->cycles = script[1];
                entry->amplitude = script[2];
                entry->flags = script[3];
                entry->envelope = script[4];
                entry->duration = script[5];
                entry->elapsed = 0;
                break;
            }
        }

        return scriptNext;
    }
}

/** Steps a projection parameter tween by a frame. */
static void stepProjectionTween(ProjectionTween* tween)
{
    if (tween->duration == 0) {
        return;
    }

    tween->elapsed += vs_gametime_vblanksPerFrame >> 1;

    if (tween->duration < tween->elapsed) {
        tween->elapsed = tween->duration;
    }

    CAMERA_SCRATCH->i1 = evaluateEasing(tween->ease, tween->elapsed, tween->duration);

    tween->value = tween->start + ((tween->delta * CAMERA_SCRATCH->i1) >> 0xC);

    if (tween->elapsed == tween->duration) {
        tween->duration = 0;
    }

    tween->changed = 1;
}

/** Steps a shake entry by one frame, returns whether it is active. */
static int stepShakeEntry(ShakeEntry* entry)
{
    int angleRange = entry->cycles * ONE;

    if (entry->duration == 0) {
        return 0;
    }

    entry->elapsed += vs_gametime_vblanksPerFrame >> 1;

    if (entry->duration < entry->elapsed) {
        entry->elapsed = entry->duration;
    }

    switch (entry->envelope) {
    case 0:
        CAMERA_SCRATCH->i1 = ONE;
        break;

    case 1:
        CAMERA_SCRATCH->i1 = rsin(entry->elapsed * (ONE / 4) / entry->duration + ONE / 4);
        break;

    case 2:
        CAMERA_SCRATCH->i1 = rsin(entry->elapsed * (ONE / 2) / entry->duration);
        break;

    case 3:
        CAMERA_SCRATCH->i1 = rsin(entry->elapsed * (ONE / 4) / entry->duration);
        break;
    }

    entry->offset =
        (((rsin((angleRange * entry->elapsed) / entry->duration) * entry->amplitude)
             >> 12)
            * CAMERA_SCRATCH->i1)
        >> 12;

    if (entry->elapsed == entry->duration) {
        entry->duration = 0;
    }

    return 1;
}

/**
 * Sums the active shake entries for the look-at and the eye.
 */
static void updateCameraShake(void)
{
    short count = 0;
    CameraScratch* clear = CAMERA_SCRATCH;
    short i = 0;
    CameraScratch* scratch;
    ShakeEntry* entry = scriptCamera->shakeEntries;
    clear->s2.vx = clear->s2.vy = clear->s2.vz = 0;
    clear->s1.vx = clear->s1.vy = clear->s1.vz = 0;
    scratch = CAMERA_SCRATCH;

    for (; i < 2; ++entry, ++i) {
        int x;
        int y;
        int z;

        if (!stepShakeEntry(entry)) {
            continue;
        }

        x = entry->offset * (((entry->flags >> 2) & 3) - 1);
        scratch->s3.vx = x;

        y = entry->offset * (((entry->flags >> 4) & 3) - 1);
        scratch->s3.vy = y;

        z = entry->offset * ((entry->flags >> 6) - 1);
        scratch->s3.vz = z;

        if (entry->flags & 1) {
            applyVector(&scratch->s1, x, y, z, +=);
        }

        if (entry->flags & 2) {
            addVector(&scratch->s2, &scratch->s3);
        }

        ++count;
    }

    scriptCamera->shakeCount = count;

    if (count) {
        // The totals in lookAt and eye are read back at their fixed addresses and not as
        // members, which the match needs.
        scriptCamera->shakeLookAt.vx = VS_SCRATCH_AT(SVECTOR*, 0xD8)->vx;
        scriptCamera->shakeLookAt.vy = VS_SCRATCH_AT(SVECTOR*, 0xD8)->vy;
        scriptCamera->shakeLookAt.vz = VS_SCRATCH_AT(SVECTOR*, 0xD8)->vz;
        scriptCamera->shakeEye.vx = VS_SCRATCH_AT(SVECTOR*, 0xE0)->vx;
        scriptCamera->shakeEye.vy = VS_SCRATCH_AT(SVECTOR*, 0xE0)->vy;
        scriptCamera->shakeEye.vz = VS_SCRATCH_AT(SVECTOR*, 0xE0)->vz;
    }
}

/**
 * Sets whether the look-at and eye carry their momentum over from the end of a move into
 * the next one, see opcode DF.
 * @param lookAt 1 to carry the look-at's momentum.
 * @param eye 1 to carry the eye's momentum.
 */
void setCameraMomentum(int lookAt, int eye)
{
    scriptCamera->lookAt.carryMomentum = lookAt;
    scriptCamera->lookAt.carrying = 0;
    scriptCamera->eye.carryMomentum = eye;
    scriptCamera->eye.carrying = 0;
}

/**
 * Stops the look-at and eye wherever they are, cancelling their moves and dropping any
 * momentum.
 */
static void stopCamera(void)
{
    ScriptCamera* c1 = scriptCamera;
    ScriptCamera* c2;

    c1->eye.mode = cameraModeIdle;
    c1->lookAt.mode = cameraModeIdle;

    c2 = scriptCamera;

    c2->eye.carrying = 0;
    c2->eye.carryMomentum = 0;
    c2->lookAt.carrying = 0;
    c2->lookAt.carryMomentum = 0;
}

/**
 * Sweeps the camera into the view the player had before the scene (the facing and zoom
 * saved in state flags 0xAF and 0xB0), coming in from above and from one side: the eye
 * orbits and the look-at moves to it.
 * @param side 0 or 1, which side the camera comes in from.
 */
void sweepCameraToSavedPlayerView(u_char side)
{
    VECTOR startLookAt;
    VECTOR endLookAt;
    VECTOR startEye;
    VECTOR endEye;
    u_char facing = getStateFlag(savedCameraFacing);
    u_char zoom = getStateFlag(savedCameraZoom);
    int startFacing = facing - 1;

    initialiseCameraFromSpherical(
        &startEye, &startLookAt, (startFacing + (side * 2)) & 7, zoom + 1);

    startEye.vy += sweepHeightOffsets[zoom] * ONE;
    startLookAt.vy += sweepHeightOffsets[zoom] * ONE;

    vectorCopy(&scriptCamera->lookAt.current, &startLookAt);
    vectorCopy(&scriptCamera->lookAt.otherPosition, &startEye);
    vectorCopy(&scriptCamera->eye.otherPosition, &startLookAt);
    vectorCopy(&scriptCamera->eye.current, &startEye);

    scriptCamera->lookAt.mode = cameraModeIdle;

    initialiseCameraFromSpherical(&endEye, &endLookAt, facing, zoom + 1);

    vectorCopy(&scriptCamera->eye.position, &endEye);
    vectorCopy(&scriptCamera->lookAt.position, &endLookAt);

    vs_battle_script_Cx_Dx_camera(sweepEyeScript, 0);
    vs_battle_script_Cx_Dx_camera(sweepLookAtScript, 0);
}

/**
 * Rescales a camera move's duration, which is for a distance of 1000, to the distance
 * it has left to travel.
 */
static void scaleMoveDurationByDistance(CameraChannel* channel)
{
    VECTOR remaining;

    vectorSubtract(&remaining, &channel->current, &channel->position);
    channel->duration = ((vectorMagnitude(&remaining) >> 12) * channel->duration) / 1000;
}

/**
 * Scales the duration of a running camera move by the distance it has left to travel,
 * see scaleMoveDurationByDistance.
 * @param target 0 = look-at, 2 = both (taking the average of the two durations),
 * anything else = eye.
 */
void scaleCameraMoveDurationByDistance(short target)
{
    CameraChannel* lookAt = &scriptCamera->lookAt;
    CameraChannel* eye = &scriptCamera->eye;

    if (target == 2) {
        scaleMoveDurationByDistance(lookAt);
        scaleMoveDurationByDistance(eye);
        lookAt->duration = eye->duration = (lookAt->duration + eye->duration) >> 1;

        return;
    }

    scaleMoveDurationByDistance(target != 0 ? eye : lookAt);
}

/**
 * Adds two fixed-point vectors.
 * @param result Receives the sum, may be one of the operands.
 * @return result
 */
static VECTOR* vectorAdd(VECTOR* result, VECTOR* a, VECTOR* b)
{
    setVector(result, a->vx + b->vx, a->vy + b->vy, a->vz + b->vz);

    return result;
}

/**
 * Subtracts one fixed-point vector from another.
 * @param result Receives a - b, may be one of the operands.
 * @return result
 */
static VECTOR* vectorSubtract(VECTOR* result, VECTOR* a, VECTOR* b)
{
    setVector(result, a->vx - b->vx, a->vy - b->vy, a->vz - b->vz);

    return result;
}

/**
 * Multiplies a fixed-point vector by a fixed-point scalar.
 * @param result Receives the product, may be the same as vector.
 * @return result
 */
static VECTOR* vectorFixedPointMult(VECTOR* result, VECTOR* vector, int scalar)
{
    setVector(result, fixedPointMult(vector->vx, scalar),
        fixedPointMult(vector->vy, scalar), fixedPointMult(vector->vz, scalar));

    return result;
}

/**
 * Copies a vector.
 * @return destination
 */
static VECTOR* vectorCopy(VECTOR* destination, VECTOR* source)
{
    copyVector(destination, source);

    return destination;
}

/**
 * Gets the length of a fixed-point vector, as a fixed-point value.
 */
static int vectorMagnitude(VECTOR* vector)
{
    VECTOR integer;

    vectorCopy(&integer, vector);
    applyVector(&integer, 12, 12, 12, >>=);

    return SquareRoot0((integer.vx * integer.vx) + (integer.vy * integer.vy)
                       + (integer.vz * integer.vz))
         * ONE;
}

/**
 * Reads a vector of three 16-bit world coordinates from script bytes into a fixed-point
 * vector.
 * @param result Receives the vector.
 * @param script The six bytes.
 * @return result
 */
static VECTOR* readScriptVector(VECTOR* result, u_char* script)
{
    setVector(result, getShort(script) * ONE, getShort(script + 2) * ONE,
        getShort(script + 4) * ONE);

    return result;
}

/**
 * Converts an integer vector to a fixed-point one.
 * @return result
 */
static VECTOR* sVectorToFixedPointVector(VECTOR* result, SVECTOR* integer)
{
    result->vx = integer->vx * ONE;
    result->vy = integer->vy * ONE;
    result->vz = integer->vz * ONE;
    return result;
}

/**
 * Multiplies two fixed-point values, using a 64-bit intermediate product.
 */
static int fixedPointMult(int a, int b)
{
#ifdef NON_MATCHING
#define MULTIPLY_SHIFT_12(result, a, b) result = ((long long)(a) * (b)) >> 12
#else
#define MULTIPLY_SHIFT_12(result, a, b)                                                  \
    __asm__("mult       %1, %2;"                                                         \
            "mflo       $t0;"                                                            \
            "mfhi       $t1;"                                                            \
            "srl        $t0, 12;"                                                        \
            "sll        $t1, 20;"                                                        \
            "or         %0, $t0, $t1;"                                                   \
        : "=r"(result)                                                                   \
        : "r"(a), "r"(b))
#endif

    int result;
    MULTIPLY_SHIFT_12(result, a, b);
    return result;
#undef MULTIPLY_SHIFT_12
}

/**
 * Gets the angle of a fixed-point offset on the x and z axes, measured from the z axis
 * towards the x axis. A full turn is ONE.
 * @param x Offset along x.
 * @param z Offset along z.
 */
static int yawFromOffset(int x, int z) { return ratan2(x >> 6, z >> 6); }

/**
 * Builds the rotation for looking along a fixed-point vector, from its heading and pitch,
 * with no roll.
 * @param direction The vector to point along.
 * @param matrix Receives the rotation.
 */
static void vectorToLookMatrix(VECTOR* direction, MATRIX* matrix)
{
    SVECTOR angles;
    SVECTOR integer;

    integer.vx = direction->vx >> 12;
    integer.vy = direction->vy >> 12;
    integer.vz = direction->vz >> 12;
    angles.vy = ratan2(integer.vx, integer.vz);
    angles.vx = ratan2(
        integer.vy, SquareRoot0((integer.vx * integer.vx) + (integer.vz * integer.vz)));
    angles.vz = 0;

    RotMatrix_gte(&angles, matrix);
}

/**
 * Normalises a fixed-point vector, discarding its fractional part first.
 * @param vector The vector.
 * @param result Receives a vector of length ONE pointing the same way.
 */
static void normalizeVector(VECTOR* vector, VECTOR* result)
{
    VECTOR integer;

    setVector(&integer, vector->vx >> 12, vector->vy >> 12, vector->vz >> 12);
    VectorNormal(&integer, result);
}

/**
 * Loads the event data of a map.
 * @param triggerSection The map's table of event triggers, see requestEvent.
 * @param triggerSectionLen Size of triggerSection, 0 if there is none.
 * @param entryScript The script run when the map loads.
 * @param entryScriptLen Size of entryScript, 0 if there is none.
 * @param triggeredScripts A table of up to 16 scripts that the triggers can start, those
 * with bit 15 set in their event id.
 * @param triggeredScriptsLen Size of triggeredScripts, 0 if there is none.
 * @param firstLoad 1 for the first map loaded after entering the battle overlay.
 * @return 1 if the map was loaded by a warp that continues the running script, otherwise
 * 0.
 */
int loadMpdEventSections(void* triggerSection, u_short triggerSectionLen,
    void* entryScript, u_short entryScriptLen, void* triggeredScripts,
    u_short triggeredScriptsLen, int firstLoad)
{
    vs_battle_setStateFlag(0xA9, 0);

    if (firstLoad == 0) {
        short i;
        for (i = 32; i < 64; ++i) {
            vs_battle_setStateFlag(i, 0);
        }
    }

    if (triggerSectionLen != 0) {
        mpdTriggerSection = vs_main_allocHeap(triggerSectionLen);
        memcpy(mpdTriggerSection, triggerSection, triggerSectionLen);
    } else {
        mpdTriggerSection = NULL;
    }

    if (triggeredScriptsLen != 0) {
        mpdTriggeredScripts = vs_main_allocHeap(triggeredScriptsLen);
        memcpy(mpdTriggeredScripts, triggeredScripts, triggeredScriptsLen);
    } else {
        mpdTriggeredScripts = NULL;
    }

    if (scriptWarpState == scriptWarpResume) {
        scriptWarpState = scriptWarpArrived;
        return 1;
    }

    if (scriptWarpState == scriptWarpEnd) {
        eventState = eventIdle;
        scriptWarpState = scriptWarpIdle;
        eventReady = 0;
    }

    mpdEntryScriptPending = entryScriptLen != 0;

    if (mpdEntryScriptPending != 0) {
        memcpy(evtBuffer, entryScript, entryScriptLen);
    }

    return 0;
}

/**
 * Gets the state of the current event.
 * @return An EventState value.
 */
short getEventState(void) { return eventState; }

/**
 * Gets an id for the current event.
 * @return The EventSource in the top nibble, below it the number of the EVT file or
 * triggered script, if relevant.
 */
short getEventId(void) { return (eventSource << 12) | evtFile; }

/**
 * Releases the event data of the current map, the counterpart of loadMpdEventSections.
 */
void unloadMpdEventSections(void)
{
    if (scriptWarpState == scriptWarpEnd) {
        releaseScriptControl();
    }
    if (mpdTriggerSection != 0) {
        vs_main_freeHeap(mpdTriggerSection);
    }
    if (mpdTriggeredScripts != 0) {
        vs_main_freeHeap(mpdTriggeredScripts);
    }
}

/**
 * Clears the zone flags.
 * @param firstLoad If nonzero, does nothing.
 */
void resetZoneFlags(int firstLoad)
{
    if (firstLoad == 0) {
        short i;
        for (i = 64; i < 128; ++i) {
            vs_battle_setStateFlag(i, 0);
        }
    }
}

void zoneUnloadNop(void) { }

/**
 * Gets a state flag.
 * @param id Index of the flag, see vs_Flags.
 */
char getStateFlag(short id)
{
    char* flags = (char*)&vs_main_stateFlags;

    return flags[id];
}

/**
 * Sets a state flag.
 * @param id Index of the flag, see vs_Flags.
 */
void vs_battle_setStateFlag(short id, char value)
{
    char* flags = (char*)&vs_main_stateFlags;

    flags[id] = value;
}

/**
 * Signals that the game is ready for the requested event to start. Does nothing if no
 * event is requested.
 * @return Always 1.
 */
int signalEventReady(void)
{
    if (eventState == eventRequested) {
        eventReady = 1;
        return 1;
    }
    return 1;
}

/**
 * Requests the event of the first of the map's triggers that matches a kind of check, or
 * a specific event.
 *
 * @param trigger One or more EventTrigger values.
 * @param arg1 With eventTriggerForced, the EVT file. With eventTriggerInteract and mode
 * 0, the actor that interacted.
 * @param arg2 With eventTriggerInteract, the actor that was interacted with if mode is 0,
 * or a pointer to the tile if mode is 1.
 * @param mode 0 or 1, see arg2.
 * @return An EventRequestResult.
 */
short requestEvent(short trigger, int arg1, int arg2, short mode)
{
    enum {
        conditionPlayerOnTile = 1,
        conditionPlayerInRectangle,
        conditionFlagVsValue,
        conditionActorExists,
        conditionActorRoleCount,
        conditionInteractActors,
        conditionActorHpPercent,
        conditionInteractFacingTile,
        conditionPlayerStopped,
        conditionItemOwned,
        conditionUnk11,
        conditionUnk12,
        conditionActorOnTile,
        conditionActorInRectangle,
        conditionFlagVsFlag,
        conditionUnk16,
        conditionNot = 0xFE,
        conditionsEnd = 0xFF,
    };

    char buf[64];
    vs_ActorPosition position;
    short i;
    short otherActorId;
    short flagId;
    short actorId;
    short flagValue;
    int conditionMet;
    short negate;
    short eventId;
    u_char* data;
    short left;
    int right;

    if (trigger == eventTriggerPoll) {
        if (eventState == eventIdle) {
            return eventRequestNone;
        }

        return eventRequestBusy;
    }

    if (trigger == eventTriggerMapLoad) {
        int pending = mpdEntryScriptPending;

        if (pending & 1) {
            mpdEntryScriptPending = 0;
            eventState = eventRequested;
            eventSource = eventFromEntryScript;
            D_800F4BA8 = 1;

            return eventRequestMade;
        }
    }

    if (trigger == eventTriggerForced) {
        evtFile = arg1;
        eventSource = eventFromEvt;
        eventState = eventRequested;
        D_800F4BA8 = 1;

        return eventRequestMade;
    }

    if (eventState != eventIdle && D_800F4BA8 != 0) {
        return eventRequestBusy;
    }

    for (i = 0; i < 16; ++i) {
        u_short offset = ((u_short*)mpdTriggerSection)[i];

        if (offset == 0xFFFF) {
            return eventRequestNone;
        }

        data = mpdTriggerSection + offset;

        if (!(*data & trigger)) {
            continue;
        }

        ++data;
        eventId = getShort(data);
        data += 2;
        negate = 0;

        while (1) {
            conditionMet = 0;

            switch (*data) {
            case conditionsEnd:
                if (eventId & 0x8000) {
                    evtFile = eventId & 0xF;
                    eventSource = eventFromTriggeredScripts;
                } else {
                    evtFile = eventId;
                    eventSource = eventFromEvt;
                }

                eventState = eventRequested;
                D_800F4BA8 = 0;

                return eventRequestMade;

            case conditionPlayerOnTile:
                vs_battle_getActorPosition(0, &position);

                if (position.unk0.unk0.x == data[1] && position.unk0.unk0.z == data[2]) {
                    conditionMet = 1;
                }

                data += 3;
                break;

            case conditionPlayerInRectangle:
                vs_battle_getActorPosition(0, &position);

                if (position.unk0.unk0.x >= data[1]
                    && position.unk0.unk0.x < data[1] + data[3]
                    && position.unk0.unk0.z >= data[2]
                    && position.unk0.unk0.z < data[2] + data[4]) {
                    conditionMet = 1;
                }

                data += 5;
                break;

            case conditionFlagVsValue:
                left = getStateFlag(((data[1] & 0xF) << 6) | (data[2] >> 2));
                right = data[3];
                goto compare;

            case conditionFlagVsFlag:
                left = getStateFlag(((data[1] & 0xF) << 6) | (data[2] >> 2));
                right = getStateFlag(((data[2] & 3) << 8) | data[3]);

            compare:
                switch (data[1] & 0xF0) {
                case flagComparisonLe:
                    if (left <= right) {
                        conditionMet = 1;
                    }
                    break;

                case flagComparisonGe:
                    if (left >= right) {
                        conditionMet = 1;
                    }
                    break;

                case flagComparisonEq:
                    if (left == right) {
                        conditionMet = 1;
                    }
                    break;

                case flagComparisonNe:
                    if (left != right) {
                        conditionMet = 1;
                    }
                    break;

                case flagComparisonLt:
                    if (left < right) {
                        conditionMet = 1;
                    }
                    break;

                case flagComparisonGt:
                    if (left > right) {
                        conditionMet = 1;
                    }
                    break;
                }

                data += 4;
                break;

            case conditionActorExists:
                left = getShort(data + 1);

                if (left & 0x1000) {
                    if (getActor(left & 0x1F) != NULL) {
                        conditionMet = 1;
                    }
                } else if (getActorSlotById(left) != 1) {
                    conditionMet = 1;
                }

                data += 3;
                break;

            case conditionActorRoleCount:
                left = flagValue = countActorsByRole(data[1]);
                flagId = getShort(data + 2);

                if (flagId != 0) {
                    vs_battle_setStateFlag(flagId, flagValue);
                    conditionMet = 1;
                } else if (left != 0) {
                    conditionMet = 1;
                }

                data += 4;
                break;

            case conditionInteractActors:
                if (mode == 0) {
                    actorId = resolveActorId(getShort(data + 1));
                    otherActorId = resolveActorId(getShort(data + 3));

                    if (actorId != 1 && otherActorId != 1 && arg1 == actorId
                        && arg2 == otherActorId) {
                        conditionMet = 1;
                    }
                }

                data += 5;
                break;

            case conditionActorHpPercent:
                actorId = resolveActorId(getShort(data + 1));

                if (actorId == 1) {
                    negate = 0;
                    break;
                }

                left = flagValue = getActorHpPercent(actorId);
                flagId = getShort(data + 3);

                if (flagId != 0) {
                    vs_battle_setStateFlag(flagId, flagValue);
                    conditionMet = 1;
                } else if (left != 0) {
                    conditionMet = 1;
                }

                data += 5;
                break;

            case conditionInteractFacingTile:
                if (mode == 1 && ((u_char*)arg2)[0] == data[1]
                    && ((u_char*)arg2)[2] == data[2]) {
                    conditionMet = 1;
                }

                data += 3;
                break;

            case conditionPlayerStopped:
                if (!(vs_battle_getActorFlags(0) & 0x104000)) {
                    conditionMet = 1;
                }

                ++data;
                break;

            case conditionItemOwned:
                left = flagValue = itemIdIsInInventory(getShort(data + 1));
                flagId = getShort(data + 3);

                if (flagId != 0) {
                    vs_battle_setStateFlag(flagId, flagValue);
                    conditionMet = 1;
                } else if (left != 0) {
                    conditionMet = 1;
                }

                data += 5;
                break;

            case conditionUnk11:
                if ((short)func_800A0024(data[1], &position.unk0) >= 0
                    && position.unk0.unk0.x == data[2] && position.unk0.unk0.z == data[3]
                    && (data[4] == 0 || -(position.unk0.unk4.vy / 128) + 1 == data[4])
                    && (data[5] == 0 || (position.unk0.unk0.extra >> 2) + 1 == data[5])) {
                    conditionMet = 1;
                }

                data += 6;
                break;

            case conditionUnk12:
                left = flagValue = -func_800A92B8(data[1], data[2]) / 128;
                flagId = getShort(data + 3);

                if (flagId != 0) {
                    vs_battle_setStateFlag(flagId, flagValue);
                    conditionMet = 1;
                } else if (left != 0) {
                    conditionMet = 1;
                }

                data += 5;
                break;

            case conditionActorOnTile:
                actorId = resolveActorId(getShort(data + 1));

                if (actorId == 1) {
                    negate = 0;
                    break;
                }

                vs_battle_getActorPosition(actorId, &position);

                if (position.unk0.unk0.x == data[3] && position.unk0.unk0.z == data[4]) {
                    conditionMet = 1;
                }

                data += 5;
                break;

            case conditionActorInRectangle:
                actorId = resolveActorId(getShort(data + 1));

                if (actorId == 1) {
                    negate = 0;
                    break;
                }

                vs_battle_getActorPosition(actorId, &position);

                if (position.unk0.unk0.x >= data[3]
                    && position.unk0.unk0.x < data[3] + data[5]
                    && position.unk0.unk0.z >= data[4]
                    && position.unk0.unk0.z < data[4] + data[6]) {
                    conditionMet = 1;
                }

                data += 7;
                break;

            case conditionUnk16:
                actorId = resolveActorId(getShort(data + 1));

                if (actorId == 1) {
                    negate = 0;
                    break;
                }

                if (func_8007CFCC(actorId) != 0) {
                    conditionMet = 1;
                }

                data += 3;
                break;

            case conditionNot:
                negate = 1;
                ++data;
                continue;

            default:
                sprintf(buf, "UNKNOWN TRIGGER DETECTED:%02x", *data);
                break;
            }

            if (conditionMet == negate) {
                break;
            }

            negate = 0;
        }
    }
}

/**
 * Sets up the engine to run an event's scripts, resetting everything they share.
 * @param data The event, with offsets to the strings at +2, to the text box shapes after
 * the built in ones at +4, to the vibration patterns at +6, and the script at +0x10.
 */
static void initEvent(u_char* data)
{
    short i;
    u_char* shapes;
    u_char* vibration;

    scriptStrings = (u_short*)(data + *(u_short*)(data + 2));
    shapes = data + *(u_short*)(data + 4);

    for (i = 9; i < 16; ++i) {
        textBoxShapes[i] =
            ((u_short*)shapes)[i - 8] ? shapes + ((u_short*)shapes)[i - 8] : 0;
    }

    vibration = data + *(u_short*)(data + 6);

    for (i = 0; i < 8; ++i) {
        vibrationPatterns[i] =
            ((u_short*)vibration)[i] ? (char*)vibration + ((u_short*)vibration)[i] : 0;
    }

    scriptSlots[0] = data + 16;
    scriptSlots[1] = scriptSlots[2] = scriptSlots[3] = 0;
    scriptSkipMode = scriptSkipOff;
    skipRequested = 0;

    vs_battle_setStateFlag(skippingScene, 0);

    scriptWaitFrames[1] = scriptWaitFrames[2] = scriptWaitFrames[3] = 0;
    effectCancelled = 0;
    weaponAnimating = 0;
    textBoxSelectionPending = 0;
    scanlinesEnabled = 0;
    scriptMenuState = scriptMenuClosed;
    scriptWarpState = scriptWarpIdle;
    cameraReturned = 0;
    scriptWaitFrames[0] = 0;
    mainScriptEnded = 0;

    for (i = 0; i < 8; ++i) {
        textBoxStatuses[i] = 0;
    }

    for (i = 0; i < 4; ++i) {
        customEasings[i].curve = customEasings[i].power = 0;
    }

    D_800F4B8B = 0;
    gimTweens[0].duration = gimTweens[1].duration = gimTweens[2].duration = 0;
    scriptMusicSlot = vs_main_getcurrentMusicSlot();
    evtCdSlot = NULL;

    for (i = scriptScratch; i < scriptScratch + 16; ++i) {
        vs_battle_setStateFlag(i, 0);
    }
}

/**
 * Starts or advances the event system by one frame.
 * @return eventRequestBusy while an event is starting, loading or running, otherwise
 * eventRequestNone.
 */
int updateEvent(void)
{
    short i;
    UNUSED int _[2];

    if (eventState == eventIdle) {
        return eventRequestNone;
    }

    if (eventState == eventRequested) {
        if (eventReady != 0) {
            eventState = eventStarting;
            eventReady = 0;
            initScriptCamera();
            func_8007CEC0();

            for (i = 0; i < 17; ++i) {
                actorMoved[i] = 0;
            }

            return eventRequestBusy;
        }

        return eventRequestNone;
    }

    if (eventState == eventStarting) {
        fogDepthOverridden = 0;
        nextEvtQueued = 0;

        switch (eventSource) {
        case eventFromEntryScript:
            initEvent(evtBuffer);
            eventState = eventRunning;
            break;

        case eventFromTriggeredScripts:
            initEvent(mpdTriggeredScripts + ((short*)mpdTriggeredScripts)[evtFile]);
            eventState = eventRunning;
            break;

        case eventFromEvt:
            loadEvt(evtFile, evtBuffer);
            eventState = eventLoading;
            break;
        }

        return eventRequestBusy;
    }

    if (eventState == eventLoading) {
        if (evtCdSlot->state == CdQueueStateLoaded) {

            vs_main_freeCdQueueSlot(evtCdSlot);

            if (nextEvtQueued != 0) {
                vs_main_memcpy(evtBuffer, nextEvtBuffer, 0x1800);
                vs_main_freeHeapR(nextEvtBuffer);

                nextEvtQueued = 0;
            }

            initEvent(evtBuffer);

            eventState = eventRunning;
        }

        return eventRequestBusy;
    }

    updateCameraAttachment();

    if (mainScriptEnded == 0) {
        if (runScript(scriptSlots, 0) != 0) {
            if (cameraReturned == 0 && nextEvtQueued == 0
                && scriptWarpState == scriptWarpIdle) {
                returnToGameplayCamera(-1, -1);
            }

            mainScriptEnded = 1;
        }

        for (i = 1; i < 4; ++i) {
            if (scriptSlots[i] != NULL) {
                runScript(&scriptSlots[i], i);
            }
        }
    }

    updateCamera();
    updateScreenEffectTweens();
    applyCameraState();
    updateGimTweens();
    updateParticleTween();

    if (scanlinesEnabled != 0) {
        drawScanlines();
    }

    if (mainScriptEnded != 0 && getCameraIdleFlags() == cameraIdleAll) {
        if (nextEvtQueued != 0) {
            eventState = eventLoading;
            eventSource = eventFromEvt;
        } else {
            releaseScriptControl();
            eventState = eventIdle;
        }

        mainScriptEnded = 0;
    }

    return eventRequestBusy;
}
