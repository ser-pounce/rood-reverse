#include "common.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/2EA3C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/40564.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include <libetc.h>
#include <stdio.h>
#include <strings.h>
#include <libgpu.h>
#include <abs.h>
#include "insertTPage.h"
#include "vs_string.h"

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
} D_8010989C_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
    char* unk8;
    char* unkC;
} D_8010A230_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
    char unkC;
    char unkD;
    char unkE;
    char unkF;
    short unk10;
    short unk12;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
} D_8010A470_t;

int func_80101268(int, int, vs_battle_menuItem_t*, u_long*);
void func_80102A7C(vs_battle_menuItem_t*);
void func_80102E10(int, int, char**, int);
int func_801031BC(void);
int func_8010337C(void);
void func_80104AF8(void);
void func_80104B40(void);
int func_80104BD0(int arg0);
void func_80104CBC(MATRIX*);
void func_80104E90(MATRIX* arg0, short arg1);
void func_80104F04(MATRIX* arg0, short arg1);
void func_80104F74(int, int, int, int, int);
void func_801051AC(int, int, int, int, int);
void func_8010552C(int arg0);
void func_801056B8(void);
void func_8010579C(int arg0);
void func_80105A0C(int arg0, int arg1, int arg2, int arg3);
void func_80105D8C(void);
void func_80105F00(int arg0);
void func_801061F8(int arg0, int arg1);
void func_80106528(void);
void func_80106780(void);
void func_80106808(int);
void _toVsStringInt(char* buf, int value);
void func_80106DE0(char* buf, int rank, int totalSeconds);
void func_80106F9C(void);
void _toVsStringPercent(char* buf, int value);
void func_80107090(void);
void func_80107120(int);
void func_80107600(void);
void _calculateScore(void);
void func_80107A98(int arg0);
void func_80107C34(void);
int func_80107FBC(short);
void func_80108098(void);
void func_801080C8(void);
void func_8010812C(int);
int func_8010823C(void);

extern void* D_1F800000[];

extern u_short _menuStrings[];
extern u_short _rankStrings[];
extern u_short _titleStrings[];
extern u_short _titleDescriptions[];
extern u_short _statHeaders[];
extern u_short _statDescriptions[];
extern u_short _timeAttacks[];
extern u_short _timeAttackDescriptions[];
extern u_short _miscInfo[];

extern char D_8010851C;
extern char D_8010851D;
extern D_8010989C_t D_8010989C;
extern char D_80109898;
extern char D_80109899;
extern short D_801098A4[];
extern u_int D_801098C4[];
extern int D_8010A214;
extern int D_8010A218;
extern int D_8010A21C;
extern int D_8010A220;
extern int D_8010A224;
extern int D_8010A228;
extern D_8010A230_t D_8010A230[];
extern short D_8010A430[];
extern int D_8010A43C;
extern int D_8010A438;
extern int D_8010A440;
extern int D_8010A444;
extern int D_8010A448;
extern u_short D_8010A44C;
extern short D_8010A44E;
extern short D_8010A450;
extern short D_8010A452;
extern int D_8010A454;
extern int D_8010A458;
extern int D_8010A45C;
extern u_long _score;
extern u_short D_8010A464;
extern u_short _clearCount;
extern u_short D_8010A468;
extern u_short D_8010A46A;
extern vs_main_CdQueueSlot* D_8010A46C;
extern D_8010A470_t* D_8010A470;
extern u_short* D_8010A474;
extern char D_8010A480[16];
extern char D_8010A490[16];

void func_80102A38(int arg0)
{
    if (arg0 != 0) {
        func_800FFA88(2);
        D_801022D6 = 0;
    } else {
        func_800FFA88(0);
        D_801022D6 = 1;
    }
}

void func_80102A7C(vs_battle_menuItem_t* arg0)
{
    int sp10;
    int sp14;
    int sp18;
    int sp1C;
    int temp_fp;
    char temp_v1_2;
    int var_a0;
    int var_s0;
    int i;
    u_long* var_s2;
    u_char* temp_s1;
    u_int temp_a0;
    u_int var_s4;
    u_long* temp_s7;
    int temp_v1;
    int s5;

    temp_s1 = arg0->text;

    sp14 = 0;
    if (vs_main_frameBuf == 0) {
        sp14 = 0x140;
    }

    var_s4 = *(int*)&arg0->animSpeed;
    temp_s7 = D_1F800000[2] + 8;

    sp10 = arg0->unk1;
    sp18 = arg0->unk4;
    temp_fp = arg0->unk5 - 1;
    sp1C = arg0->unk2;

    if (vs_main_frameBuf != D_8010851C) {
        ++D_8010851D;
        D_8010851C = vs_main_frameBuf;
        if (D_8010851D >= 0xC) {
            D_8010851D = 0;
        }
    }

    temp_v1 = arg0->state;

    if ((temp_v1 == 1) && (arg0->animSpeed < 0x80U)) {
        var_s0 = D_8010851D >> 2;
        if (temp_fp == 0) {
            var_s0 = var_s0 - 5;
        } else {
            var_s0 = temp_v1 - var_s0;
        }
        func_800C0224(0x80, (arg0->animSpeed - 0xE) | ((arg0->y + var_s0) << 0x10),
            0x100010, temp_s7 - 1)
            ->unk10 = (temp_fp * 0x10) | 0x37F93000;
    }

    i = arg0->animSpeed + 6;
    while ((var_s0 = *temp_s1++) != 0xFF) {
        if (var_s0 == 0xFA) {
            i += *temp_s1++;
        } else {
            i = func_80101268(var_s0 | (temp_fp << 0x1F), i, arg0, temp_s7);
        }
    }
    if (sp10 == 0) {
        return;
    }

    var_s2 = D_1F800000[0];
    for (i = 0, s5 = 0; i < 12; s5 += 8, ++i) {
        if (temp_fp == 0) {
            var_s0 = s5 + 0x20;
        } else {
            var_s0 = s5;
            var_s0 = 0x78 - s5;
        }
        var_s2[0] = (*temp_s7 & 0xFFFFFF) | 0x06000000;
        var_s2[1] = 0xE1000220;
        var_s2[2] = func_800C8FAC(8 - sp18, sp1C, var_s0) | 0x52000000;
        var_s2[3] = var_s4;
        var_s2[4] = func_800C8FAC(sp18, sp1C, var_s0);
        var_s2[5] = ((var_s4 + sp10 - 1) & 0xFFFF) | ((var_s4 >> 0x10) << 0x10);
        var_s2[6] = 0xE1000020;
        *temp_s7 = ((u_long)var_s2 << 8) >> 8;
        var_s2 += 7;
        var_s4 += 0x10000;
    }

    D_1F800000[0] = var_s2;
    if (temp_fp == 0) {
        func_800CCCB8(temp_s7, 0x60000000,
            ((var_s4 + 2) & 0xFFFF) | ((var_s4 >> 0x10) << 0x10), sp10 | 0x20000);
    }

    if (sp18 != 0) {
        arg0->unk4 = sp18 - 1;
    }

    var_s4 = var_s4 + 0xFFF40000;
    sp10 |= 0x10000;
    var_s0 = ((arg0->animSpeed < 0x80) ^ 1) << 7;

    for (i = 0; i < 12; ++i) {
        if (temp_fp == 0) {
            var_a0 = 0x78 - i * 8;
        } else {
            var_a0 = i * 8 + 0x20;
        }
        var_s2 = vs_battle_setSprite(var_a0, var_s4, sp10, temp_s7);
        temp_v1_2 = var_s4 - var_s0;
        temp_a0 = var_s4 >> 0x10;
        var_s4 += 0x10000;
        var_s2[1] = ((u_int)(sp14 + var_s0) >> 6) | 0xE1000120;
        var_s2[4] = temp_v1_2 | (temp_a0 << 8);
    }
}

void func_80102E10(int arg0, int arg1, char** arg2, int arg3)
{
    int sp10[arg0];
    int i;
    char temp_s1;

    for (i = 0; i < arg0; ++i) {
        sp10[i] = 0;
    }

    if ((arg0 < 9) || (arg1 < 8)) {
        D_800F4EE8.unk0[2] = arg1;
        D_800F4EE8.unk0[3] = 0;
    } else if (arg1 >= (arg0 - 8)) {
        D_800F4EE8.unk0[2] = arg1 - (arg0 - 9);
        D_800F4EE8.unk0[3] = arg0 - 9;
    } else {
        D_800F4EE8.unk0[2] = 4;
        D_800F4EE8.unk0[3] = arg1 - 4;
    }
    temp_s1 = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;
    vs_mainmenu_setMenuRows(arg0, 0x101, arg2, sp10);
    vs_main_settings.cursorMemory = temp_s1;
}

int func_80102F0C(void)
{
    int row;

    row = vs_mainmenu_getSelectedRow();
    if (row < -1) {
        func_800FA8E0(5);
    } else if (row >= 0) {
        func_800FA92C(D_800F4EEA, 1);
    }
    return row;
}

