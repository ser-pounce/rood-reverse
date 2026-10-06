#include "common.h"
#include "5BF94.h"
#include "146C.h"
#include "2842C.h"
#include "30DB0.h"
#include "38C1C.h"
#include "3A1A0.h"
#include "40564.h"
#include "573B8.h"
#include "58578.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/overlay.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/32154.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "src/GIM/SCREFF2.PRG/0.h"
#include "build/src/include/lbas.h"
#include "build/assets/BATTLE/BATTLE.PRG/menuStrings.h"
#include "build/assets/BATTLE/BATTLE.PRG/statusStrings.h"
#include "vs_string.h"
#include "gpu.h"
#include "vs_inline_c.h"
#include <memory.h>
#include <libetc.h>
#include <rand.h>
#include <abs.h>
#include <inline_c.h>

typedef struct {
    u_int unk0_0 : 8;
    u_int unk0_8 : 8;
    u_int unk0_16 : 4;
    u_int unk0_20 : 6;
    u_int unk0_26 : 6;
} func_800D57FC_t;

typedef struct {
    unsigned unk0_0 : 4;
    unsigned unk0_4 : 5;
} func_800D57FC_t2;

typedef struct {
    func_800D5780_t2 unk0;
    u_short unk2;
} func_800D55A4_t2;

typedef struct {
    int count;
    func_800D55A4_t2 unk4[0];
} func_800D55A4_t;

typedef struct {
    u_short unk0;
    u_char unk2;
    u_char unk3;
} func_800D6894_t;

typedef struct {
    u_int unk0_0 : 1;
    u_int unk0_1 : 1;
    u_int unk0_2 : 1;
    u_int unk0_3 : 3;
    u_int unk0_6 : 3;
    u_int unk0_9 : 3;
    u_int unk0_12 : 1;
    u_int unk0_13 : 3;
    char unk2;
    char unk3;
    short unk4;
    short id;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    u_short* data;
    vs_main_CdQueueSlot* cdQueueSlot;
    short unk18[240];
    u_short imageTable[254];
    int unk3F4;
} gim_t;

typedef struct {
    D_800F53B8_t3* unk0;
    D_800F53B8_t3* unk4;
    D_800F53B8_t3* unk8;
    D_800F53B8_t3* unkC;
    int unk10;
    char* unk14;
    int unk18;
    D_800F53B8_t* unk1C;
    u_char unk20;
    u_char unk21;
    u_char unk22;
    u_char unk23;
    int unk24;
} D_800F53B8_t2;

typedef struct {
    char unk0[0x22];
    u_short unk22_0 : 2;
    u_short unk22_2 : 1;
    u_short unk22_3 : 13;
    char unk24[0xAC];
} func_800D6508_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} D_800F5620_t;

typedef struct {
    char unk0[4];
    short unk4;
    short unk6;
    short unk8;
    short unkA;
} func_800CF988_t2;

typedef struct {
    char unk0[8];
    func_800CF988_t2 unk8[4];
} func_800CF988_t;

typedef struct {
    char unk0[0xC];
    short unkC;
    short unkE;
    short unk10;
    short unk12;
} func_800CFAAC_t;

typedef struct {
    u_char order[8];
    u_char unk8;
    u_char unk9;
    u_char selectedIndex;
    u_char count;
    u_char unkC;
} _textBoxSelector_t;

typedef struct {
    int unk0;
    int unk4;
    SVECTOR unk8;
    VECTOR unk10;
    VECTOR unk20;
    int unk30[2];
    VECTOR target;
    MATRIX unk48;
    int unk5C;
    int unk60;
    int unk64;
} func_800D0B30_t2;

typedef struct {
    u_char unk0[0x34];
    u_char unk34;
    u_char unk35;
    char unk36[0x42];
    func_800CFE98_t unk78;
    char unk9C[0x22];
    short unkBE;
} func_800D0C60_t;

typedef struct {
    short unk0;
    short unk2;
    unsigned char unk4;
    unsigned char unk5;
    unsigned char unk6;
    unsigned char unk7;
} func_800D6310_t;

typedef struct {
    char unk0[0x10];
    D_800F53B8_t3_2 unk10[16];
} func_800D6048_t;

typedef struct {
    u_int unk0_0 : 9;
    u_int unk0_9 : 9;
    u_int effectRenderer : 3;
    u_int unk0_21 : 6;
    u_int unk0_27 : 5;
    u_short unk4;
} func_800D5D74_t;

typedef struct {
    u_short unk0_0 : 9;
    u_short unk0_9 : 7;
    u_short unk2;
    u_int unk4_0 : 4;
    u_int unk4_4 : 5;
    u_int unk4_9 : 7;
    u_int unk4_16 : 1;
    u_int unk4_17 : 7;
    u_int unk4_24 : 1;
    u_int unk4_25 : 7;
} func_800D6A18_t;

typedef struct {
    u_char unk0;
    u_char unk1_0 : 5;
    u_char unk1_5 : 1;
    u_char unk1_6 : 1;
    u_char unk1_7 : 1;
    u_char unk2;
    u_char unk3;
    u_char unk4;
    u_char unk5;
} D_800F54B8_t;

typedef struct {
    int count;
    short offsets[0];
} pFileBlock11;

typedef struct {
    u_short unk0;
    u_short unk2;
    u_char unk4;
    u_char unk5;
    u_char unk6;
    u_char unk7;
    int unk8;
    int unkC;
    int unk10;
    short unk14[6];
    short unk20[6];
    short unk2C[6];
} func_800D0B30_t;

typedef struct {
    int unk0;
    int unk4;
    u_char unk8;
    u_char unk9;
    u_char unkA;
    u_char unkB;
    u_short unkC;
    u_short unkE;
    u_int unk10;
    u_char unk14;
    u_char unk15;
    u_char unk16;
    u_char unk17;
} func_800C5798_t;

typedef struct {
    char unk0;
    char unk1[3];
    short unk4;
    u_char unk6;
    char unk7;
    int unk8;
    int unkC;
    char* limbName;
} func_800C56C0_t2;

typedef union {
    SVECTOR vec;
    int words[2];
} func_800C4794_t;

typedef struct {
    func_800C1564_t unk0;
    func_800C1564_t unk10;
    short unk20;
    short unk22;
    int unk24;
    short unk28;
    short unk2A;
    u_char unk2C;
    u_char unk2D;
    u_char unk2E;
    u_char unk2F;
    u_char unk30;
    u_char unk31;
    char unk32[2];
    int unk34;
    func_800C4794_t unk38;
    func_800C5798_t* unk40;
    func_800C5798_t* unk44;
    char unk48[0x948];
    func_800C56C0_t2 unk990[24];
} func_800C56C0_t;

typedef struct {
    int unk0_0 : 12;
    int unk0_12 : 12;
    u_int unk0_24 : 2;
    u_int unk0_26 : 4;
} func_800CCE10_t;

void _renderDigit(int, int, int, u_long*);
void func_800C51B4(int);
void func_800CA97C(void);
void func_800CCA90(int arg0);
void func_800CBBCC(gim_t* arg0, int arg1, u_long* arg2);
int _breakArtsUnlocked(void);
extern int func_800CE174(func_800D4910_t*, u_int, int);
void func_800CE67C(void);
D_800F53B8_t* func_800CE83C(D_800F53B8_t2*);
D_800F53B8_t* func_800CF55C(D_800F53B8_t2* arg0);
int func_800CE9B0(void);
char func_800CF218(func_800CF0E8_t* arg0, int arg1, int arg2);
void func_800CF478(int arg0);
void func_800CF484(int arg0, D_800F53B8_t* arg1);
int func_800CF49C();
void func_800CF514(int arg0);
void func_800CF614(D_800F53B8_t*);
func_800D4910_t* func_800CF694(D_800F53B8_t*, effectExec, int);
void func_800CF70C(D_800F53B8_t*, func_800D4910_t*);
void func_800CFEF0(D_800F53B8_t*);
void func_800CFE98(SVECTOR* arg0, func_800CFE98_t* arg1);
void func_800D0984(int, func_800D0C60_t*, int);
void func_800D0D08(D_800F53B8_t*);
void func_800D1104(int);
int func_800D12D8(int);
void func_800D169C(SVECTOR*, SVECTOR*, int, SVECTOR*);
void func_800D17A8(VECTOR*, VECTOR*, int, VECTOR*);
void func_800D1930(void);
void func_800D1B18(D_800F54D8_t*);
void func_800D1B80(D_800F54D8_t*);
void func_800D206C(void);
void func_800D21C0(void);
void func_800D236C(void);
void func_800D2560(void);
void func_800D268C(void);
void func_800D2698(int);
void func_800D278C(void);
void func_800D2904(D_800F53B8_t*);
void func_800D46DC(int, D_800F53B8_t*);
u_char func_800D5170(D_800F53B8_t*);
u_short func_800D5198(D_800F53B8_t*);
int func_800D51D8(D_800F53B8_t* arg0);
void func_800D55A4(D_800F53B8_t*, int, int);
void func_800D5700(func_800D5780_t*);
void func_800D5738(func_800D5780_t*);
int func_800D5780(func_800D5780_t*);
int func_800D57FC(D_800F53B8_t*, func_800D5780_t*);
int func_800D5904(D_800F53B8_t*, func_800D5780_t*);
typedef struct {
    u_char* data;
    char prefix[8];
    short delay;
    short index;
} timedSpawnState;

int func_800D5A98(D_800F53B8_t*, timedSpawnState*, int);
int func_800D5D74(D_800F53B8_t*, func_800D5780_t*);
int func_800D5E00(D_800F53B8_t*, func_800D5780_t*);
int func_800D5F8C(D_800F53B8_t*, func_800D5780_t*);
int func_800D6048(D_800F53B8_t*, func_800D5780_t*, int);
int func_800D61AC(D_800F53B8_t*, func_800D5780_t*);
int func_800D6298(D_800F53B8_t*, func_800D5780_t*);
void func_800D6448(D_800F53B8_t*, u_char, u_char);
void func_800D65D8(D_800F53B8_t*, u_char);
void func_800D6628(D_800F53B8_t*, u_char);
void func_800D66FC(D_800F53B8_t*, u_char, u_char);
void func_800D67C4(D_800F53B8_t*, u_char);
int func_800D6A18(D_800F53B8_t*, func_800D5780_t*);
void func_800D1EF0(int, int, int, int, int, int, int);
void func_800D6AEC(D_800F53B8_t*, int);
void func_800D7890(int);
void func_800D78B8(void);
void func_800D78CC(void);
int func_800D7BF8(void);
void func_800D7C5C(void);
int func_800D7CFC(void);
int func_800D7EF4(void);
void func_800D8060(void*);
void vs_effpurge_exec(void);
void func_800AE68C(int, int);
void func_800C4650(func_800C5798_t* arg0, int arg1);
MATRIX* func_800C085C(func_800C1564_flags* arg0, int arg1);
void func_800C02A8(void);
void func_800C28AC(SVECTOR* arg0, int arg1);
void func_800C2B0C(SVECTOR* arg0, int arg1);
void func_800C2E24(SVECTOR* arg0, MATRIX* arg1, int arg2);
void* func_800C282C(void);
int _getCollisionMapDimensions(int arg0);
int func_800C1D84(void);

extern u_int _gimLbas[];
extern int _menuLbas[];
extern u_char D_800EABAA;
extern char D_800EA984[];
extern char D_800EA9B6[];
extern char D_800EAA54[];
extern char D_800EB9AC;
extern signed char _loadedSubMenu;
extern func_800C56C0_t* D_800EB9B8;
extern gim_t* D_800EB9BC;
extern char D_800EB9CC;
extern char D_800EB9CD;
extern char D_800EB9CE;
extern union {
    int s32;
    u_char u8[4];
} D_800EB9D0;
extern u_int* _menuBgUnpackedBuf;
extern u_char D_800EB708[];
extern u_char D_800EB7B4[];
extern u_char D_800EB7D4[];
extern int* D_800EB9D8;
extern u_int D_800EBBB8[];
extern u_int D_800EBBC0[];
extern int D_800EBBDC[];
extern int D_800EBC04[];
extern u_short D_800EBC68[];
extern char D_800EBC78;
extern int D_800EBC88[];
extern u_char D_800EBC98[];
extern u_char D_800EBCA0[];
extern int D_800EBCA8[];
extern u_short D_800EBCB8[];
extern u_char D_800EBCC0[];
extern u_char D_800EBCC8[];
extern int D_800EBCD0[];
extern u_short D_800EBCE0[];
extern u_char D_800EBCE8;
extern int D_800EBCEC[];
extern int D_800EBD14[];
extern u_int D_800EBD3C[];
extern u_short D_800EBD64;
extern u_char _spellClassCounts[];
extern u_char* _spellIds[];
extern char D_800EBD68[];
extern u_short D_800EBDDC[];
extern u_int _keystreamState;
extern char D_800EBF58[][12];
extern char* D_800EC258;
extern void (*D_800EC25C[])(gim_t*, int, u_long*);
extern func_800CCE10_t D_800EC284[][2];
extern int D_800EC2CC[];
extern int D_800EC2D8[];
extern u_char D_800EC2E4;
extern effectExec D_800EC324[];
extern int D_800EC328;
extern char D_800EC32C[];
extern u_char D_800EC330[][2][4];
extern u_char D_800EC368[][5][4];
extern int (*D_800EC3F4[])(void*);
extern u_char D_800EC4B8;
extern u_char D_800F522C;
extern u_char D_800F4C70[2][16];
extern u_char D_800F4CB0;
extern u_char D_800F4CB1;
extern char D_800F4CB8;
extern char _fontTable;
extern int _fontBrightness;
extern u_long D_800F4CD0;
extern char vs_battle_shortcutInvoked;
extern char D_800F4E68;
extern char D_800F4E69;
extern char vs_battle_lowerScreenUiState;
extern _textBoxSelector_t textBoxSelector;
extern int D_800F4ED4;
extern short D_800F4ED8[8];
extern u_long* D_800F51B8;
extern char D_800F51C8;
extern vs_main_CdQueueSlot* D_800F5218;
extern u_int D_800F521C;
extern int D_800F5224;
extern int D_800F5228;
extern func_800CF0E8_t D_800F5230;
extern func_800CF0E8_t D_800F53C0;
extern u_char D_800F5238;
extern char D_800F5318;
extern u_int D_800F531C;
extern int D_800F5320[];
extern int D_800F5330[];
extern int D_800F53B4;
extern D_800F53B8_t* D_800F53B8;
extern char D_800F54A8;
extern char D_800F54A9;
extern D_800F53B8_t* D_800F54B0;
extern D_800F54B8_t D_800F54B8[];
extern short D_800F54D0;
extern D_800F54D8_t D_800F54D8;
extern u_char D_800F4E80;
extern D_800F53B8_t3 D_800F5234;
extern char D_800F5518;
extern D_800F54D8_t D_800F5520[2];
extern short D_800F55A0;
extern D_800F54D8_t D_800F55A8;
extern u_int D_800F55E8;
extern int D_800F55F0;
extern func_800D2904_t* D_800F55F4;
extern int D_800F55F8;
extern int D_800F5600;
extern int D_800F5610;
extern int D_800F5618;
extern D_800F5620_t D_800F5620;
extern func_800D2904_t* D_800F55FC;

int func_800C4794(SVECTOR* arg0)
{
    func_800C56C0_t* state = D_800EB9B8;
    func_800C4794_t offset;
    int result;
    int lockPitch;
    func_800C1564_flags flags;
    int stickX;
    int stickY;
    int oldX;
    int oldZ;
    int angle;
    int scale;
    int value;
    MATRIX* m;
    func_800C5798_t* trigger;

    stickX = state->unk38.words[0];
    stickY = state->unk38.words[1];
    flags = state->unk0.unk4.flags;
    offset.words[0] = stickX;
    offset.words[1] = stickY;
    arg0->pad = 0;
    result = 0;

    if (state->unk2A != 0) {
        arg0->vx = state->unk0.unk8.vx;
        arg0->vy = state->unk0.unk8.vy;
        arg0->vz = state->unk0.unk8.vz;
        func_800C2B0C(&state->unk0.unk8, state->unk2A - 1);
        return 0;
    }

    func_800C282C();
    lockPitch = 0;
    stickX = vs_battle_mapStickDeadZone(vs_main_stickPosBuf.rStickX);
    stickY = vs_battle_mapStickDeadZone(vs_main_stickPosBuf.rStickY);
    arg0->pad = 0;

    if ((offset.vec.pad == 0) || (vs_main_buttonsState & 0x80)) {
        lockPitch = 1;
    }

    if (lockPitch) {
        stickX = stickY >> 3;
        if (stickX == 0) {
            if (vs_main_buttonsState & 0x1000) {
                stickX = -8;
            }
            if (vs_main_buttonsState & 0x4000) {
                stickX += 8;
            }
        }
        stickX += offset.vec.vy;
        stickY = D_800EB9B8->unk0.unk0 & 0x7F;
        if ((u_int)(stickY - 1) < 2) {
            stickY = flags.unk1 * 32;
        } else {
            stickY = 0;
        }
        if (stickX < -flags.unk1 * 32) {
            stickX = -flags.unk1 * 32;
        }
        if (stickY < stickX) {
            stickX = stickY;
        }
        D_800EB9B8->unk38.vec.vy = stickX;
    } else {
        oldX = offset.vec.vx;
        oldZ = offset.vec.vz;
        angle = -D_800EB9B8->unk0.unk2 - D_800EB9B8->unk22;
        if ((stickX == 0) && (stickY == 0)) {
            if (vs_main_buttonsState & 0x1000) {
                stickY = -0x40;
            }
            if (vs_main_buttonsState & 0x4000) {
                stickY = 0x40;
            }
            if (vs_main_buttonsState & 0x8000) {
                stickX = -0x40;
            }
            if (vs_main_buttonsState & 0x2000) {
                stickX = 0x40;
            }
        }
        offset.vec.vx += (-stickX * rcos(angle) - stickY * rsin(angle) + 0x200) >> 10;
        offset.vec.vz += (-stickX * rsin(angle) + stickY * rcos(angle) + 0x200) >> 10;
        scale =
            vs_gte_rsqrt(offset.vec.vx * offset.vec.vx + offset.vec.vz * offset.vec.vz);
        if (scale > 0x1000) {
            stickX = offset.vec.vx - oldX;
            stickY = offset.vec.vz - oldZ;
            offset.vec.vx = (offset.vec.vx << 12) / scale;
            offset.vec.vz = (offset.vec.vz << 12) / scale;
            scale =
                (ratan2(offset.vec.vx, offset.vec.vz) - ratan2(stickX, stickY)) & 0xFFF;
            if ((u_int)(scale - 8) >= 0xFF0) {
                offset.vec.vx = oldX;
                offset.vec.vz = oldZ;
            }
        }
        D_800EB9B8->unk38.vec.vx = offset.vec.vx;
        D_800EB9B8->unk38.vec.vz = offset.vec.vz;
    }

    if (offset.vec.pad != 0) {
        func_800C4650(D_800EB9B8->unk44, D_800EB9B8->unk2E);
    }
    if (offset.vec.pad == 0) {
        if (vs_main_buttonsPressed.all & 0x40) {
            vs_battle_playMenuLeaveSfx();
            arg0->pad = 1;
            return 1;
        }
        if (vs_main_buttonsPressed.all & 0x20) {
            vs_battle_playMenuSelectSfx();
            D_800EB9B8->unk38.vec.pad = 1;
            D_800EB9B8->unk0.unk0 |= 0x80;
            D_800EB9B8->unk10.unk0 &= 0x7F;
        }
    } else if (vs_main_buttonsPressed.all & 0x40) {
        vs_battle_playMenuLeaveSfx();
        D_800EB9B8->unk0.unk0 &= 0x7F;
        D_800EB9B8->unk10.unk0 |= 0x80;
        D_800EB9B8->unk38.vec.pad = 0;
        for (stickX = 0; stickX < D_800EB9B8->unk2E; ++stickX) {
            trigger = &D_800EB9B8->unk44[stickX];
            if ((trigger->unk9 >> 4) == 0) {
                func_8009FE74(trigger->unk9, (signed char)trigger->unkA);
            }
        }
    } else if (vs_main_buttonsPressed.all & 0x20) {
        vs_battle_playMenuSelectSfx();
        result = 1;
    }

    m = func_800C085C(&D_800EB9B8->unk0.unk4.flags, D_800EB9B8->unk0.unk2);
    func_800C02A8();
    for (;;) {
        switch (D_800EB9B8->unk0.unk0 & 0x7F) {
        case 1:
            scale = (D_800EB9B8->unk38.vec.vy * 2) / flags.unk1;
            scale = SquareRoot12(0x1000 - scale * scale);
            break;
        case 2:
        case 3:
            scale = 0x1000;
            break;
        case 4:
            scale = ((flags.unk1 * 32 + D_800EB9B8->unk38.vec.vy) << 7) / flags.unk1;
            break;
        case 5:
            scale = (-D_800EB9B8->unk38.vec.vy << 7) / flags.unk1;
            break;
        }
        arg0->vx = D_800EB9B8->unk0.unk8.vx;
        arg0->vy = D_800EB9B8->unk0.unk8.vy + D_800EB9B8->unk38.vec.vy;
        arg0->vz = D_800EB9B8->unk0.unk8.vz;
        if (arg0->vy < -1) {
            break;
        }
        D_800EB9B8->unk38.vec.vy = -D_800EB9B8->unk0.unk8.vy - 2;
    }

    func_800C2E24(arg0, m, scale);
    stickX = (D_800EB9B8->unk38.vec.vx * scale + 0x800) >> 12;
    stickY = (D_800EB9B8->unk38.vec.vz * scale + 0x800) >> 12;
    arg0->vx += (stickX * m->m[0][0] + stickY * m->m[2][0] + 0x800) >> 12;
    arg0->vz += (stickX * m->m[0][2] + stickY * m->m[2][2] + 0x800) >> 12;

    value = _getCollisionMapDimensions(0);
    if (((u_int)arg0->vx >= (value & 0xFFFF) * 8)
        || ((u_int)arg0->vz >= (value >> 16) * 8)) {
        if (arg0->vx < 0) {
            arg0->vx = 0;
        }
        if (arg0->vx >= (value & 0xFFFF) * 8) {
            arg0->vx = (value & 0xFFFF) * 8 - 1;
        }
        if (arg0->vz < 0) {
            arg0->vz = 0;
        }
        if (arg0->vz >= (value >> 16) * 8) {
            arg0->vz = (value >> 16) * 8 - 1;
        }
        stickX = arg0->vx - D_800EB9B8->unk0.unk8.vx;
        stickY = arg0->vz - D_800EB9B8->unk0.unk8.vz;
        value = (m->m[0][0] * m->m[2][2] - m->m[0][2] * m->m[2][0] + 0xFFF) / 4096;
        if ((scale != 0) && (value != 0)) {
            D_800EB9B8->unk38.vec.vx =
                (((stickX * m->m[2][2] - stickY * m->m[2][0]) / value) << 12) / scale;
            D_800EB9B8->unk38.vec.vz =
                (((-stickX * m->m[0][2] + stickY * m->m[0][0]) / value) << 12) / scale;
        }
        stickX = (D_800EB9B8->unk38.vec.vx * scale + 0x800) >> 12;
        stickY = (D_800EB9B8->unk38.vec.vz * scale + 0x800) >> 12;
        arg0->vx = D_800EB9B8->unk0.unk8.vx
                 + ((stickX * m->m[0][0] + stickY * m->m[2][0] + 0x800) >> 12);
        arg0->vz = D_800EB9B8->unk0.unk8.vz
                 + ((stickX * m->m[0][2] + stickY * m->m[2][2] + 0x800) >> 12);
    }

    func_800C28AC(arg0, lockPitch);
    if (!(D_800EB9B8->unk10.unk0 & 0x80)) {
        D_800EB9B8->unk10.unk1 = 0;
        stickX = ((int*)arg0)[0];
        stickY = ((int*)arg0)[1];
        ((int*)&D_800EB9B8->unk10.unk8)[0] = stickX;
        ((int*)&D_800EB9B8->unk10.unk8)[1] = stickY;
    }
    if (result) {
        func_800C4650(D_800EB9B8->unk44, D_800EB9B8->unk2E);
    }
    return result;
}

void func_800C513C(int arg0, int arg1)
{
    if (!(arg0 & 0xF0)) {
        func_8009FE74(arg0, arg1);
    }
}

void func_800C5164(int arg0, int arg1, int arg2)
{
    if (!(arg0 & 0xF0)) {
        func_8009FD5C(arg0, arg1, arg2);
    }
}

void func_800C518C(int arg0, void* arg1)
{
    if (!(arg0 & 0xF0)) {
        func_800A07FC(arg0, arg1);
    }
}

void func_800C51B4(int mode)
{
    func_800C5798_t* entries = D_800EB9B8->unk40;
    int i, group;
    if (D_800EB9B8->unk31) {
        if (mode != 3) {
            for (i = 0; i < D_800EB9B8->unk2C; ++i) {
                group = entries[i].unk9;
                if (!(group >> 4)) {
                    void* data;
                    if (mode == 1) {
                        func_800C513C(group, (signed char)entries[i].unkA);
                        data = NULL;
                    } else {
                        func_800C5164(group, 0, (signed char)entries[i].unkA);
                        data = &D_800EB9B8->unk34;
                    }
                    func_800C518C(group, data);
                }
            }
        }
    } else {
        i = D_800EB9B8->unk2D;
        if (i != 255) {
            if (mode & 1) {
                group = D_800EB9B8->unk2F;
                if (!(group >> 4)) {
                    func_800C513C(group, (signed char)D_800EB9B8->unk30);
                    func_800C518C(group, NULL);
                }
            }
            if (mode & 2) {
                D_800EB9B8->unk2F = entries[i].unk9;
                D_800EB9B8->unk30 = entries[i].unkA;
                group = D_800EB9B8->unk2F;
                if (!(group >> 4)) {
                    func_800C5164(group, 0, (signed char)D_800EB9B8->unk30);
                    func_800C518C(group, &D_800EB9B8->unk34);
                }
            }
        }
    }
}

extern u_char D_800F4C90[8], D_800F4C98[8], D_800F4CA0[8], D_800F4CA8[8];
extern u_char D_800F4CB2, D_800F4CB3;

void func_800C5360(int group)
{
    int first = 0;
    int i;
    if (D_800F4CB1 > D_800F4CB0) {
        for (i = 0; i < D_800EB9B8->unk2C; ++i) {
            if (D_800EB9B8->unk40[i].unk9 == group) {
                if (!first)
                    first = i + 1;
                D_800F4C70[1][D_800F4CB0++] = i;
            }
        }
        D_800F4CA0[D_800F4CB2] = first - 1;
        D_800F4C90[D_800F4CB2++] = group;
    } else {
        for (i = 0; i < D_800EB9B8->unk2C; ++i) {
            if (D_800EB9B8->unk40[i].unk9 == group) {
                if (!first)
                    first = i + 1;
                D_800F4C70[0][D_800F4CB1++] = i;
            }
        }
        D_800F4CA8[D_800F4CB3] = first - 1;
        D_800F4C98[D_800F4CB3++] = group;
    }
}

extern u_char D_800F4CB4;

void func_800C553C(void)
{
    int size, group, i, count;
    D_800F4CB0 = 0;
    D_800F4CB1 = 0;
    D_800F4CB2 = 0;
    D_800F4CB3 = 0;
    for (size = 6; size > 0; --size) {
        for (group = 0; group < 16; ++group) {
            count = 0;
            for (i = 0; i < D_800EB9B8->unk2C; ++i) {
                if (D_800EB9B8->unk40[i].unk9 == group)
                    ++count;
            }
            if (count == size)
                func_800C5360(group);
        }
    }
    for (i = 0; i < D_800EB9B8->unk2C; ++i) {
        group = D_800EB9B8->unk40[i].unk9;
        if (group >> 4)
            func_800C5360(group);
    }
    i = D_800F4CB1;
    if (i < D_800F4CB0)
        i = D_800F4CB0;
    D_800F4CB4 = ((16 - i) * 11) >> 1;
}

void func_800C56C0(void)
{
    int i;

    func_800C51B4(1);

    for (i = 0; i < D_800F4CB1; ++i) {
        D_800EB9B8->unk990[D_800F4C70[0][i]].unk0 = 3;
    }

    for (i = 0; i < D_800F4CB0; ++i) {
        D_800EB9B8->unk990[D_800F4C70[1][i]].unk0 = 2;
    }
}

func_800C56C0_t2* func_800C5798(int arg0, int arg1, int arg2)
{
    int temp_v1;
    func_800C56C0_t2* item = &D_800EB9B8->unk990[arg0];
    func_800C5798_t* src = &D_800EB9B8->unk40[arg0];

    vs_battle_rMemzero(item, sizeof *item);
    item->unk0 = arg1;
    item->unk6 = arg2 * 11 + 32;
    temp_v1 = src->unk4;
    item->unk8 = src->unk0;
    item->unkC = temp_v1;

    if (arg1 == 2) {
        item->unk4 = 320;
        item->limbName = vs_battle_limbNames[src->unk8] + 1;
    } else {
        item->unk4 = -72;
        item->limbName = vs_battle_limbNames[src->unk8];
        item->unk7 = 1;
    }
    return item;
}

char* _getStatusString(uint arg0)
{
    int i;
    arg0 >>= 5;
    for (i = 0; i < 24; i++) {
        if ((arg0 >> i) & 1) {
            return (char*)&vs_battle_statusStrings
                [vs_battle_statusStrings[VS_statusStrings_INDEX_strDown + i]];
        }
    }
    return (char*)&vs_battle_statusStrings[VS_statusStrings_OFFSET_empty];
}

int func_800C58F8(u_char* target)
{
    func_800C56C0_t2* item;
    func_800C5798_t* entry;
    int i;
    int value;
    int prev;
    int type;

    if (target == NULL) {
        D_800EABAA = 0;
        return 0;
    }
    if (D_800EABAA == 0) {
        D_800EB9B8->unk34 = 0x808080;
        vs_battle_initInformationTextBox(0);
        func_800C51B4(2);
        func_800C553C();
        if (D_800EB9B8->unk2C == 0) {
            D_800EABAA = 16;
        }
    }

    *target = 0xFF;

    if (D_800EABAA < 16) {
        if ((D_800EABAA >= D_800F4CB1) && (D_800EABAA >= D_800F4CB0)) {
            D_800EABAA = 18;
        } else {
            if (D_800EABAA < D_800F4CB1) {
                i = D_800F4C70[0][D_800EABAA];
                item = func_800C5798(i, 2, D_800EABAA);
                if (D_800EABAA != 0) {
                    prev = D_800F4C70[0][D_800EABAA - 1];
                    if (D_800EB9B8->unk40[i].unk9 != D_800EB9B8->unk40[prev].unk9) {
                        item->unk7 = 1 - D_800EB9B8->unk990[prev].unk7;
                    } else {
                        item->unk7 = D_800EB9B8->unk990[prev].unk7;
                    }
                }
            }
            if (D_800EABAA < D_800F4CB0) {
                i = D_800F4C70[1][D_800EABAA];
                item = func_800C5798(i, 3, D_800EABAA);
                if (D_800EABAA != 0) {
                    prev = D_800F4C70[1][D_800EABAA - 1];
                    if (D_800EB9B8->unk40[i].unk9 != D_800EB9B8->unk40[prev].unk9) {
                        item->unk7 = 1 - D_800EB9B8->unk990[prev].unk7;
                    } else {
                        item->unk7 = D_800EB9B8->unk990[prev].unk7;
                    }
                }
            }
        nextState:
            ++D_800EABAA;
        }
    } else {
        switch (D_800EABAA) {
        case 16:
            vs_battle_textBoxes[7].unk0.unk0_8 = 1;
            vs_battle_setTextBox(7, (char*)&D_800EBDDC[D_800EBDDC[0]]);
            if (vs_main_buttonsPressed.all & 0x60) {
                vs_battle_playMenuLeaveSfx();
                D_800EABAA = 17;
            }
            break;
        case 17:
            D_800EB9AC = D_800EB9B8->unk0.unk1 == 2;
            D_800EABAA = 21;
            break;
        case 18:
            if (func_800C1D84() == 0) {
                break;
            }
            goto nextState;
        case 19:
            if (++D_800EB9B8->unk990[D_800EB9B8->unk2D].unk1[2] == 0x22) {
                D_800EB9B8->unk990[D_800EB9B8->unk2D].unk1[2] = 0x12;
            }
            D_800EB9B8->unk990[D_800EB9B8->unk2D].unk1[0] = 0;
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_battle_playMenuLeaveSfx();
                func_800C56C0();
                D_800EB9AC = D_800EB9B8->unk0.unk1 == 2;
                D_800EABAA = 21;
                break;
            }
            *target = D_800EB9B8->unk2D;
            if (vs_main_buttonsPressed.all & 0x20) {
                func_800C56C0();
                D_800EABAA = 20;
                break;
            }
            value = D_800EB9B8->unk2D;
            if (vs_main_buttonRepeat & 1) {
                for (i = 0; i < D_800F4CB3; ++i) {
                    if (D_800F4C98[i] == D_800EB9B8->unk40[value].unk9) {
                        break;
                    }
                }
                if (i != D_800F4CB3) {
                    if (++i == D_800F4CB3) {
                        if (D_800F4CB2 == 0) {
                            goto selected;
                        }
                        goto firstOfRow1;
                    }
                    D_800EB9B8->unk2D = D_800F4CA8[i];
                    goto selected;
                }
                for (i = 0; i < D_800F4CB2; ++i) {
                    if (D_800F4C90[i] == D_800EB9B8->unk40[value].unk9) {
                        break;
                    }
                }
                if (++i == D_800F4CB2) {
                    goto firstOfRow0;
                }
                D_800EB9B8->unk2D = D_800F4CA0[i];
                goto selected;
            }
            for (i = 0; i < D_800F4CB1; ++i) {
                if (D_800F4C70[0][i] == value) {
                    break;
                }
            }
            if (i != D_800F4CB1) {
                if ((vs_main_buttonsPressed.all & 0x8000) && (D_800F4CB0 != 0)) {
                    if (i >= D_800F4CB0) {
                        i = D_800F4CB0 - 1;
                    }
                    goto row1;
                }
                do {
                    if (vs_main_buttonRepeat & 0x1000) {
                        if (i == 0) {
                            if (D_800F4CB0 != 0) {
                                goto lastOfRow1;
                            }
                            i = D_800F4CB1 - 1;
                        } else {
                            --i;
                        }
                    }
                } while (0);
                if (vs_main_buttonRepeat & 0x4000) {
                    if (i != D_800F4CB1 - 1) {
                        ++i;
                    } else {
                        i = 0;
                        if (D_800F4CB0 != 0) {
                            goto firstOfRow1;
                        }
                    }
                }
                D_800EB9B8->unk2D = D_800F4C70[0][i];
                goto selected;
            lastOfRow1:
                D_800EB9B8->unk2D = D_800F4C70[1][D_800F4CB0 - 1];
                goto selected;
            firstOfRow1:
                D_800EB9B8->unk2D = D_800F4C70[1][0];
                goto selected;
            lastOfRow0:
                D_800EB9B8->unk2D = D_800F4C70[0][D_800F4CB1 - 1];
                goto selected;
            firstOfRow0:
                D_800EB9B8->unk2D = D_800F4C70[0][0];
                goto selected;
            }
            for (i = 0; i < D_800F4CB0; ++i) {
                if (D_800F4C70[1][i] == value) {
                    break;
                }
            }
            if (vs_main_buttonsPressed.all & 0x2000) {
                if (i >= D_800F4CB1) {
                    i = D_800F4CB1 - 1;
                }
                D_800EB9B8->unk2D = D_800F4C70[0][i];
                goto selected;
            }
            if (vs_main_buttonRepeat & 0x1000) {
                if (i == 0) {
                    goto lastOfRow0;
                }
                --i;
            }
            if (vs_main_buttonRepeat & 0x4000) {
                if (i == D_800F4CB0 - 1) {
                    goto firstOfRow0;
                }
                ++i;
            }
        row1:
            D_800EB9B8->unk2D = D_800F4C70[1][i];
        selected:
            D_800EB9B8->unk990[D_800EB9B8->unk2D].unk1[0] = 1;
            if (value != D_800EB9B8->unk2D) {
                D_800EB9B8->unk990[D_800EB9B8->unk2D].unk1[2] = 0;
                vs_battle_playMenuChangeSfx();
                func_800C51B4(3);
            }
            entry = &D_800EB9B8->unk40[D_800EB9B8->unk2D];
            i = entry->unk9;
            type = entry->unk8;
            if (i >> 4) {
                vs_battle_stringContext.strings[0] = (char*)&vs_battle_statusStrings
                    [vs_battle_statusStrings[(i >> 5) + VS_statusStrings_INDEX_blocker]];
            } else if (type == 16) {
                vs_battle_stringContext.strings[0] = vs_battle_actors[i]->unk3C->name;
            } else {
                vs_battle_stringContext.strings[0] =
                    (char*)&vs_battle_statusStrings[vs_battle_statusStrings[type]];
            }
            for (value = 1; value < 6; ++value) {
                vs_battle_stringContext.strings[value] = D_800EAA54;
            }
            value = entry->unkB;
            if ((type == 16) && !(i >> 4) && (vs_battle_actors[i]->unk1C & 0x10)) {
                value = 5;
                vs_battle_stringContext.strings[1] =
                    (char*)&vs_battle_statusStrings[vs_battle_statusStrings
                            [entry->unkE == 0 ? VS_statusStrings_INDEX_indestructable
                                              : VS_statusStrings_INDEX__3]];
            } else if (value == 0x3A) {
                value = 1;
            } else if (value == 0x3B) {
                value = 2;
            } else if (value == 0x3E) {
                value = 3;
            } else if (value == 0x3F) {
                value = 4;
            } else {
                vs_battle_stringContext.strings[1] = D_800EA9B6;
                vs_battle_stringContext.strings[6] = _getStatusString(entry->unk10);
                value = 0;
            }
            vs_battle_stringContext.strings[2] =
                (char*)&vs_battle_statusStrings[vs_battle_statusStrings
                        [entry->unk14 + VS_statusStrings_INDEX_indestructable]];
            if (value != 0) {
                if (value < 5) {
                    vs_battle_stringContext.strings[1] =
                        (char*)&vs_battle_statusStrings[vs_battle_statusStrings
                                [VS_statusStrings_INDEX_mpTemplate - (value & 1)]];
                    vs_battle_stringContext.strings[5] =
                        (char*)&vs_battle_statusStrings[vs_battle_statusStrings
                                [entry->unk17 + VS_statusStrings_INDEX_human]];
                }
                vs_battle_stringContext.strings[3] =
                    (char*)&vs_battle_statusStrings[vs_battle_statusStrings
                            [entry->unk15 + VS_statusStrings_INDEX_empty]];
                vs_battle_stringContext.strings[4] =
                    (char*)&vs_battle_statusStrings[vs_battle_statusStrings
                            [entry->unk16 + VS_statusStrings_INDEX_physical]];
            }
            vs_battle_stringContext.integers[0] = entry->unkC;
            vs_battle_stringContext.integers[1] = entry->unkE;
            vs_battle_printf((char*)D_800EB9B8 + 0x4A54, D_800EA984);
            vs_battle_setTextBox(7, (char*)D_800EB9B8 + 0x4A54);
            break;
        case 20:
            *target = D_800EB9B8->unk2D;
            // fallthrough
        case 21:
            vs_battle_dismissTextBox(7);
            func_800C06E0();
            return 1;
        }
    }
    return 0;
}

