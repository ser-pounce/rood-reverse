#include "common.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/31724.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "build/src/include/lbas.h"
#include "gpu.h"
#include <stdio.h>
#include <libetc.h>
#include <libgpu.h>
#include <rand.h>
#include <string.h>

typedef struct {
    char x;
    char y;
    char w;
    char h;
    u_short tpage;
    u_short clut;
} _texture_t;

typedef struct {
    short stat;
    short amount;
} _buffReels_t;

static int _initCongratulationsScreen(void);
static int _initMenu(void);
static int _initTimeAttackEnd(void);
static int _initTimeAttackStart(void);
static void func_80103748(void);
static int _execMenu(void);
static int _renderCongratulationsScreen(void);
static int _renderTimeAttackEnd(void);
static int _renderTimeAttackStart(void);
static void _renderTimeAttackHeader(int x, int y, int timer);
static void _renderCourse(int arg0, int arg1, int arg2);
static void _renderBossName(int arg0, int arg1, int arg2);
static void _renderBestTimeHeader(int arg0, int arg1, int arg2);
static void _renderStartCountdown(int arg0, int arg1, int arg2);
static void func_80104914(int);
static void _renderCongratulations(int arg0, int arg1, int arg2);
static void _renderScore(int arg0, int arg1, int arg2, int arg3);
static void _renderIncrementalScore(int arg0, int arg1, int arg2, int arg3);
static void _renderMapCompletion(int arg0, int arg1, int arg2, int arg3);
static void _renderIncrementalMapCompletion(int arg0, int arg1, int arg2, int arg3);
static void _renderRiskbreakerRankHeader(int arg0, int arg1, int arg2);
static void _renderRiskbreakerRank(int arg0, int arg1, int arg2);
static void func_8010559C(int arg0, int arg1, int arg2);
static void func_8010564C(int arg0, int arg1, int arg2);
static void func_801056E8(int arg0, int arg1, int arg2);
static void func_80105790(int, int, int);
static void func_8010581C(int, int, int);
static void func_801059B8(int arg0, int arg1, int arg2);
static void func_801059FC(int arg0, int arg1, int arg2);
static void func_80105B30(int arg0, int arg1, int arg2, int arg3);
static void func_80105C34(int, int, int, int);
static void func_80105DD8(int, int, int, int, int);
static void func_80105F6C(int, int, int, int, int);
void _renderStatWheel(int, int, int, int);
static void _renderPressButtonPrompt(int, int, int, int);
static void func_8010664C(int, int, int, P_CODE colors[]);
static void _renderTexturePopIn(int, int, int, P_CODE colors[]);
static void _renderTextureWipe(int, int, int, P_CODE arg3[], int);
static int _initCubePuzzleStart(void);
static int _initCubePuzzleEnd(void);
static int _initCubePuzzleQuit(void);
static int _renderCubePuzzleStart(void);
static int _renderCubePuzzleEnd(void);
static int _renderCubePuzzleQuit(void);
static void func_801084F4(int arg0, int arg1);
static void func_80108564(int arg0, int arg1);
static void _renderAverageTime(int arg0, int arg1, int arg2);
static void func_80108688(int arg0, int arg1, int arg2);
static void func_8010873C(int arg0, int arg1, int arg2);
static void func_80108784(int arg0, int arg1, int arg2);
static void func_8010880C(int arg0, int arg1, int arg2, int arg3);
static void func_8010887C(int arg0, int arg1, int arg2);
static void _calculateScore(void);
static void _nop0(void);
static void _nop1(void);
static void _determineRank(void);
static int _getTotalStrength(void);
static int _getTotalIntelligence(void);
static int _getTotalAgility(void);
static void func_80108E48(void);
static void _nop2(void);
static void _raiseMaxStrength(int amount);
static void _raiseMaxIntelligence(int amount);
static void _raiseMaxAgility(int amount);
static void _raiseMaxHP(int amount);
static void _raiseMaxMP(int amount);

int vs_menuF_exec(u_char* arg0)
{
    switch (*arg0) {
    case 0:
        *arg0 = 1;
        // Fallthrough
    case 1:
        *arg0 += (_initMenu() != 0);
        break;
    case 2:
        if (_execMenu() != 0) {
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

int _initMenu(void)
{
    int ret;

    switch (vs_main_stateFlags.menuFSubmenu) {
    case 0:
        ret = _initCongratulationsScreen();
        break;

    case 1:
        ret = _initTimeAttackStart();
        break;

    case 2:
        ret = _initTimeAttackEnd();
        break;

    case 3:
        func_80108E48();
        _nop2();

        ret = 1;
        break;

    case 4:
        ret = _initCubePuzzleStart();
        break;

    case 5:
        ret = _initCubePuzzleEnd();
        break;

    case 6:
        ret = _initCubePuzzleQuit();
        break;
    }

    return ret;
}

static u_int _buffReelSelection;
static int _rank;
static int _clearCount;
static u_int _score;
static u_int _mapCompletion;
static u_int _buffReelSpinSpeed;
static int _buffReelIndex;
static int _onScreenMapCompletion;
static int _onScreenScore;
static int _screenTimer;
static int _screenState;

int _initCongratulationsScreen(void)
{
    static vs_main_CdQueueSlot* cdSlot;
    static void* timData;

    int i;

    if (_submenuState == 0) {

        func_8007DFF0(0x1D, 3, 5);

        timData = vs_main_allocHeapR(_disFiles[rankDis].size);
        cdSlot = vs_main_allocateCdQueueSlot(&_disFiles[rankDis]);

        vs_main_cdEnqueue(cdSlot, timData);

        ++_submenuState;

    } else if (_submenuState == 1) {
        if (cdSlot->state == vs_main_CdQueueStateLoaded) {

            for (i = 0; i < 3; ++i) {
                TIM_IMAGE tim;

                vs_battle_setTimImage(timData + i * 0x8220, &tim);

                if (tim.paddr != NULL) {
                    tim.prect->x = 832 + i * 64;
                    tim.prect->y = 256;
                    tim.prect->h = 255;

                    LoadImage(tim.prect, tim.paddr);
                }

                if (i == 0) {
                    if (tim.caddr != NULL) {
                        tim.crect->x = 768;
                        tim.crect->y = 511;
                        tim.crect->w = 128;
                        tim.crect->h = 1;
                        tim.caddr[0] = 0;

                        LoadImage(tim.crect, tim.caddr);
                    }
                }
            }

            vs_main_freeCdQueueSlot(cdSlot);
            func_80103748();

            ++_submenuState;
        }
    } else if (vs_main_clearMusicLoadQueue() == 0) {
        int strength;
        int intelligence;
        int agility;
        int mapCompletion;
        u_int chestsOpened;

        func_80045000(2, 0x7F, 0);
        vs_main_freeHeapR(timData);

        _onScreenMapCompletion = 0;
        _onScreenScore = 0;
        _screenTimer = 0;
        _screenState = 0;
        _buffReelSpinSpeed = 0;
        _buffReelSelection = (rand() & 0xF0) | 8;

        strength = _getTotalStrength();
        intelligence = _getTotalIntelligence();
        agility = _getTotalAgility();

        if ((intelligence >= strength) && (agility >= strength)) {
            _buffReelIndex = 0;
        } else if (strength >= intelligence) {
            if (agility >= intelligence) {
                _buffReelIndex = 1;
            } else {
                _buffReelIndex = 2;
            }
        } else {
            _buffReelIndex = 2;
        }

        _submenuState = 0;

        func_80108E48();

        _clearCount = vs_main_stateFlags.clearCount;

        if (vs_main_mapStatus.roomFlags[1] & 0x800000) {
            vs_main_mapStatus.roomFlags[1] |= 0x400000;
        }

        mapCompletion = 0;

        for (i = 0; i < 16; ++i) {
            int flag;
            for (flag = 0; flag < 32; ++flag) {
                int v = 1;
                if (vs_main_mapStatus.roomFlags[i] & vs_battle_mapCompletionFlags[i]
                    & (v << flag)) {
                    ++mapCompletion;
                }
            }
        }

        chestsOpened = 0;

        for (i = 0; i < 64; ++i) {
            if (vs_main_stateFlags.chestsOpened[i] != 0) {
                ++chestsOpened;
            }
        }

        if (vs_main_scoredata.mapCompletion < mapCompletion) {
            vs_main_scoredata.mapCompletion = mapCompletion;
        }
        if (vs_main_scoredata.openedChestCount < chestsOpened) {
            vs_main_scoredata.openedChestCount = chestsOpened;
        }

        _mapCompletion = (mapCompletion * 100) / 361;

        _calculateScore();
        _determineRank();

        return 1;
    }

    return 0;
}

static int _newTimeSlot;
static int _timeTrialTime;
static u_short _timBuf[160];

int _initTimeAttackEnd(void)
{
    static vs_main_CdQueueSlot* cdSlot;
    static void* timData;

    int i;
    int state = _submenuState;

    if (state == 0) {

        func_8007DFF0(0x1D, 1, 5);

        timData = vs_main_allocHeapR(_disFiles[timeDis].size);
        cdSlot = vs_main_allocateCdQueueSlot(&_disFiles[1]);

        vs_main_cdEnqueue(cdSlot, timData);

        ++_submenuState;

    } else if (state == 1) {
        if (cdSlot->state == vs_main_CdQueueStateLoaded) {
            TIM_IMAGE tim;

            vs_battle_setTimImage(timData, &tim);

            if (tim.paddr != NULL) {
                tim.prect->x = 832;
                tim.prect->y = 256;
                tim.prect->h = 255;

                LoadImage(tim.prect, tim.paddr);
            }

            if (tim.caddr != NULL) {
                tim.crect->x = 768;
                tim.crect->y = 511;
                tim.crect->w = 160;
                tim.crect->h = 1;
                tim.caddr[0] = 0;

                LoadImage(tim.crect, tim.caddr);
                vs_main_memcpy(_timBuf, tim.caddr, sizeof _timBuf);
            }

            vs_main_freeCdQueueSlot(cdSlot);
            func_80103748();

            ++_submenuState;
        }
    } else if (vs_main_clearMusicLoadQueue() == 0) {

        func_80045000(2, 0x7F, 0);

        _timeTrialTime = (vs_main_stateFlags.timeTrialMins << 0x10)
                       | (vs_main_stateFlags.timeTrialSecs << 8)
                       | vs_main_stateFlags.timeTrialMs;

        if (_timeTrialTime == 0) {
            _timeTrialTime = (59 << 16) | (59 << 8) | 99;
        }

        for (i = 0; i < 3; ++i) {
            int record;

            if ((vs_main_scoredata
                        .bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][i]
                        .time)
                < _timeTrialTime) {
                continue;
            }

            for (record = 2; i < record; --record) {
                vs_main_scoredata
                    .bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][record]
                    .time =
                    vs_main_scoredata
                        .bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][record - 1]
                        .time;
                vs_main_scoredata
                    .bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][record]
                    .round =
                    vs_main_scoredata
                        .bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][record - 1]
                        .round;
                vs_main_scoredata
                    .bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][record]
                    .difficulty =
                    vs_main_scoredata
                        .bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][record - 1]
                        .difficulty;
            }

            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][i]
                .time = _timeTrialTime;
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][i]
                .round = vs_main_stateFlags.clearCount;
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][i]
                .difficulty = vs_main_stateFlags.difficulty;

            break;
        }

        _newTimeSlot = i;
        _screenTimer = 0;
        _screenState = 0;
        _buffReelSpinSpeed = 0;
        _submenuState = 0;

        vs_main_freeHeapR(timData);

        return 1;
    }
    return 0;
}

