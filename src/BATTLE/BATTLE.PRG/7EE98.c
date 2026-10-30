#include "common.h"
#include "6E644.h"
#include "6E644Shared.h"
#include "4DEA8.h"
#include "src/SLUS_010.40/32154.h"
#include <abs.h>
#include <rand.h>

int func_800E7698(func_800E78F4_t*);
void func_800E7960(func_800E78F4_t*);

extern short D_800F17DC[][2];
extern int D_800F5918;
extern int D_800F591C;

int func_800E7698(func_800E78F4_t* arg0)
{
    D_800F4538_t* model = arg0->unk58;
    D_800F5920_t* motion = D_800F5920;
    int angle;

    arg0->unk470 = 0;
    model->unk5B0_4 = motion->unkB < 14;
    func_800E4660(0x7C0 - arg0->unk4C.vx, 0, 0x7C0 - arg0->unk4C.vz);

    switch (motion->unk2) {
    case 0:
        motion->unkA = 1;
        angle = ratan2(arg0->unk4C.vx - 0x7C0, arg0->unk4C.vz - 0x7C0) & 0xFFF;
        motion->unk10 = (-angle + ONE * 3 / 4) & 0xFFF;
        motion->unkB = 0;
        ++motion->unk2;
        motion->unk18 = arg0->unk4C.vx;
        motion->unk1A = arg0->unk4C.vz;
        break;
    case 1:
        if (!D_800F17DC[motion->unkB][0] && !D_800F17DC[motion->unkB][1]) {
            if (D_800F4538[0]->unk0.unkA_0) {
                func_800E2CCC(arg0);
                return 0;
            }

            motion->unk2 = 0;
            angle = ratan2(0x7C0 - arg0->unk4C.vx, 0x7C0 - arg0->unk4C.vz) & 0xFFF;
            motion->unk0 = (-angle + ONE * 3 / 4) & 0xFFF;
            model->unk5B0_4 = 0;
            return 1;
        }
        break;
    }

    arg0->unk17C =
        arg0->unk4C.vx * ONE + D_800F17DC[motion->unkB][0] * rcos(motion->unk10);
    arg0->unk180 =
        arg0->unk4C.vz * ONE + D_800F17DC[motion->unkB][0] * rsin(motion->unk10);
    arg0->unk184 = (arg0->unk4C.vy + D_800F17DC[motion->unkB][1]) * ONE;
    func_800DEEFC(arg0, 8);
    motion->unk3 = 0;
    ++motion->unkB;
    return 0;
}

int func_800E78F4(func_800E78F4_t* arg0)
{
    int r = 0;
    int a;
    int b;

    if (arg0->unk470 != 0 && func_800DBCB4(arg0, arg0->unk430[0])) {
        a = arg0->unk430[0]->unk4_13;
        b = D_800F58BC->unk18;
        r = a < b;
    }
    return r;
}

