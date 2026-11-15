#include "common.h"
#include "6E4CCShared.h"
#include "2842CPrivate.h"

#ifdef NON_MATCHING

void func_800D820C(int arg0, int arg1)
{
    if (arg0 != 0) {
        func_80095B7C(arg0, arg1);
    }
}

void func_800D821C(func_800E78F4_t* arg0)
{
    int id = arg0->unk88;

    func_800D820C(id, 0);
    func_800D820C(id, 0x40);
}

void func_800D8260(func_800E78F4_t* arg0, int arg1, int arg2)
{
    arg0->unk138 = arg1;
    arg0->unk12A = arg2;
}

int func_800D826C(func_800E78F4_t* arg0) { return arg0->unk8E >= 32; }

void func_800D8280(func_800E78F4_t* arg0)
{
    if (arg0->unk12A != 0) {
        if (--arg0->unk12A != 0) {
            func_800D820C(arg0->unk88, arg0->unk138);
        } else {
            func_800D820C(arg0->unk88, 0);
        }
    }
}

void func_800D82A8(int arg0)
{
    if (arg0 != 0 && D_800F5878[arg0] != NULL) {
        func_800D82CC(D_800F5878[arg0]);
    }
}

void func_800D82CC(func_800E78F4_t* arg0)
{
    int id = arg0->unk88;
    int bit = 1 << id;

    if (!(D_800F58BC->unk10 & bit)) {
        return;
    }

    D_800F58BC->unk10 &= ~bit;
    arg0->unk8E = 0;
    arg0->unk98 =
        vs_battle_actors[0] != NULL && vs_battle_actors[0]->next == NULL ? 0 : 48;
    arg0->unk9A = 90;
    func_800DBF00(arg0);
    --D_800F58BC->unk12;
    func_800D820C(id, 0);
}

int func_800D836C(func_800E78F4_t* arg0)
{
    if (arg0->unk8E != 0) {
        return 1;
    }

    if (D_800F58BC->unkD < D_800F58BC->unk12 || arg0->unk98 != 0 || D_800F58E0 != 0) {
        return 0;
    }

    arg0->unk12C = 0;
    arg0->unk8E = arg0->unk9A != 0 ? 32 : 1;
    D_800F58BC->unk10 |= 1 << arg0->unk88;
    ++D_800F58BC->unk12;

    if (D_800F58BC->unk1C == NULL) {
        D_800F58BC->unk20 = arg0;
    }

    arg0->unk1A0 = D_800F58BC->unk1C;
    D_800F58BC->unk1C = arg0;
    return 1;
}

#endif
