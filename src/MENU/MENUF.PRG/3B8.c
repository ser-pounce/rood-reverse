#include "common.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/cd.h"
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/graphics.h"
#include "src/SLUS_010.40/memory.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"
#include "src/BATTLE/BATTLE.PRG/actor.h"
#include "src/BATTLE/BATTLE.PRG/battleUi.h"
#include "src/BATTLE/BATTLE.PRG/battleUnk.h"
#include "src/BATTLE/BATTLE.PRG/menuState.h"
#include "src/BATTLE/BATTLE.PRG/mpd.h"
#include "build/src/include/lbas.h"
#include "gpu.h"
#include "texture.h"
#include <stdio.h>
#include <libetc.h>
#include <rand.h>
#include <string.h>
#include <abs.h>

typedef struct {
    short stat;
    short amount;
} BuffReels;

static int initMenu(void);
static int execMenu(void);

int vs_menuF_exec(u_char* state)
{
    switch (*state) {
    case 0:
        *state = 1;
        // Fallthrough
    case 1:
        *state += (initMenu() != 0);
        break;
    case 2:
        if (execMenu() != 0) {
            *state = 0;
            return 1;
        }
        break;
    }
    return 0;
}

#include "src/MENU/unused_vertices.h"

enum disFileIndices { rankDis, timeDis, attackDis, iqDis, escDis };

static vs_Main_CdFile const disFiles[] = { { VS_RANK_DIS_LBA, VS_RANK_DIS_SIZE },
    { VS_TIME_DIS_LBA, VS_TIME_DIS_SIZE }, { VS_ATTACK_DIS_LBA, VS_ATTACK_DIS_SIZE },
    { VS_IQ_DIS_LBA, VS_IQ_DIS_SIZE }, { VS_ESC_DIS_LBA, VS_ESC_DIS_SIZE } };

static int initCongratulationsScreen(void);
static int initTimeAttackStart(void);
static int initTimeAttackEnd(void);
static void addHealBonus(void);
static void nop2(void);
static int initCubePuzzleStart(void);
static int initCubePuzzleEnd(void);
static int initCubePuzzleQuit(void);

int initMenu(void)
{
    int ret;

    switch (vs_main_stateFlags.menuFSubmenu) {
    case 0:
        ret = initCongratulationsScreen();
        break;

    case 1:
        ret = initTimeAttackStart();
        break;

    case 2:
        ret = initTimeAttackEnd();
        break;

    case 3:
        addHealBonus();
        nop2();

        ret = 1;
        break;

    case 4:
        ret = initCubePuzzleStart();
        break;

    case 5:
        ret = initCubePuzzleEnd();
        break;

    case 6:
        ret = initCubePuzzleQuit();
        break;
    }

    return ret;
}

static void func_80103748(void);
static int getTotalStrength(void);
static int getTotalIntelligence(void);
static int getTotalAgility(void);
static void calculateScore(void);
static void determineRank(void);

static u_int buffReelSelection;
static int riskbreakerRank;
static int clearCount;
static u_int score;
static u_int mapCompletionPercent;
static u_int elementAnimationState;
static int buffReelIndex;
static int onScreenMapCompletion;
static int onScreenScore;
static int screenTimer;
static int screenState;

int initCongratulationsScreen(void)
{
    static vs_Main_CdQueueSlot* cdSlot;
    static void* timData;

    int i;

    if (vs_battle_submenuState == 0) {

        func_8007DFF0(0x1D, 3, 5);

        timData = vs_main_allocHeapR(disFiles[rankDis].size);
        cdSlot = vs_main_allocateCdQueueSlot(&disFiles[rankDis]);

        vs_main_cdEnqueue(cdSlot, timData);

        ++vs_battle_submenuState;

    } else if (vs_battle_submenuState == 1) {
        if (cdSlot->state == vs_main_CdQueueStateLoaded) {

            for (i = 0; i < 3; ++i) {
                TIM_IMAGE tim;

                vs_battle_parseTim(timData + i * 0x8220, &tim);

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

            ++vs_battle_submenuState;
        }
    } else if (vs_main_clearMusicLoadQueue() == 0) {
        int strength;
        int intelligence;
        int agility;
        int mapCompletion;
        u_int chestsOpened;

        vs_main_playMusicSlot(2, 0x7F, 0);
        vs_main_freeHeapR(timData);

        onScreenMapCompletion = 0;
        onScreenScore = 0;
        screenTimer = 0;
        screenState = 0;
        elementAnimationState = 0;
        buffReelSelection = (rand() & 0xF0) | 8;

        strength = getTotalStrength();
        intelligence = getTotalIntelligence();
        agility = getTotalAgility();

        if ((intelligence >= strength) && (agility >= strength)) {
            buffReelIndex = 0;
        } else if (strength >= intelligence) {
            if (agility >= intelligence) {
                buffReelIndex = 1;
            } else {
                buffReelIndex = 2;
            }
        } else {
            buffReelIndex = 2;
        }

        vs_battle_submenuState = 0;

        addHealBonus();

        clearCount = vs_main_stateFlags.clearCount;

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

        mapCompletionPercent = (mapCompletion * 100) / 361;

        calculateScore();
        determineRank();

        return 1;
    }

    return 0;
}

static int newTimeSlot;
static int timeTrialTime;
static u_short clutBuf[160];

int initTimeAttackEnd(void)
{
    static vs_Main_CdQueueSlot* cdSlot;
    static void* timData;

    int i;
    int state = vs_battle_submenuState;

    if (state == 0) {

        func_8007DFF0(0x1D, 1, 5);

        timData = vs_main_allocHeapR(disFiles[timeDis].size);
        cdSlot = vs_main_allocateCdQueueSlot(&disFiles[1]);

        vs_main_cdEnqueue(cdSlot, timData);

        ++vs_battle_submenuState;

    } else if (state == 1) {
        if (cdSlot->state == vs_main_CdQueueStateLoaded) {
            TIM_IMAGE tim;

            vs_battle_parseTim(timData, &tim);

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
                vs_main_memcpy(clutBuf, tim.caddr, sizeof clutBuf);
            }

            vs_main_freeCdQueueSlot(cdSlot);
            func_80103748();

            ++vs_battle_submenuState;
        }
    } else if (vs_main_clearMusicLoadQueue() == 0) {

        vs_main_playMusicSlot(2, 0x7F, 0);

        timeTrialTime = (vs_main_stateFlags.timeAttackMins << 0x10)
                      | (vs_main_stateFlags.timeAttackSecs << 8)
                      | vs_main_stateFlags.timeAttackHundredths;

        if (timeTrialTime == 0) {
            timeTrialTime = (59 << 16) | (59 << 8) | 99;
        }

        for (i = 0; i < 3; ++i) {
            int record;

            if ((vs_main_scoredata
                        .bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss][i]
                        .time)
                < timeTrialTime) {
                continue;
            }

            for (record = 2; i < record; --record) {
                vs_main_scoredata
                    .bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss][record]
                    .time = vs_main_scoredata
                                .bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss]
                                                    [record - 1]
                                .time;
                vs_main_scoredata
                    .bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss][record]
                    .round = vs_main_scoredata
                                 .bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss]
                                                     [record - 1]
                                 .round;
                vs_main_scoredata
                    .bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss][record]
                    .difficulty =
                    vs_main_scoredata
                        .bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss]
                                            [record - 1]
                        .difficulty;
            }

            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss][i]
                .time = timeTrialTime;
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss][i]
                .round = vs_main_stateFlags.clearCount;
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss][i]
                .difficulty = vs_main_stateFlags.difficulty;

            break;
        }

        newTimeSlot = i;
        screenTimer = 0;
        screenState = 0;
        elementAnimationState = 0;
        vs_battle_submenuState = 0;

        vs_main_freeHeapR(timData);

        return 1;
    }
    return 0;
}