void func_800E7960(func_800E78F4_t* arg0)
{
    D_800F5920_t* motion = D_800F5920;
    int center[3];
    int playerAngle;
    int currentAngle;
    int tracking;
    int radius;
    int heading;
    int sign;
    int cosCurrent;
    int sinTarget;
    int sinCurrent;
    int cosTarget;
    int aligned;
    int delta;
    int ratio;
    int denominator;
    int scale;
    int magnitude;
    int oppositeAngle;
    int facing;
    int correction;
    int difference;

    if (!motion->unk1C) {
        int initialAngle = ratan2(0x7C0 - arg0->unk4C.vx, 0x7C0 - arg0->unk4C.vz) & 0xFFF;

        motion->unk0 = (-initialAngle + ONE * 3 / 4) & 0xFFF;
        motion->unk12 = arg0->unk4C.vy;
        motion->unk1C = 1;
    }

    if (!motion->unk3) {
        motion->unk4 = func_800E4660(0x7C0 - arg0->unk4C.vx, 0, 0x7C0 - arg0->unk4C.vz);
        ++motion->unk3;
    }

    arg0->unk58->unk5B0_4 = 0;
    radius = vs_gte_rsqrt(motion->unk4);

    if (radius < 1024) {
        radius += 32;
    }

    if (radius > 1024) {
        radius -= 32;
    }

    difference = radius - 1024;
    difference = ABS(difference);

    if (difference < 32) {
        radius = 1024;
    }

    motion->unk4 = radius * radius;
    center[0] = 0x7C0 * ONE;
    difference = motion->unk12 - 160;

    difference = ABS(difference);

    if (difference < 16) {
        motion->unk12 = 160;
    } else if (motion->unk12 < 160) {
        motion->unk12 += 12;
    } else {
        motion->unk12 -= 12;
    }

    center[1] = motion->unk12 * ONE;
    center[2] = 0x7C0 * ONE;
    playerAngle = ratan2(
        0x7C0 - D_800F4538[0]->unk0.position.vx, 0x7C0 - D_800F4538[0]->unk0.position.vz);
    currentAngle = ratan2(0x7C0 - arg0->unk4C.vx, 0x7C0 - arg0->unk4C.vz);

    if (func_800E78F4(arg0) && func_800D826C(arg0)) {
        heading = playerAngle;
        tracking = 1;
    } else {
        tracking = 0;
        heading = playerAngle + ONE / 2;
    }

    sign = D_800F5918 >= 0 ? 1 : -1;
    cosCurrent = rcos(-currentAngle + ONE * 3 / 4);
    sinTarget = rsin(-heading + ONE * 3 / 4);
    sinCurrent = rsin(-currentAngle + ONE * 3 / 4);
    cosTarget = rcos(-heading + ONE * 3 / 4);
    aligned = ((cosCurrent * sinTarget - sinCurrent * cosTarget) * sign) >= 0;

    if (aligned) {
        delta = ABS(D_800F5918) > 0x280000 ? D_800F5918 / 8 + (sign << 16) : sign << 16;
    } else {
        delta = D_800F5918 / 4 + (sign << 16);
    }

    if ((tracking || rcos(currentAngle - heading) < rcos(222)) && !aligned) {
        delta = -delta;
    }

    D_800F5918 += delta;
    sign = D_800F5918 >= 0 ? 1 : -1;

    if (ABS(D_800F5918) > 0x820000) {
        D_800F5918 = sign * 0x820000;
    }

    ratio = (arg0->unk5C->currentHP << 16) / arg0->unk5C->maxHP;

    if (!motion->unkC) {
        if ((!motion->unk14 && ratio < 0xC000)
            || (motion->unk14 == 1 && ratio < 0x4000)) {
            ++motion->unk14;
            do {
                motion->unkE = 1;
            } while (0);
        } else if (ABS(D_800F5918) < 0x40000 && tracking && D_800F591C < 30
                   && !(rand() & 511)) {
            motion->unkE = 1;
        }
    }

    motion->unk0 += D_800F5918 >> 16;
    facing = motion->unk0;
    arg0->unk15C = 0;
    arg0->unk17C = center[0] + radius * rcos(facing);
    arg0->unk180 = center[2] + radius * rsin(facing);

    if (tracking) {
        if (aligned) {
            denominator = currentAngle - playerAngle;
            scale = -80 - D_800F591C;
        } else {
            oppositeAngle = currentAngle - ONE / 2;
            denominator = playerAngle - oppositeAngle;
            scale = 300 - D_800F591C;
        }
    } else if (aligned) {
        oppositeAngle = currentAngle - ONE / 2;
        denominator = playerAngle - oppositeAngle;
        scale = 300 - D_800F591C;
    } else {
        denominator = ABS(D_800F5918) >> 16;
        scale = 10;
    }

    denominator &= 0xFFF;

    if (denominator > ONE / 2) {
        denominator = ONE - denominator;
    }

    if (!denominator) {
        denominator = 1;
        scale = 0;
    }

    magnitude = ABS(D_800F5918);
    correction = magnitude * scale / denominator;

    if (ABS(correction) > magnitude * 4) {
        correction = (correction >> 31) * magnitude * 4;
    }

    D_800F591C += correction >> 16;

    if (D_800F591C < -100) {
        D_800F591C = -100;
    }

    if (D_800F591C > 500) {
        D_800F591C = 500;
    }

    arg0->unk184 = center[1] - D_800F591C * ONE;

    if (arg0->unk184 >= 0xFF000) {
        arg0->unk184 = 0xFF000;
    }

    func_800DEEFC(arg0, 8);
}

int func_800E7F8C(func_800E78F4_t* arg0)
{
    D_800F5920_t* temp_s0;
    char state;

    if (func_800E78F4(arg0) != 0) {
        func_800D836C(arg0);
    }

    state = vs_battle_getStateFlag(0xA6);
    temp_s0 = D_800F5920;

    if (temp_s0->unkC > 0) {
        --temp_s0->unkC;
    }

    switch (state) {
    case 0:
        if (temp_s0->unk16 != 0) {
            temp_s0->unk16 = 0;
            arg0->unk470 = temp_s0->unk17;
        }

        temp_s0->unkA = 0;
        func_800E7960(arg0);

        if ((temp_s0->unkE != 0) && (temp_s0->unkC == 0)
            && (arg0->unk5C->limbs[4].hp >= 2)) {
            temp_s0->unkC = 900;
            temp_s0->unkE = 0;
            temp_s0->unk17 = arg0->unk470;
            state = 1;
            arg0->unk470 = 0;
            temp_s0->unk16 = 1;
        }
        break;

    case 4:
        temp_s0->unk1C = 0;
        func_800D82CC(arg0);

        if (func_800E7698(arg0) != 0) {
            if (temp_s0->unkA != 0) {
                vs_battle_actorView_t* temp_a1 = arg0->unk54;

                if (temp_a1->unk3C->limbs[4].hp >= 2) {
                    temp_a1->unkC = 4;
                    temp_a1->unkE = 0;
                    setVector(&temp_a1->unk10, D_800F4538[0]->unk0.position.vx,
                        D_800F4538[0]->unk0.position.vy
                            - (D_800F4538[0]->menuCameraHeightOffset >> 1),
                        D_800F4538[0]->unk0.position.vz);
                    temp_a1->unk9 = 24;
                    temp_a1->unk8 = 0x80;
                }

                temp_s0->unk12 = arg0->unk4C.vy;
                arg0->unk470 = temp_s0->unk17;
                temp_s0->unk16 = 0;
            } else {
                state = 6;
            }

            D_800F591C = 0;
            temp_s0->unkE = 0;
            D_800F5918 = 0;
        }
        break;
    }

    vs_battle_setStateFlag(0xA6, state);
    return 1;
}

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/7EE98", D_80069C18);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/7EE98", D_80069C1C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/7EE98", D_80069C3C);
