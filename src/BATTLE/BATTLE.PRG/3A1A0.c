#include "common.h"
#include "30DB0.h"
#include "3A1A0.h"
#include "../../SLUS_010.40/main.h"

typedef struct {
    int unk0;
    int pad04[5];
    D_800F45E0_t* unk18;
    short unk1C[18];
    int unk40;
} D_1F8003BC_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
} func_800A3054_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} func_8008D2C0_t;

typedef struct {
    char unk0[6];
    short unk6;
} func_800A6660_t;

void func_800A29A0(D_800F4538_t*);
void func_800ACF54(D_800F4538_t*);
void func_800E4C28();
u_int func_800A9C54(u_char, void*, int);
void func_800AEAE8(D_800F4538_t*);
void func_800AECA0(MATRIX*);
void func_800B28A8(void*, MATRIX*, int);
int func_8008D2C0(func_8008D2C0_t*);
short func_8008DD0C(int arg0, int arg1);
D_800F4538_t* func_800A3C34(int, int, int, int);
short func_8008DC7C(int, int);
short func_8008DA24(int, int);
u_int* func_800A8D64(SVECTOR*, int);
int func_800B13CC(int, int, int);
int func_800A92B8(int, int);
int func_800A9378(int, int, int, int);
void func_800AA850(int, short, int);
int func_800A8E84(D_800F45E0_t*, SVECTOR*);
void func_800B0908(D_800F45E0_t*, int);
int func_800A6EE8(SVECTOR*, int, int, int);
int func_800E75EC(void);
int func_8009E180(D_800F4538_t*, SVECTOR*);

extern u_int* D_800F49F0;
extern u_short D_800F49F4;
extern u_char D_800F49F8;
extern u_char D_800F49F9;
extern SVECTOR D_800F4B08;
extern char D_800F4B18;
extern u_char D_800E9278[];

void func_800A29A0(D_800F4538_t* arg0)
{
    int temp_v0;
    u_int var_v0;
    int var_v0_2;
    int var_v0_3;

    temp_v0 = arg0->unk0.unkB_0;
    switch (temp_v0) {
    case 1:
        (*(u_int*)((char*)arg0 + 8)) = (u_int)((*(u_int*)((char*)arg0 + 8)) & 0xFFDFFFFF);
        func_800A0204((int)arg0->unk0.unkF, 0x13, 0, 8);
        func_800A01C8((int)arg0->unk0.unkF, 0x14, 8, 0);
        (*(u_char*)((char*)arg0 + 0x57)) = 0;
        var_v0 =
            ((((*(u_int*)((char*)arg0 + 8)) & 0xF0FFFFFF) | 0x02000000) & ~0xF00) | 0x600;
        goto block_22;
    default:
        return;
    case 2:
        if ((u_int)(((u_int)(*(u_int*)((char*)arg0 + 8)) >> 8) & 0xF) >= 8U) {
            if (arg0->unk0.unk13 == 0xFC) {
                var_v0_2 =
                    (u_int)(((u_int)(*(u_int*)((char*)D_800F4538[arg0->unk0.unk12] + 8))
                                >> 8)
                            & 0xF)
                    < 9U;
                goto block_8;
            }
            if ((*(u_int*)((char*)arg0 + 0x119C)) & 0x20000) {
                var_v0_2 = arg0->unk5CC;
            block_8:
                if (var_v0_2 == 0) {
                    (*(u_int*)((char*)arg0 + 8)) =
                        (u_int)(((*(u_int*)((char*)arg0 + 8)) & ~0xF00) | 0x900);
                    func_800A9C54(arg0->unk0.unkF, (char*)arg0 + 0x5EC, 0);
                    arg0->unk0.facing = (u_short)(*(u_short*)((char*)arg0 + 0x5F2));
                    func_800A0204((int)arg0->unk0.unkF, 0x15, 0, 8);
                    func_800A01C8((int)arg0->unk0.unkF, 0x16, 8, 0);
                    var_v0 = ((*(u_int*)((char*)arg0 + 8)) & 0xF0FFFFFF) | 0x03000000;
                    goto block_22;
                }
            }
        }
        break;
    case 3:
        if (!((*(u_int*)((char*)arg0 + 8)) & 0xF00)) {
            if (arg0->unk0.unk13 == 0xFC) {
                var_v0_3 = (*(u_int*)((char*)D_800F4538[arg0->unk0.unk12] + 8)) & 0xF00;
            } else {
                var_v0_3 = arg0->unk5CC;
            }
            if (var_v0_3 == 0) {
                func_800A0204((int)arg0->unk0.unkF, 1, 0, 8);
            case 4:
                func_800ACF54(arg0);
                func_800E4C28(arg0->unk0.currentTileX, arg0->unk0.currentTileZ);
            case 5:
                if ((int)arg0->unk17FD >= 2U) {
                    if ((*(u_int*)((char*)D_800F4538[arg0->unk17FD] + 8)) & 0x0F000000) {
                        (*(u_int*)((char*)arg0 + 8)) =
                            (u_int)(((*(u_int*)((char*)arg0 + 8)) & 0xF0FFFFFF)
                                    | 0x05000000);
                        return;
                    }
                    goto block_21;
                }
            block_21:
                var_v0 = (*(u_int*)((char*)arg0 + 8)) & 0xF0FFFFFF;
                goto block_22;
            }
        }
        break;
    }
    return;
block_22:
    (*(u_int*)((char*)arg0 + 8)) = var_v0;
}