void func_80102F64(char* arg0)
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_setMenuItem(0xA, 0x140, 0x22, 0x8C, 9, arg0);
    temp_v0->state = 2;
    temp_v0->x = 0xB4;
    temp_v0->selected = 1;
    temp_v0->unkA = 1;
}

void func_80102FB8(void) { func_800FA8E0(8); }

void _menuReady(void) { vs_mainmenu_ready(); }

int func_80102FF8(char* state)
{
    switch (*state) {
    case 3:
        func_800FFB68(1);
        D_8010A214 = 8;
        D_8010A218 = 0;
        *state = 4;
        break;
    case 4:
        if (D_8010A218 == 0) {
            D_8010A218 = func_801031BC();
        }
        if (D_8010A214 != 0) {
            D_8010A214 -= 1;
        } else if (D_8010A218 != 0) {
            func_8008A4DC(0);
            func_800CB654(1);
            D_800EB9B0 = 0x200000;
            *state = 5;
        case 5:
            *state += vs_mainmenu_ready();
        }
        break;
    case 6:
        D_8010A21C = func_8010337C();
        if (D_8010A21C != 0) {
            func_80100414(-4, 0x80);
            func_800CB654(0);
            D_800EB9B0 = 0;
            func_8008A4DC(1);
            func_800FFA88(0);
            func_800FA8E0(0x28);
            *state = 7;
        }
        break;
    case 7:
        func_800FFB68(0);
        *state = 8;
        break;
    case 8:
        if (D_801022D8 == 0) {
            if (D_8010A21C == 2) {
                vs_battle_menuState.currentState = 9;
            }
            D_801022D6 = 0;
            *state = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int func_801031BC(void)
{
    int i;
    int j;
    int new_var;

    if (D_8005FFD8.unk0[1] & 0x800000) {
        D_8005FFD8.unk0[1] |= 0x400000;
    }

    D_8010A43C = 0;
    D_8010A45C = 0;

    if (vs_main_settings.cursorMemory == 0) {
        vs_main_bzero(D_800F1BF0, 8);
    }

    D_8010A46A = 0;

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 32; ++j) {
            if (D_8005FFD8.unk0[i] & D_800E8508[i] & ((new_var = 1) << j)) {
                ++D_8010A46A;
            }
        }
    }

    D_8010A468 = 0;

    for (i = 0; i < 64; ++i) {
        if (vs_main_stateFlags.unk33F[i + 0x81] != 0) {
            ++D_8010A468;
        }
    }

    _clearCount = vs_main_stateFlags.clearCount;

    if (D_8010A46A > vs_main_scoredata.unk94) {
        vs_main_scoredata.unk94 = D_8010A46A;
    }
    if (D_8010A468 > vs_main_scoredata.unk98) {
        vs_main_scoredata.unk98 = D_8010A468;
    }

    vs_main_memcpy(D_8010A480, (void*)0x1F800034, 0x10);
    vs_main_memcpy(D_8010A490, (void*)0x1F800054, 0x10);
    _calculateScore();
    func_80107C34();
    func_80107600();

    return 1;
}

static const vs_main_CdFile D_80102818 = { 0x14FF0, 0x3800 }; // data/SMALL/MON.BIN

static const P_CODE D_80102820[] = { { 0x00, 0x41, 0x6B, 0x00 },
    { 0x19, 0x82, 0x6C, 0x00 }, { 0x40, 0x30, 0x66, 0x00 }, { 0x40, 0x38, 0x20, 0x00 } };

static const P_CODE D_80102830[] = { { 0x00, 0x05, 0x33, 0x00 },
    { 0x01, 0x28, 0x26, 0x00 }, { 0x08, 0x08, 0x20, 0x00 }, { 0x10, 0x10, 0x08, 0x00 },
    { 0x24, 0x30, 0x31, 0x3A }, { 0x32, 0x35, 0x3A, 0x30 }, { 0x30, 0x00, 0x00, 0x00 },
    { 0x24, 0x30, 0x31, 0x3A }, { 0x31, 0x35, 0x3A, 0x30 }, { 0x30, 0x00, 0x00, 0x00 },
    { 0x24, 0x30, 0x31, 0x3A }, { 0x30, 0x30, 0x3A, 0x30 }, { 0x30, 0x00, 0x00, 0x00 },
    { 0x24, 0x30, 0x30, 0x3A }, { 0x35, 0x30, 0x3A, 0x30 }, { 0x30, 0x00, 0x00, 0x00 },
    { 0x24, 0x30, 0x30, 0x3A }, { 0x34, 0x30, 0x3A, 0x30 }, { 0x30, 0x00, 0x00, 0x00 },
    { 0x24, 0x30, 0x30, 0x3A }, { 0x33, 0x30, 0x3A, 0x30 }, { 0x30, 0x00, 0x00, 0x00 },
    { 0x24, 0x30, 0x30, 0x3A }, { 0x32, 0x35, 0x3A, 0x30 }, { 0x30, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 } };

int func_8010337C(void)
{
    int _[8] __attribute__((unused));
    D_800F4FE0_t* temp_v0;
    D_8010A230_t* var_s0;
    int lStickX;
    int lStickY;
    int a0;

    switch (D_8010A43C) {
    case 0:
        func_80100414(0x7FF, 0x80);
        ++D_8010A43C;
        break;
    case 1:
        func_800F9A24(0);
        func_801080C8();
        D_8010A444 = 0x150;
        D_8010A44E = 0x6B;
        D_8010A44C = D_800F453C->unk656;
        D_8010A430[0] = 0xF40;
        D_8010A430[1] = 0xE47;
        D_8010A430[2] = 0;
        func_800CCF08(0, 0, 0xB, 0xF8, 0x10, 1, 0xB, 0xF8);
        func_800C6BF0(0, &_rankStrings[_rankStrings[D_8010A464]]);
        func_80104BD0(1);
        D_8010A220 = 0;
        ++D_8010A43C;
        break;
    case 2:
        func_8010552C(D_8010A220);
        if (D_8010A220 < 8) {
            temp_v0 = func_800CCDF4(0);
            temp_v0->unk4[9] -= 6;
            temp_v0->unk4[7] -= 6;
            ++D_8010A220;
        }
        a0 = func_80104BD0(0);
        if (a0 == -1) {
            return 0;
        }
        if (a0 == -3) {
            D_8010A440 = 2;
        } else if (a0 == -2) {
            D_8010A440 = 1;
        } else if (a0 == 3) {
            D_8010A470 = vs_main_allocHeapR(D_80102818.size);
            D_8010A46C = vs_main_allocateCdQueueSlot(&D_80102818);
            vs_main_cdEnqueue(D_8010A46C, D_8010A470);
            D_8010A440 = 0;
        } else {
            D_8010A440 = 0;
        }
        D_800F1BF7 = D_800F4EE8.unk0[2] + D_800F4EE8.unk0[3];
        func_800CD064(0);
        ++D_8010A43C;
        break;
    case 3:
        func_8010552C(D_8010A220);
        if (D_8010A220 > 0) {
            temp_v0 = func_800CCDF4(0);
            if (temp_v0 != NULL) {
                temp_v0->unk4[9] += 6;
                temp_v0->unk4[7] += 6;
            }
            --D_8010A220;
            break;
        }
        func_800F9E0C();
        if (D_8010A440 == 0) {
            D_8010A43C = (D_800F1BF7 * 3) + 4;
            break;
        }
        func_80104AF8();
        return D_8010A440;
    case 4:
        func_800FFBC8();
        func_801056B8();
        D_8010A220 = 0;
        ++D_8010A43C;
        break;
    case 5:
        if ((D_800F1BF0[1] == 0) && (D_800F1BF0[0] == 0)
            && (vs_main_buttonsPressed.all & PADLup)) {
            vs_main_playSfxDefault(0x7E, 4);
            D_800F1BF0[0] = 0x18;
            D_800F1BF0[1] = 7;
        } else if ((D_800F1BF0[1] == 7) && (D_800F1BF0[0] == 0x18)
                   && (vs_main_buttonsPressed.all & PADLdown)) {
            vs_main_playSfxDefault(0x7E, 4);
            D_800F1BF0[0] = 0;
            D_800F1BF0[1] = 0;
        } else {
            if (vs_main_buttonRepeat & PADLup) {
                if (D_800F1BF0[1] >= 2) {
                    vs_main_playSfxDefault(0x7E, 4);
                    --D_800F1BF0[1];
                } else {
                    if (D_800F1BF0[0] != 0) {
                        --D_800F1BF0[0];
                        vs_main_playSfxDefault(0x7E, 4);
                    } else if (D_800F1BF0[1] != 0) {
                        --D_800F1BF0[1];
                        vs_main_playSfxDefault(0x7E, 4);
                    }
                }
            } else if (vs_main_buttonRepeat & PADLdown) {
                if (D_800F1BF0[1] >= 6U) {
                    if (D_800F1BF0[0] < 0x18U) {
                        ++D_800F1BF0[0];
                        vs_main_playSfxDefault(0x7E, 4);
                    } else {
                        if (D_800F1BF0[1] < 7) {
                            ++D_800F1BF0[1];
                            vs_main_playSfxDefault(0x7E, 4);
                        }
                    }
                } else {
                    ++D_800F1BF0[1];
                    vs_main_playSfxDefault(0x7E, 4);
                }
            }
        }
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            vs_main_playSfxDefault(0x7E, 6);
            func_800FFBA8();
            ++D_8010A43C;
            if (vs_main_buttonsPressed.all & PADRup) {
                D_8010A440 = 1;
            } else {
                D_8010A440 = 0;
            }
        }
        func_8010579C(D_8010A220);
        if (D_8010A220 < 8) {
            ++D_8010A220;
        }
        break;
    case 6:
        func_8010579C(D_8010A220);
        if (D_8010A220 <= 0) {
            if (D_8010A440 == 0) {
                D_8010A43C = 1;
                break;
            }
            func_80104AF8();
            return 2;
        }
        --D_8010A220;
        break;
    case 7:
        func_800FFBC8();
        func_80106780();
        D_8010A220 = 0;
        ++D_8010A43C;
        break;
    case 8:
        if ((D_800F1BF0[5] == 0) && (D_800F1BF0[4] == 0)
            && (vs_main_buttonsPressed.all & PADLup)) {
            vs_main_playSfxDefault(0x7E, 4);
            D_800F1BF0[4] = 0xF;
            D_800F1BF0[5] = 7;
        } else if ((D_800F1BF0[5] == 7) && (D_800F1BF0[4] == 0xF)
                   && (vs_main_buttonsPressed.all & PADLdown)) {
            vs_main_playSfxDefault(0x7E, 4);
            D_800F1BF0[4] = 0;
            D_800F1BF0[5] = 0;
        } else {
            if (vs_main_buttonRepeat & PADLup) {
                if (D_800F1BF0[5] >= 2) {
                    vs_main_playSfxDefault(0x7E, 4);
                    --D_800F1BF0[5];
                } else {
                    if (D_800F1BF0[4] != 0) {
                        --D_800F1BF0[4];
                        vs_main_playSfxDefault(0x7E, 4);
                    } else if (D_800F1BF0[5] != 0) {
                        --D_800F1BF0[5];
                        vs_main_playSfxDefault(0x7E, 4);
                    }
                }
            } else if (vs_main_buttonRepeat & PADLdown) {
                if (D_800F1BF0[5] >= 6) {
                    if (D_800F1BF0[4] < 0xF) {
                        ++D_800F1BF0[4];
                        vs_main_playSfxDefault(0x7E, 4);
                    } else {
                        if (D_800F1BF0[5] < 7) {
                            ++D_800F1BF0[5];
                            vs_main_playSfxDefault(0x7E, 4);
                        }
                    }
                } else {
                    ++D_800F1BF0[5];
                    vs_main_playSfxDefault(0x7E, 4);
                }
            }
        }
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            vs_main_playSfxDefault(0x7E, 6);
            func_800FFBA8();
            ++D_8010A43C;
            if (vs_main_buttonsPressed.all & PADRup) {
                D_8010A440 = 1;
            } else {
                D_8010A440 = 0;
            }
        }
        func_80106808(D_8010A220);
        if (D_8010A220 < 8) {
            ++D_8010A220;
        }
        break;
    case 9:
        func_80106808(D_8010A220);
        if (D_8010A220 <= 0) {
            if (D_8010A440 == 0) {
                D_8010A43C = 1;
                break;
            }
            func_80104AF8();
            return 2;
        }
        --D_8010A220;
        break;
    case 10:
        func_800FFBC8();
        func_80106F9C();
        ++D_8010A43C;
        break;
    case 11:
        if (vs_main_buttonRepeat & PADLup) {
            vs_main_playSfxDefault(0x7E, 4);
            D_800F1BF0[6] = (D_800F1BF0[6] - 1) & 7;
        } else {
            if (vs_main_buttonRepeat & PADLdown) {
                vs_main_playSfxDefault(0x7E, 4);
                D_800F1BF0[6] = (D_800F1BF0[6] + 1) & 7;
            }
        }
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            vs_main_playSfxDefault(0x7E, 6);
            func_800FFBA8();
            func_80107090();
            ++D_8010A43C;
            if (vs_main_buttonsPressed.all & PADRup) {
                D_8010A440 = 1;
            } else {
                D_8010A440 = 0;
            }
        }
        func_80107120(D_8010A220);
        if (D_8010A220 < 8) {
            ++D_8010A220;
        }
        break;
    case 12:
        func_80107120(D_8010A220);
        if (D_8010A220 > 0) {
            --D_8010A220;
            break;
        }
        for (D_8010A220 = 0, var_s0 = D_8010A230; D_8010A220 < 8;
             ++D_8010A220, ++var_s0) {
            if (var_s0->unk2 == 0) {
                func_800FFB90(D_8010A220);
            }
        }

        D_8010A220 = 0;
        if (D_8010A440 == 0) {
            D_8010A43C = 1;
            break;
        }
        func_80104AF8();
        return 2;
    case 13:
        if (D_8010A46C->state == 4) {
            vs_main_freeCdQueueSlot(D_8010A46C);
            D_8010A474 = (u_short*)(D_8010A470 + 150);
            func_800FFBC8();
            func_80105D8C();
            D_8010A220 = 0;
            ++D_8010A43C;
        }
        break;
    case 14:
        if ((D_800F1BF0[3] == 0) && (D_800F1BF0[2] == 0)
            && (vs_main_buttonsPressed.all & PADLup)) {
            vs_main_playSfxDefault(0x7E, 4);
            D_800F1BF0[2] = 0x46;
            D_800F1BF0[3] = 7;
        } else if ((D_800F1BF0[3] == 7) && (D_800F1BF0[2] == 0x46)
                   && (vs_main_buttonsPressed.all & PADLdown)) {
            vs_main_playSfxDefault(0x7E, 4);
            D_800F1BF0[2] = 0;
            D_800F1BF0[3] = 0;
        } else if (vs_main_buttonRepeat & PADLup) {
            if (D_800F1BF0[3] > 1) {
                vs_main_playSfxDefault(0x7E, 4);
                --D_800F1BF0[3];
            } else if (D_800F1BF0[2] != 0) {
                --D_800F1BF0[2];
                vs_main_playSfxDefault(0x7E, 4);
            } else if (D_800F1BF0[3] != 0) {
                --D_800F1BF0[3];
                vs_main_playSfxDefault(0x7E, 4);
            }
        } else if (vs_main_buttonRepeat & PADLdown) {
            if (D_800F1BF0[3] >= 6) {
                if (D_800F1BF0[2] < 0x46) {
                    ++D_800F1BF0[2];
                    vs_main_playSfxDefault(0x7E, 4);
                } else {
                    if (D_800F1BF0[3] < 7) {
                        ++D_800F1BF0[3];
                        vs_main_playSfxDefault(0x7E, 4);
                    }
                }
            } else {
                ++D_800F1BF0[3];
                vs_main_playSfxDefault(0x7E, 4);
            }
        }
        if (vs_main_buttonsPressed.all & PADRright) {
            if (D_8010A470[D_800F1BF0[2] + D_800F1BF0[3]].unkC != 0) {
                vs_main_playSfxDefault(0x7E, 5);
                func_80107FBC(D_8010A470[D_800F1BF0[2] + D_800F1BF0[3]].unk0);
                ++D_8010A43C;
                D_8010A440 = 2;
            } else {
                vs_main_playSfxDefault(0x7E, 7);
            }
        } else if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            vs_main_playSfxDefault(0x7E, 6);
            func_800FFBA8();
            ++D_8010A43C;
            if (vs_main_buttonsPressed.all & PADRup) {
                D_8010A440 = 1;
            } else {
                D_8010A440 = 0;
            }
        }
        func_80105F00(D_8010A220);
        if (D_8010A220 < 8) {
            ++D_8010A220;
        }
        break;
    case 15:
        func_80105F00(D_8010A220);
        if (D_8010A220 <= 0) {
            if (D_8010A440 == 2) {
                D_8010A43C = 0x13;
                break;
            }
            if (D_8010A440 != 1) {
                vs_main_freeHeapR(D_8010A470);
                D_8010A43C = 1;
                break;
            }
            vs_main_freeHeapR(D_8010A470);
            func_80104AF8();
            return 2;
        }
        --D_8010A220;
        break;
    case 19:
        if (func_80107FBC(D_8010A470[D_800F1BF0[2] + D_800F1BF0[3]].unk0) == 0) {
            int temp_v1_4 = D_800F453C->unk656;
            D_8010A44C = temp_v1_4;
            D_8010A44E = D_800F453C->unk63E;
            D_8010A444 = (temp_v1_4 << 0x10) >> 0xE;
            if (D_8010A444 < 0x280) {
                D_8010A444 = 0x280;
            } else if (D_8010A444 > 0x1800) {
                D_8010A444 = 0x1800;
            }
            D_8010A430[1] = 0x100;
            D_8010A448 = 0;
            D_8010A430[0] = 0;
            D_8010A430[2] = 0;
            D_8010A450 = D_800F1BF0[2] + D_800F1BF0[3];
            func_80104B40();
            func_80102A38(D_8010A45C == 0);
            ++D_8010A43C;
            break;
        }
        break;
    case 20:
        if (D_8010A470[D_8010A450].unkD != D_8010A450) {
            D_8010A438 = (D_8010A438 + 1) & 0xF;
            func_80107A98(0);
            func_80107A98(1);
        }
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            vs_main_playSfxDefault(0x7E, 6);
            if (D_8010A45C != 0) {
                func_80102A38(1);
            }
            D_8010A43C += 1;
            if (vs_main_buttonsPressed.all & PADRup) {
                func_800FFBA8();
                D_8010A440 = 1;
            } else {
                D_8010A440 = 0;
            }
        }

        D_8010A458 = 0x808080;
        D_8010A454 = 0x808080;

        if ((lStickX = vs_main_stickPosBuf.lStickX - 0x80, ABS(lStickX) > 0x40)
            || (lStickY = vs_main_stickPosBuf.lStickY - 0x80, ABS(lStickY) > 0x40)) {
            D_8010A454 = 0x202020;
            if (lStickX < -0x40) {
                D_8010A430[1] -= 0x40;
            } else if (lStickX > 0x40) {
                D_8010A430[1] += 0x40;
            }

            if ((vs_main_stickPosBuf.lStickY - 0x80) < -0x40) {
                D_8010A430[0] += 0x40;
            } else if ((vs_main_stickPosBuf.lStickY - 0x80) > 0x40) {
                D_8010A430[0] -= 0x40;
            }
            if (D_8010A430[0] < 0) {
                D_8010A430[0] = 0;
            }
            if (D_8010A430[0] > 0x400) {
                D_8010A430[0] = 0x400;
            }
        } else {
            if (vs_main_buttonsPreviousState & PADL2) {
                int rStickX;
                int rStickY;
                D_8010A454 = 0x202020;

                if ((rStickX = vs_main_stickPosBuf.rStickX - 0x80, ABS(rStickX) > 0x40)
                    || (rStickY = vs_main_stickPosBuf.rStickY - 0x80,
                        ABS(rStickY) > 0x40)) {
                    if (rStickX < -0x40) {
                        D_8010A430[1] -= 0x40;
                    } else if (rStickX > 0x40) {
                        D_8010A430[1] += 0x40;
                    }
                    if ((vs_main_stickPosBuf.rStickY - 0x80) < -0x40) {
                        D_8010A430[0] += 0x40;
                    } else if ((vs_main_stickPosBuf.rStickY - 0x80) > 0x40) {
                        D_8010A430[0] -= 0x40;
                    }
                    if (D_8010A430[0] < 0) {
                        D_8010A430[0] = 0;
                    }
                    if (D_8010A430[0] > 0x400) {
                        D_8010A430[0] = 0x400;
                    }
                } else {
                    if (vs_main_buttonsPreviousState & PADLup) {
                        D_8010A430[0] += 0x40;
                    } else if (vs_main_buttonsPreviousState & PADLdown) {
                        D_8010A430[0] -= 0x40;
                    }
                    if (vs_main_buttonsPreviousState & PADLright) {
                        D_8010A430[1] = D_8010A430[1] + 0x40;
                    } else if (vs_main_buttonsPreviousState & PADLleft) {
                        D_8010A430[1] = D_8010A430[1] - 0x40;
                    }
                    if (D_8010A430[0] < 0) {
                        D_8010A430[0] = 0;
                    }
                    if (D_8010A430[0] > 0x400) {
                        D_8010A430[0] = 0x400;
                    }
                }

            } else if (vs_main_buttonsPreviousState & PADR2) {
                int rStickX;
                int rStickY;
                D_8010A458 = 0x202020;
                if ((rStickX = vs_main_stickPosBuf.rStickX - 0x80, ABS(rStickX) > 0x40)
                    || (rStickY = vs_main_stickPosBuf.rStickY - 0x80,
                        ABS(rStickY) > 0x40)) {
                    if ((vs_main_stickPosBuf.rStickY - 0x80) < -0x40) {
                        D_8010A444 -= 4;
                    } else if ((vs_main_stickPosBuf.rStickY - 0x80) > 0x40) {
                        D_8010A444 += 4;
                    }
                } else {
                    if (vs_main_buttonsPreviousState & PADLup) {
                        D_8010A444 -= 0x40;
                    } else if (vs_main_buttonsPreviousState & PADLdown) {
                        D_8010A444 += 0x40;
                    }
                }
                if (D_8010A444 >= 0x280) {
                    if (D_8010A444 > 0x1800) {
                        D_8010A444 = 0x1800;
                    }
                } else {
                    D_8010A444 = 0x280;
                }
            }
        }
        if (vs_main_buttonsPressed.all & PADselect) {
            func_80102A38(D_8010A45C);
            D_8010A45C ^= 1;
        }
        if ((vs_main_buttonsPreviousState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {
            if (vs_main_buttonsPressed.all & (PADL1 | PADR1)) {
                D_8010A452 = 0;
            }
            if (vs_main_buttonRepeat & 8) {
                if (D_8010A452 == 0) {
                    if (D_8010A470[D_8010A450].unkE != D_8010A450) {
                        vs_main_playSfxDefault(0x7E, 0xB);
                        D_8010A450 = D_8010A470[D_8010A450].unkE;
                        D_8010A448 = 8;
                        func_80104B40();
                    }
                }
                D_8010A452 = (D_8010A452 + 1) & 3;
            }
            if (vs_main_buttonRepeat & PADL1) {
                if (D_8010A452 == 0) {
                    if (D_8010A470[D_8010A450].unkD != D_8010A450) {
                        vs_main_playSfxDefault(0x7E, 0xB);
                        D_8010A450 = D_8010A470[D_8010A450].unkD;
                        D_8010A448 = 4;
                        func_80104B40();
                    }
                }
                D_8010A452 = (D_8010A452 + 1) & 3;
            }
        }
        func_801061F8(D_8010A220, 0);
        if (D_8010A220 < 8) {
            temp_v0 = func_800CCDF4(0);
            temp_v0->unk4[8] -= 0x10;
            temp_v0->unk4[6] -= 0x10;
            ++D_8010A220;
        }
        if (vs_main_buttonsReleased & D_8010A448) {
            if (D_8010A448 == 8) {
                D_8010A448 = 1;
            } else {
                D_8010A448 = 2;
            }
            D_8010A458 = 0x202020;
            D_8010A454 = 0x202020;
            D_8010A43C = 0x19;
        }
        break;
    case 21:
        D_8010A458 = 0x202020;
        D_8010A454 = 0x202020;
        func_801061F8(D_8010A220, 0);
        if (D_8010A220 > 0) {
            temp_v0 = func_800CCDF4(0);
            if (temp_v0 != NULL) {
                temp_v0->unk4[8] += 0x10;
                temp_v0->unk4[6] += 0x10;
            }
            --D_8010A220;
            break;
        }
        func_80108098();
        if (D_8010A440 != 0) {
            vs_main_freeHeapR(D_8010A470);
            func_80104AF8();
            return 2;
        }
        D_8010A450 = D_800F1BF0[2] + D_800F1BF0[3];
        vs_mainmenu_setMessage((char*)&D_8010A474[D_8010A474[D_8010A450]]);
        D_8010A43C = 0xE;
        break;
    case 25:
        func_80107A98(2);
        func_80107A98(3);
        func_801061F8(D_8010A220, D_8010A448);
        if (D_8010A220 > 0) {
            --D_8010A220;
            break;
        }
        func_80108098();
        func_80107FBC(D_8010A470[D_8010A450].unk0);
        ++D_8010A43C;
        break;
    case 26:
        func_80107A98(2);
        func_80107A98(3);
        func_801061F8(D_8010A220, 3);
        if (func_80107FBC(D_8010A470[D_800F1BF0[2] + D_800F1BF0[3]].unk0) == 0) {
            int temp_v1_10 = D_800F453C->unk656;
            D_8010A44C = temp_v1_10;
            D_8010A44E = D_800F453C->unk63E;
            D_8010A444 = (temp_v1_10 << 0x10) >> 0xE;
            if (D_8010A444 < 0x280) {
                D_8010A444 = 0x280;
            } else if (D_8010A444 >= 0x1801) {
                D_8010A444 = 0x1800;
            }
            ++D_8010A43C;
        }
        break;
    case 27:
        func_80107A98(2);
        func_80107A98(3);
        func_801061F8(D_8010A220, 3 - D_8010A448);
        if (D_8010A220 < 8) {
            D_8010A220 += 1;
        } else {
            D_8010A448 = 0;
            D_8010A43C = 0x14;
        }
        break;
    }
    return 0;
}

