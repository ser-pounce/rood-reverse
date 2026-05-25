#include "common.h"
#include "30D14.h"
#include "3A1A0.h"
#include "146C.h"
#include "../SLUS_010.40/main.h"
#include <libgte.h>
#include <libetc.h>
#include <memory.h>

typedef struct {
    u_char unk0;
    signed char unk1;
    short unk2;
    int unk4;
    int unk8;
    int unkC;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
} func_8009AC24_t;

typedef struct {
    u_char unk0[0x1FE0];
    u_short unk1FE0;
} D_800F2458_t;

int func_8009998C(vs_battle_objectData*);
int func_8009A0B8(vs_battle_objectData*);
int _loadWep(vs_battle_objectData*);
int func_8009AC84(vs_battle_objectData*);
int _loadShp(vs_battle_objectData*);
int func_8009BE5C(vs_battle_objectData*);
int _loadSeq(vs_battle_objectData*);
int func_8009D270(vs_battle_objectData*);
void func_8009E700(int, int);
void func_8009F9F4(int, u_char*);
void func_800A11D8(int, int, MATRIX*, u_long*);
int func_800A141C(int arg0, int arg1, int* arg2, int arg3);
int func_800A152C(int, int, int);
void func_800AB2AC(int);
int func_800AD714(D_800F4538_t*, D_800F4538_unkC54*, int);
void func_800AE6C0(D_800F4538_t*, int, int);

extern u_char D_800E8F2A;
extern char D_800E8F2C;
extern char D_800E8FC0;
extern int D_800E8FC4;
extern u_char D_800E9090[];
extern u_char D_800F244F[];
extern D_800F2458_t D_800F2458;
extern VECTOR D_800F4438;
extern char D_800F4448[];
extern int D_800F457C;
extern int D_800F4580;
extern int D_800F45D8;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_80099514);