void func_800C64D0(u_long* arg0, int* arg1)
{
    int a3 = 0xFFFFFF;
    int temp_t0 = ((u_long)(arg0 - 1) & a3);

    while ((*arg0 & a3) != temp_t0) {
        arg0 = (u_long*)((*arg0 & a3) | 0x80000000);
    }

    *arg0 = (*arg0 & 0xFF000000) | ((u_long)arg1 & a3);
    *arg1 = (int)((*arg1 & 0xFF000000) | temp_t0);
}

void vs_battle_renderTextRawColor(char const* text, int x, int color, void* nextPrim)
{
    u_long* prim;
    int y;
    u_char c;
    u_int width;
    u_char const* scan;
    u_char ch;
    u_int index;

    prim = vs_scratch.unk0;
    y = x >> 16;
    x = (short)x;
    if (nextPrim == NULL) {
        nextPrim = vs_scratch.unk8;
    }
    prim[0] = (((u_long)(prim + 2) << 8) >> 8) | 0x01000000;
    prim[1] = 0xE100000C;
    prim += 2;

    while ((c = *text++) != 0) {
        c -= 0x20;
        if (c >= 0x3B) {
            if (c == 0x3B) {
                --x;
            }
        } else if (c - 3 < 2u) {
            width = 0;
            scan = text;
            while ((ch = *scan++) != 0) {
                ch -= 0x20;
                if (ch < 0x3C) {
                    width += (D_800EB7B4[ch >> 1] >> ((ch << 2) & 4)) & 0xF;
                    ch -= 0x21;
                    if (ch < 26) {
                        index = *scan - 0x41;
                        if (index < 26) {
                            index += ch * 26;
                            width -= (D_800EB708[index >> 2] >> ((index & 3) * 2)) & 3;
                        }
                    }
                }
            }
            x -= width >> (c - 3);
        } else {
            width = (D_800EB7B4[c >> 1] >> ((c << 2) & 4)) & 0xF;
            if (width != 0) {
                index = D_800EB7D4[c];
                prim[0] = (((u_long)(prim + 5) << 8) >> 8) | 0x04000000;
                prim[1] = color | 0x64000000;
                prim[2] = (x & 0xFFFF) | (y << 16);
                prim[3] = (index & 0xFE) | (((index & 1) * 10 + 0x4C) << 8) | 0x37F60000;
                prim[4] = width | 0xA0000;
                if (c == 10) {
                    prim[2] = ((x - 1) & 0xFFFF) | ((y - 1) << 16);
                    prim[3] = 0x37F64BE8;
                    prim[4] = width | 0xB0000;
                }
                prim += 5;
                x += width;
                c -= 0x21;
                if (c < 26) {
                    index = *text - 0x41;
                    if (index < 26) {
                        index += c * 26;
                        x -= (D_800EB708[index >> 2] >> ((index & 3) * 2)) & 3;
                    }
                }
            }
        }
    }
    *prim = *(u_long*)nextPrim & 0xFFFFFF;
    *(u_long*)nextPrim = ((u_long)vs_scratch.unk0 << 8) >> 8;
    vs_scratch.unk0 = prim + 1;
}

void vs_battle_renderTextRaw(char const* text, int xy, void* nextPrim)
{
    vs_battle_renderTextRawColor(text, xy, vs_getRGB(128, 128, 128), nextPrim);
}

#pragma vsstring(start)

void _writeStringTerminator(char* str) { *str = '\0'; }

char* vs_battle_printf(char* dest, char* src)
{
    int divisor;
    int integer;
    int c;

    c = *src++;

    while (c != '\0') {
        if (c >= vs_char_control) {
            switch (c) {
            case vs_char_printHex:
                c = *src++;
                integer = vs_battle_stringContext.integers[c % 10];
                if (integer < 0) {
                    integer = -integer;
                    *dest++ = '-';
                }
                if (c < 10) {
                    if (integer == 0) {
                        *dest++ = '0';
                    } else {
                        for (divisor = 0x10000000; (integer / divisor) == 0;
                            divisor >>= 4)
                            ;
                        while (divisor != 0) {
                            *dest++ = (integer / divisor) & 0xF;
                            divisor >>= 4;
                        }
                    }
                } else {
                    c = (c / 10) - 1;
                    divisor = 1;
                    while (c != 0) {
                        --c;
                        divisor *= 16;
                    }
                    while (divisor != 0) {
                        *dest++ = (integer / divisor) & 0xF;
                        divisor >>= 4;
                    }
                }
                break;
            case vs_char_printDecimal:
                c = *src++;
                integer = vs_battle_stringContext.integers[c % 10];
                if (integer < 0) {
                    integer = -integer;
                    *dest++ = '-';
                }
                if (c < 10) {
                    if (integer == 0) {
                        *dest++ = 0;
                    } else {
                        for (divisor = 1000000000; (integer / divisor) == 0;
                            divisor /= 10)
                            ;
                        while (divisor != 0) {
                            *dest++ = (integer / divisor) % 10;
                            divisor /= 10;
                        }
                    }
                } else {
                    c = (c / 10) - 1;
                    for (divisor = 1; c != 0; --c) {
                        divisor *= 10;
                    }
                    while (divisor != 0) {
                        *dest++ = (integer / divisor) % 10;
                        divisor /= 10;
                    }
                }
                break;
            case vs_char_printString:
                dest = vs_battle_printf(
                    dest, vs_battle_stringContext.strings[(u_char)*src++]);
                break;
            default:
                *dest++ = c;
                *dest++ = *src++;
            }
        } else {
            *dest++ = c;
        }
        c = *src++;
    }
    *dest = c;
    return dest;
}
#pragma vsstring(end)

int vs_battle_setTextBox(int boxId, char* str)
{
    vs_battle_textBox* box = &vs_battle_textBoxes[boxId];

    if (str != NULL) {
        box->string = str;
        box->speed = 1;
        box->unk4 = 0;
        box->prevChunksPrinted = 0;
        if (!(box->unk0.unk0_24 & 0x20)) {
            func_800AAD4C(box->unk0.unk0_24, 0, box->unk2E + 1, 1);
            box->unk2C = 1;
        }
        return 0;
    }

    if ((box->speed != 0xFFFF) && (box->speed != 0)) {
        return -1;
    }

    return 0;
}

int vs_battle_selectTextBox(u_char boxMask)
{
    vs_battle_textBox tempBox;
    short yPositions[8];
    int i;
    int j;
    int tempOrder;
    int selectedIndex;
    u_int count = 0;

    if (textBoxSelector.count == 0) {

        for (i = 0; i < 8; ++i) {
            yPositions[i] = 0x7FFF;
            if ((boxMask >> i) & 1) {
                ++count;
                yPositions[i] = vs_battle_textBoxes[i].y;
            }
        }

        for (i = 0; i < count; ++i) {
            int sortedIndex = 0;
            for (j = 0; j < 8; ++j) {
                if (yPositions[sortedIndex] > yPositions[j]) {
                    sortedIndex = j;
                }
            }
            textBoxSelector.order[i] = sortedIndex;
            yPositions[sortedIndex] = 0x7FFF;
        }

        selectedIndex = vs_main_stateFlags.unk11 - 1;

        if (selectedIndex >= count) {
            selectedIndex = 0;
        }

        textBoxSelector.selectedIndex = 0;
        textBoxSelector.count = count;
    } else {
        selectedIndex = textBoxSelector.selectedIndex;
        count = textBoxSelector.count;

        if (vs_main_buttonsPressed.all
            & (PADL2 | PADR2 | PADL1 | PADR1 | PADRup | PADRright | PADRdown
                | PADRleft)) {
            vs_battle_playMenuSelectSfx();
            textBoxSelector.count = 0;
            return selectedIndex + 1;
        }

        if (vs_main_buttonsPressed.all & PADLup) {
            int v0 = selectedIndex - 1;
            selectedIndex = v0 + count;
        }

        if (vs_main_buttonsPressed.all & PADLdown) {
            ++selectedIndex;
        }

        selectedIndex %= count;
    }

    if (selectedIndex != textBoxSelector.selectedIndex) {
        vs_battle_playMenuChangeSfx();
        textBoxSelector.selectedIndex = selectedIndex;
    }

    j = selectedIndex;

    for (i = 0; i < count; ++i) {
        if (textBoxSelector.order[j] < textBoxSelector.order[i]) {
            j = i;
        }
    }

    tempOrder = textBoxSelector.order[selectedIndex];
    textBoxSelector.order[selectedIndex] = textBoxSelector.order[j];
    textBoxSelector.order[j] = tempOrder;

    tempBox = vs_battle_textBoxes[tempOrder];
    vs_battle_textBoxes[tempOrder] =
        vs_battle_textBoxes[textBoxSelector.order[selectedIndex]];
    vs_battle_textBoxes[textBoxSelector.order[selectedIndex]] = tempBox;

    for (i = 0; i < count; ++i) {
        vs_battle_textBoxes[textBoxSelector.order[i]].brightness =
            i == selectedIndex ? 0x80 : 0x40;
    }

    return 0;
}

#pragma vsstring(start)

int vs_battle_getTextLineLength(char* str)
{
    int length = 0;

    while (1) {
        u_char c = *str++;
        if (c < '\f') {
            length += vs_battle_characterWidths[c];
            continue;
        } else if ((c == '\f') || (c == '\0') || (c == '\n')) {
            return length / 6;
        } else if (c == vs_char_spacing) {
            length += *str++;
        } else if (c == vs_char_printDecimal) {
            c = *str++;
            if (c > '9') {
                length += (c / 10) * 6;
            }
        } else if (c >= vs_char_chunkSize) {
            ++str;
        }
    }
}

int vs_battle_printVariableWidthFontChar(u_int glyphId, int x, int y, u_long* ot)
{
    int glyphRow;
    u_int glyphCol;
    u_long* sprite;

    if (glyphId == ' ') {
        return x + 6;
    }

    glyphId += _fontTable * 0xBD;
    sprite =
        vs_battle_setSprite(_fontBrightness, (x & 0xFFFF) | (y << 0x10), 0xC000C, ot + 3);
    sprite[1] = 0xE100002D;
    glyphRow = glyphId / 21;
    glyphCol = glyphId % 21;
    sprite[4] = ((glyphCol * 0xC) | (glyphRow * 0xC00)
                 | ((((((D_800F4CB8 * 0x10) + 0x340) >> 4) & 0x3F) | 0x3780) << 0x10));
    return x + vs_battle_characterWidths[glyphId];
}

void vs_battle_setFontStyle(int arg0)
{
    _fontTable = 0;
    _fontBrightness = 384;
    D_800F4CB8 = arg0;
}

void _printVariableWidthFont(vs_battle_textBox* arg0)
{
    char intBuf[16];
    u_long* sp20 = D_800F51B8 + D_800F4E80 * 4;
    int done = 0;
    int sfx = 0;
    int chunksPrinted = 0;
    char* savedString;
    int speed = 1;
    int justify = 0;
    int inInlineString = 0;
    int postContinuation = 0;
    int charsRemaining = arg0->speed;

    int printX;
    int printY;
    int temp_v0;
    int var_a0;
    int var_a2;
    int hexBufPos;
    int decInt;
    int decBufPos;
    char* currentString;
    u_short temp_v1;
    u_int currentChar;
    u_int opcodeParam;

    if (charsRemaining != 0) {

        _fontTable = arg0->unk0.unk0_0 != 4;
        _fontBrightness = arg0->brightness;
        D_800F4CB8 = (1 - (*((char*)arg0) & 1)) * 4;

        if (arg0->unk0.unk0_0 == 2) {
            _fontTable = 0;
            D_800F4CB8 = 0;
        }
        currentString = arg0->string;
        printX = arg0->xIndent;
        printY = arg0->yIndent;

        arg0->unk0.done = 0;

        while (charsRemaining > 0) {
            if (postContinuation != 0) {
                --postContinuation;
            }
            currentChar = *currentString;
            ++currentString;
            if (currentChar < 0xEC) {
                if (currentChar < '\f') {
                    printX = vs_battle_printVariableWidthFontChar(
                        currentChar, printX, printY, sp20);
                    charsRemaining -= speed;
                    ++chunksPrinted;
                    continue;
                }

                switch (currentChar - 0xE5) {
                case 0: // 0xE5 New page
                    arg0->string = currentString;
                    done = (arg0->speed = 1);
                    arg0->prevChunksPrinted = 0;
                    break;
                case 1: // 0xE6 Continuation arrow
                    if (charsRemaining == 1) {
                        if ((*(&vs_main_buttonsPressed.pad[0].low)) != 0) {
                            charsRemaining = 0;
                        } else {
                            done =
                                (arg0->unk0.arrowAnimFrame + vs_gametime_tickspeed) % 24;
                            printX = vs_battle_printVariableWidthFontChar(
                                0xBC - (done >> 3), printX, printY, sp20);
                            arg0->unk0.arrowAnimFrame = done;
                        }
                        done = 1;
                    } else {
                        --charsRemaining;
                        postContinuation = 2;
                    }
                    break;
                case 2: // 0xE7 Termination
                    if (inInlineString != 0) {
                        currentString = savedString;
                        inInlineString = 0;
                    } else {
                        temp_v1 = arg0->unk2C;
                        temp_v0 = temp_v1 << 0x10;
                        if (temp_v0 > 0) {
                            arg0->unk2C = ((temp_v0 >> 0x12) - temp_v1);
                        }
                        arg0->unk0.done = 1;
                        if (((*(&vs_main_buttonsPressed.pad[0].low)) != 0)
                            || (postContinuation != 0)) {
                            arg0->speed = 0xFFFF;
                        }
                        done = 1;
                    }
                    break;
                case 3: // 0xE8 New line
                    printX = arg0->xIndent;
                    if (justify != 0) {
                        printX += ((arg0->charsPerLine * 2)
                                      - vs_battle_getTextLineLength(currentString))
                                * 3;
                    }
                    printY += 13;
                    break;
                }
                if (done != 0) {
                    break;
                }
            } else {
                opcodeParam = *currentString;
                ++currentString;

                switch (currentChar) {
                case 0xF8: // Character buffer chunking size
                    speed = opcodeParam;
                    break;
                case 0xF9: // Play sfx
                    sfx = opcodeParam;
                    break;
                case 0xFA: // Offset x
                    currentChar = 256;
                    if (opcodeParam >= 240) {
                        printX = printX - currentChar + opcodeParam;
                    } else {
                        printX += opcodeParam;
                    }
                    break;
                case 0xFB: // Manipulate font
                    if (opcodeParam & 0xF8) { // Offset y
                        printY += opcodeParam >> 3;
                    } else {
                        if (opcodeParam == 6) { // Font table 0
                            _fontTable = 0;
                        } else if (opcodeParam == 5) { // Font table 1
                            _fontTable = 1;
                        } else if (opcodeParam == 4) { // Justify
                            justify ^= 1;
                            if (justify != 0) {
                                printX =
                                    (((arg0->charsPerLine * 2)
                                         - vs_battle_getTextLineLength(currentString))
                                        * 3)
                                    + arg0->xIndent;
                            }
                        } else { // Color
                            D_800F4CB8 = (D_800F4CB8 & 4) | opcodeParam;
                        }
                    }
                    break;
                case 0xFC:
                    if (arg0->unk2C > 0) {
                        arg0->unk2C = -opcodeParam;
                    }
                    break;
                case 0xFD: // Print hex
                    hexBufPos = 0;
                    var_a2 = vs_battle_stringContext.integers[opcodeParam % 10];
                    var_a0 = 0x10000000;
                    if (var_a2 < 0) {
                        var_a2 = -var_a2;
                        intBuf[0] = 0xA7;
                        hexBufPos = 1;
                    }
                    if (opcodeParam < 10) {
                        if (var_a2 == 0) {
                            intBuf[hexBufPos++] = 0;
                        } else {

                            while ((var_a2 / var_a0) == 0) {
                                var_a0 >>= 4;
                            }

                            while (var_a0 != 0) {
                                intBuf[hexBufPos++] = (var_a2 / var_a0) & 0xF;
                                var_a0 >>= 4;
                            }
                        }
                    } else {
                        opcodeParam = (opcodeParam / 10) - 1;
                        var_a0 = 1;
                        while (opcodeParam != 0) {
                            --opcodeParam;
                            var_a0 *= 16;
                        }
                        while (var_a0 != 0) {
                            intBuf[hexBufPos++] = (var_a2 / var_a0) & 0xF;
                            var_a0 >>= 4;
                        }
                    }
                    intBuf[hexBufPos] = 0xE7;
                    savedString = currentString;
                    currentString = intBuf;
                    inInlineString = 1;
                    break;
                case 0xFE: // Print decimal
                    decBufPos = 0;
                    decInt = vs_battle_stringContext.integers[opcodeParam % 10];
                    var_a2 = 1000000000;
                    if (decInt < 0) {
                        decInt = -decInt;
                        intBuf[0] = 0xA7; // -
                        decBufPos = 1;
                    }
                    if (opcodeParam < 10) {
                        if (decInt == 0) {
                            intBuf[decBufPos] = 0;
                            ++decBufPos;
                        } else {

                            while ((decInt / var_a2) == 0) {
                                var_a2 /= 10;
                            }

                            while (var_a2 != 0) {
                                intBuf[decBufPos++] = (decInt / var_a2) % 10;
                                var_a2 /= 10;
                            }
                        }
                    } else {
                        opcodeParam = (opcodeParam / 10) - 1;
                        var_a2 = 1;
                        while (opcodeParam != 0) {
                            var_a2 *= 10;
                            --opcodeParam;
                        }
                        while (var_a2 != 0) {
                            intBuf[decBufPos++] = (decInt / var_a2) % 10;
                            var_a2 /= 10;
                        }
                    }
                    intBuf[decBufPos] = 0xE7;
                    savedString = currentString;
                    currentString = intBuf;
                    inInlineString = 1;
                    break;
                case 0xFF: // Print string reference
                    savedString = currentString;
                    currentString = (char*)vs_battle_stringContext.strings[opcodeParam];
                    inInlineString = 1;
                    break;
                }
            }
        }

        if (charsRemaining <= 0) {
            arg0->speed += vs_gametime_tickspeed >> 1;
        }

        if ((arg0->prevChunksPrinted != chunksPrinted) && (sfx != 0)) {
            vs_main_playSfxDefault(0x7E, sfx);
        }

        if (!(arg0->unk0.unk0_24 & 0x20)) {
            if (arg0->unk2C != 0) {
                ++arg0->unk2C;
            } else {
                func_800AAD4C(arg0->unk0.unk0_24, 0, 0, 0);
            }
        }
        arg0->prevChunksPrinted = chunksPrinted;
    }
}

#pragma vsstring(end)

// Looks like some unholy union of hasm and compiled code, leaving as raw asm
int _printFixedWidthFontChar(int charId, int x, int y, int width, int height, int scale);
__asm__("glabel _printFixedWidthFontChar;"
        "addu       $sp, -8;"
        "addu       $t7, $a0, $zero;"
        "addu       $t3, $a1, $zero;"
        "addu       $t0, $a2, $zero;"
        "addu       $t5, $a3, $zero;"
        "lui        $t9, (0x1F800000 >> 16);"
        "lw         $t6, 0x18($sp);"
        "lw         $t8, 0x1C($sp);"
        "lw         $t4, (0x1F800000 & 0xFFFF)($t9);"
        "li         $v0, 0x8F;"
        "beq        $t7, $v0, 0f;"
        "sw         $s0, 0x0($sp);"
        "addu       $t5, $t3;"
        "addu       $t6, $t0;"
        "srl        $t5, 16;"
        "sra        $v0, $t0, 16;"
        "sll        $t0, $v0, 16;"
        "sra        $v0, $t6, 16;"
        "sll        $t6, $v0, 16;"
        "lui        $a1, 0xFF;"
        "lui        $v0, %hi(_fontTable);"
        "or         $a1, 0xFFFF;"
        "lui        $t2, %hi(D_800F51B8);"
        "lui        $a0, %hi(D_800F4CB8);"
        "lbu        $v0, %lo(_fontTable)($v0);"
        "lbu        $a2, %lo(D_800F4CB8)($a0);"
        "sll        $v1, $v0, 1;"
        "addu       $v1, $v0;"
        "sll        $v0, $v1, 6;"
        "subu       $v0, $v1;"
        "addu       $t7, $v0;"
        "la         $v0, vs_battle_characterWidths;"
        "addu       $v0, $t7, $v0;"
        "lui        $v1, %hi(D_800F4E80);"
        "sll        $a2, 4;"
        "addu       $a2, 0x340;"
        "srl        $a2, 4;"
        "and        $a2, 0x3F;"
        "or         $a2, 0x3780;"
        "lbu        $v0, 0x0($v0);"
        "lbu        $a3, %lo(D_800F4E80)($v1);"
        "mult       $v0, $t8;"
        "sll        $a2, 16;"
        "sll        $a3, 4;"
        "lw         $v0, %lo(D_800F51B8)($t2);"
        "or         $a3, 0xC;"
        "addu       $v0, $a3, $v0;"
        "lw         $v1, 0x0($v0);"
        "or         $v0, $t5, $t0;"
        "sw         $v0, 0x10($t4);"
        "lui        $v0, 0x900;"
        "and        $v1, $a1;"
        "li         $a1, 0x86186187;"
        "mflo       $t1;"
        "or         $v1, $v0;"
        "lui        $v0, %hi(_fontBrightness);"
        "multu      $t7, $a1;"
        "sw         $v1, 0x0($t4);"
        "lw         $v1, %lo(_fontBrightness)($v0);"
        "or         $v0, $t5, $t6;"
        "sw         $v0, 0x20($t4);"
        "sw         $v1, 0x4($t4);"
        "addu       $t8, $t3, $t1;"
        "srl        $t3, 16;"
        "or         $t0, $t3, $t0;"
        "or         $t1, $t3, $t6;"
        "sw         $t0, 0x8($t4);"
        "sw         $t1, 0x18($t4);"
        "mfhi       $a1;"
        "subu       $v0, $t7, $a1;"
        "srl        $v0, 1;"
        "addu       $a1, $v0;"
        "srl        $a1, 4;"
        "sll        $v0, $a1, 2;"
        "addu       $v0, $a1;"
        "sll        $v0, 2;"
        "addu       $v0, $a1;"
        "subu       $v0, $t7, $v0;"
        "sll        $v1, $v0, 1;"
        "addu       $v1, $v0;"
        "sll        $t3, $v1, 2;"
        "addiu      $t5, $t3, 0xC;"
        "sll        $a0, $a1, 1;"
        "addu       $a0, $a1;"
        "sll        $a0, 10;"
        "addiu      $t6, $a0, 0xC00;"
        "addu       $v0, $t8, $zero;"
        "or         $v1, $t3, $a0;"
        "or         $v1, $a2;"
        "or         $a0, $t5, $a0;"
        "sw         $v1, 0xC($t4);"
        "lui        $v1, 0xD;"
        "or         $a0, $v1;"
        "or         $v1, $t3, $t6;"
        "sw         $v1, 0x1C($t4);"
        "or         $v1, $t5, $t6;"
        "sw         $v1, 0x24($t4);"
        "sll        $v1, $t4, 8;"
        "sw         $a0, 0x14($t4);"
        "lw         $a0, %lo(D_800F51B8)($t2);"
        "srl        $v1, 8;"
        "addu       $a3, $a0;"
        "sw         $v1, 0x0($a3);"
        "addiu      $v1, $t4, 0x28;"
        "j          1f;"
        "sw         $v1, 0($t9);"
        "0:;"
        "sll        $v0, $t8, 1;"
        "addu       $v0, $t8;"
        "sll        $v0, 1;"
        "addu       $v0, $t3, $v0;"
        "1:;"
        "lw         $s0, 0x0($sp);"
        "j          $ra;"
        "addiu      $sp, 0x8;"
        "endlabel _printFixedWidthFontChar;");

#pragma vsstring(start)
void _printFixedWidthFont(vs_battle_textBox* ctx, int scale)
{
    int justify = 0;
    char* str = ctx->string;
    int charWidth = scale * 12;
    int charHeight = charWidth;
    int lineHeight = scale * 13;

    if (ctx->speed != 0) {
        int temp_s6;
        int done;
        int printX = (ctx->unk24 << 0x10) + ((ctx->xIndent - ctx->x) * scale);
        int printY = (ctx->unk26 << 0x10) + ((ctx->yIndent - ctx->y) * scale);

        D_800F4CB8 = (1 - (*((char*)ctx) & 1)) * 4;
        _fontTable = ctx->unk0.unk0_0 != 4;
        _fontBrightness = ctx->brightness;

        temp_s6 = printX;

        if (ctx->unk0.unk0_0 == 2) {
            _fontTable = 0;
            D_800F4CB8 = 0;
        }

        done = ctx->brightness;
        _fontBrightness = done | (done << 8) | (done << 0x10) | 0x2C000000;
        done = 0;

        while (1) {
            u_int currentChar = *str++;

            if (currentChar < 0xEC) {
                if (currentChar < '\f') {
                    printX = _printFixedWidthFontChar(
                        currentChar, printX, printY, charWidth, charHeight, scale);
                    continue;
                }

                switch (currentChar - '\f') {
                case 2: // 0xE7 Termination
                    done = 1;
                    break;
                case 3: // 0xE8 New line
                    printX = temp_s6;
                    if (justify != 0) {
                        printX = temp_s6
                               + (((ctx->charsPerLine * 2)
                                      - vs_battle_getTextLineLength(str))
                                   * (charWidth >> 2));
                    }
                    printY += lineHeight;
                    break;
                }
                if (done != 0) {
                    break;
                }
            } else {
                u_int opcodeParam = *str++;

                switch (currentChar - 0xF8) {
                case 2: // Offset x
                    if (opcodeParam >= 0xF0) {
                        printX -= ((256 - opcodeParam) * charWidth) / 12;
                    } else {
                        printX += (opcodeParam * charWidth) / 12;
                    }
                    break;
                case 3: // Manipulate font
                    if (opcodeParam & 0xF8) { // Offset y
                        printY += (opcodeParam >> 3) * scale;
                    } else {
                        if (opcodeParam == 6) { // Font table 0
                            _fontTable = 0;
                        } else if (opcodeParam == 5) { // Font table 1
                            _fontTable = 1;
                        } else if (opcodeParam == 4) { // Justify
                            justify ^= 1;
                            if (justify != 0) {
                                printX = temp_s6
                                       + (((ctx->charsPerLine * 2)
                                              - vs_battle_getTextLineLength(str))
                                           * (charWidth >> 2));
                            }
                        } else { // Color
                            D_800F4CB8 = (D_800F4CB8 & 4) | opcodeParam;
                        }
                    }
                    break;
                }
            }
        }
    }
}
#pragma vsstring(end)

void func_800C7EBC(u_short*, u_int, int, u_int);
extern u_short D_800EB98C[16];

void func_800C7EBC(u_short* destination, u_int glyph, int stride, u_int alpha)
{
    RECT rect;
    u_long pixels[18];
    u_short packed;
    int row, column;
    u_short* output;
    u_int inverse = 0x10000 - alpha;
    rect.x = (glyph % 21) * 3 + 0x340;
    rect.y = (glyph / 21) * 12;
    rect.w = 3;
    rect.h = 12;
    StoreImage(&rect, pixels);
    DrawSync(0);
    for (row = 0; row < 12;) {
        for (column = 0, output = destination; column < 12; ++column, ++output) {
            u_short source, previous;
            u_int index;
            if (column & 3)
                packed >>= 4;
            else
                packed = *(u_short*)((u_int)pixels + (((column >> 2) + row * 3) << 1));
            index = packed & 15;
            source = index;
            if (index != 0) {
                previous = *output;
                source = D_800EB98C[source];
                *output =
                    (((((previous & 31) * inverse) + ((source & 31) * alpha)) >> 16) & 31)
                    | (((((previous & 0x3E0) * inverse) + ((source & 0x3E0) * alpha))
                           >> 16)
                        & 0x3E0)
                    | (((((previous & 0x7C00) * inverse) + ((source & 0x7C00) * alpha))
                           >> 16)
                        & 0x7C00);
            }
        }
        ++row;
        destination += stride;
    }
}

#pragma vsstring(start)
void _renderTextImmediate(vs_battle_textBox* arg0, int arg1)
{
    RECT rect;
    int height;
    int _y;
    int done = 0;
    u_short* buf;
    int width;
    int x = arg0->x;
    int y = arg0->y;
    int justify = 0;
    char* str = arg0->string;
    u_int printX = arg0->xIndent - x;
    u_int printY;

    _y = y;
    printY = arg0->yIndent - y;
    width = arg0->charsPerLine * 12 + 10;
    height = arg0->lineCount * 13 + 4;

    if ((x < 0) || (y < 0) || ((x + width) >= 320) || ((y + height) >= 224)) {
        return;
    }

    buf = vs_main_allocHeapR(width * height * 2);

    if ((arg1 >> 0x10) != 0) {
        arg1 = 0x10000;
    }

    setRECT(&rect, x + vs_main_frameBuf * 320, y, width, height);
    StoreImage(&rect, (void*)buf);

    _fontTable = 1;

    while (1) {
        u_int currentChar = *str++;

        if (currentChar < 0xEC) {
            if (currentChar < '\f') {
                if (currentChar != ' ') {
                    currentChar += _fontTable * 21 * 9;
                    if (((width - 12) >= printX) && ((height - 12) >= printY)) {
                        func_800C7EBC(buf + ((printX + (printY * width))), currentChar,
                            width, arg1);
                    }
                }
                printX += vs_battle_characterWidths[currentChar];
            } else {
                switch (currentChar - '\f') {
                case 2:
                    if (vs_main_buttonsPressed.all & PADRright) {
                        arg0->speed = 0xFFFF;
                    }
                    done = 1;
                    break;
                case 3:
                    printX = arg0->xIndent - x;
                    if (justify != 0) {
                        printX +=
                            ((arg0->charsPerLine * 2) - vs_battle_getTextLineLength(str))
                            * 3;
                    }
                    printY += 13;
                    break;
                }
                if (done != 0) {
                    break;
                }
            }
        } else {
            u_int opcodeParam = *str++;
            switch (currentChar - 0xF8) {
            case 2:
                currentChar = 256;
                if (opcodeParam >= 0xF0) {
                    printX = printX - currentChar + opcodeParam;
                } else {
                    printX += opcodeParam;
                }
                break;
            case 3:
                if (opcodeParam & 0xF8) {
                    printY += opcodeParam >> 3;
                } else {
                    if (opcodeParam == 6) {
                        _fontTable = 0;
                    } else if (opcodeParam == 5) {
                        _fontTable = 1;
                    } else if (opcodeParam == 4) {
                        justify ^= 1;
                        if (justify != 0) {
                            printX = ((((arg0->charsPerLine * 2)
                                           - vs_battle_getTextLineLength(str))
                                          * 3)
                                         + arg0->xIndent)
                                   - x;
                        }
                    }
                }
                break;
            }
        }
    }
    vs_battle_renderImage(
        (x + (vs_main_frameBuf * 320)) | (_y << 0x10), buf, width | (height << 0x10));
    DrawSync(0);
    vs_main_freeHeapR(buf);
}
#pragma vsstring(end)

