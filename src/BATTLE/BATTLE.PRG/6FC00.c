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

extern int D_800F58C4;

u_int func_800D8400(func_800E78F4_t* arg0, int arg1, int arg2, int arg3)
{
    union {
        vs_battle_movementPosition fields;
        u_int value;
    } pos;
    vs_battle_movementPosition source;
    u_int directions;
    int count;
    int i;
    int result;

    if (arg0->unk7 != 0) {
        return 0;
    }

    source = arg0->unk34;
    pos.fields.status = 1;

    if (arg1 == arg2) {
        directions = arg3;
        count = 1;
    } else {
        u_int quadrant = (u_int)(arg3 & 0xFFF) >> 10;

        arg3 = (arg3 & 0x3FF) >= 0x201U ? ((quadrant + 1) & 3) * 2 : quadrant * 2;
        directions = (arg3 == arg1 ? arg2 << 16 : arg1 << 16) | arg3;
        count = 2;
    }

    for (i = 0; i < count; ++i) {
        arg3 = (directions >> (i * 16)) & 0xFFFF;
        pos.fields.x = source.x + ((D_800F16EC_t*)0x1F8003EC)[arg3].dx;
        pos.fields.z = source.z + ((D_800F16EC_t*)0x1F8003EC)[arg3].dz;

        result = func_800D96C8(arg0, source, pos.fields, arg3);

        if (result > 0) {
            result = func_800D954C(arg0, pos.fields);
            if (result >= 0) {
                if (result != 0) {
                    pos.fields.y = 0;
                    return pos.value;
                }
                return 0;
            }
        } else if (result >= 0) {
            pos.value = func_800DB93C(arg0, pos.fields, arg3, source);
            if (pos.fields.status == 1) {
                pos.fields.y = 0;
                return pos.value;
            }
            if (pos.fields.status == 0) {
                continue;
            }
        }
        goto fail;
    }

    return 0;

fail:
    pos.fields.status = 2;
    pos.fields.y = 0;
    return pos.value;
}

int func_800D85D8(func_800E78F4_t* arg0)
{
    int i;
    int changed = 0;
    u_char status;
    vs_battle_actor* actor;

    for (i = 0; i < arg0->unk470; ++i) {
        func_800DCAA0_t* entry = arg0->unk430[i];

        if (entry->unkC_19 && entry->unk4_13 <= D_800F58BC->unk18
            && (!func_800E4CF4(arg0, entry, entry->unkC_0)
                || !func_800E4DF8(arg0, entry->unk4_0, entry->unk4_3))) {
            entry->unkC_19 = 0;
        }
    }

    if (arg0->unk470 > 0 && !arg0->unk430[0]->unkC_19) {
        changed = 1;

        for (i = 1; i < arg0->unk470; ++i) {
            func_800DCAA0_t* entry = arg0->unk430[i];

            if (entry->unkC_19) {
                arg0->unk430[0] = entry;
                func_800D9DD8(arg0);
                goto done;
            }
        }

        arg0->unk470 = 0;
    }

done:
    if (!arg0->unk470) {
        for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
            if (arg0->unk1A4[actor->id].unk0_6 == 3) {
                break;
            }
        }

        status = actor == NULL ? 3 : 2;
    } else {
        status = D_800F58BC->unk18 + 30 < arg0->unk430[0]->unk4_13;
    }

    arg0->unk131 = status;
    return changed;
}

static inline int _checkExtent(SVECTOR* from, SVECTOR* to, func_800E78F4_t* state, int id)
{
    func_800E78F4_t* other = ((func_800E78F4_t**)0x1F80037C)[id];
    int extent = other != NULL ? other->unkB8 : 128;

    return func_800E44E8(from, to, extent, state->unkB8);
}

static inline int _checkHeight(SVECTOR* from, SVECTOR* to, func_800E78F4_t* state, int id)
{
    func_800E78F4_t* other = ((func_800E78F4_t**)0x1F80037C)[id];
    int height = other != NULL ? ABS(other->unk82) : 64;

    return func_800E44E8(from, to, height, ABS(state->unk82));
}