int initTimeAttackStart(void)
{
    static vs_Main_CdQueueSlot* cdSlot;
    static void* timData;

    if (vs_battle_submenuState == 0) {

        func_8007DFF0(0x1D, 2, 5);

        timData = vs_main_allocHeapR(disFiles[attackDis].size);
        cdSlot = vs_main_allocateCdQueueSlot(&disFiles[attackDis]);

        vs_main_cdEnqueue(cdSlot, timData);

        ++vs_battle_submenuState;
    } else if (vs_battle_submenuState == 1) {
        if (cdSlot->state == vs_main_CdQueueStateLoaded) {
            int i;
            TIM_IMAGE tim;

            for (i = 0; i < 2; ++i) {
                vs_battle_parseTim(timData + i * 0x8220, &tim);

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

            ++vs_battle_submenuState;
        }
    } else {
        vs_main_freeHeapR(timData);

        onScreenMapCompletion = 0;
        onScreenScore = 0;
        screenTimer = 0;
        screenState = 0;
        elementAnimationState = 0;
        buffReelSelection = 0;
        vs_battle_submenuState = 0;
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

static int renderCongratulationsScreen(void);
static int renderTimeAttackStart(void);
static int renderTimeAttackEnd(void);
static int renderCubePuzzleStart(void);
static int renderCubePuzzleEnd(void);
static int renderCubePuzzleQuit(void);

int execMenu(void)
{
    int ret;

    switch (vs_main_stateFlags.menuFSubmenu) {
    case 0:
        ret = renderCongratulationsScreen();
        break;

    case 1:
        ret = renderTimeAttackStart();
        break;

    case 2:
        ret = renderTimeAttackEnd();
        break;

    case 3:
        ret = 1;
        break;

    case 4:
        ret = renderCubePuzzleStart();
        break;

    case 5:
        ret = renderCubePuzzleEnd();
        break;

    case 6:
        ret = renderCubePuzzleQuit();
        break;
    }

    // BUG: potential garbage
    return ret;
}

enum disIndices {
    disIndexCommonZero,
    disIndexRank0Comma = 10,
    disIndexRank0Bonus,
    disIndexRank0RiskbreakerRank,
    disIndexRank0Str,
    disIndexRank0Agl,
    disIndexRank0Int,
    disIndexRank0Hp,
    disIndexRank0Mp,
    disIndexRank0Score,
    disIndexRank0Percent,
    disIndexRank0Pts,
    disIndexRank0MapCompleted,
    disIndexRank0Congratulations,
    disIndexRank0Plus = 24,
    disIndexRank0Minus,
    disIndexRank0Colon,
    disIndexRank1Grand,
    disIndexRank1Master,
    disIndexRank1Breaker,
    disIndexRank1Paladin,
    disIndexRank1Gladiator,
    disIndexRank1Raging,
    disIndexRank1Berserker,
    disIndexRank1Radiant,
    disIndexRank1Couragous,
    disIndexRank1Adventurer,
    disIndexRank1Knight,
    disIndexRank1Archer = 39,
    disIndexRank1DareDevil = 42,
    disIndexRank1Blade = 44,
    disIndexRank2Of = 48,
    disIndexRank2Mystic = 55,
    disIndexRank2Wanderer,
    disIndexRank2Destroyer,
    disIndexRank2Gladiator,
    disIndexRank2Spectrebane,
    disIndexRank2Normal,
    disIndexRank2Phantom,
    disIndexRank2Fighter,
    disIndexRank2Demon,
    disIndexRank2Eater,
    disIndexRank2Agent,
    disIndexRank2Dragon,
    disIndexRank2Slayer,
    disIndexRank2Cartographer,
    disIndexTime0NewRecord = 69,
    disIndexTime0TimeAttackResults,
    disIndexTime0Time = 72,
    disIndexTime0Prime,
    disIndexTime0DoublePrime,
    disIndexTime0First,
    disIndexTime0Excellent = 78,
    disIndexTime0Dash = 83,
    disIndexAttack0Course,
    disIndexAttack0Minotaur,
    disIndexAttack0Death = 91,
    disIndexAttack0OgreZombie = 93,
    disIndexAttack0BestTime = 95,
    disIndexAttack0Three,
    disIndexAttack0TimeAttack = 100,
    disIndexIq0EvolveOrDie = 102,
    disIndexIq0AverageTime = 104,
    disIndexIq0Foodchain = 105,
    disIndexIq1GameDesigner = 107,
    disIndexEsc0GivingUp = 123,
    disIndexEsc0Chicken = 125,
};

static Texture disMap[] = {
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
 * First element == word count, followed by indices into pages 1 and 2 of RANK.DIS
 */
static u_char riskbreakerRanks[][4] = { { 3, disIndexRank1Grand, disIndexRank1Master,
                                            disIndexRank1Breaker },
    { 2, disIndexRank1Grand, disIndexRank1Paladin },
    { 2, disIndexRank1Radiant, disIndexRank1Knight },
    { 2, disIndexRank1Raging, disIndexRank1Berserker },
    { 2, disIndexRank2Dragon, disIndexRank2Slayer },
    { 2, disIndexRank1Couragous, disIndexRank1Adventurer },
    { 2, disIndexRank1Master, disIndexRank1Gladiator },
    { 2, disIndexRank1Blade, disIndexRank1Master },
    { 2, disIndexRank2Mystic, disIndexRank2Wanderer }, { 1, disIndexRank1Paladin },
    { 1, disIndexRank2Spectrebane }, { 1, disIndexRank2Destroyer },
    { 1, disIndexRank1Berserker }, { 1, disIndexRank1DareDevil },
    { 1, disIndexRank1Gladiator }, { 2, disIndexRank2Normal, disIndexRank2Agent } };

enum BuffReelStats {
    buffReelStatStr = 13,
    buffReelStatAgi,
    buffReelStatInt,
    buffReelStatHp,
    buffReelStatMp
};

static BuffReels buffReels[][16] = {
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

static void renderCongratulations(int arg0, int arg1, int arg2);
static void renderIncrementalScore(int arg0, int arg1, int arg2, int arg3);
static void renderIncrementalMapCompletion(int arg0, int arg1, int arg2, int arg3);
static void renderRiskbreakerRankHeader(int arg0, int arg1, int arg2);
static void renderRiskbreakerRank(int arg0, int arg1, int arg2);
void renderStatWheel(int, int, int, int);
static void renderPressButtonPrompt(int, int, int, int);
static void renderScore(int arg0, int arg1, int arg2, int arg3);
static void renderMapCompletion(int arg0, int arg1, int arg2, int arg3);
static void raiseMaxStrength(int amount);
static void raiseMaxIntelligence(int amount);
static void raiseMaxAgility(int amount);
static void raiseMaxHP(int amount);
static void raiseMaxMP(int amount);

static int incrementingScore;
static int incrementingMapCompletion;

int renderCongratulationsScreen(void)
{
    static int stateTimer;

    if (screenState != 3) {
        if (screenTimer == 208) {
            vs_main_playSfxDefault(0x7E, 0x77);
            vs_main_playSfxDefault(0x7E, 0x78);
        }

        renderCongratulations(160, 40, screenTimer);
        renderIncrementalScore(160, 80, screenTimer - 32, screenState);
        renderIncrementalMapCompletion(160, 102, screenTimer - 112, screenState);
        renderRiskbreakerRankHeader(160, 138, screenTimer - 192);
        renderRiskbreakerRank(160, 154, screenTimer - 208);
        renderStatWheel(130, 190, screenTimer - 272, screenState);
    }

    if (screenState == 0) {
        buffReelSelection = (buffReelSelection + (elementAnimationState >> 3)) & 0xFF;
        if ((screenTimer - 272) > 0) {

            if (elementAnimationState == 8) {
                vs_main_playSfxDefault(0x7E, 0x74);
                vs_main_playSfxDefault(0x7E, 0x75);
            }

            if (elementAnimationState < 48) {
                if (screenTimer > 288) {
                    ++elementAnimationState;

                    renderPressButtonPrompt(214, 187, elementAnimationState, screenTimer);
                }
            } else {
                if ((vs_main_buttonsPressed.all & PADRright) || screenTimer > 2072) {

                    if (vs_main_buttonsPressed.all & PADRright) {
                        vs_main_playSfxDefault(0x7E, 0x76);
                    }

                    screenState = 1;
                    stateTimer = 0;

                    vs_main_fadeSfxVolume(0x7E, 0x74, 0x40, 0x30);
                    vs_main_fadeSfxVolume(0x7E, 0x75, 0x40, 0x30);
                    vs_main_fadeSfxPitch(0x7E, 0x74, -0x10, 0x30);
                    vs_main_fadeSfxPitch(0x7E, 0x75, -0x10, 0x30);
                }

                renderPressButtonPrompt(214, 187, 48, screenTimer);
            }
        } else if (vs_main_buttonsPressed.all & PADRright) {

            vs_main_evictSfx(0x7E, 0);

            screenTimer = 272;
            incrementingScore = 0;
            incrementingMapCompletion = 0;
            onScreenMapCompletion = mapCompletionPercent;
            onScreenScore = score;
        }
    } else if (screenState == 1) {
        int temp_v1;
        int temp_a2_2 = 48 - stateTimer;

        if (temp_a2_2 > 0) {
            renderPressButtonPrompt(0xD6, 0xBB, temp_a2_2, screenTimer);
        }

        temp_v1 = buffReelSelection + (elementAnimationState >> 3);
        buffReelSelection = temp_v1 & 0xFF;

        if (elementAnimationState >= 9) {
            --elementAnimationState;
        }

        temp_v1 &= 0xF;

        if ((temp_v1 == 8) && (elementAnimationState == temp_v1)) {

            vs_main_evictSfx(0x7E, 0x74);
            vs_main_evictSfx(0x7E, 0x75);
            vs_main_playSfxDefault(0x7E, 0x77);
            vs_main_playSfxDefault(0x7E, 0x78);

            screenState = 2;
            stateTimer = 0;
        }
    } else if (screenState == 2) {
        if ((vs_main_buttonsPressed.all & PADRright) || (stateTimer > 450)) {
            screenState = 3;
            stateTimer = 0;
        }
    } else {

        renderCongratulations(160, 40, 8 - stateTimer);
        renderScore(160, 80, 8 - stateTimer, 3);
        renderMapCompletion(160, 102, 8 - stateTimer, 3);
        renderRiskbreakerRankHeader(160, 138, 8 - stateTimer);
        renderRiskbreakerRank(160, 154, 8 - stateTimer);
        renderStatWheel(130, 190, 8 - stateTimer, 3);

        if (stateTimer >= 8) {
            int amount = buffReels[buffReelIndex][(char)buffReelSelection / 16].amount;
            switch ((short)(buffReels[buffReelIndex][(char)buffReelSelection / 16].stat
                            - 13)) {
            case 0:
                raiseMaxStrength(amount);
                break;

            case 1:
                raiseMaxAgility(amount);
                break;

            case 2:
                raiseMaxIntelligence(amount);
                break;

            case 3:
                raiseMaxHP(amount);
                break;

            case 4:
                raiseMaxMP(amount);
                break;
            }

            func_8007E0A8(0x1D, 3, 5);
            nop2();

            return 1;
        }
    }

    ++stateTimer;
    ++screenTimer;
    return 0;
}

static void pulseTimeAttackEnd(int);
static void renderTimeAttackResultsHeader(int arg0, int arg1, int arg2);
static void renderHeaderAndIncrementalTime(int, int, int);
static void renderTimeAttackRatingWipe(int arg0, int arg1, int arg2);
static void renderNewRecord(int arg0, int arg1, int arg2);
static void renderStoredTime(int arg0, int arg1, int arg2, int arg3);
static void renderHeaderAndTime(int, int, int);
static void renderTimeAttackRating(int arg0, int arg1, int arg2);
static void renderAllStoredTimes(int arg0, int arg1, int arg2);

int renderTimeAttackEnd(void)
{
    int var_v0 = rsin(elementAnimationState);

    pulseTimeAttackEnd(ABS(var_v0) / 256);

    elementAnimationState = (elementAnimationState + 64) & 0xFFF;

    if (screenState == 0) {
        if (screenTimer == 0x30) {
            vs_main_playSfxDefault(0x7E, 0x72);
        }

        if (screenTimer == 0x60) {
            vs_main_evictSfx(0x7E, 0x72);
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        renderTimeAttackResultsHeader(160, 52, screenTimer);
        renderHeaderAndIncrementalTime(16, 164, screenTimer - 32);
        renderTimeAttackRatingWipe(16, 144, screenTimer - 96);

        if (newTimeSlot == 0) {
            renderNewRecord(70, 184, screenTimer - 128);
        }

        if ((screenTimer == 128) && (newTimeSlot == 0)) {
            vs_main_playSfxDefault(0x7E, 0x76);
        }

        if (screenTimer == 160) {
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        if (screenTimer == 168) {
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        if (screenTimer == 176) {
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        renderStoredTime(304, 144, 0, screenTimer - 160);
        renderStoredTime(304, 144, 1, screenTimer - 168);
        renderStoredTime(304, 144, 2, screenTimer - 176);

        ++screenTimer;

        if ((vs_main_buttonsPressed.all & PADRright) || (screenTimer >= 192)) {

            vs_main_evictSfx(0x7E, 0);

            screenTimer = 0;
            ++screenState;
        }
    } else if (screenState == 1) {

        renderTimeAttackResultsHeader(160, 52, 64);
        renderHeaderAndTime(16, 164, 64);
        renderTimeAttackRating(16, 144, 64);

        if (newTimeSlot == 0) {
            renderNewRecord(70, 184, 64);
        }

        renderAllStoredTimes(304, 144, 64);

        ++screenTimer;

        if ((vs_main_buttonsPressed.all & PADRright) || (screenTimer >= 450)) {

            if (vs_main_buttonsPressed.all & PADRright) {
                vs_main_playSfxDefault(0x7E, 5);
            }

            ++screenState;
            screenTimer = 7;
        }
    } else if (screenState == 2) {

        renderTimeAttackResultsHeader(160, 52, screenTimer);
        renderHeaderAndTime(16, 164, screenTimer);
        renderTimeAttackRating(16, 144, screenTimer);

        if (newTimeSlot == 0) {
            renderNewRecord(70, 184, screenTimer);
        }

        renderAllStoredTimes(304, 144, screenTimer);

        if (screenTimer > 0) {
            --screenTimer;
        } else {
            ++screenState;
        }
    } else {
        func_8007E0A8(29, 1, 5);

        return 1;
    }
    return 0;
}

static void renderTimeAttackHeader(int x, int y, int timer);
static void renderCourse(int arg0, int arg1, int arg2);
static void renderBossName(int arg0, int arg1, int arg2);
static void renderBestTimeHeader(int arg0, int arg1, int arg2);
static void renderStartCountdown(int arg0, int arg1, int arg2);

int renderTimeAttackStart(void)
{
    static int countdownOffsets[] = { 121, 93, 67, 43, 25, 12, 3, 0 };
    static VECTOR D_801096F0[3] = { { 0x1029, 0x1029, 0x1000 },
        { 0x107A, 0x107A, 0x1000 } };
    static CVECTOR colors[] = { { 220, 80, 64 }, { 64, 128, 220 }, { 128, 128, 128 } };

    int temp_v1_2;
    int x;

    if (screenState == 0) {
        if ((screenTimer == ((screenTimer / 15) * 0xF)) && (screenTimer < 0x2E)) {
            vs_main_playSfxDefault(0x7E, 0x7A);
            vs_main_playSfxDefault(0x7E, 0x7B);
            vs_main_playSfxDefault(0x7E, 0x7C);
        }

        renderTimeAttackHeader(160, 48, screenTimer);
        renderCourse(160, 92, screenTimer - 15);
        renderBossName(160, 120, screenTimer - 30);
        renderBestTimeHeader(160, 156, screenTimer - 45);

        ++screenTimer;

        if (vs_main_buttonsPressed.all & PADRright) {
            screenState = 2;
            screenTimer = 0;
        } else if (screenTimer >= 90) {
            screenState = 1;
            screenTimer = 8;
        }
    } else if (screenState == 1) {
        --screenTimer;

        renderTimeAttackHeader(160, 48, screenTimer);
        renderCourse(160, 92, screenTimer);
        renderBossName(160, 120, screenTimer);
        renderBestTimeHeader(160, 156, screenTimer);

        if ((vs_main_buttonsPressed.all & PADRright) || (screenTimer == 0)) {
            screenState = 2;
            screenTimer = 0;
        }

    } else if (screenState == 2) {
        func_8007C36C(4);
        func_8007DDAC(0);
        func_8007DDB8(&D_801096F0[0]);
        func_8007DDD4(&colors[1]);
        func_8007DDF8((D_801096F0 + 2));
        func_8007DE2C(0);
        func_8007DE44(0U);
        func_8007DE5C(0);
        func_8007DD50(1);

        ++screenState;

    } else if (screenState == 3) {

        temp_v1_2 = screenTimer / 15;

        if (screenTimer == (temp_v1_2 * 0xF)) {

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

        if (screenTimer >= 45) {

            if (screenTimer == 45) {
                func_8007DE2C(1);
                func_8007DDB8(&D_801096F0[1]);
                func_8007DDD4(&colors[0]);
            } else if (screenTimer == 0x2E) {
                func_8007DE2C(0);
            } else if (screenTimer == 0x37) {
                func_8007DDD4(&colors[2]);
            } else if (screenTimer == 0x3C) {
                func_8007DDB8(&D_801096F0[0]);
            }

            x = 104 - screenTimer;

            if (x < 45) {
                x = 45;
            }

            renderStartCountdown(160, 120, x);

        } else {
            x = screenTimer % 15;

            if (x > 7) {
                x = 7;
            }

            x = countdownOffsets[x];

            renderStartCountdown(x + 160, 120, screenTimer);
        }

        ++screenTimer;

        if (screenTimer >= 62) {
            ++screenState;
        }

    } else if (screenState == 4) {
        func_8007C36C(2);
        func_8007DDB8(&D_801096F0[2]);
        func_8007DD50(0);
        func_8007E0A8(0x1D, 2, 5);

        return 1;
    }

    return 0;
}

void renderTimeAttackHeader(int x, int y, int timer)
{
    static CVECTOR colors[] = { { 128, 96, 64 }, { 200, 180, 160 }, { 128, 96, 64 } };

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 0x40) {
        timer = 0x40;
    }

    if (timer > 0) {

        colors[0].cd = timer;
        colors[1].cd = timer;
        x -= (disMap[disIndexAttack0TimeAttack].w
                 + disMap[disIndexAttack0TimeAttack + 1].w)
          >> 1;

        renderTexturePopIn(x, y, 100, colors);
        renderTexturePopIn(x + disMap[disIndexAttack0TimeAttack].w, y,
            disIndexAttack0TimeAttack + 1, &colors[1]);
    }
}

static void renderTextureFadeIn(int, int, int, int);
static void renderTextureFadeInClut(int, int, int, int, int);

void renderCourse(int x, int y, int timer)
{
    int new_var;

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        x -= (disMap[disIndexAttack0Course].w + 24) >> 1;

        renderTextureFadeIn(x, y, disIndexAttack0Course, timer);

        new_var = x + 12;

        renderTextureFadeInClut(new_var + disMap[disIndexAttack0Course].w, y - 1,
            vs_main_stateFlags.timeAttackBoss + 1, timer, 0x7FF4);
    }
}

void renderBossName(int x, int y, int timer)
{
    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        if (vs_main_stateFlags.timeAttackBoss != 6) {

            renderTextureFadeIn(
                x
                    - (disMap[vs_main_stateFlags.timeAttackBoss + disIndexAttack0Minotaur]
                            .w
                        >> 1),
                y, vs_main_stateFlags.timeAttackBoss + disIndexAttack0Minotaur, timer);

        } else {
            x -= (disMap[disIndexAttack0Death].w + disMap[disIndexAttack0OgreZombie].w)
              >> 1;

            renderTextureFadeIn(x, y, disIndexAttack0Death, timer);

            x += disMap[disIndexAttack0Death].w;

            renderTextureFadeIn(x, y, disIndexAttack0OgreZombie, timer);
        }
    }
}

static void renderTime(int, int, int, int, int);

void renderBestTimeHeader(int x, int y, int timer)
{
    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        int new_var;
        x -= (disMap[disIndexAttack0BestTime].w + 96) >> 1;

        renderTextureFadeIn(x, y, disIndexAttack0BestTime, timer);

        x++;
        new_var = x + 11;

        renderTime(new_var + disMap[disIndexAttack0BestTime].w, y + 2, timer,
            vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss][0]
                .time,
            0);
    }
}

void renderStartCountdown(int x, int y, int timer)
{
    int temp_a2 = (timer / 15) + disIndexAttack0Three;

    renderTextureFadeIn(
        x - (disMap[temp_a2].w / 2), y - (disMap[temp_a2].h / 2), temp_a2, timer % 15);
}

void pulseTimeAttackEnd(int arg0)
{
    RECT rect;
    int var_a1;
    int r;
    int g;
    int b;
    int i;
    int new_var3;
    int new_var4;

    for (i = 0; i < 32; ++i) {

        b = clutBuf[128 + i];

        var_a1 =
            ((clutBuf[32 + i] & 0x1F) * arg0) + ((clutBuf[96 + i] & 0x1F) * (16 - arg0));

        r = (var_a1 / 16) & 0x1F;

        g = ((clutBuf[32 + i] & 0x3E0) * arg0)
          + ((clutBuf[96 + i] & 0x3E0) * (16 - arg0));

        new_var4 = r | ((g / 16) & 0x3E0);

        b = ((clutBuf[32 + i] & 0x7C00) * arg0)
          + ((clutBuf[96 + i] & 0x7C00) * (16 - arg0));

        new_var3 = (b / 16) & 0x7C00;

        clutBuf[128 + i] = (new_var4 | new_var3) | (clutBuf[32 + i] & 0x8000);
    }

    setRECT(&rect, 768, 511, 160, 1);

    LoadImage(&rect, (u_long*)clutBuf);
}

void pulseCubePuzzleEnd(int arg0)
{
    RECT rect;
    int var_a1;
    int b;
    int var_a2;
    int i;
    int r;
    int new_var3;
    int new_var4;

    for (i = 0; i < 32; ++i) {

        b = clutBuf[128 + i];

        var_a1 =
            ((clutBuf[96 + i] & 0x1F) * arg0) + ((clutBuf[64 + i] & 0x1F) * (16 - arg0));

        r = (var_a1 / 16) & 0x1F;

        var_a2 = ((clutBuf[96 + i] & 0x3E0) * arg0)
               + ((clutBuf[64 + i] & 0x3E0) * (16 - arg0));

        new_var4 = r | ((var_a2 / 16) & 0x3E0);

        b = ((clutBuf[96 + i] & 0x7C00) * arg0)
          + ((clutBuf[64 + i] & 0x7C00) * (16 - arg0));

        new_var3 = (b / 16) & 0x7C00;

        clutBuf[128 + i] = (new_var4 | new_var3) | (clutBuf[96 + i] & 0x8000);
    }

    setRECT(&rect, 768, 511, 160, 1);

    LoadImage(&rect, (u_long*)clutBuf);
}

void renderCongratulations(int x, int y, int timer)
{
    static CVECTOR colors[] = { { 128, 96, 64 }, { 200, 180, 160 }, { 128, 96, 64 } };

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        colors[0].cd = timer;
        colors[1].cd = timer;
        x -= (disMap[disIndexRank0Congratulations].w
                 + disMap[disIndexRank0Congratulations + 1].w)
          >> 1;

        renderTexturePopIn(x, y, disIndexRank0Congratulations, colors);
        renderTexturePopIn(x + disMap[disIndexRank0Congratulations].w, y,
            disIndexRank0Congratulations + 1, &colors[1]);
    }
}

void renderScore(int x, int y, int timer, UNUSED int arg3)
{
    static CVECTOR colors[] = { { 100, 180, 220 }, { 100, 180, 220 } };

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
        colors[0].cd = timer;

        sprintf(buf, "%09d", score);

        new_var = disMap[disIndexRank0Score].w + disMap[disIndexRank0Colon].w;
        x -=
            (((disMap[disIndexRank0Comma].w * 2) + (new_var + disMap[disIndexRank0Pts].w))
                + 116)
            >> 1;

        renderTextureFadeInTint(x, y, disIndexRank0Score, colors);

        x += disMap[disIndexRank0Score].w;

        renderTextureFadeInTint(x, y + 7, disIndexRank0Colon, colors);

        i = 2;
        x = (x + i) + disMap[disIndexRank0Colon].w;

        for (i = 0; i < 9; ++i) {
            renderTextureFadeInTint(x, y + 3, buf[i] - '0', colors);

            x += 0xC;

            if ((i == 2) || (i == 5)) {
                renderTextureFadeInTint(x, y + 14, 10, colors);

                x += disMap[disIndexRank0Comma].w + 3;
            }
        }

        renderTextureFadeInTint(x, y + 8, disIndexRank0Pts, colors);
    }
}

void renderIncrementalScore(int x, int y, int timer, UNUSED int arg3)
{
    static CVECTOR colors[] = { { 100, 180, 220 }, { 100, 180, 220 } };

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

    if ((score != 0) && (timer >= 32)) {

        if (onScreenScore == 0) {

            incrementingScore = 1;

            vs_main_playSfxDefault(0x7E, 0x72);
        }

        if ((onScreenScore == score) && (incrementingScore != 0)) {

            incrementingScore = 0;

            vs_main_evictSfx(0x7E, 0x72);
            vs_main_playSfxDefault(0x7E, 0x73);
        }
    }

    if (timer >= 32) {
        onScreenScore = (score >> 5) * (timer - 32);
    }

    if (timer == 64) {
        onScreenScore = score;
    }

    sprintf(buf, "%09d", onScreenScore);

    v = disMap[disIndexRank0Score].w + disMap[disIndexRank0Colon].w
      + disMap[disIndexRank0Pts].w;
    x -= (((disMap[disIndexRank0Comma].w * 2) + v) + 116) >> 1;

    renderTextureWipe(x, y, disIndexRank0Score, colors, temp_s2);

    x += disMap[disIndexRank0Score].w;

    renderTextureWipe(x, y + 7, disIndexRank0Colon, colors, temp_s2);

    i = 2;
    x = x + i + disMap[disIndexRank0Colon].w;

    for (i = 0; i < 9; ++i) {
        renderTextureWipe(x, y + 3, buf[i] - '0', colors, temp_s2);

        x += 12;

        if ((i == 2) || (i == 5)) {
            renderTextureWipe(x, y + 14, disIndexRank0Comma, colors, temp_s2);

            x += 3 + disMap[disIndexRank0Comma].w;
        }
    }

    renderTextureWipe(x, y + 8, 0x14, colors, temp_s2);
}

void renderMapCompletion(int x, int y, int timer, UNUSED int arg3)
{
    static CVECTOR colors[] = { { 100, 180, 220 }, { 100, 180, 220 } };

    char buf[4];
    int i;

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        colors[0].cd = timer;

        sprintf(buf, "%03d", mapCompletionPercent);

        x -= (disMap[21].w + disMap[26].w + disMap[19].w + 0x26) >> 1;
        i = 2;

        renderTextureFadeInTint(x, y, 0x15, colors);

        x += disMap[21].w;

        renderTextureFadeInTint(x, y + 7, 0x1A, colors);

        x = x + i + disMap[26].w;

        for (i = 0; i < 3; ++i) {
            renderTextureFadeInTint(x, y + 3, buf[i] - '0', colors);

            x += 0xC;
        }

        renderTextureFadeInTint(x, y + 8, 0x13, colors);
    }
}

void renderIncrementalMapCompletion(int arg0, int arg1, int arg2, UNUSED int arg3)
{
    static CVECTOR colors[] = { { 100, 180, 220 }, { 100, 180, 220 } };

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

    if ((mapCompletionPercent != 0) && (arg2 >= 32)) {

        if (onScreenMapCompletion == 0) {
            incrementingMapCompletion = 1;

            vs_main_playSfxDefault(0x7E, 0x72);
        }

        if ((onScreenMapCompletion == mapCompletionPercent)
            && (incrementingMapCompletion != 0)) {
            incrementingMapCompletion = 0;

            vs_main_evictSfx(0x7E, 0x72);
            vs_main_playSfxDefault(0x7E, 0x73);
        }
    }

    if (arg2 >= 32) {
        if (mapCompletionPercent >= 32) {
            onScreenMapCompletion = (mapCompletionPercent * (arg2 - 32)) >> 5;
        } else if (onScreenMapCompletion < mapCompletionPercent) {
            ++onScreenMapCompletion;
        }
    }

    sprintf(buf, "%03d", onScreenMapCompletion);

    arg0 -= (disMap[disIndexRank0MapCompleted].w + disMap[disIndexRank0Colon].w
                + disMap[disIndexRank0Percent].w + 38)
         >> 1;

    renderTextureWipe(arg0, arg1, disIndexRank0MapCompleted, colors, temp_s4);

    arg0 += disMap[disIndexRank0MapCompleted].w;
    i = 2;

    renderTextureWipe(arg0, arg1 + 7, disIndexRank0Colon, colors, temp_s4);
    arg0 = arg0 + i + disMap[disIndexRank0Colon].w;

    for (i = 0; i < 3; ++i) {
        renderTextureWipe(arg0, arg1 + 3, buf[i] - '0', colors, temp_s4);

        arg0 += 12;
    }

    renderTextureWipe(arg0, arg1 + 8, disIndexRank0Percent, colors, temp_s4);
}

void renderRiskbreakerRankHeader(int x, int y, int timer)
{
    static CVECTOR colors[] = { { 200, 80, 20 }, { 200, 80, 20 } };

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        colors[0].cd = timer;

        renderTextureFadeInTint(x - (disMap[disIndexRank0RiskbreakerRank].w >> 1), y,
            disIndexRank0RiskbreakerRank, colors);
    }
}

void renderRiskbreakerRank(int x, int y, int timer)
{
    static CVECTOR colors[] = { { 128, 128, 128 }, { 128, 128, 128 } };

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

        colors[0].cd = timer;

        for (i = 0; i < riskbreakerRanks[riskbreakerRank][0]; ++i) {
            xInset += disMap[riskbreakerRanks[riskbreakerRank][i + 1]].w;
        }

        xInset /= 2;
        x -= xInset;

        for (i = 0; i < riskbreakerRanks[riskbreakerRank][0]; ++i) {
            renderTexturePopIn(x, y, riskbreakerRanks[riskbreakerRank][i + 1], colors);

            x += disMap[riskbreakerRanks[riskbreakerRank][i + 1]].w;
        }
    }
}