int vs_battle_getEmptyObjectDataSlot(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        if (vs_battle_objectDataSlots[i].unk0 == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", vs_battle_populateDataSlot);

int vs_battle_processObjectDataQueue(void)
{
    int i;
    int ret;
    vs_battle_objectData* slot = vs_battle_objectDataSlots;

    D_800F4580 = VSync(1);

    switch (slot->unk0) {
    case 0:
        return 0;
    case 1:
        ret = func_8009AC84(slot);
        break;
    case 3:
        ret = func_8009A0B8(slot);
        break;
    case 7:
        ret = func_8009BE5C(slot);
        break;
    case 2:
        ret = _loadShp(slot);
        break;
    case 4:
        ret = _loadWep(slot);
        break;
    case 6:
        ret = func_8009998C(slot);
        break;
    case 8:
        ret = _loadSeq(slot);
        break;
    case 9:
        ret = func_8009D270(slot);
        break;
    default:
        return -1;
    }

    D_800F4580 = VSync(1) - D_800F4580;

    if (D_800E8F2A == 2) {
        if (D_800E8FC4 < D_800F4580) {
            D_800E8FC4 = D_800F4580;
            D_800F45D8 = slot->unk0;
            D_800F457C = D_800E8F2A;
        }
    }

    if (ret == -1) {
        return 1;
    }

    for (i = 1; i < 15; ++i) {
        vs_main_memcpy(&vs_battle_objectDataSlots[i - 1], &vs_battle_objectDataSlots[i],
            sizeof vs_battle_objectDataSlots[i]);
    }

    vs_battle_objectDataSlots[i - 1].unk0 = 0;

    return ret < 0 ? -1 : 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_80099854);

int func_80099900(func_8009AC24_t* arg0)
{
    int i;

    for (i = 0; i < 16; ++i) {
        if ((i != arg0->unk1)
            && ((D_800F45E0[i] != NULL)
                && (D_800F45E0[i]->unk6C[8].unk0_0 == arg0->unk10))) {
            arg0->unk8 = i;
            return 1;
        }
    }
    return 0;
}

void func_80099960(void* arg0) { vs_main_memcpy(&D_800F4448, arg0, 0xE0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009998C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_80099D6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_80099E7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_80099FA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009A028);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009A0B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", _loadWep);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009A98C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009AA84);

int func_8009AC24(func_8009AC24_t* arg0)
{
    int i;

    for (i = 0; i < 17; ++i) {
        if ((i != arg0->unk1)
            && ((D_800F4538[i] != NULL) && (D_800F4538[i]->unk6E6 == arg0->unk2))) {
            arg0->unk8 = i;
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009AC84);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", _loadShp);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009BD90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009BE5C);

void func_8009C378(func_8009C378_t* arg0, func_8009C378_t* arg1)
{
    vs_main_memcpy(arg0, arg1, 0x7800);
    arg0->unk0 -= (long)arg1;
    arg0->unk4 -= (long)arg1;
    arg0->unk0 += (long)arg0;
    arg0->unk4 += (long)arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", _loadSeq);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009CAEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009CC20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009CE9C);

int func_8009CFA0(void) { return D_800E8F2C + 1; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009CFB0);

int func_8009D208(int arg0)
{
    if (D_800F244F[arg0] != 0) {
        func_800AB2AC(arg0 - 1);
        if (func_8007E0A8(D_800F244F[arg0], 1, 4) == 0) {
            return -3;
        }
        D_800F244F[arg0] = 0;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009D270);

void func_8009D458(void) { }

void func_8009D460(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009D468);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009D6F4);

void func_8009D7E8(int arg0, int arg1)
{
    D_800F4538_t* temp_a2 = D_800F4538[arg0];
    if (temp_a2 != NULL) {
        if (arg1 == 0) {
            temp_a2->unk5AC_21 = 0;
        } else {
            temp_a2->unk1800[2] = 0;
            temp_a2->unk5AC_21 = 1;
            temp_a2->unk1800[3] = arg1 * 2;
            temp_a2->unk5AC_22 = 0;
        }
    }
}

void func_8009D854(int arg0)
{
    if (D_800F4538[arg0] != NULL) {
        D_800F4538[arg0]->unk5AC_18 = 1;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009D88C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009D934);

void func_8009DBDC(int arg0, int arg1)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        func_800AE6C0(temp_a0, D_800E9090[temp_a0->unk5B1] + arg1, 0);
    }
}

void func_8009DC38(int arg0)
{
    D_800F4538_t* temp_s0 = D_800F4538[arg0];
    if (temp_s0 != NULL) {
        func_8009DC8C(arg0);
        temp_s0->unk1A = 0;
        temp_s0->unk18 = 0;
        temp_s0->unk28[3] = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009DC8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009DD00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009DDF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009DF3C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009E070);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009E180);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009E228);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009E2E0);

int func_8009E480(void)
{
    if (D_800F4538[0]->unk5B8 == 0x63) {
        return 1;
    }
    return D_800F4538[0]->unk5B8 == 0xC7;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009E4B0);

void func_8009E5C4(int arg0)
{
    if ((D_800F4538[arg0]->unk5B8 != 0x63) && (D_800F4538[arg0]->unk5B8 != 0xC7)) {
        func_8009E700(arg0, 1);
    }
}

void func_8009E614(int arg0) { func_8009E700(arg0, 6); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009E634);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009E700);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009EA14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009EC9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009EE9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009EFEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009F298);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009F314);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009F530);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009F794);

int func_8009F858(int arg0)
{
    D_800F4588_t* temp_a0 = D_800F45E0[arg0];

    if (temp_a0 == NULL) {
        return -1;
    }

    if (temp_a0->unk6C[8].unk0_0 != 1) {
        return -1;
    }

    return temp_a0->unk6C[8].unk1;
}

void func_8009F898(int arg0, int arg1, int arg2)
{
    D_800F4588_t* temp_a0 = D_800F4588[arg0 * 2];

    if (temp_a0 != NULL) {
        temp_a0->unk5C0 = arg2;
        temp_a0->unk8_6 = arg1;
    }
}

