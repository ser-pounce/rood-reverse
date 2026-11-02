#include "common.h"
#include "6E4CC.h"
#include "6E4CCShared.h"
#include "146C.h"
#include "4DEA8.h"
#include "battleUnk.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include <abs.h>
#include <rand.h>

typedef union {
    unsigned int raw;
    vs_battle_movementPosition p;
} vs_battle_movementTile;

extern u_char D_800F175C[];

int func_800DFAF8(func_800E78F4_t* arg0, vs_battle_movementPosition arg1, int arg2);

void func_800DF8A4(func_800E78F4_t* arg0)
{
    vs_battle_movementPosition pos;
    int i;

    if (arg0->unk34.y < 2) {
        vs_battle_movementPosition none = { 0xFF, 0xFF, 0xFF, 0xFF };

        arg0->unk19C = none;
        func_800E4BD8(arg0->unk19B);
        arg0->unk19B = 0;
        return;
    }

    i = func_800DFAF8(arg0, arg0->unk19C, 0);

    if (i >= 0) {
        pos.x = D_800F5910[i * 2].unk0_0;
        pos.z = D_800F5910[i * 2].unk0_5;
        pos.y = 0;

        if (func_800D954C(arg0, pos) > 0) {
            vs_battle_movementPosition none = { 0xFF, 0xFF, 0xFF, 0xFF };

            arg0->unk19C = none;
            arg0->unk19B = 0;
            func_800E4BD8((i >> 1) + 2);
            arg0->unk170 = pos;
            func_800DEEFC(arg0, 0xE);
            return;
        }
    }

    func_800E2CCC(arg0);

    // HACK: Bogus return to force match.
    return (void)&pos;
}

void func_800DF9A8(func_800DFA54_t* arg0, func_800DFA54_t* arg1)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (D_800F5910[i * 2].unk0_0 == arg0->unk0
            && D_800F5910[i * 2].unk0_5 == arg0->unk2) {
            if (i & 1) {
                i--;
            } else {
                i++;
            }
            arg1->unk0 = D_800F5910[i * 2 + 1].unk0_0;
            arg1->unk2 = D_800F5910[i * 2 + 1].unk0_5;
            arg1->unk1 = i >> 1;
            return;
        }
    }
    *(int*)arg1 = *(int*)arg0;
}

void func_800DFA54(int arg0, int arg1, int arg2, func_800DFA54_t* arg3)
{
    int i;

    arg1 >>= 19;
    arg2 >>= 19;
    for (i = arg0 * 2; i < arg0 * 2 + 2; i++) {
        if (arg1 == D_800F5910[i * 2 + 1].unk0_0
            && arg2 == D_800F5910[i * 2 + 1].unk0_5) {
            goto found;
        }
    }
    i = arg0 * 2;
found:
    arg3->unk0 = D_800F5910[i * 2].unk0_0;
    arg3->unk2 = D_800F5910[i * 2].unk0_5;
}

int func_800DFAF8(func_800E78F4_t* arg0 __attribute__((unused)),
    vs_battle_movementPosition arg1, int arg2)
{
    SVECTOR sp10[4];
    SVECTOR* m;
    int i;
    int j;

    func_8008D2C0(sp10);
    for (i = 0; i < 8; ++i) {
        D_800F5910_t* e = &D_800F5910[i * 2];
        j = i >> 1;
        if (arg2 == 0) {
            ++e;
        }
        if (arg1.x == e->unk0_0 && arg1.z == e->unk0_5) {
            m = &sp10[j];
            if (D_800F5910[i * 2 + 1].unk0_0 == m->vx >> 7
                && D_800F5910[i * 2 + 1].unk0_5 == m->vz >> 7) {
                return i;
            }
        }
    }
    return -1;
}