void func_80104AF8(void)
{
    vs_main_memcpy((void*)getScratchAddr(13), D_8010A480, sizeof D_8010A480);
    vs_main_memcpy((void*)getScratchAddr(21), D_8010A490, sizeof D_8010A490);
}

void func_80104B40(void)
{
    if (D_8010A470[D_8010A450].unkC != 0) {
        vs_mainmenu_setMessage((char*)&D_8010A474[D_8010A474[D_8010A450]]);
    } else {
        vs_mainmenu_setMessage((char*)&_miscInfo[_miscInfo[2]]);
    }
}

int func_80104BD0(int arg0)
{
    char* sp10[8];
    int i;

    if (arg0 != 0) {
        D_8010A224 = 0;
        D_8010A228 = 0;
    }

    switch (D_8010A224) {
    case 0:
        for (i = 0; i < 4; ++i) {
            sp10[i * 2] = (char*)&_menuStrings[_menuStrings[i]];
            sp10[i * 2 + 1] = NULL;
        }
        func_80102E10(4, D_800F1BF7, sp10, i);
        ++D_8010A224;
        break;
    case 1:
        D_8010A228 = func_80102F0C();
        if (D_8010A228 == -1) {
            break;
        }
        return D_8010A228;
    }
    return -1;
}

void func_80104CBC(MATRIX* arg0)
{
    SVECTOR sp10;
    SVECTOR sp18;
    MATRIX sp20;
    int trig0;
    int trig1;
    int trig2;
    int var_v0;
    int* scratch;

    trig0 = vs_math_sine(D_8010A430[1]);
    trig1 = vs_math_cosine(D_8010A430[0]);
    trig0 *= D_8010A444;
    if (trig0 < 0) {
        trig0 += 0xFFF;
    }

    var_v0 = (trig0 >> 0xC) * trig1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }

    sp18.vx = var_v0 >> 0xC;
    trig0 = vs_math_cosine(D_8010A430[1]);
    trig1 = vs_math_cosine(D_8010A430[0]);
    trig0 *= -D_8010A444;
    if (trig0 < 0) {
        trig0 += 0xFFF;
    }

    var_v0 = (trig0 >> 0xC) * trig1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }

    sp18.vz = var_v0 >> 0xC;
    trig2 = vs_math_sine(D_8010A430[0]) * -D_8010A444;
    if (trig2 < 0) {
        trig2 += 0xFFF;
    }

    sp18.vy = (trig2 >> 0xC) - (D_8010A44E / 2);

    scratch = (int*)getScratchAddr(0);
    scratch[13] = sp18.vx << 0xC;
    scratch[14] = (sp18.vy << 0x10) >> 4;
    scratch[15] = sp18.vz << 0xC;
    scratch[21] = D_8010A430[0];
    scratch[22] = D_8010A430[1];
    scratch[23] = D_8010A430[2];

    func_80104E90(arg0, D_8010A430[1]);
    func_80104F04(&sp20, D_8010A430[0]);
    func_80041C68(&sp20, arg0);

    sp10.vx = -sp18.vx;
    sp10.vy = -sp18.vy;
    sp10.vz = -sp18.vz;

    ApplyMatrix(arg0, &sp10, (VECTOR*)&arg0->t);
}