int func_8009F8DC(int arg0)
{
    int temp_s2;
    int temp_v0;
    int temp_s1;
    D_800F4538_unkC54* s0 = &D_800F4538[arg0]->unkC54;

    temp_s1 = s0->unk542;
    temp_s2 = s0->unk544;
    temp_v0 = func_800AD714(D_800F4538[arg0], s0, 3);
    s0->unk542 = temp_s1;
    s0->unk544 = temp_s2;
    return temp_v0;
}

void func_8009F940(int arg0, int arg1, D_800F4538_unk58_2* arg2, D_800F4538_unk58_2* arg3)
{
    D_800F4538_t* temp_t0 = D_800F4538[arg0];

    if (temp_t0 != NULL) {
        temp_t0->unk17FD = arg1;
        if (arg1 != 0) {
            *(int*)&temp_t0->unk6F4 = *(int*)arg2;
            temp_t0->unk6F8 = *arg3;
        }
    }
}

void func_8009F990(int arg0, u_char* arg1)
{
    int i;

    if (arg0 == -1) {
        for (i = 0; i < 17; ++i) {
            func_8009F9F4(i, arg1);
        }
    } else {
        func_8009F9F4(arg0, arg1);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009F9F4);

void func_8009FB64(VECTOR* arg0)
{
    int i;

    D_800F4438 = *arg0;

    for (i = 0; i < 17; ++i) {
        if (D_800F4538[i] != NULL) {
            D_800F4538[i]->unk183C = D_800F2458.unk1FE0;
        }
    }
}

int func_8009FBD8(int arg0, int arg1)
{
    int _[2] __attribute__((unused));
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 == NULL) {
        return -1;
    }

    if (arg1 == -1) {
        temp_a0->unk6E5 = 0xD;
    } else {
        temp_a0->unk6E5 = arg1;
    }

    return 0;
}

int func_8009FC20(int arg0, int* arg1)
{
    int _[2] __attribute__((unused));
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 == NULL) {
        return -1;
    }

    *arg1 = temp_a0->unk6E5;

    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009FC60);

typedef struct {
    char unk0[0x63C];
    u_short unk63C;
    char unk63E[0x11BC];
    short unk17FA;
} func_8009FD38_t;

void func_8009FD38(func_8009FD38_t* arg0)
{
    arg0->unk17FA = 30;
    if (arg0->unk63C > 128) {
        arg0->unk17FA = 20;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009FD5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009FE74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009FF08);

int func_8009FFA8(int arg0, int arg1)
{
    int _[2] __attribute__((unused));

    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    int temp_v1 = temp_a0->unk12;

    if (temp_v1 == 0xFF) {
        return -2;
    }

    if ((temp_v1 > 16) || (D_800F4538[temp_v1]->unk0 == 0)) {
        return -1;
    }

    temp_a0->unk9_5 = 0;
    // BUG: no return value, in practice it isn't read by the only caller.
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A0024);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A0104);

int func_800A01C8(int arg0, int arg1, int arg2, int arg3)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 == NULL) {
        return -1;
    }

    temp_a0->unk6E0 = arg1;
    temp_a0->unk6E1 = arg2;
    temp_a0->unk6E2 = arg3;

    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A0204);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A0618);

void func_800A06B8(D_800F4538_t* arg0, int arg1)
{
    D_800F4538_unk1864* a2 = &arg0->unk1864;
    a2->unk5 = 0;
    if (arg1 == 0) {
        a2->unkC = arg0->unk64E;
        a2->unkE = arg0->unk650;
        a2->unk8 = 0;
    } else {
        a2->unk10 = arg0->unk64E - a2->unkC;
        a2->unk12 = arg0->unk650 - a2->unkE;
        a2->unkA = -a2->unk8;
    }
    a2->unk4 = arg1;
    a2->unk5 = arg1;
}

int func_800A071C(int arg0, D_800F4538_unk58_2* arg1)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 != NULL) {
        arg1->unk0 = temp_a0->unk6F2;
        arg1->unk1 = temp_a0->unk6F1;
        arg1->unk2 = temp_a0->unk6F0;
        return 0;
    }
    return -1;
}