void func_800D87E8(func_800E78F4_t* arg0, int id)
{
    int height;
    func_800DA1D4_t relation;
    func_800DA1D4_t final;
    D_800F4538_t* object;
    func_800E78F4_t* other;
    vs_battle_actor* actor;
    int owner;
    int blocked;
    int heading;
    int x;
    int z;
    u_int radius;
    u_int targetDistance;

    if (D_800F5878[id] != NULL) {
        D_800F4538_t* target = D_800F4538[id];

        if ((target->unk0.unkA_3 << 19) && (target->unk0.position.vy > arg0->unk4C.vy)) {
            height = -D_800F5878[id]->unkB8;
        } else {
            height = D_800F5878[id]->unk82;
        }
    } else {
        height = -64;
    }

    arg0->unk1E4[id] = func_800E4624(
        &arg0->unk4C, &vs_battle_actors[id]->unk44->unk0.position, arg0->unk82, height);

    if (D_800F45E0[id]
        || ((object = vs_battle_actors[id]->unk44),
            ((object->unk0.currentTile.x == arg0->unk34.x)
                && (object->unk0.currentTile.z == arg0->unk34.z)))
        || ((object->unk0.unkA_3 << 19)
            && ((object->unk0.lastTouchedTile.x == arg0->unk34.x)
                && (object->unk0.lastTouchedTile.z == arg0->unk34.z)))) {
        arg0->unk1A4[id].unk0_2 = 1;
        arg0->unk1A4[id].unk0_30 = 1;
    } else {
        if (++arg0->unk12B & 1) {
            arg0->unk1A4[id].unk0_30 =
                !_checkExtent(&object->unk0.position, &arg0->unk4C, arg0, id);
        } else {
            arg0->unk1A4[id].unk0_2 =
                !_checkHeight(&object->unk0.position, &arg0->unk4C, arg0, id);
        }

        if (arg0->unk1A4[id].unk0_2) {
            arg0->unk1A4[id].unk0_30 = 1;
        }
    }

    arg0->unk1A4[id].unk0_3 =
        func_800E437C(&arg0->unk4C, &vs_battle_actors[id]->unk44->unk0.position,
            arg0->unk58->unk0.facing + arg0->unk58->unk0.unk14, arg0->unk1E4[id])
        >= arg0->unkA8;

    memcpy(&relation, &arg0->unk1A4[id], sizeof relation);

    if (arg0->unk88 == id) {
        relation.unk0_0 = 1;
        relation.unk0_5 = 1;
        relation.unk0_1 = 0;
    } else {
        relation.unk0_0 = (arg0->unk1E4[id] <= arg0->unkAC) && relation.unk0_3
                       && id != arg0->unk88 && (arg0->unk25 || relation.unk0_30);

        if (relation.unk0_15) {
            --relation.unk0_15;
            relation.unk0_0 = 1;
        }

        relation.unk0_1 = !relation.unk0_0 && arg0->unk1A4[id].unk0_0;
        relation.unk0_5 =
            relation.unk0_0 || ((arg0->unk1E4[id] < arg0->unkA4) && relation.unk0_30);
    }

    if ((*(u_short(**)[32])0x1F8003C0)[vs_battle_actors[id]->unk44->unk0.currentTile.z]
                                      [vs_battle_actors[id]->unk44->unk0.currentTile.x]
        & 0x2000) {
        relation.unk0_31 = 1;
    } else {
        relation.unk0_31 = relation.unk0_0;
    }

    memcpy(&arg0->unk1A4[id], &relation, sizeof relation);
    blocked = 0;
    radius = 63;

    x = arg0->unk58->unk0.position.vx;
    z = arg0->unk58->unk0.position.vz;

    owner = arg0->unk88;
    targetDistance = arg0->unk1E4[id];
    heading = ratan2(vs_battle_actors[id]->unk44->unk0.position.vx - x,
        vs_battle_actors[id]->unk44->unk0.position.vz - z);
    other = ((func_800E78F4_t**)0x1F80037C)[id];

    if (other != NULL) {
        radius = other->unk92;
    }

    for (actor = vs_battle_actors[0]; actor != NULL; actor = actor->next) {
        int candidate = actor->id;
        int angle;
        int distance;

        if (candidate == owner || candidate == id
            || (arg0->unk1E4[candidate] > targetDistance)) {
            continue;
        }

        angle = ratan2(D_800F4538[candidate]->unk0.position.vx - x,
                    D_800F4538[candidate]->unk0.position.vz - z)
              - heading;

        if (rcos(angle) < 0) {
            continue;
        }

        distance = (vs_gte_rsqrt(arg0->unk1E4[candidate]) * rsin(angle)) >> 12;
        distance = ABS(distance);

        if (distance < radius) {
            blocked = 1;
            break;
        }
    }

    arg0->unk1A4[id].unk0_27 = blocked;

    if (arg0->unk88 == id || ((func_800E78F4_t**)0x1F80037C)[id] == NULL) {
        return;
    }

    final = arg0->unk1A4[id];

    if (final.unk0_20) {
        --final.unk0_20;

        if (!final.unk0_20) {
            final.unk0_6 = final.unk0_28;
        }
    }

    if (arg0->unk22 && final.unk0_6 == 3) {
        if (final.unk0_0) {
            final.unk0_8 = 0;
        } else {
            ++final.unk0_8;

            if (final.unk0_8 >= 121) {
                final.unk0_6 = 1;
            }
        }
    }

    arg0->unk1A4[id] = final;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6FC00", func_800D8EF4);

void func_800D9538(void) { D_800F58C4 = *(int*)0x1F8003F8; }
