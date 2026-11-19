#include "common.h"
#include "6E4CCPrivate.h"
#include "6E4CCShared.h"
#include "entity.h"
#include <abs.h>

#ifdef NON_MATCHING

static void setCommandTile(Actor* actor, vs_TilePosition* tile)
{
    actor->commandArgs.u8[0] = tile->x;
    actor->commandArgs.u8[1] = tile->surface;
    actor->commandArgs.u8[2] = tile->z;
    actor->commandArgs.u8[3] = tile->extra;
}

static int isCornerBlocked(func_800E78F4_t* arg0, int dx, int dz, int checkHeight)
{
    int tileX = arg0->unk34.x;
    int tileZ = arg0->unk34.z;
    int direction = ((signed char (*)[4])0x1F8003E0)[dz][dx];
    u_short(*map)[32];
    int blockedDirections;
    int height;
    int neighbourHeight;

    if (direction < 0) {
        return 0;
    }

    if (!checkHeight) {
        return func_800E4690(arg0->unk34, direction);
    }

    map = *(u_short(**)[32])0x1F8003BC;
    blockedDirections = (*(u_char**)0x1F8003C4)[tileZ * *(u_char*)0x1F8003DC + tileX];
    height = (map[tileZ][tileX] >> 10) & 7;
    neighbourHeight = (map[tileZ + dz - 1][tileX + dx - 1] >> 10) & 7;

    return ((blockedDirections >> direction) & 1) || (height < neighbourHeight);
}

static void func_800DF4EC(func_800E78F4_t* arg0, Actor* actor)
{
    int worldX;
    int worldZ;

    actor->unk9 = 23;
    setCommandTile(actor, &arg0->unk170);

    worldX = arg0->unk170.x * 128 + 64;
    worldZ = arg0->unk170.z * 128 + 64;

    setVector(&arg0->unk174, worldX, func_800E42D4(worldX, worldZ), worldZ);

    // The original zero-extends vx and vz here, probably a bug so they are signed here.
    actor->commandArgs.s32[1] = ratan2(arg0->unk4C.vx - worldX, arg0->unk4C.vz - worldZ);

    func_800E4C1C(arg0->unk170.x, arg0->unk170.z);
}