void renderTimeAttackResultsHeader(int x, int y, int timer)
{
    static CVECTOR colors[] = { { 128, 128, 128 }, { 128, 128, 128 } };

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        colors[0].cd = timer;
        x -= (disMap[disIndexTime0TimeAttackResults].w
                 + disMap[disIndexTime0TimeAttackResults + 1].w)
          >> 1;

        renderTexturePopIn(x, y, disIndexTime0TimeAttackResults, colors);
        renderTexturePopIn(x + disMap[disIndexTime0TimeAttackResults].w, y,
            disIndexTime0TimeAttackResults + 1, colors);
    }
}

void renderTimeAttackRating(int x, int y, int arg2)
{
    int var_a2;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 <= 0) {
        return;
    }

    if (timeTrialTime < 7680) {
        var_a2 = 0;
    } else if (timeTrialTime <= 65535) {
        var_a2 = 1;
    } else if (timeTrialTime <= 73215) {
        var_a2 = 2;
    } else if (timeTrialTime <= 131071) {
        var_a2 = 3;
    } else {
        var_a2 = 4;
    }

    renderTextureFadeIn(x, y, var_a2 + disIndexTime0Excellent, arg2);
}

void renderTimeAttackRatingWipe(int x, int y, int arg2)
{
    static CVECTOR colors[] = { { 128, 128, 128 }, { 128, 128, 128 } };

    int arg3;

    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 <= 0) {
        return;
    }

    arg3 = x + (arg2 * 8);

    if (timeTrialTime < 7680) {
        arg2 = 0;
    } else if (timeTrialTime <= 65535) {
        arg2 = 1;
    } else if (timeTrialTime <= 73215) {
        arg2 = 2;
    } else if (timeTrialTime <= 131071) {
        arg2 = 3;
    } else {
        arg2 = 4;
    }

    renderTextureWipe(x, y, arg2 + disIndexTime0Excellent, colors, arg3);
}

