#include "common.h"
#include "30D14.h"
#include "3A1A0.h"

typedef struct {
    int unk0;
    int pad04[5];
    D_800F4538_t* unk18;
    short unk1C[18];
    int unk40;
} D_1F8003BC_t;

u_int func_800A29A0(void*);
u_int func_800A9C54(u_char, void*, int);
void func_800AEAE8(void*);
void func_800AECA0(MATRIX*);
void func_800B28A8(void*, MATRIX*, int);
short func_8008DD0C(int arg0, int arg1);
D_800F4538_t* func_800A3C34(u_char, u_char, short, u_int);
short func_8008DC7C(int, int);
short func_8008DA24(int, int);
u_int* func_800A8D64(SVECTOR*, int);
int func_800B13CC(int, int, int);
int func_800A92B8(int, int);
int func_800A9378(int, int, int, int);
int func_800A8E84(D_800F4538_t*, SVECTOR*);

extern u_int* D_800F49F0;
extern u_short D_800F49F4;
extern u_char D_800F49F8;
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A2FBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3054);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A30A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3310);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3394);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3500);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A35A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A36E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A3760);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A47C4);

void func_800A4828(int arg0, MATRIX* arg1)
{
    D_800F4538_t* temp_s1 = D_800F4538[arg0];
    int temp_s0 = temp_s1->unk0.unk8_1;
    temp_s1->unk0.unk8_1 = 0;
    temp_s1->unk5B2 = 1;
    func_800AECA0(arg1);
    func_800AEAE8(temp_s1);
    func_800B28A8(temp_s1, arg1, 0);
    temp_s1->unk0.unk8_1 = temp_s0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A48CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4A24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4A88);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4D8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A4E68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A51A0);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A6660);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A6798);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A69B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A6AA0);

int func_800A6EE8(SVECTOR* arg0, int arg1, int arg2, int arg3)
{
    SVECTOR sp;
    u_int* ent;
    int x;
    int z;
    int h;
    int r;
    int los;

    x = arg1 + arg0->vx;
    z = arg2 + arg0->vz;
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
            if ((*ent >> 17) & 1) {
                if (h >= 0) {
                    h = 0xBB8;
                    if (arg3 == 3) {
                        los = D_800E9278[*ent & 0x1F];
                        if (los == 0x14) {
                            h = 0;
                        }
                    }
                }
            }
            if (arg3 != 2 && arg3 != 4) {
                los = func_800A9378(x, arg0->vy, z, 0);
                r = h;
                if (los != 0) {
                    if (los < h) {
                        h = los;
                    }
                }
                if (arg3 == 3 && h < arg0->vy - 0x40) {
                    h = r;
                }
            }
            return h;
        }
    }
    if (arg3 == 3) {
        return arg0->vy;
    }
    return -0xBB8;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A70DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A7524);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/3A1A0", func_800A76BC);

int func_800A8B34(SVECTOR* arg0, int arg1)
{
    D_1F8003BC_t* sb = (D_1F8003BC_t*)0x1F8003BC;
    D_800F4538_t* actor = sb->unk18;
    int limit = sb->unk1C[arg1 & 7];
    u_int* ent;
    int h;
    int elev2;
    int gx;
    int gz;
    int r;
    int los;
    int diff;
    int q;

    if (*(int*)((u_char*)actor + 0x5AC) & 0x600) {
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

    if (h - actor->unk0.unk1C.vy < -0x17F) {
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
        q--;
    }
    return -q;
}