void func_800A2C48(D_800F4538_t* arg0)
{
    func_800A9C54(arg0->unk0.unkF, &arg0->unk5DC[4], 0);
    arg0->unk6E0 = 0;
    arg0->unk0.unkB_0 = 4;
    func_800A29A0(arg0);
    if (arg0->unk17FD >= 2) {
        func_800A2C48(D_800F4538[arg0->unk17FD]);
    }
}

void func_800A2FBC(D_800F4538_t*);
void func_800A9EB4(int, short, int);
void func_800AA620(int, SVECTOR*, int);

void func_800A2CD4(D_800F4538_t* arg0)
{
    int temp_v0;
    u_short temp_v0_2;
    u_int temp_v1;
    u_int var_v0;
    u_char temp_v1_2;

    temp_v0 = ((u_int)(*(u_int*)((char*)arg0 + 8)) >> 0x1C) & 7;
    switch (temp_v0) {
    case 1:
        func_800A0204((int)arg0->unk0.unkF, 9, 0, 8);
        func_800A9C54(arg0->unk0.unkF, (char*)arg0 + 0x5EC, -1);
        func_800A9EB4(arg0->unk0.unkF, (*(short*)((char*)arg0 + 0x5F2)), 8);
        arg0->unk5CA = (u_short)arg0->unk0.unk1A;
        arg0->unk0.unk1A = 0U;
        if (arg0->unk5CA != 0) {
            (*(u_int*)((char*)arg0 + 8)) =
                (u_int)(((*(u_int*)((char*)arg0 + 8)) & 0x8FFFFFFF) | 0x20000000);
            return;
        }
        goto block_10;
    default:
        return;
    case 2:
        func_800A2FBC(arg0);
        func_800A9378(
            arg0->unk0.position.vx, arg0->unk0.position.vy, arg0->unk0.position.vz, 2);
        if ((*(int*)&D_800F49F4) != 0) {
            (*(u_int*)((char*)arg0 + 8)) =
                (u_int)((*(u_int*)((char*)arg0 + 8)) | 0x200000);
            goto block_16;
        }
        if (arg0->unk5CA == 0) {
            func_800A0204((int)arg0->unk0.unkF, 0xA, 0, 8);
            arg0->unk0.unkA_5 = 0;
            arg0->unk0.unkB_4 = 3;
            return;
        }
        break;
    case 3:
        if ((arg0->unk0.unk1A == 0) && ((*(u_int*)((char*)arg0 + 0x119C)) & 0x20000)) {
        block_10:
            (*(u_int*)((char*)arg0 + 8)) =
                (u_int)((*(u_int*)((char*)arg0 + 8)) & 0xFFDFFFFF);
            func_800ACF54(arg0);
            func_800E4C28(arg0->unk0.currentTileX, arg0->unk0.currentTileZ);
            func_800A0204((int)arg0->unk0.unkF, 1, 0, 8);
            arg0->unk0.unkB_4 = 0;
            break;
        }
        break;
    case 4:
        func_800A0204((int)arg0->unk0.unkF, 7, 0, 8);
        func_800A01C8((int)arg0->unk0.unkF, 0x25, 8, 0);
        func_800AA620(arg0->unk0.unkF, (SVECTOR*)((char*)arg0 + 0x5EC), -1);
        func_800A9EB4(arg0->unk0.unkF, (*(short*)((char*)arg0 + 0x5F2)), 8);
        temp_v0_2 = arg0->unk0.unk1A;
        arg0->unk0.unk1A = 0U;
        arg0->unk5CA = temp_v0_2;
        temp_v1 = (*(u_int*)((char*)arg0 + 8)) | 0x200000;
        (*(u_int*)((char*)arg0 + 8)) = temp_v1;
        if (arg0->unk5CA == 0) {
            arg0->unk6E0 = 0;
            goto block_16;
        }
        var_v0 = (temp_v1 & 0x8FFFFFFF) | 0x50000000;
        goto block_22;
    case 5:
        func_800A2FBC(arg0);
        func_800A9378(
            arg0->unk0.position.vx, arg0->unk0.position.vy, arg0->unk0.position.vz, 3);
        if ((*(int*)&D_800F49F4) == 0) {
            if (arg0->unk5CA == 0) {
            block_16:
            block_17:
                func_800A0204((int)arg0->unk0.unkF, 1, 0, 8);
                arg0->unk0.unkB_4 = 0;
                break;
            }
        } else {
            goto block_17;
        }
        break;
    case 6:
        temp_v1_2 = arg0->animationId;
        if ((temp_v1_2 != 0xC7) && (temp_v1_2 != 0xC9) && (arg0->unk5CC == 0)) {
            goto block_21;
        }
        break;
    }
    return;
block_21:
    var_v0 = (*(u_int*)((char*)arg0 + 8)) & 0x8FFFFFFF;
block_22:
    (*(u_int*)((char*)arg0 + 8)) = var_v0;
}