int _initTimeAttackStart(void)
{
    static vs_main_CdQueueSlot* cdSlot;
    static void* timData;

    if (_submenuState == 0) {

        func_8007DFF0(0x1D, 2, 5);

        timData = vs_main_allocHeapR(_disFiles[attackDis].size);
        cdSlot = vs_main_allocateCdQueueSlot(&_disFiles[attackDis]);

        vs_main_cdEnqueue(cdSlot, timData);

        ++_submenuState;
    } else if (_submenuState == 1) {
        if (cdSlot->state == vs_main_CdQueueStateLoaded) {
            int i;
            TIM_IMAGE tim;

            for (i = 0; i < 2; ++i) {
                vs_battle_setTimImage(timData + i * 0x8220, &tim);

                if (tim.paddr != NULL) {
                    tim.prect->x = 832 + i * 64;
                    tim.prect->y = 256;
                    tim.prect->h = 255;

                    LoadImage(tim.prect, tim.paddr);
                }

                if (i == 0) {
                    if (tim.caddr != NULL) {
                        tim.crect->x = 768;
                        tim.crect->y = 511;
                        tim.crect->w = 160;
                        tim.crect->h = 1;
                        tim.caddr[0] = 0;

                        LoadImage(tim.crect, tim.caddr);
                    }
                }
            }

            vs_main_freeCdQueueSlot(cdSlot);

            ++_submenuState;
        }
    } else {
        vs_main_freeHeapR(timData);

        _onScreenMapCompletion = 0;
        _onScreenScore = 0;
        _screenTimer = 0;
        _screenState = 0;
        _buffReelSpinSpeed = 0;
        _buffReelSelection = 0;
        _submenuState = 0;
        return 1;
    }

    return 0;
}

void func_80103748(void)
{
    if ((vs_main_soundData.unk8 != 7)
        && (((vs_main_soundData.unk8 - 31) < 9) || ((vs_main_soundData.unk8 - 45) < 5))) {
        vs_main_loadMusicSlot(vs_main_soundData.unk8 + 100, 2);
    } else {
        vs_main_loadMusicSlot(128, 2);
    }
}

int _execMenu(void)
{
    int ret;

    switch (vs_main_stateFlags.menuFSubmenu) {
    case 0:
        ret = _renderCongratulationsScreen();
        break;

    case 1:
        ret = _renderTimeAttackStart();
        break;

    case 2:
        ret = _renderTimeAttackEnd();
        break;

    case 3:
        ret = 1;
        break;

    case 4:
        ret = _renderCubePuzzleStart();
        break;

    case 5:
        ret = _renderCubePuzzleEnd();
        break;

    case 6:
        ret = _renderCubePuzzleQuit();
        break;
    }

    // BUG: potential garbage
    return ret;
}

enum disIndices {
    disIndexRank0Comma = 10,
    disIndexRank0Bonus,
    disIndexRank0RiskbreakerRank,
    disIndexRank0Score = 18,
    disIndexRank0Percent,
    disIndexRank0Pts,
    disIndexRank0MapCompleted,
    disIndexRank0Congratulations,
    disIndexRank0Plus = 24,
    disIndexRank0Colon = 26,
    disIndexAttack0Course = 84,
    disIndexAttack0Minotaur,
    disIndexAttack0Death = 91,
    disIndexAttack0OgreZombie = 93,
    disIndexAttack0BestTime = 95,
    disIndexAttack0Three,
    disIndexAttack0TimeAttack = 100,
    disIndexIq0AverageTime = 102,
};

static _texture_t _disMap[] = {
    { 0, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 14, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 28, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 42, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 56, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 70, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 84, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 98, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 112, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 126, 0, 14, 20, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 240, 16, 4, 8, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 148, 4, 60, 16, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 6, 24, 154, 16, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 4, 44, 38, 18, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 50, 44, 44, 18, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 98, 44, 38, 18, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 144, 44, 30, 18, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 182, 44, 34, 18, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 0, 64, 66, 22, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 104, 70, 12, 12, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 118, 70, 28, 14, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 0, 88, 170, 22, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 8, 118, 136, 24, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 8, 150, 134, 24, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 200, 82, 10, 10, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 216, 82, 8, 6, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 232, 82, 6, 12, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 30, 12, 66, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 98, 12, 70, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 170, 12, 76, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 70, 36, 72, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 144, 36, 102, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 78, 60, 70, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 152, 60, 94, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 38, 84, 80, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 118, 84, 122, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 46, 108, 118, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 166, 108, 74, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 78, 132, 94, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 172, 132, 74, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 82, 156, 86, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 170, 156, 76, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 60, 180, 96, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 158, 180, 88, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 120, 204, 54, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 178, 204, 68, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 56, 228, 114, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 172, 228, 72, 24, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 110, 12, 26, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 138, 12, 54, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 194, 12, 52, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 64, 36, 88, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 182, 36, 64, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 90, 60, 90, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 184, 60, 62, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 82, 84, 66, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 148, 84, 98, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 42, 108, 102, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 144, 108, 102, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 50, 132, 116, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 168, 132, 78, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 74, 156, 92, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 166, 156, 80, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 58, 180, 68, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 130, 180, 52, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 184, 180, 62, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 106, 204, 78, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 188, 204, 58, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 106, 228, 140, 24, getTPage(0, 0, 960, 256), getClut(768, 511) },
    { 146, 2, 88, 14, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 0, 24, 144, 24, getTPage(0, 0, 832, 256), getClut(864, 511) },
    { 0, 48, 144, 24, getTPage(0, 0, 832, 256), getClut(864, 511) },
    { 176, 78, 56, 18, getTPage(0, 0, 832, 256), getClut(800, 511) },
    { 144, 16, 8, 8, getTPage(0, 0, 832, 256), getClut(800, 511) },
    { 152, 16, 8, 8, getTPage(0, 0, 832, 256), getClut(800, 511) },
    { 192, 18, 32, 20, getTPage(0, 0, 832, 256), getClut(800, 511) },
    { 180, 38, 44, 20, getTPage(0, 0, 832, 256), getClut(800, 511) },
    { 184, 58, 40, 20, getTPage(0, 0, 832, 256), getClut(800, 511) },
    { 2, 72, 116, 20, getTPage(0, 0, 832, 256), getClut(832, 511) },
    { 0, 96, 70, 20, getTPage(0, 0, 832, 256), getClut(832, 511) },
    { 72, 96, 68, 20, getTPage(0, 0, 832, 256), getClut(832, 511) },
    { 122, 72, 46, 20, getTPage(0, 0, 832, 256), getClut(832, 511) },
    { 144, 96, 100, 20, getTPage(0, 0, 832, 256), getClut(832, 511) },
    { 238, 4, 12, 16, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 166, 20, 76, 18, getTPage(0, 0, 832, 256), getClut(832, 511) },
    { 4, 32, 140, 24, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 4, 56, 114, 24, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 4, 80, 204, 24, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 4, 104, 198, 24, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 4, 128, 232, 24, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 4, 152, 204, 24, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 4, 176, 114, 24, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 122, 56, 100, 24, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 4, 200, 176, 24, getTPage(0, 0, 832, 256), getClut(896, 511) },
    { 4, 227, 212, 28, getTPage(0, 0, 832, 256), getClut(864, 511) },
    { 146, 180, 100, 18, getTPage(0, 0, 832, 256), getClut(800, 511) },
    { 158, 14, 86, 106, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 50, 14, 92, 106, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 16, 14, 30, 106, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 30, 132, 204, 106, getTPage(0, 0, 896, 256), getClut(768, 511) },
    { 4, 227, 106, 28, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 110, 227, 106, 28, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 4, 120, 111, 30, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 115, 120, 111, 30, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 4, 150, 160, 24, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 8, 176, 170, 24, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 8, 200, 116, 24, getTPage(0, 0, 832, 256), getClut(768, 511) },
    { 8, 8, 170, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 28, 134, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 102, 48, 118, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 48, 94, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 142, 28, 88, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 68, 142, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 88, 144, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 108, 128, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 128, 98, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 136, 108, 104, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 148, 156, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 168, 174, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 106, 128, 88, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 188, 154, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 208, 156, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 8, 228, 194, 20, getTPage(0, 0, 896, 256), getClut(896, 511) },
    { 0, 0, 160, 24, getTPage(0, 0, 832, 256), getClut(864, 511) },
    { 0, 24, 160, 24, getTPage(0, 0, 832, 256), getClut(864, 511) },
    { 0, 48, 160, 24, getTPage(0, 0, 832, 256), getClut(832, 511) },
    { 0, 72, 160, 24, getTPage(0, 0, 832, 256), getClut(832, 511) },
};

/**
 * First element == word count, followed by word lengths
 */
static u_char _riskbreakerRanks[][4] = { { 3, 27, 28, 29 }, { 2, 27, 30 }, { 2, 34, 37 },
    { 2, 32, 33 }, { 2, 66, 67 }, { 2, 35, 36 }, { 2, 28, 31 }, { 2, 44, 28 },
    { 2, 55, 56 }, { 1, 30 }, { 1, 59 }, { 1, 57 }, { 1, 33 }, { 1, 42 }, { 1, 31 },
    { 2, 60, 65 } };

enum BuffReelStats {
    buffReelStatStr = 13,
    buffReelStatAgi,
    buffReelStatInt,
    buffReelStatHp,
    buffReelStatMp
};