void vs_battle_loadGim(int id, int arg1)
{
    vs_main_CdFile file;
    gim_t* var_s0;
    int i;

    if (D_800EB9BC == NULL) {
        var_s0 = vs_main_allocHeapR(sizeof *var_s0 * 3);
        D_800EB9BC = var_s0;
        var_s0->data = vs_main_allocHeapR((char)_gimLbas[id] << 0xB);

        for (i = 0; i < 3; ++i) {
            *(u_short*)var_s0 = 0;
            var_s0->unk0_1 = 1;
            var_s0->unk0_6 = 1;
            var_s0->unk2 = arg1;
            var_s0->unk3 = 0x80;
            var_s0->id = id;
            var_s0->unk8 = 0;
            var_s0->unkA = 0;
            var_s0->unkC = 0x1000;
            ++var_s0;
        }
        file.lba = _gimLbas[id] >> 8;
        file.size = (u_char)_gimLbas[id] << 0xB;
        D_800EB9BC->cdQueueSlot = vs_main_allocateCdQueueSlot(&file);
        vs_main_cdEnqueue(D_800EB9BC->cdQueueSlot, D_800EB9BC->data);
    }
}

void func_800C8550(u_int arg0, void* arg1, u_char* arg2)
{
    gim_t* gim = &D_800EB9BC[arg0];
    int step;
    int next;
    int i;

    gim->unk0_0 = 1;

    if (gim->unk0_3 == 2) {
        short* p = gim->unk18;
        int angle = vs_battle_keystreamBits(9);
        int target = vs_battle_keystreamBits(10);

        for (i = 0; i < 240; ++i) {
            p[i] = (rsin(angle) >> 3) + 320;
            step = vs_battle_keystreamBits(8) - 64;
            next = vs_battle_keystreamBits(10);

            if (target < angle) {
                angle -= step;

                if (target >= angle) {
                    target = next;
                }
            } else {
                angle += step;

                if (angle >= target) {
                    target = next;
                }
            }

            if (angle < 0) {
                angle = 128;
                target = vs_battle_keystreamBits(10);
            }
        }
    }

    if (gim->unk0_3 == 3) {
        func_8007DFF0(D_800EB9BC->unk2 + D_800EB9BC->unk0_9, 1, 6);
    }
}

void func_800C86AC(void)
{
    gim_t* var_s0 = D_800EB9BC;
    int i;

    if ((var_s0 != NULL) && (var_s0->unk0_6 == 3)) {
        func_8007E0A8(var_s0->unk2, var_s0->unk0_9, 6);
        for (i = 0; i < 3; ++i) {
            if (var_s0->unk0_3 == 3) {
                func_8007E0A8(D_800EB9BC->unk2 + D_800EB9BC->unk0_9, 1, 6);
            }
            ++var_s0;
        }
        vs_main_freeHeapR(D_800EB9BC);
        D_800EB9BC = NULL;
    }
}

void func_800C8778(void)
{
    gim_t* gim = D_800EB9BC;
    gim_t* second = gim + 1;
    gim_t* third = gim + 2;
    gim_t* current;
    int i;
    int j;
    int count;
    int width;
    int tiles;
    int height;
    int _[2] __attribute__((unused));

    if (gim == NULL) {
        return;
    }

    switch (gim->unk0_6) {
    case 0:
        break;
    case 1:
        if (gim->cdQueueSlot->state != 4) {
            return;
        }
        vs_main_freeCdQueueSlot(gim->cdQueueSlot);

        count = gim->data[0];
        width = count & 0xFF;
        j = count >> 8;
        count = width * j + 4;
        ((u_char*)&gim->unk4)[0] = width;
        ((u_char*)&gim->unk4)[1] = j;
        for (i = 0; i < count; ++i) {
            gim->imageTable[i] = gim->data[i];
        }

        if (gim->data[3] != 0) {
            width = gim->data[count];
            tiles = width >> 8;
            ((u_char*)&second->unk4)[0] = width;
            ((u_char*)&second->unk4)[1] = tiles;
            width = (width & 0xFF) * tiles + 4;
            for (i = 0; i < width; ++i) {
                second->imageTable[i] = gim->data[i + count];
            }
            count += width;

            if (gim->data[3] == 2) {
                width = gim->data[count];
                tiles = width >> 8;
                ((u_char*)&third->unk4)[0] = width;
                ((u_char*)&third->unk4)[1] = tiles;
                width = (width & 0xFF) * tiles + 4;
                for (i = 0; i < width; ++i) {
                    third->imageTable[i] = gim->data[i + count];
                }
                count += width;
            }
        }

        count = (count + 1) & 0xFFFE;
        width = (gim->unk2 - 24) * 64;
        vs_battle_renderImage((width + 512) | 0x1FF0000, gim->data + count, 0x10040);

        for (j = 0; j < 3; ++j) {
            current = &gim[j];
            switch (current->imageTable[2]) {
            case 0:
                current->unk0_2 = 0;
                current->unkE = gim->data[count + j * 16];
                break;
            case 1:
                current->unk0_2 = 1;
                current->unkE = gim->data[count + 64];
                break;
            case 2:
                current->unk0_2 = 1;
                current->unkE = gim->data[count + 320];
                current->unk0_12 = 1;
                vs_battle_renderImage(
                    (width + 512) | 0x1FF0000, gim->data + (count + 320), 0x10100);
                break;
            }
        }

        vs_main_loadClut(gim->data + (count + 64), 3, 0, 256);

        i = gim->data[1];
        height = i >> 8;
        i &= 0xFF;
        j = (i + 16) / 17;
        gim->unk0_9 = j;
        second->unk0_9 = j;
        third->unk0_9 = j;
        height *= 16;
        count += height;
        func_8007DFF0(gim->unk2, gim->unk0_9, 6);

        while (i > 0) {
            vs_battle_renderImage((width + 512) | 0x1000000, gim->data + count,
                i >= 17 ? 0xFF0040 : ((i * 15) << 16) | 64);
            i -= 17;
            count += 0x3FC0;
            width += 64;
        }
        gim->unk0_6 = 2;
        break;
    case 2:
        vs_main_freeHeapR(gim->data);
        for (j = 0; j < 3; ++j) {
            gim[j].unk0_1 = 0;
        }
        gim->unk0_6 = 3;
        break;
    case 3:
        for (j = 0; j < 3; ++j) {
            if (gim[j].unk0_0) {
                func_800CCA90(j);
            }
        }
        break;
    }
}

int vs_battle_loadMenuPrg(int arg0)
{
    vs_battle_menuState_t* state = &vs_battle_menuState;
    int subMenu = arg0 & 0x1F;

    if (subMenu == 31) {
        return 1;
    }

    if (subMenu == 0 && _loadedSubMenu > 0) {
        return 1;
    }

    if (_loadedSubMenu != subMenu) {
        void* overlaySlot;
        vs_main_CdFile file;
        u_int fileData;

        _loadedSubMenu = subMenu;
        state->loading = 1;

        if (vs_battle_shortcutInvoked != 5) {
            fileData = _menuLbas[subMenu];
        } else {
            fileData = VS_MAINMENU_PRG_LBA << 8 | VS_MAINMENU_PRG_SIZE >> 11;
        }

        file.lba = fileData >> 8;
        file.size = (fileData & 0xFF) << 11;
        state->cdQueue = vs_main_allocateCdQueueSlot(&file);

        if (subMenu == 0) {
            overlaySlot = vs_overlay_slots[1];
        } else {
            overlaySlot = vs_overlay_slots[2];
        }

        vs_main_cdEnqueue(state->cdQueue, overlaySlot);
    }

    if (state->loading == 0) {
        if (_menuBgUnpackedBuf != NULL) {

            vs_main_freeHeapR(_menuBgUnpackedBuf);

            _menuBgUnpackedBuf = NULL;

            vs_mainMenu_initInventory();
        }

        return 1;
    }

    if (state->cdQueue->state == vs_main_CdQueueStateLoaded) {

        vs_main_freeCdQueueSlot(state->cdQueue);
        vs_main_wait();

        state->loading = 0;

        if (D_800F4FDB != 0) {
            if (vs_battle_shortcutInvoked == 5) {
                vs_mainMenu_miscItemsShortcutMenu(1);
                return 0;
            }
            return 1;
        }

        if (subMenu == 0) {
            _menuBgUnpackedBuf = (u_int*)vs_main_allocHeapR(0xB400);
            vs_mainMenu_unpackMenubg(_menuBgUnpackedBuf);
        }
    }

    return 0;
}

void vs_battle_initInformationTextBox(enum vs_battle_informationTextBoxHeader header)
{
    vs_battle_initTextBox(7, (header << 8) | 4, 0, 1, 0, 4, 0, 0);
}

vs_battle_menuItem_t* vs_battle_getMenuItem(int id) { return vs_battle_menuItems + id; }

vs_battle_menuItem_t* vs_battle_setMenuItem(
    int row, int x, int y, int w, int backgroundWidth, char* text)
{
    vs_battle_menuItem_t* menuItem;
    vs_battle_menuItem_t* var_a0;
    int i;
    u_int c;

    menuItem = &vs_battle_menuItems[row];
    menuItem->state = 1;
    menuItem->w = w;
    menuItem->backgroundWidth = backgroundWidth;

    vs_battle_rMemzero(&menuItem->gradientState, 0x3C);

    var_a0 = menuItem;
    menuItem->x = x;
    menuItem->y = y;

    for (i = 0; i < 31;) {

        c = *text++;
        if (c == vs_char_spacing) {
            var_a0->text[i++] = c;
            c = *text++;
        } else if (c == vs_char_terminator) {
            var_a0->text[i] = 0xFF;
            break;
        } else if (c >= vs_char_nonPrinting) {
            continue;
        }

        var_a0->text[i++] = c;
    }

    return menuItem;
}

/**
 * Lerps between two colors.
 *
 * @param brightness Color multiplier
 * @param blendFactor Proportion of color0 to color1
 */
u_int _lerpColor(u_int color0, u_int color1, int brightness, int blendFactor)
{
    u_int i;
    u_int ret = 0;

    for (i = 0; i < 3; ++i) {
        u_int temp_lo = ((((color0 >> 0x10) & 0xFF) * (8 - blendFactor))
                            + (((color1 >> 0x10) & 0xFF) * blendFactor))
                      * brightness;
        color0 <<= 8;
        ret = (ret << 8) + (temp_lo >> 0xA);
        color1 <<= 8;
    }

    return ret;
}

int vs_battle_uiGradientStop(u_int gradient, u_int colorIndex, int brightness)
{
    u_int color0;
    u_int color1;

    if (colorIndex < 9) {
        color0 = _lerpColor(0x6B4100, 0x6C8219, 0x80, colorIndex);
        color1 = _lerpColor(0x330500, 0x262801, 0x80, colorIndex);
    } else {
        color0 = D_800EBBB8[((colorIndex >> 3) - 2)];
        color1 = D_800EBBC0[((colorIndex >> 3) - 2)];
    }

    return _lerpColor(color0, color1, brightness, gradient);
}

void vs_battle_renderMenuItem(vs_battle_menuItem_t* menuItem)
{

    int y = menuItem->gradientState;
    u_long* scratch = *(void**)0x1F800008 + 8;
    int w = menuItem->w;
    int bgWidth = menuItem->backgroundWidth;
    char* text = menuItem->text;

    if (menuItem->state != 0) {
        int temp_v1;
        int x;
        int c;
        int var_s2;
        char* pText;
        int color;
        u_long* prim;
        char** v;

        if ((menuItem->selected | menuItem->invertGradient) && !menuItem->unselectable) {
            y = 8;
        }

        color = menuItem->fontColor;

        if (color == 0) {
            color = menuItem->unselectable * 3;
        }

        vs_battle_setFontStyle(color + 4);

        temp_v1 = menuItem->x;
        var_s2 = temp_v1 + 6;

        if ((menuItem->rowIcon - 1) < 23u) {
            var_s2 = temp_v1 + 22;
        }

        c = text[0];
        pText = text + 1;

        while (c != 0xFF) {
            if (c == vs_char_spacing) {
                var_s2 += *pText++;
            } else {
                var_s2 = vs_battle_printVariableWidthFontChar(
                    c, var_s2, menuItem->y, scratch - 3);
            }
            c = *pText++;
        }

        c = vs_battle_uiGradientStop(8 - y, bgWidth, 128);
        var_s2 = vs_battle_uiGradientStop(y, bgWidth, 128);

        if (bgWidth & 7) {
            menuItem->backgroundWidth = (bgWidth + 1) & 0xF;
        }

        if (y != 0) {
            menuItem->gradientState = y - 1;
        }

        x = *(int*)&menuItem->x;
        y = x >> 0x10;
        x &= 0xFFFF;

        vs_battle_addTile(scratch + 1, 0x60000000, vs_getXY_2(x + 2, y + 2), w | 0xC0000);

        prim = *(void**)0x1F800000;

        prim[0] = ((*scratch & 0xFFFFFF) | 0x0A000000);
        prim[1] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
        prim[2] = vs_getRGB0Raw(primPolyG4, c);
        prim[3] = (x | (y << 0x10));
        prim[4] = var_s2;
        prim[5] = (((x + w) & 0xFFFF) | (y << 0x10));
        prim[6] = c;
        prim[7] = (x | ((y + 12) << 0x10));
        prim[8] = var_s2;
        prim[9] = (((x + w) & 0xFFFF) | ((y + 12) << 0x10));
        prim[10] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOff);

        *scratch = (u_int)((u_long)prim << 8) >> 8;
        *(void**)0x1F800000 = prim + 11;

        v = &menuItem->subText;
        if (*v != NULL) {
            vs_battle_renderTextRaw(*v, (x - 10) | ((y + 1) << 0x10), scratch);
        }
    }
}

extern int D_800F4CC0;
extern char D_800EBA78[];

int func_800C930C(int mode)
{
    u_int selected = vs_battle_submenuStates[0];
    vs_battle_menuItem_t* items = vs_battle_menuItems;
    u_int enabled = vs_main_settings.menuFlags;
    u_int mask;
    u_int conditions;

    if (mode) {
        if (mode == 2 && !vs_main_settings.cursorMemory) {
            selected = 0;
        }
        while (!((enabled >> selected) & 1)) {
            selected = (selected + 1) % 10;
        }
        vs_battle_submenuStates[0] = selected;
        vs_battle_rMemzero(vs_battle_menuItems, 0xB24);
        mask = 9;
        for (mode = 0; mode < 10; ++mode) {
            if ((enabled >> mode) & 1) {
                items[mode].animationStep = mask++;
            }
        }
        D_800F4CC0 = -mask;
        return 0;
    }

    if (D_800F4CC0 < 0) {
        ++D_800F4CC0;
        for (selected = 0; mode < 10; ++mode) {
            if ((enabled >> mode) & 1) {
                u_char step = items[mode].animationStep;
                if (step != 0) {
                    items[mode].animationStep = --step;
                }
                vs_battle_setMenuItem(mode, vs_battle_rowAnimationSteps[step] + 194,
                    selected * 16 + 18, 126, mode == 10 ? 24 : 0,
                    (char*)&vs_battle_menuStrings[vs_battle_menuStrings[mode]]);
                ++selected;
                mask = D_800F4EA0;
                items[0].unselectable = (mask & 0xB7) != 0;
                items[1].unselectable = (mask & 0x15F) != 0;
                items[3].unselectable = (mask & 7) != 0;
                items[5].unselectable = vs_battle_getCurrentSceneId() == 0;
            }
        }
        return 0;
    }

    if (vs_main_buttonsPressed.all & PADRright) {
        vs_battle_playMenuSelectSfx();
        items[selected].backgroundWidth = items[selected].selected = 1;
        vs_battle_textBoxes[7].state = 0;
        return selected + 1;
    }
    items[selected].selected = 0;
    if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
        vs_battle_playMenuLeaveSfx();
        vs_battle_textBoxes[7].state = 0;
        return -1;
    }
    if (vs_main_buttonRepeat & PADLup) {
        do {
            selected = (selected + 9) % 10;
        } while (!((enabled >> selected) & 1));
    }
    if (vs_main_buttonRepeat & PADLdown) {
        selected = (selected + 1) % 10;
    }
    while (!((enabled >> selected) & 1)) {
        selected = (selected + 1) % 10;
    }
    if (selected != vs_battle_submenuStates[0]) {
        vs_battle_playMenuChangeSfx();
        vs_battle_submenuStates[0] = selected;
    }
    items[selected].selected = 1;
    D_800F4CC0 = vs_battle_drawCursor(D_800F4CC0, (items[selected].y >> 4) - 1);

    if (items[selected].unselectable) {
        if (vs_main_buttonsState & (PADLup | PADLdown)) {
            return 0;
        }
        vs_battle_initInformationTextBox(1);
        vs_battle_textBoxes[7].state = 11;
        vs_battle_setTextBox(7, D_800EBA78);
        mask = 0;
        if (selected == 0) {
            mask = 0xB7;
        }
        if (selected == 1) {
            mask = 0x15F;
        }
        if (selected == 3) {
            mask = 7;
        }
        conditions = D_800F4EA0 & mask;
        for (mode = 0; mode < 9; ++mode) {
            if (conditions & (1 << mode)) {
                break;
            }
        }
        vs_battle_stringContext.strings[0] =
            (char*)&vs_battle_menuStrings[vs_battle_menuStrings[mode + 12]];
    } else {
        vs_battle_textBoxes[7].state = 0;
    }
    return 0;
}

void func_800C97BC(void)
{
    vs_battle_menuItem_t* var_s2;
    int temp_s1;
    int miscIndex;
    int i;
    int var_s0;

    var_s2 = vs_battle_menuItems;
    var_s0 = vs_battle_menuState.currentMenu;

    if (var_s0 == 0x7F) {
        D_800F4E98.unk0 = 2;
        vs_battle_menuState.currentMenu = 0x3F;
    }

    temp_s1 = var_s0 & 0x3F;

    if (temp_s1 != 0x3F) {
        if (vs_battle_loadMenuPrg(0) != 0) {

            if (vs_battle_shortcutInvoked == 5) {
                vs_mainMenu_miscItemsShortcutMenu(0);
                return;
            }

            vs_mainMenu_exec(var_s0);
            return;
        }

        if (temp_s1 == 0) {

            miscIndex = func_800C930C(0);

            if (miscIndex != 0) {

                var_s0 = 0x1F;

                if (miscIndex > 0) {
                    var_s0 = miscIndex | 0x40;
                }

                vs_battle_menuState.currentMenu = var_s0;
            }
        }

        if ((var_s0 >= 0x1F) || (temp_s1 == 0)) {
            for (i = 0; i < 10; ++i) {
                vs_battle_renderMenuItem(var_s2);
                ++var_s2;
            }
        }
    }
}

void _renderDigit(int font, int xy, int digit, u_long* before)
{
    u_long* prim = vs_battle_setSpriteDefaultTexPage(
        128, xy + ((font & 2) << 0x10), (0x05CA0576 >> (font * 4)) & 0xF000F, before);

    prim[4] = vs_getUV0Clut(32, 11, 832, 223);

    if (font != 2) {
        ((short*)prim)[8] = ((((digit * 2) + 64) * (font + 3)) - 192);
    }
}

int vs_battle_renderValue(int font, int xy, int value, u_long* before)
{
    int new_var;

    if (before == NULL) {
        before = vs_scratch.unk4 - 0x10;
    }

    do {
        value = vs_battle_toBCD(value);

        _renderDigit(font, xy, value & 0xF, before);

        new_var = xy - 5;
        xy = new_var - font;
        value >>= 4;
    } while (value != 0);

    return xy;
}

void vs_battle_renderStatBar(int colorIndex, int w, u_long* before, int xy)
{
    int rgb0;
    u_int rgb1;
    u_long* primBuf;

    rgb1 = D_800EBC04[colorIndex];
    primBuf = vs_scratch.unk0;

    rgb0 = (((w * 0xFF) + ((rgb1 & 0xFF) * (0x40 - w))) >> 6)
         | ((((w * 0xF0) + (((rgb1 >> 8) & 0xFF) * (0x40 - w))) >> 6) << 8)
         | ((((w * 0x9E) + ((rgb1 >> 16) * (0x40 - w))) >> 6) << 16);

    primBuf[0] = (*before & 0xFFFFFF) | (w == 0 ? 0x03000000 : 0x0D000000);
    primBuf[1] = vs_getRGB0(primTile, 0x00, 0x28, 0x40);
    primBuf[2] = xy;
    primBuf[3] = 0x50042;
    primBuf[4] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
    primBuf[5] = rgb0 | (primPolyG4 << 24);
    xy += vs_getXY(1, 1);
    primBuf[6] = xy;
    primBuf[7] = rgb1;
    primBuf[8] = xy + w;
    xy += vs_getXY(0, 3);
    primBuf[9] = rgb0;
    primBuf[10] = xy;
    primBuf[11] = rgb1;
    rgb1 = w;
    primBuf[12] = xy + rgb1;
    primBuf[13] = vs_getTpage(0, 0, 0, 0, 0);
    *before = ((u_long)primBuf << 8) >> 8;
    vs_scratch.unk0 = primBuf + 14;
}

void _renderStatBar(int colorIndex, int current, int max)
{
    u_long* prim = vs_scratch.unk4 - 0xC;
    int xy = D_800EBBDC[colorIndex] - D_800EB9B0;

    if (max != 0) {
        vs_battle_renderStatBar(colorIndex, (((current << 6) + max) - 1) / max, prim, xy);
        if (colorIndex & 2) {
            xy += 54 | (3 << 0x10);
            if (colorIndex == 3) {
                current = (current + 0xFF) >> 8;
            }
        } else {
            xy = vs_battle_renderValue(0, xy + (56 | ((u_short)-8 << 0x10)), max, NULL);
            _renderDigit(2, xy, 0, prim);
            xy += (u_short)-7 | ((u_short)-2 << 0x10);
        }
        vs_battle_renderValue(1, xy, current, NULL);
        vs_battle_setSpriteDefaultTexPage(0x180, D_800EBBEC[colorIndex] - D_800EB9B0,
            D_800EBBFC[colorIndex] | 0x90000, prim)[4] =
            D_800EBC00[colorIndex] | 0x37F60000;
    }
}

void func_800C9CB4(int arg0, int arg1, int arg2)
{
    int var_s1;
    int var_s2;
    u_long* temp_a0;

    if ((arg0 != 0xFF) && (D_800EB9B0 == 0)) {

        var_s2 = vs_battle_statusIconTexOffsets[arg0];
        arg2 = (arg2 * 0x10) + 0xA0;

        if (arg1 < 0) {
            var_s2 -= arg1;
            var_s1 = arg1 + 0x10;
        } else {
            arg2 += arg1;
            var_s1 = 0x10 - arg1;
        }

        temp_a0 = vs_battle_setSpriteDefaultTexPage(
            0x80, arg2 | 0x80000, var_s1 | 0x100000, vs_scratch.unk4 - 4);

        temp_a0[4] = (var_s2 | (((0x0F0F906A >> arg0) & 1) ? 0x37F90000 : 0x37F80000));

        if ((arg0 & 0x10) && !(arg2 & 8)) {
            var_s2 = (arg0 & 3) * 8 + 0x3068;
            if (var_s1 >= 9) {
                if (arg2 & 7) {
                    arg2 += 8;
                    var_s1 -= 8;
                } else {
                    int v0 = arg2 - 8;
                    arg2 = v0 + var_s1;
                    var_s1 = 8;
                }
            } else {
                int v0 = (arg0 & 3) * 8 + 0x3070;
                var_s2 = v0 - var_s1;
            }

            vs_battle_setSpriteDefaultTexPage(0x80, arg2 | 0x80000, var_s1 | 0x80000,
                vs_scratch.unk4 - 4)[4] = var_s2 | 0x37FF0000;
        }
    }
}

int vs_battle_getStatusFlags(vs_battle_actor2* arg0)
{
    int i;
    int temp_v1 = (u_int)arg0->statuses >> 5;
    int var_a2 = temp_v1 & 0xFFFF;
    temp_v1 >>= 16;

    for (i = 0; i < 8; ++i) {
        if ((temp_v1 >> i) & 1) {
            var_a2 |= D_800EBC68[i] << 16;
        }
    }

    return var_a2;
}

int vs_battle_getLimbStatus(vs_battle_uiEquipment_limb* limb)
{
    int maxHp = limb->maxHp;

    if (limb->hp < 2) {
        return limbStatusCritical;
    }

    if ((limb->hp * 4) < maxHp) {
        return limbStatusDamaged;
    }

    if ((limb->hp * 4) < (maxHp * 3)) {
        return limbStatusWounded;
    }

    if (limb->hp < maxHp) {
        return limbStatusGood;
    }

    return limbStatusExcellent;
}

int func_800C9EB8(int arg0)
{
    int temp_s0 = func_800CABE0(0);
    int var_s2 = 0x180;

    switch (arg0) {
    case 0:
    case 1:
    case 2:
    case 3:
        if (vs_battle_isSpellClassUnlocked((0x3021 >> (arg0 * 4)) & 0xF) == 0) {
            return 0;
        }
        if (temp_s0 & 0xB7) {
            var_s2 = 0x140;
        }
        break;
    case 4:
        if (temp_s0 & 0x7) {
            var_s2 = 0x140;
        }
        break;
    case 5:
    case 6:
        if (vs_battle_chainAbilitiesUnlocked(6 - arg0) == 0) {
            return 0;
        }
        break;
    case 7:
        if (_breakArtsUnlocked() == 0) {
            return 0;
        }
        if (temp_s0 & 0x15F) {
            var_s2 = 0x140;
        }
        break;
    default:
        break;
    }
    return var_s2;
}

void func_800C9F88(void) { D_800EBC78 = 1; }

void func_800C9F98(int arg0, int arg1)
{
    u_long* temp_v0 =
        vs_battle_setSpriteDefaultTexPage(arg1, arg0, 0x60006, vs_scratch.unk8);
    temp_v0[1] = 0xE1000017;
    temp_v0[4] = 0x373D80C0;
}

void func_800C9FE8(void)
{
    int temp_s3;
    int temp_v0;
    int i;
    u_long* temp_v0_2;

    if (D_800EBC78 != 0) {
        if (D_800EBCE8 != 0) {
            D_800EBCE8 -= 1;
        }
    } else {
        D_800EBCE8 = vs_battle_animationIndices[D_800EBCE8];
    }

    if (D_800EBCE8 != 10) {

        temp_s3 = -vs_battle_rowAnimationSteps[D_800EBCE8];

        for (i = 0; i < 4; ++i) {
            temp_v0 = func_800C9EB8(i + 4);
            if (temp_v0 != 0) {
                func_800C9F98(
                    ((temp_s3 + D_800EBC98[i]) & 0xFFFF) | (D_800EBC98[i + 4] << 0x10),
                    temp_v0);
                temp_v0_2 = vs_battle_setSpriteDefaultTexPage(temp_v0,
                    ((temp_s3 + D_800EBCA0[i]) & 0xFFFF) | (D_800EBCA0[i + 4] << 0x10),
                    D_800EBCA8[i], vs_scratch.unk8);
                temp_v0_2[1] = 0xE1000017;
                temp_v0_2[4] = (*((i) + D_800EBCB8) | 0x373D0000);
            }
        }

        vs_battle_setSpriteDefaultTexPage(0x180, ((temp_s3 + 0x48) & 0xFFFF) | 0x660000,
            0x1E001E, vs_scratch.unk8)[4] = 0x37FBA0B8;
        temp_s3 = (0xA0 - temp_s3);

        for (i = 0; i < 4; ++i) {
            temp_v0 = func_800C9EB8(i);
            if (temp_v0 != 0) {
                func_800C9F98(
                    ((temp_s3 + D_800EBCC0[i]) & 0xFFFF) | (D_800EBCC0[i + 4] << 0x10),
                    temp_v0);
                temp_v0_2 = vs_battle_setSpriteDefaultTexPage(temp_v0,
                    (((temp_s3 + D_800EBCC8[i]) - 2) & 0xFFFF)
                        | (D_800EBCC8[i + 4] << 0x10),
                    D_800EBCD0[i], vs_scratch.unk8);
                temp_v0_2[1] = 0xE1000017;
                temp_v0_2[4] = D_800EBCE0[i] | 0x373D0000;
            }
            vs_battle_setSpriteDefaultTexPage(0x80, temp_s3 + D_800EBC88[3 - i], 0x100010,
                vs_scratch.unk8)[4] = (((3 - i) * 0x10) | 0x37FB8000);
        }
    }
    D_800EBC78 = 0;
}

void func_800CA2DC(void)
{
    u_long* prim;
    vs_battle_actor2* actor;
    void* ot;
    int i;
    int j;
    int k;
    int rightX;
    u_int flags;
    u_int count;
    int selected;

    actor = vs_battle_characterState->unk3C;
    ot = vs_scratch.unk4 - 4;
    func_800C9FE8();

    if (D_800EB9CC == 1) {
        if ((u_char)D_800EB9CD < 4) {
            D_800EBD64 = 0;
            ++D_800EB9CD;
        }
    } else if (D_800EB9CD != 0) {
        --D_800EB9CD;
    }

    if (D_800EB9CD != 0) {
        prim = vs_battle_setSprite(0x140,
            ((((u_char)D_800EB9CD * 3 - 4) << 16) - D_800EB9B0) | 0xEC, 0xA0049,
            vs_scratch.unk4 - 0xC);
        prim[1] = 0xE1000017;
        k = rsin(D_800EBD64 & 0x7FF);
        prim[4] = 0x373D0040;
        prim[2] += k >> 5;
        D_800EBD64 += vs_gametime_tickspeed * 64;
    }

    if (D_800EB9AF != 0) {
        if (D_800EB9B0 == 0x200000) {
            return;
        }
        D_800EB9B0 += 0x80000;
    } else {
        k = vs_battle_textBoxes[7].state;
        if (!(vs_battle_lowerScreenUiState & 2)
            && ((k == 0) || (k != vs_battle_textBoxes[7].unk22 + 1))) {
            k = 0xB80008;
            for (i = 0; i < 5; ++i) {
                j = i + (D_800EB9CC & 1) * 5;
                prim = vs_battle_setSpriteDefaultTexPage(
                    0, k + D_800EBCEC[j], D_800EBD14[j], ot);
                prim[2] = D_800EBC54[vs_battle_getLimbStatus(
                              &vs_battle_characterState->unk3C->limbs[i])]
                        | 0x64000000;
                prim[4] = D_800EBD3C[j];
            }
        }
        if (D_800EB9B0 != 0) {
            D_800EB9B0 -= 0x80000;
        }
    }

    _renderStatBar(0, actor->currentHP, actor->maxHP);
    _renderStatBar(1, actor->currentMP, actor->maxMP);
    if ((k = actor->risk) != 0) {
        _renderStatBar(2, k, 100);
    }
    if (k == 0) {
        vs_battle_renderTextRaw(
            "RISK  ZERO", 0x16000C - D_800EB9B0, vs_scratch.unk4 - 0xC);
    }

    if (D_800EB9AE != 0) {
        return;
    }

    flags = vs_battle_getStatusFlags(actor);
    count = 0;
    selected = 0xFF;
    for (j = 0; j < 32; ++j) {
        if ((flags >> j) & 1) {
            if (j == D_800EB9D0.u8[1]) {
                selected = count;
            }
            ++count;
        }
    }
    for (j = 0; j < 3; ++j) {
        if (!((flags >> D_800EB9D0.u8[j]) & 1)) {
            D_800EB9D0.u8[j] = 0xFF;
        }
    }

    if (count == 0) {
        return;
    }

    j = D_800EB9D0.u8[3];
    if (j == 12) {
        D_800EB9D0.u8[0] = D_800EB9D0.u8[1];
        D_800EB9D0.u8[1] = D_800EB9D0.u8[2];
        D_800EB9D0.u8[2] = 0xFF;
        i = (D_800EB9D0.u8[1] + 1) & 0xFF;
        for (k = 0; k < 32; ++k, ++i) {
            i %= 32;
            if (((flags >> i) & 1) && (i != D_800EB9D0.u8[1])) {
                D_800EB9D0.u8[2] = i;
                break;
            }
        }
    }

    k = 1; // dead store kept for codegen: count == 1 below is compared against this
           // register
    if ((D_800EB9D0.u8[0] == D_800EB9D0.u8[2]) && (D_800EB9D0.u8[1] != 0xFF)) {
        if ((count == 1) && (j < 3)) {
            j = 0;
        }
        if ((count == 2) && (D_800EB9D0.u8[0] != 0xFF) && ((u_int)(j - 12) < 3)) {
            j = 12;
        }
    }

    k = -8;
    if (j >= 9) {
        if (j < 12) {
            k = 8 - j * 2;
        } else {
            k = 24 - j * 2;
        }
    }

    if ((++j != D_800EB9D0.u8[3]) && (vs_gametime_tickspeed == 4)) {
        j = (j + 1) & 0xE;
    }
    rightX = k + 16;
    D_800EB9D0.u8[3] = j & 0xF;
    func_800C9CB4(D_800EB9D0.u8[2], rightX, 1);
    ot -= 4;
    func_800C9CB4(D_800EB9D0.u8[1], k, 1);
    func_800C9CB4(D_800EB9D0.u8[1], rightX, 0);
    func_800C9CB4(D_800EB9D0.u8[0], k, 0);

    k = 0x80000 - D_800EB9B0;
    if (count < 3) {
        for (i = 0; i < count; ++i) {
            prim =
                vs_battle_setSpriteDefaultTexPage(0x80, (0x94 + i * 3) | k, 0x40004, ot);
            prim[4] = 0x37F40C1A;
        }
        return;
    }

    j = k + 0x30000;
    if (selected != 0xFF) {
        prim = vs_battle_setSprite(
            0x80, ((selected & 7) * 3 + 0x94) | (!(selected & 8) ? k : j), 0x40004, ot);
        prim[4] = 0x37F40C1A;
    }
    i = 25;
    if (count < 9) {
        i = count * 3 + 1;
    } else {
        prim = vs_battle_setSprite(0x80, j | 0x94, ((count - 8) * 3 + 1) | 0x40000, ot);
        prim[4] = 0x37F40C00;
    }
    prim = vs_battle_setSpriteDefaultTexPage(0x80, k | 0x94, i | 0x40000, ot);
    prim[4] = 0x37F40C00;
}