void func_800A2FBC(D_800F4538_t* arg0)
{
    int temp_a1 = arg0->unk0.unk34.vx / arg0->unk5CA;
    arg0->unk0.unk34.vx -= temp_a1;
    arg0->unk0.position.vx += temp_a1;

    temp_a1 = arg0->unk0.unk34.vy / arg0->unk5CA;
    arg0->unk0.unk34.vy -= temp_a1;
    arg0->unk0.position.vy += temp_a1;

    temp_a1 = arg0->unk0.unk34.vz / arg0->unk5CA;
    arg0->unk0.unk34.vz -= temp_a1;
    arg0->unk0.position.vz += temp_a1;

    --arg0->unk5CA;
}

void func_800A3054(D_800F4538_t* arg0, func_800A3054_t* arg1)
{
    int var_a2;
    int var_a3;

    var_a2 = 0x3F;
    var_a3 = 0x3F;
    if (arg1->unk0 < 0) {
        var_a2 = -0x3F;
    }
    if (arg1->unk4 < 0) {
        var_a3 = -0x3F;
    }
    arg0->unk181A = 1;
    arg0->unk1814 = (u_short)arg0->unk0.position.vx + var_a2;
    arg0->unk1818 = (u_short)arg0->unk0.position.vz + var_a3;
}

inline int func_800A3310(int, SVECTOR*);
void func_800A3394(int, SVECTOR*);
int func_800A3500(int, int);
func_8008D2C0_t* func_800A4A24(int);
void func_800ACF54(D_800F4538_t*);

void func_800A30A0(int actorId, func_80089888_t* placement, int height, int mode)
{
    D_800F4538_t* actor;
    SVECTOR* position;
    short z;
    int ceiling;
    int flags;
    int value;
    u_char tileType;
    int* anchor;

    actor = D_800F4538[actorId];
    (*(int*)((char*)actor + 0x5C)) = *(int*)placement;
    actor->unk0.position.vx = ((u_char)placement->unk0_0 << 7) + 0x40;
    z = ((u_char)placement->unk0_16 << 7) + 0x40;
    actor->unk0.position.vz = z;
    actor->unk0.position.vy = func_800A3500(actor->unk0.position.vx, z);
    if (mode == 0x10 || mode == 0x20) {
        ceiling = func_800E75EC();
        if (ceiling == 0) {
            value = -0x180;
        } else {
            value = ceiling - actor->unk0.position.vy;
            if (value >= -0x7F) {
                value = -0x80;
            }
        }
        position = &actor->unk0.position;
        actor->unk0.position.vy = (u_short)actor->unk0.position.vy + value;
        if (func_800A3310(actorId, position) != 0) {
            func_800A3394(actorId, position);
        }
        (*(int*)((char*)actor + 0x8)) |= 0x200000;
        func_800A0204(actorId, 8, 0, 0);
    } else {
        if (mode == 0x40 || mode == 0x80) {
            (*(int*)((char*)actor + 0x8)) |= 0x400000;
        }
        tileType = (u_char)placement->unk0_8;
        if (tileType == 7) {
            actor->unk0.unk5D = 0;
            actor->unk0.position.vy = (short)height;
            actor->unk0.unk34.vy = 0;
            (*(int*)((char*)actor + 0x8)) =
                (int)(((*(int*)((char*)actor + 0x8)) & 0xFFF8FFFF) | 0x30000);
        } else {
            if (tileType >= 2U) {
                anchor = (int*)func_800A4A24((u_char)placement->unk0_8);
                (*(int*)((char*)actor + 0x1C)) = (int)anchor[0];
                (*(int*)((char*)actor + 0x20)) = (int)anchor[1];
                (*(int*)((char*)actor + 0x17EC)) = (int)anchor[0];
                (*(int*)((char*)actor + 0x17F0)) = (int)anchor[1];
                (*(short*)((char*)actor + 0x17F2)) = (short)(u_char)placement->unk0_8;
                flags = ((*(int*)((char*)actor + 0xC)) & ~0xF)
                      | ((u_char)placement->unk0_8 & 0xF);
                (*(int*)((char*)actor + 0xC)) = flags;
                (*(int*)((char*)actor + 0xC)) =
                    (int)((flags & ~0xF0) | (((u_char)placement->unk0_8 & 0xF) * 0x10));
            }
            func_800A0204(actorId, 1, 0, 0);
        }
    }
    func_800ACF54(actor);
    actor->unk0.unk1A = 0;
    value = *((u_char*)placement + 3);
    actor->unk0.unk3E = 0;
    actor->unk0.unk18 = 0;
    (*(short*)((char*)actor + 0x18D2)) = 0;
    (*(short*)((char*)actor + 0x18D4)) = 0;
    (*(short*)((char*)actor + 0x18D6)) = 0;
    (*(short*)((char*)actor + 0x18D8)) = 0;
    value *= 0x10;
    actor->unk0.facing = value;
    func_800A0ABC(actorId);
    actor->unk6E4 = 0;
}

inline int func_800A3310(int arg0, SVECTOR* arg1)
{
    int i;

    for (i = 2; i < arg0; ++i) {
        D_800F4538_t* temp_a2 = D_800F4538[i];
        if (temp_a2 != NULL && temp_a2->unk0.unkA_5
            && *(int*)&temp_a2->unk0.position == *(int*)arg1
            && temp_a2->unk0.position.vz == arg1->vz) {
            return i;
        }
    }
    return 0;
}