static _buffReels_t _buffReels[][16] = {
    { { buffReelStatHp, 5 }, { buffReelStatHp, 3 }, { buffReelStatStr, 2 },
        { buffReelStatAgi, 1 }, { buffReelStatHp, 4 }, { buffReelStatInt, 1 },
        { buffReelStatMp, 2 }, { buffReelStatHp, 3 }, { buffReelStatStr, 2 },
        { buffReelStatMp, 1 }, { buffReelStatHp, 4 }, { buffReelStatHp, 4 },
        { buffReelStatStr, 3 }, { buffReelStatHp, 3 }, { buffReelStatMp, 2 },
        { buffReelStatStr, 1 } },
    { { buffReelStatMp, 1 }, { buffReelStatHp, 4 }, { buffReelStatInt, 1 },
        { buffReelStatHp, 3 }, { buffReelStatHp, 5 }, { buffReelStatHp, 4 },
        { buffReelStatInt, 2 }, { buffReelStatStr, 1 }, { buffReelStatHp, 4 },
        { buffReelStatMp, 2 }, { buffReelStatAgi, 1 }, { buffReelStatInt, 3 },
        { buffReelStatHp, 4 }, { buffReelStatInt, 2 }, { buffReelStatHp, 3 },
        { buffReelStatHp, 3 } },
    { { buffReelStatHp, 4 }, { buffReelStatInt, 1 }, { buffReelStatAgi, 2 },
        { buffReelStatHp, 4 }, { buffReelStatMp, 2 }, { buffReelStatAgi, 1 },
        { buffReelStatMp, 1 }, { buffReelStatHp, 3 }, { buffReelStatAgi, 3 },
        { buffReelStatHp, 4 }, { buffReelStatHp, 3 }, { buffReelStatHp, 5 },
        { buffReelStatAgi, 2 }, { buffReelStatMp, 2 }, { buffReelStatHp, 3 },
        { buffReelStatStr, 1 } }
};

static int _incrementingScore;
static int _incrementingMapCompletion;

int _renderCongratulationsScreen(void)
{
    static int _stateTimer;

    if (_screenState != 3) {
        if (_screenTimer == 208) {
            vs_main_playSfxDefault(0x7E, 0x77);
            vs_main_playSfxDefault(0x7E, 0x78);
        }

        _renderCongratulations(160, 40, _screenTimer);
        _renderIncrementalScore(160, 80, _screenTimer - 32, _screenState);
        _renderIncrementalMapCompletion(160, 102, _screenTimer - 112, _screenState);
        _renderRiskbreakerRankHeader(160, 138, _screenTimer - 192);
        _renderRiskbreakerRank(160, 154, _screenTimer - 208);
        _renderStatWheel(130, 190, _screenTimer - 272, _screenState);
    }

    if (_screenState == 0) {
        _buffReelSelection = (_buffReelSelection + (_buffReelSpinSpeed >> 3)) & 0xFF;
        if ((_screenTimer - 272) > 0) {

            if (_buffReelSpinSpeed == 8) {
                vs_main_playSfxDefault(0x7E, 0x74);
                vs_main_playSfxDefault(0x7E, 0x75);
            }

            if (_buffReelSpinSpeed < 48) {
                if (_screenTimer > 288) {
                    ++_buffReelSpinSpeed;

                    _renderPressButtonPrompt(214, 187, _buffReelSpinSpeed, _screenTimer);
                }
            } else {
                if ((vs_main_buttonsPressed.all & PADRright) || _screenTimer > 2072) {

                    if (vs_main_buttonsPressed.all & PADRright) {
                        vs_main_playSfxDefault(0x7E, 0x76);
                    }

                    _screenState = 1;
                    _stateTimer = 0;

                    func_80045BFC(0x7E, 0x74, 0x40, 0x30);
                    func_80045BFC(0x7E, 0x75, 0x40, 0x30);
                    func_80045C74(0x7E, 0x74, -0x10, 0x30);
                    func_80045C74(0x7E, 0x75, -0x10, 0x30);
                }

                _renderPressButtonPrompt(214, 187, 48, _screenTimer);
            }
        } else if (vs_main_buttonsPressed.all & PADRright) {

            func_80045D64(0x7E, 0);

            _screenTimer = 272;
            _incrementingScore = 0;
            _incrementingMapCompletion = 0;
            _onScreenMapCompletion = _mapCompletion;
            _onScreenScore = _score;
        }
    } else if (_screenState == 1) {
        int temp_v1;
        int temp_a2_2 = 48 - _stateTimer;

        if (temp_a2_2 > 0) {
            _renderPressButtonPrompt(0xD6, 0xBB, temp_a2_2, _screenTimer);
        }

        temp_v1 = _buffReelSelection + (_buffReelSpinSpeed >> 3);
        _buffReelSelection = temp_v1 & 0xFF;

        if (_buffReelSpinSpeed >= 9) {
            --_buffReelSpinSpeed;
        }

        temp_v1 &= 0xF;

        if ((temp_v1 == 8) && (_buffReelSpinSpeed == temp_v1)) {

            func_80045D64(0x7E, 0x74);
            func_80045D64(0x7E, 0x75);
            vs_main_playSfxDefault(0x7E, 0x77);
            vs_main_playSfxDefault(0x7E, 0x78);

            _screenState = 2;
            _stateTimer = 0;
        }
    } else if (_screenState == 2) {
        if ((vs_main_buttonsPressed.all & PADRright) || (_stateTimer > 450)) {
            _screenState = 3;
            _stateTimer = 0;
        }
    } else {

        _renderCongratulations(160, 40, 8 - _stateTimer);
        _renderScore(160, 80, 8 - _stateTimer, 3);
        _renderMapCompletion(160, 102, 8 - _stateTimer, 3);
        _renderRiskbreakerRankHeader(160, 138, 8 - _stateTimer);
        _renderRiskbreakerRank(160, 154, 8 - _stateTimer);
        _renderStatWheel(130, 190, 8 - _stateTimer, 3);

        if (_stateTimer >= 8) {
            int amount = _buffReels[_buffReelIndex][(char)_buffReelSelection / 16].amount;
            switch ((short)(_buffReels[_buffReelIndex][(char)_buffReelSelection / 16].stat
                            - 13)) {
            case 0:
                _raiseMaxStrength(amount);
                break;

            case 1:
                _raiseMaxAgility(amount);
                break;

            case 2:
                _raiseMaxIntelligence(amount);
                break;

            case 3:
                _raiseMaxHP(amount);
                break;

            case 4:
                _raiseMaxMP(amount);
                break;
            }

            func_8007E0A8(0x1D, 3, 5);
            _nop2();

            return 1;
        }
    }

    ++_stateTimer;
    ++_screenTimer;
    return 0;
}

int _renderTimeAttackEnd(void)
{
    int var_v0 = rsin(_buffReelSpinSpeed);

    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }

    if (var_v0 <= -1) {
        var_v0 += 0xFF;
    }

    func_80104914(var_v0 >> 8);

    _buffReelSpinSpeed = (_buffReelSpinSpeed + 0x40) & 0xFFF;

    if (_screenState == 0) {
        if (_screenTimer == 0x30) {
            vs_main_playSfxDefault(0x7E, 0x72);
        }

        if (_screenTimer == 0x60) {
            func_80045D64(0x7E, 0x72);
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        func_8010559C(0xA0, 0x34, _screenTimer);
        func_8010581C(0x10, 0xA4, _screenTimer - 0x20);
        func_801056E8(0x10, 0x90, _screenTimer - 0x60);

        if (_newTimeSlot == 0) {
            func_801059B8(0x46, 0xB8, _screenTimer - 0x80);
        }

        if ((_screenTimer == 0x80) && (_newTimeSlot == 0)) {
            vs_main_playSfxDefault(0x7E, 0x76);
        }

        if (_screenTimer == 0xA0) {
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        if (_screenTimer == 0xA8) {
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        if (_screenTimer == 0xB0) {
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        func_80105B30(0x130, 0x90, 0, _screenTimer - 0xA0);
        func_80105B30(0x130, 0x90, 1, _screenTimer - 0xA8);
        func_80105B30(0x130, 0x90, 2, _screenTimer - 0xB0);

        ++_screenTimer;

        if ((vs_main_buttonsPressed.all & PADRright) || (_screenTimer >= 192)) {

            func_80045D64(0x7E, 0);

            _screenTimer = 0;
            ++_screenState;
        }
    } else if (_screenState == 1) {

        func_8010559C(0xA0, 0x34, 0x40);
        func_80105790(0x10, 0xA4, 0x40);
        func_8010564C(0x10, 0x90, 0x40);

        if (_newTimeSlot == 0) {
            func_801059B8(0x46, 0xB8, 0x40);
        }

        func_801059FC(0x130, 0x90, 0x40);

        ++_screenTimer;

        if ((vs_main_buttonsPressed.all & PADRright) || (_screenTimer >= 450)) {

            if (vs_main_buttonsPressed.all & PADRright) {
                vs_main_playSfxDefault(0x7E, 5);
            }

            ++_screenState;
            _screenTimer = 7;
        }
    } else if (_screenState == 2) {

        func_8010559C(0xA0, 0x34, _screenTimer);
        func_80105790(0x10, 0xA4, _screenTimer);
        func_8010564C(0x10, 0x90, _screenTimer);

        if (_newTimeSlot == 0) {
            func_801059B8(0x46, 0xB8, _screenTimer);
        }

        func_801059FC(0x130, 0x90, _screenTimer);

        if (_screenTimer > 0) {
            --_screenTimer;
        } else {
            ++_screenState;
        }
    } else {
        func_8007E0A8(0x1D, 1, 5);

        return 1;
    }
    return 0;
}

static int D_801096D0[] = { 0x79, 0x5D, 0x43, 0x2B, 0x19, 0xC, 3, 0 };
static D_800F1A68_t D_801096F0[3] = { { 0x1029, 0x1029, 0x1000 },
    { 0x107A, 0x107A, 0x1000 } };
static P_CODE D_80109720[] = { { 0xDC, 0x50, 0x40 }, { 0x40, 0x80, 0xDC },
    { 0x80, 0x80, 0x80 } };

int _renderTimeAttackStart(void)
{
    int temp_v1_2;
    int var_a3;

    if (_screenState == 0) {
        if ((_screenTimer == ((_screenTimer / 15) * 0xF)) && (_screenTimer < 0x2E)) {
            vs_main_playSfxDefault(0x7E, 0x7A);
            vs_main_playSfxDefault(0x7E, 0x7B);
            vs_main_playSfxDefault(0x7E, 0x7C);
        }

        _renderTimeAttackHeader(160, 48, _screenTimer);
        _renderCourse(160, 92, _screenTimer - 15);
        _renderBossName(160, 120, _screenTimer - 30);
        _renderBestTimeHeader(160, 156, _screenTimer - 45);

        ++_screenTimer;

        if (vs_main_buttonsPressed.all & PADRright) {
            _screenState = 2;
            _screenTimer = 0;
        } else if (_screenTimer >= 90) {
            _screenState = 1;
            _screenTimer = 8;
        }
    } else if (_screenState == 1) {
        --_screenTimer;

        _renderTimeAttackHeader(160, 48, _screenTimer);
        _renderCourse(160, 92, _screenTimer);
        _renderBossName(160, 120, _screenTimer);
        _renderBestTimeHeader(160, 156, _screenTimer);

        if ((vs_main_buttonsPressed.all & PADRright) || (_screenTimer == 0)) {
            _screenState = 2;
            _screenTimer = 0;
        }

    } else if (_screenState == 2) {
        func_8007C36C(4);
        func_8007DDAC(0);
        func_8007DDB8(&D_801096F0[0]);
        func_8007DDD4(&D_80109720[1]);
        func_8007DDF8((D_800F1A68_t*)(D_801096F0 + 2));
        func_8007DE2C(0);
        func_8007DE44(0U);
        func_8007DE5C(0);
        func_8007DD50(1);

        ++_screenState;

    } else if (_screenState == 3) {

        temp_v1_2 = _screenTimer / 15;

        if (_screenTimer == (temp_v1_2 * 0xF)) {

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

        if (_screenTimer >= 45) {

            if (_screenTimer == 45) {
                func_8007DE2C(1);
                func_8007DDB8(&D_801096F0[1]);
                func_8007DDD4(&D_80109720[0]);
            } else if (_screenTimer == 0x2E) {
                func_8007DE2C(0);
            } else if (_screenTimer == 0x37) {
                func_8007DDD4(&D_80109720[2]);
            } else if (_screenTimer == 0x3C) {
                func_8007DDB8(&D_801096F0[0]);
            }

            var_a3 = 104 - _screenTimer;

            if (var_a3 < 45) {
                var_a3 = 45;
            }

            _renderStartCountdown(160, 120, var_a3);

        } else {
            var_a3 = _screenTimer % 15;

            if (var_a3 > 7) {
                var_a3 = 7;
            }

            var_a3 = D_801096D0[var_a3];

            _renderStartCountdown(var_a3 + 160, 120, _screenTimer);
        }

        ++_screenTimer;

        if (_screenTimer >= 62) {
            ++_screenState;
        }

    } else if (_screenState == 4) {
        func_8007C36C(2);
        func_8007DDB8(&D_801096F0[2]);
        func_8007DD50(0);
        func_8007E0A8(0x1D, 2, 5);

        return 1;
    }

    return 0;
}

void _renderTimeAttackHeader(int x, int y, int timer)
{
    static P_CODE colors[] = { { 128, 96, 64 }, { 200, 180, 160 }, { 128, 96, 64 } };

    if (timer < 0) {
        timer = 0;
    }
    if (timer > 0x40) {
        timer = 0x40;
    }
    if (timer > 0) {

        colors[0].code = timer;
        colors[1].code = timer;
        x -= (_disMap[disIndexAttack0TimeAttack].w
                 + _disMap[disIndexAttack0TimeAttack + 1].w)
          >> 1;

        _renderTexturePopIn(x, y, 100, colors);
        _renderTexturePopIn(x + _disMap[disIndexAttack0TimeAttack].w, y,
            disIndexAttack0TimeAttack + 1, &colors[1]);
    }
}

void _renderCourse(int x, int y, int timer)
{
    int new_var;

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        x -= (_disMap[disIndexAttack0Course].w + 24) >> 1;

        func_80105C34(x, y, disIndexAttack0Course, timer);

        new_var = x + 12;

        func_80105DD8(new_var + _disMap[disIndexAttack0Course].w, y - 1,
            vs_main_stateFlags.timeTrialBoss + 1, timer, 0x7FF4);
    }
}

void _renderBossName(int x, int y, int timer)
{
    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        if (vs_main_stateFlags.timeTrialBoss != 6) {

            func_80105C34(
                x
                    - (_disMap[vs_main_stateFlags.timeTrialBoss + disIndexAttack0Minotaur]
                            .w
                        >> 1),
                y, vs_main_stateFlags.timeTrialBoss + disIndexAttack0Minotaur, timer);

        } else {
            x -= (_disMap[disIndexAttack0Death].w + _disMap[disIndexAttack0OgreZombie].w)
              >> 1;

            func_80105C34(x, y, disIndexAttack0Death, timer);

            x += _disMap[disIndexAttack0Death].w;

            func_80105C34(x, y, disIndexAttack0OgreZombie, timer);
        }
    }
}

void _renderBestTimeHeader(int x, int y, int timer)
{
    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        int new_var;
        x -= (_disMap[disIndexAttack0BestTime].w + 96) >> 1;

        func_80105C34(x, y, disIndexAttack0BestTime, timer);

        x++;
        new_var = x + 11;

        func_80105F6C(new_var + _disMap[disIndexAttack0BestTime].w, y + 2, timer,
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][0]
                .time,
            0);
    }
}

