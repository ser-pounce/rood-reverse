#include "common.h"
#include "573B8.h"
#include "146C.h"
#include "4DEA8.h"
#include "battleUi.h"
#include "build/src/include/lbas.h"
#include <libetc.h>

typedef struct {
    u_char curve;
    signed char power;
} D_800F4B28_t;

extern u_char D_800E9C30[];
extern int (*_opcodeFunctionTable[])(u_char*, short);
extern D_800F4B28_t D_800F4B28[];
extern unsigned char D_800F4B70[17];
extern vs_main_CdQueueSlot* D_800F4BBC;
extern vs_main_CdFile D_800F4BF0;

int func_800BFE34(u_char*);
void func_800C0150(void);

short func_800BFBB8(u_char** arg0, short arg1)
{
    int ret;
    u_char* script = *arg0;

    if ((arg1 == 0) && (D_800F4C2C == 1)
        && ((vs_main_buttonsPressed.all & PADstart) || (D_800F4C68 != 0))) {
        D_800F4C68 = 0;
        D_800F4C58[3] = 0;
        D_800F4C58[2] = 0;
        D_800F4C58[1] = 0;
        D_800F4C58[0] = 0;
        vs_battle_textBoxStatuses[3] = 0;
        vs_battle_textBoxStatuses[2] = 0;
        vs_battle_textBoxStatuses[1] = 0;
        vs_battle_textBoxStatuses[0] = 0;

        if (D_800F4C20 != 0) {
            func_80044DF4(0);
        }

        func_80045DC0();
        func_800434A4(0, 2);
        func_800C0150();
        func_8007C46C(0, 0xFF, 0);
        func_8007C424();
        vs_battle_setStateFlag(0xA8, 1);
        D_800F4C2C = 2;
    }

    while (1) {
        if (D_800F4C2C != 2) {
            ret = _opcodeFunctionTable[*script](script, arg1);
        } else {
            ret = D_800F4C28[*script](script, arg1);
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

short vs_battle_getShort(u_char* arg0)
{
    if (!((long)arg0 & 1)) {
        return *(short*)arg0;
    }
    return arg0[0] | (arg0[1] << 8);
}

int func_800BFE34(u_char* arg0) { return D_800E9C30[arg0[0]]; }

int func_800BFE50(u_short arg0)
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
    D_800F4BF0.lba = (_evtFile * 3) + VS_0000_EVT_LBA; // .EVT files must be sequential
    D_800F4BBC = vs_main_allocateCdQueueSlot(&D_800F4BF0);
    vs_main_cdEnqueue(D_800F4BBC, arg1);
}

void func_800C0150(void)
{
    short i;

    for (i = 0; i < 17; ++i) {
        if (func_8007CF64(i) != NULL) {
            func_800A0204(i, 1, 0, 0);
        }
    }
}