void func_800A3394(int arg0, SVECTOR* arg1)
{
    SVECTOR pos;
    int floor;
    int retried;
    D_800F4538_t* actor = D_800F4538[arg0];

    pos.vx = arg1->vx;
    pos.vz = arg1->vz;
    pos.vy = arg1->vy - 0xC0;
    floor = func_800E75EC();
    retried = 0;

    while (1) {
        if (func_800A3310(arg0, &pos) != 0) {
            pos.vy -= 0xC0;
        } else if (floor != 0 && pos.vy - actor->menuCameraHeightOffset < floor) {
            if (retried != 0) {
                return;
            }
            retried = 1;
            pos.vy = arg1->vy - 0x60;
        } else {
            arg1->vy = pos.vy;
            return;
        }
    }
}

int func_800A3500(int arg0, int arg1)
{
    int h;
    int i;
    D_800F45E0_t* actor;

    h = func_8008DA24(arg0, arg1);
    h <<= 17;
    h >>= 17;

    for (i = 0; i < 16; ++i) {
        actor = D_800F45E0[i];
        if (actor != NULL && actor->unk1C == arg0 && actor->unk20 == arg1
            && actor->unk1E - 0x80 < h) {
            h = actor->unk1E - 0x80;
        }
    }
    return h;
}

void func_800A35A8(void)
{
    int i;
    int j;
    int h;
    int x;
    int z;
    D_800F4538_t* actor;
    D_800F45E0_t* obj;

    for (i = 2; i < 17; ++i) {
        actor = D_800F4538[i];

        if (actor != NULL && !actor->unk0.unkA_5 && actor->unk0.unk5D < 2
            && !actor->unk0.unkA_0) {
            x = actor->unk0.position.vx;
            z = actor->unk0.position.vz;
            h = func_8008DA24(x, z);
            h <<= 17;
            h >>= 17;

            for (j = 0; j < 16; ++j) {
                obj = D_800F45E0[j];
                if (obj != NULL && obj->unk1C == x && obj->unk20 == z
                    && obj->unk1E - 0x80 < h) {
                    h = obj->unk1E - 0x80;
                }
            }

            actor->unk0.position.vy = h;
        }
    }
}

void func_800A36E0(int arg0, int arg1, func_8006EBF8_t* arg2)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        arg2->unk0.unk0.value = temp_a0->unk1868;
        if (temp_a0->unk0.unkA_5 && ((arg1 == 0x10) || (arg1 == 0x20))) {
            arg2->unk0.unk0.value = *(int*)&temp_a0->unk0.currentTileX;
        }
        arg2->unk0.unk0.fields.unk0_24 = temp_a0->unk0.facing / 16;
    }
}

int func_800A3760(int arg0, int arg1, int arg2)
{
    int i;
    int maxDist;
    int bestDist;
    int best = -1;
    D_800F4538_t* self = D_800F4538[arg0];

    if (self == NULL) {
        return -1;
    }

    maxDist = arg1 * arg1;

    for (i = 0; i < 17; ++i) {
        D_800F4538_t* actor;
        int dx;
        int dy;
        int dz;
        int dist;
        int angle;

        if (i == arg0) {
            continue;
        }
        actor = D_800F4538[i];
        if (actor == NULL || actor->unk0.skip) {
            continue;
        }
        dy = actor->unk0.position.vy - self->unk0.position.vy;
        if (dy < -arg2 || dy > arg2) {
            continue;
        }
        dx = actor->unk0.position.vx - self->unk0.position.vx;
        dz = actor->unk0.position.vz - self->unk0.position.vz;
        dist = dx * dx;
        if (dist < 0) {
            dist = -dist;
        }
        dz = dz * dz;
        if (dz < 0) {
            dz = -dz;
        }
        dist += dz;
        if (dist > maxDist) {
            continue;
        }
        angle = func_8009E180(self, &actor->unk0.position);
        if (angle < -ONE / 4 || angle > ONE / 4) {
            continue;
        }
        if (best == -1) {
            best = i;
            bestDist = dist;
        } else if (dist < bestDist) {
            best = i;
            bestDist = dist;
        }
    }
    return best;
}

extern int D_800F49E8;
int func_800A3BC4(int, int);
int func_800A3DB4(int, int, int);
int func_800A91DC(int, int, int);