int func_800DFBCC(func_800E78F4_t* arg0, int index, int area)
{
    u_short routes[2];
    int distances[2];
    vs_battle_movementTile position;
    int count;
    int i;
    int x;
    u_short route;

    position.raw = *(u_int*)&arg0->unk34;
    *(u_int*)routes = (*(u_int**)0x1F8003F4)[area * 16 + index];

    if (!(*(u_int*)routes & 0x1BE0)) {
        return 6;
    }

    arg0->unk154[0] = area;
    count = 1;

    if (*(u_int*)routes & 0x1BE00000) {
        count = 2;
    }

    for (i = 0; i < count; ++i) {
        vs_battle_movementPosition candidate;
        int result;

        route = (i == 0) ? routes[0] : routes[1];

        if ((((route >> 5) & 0x1F) != position.p.x) || ((route & 0x1F) != position.p.z)) {
            continue;
        }

        candidate = position.p;

        if (route & 0x400) {
            int slot;

            if (route & 0x8000) {
                continue;
            }

            result = func_800DFAF8(arg0, position.p, 1);

            if ((result >= 0) && (func_8008E320(slot = result >> 1) >= 0)) {
                candidate.y = slot + 2;

                if (!((D_800F58BC->unkE >> candidate.y) & 1)) {
                    arg0->unk19B = candidate.y;

                    if (arg0->unk88) {
                        func_800E4BE0(candidate.y);
                    }

                    func_800DF9A8(
                        (func_800DFA54_t*)&candidate, (func_800DFA54_t*)&arg0->unk19C);
                    arg0->unk170 = candidate;
                    return 14;
                }
            }

            candidate.x = (route >> 5) & 0x1F;
            candidate.z = route & 0x1F;
        } else if (route & 0x6000) {
            int amount;
            u_char* step;

            arg0->unk154[0] =
                (*(u_short(**)[32])0x1F8003C0)[candidate.z][candidate.x] % 16;
            arg0->unk5 = 0;
            amount = ((route >> 13) & 3) + 1;
            step = &D_800F175C[(route >> 11) & 3];
            candidate.x += amount * ((D_800F16EC_t*)0x1F8003EC)[*step].dx;
            candidate.z += amount * ((D_800F16EC_t*)0x1F8003EC)[*step].dz;
            result = func_800D954C(arg0, candidate);

            if (result < 0) {
            center:
                if ((arg0->unk15C != 16)
                    && ((func_800E78F4_t**)0x1F80037C)[arg0->unk15C]) {
                    arg0->unk17C =
                        ((func_800E78F4_t**)0x1F80037C)[arg0->unk15C]->unk60->vx;
                    arg0->unk180 =
                        ((func_800E78F4_t**)0x1F80037C)[arg0->unk15C]->unk60->vz;
                } else {
                    arg0->unk17C = candidate.x * 128 + 64;
                    arg0->unk180 = candidate.z * 128 + 64;
                }

                arg0->unk18A =
                    ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180)
                    & 0xFFF;
                arg0->unk13A = arg0->unk13C;
                return 4;
            }

            if (result <= 0) {
                continue;
            }

        stop:
            candidate.y = 0;
            arg0->unk170 = candidate;
            return 14;
        } else {
            u_char* table = D_800F175C;
            u_char* direction = &table[(route >> 11) & 3];

            candidate.x += ((D_800F16EC_t*)0x1F8003EC)[*direction].dx;
            candidate.z += ((D_800F16EC_t*)0x1F8003EC)[*direction].dz;

            if (func_800D954C(arg0, candidate) > 0) {
                if (((*(u_short(**)[32])0x1F8003BC)[candidate.z][candidate.x] & 0x1C00)
                    || (((*(u_char**)0x1F8003C4)[position.p.z * *(u_char*)0x1F8003DC
                                                 + position.p.x]
                            >> *direction)
                        & 1)) {
                    goto stop;
                }

                arg0->unk188 = *direction;
                return 5;
            }
        }

        goto center;
    }

    if ((*(u_int*)routes & 0x8400) == 0x8400) {
        if (count == 1) {
        areaOnly:
            arg0->unk154[0] =
                (*(u_short(**)[32])0x1F8003C0)[position.p.z][position.p.x] % 16;
            return 6;
        }

        if ((*(u_int*)routes & 0x84000000) == 0x84000000) {
            goto areaOnly;
        }

        goto second;
    }

    if ((*(u_int*)routes & 0x84000000) == 0x84000000) {
        goto first;
    }

    for (i = 0; i < count; ++i) {
        route = (i == 0) ? routes[0] : routes[1];

        if (!((*(u_short(**)[32])0x1F8003BC)[route & 0x1F][(route >> 5) & 0x1F]
                & 0x1C00)) {
            continue;
        }

        route = (i != 0) ? routes[0] : routes[1];

        if (((*(u_short(**)[32])0x1F8003BC)[route & 0x1F][(route >> 5) & 0x1F] & 0x1C00)
            || (count == 1)) {
            arg0->unk154[0] =
                (*(u_short(**)[32])0x1F8003C0)[position.p.z][position.p.x] % 16;
            return 6;
        }

        *(u_int*)&arg0->unk168 = ((route & 0x1F) << 16) | ((route >> 5) & 0x1F);
        return 6;
    }

    x = position.p.x;

    if (count == 1) {
        if (((*(u_int*)& arg0->unk168 =
                     ((routes[0] & 0x1F) << 16) | ((*(u_int*)routes >> 5) & 0x1F))
                & 0xFF00FF)
            != (*(u_int*)&arg0->unk34 & 0xFF00FF)) {
            return 6;
        }
    } else {
        int z = position.p.z;

        distances[0] =
            (x - ((*(u_int*)routes >> 5) & 0x1F)) * (x - ((*(u_int*)routes >> 5) & 0x1F))
            + (z - (routes[0] & 0x1F)) * (z - (routes[0] & 0x1F));
        x -= (*(u_int*)routes >> 21) & 0x1F;
        z -= (*(u_int*)routes >> 16) & 0x1F;
        distances[1] = x * x + z * z;

        if (distances[0] < distances[1]) {
        first:
            *(u_int*)&arg0->unk168 =
                ((routes[0] & 0x1F) << 16) | ((*(u_int*)routes >> 5) & 0x1F);
        } else {
        second:
            *(u_int*)&arg0->unk168 =
                (*(u_int*)routes & 0x1F0000) | ((*(u_int*)routes >> 21) & 0x1F);
        }

        if ((*(u_int*)&arg0->unk168 & 0xFF00FF) != (*(u_int*)&arg0->unk34 & 0xFF00FF)) {
            return 6;
        }
    }

    goto center;
}

