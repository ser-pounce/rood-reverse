#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "lbas.h"
#include <stdio.h>
#include <libetc.h>
#include <libgpu.h>
#include <rand.h>
#include <string.h>

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    u_short unk4;
    u_short unk6;
} D_801091D8_t;

typedef struct {
    short unk0;
    short unk2;
} D_80109610_t;

int _loadRankDis(void);
int func_80102C54(void);
int func_8010310C(void);
int _loadAttackDis(void);
void func_80103748(void);
int func_801037A0(void);
int func_8010384C(void);
int func_80103D88(void);
int func_8010412C(void);
void func_8010459C(int arg0, int arg1, int arg2);
void func_80104650(int arg0, int arg1, int arg2);
void func_801046F8(int arg0, int arg1, int arg2);
void func_801047D4(int arg0, int arg1, int arg2);
void func_8010489C(int arg0, int arg1, int arg2);
void func_80104914(int);
void func_80104A50(int);
void func_80104B8C(int arg0, int arg1, int arg2);
void func_80104C40(int arg0, int arg1, int arg2, int arg3);
void func_80104DBC(int arg0, int arg1, int arg2, int arg3);
void func_80105020(int arg0, int arg1, int arg2, int arg3);
void func_8010516C(int arg0, int arg1, int arg2, int arg3);
void func_801053B0(int arg0, int arg1, int arg2);
void func_8010540C(int arg0, int arg1, int arg2);
void func_8010559C(int arg0, int arg1, int arg2);
void func_8010564C(int arg0, int arg1, int arg2);
void func_801056E8(int arg0, int arg1, int arg2);
void func_80105790(int, int, int);
void func_8010581C(int, int, int);
void func_801059B8(int arg0, int arg1, int arg2);
void func_801059FC(int arg0, int arg1, int arg2);
void func_80105B30(int arg0, int arg1, int arg2, int arg3);
void func_80105C34(int, int, int, int);
void func_80105DD8(int, int, int, int, int);
void func_80105F6C(int, int, int, int, int);
void func_801060A8(int, int, int, int);
void func_801064D4(int, int, int, int);
void func_8010664C(int, int, int, char*);
void func_80106A80(int, int, int, char*);
void func_80107140(int, int, int, char*, int);
int _loadIqDis(void);
void func_80107698(int arg0, int arg1, int arg2);
int func_80107D4C(void);
int _loadEscDis(void);
int func_80107FC0(void);
int func_801080E4(void);
int func_801083AC(void);
void func_801084F4(int arg0, int arg1);
void func_80108564(int arg0, int arg1);
void func_801085D4(int arg0, int arg1, int arg2);
void func_80108688(int arg0, int arg1, int arg2);
void func_8010873C(int arg0, int arg1, int arg2);
void func_80108784(int arg0, int arg1, int arg2);
void func_8010880C(int arg0, int arg1, int arg2, int arg3);
void func_8010887C(int arg0, int arg1, int arg2);
void _calculateScore(void);
void func_80108E38(void);
void func_80108E40(void);
void func_80108A0C(void);
int _getTotalStrength(void);
int _getTotalIntelligence(void);
int _getTotalAgility(void);
void func_80108E48(void);
void _nop(void);
void _raiseMaxStrength(int amount);
void _raiseMaxIntelligence(int amount);
void _raiseMaxAgility(int amount);
void _raiseMaxHP(int amount);
void _raiseMaxMP(int amount);

extern D_801091D8_t D_801091D8[];
extern char D_8010923A;
extern char D_8010941A;
extern char D_8010951A;
extern u_char D_801095D0[];
extern D_80109610_t D_80109610[][16];
extern int D_801096D0[];
extern int D_801096F0;
extern int D_80109700;
extern int D_80109710;
extern D_800F1A78_t D_80109720;
extern D_800F1A78_t D_80109724;
extern D_800F1A78_t D_80109728;
extern char D_8010972C[];
extern char D_80109738[];
extern char D_80109744[];
extern char D_8010974C[];
extern char D_80109754[];
extern char D_8010975C[];
extern char D_80109764[];
extern char D_8010976C;
extern char D_8010976F;
extern char D_80109774[];
extern char D_8010977C[];
extern int D_8010978C[];
extern char D_801097CC[];
extern char D_801097D8[];
extern char D_801097E4[];
extern short D_801097EC[];
extern u_int D_8010980C[];
extern vs_main_CdQueueSlot* D_80109854;
extern void* D_80109858;
extern int D_80109864;
extern vs_main_CdQueueSlot* _rankDataCdSlot;
extern void* _rankData;
extern vs_main_CdQueueSlot* _attackDisCdSlot;
extern void* _attackDisData;
extern vs_main_CdQueueSlot* _iqDisCdSlot;
extern void* _iqDisData;
extern vs_main_CdQueueSlot* _escDisCdSLot;
extern void* _escDisData;
extern u_int D_80109878;
extern int D_8010987C;
extern int _clearCount;
extern u_int _score;
extern u_int _mapCompletion;
extern u_int D_8010988C;
extern int D_80109890;
extern int D_80109894;
extern int D_80109898;
extern int D_8010989C;
extern int D_801098A0;
extern int D_801098A4;
extern int D_801098A8;
extern u_short D_801098AC[0x70];
extern int D_801099EC;
extern int D_801099F0;
extern short D_801099F4;
extern short D_801099F6;

int func_80102BB8(char* arg0)
{
    switch (*arg0) {
    case 0:
        *arg0 = 1;
        // Fallthrough
    case 1:
        *arg0 += (func_80102C54() != 0);
        break;
    case 2:
        if (func_801037A0() != 0) {
            *arg0 = 0;
            return 1;
        }
        break;
    }
    return 0;
}

#include "../unused_vertices.h"

enum _disFileIndices { rankDis, timeDis, attackDis, iqDis, escDis };

static vs_main_CdFile const _disFiles[] = { { VS_RANK_DIS_LBA, VS_RANK_DIS_SIZE },
    { VS_TIME_DIS_LBA, VS_TIME_DIS_SIZE }, { VS_ATTACK_DIS_LBA, VS_ATTACK_DIS_SIZE },
    { VS_IQ_DIS_LBA, VS_IQ_DIS_SIZE }, { VS_ESC_DIS_LBA, VS_ESC_DIS_SIZE } };

int func_80102C54(void)
{
    int ret;

    switch (vs_main_stateFlags.unkB6) {
    case 0:
        ret = _loadRankDis();
        break;
    case 1:
        ret = _loadAttackDis();
        break;
    case 2:
        ret = func_8010310C();
        break;
    case 3:
        func_80108E48();
        _nop();
        ret = 1;
        break;
    case 4:
        ret = _loadIqDis();
        break;
    case 5:
        ret = func_80107D4C();
        break;
    case 6:
        ret = _loadEscDis();
        break;
    }
    return ret;
}

int _loadRankDis(void)
{
    func_80103530_t sp10;
    int temp_s0;
    int temp_s1;
    int temp_v1;
    int var_a0;
    int i;
    int mapCompletion;
    u_int var_v1;

    if (D_800F1CD8 == 0) {
        func_8007DFF0(0x1D, 3, 5);
        _rankData = vs_main_allocHeapR(_disFiles[rankDis].size);
        _rankDataCdSlot = vs_main_allocateCdQueueSlot(&_disFiles[rankDis]);
        vs_main_cdEnqueue(_rankDataCdSlot, _rankData);
        ++D_800F1CD8;
    } else if (D_800F1CD8 == 1) {
        if (_rankDataCdSlot->state == vs_main_CdQueueStateLoaded) {
            for (i = 0; i < 3; ++i) {
                func_8008D820(_rankData + i * 0x8220, &sp10);
                if (sp10.unk10 != NULL) {
                    sp10.unkC->x = 0x340 + i * 0x40;
                    sp10.unkC->y = 0x100;
                    sp10.unkC->h = 0xFF;
                    LoadImage(sp10.unkC, (u_long*)sp10.unk10);
                }
                if (i == 0) {
                    if (sp10.unk8 != NULL) {
                        sp10.unk4->x = 0x300;
                        sp10.unk4->y = 0x1FF;
                        sp10.unk4->w = 0x80;
                        sp10.unk4->h = 1;
                        *sp10.unk8 = 0;
                        LoadImage(sp10.unk4, sp10.unk8);
                    }
                }
            }
            vs_main_freeCdQueueSlot(_rankDataCdSlot);
            func_80103748();
            ++D_800F1CD8;
        }
    } else if (vs_main_clearMusicLoadQueue() == 0) {
        func_80045000(2, 0x7F, 0);
        vs_main_freeHeapR(_rankData);
        D_80109894 = 0;
        D_80109898 = 0;
        D_8010989C = 0;
        D_801098A0 = 0;
        D_8010988C = 0;
        D_80109878 = (rand() & 0xF0) | 8;
        temp_s0 = _getTotalStrength();
        temp_s1 = _getTotalIntelligence();
        temp_v1 = _getTotalAgility();
        if ((temp_s1 >= temp_s0) && (temp_v1 >= temp_s0)) {
            D_80109890 = 0;
        } else if (temp_s0 >= temp_s1) {
            if (temp_v1 >= temp_s1) {
                D_80109890 = 1;
            } else {
                D_80109890 = 2;
            }
        } else {
            D_80109890 = 2;
        }

        D_800F1CD8 = 0;
        func_80108E48();
        _clearCount = vs_main_stateFlags.clearCount;

        if (vs_main_mapStatus.roomFlags[1] & 0x800000) {
            vs_main_mapStatus.roomFlags[1] |= 0x400000;
        }

        mapCompletion = 0;

        for (i = 0; i < 16; ++i) {
            for (var_a0 = 0; var_a0 < 32; ++var_a0) {
                int v = 1;
                if (vs_main_mapStatus.roomFlags[i] & vs_battle_mapCompletionFlags[i]
                    & (v << var_a0)) {
                    ++mapCompletion;
                }
            }
        }

        var_v1 = 0;

        for (i = 0; i < 64; ++i) {
            if (vs_main_stateFlags.unk3C0[i] != 0) {
                ++var_v1;
            }
        }

        if (vs_main_scoredata.mapCompletion < mapCompletion) {
            vs_main_scoredata.mapCompletion = mapCompletion;
        }
        if (vs_main_scoredata.unk98 < var_v1) {
            vs_main_scoredata.unk98 = var_v1;
        }
        _mapCompletion = (mapCompletion * 100) / 361;
        _calculateScore();
        func_80108A0C();
        return 1;
    }
    return 0;
}