int func_800A38E0(int actorId)
{
    D_800F4538_t* actor = D_800F4538[actorId];
    D_800F45E0_t* object;
    int direction;
    int x;
    int z;
    int farX;
    int farZ;
    int objectId;
    int found;
    int oldX;
    int oldZ;
    int flags;
    if (actor == 0)
        return -1;
    if ((*((u_int*)(((char*)actor) + 0x5AC))) & 3)
        return -1;
    flags = *((u_int*)(((char*)actor) + 8));
    if (flags & 0x70000)
        return -1;
    if (flags & 0x180000)
        goto fail;
    direction = actor->unk0.facing + 0x200;
    direction &= 0xFFF;
    direction /= 1024;
    D_800F49E8 = direction;
    oldX = (farX = (x = actor->unk0.currentTileX));
    oldZ = (farZ = (z = actor->unk0.currentTileZ));
    found = (direction < 2) ? (-1) : (1);
    if (direction & 1) {
        x += found;
        farX = oldX + (found * 2);
    } else {
        z += found;
        farZ = oldZ + (found * 2);
    }
    if ((x < 0) || (z < 0))
        return -1;
    if ((*((u_int*)(((char*)actor) + 0x5AC))) & 8) {
        x = (x * 128) + 64;
        objectId = actor->unk0.unk13;
        object = D_800F45E0[objectId];
        z = (z * 128) + 64;
        if (object->unk1A != 0)
            goto fail;
        if (!func_800A3DB4(x, z, actor->unk0.position.vy - 128))
            return -1;
        direction = actor->unk0.position.vy - 384;
        if (direction < func_800A3BC4(actor->unk0.position.vx, actor->unk0.position.vz))
            goto fail;
        if (direction < func_800A3BC4(x, z))
            return -1;
        return objectId;
    } else {
        found = func_800A91DC(x, z, 0);
        if (found == 0)
            goto fail;
        object = D_800F45E0[found];
        objectId = found;
        if (((*((u_int*)(((char*)object) + 0x16C))) & 0x30) == 0x10)
            goto fail;
        if (object->unk1A != 0)
            return -1;
        x = (x * 128) + 64;
        z = (z * 128) + 64;
        farX = (farX * 128) + 64;
        farZ = (farZ * 128) + 64;
        if (object->unk1E < (actor->unk0.position.vy - 128))
            return -1;
        if ((actor->unk0.position.vy + 64) < object->unk1E)
            return -1;
        if (((*((u_char*)(((char*)object) + 0x16C))) & 7) < 4U) {
            if (!func_800A3DB4(farX, farZ, object->unk1E))
                return -1;
        } else {
            direction = actor->unk0.position.vy - 384;
            if (direction
                < func_800A3BC4(actor->unk0.position.vx, actor->unk0.position.vz))
                return -1;
            if (direction < func_800A3BC4(x, z))
                goto fail;
        }
        if (func_800A3C00(object, 1) == 0)
            return objectId;
    }
fail:
    return -1;
}

int func_800A3BC4(int arg0, int arg1);
D_800F4538_t* func_800A3C00(D_800F45E0_t* arg0, u_int arg1);
int func_800A3DB4(int x, int z, int minimumHeight);

int func_800A3BC4(int arg0, int arg1)
{
    short temp_v0 = func_8008DD0C(arg0, arg1);
    if (temp_v0 == 0) {
        return 0;
    }
    return (temp_v0 << 0x11) >> 0x11;
}

D_800F4538_t* func_800A3C00(D_800F45E0_t* arg0, u_int arg1)
{
    return func_800A3C34(arg0->unk5C, arg0->unk5E, arg0->unk1E, arg1);
}

D_800F4538_t* func_800A3C34(int arg0, int arg1, int arg2, int arg3)
{
    int i;

    arg2 -= 192;

    if (arg3 < 2) {
        i = 0;
    } else {
        i = arg3;
    }

    for (; i < 17; ++i) {
        D_800F4538_t* actor = D_800F4538[i];
        if ((actor == NULL) || actor->unk0.skip || (actor->unk6E6 == 0x7F)) {
            continue;
        }
        if ((arg3 == 1)
            && (((actor->unk0.unkB_4 != 0) && (actor->unk0.unkB_4 < 3))
                || actor->unk0.unkA_0 || actor->unk0.unkB_0)) {
            SVECTOR* pos = &actor->unk5EC;
            if (((pos->vx & 0xFF) == arg0) && (arg1 == (pos->vy & 0xFF))) {
                return actor;
            }
            continue;
        }
        if ((i == 0) && (*((int*)&actor->unk5B4 - 2) & 0xF0000000)) {
            D_800F45E0_t* temp_v1 = D_800F45E0[actor->unk5AC_28];
            if ((arg0 == temp_v1->unk5C) && (arg1 == temp_v1->unk5E)) {
                return actor;
            }
            continue;
        }
        if ((actor->unk0.unkA_3 != 2) && (actor->unk0.currentTileX == arg0)
            && (actor->unk0.currentTileZ == arg1) && !actor->unk0.unkA_5
            && (actor->unk0.position.vy >= arg2)) {
            return actor;
        }
    }
    return NULL;
}

int func_800A3DB4(int x, int z, int minimumHeight)
{
    SVECTOR offset;
    int height;
    ((int*)&offset)[0] = 0;
    ((int*)&offset)[1] = 0;
    height = func_800A6EE8(&offset, x, z, 1);
    if (height < minimumHeight)
        return 0;
    if ((*D_800F49F0 >> 20) & 1)
        return 0;
    return func_800A3C34(x / 128, z / 128, height, 1) == NULL;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3E6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A41D0);

