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

u_int func_800A29A0(void*);
u_int func_800A9C54(u_char, void*, int);
void func_800AEAE8(void*);
void func_800AECA0(MATRIX*);
void func_800B28A8(void*, MATRIX*, int);
int func_8008D2C0(func_8008D2C0_t*);
short func_8008DD0C(int arg0, int arg1);
D_800F4538_t* func_800A3C34(u_char, u_char, short, u_int);
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A29A0);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A2CD4);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A30A0);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A38E0);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3C34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3DB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3E6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A41D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4494);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A46A4);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A48CC);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A6798);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A7524);

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
