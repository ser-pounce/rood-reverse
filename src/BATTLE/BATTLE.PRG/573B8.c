#include "common.h"
#include "actorPrivate.h"
#include "573B8Private.h"
#include "146CPrivate.h"
#include "4DEA8Private.h"
#include "battleUi.h"
#include "src/SLUS_010.40/cd.h"
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"
#include "build/src/include/lbas.h"
#include <libetc.h>

extern int (*normalOpcodeTable[])(u_char*, short);
extern vs_CdFile D_800F4BF0;

int getOpcodeLength(u_char*);
void func_800C0150(void);

extern unsigned char actorMoved[17];

short func_800BFBB8(u_char** arg0, short arg1)
{
    int ret;
    u_char* script = *arg0;

    if ((arg1 == 0) && (scriptSkipMode == scriptSkippable)
        && ((vs_main_buttonsPressed.all & PADstart) || (skipRequested != 0))) {
        skipRequested = 0;
        scriptWaitFrames[3] = 0;
        scriptWaitFrames[2] = 0;
        scriptWaitFrames[1] = 0;
        scriptWaitFrames[0] = 0;
        textBoxStatuses[3] = 0;
        textBoxStatuses[2] = 0;
        textBoxStatuses[1] = 0;
        textBoxStatuses[0] = 0;

        if (stopMusicOnSkip != 0) {
            vs_main_stopMusicSlot(0);
        }

        vs_main_stopAllSfx();
        vs_main_stopVibration(0, 2);
        func_800C0150();
        startScreenTransitionOut(0, 0xFF, 0);
        vs_battle_disableDispMask();
        vs_battle_setStateFlag(skippingScene, 1);
        scriptSkipMode = scriptSkipping;
    }

    while (1) {
        if (scriptSkipMode != scriptSkipping) {
            ret = normalOpcodeTable[*script](script, arg1);
        } else {
            ret = vs_battle_skipOpcodeTable[*script](script, arg1);
        }

        switch (ret) {
        case 0:
            script += getOpcodeLength(script);
            continue;

        case 1:
            break;

        case 3:
            *arg0 = NULL;
            return 0;

        case 2:
            return 1;

        case 4:
            script += getOpcodeLength(script);
            break;

        default:
            script = (u_char*)ret;
            continue;
        }

        *arg0 = script;
        return 0;
    }
}

/**
 * Returns the actors and the camera that scripts have been controlling to the game.
 */
void releaseScriptControl(void)
{
    int i;

    for (i = 0; i < 17; i++) {
        if (actorMoved[i] != 0) {
            releaseActorControl(i);
        }
    }

    freeScriptCamera();
}

short getShort(u_char* arg0)
{
    if (!((long)arg0 & 1)) {
        return *(short*)arg0;
    }
    return arg0[0] | (arg0[1] << 8);
}

int getOpcodeLength(u_char* arg0) { return opcodeLengths[arg0[0]]; }

int resolveActorId(u_short arg0)
{
    switch (arg0 >> 12) {
    case 0:
        return getActorSlotById(arg0 & 0xFFF);
    case 1:
        return arg0 & 0x1F;
    case 2:
        return arg0;
    }
}

/**
 * Evaluates an easing curve.
 * @param mode Easing curve, see Easing.
 * @param frame Time elapsed, clamped to duration.
 * @param duration Total time.
 * @return Progress from 0 to ONE.
 */
int evaluateEasing(short mode, short frame, short duration)
{
    short position = frame;
    int value;
    int power;
    int i;

    if (frame > duration) {
        position = duration;
    }

    switch (mode) {
    case easingLinear:
        return position * ONE / duration;

    case easingSineOut:
        return rsin(position * (ONE / 4) / duration);

    case easingSineInOut:
        return (rcos(position * (ONE / 2) / duration + ONE / 2) + ONE) >> 1;

    case easingSineIn:
        return rsin(position * (ONE / 4) / duration - ONE / 4) + ONE;

    default:
        mode -= easingCustom0;
        power = customEasings[mode].power;
        value = position * ONE / duration;

        if (power != 0) {
            if (power > 0) {
                for (i = 0; i < power; ++i) {
                    value = (value * value) >> 12;
                }
            } else {
                value = ONE - value;

                for (i = 0; i < -power; ++i) {
                    value = (value * value) >> 12;
                }

                value = ONE - value;
            }
        }

        switch (customEasings[mode].curve) {
        case easingSineOut:
            return rsin(value / 4);

        case easingSineInOut:
            return (rcos(value / 2 + ONE / 2) + ONE) >> 1;

        case easingSineIn:
            return rsin(value / 4 - ONE / 4) + ONE;

        case easingLinear:
        default:
            return value;
        }
    }
}

/**
 * Starts loading an EVT file from disc.
 * @param file Unused, the file is taken from evtFile.
 * @param buffer Receives the file.
 */
void loadEvt(UNUSED int file, void* buffer)
{
    D_800F4BF0.size = VS_0000_EVT_SIZE;
    D_800F4BF0.lba = (evtFile * 3) + VS_0000_EVT_LBA; // .EVT files must be sequential
    evtCdSlot = vs_main_allocateCdQueueSlot(&D_800F4BF0);
    vs_main_cdEnqueue(evtCdSlot, buffer);
}

void func_800C0150(void)
{
    short i;

    for (i = 0; i < 17; ++i) {
        if (getActor(i) != NULL) {
            vs_battle_setActorAnimation(i, 1, 0, 0);
        }
    }
}