void _renderStartCountdown(int x, int y, int timer)
{
    int temp_a2 = (timer / 15) + disIndexAttack0Three;

    func_80105C34(
        x - (_disMap[temp_a2].w / 2), y - (_disMap[temp_a2].h / 2), temp_a2, timer % 15);
}

void func_80104914(int arg0)
{
    RECT sp10;
    int var_a1;
    int var_a1_2;
    int var_a2;
    int i;
    int new_var2;
    int new_var3;
    int new_var4;

    for (i = 0; i < 32; ++i) {

        var_a1_2 = _timBuf[128 + i];

        var_a1 = ((_timBuf[32 + i] & 0x1F) * arg0)
               + ((_timBuf[96 + i] & 0x1F) * (0x10 - arg0));

        if (var_a1 < 0) {
            var_a1 += 0xF;
        }

        new_var2 = (var_a1 >> 4) & 0x1F;

        var_a2 = ((_timBuf[32 + i] & 0x3E0) * arg0)
               + ((_timBuf[0x60 + i] & 0x3E0) * (0x10 - arg0));

        if (var_a2 < 0) {
            var_a2 += 0xF;
        }

        new_var4 = new_var2 | ((var_a2 >> 4) & 0x3E0);

        var_a1_2 = ((_timBuf[0x20 + i] & 0x7C00) * arg0)
                 + ((_timBuf[0x60 + i] & 0x7C00) * (0x10 - arg0));

        if (var_a1_2 < 0) {
            var_a1_2 += 0xF;
        }

        new_var3 = (var_a1_2 >> 4) & 0x7C00;

        _timBuf[0x80 + i] = (new_var4 | new_var3) | (_timBuf[0x20 + i] & 0x8000);
    }

    setRECT(&sp10, 0x300, 0x1FF, 0xA0, 1);

    LoadImage(&sp10, (u_long*)_timBuf);
}

void func_80104A50(int arg0)
{
    RECT sp10;
    int var_a1;
    int var_a1_2;
    int var_a2;
    int i;
    int new_var2;
    int new_var3;
    int new_var4;

    for (i = 0; i < 32; ++i) {

        var_a1_2 = _timBuf[0x80 + i];

        var_a1 = ((_timBuf[0x60 + i] & 0x1F) * arg0)
               + ((_timBuf[0x40 + i] & 0x1F) * (0x10 - arg0));

        if (var_a1 < 0) {
            var_a1 += 0xF;
        }

        new_var2 = (var_a1 >> 4) & 0x1F;

        var_a2 = ((_timBuf[0x60 + i] & 0x3E0) * arg0)
               + ((_timBuf[0x40 + i] & 0x3E0) * (0x10 - arg0));

        if (var_a2 < 0) {
            var_a2 += 0xF;
        }

        new_var4 = new_var2 | ((var_a2 >> 4) & 0x3E0);

        var_a1_2 = ((_timBuf[0x60 + i] & 0x7C00) * arg0)
                 + ((_timBuf[0x40 + i] & 0x7C00) * (0x10 - arg0));

        if (var_a1_2 < 0) {
            var_a1_2 += 0xF;
        }

        new_var3 = (var_a1_2 >> 4) & 0x7C00;

        _timBuf[0x80 + i] = (new_var4 | new_var3) | (_timBuf[0x60 + i] & 0x8000);
    }

    setRECT(&sp10, 0x300, 0x1FF, 0xA0, 1);

    LoadImage(&sp10, (u_long*)_timBuf);
}

void _renderCongratulations(int x, int y, int timer)
{
    static P_CODE colors[] = { { 128, 96, 64 }, { 200, 180, 160 }, { 128, 96, 64 } };

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        colors[0].code = timer;
        colors[1].code = timer;
        x -= (_disMap[disIndexRank0Congratulations].w
                 + _disMap[disIndexRank0Congratulations + 1].w)
          >> 1;

        _renderTexturePopIn(x, y, disIndexRank0Congratulations, colors);
        _renderTexturePopIn(x + _disMap[disIndexRank0Congratulations].w, y,
            disIndexRank0Congratulations + 1, &colors[1]);
    }
}

void _renderScore(int x, int y, int timer, int arg3 __attribute__((unused)))
{
    static P_CODE D_80109744[] = { { 100, 180, 220 }, { 100, 180, 220 } };

    char buf[16];
    int i;
    int new_var;

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        D_80109744[0].code = timer;

        sprintf(buf, "%09d", _score);

        new_var = _disMap[disIndexRank0Score].w + _disMap[disIndexRank0Colon].w;
        x -= (((_disMap[disIndexRank0Comma].w * 2)
                  + (new_var + _disMap[disIndexRank0Pts].w))
                 + 116)
          >> 1;

        func_8010664C(x, y, disIndexRank0Score, D_80109744);

        x += _disMap[disIndexRank0Score].w;

        func_8010664C(x, y + 7, disIndexRank0Colon, D_80109744);

        i = 2;
        x = (x + i) + _disMap[disIndexRank0Colon].w;

        for (i = 0; i < 9; ++i) {
            func_8010664C(x, y + 3, buf[i] - '0', D_80109744);

            x += 0xC;

            if ((i == 2) || (i == 5)) {
                func_8010664C(x, y + 14, 10, D_80109744);

                x += _disMap[disIndexRank0Comma].w + 3;
            }
        }

        func_8010664C(x, y + 8, disIndexRank0Pts, D_80109744);
    }
}