int func_800E02B4(func_800E78F4_t* arg0, int arg1, int arg2)
{
    SVECTOR points[4];
    int x;
    int y;
    int z;
    int i;
    int dx;
    int dy;
    int dz;
    u_int radius;
    u_int height;
    vs_battle_actor* actor;

    if ((((D_1F8003D0_t*)0x1F8003D0)->unk2 >> arg1) & 1) {
        return ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1];
    }

    x = arg0->unk4C.vx + arg2 * (arg0->unkB3 * ((D_800F16EC_t*)0x1F8003EC)[arg1].dx);
    y = arg0->unk4C.vy;
    z = arg0->unk4C.vz + arg2 * (arg0->unkB3 * ((D_800F16EC_t*)0x1F8003EC)[arg1].dz);

    for (i = func_8008D2C0(points) - 1; i != -1; --i) {
        dx = points[i].vx - x;
        dy = points[i].vy - y;
        dz = points[i].vz - z;

        if (arg2
            && ((((D_800F16EC_t*)0x1F8003EC)[arg1].dx > 0 && dx < 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dx < 0 && dx > 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dz > 0 && dz < 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dz < 0 && dz > 0))) {
            continue;
        }

        radius = arg0->unk92 + 96;
        height = (arg0->unkB8 + 32) >> 1;

        if (ABS(dx) <= radius && ABS(dz) <= radius && ABS(dy) <= height) {
            ((D_1F8003D0_t*)0x1F8003D0)->unk2 |= 1 << arg1;
            ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1] = 1;
            return 1;
        }
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        func_800E78F4_t* other = ((func_800E78F4_t**)0x1F80037C)[actor->id];
        D_800F4538_t* model = other->unk58;

        if (other->unk88 == arg0->unk88 || other->unk88 == 0) {
            continue;
        }

        dx = model->unk0.position.vx - x;
        dy = model->unk0.position.vy - y;
        dz = model->unk0.position.vz - z;

        if (arg2
            && ((((D_800F16EC_t*)0x1F8003EC)[arg1].dx > 0 && dx < 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dx < 0 && dx > 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dz > 0 && dz < 0)
                || (((D_800F16EC_t*)0x1F8003EC)[arg1].dz < 0 && dz > 0))) {
            continue;
        }

        radius = other->unk92 + arg0->unk92 + other->unkB3;

        if (other->unk88 == 0) {
            height = -1;
        } else {
            height = (arg0->unkB8 + other->unkB8) >> 1;
        }

        if (ABS(dx) <= radius && ABS(dz) <= radius && ABS(dy) <= height) {
            ((D_1F8003D0_t*)0x1F8003D0)->unk2 |= 1 << arg1;
            ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1] = actor->id + 1;
            return actor->id + 1;
        }
    }

    ((D_1F8003D0_t*)0x1F8003D0)->unk2 |= 1 << arg1;
    ((D_1F8003D0_t*)0x1F8003D0)->unk4[arg1] = 0;
    return 0;
}

int func_800E0678(func_800E78F4_t* arg0, int arg1)
{
    if ((((D_1F8003D0_t*)0x1F8003D0)->unk0 >> arg1) & 1) {
        return (((D_1F8003D0_t*)0x1F8003D0)->unk1 & (1 << arg1)) > 0;
    }

    if (!func_800E02B4(arg0, arg1, 1)) {
        int x = arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[arg1].dx;
        int z = arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[arg1].dz;

        if (x <= D_800F58BC->unk0 && x >= D_800F58BC->unk2 && z <= D_800F58BC->unk1
            && z >= D_800F58BC->unk3 && !((*(u_short(**)[32])0x1F8003C0)[z][x] & 0x40)
            && (((vs_battle_movementPosition*)&arg0->unk38)->x != x
                || ((vs_battle_movementPosition*)&arg0->unk38)->z != z)) {
            if (D_800F58BC->unk14
                && func_800E42EC(x, z) + arg0->unkBE < D_800F58BC->unk14) {
                return 0;
            }

            ((D_1F8003D0_t*)0x1F8003D0)->unk0 |= 1 << arg1;
            ((D_1F8003D0_t*)0x1F8003D0)->unk1 |= 1 << arg1;
            return 1;
        }
    }

    ((D_1F8003D0_t*)0x1F8003D0)->unk0 |= 1 << arg1;
    ((D_1F8003D0_t*)0x1F8003D0)->unk1 &= ~(1 << arg1);
    return 0;
}