void func_800CA97C(void)
{
    D_800EB9B4 = NULL;
    memset(&D_800F4ED8, 0, sizeof D_800F4ED8);
    D_800F4ED8[2] = 0x1000;
}

void func_800CA9C0(void* arg0)
{
    D_800EB9AC = 0;
    _loadedSubMenu = 0;
    D_800EB9AE = 0;
    D_800EB9B0 = 0;
    D_800F4ED4 = 0;
    D_800EB9B4 = NULL;
    D_800EB9B8 = NULL;
    D_800EB9BC = NULL;
    vs_battle_menuItems = 0;
    D_800EB9CE = 0;
    vs_battle_lowerScreenUiState = 0;
    D_800EB9AF = 0;
    D_800EB9CC = 0;
    D_800EB9CD = 0;
    D_800EB9D0.s32 = 0xFFFFFF;
    _menuBgUnpackedBuf = NULL;
    D_800EB9D8 = 0;
    func_800CA97C();
    vs_battle_rMemzero(&vs_battle_menuState, 8);
    vs_battle_menuState.currentMenu = 0x3F;
    vs_battle_rMemzero(&D_800F4E98, sizeof D_800F4E98);
    vs_battle_rMemzero(&vs_battle_textBoxes[0], sizeof vs_battle_textBoxes[0]);
    vs_battle_rMemzero(vs_battle_submenuStates, sizeof vs_battle_submenuStates);
    D_800F4EE8 = (D_800F4EE8_t) { { 0 } };
    D_800F51B8 = &D_800F4CD0;
    vs_battle_renderImage(0x340, arg0, 0xE00040);
    vs_battle_renderImage(0x380, arg0 + 0x7000, 0xE00040);
    vs_battle_renderImage(0x4203C0, arg0 + 0xE000, 0x9E0040);
    DrawSync(0);
    ClearOTag(D_800F51B8, 0x22);
}

void func_800CAB40(void)
{
    D_800F4E98.unk2 = 0;
    D_800F4E98.unk0 = 1;
    if (vs_battle_shortcutInvoked == 5) {
        vs_battle_menuState.currentMenu = 4;
        vs_mainMenu_miscItemsShortcutMenu(2);
    } else {
        vs_battle_menuState.currentMenu = vs_battle_menuState.returnState;
        vs_battle_submenuStates[vs_battle_menuState.returnState & 0xF] =
            vs_battle_menuState.executeAbilityType;
    }
    if (D_800F4FDB == 0) {
        func_8007DFF0(0x1A, 3, 6);
    }
}

int func_800CABE0(int arg0)
{
    int ret;
    vs_battle_actor2* actor = vs_battle_characterState->unk3C;
    int temp_v0 = func_800A0BE0(0);
    int var_a0 = ((temp_v0 & 0x80000) != 0) * 2;

    if ((temp_v0 & 0x40100000) == 0x100000) {
        var_a0 |= 4;
    }

    if (!(vs_battle_characterState->unk44->weaponDrawn)) {
        var_a0 |= 8;
    }

    ret = var_a0;

    if (actor->currentMP == 0) {
        ret |= 0x20;
    }

    if (actor->currentHP == 0) {
        ret |= 0x40;
    }

    if (actor->statuses & (vsBattleStatusRegen | vsBattleStatusStrDown)) {
        ret |= 0x80;
    }

    if (actor->statuses & vsBattleStatusWard) {
        ret |= 0x100;
    }

    if (arg0 == 2) {
        ret |= 0x200;
    }

    return ret;
}

int func_800CACD0(int menuState, int arg1)
{
    int i;
    u_short var_a1;
    int var_a0;
    void* miscIndex;

    if (vs_battle_menuState.currentMenu == 0x3F) {
        vs_battle_shortcutInvoked = 0;
        D_800F4FDB = 0;
        D_800F4EA0 = func_800CABE0(arg1);
        D_800F4E98.unk2 = 0;
        vs_battle_menuState.currentMenu = menuState;
        D_800F4E98.unk0 = 1;

        if (arg1 == 0) {
            vs_battle_playSfx10();
        }

        if (vs_battle_menuItems == 0) {
            _loadedSubMenu = -1;

            func_8007E180(6);

            miscIndex = vs_main_allocHeapR(0xB24);
            var_a1 = vs_main_settings.menuFlags;
            vs_battle_stringBuf = miscIndex + 0xA00;
            vs_battle_menuItems = miscIndex;
            vs_battle_rowTypeBuf = miscIndex + 0xA60;

            for (i = 0; i < 3; ++i) {
                for (var_a0 = D_800EBD68[i * 2]; var_a0 < D_800EBD68[i * 2 + 1];
                    ++var_a0) {
                    if (vs_main_actions[var_a0].unlocked) {
                        var_a1 |= 1 << i;
                        break;
                    }
                }
            }

            if (vs_main_stateFlags.unkB5 != 0) {
                var_a1 |= 1;
            }
            if (vs_main_stateFlags.introState >= 3) {
                var_a1 |= 0x120;
            }
            vs_main_settings.menuFlags = var_a1;
            func_800C930C(2);
        }
        return 1;
    }

    vs_battle_playInvalidSfx();
    return 0;
}

int vs_battle_isSpellClassUnlocked(int spellClass)
{
    int i;

    for (i = 0; i < _spellClassCounts[spellClass]; ++i) {
        if (vs_main_actions[_spellIds[spellClass][i]].unlocked) {
            return 1;
        }
    }
    return 0;
}

int _breakArtsUnlocked(void)
{
    int i;
    for (i = 0; i < 4; ++i) {
        if ((vs_main_actions
                    [0xB8 + ((vs_battle_characterState->equippedWeaponCategory - 1) * 4)
                        + i]
                        .unlocked)) {
            return 1;
        }
    }
    return 0;
}

int vs_battle_chainAbilitiesUnlocked(int defense)
{
    int i;
    vs_action_t* v0;

    for (i = 0; i < 14; ++i) {
        v0 = vs_main_actions;
        if (v0[defense == 0 ? vs_battle_chainAbilityOffsets[i]
                            : vs_battle_defenseAbilityOffsets[i]]
                .unlocked) {
            return 1;
        }
    }
    return 0;
}

int vs_battle_validateShortcutSelection(int shortcut)
{
    int noneUnlocked = 0;
    int menuState = 0;

    switch (shortcut) {
    case 1:
    case 2:
    case 3:
    case 4:
        noneUnlocked = vs_battle_isSpellClassUnlocked(shortcut - 1) == 0;
        menuState = 1;
        break;
    case 5:
        menuState = 4;
        break;
    case 6:
        noneUnlocked = _breakArtsUnlocked() == 0;
        menuState = 2;
        break;
    case 7:
    case 8:
        noneUnlocked = vs_battle_chainAbilitiesUnlocked(shortcut - 7) == 0;
        menuState = 3;
        break;
    }

    if (noneUnlocked) {
        vs_battle_playInvalidSfx();
        menuState = 0;
        D_800F4E98.unk2 = 0;
        D_800F4E98.unk0 = 2;
    } else {
        menuState = func_800CACD0(menuState, 0);
        vs_battle_shortcutInvoked = shortcut;
        D_800F4FDB = 1;
    }

    return menuState;
}

void func_800CB114(void)
{
    if (vs_battle_menuItems != 0) {
        func_8007E1C0(6);
        vs_main_freeHeapR(vs_battle_menuItems);
        vs_battle_menuItems = 0;
    }
}

void func_800CB158(vs_battle_lootListNode* arg0)
{
    D_800EB9C4 = arg0;
    D_800EB9C8 = NULL;
    func_800CACD0(0xC, 2);
}

void func_800CB18C(vs_battle_loot* arg0)
{
    D_800EB9C8 = arg0;
    D_800EB9C4 = NULL;
    func_800CACD0(0xC, 2);
}

void func_800CB1C0(int arg0)
{
    func_800CACD0(7, 2);
    D_800F4E6B = arg0 + 0x40;
    D_800F4EA0 |= 0x400;
}

void _setArtAndAbilityToUnlock(int art, int battleAbility)
{
    vs_battle_unlockedBreakArt = art;
    vs_battle_unlockedBattleAbility = battleAbility;
    func_800CACD0(3, 2);
}

void func_800CB23C(void)
{
    func_800CACD0(0xF, 2);
    D_800F4FDB = 1;
}

int _dismissAllTextBoxes(void)
{
    int i;
    int var_s1 = 1;

    for (i = 0; i < 8; ++i) {
        if (vs_battle_dismissTextBox(i) != 0) {
            var_s1 = 0;
        }
    }

    return var_s1;
}

void vs_battle_displaySceneMessage(int arg0, int arg1, int arg2)
{
    D_800EB9D8 = vs_main_allocHeapR(112);
    D_800F4E69 = arg2;
    if (D_800F4E69) {
        D_800F4E68 = 0x78;
    }

    vs_battle_initTextBox(7, 0x304, 0, 1, 0, 3, 0, 0);

    D_800EB9D8[0] = 0x00F8 | (0x04FB << 16);
    vs_battle_stringContext.strings[0] = vs_main_actions[arg1].name;

    if (arg0 == 12) {
        vs_battle_printf((char*)&D_800EB9D8[1],
            (char*)&vs_battle_menuStrings[VS_menuStrings_OFFSET_spellMastered]);
    } else if (arg0 == 11) {
        vs_battle_textBoxes[7].unk0.unk0_8 = 0;
        vs_battle_printf((char*)&D_800EB9D8[1],
            (char*)&vs_battle_menuStrings[vs_battle_menuStrings[vs_main_actions[arg1].type
                                                                + 22]]);
    } else {
        if (arg1 != 0) {
            vs_battle_stringContext.strings[0] = D_800EBF58[(arg1 - 0x1CA) * 2];
        }
        vs_battle_printf((char*)D_800EB9D8, (char*)&D_800EBDDC[D_800EBDDC[arg0]]);
    }

    vs_battle_setTextBox(7, (char*)D_800EB9D8);
}

int func_800CB45C(void)
{
    if (D_800EB9D8 != NULL) {

        if (!vs_battle_textBoxes[7].unk0.done) {
            return 1;
        }

        if (D_800F4E69 != 0) {

            if (D_800F4E68 < 4) {
                D_800F4E68 = 0;
            } else {
                D_800F4E68 -= vs_gametime_tickspeed;
            }

            if (D_800F4E68 != 0) {
                return -vs_battle_setTextBox(7, NULL);
            }

            return 0;
        }
        return -vs_battle_setTextBox(7, NULL);
    }
    return 0;
}

void func_800CB50C(void)
{
    if (D_800EB9D8 != NULL) {
        vs_battle_dismissTextBox(7);
        vs_main_freeHeapR(D_800EB9D8);
        D_800EB9D8 = NULL;
    }
}

void func_800CB550(void) { vs_battle_lowerScreenUiState = 1; }

void func_800CB560(void) { vs_battle_lowerScreenUiState = 0; }

char const D_80069998[] = "00:00:00";

void _renderTimer(int* value)
{
    char sp10[4];
    int i;

    *(int*)sp10 = *value;
    sp10[0] = vs_main_stateFlags.puzzleTimerHundredths;

    if (sp10[3] != 0) {
        sp10[2] = 59;
        sp10[1] = 59;
        sp10[0] = 99;
    }

    for (i = 0; i < 3; ++i) {
        int bcd = vs_battle_toBCD(sp10[i]);
        D_800EC258[6 - i * 3] = (bcd >> 4) + '0';
        D_800EC258[7 - i * 3] = (bcd & 0xF) + '0';
    }

    vs_battle_renderTextRaw(D_800EC258, vs_getXY(128, 200), vs_scratch.unk4 - 4);
}

void func_800CB654(int arg0) { D_800EB9AF = arg0; }

void func_800CB660(int arg0) { D_800EB9CC = arg0; }

D_800F18EC_t* func_800CB66C(void) { return &D_800F4E98; }

void _loadScreff2(int arg0)
{
    vs_main_CdFile file;
    D_800EB9B4_t* p = D_800EB9B4;
    void* const* new_var;

    if (arg0 != 0) {
        p->unk0 = 1;
        file.lba = VS_SCREFF2_PRG_LBA;
        file.size = VS_SCREFF2_PRG_SIZE;
        p->slot = vs_main_allocateCdQueueSlot(&file);
        new_var = &vs_overlay_slots[1];
        vs_main_cdEnqueue(p->slot, *new_var);
        return;
    }

    if (p->slot->state == 4) {
        vs_main_freeCdQueueSlot(p->slot);
        p->unk0 = 0;
        vs_main_wait();
    }
}

void func_800CB708(void)
{
    D_800EB9B4_t* temp_s0 = D_800EB9B4;
    if (temp_s0 != NULL) {
        if (temp_s0->unk0 != 0) {
            _loadScreff2(0);
            return;
        }
        if (*(int*)&temp_s0->unk4 != 0x1000) {
            func_800F9BD8();
        }
        if (temp_s0->unk2 != 0) {
            func_800F986C();
        }
        if (temp_s0->unk8 != 0) {
            func_800F9FB8();
        }
    }
}

void func_800CB79C(void)
{
    if (D_800EB9B4 == NULL) {
        D_800EB9B4 = (D_800EB9B4_t*)D_800F4ED8;
        func_8007E180(6);
        _loadScreff2(1);
    }
}

void func_800CB7DC(void)
{
    if (D_800EB9B4 != NULL) {
        func_8007E1C0(6);
        if (D_800EB9B4->unk1 == 1) {
            func_8007E0A8(0x1B, 5, 6);
        }
        func_800CA97C();
    }
}

void func_800CD158(int);
void func_800CD3E4(int);
extern int D_8005046C;

void func_800CB83C(void)
{
    int id, state, duration, scale, reverse;
    int x, cx, y, cy, width, height;
    int flags;
    vs_battle_textBox* box;

    for (id = 7; id != -1; --id) {
        box = &vs_battle_textBoxes[id];
        state = box->state;
        if (state == 0)
            continue;
        flags = *(int*)&box->unk0;
        D_800F4E80 = id;
        if (flags < 0)
            continue;
        duration = box->unk22;
        scale = vs_gametime_tickspeed >> 1;
        if (state < 0) {
            state -= scale;
            if (state < -duration) {
                box->state = 0;
                continue;
            }
            scale = ((duration + state + 1) << 16) / duration;
        } else {
            state += scale;
            if (duration < state)
                state = duration + 1;
            scale = state - 1;
            switch ((int)(((u_int)flags >> 4) & 3)) {
            case 0:
            case 1:
                scale = rsin((scale << 10) / duration) * 16;
                break;
            case 2:
                if (scale < duration - 1)
                    scale = (scale << 16) / (duration - 2);
                else
                    goto settle;
                break;
            case 3:
                if (duration >= 3) {
                    if (scale < duration - 1)
                        scale = (scale * 0xC000) / (duration - 2) + 0x6000;
                    else {
                    settle:
                        scale = scale == duration ? 0x10000 : 0x11000;
                    }
                }
                break;
            }
        }
        x = box->x * scale;
        reverse = 0x10000 - scale;
        cx = box->centerX * reverse;
        y = box->y * scale;
        cy = box->centerY * reverse;
        width = (box->charsPerLine * 12 + 10) * scale;
        height = (box->lineCount * 13 + 4) * scale;
        box->state = state;
        box->unk24 = (x + cx) >> 16;
        box->unk26 = (y + cy) >> 16;
        box->unk28 = width >> 16;
        box->unk2A = height >> 16;
        switch (box->unk0.unk0_0) {
        case 0:
            if (state < 0) {
                _renderTextImmediate(box, scale);
                break;
            }
            goto text;
        case 4:
            func_800CD158(id);
            if (state < 0)
                break;
            goto text;
        case 6:
        immediate:
            _renderTextImmediate(box, scale);
            break;
        case 2:
        case 7:
            func_800CD3E4(id);
        default:
        text:
            if (state == duration + 1)
                _printVariableWidthFont(box);
            else if (state < 0)
                _printFixedWidthFont(box, scale);
            break;
        case 3:
            break;
        }
    }
    AddPrims((u_long*)vs_scratch.unk4 - 6, D_800F51B8, D_800F51B8 + 33);
    D_800EB9CE = D_800EB9CE == 2 ? 0 : D_800EB9CE + 1;
    D_800F51B8 = &D_800F4CD0 + D_800EB9CE * 34;
    ClearOTag(D_800F51B8, 34);
    if (vs_battle_lowerScreenUiState == 1)
        _renderTimer(&D_8005046C);
    func_800CB708();
    vs_battle_keystreamBits(0);
}

void func_800CBBCC(gim_t* image, int clut, u_long* ot)
{
    int alpha = image->unk3;
    int background;
    int quadColor;
    u_short* tiles = (u_short*)((char*)image + 0x200);
    int scale = image->unkC & 0x3FFF;
    int columns = ((u_char*)&image->unk4)[0];
    int rows = ((u_char*)&image->unk4)[1];
    int color;
    short* columnX;
    short* rowY;
    int i, j;
    int top, bottom, left, right, tile, u, v, tpage;
    int packedBottom;
    u_long* prim;

    j = image->unk8 + 160;
    columnX = (short*)(0x1F800400 - ((columns + 1) << 1));
    rowY = columnX - (rows + 1);

    for (i = 0; i <= columns; i++) {
        columnX[i] = (((i * 2 - columns) * scale) >> 7) + j;
    }

    j = image->unkA + 120;
    for (i = 0; i <= rows; i++) {
        rowY[i] = (((i * 2 - rows) * scale * 15) >> 13) + j;
    }

    color = (u_short)image->unkE;
    if (color) {
        int r = ((color << 3) & 0xF8) * alpha;
        int g = ((color >> 2) & 0xF8) * alpha;
        int b = ((color >> 7) & 0xF8) * alpha;
        background =
            (r >> 7) | ((g >> 7) << 8) | ((b >> 7) << 16) | ((D_800F51C8 + 48) << 25);

        i = rowY[0];
        if (i > 0) {
            vs_battle_addTile(ot, background, 0, 320 | (i << 16));
        }
        i = rowY[rows];
        if (i < 240) {
            vs_battle_addTile(ot, background, i << 16, 320 | (0xF00000 - (i << 16)));
        }
        i = columnX[0];
        if (i > 0) {
            vs_battle_addTile(ot, background, 0, i | 0xF00000);
        }
        i = columnX[columns];
        if (i < 320) {
            vs_battle_addTile(ot, background, i & 0xFFFF, (320 - i) | 0xF00000);
        }
    }

    quadColor = alpha | (alpha << 8) | (alpha << 16) | ((D_800F51C8 + 22) << 25);
    alpha |= D_800F51C8 << 8;

    for (j = 0; j < rows; j++) {
        top = rowY[j];
        if (top >= 240) {
            continue;
        }
        bottom = rowY[j + 1];
        if (bottom < 0) {
            continue;
        }
        for (i = 0; i < columns; i++) {
            left = columnX[i];
            if (left >= 320) {
                continue;
            }
            right = columnX[i + 1];
            if (right < 0) {
                continue;
            }
            tile = tiles[i + j * columns];
            if (tile) {
                v = tile << 6;
                u = v & 0xC0;
                v = (v & 0x1F00) * 15;
                tpage = getTPage(image->unk0_2, 1,
                    ((image->unk2 - 18) << 6) + ((tile >> 2) & 0x1C0), 256);
                if (scale == ONE) {
                    prim = vs_battle_setSprite(alpha, left | (top << 16), 0xF0040, ot);
                } else {
                    int x0 = left & 0xFFFF;
                    int u1 = u + 64;
                    u1 -= u1 >> 8;
                    packedBottom = bottom << 16;
                    prim = vs_scratch.unk0;
                    prim[0] = (*ot & 0xFFFFFF) | 0xA000000;
                    prim[2] = quadColor;
                    prim[3] = x0 | (top << 16);
                    prim[5] = right | (top << 16);
                    prim[6] = u1 | v | (tpage << 16);
                    prim[7] = x0 | packedBottom;
                    prim[8] = u | (v + 0xF00);
                    prim[9] = right | packedBottom;
                    prim[10] = u1 | (v + 0xF00);
                    *ot = ((u_long)prim << 8) >> 8;
                    vs_scratch.unk0 = prim + 11;
                }
                prim[1] = tpage | 0xE1000000;
                prim[4] = u | v | clut;
            } else if (color && (color != 0x8000 || !D_800F51C8)) {
                vs_battle_addTile(ot, background, (left & 0xFFFF) | (top << 16),
                    (right - left) | ((bottom - top) << 16));
            }
        }
    }
}

void func_800CC128(gim_t* arg0, int arg1, u_long* arg2)
{
    int var_s1;
    int new_var;

    int temp_s0 = arg0->unk3;

    if (temp_s0 == 0x80) {
        func_800CBBCC(arg0, arg1, arg2);
        return;
    }

    D_800F51C8 = 1;

    func_800CBBCC(arg0, arg1, arg2);
    var_s1 = 0;

    if (vs_main_frameBuf == 0) {
        var_s1 = 0x140;
    }

    new_var = 0x120;
    vs_battle_setSprite(0x80 - temp_s0, 0, 0xF00100, arg2)[1] =
        ((u_int)var_s1 >> 6) | new_var | 0xE1000000;
    vs_battle_setSprite(0x80 - temp_s0, 0x100, 0xF00040, arg2)[1] =
        ((var_s1 + 0x100) >> 6) | new_var | 0xE1000000;
}

/* Draws a tiled image wiped in horizontally: per scanline the visible span is
   [left[y], right[y]) from the per-line widths at unk18 scaled by unkC (below ONE
   the image wipes in, above ONE it wipes out; unk3 picks the side). Each 64x15
   tile cell is drawn as one sprite per scanline, odd start columns first as a
   1-pixel sprite. The original reuses x/end for the scale/side and column for the
   scaled width. */
void func_800CC204(gim_t* image, int clut, u_long* ot)
{
    short left[240];
    short right[240];
    u_short* tiles = (u_short*)((char*)image + 0x200);
    int mode = image->unk0_2;
    u_short* widths = (u_short*)image->unk18;
    int page = image->unk2 - 18;
    int color = (u_short)image->unkE;
    int y, column, x, end, tile, tpage;
    u_long* prim;

    end = image->unk3;
    x = image->unkC & 0x3FFF;

    if (x == ONE) {
        image->unk3 = 0x80;
        func_800CBBCC(image, clut, ot);
        image->unk3 = end;
        return;
    }
    if (x < ONE) {
        for (y = 0; y < 240; y++) {
            column = (widths[y] * x) >> 12;
            if (end) {
                left[y] = 320 - column;
                right[y] = 320;
            } else {
                left[y] = 0;
                right[y] = column;
            }
        }
    } else {
        for (y = 0; y < 240; y++) {
            column = (widths[y] * (x - ONE)) >> 12;
            if (end) {
                left[y] = 0;
                right[y] = 320 - column;
            } else {
                left[y] = column;
                right[y] = 320;
            }
        }
    }
    for (y = 0; y < 240; y++) {
        for (column = 0; column < 5; column++) {
            x = left[y];
            if (x >= (column + 1) * 64) {
                continue;
            }
            end = right[y];
            if (end <= column * 64) {
                continue;
            }
            if (x < column * 64) {
                x = column * 64;
            }
            if (end > (column + 1) * 64) {
                end = (column + 1) * 64;
            }
            tile = tiles[(y / 15) * 5 + column];
            if (tile) {
                tpage = getTPage(mode, 1, (page + (tile >> 8)) << 6, 256);
            draw:
                do {
                    prim = vs_battle_setSprite(0x80, x | (y << 16),
                        (x & 1) ? 0x10001 : ((end - x) | 0x10000), ot);
                    prim[1] = tpage | 0xE1000000;
                    prim[4] = (((tile & 3) << 6) + (x & 0x3F))
                            | ((((tile >> 2) & 0x1F) * 15 + (y % 15)) << 8) | clut;
                } while (0);
                if (x & 1) {
                    ++x;
                    goto draw;
                }
            } else if (color) {
                vs_battle_addTile(ot,
                    ((color & 0x1F) << 3) | ((color & 0x3E0) << 6)
                        | ((color & 0x7C00) << 9) | 0x40000000,
                    (x & 0xFFFF) | (y << 16), (end - 1) | (y << 16));
            }
        }
    }
}

void func_800CC580(u_long* arg0, int arg1)
{
    vs_battle_addTile(
        arg0, arg1 | 0xE3040000, (arg1 + 0x3F) | 0xE407FC00, arg1 | 0xE5080000);
}

void func_800CC5C0(u_long* arg0, int arg1)
{
    vs_battle_addTile(
        arg0, arg1 | 0xE3000000, (arg1 + 0x13F) | 0xE403BC00, arg1 | 0xE5000000);
}

void func_800CC600(gim_t* image, int clut, u_long* ot)
{
    int alpha, inverse;
    u_short* tiles = (u_short*)((char*)image + 0x200);
    int mode = image->unk0_2;
    int columns, column, top, fb = 0, page;
    int height, x, y, row, tile, index;
    u_long* prim;
    if (vs_main_frameBuf == 0)
        fb = 320;
    alpha = image->unk3;
    page = (image->unk2 + image->unk0_9 - 16) << 6;
    if (alpha == 128) {
        func_800CBBCC(image, clut, ot);
        return;
    }
    inverse = 128 - alpha;
    alpha |= 256;
    inverse += 7;
    alpha += 7;
    columns = ((u_char*)&image->unk4)[0];
    height = ((u_char*)&image->unk4)[1] * 15;
    {
        int offset = (height >> 1) - 120;
        top = image->unkA - offset;
    }
    for (column = 0; column < columns; column++) {
        prim = vs_battle_setSprite(
            384, (column * 64) | (top << 16), 64 | (height << 16), ot);
        prim[1] = _get_mode(0, 0, getTPage(2, 1, page, 256));
        func_800CC5C0(ot, fb);
        for (y = height - 15; y >= 0; y -= 15) {
            for (x = 32; x >= 0; x -= 32) {
                prim = vs_battle_setSprite(384, x | (y << 16), 0xF0020, ot);
                prim[1] = _get_mode(0, 0, getTPage(2, 2, page, 256));
                prim[4] = x | (y << 8);
                func_800CC580(ot, page);
                prim = vs_battle_setSprite(
                    alpha, (x + (column * 64)) | ((top + y) << 16), 0xF0020, ot);
                prim[1] = _get_mode(0, 0, getTPage(2, 1, page, 256));
                prim[4] = x | (y << 8);
                func_800CC5C0(ot, fb);
            }
        }
        x = image->unkA + 120;
        for (y = 0; y < ((u_char*)&image->unk4)[1]; y++) {
            tile = tiles[y * columns + column];
            if (tile) {
                prim = vs_battle_setSprite(
                    128, ((((y * 30 - height) >> 1) + x - top) << 16), 0xF0040, ot);
                {
                    int atlas = tile >> 2;
                    int uv = ((tile << 6) & 192) | ((atlas & 31) * 15 << 8) | clut;
                    int tx = ((image->unk2 - 18) << 6) + (atlas & 448);
                    prim[4] = uv;
                    prim[1] = _get_mode(0, 0, getTPage(mode, 0, tx, 256));
                }
            }
        }
        func_800CC580(ot, page);
        for (y = 0; y < height; y += 15) {
            for (x = 0; x < 64; x += 32) {
                prim = vs_battle_setSprite(
                    inverse, (x + (column * 64)) | ((top + y) << 16), 0xF0020, ot);
                prim[1] = _get_mode(0, 0, getTPage(2, 0, (fb + column * 64), 0));
                prim[4] = x | ((top + y) << 8);
                func_800CC5C0(ot, fb);
                prim = vs_battle_setSprite(128, x | (y << 16), 0xF0020, ot);
                prim[1] = _get_mode(0, 0, getTPage(2, 0, (fb + column * 64), 0));
                prim[4] = x | ((top + y) << 8);
                func_800CC580(ot, page);
            }
        }
        vs_battle_addTile(ot, 0x60000000, 0, 64 | (height << 16));
        func_800CC580(ot, page);
    }
}

void func_800CCA90(int arg0)
{
    gim_t* gim = &D_800EB9BC[arg0];
    int clut = (gim->unk2 - 16) << 6;

    if ((gim->unk3 == 0) && (gim->unk0_3 != 2)) {
        return;
    }

    if (gim->unk0_2) {
        if (gim->unk0_12) {
            clut = getClut(clut, 511);
        } else {
            clut = getClut(768, 227);
        }
    } else {
        clut = getClut(clut + arg0 * 16, 511);
    }

    D_800F51C8 = 0;
    D_800EC25C[gim->unk0_3](gim, clut << 16,
        gim->unkC & 0x4000 ? vs_scratch.unk4 + 0x1FF8 - arg0 * 4
                           : vs_scratch.unk8 + 0x18 - arg0 * 8);
}

int vs_battle_decreaseMiscCount(int miscId)
{
    int i;

    if (miscId < 0x143) {
        vs_battle_miscItemInvoked = 0;
    }

    for (i = 0; i < 64; ++i) {
        int miscIndex = (vs_battle_miscItemInvoked + i) & 0x3F;
        if (vs_main_inventory.misc[miscIndex].id == miscId) {
            int count = vs_main_inventory.misc[miscIndex].count - 1;
            vs_main_inventory.misc[miscIndex].count = count;
            if (count == 0) {
                vs_main_inventory.misc[miscIndex].id = 0;
            }
            return 1;
        }
    }
    return 0;
}

void vs_battle_rMemzero(void* arg0, int arg1)
{
    int* var_v0;

    var_v0 = arg0 + arg1;
    do {
        *(int*)--var_v0 = 0;
    } while (arg0 != var_v0);
}

void vs_battle_rMemcpy(void* dest, void const* src, int size)
{
    do {
        --size;
        ((char*)dest)[size] = ((char const*)src)[size];
    } while (size != 0);
}

int vs_battle_toBCD(int value) { return (value % 10) | ((value / 10) * 16); }

u_int vs_battle_keystreamBits(int value)
{
    u_int temp_a1 = _keystreamState;
    _keystreamState = temp_a1 * 0x19660D;
    return temp_a1 >> (32 - value);
}

void vs_battle_addTile(u_long* before, int rgb0, int xy, int wh)
{
    u_long* prim = vs_scratch.unk0;
    prim[0] = (int)((*before & 0xFFFFFF) | 0x03000000);
    prim[1] = rgb0;
    prim[2] = xy;
    prim[3] = wh;
    *before = ((u_long)prim << 8) >> 8;
    vs_scratch.unk0 = prim + 4;
}

void vs_battle_insertTpage(int tpage, u_long* before)
{
    u_long* prim = vs_scratch.unk0;
    prim[0] = vs_getTag(sizeof(int), *before);
    prim[1] = tpage;
    *before = ((u_long)prim << 8) >> 8;
    vs_scratch.unk0 = prim + 2;
}

int vs_battle_drawCursor(int animStep, int position)
{
    vs_battle_setSpriteDefaultTexPage(vs_battle_cursorBrightnessAnimation[animStep],
        (((position * 0x10) + 0xA) << 0x10) | 0xB4, 0x100010, vs_scratch.unk8)[4] =
        0x37F83020;
    return (animStep + 1) & 0xF;
}

void vs_battle_renderImage(int xy, void* buffer, int wh)
{
    extern int D_800EC280;
    extern RECT D_800F51D0[];
    RECT* rect;

    rect = D_800EC280 + D_800F51D0;
    D_800EC280 = (D_800EC280 + 1) & 7;
    *(int*)&rect->x = xy;
    *(int*)&rect->w = wh;
    LoadImage(rect, buffer);
}

vs_battle_textBox* vs_battle_getTextBox(int id) { return &vs_battle_textBoxes[id]; }

func_800CCE10_t func_800CCE10(int arg0, int arg1, int arg2, int arg3)
{
    func_800CCE10_t ret;
    func_800CCE10_t* p =
        &D_800EC284[arg0][((arg1 >> 2) & 3) == 1 || ((arg1 >> 2) & 3) == 2];
    int offsetX = p->unk0_0;
    int offsetY = p->unk0_12;
    int unk24 = p->unk0_24;

    if ((arg1 >> 2) & 1) {
        offsetX = -offsetX;
        unk24 ^= 2;
    }

    ret.unk0_0 = offsetX - ((arg2 * 12 + 10) >> 1);
    ret.unk0_12 = offsetY - ((arg3 * 13 + 4) >> 1);
    ret.unk0_24 = unk24;
    ret.unk0_26 = p->unk0_26;
    return ret;
}

void vs_battle_initTextBox(
    int id, int flags, int x, int y, int charsPerLine, int h, int centerX, int centerY)
{
    vs_battle_textBox* box = &vs_battle_textBoxes[id];

    *(int*)&box->unk0 = flags & 0xFFFF;
    box->unk0.unk0_24 = 32;
    box->x = x;
    box->y = y;
    box->unk4 = 0;
    box->unk6 = 0;
    box->speed = 0;
    box->xIndent = x + 5;
    box->yIndent = y + 3;
    box->unk2E = 0;
    box->brightness = 0x80;
    box->charsPerLine = charsPerLine;
    box->lineCount = h;
    box->centerX = centerX;
    box->centerY = centerY;
    // looks up { 10, 20, 10, 8 };
    box->unk22 = ((0x45A5 >> ((box->unk0.unk0_4 * 4))) & 0xF) * 2;

    if (box->state <= 0) {
        box->state = 1;
    }

    switch (box->unk0.unk0_0) {
    case 1:
        box->unk0.unk0_0 = 7;
        box->unk0.unk0_8 = 0;
        return;
    case 4:
        box->charsPerLine = 0x18;
        box->centerX = 0xA0;
        box->centerY = 0xF0;
        box->xIndent = 0x10;
        box->yIndent = 0xF2 - (h * 0xD);
        return;
    case 5:
        box->unk0.unk0_0 = 7;
        box->unk0.unk0_8 = 2;
        return;
    }
}

int vs_battle_dismissTextBox(int id)
{
    vs_battle_textBox* box = &vs_battle_textBoxes[id];

    if (!(box->unk0.unk0_24 & 0x20)) {
        func_800AAD4C(box->unk0.unk0_24, 0, 0, 0);
    }

    if (box->state != 0) {
        if (box->state > 0) {
            box->unk22 = 8;
            box->state = -1;
            box->unk0.unk0_4 = 0;
        }
        return -1;
    }

    return 0;
}

void func_800CD0FC(int arg0, u_int arg1)
{
    if (arg1 < 3) {
        vs_battle_setSpriteDefault(D_800EC2CC[arg1], (arg0 << 0x10) | 0xA)[4] =
            D_800EC2D8[arg1];
    }
}