int func_8010310C(void)
{
    func_80103530_t sp10;
    int temp_s0;
    int var_a3;
    int i;

    temp_s0 = D_800F1CD8;
    if (temp_s0 == 0) {
        func_8007DFF0(0x1D, 1, 5);
        D_80109858 = vs_main_allocHeapR(_disFiles[1].size);
        D_80109854 = vs_main_allocateCdQueueSlot(&_disFiles[1]);
        vs_main_cdEnqueue(D_80109854, D_80109858);
        ++D_800F1CD8;
    } else if (temp_s0 == 1) {
        if (D_80109854->state == 4) {
            func_8008D820(D_80109858, &sp10);
            if (sp10.unk10 != NULL) {
                sp10.unkC->x = 0x340;
                sp10.unkC->y = 0x100;
                sp10.unkC->h = 0xFF;
                LoadImage(sp10.unkC, (u_long*)sp10.unk10);
            }
            if (sp10.unk8 != NULL) {
                sp10.unk4->x = 0x300;
                sp10.unk4->y = 0x1FF;
                sp10.unk4->w = 0xA0;
                sp10.unk4->h = temp_s0;
                *sp10.unk8 = 0;
                LoadImage(sp10.unk4, sp10.unk8);
                vs_main_memcpy(D_801098AC, sp10.unk8, 0x140U);
            }
            vs_main_freeCdQueueSlot(D_80109854);
            func_80103748();
            ++D_800F1CD8;
        }
    } else if (vs_main_clearMusicLoadQueue() == 0) {
        func_80045000(2, 0x7F, 0);
        D_801098A8 = (vs_main_stateFlags.unkC5 << 0x10) | (vs_main_stateFlags.unkC6 << 8)
                   | vs_main_stateFlags.unkC7;
        if (D_801098A8 == 0) {
            D_801098A8 = 0x3B3B63;
        }

        for (i = 0; i < 3; ++i) {
            if ((vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.unkC4][i]
                        .time.unk0)
                < D_801098A8) {
                continue;
            }
            for (var_a3 = 2; i < var_a3; --var_a3) {
                vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.unkC4][var_a3]
                    .time.unk0 =
                    vs_main_scoredata
                        .bossTimeTrialScores[vs_main_stateFlags.unkC4][var_a3 - 1]
                        .time.unk0;
                vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.unkC4][var_a3]
                    .time.unk24 =
                    vs_main_scoredata
                        .bossTimeTrialScores[vs_main_stateFlags.unkC4][var_a3 - 1]
                        .time.unk24;
                vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.unkC4][var_a3]
                    .time.unk31 =
                    vs_main_scoredata
                        .bossTimeTrialScores[vs_main_stateFlags.unkC4][var_a3 - 1]
                        .time.unk31;
            }
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.unkC4][i].time.unk0 =
                D_801098A8;
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.unkC4][i]
                .time.unk24 = vs_main_stateFlags.clearCount;
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.unkC4][i]
                .time.unk31 = vs_main_stateFlags.unk1;
            break;
        }
        D_801098A4 = i;
        D_8010989C = 0;
        D_801098A0 = 0;
        D_8010988C = 0;
        D_800F1CD8 = 0;
        vs_main_freeHeapR(D_80109858);
        return 1;
    }
    return 0;
}

int _loadAttackDis(void)
{
    if (D_800F1CD8 == 0) {
        func_8007DFF0(0x1D, 2, 5);
        _attackDisData = vs_main_allocHeapR(_disFiles[attackDis].size);
        _attackDisCdSlot = vs_main_allocateCdQueueSlot(&_disFiles[attackDis]);
        vs_main_cdEnqueue(_attackDisCdSlot, _attackDisData);
        ++D_800F1CD8;
    } else if (D_800F1CD8 == 1) {
        if (_attackDisCdSlot->state == vs_main_CdQueueStateLoaded) {
            int i;
            func_80103530_t sp10;
            for (i = 0; i < 2; ++i) {
                func_8008D820(_attackDisData + i * 0x8220, &sp10);
                if (sp10.unk10 != NULL) {
                    sp10.unkC->x = 0x340 + i * 0x40;
                    sp10.unkC->y = 0x100;
                    sp10.unkC->h = 0xFF;
                    LoadImage(sp10.unkC, (u_long*)sp10.unk10);
                }
                if (i == 0) {
                    if (sp10.unk8 != NULL) {
                        sp10.unk4->x = 0x300;
                        sp10.unk4->y = 0x1FF;
                        sp10.unk4->w = 0xA0;
                        sp10.unk4->h = 1;
                        sp10.unk8[0] = 0;
                        LoadImage(sp10.unk4, sp10.unk8);
                    }
                }
            }
            vs_main_freeCdQueueSlot(_attackDisCdSlot);
            ++D_800F1CD8;
        }
    } else {
        vs_main_freeHeapR(_attackDisData);
        D_80109894 = 0;
        D_80109898 = 0;
        D_8010989C = 0;
        D_801098A0 = 0;
        D_8010988C = 0;
        D_80109878 = 0;
        D_800F1CD8 = 0;
        return 1;
    }
    return 0;
}

void func_80103748(void)
{
    if ((D_8005E040 != 7) && (((D_8005E040 - 0x1F) < 9) || ((D_8005E040 - 0x2D) < 5))) {
        vs_main_loadMusicSlot(D_8005E040 + 0x64, 2);
    } else {
        vs_main_loadMusicSlot(0x80, 2);
    }
}

int func_801037A0(void)
{
    int ret;

    switch (vs_main_stateFlags.unkB6) {
    case 0:
        ret = func_8010384C();
        break;
    case 1:
        ret = func_8010412C();
        break;
    case 2:
        ret = func_80103D88();
        break;
    case 3:
        ret = 1;
        break;
    case 4:
        ret = func_80107FC0();
        break;
    case 5:
        ret = func_801080E4();
        break;
    case 6:
        ret = func_801083AC();
        break;
    }
    // BUG: potential garbage
    return ret;
}

int func_8010384C(void)
{
    int temp_a0;
    int temp_a2_2;
    int temp_v1;

    if (D_801098A0 != 3) {
        if (D_8010989C == 0xD0) {
            vs_main_playSfxDefault(0x7E, 0x77);
            vs_main_playSfxDefault(0x7E, 0x78);
        }
        func_80104B8C(0xA0, 0x28, D_8010989C);
        func_80104DBC(0xA0, 0x50, D_8010989C - 0x20, D_801098A0);
        func_8010516C(0xA0, 0x66, D_8010989C - 0x70, D_801098A0);
        func_801053B0(0xA0, 0x8A, D_8010989C - 0xC0);
        func_8010540C(0xA0, 0x9A, D_8010989C - 0xD0);
        func_801060A8(0x82, 0xBE, D_8010989C - 0x110, D_801098A0);
    }

    if (D_801098A0 == 0) {
        D_80109878 = (D_80109878 + (D_8010988C >> 3)) & 0xFF;
        if ((D_8010989C - 0x110) > 0) {
            if (D_8010988C == 8) {
                vs_main_playSfxDefault(0x7E, 0x74);
                vs_main_playSfxDefault(0x7E, 0x75);
            }
            if (D_8010988C < 0x30) {
                if (D_8010989C >= 0x121) {
                    ++D_8010988C;
                    func_801064D4(0xD6, 0xBB, D_8010988C, D_8010989C);
                }
            } else {
                if ((vs_main_buttonsPressed.all & PADRright) || D_8010989C >= 0x819) {
                    if (vs_main_buttonsPressed.all & PADRright) {
                        vs_main_playSfxDefault(0x7E, 0x76);
                    }
                    D_801098A0 = 1;
                    D_80109864 = 0;
                    func_80045BFC(0x7E, 0x74, 0x40, 0x30);
                    func_80045BFC(0x7E, 0x75, 0x40, 0x30);
                    func_80045C74(0x7E, 0x74, -0x10, 0x30);
                    func_80045C74(0x7E, 0x75, -0x10, 0x30);
                }
                func_801064D4(0xD6, 0xBB, 0x30, D_8010989C);
            }
        } else if (vs_main_buttonsPressed.all & PADRright) {
            func_80045D64(0x7E, 0);
            D_8010989C = 0x110;
            D_801099EC = 0;
            D_801099F0 = 0;
            D_80109894 = _mapCompletion;
            D_80109898 = _score;
        }
    } else if (D_801098A0 == 1) {
        temp_a2_2 = 0x30 - D_80109864;
        if (temp_a2_2 > 0) {
            func_801064D4(0xD6, 0xBB, temp_a2_2, D_8010989C);
        }
        temp_v1 = D_80109878 + (D_8010988C >> 3);
        D_80109878 = temp_v1 & 0xFF;
        if (D_8010988C >= 9) {
            --D_8010988C;
        }
        temp_v1 = temp_v1 & 0xF;
        if ((temp_v1 == 8) && (D_8010988C == temp_v1)) {
            func_80045D64(0x7E, 0x74);
            func_80045D64(0x7E, 0x75);
            vs_main_playSfxDefault(0x7E, 0x77);
            vs_main_playSfxDefault(0x7E, 0x78);
            D_801098A0 = 2;
            D_80109864 = 0;
        }
    } else if (D_801098A0 == 2) {
        if ((vs_main_buttonsPressed.all & PADRright) || (D_80109864 >= 451)) {
            D_801098A0 = 3;
            D_80109864 = 0;
        }
    } else {
        func_80104B8C(0xA0, 0x28, 8 - D_80109864);
        func_80104C40(0xA0, 0x50, 8 - D_80109864, 3);
        func_80105020(0xA0, 0x66, 8 - D_80109864, 3);
        func_801053B0(0xA0, 0x8A, 8 - D_80109864);
        func_8010540C(0xA0, 0x9A, 8 - D_80109864);
        func_801060A8(0x82, 0xBE, 8 - D_80109864, 3);
        if (D_80109864 >= 8) {
            temp_a0 = D_80109610[D_80109890][(char)D_80109878 >> 4].unk2;
            switch ((short)(D_80109610[D_80109890][(char)D_80109878 >> 4].unk0 - 0xD)) {
            case 0:
                _raiseMaxStrength(temp_a0);
                break;
            case 1:
                _raiseMaxAgility(temp_a0);
                break;
            case 2:
                _raiseMaxIntelligence(temp_a0);
                break;
            case 3:
                _raiseMaxHP(temp_a0);
                break;
            case 4:
                _raiseMaxMP(temp_a0);
                break;
            }
            func_8007E0A8(0x1D, 3, 5);
            _nop();
            return 1;
        }
    }
    ++D_80109864;
    ++D_8010989C;
    return 0;
}