int func_800E0850(func_800E78F4_t* arg0, u_int arg1)
{
    int min = 0;
    int count = 1;

    if (arg1 & 0x3FF) {
        count = 3;
    }
    arg1 = (arg1 >> 9) & 6;
    while (--count != -1) {
        if (func_800E0678(arg0, arg1) != 0) {
            int h = func_800E42EC(arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[arg1].dx,
                arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[arg1].dz);
            if (h < min) {
                min = h;
            }
        }
        arg1 = (arg1 + 1) & 7;
    }
    return min;
}

int func_800E0918(func_800E78F4_t* arg0, int arg1, int arg2)
{
    void (*callback)(func_800E78F4_t*, int) = arg2 ? func_800E4B2C : func_800E4B70;

    if (arg0->unk15E & 6) {
        u_int distance = func_800E45F4(arg0->unk168, arg0->unk34);

        if (arg2 && distance < 16) {
            if (!(arg0->unk58->unk0.unkA_5 << 21)) {
                callback(arg0, arg1);
                return 1;
            }
        } else if (D_800F58BC->unk14
                   && func_800E42E0(arg0->unk34) + arg0->unkBE < D_800F58BC->unk14) {
            if (arg0->unk58->unk0.unkA_5 << 21) {
                if (func_800D954C(arg0, arg0->unk34) > 0) {
                    func_800E678C(arg0);
                    func_800E4B10(arg0);
                    return 1;
                }
            } else {
                callback(arg0, arg1);
                return 1;
            }
        }
    }

    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/770A4", func_800E0A68);

void func_800E1238(func_800E78F4_t* arg0, int arg1)
{
    int sp10;
    int sp14;
    int angle;
    int c;
    int s;

    if (func_800E0918(arg0, arg1, 0) != 0) {
        return;
    }

    if (func_800E4764(arg0, &sp10, &sp14) == 0) {
        func_800E2CCC(arg0);
        return;
    }

    arg0->unk7 = 1;
    func_800E3600(arg0, arg1, 3);

    if (*(int*)0x1F8003C8 != 5 && *(int*)0x1F8003C8 != 7) {
        func_800E678C(arg0);
        func_800E2CCC(arg0);
        return;
    }

    if (*(int*)0x1F8003C8 == 5) {
        arg1 = arg0->unk188 * (ONE / 8);
    }

    angle = (-arg1 + ONE * 3 / 4) & 0xFFF;
    c = rcos(angle);
    s = rsin(angle);

    if (func_800E0850(arg0, arg1) + arg0->unkBE < arg0->unk4C.vy) {
        arg0->unk184 = -ONE;
        arg0->unk180 = 0;
        arg0->unk17C = 0;
    } else {
        arg0->unk184 = 0;
        arg0->unk17C = c;
        arg0->unk180 = s;
    }

    if (!(arg0->unk58->unk0.unkA_5 << 21)) {
        func_800E4B18(arg0);
    } else {
        arg0->unk228 = 0;
        func_800DEEFC(arg0, sp14);
    }
}

void func_800E1388(
    func_800E78F4_t* arg0, vs_battle_movementPosition arg1, int arg2, u_int arg3)
{
    vs_battle_movementPosition dest;
    int i;
    int angle = (-arg2 + ONE * 3 / 4) & 0xFFF;
    u_int step = arg3 >> 3;

    for (i = 0; i < 8; ++i, arg3 -= step) {
        int x = ((int)(arg3 * rcos(angle)) >> 12) + 64;
        int z;

        dest.x = (arg1.x * 128 + x) >> 7;
        z = ((int)(arg3 * rsin(angle)) >> 12) + 64;
        dest.z = (arg1.z * 128 + z) >> 7;

        if (func_800D954C(arg0, dest) > 0) {
            break;
        }
    }

    if (dest.x < D_800F58BC->unk2) {
        dest.x = D_800F58BC->unk2;
    } else if (dest.x > D_800F58BC->unk0) {
        dest.x = D_800F58BC->unk0;
    }

    if (dest.z < D_800F58BC->unk3) {
        dest.z = D_800F58BC->unk3;
    } else if (dest.z > D_800F58BC->unk1) {
        dest.z = D_800F58BC->unk1;
    }

    arg0->unk168 = dest;
}

void func_800E153C(func_800E78F4_t* arg0, int arg1)
{
    int distance = arg0->unkB4;

    if ((*(u_int*)&arg0->unk34 & 0xFF00FF) != (*(u_int*)&arg0->unk168 & 0xFF00FF)) {
        int angle = ratan2(arg0->unk4C.vx - arg0->unk168.x * 128 - 64,
            arg0->unk4C.vz - arg0->unk168.z * 128 - 64);

        if (func_800E4660(arg0->unk168.x * 128 - arg0->unk4C.vx + 64, 0,
                arg0->unk168.z * 128 - arg0->unk4C.vz + 64)
            > distance * distance) {
            func_800E1388(arg0, arg0->unk34, angle, distance);
        }

        if ((arg0->unk15E & 6)
            && (arg0->unkD || func_800E45F4(arg0->unk168, arg0->unk34) < 16)) {
            if ((int)(*(u_int*)&arg0->unk48 << 8) >= 0) {
                arg0->unk168 = arg0->unk48;
            }

            func_800E4B2C(arg0, angle);
            return;
        }

        if (++arg0->unk8C >= 6) {
            int i;
            vs_battle_movementPosition dest = arg0->unk168;

            if (func_800D954C(arg0, dest) <= 0) {
                for (i = 0; i < 4; ++i) {
                    dest.x = arg0->unk168.x + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dx;
                    dest.z = arg0->unk168.z + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dz;

                    if (func_800D954C(arg0, dest) > 0) {
                        arg0->unk168 = dest;
                        goto begin;
                    }
                }

                goto fallback;
            }

        begin:
            arg0->unk8C = 0;
            arg0->unk170 = arg0->unk168;
            func_800DEEFC(arg0, 13);
            return;
        }
    }

fallback:
    func_800E2CCC(arg0);
}

void func_800E1764(func_800E78F4_t* arg0, int arg1)
{
    vs_battle_movementPosition previous[2];
    u_int distance;
    int opposite = (arg1 + ONE / 2) & 0xFFF;

    func_800E1388(arg0, arg0->unk34, arg1, arg0->unkB4);
    previous[0] = arg0->unk168;
    func_800E1388(arg0, arg0->unk34, opposite, arg0->unkB4);
    distance = func_800E4660(arg0->unk168.x * 128 - arg0->unk17C + 64, 0,
        arg0->unk168.z * 128 - arg0->unk180 + 64);

    if (distance < func_800E4660(previous[0].x * 128 - arg0->unk17C + 64, 0,
            previous[0].z * 128 - arg0->unk180 + 64)) {
        arg0->unk168 = previous[0];
    }

    func_800E153C(arg0, arg1);
}

u_char func_800E1850(u_char arg0, vs_battle_movementPosition arg1, int arg2)
{
    int x = arg1.x;
    int z = arg1.z;
    int i;

    int z2 = z;

    for (i = 0; i < 8; ++i) {
        if ((arg0 >> i) & 1) {
            if (func_800E42EC(x + ((D_800F16EC_t*)0x1F8003EC)[i].dx,
                    z2 + ((D_800F16EC_t*)0x1F8003EC)[i].dz)
                > arg2) {
                arg0 &= ~(1 << i);
            }
        }
    }
    return arg0;
}

void func_800E1908(func_800E78F4_t* arg0)
{
    u_char* tile =
        &(*(u_char**)0x1F8003C4)[arg0->unk34.z * *(u_char*)0x1F8003DC + arg0->unk34.x];
    int old = *tile;
    vs_battle_actorView_t* actor = arg0->unk54;
    int result;

    *tile = func_800E1850(old, arg0->unk34, arg0->unk4C.vy);
    func_800E3600(arg0,
        ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180) & 0xFFF, 0);
    *tile = old;
    result = *(int*)0x1F8003C8;

    if ((0xA0 >> result) & 1) {
        actor->unk9 = 9;

        if (result == 5) {
            actor->unkC = arg0->unk188 << 9;
        } else {
            actor->unkC = arg0->unk188;
        }
    }
}

