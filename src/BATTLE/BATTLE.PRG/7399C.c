#include "common.h"
#include "6E4CCPrivate.h"
#include "6E4CCShared.h"
#include "146CPrivate.h"
#include "src/SLUS_010.40/memory.h"
#include <rand.h>

#ifdef NON_MATCHING

void func_800DC19C(func_800E78F4_t* arg0)
{
    arg0->unk126 = 0;

    if (arg0->unk13 == 0) {
        return;
    }

    arg0->unk13 = 0;
    func_800D820C(arg0->unk88, 0x40);
    func_800E7370(arg0);

    if (arg0->unk6C != NULL) {
        arg0->unk68 = arg0->unk6C;
    }

    arg0->unk6C = NULL;

    if (arg0->unk30 == 0) {
        func_800D8260(arg0, 6, 40);
        func_800E48A8(arg0, 2, 128);
    }
}

void func_800DC210(func_800E78F4_t* arg0, int arg1)
{
    if (arg1 == 0) {
        if ((rand() & 0x7F) >= 76) {
            return;
        }

        if (++arg0->unk126 < 2) {
            return;
        }
    }

    arg0->unk13 = 1;
    arg0->unk6C = arg0->unk68;
    arg0->unk68 = D_800DBC0C;
    func_800D820C(arg0->unk88, 0x80);
}

int func_800DC284(int arg0, int arg1, int arg2, int arg3)
{
    return arg0 * 6 + (short)arg1 * 4 + (short)arg2 + (short)arg3 * 2;
}

void func_800DC2E0(func_800DCAA0_t* arg0, func_800DCAA0_t* arg1) { *arg0 = *arg1; }

void func_800DC30C(short* arg0, short* arg1, int arg2, int arg3)
{
    int value = arg3 == 2 ? *arg0 + arg2 : *arg0 - arg2;

    if (value < 0) {
        value = 0;
    } else if (value > *arg1) {
        value = *arg1;
    }

    *arg0 = value;
}

void func_800DC344(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    int count = arg0->unk470;
    func_800DCAA0_t* entry;

    if (count >= 16 || arg1->unkC_19 == 0) {
        return;
    }

    D_800F5904[arg1->unkC_0][arg1->unk4_5] = 1;
    entry = &arg0->unk2F0[count];
    arg0->unk430[count] = entry;
    arg0->unk470 = count + 1;
    func_800DC2E0(entry, arg1);
}

void func_800DC3CC(func_800E78F4_t* arg0)
{
    if (arg0->unk470 != 0) {
        func_800E6958(arg0->unk430, 0, arg0->unk470 - 1);
    }
}

void func_800DC3E8(vs_ActorStats* src, vs_ActorStats* dst)
{
    dst->currentHP = src->currentHP;
    dst->maxHP = src->maxHP;
    dst->currentMP = src->currentMP;
    dst->maxMP = src->maxMP;
    dst->statuses = src->statuses;
    dst->unk30 = src->unk30;
    dst->unk31 = src->unk31;
    dst->unk32 = src->unk32;
    dst->unk33 = src->unk33;
    vs_main_memcpy(dst->limbs, src->limbs, sizeof dst->limbs);
}

void func_800DC424(func_800DC888_t* arg0)
{
    Actor* actor = vs_battle_actors[0];

    do {
        func_800DC888_t* row = &arg0[actor->id];
        vs_ActorStats* stats = actor->stats;

        row->unk0_0 = actor->id;
        row->unk0_4 = 0;
        row->unk4 = stats->currentHP;
        row->unk6 = stats->maxHP;
        row->unk8 = stats->currentMP;
        row->unkA = stats->maxMP;
        row->unkC = stats->statuses;
        row->unk10 = stats->weapon.currentDp;
        row->unk12 = stats->weapon.maxDp;
        row->unk14 = stats->shield.currentDp;
        row->unk16 = stats->shield.maxDp;
        actor = actor->next;
    } while (actor != NULL);
}

int func_800DC484(int arg0, int arg1)
{
    int flag = vs_main_actions[arg0].flagsE.unk14 >> 1;

    if (arg0 == 96 && vs_battle_actors[arg1]->stats->enemyClass == enemyClassUndead) {
        return flag ^ 1;
    }

    return flag;
}

int func_800DC48C(int arg0, int arg1)
{
    int flags = vs_main_actions[arg0].flagsE.unk14;

    if (arg0 == 96 && vs_battle_actors[arg1]->stats->enemyClass == enemyClassUndead) {
        return flags ^ 1;
    }

    return flags & 1;
}