void func_800CD158(int id)
{
    vs_battle_textBox* box = &vs_battle_textBoxes[id];
    int y = box->y;
    u_long* ot = D_800F51B8 + id * 4 + 1;
    int offset;
    int edge;
    u_int i;
    u_int count;
    u_int brightness;
    u_int page;
    u_long* prim;

    edge = box->unk2A;
    offset = vs_main_frameBuf ? 0 : 320;
    if (y == 0) {
        y = edge;
    } else {
        y = 240 - edge;
    }
    count = box->lineCount * 13 + 4 - edge;
    if (count > 16) {
        count = 16;
    } else if (count < 4) {
        count = 4;
    }
    for (i = 0; i < count; ++i) {
        brightness = ((count - i) * 128) / (count + 1);
        prim = vs_battle_setSprite(brightness, (y << 16) | 256, 0x10040, ot);
        page = ((u_int)(offset + 256) >> 6) | 0x100;
        prim[1] = page | 0xE1000000;
        prim[4] = y << 8;
        prim = vs_battle_setSprite(brightness, y << 16, 0x10100, ot);
        brightness = ((u_int)offset >> 6) | 0x100;
        prim[1] = brightness | 0xE1000000;
        prim[4] = y << 8;
        if (y < 128) {
            if (--y < 0) {
                break;
            }
        } else if (++y >= 240) {
            break;
        }
    }
    if (y < 128) {
        if (y >= 0) {
            vs_battle_addTile(ot, 0x60000000, 0, ((y + 1) << 16) | 320);
        }
    } else {
        if (y < 240) {
            vs_battle_addTile(ot, 0x60000000, y << 16, (0xF00000 - (y << 16)) | 320);
        }
        if (box->state == box->unk22 + 1) {
            func_800CD0FC(y - 7, box->unk0.unk0_8 - 1);
        }
    }
}

int func_800CD3A0(int arg0, int arg1)
{
    int var_v1 = arg0;

    if (arg1 & 1) {
        var_v1 = (var_v1 & 0xFF) | ((0xFF - (var_v1 >> 8)) << 8);
    }

    if (arg1 & 2) {
        var_v1 = (~var_v1 & 0xFF) | (var_v1 & 0xFF00);
    }

    return var_v1;
}

extern u_char* D_800EB588[];

#define POINT_X(p) (((short*)&points[p])[0])
#define POINT_Y(p) (((short*)&points[p])[1])

/* Draws the frame of text box `index` from shape D_800EB588[unk0_8]: header word
   (b0 vertex count, b1 part count, b2 outline vertex count) followed by one word per
   part (b0/b1 outline join indices, b2 outline length, b3 polygon count), the packed
   x/y vertices (flipped by func_800CD3A0) and 4-byte polygons (0xFF = triangle).
   The original reuses its locals heavily: w/h/flip become polygon vertex 2/3 and the
   colour, i/n/k/v change roles between the passes. */
void func_800CD3E4(int index)
{
    u_long* ot;
    u_int part;
    vs_battle_textBox* box;
    u_short* verts;
    u_char* shape;
    int header;
    int* points;
    short* out;
    u_long* prim;
    int x;
    int y;
    int w;
    int h;
    int flip;
    int i;
    int n;
    u_char count;
    int k;
    int v;
    int quad;

    points = (int*)0x1F800088;
    box = &vs_battle_textBoxes[index];
    x = box->unk24;
    y = box->unk26;
    w = box->unk28;
    h = box->unk2A;
    verts = (u_short*)D_800EB588[box->unk0.unk0_8];
    ot = D_800F51B8 + index * 4;
    if (verts == NULL) {
        return;
    }
    out = (short*)0x1F800088;
    flip = box->unk0.unk0_6;
    shape = (u_char*)verts;
    part = ((int*)shape)[box->unk0.unk0_12];
    verts = (u_short*)(shape + (shape[1] + 1) * 4);
    count = shape[2];
    header = *(int*)shape;

    for (i = 0; i < count; ++i) {
        v = func_800CD3A0(verts[i], flip);
        *out++ = x + (((v & 0xFF) * w) >> 8);
        *out++ = y + (((v >> 8) * h) >> 8);
    }
    if ((u_int)(box->unk0.unk0_12 - 1) < ((header >> 8) & 0xFF)) {
        v = func_800CD3A0(verts[part & 0xFF], flip);
        for (; i < (header & 0xFF); ++i) {
            n = func_800CD3A0(verts[i], flip);
            k = n >> 8;
            n &= 0xFF;
            if (n >= 0x80) {
                n -= 0x100;
            }
            if (k >= 0x80) {
                k -= 0x100;
            }
            *out++ = x + (((n + (v & 0xFF)) * w) >> 8);
            *out++ = y + (((k + (v >> 8)) * h) >> 8);
        }
    } else {
        part = 0xFFFF;
    }
    verts += header & 0xFF;

    i = (header >> 16) & 0xFF;
    for (n = 0; n < i;) {
        if (n == (part & 0xFF)) {
            v = 0;
            for (k = 0; k < box->unk0.unk0_12; ++k) {
                v += shape[k * 4 + 2];
            }
            for (k = 0; k < shape[box->unk0.unk0_12 * 4 + 2]; ++k) {
                vs_battle_addTile(ot + 2, 0x40303030, points[n], points[v + k]);
                n = v + k;
            }
            v = n;
            n = (part >> 8) & 0xFF;
            vs_battle_addTile(ot + 2, 0x40303030, points[n], points[v]);
        }
        v = (n + 1) % i;
        vs_battle_addTile(ot + 2, 0x40303030, points[n], points[v]);
        n = n + 1;
    }
    vs_battle_insertTpage(0xE2000000, ot + 2);

    prim = vs_scratch.unk0;
    flip = box->brightness;
    flip = flip | (flip << 8) | (flip << 16);
    for (n = 0; n <= shape[1]; ++n) {
        for (k = 0; k < shape[n * 4 + 3]; ++k) {
            if ((n != 0) && (n != box->unk0.unk0_12)) {
                verts = (u_short*)((u_char*)verts + 4);
                continue;
            }
            v = ((u_char*)verts)[0];
            i = ((u_char*)verts)[1];
            w = ((u_char*)verts)[2];
            h = ((u_char*)verts)[3];
            verts = (u_short*)((u_char*)verts + 4);

            x = POINT_X(v);
            if (POINT_X(i) < x) {
                x = POINT_X(i);
            }
            if (POINT_X(w) < x) {
                x = POINT_X(w);
            }
            y = POINT_Y(v);
            if (POINT_Y(i) < y) {
                y = POINT_Y(i);
            }
            if (POINT_Y(w) < y) {
                y = POINT_Y(w);
            }
            quad = (h != 0xFF) * 2;
            if (quad) {
                if (POINT_X(h) < x) {
                    x = POINT_X(h);
                }
                if (POINT_Y(h) < y) {
                    y = POINT_Y(h);
                }
            } else {
                h = 0;
            }

            prim[0] = (ot[2] & 0xFFFFFF) | ((quad + 7) << 24);
            prim[1] = flip | ((quad + 9) << 26);
            x = (x >> 6) << 6;
            y = (y >> 6) << 6;
            prim[2] = points[v];
            prim[3] = ((POINT_X(v) - x) & 0xFF) | (((POINT_Y(v) - y) << 8) & 0xFF00)
                    | 0x373E0000;
            prim[4] = points[i];
            prim[5] =
                ((POINT_X(i) - x) & 0xFF) | (((POINT_Y(i) - y) << 8) & 0xFF00) | 0x170000;
            prim[6] = points[w];
            prim[7] = ((POINT_X(w) - x) & 0xFF) | (((POINT_Y(w) - y) << 8) & 0xFF00);
            prim[8] = points[h];
            prim[9] = ((POINT_X(h) - x) & 0xFF) | (((POINT_Y(h) - y) << 8) & 0xFF00);
            ot[2] = ((u_long)prim << 8) >> 8;
            prim += quad + 8;

            prim[0] = (ot[1] & 0xFFFFFF) | 0x0C000000;
            prim[1] = (quad + 8) << 26;
            prim[2] = ((POINT_X(v) + 2) & 0xFFFF) | ((POINT_Y(v) + 2) << 16);
            prim[3] = ((POINT_X(i) + 2) & 0xFFFF) | ((POINT_Y(i) + 2) << 16);
            prim[4] = ((POINT_X(w) + 2) & 0xFFFF) | ((POINT_Y(w) + 2) << 16);
            if (quad) {
                prim[5] = ((POINT_X(h) + 2) & 0xFFFF) | ((POINT_Y(h) + 2) << 16);
            } else {
                prim[5] = 0;
            }
            prim[6] = 0x48000000;
            prim[7] = prim[2];
            prim[8] = prim[3];
            prim[9] = prim[quad + 3];
            prim[10] = prim[4];
            prim[11] = prim[2];
            prim[12] = 0x55555555;
            ot[1] = ((u_long)prim << 8) >> 8;
            prim += 13;
        }
    }
    vs_scratch.unk0 = prim;
    vs_battle_addTile(ot + 2, 0xE1000017, 0xE2000318, 0);
}

#undef POINT_X
#undef POINT_Y

typedef struct {
    union {
        int value;
        u_char bytes[4];
        struct {
            u_int actor : 16, color : 4, texture : 4, life : 8;
        } bits;
    } config;
    int index, age;
    SVECTOR first[8], second[8], previousFirst, currentFirst, previousSecond,
        currentSecond;
    int projectionDepth, projectionFlags;
} effectTrailState;
typedef struct {
    u_long tag;
    POLY_GT4 poly;
    u_long endPage;
} TrailPacket;
extern CVECTOR D_800EC308[], D_800EC2E8[];
void func_800CF988(func_800CF988_t*, int, int, int);
void func_800CDCBC(effectTrailState* t, int head, int tail)
{
    long xy[4];
    int depth;
    TrailPacket* p;
    u_short uv;
    u_char row, column;
    vs_scratch_t* scratch;
    depth = RotAverage4(&t->previousFirst, &t->currentFirst, &t->previousSecond,
        &t->currentSecond, &xy[0], &xy[1], &xy[2], &xy[3], (long*)&t->projectionDepth,
        (long*)&t->projectionFlags);
    if ((u_int)(depth - 17) >= 2031)
        return;
    p = vs_scratch.unk0;
    vs_scratch.unk0 = (char*)p + sizeof(TrailPacket);
    setlen(p, 14);
    p->poly.code = 0x3C;
    p->poly.tag = 0xE1000000;
    p->endPage = 0xE1000200;
    *(long*)&p->poly.x0 = xy[0];
    *(long*)&p->poly.x1 = xy[1];
    *(long*)&p->poly.x2 = xy[2];
    *(long*)&p->poly.x3 = xy[3];
    scratch = &vs_scratch;
    if ((t->config.value & 0xF00000) == 0x600000) {
        p->poly.r0 = p->poly.r1 = D_800EC308[t->config.bits.color].r * head - 128;
        p->poly.g0 = p->poly.g1 = D_800EC308[t->config.bits.color].g * head - 128;
        p->poly.b0 = p->poly.b1 = D_800EC308[t->config.bits.color].b * head - 128;
        p->poly.r2 = p->poly.r3 = D_800EC308[t->config.bits.color].r * tail - 128;
        p->poly.g2 = p->poly.g3 = D_800EC308[t->config.bits.color].g * tail - 128;
        p->poly.b2 = p->poly.b3 = D_800EC308[t->config.bits.color].b * tail - 128;
        func_800CF988((func_800CF988_t*)p, head, head, 0);
        addPrim((u_long*)scratch->unk4 + depth, p);
    } else {
        p->poly.code = 0x3E;
        uv = 0x58;
        if ((t->config.value & 0xF0000) != 0x70000)
            uv = 0x38;
        p->poly.tpage = uv;
        p->poly.clut = 0x3C30;
        column = t->config.bits.texture % 3U;
        row = t->config.bits.texture / 3U;
        uv = column * 2560 + row * 40;
        *(u_short*)&p->poly.u0 = uv + 0x4868;
        *(u_short*)&p->poly.u2 = uv + 0x4887;
        *(u_short*)&p->poly.u1 = uv + 0x4F68;
        *(u_short*)&p->poly.u3 = uv + 0x4F87;
        p->poly.r0 = p->poly.r1 = (D_800EC2E8[t->config.bits.color].r * head) / 8;
        p->poly.g0 = p->poly.g1 = (D_800EC2E8[t->config.bits.color].g * head) / 8;
        p->poly.b0 = p->poly.b1 = (D_800EC2E8[t->config.bits.color].b * head) / 8;
        p->poly.r2 = p->poly.r3 = (D_800EC2E8[t->config.bits.color].r * tail) / 8;
        p->poly.g2 = p->poly.g3 = (D_800EC2E8[t->config.bits.color].g * tail) / 8;
        p->poly.b2 = p->poly.b3 = (D_800EC2E8[t->config.bits.color].b * tail) / 8;
        addPrim((u_long*)scratch->unk4 + depth, p);
    }
}

int func_800CE174(func_800D4910_t* node, u_int mode, int config)
{
    effectTrailState* t = node->unk8;
    int result = 1;
    int segments, phase, span, weight;
    switch (mode) {
    case 1:
        t = vs_main_allocHeapR(sizeof(effectTrailState));
        node->unk8 = t;
        t->index = 0;
        t->age = 0;
        t->config.value = config;
        break;
    case 2:
        t->index = (t->index + 1) & 7;
        func_800A1AF8(t->config.bytes[0], t->config.bytes[1], &t->first[t->index], 0);
        func_800A1AF8(t->config.bytes[0], t->config.bytes[1], &t->second[t->index], 1);
        if (++t->age >= 4) {
            segments = 5;
            if (t->age < 9)
                segments = t->age - 3;
            SetRotMatrix(&vs_scratch.viewMatrix);
            SetTransMatrix(&vs_scratch.viewMatrix);
            vs_battle_splineInterpolate(&t->first[t->index],
                &t->first[(t->index - 1) & 7], &t->first[(t->index - 2) & 7],
                &t->first[(t->index - 3) & 7], -4096, &t->previousFirst);
            vs_battle_splineInterpolate(&t->second[t->index],
                &t->second[(t->index - 1) & 7], &t->second[(t->index - 2) & 7],
                &t->second[(t->index - 3) & 7], -4096, &t->previousSecond);
            weight = (segments + 1) * 2;
            for (span = -2048; span < 0; span += 2048) {
                vs_battle_splineInterpolate(&t->first[t->index],
                    &t->first[(t->index - 1) & 7], &t->first[(t->index - 2) & 7],
                    &t->first[(t->index - 3) & 7], span, &t->currentFirst);
                vs_battle_splineInterpolate(&t->second[t->index],
                    &t->second[(t->index - 1) & 7], &t->second[(t->index - 2) & 7],
                    &t->second[(t->index - 3) & 7], span, &t->currentSecond);
                func_800CDCBC(t, weight / 2, (weight - 1) / 2);
                --weight;
                t->previousFirst = t->currentFirst;
                t->previousSecond = t->currentSecond;
            }
            for (span = 0; span < segments; ++span) {
                for (phase = 0; phase < 4096; phase += 2048) {
                    vs_battle_splineInterpolate(&t->first[((t->index - span) & 7)],
                        &t->first[((t->index - span) - 1) & 7],
                        &t->first[((t->index - span) - 2) & 7],
                        &t->first[((t->index - span) - 3) & 7], phase, &t->currentFirst);
                    vs_battle_splineInterpolate(&t->second[((t->index - span) & 7)],
                        &t->second[((t->index - span) - 1) & 7],
                        &t->second[((t->index - span) - 2) & 7],
                        &t->second[((t->index - span) - 3) & 7], phase,
                        &t->currentSecond);
                    func_800CDCBC(t, weight / 2, (weight - 1) / 2);
                    --weight;
                    t->previousFirst = t->currentFirst;
                    t->previousSecond = t->currentSecond;
                }
            }
        }
        if (t->config.bytes[3] != 255)
            --t->config.bytes[3];
        if (t->config.bytes[3] == 0)
            result = 0;
        break;
    case 3:
        t->config.bytes[3] = 8;
        break;
    case 4:
        vs_main_freeHeapR(t);
        node->unk8 = 0;
        result = 0;
        break;
    }
    return result;
}

int func_800CE644(int arg0 __attribute__((unused))) { }

void func_800CE64C(void)
{
    func_800CE67C();
    func_800D7814();
    func_800D268C();
}

void func_800CE67C(void)
{
    int i;
    func_800CF478(0);
    D_800F5228 = 0;
    D_800F5224 = 0;
    D_800F54A8 = 0;
    D_800F5318 = 0;
    D_800F54B0 = NULL;
    D_800F53BC = 0;
    D_800F53B4 = 0;
    D_800F53B8 = 0;
    D_800F5330[0] = 0;
    D_800F522C = 0;
    D_800F5218 = NULL;
    for (i = 0; i < 4; ++i) {
        D_800F5320[i] = 0;
    }
}

void func_800CE714(D_800F53B8_t2* arg0, D_800F53B8_t* arg1)
{
    int i;

    arg1->previous = arg0->unk1C;
    arg1->unk8 = 0;
    arg1->unk9 = arg0->unk10;
    arg1->unkA = arg0->unk18;
    arg1->unkC = arg0->unk14;
    *(int*)&arg1->unk10 = 0;
    arg1->unk14_0 = arg0->unk20;
    arg1->unk18 = 0;
    arg1->unk14_11 = 0;
    arg1->unk14_16 = 0;

    for (i = 0; i < 16; ++i) {
        ((short*)&arg1->unk1C[i].unk4)[1] = 0;
        arg1->unk1C[i].unk4 = 0;
        arg1->unk1C[i].unk0 = 0;
        arg1->unk1C[i].unkC = 0;
        arg1->unk1C[i].unk8 = 0;
        arg1->unk1C[i].unk18 = 0;
        arg1->unk1C[i].unk14 = 0;
        arg1->unk1C[i].unk10 = 0;
        arg1->unk1C[i].unk30 = 0;
        arg1->unk1C[i].unk2C = 0;
        arg1->unk1C[i].unk28 = 0;
        *(int*)&arg1->unk1C[i].unk34 = 0;
    }

    arg1->unkD1C.unk0 = arg0->unk0->unk0;
    arg1->unkD1C.unkC = arg0->unk4->unk0;
    arg1->unkD1C.unk18 = arg0->unk8->unk0;
    arg1->unkD1C.unk24 = arg0->unkC->unk0;

    arg1->unkD1C.unk30 = 0;
    arg1->unkD1C.unk34 = 0;
    arg1->unkD1C.unk3C = 0;
}

D_800F53B8_t* func_800CE83C(D_800F53B8_t2* arg0)
{
    D_800F53B8_t* currentNode;
    D_800F53B8_t* newNode = vs_main_allocHeapR(sizeof *newNode);

    func_800CE714(arg0, newNode);

    currentNode = D_800F53B8;

    if ((currentNode == NULL) || (arg0->unk10 < currentNode->unk9)) {
        newNode->next = currentNode;
        D_800F53B8 = newNode;
    } else {
        while (1) {
            if ((currentNode->next == NULL) || (arg0->unk10 < currentNode->next->unk9)) {
                newNode->next = currentNode->next;
                currentNode->next = newNode;
                break;
            }
            currentNode = currentNode->next;
        }
    }
    return newNode;
}

void func_800CE8F4(D_800F53B8_t* arg0)
{
    func_800D4910_t* var_s1;
    D_800F53B8_t* var_v1 = D_800F53B8;

    if (var_v1 == arg0) {
        D_800F53B8 = arg0->next;
    } else {
        while (var_v1->next != NULL) {
            if (var_v1->next == arg0) {
                var_v1->next = arg0->next;
                break;
            }
            var_v1 = var_v1->next;
        }
    }

    func_800D2904(arg0);

    var_s1 = arg0->unkD1C.unk34;

    while (var_s1 != NULL) {
        func_800D4910_t* temp_s0 = var_s1->next;
        var_s1->renderer(var_s1, 4, 0);
        func_800CF70C(arg0, var_s1);
        var_s1 = temp_s0;
    }

    vs_main_freeHeapR(arg0);
}

int func_800CE9B0(void)
{
    int _[10] __attribute__((unused));
    vs_main_CdFile sp38;
    D_800F53B8_t* temp_s1;
    D_800F53B8_t* var_s0;
    int i;
    int var_s2;

    var_s0 = D_800F53B8;
    var_s2 = 1;

    switch (D_800F531C) {
    case 0:
        var_s2 = 0;
        break;

    case 6:
        if (vs_battle_loadEffPurge() == 0) {
            vs_main_wait();
            vs_effpurge_exec();
            if ((D_800F5230.effectId != 0) && (vs_battle_pFileLoadContext.lba == 0)) {
                func_800CF478(4);
                D_800F5224 = 0;
                D_800F5228 = 0;
            } else {
                func_800CF478(2);
            }
            if (D_800F5684 != 0) {
                func_8007E1C0(2);
                D_800F5684 = 0;
            }
        }
        break;

    case 2:
        if (func_800D7CFC() == 0) {
            func_800CF478(8);
        }
        break;

    case 8:
        if (func_800D7EF4() == 0) {
            func_800CF478(3);
            vs_main_wait();
        }
        break;

    case 3:
        if (func_800D7BF8() == 0) {
            func_800D8060(vs_battle_pfileBuf);
            func_800CF478(5);

            D_800F5224 = D_800F569C->block9Data->unk14;
            D_800F5228 = 0;

            for (i = 0; i < D_800F5224; ++i) {
                D_800F521C |= 1 << i;
            }

            D_800F54A8 = 1;
            sp38.lba = vs_battle_getMainMenuLba();
            sp38.size = 0;
            D_800F5218 = vs_main_allocateCdQueueSlot(&sp38);
            vs_main_cdEnqueue(D_800F5218, NULL);
        }
        break;

    case 4:
        while (var_s0 != NULL) {

            temp_s1 = var_s0->next;
            D_800F53BC = var_s0;

            if (D_800F569C->curveBlock != NULL) {
                func_800D1104(var_s0->unk14_16);
            }

            func_800D78F0();

            if (func_800D51D8(var_s0) == 0) {
                func_800CE8F4(var_s0);
            } else {
                ++var_s0->unk14_16;
            }

            var_s0 = temp_s1;
        }

        if (D_800F53B8 != NULL) {
            break;
        }

        if (D_800F5224 <= D_800F5228) {

            if (D_800F569C->block12Data != 0) {
                func_80046194();
                D_800F569C->block12Data = NULL;
            }

            if (D_800F569C->block13Data != NULL) {
                func_80046634();
                D_800F569C->block13Data = NULL;
                D_800F569C->unkCC = 0;
            }

            func_800434A4(0, 1);
            func_800D7C5C();
            func_800D278C();
            func_800CF514(D_800F5318);

            D_800F54A8 = 0;
            D_800F5318 = 0;

            if (D_800F5684 != 0) {
                func_8007E1C0(2);
                D_800F5684 = 0;
            }

            func_800D1930();
            func_800CF478(9);
        } else {
            func_800CF478(5);
        }

        var_s2 = 1;
        break;

    case 9:
        if (D_800F5218 != NULL) {
            if (D_800F5218->state != 4) {
                // Ugly match hack
                if (D_800F569C || var_s2) {
                    var_s2 = 1;
                    break;
                } else {
                    var_s2 = 1;
                    break;
                }
            }
            vs_main_freeCdQueueSlot(D_800F5218);
            D_800F5218 = NULL;
        }
        func_800CF478(0);
        var_s2 = 0;
        break;
    }

    return var_s2;
}

int func_800CED60(void)
{
    D_800F53B8_t* temp_s4;
    D_800F53B8_t* var_s1;
    func_800D4910_t* var_s0;
    int var_s3;

    var_s1 = D_800F54B0;
    var_s3 = 0;

    while (var_s1 != NULL) {

        D_800F53BC = var_s1;
        temp_s4 = var_s1->next;

        switch (var_s1->unkD1C.unk3A) {
        case 2:
            break;
        case 3:
            func_800D2698(0xFF);
            func_800CF484(4, var_s1);
            break;
        case 4:
            if (D_800F569C->curveBlock != NULL) {
                func_800D1104(var_s1->unk14_16);
            }

            func_800D78F0();

            var_s0 = var_s1->unkD1C.unk34;

            while (var_s0 != NULL) {
                func_800D4910_t* temp_s2 = var_s0->next;
                if (var_s0->renderer(var_s0, 2, 0) == 0) {
                    func_800CF70C(var_s1, var_s0);
                }
                var_s0 = temp_s2;
            }
            if (func_800D51D8(var_s1) == 0) {
                func_800CF614(var_s1);
                func_800D278C();
            } else {
                ++var_s1->unk14_16;
            }
            break;
        }
        var_s3 |= var_s1->unk14_8;
        var_s1 = temp_s4;
    }
    return var_s3;
}

int func_800CEEBC(void)
{
    int var_a1 = 0;
    if (((D_800F531C - 4) < 2) && (D_800F5224 > D_800F5228)) {
        var_a1 = D_800F521C > 0;
    }
    return var_a1;
}

int func_800CEF0C(void)
{
    int var_v1 = 0;
    if ((D_800F531C - 4) < 2) {
        var_v1 = D_800F5224;
    }
    return var_v1;
}

void func_800CEF38(int arg0)
{
    D_800F5228 -= 1;
    D_800F521C |= 1 << arg0;
}

int func_800CEF64(void) { return D_800F54A8 != 0; }

int func_800CEF74(int arg0)
{
    D_800F53B8_t2 sp10;
    int v;

    func_800D7890(1);
    v = func_800CEEBC();
    if (v != 0) {
        if (D_800F521C & (1 << arg0)) {
            char* a1 = D_800F569C->block8Data;
            sp10.unk18 = arg0 * 3;
            sp10.unk0 = &D_800F5234;
            sp10.unk4 = &D_800F5234;
            sp10.unk10 = 0;
            sp10.unk8 = (D_800F53B8_t3*)&D_800F5234.unkC;
            sp10.unkC = (D_800F53B8_t3*)&D_800F5234.unkC;
            sp10.unk1C = 0;
            sp10.unk20 = D_800F5318;
            sp10.unk14 = a1;
            func_800CE83C(&sp10);
            func_800CF478(4);
            ++D_800F5228;
            D_800F521C &= ~(1 << arg0);
        }
    }
    return v;
}

int func_800CF060(void)
{
    int temp_s0;
    int temp_s1;

    D_800EC2E4 = 1 - D_800EC2E4;
    func_800D7890(1);
    temp_s1 = func_800CE9B0();
    func_800D7890(0);
    temp_s0 = func_800CED60();
    func_800D7890(1);
    if (D_800F531C == 4) {
        func_800D2560();
    }
    return temp_s1 | temp_s0;
}

int func_800CF0E8(func_800CF0E8_t* arg0, int arg1, int arg2)
{
    D_800F5230 = *arg0;

    if ((arg1 != 0) && (arg0->unk4 == 4)) {
        D_800F522C = arg1;
        D_800F54A9 = arg2;
    }

    D_800F5318 = func_800CF49C();
    func_800D7890(1);
    func_800D1B18(&D_800F55A8);
    func_800D1B18(&D_800F54D8);
    func_800CF478(6);

    return D_800F5318;
}

void func_800CF1A8(void)
{
    D_800F53B8_t* var_s0 = D_800F53B8;

    func_800434A4(0U, 1);

    while (var_s0 != NULL) {
        D_800F53B8_t* temp_s1 = var_s0->next;
        if (var_s0->unkD1C.unk30 != NULL) {
            vs_main_freeHeapR(var_s0->unkD1C.unk30);
            var_s0->unkD1C.unk30 = NULL;
        }
        func_800CE8F4(var_s0);
        var_s0 = temp_s1;
    }
}

char func_800CF218(func_800CF0E8_t* arg0, int arg1, int arg2)
{
    D_800F53B8_t2 spawn;
    int _[4] __attribute__((unused));
    char token;
    int id;
    int i;
    D_800F53B8_t* child;

    token = func_800CF49C();
    spawn.unk0 = (D_800F53B8_t3*)&arg0->unk4;
    spawn.unk14 = D_800F569C->block8Data;
    spawn.unk18 = arg0->effectId * 3;
    spawn.unk1C = NULL;
    spawn.unk20 = token;
    D_800F53C0 = *arg0;

    for (i = 0; i < arg0->unk2; ++i) {
        id = arg0->effectId;
        if ((id >= 40 && id <= 41) || (id >= 44 && id <= 53)) {
            spawn.unk4 = (D_800F53B8_t3*)((char*)arg0 + (i * 12 + 16));
            spawn.unkC = (D_800F53B8_t3*)&arg0->unk4;
        } else {
            switch ((u_short)id) {
            case 23:
            case 25:
                spawn.unk4 = (D_800F53B8_t3*)((char*)arg0 + (i * 12 + 16));
                spawn.unkC = (D_800F53B8_t3*)&arg0->unk4;
                break;
            default:
                spawn.unk4 = (D_800F53B8_t3*)&arg0->unk4;
                spawn.unkC = (D_800F53B8_t3*)((char*)arg0 + (i * 12 + 16));
                break;
            }
        }
        spawn.unk8 = (D_800F53B8_t3*)((char*)arg0 + (i * 12 + 16));
        spawn.unk10 = *(u_short*)((char*)arg0 + i * 12 + 16);
        child = func_800CF55C(&spawn);
        child->unkD1C.unk3C = arg2;
        child->unkD1C.unk38 = arg0->effectId;
        if (arg0->effectId == 54) {
            child->unk14_8 = 4;
        } else {
            child->unk14_8 = 2;
        }
        func_800CF484(3, child);
    }
    return token;
}

int func_800CF3F8(func_800CF0E8_t* arg0, int arg1)
{
    int _[4] __attribute__((unused));
    func_800D7890(0);
    func_800D1B18(&D_800F55A8);
    func_800D1B18(&D_800F54D8);
    return func_800CF218(arg0, 0, arg1);
}

int func_800CF458(func_800CF0E8_t* arg0, int arg1, int arg2)
{
    return func_800CF218(arg0, arg1, arg2);
}

void func_800CF478(int arg0) { D_800F531C = arg0; }

void func_800CF484(int arg0, D_800F53B8_t* arg1) { arg1->unkD1C.unk3A = arg0; }

int func_800CF48C(void) { return D_800F531C; }

int func_800CF49C(void)
{
    int temp_a1;
    int j;
    int i;
    int var_t2;
    int* var_a2;

    var_t2 = 0;
    var_a2 = D_800F5320;

    for (i = 0; i < 4; ++i) {
        temp_a1 = D_800F5320[i];
        if (temp_a1 == -2) {
            continue;
        }

        for (j = 1; j < 32; ++j) {
            int v = 1 << j;
            if (!(temp_a1 & v)) {
                D_800F5320[i] = temp_a1 | v;
                var_t2 = (i << 5) + j;
                goto done;
            }
        }
    }
done:
    return var_t2;
}

void func_800CF514(int arg0)
{
    int* ptr = D_800F5320;
    int var_v1 = arg0;
    if (arg0 < 0) {
        var_v1 = arg0 + 0x1F;
    }
    var_v1 >>= 5;
    ptr[var_v1] &= ~(1 << (arg0 - (var_v1 << 5)));
}

D_800F53B8_t* func_800CF55C(D_800F53B8_t2* arg0)
{
    D_800F53B8_t* var_a1;
    D_800F53B8_t* temp_v0 = vs_main_allocHeapR(sizeof *temp_v0);
    func_800CE714(arg0, temp_v0);
    var_a1 = D_800F54B0;

    if ((var_a1 == NULL) || (arg0->unk10 < var_a1->unk9)) {
        temp_v0->next = var_a1;
        D_800F54B0 = temp_v0;
    } else {
        while (1) {
            D_800F53B8_t* temp_a0 = var_a1->next;
            if ((temp_a0 == NULL) || (arg0->unk10 < temp_a0->unk9)) {
                temp_v0->next = temp_a0;
                var_a1->next = temp_v0;
                break;
            }
            var_a1 = temp_a0;
        }
    }
    return temp_v0;
}

void func_800CF614(D_800F53B8_t* arg0)
{
    D_800F53B8_t* var_v1 = D_800F54B0;
    if (var_v1 == arg0) {
        D_800F54B0 = arg0->next;
    } else {
        while (var_v1->next != NULL) {
            if (var_v1->next == arg0) {
                var_v1->next = arg0->next;
                break;
            }
            var_v1 = var_v1->next;
        }
    }
    func_800D2904(arg0);
    func_800CF514(arg0->unk14_0);
    vs_main_freeHeapR(arg0);
}

func_800D4910_t* func_800CF694(D_800F53B8_t* arg0, effectExec renderer, int arg2)
{
    func_800D4910_t* temp_v0 = vs_main_allocHeapR(sizeof *temp_v0);
    temp_v0->next = arg0->unkD1C.unk34;
    arg0->unkD1C.unk34 = temp_v0;
    temp_v0->renderer = renderer;
    temp_v0->unk8 = 0;
    temp_v0->renderer(temp_v0, 1, arg2);
    return temp_v0;
}

void func_800CF70C(D_800F53B8_t* arg0, func_800D4910_t* arg1)
{
    if (arg1->unk8 != NULL) {
        vs_main_freeHeapR(arg1->unk8);
    }

    if (arg0->unkD1C.unk34 == arg1) {
        arg0->unkD1C.unk34 = arg1->next;
    } else {
        func_800D4910_t* var_v1 = arg0->unkD1C.unk34;
        while (var_v1->next != arg1) {
            var_v1 = var_v1->next;
        }
        var_v1->next = arg1->next;
    }

    vs_main_freeHeapR(arg1);
}

void func_800CF7A8(int arg0, int arg1, int arg2, int arg3)
{
    func_800CF0E8_t sp10;

    sp10.effectId = 54;
    sp10.unk2 = 1;
    sp10.unk4 = 5;
    sp10.unk10 = 5;
    sp10.unk8.s16 = 0;
    sp10.unkA.s16 = 0;
    sp10.unkC = 0;
    sp10.unk14.u16 = 0;
    sp10.unk16.u16 = 0;
    sp10.unk18 = 0;
    sp10.unk3 = 0;
    func_800CF3F8(&sp10, (arg0 & 0xFF) | ((arg1 & 0xFF) << 8) | ((arg2 & 0xF) << 0x10)
                             | ((arg3 & 0xF) << 0x14) | 0xFF000000);
}

void func_800CF830(int arg0, int arg1)
{
    D_800F53B8_t* var_s1 = D_800F54B0;

    while (var_s1 != NULL) {
        func_800D4910_t* var_s0 = var_s1->unkD1C.unk34;
        while (var_s0 != NULL) {
            if (var_s0->renderer == func_800CE174) {
                var_s0->renderer(var_s0, 3, 0);
            }
            var_s0 = var_s0->next;
        }
        var_s1 = var_s1->next;
    }
}

void func_800CF8BC(void)
{
    func_800CF0E8_t sp10;

    sp10.effectId = 56;
    sp10.unk2 = 1;
    sp10.unk4 = 4;
    sp10.unkA.u8[0] = 0;
    sp10.unk10 = 5;
    sp10.unk14.u16 = 0;
    sp10.unk16.u16 = 0;
    sp10.unk18 = 0;
    sp10.unk3 = 0;
    sp10.unk8.u8[0] = D_800F5238;
    func_800CF3F8(&sp10, 0);
}

void func_800CF920(void) { D_800F522C = 0; }