int func_80103D88(void)
{
    int var_v0;

    var_v0 = rsin(D_8010988C);
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    if (var_v0 <= -1) {
        var_v0 += 0xFF;
    }
    func_80104914(var_v0 >> 8);
    D_8010988C = (D_8010988C + 0x40) & 0xFFF;
    if (D_801098A0 == 0) {
        if (D_8010989C == 0x30) {
            vs_main_playSfxDefault(0x7E, 0x72);
        }
        if (D_8010989C == 0x60) {
            func_80045D64(0x7E, 0x72);
            vs_main_playSfxDefault(0x7E, 0x73);
        }
        func_8010559C(0xA0, 0x34, D_8010989C);
        func_8010581C(0x10, 0xA4, D_8010989C - 0x20);
        func_801056E8(0x10, 0x90, D_8010989C - 0x60);
        if (D_801098A4 == 0) {
            func_801059B8(0x46, 0xB8, D_8010989C - 0x80);
        }
        if ((D_8010989C == 0x80) && (D_801098A4 == 0)) {
            vs_main_playSfxDefault(0x7E, 0x76);
        }
        if (D_8010989C == 0xA0) {
            vs_main_playSfxDefault(0x7E, 0x73);
        }
        if (D_8010989C == 0xA8) {
            vs_main_playSfxDefault(0x7E, 0x73);
        }
        if (D_8010989C == 0xB0) {
            vs_main_playSfxDefault(0x7E, 0x73);
        }
        func_80105B30(0x130, 0x90, 0, D_8010989C - 0xA0);
        func_80105B30(0x130, 0x90, 1, D_8010989C - 0xA8);
        func_80105B30(0x130, 0x90, 2, D_8010989C - 0xB0);
        ++D_8010989C;
        if ((vs_main_buttonsPressed.all & 0x20) || (D_8010989C >= 0xC0)) {
            func_80045D64(0x7E, 0);
            D_8010989C = 0;
            ++D_801098A0;
        }
    } else if (D_801098A0 == 1) {
        func_8010559C(0xA0, 0x34, 0x40);
        func_80105790(0x10, 0xA4, 0x40);
        func_8010564C(0x10, 0x90, 0x40);
        if (D_801098A4 == 0) {
            func_801059B8(0x46, 0xB8, 0x40);
        }
        func_801059FC(0x130, 0x90, 0x40);
        ++D_8010989C;
        if ((vs_main_buttonsPressed.all & PADRright) || (D_8010989C >= 0x1C2)) {
            if (vs_main_buttonsPressed.all & PADRright) {
                vs_main_playSfxDefault(0x7E, 5);
            }
            ++D_801098A0;
            D_8010989C = 7;
        }
    } else if (D_801098A0 == 2) {
        func_8010559C(0xA0, 0x34, D_8010989C);
        func_80105790(0x10, 0xA4, D_8010989C);
        func_8010564C(0x10, 0x90, D_8010989C);
        if (D_801098A4 == 0) {
            func_801059B8(0x46, 0xB8, D_8010989C);
        }
        func_801059FC(0x130, 0x90, D_8010989C);
        if (D_8010989C > 0) {
            --D_8010989C;
        } else {
            ++D_801098A0;
        }
    } else {
        func_8007E0A8(0x1D, 1, 5);
        return 1;
    }
    return 0;
}

int func_8010412C(void)
{
    int temp_v1_2;
    int var_a3;

    if (D_801098A0 == 0) {
        if ((D_8010989C == ((D_8010989C / 15) * 0xF)) && (D_8010989C < 0x2E)) {
            vs_main_playSfxDefault(0x7E, 0x7A);
            vs_main_playSfxDefault(0x7E, 0x7B);
            vs_main_playSfxDefault(0x7E, 0x7C);
        }
        func_8010459C(0xA0, 0x30, D_8010989C);
        func_80104650(0xA0, 0x5C, D_8010989C - 0xF);
        func_801046F8(0xA0, 0x78, D_8010989C - 0x1E);
        func_801047D4(0xA0, 0x9C, D_8010989C - 0x2D);
        ++D_8010989C;
        if (vs_main_buttonsPressed.all & 0x20) {
            D_801098A0 = 2;
            D_8010989C = 0;
        } else if (D_8010989C >= 0x5A) {
            D_801098A0 = 1;
            D_8010989C = 8;
        }
    } else if (D_801098A0 == 1) {
        --D_8010989C;
        func_8010459C(0xA0, 0x30, D_8010989C);
        func_80104650(0xA0, 0x5C, D_8010989C);
        func_801046F8(0xA0, 0x78, D_8010989C);
        func_801047D4(0xA0, 0x9C, D_8010989C);
        if ((vs_main_buttonsPressed.all & 0x20) || (D_8010989C == 0)) {
            D_801098A0 = 2;
            D_8010989C = 0;
        }
    } else if (D_801098A0 == 2) {
        func_8007C36C(4);
        func_8007DDAC(0);
        func_8007DDB8(&D_801096F0);
        func_8007DDD4(&D_80109724);
        func_8007DDF8((D_800F1A68_t*)(&D_801096F0 + 8));
        func_8007DE2C(0);
        func_8007DE44(0U);
        func_8007DE5C(0);
        func_8007DD50(1);
        ++D_801098A0;
    } else if (D_801098A0 == 3) {
        temp_v1_2 = D_8010989C / 15;
        if (D_8010989C == (temp_v1_2 * 0xF)) {
            switch (temp_v1_2) {
            case 0:
            case 1:
            case 2:
                vs_main_playSfxDefault(0x7E, 0x7D);
                vs_main_playSfxDefault(0x7E, 0x7E);
                vs_main_playSfxDefault(0x7E, 0x7F);
                break;
            case 3:
                vs_main_playSfxDefault(0x7E, 0x80);
                vs_main_playSfxDefault(0x7E, 0x81);
                vs_main_playSfxDefault(0x7E, 0x82);
                break;
            }
        }
        if (D_8010989C >= 0x2D) {
            if (D_8010989C == 0x2D) {
                func_8007DE2C(1);
                func_8007DDB8(&D_80109700);
                func_8007DDD4(&D_80109720);
            } else if (D_8010989C == 0x2E) {
                func_8007DE2C(0);
            } else if (D_8010989C == 0x37) {
                func_8007DDD4(&D_80109728);
            } else if (D_8010989C == 0x3C) {
                func_8007DDB8(&D_801096F0);
            }
            var_a3 = 0x68 - D_8010989C;
            if (var_a3 < 0x2D) {
                var_a3 = 0x2D;
            }
            func_8010489C(0xA0, 0x78, var_a3);
        } else {
            var_a3 = D_8010989C % 15;
            if (var_a3 > 7) {
                var_a3 = 7;
            }
            var_a3 = D_801096D0[var_a3];
            func_8010489C(var_a3 + 0xA0, 0x78, D_8010989C);
        }
        ++D_8010989C;
        if (D_8010989C >= 0x3E) {
            ++D_801098A0;
        }
    } else if (D_801098A0 == 4) {
        func_8007C36C(2);
        func_8007DDB8(&D_80109710);
        func_8007DD50(0);
        func_8007E0A8(0x1D, 2, 5);
        return 1;
    }
    return 0;
}

void func_8010459C(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_8010972C[3] = arg2;
        D_8010972C[7] = arg2;
        arg0 -= (D_801091D8[100].unk2 + D_801091D8[101].unk2) >> 1;
        func_80106A80(arg0, arg1, 0x64, D_8010972C);
        func_80106A80(arg0 + D_801091D8[100].unk2, arg1, 0x65, D_8010972C + 4);
    }
}