void func_800DC4F0(func_800DCAA0_t* arg0, vs_Action* arg1)
{
    int bit = 1 << (arg0->unk4_0 * 4 + arg0->unk4_3);

    if (!arg1->flagsE.unk6 || (D_800F58F4 & bit)) {
        return;
    }

    D_800F58F4 |= bit;

    if (D_800F58F0 < 16) {
        func_800DC2E0(&D_800F58F8[D_800F58F0], arg0);
        ++D_800F58F0;
    }
}

void func_800DC574(func_800E78F4_t* arg0, int arg1)
{
    int i = 0;

    do {
        int roll = rand() & 0x7F;
        func_800DCAA0_t* entry = arg0->unk430[i];

        if (entry->unk4_5 != 0) {
            // Potential bug in original, needs investigating.
            // The test of unk2B branches to the next instruction and the
            // (unkC_19 + 76) / 2 it computes is overwritten, so the chance is unkC_19
            // capped at 76 either way.
            if (roll < MIN(entry->unkC_19, 76)) {
                arg0->unk430[i] = arg0->unk430[0];
                arg0->unk430[0] = entry;
                func_800E6958(arg0->unk430, 1, arg1 - 1);
                return;
            }
        }
    } while (++i < arg1);
}

void func_800DC638(void)
{
    SVECTOR points[13];
    u_int held;
    int count;
    int mask;
    int i;
    int j;

    count = func_8008D2C0(points);
    mask = 0;

    for (i = 0; i < count; ++i) {
        mask |= 1 << points[i].pad;
    }

    if (D_800F58C0 == NULL) {
        return;
    }

    // Potential bug in original, needs investigating.
    // Both key tests shift and mask their key in place, so after its first use a key
    // holds the last result and not the bits read from the cell. On the first cell,
    // with its low half off, the first high key shift uses the address of points
    // instead of 1.
    held = (u_int)points;

    for (i = 0; i < 256; ++i) {
        u_int cell = D_800F58C0[i];
        int lowX;
        int lowZ;
        int highX;
        int highZ;
        u_int lowKey;
        u_int highKey;

        if (!(cell & 0x04000400)) {
            held = 1;
            continue;
        }

        cell |= 0x80008000;
        lowX = (cell >> 5) & 0x1F;
        lowZ = cell & 0x1F;
        highX = (cell >> 21) & 0x1F;
        highZ = (cell >> 16) & 0x1F;
        lowKey = (cell >> 13) & 3;
        highKey = (cell >> 29) & 3;

        for (j = 0; j < 8; ++j) {
            int x = D_800F5910[j * 2].unk0_0;
            int z = D_800F5910[j * 2].unk0_5;

            if (cell & 0x400) {
                held = 1;

                if (lowX == x) {
                    lowKey = 1 << (lowKey & 31);

                    if (lowZ == z) {
                        lowKey &= mask;

                        if (lowKey != 0) {
                            cell &= ~0x8000;
                        }
                    }
                }
            }

            highKey = held << (highKey & 31);
            held = 1;

            if (cell & 0x4000000) {
                highKey &= mask;

                if (highX == x && highZ == z && highKey != 0) {
                    cell &= ~0x80000000;
                }
            }
        }

        D_800F58C0[i] = cell;
    }
}

void func_800DC784(func_800E78F4_t* arg0, int arg1)
{
    func_800DA1D4_t state = arg0->unk1A4[arg1];

    if (state.unk0_6 < 3) {
        // Potential bug in original, needs investigating.
        // rand() & 0x7F is always below 128, so unk18 is always set.
        if ((rand() & 0x7F) < 128) {
            arg0->unk18 = 1;
        }

        func_800D8260(arg0, 6, 40);
        func_800E48A8(arg0, 2, 128);
    }

    state.unk0_6 = 3;
    state.unk0_8 = 0;
    arg0->unk1A4[arg1] = state;
}

void func_800DC810(D_800F19CC_t2* arg0)
{
    Actor* actor = vs_battle_actors[0];

    do {
        func_800DD000(D_800F5878[actor->id], arg0);
        actor = actor->next;
    } while (actor != NULL);

    actor = vs_battle_actors[0];

    do {
        func_800DD344(D_800F5878[actor->id]);
        actor = actor->next;
    } while (actor != NULL);
}

#endif
