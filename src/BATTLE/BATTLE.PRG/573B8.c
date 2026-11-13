#include "common.h"
#include "actorPrivate.h"
#include "573B8Private.h"
#include "146CPrivate.h"
#include "4DEA8Private.h"
#include "battleUi.h"
#include "src/SLUS_010.40/cd.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"
#include "build/src/include/lbas.h"
#include <libetc.h>

typedef struct {
    u_char curve;
    signed char power;
} D_800F4B28_t;

extern int (*normalOpcodeTable[])(u_char*, short);
extern vs_CdFile D_800F4BF0;

int func_800BFE34(u_char*);
void func_800C0150(void);

extern unsigned char D_800F4B70[17];
extern D_800F4B28_t D_800F4B28[];

short func_800BFBB8(u_char** arg0, short arg1)
{
    int ret;
    u_char* script = *arg0;

    if ((arg1 == 0) && (scriptSkipMode == vs_battle_scriptSkippable)
        && ((vs_main_buttonsPressed.all & PADstart) || (skipRequested != 0))) {
        skipRequested = 0;
        D_800F4C58[3] = 0;
        D_800F4C58[2] = 0;
        D_800F4C58[1] = 0;
        D_800F4C58[0] = 0;
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
        func_8007C46C(0, 0xFF, 0);
        vs_battle_disableDispMask();
        vs_battle_setStateFlag(0xA8, 1);
        scriptSkipMode = vs_battle_scriptSkipping;
    }

    while (1) {
        if (scriptSkipMode != vs_battle_scriptSkipping) {
            ret = normalOpcodeTable[*script](script, arg1);
        } else {
            ret = vs_battle_skipOpcodeTable[*script](script, arg1);
        }

        switch (ret) {
        case 0:
            script += func_800BFE34(script);
            continue;

        case 1:
            break;

        case 3:
            *arg0 = NULL;
            return 0;

        case 2:
            return 1;

        case 4:
            script += func_800BFE34(script);
            break;

        default:
            script = (u_char*)ret;
            continue;
        }

        *arg0 = script;
        return 0;
    }
}

void func_800BFD9C(void)
{
    int i;

    for (i = 0; i < 17; i++) {
        if (D_800F4B70[i] != 0) {
            func_8007D260(i);
        }
    }

    func_800BBDDC();
}

short getShort(u_char* arg0)
{
    if (!((long)arg0 & 1)) {
        return *(short*)arg0;
    }
    return arg0[0] | (arg0[1] << 8);
}

int func_800BFE34(u_char* arg0) { return D_800E9C30[arg0[0]]; }

int resolveActorId(u_short arg0)
{
    switch (arg0 >> 12) {
    case 0:
        return func_8007CF18(arg0 & 0xFFF);
    case 1:
        return arg0 & 0x1F;
    case 2:
        return arg0;
    }
}

int func_800BFEBC(short mode, short frame, short duration)
{
    short position = frame;
    int value;
    int power;
    int i;

    if (frame > duration) {
        position = duration;
    }

    switch (mode) {
    case 0:
        return position * ONE / duration;
    case 1:
        return rsin(position * (ONE / 4) / duration);
    case 2:
        return (rcos(position * (ONE / 2) / duration + ONE / 2) + ONE) >> 1;
    case 3:
        return rsin(position * (ONE / 4) / duration - ONE / 4) + ONE;
    default:
        mode -= 4;
        power = D_800F4B28[mode].power;
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

        switch (D_800F4B28[mode].curve) {
        case 1:
            return rsin(value / 4);
        case 2:
            return (rcos(value / 2 + ONE / 2) + ONE) >> 1;
        case 3:
            return rsin(value / 4 - ONE / 4) + ONE;
        case 0:
        default:
            return value;
        }
    }
}

void func_800C00E8(int arg0, void* arg1)
{
    D_800F4BF0.size = VS_0000_EVT_SIZE;
    D_800F4BF0.lba = (evtFile * 3) + VS_0000_EVT_LBA; // .EVT files must be sequential
    evtCdSlot = vs_main_allocateCdQueueSlot(&D_800F4BF0);
    vs_main_cdEnqueue(evtCdSlot, arg1);
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