void func_80104E90(MATRIX* arg0, short arg1)
{
    int sine = vs_math_sine(-arg1);
    int cosine = vs_math_cosine(-arg1);
    arg0->m[0][0] = cosine;
    arg0->m[0][1] = 0;
    arg0->m[0][2] = -sine;
    arg0->m[1][0] = 0;
    arg0->m[1][1] = 0x1000;
    arg0->m[1][2] = 0;
    arg0->m[2][0] = sine;
    arg0->m[2][1] = 0;
    arg0->m[2][2] = cosine;
}

void func_80104F04(MATRIX* arg0, short arg1)
{
    int temp_s0;
    int temp_v0;

    temp_s0 = vs_math_sine(arg1);
    temp_v0 = vs_math_cosine(arg1);
    arg0->m[0][0] = 0x1000;
    arg0->m[0][1] = 0;
    arg0->m[0][2] = 0;
    arg0->m[1][0] = 0;
    arg0->m[1][1] = temp_v0;
    arg0->m[1][2] = -temp_s0;
    arg0->m[2][0] = 0;
    arg0->m[2][1] = temp_s0;
    arg0->m[2][2] = temp_v0;
}

void func_80104F74(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int i;
    int var_s7;
    LINE_G2* line;
    POLY_F4* poly;

    void** scratch = (void**)getScratchAddr(0);

    line = scratch[0];

    for (i = arg1, var_s7 = arg2; i < ((arg1 + arg3) - 1); ++i, --var_s7) {

        setLineG2(line);
        setXY2(line, arg0, i, (arg0 + var_s7) - 1, i);
        setRGB0(line, D_80102820[arg4].r0, D_80102820[arg4].g0, D_80102820[arg4].b0);
        setRGB1(line, D_80102830[arg4].r0, D_80102830[arg4].g0, D_80102830[arg4].b0);
        AddPrim(*((void**)getScratchAddr(1)) + 0x1C, line++);
    }
    arg0 += 2;
    arg1 += 2;
    poly = (POLY_F4*)line;
    setPolyF4(poly);
    setXY4(poly, arg0, arg1, (arg0 + arg2) - 1, arg1, arg0, (arg1 + arg3) - 1,
        (arg0 + arg2) - arg3, (arg1 + arg3) - 1);
    setRGB0(poly, 0, 0, 0);
    scratch = (void**)getScratchAddr(0);
    AddPrim(scratch[1] + 0x1C, poly++);
    scratch[0] = (void*)poly;
    _insertTPage(7, 0x60);
}