void func_80104650(int arg0, int arg1, int arg2)
{
    int new_var;

    if (arg2 > 0x40) {
        arg2 = 0x40;
    }

    if (arg2 > 0) {
        arg0 -= (D_801091D8[84].unk2 + 0x18) >> 1;
        func_80105C34(arg0, arg1, 0x54, arg2);
        new_var = arg0 + 0xC;
        func_80105DD8(new_var + D_801091D8[84].unk2, arg1 - 1,
            vs_main_stateFlags.unkC4 + 1, arg2, 0x7FF4);
    }
}

void func_801046F8(int arg0, int arg1, int arg2)
{
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        if (vs_main_stateFlags.unkC4 != 6) {
            func_80105C34(arg0 - (D_801091D8[vs_main_stateFlags.unkC4 + 0x55].unk2 >> 1),
                arg1, vs_main_stateFlags.unkC4 + 0x55, arg2);
        } else {
            arg0 -= (D_801091D8[91].unk2 + D_801091D8[93].unk2) >> 1;
            func_80105C34(arg0, arg1, 0x5B, arg2);
            arg0 += D_801091D8[91].unk2;
            func_80105C34(arg0, arg1, 0x5D, arg2);
        }
    }
}

void func_801047D4(int arg0, int arg1, int arg2)
{
    int new_var;
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        arg0 -= (D_801091D8[95].unk2 + 0x60) >> 1;
        func_80105C34(arg0, arg1, 0x5F, arg2);
        arg0++;
        new_var = arg0 + 0xB;
        func_80105F6C(new_var + D_801091D8[95].unk2, arg1 + 2, arg2,
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.unkC4][0].time.unk0,
            0);
    }
}

void func_8010489C(int arg0, int arg1, int arg2)
{
    int temp_a2 = (arg2 / 15) + 0x60;
    func_80105C34(arg0 - (D_801091D8[temp_a2].unk2 >> 1),
        arg1 - (D_801091D8[temp_a2].unk3 >> 1), temp_a2, arg2 % 15);
}

// https://decomp.me/scratch/UJOBa
INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104914);

// https://decomp.me/scratch/ZDcyC
INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104A50);

void func_80104B8C(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109738[3] = arg2;
        D_80109738[7] = arg2;
        arg0 -= (D_801091D8[22].unk2 + D_801091D8[23].unk2) >> 1;
        func_80106A80(arg0, arg1, 0x16, D_80109738);
        func_80106A80(arg0 + D_801091D8[22].unk2, arg1, 0x17, D_80109738 + 4);
    }
}

void func_80104C40(int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    char buf[16];
    int i;
    int new_var;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 >= 0x41) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109744[3] = arg2;
        sprintf(buf, "%09d", _score);
        new_var = D_801091D8[18].unk2 + D_801091D8[26].unk2;
        arg0 -=
            (((D_801091D8[10].unk2 * 2) + (new_var + D_801091D8[20].unk2)) + 0x74) >> 1;
        func_8010664C(arg0, arg1, 0x12, D_80109744);
        arg0 += D_801091D8[18].unk2;
        func_8010664C(arg0, arg1 + 7, 0x1A, D_80109744);
        i = 2;
        arg0 = (arg0 + i) + D_801091D8[26].unk2;

        for (i = 0; i < 9; ++i) {
            func_8010664C(arg0, arg1 + 3, buf[i] - '0', D_80109744);
            arg0 += 0xC;
            if ((i == 2) || (i == 5)) {
                func_8010664C(arg0, arg1 + 0xE, 0xA, D_80109744);
                arg0 += D_801091D8[10].unk2 + 3;
            }
        }

        func_8010664C(arg0, arg1 + 8, 0x14, D_80109744);
    }
}

void func_80104DBC(int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    char buf[16];
    int temp_s2;
    int i;
    int v;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 >= 0x41) {
        arg2 = 0x40;
    }
    if (arg2 <= 0) {
        return;
    }

    temp_s2 = arg0 + (arg2 * 8);

    if (_score != 0) {
        if (arg2 >= 0x20) {
            if (D_80109898 == 0) {
                D_801099EC = 1;
                vs_main_playSfxDefault(0x7E, 0x72);
            }
            if (D_80109898 == _score) {
                if (D_801099EC != 0) {
                    D_801099EC = 0;
                    func_80045D64(0x7E, 0x72);
                    vs_main_playSfxDefault(0x7E, 0x73);
                }
            }
        }
    }
    if (arg2 >= 0x20) {
        D_80109898 = (_score >> 5) * (arg2 - 0x20);
    }
    if (arg2 == 0x40) {
        D_80109898 = _score;
    }

    sprintf(buf, "%09d", D_80109898);
    v = D_801091D8[18].unk2 + D_801091D8[26].unk2 + D_801091D8[20].unk2;
    arg0 -= (((D_801091D8[10].unk2 * 2) + v) + 0x74) >> 1;
    func_80107140(arg0, arg1, 0x12, D_8010974C, temp_s2);
    arg0 += D_801091D8[18].unk2;
    func_80107140(arg0, arg1 + 7, 0x1A, D_8010974C, temp_s2);
    i = 2;
    arg0 = arg0 + i + D_801091D8[26].unk2;
    for (i = 0; i < 9; ++i) {
        func_80107140(arg0, arg1 + 3, buf[i] - '0', D_8010974C, temp_s2);
        arg0 += 0xC;
        if ((i == 2) || (i == 5)) {
            func_80107140(arg0, arg1 + 0xE, 0xA, D_8010974C, temp_s2);
            arg0 += 3 + D_801091D8[10].unk2;
        }
    }
    func_80107140(arg0, arg1 + 8, 0x14, D_8010974C, temp_s2);
}

void func_80105020(int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    char buf[4];
    int i;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109754[3] = arg2;
        sprintf(buf, "%03d", _mapCompletion);
        arg0 -=
            (D_801091D8[21].unk2 + D_801091D8[26].unk2 + D_801091D8[19].unk2 + 0x26) >> 1;
        i = 2;
        func_8010664C(arg0, arg1, 0x15, D_80109754);
        arg0 += D_801091D8[21].unk2;
        func_8010664C(arg0, arg1 + 7, 0x1A, D_80109754);
        arg0 = arg0 + i + D_801091D8[26].unk2;

        for (i = 0; i < 3; ++i) {
            func_8010664C(arg0, arg1 + 3, buf[i] - '0', D_80109754);
            arg0 += 0xC;
        }

        func_8010664C(arg0, arg1 + 8, 0x13, D_80109754);
    }
}

void func_8010516C(int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    char buf[8];
    int temp_s4;
    int i;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 <= 0) {
        return;
    }

    temp_s4 = arg0 + (arg2 * 8);

    if (_mapCompletion != 0) {
        if (arg2 >= 0x20) {
            if (D_80109894 == 0) {
                D_801099F0 = 1;
                vs_main_playSfxDefault(0x7E, 0x72);
            }
            if (D_80109894 == _mapCompletion) {
                if (D_801099F0 != 0) {
                    D_801099F0 = 0;
                    func_80045D64(0x7E, 0x72);
                    vs_main_playSfxDefault(0x7E, 0x73);
                }
            }
        }
    }
    if (arg2 >= 0x20) {
        if (_mapCompletion >= 0x20) {
            D_80109894 = (_mapCompletion * (arg2 - 0x20)) >> 5;
        } else if (D_80109894 < _mapCompletion) {
            ++D_80109894;
        }
    }

    sprintf(buf, "%03d", D_80109894);
    arg0 -= (D_801091D8[21].unk2 + D_801091D8[26].unk2 + D_801091D8[19].unk2 + 0x26) >> 1;
    func_80107140(arg0, arg1, 0x15, D_8010975C, temp_s4);
    arg0 += D_801091D8[21].unk2;
    i = 2;
    func_80107140(arg0, arg1 + 7, 0x1A, D_8010975C, temp_s4);
    arg0 = arg0 + i + D_801091D8[26].unk2;

    for (i = 0; i < 3; ++i) {
        func_80107140(arg0, arg1 + 3, buf[i] - '0', D_8010975C, temp_s4);
        arg0 += 0xC;
    }
    func_80107140(arg0, arg1 + 8, 0x13, D_8010975C, temp_s4);
}

void func_801053B0(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109764[3] = arg2;
        func_8010664C(arg0 - (D_8010923A >> 1), arg1, 0xC, D_80109764);
    }
}

void func_8010540C(int arg0, int arg1, int arg2)
{
    int var_a0;
    int i;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 >= 0x41) {
        arg2 = 0x40;
    }

    var_a0 = 0;
    if (arg2 > 0) {
        D_8010976F = arg2;
        for (i = 0; i < D_801095D0[D_8010987C * 4]; ++i) {
            var_a0 += D_801091D8[D_801095D0[i + 1 + (D_8010987C * 4)]].unk2;
        }

        var_a0 /= 2;
        arg0 -= var_a0;
        for (i = 0; i < D_801095D0[D_8010987C * 4]; ++i) {
            int new_var2 = 1;
            func_80106A80(
                arg0, arg1, D_801095D0[i + (D_8010987C * 4 + new_var2)], &D_8010976C);
            arg0 += D_801091D8[D_801095D0[i + (D_8010987C * 4 + new_var2)]].unk2;
        }
    }
}

void func_8010559C(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109774[3] = arg2;
        arg0 -= (D_801091D8[70].unk2 + D_801091D8[71].unk2) >> 1;
        func_80106A80(arg0, arg1, 0x46, D_80109774);
        func_80106A80(arg0 + D_801091D8[70].unk2, arg1, 0x47, D_80109774);
    }
}