void func_800CF92C(int arg0, int arg1, int arg2, short* arg3)
{
    int var_v1;
    int temp_a1;

    var_v1 = (short)arg2 + arg0;

    if (var_v1 <= 0) {
        var_v1 = 1;
    } else if (var_v1 >= 0xFF) {
        var_v1 = 0xFE;
    }

    temp_a1 = (arg2 >> 16) + arg1;

    if (temp_a1 <= 0) {
        temp_a1 = 1;
    } else if (temp_a1 >= 0xFF) {
        temp_a1 = 0xFE;
    }

    *arg3 = var_v1 | temp_a1 << 8;
}

void func_800CF988(func_800CF988_t* arg0, int arg1, int arg2, int arg3)
{
    int page;
    int offset;
    int left = 320;

    if (arg0->unk8[0].unk4 < left) {
        left = arg0->unk8[0].unk4;
    }

    if (arg0->unk8[1].unk4 < left) {
        left = arg0->unk8[1].unk4;
    }

    if (arg0->unk8[2].unk4 < left) {
        left = arg0->unk8[2].unk4;
    }

    if (arg0->unk8[3].unk4 < left) {
        left = arg0->unk8[3].unk4;
    }

    left &= ~0x3F;
    page = left / 64;
    arg0->unk8[1].unkA = ((vs_main_frameBuf & 1) ? page : page + 5) | arg3 | 0x100;
    offset = arg1 - left;
    func_800CF92C(offset, arg2, *(int*)&arg0->unk8[0].unk4, &arg0->unk8[0].unk8);
    func_800CF92C(offset, arg2, *(int*)&arg0->unk8[1].unk4, &arg0->unk8[1].unk8);
    func_800CF92C(offset, arg2, *(int*)&arg0->unk8[2].unk4, &arg0->unk8[2].unk8);
    func_800CF92C(offset, arg2, *(int*)&arg0->unk8[3].unk4, &arg0->unk8[3].unk8);
}

void func_800CFAAC(func_800CFAAC_t* arg0)
{
    int dx;
    int dy;
    int sx;
    int sy;

    if (*(int*)&arg0->unkC == *(int*)&arg0->unk10) {
        return;
    }
    sx = -1;
    sy = -1;
    dx = arg0->unk10 - arg0->unkC;
    dy = arg0->unk12 - arg0->unkE;
    if (dx < 0) {
        dx = -dx;
        sx = 1;
    }
    if (dy < 0) {
        dy = -dy;
        sy = 1;
    }
    if (dy < dx) {
        arg0->unk10 += sx;
        if (dx < dy * 2) {
            arg0->unk12 += sy;
        }
    } else {
        arg0->unk12 += sy;
        if (dy < dx * 2) {
            arg0->unk10 += sx;
        }
    }
}

int func_800CFB68(int arg0, int arg1, int arg2)
{
    return (((arg1 - arg0) * arg2) >> 7) + arg0;
}

int vs_battle_randUniformInt(int arg0, int arg1)
{
    if (arg0 != arg1) {
        int new_var;

        if (arg1 < arg0) {
            new_var = rand() % (arg0 - arg1);
            return new_var + arg1;
        }

        new_var = rand() % (arg1 - arg0);
        return new_var + arg0;
    }

    return arg0;
}

int _absMax3(int arg0, int arg1, int arg2) __attribute__((unused));
int _absMax3(int arg0, int arg1, int arg2)
{
    int var_v0;
    int new_var = 0;
    int var_t0 = arg0 >= new_var ? arg0 : -arg0;
    int var_a3 = arg1 >= new_var ? arg1 : -arg1;
    int var_v1 = arg2 >= new_var ? arg2 : -arg2;

    if (var_t0 < var_a3) {
        var_v0 = var_a3 < var_v1;
        arg0 = arg1;
    } else {
        var_v0 = var_t0 < var_v1;
    }
    if (var_v0 != 0) {
        arg0 = arg2;
    }
    return arg0;
}

int _absMax2(int arg0, int arg1) __attribute__((unused));
int _absMax2(int arg0, int arg1)
{
    int abs0 = arg0 >= 0 ? arg0 : -arg0;

    if (abs0 < (arg1 < 0 ? -arg1 : arg1)) {
        return arg1;
    }
    return arg0;
}

int func_800CFC8C(int arg0, int arg1, int arg2, int arg3)
{
    return arg0
         + ((int)((arg1 - arg0) * (ONE - rcos((int)(arg3 * ONE / 2) / arg2)))
             / (ONE * 2));
}

void vs_battle_lerpVector(short* src, int t, VECTOR* vec)
{
    int start0 = src[0];
    int end0 = src[1];
    int start1 = src[2];
    int end1 = src[3];
    int start2 = src[4];
    int end2 = src[5];

    vec->vx = (((end0 - start0) * t) >> 7) + start0;
    vec->vy = (((end1 - start1) * t) >> 7) + start1;
    vec->vz = (((end2 - start2) * t) >> 7) + start2;
}

void vs_battle_lerpSvector(short* src, int t, SVECTOR* vec)
{
    int start0 = src[0];
    int end0 = src[1];
    int start1 = src[2];
    int end1 = src[3];
    int start2 = src[4];
    int end2 = src[5];

    vec->vx = (((end0 - start0) * t) >> 7) + start0;
    vec->vy = (((end1 - start1) * t) >> 7) + start1;
    vec->vz = (((end2 - start2) * t) >> 7) + start2;
}

void vs_battle_lerp2DVector(short* src, int t, int* vec)
{
    int start0 = src[0];
    int end0 = src[1];
    int start1 = src[2];
    int end1 = src[3];

    vec[0] = ((((end0 - start0) * t) >> 7) + start0);
    vec[1] = ((((end1 - start1) * t) >> 7) + start1);
}

int func_800CFE1C(short* arg0, int arg1)
{
    int new_var = arg0[0];
    return (((arg0[1] - new_var) * arg1) >> 7) + new_var;
}

void _addSVectorToVector(SVECTOR* svec, VECTOR* vec, VECTOR* out) __attribute__((unused));
void _addSVectorToVector(SVECTOR* svec, VECTOR* vec, VECTOR* out)
{
    int v = svec->vy;
    out->vx = vec->vx + svec->vx;
    do {
        out->vy = vec->vy + v;
        out->vz = vec->vz + svec->vz;
    } while (0);
}

void func_800CFE7C(func_800CFE98_t* arg0)
{
    arg0->unk10 = 0x1000;
    arg0->unk8 = 0x1000;
    arg0->unk0 = 0x1000;
    arg0->unkC = 0;
    arg0->unk4 = 0;
}

void func_800CFE98(SVECTOR* arg0, func_800CFE98_t* arg1)
{
    func_800CFE7C(arg1);
    arg1->unk14.vx = arg0->vx;
    arg1->unk14.vy = arg0->vy;
    arg1->unk14.vz = arg0->vz;
}

typedef struct {
    short rotation[3];
    u_short flags;
    u_char pad8[6];
    short frame;
    u_char pad10[12];
    VECTOR position;
    u_char pad2C[8];
    u_char actor, bone, targetActor, targetBone;
    MATRIX world, view, attachment, facing;
    SVECTOR saved, control0, control1;
} effectTransformState;

void func_800CFEF0(D_800F53B8_t* arg0)
{
    int i;
    for (i = 0; i < D_800F569C->block9Data->unk15; ++i) {
        func_800D0B30_t* definition = &((func_800D0B30_t*)D_800F569C->block10Data)[i];
        effectTransformState* state = (void*)&arg0->unk1C[i];
        state->rotation[0] = definition->unk8;
        state->rotation[1] = definition->unkC;
        state->rotation[2] = definition->unk10;
        state->position.vx = 0;
        state->position.vy = 0;
        state->position.vz = 0;
        func_800CFE7C((void*)&state->facing);
        state->flags = 0;
        state->frame = 0;
        *(int*)&state->actor = 0;
        if (definition->unk0 & 2) {
            switch (definition->unk0 & 0x18) {
            case 0x10:
                if (arg0->unkD1C.unk24.unk0 == 4) {
                    state->actor = ((u_char*)&arg0->unkD1C.unk24.unk4)[0];
                    state->bone = ((u_char*)&arg0->unkD1C.unk24.unk4)[2];
                } else {
                    state->actor = 0xFF;
                    func_800CFE98(
                        (SVECTOR*)&arg0->unkD1C.unk24.unk4, (void*)&state->attachment);
                }
                break;
            case 8:
                if (arg0->unkD1C.unkC.unk0 == 4) {
                    state->actor = ((u_char*)&arg0->unkD1C.unkC.unk4)[0];
                    state->bone = ((u_char*)&arg0->unkD1C.unkC.unk4)[2];
                } else {
                    state->actor = 0xFF;
                    func_800CFE98(
                        (SVECTOR*)&arg0->unkD1C.unkC.unk4, (void*)&state->attachment);
                }
                break;
            case 0:
                state->actor = (u_char)definition->unk2;
                state->bone = 0;
                break;
            }
            if (!(definition->unk0 & 4))
                state->bone = ((u_char*)&definition->unk2)[1];
        }
        if (definition->unk0 & 0x80) {
            switch (definition->unk0 & 0xC00) {
            case 0x800:
                if (arg0->unkD1C.unk24.unk0 == 4) {
                    state->targetActor = ((u_char*)&arg0->unkD1C.unk24.unk4)[0];
                    state->targetBone = ((u_char*)&arg0->unkD1C.unk24.unk4)[2];
                } else {
                    state->targetActor = 0xFF;
                    state->saved = *(SVECTOR*)&arg0->unkD1C.unk24.unk4;
                }
                break;
            case 0x400:
                if (arg0->unkD1C.unkC.unk0 == 4) {
                    state->targetActor = ((u_char*)&arg0->unkD1C.unkC.unk4)[0];
                    state->targetBone = ((u_char*)&arg0->unkD1C.unkC.unk4)[2];
                } else {
                    state->targetActor = 0xFF;
                    state->saved = *(SVECTOR*)&arg0->unkD1C.unkC.unk4;
                }
                break;
            case 0:
                state->targetActor = ((u_char*)&definition->unk8)[2] & 31;
                state->targetBone = 0;
                break;
            }
            if (!(definition->unk0 & 0x200))
                state->targetBone = ((u_char*)&definition->unk8)[3];
        }
    }
}

typedef struct {
    u_short flags;
    u_char pad2[3];
    u_char curve;
    u_char pad6[4];
    u_short mode;
    u_char padC[2];
    u_char limit;
    u_char padF;
    u_short unk10;
    u_short shape12;
} func_800D0548_arg0;

typedef struct {
    u_char pad0[6];
    u_short flags;
    u_char pad8[6];
    short frame;
    u_char pad10[12];
    VECTOR position;
    u_char pad2C[32];
    VECTOR endpoint;
    u_char pad5C[92];
    SVECTOR saved;
    SVECTOR control0;
    SVECTOR control1;
} func_800D0548_arg1;

void func_800D1718(SVECTOR*, SVECTOR*, int, int, SVECTOR*);
void func_800D1778(SVECTOR*, SVECTOR*, int, int, SVECTOR*);

void func_800D01E4(func_800D0548_arg0* arg0, func_800D0548_arg1* arg1)
{
    SVECTOR start, end, result;
    if (arg0->mode & 0x80) {
        start = arg1->saved;
        end.vx = arg1->endpoint.vx;
        end.vy = arg1->endpoint.vy;
        end.vz = arg1->endpoint.vz;
    } else {
        end = arg1->saved;
        start.vx = arg1->endpoint.vx;
        start.vy = arg1->endpoint.vy;
        start.vz = arg1->endpoint.vz;
    }
    switch ((arg0->mode >> 5) & 3) {
    case 0:
        func_800D1778(&start, &end, arg0->limit + 1, arg1->frame, &result);
        break;
    case 1:
        func_800D1718(&start, &end, arg0->limit + 1, arg1->frame, &result);
        break;
    case 2:
        func_800D1778(&start, &end, 128,
            vs_battle_sampleCurve(arg0->curve + 1, arg1->frame), &result);
        break;
    }
    arg1->position.vx = result.vx;
    arg1->position.vy = result.vy;
    arg1->position.vz = result.vz;
}

void func_800D037C(func_800D0548_arg0* arg0, func_800D0548_arg1* arg1)
{
    int t;
    SVECTOR start, end, result;
    if (arg0->mode & 0x80) {
        start = arg1->saved;
        end.vx = arg1->endpoint.vx;
        end.vy = arg1->endpoint.vy;
        end.vz = arg1->endpoint.vz;
    } else {
        end = arg1->saved;
        start.vx = arg1->endpoint.vx;
        start.vy = arg1->endpoint.vy;
        start.vz = arg1->endpoint.vz;
    }
    switch ((arg0->mode >> 5) & 3) {
    case 0:
        t = (arg1->frame * 3 * ONE) / (arg0->limit + 1) - ONE;
        break;
    case 1:
        t = (-rcos((arg1->frame * (ONE / 2)) / (arg0->limit + 1)) * 3) / 2 + ONE / 2;
        break;
    case 2:
        t = vs_battle_sampleCurve(arg0->curve + 1, arg1->frame) * 96 - ONE;
        break;
    }
    vs_battle_splineInterpolate(
        &start, &arg1->control0, &arg1->control1, &end, t, &result);
    arg1->position.vx = result.vx;
    arg1->position.vy = result.vy;
    arg1->position.vz = result.vz;
}

void func_800D0548(func_800D0548_arg0* arg0, func_800D0548_arg1* arg1)
{
    switch (arg0->flags & 0x3000) {
    case 0:
        break;
    case 0x1000:
        func_800D01E4(arg0, arg1);
        break;
    case 0x2000:
        func_800D037C(arg0, arg1);
        break;
    }
    if (arg1->flags & 4) {
        if (arg0->limit >= arg1->frame) {
            ++arg1->frame;
        }
    }
}

void func_800D05F4(func_800D0548_arg0* arg0, func_800D0548_arg1* arg1)
{
    SVECTOR control0, control1;
    VECTOR delta, start, end;
    MATRIX transform;
    long distance;
    int radius0, radius1, angle0, angle1;

    if (arg0->mode & 0x80) {
        start.vx = arg1->saved.vx;
        start.vy = arg1->saved.vy;
        start.vz = arg1->saved.vz;
        end.vx = arg1->endpoint.vx;
        end.vy = arg1->endpoint.vy;
        end.vz = arg1->endpoint.vz;
    } else {
        start.vx = arg1->endpoint.vx;
        start.vy = arg1->endpoint.vy;
        start.vz = arg1->endpoint.vz;
        end.vx = arg1->saved.vx;
        end.vy = arg1->saved.vy;
        end.vz = arg1->saved.vz;
    }
    delta.vx = end.vx - start.vx;
    delta.vy = end.vy - start.vy;
    delta.vz = end.vz - start.vz;
    distance =
        vs_gte_rsqrt(delta.vx * delta.vx + delta.vy * delta.vy + delta.vz * delta.vz);
    control0.vz = distance * (((arg0->shape12 >> 8) & 15) - 8) / 8;
    control1.vz = distance + distance * ((arg0->shape12 >> 12) - 8) / 8;
    radius1 = (*(u_short*)&arg0->limit >> 3) & 0x1E0;
    radius0 = radius1;
    if (*(u_short*)&arg0->limit & 0xF000) {
        radius0 = radius1 + rand() % ((*(u_short*)&arg0->limit >> 12) << 5);
        radius1 += rand() % ((*(u_short*)&arg0->limit >> 12) << 5);
    }
    angle1 = ((u_char)arg0->shape12 & 15) << 8;
    angle0 = angle1;
    if (arg0->shape12 & 0xF0) {
        angle0 = angle1 + rand() % ((arg0->shape12 * 16) & 0xF00);
        angle1 += rand() % ((arg0->shape12 * 16) & 0xF00);
    }
    control0.vx = (rcos(angle0) * radius0) >> 12;
    control0.vy = (rsin(angle0) * radius0) >> 12;
    control1.vx = (rcos(angle1) * radius1) >> 12;
    control1.vy = (rsin(angle1) * radius1) >> 12;
    vs_battle_lookAt(&start, &end, &transform);
    transform.t[0] = start.vx;
    transform.t[1] = start.vy;
    transform.t[2] = start.vz;
    SetRotMatrix(&transform);
    SetTransMatrix(&transform);
    RotTrans(&control0, &start, &distance);
    RotTrans(&control1, &end, &distance);
    arg1->control0.vx = start.vx;
    arg1->control0.vy = start.vy;
    arg1->control0.vz = start.vz;
    arg1->control1.vx = end.vx;
    arg1->control1.vy = end.vy;
    arg1->control1.vz = end.vz;
}

void func_800D0984(int arg0, func_800D0C60_t* arg1, int arg2)
{
    VECTOR delta, start, end;
    SVECTOR offset;
    long distance;
    start.vx = vs_scratch.camera.lookAt.vx >> 12;
    start.vy = vs_scratch.camera.lookAt.vy >> 12;
    start.vz = vs_scratch.camera.lookAt.vz >> 12;
    end.vx = vs_scratch.camera.position.vx >> 12;
    end.vy = vs_scratch.camera.position.vy >> 12;
    end.vz = vs_scratch.camera.position.vz >> 12;
    vs_battle_lookAt(&start, &end, (MATRIX*)&arg1->unk78);
    arg1->unk78.unk14.vx = start.vx;
    arg1->unk78.unk14.vy = start.vy;
    arg1->unk78.unk14.vz = start.vz;
    if (arg2) {
        delta.vx = end.vx - start.vx;
        delta.vy = end.vy - start.vy;
        delta.vz = end.vz - start.vz;
        distance =
            vs_gte_rsqrt(delta.vx * delta.vx + delta.vy * delta.vy + delta.vz * delta.vz);
        offset.vx = offset.vy = 0;
        offset.vz = distance - 0x600;
        SetRotMatrix((MATRIX*)&arg1->unk78);
        SetTransMatrix((MATRIX*)&arg1->unk78);
        RotTrans(&offset, &start, &distance);
        arg1->unk78.unk14.vx = start.vx;
        arg1->unk78.unk14.vy = start.vy;
        arg1->unk78.unk14.vz = start.vz;
    }
}

void func_800D0B08(func_800CFE98_t* arg0) { func_800CFE98(D_800F5310, arg0); }

void func_800D0B30(func_800D0B30_t* arg0, SVECTOR* arg1, func_800D0B30_t2* arg2)
{
    if (arg0->unk0 & 1) {
        vs_battle_lerpSvector(arg0->unk14, D_800F5330[arg0->unk6], &arg2->unk8);
        arg1->vx += arg2->unk8.vx;
        arg1->vy = arg1->vy + arg2->unk8.vy;
        arg1->vz += arg2->unk8.vz;
        RotMatrix_gte(arg1, &arg2->unk48);
        vs_battle_lerpVector(arg0->unk20, D_800F5330[arg0->unk4], &arg2->unk10);
        TransMatrix(&arg2->unk48, &arg2->unk10);
        vs_battle_lerpVector(arg0->unk2C, D_800F5330[arg0->unk7], &arg2->unk20);
        ScaleMatrix(&arg2->unk48, &arg2->unk20);
        return;
    }
    func_800CFE7C((func_800CFE98_t*)&arg2->unk48);
    arg2->unk48.t[2] = 0;
    arg2->unk48.t[1] = 0;
    arg2->unk48.t[0] = 0;
}

void func_800D0C60(int arg0, func_800D0C60_t* arg1)
{
    func_8006EBF8_t sp10;
    int sp20[2];

    if (arg1->unk34 < 0x10U) {
        func_800A1720(arg1->unk34, arg1->unk35, &arg1->unk78, sp20);
        func_800A1108(arg1->unk34, &sp10);
        arg1->unkBE = sp10.unk0.unk4.pad;
        return;
    }

    switch (arg1->unk34) {
    case 0x10:
    case 0x11:
        func_800D0984(arg0, arg1, arg1->unk34 != 0x10);
        break;
    case 0x12:
        func_800D0B08(&arg1->unk78);
        break;
    }
}

void func_800D0D08(D_800F53B8_t* arg0)
{
    int i;
    func_800D0B30_t2* scratch = (void*)0x1F8002C8;
    for (i = 0; i < D_800F569C->block9Data->unk15; ++i) {
        func_800D0B30_t* definition = &((func_800D0B30_t*)D_800F569C->block10Data)[i];
        effectTransformState* state = (void*)&arg0->unk1C[i];
        func_800D0B30(definition, (SVECTOR*)state, scratch);
        if ((definition->unk0 & 0x80) && state->targetActor != 0xFF
            && ((definition->unk0 & 0x100) || !(state->flags & 2))) {
            if (state->targetActor == 0x12) {
                state->saved.vx = D_800F5230.unkE0.vx;
                state->saved.vy = D_800F5230.unkE0.vy;
                state->saved.vz = D_800F5230.unkE0.vz;
            } else {
                func_800A1AF8(state->targetActor, state->targetBone, &state->saved, 0);
            }
            state->flags |= 2;
        }
        if (state->actor != 0xFF && ((definition->unk0 & 0x20) || !(state->flags & 1))) {
            func_800D0C60((int)arg0, (void*)state);
            state->flags |= 1;
        }
        if (definition->unk0 & 2) {
            if ((definition->unk0 & 0xC000) == 0x4000) {
                ((int*)&state->attachment)[0] = ((int*)&state->attachment)[4] =
                    rcos(state->saved.pad);
                ((int*)&state->attachment)[1] = rsin(state->saved.pad);
                ((int*)&state->attachment)[3] = -((int*)&state->attachment)[1];
                ((int*)&state->attachment)[2] = 0x1000;
            }
            CompMatrix(&state->attachment, &scratch->unk48, &state->world);
        } else {
            state->world = scratch->unk48;
        }
        if ((definition->unk0 & 0x3000) == 0x2000 && !(state->flags & 8)) {
            func_800D05F4((void*)definition, (void*)state);
            state->flags |= 8;
        }
        if (definition->unk0 & 0x80) {
            func_800D0548((void*)definition, (void*)state);
        }
        if (definition->unk0 & 0x40) {
            state->world.t[0] = state->position.vx;
            state->world.t[1] = state->position.vy;
            state->world.t[2] = state->position.vz;
        } else {
            state->world.t[0] += state->position.vx;
            state->world.t[1] += state->position.vy;
            state->world.t[2] += state->position.vz;
        }
        if ((short)definition->unk0 & 0x8000) {
            if (definition->unk0 & 0x4000) {
                scratch->target.vx = state->saved.vx;
                scratch->target.vy = state->saved.vy;
                scratch->target.vz = state->saved.vz;
            } else {
                scratch->target.vx = state->attachment.t[0];
                scratch->target.vy = state->attachment.t[1];
                scratch->target.vz = state->attachment.t[2];
            }
            if (scratch->target.vx != state->world.t[0]
                || scratch->target.vy != state->world.t[1]
                || scratch->target.vz != state->world.t[2]) {
                vs_battle_lookAt(
                    (VECTOR*)state->world.t, &scratch->target, &state->facing);
                state->facing.t[0] = state->world.t[0];
                state->facing.t[1] = state->world.t[1];
                state->facing.t[2] = state->world.t[2];
            }
            CompMatrix(&state->facing, &scratch->unk48, &state->world);
        }
        CompMatrix(&vs_scratch.viewMatrix, &state->world, &state->view);
    }
}

void func_800D1104(int arg0)
{
    int i;
    pFileCurveBlock* temp_a2 = D_800F569C->curveBlock;

    for (i = 0; i < temp_a2->count; ++i) {
        D_800F5330[i + 1] = D_800F569C->curves[i][arg0 % temp_a2->curveSizes[i]];
    }
}

int vs_battle_sampleCurve(int curveId, int distance)
{
    pFileCurveBlock* block = D_800F569C->curveBlock;

    if ((curveId != 0) && (block->count >= curveId)) {
        return D_800F569C->curves[curveId - 1][distance % block->curveSizes[curveId - 1]];
    }

    return 0;
}

int func_800D11F4(int arg0, int arg1)
{
    u_char* buf = D_800F569C->block11Data;
    pFileBlock11* table = (pFileBlock11*)buf;
    int offset;
    int v;

    if (arg0 < table->count) {
        offset = *(arg0 + table->offsets);
        offset += buf[offset];
        while (buf[offset] != 0) {
            v = arg1 - buf[offset];
            if (v < 0) {
                break;
            }
            offset += 2;
            arg1 = v;
        }
        if (buf[offset] != 0) {
            return (buf[offset + 3] - buf[offset + 1]) * arg1 / buf[offset]
                 + buf[offset + 1];
        }
        if (arg1 == 0) {
            return buf[offset + 1];
        }
        return -1;
    }
    return 0;
}

int func_800D12D8(int arg0)
{
    u_char* table = D_800F569C->block11Data;
    int sum = 0;

    if (arg0 < *(int*)table) {
        int off = ((short*)table)[arg0 + 2];
        off += table[off];
        while (table[off] != 0) {
            sum += table[off];
            off += 2;
        }
        sum += 1;
    }
    return sum;
}

int vs_battle_lerpRatio(int arg0, int arg1, int arg2, int arg3)
{
    int var_v0 = (arg1 - arg0) * ((arg2 * ONE) / arg3);
    return arg0 + var_v0 / ONE;
}

void vs_battle_splineInterpolate(
    SVECTOR* p0, SVECTOR* p1, SVECTOR* p2, SVECTOR* p3, int t, SVECTOR* out)
{
    int temp_t3 = -t;
    int temp_t2 = t - ONE;
    int temp_t1 = t + ONE;

    int temp_t0 =
        (((((temp_t3 * temp_t2) >> 0xC) * (t - ONE * 2)) >> 0xC) * (ONE * 2 / 3)) >> 0xE;
    int temp_t3_2 = (((temp_t1 * temp_t2) >> 0xC) * (t - ONE * 2)) >> 0xD;
    int temp_t2_2 = (((temp_t1 * temp_t3) >> 0xC) * (t - ONE * 2)) >> 0xD;
    int temp_v1_2 = (((((temp_t1 * t) >> 0xC) * temp_t2) >> 0xC) * (ONE * 2 / 3)) >> 0xE;

    out->vx = ((p0->vx * temp_t0) + (p1->vx * temp_t3_2) + (p2->vx * temp_t2_2)
                  + (p3->vx * temp_v1_2))
           >> 0xC;
    out->vy = ((p0->vy * temp_t0) + (p1->vy * temp_t3_2) + (p2->vy * temp_t2_2)
                  + (p3->vy * temp_v1_2))
           >> 0xC;
    out->vz = ((p0->vz * temp_t0) + (p1->vz * temp_t3_2) + (p2->vz * temp_t2_2)
                  + (p3->vz * temp_v1_2))
           >> 0xC;
}

void func_800D155C(int arg0, int arg1, int arg2, int arg3, int arg4, int* arg5)
{
    int p0 = ((-arg4 * (arg4 - ONE)) >> 12) * (arg4 - (ONE * 2));
    int p1 = (((arg4 + ONE) * (arg4 - ONE)) >> 12) * (arg4 - (ONE * 2));
    int p2 = (((arg4 + ONE) * -arg4) >> 12) * (arg4 - (ONE * 2));
    int p3 = (((arg4 + ONE) * arg4) >> 12) * (arg4 - ONE);

    *arg5 = ((arg0 * (((p0 >> 12) * (ONE * 2 / 3)) >> 14)) + (arg1 * (p1 >> 13))
                + (arg2 * (p2 >> 13)) + (arg3 * (((p3 >> 12) * (ONE * 2 / 3)) >> 14)))
         >> 12;
}

int vs_battle_lerp(int arg0, int arg1, int arg2)
{
    int var_v0 = (arg1 - arg0) * arg2;
    return arg0 + (var_v0 / (ONE * 2));
}

void func_800D169C(SVECTOR* arg0, SVECTOR* arg1, int arg2, SVECTOR* arg3)
{
    arg3->vx = vs_battle_lerp(arg0->vx, arg1->vx, arg2);
    arg3->vy = vs_battle_lerp(arg0->vy, arg1->vy, arg2);
    arg3->vz = vs_battle_lerp(arg0->vz, arg1->vz, arg2);
}

void func_800D1718(SVECTOR* arg0, SVECTOR* arg1, int arg2, int arg3, SVECTOR* arg4)
{
    func_800D169C(arg0, arg1, ONE - rcos((arg3 * ONE / 2) / arg2), arg4);
}

void func_800D1778(SVECTOR* arg0, SVECTOR* arg1, int arg2, int arg3, SVECTOR* arg4)
{
    func_800D169C(arg0, arg1, (arg3 * (ONE * 2)) / arg2, arg4);
}

void func_800D17A8(VECTOR* arg0, VECTOR* arg1, int arg2, VECTOR* arg3)
{
    arg3->vx = vs_battle_lerp(arg0->vx, arg1->vx, arg2);
    arg3->vy = vs_battle_lerp(arg0->vy, arg1->vy, arg2);
    arg3->vz = vs_battle_lerp(arg0->vz, arg1->vz, arg2);
}

void func_800D1824(VECTOR* arg0, VECTOR* arg1, int arg2, int arg3, VECTOR* arg4)
{
    func_800D17A8(arg0, arg1, ONE - rcos((arg3 * ONE / 2) / arg2), arg4);
}

void func_800D1884(VECTOR* arg0, VECTOR* arg1, int arg2, int arg3, VECTOR* arg4)
{
    func_800D17A8(arg0, arg1, (arg3 * (ONE * 2)) / arg2, arg4);
}

int func_800D18B4(int arg0, int arg1, int arg2, int arg3)
{
    return vs_battle_lerp(arg0, arg1, ONE - rcos((arg3 * ONE / 2) / arg2));
}

int func_800D1904(int arg0, int arg1, int arg2, int arg3)
{
    return vs_battle_lerp(arg0, arg1, (arg3 * (ONE * 2)) / arg2);
}

void func_800D1930(void)
{
    int i;
    D_800F5518 = 0;
    D_800F55E8 = 0;
    D_800F54D0 = 0;
    D_800F55A0 = 0;

    for (i = 0; i < 4; ++i) {
        D_800F54B8[i].unk0 = 0xFF;
    }
}

void func_800D197C(VECTOR* position, VECTOR* target, MATRIX* view)
{
    static const VECTOR initialUp = { 0, -ONE, 0 };
    VECTOR up = initialUp;
    VECTOR right, forward, translation;
    forward.vx = target->vx - position->vx;
    forward.vy = target->vy - position->vy;
    forward.vz = target->vz - position->vz;
    VectorNormal(&forward, &forward);
    OuterProduct0(&up, &forward, &right);
    VectorNormal(&right, &right);
    OuterProduct0(&right, &forward, &up);
    VectorNormal(&up, &up);
    view->m[0][0] = -right.vx;
    view->m[0][1] = -right.vy;
    view->m[0][2] = -right.vz;
    view->m[1][0] = up.vx;
    view->m[1][1] = up.vy;
    view->m[1][2] = up.vz;
    view->m[2][0] = forward.vx;
    view->m[2][1] = forward.vy;
    view->m[2][2] = forward.vz;
    ApplyMatrixLV(view, position, &translation);
    view->t[0] = -translation.vx;
    view->t[1] = -translation.vy;
    view->t[2] = -translation.vz;
}

void func_800D1B18(D_800F54D8_t* arg0)
{
    vs_battle_getCameraPosition(&arg0->position);
    vs_battle_getCameraLookAt(&arg0->lookAt);
    arg0->roll = vs_battle_getCameraRoll() + ONE * 8;
    arg0->nearClip = vs_main_nearClip;
    arg0->projectionDistance = vs_main_projectionDistance;
    arg0->farClip = vs_scratch.camera.farClip;
}

void func_800D1B80(D_800F54D8_t* camera)
{
    VECTOR offset, position;
    MATRIX unusedTransform;
    SVECTOR unusedRotation;
    int dx, dz, yaw, pitch, horizontal;
    dx = (camera->position.vx - camera->lookAt.vx) >> 12;
    dz = (camera->position.vz - camera->lookAt.vz) >> 12;
    yaw = ratan2(dx, dz);
    offset.vx = rcos(yaw) * (camera->unk20 >> 12);
    offset.vz = -rsin(yaw) * (camera->unk20 >> 12);
    pitch = ratan2(
        (camera->position.vy - camera->lookAt.vy) >> 12, vs_gte_rsqrt(dx * dx + dz * dz));
    offset.vy = -rsin(pitch) * (camera->unk28 >> 12);
    horizontal = -rcos(pitch) * (camera->unk28 >> 12);
    offset.vy += rcos(pitch) * (camera->unk24 >> 12);
    horizontal += -rsin(pitch) * (camera->unk24 >> 12);
    offset.vx += rsin(yaw) * (horizontal >>= 12);
    offset.vz += rcos(yaw) * horizontal;
    position.vx = camera->position.vx + offset.vx;
    position.vy = camera->position.vy + offset.vy;
    position.vz = camera->position.vz + offset.vz;
    vs_battle_setCameraPosition(&position);
    position.vx = camera->lookAt.vx + offset.vx;
    position.vy = camera->lookAt.vy + offset.vy;
    position.vz = camera->lookAt.vz + offset.vz;
    vs_battle_setCameraLookAt(&position);
    {
        int rollOffset = camera->unk2C - 0x8000;
        vs_battle_setCameraRoll(camera->roll + rollOffset);
    }
    vs_battle_setNearClip(camera->nearClip);
    vs_battle_setProjectionDistance(camera->projectionDistance);
    /* This original call site does not initialize the setter's second argument. */
    ((void (*)())vs_battle_setFarClip)(camera->farClip);
    func_8007ACB0();
}

void func_800D1DE4(int arg0) { D_800F5518 |= arg0; }

void func_800D1DFC(int arg0)
{
    if (arg0 != 0) {
        D_800F5518 &= ~arg0;
        return;
    }
    D_800F5518 = 0;
}

void func_800D1E20(int arg0) { D_800F55E8 = arg0; }

u_char func_800D1E2C(D_800F54B8_t* arg0)
{
    int var_v0;

    if (arg0->unk1_5) {
        var_v0 = vs_battle_sampleCurve(arg0->unk2, arg0->unk0);
    } else {
        var_v0 = arg0->unk2;
    }
    return var_v0;
}

u_char func_800D1E78(D_800F54B8_t* arg0)
{
    int var_s0;

    if (arg0->unk1_6) {
        var_s0 = vs_battle_sampleCurve(arg0->unk3, arg0->unk0);
    } else {
        var_s0 = arg0->unk3;
    }

    if (var_s0 == 0) {
        return 0;
    }

    return (rand() % var_s0);
}

void func_800D1EF0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if ((arg0 >> i) & 1) {
            D_800F54B8_t* p = &D_800F54B8[i];
            p->unk1_0 = arg1;
            p->unk4 = arg2;
            p->unk1_5 = arg3;
            p->unk2 = arg4;
            p->unk1_6 = arg5;
            p->unk3 = arg6;
            p->unk0 = 0;
            p->unk5 = func_800D1E78(p);
            func_800D1DE4(1 << i);
        }
    }
}