void renderHeaderAndTime(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }

    if (arg2 > 64) {
        arg2 = 64;
    }

    if (arg2 > 0) {
        renderTextureFadeIn(arg0, arg1, disIndexTime0Time, arg2);

        arg0 += disMap[disIndexTime0Time].w;

        renderTime(arg0, arg1 + 2, arg2, timeTrialTime, 0);
    }
}

void renderHeaderAndIncrementalTime(int x, int y, int timer)
{
    int temp_a3;
    int var_a3;
    int* new_var4;

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        renderTextureFadeIn(x, y, disIndexTime0Time, timer);

        x += disMap[disIndexTime0Time].w;

        if (timer >= 16) {
            int mins = (timeTrialTime >> 0x10) & 0xFF;
            int secs = (timeTrialTime >> 8) & 0xFF;
            int ms = timeTrialTime & 0xFF;
            temp_a3 = ((mins * 6000) + (secs * 100)) + ms;
            var_a3 = temp_a3;
            var_a3 = ((*(new_var4 = &var_a3)) * (timer - 16)) / 48;
            mins = var_a3 / 6000;
            var_a3 = var_a3 % 6000;
            secs = var_a3 / 100;
            var_a3 = var_a3 % 100;
            var_a3 = (mins << 16) | (secs << 8) | var_a3;
        } else {
            var_a3 = 0;
        }

        renderTime(x, y + 2, timer, var_a3, 0);
    }
}