void func_8010564C(int arg0, int arg1, int arg2)
{
    int var_a2;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 <= 0) {
        return;
    }
    if (D_801098A8 < 0x1E00) {
        var_a2 = 0;
    } else if (D_801098A8 <= 0xFFFF) {
        var_a2 = 1;
    } else if (D_801098A8 <= 0x11DFF) {
        var_a2 = 2;
    } else if (D_801098A8 <= 0x1FFFF) {
        var_a2 = 3;
    } else {
        var_a2 = 4;
    }
    func_80105C34(arg0, arg1, var_a2 + 0x4E, arg2);
}

void func_801056E8(int arg0, int arg1, int arg2)
{
    int arg3;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 <= 0) {
        return;
    }

    arg3 = arg0 + (arg2 * 8);

    if (D_801098A8 < 0x1E00) {
        arg2 = 0;
    } else if (D_801098A8 <= 0xFFFF) {
        arg2 = 1;
    } else if (D_801098A8 <= 0x11DFF) {
        arg2 = 2;
    } else if (D_801098A8 <= 0x1FFFF) {
        arg2 = 3;
    } else {
        arg2 = 4;
    }
    func_80107140(arg0, arg1, arg2 + 0x4E, D_8010977C, arg3);
}

void func_80105790(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        func_80105C34(arg0, arg1, 0x48, arg2);
        arg0 += D_8010941A;
        func_80105F6C(arg0, arg1 + 2, arg2, D_801098A8, 0);
    }
}

// https://decomp.me/scratch/2GyJv
INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010581C);

void func_801059B8(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        func_80105C34(arg0, arg1, 0x45, arg2);
    }
}

void func_801059FC(int arg0, int arg1, int arg2)
{
    int temp_v0;
    int i;
    int var_s3;

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 >= 0x41) {
        arg2 = 0x40;
    }

    for (i = 0; i < 3; ++i) {
        var_s3 = 0x7FF2;
        temp_v0 = D_801098A4 == i;
        if (temp_v0 != 0) {
            var_s3 = 0x7FF8;
        }
        func_80105F6C(arg0 - 0x54, arg1 + i * 0x14 + 2, arg2,
            vs_main_scoredata.bossTimeTrialScores[0][vs_main_stateFlags.unkC4 * 3 + i]
                .time.unk0,
            temp_v0);
        func_80105DD8((arg0 - D_801091D8[75 + i].unk2) - 0x58, arg1 + i * 0x14, i + 0x4B,
            arg2, var_s3);
    }
}

void func_80105B30(int arg0, int arg1, int arg2, int arg3)
{
    int temp_t1;
    int var_s3;

    if (arg3 < 0) {
        arg3 = 0;
    }
    if (arg3 >= 0x41) {
        arg3 = 0x40;
    }
    temp_t1 = D_801098A4 == arg2;
    var_s3 = 0x7FF2;
    if (temp_t1 != 0) {
        var_s3 = 0x7FF8;
    }

    func_80105F6C(arg0 - 0x54, arg1 + (arg2 * 0x14) + 2, arg3,
        vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.unkC4][arg2].time.unk0,
        temp_t1);
    func_80105DD8((arg0 - D_801091D8[arg2 + 0x4B].unk2) - 0x58, arg1 + (arg2 * 0x14),
        arg2 + 0x4B, arg3, var_s3);
}

void func_80105C34(int arg0, int arg1, int arg2, int arg3)
{
    D_801091D8_t* temp_a2;
    POLY_FT4* poly;
    void** scratch;

    if (arg3 <= 0) {
        return;
    }

    poly = *(void**)getScratchAddr(0);
    temp_a2 = &D_801091D8[arg2];
    setPolyFT4(poly);
    setXY4(poly, arg0, arg1, temp_a2->unk2 + arg0, arg1, arg0, temp_a2->unk3 + arg1,
        temp_a2->unk2 + arg0, temp_a2->unk3 + arg1);
    setUV4(poly, temp_a2->unk0, temp_a2->unk1, temp_a2->unk0 + temp_a2->unk2,
        temp_a2->unk1, temp_a2->unk0, temp_a2->unk1 + temp_a2->unk3,
        temp_a2->unk0 + temp_a2->unk2, temp_a2->unk1 + temp_a2->unk3);
    setSemiTrans(poly, 1);

    if (arg3 < 8) {
        setRGB0(poly, arg3 * 0x10, arg3 * 0x10, arg3 * 0x10);
        poly->tpage = temp_a2->unk4 | 0x20;
        poly->clut = temp_a2->unk6 + 1;
    } else {
        setRGB0(poly, 0x80, 0x80, 0x80);
        poly->tpage = temp_a2->unk4;
        poly->clut = temp_a2->unk6;
    }
    scratch = (void**)getScratchAddr(0);
    AddPrim(scratch[1] - 0x1C, poly++);
    scratch[0] = poly;
}

void func_80105DD8(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    D_801091D8_t* temp_a2;
    POLY_FT4* poly;
    void** scratch;

    if (arg3 <= 0) {
        return;
    }

    poly = *(void**)getScratchAddr(0);
    temp_a2 = &D_801091D8[arg2];
    setPolyFT4(poly);
    setXY4(poly, arg0, arg1, temp_a2->unk2 + arg0, arg1, arg0, temp_a2->unk3 + arg1,
        temp_a2->unk2 + arg0, temp_a2->unk3 + arg1);
    setUV4(poly, temp_a2->unk0, temp_a2->unk1, temp_a2->unk0 + temp_a2->unk2,
        temp_a2->unk1, temp_a2->unk0, temp_a2->unk1 + temp_a2->unk3,
        temp_a2->unk0 + temp_a2->unk2, temp_a2->unk1 + temp_a2->unk3);
    setSemiTrans(poly, 1);

    if (arg3 < 8) {
        setRGB0(poly, arg3 * 0x10, arg3 * 0x10, arg3 * 0x10);
        poly->tpage = temp_a2->unk4 | 0x20;
        poly->clut = arg4 + 1;
    } else {
        setRGB0(poly, 0x80, 0x80, 0x80);
        poly->tpage = temp_a2->unk4;
        poly->clut = arg4;
    }
    scratch = (void**)getScratchAddr(0);
    AddPrim(scratch[1] - 0x1C, poly++);
    scratch[0] = poly;
}

void func_80105F6C(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    char buf[16];
    int i;
    int s2;

    if (arg3 == 0x800000) {
        sprintf(buf, "------");
    } else {
        sprintf(
            buf, "%02d%02d%02d", (arg3 >> 0x10) & 0xFF, (arg3 >> 8) & 0xFF, arg3 & 0xFF);
    }

    s2 = 0x7FF2;
    if (arg4 != 0) {
        s2 = 0x7FF8;
    }

    for (i = 0; i < 6; ++i) {
        if (buf[i] == 0x2D) {
            func_80105DD8(arg0, arg1, 0x53, arg2, s2);
            arg0 += 0xC;
        } else {
            func_80105DD8(arg0, arg1 - 3, buf[i] - 0x30, arg2, s2);
            arg0 += 0xC;
        }

        if (i == 1) {
            func_80105DD8(arg0, arg1 - 2, 0x49, arg2, s2);
            arg0 += 6;
        } else if (i == 3) {
            func_80105DD8(arg0, arg1 - 2, 0x4A, arg2, s2);
            arg0 += 6;
        }
    }
}

// https://decomp.me/scratch/5NYkC
INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801060A8);

void func_801064D4(int arg0, int arg1, int arg2, int arg3)
{
    POLY_FT4* poly;
    void** p;
    int v1;

    if (arg2 < 0) {
        return;
    }

    v1 = arg0 + 0x120;

    if (arg2 > 0x30) {
        arg2 = 0x30;
    }

    arg0 = (v1 - (arg2 * 6));

    func_800C6540("PRESS", ((arg0 + 0x12) & 0xFFFF) | (arg1 << 0x10), 0x8080FF, NULL);
    func_800C6540(
        "BUTTON", ((arg0 + 0x12) & 0xFFFF) | ((arg1 + 0xA) << 0x10), 0x8080FF, NULL);

    arg1 += 0x16;

    if ((arg3 & 0xF) < 9) {
        v1 = arg1 - 0x10;
        arg1 = v1 + ((arg3 & 0xF) >> 1);
    } else {
        v1 = arg1 - 0xA;
        arg1 = v1 - ((arg3 & 0xF) >> 2);
    }

    poly = *(void**)0x1F800000;
    setPolyFT4(poly);
    setShadeTex(poly, 1);
    setXY4(poly, arg0, arg1 - 2, arg0 + 0x10, arg1 - 2, arg0, arg1 + 0xE, arg0 + 0x10,
        arg1 + 0xE);
    setUV4(poly, 0x20, 0x80, 0x30, 0x80, 0x20, 0x90, 0x30, 0x90);
    setTPage(poly, 0, 0, 768, 0);
    setClut(poly, 944, 223);
    p = (void**)0x1F800000;
    AddPrim(p[1] - 0x1C, poly++);
    p[0] = poly;
}

static inline int _adjust(int v)
{
    if (v < 0) {
        v += 7;
    }
    return v >> 3;
}