void func_800D1FEC(int arg0)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if ((arg0 >> i) & 1) {
            D_800F54B8[i].unk0 = 0xFF;
            func_800D1DFC(1 << i);
        }
    }
}

void func_800D206C(void)
{
    int i;

    for (i = 0; i < 4; ++i) {
        int v;

        if (!((D_800F5518 >> i) & 1)) {
            continue;
        }

        v = func_800D11F4(D_800F54B8[i].unk1_0, D_800F54B8[i].unk0);

        if (v >= 0) {
            v = ((rsin(D_800F54B8[i].unk5 * 32) * v) * D_800F54B8[i].unk4) >> 8;

            switch (i) {
            case 0:
                D_800F54D8.unk20 = v;
                break;

            case 1:
                D_800F54D8.unk24 = v;
                break;

            case 2:
                D_800F54D8.unk28 = v;
                break;

            case 3:
                D_800F54D8.unk2C = v >> 12;
                break;
            }

            D_800F54B8[i].unk5 +=
                func_800D1E2C(&D_800F54B8[i]) + func_800D1E78(&D_800F54B8[i]);
            ++D_800F54B8[i].unk0;
        } else {
            func_800D1FEC(1 << i);
        }
    }
}

void func_800D21C0(void)
{
    VECTOR start, end, result;
    start.vx = D_800F5520[0].position.vx >> 12;
    start.vy = D_800F5520[0].position.vy >> 12;
    start.vz = D_800F5520[0].position.vz >> 12;
    end.vx = D_800F5520[1].position.vx >> 12;
    end.vy = D_800F5520[1].position.vy >> 12;
    end.vz = D_800F5520[1].position.vz >> 12;
    func_800D1884(&start, &end, D_800F55A0, D_800F54D0, &result);
    D_800F54D8.position.vx = result.vx << 12;
    D_800F54D8.position.vy = result.vy << 12;
    D_800F54D8.position.vz = result.vz << 12;
    start.vx = D_800F5520[0].lookAt.vx >> 12;
    start.vy = D_800F5520[0].lookAt.vy >> 12;
    start.vz = D_800F5520[0].lookAt.vz >> 12;
    end.vx = D_800F5520[1].lookAt.vx >> 12;
    end.vy = D_800F5520[1].lookAt.vy >> 12;
    end.vz = D_800F5520[1].lookAt.vz >> 12;
    func_800D1884(&start, &end, D_800F55A0, D_800F54D0, &result);
    D_800F54D8.lookAt.vx = result.vx << 12;
    D_800F54D8.lookAt.vy = result.vy << 12;
    D_800F54D8.lookAt.vz = result.vz << 12;
    D_800F54D8.roll =
        func_800D1904(D_800F5520[0].roll, D_800F5520[1].roll, D_800F55A0, D_800F54D0);
    D_800F54D8.farClip = func_800D1904(
        D_800F5520[0].farClip, D_800F5520[1].farClip, D_800F55A0, D_800F54D0);
    D_800F54D8.nearClip = func_800D1904(
        D_800F5520[0].nearClip, D_800F5520[1].nearClip, D_800F55A0, D_800F54D0);
}

void func_800D236C(void)
{
    VECTOR start, end, result;
    start.vx = D_800F5520[0].position.vx >> 12;
    start.vy = D_800F5520[0].position.vy >> 12;
    start.vz = D_800F5520[0].position.vz >> 12;
    end.vx = D_800F5520[1].position.vx >> 12;
    end.vy = D_800F5520[1].position.vy >> 12;
    end.vz = D_800F5520[1].position.vz >> 12;
    func_800D1824(&start, &end, D_800F55A0, D_800F54D0, &result);
    D_800F54D8.position.vx = result.vx << 12;
    D_800F54D8.position.vy = result.vy << 12;
    D_800F54D8.position.vz = result.vz << 12;
    start.vx = D_800F5520[0].lookAt.vx >> 12;
    start.vy = D_800F5520[0].lookAt.vy >> 12;
    start.vz = D_800F5520[0].lookAt.vz >> 12;
    end.vx = D_800F5520[1].lookAt.vx >> 12;
    end.vy = D_800F5520[1].lookAt.vy >> 12;
    end.vz = D_800F5520[1].lookAt.vz >> 12;
    func_800D1824(&start, &end, D_800F55A0, D_800F54D0, &result);
    D_800F54D8.lookAt.vx = result.vx << 12;
    D_800F54D8.lookAt.vy = result.vy << 12;
    D_800F54D8.lookAt.vz = result.vz << 12;
    D_800F54D8.roll =
        func_800D18B4(D_800F5520[0].roll, D_800F5520[1].roll, D_800F55A0, D_800F54D0);
    D_800F54D8.farClip = func_800D18B4(
        D_800F5520[0].farClip, D_800F5520[1].farClip, D_800F55A0, D_800F54D0);
    D_800F54D8.nearClip = func_800D18B4(
        D_800F5520[0].nearClip, D_800F5520[1].nearClip, D_800F55A0, D_800F54D0);
}

void func_800D2518(void) { D_800F54D8 = D_800F5520[0]; }

void func_800D2560(void)
{
    int temp_s0 = D_800F55E8 != 0;

    if (D_800F55A0 != 0) {
        switch (D_800F55E8) {
        case 0:
            break;
        case 1:
            func_800D21C0();
            break;
        case 2:
            func_800D236C();
            break;
        case 3:
            func_800D2518();
            break;
        }
        if (D_800F54D0 <= D_800F55A0) {
            ++D_800F54D0;
            if (D_800F54D0 > D_800F55A0) {
                D_800F54D0 = 0;
                D_800F55A0 = 0;
                func_800D1E20(0);
            }
        }
    }
    if (D_800F5518 != 0) {
        func_800D206C();
    } else {
        D_800F54D8.unk2C = 0;
        D_800F54D8.unk28 = 0;
        D_800F54D8.unk24 = 0;
        D_800F54D8.unk20 = 0;
    }
    if (D_800F5518 != 0 || temp_s0) {
        func_800D1B80(&D_800F54D8);
    }
}

void func_800D268C(void) { D_800F5600 = 0; }

void func_800D2698(int count)
{
    int i;

    if (D_800F5600 != 0) {
        ++D_800F5600;
        return;
    }

    D_800F55FC = vs_main_allocHeapR(sizeof *D_800F55FC * count);
    D_800F55FC[0].previous = NULL;
    D_800F55FC[0].next = &D_800F55FC[1];

    for (i = 1; i < count - 1; ++i) {
        D_800F55FC[i].previous = &D_800F55FC[i - 1];
        D_800F55FC[i].next = &D_800F55FC[i + 1];
    }

    D_800F55F8 = 0;
    D_800F55F0 = count;
    D_800F5600 = 1;
    D_800F55FC[i].previous = &D_800F55FC[i - 1];
    D_800F55FC[i].next = NULL;
    D_800F55F4 = D_800F55FC;
}

void func_800D278C(void)
{
    if (D_800F5600 == 1) {
        if (D_800F55FC != NULL) {
            vs_main_freeHeapR(D_800F55FC);
            D_800F55FC = NULL;
        }
        D_800F5600 = 0;
        return;
    }
    --D_800F5600;
}

func_800D2904_t* func_800D27F0(D_800F53B8_t* arg0)
{
    func_800D2904_t* node = D_800F55F4;

    if (node == NULL) {
        func_800CE644(0x14);
    }

    func_800D6CCC(node->unk3C);

    node->unk74.fields.age = 0xFF;
    node->previous = NULL;
    ++D_800F55F8;
    D_800F55F4 = node->next;
    node->next = arg0->unk18;

    if (arg0->unk18 != NULL) {
        arg0->unk18->previous = node;
    }

    arg0->unk18 = node;
    ++arg0->unk8;

    do {
    } while (0);

    return node;
}

void func_800D2888(func_800D2904_t* arg0, D_800F53B8_t* arg1)
{
    if (arg0->next != NULL) {
        arg0->next->previous = arg0->previous;
    }

    if (arg0->previous != NULL) {
        arg0->previous->next = arg0->next;
    } else {
        arg1->unk18 = arg0->next;
    }

    arg0->next = D_800F55F4;
    D_800F55F4 = arg0;
    --D_800F55F8;
    --arg1->unk8;
}

void func_800D2904(D_800F53B8_t* arg0)
{
    func_800D2904_t* temp_a1;
    func_800D2904_t* var_a0;

    temp_a1 = arg0->unk18;
    var_a0 = temp_a1;

    if (temp_a1 == 0) {
        return;
    }

    while (var_a0->next != 0) {
        var_a0 = var_a0->next;
    }

    var_a0->next = D_800F55F4;
    D_800F55F4 = temp_a1;
    D_800F55F8 -= arg0->unk8;
    arg0->unk8 = 0;
}

void vs_battle_addVector(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2)
{
    arg2->vx = arg0->vx + arg1->vx;
    arg2->vy = arg0->vy + arg1->vy;
    arg2->vz = arg0->vz + arg1->vz;
}

void vs_battle_addVecToSvec(VECTOR* arg0, SVECTOR* arg1, VECTOR* arg2)
{
    arg2->vx = arg0->vx + arg1->vx;
    arg2->vy = arg0->vy + arg1->vy;
    arg2->vz = arg0->vz + arg1->vz;
}

void vs_battle_svecToVec(SVECTOR* arg0, VECTOR* arg1)
{
    arg1->vx = arg0->vx;
    arg1->vy = arg0->vy;
    arg1->vz = arg0->vz;
}

void vs_battle_vecToSvec(VECTOR* arg0, SVECTOR* arg1)
{
    arg1->vx = arg0->vx;
    arg1->vy = arg0->vy;
    arg1->vz = arg0->vz;
}

void func_800D2A38(func_800FA098_arg1* arg0, func_800D2904_t* arg1)
{
    if (arg0->flags & 0x40000) {
        ApplyRotMatrix(&arg0->unk2C, &arg0->unk34);
    } else {
        arg0->unk34.vx = arg0->unk2C.vx;
        arg0->unk34.vy = arg0->unk2C.vy;
        arg0->unk34.vz = arg0->unk2C.vz;
    }
    arg1->unkC = arg0->unk98.vx + arg0->unk34.vx * ONE;
    arg1->unk10 = arg0->unk98.vy + arg0->unk34.vy * ONE;
    arg1->unk14 = arg0->unk98.vz + arg0->unk34.vz * ONE;
}

/* Uniform integer between a and b (inclusive) using 30 random bits. */
#define RAND_UNIFORM_WIDE(a, b)                                                    \
    ((a) == (b)  ? (a)                                                             \
     : (b) < (a) ? (rand() + (rand() << 16)) % ((a) - (b) + 1) + (b)               \
                 : (rand() + (rand() << 16)) % ((b) - (a) + 1) + (a))

void func_800D2ADC(
    D_800F53B8_t* arg0, int event, int arg2, int arg3, func_800FB4C0_t* parent)
{
    int _[4] __attribute__((unused));
    int frame;
    int count;
    int i;
    int sample;
    int step;
    int angle;
    int x;
    int z;
    int value;
    func_800D2904_t* node;
    func_800D2904_t* first;
    MATRIX* matrix;
    int prevX;
    int prevZ;
    int range;
    func_800FA098_arg1* scratch = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA098_arg0* def = &D_800F569C->block5Data->unk4[event];

    scratch->flags = def->flags;
    scratch->unk28 = scratch->flags;
    scratch->unk168 = def->unkC8;
    scratch->unk16C = def->unkC9;

    if (arg2 != 0) {
        scratch->unk180 = arg2;
    } else if (def->transparencyCurve != 0) {
        scratch->unk180 = def->transparencyCurve;
    } else if (parent != NULL) {
        scratch->unk180 = parent->unk60;
    } else {
        scratch->unk180 = 4;
    }

    if (parent != NULL && arg3 == 0) {
        arg3 = parent->unk60_8 & 0xF;
    }

    frame = arg0->unk14_16;
    sample = def->unk16;
    if (frame % func_800CFE1C(def->unkC0, D_800F5330[sample]) != 0) {
        return;
    }

    gte_zrtr();

    matrix = &arg0->unk1C[scratch->unk168].unk38;
    sample = def->unk15;
    count = func_800CFE1C(def->unkBC, D_800F5330[sample]);
    if (count + D_800F55F8 >= D_800F55F0) {
        count = D_800F55F0 - D_800F55F8;
    }

    for (i = 0; i < count; ++i) {
        node = func_800D27F0(arg0);
        node->unk6A = scratch->unk168;
        node->unk6B = scratch->unk16C;
        func_800D6CF0((func_800D6CF_t*)node->unk3C, def->unk1, def->unk0);
    }

    sample = def->unk8;
    vs_battle_lerpVector(def->unk18, D_800F5330[sample], &scratch->unk98);
    first = node;

    switch (scratch->flags & 7) {
    case 0:
        break;
    case 1:
        vs_battle_addVecToSvec(&scratch->unk98, D_800F5310, &scratch->unk98);
        break;
    case 2:
        scratch->unk98.vx += matrix->t[0];
        scratch->unk98.vy += matrix->t[1];
        scratch->unk98.vz += matrix->t[2];
        break;
    case 4:
        if (parent != NULL) {
            scratch->unk98.vx += parent->unkC.vx >> 12;
            scratch->unk98.vy += parent->unkC.vy >> 12;
            scratch->unk98.vz += parent->unkC.vz >> 12;
        }
        break;
    }

    scratch->unk98.vx <<= 12;
    scratch->unk98.vy <<= 12;
    scratch->unk98.vz <<= 12;

    sample = def->unk9;
    vs_battle_lerpVector(def->unk24, D_800F5330[sample], &scratch->unkA8);
    node = first;
    sample = def->unk17;
    sample = func_800CFE1C(def->unk30, D_800F5330[sample]);
    SetRotMatrix(matrix);
    gte_zrtr();

    switch (scratch->flags & 0x38) {
    case 0:
        scratch->unkD8.vx = (scratch->unkA8.vx * sample) >> 12;
        scratch->unkD8.vy = (scratch->unkA8.vy * sample) >> 12;
        scratch->unkD8.vz = (scratch->unkA8.vz * sample) >> 12;
        for (i = 0; i < count; ++i) {
            angle = rand();
            scratch->unk170 = rsin(angle);
            scratch->unk178 = rcos(angle);
            angle = rand();
            scratch->unk174 = rsin(angle);
            scratch->unk17C = rcos(angle);
            switch (scratch->flags & 0x1800) {
            case 0:
                scratch->unk2C.vx =
                    vs_battle_randUniformInt(scratch->unkA8.vx, scratch->unkD8.vx);
                scratch->unk2C.vy =
                    vs_battle_randUniformInt(scratch->unkA8.vy, scratch->unkD8.vy);
                scratch->unk2C.vz =
                    vs_battle_randUniformInt(scratch->unkA8.vz, scratch->unkD8.vz);
                goto scale0;
            case 0x800:
            case 0x1000:
                vs_battle_vecToSvec(&scratch->unkA8, &scratch->unk2C);
            scale0:
                scratch->unk2C.vx =
                    (((scratch->unk2C.vx * scratch->unk178) >> 12) * scratch->unk17C)
                    >> 12;
                scratch->unk2C.vy =
                    (((scratch->unk2C.vy * scratch->unk178) >> 12) * scratch->unk174)
                    >> 12;
                scratch->unk2C.vz = (scratch->unk2C.vz * scratch->unk170) >> 12;
                break;
            }
            func_800D2A38(scratch, node);
            node = node->next;
        }
        break;

    case 8:
        scratch->unkD8.vx = (scratch->unkA8.vx * sample) >> 12;
        scratch->unkD8.vy = (scratch->unkA8.vy * sample) >> 12;
        scratch->unkD8.vz = (scratch->unkA8.vz * sample) >> 12;
        for (i = 0; i < count; ++i) {
            switch (scratch->flags & 0x1800) {
            case 0:
                angle = rand();
                if (angle & 1) {
                    scratch->unk2C.vx =
                        vs_battle_randUniformInt(scratch->unkA8.vx, scratch->unkD8.vx);
                } else {
                    scratch->unk2C.vx =
                        vs_battle_randUniformInt(-scratch->unkA8.vx, -scratch->unkD8.vx);
                }
                if (angle & 2) {
                    scratch->unk2C.vy =
                        vs_battle_randUniformInt(scratch->unkA8.vy, scratch->unkD8.vy);
                } else {
                    scratch->unk2C.vy =
                        vs_battle_randUniformInt(-scratch->unkA8.vy, -scratch->unkD8.vy);
                }
                if (angle & 4) {
                    scratch->unk2C.vz =
                        vs_battle_randUniformInt(scratch->unkA8.vz, scratch->unkD8.vz);
                } else {
                    scratch->unk2C.vz =
                        vs_battle_randUniformInt(-scratch->unkA8.vz, -scratch->unkD8.vz);
                }
                break;
            case 0x800:
                switch (rand() % 6) {
                case 0:
                    scratch->unk2C.vx = scratch->unkA8.vx;
                    goto face_x;
                case 1:
                    scratch->unk2C.vx = -scratch->unkA8.vx;
                face_x:
                    scratch->unk2C.vy =
                        vs_battle_randUniformInt(scratch->unkA8.vy, -scratch->unkA8.vy);
                    scratch->unk2C.vz =
                        vs_battle_randUniformInt(scratch->unkA8.vz, -scratch->unkA8.vz);
                    break;
                case 2:
                    scratch->unk2C.vy = scratch->unkA8.vy;
                    goto face_y;
                case 3:
                    scratch->unk2C.vy = -scratch->unkA8.vy;
                face_y:
                    scratch->unk2C.vx =
                        vs_battle_randUniformInt(scratch->unkA8.vx, -scratch->unkA8.vx);
                    scratch->unk2C.vz =
                        vs_battle_randUniformInt(scratch->unkA8.vz, -scratch->unkA8.vz);
                    break;
                case 4:
                    scratch->unk2C.vz = scratch->unkA8.vz;
                    goto face_z;
                case 5:
                    scratch->unk2C.vz = -scratch->unkA8.vz;
                face_z:
                    scratch->unk2C.vx =
                        vs_battle_randUniformInt(scratch->unkA8.vx, -scratch->unkA8.vx);
                    scratch->unk2C.vy =
                        vs_battle_randUniformInt(scratch->unkA8.vy, -scratch->unkA8.vy);
                    break;
                }
                break;
            case 0x1000:
                D_800EC328 = (D_800EC328 + 1) & 7;
                scratch->unk2C.vx =
                    (D_800EC328 & 1) ? scratch->unkA8.vx : -scratch->unkA8.vx;
                scratch->unk2C.vy =
                    (D_800EC328 & 2) ? scratch->unkA8.vy : -scratch->unkA8.vy;
                scratch->unk2C.vz =
                    (D_800EC328 & 4) ? scratch->unkA8.vz : -scratch->unkA8.vz;
                break;
            }
            func_800D2A38(scratch, node);
            node = node->next;
        }
        break;

    case 16:
        scratch->unkD8.vx = (scratch->unkA8.vx * sample) >> 12;
        scratch->unkD8.vy = scratch->unkA8.vy;
        scratch->unkD8.vz = (scratch->unkA8.vz * sample) >> 12;
        for (i = 0; i < count; ++i) {
            angle = rand();
            scratch->unk170 = rsin(angle);
            scratch->unk178 = rcos(angle);
            switch (scratch->flags & 0x1800) {
            case 0:
                scratch->unk2C.vx =
                    vs_battle_randUniformInt(scratch->unkA8.vx, scratch->unkD8.vx);
                scratch->unk2C.vz =
                    vs_battle_randUniformInt(scratch->unkA8.vz, scratch->unkD8.vz);
                goto scale16;
            case 0x800:
            case 0x1000:
                scratch->unk2C.vx = scratch->unkA8.vx;
                scratch->unk2C.vz = scratch->unkA8.vz;
            scale16:
                scratch->unk2C.vy = vs_gte_rsqrt(
                    RAND_UNIFORM_WIDE(scratch->unkA8.vy * scratch->unkA8.vy, 0));
                scratch->unk2C.vx =
                    (((scratch->unk2C.vx * scratch->unk178) >> 12) * scratch->unk2C.vy)
                    / scratch->unkA8.vy;
                scratch->unk2C.vz =
                    (((scratch->unk2C.vz * scratch->unk170) >> 12) * scratch->unk2C.vy)
                    / scratch->unkA8.vy;
                break;
            }
            func_800D2A38(scratch, node);
            node = node->next;
        }
        break;

    case 24:
        scratch->unkD8.vx = (scratch->unkA8.vx * sample) >> 12;
        scratch->unkD8.vz = (scratch->unkA8.vz * sample) >> 12;
        for (i = 0; i < count; ++i) {
            angle = rand();
            scratch->unk170 = rsin(angle);
            scratch->unk178 = rcos(angle);
            switch (scratch->flags & 0x1800) {
            case 0:
                scratch->unk2C.vx =
                    vs_gte_rsqrt(RAND_UNIFORM_WIDE(scratch->unkA8.vx * scratch->unkA8.vx,
                        scratch->unkD8.vx * scratch->unkD8.vx));
                scratch->unk2C.vz =
                    vs_gte_rsqrt(RAND_UNIFORM_WIDE(scratch->unkA8.vz * scratch->unkA8.vz,
                        scratch->unkD8.vz * scratch->unkD8.vz));
                goto scale24;
            case 0x800:
            case 0x1000:
                scratch->unk2C.vx = scratch->unkA8.vx;
                scratch->unk2C.vz = scratch->unkA8.vz;
            scale24:
                scratch->unk2C.vx = (scratch->unk2C.vx * scratch->unk178) >> 12;
                scratch->unk2C.vy = vs_battle_randUniformInt(scratch->unkA8.vy, 0);
                scratch->unk2C.vz = (scratch->unk2C.vz * scratch->unk170) >> 12;
                break;
            }
            func_800D2A38(scratch, node);
            node = node->next;
        }
        break;

    case 32:
        scratch->unkD8.vx = (scratch->unkA8.vx * sample) >> 12;
        scratch->unkD8.vz = (scratch->unkA8.vz * sample) >> 12;
        for (i = 0; i < count; ++i) {
            angle = rand();
            scratch->unk170 = rsin(angle);
            scratch->unk178 = rcos(angle);
            switch (scratch->flags & 0x1800) {
            case 0:
                scratch->unk2C.vx =
                    vs_gte_rsqrt(RAND_UNIFORM_WIDE(scratch->unkA8.vx * scratch->unkA8.vx,
                        scratch->unkD8.vx * scratch->unkD8.vx));
                scratch->unk2C.vz =
                    vs_gte_rsqrt(RAND_UNIFORM_WIDE(scratch->unkA8.vz * scratch->unkA8.vz,
                        scratch->unkD8.vz * scratch->unkD8.vz));
                goto scale32;
            case 0x800:
            case 0x1000:
                scratch->unk2C.vx = scratch->unkA8.vx;
                scratch->unk2C.vz = scratch->unkA8.vz;
            scale32:
                scratch->unk2C.vy = 0;
                scratch->unk2C.vx = (scratch->unk2C.vx * scratch->unk178) >> 12;
                scratch->unk2C.vz = (scratch->unk2C.vz * scratch->unk170) >> 12;
                break;
            }
            func_800D2A38(scratch, node);
            node = node->next;
        }
        break;

    case 40:
        scratch->unk184 = 4;
        scratch->unk188 = 4;
        goto ring;

    case 48:
        scratch->unk184 = def->unkCA;
        if (scratch->unk184 == 0) {
            scratch->unk184 = 1;
        }
        scratch->unk188 = def->unkCB;
        if (scratch->unk188 == 0) {
            scratch->unk188 = scratch->unk184;
        }
    ring:
        step = 0x1000 / scratch->unk184;
        if ((scratch->flags & 0x1800) != 0x1000) {
            D_800EC328 %= scratch->unk188;
            angle = D_800EC328 * step + 0x200;
            prevX = (rcos(angle) * scratch->unkA8.vx) >> 12;
            prevZ = (rsin(angle) * scratch->unkA8.vz) >> 12;
        }
        for (i = 0; i < count; ++i) {
            range = 0x1194 - sample;
            D_800EC328 = (D_800EC328 + 1) % scratch->unk188;
            angle = D_800EC328 * step + 0x200;
            x = (rcos(angle) * scratch->unkA8.vx) >> 12;
            z = (rsin(angle) * scratch->unkA8.vz) >> 12;
            if ((scratch->flags & 0x1800) == 0x1000) {
                scratch->unk2C.vx = x;
                scratch->unk2C.vz = z;
            } else {
                value = rand() >> 3;
                scratch->unk2C.vx = (((x - prevX) * value) >> 12) + prevX;
                scratch->unk2C.vz = (((z - prevZ) * value) >> 12) + prevZ;
                prevX = x;
                prevZ = z;
                if ((scratch->flags & 0x1800) != 0x800) {
                    value = SquareRoot12(((rand() * range) >> 15) + sample);
                    if (value > 0x1000) {
                        value = 0x1000;
                    }
                    scratch->unk2C.vx = (scratch->unk2C.vx * value) >> 12;
                    scratch->unk2C.vz = (scratch->unk2C.vz * value) >> 12;
                }
            }
            scratch->unk2C.vy = 0;
            func_800D2A38(scratch, node);
            node = node->next;
        }
        break;
    }

    sample = def->unkC;
    vs_battle_lerp2DVector(def->unk94[2], D_800F5330[sample], scratch->unk118);
    scratch->unk118[0] <<= 5;
    scratch->unk118[1] <<= 5;
    sample = def->unkB;
    vs_battle_lerpVector(def->unk34[1], D_800F5330[sample], &scratch->unkC8);
    sample = def->unkA;
    vs_battle_lerpVector(def->unk34[0], D_800F5330[sample], &scratch->unkE8);
    node = first;

    switch (scratch->flags & 0xE000) {
    case 0x4000:
        if (arg0->unkD1C.unkC.unk0 == 4) {
            func_800A1AF8(((u_char*)&arg0->unkD1C.unkC.unk4)[0],
                ((u_char*)&arg0->unkD1C.unkC.unk4)[2], &scratch->unk2C, 0);
        } else {
            scratch->unk2C = *(SVECTOR*)&arg0->unkD1C.unkC.unk4;
        }
        goto aim;
    case 0x6000:
        if (arg0->unkD1C.unk24.unk0 == 4) {
            func_800A1AF8(((u_char*)&arg0->unkD1C.unk24.unk4)[0],
                ((u_char*)&arg0->unkD1C.unk24.unk4)[2], &scratch->unk2C, 0);
        } else {
            scratch->unk2C = *(SVECTOR*)&arg0->unkD1C.unk24.unk4;
        }
    aim:
        vs_battle_svecToVec(&scratch->unk2C, &scratch->unk34);
        scratch->unk44.vx = scratch->unk98.vx >> 12;
        scratch->unk44.vy = scratch->unk98.vy >> 12;
        scratch->unk44.vz = scratch->unk98.vz >> 12;
        vs_battle_lookAt(&scratch->unk44, &scratch->unk34, &scratch->unk64);
        matrix = &scratch->unk64;
    case 0:
        for (i = 0; i < count; ++i) {
            scratch->unk2C.vx =
                scratch->unkE8.vx
                + vs_battle_randUniformInt(scratch->unkC8.vx, -scratch->unkC8.vx);
            scratch->unk2C.vy =
                scratch->unkE8.vy
                + vs_battle_randUniformInt(scratch->unkC8.vy, -scratch->unkC8.vy);
            scratch->unk2C.vz =
                scratch->unkE8.vz
                + vs_battle_randUniformInt(scratch->unkC8.vz, -scratch->unkC8.vz);
            RotMatrix_gte(&scratch->unk2C, (MATRIX*)scratch);
            gte_SetRotMatrix(scratch);
            *(int*)&scratch->unk2C = 0;
            scratch->unk2C.vz = 0x1000;
            RotTrans(&scratch->unk2C, &scratch->unkB8, &scratch->unkB8.pad);
            if (scratch->flags & 0x40000) {
                vs_battle_vecToSvec(&scratch->unkB8, &scratch->unk2C);
                gte_SetRotMatrix(matrix);
                ApplyRotMatrix(&scratch->unk2C, &scratch->unkB8);
            }
            scratch->unk120 =
                vs_battle_randUniformInt(scratch->unk118[0], scratch->unk118[1]);
            node->unk18[0] = (scratch->unkB8.vx * scratch->unk120) >> 12;
            node->unk18[1] = (scratch->unkB8.vy * scratch->unk120) >> 12;
            node->unk18[2] = (scratch->unkB8.vz * scratch->unk120) >> 12;
            node = node->next;
        }
        break;
    case 0x8000:
        for (i = 0; i < count; ++i) {
            scratch->unk2C.vx =
                scratch->unkE8.vx
                + vs_battle_randUniformInt(scratch->unkC8.vx, -scratch->unkC8.vx);
            scratch->unk2C.vy =
                scratch->unkE8.vy
                + vs_battle_randUniformInt(scratch->unkC8.vy, -scratch->unkC8.vy);
            scratch->unk2C.vz =
                scratch->unkE8.vz
                + vs_battle_randUniformInt(scratch->unkC8.vz, -scratch->unkC8.vz);
            RotMatrix_gte(&scratch->unk2C, (MATRIX*)scratch);
            gte_SetRotMatrix(scratch);
            *(int*)&scratch->unk2C = 0;
            scratch->unk2C.vz = 0x1000;
            RotTrans(&scratch->unk2C, &scratch->unkB8, &scratch->unkB8.pad);
            gte_SetRotMatrix(matrix);
            vs_battle_vecToSvec(&scratch->unkB8, &scratch->unk2C);
            RotTrans(&scratch->unk2C, &scratch->unkB8, &scratch->unkB8.pad);
            scratch->unk120 =
                vs_battle_randUniformInt(scratch->unk118[0], scratch->unk118[1]);
            node->unk18[0] = (scratch->unkB8.vx * scratch->unk120) >> 12;
            node->unk18[1] = (scratch->unkB8.vy * scratch->unk120) >> 12;
            node->unk18[2] = (scratch->unkB8.vz * scratch->unk120) >> 12;
            node = node->next;
        }
        break;
    case 0x2000:
        for (i = 0; i < count; ++i) {
            scratch->unkB8.vx = (scratch->unk98.vx - node->unkC) >> 12;
            scratch->unkB8.vy = (scratch->unk98.vy - node->unk10) >> 12;
            scratch->unkB8.vz = (scratch->unk98.vz - node->unk14) >> 12;
            scratch->unk120 =
                vs_battle_randUniformInt(scratch->unk118[0], scratch->unk118[1]);
            if (scratch->unkB8.vx != 0 || scratch->unkB8.vy != 0
                || scratch->unkB8.vz != 0) {
                VectorNormal(&scratch->unkB8, &scratch->unkB8);
                node->unk18[0] = (scratch->unkB8.vx * scratch->unk120) >> 12;
                node->unk18[1] = (scratch->unkB8.vy * scratch->unk120) >> 12;
                node->unk18[2] = (scratch->unkB8.vz * scratch->unk120) >> 12;
            } else {
                node->unk18[1] = scratch->unk120;
                node->unk18[2] = 0;
                node->unk18[0] = 0;
            }
            node = node->next;
        }
        break;
    }

    sample = def->unkD;
    vs_battle_lerpSvector(def->unk34[2], D_800F5330[sample], &scratch->unkF8);
    vs_battle_lerpSvector(def->unk34[3], D_800F5330[sample], &scratch->unk100);
    sample = def->unkE;
    vs_battle_lerpSvector(def->unk34[4], D_800F5330[sample], &scratch->unk108);
    vs_battle_lerpSvector(def->unk34[5], D_800F5330[sample], &scratch->unk110);
    node = first;
    for (i = 0; i < count; ++i) {
        node->unk24[0] = vs_battle_randUniformInt(scratch->unkF8.vx, scratch->unk100.vx);
        node->unk24[1] = vs_battle_randUniformInt(scratch->unkF8.vy, scratch->unk100.vy);
        node->unk24[2] = vs_battle_randUniformInt(scratch->unkF8.vz, scratch->unk100.vz);
        node->unk30[0] = vs_battle_randUniformInt(scratch->unk108.vx, scratch->unk110.vx);
        node->unk30[1] = vs_battle_randUniformInt(scratch->unk108.vy, scratch->unk110.vy);
        node->unk30[2] = vs_battle_randUniformInt(scratch->unk108.vz, scratch->unk110.vz);
        node = node->next;
    }

    sample = def->unk12;
    vs_battle_lerp2DVector(def->unk94[0], D_800F5330[sample], scratch->unk124);
    sample = def->unk13;
    vs_battle_lerp2DVector(def->unk94[1], D_800F5330[sample], scratch->unk12C);
    sample = def->unk14;
    vs_battle_lerp2DVector(def->unk94[4], D_800F5330[sample], scratch->unk134);
    node = first;
    for (i = 0; i < count; ++i) {
        node->unk8 = vs_battle_randUniformInt(scratch->unk124[0], scratch->unk124[1]);
        node->unkA = vs_battle_randUniformInt(scratch->unk12C[0], scratch->unk12C[1]);
        node->lifetime = vs_battle_randUniformInt(scratch->unk134[0], scratch->unk134[1]);
        node = node->next;
    }

    sample = def->unkF;
    vs_battle_lerpSvector(def->unk34[6], D_800F5330[sample], &scratch->unk13C);
    sample = def->unk10;
    vs_battle_lerpSvector(def->unk34[7], D_800F5330[sample], &scratch->unk144);
    node = first;

    switch (scratch->flags & 0x1C0) {
    case 0:
    case 0x40:
        for (i = 0; i < count; ++i) {
            node->unk62[0] = scratch->unk13C.vx;
            node->unk62[1] = scratch->unk13C.vy;
            node->unk62[2] = scratch->unk13C.vz;
            node = node->next;
        }
        break;
    case 0xC0:
        for (i = 0; i < count; ++i) {
            node->unk62[0] =
                arg0->unk1C[scratch->unk16C].unk38.t[0] + scratch->unk13C.vx
                + vs_battle_randUniformInt(scratch->unk144.vx, -scratch->unk144.vy);
            node->unk62[1] =
                arg0->unk1C[scratch->unk16C].unk38.t[1] + scratch->unk13C.vy
                + vs_battle_randUniformInt(scratch->unk144.vy, -scratch->unk144.vy);
            node->unk62[2] =
                arg0->unk1C[scratch->unk16C].unk38.t[2] + scratch->unk13C.vz
                + vs_battle_randUniformInt(scratch->unk144.vz, -scratch->unk144.vz);
            node = node->next;
        }
        break;
    case 0x80:
    case 0x140:
        for (i = 0; i < count; ++i) {
            node->unk62[2] = 0;
            node->unk62[1] = 0;
            node->unk62[0] = 0;
            node = node->next;
        }
        break;
    }

    sample = def->unk11;
    vs_battle_lerp2DVector(def->unk94[3], D_800F5330[sample], scratch->unk14C);
    node = first;
    scratch->unk154.packed = *(int*)&def->rCurve;
    scratch->unk154.fields.age = node->unk74.fields.age;
    for (i = 0; i < count; ++i) {
        node->unk5C = scratch->flags;
        value = vs_battle_randUniformInt(scratch->unk14C[0], scratch->unk14C[1]);
        node->unk74.packed = scratch->unk154.packed;
        node->unk70 = value;
        *(u_short*)&node->endEvent = *(u_short*)&def->unk2;
        node->unk60_0 = scratch->unk180;
        node->unk60_8 = arg3;
        node = node->next;
    }
}