void renderNewRecord(int x, int y, int timer)
{
    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        renderTextureFadeIn(x, y, disIndexTime0NewRecord, timer);
    }
}

void renderAllStoredTimes(int x, int y, int timer)
{
    int isNewRecord;
    int i;
    int var_s3;

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    for (i = 0; i < 3; ++i) {

        var_s3 = getClut(800, 511);
        isNewRecord = newTimeSlot == i;

        if (isNewRecord != 0) {
            var_s3 = getClut(896, 511);
        }

        renderTime(x - 84, y + i * 20 + 2, timer,
            vs_main_scoredata
                .bossTimeTrialScores[0][vs_main_stateFlags.timeAttackBoss * 3 + i]
                .time,
            isNewRecord);
        renderTextureFadeInClut((x - disMap[disIndexTime0First + i].w) - 88, y + i * 20,
            disIndexTime0First + i, timer, var_s3);
    }
}

void renderStoredTime(int x, int y, int slot, int timer)
{
    int isCurrentTime;
    int clut;

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    isCurrentTime = newTimeSlot == slot;
    clut = getClut(800, 511);

    if (isCurrentTime != 0) {
        clut = getClut(896, 511);
    }

    renderTime(x - 84, y + (slot * 20) + 2, timer,
        vs_main_scoredata.bossTimeTrialScores[vs_main_stateFlags.timeAttackBoss][slot]
            .time,
        isCurrentTime);
    renderTextureFadeInClut((x - disMap[slot + disIndexTime0First].w) - 88,
        y + (slot * 20), slot + disIndexTime0First, timer, clut);
}

void renderTextureFadeIn(int x, int y, int texIndex, int brightness)
{
    Texture* texture;
    POLY_FT4* poly;
    void** scratch;

    if (brightness <= 0) {
        return;
    }

    poly = *(void**)getScratchAddr(0);
    texture = &disMap[texIndex];

    setPolyFT4(poly);
    setXY4(
        poly, x, y, texture->w + x, y, x, texture->h + y, texture->w + x, texture->h + y);
    setUV4(poly, texture->x, texture->y, texture->x + texture->w, texture->y, texture->x,
        texture->y + texture->h, texture->x + texture->w, texture->y + texture->h);
    setSemiTrans(poly, 1);

    if (brightness < 8) {
        setRGB0(poly, brightness * 16, brightness * 16, brightness * 16);
        poly->tpage = texture->tpage | getTPage(0, semiTransparencyFull, 0, 0);
        poly->clut = texture->clut + 1;
    } else {
        setRGB0(poly, 128, 128, 128);
        poly->tpage = texture->tpage;
        poly->clut = texture->clut;
    }

    scratch = (void**)getScratchAddr(0);

    AddPrim(scratch[1] - 0x1C, poly++);

    scratch[0] = poly;
}

