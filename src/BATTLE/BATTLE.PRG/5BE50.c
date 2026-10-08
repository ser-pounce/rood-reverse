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
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    char unk6;
    char unk7;
    SVECTOR unk8;
    char* unk10;
} D_800EB9B8_unk990;

typedef struct {
    short xyz[3];
    short flags;
} menuShapeVertex;

typedef struct {
    func_800C1564_t unk0[2];
    short unk20;
    short unk22;
    short unk24;
    short unk26;
    short unk28;
    short unk2A;
    char unk2C;
    char unk2D;
    char unk2E;
    char unk2F;
    char unk30;
    char unk31;
    short unk32;
    int unk34;
    int unk38;
    short unk3C;
    short unk3E;
    int unk40[2];
    menuShapeVertex unk48[297];
    D_800EB9B8_unk990 unk990[24];
    char unkB70[0x3800];
    int unk4370[81];
    char unk44B4[0x604];
    u_char unk4AB8[81];
} D_800EB9B8_t;

typedef struct {
    u_short unk0[3];
    u_char unk6;
    u_char unk7;
    u_char unk8;
    u_char unk9;
    signed char unkA;
    char unkB[0xD];
} func_800C4650_t;

extern D_800EB9B8_t* D_800EB9B8;

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
    if ((D_800EB9B8->unk3E == 0) || (vs_main_buttonsState & 0x80)) {
        return 1;
    }
    return 2;
}