void func_8010664C(int arg0, int arg1, int arg2, char* arg3)
{
    POLY_GT4* poly;
    void** p;

    if (arg3[3] != 0) {
        poly = *(void**)0x1F800000;
        setPolyGT4(poly);
        setXY4(poly, arg0, arg1, D_801091D8[arg2].unk2 + arg0, arg1, arg0,
            D_801091D8[arg2].unk3 + arg1, D_801091D8[arg2].unk2 + arg0,
            D_801091D8[arg2].unk3 + arg1);
        setUV4(poly, D_801091D8[arg2].unk0, D_801091D8[arg2].unk1,
            D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2, D_801091D8[arg2].unk1,
            D_801091D8[arg2].unk0, D_801091D8[arg2].unk1 + D_801091D8[arg2].unk3,
            D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2,
            D_801091D8[arg2].unk1 + D_801091D8[arg2].unk3);
        if (arg3[3] < 8) {
            setRGB0(poly, _adjust(arg3[0] * arg3[3]), _adjust(arg3[1] * arg3[3]),
                _adjust(arg3[2] * arg3[3]));
            setRGB1(poly, _adjust(arg3[4] * arg3[3]), _adjust(arg3[5] * arg3[3]),
                _adjust(arg3[6] * arg3[3]));
            setRGB2(poly, _adjust(arg3[0] * arg3[3]), _adjust(arg3[1] * arg3[3]),
                _adjust(arg3[2] * arg3[3]));
            setRGB3(poly, _adjust(arg3[4] * arg3[3]), _adjust(arg3[5] * arg3[3]),
                _adjust(arg3[6] * arg3[3]));
        } else {
            setRGB0(poly, arg3[0], arg3[1], arg3[2]);
            setRGB1(poly, arg3[4], arg3[5], arg3[6]);
            setRGB2(poly, arg3[0], arg3[1], arg3[2]);
            setRGB3(poly, arg3[4], arg3[5], arg3[6]);
        }
        setSemiTrans(poly, 1);
        if (arg3[3] < 8) {
            poly->clut = D_801091D8[arg2].unk6 + 1;
            poly->tpage = D_801091D8[arg2].unk4 | 0x20;
        } else {
            poly->clut = D_801091D8[arg2].unk6;
            poly->tpage = D_801091D8[arg2].unk4;
        }
        p = (void**)0x1F800000;
        AddPrim(p[1] - 0x1C, poly++);
        p[0] = poly;
    }
}

static inline int _adjust2(int v0, int v1)
{
    int ret = (v0 * v1) + ((4 - v1) * 0xC0);
    if (ret < 0) {
        ret += 3;
    }
    return ret >> 2;
}

void func_80106A80(int arg0, int arg1, int arg2, char* arg3)
{
    POLY_GT4* poly;
    void** p;

    if (arg3[3] != 0) {
        poly = *(void**)0x1F800000;
        setPolyGT4(poly);
        setXY4(poly, arg0, arg1, D_801091D8[arg2].unk2 + arg0, arg1, arg0,
            D_801091D8[arg2].unk3 + arg1, D_801091D8[arg2].unk2 + arg0,
            D_801091D8[arg2].unk3 + arg1);
        setUV4(poly, D_801091D8[arg2].unk0, D_801091D8[arg2].unk1,
            D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2, D_801091D8[arg2].unk1,
            D_801091D8[arg2].unk0, D_801091D8[arg2].unk1 + D_801091D8[arg2].unk3,
            D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2,
            D_801091D8[arg2].unk1 + D_801091D8[arg2].unk3);
        if (arg3[3] < 8) {
            setRGB0(poly, _adjust(arg3[0] * arg3[3]), _adjust(arg3[1] * arg3[3]),
                _adjust(arg3[2] * arg3[3]));
            setRGB1(poly, _adjust(arg3[4] * arg3[3]), _adjust(arg3[5] * arg3[3]),
                _adjust(arg3[6] * arg3[3]));
            setRGB2(poly, _adjust(arg3[0] * arg3[3]), _adjust(arg3[1] * arg3[3]),
                _adjust(arg3[2] * arg3[3]));
            setRGB3(poly, _adjust(arg3[4] * arg3[3]), _adjust(arg3[5] * arg3[3]),
                _adjust(arg3[6] * arg3[3]));
        } else if (arg3[3] == 8) {
            setRGB0(poly, 0xC0, 0xC0, 0xC0);
            setRGB1(poly, 0xC0, 0xC0, 0xC0);
            setRGB2(poly, 0xC0, 0xC0, 0xC0);
            setRGB3(poly, 0xC0, 0xC0, 0xC0);
        } else if (arg3[3] == 9) {
            setRGB0(poly, 0xE0, 0xE0, 0xE0);
            setRGB1(poly, 0xE0, 0xE0, 0xE0);
            setRGB2(poly, 0xE0, 0xE0, 0xE0);
            setRGB3(poly, 0xE0, 0xE0, 0xE0);
        } else if (arg3[3] < 14) {
            int temp_a0 = arg3[3] - 0xA;
            setRGB0(poly, _adjust2(arg3[0], temp_a0), _adjust2(arg3[1], temp_a0),
                _adjust2(arg3[2], temp_a0));
            setRGB1(poly, _adjust2(arg3[4], temp_a0), _adjust2(arg3[5], temp_a0),
                _adjust2(arg3[6], temp_a0));
            setRGB2(poly, _adjust2(arg3[0], temp_a0), _adjust2(arg3[1], temp_a0),
                _adjust2(arg3[2], temp_a0));
            setRGB3(poly, _adjust2(arg3[4], temp_a0), _adjust2(arg3[5], temp_a0),
                _adjust2(arg3[6], temp_a0));
        } else {
            setRGB0(poly, arg3[0], arg3[1], arg3[2]);
            setRGB1(poly, arg3[4], arg3[5], arg3[6]);
            setRGB2(poly, arg3[0], arg3[1], arg3[2]);
            setRGB3(poly, arg3[4], arg3[5], arg3[6]);
        }
        setSemiTrans(poly, 1);
        if (arg3[3] < 10) {
            poly->clut = D_801091D8[arg2].unk6 + 1;
            poly->tpage = D_801091D8[arg2].unk4 | 0x20;
        } else {
            poly->clut = D_801091D8[arg2].unk6;
            poly->tpage = D_801091D8[arg2].unk4;
        }
        p = (void**)0x1F800000;
        AddPrim(p[1] - 0x1C, poly++);
        p[0] = poly;
    }
}

static inline int _adjust3(int v0)
{
    if (v0 < 0) {
        v0 += 0x3F;
    }
    return v0 >> 6;
}

void func_80107140(int arg0, int arg1, int arg2, char* arg3, int arg4)
{
    int temp_a1;
    int var_a0;
    int i;
    char var_s6;
    POLY_GT4* poly;
    void** scratch;

    if ((arg0 + D_801091D8[arg2].unk2) < (arg4 - 0x40)) {
        scratch = (void**)0x1F800000;
        poly = scratch[0];
        setPolyGT4(poly);
        setXY4(poly, arg0, arg1, D_801091D8[arg2].unk2 + arg0, arg1, arg0,
            D_801091D8[arg2].unk3 + arg1, D_801091D8[arg2].unk2 + arg0,
            D_801091D8[arg2].unk3 + arg1);
        setUV4(poly, D_801091D8[arg2].unk0, D_801091D8[arg2].unk1,
            D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2, D_801091D8[arg2].unk1,
            D_801091D8[arg2].unk0, D_801091D8[arg2].unk1 + D_801091D8[arg2].unk3,
            D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2,
            D_801091D8[arg2].unk1 + D_801091D8[arg2].unk3);
        setRGB0(poly, arg3[0], arg3[1], arg3[2]);
        setRGB1(poly, arg3[4], arg3[5], arg3[6]);
        setRGB2(poly, arg3[0], arg3[1], arg3[2]);
        setRGB3(poly, arg3[4], arg3[5], arg3[6]);
        setSemiTrans(poly, 1);
        poly->clut = D_801091D8[arg2].unk6;
        poly->tpage = D_801091D8[arg2].unk4;
        scratch = (void**)0x1F800000;
        AddPrim(scratch[1] - 0x1C, poly++);
        scratch[0] = poly;
        return;
    }

    if (arg0 < arg4) {
        scratch = (void**)0x1F800000;
        poly = scratch[0];
        var_s6 = D_801091D8[arg2].unk0;
        for (i = 0; i < D_801091D8[arg2].unk2; i += 12, arg0 += 0xC, var_s6 += 0xC) {
            var_a0 = 0xC;
            if ((i + 0xC) >= D_801091D8[arg2].unk2) {
                var_a0 = D_801091D8[arg2].unk2 - i;
            }
            setPolyGT4(poly);
            temp_a1 = arg0 + var_a0;
            setXY4(poly, arg0, arg1, temp_a1, arg1, arg0, D_801091D8[arg2].unk3 + arg1,
                temp_a1, D_801091D8[arg2].unk3 + arg1);
            setUV4(poly, var_s6, D_801091D8[arg2].unk1, var_s6 + var_a0,
                D_801091D8[arg2].unk1, var_s6,
                D_801091D8[arg2].unk1 + D_801091D8[arg2].unk3, var_s6 + var_a0,
                D_801091D8[arg2].unk1 + D_801091D8[arg2].unk3);

            var_a0 = arg4 - arg0;
            if (var_a0 > 0x40) {
                var_a0 = 0x40;
            }
            if (var_a0 < 0) {
                var_a0 = 0;
            }

            setRGB0(poly, _adjust3(arg3[0] * var_a0), _adjust3(arg3[1] * var_a0),
                _adjust3(arg3[2] * var_a0));
            setRGB2(poly, _adjust3(arg3[0] * var_a0), _adjust3(arg3[1] * var_a0),
                _adjust3(arg3[2] * var_a0));

            var_a0 = arg4 - temp_a1;
            if (var_a0 > 0x40) {
                var_a0 = 0x40;
            }
            if (var_a0 < 0) {
                var_a0 = 0;
            }

            setRGB1(poly, _adjust3(arg3[4] * var_a0), _adjust3(arg3[5] * var_a0),
                _adjust3(arg3[6] * var_a0));
            setRGB3(poly, _adjust3(arg3[4] * var_a0), _adjust3(arg3[5] * var_a0),
                _adjust3(arg3[6] * var_a0));

            setSemiTrans(poly, 1);
            poly->clut = (D_801091D8[arg2].unk6 + 1);
            poly->tpage = (D_801091D8[arg2].unk4 | 0x20);
            scratch = (void**)0x1F800000;
            AddPrim(scratch[1] - 0x1C, poly++);
        }
        scratch = (void**)0x1F800000;
        scratch[0] = poly;
    }
}