void renderTextureFadeInClut(int x, int y, int texIndex, int brightness, int clut)
{
    Texture* texture;
    POLY_FT4* poly;
    void** scratch;

    if (brightness <= 0) {
        return;
    }

    poly = *(void**)getScratchAddr(0);
    texture = &disMap[texIndex];

    setPolyFT4(poly);
    setXY4(
        poly, x, y, texture->w + x, y, x, texture->h + y, texture->w + x, texture->h + y);
    setUV4(poly, texture->x, texture->y, texture->x + texture->w, texture->y, texture->x,
        texture->y + texture->h, texture->x + texture->w, texture->y + texture->h);
    setSemiTrans(poly, 1);

    if (brightness < 8) {
        setRGB0(poly, brightness * 16, brightness * 16, brightness * 16);
        poly->tpage = texture->tpage | getTPage(0, semiTransparencyFull, 0, 0);
        poly->clut = clut + 1;
    } else {
        setRGB0(poly, 128, 128, 128);
        poly->tpage = texture->tpage;
        poly->clut = clut;
    }

    scratch = (void**)getScratchAddr(0);

    AddPrim(scratch[1] - 0x1C, poly++);

    scratch[0] = poly;
}

void renderTime(int x, int y, int timer, int time, int isNewRecord)
{
    char buf[16];
    int i;
    int s2;

    if (time == 0x800000) {
        sprintf(buf, "------");
    } else {
        sprintf(
            buf, "%02d%02d%02d", (time >> 0x10) & 0xFF, (time >> 8) & 0xFF, time & 0xFF);
    }

    s2 = getClut(800, 511);

    if (isNewRecord != 0) {
        s2 = getClut(896, 511);
    }

    for (i = 0; i < 6; ++i) {
        if (buf[i] == '-') {
            renderTextureFadeInClut(x, y, disIndexTime0Dash, timer, s2);

            x += 12;
        } else {
            renderTextureFadeInClut(x, y - 3, buf[i] - '0', timer, s2);

            x += 12;
        }

        if (i == 1) {
            renderTextureFadeInClut(x, y - 2, disIndexTime0Prime, timer, s2);

            x += 6;

        } else if (i == 3) {
            renderTextureFadeInClut(x, y - 2, disIndexTime0DoublePrime, timer, s2);

            x += 6;
        }
    }
}

void renderAnimatedStatWheel(int x, int y, int texId);

void renderStatWheel(int x, int y, int timer, int arg3)
{
    static CVECTOR colors[] = { { 128, 96, 64 }, { 200, 180, 160 } };

    RECT sp18;
    char buf[8];
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

        colors[0].cd = timer;
        x -= (disMap[11].w + disMap[26].w + disMap[14].w + disMap[24].w + 0xE) >> 1;

        renderTextureFadeInTint(x, y, disIndexRank0Bonus, colors);

        x += disMap[11].w;

        renderTextureFadeInTint(x, y, disIndexRank0Colon, colors);

        x += 2 + disMap[26].w;
        new_var2 = 16;
        p = (void**)0x1F800000;
        area = p[0];

        SetDrawArea(area, &vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip);
        AddPrim(p[1] - 0x1C, area++);

        p[0] = area;

        if (vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip.x >= 320) {
            sp18.x = 320;
        } else {
            sp18.x = 0;
        }

        sp18.y = y - (elementAnimationState >> 3);
        sp18.w = 320;
        sp18.h = ((elementAnimationState >> 3) * 2) + new_var2;

        if (arg3 < 2) {
            int a0 = x;
            int new_var;
            y += 8 + (buffReelSelection & 0xF);

            for (i = 0; i < 3; ++i) {
                x = a0;
                new_var = i - 1;
                v1 = (buffReelSelection / 16);
                v1 += new_var;
                temp = v1 & 0xF;

                renderAnimatedStatWheel(
                    x, y - 1, buffReels[buffReelIndex][v1 & 0xF].stat);

                x += disMap[buffReels[buffReelIndex][v1 & 0xF].stat].w;

                renderAnimatedStatWheel(x, y + 4, disIndexRank0Plus);

                x += disMap[24].w;

                sprintf(buf, "%d", buffReels[buffReelIndex][v1 & 0xF].amount);

                len = strlen(buf);

                for (j = 0; j < len; ++j) {
                    renderAnimatedStatWheel(x, y - 1, buf[j] - 0x30);
                    x += 0xC;
                }

                y -= 16;
            }

        } else {
            temp = (char)buffReelSelection / 16;

            renderTextureFadeInClut(
                x, y - 1, buffReels[buffReelIndex][temp].stat, timer, getClut(800, 511));

            x += disMap[buffReels[buffReelIndex][temp].stat].w;

            renderTextureFadeInClut(
                x, y + 4, disIndexRank0Plus, timer, getClut(800, 511));

            x += disMap[24].w;

            sprintf(buf, "%d", buffReels[buffReelIndex][temp].amount);

            len = strlen(buf);

            for (j = 0; j < len; ++j) {
                renderTextureFadeInClut(x, y - 1, buf[j] - '0', timer, getClut(800, 511));
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

void renderPressButtonPrompt(int x, int y, int arg2, int arg3)
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

#include "src/renderTextures.h"

void renderAnimatedStatWheel(int x, int y, int texId)
{
    int i;
    int brightness;
    void** p = (void**)0x1F800000;
    POLY_FT4* poly = p[0];
    int texY = disMap[texId].y;

    for (i = 0; i < disMap[texId].h; ++i, ++y, ++texY) {

        setPolyFT4(poly);
        setXY4(poly, x, y, disMap[texId].w + x, y, x, y + 1, disMap[texId].w + x, y + 1);
        setUV4(poly, disMap[texId].x, texY, disMap[texId].x + disMap[texId].w, texY,
            disMap[texId].x, texY + 1, disMap[texId].x + disMap[texId].w, texY + 1);

        if (y < 190) {
            brightness = 128 - ((189 - y) * 16);

            if (brightness < 0) {
                brightness = 0;
            }

            setRGB0(poly, brightness, brightness, brightness);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage = disMap[texId].tpage | getTPage(0, semiTransparencyFull, 0, 0);

            AddPrim(p[1] - 0x1C, poly++);

            setPolyFT4(poly);
            setXY4(
                poly, x, y, disMap[texId].w + x, y, x, y + 1, disMap[texId].w + x, y + 1);
            setUV4(poly, disMap[texId].x, texY, disMap[texId].x + disMap[texId].w, texY,
                disMap[texId].x, texY + 1, disMap[texId].x + disMap[texId].w, texY + 1);

            setRGB0(poly, brightness, brightness, brightness);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage =
                disMap[texId].tpage | getTPage(0, semiTransparencySubtract, 0, 0);

            AddPrim(p[1] - 0x1C, poly++);

        } else if (y >= 206) {

            brightness = 128 - ((y - 206) * 16);

            if (brightness < 0) {
                brightness = 0;
            }

            setRGB0(poly, brightness, brightness, brightness);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage = disMap[texId].tpage | getTPage(0, semiTransparencyFull, 0, 0);

            AddPrim(p[1] - 0x1C, poly++);

            setPolyFT4(poly);
            setXY4(
                poly, x, y, disMap[texId].w + x, y, x, y + 1, disMap[texId].w + x, y + 1);
            setUV4(poly, disMap[texId].x, texY, disMap[texId].x + disMap[texId].w, texY,
                disMap[texId].x, texY + 1, disMap[texId].x + disMap[texId].w, texY + 1);
            setRGB0(poly, brightness, brightness, brightness);
            setSemiTrans(poly, 1);
            setClut(poly, 816, 511);
            poly->tpage =
                disMap[texId].tpage | getTPage(0, semiTransparencySubtract, 0, 0);

            AddPrim(p[1] - 0x1C, poly++);

        } else {
            setRGB0(poly, 128, 128, 128);
            setSemiTrans(poly, 1);
            setClut(poly, 800, 511);
            poly->tpage = disMap[texId].tpage;

            AddPrim(p[1] - 0x1C, poly++);
        }
    }

    p[0] = poly;
}

static void nop0(void);

static short puzzleParTime;
static short puzzleRankCap;

int initCubePuzzleStart(void)
{
    static vs_Main_CdQueueSlot* iqDisCdSlot;
    static void* iqDisData;

    vs_Room* room;

    struct {
        short zoneId;
        short mapId;
        short par;
        short rankCap;
    }* puzzleData;

    if (vs_battle_submenuState == 0) {

        func_8007DFF0(0x1D, 2, 5);

        iqDisData = vs_main_allocHeapR(disFiles[iqDis].size);
        iqDisCdSlot = vs_main_allocateCdQueueSlot(&disFiles[iqDis]);

        vs_main_cdEnqueue(iqDisCdSlot, iqDisData);

        ++vs_battle_submenuState;

    } else if (vs_battle_submenuState == 1) {
        if (iqDisCdSlot->state == vs_main_CdQueueStateLoaded) {
            int i;
            TIM_IMAGE tim;
            for (i = 0; i < 2; ++i) {

                vs_battle_parseTim(iqDisData + i * 0x8220, &tim);

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
                        vs_main_memcpy(clutBuf, tim.caddr, sizeof clutBuf);
                    }
                }
            }

            puzzleParTime = 600;
            puzzleRankCap = 1;
            room = vs_battle_roomData.sectionF->rooms;
            puzzleData = iqDisData + 0x10440;

            for (i = 0; i < 64; ++i, ++puzzleData) {
                if ((puzzleData->zoneId == room->zoneId)
                    && (puzzleData->mapId == room->mapId)) {
                    puzzleParTime = puzzleData->par;
                    puzzleRankCap = puzzleData->rankCap;
                    break;
                }
            }

            vs_main_freeCdQueueSlot(iqDisCdSlot);

            ++vs_battle_submenuState;
        }
    } else {
        vs_main_freeHeapR(iqDisData);

        onScreenMapCompletion = 0;
        onScreenScore = 0;
        screenTimer = 0;
        screenState = 0;
        elementAnimationState = 0;
        buffReelSelection = 0;
        vs_battle_submenuState = 0;

        nop0();
        return 1;
    }

    return 0;
}

int initCubePuzzleEnd(void)
{
    if (vs_main_stateFlags.puzzleSetMaxTimer != 0) {
        vs_main_stateFlags.puzzleTimerMins = 59;
        vs_main_stateFlags.puzzleTimerSeconds = 59;
        vs_main_stateFlags.puzzleSetMaxTimer = 0;
        vs_main_stateFlags.puzzleTimerHundredths = 99;
    }

    return initCubePuzzleStart();
}

int initCubePuzzleQuit(void)
{
    static vs_Main_CdQueueSlot* escDisCdSLot;
    static void* escDisData;

    TIM_IMAGE tim;
    int i;

    if (vs_battle_submenuState == 0) {

        func_8007DFF0(0x1D, 1, 5);

        escDisData = vs_main_allocHeapR(disFiles[escDis].size);
        escDisCdSLot = vs_main_allocateCdQueueSlot(&disFiles[escDis]);

        vs_main_cdEnqueue(escDisCdSLot, escDisData);

        ++vs_battle_submenuState;

    } else if (vs_battle_submenuState == 1) {
        if (escDisCdSLot->state == vs_main_CdQueueStateLoaded) {
            for (i = 0; i <= 0; ++i) {

                vs_battle_parseTim(escDisData + i * 0x8220, &tim);

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
                    vs_main_memcpy(clutBuf, tim.caddr, sizeof clutBuf);
                }
            }

            vs_main_freeCdQueueSlot(escDisCdSLot);

            ++vs_battle_submenuState;
        }
    } else {
        vs_main_freeHeapR(escDisData);

        onScreenMapCompletion = 0;
        onScreenScore = 0;
        screenTimer = 0;
        screenState = 0;
        elementAnimationState = 0;
        buffReelSelection = 0;
        vs_battle_submenuState = 0;
        return 1;
    }

    return 0;
}

