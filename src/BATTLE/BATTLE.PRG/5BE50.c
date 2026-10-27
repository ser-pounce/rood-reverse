#include "common.h"
#include "146C.h"
#include "30DB0.h"
#include "58578.h"
#include "573B8.h"
#include "5BF94.h"
#include "../../SLUS_010.40/main.h"
#include <memory.h>
#include <stddef.h>
#include <inline_c.h>
#include "vs_inline_c.h"

typedef struct {
    u_short unk0[3];
    u_char unk6;
    u_char unk7;
    u_char unk8;
    u_char unk9;
    signed char unkA;
    char unkB[0xD];
} func_800C4650_t;

void func_800C4650(func_800C4650_t* arg0, int arg1)
{
    int i;
    int type;

    for (i = 0; i < arg1; i++, arg0++) {
        type = arg0->unk9;
        if ((type >> 4) == 0) {
            if (func_800C1564(&D_800EB9B8->unk0[1], arg0->unk0)) {
                func_8009FD5C(type, 0, arg0->unkA);
            } else {
                func_8009FE74(type, arg0->unkA);
            }
        }
    }
}

int vs_battle_mapStickDeadZone(int arg0)
{
    if (arg0 < 64) {
        return arg0 - 64;
    }
    if (arg0 >= 192) {
        return arg0 - 192;
    }
    return 0;
}

int func_800C4734(void)
{
    if ((D_800EB9B8 == NULL) || (D_800EB9B8->unk2A != 0)) {
        return 0;
    }
    if ((D_800EB9B8->unk38.pad == 0) || (vs_main_buttonsState & 0x80)) {
        return 1;
    }
    return 2;
}