void func_801051AC(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    char b1;
    char g0;
    char r1;
    char g1;
    char r0;
    char b0;
    POLY_G4* polyG4;
    POLY_F4* polyF4;
    void** scratch = (void**)0x1F800000;

    int a3 = (arg0 + arg2) - 1;
    int a2 = (arg1 + arg3) - 1;

    polyG4 = scratch[0];
    setPolyG4(polyG4);
    r0 = D_80102820[arg4].r0;
    g0 = D_80102820[arg4].g0;
    b0 = D_80102820[arg4].b0;
    r1 = D_80102830[arg4].r0;
    g1 = D_80102830[arg4].g0;
    b1 = D_80102830[arg4].b0;

    setXY4(polyG4, arg0, arg1, a3, arg1, arg0, a2, a3, a2);
    setRGB0(polyG4, r0, g0, b0);
    setRGB1(polyG4, r1, g1, b1);
    setRGB2(polyG4, r0, g0, b0);
    setRGB3(polyG4, r1, g1, b1);
    AddPrim(scratch[1] + 0x1C, polyG4++);

    arg0 += 2;
    arg1 += 2;
    polyF4 = (POLY_F4*)polyG4;
    setPolyF4(polyF4);
    setXY4(polyF4, arg0, arg1, (arg0 + arg2) - 1, arg1, arg0, (arg1 + arg3) - 1,
        (arg0 + arg2) - 1, (arg1 + arg3) - 1);
    setRGB0(polyF4, 0, 0, 0);
    AddPrim(scratch[1] + 0x1C, polyF4++);
    scratch[0] = polyF4;
    _insertTPage(7, getTPage(0, 3, 0, 0));
}

void func_8010539C(int arg0)
{
    POLY_F4* polyF4;
    void** scratch = (void**)getScratchAddr(0);
    POLY_G4* polyG4 = scratch[0];

    setPolyG4(polyG4);
    setXY4(polyG4, 0, arg0, 0x140, arg0, 0, arg0 + 8, 0x140, arg0 + 8);
    setRGB0(polyG4, 0, 0, 0);
    setRGB1(polyG4, 0, 0, 0);
    setRGB2(polyG4, 0x80, 0x80, 0x80);
    setRGB3(polyG4, 0x80, 0x80, 0x80);
    setSemiTrans(polyG4, 1);
    AddPrim(scratch[1] + 0x1C, polyG4++);
    polyF4 = (POLY_F4*)polyG4;
    setPolyF4(polyF4);
    setXY4(polyF4, 0, arg0 + 8, 0x140, arg0 + 8, 0, 0xF0, 0x140, 0xF0);
    setRGB0(polyF4, 0, 0, 0);
    AddPrim(scratch[1] + 0x1C, polyF4++);
    scratch[0] = polyF4;
    _insertTPage(7, getTPage(0, 2, 0, 0));
}

void func_8010552C(int arg0)
{
    vs_battle_geomOffset sp18;
    vs_battle_geomOffset sp20;
    char sp28[128];
    MATRIX spA8;
    void** scratch;

    if (arg0 < 8) {
        func_80106528();
    }
    vs_battle_getGeomOffset(&sp18);
    sp20.x = 0x80 - ((8 - arg0) << 5);
    sp20.y = 0xF0;
    vs_battle_setGeomOffset(&sp20);
    func_80104CBC(&spA8);
    func_800F9EB8(&spA8);
    vs_battle_setGeomOffset(&sp18);
    sprintf(sp28, "#%ld", _score);
    scratch = (void**)getScratchAddr(0);
    func_800C6540("SCORE", (((arg0 * 0x10) - 0x78) & 0xFFFF) | 0x100000, 0x808080,
        scratch[1] + 0x1C);
    func_800C6540(sp28, ((arg0 * 0x10) & 0xFFFF) | 0x100000, 0x808080, scratch[1] + 0x1C);
    func_801051AC((arg0 * 0x10) - 0x80, 0x10, 0x88, 0xC, 2);
    func_800C6540("RISK   BREAKER   RANK", (((arg0 * 0x10) - 0x78) & 0xFFFF) | 0xB80000,
        0x808080, scratch[1] + 0x1C);
    func_801051AC((arg0 * 0x10) - 0x80, 0xB8, 0x88, 0xC, 1);
    func_8010539C(0xEC - (arg0 * 6));
}