static void renderEvolveOrDie(int arg0, int arg1, int arg2);
static void renderAverageTimeHeader(int arg0, int arg1, int arg2);
static void renderCubePuzzleTime(int arg0, int arg1, int arg2);

int renderCubePuzzleStart(void)
{
    if (screenState != 0) {
        return 0;
    }

    if (screenTimer == 0) {
        vs_main_playSfxDefault(0x7E, 0x7D);
    }

    if (screenTimer == 30) {
        vs_main_playSfxDefault(0x7E, 0x7D);
    }

    renderEvolveOrDie(160, 64, screenTimer);
    renderAverageTimeHeader(128, 116, screenTimer - 15);
    renderCubePuzzleTime(192, 144, screenTimer - 30);
    renderPressButtonPrompt(214, 187, screenTimer - 30, screenTimer);

    if (screenTimer < 32767) {
        ++screenTimer;
    }

    if (vs_main_buttonsPressed.all & PADRright) {
        if (screenTimer >= 78) {

            vs_main_evictSfx(126, 0);
            func_8007E0A8(29, 2, 5);

            return 1;
        }

        vs_main_evictSfx(126, 0);

        screenTimer = 78;
    }

    return 0;
}

static void renderFoodchain(int arg0, int arg1, int arg2);
static void renderCubePuzzleRank(int arg0, int arg1, int arg2, int arg3);
static void renderCubePuzzleIncrementalTime(int arg0, int arg1, int arg2);
static void nop1(void);

int renderCubePuzzleEnd(void)
{
    static int puzzleModeRankPoints[] = { 100, 200, 400, 600, 800, 1000, 2000, 3000, 4000,
        5000, 6000, 7000, 8000, 9000, 10000, 20000 };

    int var_v0;

    pulseCubePuzzleEnd((rsin(elementAnimationState) / 512) + 8);

    elementAnimationState = (elementAnimationState + 64) & 0xFFF;

    if (screenState == 0) {
        int rank = ((vs_main_stateFlags.puzzleTimerMins * 6000)
                    + (vs_main_stateFlags.puzzleTimerSeconds * 100)
                    + vs_main_stateFlags.puzzleTimerHundredths);
        rank -= (puzzleParTime * 100);

        if (rank <= 0) {
            rank = 15 - puzzleRankCap;
        } else {
            --rank;
            rank = rank / 200;
            var_v0 = 1;
            rank = 15 - (puzzleRankCap + (rank + var_v0));

            if (rank >= 16) {
                rank = 15;
            }

            if (rank < 0) {
                rank = 0;
            }
        }

        if (screenTimer == 16) {
            vs_main_playSfxDefault(0x7E, 0x72);
        }

        if (screenTimer == 64) {
            vs_main_evictSfx(0x7E, 0x72);
            vs_main_playSfxDefault(0x7E, 0x73);
        }

        if (screenTimer == 67) {
            vs_main_playSfxDefault(0x7E, 0x7D);
        }

        if (screenTimer == 75) {
            vs_main_playSfxDefault(0x7E, 0x7D);
        }

        if (screenTimer == 90) {
            vs_main_playSfxDefault(0x7E, 0x7D);
        }

        renderCubePuzzleIncrementalTime(88, 64, screenTimer);
        renderFoodchain(160, 100, screenTimer - 75);
        renderCubePuzzleRank(160, 124, screenTimer - 90, rank);
        renderPressButtonPrompt(214, 187, screenTimer - 90, screenTimer);

        if (screenTimer < 32767) {
            ++screenTimer;
        }

        if (vs_main_buttonsPressed.all & PADRright) {
            if (screenTimer >= 138) {

                vs_main_evictSfx(0x7E, 0);
                func_8007E0A8(0x1D, 2, 5);

                vs_main_scoredata.miscScore += puzzleModeRankPoints[rank];

                nop1();

                return 1;
            }

            vs_main_evictSfx(0x7E, 0);

            screenTimer = 138;
        }
    }

    return 0;
}

static void renderGivingUp(int arg0, int arg1);
static void renderChicken(int arg0, int arg1);

int renderCubePuzzleQuit(void)
{
    pulseCubePuzzleEnd((rsin(elementAnimationState) / 512) + 8);

    elementAnimationState = (elementAnimationState + 64) & 0xFFF;

    if (screenState != 0) {
        return 0;
    }

    if (screenTimer == 0) {
        vs_main_playSfxDefault(0x7E, 0x7A);
    }

    if (screenTimer == 15) {
        vs_main_playSfxDefault(0x7E, 0x7A);
    }

    renderGivingUp(64, screenTimer);
    renderChicken(100, screenTimer - 15);
    renderPressButtonPrompt(214, 187, screenTimer - 15, screenTimer);

    if (screenTimer < 0x7FFF) {
        ++screenTimer;
    }

    if (vs_main_buttonsPressed.all & PADRright) {
        if (screenTimer > 62) {

            vs_main_evictSfx(0x7E, 0);
            func_8007E0A8(0x1D, 1, 5);
            nop1();

            return 1;
        }

        screenTimer = 63;

        vs_main_evictSfx(0x7E, 0);
    }

    return 0;
}

void renderGivingUp(int arg0, int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 > 64) {
        arg1 = 64;
    }
    if (arg1 > 0) {
        renderTextureFadeIn(0, arg0, disIndexEsc0GivingUp, arg1);
        renderTextureFadeIn(160, arg0, disIndexEsc0GivingUp + 1, arg1);
    }
}