void func_80107698(int arg0, int arg1, int arg2)
{
    int i;
    int var_s2;
    void** p = (void**)0x1F800000;
    POLY_FT4* poly = p[0];
    int unk1 = D_801091D8[arg2].unk1;

    for (i = 0; i < D_801091D8[arg2].unk3; ++i, ++arg1, ++unk1) {
        setPolyFT4(poly);
        setXY4(poly, arg0, arg1, D_801091D8[arg2].unk2 + arg0, arg1, arg0, arg1 + 1,
            D_801091D8[arg2].unk2 + arg0, arg1 + 1);
        setUV4(poly, D_801091D8[arg2].unk0, unk1,
            D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2, unk1, D_801091D8[arg2].unk0,
            unk1 + 1, D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2, unk1 + 1);

        if (arg1 < 0xBE) {
            var_s2 = 0x80 - ((0xBD - arg1) * 0x10);
            if (var_s2 < 0) {
                var_s2 = 0;
            }
            setRGB0(poly, var_s2, var_s2, var_s2);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage = D_801091D8[arg2].unk4 | 0x20;
            AddPrim(p[1] - 0x1C, poly++);

            setPolyFT4(poly);
            setXY4(poly, arg0, arg1, D_801091D8[arg2].unk2 + arg0, arg1, arg0, arg1 + 1,
                D_801091D8[arg2].unk2 + arg0, arg1 + 1);
            setUV4(poly, D_801091D8[arg2].unk0, unk1,
                D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2, unk1,
                D_801091D8[arg2].unk0, unk1 + 1,
                D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2, unk1 + 1);

            setRGB0(poly, var_s2, var_s2, var_s2);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage = D_801091D8[arg2].unk4 | 0x40;
            AddPrim(p[1] - 0x1C, poly++);
        } else if (arg1 >= 0xCE) {
            var_s2 = 0x80 - ((arg1 - 0xCE) * 0x10);
            if (var_s2 < 0) {
                var_s2 = 0;
            }
            setRGB0(poly, var_s2, var_s2, var_s2);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage = (D_801091D8[arg2].unk4 | 0x20);
            AddPrim(p[1] - 0x1C, poly++);

            setPolyFT4(poly);
            setXY4(poly, arg0, arg1, D_801091D8[arg2].unk2 + arg0, arg1, arg0, arg1 + 1,
                D_801091D8[arg2].unk2 + arg0, arg1 + 1);
            setUV4(poly, D_801091D8[arg2].unk0, unk1,
                D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2, unk1,
                D_801091D8[arg2].unk0, unk1 + 1,
                D_801091D8[arg2].unk0 + D_801091D8[arg2].unk2, unk1 + 1);
            setRGB0(poly, var_s2, var_s2, var_s2);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage = D_801091D8[arg2].unk4 | 0x40;
            AddPrim(p[1] - 0x1C, poly++);
        } else {
            setRGB0(poly, 0x80, 0x80, 0x80);
            setSemiTrans(poly, 1);
            setClut(poly, 800, 511);
            poly->tpage = D_801091D8[arg2].unk4;
            AddPrim(p[1] - 0x1C, poly++);
        }
    }
    p[0] = poly;
}

int _loadIqDis(void)
{
    vs_battle_room* room;
    short* var_a0;

    if (D_800F1CD8 == 0) {
        func_8007DFF0(0x1D, 2, 5);
        _iqDisData = vs_main_allocHeapR(_disFiles[iqDis].size);
        _iqDisCdSlot = vs_main_allocateCdQueueSlot(&_disFiles[iqDis]);
        vs_main_cdEnqueue(_iqDisCdSlot, _iqDisData);
        ++D_800F1CD8;
        if (0) {
        wat:
            D_801099F4 = var_a0[2];
            D_801099F6 = var_a0[3];
            goto wat2;
        }
    } else if (D_800F1CD8 == 1) {
        if (_iqDisCdSlot->state == vs_main_CdQueueStateLoaded) {
            int i;
            func_80103530_t sp10;
            for (i = 0; i < 2; ++i) {
                func_8008D820(_iqDisData + i * 0x8220, &sp10);
                if (sp10.unk10 != NULL) {
                    sp10.unkC->x = 0x340 + i * 0x40;
                    sp10.unkC->y = 0x100;
                    sp10.unkC->h = 0xFF;
                    LoadImage(sp10.unkC, (u_long*)sp10.unk10);
                }
                if (i == 0) {
                    if (sp10.unk8 != NULL) {
                        sp10.unk4->x = 0x300;
                        sp10.unk4->y = 0x1FF;
                        sp10.unk4->w = 0xA0;
                        sp10.unk4->h = 1;
                        sp10.unk8[0] = 0;
                        LoadImage(sp10.unk4, sp10.unk8);
                        vs_main_memcpy(D_801098AC, sp10.unk8, 0x140);
                    }
                }
            }
            D_801099F4 = 0x258;
            D_801099F6 = 1;
            room = vs_battle_currentScene->rooms;
            var_a0 = _iqDisData + 0x10440;
            for (i = 0; i < 0x40; ++i, var_a0 += 4) {
                if ((var_a0[0] == room->zoneId) && (var_a0[1] == room->mapId)) {
                    goto wat;
                }
            }
        wat2:
            vs_main_freeCdQueueSlot(_iqDisCdSlot);
            ++D_800F1CD8;
        }
    } else {
        vs_main_freeHeapR(_iqDisData);
        D_80109894 = 0;
        D_80109898 = 0;
        D_8010989C = 0;
        D_801098A0 = 0;
        D_8010988C = 0;
        D_80109878 = 0;
        D_800F1CD8 = 0;
        func_80108E38();
        return 1;
    }
    return 0;
}

int func_80107D4C(void)
{
    if (vs_main_stateFlags.unkA3 != 0) {
        vs_main_stateFlags.unkA2 = 0x3B;
        vs_main_stateFlags.unkA1 = 0x3B;
        vs_main_stateFlags.unkA3 = 0;
        vs_main_stateFlags.unkA0 = 0x63;
    }
    return _loadIqDis();
}

int _loadEscDis(void)
{
    func_80103530_t sp10;
    int i;

    if (D_800F1CD8 == 0) {
        func_8007DFF0(0x1D, 1, 5);
        _escDisData = vs_main_allocHeapR(_disFiles[escDis].size);
        _escDisCdSLot = vs_main_allocateCdQueueSlot(&_disFiles[escDis]);
        vs_main_cdEnqueue(_escDisCdSLot, _escDisData);
        ++D_800F1CD8;
    } else if (D_800F1CD8 == 1) {
        if (_escDisCdSLot->state == vs_main_CdQueueStateLoaded) {
            for (i = 0; i <= 0; ++i) {
                func_8008D820(_escDisData + i * 0x8220, &sp10);
                if (sp10.unk10 != NULL) {
                    sp10.unkC->x = 0x340 + i * 0x40;
                    sp10.unkC->y = 0x100;
                    sp10.unkC->h = 0xFF;
                    LoadImage(sp10.unkC, (u_long*)sp10.unk10);
                }
                if ((i == 0) && (sp10.unk8 != NULL)) {
                    sp10.unk4->x = 0x300;
                    sp10.unk4->y = 0x1FF;
                    sp10.unk4->w = 0xA0;
                    sp10.unk4->h = 1;
                    *sp10.unk8 = 0;
                    LoadImage(sp10.unk4, sp10.unk8);
                    vs_main_memcpy(D_801098AC, sp10.unk8, 0x140U);
                }
            }
            vs_main_freeCdQueueSlot(_escDisCdSLot);
            ++D_800F1CD8;
        }
    } else {
        vs_main_freeHeapR(_escDisData);
        D_80109894 = 0;
        D_80109898 = 0;
        D_8010989C = 0;
        D_801098A0 = 0;
        D_8010988C = 0;
        D_80109878 = 0;
        D_800F1CD8 = 0;
        return 1;
    }
    return 0;
}

int func_80107FC0(void)
{
    if (D_801098A0 != 0) {
        return 0;
    }
    if (D_8010989C == 0) {
        vs_main_playSfxDefault(0x7E, 0x7D);
    }
    if (D_8010989C == 0x1E) {
        vs_main_playSfxDefault(0x7E, 0x7D);
    }

    func_801085D4(0xA0, 0x40, D_8010989C);
    func_8010873C(0x80, 0x74, D_8010989C - 0xF);
    func_80108784(0xC0, 0x90, D_8010989C - 0x1E);
    func_801064D4(0xD6, 0xBB, D_8010989C - 0x1E, D_8010989C);

    if (D_8010989C < 0x7FFF) {
        ++D_8010989C;
    }

    if (vs_main_buttonsPressed.all & PADRright) {
        if (D_8010989C >= 0x4E) {
            func_80045D64(0x7E, 0);
            func_8007E0A8(0x1D, 2, 5);
            return 1;
        }
        func_80045D64(0x7E, 0);
        D_8010989C = 0x4E;
    }

    return 0;
}