void _renderIncrementalScore(int x, int y, int timer, int arg3 __attribute__((unused)))
{
    static P_CODE colors[] = { { 100, 180, 220 }, { 100, 180, 220 } };

    char buf[16];
    int temp_s2;
    int i;
    int v;

    if (timer < 0) {
        timer = 0;
    }
    if (timer > 64) {
        timer = 64;
    }
    if (timer <= 0) {
        return;
    }

    temp_s2 = x + (timer * 8);

    if (_score != 0) {
        if (timer >= 32) {

            if (_onScreenScore == 0) {

                _incrementingScore = 1;

                vs_main_playSfxDefault(0x7E, 0x72);
            }

            if (_onScreenScore == _score) {
                if (_incrementingScore != 0) {

                    _incrementingScore = 0;

                    func_80045D64(0x7E, 0x72);
                    vs_main_playSfxDefault(0x7E, 0x73);
                }
            }
        }
    }

    if (timer >= 32) {
        _onScreenScore = (_score >> 5) * (timer - 32);
    }

    if (timer == 64) {
        _onScreenScore = _score;
    }

    sprintf(buf, "%09d", _onScreenScore);

    v = _disMap[disIndexRank0Score].w + _disMap[disIndexRank0Colon].w
      + _disMap[disIndexRank0Pts].w;
    x -= (((_disMap[disIndexRank0Comma].w * 2) + v) + 116) >> 1;

    _renderTextureWipe(x, y, disIndexRank0Score, colors, temp_s2);

    x += _disMap[disIndexRank0Score].w;

    _renderTextureWipe(x, y + 7, disIndexRank0Colon, colors, temp_s2);

    i = 2;
    x = x + i + _disMap[disIndexRank0Colon].w;

    for (i = 0; i < 9; ++i) {
        _renderTextureWipe(x, y + 3, buf[i] - '0', colors, temp_s2);

        x += 12;

        if ((i == 2) || (i == 5)) {
            _renderTextureWipe(x, y + 14, disIndexRank0Comma, colors, temp_s2);

            x += 3 + _disMap[disIndexRank0Comma].w;
        }
    }

    _renderTextureWipe(x, y + 8, 0x14, colors, temp_s2);
}

void _renderMapCompletion(int x, int y, int timer, int arg3 __attribute__((unused)))
{
    static P_CODE D_80109754[] = { { 100, 180, 220 }, { 100, 180, 220 } };

    char buf[4];
    int i;

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        D_80109754[0].code = timer;

        sprintf(buf, "%03d", _mapCompletion);

        x -= (_disMap[21].w + _disMap[26].w + _disMap[19].w + 0x26) >> 1;
        i = 2;

        func_8010664C(x, y, 0x15, D_80109754);

        x += _disMap[21].w;

        func_8010664C(x, y + 7, 0x1A, D_80109754);

        x = x + i + _disMap[26].w;

        for (i = 0; i < 3; ++i) {
            func_8010664C(x, y + 3, buf[i] - '0', D_80109754);

            x += 0xC;
        }

        func_8010664C(x, y + 8, 0x13, D_80109754);
    }
}

void _renderIncrementalMapCompletion(
    int arg0, int arg1, int arg2, int arg3 __attribute__((unused)))
{
    static P_CODE colors[] = { { 100, 180, 220 }, { 100, 180, 220 } };

    char buf[8];
    int temp_s4;
    int i;

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 <= 0) {
        return;
    }

    temp_s4 = arg0 + (arg2 * 8);

    if (_mapCompletion != 0) {
        if (arg2 >= 0x20) {
            if (_onScreenMapCompletion == 0) {
                _incrementingMapCompletion = 1;

                vs_main_playSfxDefault(0x7E, 0x72);
            }

            if (_onScreenMapCompletion == _mapCompletion) {
                if (_incrementingMapCompletion != 0) {
                    _incrementingMapCompletion = 0;

                    func_80045D64(0x7E, 0x72);
                    vs_main_playSfxDefault(0x7E, 0x73);
                }
            }
        }
    }

    if (arg2 >= 32) {
        if (_mapCompletion >= 32) {
            _onScreenMapCompletion = (_mapCompletion * (arg2 - 32)) >> 5;
        } else if (_onScreenMapCompletion < _mapCompletion) {
            ++_onScreenMapCompletion;
        }
    }

    sprintf(buf, "%03d", _onScreenMapCompletion);

    arg0 -= (_disMap[disIndexRank0MapCompleted].w + _disMap[disIndexRank0Colon].w
                + _disMap[disIndexRank0Percent].w + 38)
         >> 1;

    _renderTextureWipe(arg0, arg1, disIndexRank0MapCompleted, colors, temp_s4);

    arg0 += _disMap[disIndexRank0MapCompleted].w;
    i = 2;

    _renderTextureWipe(arg0, arg1 + 7, disIndexRank0Colon, colors, temp_s4);
    arg0 = arg0 + i + _disMap[disIndexRank0Colon].w;

    for (i = 0; i < 3; ++i) {
        _renderTextureWipe(arg0, arg1 + 3, buf[i] - '0', colors, temp_s4);

        arg0 += 12;
    }

    _renderTextureWipe(arg0, arg1 + 8, disIndexRank0Percent, colors, temp_s4);
}

void _renderRiskbreakerRankHeader(int x, int y, int timer)
{
    static P_CODE colors[] = { { 200, 80, 20 }, { 200, 80, 20 } };

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        colors[0].code = timer;

        func_8010664C(x - (_disMap[disIndexRank0RiskbreakerRank].w >> 1), y,
            disIndexRank0RiskbreakerRank, colors);
    }
}

void _renderRiskbreakerRank(int x, int y, int timer)
{
    static P_CODE colors[] = { { 128, 128, 128 }, { 128, 128, 128 } };

    int xInset;
    int i;

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    xInset = 0;

    if (timer > 0) {

        colors[0].code = timer;

        for (i = 0; i < _riskbreakerRanks[_rank][0]; ++i) {
            xInset += _disMap[_riskbreakerRanks[_rank][i + 1]].w;
        }

        xInset /= 2;
        x -= xInset;

        for (i = 0; i < _riskbreakerRanks[_rank][0]; ++i) {
            _renderTexturePopIn(x, y, _riskbreakerRanks[_rank][i + 1], colors);

            x += _disMap[_riskbreakerRanks[_rank][i + 1]].w;
        }
    }
}

void func_8010559C(int arg0, int arg1, int arg2)
{
    static P_CODE D_80109774[] = { { 128, 128, 128 }, { 128, 128, 128 } };

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 > 0) {
        D_80109774[0].code = arg2;
        arg0 -= (_disMap[70].w + _disMap[71].w) >> 1;

        _renderTexturePopIn(arg0, arg1, 70, D_80109774);
        _renderTexturePopIn(arg0 + _disMap[70].w, arg1, 71, D_80109774);
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

    if (_timeTrialTime < 0x1E00) {
        var_a2 = 0;
    } else if (_timeTrialTime <= 0xFFFF) {
        var_a2 = 1;
    } else if (_timeTrialTime <= 0x11DFF) {
        var_a2 = 2;
    } else if (_timeTrialTime <= 0x1FFFF) {
        var_a2 = 3;
    } else {
        var_a2 = 4;
    }

    func_80105C34(arg0, arg1, var_a2 + 0x4E, arg2);
}

void func_801056E8(int arg0, int arg1, int arg2)
{
    static P_CODE D_8010977C[] = { { 0x80, 0x80, 0x80 }, { 0x80, 0x80, 0x80 } };

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

    if (_timeTrialTime < 0x1E00) {
        arg2 = 0;
    } else if (_timeTrialTime <= 0xFFFF) {
        arg2 = 1;
    } else if (_timeTrialTime <= 0x11DFF) {
        arg2 = 2;
    } else if (_timeTrialTime <= 0x1FFFF) {
        arg2 = 3;
    } else {
        arg2 = 4;
    }

    _renderTextureWipe(arg0, arg1, arg2 + 0x4E, D_8010977C, arg3);
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

        arg0 += _disMap[72].w;

        func_80105F6C(arg0, arg1 + 2, arg2, _timeTrialTime, 0);
    }
}

void func_8010581C(int arg0, int arg1, int arg2)
{
    int temp_a3;
    int var_a3;
    int* new_var4;

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 >= 0x41) {
        arg2 = 0x40;
    }

    if (arg2 > 0) {
        func_80105C34(arg0, arg1, 0x48, arg2);

        arg0 += _disMap[72].w;

        if (arg2 >= 0x10) {
            int a0 = (_timeTrialTime >> 0x10) & 0xFF;
            int a1 = (_timeTrialTime >> 8) & 0xFF;
            int a2 = _timeTrialTime & 0xFF;
            temp_a3 = ((a0 * 6000) + (a1 * 100)) + a2;
            var_a3 = temp_a3;
            var_a3 = ((*(new_var4 = &var_a3)) * (arg2 - 0x10)) / 48;
            a0 = var_a3 / 6000;
            var_a3 = var_a3 % 6000;
            a1 = var_a3 / 100;
            var_a3 = var_a3 % 100;
            var_a3 = (a0 << 0x10) | (a1 << 8) | var_a3;
        } else {
            var_a3 = 0;
        }

        func_80105F6C(arg0, arg1 + 2, arg2, var_a3, 0);
    }
}

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
        temp_v0 = _newTimeSlot == i;
        if (temp_v0 != 0) {
            var_s3 = 0x7FF8;
        }

        func_80105F6C(arg0 - 0x54, arg1 + i * 0x14 + 2, arg2,
            vs_main_scoredata
                .bossTimeTrialScores[0][vs_main_stateFlags.timeTrialBoss * 3 + i]
                .time,
            temp_v0);
        func_80105DD8(
            (arg0 - _disMap[75 + i].w) - 0x58, arg1 + i * 0x14, i + 0x4B, arg2, var_s3);
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

    temp_t1 = _newTimeSlot == arg2;
    var_s3 = 0x7FF2;

    if (temp_t1 != 0) {
        var_s3 = 0x7FF8;
    }

    func_80105F6C(arg0 - 0x54, arg1 + (arg2 * 0x14) + 2, arg3,
        vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeTrialBoss][arg2]
            .time,
        temp_t1);
    func_80105DD8((arg0 - _disMap[arg2 + 0x4B].w) - 0x58, arg1 + (arg2 * 0x14),
        arg2 + 0x4B, arg3, var_s3);
}

void func_80105C34(int arg0, int arg1, int arg2, int arg3)
{
    _texture_t* temp_a2;
    POLY_FT4* poly;
    void** scratch;

    if (arg3 <= 0) {
        return;
    }

    poly = *(void**)getScratchAddr(0);
    temp_a2 = &_disMap[arg2];
    setPolyFT4(poly);
    setXY4(poly, arg0, arg1, temp_a2->w + arg0, arg1, arg0, temp_a2->h + arg1,
        temp_a2->w + arg0, temp_a2->h + arg1);
    setUV4(poly, temp_a2->x, temp_a2->y, temp_a2->x + temp_a2->w, temp_a2->y, temp_a2->x,
        temp_a2->y + temp_a2->h, temp_a2->x + temp_a2->w, temp_a2->y + temp_a2->h);
    setSemiTrans(poly, 1);

    if (arg3 < 8) {
        setRGB0(poly, arg3 * 0x10, arg3 * 0x10, arg3 * 0x10);
        poly->tpage = temp_a2->tpage | 0x20;
        poly->clut = temp_a2->clut + 1;
    } else {
        setRGB0(poly, 0x80, 0x80, 0x80);
        poly->tpage = temp_a2->tpage;
        poly->clut = temp_a2->clut;
    }

    scratch = (void**)getScratchAddr(0);

    AddPrim(scratch[1] - 0x1C, poly++);

    scratch[0] = poly;
}