void func_800D46DC(int arg0, D_800F53B8_t* arg1)
{
    if (arg0) {
        arg1->unkA = func_800D5198(arg1);
    } else {
        arg1->unkA += 2;
    }
}

int func_800D4720(D_800F53B8_t* arg0)
{
    arg0->unkA = func_800D5198(arg0);
    return 0;
}

int func_800D474C(D_800F53B8_t* arg0)
{
    arg0->unkA = func_800D5198(arg0);
    return 1;
}

int func_800D4778(D_800F53B8_t* arg0)
{
    D_800F53B8_t2 sp10;

    sp10.unk14 = arg0->unkC;
    sp10.unk18 = func_800D5198(arg0);
    sp10.unk0 = &arg0->unkD1C;
    func_800CE83C(&sp10);
    return 1;
}

int func_800D47C0(D_800F53B8_t* arg0 __attribute__((unused))) { return 2; }

int func_800D47C8(D_800F53B8_t* arg0)
{
    D_800F5610 = func_800D5170(arg0);
    return 1;
}

int func_800D47F4(D_800F53B8_t* arg0)
{
    int temp_s0;
    int temp_s2;

    temp_s2 = func_800D5170(arg0);
    temp_s0 = func_800D5198(arg0);
    temp_s0 = temp_s0 + (func_800D5198(arg0) << 0x10);

    if (arg0->unkD1C.unk3C != 0) {
        temp_s0 = arg0->unkD1C.unk3C;
    }

    func_800CF694(arg0, D_800EC324[temp_s2], temp_s0);
    return 1;
}

int func_800D487C(D_800F53B8_t* arg0)
{
    func_800D46DC(arg0->unkD1C.unk34 == 0, arg0);
    return 1;
}

int func_800D48A4(D_800F53B8_t* arg0)
{
    func_800D55A4(arg0, func_800D5170(arg0) & 0xFF, 0);
    arg0->unkA = 0xB7;
    return 1;
}

int func_800D48E4(D_800F53B8_t* arg0)
{
    func_800D46DC(D_800F522C == 0, arg0);
    return 1;
}

int func_800D4910(D_800F53B8_t* arg0)
{
    func_800D4910_t* var_s0 = arg0->unkD1C.unk34;

    while (var_s0 != 0) {
        func_800D4910_t* s1 = var_s0->next;
        if (var_s0->renderer(var_s0, 2, 0) == 0) {
            func_800CF70C(arg0, var_s0);
        }
        var_s0 = s1;
    }
    return 1;
}

int func_800D4984(D_800F53B8_t* arg0)
{
    func_800D0D08(arg0);
    return 1;
}

int func_800D49A4(D_800F53B8_t* arg0)
{
    int i;

    if (((u_short)(arg0->unkD1C.unk38 - 6) < 16) || (arg0->unkD1C.unk38 == 0x21)
        || (arg0->unkD1C.unk38 == 0x24)) {
        for (i = 0; i < D_800F569C->block9Data->unk15; ++i) {
            arg0->unk1C[i].unk20 = -0x80;
        }
    } else if ((arg0->unkD1C.unk38 == 0x38) && (arg0->unk10[3] == 0x2B)) {
        for (i = 0; i < D_800F569C->block9Data->unk15; ++i) {
            arg0->unk1C[i].unk20 = 0x80;
        }
    }
    return 1;
}

int func_800D4A94(D_800F53B8_t* arg0)
{
    func_800CFEF0(arg0);
    return 1;
}

int func_800D4AB4(D_800F53B8_t* arg0)
{
    if (D_800F522C < 4) {
        arg0->unk10[3] = D_800EC32C[D_800F522C];
    }
    return 1;
}

int func_800D4AEC(D_800F53B8_t* arg0)
{
    arg0->unk10[func_800D5170(arg0)] = func_800D5198(arg0);
    return 1;
}

int func_800D4B34(D_800F53B8_t* arg0)
{
    func_800D46DC(arg0->unk10[func_800D5170(arg0)] == (func_800D5198(arg0)), arg0);
    return 1;
}

int func_800D4B90(D_800F53B8_t* arg0)
{
    func_800D46DC(arg0->unk8 == func_800D5170(arg0), arg0);
    return 1;
}

int func_800D4BD0(D_800F53B8_t* arg0)
{
    func_800D2ADC(arg0, arg0->unk10[func_800D5170(arg0)], 0, 0, NULL);
    return 1;
}

void func_800D52A4(func_800D2904_t*);
void func_800D6E24(void);

int func_800D4C18(D_800F53B8_t* arg0)
{
    func_800D2904_t* next = arg0->unk18;
    func_800D2904_t* node;

    func_800D52A4(next);
    /* The original caller supplies arguments to this argument-free wrapper. */
    ((void (*)())func_800D6E24)(arg0->unk18, (void*)0x1F80015C);
    node = next;
    while (next != NULL) {
        next = node->next;
        ++node->unk74.fields.age;
        if (node->tickEvent != 0) {
            func_800D2ADC(arg0, node->tickEvent - 1, 0, 0, (void*)node);
        }
        if (node->lifetime == -1) {
            if (((u_char*)node)[0x42] == 0) {
                if (node->endEvent != 0) {
                    func_800D2ADC(arg0, node->endEvent - 1, 0, 0, (void*)node);
                }
                func_800D2888(node, arg0);
            }
        } else if (--node->lifetime == 0) {
            if (node->endEvent != 0) {
                func_800D2ADC(arg0, node->endEvent - 1, 0, 0, (void*)node);
            }
            func_800D2888(node, arg0);
        }
        node = next;
    }
    return 1;
}

int func_800D4D44(D_800F53B8_t* arg0 __attribute__((unused)))
{
    func_800D78F0();
    return 1;
}

int func_800D4D64(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk0.unk0 == 4) {
        func_8006CDB8((u_char)arg0->unkD1C.unk0.unk4.unk0);
    }
    return 1;
}

int func_800D4D98(D_800F53B8_t* arg0 __attribute__((unused)))
{
    D_800F522C = 0;
    return 1;
}

int func_800D4DA8(D_800F53B8_t* arg0 __attribute__((unused))) { return 1; }

int func_800D4DB0(D_800F53B8_t* arg0)
{
    u_char index = arg0->unk10[func_800D5170(arg0)];

    if (arg0->previous == NULL && index < 4) {
        int id = D_800F569C->block9Data->unk16[index];
        if (id != 0 && D_800F569C->block3Data != NULL
            && id < D_800F569C->block3Data->count) {
            index = id - 1;
        }
    }
    func_800D55A4(arg0, index, 0);
    return 1;
}

int func_800D4E5C(D_800F53B8_t* arg0)
{
    func_800D6AEC(arg0, func_800D5198(arg0));
    return 1;
}

int func_800D4E90(D_800F53B8_t* arg0)
{
    func_800D46DC(arg0->unkD1C.unk30->unk4 == 0, arg0);
    return 1;
}

int func_800D4EC0(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk30 != NULL) {
        vs_main_freeHeapR(arg0->unkD1C.unk30);
        arg0->unkD1C.unk30 = NULL;
    }
    return 1;
}

int func_800D4F00(D_800F53B8_t* arg0)
{
    u_char first = func_800D5170(arg0);
    u_char second = func_800D5170(arg0);
    u_char third = func_800D5170(arg0);
    func_800FA098_arg0* dst = &D_800F569C->block5Data->unk4[first & 0x3F];

    dst->rCurve = (first >> 6) + ((second & 0xF) << 2);
    dst->gCurve = (second >> 4) + ((third & 3) << 4);
    dst->bCurve = third >> 2;
    return 1;
}

int func_800D4FB4(D_800F53B8_t* arg0)
{
    int i;

    for (i = 0; i < 2; ++i) {
        func_800FA098_arg0* dst = &D_800F569C->block5Data->unk4[i];
        dst->rCurve = D_800EC330[arg0->unkD1C.unk18.unk2][i][0];
        dst->gCurve = D_800EC330[arg0->unkD1C.unk18.unk2][i][1];
        dst->bCurve = D_800EC330[arg0->unkD1C.unk18.unk2][i][2];
    }

    return 1;
}

int func_800D5048(D_800F53B8_t* arg0)
{
    if (arg0->previous != 0) {
        --arg0->previous->unk14_11;
    }
    return 1;
}

int func_800D5088(D_800F53B8_t* arg0);
int func_800D5088(D_800F53B8_t* arg0)
{
    int i;

    for (i = 0; i < 5; i++) {
        func_800FA098_arg0* dst =
            &D_800F569C->block5Data->unk4[D_800EC368[arg0->unkD1C.unk18.unk2][i][3]];
        dst->rCurve = D_800EC368[arg0->unkD1C.unk18.unk2][i][0];
        dst->gCurve = D_800EC368[arg0->unkD1C.unk18.unk2][i][1];
        dst->bCurve = D_800EC368[arg0->unkD1C.unk18.unk2][i][2];
    }
    return 1;
}

int func_800D5150(D_800F53B8_t* arg0 __attribute__((unused)))
{
    return func_800CE644(0x1E);
}

u_char func_800D5170(D_800F53B8_t* arg0) { return arg0->unkC[arg0->unkA++]; }

u_short func_800D5198(D_800F53B8_t* arg0)
{
    u_char lo = func_800D5170(arg0);
    u_char hi = func_800D5170(arg0);
    return lo | (hi << 8);
}

int func_800D51D8(D_800F53B8_t* arg0)
{
    int miscIndex;

    do {
        miscIndex = D_800EC3F4[func_800D5170(arg0)](arg0);
        if (miscIndex == 2) {
            return 0;
        }
    } while (miscIndex == 1);
    return 1;
}

void func_800D5260(D_800F5620_t* arg0) { D_800F5620 = *arg0; }

void func_800D5294(int* arg0) { D_800F5618 = *arg0; }

typedef struct {
    short mass;
    short gravityScale;
    int x, y, z;
    int vx, vy, vz;
    int fx, fy, fz;
    int ax, ay, az;
} effectMotionState;

typedef struct {
    char prefix[0x62];
    short targetX, targetY, targetZ;
    char padding[8];
    int attraction;
} effectAttractionView;

void func_800D52A4(func_800D2904_t* node)
{
    VECTOR direction;
    effectMotionState* state;
    int damping;
    int drag = D_800F5618;
    int gravityX = D_800F5620.unk0;
    int gravityY = D_800F5620.unk4;
    int gravityZ = D_800F5620.unk8;

    for (; node != NULL; node = node->next) {
        state = (effectMotionState*)&node->unk8;
        damping = node->unk8 - drag;
        state->vx = (state->vx * damping + (state->fx << 12)) / node->unk8
                  + ((gravityX * state->gravityScale) >> 12);
        state->x += state->vx;
        state->vy = (state->vy * damping + (state->fy << 12)) / node->unk8
                  + ((gravityY * state->gravityScale) >> 12);
        state->y += state->vy;
        state->vz = (state->vz * damping + (state->fz << 12)) / node->unk8
                  + ((gravityZ * state->gravityScale) >> 12);
        state->z += state->vz;
        damping = ((effectAttractionView*)node)->attraction;
        if (damping != 0) {
            direction.vx = ((effectAttractionView*)node)->targetX - (state->x >> 12);
            direction.vy = ((effectAttractionView*)node)->targetY - (state->y >> 12);
            direction.vz = ((effectAttractionView*)node)->targetZ - (state->z >> 12);
            if (direction.vx != 0 || direction.vy != 0 || direction.vz != 0) {
                VectorNormal(&direction, &direction);
                direction.vx = (direction.vx * damping) >> 12;
                direction.vy = (direction.vy * damping) >> 12;
                direction.vz = (direction.vz * damping) >> 12;
            }
            state->fx += state->ax + direction.vx;
            state->fy += state->ay + direction.vy;
            state->fz += state->az + direction.vz;
        } else {
            state->fx += state->ax;
            state->fy += state->ay;
            state->fz += state->az;
        }
    }
}

void* _getPFileBlock3section(pFileBlock3* arg0, int arg1)
{
    return (char*)arg0 + arg0->offsets[arg1];
}

void* func_800D5564(pFileBlock3* arg0, int arg1, int arg2)
{
    func_800D55A4_t* entry = _getPFileBlock3section(arg0, arg1);
    return (char*)arg0 + entry->unk4[arg2].unk2;
}

void func_800D55A4(D_800F53B8_t* arg0, int arg1, int arg2)
{
    func_800D55A4_t* entry = _getPFileBlock3section(D_800F569C->block3Data, arg1);
    D_800F53B8_t4* p;
    int count = 0;
    int i;

    if (arg0->unkD1C.unk30 != NULL) {
        vs_main_freeHeapR(arg0->unkD1C.unk30);
    }

    arg0->unkD1C.unk30 = vs_main_allocHeapR(entry->count * 16 + 8);
    p = arg0->unkD1C.unk30;
    p->unk0 = entry->count;
    p->unk2 = 0;
    p->unk4 = 0;

    for (i = 0; i < p->unk0; ++i) {
        p->unk8[i].unk0 = func_800D5564(D_800F569C->block3Data, arg1, i);
        p->unk8[i].unk4 = entry->unk4[i].unk0;

        if (p->unk8[i].unk4.unk0_0 == 3) {
            ++count;
        }

        p->unk8[i].unk6 = -1;
        *(int*)&p->unk8[i].unk8 = 0;
        p->unk8[i].unkC = 0;
        func_800D5780(&p->unk8[i]);
        p->unk4 |= 1 << i;
    }

    p->unk1 = count ? 2 : 0;
}

void func_800D5700(func_800D5780_t* arg0)
{
    func_800D57FC_t* base = (func_800D57FC_t*)arg0->unk0;
    arg0->unkC = base[arg0->unk6].unk0_20;
    arg0->unkA = base[arg0->unk6].unk0_8;
}

void func_800D5738(func_800D5780_t* arg0)
{
    arg0->unkA =
        func_800D12D8((((func_800D57FC_t2*)&arg0->unk0[arg0->unk6 * 2 + 1])->unk0_4));
}

int func_800D5780(func_800D5780_t* arg0)
{
    if (arg0->unk6 + 1 >= arg0->unk4.unk0_8) {
        return 0;
    }
    arg0->unk6++;
    switch (arg0->unk4.unk0_0) {
    case 1:
        func_800D5700(arg0);
        break;
    case 0xD:
        func_800D5738(arg0);
        break;
    }
    return 1;
}

int func_800D57FC(D_800F53B8_t* arg0, func_800D5780_t* arg1)
{
    func_800D57FC_t* e = (func_800D57FC_t*)arg1->unk0;
    int ret = 1;
    int key = e[arg1->unk6].unk0_0;
    int cur = arg0->unkD1C.unk30->unk2;

    if (cur < key) {
        return ret;
    }
    func_800D1104(arg1->unk8);
    func_800D2ADC(
        arg0, e[arg1->unk6].unk0_20, e[arg1->unk6].unk0_26, e[arg1->unk6].unk0_16, NULL);
    ++arg1->unk8;
    if (!(arg0->unkD1C.unk30->unk1 & 1)) {
        --arg1->unkA;
    }
    if (arg1->unkA == 0) {
        ret = func_800D5780(arg1);
        arg1->unk8 = 0;
    }
    return ret;
}

void func_80046578(int);

int func_800D5904(D_800F53B8_t* arg0, func_800D5780_t* arg1)
{
    SVECTOR position;
    u_int* commands = (u_int*)arg1->unk0;
    u_int command = commands[arg1->unk6];
    if ((command & 0x1FF) == arg0->unkD1C.unk30->unk2) {
        int kind = (command >> 18) & 3;
        if (kind == 2) {
            if (D_800F569C->unkCC != 0)
                func_80046578(D_800F569C->unkCC);
        } else {
            int bank = kind == 0 ? 0x7E : 0xF00000;
            if (((command >> 20) & 3) == 0) {
                vs_main_playSfxDefault(bank, (command >> 9) & 0x1FF);
            } else {
                position.vx = arg0->unk1C[(commands[arg1->unk6] >> 22) & 63].unk38.t[0];
                position.vy = arg0->unk1C[(commands[arg1->unk6] >> 22) & 63].unk38.t[1];
                position.vz = arg0->unk1C[(commands[arg1->unk6] >> 22) & 63].unk38.t[2];
                vs_main_panSfx(bank, (commands[arg1->unk6] >> 9) & 0x1FF, &position);
            }
        }
        return func_800D5780(arg1);
    }
    return 1;
}

int func_800D5A98(D_800F53B8_t* arg0, timedSpawnState* arg1, int arg2)
{
    D_800F53B8_t2 spawn;
    D_800F53B8_t* child;
    struct {
        u_char actors[6];
        u_char final, frame, delay;
    }* event = (void*)arg1->data;
    int result = 1;

    if (event->frame <= arg0->unkD1C.unk30->unk2) {
        if (arg1->index < ((func_800D6894_t*)D_800F569C->unkD0)->unk2) {
            if (arg1->delay == 0) {
                do {
                    spawn.unk14 = D_800F569C->block8Data;
                    spawn.unk18 = arg2;
                    spawn.unk10 = 0;
                    spawn.unk0 = D_800F569C->unkD0 + 4;
                    spawn.unk4 = D_800F569C->unkD0 + 4;
                    spawn.unk8 = D_800F569C->unkD0 + (arg1->index * 12 + 16);
                    spawn.unkC = D_800F569C->unkD0 + (arg1->index * 12 + 16);
                    spawn.unk1C = arg0;
                    spawn.unk20 = arg0->unk14_0;
                    child = func_800CE83C(&spawn);
                    ++arg0->unk14_11;
                    if (spawn.unk8->unk0.unk0 == 4) {
                        child->unk10[1] = event->actors[((u_char*)spawn.unk8)[5]];
                    } else {
                        child->unk10[1] = event->actors[0];
                    }
                    if (++arg1->index == ((func_800D6894_t*)D_800F569C->unkD0)->unk2)
                        break;
                    arg1->delay += event->delay;
                } while (arg1->delay == 0);
            }
            if (arg1->delay != 0)
                --arg1->delay;
        } else if (arg1->index == ((func_800D6894_t*)D_800F569C->unkD0)->unk2) {
            if ((*(u_int*)((char*)arg0 + 0x14) & 0xF800) == 0) {
                spawn.unk14 = D_800F569C->block8Data;
                spawn.unk18 = arg2;
                spawn.unk10 = 0;
                spawn.unk0 = D_800F569C->unkD0 + 4;
                spawn.unk4 = D_800F569C->unkD0 + 4;
                spawn.unk8 = D_800F569C->unkD0 + 16;
                spawn.unkC = D_800F569C->unkD0 + 16;
                spawn.unk1C = arg0;
                spawn.unk20 = arg0->unk14_0;
                child = func_800CE83C(&spawn);
                ++arg0->unk14_11;
                child->unk10[1] = event->final;
                ++arg1->index;
            }
        } else {
            result = 0;
        }
    }
    return result;
}

int func_800D5D74(D_800F53B8_t* arg0, func_800D5780_t* arg1)
{
    func_800D5D74_t* temp_a3 = (func_800D5D74_t*)(arg1->unk6 * 8 + (u_int)arg1->unk0);

    if (temp_a3->unk0_0 == arg0->unkD1C.unk30->unk2) {
        func_800CF694(arg0, vs_battle_effectRenderers[temp_a3->effectRenderer],
            (temp_a3->unk0_9 + temp_a3->unk0_21 * 256) | (temp_a3->unk4 << 0x10));
        return func_800D5780(arg1);
    }
    return 1;
}

typedef struct {
    u_short unk0;
    u_char count, unk3;
    char prefix[12];
    D_800F53B8_t3_2 target[0];
} soundEventTargets;
int func_800D5E00(D_800F53B8_t* actor, func_800D5780_t* event)
{
    int result = 1;
    u_short* data = (u_short*)event->unk0;
    u_short packed = data[event->unk6];
    int play = 0;
    int i;
    if ((packed & 511) != actor->unkD1C.unk30->unk2)
        return result;
    switch (packed >> 14) {
    case 1:
        if (actor->unkD1C.unk0.unk0 == 4 && (u_char)actor->unkD1C.unk0.unk4.unk0 == 0)
            play = 1;
        break;
    case 2:
        if (actor->unkD1C.unk18.unk0 == 4 && (u_char)actor->unkD1C.unk18.unk4.unk0 == 0)
            play = 1;
        break;
    case 0:
        play = 1;
        break;
    case 3:
        for (i = 0; i < ((soundEventTargets*)D_800F569C->unkD0)->count; ++i) {
            if (((soundEventTargets*)D_800F569C->unkD0)->target[i].unk0 == 4
                && (u_char)((soundEventTargets*)D_800F569C->unkD0)->target[i].unk4.unk0
                       == 0) {
                play = 1;
                break;
            }
        }
        break;
    }
    if (play) {
        char* sound = (char*)D_800F569C->block11Data;
        func_800433B4(
            sound + ((short*)(sound + 4))[(data[event->unk6] >> 9) & 31], 255, 1);
    }
    result = func_800D5780(event);
    return result;
}

int func_800D5F8C(D_800F53B8_t* arg0, func_800D5780_t* arg1)
{
    func_800D6310_t* temp_s0 = (func_800D6310_t*)arg1->unk0 + arg1->unk6;

    if (temp_s0->unk0 == arg0->unkD1C.unk30->unk2) {
        if ((arg0->unkD1C.unkC.unk0 == 4)
            && (func_800A0BE0((char)arg0->unkD1C.unkC.unk4.unk0) & 2)) {
            func_8007B29C(temp_s0->unk7, temp_s0->unk2, (char)arg0->unkD1C.unkC.unk4.unk0,
                temp_s0->unk4 - 0x80, temp_s0->unk5 - 0x80, temp_s0->unk6 - 0x80);
        }
        return func_800D5780(arg1);
    }
    return 1;
}

int func_800D6048(D_800F53B8_t* arg0, func_800D5780_t* arg1, int arg2)
{
    int i;
    func_800D6310_t* entry = (func_800D6310_t*)arg1->unk0 + arg1->unk6;

    if (entry->unk0 != arg0->unkD1C.unk30->unk2) {
        return 1;
    }

    if (arg2 != 0) {
        func_800D6048_t* effect = (func_800D6048_t*)&D_800F5230;
        for (i = 0; i < D_800F5230.unk2; ++i) {
            if ((effect->unk10[i].unk0 == 4)
                && (func_800A0BE0(effect->unk10[i].unk4.unk0 & 0xFF) & 2)) {
                func_8007B29C(entry->unk7, entry->unk2, effect->unk10[i].unk4.unk0 & 0xFF,
                    entry->unk4 - 128, entry->unk5 - 128, entry->unk6 - 128);
            }
        }
    } else if ((arg0->unkD1C.unk24.unk0 == 4)
               && (func_800A0BE0(arg0->unkD1C.unk24.unk4.unk0 & 0xFF) & 2)) {
        func_8007B29C(entry->unk7, entry->unk2, arg0->unkD1C.unk24.unk4.unk0 & 0xFF,
            entry->unk4 - 128, entry->unk5 - 128, entry->unk6 - 128);
    }
    return func_800D5780(arg1);
}

int func_800D61AC(D_800F53B8_t* arg0, func_800D5780_t* arg1)
{
    int i;
    func_800D6310_t* temp_s2 = (func_800D6310_t*)(arg1->unk0 + (arg1->unk6 * 2));

    if (temp_s2->unk0 == arg0->unkD1C.unk30->unk2) {
        for (i = 0; i < D_800F5230.unk3; ++i) {
            if (func_800A0BE0(D_800F5230.unkD0[i]) & 2) {
                func_8007B29C(temp_s2->unk7, temp_s2->unk2, D_800F5230.unkD0[i],
                    temp_s2->unk4 - 0x80, (temp_s2->unk5 - 0x80), (temp_s2->unk6 - 0x80));
            }
        }
        return func_800D5780(arg1);
    }
    return 1;
}

int func_800D6298(D_800F53B8_t* arg0, func_800D5780_t* arg1)
{
    func_800D6310_t* temp_a3 = (func_800D6310_t*)arg1->unk0 + (arg1->unk6);

    if (temp_a3->unk0 == arg0->unkD1C.unk30->unk2) {
        func_8007B1B8(temp_a3->unk7, temp_a3->unk2, temp_a3->unk4 - 0x80,
            temp_a3->unk5 - 0x80, (temp_a3->unk6 - 0x80));
        return func_800D5780(arg1);
    }
    return 1;
}

int func_800D6310(D_800F53B8_t* arg0, func_800D5780_t* arg1)
{
    func_800D6310_t* temp_a3 = (func_800D6310_t*)(arg1->unk0 + arg1->unk6 * 2);

    if (temp_a3->unk0 == arg0->unkD1C.unk30->unk2) {
        func_8007B344(temp_a3->unk7, temp_a3->unk2, temp_a3->unk4 - 0x80,
            temp_a3->unk5 - 0x80, temp_a3->unk6 - 0x80);
        return func_800D5780(arg1);
    }
    return 1;
}

void func_800D6388(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk18.unk0 == 4) {
        func_8006CB04((u_char)arg0->unkD1C.unk18.unk4.unk0, NULL);
    } else {
        func_8006CB04(arg0->unkD1C.unk18.unk4.unk6, &arg0->unkD1C.unk18.unk4);
    }
}

void func_800D63D0(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk0.unk0 == 4) {
        func_8006CA20((u_char)arg0->unkD1C.unk0.unk4.unk0, NULL);
    } else {
        func_8006CA20(arg0->unkD1C.unk0.unk4.unk6, &arg0->unkD1C.unk0.unk4);
    }
}

void func_800D6418(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk18.unk0 == 5) {
        func_8006CDD8(&arg0->unkD1C.unk18.unk4);
    }
}

void func_800D6448(D_800F53B8_t* arg0, u_char arg1, u_char arg2)
{
    func_800D78B8();
    func_800CF7A8(arg0->unk1C[arg1].unk34, arg0->unk1C[arg1].unk35, arg2 % 10, arg2 / 10);
    func_800D78CC();
}

void func_800D64E4(void) { func_800CF830(0, 0); }

void func_800D6508(func_800D6508_t* arg0, char arg1)
{
    arg0 += arg1;
    arg0->unk22_2 = 1;
}

void func_800D6538(D_800F53B8_t* arg0) { arg0->unkD1C.unk30->unk1 |= 1; }

void func_800D6554(void) { func_8006CE50(); }

void func_800D6574(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk0.unk0 == 4) {
        func_8006CDB8((u_char)arg0->unkD1C.unk0.unk4.unk0);
    }
}

void func_800D65A8(func_800D6508_t* arg0, char arg1)
{
    arg0 += arg1;
    arg0->unk22_0 = 0;
}

void func_800D65D8(D_800F53B8_t* arg0, u_char arg1)
{

    if (arg0->unkD1C.unkC.unk0 == 4) {
        if (arg1 != 0) {
            func_8009F898((u_char)arg0->unkD1C.unkC.unk4.unk0, 1, arg1);

        } else {
            func_8009F898((u_char)arg0->unkD1C.unkC.unk4.unk0, 0, 0);
        }
    }
}

void func_800D6628(D_800F53B8_t* arg0, u_char arg1)
{
    int var;

    if (arg0->unkD1C.unkC.unk0 == 4) {
        if (arg1 < 4) {
            func_800AE68C((u_char)arg0->unkD1C.unkC.unk4.unk0, arg1);
        } else {
            do {
                var = rand() % 3;
            } while (var == D_800EC4B8);
            func_800AE68C((u_char)arg0->unkD1C.unkC.unk4.unk0, D_800EC4B8 = var);
        }
    }
}

void func_800D66CC(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk18.unk0 == 5) {
        func_8006CE70(&arg0->unkD1C.unk18.unk4);
    }
}

void func_800D66FC(D_800F53B8_t* arg0, u_char arg1, u_char arg2)
{
    func_800D1B18(D_800F5520);
    func_800D1B18(&D_800F5520[1]);
    D_800F5520[1].lookAt.vx = arg0->unk1C[arg1].unk38.t[0] * ONE;
    D_800F5520[1].lookAt.vy = arg0->unk1C[arg1].unk38.t[1] * ONE;
    D_800F5520[1].lookAt.vz = arg0->unk1C[arg1].unk38.t[2] * ONE;
    D_800F54D0 = 0;
    if (arg2 == 0) {
        arg2 = 1;
    }
    D_800F55A0 = arg2;
    func_800D1E20(2);
}

void func_800D67C4(D_800F53B8_t* arg0, u_char arg1)
{
    func_800D1B18(D_800F5520);
    D_800F5520[1] = D_800F55A8;
    D_800F54D0 = 0;
    if (arg1 == 0) {
        arg1 = 1;
    }
    D_800F55A0 = arg1;
    func_800D1E20(2);
}

void func_800D6860(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk24.unk0 == 4) {
        func_80069C6C((u_char)arg0->unkD1C.unk24.unk4.unk0);
    }
}

int func_800D6894(D_800F53B8_t* arg0, func_800D5780_t* arg1)
{
    func_800D6894_t* temp_a2 = (func_800D6894_t*)(arg1->unk0 - (-arg1->unk6));

    if ((temp_a2->unk0 & 0x1FF) == arg0->unkD1C.unk30->unk2) {
        u_char temp_a1_2 = temp_a2->unk2;
        u_char temp_a2_2 = temp_a2->unk3;

        switch (temp_a2->unk0 >> 9) {
        case 0:
            func_800D6388(arg0);
            break;

        case 1:
            func_800D63D0(arg0);
            break;

        case 2:
            func_800D6418(arg0);
            break;

        case 3:
            func_800D6448(arg0, temp_a1_2, temp_a2_2);
            break;

        case 4:
            func_800D64E4();
            break;

        case 5:
            func_800D6508((func_800D6508_t*)arg0, temp_a1_2);
            break;

        case 6:
            func_800D6538(arg0);
            break;

        case 7:
            func_800D6554();
            break;

        case 8:
            func_800D6574(arg0);
            break;

        case 9:
            func_800D65A8((func_800D6508_t*)arg0, temp_a1_2);
            break;

        case 10:
            func_800D65D8(arg0, temp_a1_2);
            break;

        case 11:
            func_800D6628(arg0, temp_a1_2);
            break;

        case 12:
            func_800D66CC(arg0);
            break;

        case 13:
            func_800D66FC(arg0, temp_a1_2, temp_a2_2);
            break;

        case 14:
            func_800D67C4(arg0, temp_a1_2);
            break;

        case 15:
            func_800D6860(arg0);
            break;
        }

        return func_800D5780(arg1);
    }

    return 1;
}

int func_800D6A18(D_800F53B8_t* arg0, func_800D5780_t* arg1)
{
    func_800D6A18_t* e = (func_800D6A18_t*)arg1->unk0;
    int ret = 1;
    int key = e[arg1->unk6].unk0_0;
    int cur = arg0->unkD1C.unk30->unk2;

    if (cur < key) {
        return ret;
    }
    if (key == cur) {
        func_800D1EF0(e->unk4_0, e->unk4_4, e->unk4_9, e->unk4_16, e->unk4_17, e->unk4_24,
            e->unk4_25);
    }
    if (--arg1->unkA == 0) {
        ret = func_800D5780(arg1);
    }
    return ret;
}

void func_800D6AEC(D_800F53B8_t* arg0, int arg1)
{
    D_800F53B8_t4* temp_a0;
    func_800D5780_t* temp_a1;
    int var_s1;

    for (var_s1 = 0; var_s1 < arg0->unkD1C.unk30->unk0; var_s1++) {
        if ((arg0->unkD1C.unk30->unk4 >> var_s1) & 1) {
            int temp;
            func_800D5780_t* temp_a1 =
                (func_800D5780_t*)&arg0->unkD1C.unk30[var_s1 * 2 + 1];
            switch (temp_a1->unk4.unk0_0) {
            case 1:
                temp = func_800D57FC(arg0, temp_a1);
                break;
            case 2:
                temp = func_800D5904(arg0, temp_a1);
                break;
            case 3:
                temp = func_800D5A98(arg0, (void*)temp_a1, arg1);
                break;
            case 4:
                temp = func_800D5D74(arg0, temp_a1);
                break;
            case 5:
                temp = func_800D5E00(arg0, temp_a1);
                break;
            case 6:
                temp = func_800D5F8C(arg0, temp_a1);
                break;
            case 7:
                temp = func_800D6048(arg0, temp_a1, arg0->unkD1C.unk30->unk1 & 2);
                break;
            case 8:
                temp = func_800D61AC(arg0, temp_a1);
                break;
            case 9:
                temp = func_800D6298(arg0, temp_a1);
                break;
            case 10:
                temp = func_800D6310(arg0, temp_a1);
                break;
            case 12:
                temp = func_800D6894(arg0, temp_a1);
                break;
            case 13:
                temp = func_800D6A18(arg0, temp_a1);
                break;
            }
            if (temp == 0) {
                arg0->unkD1C.unk30->unk4 &= ~(1 << var_s1);
            }
        }
    }
    if (!(arg0->unkD1C.unk30->unk1 & 1)) {
        arg0->unkD1C.unk30->unk2++;
    }
}

void func_800D6CCC(int* arg0)
{
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[4] = 0;
    arg0[5] = 0;
    arg0[6] = 0;
    arg0[7] = 0;
}

void func_800D6CF0(func_800D6CF_t* arg0, int arg1, int arg2)
{
    arg0->unk16 = arg1;
    arg0->unk18 = (u_char*)D_800F569C->block2Data + D_800F569C->block2Data[arg2 + 2];
    arg0->unkE = 0;
    arg0->unk6 = 0;
}

void func_800D6D24(func_800D6CF_t* arg0)
{
    if (arg0->unk6 != 0) {
        arg0->unk6 -= 2;
        if (arg0->unk6 != 0) {
            return;
        }
    }

    while (1) {
        int w = *(int*)(arg0->unk18 + arg0->unkE);

        switch (w & 0xF0000000) {
        case 0:
            arg0->unk1C = D_800F569C->block1Tables[arg0->unk16] + (w & 0xFFFF);
            *(short*)&arg0->unk6 = (w >> 16) & 0x3FFF;
            arg0->unkE += 4;
            return;
        case 0x10000000:
            arg0->unk8 = (w << 18) >> 18;
            arg0->unkA = (w << 4) >> 18;
            arg0->unkE += 4;
            break;
        case 0x20000000:
            arg0->unkE = 0;
            break;
        case 0x30000000:
            return;
        }
    }
}

void func_800D6E24(void) { func_800D6E44(); }
