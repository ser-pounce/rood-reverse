#include "common.h"
#include "6E4CCShared.h"
#include "146C.h"
#include <abs.h>
#include <libgte.h>

#ifdef NON_MATCHING

int func_800DB370(func_800E78F4_t* arg0, int arg1, int arg2, int arg3)
{
    D_800F4538_t* entry = D_800F4538[arg1];
    VECTOR* waypoint;
    int found;
    int mask;
    int surface;
    int packed;

    if (((func_800E78F4_t**)0x1F80037C)[arg1] == NULL) {
        // Potential bug in original, needs investigating.
        // arg1 is tested here in place of a result, so a missing state with a nonzero
        // arg1 still sets mode 1.
        found = arg1;
    } else {
        mask = arg0->unk15E & 0x38;

        if (arg0->unkE5 != arg1) {
            arg0->unkE4 = 0;
            arg0->unkE6 = 0;
            arg0->unkE7 = 0;
            arg0->unkE8 = 0;
            arg0->unkE9 = 0;
            arg0->unkEA = 0;
            arg0->unkEB = 0;
        }

        arg0->unkE5 = arg1;
        arg0->unkDC = arg2;
        surface = 0;

        if (mask == 0 && (entry->unk0.unkA_0 || entry->unk0.unkA_3)) {
            arg0->unk168 = entry->unk0.lastTouchedTile;
            surface = arg0->unk168.surface;
        } else if ((arg0->unk29 || mask) && entry->unk0.unkC_0) {
            surface = entry->unk0.unkC_0;
        } else {
            arg0->unk168 = entry->unk0.currentTile;
        }

        if (surface != 0) {
            waypoint = func_8008E2D4(surface - 2);
            func_800DFA54(surface - 2, waypoint->vx, waypoint->vz, &arg0->unk168);
            arg0->unkEC = arg0->unk168;
            // Potential bug in original, needs investigating.
            // x * 2 and z * 2 are ORed into one word at unkF4, so unkF6 is cleared where
            // z * 2 would be expected.
            packed = (arg0->unk168.x * 2) | (arg0->unk168.z * 2);
            arg0->unkF4 = packed;
            arg0->unkF5 = packed >> 8;
            arg0->unkF6 = 0;
            arg0->unkF7 = 0;
        }

        found = func_800E24EC(arg0, arg3);
    }

    if (found) {
        return func_800DB4AC(arg0, 1);
    }

    return 0;
}

int func_800DB4AC(func_800E78F4_t* arg0, int arg1)
{
    D_800F58C8_t2* waypoints;
    u_int best;
    int nearest;
    int i;

    arg0->unk89 = arg1;

    if (arg0->unk8A == arg1) {
        return 1;
    }

    switch (arg1) {
    case 1:
        arg0->unkE4 = 0;
        arg0->unkE5 = 0;
        arg0->unkE6 = 0;
        arg0->unkE7 = 0;
        arg0->unkE8 = 0;
        arg0->unkE9 = 0;
        break;

    case 3:
        arg0->unkC0 = 0;
        arg0->unkD2 = 0;
        break;

    case 6:
        arg0->unk10C = 0;
        VS_TILE_CLEAR(arg0->unk108);
        break;

    case 5:
        waypoints = D_800F58D8[arg0->unk101].unk0;
        best = -1;
        nearest = -1;

        for (i = 0; i < 8; ++i) {
            if (waypoints[i].active) {
                u_int distance = ABS(waypoints[i].x - arg0->unk34.x)
                               + ABS(waypoints[i].z - arg0->unk34.z);

                if (distance < best) {
                    best = distance;
                    nearest = i;
                }
            }
        }

        if (nearest >= 0) {
            arg0->unk100 = nearest;
        }

        arg0->unk104 = 0;
        break;
    }

    arg0->unk8A = arg1;
    arg0->unk474[arg1 * 2] = 0;
    func_800E4BB8(arg0);
    return 1;
}

void func_800DB5B0(func_800E78F4_t* arg0)
{
    func_800DB5B8(arg0, arg0->unkCC, arg0->unkC8);
}

void func_800DB5B8(func_800E78F4_t* arg0, vs_TilePosition arg1, int arg2)
{
    func_800DB4AC(arg0, 3);
    func_800E1EAC(arg0, arg1, arg2);
}

void func_800DB5DC(func_800E78F4_t* arg0, vs_TilePosition arg1, int arg2)
{
    arg0->unk168 = arg1;
    func_800DB4AC(arg0, 2);
    func_800E5030(arg0, arg2);
}

void func_800DB5FC(func_800E78F4_t* arg0)
{
    // In the original, this also returns early when a third argument is 0, but the only
    // caller passes one argument, so the test reads whatever the caller left behind.
    // Needs investigation.
    func_800DB4AC(arg0, 5);
    func_800E23AC(arg0);
}