void func_80105DD8(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    _texture_t* temp_a2;
    POLY_FT4* poly;
    void** scratch;

    if (arg3 <= 0) {
        return;
    }

    poly = *(void**)getScratchAddr(0);
    temp_a2 = &_disMap[arg2];
    setPolyFT4(poly);
    setXY4(poly, arg0, arg1, temp_a2->w + arg0, arg1, arg0, temp_a2->h + arg1,
        temp_a2->w + arg0, temp_a2->h + arg1);
    setUV4(poly, temp_a2->x, temp_a2->y, temp_a2->x + temp_a2->w, temp_a2->y, temp_a2->x,
        temp_a2->y + temp_a2->h, temp_a2->x + temp_a2->w, temp_a2->y + temp_a2->h);
    setSemiTrans(poly, 1);

    if (arg3 < 8) {
        setRGB0(poly, arg3 * 0x10, arg3 * 0x10, arg3 * 0x10);
        poly->tpage = temp_a2->tpage | 0x20;
        poly->clut = arg4 + 1;
    } else {
        setRGB0(poly, 0x80, 0x80, 0x80);
        poly->tpage = temp_a2->tpage;
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

void func_80107698(int x, int y, int texId);

void _renderStatWheel(int x, int y, int timer, int arg3)
{
    static P_CODE colors[] = { { 128, 96, 64 }, { 200, 180, 160 } };

    RECT sp18;
    char sp20[8];
    DR_AREA* area;
    int i;
    int j;
    void** p;
    void** q;
    int new_var2;
    int v1;
    int len;
    int temp;

    if (timer < 0) {
        timer = 0;
    }
    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        colors[0].code = timer;
        x -= (_disMap[11].w + _disMap[26].w + _disMap[14].w + _disMap[24].w + 0xE) >> 1;
        func_8010664C(x, y, 0xB, colors);
        x += _disMap[11].w;
        func_8010664C(x, y, 0x1A, colors);
        x += 2 + _disMap[26].w;
        new_var2 = 0x10;
        p = (void**)0x1F800000;
        area = p[0];
        SetDrawArea(area, &vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip);
        AddPrim(p[1] - 0x1C, area++);
        p[0] = area;

        if (vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip.x >= 0x140) {
            sp18.x = 0x140;
        } else {
            sp18.x = 0;
        }
        sp18.y = y - (_buffReelSpinSpeed >> 3);
        sp18.w = 0x140;
        sp18.h = ((_buffReelSpinSpeed >> 3) * 2) + new_var2;

        if (arg3 < 2) {
            int a0 = x;
            int new_var;
            y += 8 + (_buffReelSelection & 0xF);

            for (i = 0; i < 3; ++i) {
                x = a0;
                new_var = i - 1;
                v1 = (_buffReelSelection / 16);
                v1 += new_var;
                temp = v1 & 0xF;
                func_80107698(x, y - 1, _buffReels[_buffReelIndex][v1 & 0xF].stat);
                x += _disMap[_buffReels[_buffReelIndex][v1 & 0xF].stat].w;
                func_80107698(x, y + 4, 0x18);
                x += _disMap[24].w;
                sprintf(sp20, "%d", _buffReels[_buffReelIndex][v1 & 0xF].amount);
                len = strlen(sp20);
                for (j = 0; j < len; ++j) {
                    func_80107698(x, y - 1, sp20[j] - 0x30);
                    x += 0xC;
                }
                y -= 16;
            }

        } else {
            temp = (char)_buffReelSelection / 16;
            func_80105DD8(x, y - 1, _buffReels[_buffReelIndex][temp].stat, timer, 0x7FF2);
            x += _disMap[_buffReels[_buffReelIndex][temp].stat].w;
            func_80105DD8(x, y + 4, 0x18, timer, 0x7FF2);
            x += _disMap[24].w;
            sprintf(sp20, "%d", _buffReels[_buffReelIndex][temp].amount);
            len = strlen(sp20);
            for (j = 0; j < len; ++j) {
                func_80105DD8(x, y - 1, sp20[j] - 0x30, timer, 0x7FF2);
                x += 0xC;
            }
        }
        q = (void**)0x1F800000;
        area = q[0];
        SetDrawArea(area, &sp18);
        AddPrim(q[1] - 0x1C, area++);
        q[0] = area;
    }
}

void _renderPressButtonPrompt(int x, int y, int arg2, int arg3)
{
    POLY_FT4* poly;
    void** p;
    int v1;

    if (arg2 < 0) {
        return;
    }

    v1 = x + 288;

    if (arg2 > 48) {
        arg2 = 48;
    }

    x = (v1 - (arg2 * 6));

    vs_battle_renderTextRawColor(
        "PRESS", vs_getXY_2(x + 18, y), vs_getRGB888(255, 128, 128), NULL);
    vs_battle_renderTextRawColor(
        "BUTTON", vs_getXY_2(x + 18, y + 10), vs_getRGB888(255, 128, 128), NULL);

    y += 22;

    if ((arg3 & 0xF) < 9) {
        v1 = y - 16;
        y = v1 + ((arg3 & 0xF) >> 1);
    } else {
        v1 = y - 10;
        y = v1 - ((arg3 & 0xF) >> 2);
    }

    poly = *(void**)0x1F800000;

    setPolyFT4(poly);
    setShadeTex(poly, 1);
    setXY4(poly, x, y - 2, x + 16, y - 2, x, y + 14, x + 16, y + 0xE);
    setUV4(poly, 32, 128, 48, 128, 32, 144, 48, 144);
    setTPage(poly, 0, 0, 768, 0);
    setClut(poly, 944, 223);

    p = (void**)0x1F800000;

    AddPrim(p[1] - 0x1C, poly++);

    p[0] = poly;
}

void func_8010664C(int arg0, int arg1, int arg2, P_CODE arg3[])
{
    POLY_GT4* poly;
    void** p;

    if (arg3[0].code != 0) {
        poly = *(void**)0x1F800000;
        setPolyGT4(poly);
        setXY4(poly, arg0, arg1, _disMap[arg2].w + arg0, arg1, arg0,
            _disMap[arg2].h + arg1, _disMap[arg2].w + arg0, _disMap[arg2].h + arg1);
        setUV4(poly, _disMap[arg2].x, _disMap[arg2].y, _disMap[arg2].x + _disMap[arg2].w,
            _disMap[arg2].y, _disMap[arg2].x, _disMap[arg2].y + _disMap[arg2].h,
            _disMap[arg2].x + _disMap[arg2].w, _disMap[arg2].y + _disMap[arg2].h);
        if (arg3[0].code < 8) {
            setRGB0(poly, (arg3[0].r0 * arg3[0].code) / 8,
                (arg3[0].g0 * arg3[0].code) / 8, (arg3[0].b0 * arg3[0].code) / 8);
            setRGB1(poly, (arg3[1].r0 * arg3[0].code) / 8,
                (arg3[1].g0 * arg3[0].code) / 8, (arg3[1].b0 * arg3[0].code) / 8);
            setRGB2(poly, (arg3[0].r0 * arg3[0].code) / 8,
                (arg3[0].g0 * arg3[0].code) / 8, (arg3[0].b0 * arg3[0].code) / 8);
            setRGB3(poly, (arg3[1].r0 * arg3[0].code) / 8,
                (arg3[1].g0 * arg3[0].code) / 8, (arg3[1].b0 * arg3[0].code) / 8);
        } else {
            setRGB0(poly, arg3[0].r0, arg3[0].g0, arg3[0].b0);
            setRGB1(poly, arg3[1].r0, arg3[1].g0, arg3[1].b0);
            setRGB2(poly, arg3[0].r0, arg3[0].g0, arg3[0].b0);
            setRGB3(poly, arg3[1].r0, arg3[1].g0, arg3[1].b0);
        }

        setSemiTrans(poly, 1);

        if (arg3[0].code < 8) {
            poly->clut = _disMap[arg2].clut + 1;
            poly->tpage = _disMap[arg2].tpage | 0x20;
        } else {
            poly->clut = _disMap[arg2].clut;
            poly->tpage = _disMap[arg2].tpage;
        }

        p = (void**)0x1F800000;

        AddPrim(p[1] - 0x1C, poly++);

        p[0] = poly;
    }
}

static inline int _adjust(int component, int weight)
{
    int ret = (component * weight) + ((4 - weight) * 192);
    return ret / 4;
}

void _renderTexturePopIn(int x, int y, int texId, P_CODE colors[])
{
    POLY_GT4* poly;
    void** p;

    if (colors[0].code != 0) {
        poly = *(void**)0x1F800000;

        setPolyGT4(poly);
        setXY4(poly, x, y, _disMap[texId].w + x, y, x, _disMap[texId].h + y,
            _disMap[texId].w + x, _disMap[texId].h + y);
        setUV4(poly, _disMap[texId].x, _disMap[texId].y,
            _disMap[texId].x + _disMap[texId].w, _disMap[texId].y, _disMap[texId].x,
            _disMap[texId].y + _disMap[texId].h, _disMap[texId].x + _disMap[texId].w,
            _disMap[texId].y + _disMap[texId].h);

        if (colors[0].code < 8) {
            setRGB0(poly, (colors[0].r0 * colors[0].code) / 8,
                (colors[0].g0 * colors[0].code) / 8, (colors[0].b0 * colors[0].code) / 8);
            setRGB1(poly, (colors[1].r0 * colors[0].code) / 8,
                (colors[1].g0 * colors[0].code) / 8, (colors[1].b0 * colors[0].code) / 8);
            setRGB2(poly, (colors[0].r0 * colors[0].code) / 8,
                (colors[0].g0 * colors[0].code) / 8, (colors[0].b0 * colors[0].code) / 8);
            setRGB3(poly, (colors[1].r0 * colors[0].code) / 8,
                (colors[1].g0 * colors[0].code) / 8, (colors[1].b0 * colors[0].code) / 8);
        } else if (colors[0].code == 8) {
            setRGB0(poly, 192, 192, 192);
            setRGB1(poly, 192, 192, 192);
            setRGB2(poly, 192, 192, 192);
            setRGB3(poly, 192, 192, 192);
        } else if (colors[0].code == 9) {
            setRGB0(poly, 224, 224, 224);
            setRGB1(poly, 224, 224, 224);
            setRGB2(poly, 224, 224, 224);
            setRGB3(poly, 224, 224, 224);
        } else if (colors[0].code < 14) {
            int temp_a0 = colors[0].code - 10;
            setRGB0(poly, _adjust(colors[0].r0, temp_a0), _adjust(colors[0].g0, temp_a0),
                _adjust(colors[0].b0, temp_a0));
            setRGB1(poly, _adjust(colors[1].r0, temp_a0), _adjust(colors[1].g0, temp_a0),
                _adjust(colors[1].b0, temp_a0));
            setRGB2(poly, _adjust(colors[0].r0, temp_a0), _adjust(colors[0].g0, temp_a0),
                _adjust(colors[0].b0, temp_a0));
            setRGB3(poly, _adjust(colors[1].r0, temp_a0), _adjust(colors[1].g0, temp_a0),
                _adjust(colors[1].b0, temp_a0));
        } else {
            setRGB0(poly, colors[0].r0, colors[0].g0, colors[0].b0);
            setRGB1(poly, colors[1].r0, colors[1].g0, colors[1].b0);
            setRGB2(poly, colors[0].r0, colors[0].g0, colors[0].b0);
            setRGB3(poly, colors[1].r0, colors[1].g0, colors[1].b0);
        }

        setSemiTrans(poly, 1);

        if (colors[0].code < 10) {
            poly->clut = _disMap[texId].clut + getClut(16, 0);
            poly->tpage = _disMap[texId].tpage | getTPage(0, 1, 0, 0);
        } else {
            poly->clut = _disMap[texId].clut;
            poly->tpage = _disMap[texId].tpage;
        }

        p = (void**)0x1F800000;

        AddPrim(p[1] - 0x1C, poly++);

        p[0] = poly;
    }
}

void _renderTextureWipe(int x, int y, int texId, P_CODE arg3[], int arg4)
{
    int temp_a1;
    int var_a0;
    int i;
    char var_s6;
    POLY_GT4* poly;
    void** scratch;

    if ((x + _disMap[texId].w) < (arg4 - 64)) {

        scratch = (void**)0x1F800000;
        poly = scratch[0];

        setPolyGT4(poly);
        setXY4(poly, x, y, _disMap[texId].w + x, y, x, _disMap[texId].h + y,
            _disMap[texId].w + x, _disMap[texId].h + y);
        setUV4(poly, _disMap[texId].x, _disMap[texId].y,
            _disMap[texId].x + _disMap[texId].w, _disMap[texId].y, _disMap[texId].x,
            _disMap[texId].y + _disMap[texId].h, _disMap[texId].x + _disMap[texId].w,
            _disMap[texId].y + _disMap[texId].h);
        setRGB0(poly, arg3[0].r0, arg3[0].g0, arg3[0].b0);
        setRGB1(poly, arg3[1].r0, arg3[1].g0, arg3[1].b0);
        setRGB2(poly, arg3[0].r0, arg3[0].g0, arg3[0].b0);
        setRGB3(poly, arg3[1].r0, arg3[1].g0, arg3[1].b0);
        setSemiTrans(poly, 1);

        poly->clut = _disMap[texId].clut;
        poly->tpage = _disMap[texId].tpage;

        scratch = (void**)0x1F800000;

        AddPrim(scratch[1] - 0x1C, poly++);

        scratch[0] = poly;
        return;
    }

    if (x < arg4) {

        scratch = (void**)0x1F800000;
        poly = scratch[0];
        var_s6 = _disMap[texId].x;

        for (i = 0; i < _disMap[texId].w; i += 12, x += 12, var_s6 += 12) {

            var_a0 = 12;

            if ((i + 12) >= _disMap[texId].w) {
                var_a0 = _disMap[texId].w - i;
            }

            setPolyGT4(poly);
            temp_a1 = x + var_a0;
            setXY4(poly, x, y, temp_a1, y, x, _disMap[texId].h + y, temp_a1,
                _disMap[texId].h + y);
            setUV4(poly, var_s6, _disMap[texId].y, var_s6 + var_a0, _disMap[texId].y,
                var_s6, _disMap[texId].y + _disMap[texId].h, var_s6 + var_a0,
                _disMap[texId].y + _disMap[texId].h);

            var_a0 = arg4 - x;

            if (var_a0 > 64) {
                var_a0 = 64;
            }

            if (var_a0 < 0) {
                var_a0 = 0;
            }

            setRGB0(poly, (arg3[0].r0 * var_a0) / 64, (arg3[0].g0 * var_a0) / 64,
                (arg3[0].b0 * var_a0) / 64);
            setRGB2(poly, (arg3[0].r0 * var_a0) / 64, (arg3[0].g0 * var_a0) / 64,
                (arg3[0].b0 * var_a0) / 64);

            var_a0 = arg4 - temp_a1;

            if (var_a0 > 64) {
                var_a0 = 64;
            }

            if (var_a0 < 0) {
                var_a0 = 0;
            }

            setRGB1(poly, (arg3[1].r0 * var_a0) / 64, (arg3[1].g0 * var_a0) / 64,
                (arg3[1].b0 * var_a0) / 64);
            setRGB3(poly, (arg3[1].r0 * var_a0) / 64, (arg3[1].g0 * var_a0) / 64,
                (arg3[1].b0 * var_a0) / 64);

            setSemiTrans(poly, 1);

            poly->clut = (_disMap[texId].clut + 1);
            poly->tpage = (_disMap[texId].tpage | 0x20);

            scratch = (void**)0x1F800000;

            AddPrim(scratch[1] - 0x1C, poly++);
        }

        scratch = (void**)0x1F800000;
        scratch[0] = poly;
    }
}

void func_80107698(int x, int y, int texId)
{
    int i;
    int brightness;
    void** p = (void**)0x1F800000;
    POLY_FT4* poly = p[0];
    int texY = _disMap[texId].y;

    for (i = 0; i < _disMap[texId].h; ++i, ++y, ++texY) {

        setPolyFT4(poly);
        setXY4(
            poly, x, y, _disMap[texId].w + x, y, x, y + 1, _disMap[texId].w + x, y + 1);
        setUV4(poly, _disMap[texId].x, texY, _disMap[texId].x + _disMap[texId].w, texY,
            _disMap[texId].x, texY + 1, _disMap[texId].x + _disMap[texId].w, texY + 1);

        if (y < 190) {
            brightness = 128 - ((189 - y) * 16);

            if (brightness < 0) {
                brightness = 0;
            }

            setRGB0(poly, brightness, brightness, brightness);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage = _disMap[texId].tpage | getTPage(0, semiTransparencyFull, 0, 0);

            AddPrim(p[1] - 0x1C, poly++);

            setPolyFT4(poly);
            setXY4(poly, x, y, _disMap[texId].w + x, y, x, y + 1, _disMap[texId].w + x,
                y + 1);
            setUV4(poly, _disMap[texId].x, texY, _disMap[texId].x + _disMap[texId].w,
                texY, _disMap[texId].x, texY + 1, _disMap[texId].x + _disMap[texId].w,
                texY + 1);

            setRGB0(poly, brightness, brightness, brightness);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage =
                _disMap[texId].tpage | getTPage(0, semiTransparencySubtract, 0, 0);

            AddPrim(p[1] - 0x1C, poly++);

        } else if (y >= 206) {

            brightness = 128 - ((y - 206) * 16);

            if (brightness < 0) {
                brightness = 0;
            }

            setRGB0(poly, brightness, brightness, brightness);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage = _disMap[texId].tpage | getTPage(0, semiTransparencyFull, 0, 0);

            AddPrim(p[1] - 0x1C, poly++);

            setPolyFT4(poly);
            setXY4(poly, x, y, _disMap[texId].w + x, y, x, y + 1, _disMap[texId].w + x,
                y + 1);
            setUV4(poly, _disMap[texId].x, texY, _disMap[texId].x + _disMap[texId].w,
                texY, _disMap[texId].x, texY + 1, _disMap[texId].x + _disMap[texId].w,
                texY + 1);
            setRGB0(poly, brightness, brightness, brightness);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage =
                _disMap[texId].tpage | getTPage(0, semiTransparencySubtract, 0, 0);

            AddPrim(p[1] - 0x1C, poly++);

        } else {
            setRGB0(poly, 128, 128, 128);
            setSemiTrans(poly, 1);
            setClut(poly, 800, 511);
            poly->tpage = _disMap[texId].tpage;

            AddPrim(p[1] - 0x1C, poly++);
        }
    }

    p[0] = poly;
}

static short D_801099F4;
static short D_801099F6;

int _initCubePuzzleStart(void)
{
    static vs_main_CdQueueSlot* _iqDisCdSlot;
    static void* _iqDisData;

    vs_battle_room* room;
    short* var_a0;

    if (_submenuState == 0) {

        func_8007DFF0(0x1D, 2, 5);

        _iqDisData = vs_main_allocHeapR(_disFiles[iqDis].size);
        _iqDisCdSlot = vs_main_allocateCdQueueSlot(&_disFiles[iqDis]);

        vs_main_cdEnqueue(_iqDisCdSlot, _iqDisData);

        ++_submenuState;

    } else if (_submenuState == 1) {
        if (_iqDisCdSlot->state == vs_main_CdQueueStateLoaded) {
            int i;
            TIM_IMAGE tim;
            for (i = 0; i < 2; ++i) {

                vs_battle_setTimImage(_iqDisData + i * 0x8220, &tim);

                if (tim.paddr != NULL) {
                    tim.prect->x = 0x340 + i * 0x40;
                    tim.prect->y = 0x100;
                    tim.prect->h = 0xFF;

                    LoadImage(tim.prect, (u_long*)tim.paddr);
                }

                if (i == 0) {
                    if (tim.caddr != NULL) {
                        tim.crect->x = 0x300;
                        tim.crect->y = 0x1FF;
                        tim.crect->w = 0xA0;
                        tim.crect->h = 1;
                        tim.caddr[0] = 0;

                        LoadImage(tim.crect, tim.caddr);
                        vs_main_memcpy(_timBuf, tim.caddr, sizeof _timBuf);
                    }
                }
            }

            D_801099F4 = 600;
            D_801099F6 = 1;
            room = vs_battle_roomData.sectionF->rooms;
            var_a0 = _iqDisData + 0x10440;

            for (i = 0; i < 64; ++i, var_a0 += 4) {
                if ((var_a0[0] == room->zoneId) && (var_a0[1] == room->mapId)) {
                    D_801099F4 = var_a0[2];
                    D_801099F6 = var_a0[3];
                    break;
                }
            }

            vs_main_freeCdQueueSlot(_iqDisCdSlot);

            ++_submenuState;
        }
    } else {
        vs_main_freeHeapR(_iqDisData);

        _onScreenMapCompletion = 0;
        _onScreenScore = 0;
        _screenTimer = 0;
        _screenState = 0;
        _buffReelSpinSpeed = 0;
        _buffReelSelection = 0;
        _submenuState = 0;

        _nop0();
        return 1;
    }

    return 0;
}

int _initCubePuzzleEnd(void)
{
    if (vs_main_stateFlags.unkA3 != 0) {
        vs_main_stateFlags.unkA2 = 0x3B;
        vs_main_stateFlags.unkA1 = 0x3B;
        vs_main_stateFlags.unkA3 = 0;
        vs_main_stateFlags.unkA0 = 0x63;
    }

    return _initCubePuzzleStart();
}

int _initCubePuzzleQuit(void)
{
    static vs_main_CdQueueSlot* _escDisCdSLot;
    static void* _escDisData;

    TIM_IMAGE tim;
    int i;

    if (_submenuState == 0) {

        func_8007DFF0(0x1D, 1, 5);

        _escDisData = vs_main_allocHeapR(_disFiles[escDis].size);
        _escDisCdSLot = vs_main_allocateCdQueueSlot(&_disFiles[escDis]);

        vs_main_cdEnqueue(_escDisCdSLot, _escDisData);

        ++_submenuState;

    } else if (_submenuState == 1) {
        if (_escDisCdSLot->state == vs_main_CdQueueStateLoaded) {
            for (i = 0; i <= 0; ++i) {

                vs_battle_setTimImage(_escDisData + i * 0x8220, &tim);

                if (tim.paddr != NULL) {
                    tim.prect->x = 832 + i * 64;
                    tim.prect->y = 256;
                    tim.prect->h = 255;

                    LoadImage(tim.prect, (u_long*)tim.paddr);
                }

                if ((i == 0) && (tim.caddr != NULL)) {
                    tim.crect->x = 768;
                    tim.crect->y = 511;
                    tim.crect->w = 160;
                    tim.crect->h = 1;
                    *tim.caddr = 0;

                    LoadImage(tim.crect, tim.caddr);
                    vs_main_memcpy(_timBuf, tim.caddr, sizeof _timBuf);
                }
            }

            vs_main_freeCdQueueSlot(_escDisCdSLot);

            ++_submenuState;
        }
    } else {
        vs_main_freeHeapR(_escDisData);

        _onScreenMapCompletion = 0;
        _onScreenScore = 0;
        _screenTimer = 0;
        _screenState = 0;
        _buffReelSpinSpeed = 0;
        _buffReelSelection = 0;
        _submenuState = 0;
        return 1;
    }

    return 0;
}

int _renderCubePuzzleStart(void)
{
    if (_screenState != 0) {
        return 0;
    }

    if (_screenTimer == 0) {
        vs_main_playSfxDefault(0x7E, 0x7D);
    }

    if (_screenTimer == 30) {
        vs_main_playSfxDefault(0x7E, 0x7D);
    }

    _renderAverageTime(160, 64, _screenTimer);
    func_8010873C(128, 116, _screenTimer - 15);
    func_80108784(192, 144, _screenTimer - 30);
    _renderPressButtonPrompt(214, 187, _screenTimer - 30, _screenTimer);

    if (_screenTimer < 32767) {
        ++_screenTimer;
    }

    if (vs_main_buttonsPressed.all & PADRright) {
        if (_screenTimer >= 78) {

            func_80045D64(126, 0);
            func_8007E0A8(29, 2, 5);

            return 1;
        }

        func_80045D64(126, 0);

        _screenTimer = 78;
    }

    return 0;
}

static int D_8010978C[] = { 100, 200, 400, 600, 800, 1000, 2000, 3000, 4000, 5000, 6000,
    7000, 8000, 9000, 10000, 20000 };

int _renderCubePuzzleEnd(void)
{
    int temp_s0;
    int var_v0;

    var_v0 = rsin(_buffReelSpinSpeed);
    if (var_v0 < 0) {
        var_v0 += 0x1FF;
    }

    func_80104A50((var_v0 >> 9) + 8);

    _buffReelSpinSpeed = (_buffReelSpinSpeed + 0x40) & 0xFFF;

    if (_screenState == 0) {
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

        if (_screenTimer == 16) {
            vs_main_playSfxDefault(0x7E, 0x72);
        }

        if (_screenTimer == 64) {
            func_80045D64(0x7E, 0x72);
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        if (_screenTimer == 67) {
            vs_main_playSfxDefault(0x7E, 0x7D);
        }

        if (_screenTimer == 75) {
            vs_main_playSfxDefault(0x7E, 0x7D);
        }

        if (_screenTimer == 90) {
            vs_main_playSfxDefault(0x7E, 0x7D);
        }

        func_8010887C(0x58, 0x40, _screenTimer);
        func_80108688(0xA0, 0x64, _screenTimer - 0x4B);
        func_8010880C(0xA0, 0x7C, _screenTimer - 0x5A, temp_s0);
        _renderPressButtonPrompt(0xD6, 0xBB, _screenTimer - 0x5A, _screenTimer);

        if (_screenTimer < 32767) {
            ++_screenTimer;
        }

        if (vs_main_buttonsPressed.all & PADRright) {
            if (_screenTimer >= 138) {

                func_80045D64(0x7E, 0);
                func_8007E0A8(0x1D, 2, 5);

                vs_main_scoredata.enemyKillStreak += D_8010978C[temp_s0];

                _nop1();

                return 1;
            }

            func_80045D64(0x7E, 0);

            _screenTimer = 138;
        }
    }
    return 0;
}

int _renderCubePuzzleQuit(void)
{
    int var_v0;

    var_v0 = rsin(_buffReelSpinSpeed);

    if (var_v0 < 0) {
        var_v0 += 0x1FF;
    }

    func_80104A50((var_v0 >> 9) + 8);

    _buffReelSpinSpeed = (_buffReelSpinSpeed + 0x40) & 0xFFF;

    if (_screenState != 0) {
        return 0;
    }

    if (_screenTimer == 0) {
        vs_main_playSfxDefault(0x7E, 0x7A);
    }

    if (_screenTimer == 0xF) {
        vs_main_playSfxDefault(0x7E, 0x7A);
    }

    func_801084F4(0x40, _screenTimer);
    func_80108564(0x64, _screenTimer - 0xF);
    _renderPressButtonPrompt(0xD6, 0xBB, _screenTimer - 0xF, _screenTimer);

    if (_screenTimer < 0x7FFF) {
        ++_screenTimer;
    }

    if (vs_main_buttonsPressed.all & PADRright) {
        if (_screenTimer >= 0x3F) {

            func_80045D64(0x7E, 0);
            func_8007E0A8(0x1D, 1, 5);
            _nop1();

            return 1;
        }

        _screenTimer = 0x3F;

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

void _renderAverageTime(int x, int y, int step)
{
    static P_CODE colors[] = { { 128, 96, 64 }, { 200, 180, 160 }, { 128, 96, 64 } };

    if (step < 0) {
        step = 0;
    }

    if (step > 64) {
        step = 64;
    }

    if (step > 0) {
        colors[0].code = step;
        colors[1].code = step;
        x -= (_disMap[disIndexIq0AverageTime].w + _disMap[disIndexIq0AverageTime + 1].w)
          >> 1;

        _renderTexturePopIn(x, y, disIndexIq0AverageTime, colors);
        _renderTexturePopIn(x + _disMap[disIndexIq0AverageTime].w, y,
            disIndexIq0AverageTime + 1, &colors[1]);
    }
}

void func_80108688(int arg0, int arg1, int arg2)
{
    static P_CODE D_801097D8[] = { { 0x80, 0x60, 0x40 }, { 0xC8, 0xB4, 0xA0 },
        { 0x80, 0x60, 0x40 } };

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 0x40) {
        arg2 = 0x40;
    }

    if (arg2 > 0) {
        D_801097D8[0].code = arg2;
        D_801097D8[1].code = arg2;
        arg0 -= (_disMap[105].w + _disMap[106].w) >> 1;

        _renderTexturePopIn(arg0, arg1, 0x69, D_801097D8);
        _renderTexturePopIn(arg0 + _disMap[105].w, arg1, 0x6A, &D_801097D8[1]);
    }
}

void func_8010873C(int x, int y, int arg2)
{
    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 > 0) {
        func_80105C34(x - (_disMap[104].w >> 1), y, 104, arg2);
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
    static P_CODE D_801097E4[] = { { 0x80, 0x80, 0x80 }, { 0x80, 0x80, 0x80 } };

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 0x40) {
        arg2 = 0x40;
    }

    if (arg2 > 0) {
        D_801097E4[0].code = arg2;

        _renderTexturePopIn(
            arg0 - (_disMap[arg3 + 0x6B].w >> 1), arg1, arg3 + 0x6B, D_801097E4);
    }
}

void func_8010887C(int arg0, int arg1, int arg2)
{
    int temp_a3;
    int var_a3;
    int new_var2;
    int* new_var4;

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 >= 0x41) {
        arg2 = 0x40;
    }

    if (arg2 > 0) {

        func_80105C34(arg0, arg1, 0x48, arg2);

        arg0 += _disMap[72].w;

        if (arg2 >= 0x10) {
            temp_a3 = vs_main_stateFlags.unkA1;
            new_var2 = vs_main_stateFlags.unkA2;
            temp_a3 = ((new_var2 * 0x1770) + (temp_a3 * 100)) + vs_main_stateFlags.unkA0;
            var_a3 = temp_a3;
            var_a3 = ((*(new_var4 = &var_a3)) * (arg2 - 0x10)) / 48;
            new_var2 = var_a3 / 6000;
            var_a3 = var_a3 % 6000;
            temp_a3 = var_a3 / 100;
            var_a3 = var_a3 % 100;
            var_a3 = (new_var2 << 0x10) | (temp_a3 << 8) | var_a3;
        } else {
            var_a3 = 0;
        }

        func_80105F6C(arg0, arg1 + 2, arg2, var_a3, 0);
    }
}

void _determineRank(void)
{
    static short titleThresholds[16] = { 16, 12, 8 };
    static u_int rankScores[] = { 100000000, 75000000, 60000000, 40000000, 32000000,
        24000000, 16000000, 12000000, 8000000, 5000000, 4000000, 3000000, 2000000,
        1000000, 500000, 0 };

    int unlockedTitles;
    int i;
    int flag;

    for (i = 0, unlockedTitles = 0, flag = 1; i < 16; ++i) {
        if (vs_main_scoredata.titles & (flag << i)) {
            ++unlockedTitles;
        }
    }

    for (i = 0; i < 16; ++i) {
        if (unlockedTitles >= titleThresholds[i]) {
            if (_score >= rankScores[i]) {
                _rank = i;
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
        if ((vs_main_scoredata.bossTimeTrialScores[i][0].time) != 0x800000) {
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

void _nop0(void) { }

void _nop1(void) { }

void func_80108E48(void)
{
    int new_var = vs_main_scoredata.enemyKillStreak + 100000;

    vs_main_scoredata.enemyKillStreak = new_var - (vs_main_scoredata.bossHealCount * 100);

    if (vs_main_scoredata.enemyKillStreak > 999999999) {
        vs_main_scoredata.enemyKillStreak = 999999999;
    }

    vs_main_scoredata.bossHealCount = 0;
}

void _nop2(void) { }

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