void func_800E19FC(func_800E78F4_t* arg0)
{
    int current;
    int next;

    arg0->unk4 = 0;
    arg0->unk5 = 1;

    if (arg0->unk1A) {
        func_800E1908(arg0);
        return;
    }

    current = (*(u_short(**)[32])0x1F8003C0)[arg0->unk34.z][arg0->unk34.x] & 15;
    next = (*(u_short(**)[32])0x1F8003C0)[arg0->unk168.z][arg0->unk168.x] & 15;

    if (current != next) {
        if (arg0->unk29) {
            int mode = func_800DFBCC(arg0, current, next);

            if (mode == 6) {
                arg0->unk17C = arg0->unk168.x * 128 + 64;
                arg0->unk180 = arg0->unk168.z * 128 + 64;

                if (((*(u_short(**)[32])0x1F8003C0)[arg0->unk168.z][arg0->unk168.x] & 15)
                    != ((*(u_short(**)[32])0x1F8003C0)[arg0->unk34.z][arg0->unk34.x]
                        & 15)) {
                    arg0->unk2 = 1;
                    ((D_1F8003D0_t*)0x1F8003D0)->unk0 = 0;
                }
            } else {
                func_800E4BB8(arg0);

                if (mode == 5) {
                    func_800E4B70(arg0, arg0->unk188 * (ONE / 8));
                } else {
                    func_800DEEFC(arg0, mode);
                }

                return;
            }
        } else {
            arg0->unk2 = 1;
            ((D_1F8003D0_t*)0x1F8003D0)->unk0 = 0;
        }
    }

    func_800E3600(arg0,
        ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180) & 0xFFF, 0);
}