void func_801056B8(void)
{
    int i;
    D_8010A230_t* var_a2;
    int new_var;

    for (i = 0, var_a2 = D_8010A230; i < 32; ++i, ++var_a2) {
        var_a2->unk4 = 0x3C;
        var_a2->unk6 = i + 1;
        var_a2->unk0 = 0;
        var_a2->unk2 = 0;
        var_a2->unk3 = 0;
        if (vs_main_scoredata.unk0 & ((new_var = 1) << i)) {
            var_a2->unk1 = 1;
            var_a2->unk8 = (char*)&_titleStrings[_titleStrings[i]];
            var_a2->unkC = (char*)&_titleDescriptions[_titleDescriptions[i]];
        } else {
            var_a2->unk1 = 0;
            var_a2->unk8 = (char*)&_miscInfo[_miscInfo[0]];
            var_a2->unkC = (char*)&_miscInfo[_miscInfo[1]];
        }
    }
}

void func_8010579C(int arg0)
{
    int i;
    vs_battle_menuItem_t* temp_s0;

    D_8010A230_t* var_s2 = D_8010A230;
    int temp_s1 = D_800F1BF0[0] + D_800F1BF0[1];

    for (i = 0; i < 32; ++i, ++var_s2) {
        if (i == temp_s1) {
            if (var_s2->unk0 == 0) {
                vs_mainmenu_setMessage(var_s2->unkC);
            }
            var_s2->unk0 = 1;
            if (var_s2->unk1 != 0) {
                var_s2->unk2 = 8;
            }
        } else {
            var_s2->unk0 = 0;
            if (var_s2->unk2 != 0) {
                --var_s2->unk2;
            }
        }
    }

    var_s2 = &D_8010A230[(u_char)D_800F1BF0[0]];

    for (i = 0; i < 8; ++i, ++var_s2) {
        int var_s3 = (arg0 * 0x17) - 0x10;
        if ((0x38 + i * 0x10) < var_s3) {
            var_s3 = (0x38 + i * 0x10);
        }
        if (var_s2->unk0 != 0) {
            if (arg0 == 8) {
                D_80109898 = func_800FFCDC((int)D_80109898,
                    ((var_s2->unk4 - 0xC) & 0xFFFF) | ((var_s3 - 8) << 0x10));
            }
        }
        temp_s0 =
            vs_battle_setMenuItem(0, (int)var_s2->unk4, var_s3, 0xC8, 0, var_s2->unk8);
        if (var_s2->unk1 == 0) {
            temp_s0->unkA = 3;
        }
        temp_s0->unk4 = var_s2->unk2;
        if ((i == 0) && (D_800F1BF0[0] != 0)) {
            temp_s0->unk5 = 1;
        }
        if ((i == 7) && (D_800F1BF0[0] != 0x18)) {
            temp_s0->unk5 = 2;
        }
        func_80105A0C(var_s2->unk4 - 0xE, var_s3, var_s2->unk6, temp_s0->unk5 & 1);
        if ((temp_s0->unk5 != 0) && (arg0 == 8)) {
            func_80102A7C(temp_s0);
        } else {
            func_800C9078(temp_s0);
        }
    }
    vs_battle_getMenuItem(0)->state = 0;
}

void func_80105A0C(int arg0, int arg1, int arg2, int arg3)
{
    char digits[2];
    int i;
    POLY_FT4* poly;

    sprintf(digits, "%02d", arg2);
    arg0 += 0x13;
    poly = *(void**)0x1F800000;

    for (i = 1; i >= 0; --i, arg0 -= 5) {
        setPolyFT4(poly);
        poly->x0 = arg0;
        poly->y0 = arg1 - 4;
        poly->x1 = arg0 + 6;
        poly->y1 = arg1 - 4;
        poly->x2 = arg0;
        poly->y2 = arg1 + 6;
        poly->x3 = arg0 + 6;
        poly->y3 = arg1 + 6;
        setcode(poly, (getcode(poly) | 0x02) & 0xFE);
        poly->u0 = (digits[i] - 0x30) * 6;
        poly->v0 = 0;
        poly->u1 = ((digits[i] - 0x30) * 6) + 6;
        poly->v1 = 0;
        poly->u2 = (digits[i] - 0x30) * 6;
        poly->v2 = 0xA;
        poly->u3 = ((digits[i] - 0x30) * 6) + 6;
        poly->v3 = 0xA;
        if (arg3 != 0) {
            poly->tpage = 0x2C;
            poly->r0 = 0x20;
            poly->g0 = 0x20;
            poly->b0 = 0x20;
            poly->clut = 0x37F7;
        } else {
            poly->tpage = 0xC;
            poly->r0 = 0x80;
            poly->g0 = 0x80;
            poly->b0 = 0x80;
            poly->clut = 0x37F4;
        }
        AddPrim(*(void**)0x1F800008, poly++);
    }
    *(void**)0x1F800000 = poly;
}

void func_80105BCC(int arg0, int arg1, int arg2, int arg3)
{
    char sp10[2];
    int i;
    POLY_FT4* poly;

    sprintf(sp10, "%03d", arg2);
    arg0 += 0x18;
    poly = *(void**)getScratchAddr(0);

    for (i = 2; i >= 0; --i, arg0 -= 5) {
        setPolyFT4(poly);
        setXY4(
            poly, arg0, arg1 - 4, arg0 + 6, arg1 - 4, arg0, arg1 + 6, arg0 + 6, arg1 + 6);
        setcode(poly, (getcode(poly) | 0x02) & 0xFE);
        setUV4(poly, (sp10[i] - 0x30) * 6, 0, ((sp10[i] - 0x30) * 6) + 6, 0,
            (sp10[i] - 0x30) * 6, 0xA, ((sp10[i] - 0x30) * 6) + 6, 0xA);
        if (arg3 != 0) {
            setTPage(poly, 0, 1, 768, 0);
            setRGB0(poly, 0x20, 0x20, 0x20);
            setClut(poly, 880, 223);
        } else {
            setTPage(poly, 0, 0, 768, 0);
            setRGB0(poly, 0x80, 0x80, 0x80);
            setClut(poly, 832, 223);
        }
        AddPrim(*(void**)getScratchAddr(2), poly++);
    }
    *(void**)getScratchAddr(0) = poly;
}

void func_80105D8C(void)
{
    int j;
    int var_v0;
    int i;
    char var_a0_2;
    D_8010A470_t* var_a3;
    int new_var;
    int* new_var2;

    for (i = 0, var_a3 = D_8010A470; i < 0x4E; ++i, ++var_a3) {
        var_a3->unkC = 0;
        for (j = var_a3->unk4; j < (var_a3->unk4 + var_a3->unk6); ++j) {
            var_v0 = j;
            if (j < 0) {
                var_v0 += 0x1F;
            }
            var_v0 >>= 5;
            new_var = vs_main_scoredata.unk9C[var_v0]
                    & (1 << (j - ((*(new_var2 = &var_v0)) << 5)));
            if (new_var) {
                var_a3->unkC = 1;
                break;
            }
        }
    }

    for (i = 0, var_a3 = D_8010A470, var_a0_2 = -1; i < 0x4E; ++i, ++var_a3) {
        if (var_a3->unkC != 0) {
            var_a3->unkD = var_a0_2;
            var_a0_2 = i;
        }
    }

    for (i = 0, var_a3 = D_8010A470; i < 0x4E; ++i, ++var_a3) {
        if (var_a3->unkC != 0) {
            var_a3->unkD = var_a0_2;
            break;
        }
    }

    for (i = 0x4D, var_a3 = &D_8010A470[77], var_a0_2 = -1; i >= 0; --i, --var_a3) {
        if (var_a3->unkC != 0) {
            var_a3->unkE = var_a0_2;
            var_a0_2 = i;
        }
    }

    for (i = 0x4D, var_a3 = &D_8010A470[77]; i >= 0; --i, --var_a3) {
        if (var_a3->unkC != 0) {
            var_a3->unkE = var_a0_2;
            break;
        }
    }
}