int func_801080E4(void)
{
    int temp_s0;
    int var_v0;

    var_v0 = rsin(D_8010988C);
    if (var_v0 < 0) {
        var_v0 += 0x1FF;
    }
    func_80104A50((var_v0 >> 9) + 8);
    D_8010988C = (D_8010988C + 0x40) & 0xFFF;
    if (D_801098A0 == 0) {
        temp_s0 = ((vs_main_stateFlags.unkA2 * 0x1770) + (vs_main_stateFlags.unkA1 * 0x64)
                   + vs_main_stateFlags.unkA0);
        temp_s0 -= (D_801099F4 * 0x64);
        if (temp_s0 <= 0) {
            temp_s0 = 0xF - D_801099F6;
        } else {
            --temp_s0;
            temp_s0 = temp_s0 / 200;
            var_v0 = 1;
            temp_s0 = 0xF - (D_801099F6 + (temp_s0 + var_v0));
            if (temp_s0 >= 0x10) {
                temp_s0 = 0xF;
            }
            if (temp_s0 < 0) {
                temp_s0 = 0;
            }
        }
        if (D_8010989C == 0x10) {
            vs_main_playSfxDefault(0x7E, 0x72);
        }
        if (D_8010989C == 0x40) {
            func_80045D64(0x7E, 0x72);
            vs_main_playSfxDefault(0x7E, 0x73);
        }
        if (D_8010989C == 0x43) {
            vs_main_playSfxDefault(0x7E, 0x7D);
        }
        if (D_8010989C == 0x4B) {
            vs_main_playSfxDefault(0x7E, 0x7D);
        }
        if (D_8010989C == 0x5A) {
            vs_main_playSfxDefault(0x7E, 0x7D);
        }
        func_8010887C(0x58, 0x40, D_8010989C);
        func_80108688(0xA0, 0x64, D_8010989C - 0x4B);
        func_8010880C(0xA0, 0x7C, D_8010989C - 0x5A, temp_s0);
        func_801064D4(0xD6, 0xBB, D_8010989C - 0x5A, D_8010989C);
        if (D_8010989C < 0x7FFF) {
            ++D_8010989C;
        }
        if (vs_main_buttonsPressed.all & PADRright) {
            if (D_8010989C >= 0x8A) {
                func_80045D64(0x7E, 0);
                func_8007E0A8(0x1D, 2, 5);
                vs_main_scoredata.enemyKillStreak += D_8010978C[temp_s0];
                func_80108E40();
                return 1;
            }
            func_80045D64(0x7E, 0);
            D_8010989C = 0x8A;
        }
    }
    return 0;
}

int func_801083AC(void)
{
    int var_v0;

    var_v0 = rsin(D_8010988C);
    if (var_v0 < 0) {
        var_v0 += 0x1FF;
    }
    func_80104A50((var_v0 >> 9) + 8);
    D_8010988C = (D_8010988C + 0x40) & 0xFFF;
    if (D_801098A0 != 0) {
        return 0;
    }
    if (D_8010989C == 0) {
        vs_main_playSfxDefault(0x7E, 0x7A);
    }
    if (D_8010989C == 0xF) {
        vs_main_playSfxDefault(0x7E, 0x7A);
    }
    func_801084F4(0x40, D_8010989C);
    func_80108564(0x64, D_8010989C - 0xF);
    func_801064D4(0xD6, 0xBB, D_8010989C - 0xF, D_8010989C);
    if (D_8010989C < 0x7FFF) {
        ++D_8010989C;
    }
    if (vs_main_buttonsPressed.all & PADRright) {
        if (D_8010989C >= 0x3F) {
            func_80045D64(0x7E, 0);
            func_8007E0A8(0x1D, 1, 5);
            func_80108E40();
            return 1;
        }
        D_8010989C = 0x3F;
        func_80045D64(0x7E, 0);
    }
    return 0;
}

void func_801084F4(int arg0, int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 > 0x40) {
        arg1 = 0x40;
    }
    if (arg1 > 0) {
        func_80105C34(0, arg0, 0x7B, arg1);
        func_80105C34(0xA0, arg0, 0x7C, arg1);
    }
}

void func_80108564(int arg0, int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 > 0x40) {
        arg1 = 0x40;
    }
    if (arg1 > 0) {
        func_80105C34(0, arg0, 0x7D, arg1);
        func_80105C34(0xA0, arg0, 0x7E, arg1);
    }
}

void func_801085D4(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_801097CC[3] = arg2;
        D_801097CC[7] = arg2;
        arg0 -= (D_801091D8[102].unk2 + D_801091D8[103].unk2) >> 1;
        func_80106A80(arg0, arg1, 0x66, D_801097CC);
        func_80106A80(arg0 + D_801091D8[102].unk2, arg1, 0x67, D_801097CC + 4);
    }
}

void func_80108688(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_801097D8[3] = arg2;
        D_801097D8[7] = arg2;
        arg0 -= (D_801091D8[105].unk2 + D_801091D8[106].unk2) >> 1;
        func_80106A80(arg0, arg1, 0x69, D_801097D8);
        func_80106A80(arg0 + D_801091D8[105].unk2, arg1, 0x6A, D_801097D8 + 4);
    }
}

void func_8010873C(int arg0, int arg1, int arg2)
{
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        func_80105C34(arg0 - (D_8010951A >> 1), arg1, 0x68, arg2);
    }
}

void func_80108784(int arg0, int arg1, int arg2)
{
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        int new_var = (D_801099F4 % 60) << 0x10;
        func_80105F6C(arg0, arg1, arg2, ((D_801099F4 / 60) << 0x10) | (new_var >> 8), 0);
    }
}

void func_8010880C(int arg0, int arg1, int arg2, int arg3)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_801097E4[3] = arg2;
        func_80106A80(
            arg0 - (D_801091D8[arg3 + 0x6B].unk2 >> 1), arg1, arg3 + 0x6B, D_801097E4);
    }
}

// https://decomp.me/scratch/FRfFv
INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010887C);

void func_80108A0C(void)
{
    int var_a2;
    int i;
    int a1;

    for (i = 0, var_a2 = 0, a1 = 1; i < 16; ++i) {
        if (vs_main_scoredata.flags & (a1 << i)) {
            ++var_a2;
        }
    }

    for (i = 0; i < 16; ++i) {
        if (var_a2 >= D_801097EC[i]) {
            if (_score >= D_8010980C[i]) {
                D_8010987C = i;
                return;
            }
        }
    }
}

void _calculateScore(void)
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
        if ((vs_main_scoredata.bossTimeTrialScores[i][0].time.unk0) != 0x800000) {
            _score += 20000;
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

    _score += _clearCount * 100000;

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

void func_80108E38(void) { }

void func_80108E40(void) { }

void func_80108E48(void)
{
    int new_var = vs_main_scoredata.enemyKillStreak + 100000;
    vs_main_scoredata.enemyKillStreak = new_var - (vs_main_scoredata.bossHealCount * 100);
    if (vs_main_scoredata.enemyKillStreak > 999999999) {
        vs_main_scoredata.enemyKillStreak = 999999999;
    }
    vs_main_scoredata.bossHealCount = 0;
}

void _nop(void) { }

int _getTotalStrength(void) { return vs_battle_characterState->unk3C->totalStrength; }

int _getTotalIntelligence(void)
{
    return vs_battle_characterState->unk3C->totalIntelligence;
}

int _getTotalAgility(void) { return vs_battle_characterState->unk3C->totalAgility; }

void _raiseMaxStrength(int amount)
{
    vs_battle_characterState->unk3C->totalStrength += amount;
    if (vs_battle_characterState->unk3C->totalStrength > 999) {
        vs_battle_characterState->unk3C->totalStrength = 999;
    }
    vs_battle_characterState->unk3C->strength += amount;
    if (vs_battle_characterState->unk3C->strength > 999) {
        vs_battle_characterState->unk3C->strength = 999;
    }
}

void _raiseMaxIntelligence(int amount)
{
    vs_battle_characterState->unk3C->totalIntelligence += amount;
    if (vs_battle_characterState->unk3C->totalIntelligence > 999) {
        vs_battle_characterState->unk3C->totalIntelligence = 999;
    }
    vs_battle_characterState->unk3C->intelligence += amount;
    if (vs_battle_characterState->unk3C->intelligence > 999) {
        vs_battle_characterState->unk3C->intelligence = 999;
    }
}

void _raiseMaxAgility(int amount)
{
    vs_battle_characterState->unk3C->totalAgility += amount;
    if (vs_battle_characterState->unk3C->totalAgility > 999) {
        vs_battle_characterState->unk3C->totalAgility = 999;
    }
    vs_battle_characterState->unk3C->agility += amount;
    if (vs_battle_characterState->unk3C->agility > 999) {
        vs_battle_characterState->unk3C->agility = 999;
    }
}

void _raiseMaxHP(int amount)
{
    vs_battle_characterState->unk3C->maxHP += amount;
    if (vs_battle_characterState->unk3C->maxHP > 999) {
        vs_battle_characterState->unk3C->maxHP = 999;
    }
    vs_battle_characterState->unk3C->currentHP += amount;
    if (vs_battle_characterState->unk3C->currentHP > 999) {
        vs_battle_characterState->unk3C->currentHP = 999;
    }
}

void _raiseMaxMP(int amount)
{
    vs_battle_characterState->unk3C->maxMP += amount;
    if (vs_battle_characterState->unk3C->maxMP > 999) {
        vs_battle_characterState->unk3C->maxMP = 999;
    }
    vs_battle_characterState->unk3C->currentMP += amount;
    if (vs_battle_characterState->unk3C->currentMP > 999) {
        vs_battle_characterState->unk3C->currentMP = 999;
    }
}