int func_800E1BB8(
    func_800E78F4_t* arg0, vs_battle_movementPosition arg1, u_int arg2, int arg3)
{
    vs_battle_movementPosition candidate;
    u_int count = 0;
    int choices[4];
    int i;
    u_int chosen;

    if (!arg2) {
        return -1;
    }

    if (!arg0->unk15D) {
        arg0->unk11C = arg1;
    }

    candidate = arg0->unk11C;

    for (i = 0; i < 4; ++i) {
        if (!(arg0->unk15E & 8)) {
            if (*(int*)0x1F8003F4) {
                candidate.y =
                    ((*(u_char**)0x1F8003C4)[arg0->unk11C.z * *(u_char*)0x1F8003DC
                                             + arg0->unk11C.x]
                        >> i * 2)
                    & 1;
            } else {
                candidate.y = func_800E4690(arg0->unk11C, i * 2);
            }

            candidate.x = arg0->unk11C.x + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dx;
            candidate.z = arg0->unk11C.z + ((D_800F16EC_t*)0x1F8003EC)[i * 2].dz;

            if (candidate.y) {
                if (!func_800D96C8(arg0, arg0->unk11C, candidate, i * 2)) {
                    continue;
                }

                candidate.y = 0;
            }

            if (!arg0->unk2
                && ((*(u_short(**)[32])0x1F8003C0)[candidate.z][candidate.x] & 15)
                       != ((*(u_short(**)[32])0x1F8003C0)[arg0->unk11C.z][arg0->unk11C.x]
                           & 15)) {
                continue;
            }
        }

        if (!((*(u_short(**)[32])0x1F8003C0)[candidate.z][candidate.x] & 32)) {
            choices[count++] = i * 2;
        }
    }

    if (!count) {
        return -1;
    }

    chosen = func_800E45D4(4096) % count;

    if (arg0->unkD0 > 0 && ((arg0->unkD0 + 4) & 7) == choices[chosen]) {
        chosen = func_800E45D4(4096) % count;
    }

    arg0->unk11C.x += ((D_800F16EC_t*)0x1F8003EC)[choices[chosen]].dx;
    arg0->unk11C.z += ((D_800F16EC_t*)0x1F8003EC)[choices[chosen]].dz;
    arg0->unkD0 = choices[chosen];
    ++arg0->unk15D;
    return arg2 < arg0->unk15D;
}

static inline int _randomHeading(int direction)
{
    int offset = func_800E45D4(512);
    int angle = direction * 512;

    offset += 65280;
    return angle + offset;
}