void func_800A4A88(D_800F4538_t*, int);
int func_800A46A4(D_800F4538_t*);
int func_800A4494(int contact, SVECTOR* point)
{
    int i;
    D_800F4538_t* actor;
    int dx, dz, hit;
    int radius, x, z, y;
    for (i = 0; i < 17; i++) {
        actor = D_800F4538[i];
        if (actor == 0 || actor->unk0.skip)
            continue;
        if (actor->unk0.unkC_0 == contact) {
            if (actor->unk0.unkA_3 != 2)
                continue;
            dx = point->vx - *(short*)&actor->unk17EC[0];
            dz = point->vz - *(short*)&actor->unk17EC[4];
            actor->unk0.position.vx += dx;
            actor->unk0.position.vz += dz;
            hit = func_800A46A4(actor);
            actor->unk0.position.vx -= dx;
            actor->unk0.position.vz -= dz;
            if (!hit)
                continue;
        transition:
            actor->unk0.unk34.vx = 0;
            actor->unk0.unk34.vy = 3;
            actor->unk0.unk34.vz = 0;
            actor->unk6EE = 0;
            actor->unk6EF = 0;
            actor->unk0.unkA_0 = 3;
            actor->unk0.unkA_3 = 0;
            actor->unk0.unk9_6 = 0;
            actor->unk0.unkC_0 = 0;
            func_800A4A88(actor, 2);
            return 1;
        } else {
            radius = actor->unk63C;
            x = point->vx;
            if (x + 64 < actor->unk0.position.vx - radius
                || x - 64 > actor->unk0.position.vx + radius)
                continue;
            z = point->vz;
            if (z + 64 < actor->unk0.position.vz - radius
                || z - 64 > actor->unk0.position.vz + radius)
                continue;
            y = actor->unk0.position.vy;
            if (point->vy < y - 288 || point->vy >= y)
                continue;
            if (actor->unk0.unkA_3 == 2)
                goto transition;
            return 1;
        }
    }
    return 0;
}

void func_800A70DC(D_800F4538_t*, int);
typedef struct {
    char prefix[0x2C];
    u_char contact, nextContact;
} collisionScratchView;

int func_800A46A4(D_800F4538_t* actor)
{
    collisionScratchView* scratch = (void*)0x1F8003BC;
    int saved = actor->unk0.unkC_0;
    int radius = actor->unk63C;
    int direction;
    collisionScratchView *hit, *previous;
    actor->unk0.unkC_0 = 0;
    actor->unk0.unkA_3 = 0;
    actor->unk0.unk9_6 = 0;
    func_800A70DC(actor, rsin(512) * radius / 4096);
    actor->unk0.unkC_0 = saved;
    actor->unk0.unkA_3 = 2;
    direction = (u_short)actor->unk1800 >> 9;
    hit = (void*)((char*)scratch + direction);
    hit->contact = 0;
    hit->nextContact = 0;
    --direction;
    direction &= 7;
    previous = (void*)((char*)scratch + direction);
    previous->contact = 0;
    for (direction = 0; direction < 8; ++direction) {
        if (((collisionScratchView*)((char*)scratch + direction))->contact)
            return 1;
    }
    return 0;
}

int func_800A47C4(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        D_800F45E0_t* temp_v1 = D_800F45E0[i];
        if ((D_800F45E0[i] != NULL) && !D_800F45E0[i]->unk8_0 && !temp_v1->unk9_0
            && temp_v1->unk1A) {
            return 1;
        }
    }
    return 0;
}

void func_800A4828(int arg0, MATRIX* arg1)
{
    D_800F4538_t* temp_s1 = D_800F4538[arg0];
    int visible = temp_s1->unk0.visible;
    temp_s1->unk0.visible = 0;
    temp_s1->unk5B2 = 1;
    func_800AECA0(arg1);
    func_800AEAE8(temp_s1);
    func_800B28A8(temp_s1, arg1, 0);
    temp_s1->unk0.visible = visible;
}

void func_800B64A8(int, int, int);
typedef struct {
    unsigned mode : 2;
    unsigned fast : 1;
    unsigned reserved : 29;
} vs_battleMovementModeFlags;
void func_800A48CC(int index, int direction, int distance)
{
    D_800F4538_t* actor = D_800F4538[index];
    vs_battleMovementModeFlags* flags = (void*)((char*)actor + 0x5B0);
    if (actor->unk5AC_0 != 0)
        return;
    if (actor->unk0.unkA_3 != 0)
        return;
    if (actor->unk0.unkA_0 != 0) {
        func_800B64A8(index, direction, distance);
        return;
    }
    if (distance == 0) {
        flags->fast = 0;
        flags->mode = 0;
        func_800A0204(index, 0x2F, 0, 4);
        actor->unk0.unk11 = 6;
        actor->unk0.unkA_0 = 2;
    } else {
        flags->fast = 0;
        flags->mode = 1;
        if (distance / 4096 >= actor->unk5B9) {
            flags->mode = 2;
            flags->fast = 1;
        }
        actor->unk0.unk11 = 0;
        actor->unk0.unkA_0 = 1;
    }
    actor->unk1848.unk0 = 7;
    actor->unk1848.unk4 = direction;
    actor->unk1848.unk8 = distance;
}