void renderChicken(int arg0, int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }

    if (arg1 > 64) {
        arg1 = 64;
    }

    if (arg1 > 0) {
        renderTextureFadeIn(0, arg0, disIndexEsc0Chicken, arg1);
        renderTextureFadeIn(0xA0, arg0, disIndexEsc0Chicken + 1, arg1);
    }
}

void renderEvolveOrDie(int x, int y, int step)
{
    static CVECTOR colors[] = { { 128, 96, 64 }, { 200, 180, 160 }, { 128, 96, 64 } };

    if (step < 0) {
        step = 0;
    }

    if (step > 64) {
        step = 64;
    }

    if (step > 0) {
        colors[0].cd = step;
        colors[1].cd = step;
        x -= (disMap[disIndexIq0EvolveOrDie].w + disMap[disIndexIq0EvolveOrDie + 1].w)
          >> 1;

        renderTexturePopIn(x, y, disIndexIq0EvolveOrDie, colors);
        renderTexturePopIn(x + disMap[disIndexIq0EvolveOrDie].w, y,
            disIndexIq0EvolveOrDie + 1, &colors[1]);
    }
}

void renderFoodchain(int x, int y, int timer)
{
    static CVECTOR colors[] = { { 128, 96, 64 }, { 200, 180, 160 }, { 128, 96, 64 } };

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        colors[0].cd = timer;
        colors[1].cd = timer;
        x -= (disMap[disIndexIq0Foodchain].w + disMap[disIndexIq0Foodchain + 1].w) >> 1;

        renderTexturePopIn(x, y, disIndexIq0Foodchain, colors);
        renderTexturePopIn(
            x + disMap[disIndexIq0Foodchain].w, y, disIndexIq0Foodchain + 1, &colors[1]);
    }
}

void renderAverageTimeHeader(int x, int y, int timer)
{
    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        renderTextureFadeIn(x - (disMap[disIndexIq0AverageTime].w >> 1), y,
            disIndexIq0AverageTime, timer);
    }
}

void renderCubePuzzleTime(int x, int y, int timer)
{
    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        int new_var = (puzzleParTime % 60) << 0x10;

        renderTime(x, y, timer, ((puzzleParTime / 60) << 0x10) | (new_var >> 8), 0);
    }
}

void renderCubePuzzleRank(int x, int y, int timer, int rank)
{
    static CVECTOR colors[] = { { 128, 128, 128 }, { 128, 128, 128 } };

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer > 0) {
        colors[0].cd = timer;

        renderTexturePopIn(x - (disMap[rank + disIndexIq1GameDesigner].w >> 1), y,
            rank + disIndexIq1GameDesigner, colors);
    }
}

void renderCubePuzzleIncrementalTime(int x, int y, int timer)
{
    int temp_a3;
    int time;
    int new_var2;
    int* new_var4;

    if (timer < 0) {
        timer = 0;
    }

    if (timer > 64) {
        timer = 64;
    }

    if (timer <= 0) {
        return;
    }

    renderTextureFadeIn(x, y, 72, timer);

    x += disMap[72].w;

    if (timer >= 16) {
        temp_a3 = vs_main_stateFlags.puzzleTimerSeconds;
        new_var2 = vs_main_stateFlags.puzzleTimerMins;
        temp_a3 = ((new_var2 * 6000) + (temp_a3 * 100))
                + vs_main_stateFlags.puzzleTimerHundredths;
        time = temp_a3;
        time = ((*(new_var4 = &time)) * (timer - 16)) / 48;
        new_var2 = time / 6000;
        time = time % 6000;
        temp_a3 = time / 100;
        time = time % 100;
        time = (new_var2 << 0x10) | (temp_a3 << 8) | time;
    } else {
        time = 0;
    }

    renderTime(x, y + 2, timer, time, 0);
}

void determineRank(void)
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
            if (score >= rankScores[i]) {
                riskbreakerRank = i;
                return;
            }
        }
    }
}

void calculateScore(void)
{
    short classPoints[] = { 20, 20, 40, 80, 100, 60 };
    short weaponClassPoints[] = { 20, 40, 20, 100, 60, 100, 60, 100, 80, 60 };
    int i;

    score = 0;

    for (i = 0; i < 6; ++i) {
        score += vs_main_scoredata.enemyKills[i] * classPoints[i];
    }

    for (i = 0; i < 10; ++i) {
        score += vs_main_scoredata.weaponAttacks[i] * weaponClassPoints[i];
    }

    for (i = 0; i < 8; ++i) {
        if ((vs_main_scoredata.bossTimeTrialScores[i][0].time) != 0x800000) {
            score += 20000;
        }
    }

    if (vs_main_scoredata.maxChain < 6) {
        score += vs_main_scoredata.maxChain * 10;
    } else if (vs_main_scoredata.maxChain < 11) {
        score += vs_main_scoredata.maxChain * 20;
    } else if (vs_main_scoredata.maxChain < 16) {
        score += vs_main_scoredata.maxChain * 40;
    } else if (vs_main_scoredata.maxChain < 21) {
        score += vs_main_scoredata.maxChain * 80;
    } else if (vs_main_scoredata.maxChain < 26) {
        score += vs_main_scoredata.maxChain * 160;
    } else if (vs_main_scoredata.maxChain < 31) {
        score += vs_main_scoredata.maxChain * 320;
    } else if (vs_main_scoredata.maxChain < 51) {
        score += vs_main_scoredata.maxChain * 640;
    } else {
        score += vs_main_scoredata.maxChain * 1280;
    }

    score += clearCount * 100000;

    if ((clearCount != 0) && (vs_main_scoredata.completionTimeMinutes < 600)) {
        if (vs_main_scoredata.completionTimeMinutes >= 540) {
            score = score + (score >> 2);
        } else if (vs_main_scoredata.completionTimeMinutes >= 300) {
            score = score + (score >> 1);
        } else {
            score = score * 2;
        }
    }

    score = score + vs_main_scoredata.streakScore;
    score = score + vs_main_scoredata.miscScore;

    if (score > 999999999) {
        score = 999999999;
    }
}

void nop0(void) { }

void nop1(void) { }

void addHealBonus(void)
{
    int new_var = vs_main_scoredata.miscScore + 100000;

    vs_main_scoredata.miscScore = new_var - (vs_main_scoredata.healCount * 100);

    if (vs_main_scoredata.miscScore > 999999999) {
        vs_main_scoredata.miscScore = 999999999;
    }

    vs_main_scoredata.healCount = 0;
}

void nop2(void) { }

int getTotalStrength(void) { return vs_battle_characterState->stats->totalStrength; }

int getTotalIntelligence(void)
{
    return vs_battle_characterState->stats->totalIntelligence;
}

int getTotalAgility(void) { return vs_battle_characterState->stats->totalAgility; }

void raiseMaxStrength(int amount)
{
    vs_battle_characterState->stats->totalStrength += amount;

    if (vs_battle_characterState->stats->totalStrength > 999) {
        vs_battle_characterState->stats->totalStrength = 999;
    }

    vs_battle_characterState->stats->strength += amount;

    if (vs_battle_characterState->stats->strength > 999) {
        vs_battle_characterState->stats->strength = 999;
    }
}

void raiseMaxIntelligence(int amount)
{
    vs_battle_characterState->stats->totalIntelligence += amount;

    if (vs_battle_characterState->stats->totalIntelligence > 999) {
        vs_battle_characterState->stats->totalIntelligence = 999;
    }

    vs_battle_characterState->stats->intelligence += amount;

    if (vs_battle_characterState->stats->intelligence > 999) {
        vs_battle_characterState->stats->intelligence = 999;
    }
}

void raiseMaxAgility(int amount)
{
    vs_battle_characterState->stats->totalAgility += amount;

    if (vs_battle_characterState->stats->totalAgility > 999) {
        vs_battle_characterState->stats->totalAgility = 999;
    }

    vs_battle_characterState->stats->agility += amount;

    if (vs_battle_characterState->stats->agility > 999) {
        vs_battle_characterState->stats->agility = 999;
    }
}

void raiseMaxHP(int amount)
{
    vs_battle_characterState->stats->maxHP += amount;

    if (vs_battle_characterState->stats->maxHP > 999) {
        vs_battle_characterState->stats->maxHP = 999;
    }

    vs_battle_characterState->stats->currentHP += amount;

    if (vs_battle_characterState->stats->currentHP > 999) {
        vs_battle_characterState->stats->currentHP = 999;
    }
}

void raiseMaxMP(int amount)
{
    vs_battle_characterState->stats->maxMP += amount;

    if (vs_battle_characterState->stats->maxMP > 999) {
        vs_battle_characterState->stats->maxMP = 999;
    }

    vs_battle_characterState->stats->currentMP += amount;

    if (vs_battle_characterState->stats->currentMP > 999) {
        vs_battle_characterState->stats->currentMP = 999;
    }
}