void func_800DEEFC(func_800E78F4_t* arg0, int arg1)
{
    Actor* actor;
    D_800F4538_t* model;
    func_800DCAA0_t* node;
    SVECTOR* position;
    int angle;
    int speed;
    int target;
    int diff;
    int step;
    int sign;
    int inRange;
    int value;
    int kind;
    int from;
    int to;
    int worldX;
    int worldZ;
    int posX;
    int posZ;
    int nextX;
    int nextZ;
    int tileX;
    int tileZ;
    int centerX;
    int centerZ;
    int radius;
    int checkHeight;
    u_int packed;
    int pushX;
    int pushZ;
    int tile;

    *(int*)0x1F8003C8 = arg1;

    actor = arg0->unk54;
    actor->unk8 = 0x80;
    actor->unkA = arg0->unk15C;

    switch (arg1) {
    case 0:
        actor->unk9 = 2;
        return;

    case 1:
        actor->unk9 = 1;
        return;

    case 2:
        actor->unk9 = 20;
        return;

    case 3:
        actor->unk9 = 3;
        actor->commandArgs.u16[0] = arg0->unk188 & 0xFFF;
        actor->commandArgs.u16[1] = arg0->unkBA;
        return;

    case 4:
        model = arg0->unk58;
        target = arg0->unk18A & 0xFFF;
        diff = (target - (model->unk0.unk14 + model->unk0.facing)) & 0xFFF;
        step = arg0->unk13A;

        if (diff < ONE / 2) {
            sign = 1;
            inRange = model->unk0.unk14 < 800;
        } else {
            sign = -1;
            inRange = model->unk0.unk14 > -800;
        }

        if (arg0->unk2A & inRange) {
            actor->unk9 = 7;
        } else {
            actor->unk9 = 3;
        }

        if ((diff == 0) || (diff < step) || (ONE - diff < step)) {
            actor->unk9 = 4;
            value = target;
        } else if (actor->unk9 == 3) {
            value = sign * step + model->unk0.facing;
        } else {
            value = sign * step + model->unk0.unk14;
        }

        actor->commandArgs.u16[0] = value;
        actor->commandArgs.u16[1] = step;
        return;

    case 5:
        angle = arg0->unk188 * (ONE / 8);
        break;

    case 6:
        // Potential bug in original, needs investigating.
        // The second argument is the difference of the surface bytes shifted left by 24,
        // where the difference of the z bytes would be expected.
        angle = ratan2(arg0->unk34.x - arg0->unk168.x,
            (arg0->unk34.surface - arg0->unk168.surface) << 24);
        break;

    case 7:
        angle = arg0->unk188;
        break;

    case 8:
        actor->unk9 = 19;
        actor->commandArgs.s32[0] = arg0->unk17C;
        actor->commandArgs.s32[1] = arg0->unk180;
        actor->commandArgs.s32[2] = arg0->unk184;
        return;

    case 9:
    case 10:
        actor->unk9 = arg1 == 9 ? 16 : 17;
        actor->commandArgs.u16[0] = arg0->unk17C;
        actor->commandArgs.u16[1] = arg0->unk184;
        actor->commandArgs.u16[2] = arg0->unk180;
        return;

    case 11:
        actor->unk9 = 21;
        setCommandTile(actor, &arg0->unk170);
        func_800E4C1C(arg0->unk170.x, arg0->unk170.z);
        return;

    case 12:
        actor->unk9 = 22;
        worldX = arg0->unk170.x * 128 + 64;
        worldZ = arg0->unk170.z * 128 + 64;
        actor->commandArgs.u16[0] = worldX;
        actor->commandArgs.u16[1] = func_800E42D4(worldX, worldZ) + arg0->unkBE;
        actor->commandArgs.u16[2] = worldZ;
        return;

    case 13:
        func_800DF4EC(arg0, actor);
        return;

    case 14:
        from = func_800E42E0(arg0->unk34);
        to = func_800E42E0(arg0->unk170);

        if (ABS(to - from) < arg0->unkB0) {
            actor->unk9 = 11;
        } else if (arg0->unk15E & 8) {
            func_800DF4EC(arg0, actor);
            return;
        } else if (arg0->unk15E & 0x30) {
            actor->unk9 = 18;
        } else if (arg0->unk15E & 0xC0) {
            actor->unk9 = 14;
        } else {
            actor->unk9 = 11;
        }

        setCommandTile(actor, &arg0->unk170);

        worldX = arg0->unk170.x * 128 + 64;
        worldZ = arg0->unk170.z * 128 + 64;

        setVector(&arg0->unk174, worldX, func_800E42D4(worldX, worldZ), worldZ);

        if (arg0->unk1 && (arg0->unk224 & 0x84)) {
            speed = arg0->unk226;
        } else if (arg0->unk1 && (arg0->unk225 & 0x84)) {
            speed = arg0->unk227;
        } else if (arg0->unk224 & 0x42) {
            speed = arg0->unk226;
        } else if (arg0->unk225 & 0x42) {
            speed = arg0->unk227;
        } else {
            actor->unk9 = 2;
            return;
        }

        actor->commandArgs.s32[1] = speed;

        if ((actor->id != 0) && (arg0->unk170.surface == 0)) {
            func_800E4C1C(arg0->unk170.x, arg0->unk170.z);
        }
        return;

    case 15:
        node = arg0->unk22C;
        actor->commandArgs.u16[0] = node->unk4_0;
        actor->commandArgs.u16[1] = node->unk4_3;

        kind = arg0->unk230[node->unk4_0][node->unk4_3].unk0_3;

        if ((kind == 1) || (kind == 2)) {
            actor->commandArgs.u16[2] = node->unkC_0;
            actor->commandArgs.u16[3] = node->unkC_4;
        } else {
            position = &D_800F4538[node->unkC_0]->unk0.position;
            actor->commandArgs.u16[2] = position->vx;
            actor->commandArgs.u16[3] = position->vy - node->unkC_7;
            actor->commandArgs.u16[4] = position->vz;
        }

        actor->unk9 = 24;
        return;

    case 16:
        actor->unk9 = 6;
        actor->commandArgs.u16[0] = arg0->unk188;
        actor->commandArgs.u16[1] = arg0->unk13A;
        return;

    case 17:
        actor->unk9 = 8;
        return;
    }

    angle &= 0xFFF;
    actor->commandArgs.u16[0] = angle;
    angle = (ONE * 3 / 4 - angle) & 0xFFF;

    if (arg0->unk1 && (arg0->unk224 & 0x84)) {
        actor->unk9 = 10;
        speed = arg0->unk226;
    } else if (arg0->unk1 && (arg0->unk225 & 0x84)) {
        actor->unk9 = 10;
        speed = arg0->unk227;
    } else if (arg0->unk224 & 0x42) {
        actor->unk9 = 9;
        speed = arg0->unk226;
    } else if (arg0->unk226 & 0x42) {
        // Potential bug in original, needs investigating.
        // This test reads unk226, where the same test in case 14 reads unk225.
        actor->unk9 = 9;
        speed = arg0->unk227;
    } else {
        actor->unk9 = 2;
        return;
    }

    tileX = arg0->unk34.x;
    tileZ = arg0->unk34.z;
    radius = arg0->unk92;
    checkHeight = *(int*)0x1F8003F4;

    // The original zero-extends vx and vz here, probably a bug so they are signed here.
    posX = arg0->unk4C.vx;
    posZ = arg0->unk4C.vz;

    nextX = posX + ((rcos(angle) * speed) >> 12);
    nextZ = posZ + ((rsin(angle) * speed) >> 12);

    // Potential bug in original, needs investigating.
    // nextX and nextZ are packed into one word and read back from it, so a negative
    // nextX also sets the upper half that is read back as nextZ.
    packed = (nextZ << 16) | nextX;

    if (!isCornerBlocked(arg0, ((nextX - radius) >> 7) - tileX + 1,
            ((nextZ - radius) >> 7) - tileZ + 1, checkHeight)
        && !isCornerBlocked(arg0, ((nextX - radius) >> 7) - tileX + 1,
            ((nextZ + radius) >> 7) - tileZ + 1, checkHeight)
        && !isCornerBlocked(arg0, ((nextX + radius) >> 7) - tileX + 1,
            ((nextZ - radius) >> 7) - tileZ + 1, checkHeight)
        && !isCornerBlocked(arg0, ((nextX + radius) >> 7) - tileX + 1,
            ((nextZ + radius) >> 7) - tileZ + 1, checkHeight)) {
        return;
    }

    centerX = tileX * 128 + 64;
    centerZ = tileZ * 128 + 64;

    if ((packed & 0xFFFF) < centerX) {
        pushX = centerX - 64 + radius;
    } else {
        pushX = centerX + 63 - radius;
    }

    if ((packed >> 16) < centerZ) {
        pushZ = centerZ - 64 + radius;
    } else {
        pushZ = centerZ + 63 - radius;
    }

    pushX -= posX;
    pushZ -= posZ;

    if ((pushX == 0) && (pushZ == 0)) {
        return;
    }

    tile = (tileZ << 16) | tileX;

    if (tile == (arg0->unk9C & 0xFF00FF)) {
        return;
    }

    arg0->unk9C = tile;
    actor->unk9 = 13;
    actor->commandArgs.s32[0] = pushX * ONE;
    actor->commandArgs.s32[1] = pushZ * ONE;
}

#endif