void func_80105F00(int arg0)
{
    int sp18;
    D_8010A470_t* var_s4;
    int temp_s3;
    int var_s1;
    int i;
    vs_battle_menuItem_t* var_s0_2;
    int s6;

    temp_s3 = D_800F1BF0[2] + D_800F1BF0[3];
    var_s4 = D_8010A470;
    for (i = 0; i < 0x4E; ++i) {
        if (i == temp_s3) {
            if (var_s4->unk8 == 0) {
                if (var_s4->unkC != 0) {
                    vs_mainmenu_setMessage((char*)&D_8010A474[D_8010A474[i]]);
                } else {
                    vs_mainmenu_setMessage((char*)&_miscInfo[_miscInfo[2]]);
                }
            }
            var_s4->unk8 = 1;
            if (var_s4->unkC != 0) {
                var_s4->unkA = 8;
            }
        } else {
            var_s4->unk8 = 0;
            if (var_s4->unkA > 0) {
                var_s4->unkA = var_s4->unkA - 1;
            }
        }
        ++var_s4;
    }

    i = 0;
    sp18 = arg0 * 0x17;
    var_s4 = &D_8010A470[D_800F1BF0[2]];

    for (; i < 8; ++i, ++var_s4) {
        u_char* new_var = D_800F1BF0;
        var_s1 = sp18 - 0x10;
        if ((0x38 + i * 0x10) < var_s1) {
            var_s1 = 0x38 + i * 0x10;
        }
        s6 = 0x3C;
        if ((var_s4->unk8 != 0) && (arg0 == 8)) {
            D_80109899 = func_800FFCDC(D_80109899, ((var_s1 - 8) << 0x10) | 0x30);
        }
        if (var_s4->unkC != 0) {
            var_s0_2 =
                vs_battle_setMenuItem(0, s6, var_s1, 0xC8, 0, (char*)&var_s4->unk10);
        } else {
            var_s0_2 = vs_battle_setMenuItem(
                0, s6, var_s1, 0xC8, 0, (char*)&_miscInfo[_miscInfo[3]]);
            var_s0_2->unkA = 3;
        }
        var_s0_2->unk4 = var_s4->unkA;
        if ((i == 0) && (new_var[2] != 0)) {
            var_s0_2->unk5 = 1;
        }
        if ((i == 7) && (new_var[2] != 0x46)) {
            var_s0_2->unk5 = 2;
        }
        func_80105BCC(s6 - 0xE, var_s1, new_var[2] + i + 1, var_s0_2->unk5 & 1);
        if ((var_s0_2->unk5 != 0) && (arg0 == 8)) {
            func_80102A7C(var_s0_2);
        } else {
            func_800C9078(var_s0_2);
        }
    }
    vs_battle_getMenuItem(0)->state = 0;
}

void func_801061F8(int arg0, int arg1)
{
    char const* sp18[] = { "HUMAN", "BEAST", "UNDEAD", "PHANTOM", "DRAGON", "EVIL" };
    MATRIX sp30;
    vs_battle_geomOffset sp50;
    vs_battle_geomOffset sp58;
    char sp60[12];
    int temp_s0;
    int temp_s2;
    int temp_s4;
    int temp_s6;
    void** scratch;

    if (arg0 < 8) {
        func_80106528();
    }
    if (arg1 != 3) {
        vs_battle_getGeomOffset(&sp50);
        if (arg1 == 2) {
            sp58.x = ((8 - arg0) << 5) + 0xA0;
        } else {
            sp58.x = 0xA0 - ((8 - arg0) << 5);
        }
        sp58.y = 0x68;
        vs_battle_setGeomOffset(&sp58);
        func_80104CBC(&sp30);
        func_800F9EB8(&sp30);
        vs_battle_setGeomOffset(&sp50);
    }
    if (arg1 > 0) {
        arg0 = 8;
    }
    if (D_8010A45C == 0) {
        temp_s2 = (8 - arg0) * 0x10;
        func_800C9078(vs_battle_setMenuItem(
            0, temp_s2 + 0xB8, 0xA6, 0x100, 0, (char*)&D_8010A470[D_8010A450].unk12));
        vs_battle_getMenuItem(0)->state = 0;
        temp_s4 = arg0 * 0x10;
        scratch = (void**)getScratchAddr(0);
        vs_mainmenu_drawButton(6, temp_s4 - 0x78, 0xF, scratch[1] + 0x18);
        temp_s0 = (temp_s4 - 0x64) & 0xFFFF;
        func_800C6540("ROTATION", temp_s0 | 0x120000, D_8010A458, scratch[1] + 0x18);
        temp_s6 = temp_s4 - 0x70;
        func_80104F74(temp_s6, 0x12, 0x60, 0xC, 3);
        vs_mainmenu_drawButton(7, temp_s4 - 0x78, 0x22, scratch[1] + 0x18);
        func_800C6540("ZOOM", temp_s0 | 0x240000, D_8010A454, scratch[1] + 0x18);
        func_80104F74(temp_s6, 0x24, 0x4E, 0xC, 3);
        sprintf(sp60, "NO.   %03d/%03d", D_8010A450 + 1, 0x4E);
        func_800C6540(
            sp60, ((temp_s4 - 0x78) & 0xFFFF) | 0xA00000, 0x808080, scratch[1] + 0x1C);
        func_801051AC(temp_s4 - 0x80, 0xA0, 0x64, 0xC, 2);
        func_800C6540(sp18[D_8010A470[D_8010A450].unk2],
            ((temp_s2 + 0xBC) & 0xFFFF) | 0x9B0000, 0x808080, NULL);
        func_801051AC(temp_s2 + 0xB4, 0x9B, 0x8C, 0x1A, 1);
    }
}

void func_80106528(void)
{
    void** scratch = (void**)0x1F800000;
    POLY_G4* poly = scratch[0];

    setPolyG4(poly);
    setXY4(poly, 0, 0, 0x40, 0, 0, 0xF0, 0x40, 0xF0);
    setRGB0(poly, 0x80, 0x80, 0x80);
    setRGB1(poly, 0, 0, 0);
    setRGB2(poly, 0x80, 0x80, 0x80);
    setRGB3(poly, 0, 0, 0);
    setSemiTrans(poly, 1);
    AddPrim(scratch[1] + 0x20, poly++);
    setPolyG4(poly);
    setXY4(poly, 0x100, 0, 0x140, 0, 0x100, 0xF0, 0x140, 0xF0);
    setRGB0(poly, 0, 0, 0);
    setRGB1(poly, 0x80, 0x80, 0x80);
    setRGB2(poly, 0, 0, 0);
    setRGB3(poly, 0x80, 0x80, 0x80);
    setSemiTrans(poly, 1);
    AddPrim(scratch[1] + 0x20, poly++);
    scratch[0] = poly;
    _insertTPage(8, getTPage(0, 2, 0, 0));
}

void _vsStrcpy(u_char* arg0, u_char* arg1)
{
    while (*arg1 != 0xE7) {
        *arg0++ = *arg1++;
    }
    *arg0 = *arg1;
}

void _vsStrcat(char* arg0, char* arg1)
{
    while (*arg0 != 0xE7) {
        ++arg0;
    }
    while (*arg1 != 0xE7) {
        *arg0++ = *arg1++;
    }
    *arg0 = *arg1;
}

void func_80106780(void)
{
    int i;
    D_8010A230_t* p;

    for (i = 0, p = D_8010A230; i < 23; ++i, ++p) {
        p->unk4 = 16;
        p->unk8 = (void*)&_statHeaders[_statHeaders[i]];
        p->unkC = (void*)&_statDescriptions[_statDescriptions[i]];
        p->unk2 = 0;
        p->unk6 = i + 1;
        p->unk0 = 0;
        p->unk3 = 0;
        p->unk1 = 1;
    }
}

// https://decomp.me/scratch/J4g91
INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80106808);

void _toVsStringInt(char* buf, int value)
{
    int len;
    int i;
    buf++;
    buf--;
    sprintf(buf, "%d", value);
    len = strlen(buf);

    for (i = 0; i < len; ++i) {
        buf[i] -= 0x30;
    }
    buf += len;
    *buf = -0x19;
}

void _toVsStringPercent(char* buf, int value)
{

    int len;
    int i;

    buf++;
    buf--;

    sprintf(buf, "%d", value);

    len = strlen(buf);
    for (i = 0; i < len; ++i) {
        buf[i] -= 0x30;
    }
    buf += len;
    *((D_8010989C_t*)buf) = D_8010989C;
}

void func_80106DE0(char* buf, int rank, int totalSeconds)
{
    int len;
    int i;
    int minutes;
    int seconds;
    char* str;

    if (_clearCount == 0) {
        _vsStrcpy((u_char*)buf, (u_char*)&_miscInfo[_miscInfo[0]]);
        return;
    }

    minutes = totalSeconds / 60;

    if (minutes >= 100) {
        minutes = 99;
        seconds = 59;
    } else {
        seconds = totalSeconds % 60;
    }

    *buf = vs_char_R;
    str = buf + 1;
    sprintf(str, "%d", rank + 1);
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        str[i] -= 0x30;
    }

    str = &str[len];
    *str++ = (u_char)vs_char_spacing;
    *str++ = 12;

    sprintf(str, "%02d", minutes);
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        str[i] -= 0x30;
    }

    str = &str[len];
    *str++ = (u_char)vs_char_colon;
    sprintf(str, "%02d", seconds);
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        str[i] -= 0x30;
    }

    str += len;
    *str = (u_char)vs_char_terminator;
}