void func_800E1EAC(func_800E78F4_t* arg0, vs_battle_movementPosition arg1, u_int arg2)
{
    int rate = arg0->unkD8;
    u_short rest = arg0->unkD4;
    u_short move = arg0->unkD6;
    int value;
    int (*check)(func_800E78F4_t*, int);

    ++arg0->unkC2;
    check = (arg0->unk58->unk0.unkA_5 << 21) ? func_800E0678 : func_800D9B6C;

    if (arg0->unk12D == 1) {
        if (arg0->unkC2 < 31) {
            return;
        }

        if (func_800E45D4(128) < 44u) {
            arg0->unk12D = 2;
        } else {
            arg0->unkC2 = 0;
            return;
        }
    }

    if (arg0->unkC2 == move) {
        if (func_800E45D4(128) < 44u) {
            arg0->unkC2 = 0;
        }
    } else if (arg0->unkC2 >= rest + move) {
        arg0->unkC2 = func_800E45D4(128) < 44u ? move : 0;
    }

    arg0->unk2 = 1;
    *(u_char*)0x1F8003D0 = 0;

    value = arg0->unkC2 < move;

    if (value) {
        int heading;
        int result;

        if (arg2 >= 63) {
            int i;
            int side;
            int step;

            if (!arg0->unkC0 || !func_800E45D4(1 << rate) || !arg0->unkD2) {
                value = func_800E45D4(4096) % arg2 + 128;
                arg0->unkC0 = 1;
                arg0->unkD2 = 60;
                arg0->unkC4 = value * value;
                heading = func_800E45D4(4) * 2;

                for (i = 0; i < 4; ++i) {
                    int direction = (heading + i * 2) & 7;

                    if (check(arg0, direction)) {
                        arg0->unkD0 = _randomHeading(direction);
                        break;
                    }
                }

                if (i == 4) {
                    arg0->unkD0 = func_800E45D4(4096);
                }
            }

            if (!arg0->unk8) {
                arg0->unkD2 = 60;
            } else if (arg0->unkD2) {
                --arg0->unkD2;
            }

            if (arg0->unk15E & 8) {
                func_800E1388(arg0, arg0->unk34, arg0->unkD0, arg0->unkB4);
            }

            for (side = arg0->unkD0 >> 9, step = 0; step < 2;
                side = (side + 2) & 7, ++step) {
                int x = arg0->unk34.x + ((D_800F16EC_t*)0x1F8003EC)[side].dx;
                int z = arg0->unk34.z + ((D_800F16EC_t*)0x1F8003EC)[side].dz;

                if (D_800F58BC->unk1 < z || z < D_800F58BC->unk3 || D_800F58BC->unk0 < x
                    || x < D_800F58BC->unk2
                    || ((*(u_short(**)[32])0x1F8003C0)[z][x] & 0x800)) {
                    arg0->unkD2 = 0;
                    break;
                }
            }

            func_800E50A0(arg0, 1, arg0->unkD0);
            return;
        }

        arg0->unk3 = 1;

        if (!func_800E45D4(1 << rate)) {
            arg0->unkC0 = 0;
        }

        switch (arg0->unkC0) {
        case 0:
            arg0->unkD0 = -1;
            arg0->unk15D = 0;
            arg0->unkD2 = 60;
            ++arg0->unkC0;
            func_800E2CCC(arg0);
            return;

        case 1:
            result = func_800E1BB8(arg0, arg1, arg2, 3);

            if (result < 0) {
                arg0->unkC0 = 0;
            } else if (result > 0) {
                ++arg0->unkC0;
                arg0->unk168 = arg0->unk11C;
            }
            break;

        case 2:
            arg0->unk168 = arg0->unk11C;

            if (arg0->unk15E & 8) {
                heading = ratan2(arg0->unk4C.vx - arg0->unk168.x * 128 - 64,
                              arg0->unk4C.vz - arg0->unk168.z * 128 - 64)
                        & 0xFFF;
                arg0->unk48 = arg0->unk168;
                func_800E1388(arg0, arg0->unk34, heading, arg0->unkB4);
            }

            func_800E50A0(arg0, 0, 0);

            if (!arg0->unk8) {
                arg0->unkD2 = 60;
            } else if (arg0->unkD2) {
                --arg0->unkD2;
            }

            if ((*(u_int*)&arg0->unk168 & 0xFF00FF) == (*(u_int*)&arg0->unk34 & 0xFF00FF)
                || !arg0->unkD2) {
                arg0->unkC0 = 0;
            }

            return;

        default:
            arg0->unkC0 = 0;
            break;
        }
    }

    func_800E2CCC(arg0);
}

static inline void _nextWaypoint(func_800E78F4_t* arg0, D_800F58C8_t2* waypoints)
{
    D_800F58C8_t2* waypoint = &waypoints[arg0->unk100];
    int step;
    int active;

    if ((arg0->unk34.x != waypoint->x) || (arg0->unk34.z != waypoint->z)) {
        if (arg0->unk104 != 0) {
            --arg0->unk104;
        }

        if (func_800E45D4(1 << arg0->unk102) || (arg0->unk104 != 0)) {
            return;
        }

        arg0->unk103 = -arg0->unk103;
    }

    step = arg0->unk103 + 8;

    do {
        arg0->unk100 = (arg0->unk100 + step) & 7;
        waypoint = &waypoints[arg0->unk100];
        active = waypoint->active;
    } while (!active);

    arg0->unk104 = 10;
}