int func_800DB61C(func_800E78F4_t* arg0, int arg1)
{
    Actor* actor = vs_battle_actors[0];
    D_800F4538_t* entry;
    u_int sumX = 0;
    u_int sumZ = 0;
    int count = 0;

    do {
        if (arg0->unk1A4[actor->id].unk0_5 && arg0->unk1A4[actor->id].unk0_6 == 3) {
            entry = D_800F4538[actor->id];
            ++count;
            sumX += entry->unk0.position.vx;
            sumZ += entry->unk0.position.vz;

            if (count != 1) {
                sumX >>= 1;
                sumZ >>= 1;
            }
        }

        actor = actor->next;
    } while (actor != NULL);

    if (count > 0) {
        arg0->unk114 = 90;
        arg0->unk110.x = sumX >> 7;
        arg0->unk110.surface = 0;
        arg0->unk110.z = sumZ >> 7;
        arg0->unk110.extra = 0;
    } else {
        if (arg0->unk114 != 0) {
            --arg0->unk114;
        }

        if (arg0->unk114 == 0 || arg0->unk8A != 4) {
            return 0;
        }
    }

    arg0->unk4 = 1;
    arg0->unk17C = arg0->unk110.x * 128 + 64;
    arg0->unk180 = arg0->unk110.z * 128 + 64;
    arg0->unk168 = arg0->unk110;
    func_800E4FE0(arg0, arg1);
    return func_800DB4AC(arg0, 4);
}

int func_800DB74C(func_800E78F4_t* arg0, int arg1)
{
    D_800F4538_t* entry = D_800F4538[arg1];

    arg0->unk17C = entry->unk0.position.vx;
    arg0->unk180 = entry->unk0.position.vz;
    arg0->unk168 = entry->unk0.currentTile;

    if (func_800E2B2C(arg0, arg1)) {
        return func_800DB4AC(arg0, 6);
    }

    return 0;
}

void func_800DB7B4(func_800E78F4_t* arg0)
{
    if (arg0->unk12D == 0) {
        return;
    }

    if (arg0->unk12D == 1 && arg0->unk54->unk9 < 9) {
        func_800DEEFC(arg0, 1);
        return;
    }

    func_800E678C(arg0);
    arg0->unk12D = 0;
    func_800DEEFC(arg0, 2);
}

void func_800DB820(func_800E78F4_t* arg0)
{
    if (func_800DAD9C(arg0) || func_800DB0BC(arg0)) {
        return;
    }

    if (arg0->unk68 != NULL && arg0->unk68(arg0)) {
        return;
    }

    func_800DB5B0(arg0);
}

int func_800DB8AC(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    // Potential bug in original, needs investigating.
    // The result of this call is not used.
    func_800DBCB4(arg0, arg1);

    if (arg0->unk8E != 0) {
        return 1;
    }

    if (arg0->unk98 != 0 || !arg0->unk1A4[arg1->unkC_0].unk0_0
        || D_800F58BC->unkD < D_800F58BC->unk24) {
        return 0;
    }

    if (D_800F58BC->unk10 & (1 << arg0->unk88)) {
        return 1;
    }

    return D_800F58BC->unkD >= D_800F58BC->unk12;
}

u_int func_800DB93C(
    func_800E78F4_t* arg0, vs_TilePosition arg1, int arg2, vs_TilePosition arg3)
{
    D_800F16EC_t step;
    vs_TilePosition tile;
    int range;
    int limit;
    int result;
    int i;
    int tileX = arg1.x;
    int tileZ = arg1.z;

    if (!((*(u_short(**)[32])0x1F8003C0)[tileZ][tileX] & 0x20)) {
        return arg1.x | (arg1.surface << 8) | (arg1.z << 16);
    }

    range = arg0->unkB2;
    limit = MIN(range, 3);
    step = ((D_800F16EC_t*)0x1F8003EC)[arg2];
    result = 0;
    i = 0;

    do {
        tileX = (tileX + step.dx) & 0xFF;
        tileZ = (tileZ + step.dz) & 0xFF;
        ++i;

        if (!((*(u_short(**)[32])0x1F8003C0)[tileZ][tileX] & 0x20)) {
            if (i < limit) {
                tile.x = tileX;
                tile.surface = 0;
                tile.z = tileZ;
                tile.extra = 0;
                result = func_800D96C8(arg0, arg3, tile, arg2);

                if (result == 1) {
                    result = func_800D954C(arg0, tile);
                }
            }

            break;
        }
    } while (range != 0);

    return (result << 24) | (tileZ << 16) | tileX;
}