void func_80106F9C(void)
{
    int i;
    D_8010A230_t* var_t0;

    for (i = 0, var_t0 = D_8010A230; i < 8; ++i, ++var_t0) {
        var_t0->unk4 = 0xC2;
        if ((vs_main_scoredata.bossTimeTrialScores[i][0] & 0xFFFFFF) == 0x800000) {
            var_t0->unk3 = 1;
            var_t0->unk8 = (char*)&_miscInfo[_miscInfo[4]];
            var_t0->unkC = (char*)&_miscInfo[_miscInfo[5]];
        } else {
            var_t0->unk3 = 0;
            var_t0->unk8 = (char*)&_timeAttacks[_timeAttacks[i]];
            var_t0->unkC = (char*)&_timeAttackDescriptions[_timeAttackDescriptions[i]];
        }
        var_t0->unk0 = 0;
        var_t0->unk2 = i + 1;
        var_t0->unk1 = 1;
    }
}

void func_80107090(void)
{
    int i;
    D_8010A230_t* p = D_8010A230;

    for (i = 0; i < 8; ++i, ++p) {
        if (p->unk2 == 0) {
            vs_battle_menuItem_t* temp_v0 = vs_battle_getMenuItem(i);
            temp_v0->state = 2;
            temp_v0->x = 0x140;
        } else {
            p->unk2 = -1;
        }
    }
}

// https://decomp.me/scratch/oR7eY
INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", func_80107120);

void func_80107600(void)
{
    int i;
    int var_a2;
    int a1;

    for (i = 0, var_a2 = 0, a1 = 1; i < 16; ++i) {
        if (vs_main_scoredata.unk0 & (a1 << i)) {
            ++var_a2;
        }
    }

    for (i = 0; i < 16; ++i) {
        if ((var_a2 >= D_801098A4[i]) && (_score >= D_801098C4[i])) {
            D_8010A464 = i;
            return;
        }
    }
}

void _calculateScore(void)
{
    int i;

    if (_clearCount != 0) {
        vs_main_scoredata.unk0 |= 1;
    }
    if (vs_main_scoredata.unk98 >= 0x34U) {
        vs_main_scoredata.unk0 |= 4;
    }
    if (vs_main_scoredata.unk94 >= 0x169U) {
        vs_main_scoredata.unk0 |= 8;
    }
    if (vs_main_stateFlags.unkCC != 0) {
        vs_main_scoredata.unk0 |= 0x10;
    }
    if (vs_main_stateFlags.unkCD != 0) {
        vs_main_scoredata.unk0 |= 0x20;
    }
    if (vs_main_stateFlags.unkCE != 0) {
        vs_main_scoredata.unk0 |= 0x40;
    }
    if (vs_main_stateFlags.unkCF != 0) {
        vs_main_scoredata.unk0 |= 0x80;
    }
    if (vs_main_stateFlags.unkD0 != 0) {
        vs_main_scoredata.unk0 |= 0x100;
    }
    if (vs_main_stateFlags.unkD1 != 0) {
        vs_main_scoredata.unk0 |= 0x200;
    }

    for (i = 0; i < 8; ++i) {
        if ((vs_main_scoredata.bossTimeTrialScores[i][0] & 0xFFFFFF) == 0x800000) {
            break;
        }
    }

    if (i == 8) {
        vs_main_scoredata.unk0 |= 0x400;
    }

    if (vs_main_scoredata.maxChain >= 30) {
        vs_main_scoredata.unk0 |= 0x800;
    }

    if (vs_main_stateFlags.unk383 != 0) {
        vs_main_scoredata.unk0 |= 0x1000;
    }

    if (vs_main_stateFlags.unk387 != 0) {
        vs_main_scoredata.unk0 |= 0x2000;
    }

    for (i = 0xB8; i < 0xE0; ++i) {
        if (!((vs_main_skills[i].flags >> 0xF) & 1)) {
            break;
        }
    }

    if (i == 0xE0) {
        vs_main_scoredata.unk0 |= 0x4000;
    }

    for (i = 0x16; i < 0x36; ++i) {
        if (((i != 0x21) && (i != 0x24) && (i != 0x26) && (i != 0x27)
                && !((vs_main_skills[i].flags >> 0xF) & 1))) {
            break;
        }
    }

    if (i == 0x36) {
        vs_main_scoredata.unk0 |= 0x8000;
    }

    for (i = 0; i < 6; ++i) {
        if (vs_main_scoredata.enemyKills[i] < 5000) {
            break;
        }
    }

    if (i == 6) {
        vs_main_scoredata.unk0 |= 0x100000;
    }

    for (i = 0; i < 10; ++i) {
        if (vs_main_scoredata.weaponAttacks[i] < 5000) {
            break;
        }
    }

    if (i == 0xA) {
        vs_main_scoredata.unk0 |= 0x200000;
    }

    for (i = 0; i < 9; ++i) {
        if (vs_main_scoredata.weaponAttacks[i + 1] >= 500) {
            vs_main_scoredata.unk0 |= 1 << (i + 0x16);
        }
    }

    if (vs_main_scoredata.weaponAttacks[0] >= 500) {
        vs_main_scoredata.unk0 |= 0x80000000;
    }
}

void func_80107A98(int arg0)
{
    int x;
    int clut;
    POLY_FT4* poly;
    void** scratch;
    int new_var;

    if (D_8010A45C == 0) {
        clut = getClut(896, 223);
        if (arg0 >= 2) {
            arg0 -= 2;
            clut = getClut(912, 223);
        }
        if (arg0 != 0) {
            func_800C6540("#R1", 0x62011E, 0x808080, NULL);
            if (D_8010A438 < 9) {
                x = (D_8010A438 >> 1) + 0x120;
            } else {
                x = -(D_8010A438 >> 2) + 0x126;
            }
        } else {
            func_800C6540("L1", 0x620022, 0x808080, NULL);
            if (D_8010A438 < 9) {
                new_var = 0x20;
                x = new_var - (D_8010A438 >> 1);
            } else {
                x = (D_8010A438 >> 2) + 0x1A;
            }
        }
        x -= 8;
        scratch = (void**)getScratchAddr(0);
        poly = scratch[0];
        setPolyFT4(poly);
        setXY4(poly, x, 0x60, x + 0x10, 0x60, x, 0x70, x + 0x10, 0x70);
        setUV4(poly, arg0 * 0x10, 0x30, (arg0 * 0x10) + 0x10, 0x30, arg0 * 0x10, 0x40,
            (arg0 * 0x10) + 0x10, 0x40);
        setTPage(poly, 0, 0, 768, 0);
        poly->clut = clut;
        setShadeTex(poly, 1);
        AddPrim(scratch[1], poly++);
        scratch[0] = poly;
    }
}

void func_80107C34(void)
{
    short classPoints[6] = { 20, 20, 40, 80, 100, 60 };
    short weaponClassPoints[10] = { 20, 40, 20, 100, 60, 100, 60, 100, 80, 60 };
    int i;

    _score = 0;

    for (i = 0; i < 6; ++i) {
        _score += vs_main_scoredata.enemyKills[i] * classPoints[i];
    }

    for (i = 0; i < 10; ++i) {
        _score += vs_main_scoredata.weaponAttacks[i] * weaponClassPoints[i];
    }

    for (i = 0; i < 8; ++i) {
        if ((vs_main_scoredata.bossTimeTrialScores[i][0] & 0xFFFFFF) != 0x800000) {
            _score += 0x4E20;
        }
    }

    if (vs_main_scoredata.maxChain < 6) {
        _score += vs_main_scoredata.maxChain * 10;
    } else if (vs_main_scoredata.maxChain < 11) {
        _score += vs_main_scoredata.maxChain * 20;
    } else if (vs_main_scoredata.maxChain < 16) {
        _score += vs_main_scoredata.maxChain * 40;
    } else if (vs_main_scoredata.maxChain < 21) {
        _score += vs_main_scoredata.maxChain * 80;
    } else if (vs_main_scoredata.maxChain < 26) {
        _score += vs_main_scoredata.maxChain * 160;
    } else if (vs_main_scoredata.maxChain < 31) {
        _score += vs_main_scoredata.maxChain * 320;
    } else if (vs_main_scoredata.maxChain < 51) {
        _score += vs_main_scoredata.maxChain * 640;
    } else {
        _score += vs_main_scoredata.maxChain * 1280;
    }

    _score = _score + (_clearCount * 100000);

    if ((_clearCount != 0) && (vs_main_scoredata.completionTimeMinutes < 600)) {
        if (vs_main_scoredata.completionTimeMinutes >= 540) {
            _score = _score + (_score >> 2);
        } else if (vs_main_scoredata.completionTimeMinutes >= 300) {
            _score = _score + (_score >> 1);
        } else {
            _score = _score * 2;
        }
    }

    _score = _score + vs_main_scoredata.streakScore;
    _score = _score + vs_main_scoredata.enemyKillStreak;
    if (_score > 999999999) {
        _score = 999999999;
    }
}