void func_800E23AC(func_800E78F4_t* arg0)
{
    D_800F58C8_t2* waypoints = D_800F58D8[arg0->unk101].unk0;
    D_800F58C8_t2* waypointX;
    D_800F58C8_t2* waypointZ;

    _nextWaypoint(arg0, waypoints);
    waypointX = &waypoints[arg0->unk100];
    arg0->unk168.x = waypointX->x;
    waypointZ = &waypoints[arg0->unk100];
    arg0->unk168.z = waypointZ->z;
    func_800E50A0(arg0, 0, 0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/770A4", func_800E24EC);

int func_800E2B2C(func_800E78F4_t* arg0, int arg1)
{
    D_800F4538_t* model = arg0->unk58;
    int angle;

    if (arg1 == arg0->unk88) {
        func_800DEEFC(arg0, 0);
        return 1;
    }

    if (!arg0->unkBA) {
        return 0;
    }

    if (arg0->unk481) {
        if (func_800E4180(arg0, 128, 3, 6)) {
            return 1;
        }

        arg0->unk10C = 0;
        return 0;
    }

    angle = ratan2(arg0->unk4C.vx - arg0->unk17C, arg0->unk4C.vz - arg0->unk180);

    if ((*(u_int*)&arg0->unk168 & 0xFF00FF) != (*(u_int*)&arg0->unk108 & 0xFF00FF)
        && arg0->unk1A4[arg1].unk0_5 && !arg0->unk10C) {
        arg0->unk10C = 1;
        arg0->unk18A = angle;
        arg0->unk108 = arg0->unk168;
    }

    if (!arg0->unk10C) {
        return 0;
    }

    arg0->unk13A = arg0->unkBA;

    if (((model->unk0.facing + model->unk0.unk14) & 0xFFF) == (arg0->unk18A & 0xFFF)) {
        if (!arg0->unk1A4[arg1].unk0_5) {
            if (func_800E4180(arg0, 128, 1, 6)) {
                return 1;
            }

            arg0->unk10C = 0;
            goto failed;
        } else {
            arg0->unk10C = 1;
            arg0->unk18A = angle & 0xFFF;
            arg0->unk108 = arg0->unk168;
        }
    }

    func_800DEEFC(arg0, 4);
    return 1;

failed:
    return 0;
}

void func_800E2CCC(func_800E78F4_t* arg0)
{
    D_800F4538_t* model = arg0->unk58;
    int direction;

    if ((model->unk0.unkA_5 << 21) && arg0->unk228++ > 120 && (arg0->unk15E & 6)
        && (arg0->unk15E & 0x30) && func_800D954C(arg0, arg0->unk34) > 0) {
        func_800E678C(arg0);
        func_800E4B10(arg0);
        return;
    }

    if (arg0->unk15C != 16) {
        direction = ratan2(arg0->unk4C.vx - D_800F4538[arg0->unk15C]->unk0.position.vx,
                        arg0->unk4C.vz - D_800F4538[arg0->unk15C]->unk0.position.vz)
                  & 0xFFF;
        arg0->unk18A = direction;
        arg0->unk13A = arg0->unk13C;
        func_800DEEFC(arg0, 4);
    } else if (arg0->unk9) {
        direction =
            ratan2(arg0->unk4C.vx - arg0->unk158, arg0->unk4C.vz - arg0->unk15A) & 0xFFF;
        arg0->unk188 = direction;
        arg0->unk13A = arg0->unk13C;
        func_800DEEFC(arg0, 3);
    } else {
        int i;
        int nx;
        int nz;
        u_char* bounds;
        int bestHeight = 0x80000000;
        int bestDirection = -1;
        vs_battle_movementPosition source = arg0->unk34;
        u_int x = source.x;
        u_int z = source.z;
        u_int z2 = z;
        u_int angle = model->unk0.facing + model->unk0.unk14;
        u_int quadrant = (angle & 0xFFF) / (ONE / 4);
        direction = (angle & 0x3FF) > ONE / 8 ? ((quadrant + 1) & 3) * 2 : quadrant * 2;

        for (i = 0, bounds = (u_char*)0x1F8003DC; i < 4; ++i) {
            direction = (direction + i * 2) & 7;
            nx = (x + ((D_800F16EC_t*)0x1F8003EC)[direction].dx) & 0xFF;
            nz = (z2 + ((D_800F16EC_t*)0x1F8003EC)[direction].dz) & 0xFF;

            if (nx < bounds[0] && nz < bounds[1]) {
                int height = (func_800E4320(nx, nz) << 17) >> 17;

                if (height > bestHeight) {
                    bestDirection = direction;
                    bestHeight = height;
                }
            }
        }

        if (bestDirection < 0) {
            func_800DEEFC(arg0, 0);
        } else {
            arg0->unk18A = bestDirection * (ONE / 8);
            arg0->unk13A = arg0->unk13C;
            func_800DEEFC(arg0, 4);
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/770A4", func_800E2F5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/770A4", func_800E3600);