func_8008D2C0_t* func_800A4A24(int arg0)
{
    func_8008D2C0_t sp10[4];
    int temp_v0;
    int i;
    arg0 -= 2;

    temp_v0 = func_8008D2C0(sp10);

    for (i = 0; i < temp_v0; ++i) {
        if (sp10[i].unk6 == arg0) {
            // BUG: returns stack variable
            return &sp10[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4A88);

void func_800A4D8C(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        if ((D_800F45E0[i] != NULL) && (D_800F45E0[i]->unk0 != 0)) {
            func_800B0908(D_800F45E0[i], vs_gametime_tickspeed / 2);
        }
    }
    for (i = 0; i < 17; ++i) {
        if ((D_800F4538[i] != NULL) && (D_800F4538[i]->unk0.skip == 0)) {
            func_800A4E68(i);
        }
    }
    D_800F4B18 = 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4E68);

int func_800A51A0(int arg0, SVECTOR* arg1)
{
    func_8008D2C0_t sp10[4];
    func_8008D2C0_t* p;
    int n;
    int i;

    arg0 -= 2;
    n = func_8008D2C0(sp10);
    for (i = 0; i < n; i++) {
        if (sp10[i].unk6 == arg0) {
            p = &sp10[i];
            goto found;
        }
    }
    p = NULL;
found:
    if (p->unk0 + 0x40 < arg1->vx) {
        return 0;
    }
    if (arg1->vx < p->unk0 - 0x40) {
        return 0;
    }
    if (p->unk4 + 0x40 < arg1->vz) {
        return 0;
    }
    return !(arg1->vz < p->unk4 - 0x40);
}

void func_800A525C(D_800F4538_t* arg0)
{
    arg0->unk1848.unk0 = 1;
    if (arg0->unk0.unkF == 0) {
        arg0->unk1848.unk0 = 0;
    }
    arg0->unk1848.unk4 = 0;
    arg0->unk1848.unk8 = 0;
    arg0->unk1848.unk6 = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A5280);

void func_800A6660(D_800F4538_t* arg0, int arg1, func_800A6660_t* arg2)
{
    int delta;

    if (arg1 == arg0->unk0.facing) {
        return;
    }
    if (arg0->unk0.unk18 != 0) {
        if (arg2->unk6 == 0) {
            delta = arg1 - ((arg0->unk0.facing + arg0->unk0.unk3E) & 0xFFF);
            if (delta >= ONE / 2) {
                delta -= ONE;
            } else if (delta < -ONE / 2) {
                delta += ONE;
            }
            arg0->unk0.unk3E += delta;
        } else {
            delta = arg1 - arg0->unk0.facing;
            if (delta >= ONE / 2) {
                delta -= ONE;
            } else if (delta < -ONE / 2) {
                delta += ONE;
            }
            arg0->unk0.unk3E = delta;
            arg0->unk0.unk18 = 12;
        }
    } else {
        func_800AA850(arg0->unk0.unkF, arg1, 12);
    }
    if (arg0->unk63C > 0x80) {
        delta = arg0->unk0.unk3E / 32;
        if (delta < 0) {
            delta = -delta;
        }
        if (arg0->unk0.unk18 < delta) {
            arg0->unk0.unk18 = delta;
        }
    }
}

extern short D_800F4B0A;
typedef struct {
    int words[2];
} probePosition;
int func_800A76BC(D_800F4538_t*, int, int*, int);

int func_800A6798(D_800F4538_t* actor, SVECTOR* offset, int arg2)
{
    probePosition saved;
    int height;
    int valid = 0;
    if (actor->unk6EC <= D_800F4B0A) {
        return 0;
    }
    offset->vx = 0;
    offset->vz = 0;
    offset->vy += 0xEC;
    saved = *(probePosition*)&actor->unk0.position;
    actor->unk0.position.vx += offset->vx;
    actor->unk0.position.vy += offset->vy;
    actor->unk0.position.vz += offset->vz;
    actor->unk0.unkA_3 = 2;
    if (func_800A76BC(actor, arg2, &height, 0) != 3
        && !(*(int*)((char*)actor + 0x5AC) & 0x2000) && height < 5) {
        height = rsin(0x200);
        height = height * actor->unk63C / 4096;
        if ((D_800F49F9 >> 1) & 1) {
            offset->vz = height;
        } else {
            offset->vx = height;
        }
        height = func_800A6EE8(&D_800F4B08, offset->vx, offset->vz, 1);
        height -= D_800F4B08.vy;
        if (height >= -0x3F) {
            height = func_800A6EE8(&D_800F4B08, -offset->vx, -offset->vz, 1);
            height -= D_800F4B08.vy;
            if (height >= -0x3F) {
                valid = 1;
            }
        }
    }
    actor->unk0.unkA_3 = 0;
    actor->unk0.unk9_6 = 0;
    offset->vx = 0;
    offset->vz = 0;
    *(probePosition*)&actor->unk0.position = saved;
    return valid;
}

int func_800A69B4(D_800F4538_t* arg0)
{
    SVECTOR v;
    int ret = 0;
    int h = rsin(ONE / 8) * arg0->unk63C / ONE;

    v.vx = 0;
    v.vz = 0;
    if ((D_800F49F9 >> 1) & 1) {
        v.vz = h;
    } else {
        v.vx = h;
    }
    h = func_800A6EE8(&D_800F4B08, v.vx, v.vz, 1) - D_800F4B08.vy;
    if (h > -64) {
        h = func_800A6EE8(&D_800F4B08, -v.vx, -v.vz, 1) - D_800F4B08.vy;
        if (h > -64) {
            ret = 1;
        }
    }
    return ret;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A6AA0);

int func_800A6EE8(SVECTOR* arg0, int arg1, int arg2, int arg3)
{
    SVECTOR sp;
    u_int* ent;
    int h;
    int r;
    int los;

    int x = arg1 + arg0->vx;
    int z = arg2 + arg0->vz;

    sp.vx = x;
    sp.vz = z;

    ent = func_800A8D64(&sp, 0);

    if (ent != NULL) {

        D_800F49F0 = ent;

        if (arg3 == 0) {
            h = func_8008DC7C(x, z);
        } else {
            h = func_8008DA24(x, z);
        }

        if (h >= 0) {

            h <<= 17;
            h >>= 17;

            if (arg3 == 2) {
                r = func_800B13CC(x / 128, z / 128, arg0->vy);
            } else {
                r = func_800A92B8(x / 128, z / 128);
            }

            if (r != 0) {
                h = r;
            }

            if (((*ent >> 17) & 1) && (h >= 0)) {

                h = 3000;

                if (arg3 == 3) {

                    los = D_800E9278[*ent & 0x1F];

                    if (los == 0x14) {
                        h = 0;
                    }
                }
            }

            if (arg3 != 2 && arg3 != 4) {

                los = func_800A9378(x, arg0->vy, z, 0);

                r = h;

                if ((los != 0) && (los < h)) {
                    h = los;
                }

                if (arg3 == 3 && h < arg0->vy - 64) {
                    h = r;
                }
            }

            return h;
        }
    }

    if (arg3 == 3) {
        return arg0->vy;
    }

    return -3000;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A70DC);

typedef struct {
    char prefix[0x2C];
    u_char contacts[8];
} collisionResponseScratch;

void func_800A7524(D_800F4538_t* actor, SVECTOR* motion)
{
    collisionResponseScratch* scratch;
    int x, z;
    if (*(u_int*)((char*)actor + 0x5AC) & 0x1000) {
        scratch = (void*)0x1F8003BC;
        x = 0;
        z = (scratch->contacts[0] != 0) * 16;
        if (scratch->contacts[1]) {
            x = 8;
            z += 8;
        }
        if (scratch->contacts[2])
            x += 16;
        if (scratch->contacts[3]) {
            x += 8;
            z -= 8;
        }
        if (scratch->contacts[4])
            z -= 16;
        if (scratch->contacts[5]) {
            x -= 8;
            z -= 8;
        }
        if (scratch->contacts[6])
            x -= 16;
        if (scratch->contacts[7]) {
            x -= 8;
            z += 8;
        }
        if (x > 16)
            x = 16;
        if (x < -16)
            x = -16;
        if (z > 16)
            z = 16;
        if (z < -16)
            z = -16;
        if (x != 0) {
            if (x < 0) {
                if (motion->vx > 0)
                    motion->vx = 0;
            } else if (motion->vx < 0)
                motion->vx = 0;
        }
        if (z != 0) {
            if (z < 0) {
                if (motion->vz > 0)
                    motion->vz = 0;
            } else if (motion->vz < 0)
                motion->vz = 0;
        }
        motion->vx += x;
        motion->vz += z;
        actor->unk6EE = 0;
        actor->unk6EF = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A76BC);

int func_800A8B34(SVECTOR* arg0, int arg1)
{
    u_int* ent;
    int h;
    int elev2;
    int gx;
    int gz;
    int r;
    int los;
    int diff;
    int q;
    D_1F8003BC_t* sb = (D_1F8003BC_t*)0x1F8003BC;
    D_800F45E0_t* actor = sb->unk18;
    int limit = sb->unk1C[arg1 & 7];

    if (actor->unk5AC_9 << 9) {
        return 0;
    }

    gx = arg0->vx / 128;
    gz = arg0->vz / 128;
    elev2 = func_8008DD0C(arg0->vx, arg0->vz);
    elev2 <<= 17;
    elev2 >>= 17;

    if (limit + sb->unk0 < elev2) {
        return 0xFF;
    }

    ent = func_800A8D64(arg0, 0);

    if (ent == NULL) {
        return 0xFF;
    }

    h = func_8008DC7C(arg0->vx, arg0->vz);

    if (h < 0) {
        return 0xFF;
    }

    h <<= 17;
    h >>= 17;

    r = func_800A92B8(gx, gz);

    if (r != 0) {
        h = r;
    }

    if ((*ent >> 17) & 1) {
        if (h >= 0) {
            h = 0xBB8;
        }
    }

    if (h - actor->unk1E < -0x17F) {
        return 0xFF;
    }

    los = func_800A9378(arg0->vx, limit, arg0->vz, 0);

    if (los == 0) {
        arg0->pad = 0;
    } else {
        arg0->pad = D_800F49F4;
        h = los;
    }

    arg0->pad |= D_800F49F8 << 8;

    if (sb->unk0 < elev2 - h) {
        return 0xFF;
    }

    if (h < sb->unk40 + limit) {
        return 0xFF;
    }

    if (func_800A8E84(actor, arg0) == 0) {
        return 0xFF;
    }

    arg0->vy = h;
    diff = h - limit;
    q = diff / 64;

    if (q >= 0) {
        return 0;
    }

    if (diff & 0x3F) {
        --q;
    }

    return -q;
}