int func_800A0768(int arg0, D_800F4538_unk58_2* arg1)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 != NULL) {
        temp_a0->unk6F2 = arg1->unk0;
        temp_a0->unk6F1 = arg1->unk1;
        temp_a0->unk6F0 = arg1->unk2;
        return 0;
    }
    return -1;
}

int func_800A07B4(int arg0, D_800F4538_unk58_2* arg1)
{
    if (D_800F4538[arg0] == NULL) {
        return -1;
    }

    *arg1 = D_800F4538[arg0]->unk58;
    return 0;
}

int func_800A07FC(int arg0, D_800F4538_unk58_2* arg1)
{
    D_800F4538_t* temp_a2 = D_800F4538[arg0];

    if (temp_a2 == NULL) {
        return -1;
    }

    if (arg1 == NULL) {
        temp_a2->unk5AC_8 = 0;
    } else {
        temp_a2->unk5AC_8 = 1;
        temp_a2->unk58 = *arg1;
    }

    return 0;
}

void func_800A0870(int arg0) { D_800E8FC0 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A087C);

void func_800A09D8(int arg0, int arg1)
{
    if (D_800F4538[arg0] != NULL) {
        D_800F4538[arg0]->unk5AC_24 = arg1;
    }
}

void func_800A0A1C(int arg0, int arg1)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (D_800F4538[arg0] != NULL) {
        temp_a0->unk5AC_9 = arg1;
        temp_a0->unk5AC_11 = arg1 >> 1;
    }
}

int func_800A0A74(int arg0)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        int var_v1 = temp_a0->unk5AC_9;
        if ((temp_a0->unk5AC_11 << 11)) {
            var_v1 |= 2;
        }
        return var_v1;
    }
}

void func_800A0ABC(int arg0)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        temp_a0->unk1840 = 0;
        temp_a0->unk1846 = 0;
        temp_a0->unk5AC_15 = 0;
    }
}

void func_800A0AFC(int arg0, int arg1, int arg2)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        temp_a0->unk5BA = arg1 / ONE;
        temp_a0->unk5B9 = arg2 / ONE;
        if (arg1 >= arg2) {
            temp_a0->unk5B9 = 0xFF;
        }
    }
}

void func_800A0B5C(int arg0, int arg1, int arg2)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 == NULL) {
        return;
    }

    if (arg1 < 0) {
        arg1 = 1;
    }
    temp_a0->unk5C2 = arg1;

    if (arg2 < 0) {
        arg2 = 1;
    }
    temp_a0->unk5C0 = arg2;
}

void func_800A0BA0(int arg0, int* arg1, int* arg2)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != 0) {
        *arg1 = temp_a0->unk5C2;
        *arg2 = temp_a0->unk5C0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A0BE0);

int func_800A1108(int arg0, void* arg1)
{
    D_800F4538_t* var_v1 = D_800F4538[arg0];

    if (var_v1 == NULL) {
        var_v1 = (D_800F4538_t*)D_800F45E0[arg0];
        if (var_v1 == NULL) {
            return -1;
        }
    }

    ((int*)arg1)[0] = *(int*)&var_v1->unk5C;
    ((int*)arg1)[1] = *(int*)&var_v1->unk1C;
    ((int*)arg1)[2] = *(int*)&var_v1->unk20;
    ((u_short*)arg1)[5] = var_v1->unk26;
    return 0;
}

int func_800A1178(int arg0, int arg1, MATRIX* arg2, u_long* arg3)
{
    int temp_v0 = func_800A152C(arg0, arg1, 0);
    if (temp_v0 < 0) {
        return temp_v0;
    }
    func_800A11D8(arg0, temp_v0, arg2, arg3);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A11D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A1280);

int func_800A13EC(int arg0, int arg1, int* arg2, int arg3)
{
    int var_v0 = func_800A141C(arg0, arg1, arg2, arg3);
    if (var_v0 < 0) {
        return var_v0;
    }
    return 0;
}