int func_800DBA4C(func_800E78F4_t* arg0)
{
    if (arg0->unkE == 0) {
        return func_800DA1D4(arg0);
    }

    if (!func_800DB61C(arg0, 1)) {
        func_800DB5B0(arg0);
    }

    return 1;
}

int func_800DBA88(func_800E78F4_t* arg0)
{
    func_800DCAA0_t* target;
    int distance;
    int result;
    int mask;

    if (arg0->unkE != 0) {
        return func_800DB61C(arg0, 1);
    }

    mask = 1 << arg0->unk131;

    if (!(mask & 3)) {
        return func_800DA1D4(arg0);
    }

    distance = arg0->unk58->unk0.unkA_5 ? 320 : 256;
    target = arg0->unk430[0];

    if (mask & 1) {
        int root = SquareRoot0(target->unk8);
        distance = MIN(distance, root);
    }

    result = func_800DB370(arg0, target->unkC_0, distance, 0);

    if (result) {
        return result;
    }

    return func_800DB74C(arg0, target->unkC_0);
}

int func_800DBB2C(func_800E78F4_t* arg0, vs_TilePosition* arg1, int arg2)
{
    Actor* actor = vs_battle_actors[0];

    do {
        if (actor->id != arg0->unk88 && arg0->unk1A4[actor->id].unk0_6 == arg2) {
            if (arg1 != NULL) {
                *arg1 = actor->unk44->unk0.currentTile;
            }
            return actor->id;
        }

        actor = actor->next;
    } while (actor != NULL);

    return -1;
}

int func_800DBB98(func_800E78F4_t* arg0)
{
    vs_TilePosition tile;
    int id;
    int result = func_800DA1D4(arg0);

    if (result) {
        return result;
    }

    id = func_800DBB2C(arg0, &tile, 2);

    if (id < 0) {
        return 0;
    }

    if (arg0->unk1E4[id] > 640 * 640) {
        func_800DB5DC(arg0, tile, 0);
    } else {
        func_800DB5B8(arg0, tile, 5);
    }

    return 1;
}

int D_800DBC0C(func_800E78F4_t* arg0)
{
    int result;

    if (func_800D826C(arg0)) {
        result = func_800DA1D4(arg0);

        if (result) {
            return result;
        }
    }

    result = func_800DB370(arg0, 0, 256, 0);

    if (result) {
        return result;
    }

    return func_800DB74C(arg0, 0);
}

int func_800DBC60(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    if (arg0->unk13) {
        return 1;
    }

    if (!arg1->unk10.unk4) {
        return 0;
    }

    return D_800F45E0[arg1->unkC_0] == NULL;
}

int func_800DBCB4(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    if (arg0->unk90) {
        return 0;
    }

    if (!func_800DBC60(arg0, arg1)) {
        return 1;
    }

    return arg0->unk13F == 0;
}

int func_800DBCEC(func_800E78F4_t* arg0, int arg1)
{
    Actor* actor;

    // Potential bug in original, needs investigating.
    // The walk starts at vs_battle_actors itself, so the first pass reads the array as an
    // actor and uses vs_battle_actors[1] as its id.
    for (actor = (Actor*)vs_battle_actors; actor != NULL; actor = actor->next) {
        if (arg0->unk1A4[actor->id].unk0_6 == 3
            && func_800E45F4(D_800F4538[actor->id]->unk0.currentTile,
                   D_800F45E0[arg1]->unk0.currentTile)
                   < 3) {
            return 0;
        }
    }

    return 1;
}

int func_800DBD80(func_800E78F4_t* arg0, func_800DCAA0_t* arg1)
{
    D_800F4538_t* player;
    int distance;
    int range;
    int id;

    if (arg1->unkC_19 == 0 || D_800F58BC->unk18 < arg1->unk4_13
        || !func_800DBCB4(arg0, arg1)) {
        return 0;
    }

    id = arg1->unkC_0;
    distance = arg0->unk1E4[id];

    if (D_800F45E0[id] != NULL
        && (distance > 320 * 320 || arg0->unk13 || func_800DBCEC(arg0, id))) {
        return 0;
    }

    if (arg1->unk8 < distance) {
        return 0;
    }

    // Potential bug in original, needs investigating.
    // The result of this call is not used.
    SquareRoot0(arg1->unk8);
    range = arg1->unk10.unk6;

    if (range > 0 && arg1->unk10.unk1 && distance < range * range) {
        return 0;
    }

    if (!arg0->unk1A4[id].unk0_31) {
        return 0;
    }

    player = D_800F4538[0];

    if (player->unk0.unkA_0 || player->unk0.unkA_3 == 1) {
        return 0;
    }

    if (!arg1->unk10.unk2 && !arg0->unk1A4[id].unk0_2) {
        return 0;
    }

    return arg1->unk10.unk3 || !arg0->unk1A4[id].unk0_27;
}

#endif
