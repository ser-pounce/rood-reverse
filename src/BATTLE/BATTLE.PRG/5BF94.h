#pragma once
#include "../../SLUS_010.40/main.h"
#include "146C.h"
#include "6E644.h"

enum vs_battle_warlockSpellIds_e {
    vs_battle_spell_solidShock = 0x61,
    vs_battle_spell_lightningBolt,
    vs_battle_spell_fireball,
    vs_battle_spell_vulcanLance,
    vs_battle_spell_aquaBlast,
    vs_battle_spell_spiritSurge,
    vs_battle_spell_darkChant,
    vs_battle_spell_exorcism,
    vs_battle_spell_banish,
    vs_battle_spell_explosion,
    vs_battle_spell_thunderburst = 0x6E,
    vs_battle_spell_flameSphere = 0x72,
    vs_battle_spell_gaeaStrike = 0x76,
    vs_battle_spell_avalanche = 0x7A,
    vs_battle_spell_radialSurge = 0x7E,
    vs_battle_spell_meteor = 0x82,
    vs_battle_spell_drainHeart = 0x5E,
    vs_battle_spell_drainMind = 0x5F
};

enum vs_battle_menuItemScrollable {
    menuItem_scrollNone,
    menuItem_scrollUp,
    menuItem_scrollDown
};

enum vs_battle_menuItemState {
    menuItemStateInactive,
    menuItemStateIdle,
    menuItemStateSlideX,
    menuItemStateSlideY,
    menuItemStateSlideXY,
    menuItemStateDismiss = 5
};

typedef struct {
    u_char state;
    u_char w;
    u_char backgroundWidth;
    u_char _ __attribute__((unused));
    u_char gradientState;
    u_char isScrollable;
    u_char selected;
    u_char unselectable;
    u_char buttonId;
    u_char rowIcon;
    u_char fontColor;
    u_char invertGradient;
    u_char material;
    u_char outsetIcon;
    u_short itemPage;
    u_short count;
    u_short max;
    short x;
    short y;
    short targetPosition0;
    short targetPosition1;
    char text[32];
    char* subText;
} vs_battle_menuItem_t;

enum vs_battle_menuStates {
    menuStateMainMenu,
    menuStateNoneClosing = 0x1F,
    menuStateNoneClosed = 0x3F,
    menuStateOpenedFromMainMenu = 0x40
};

typedef struct {
    char currentMenu;
    char returnState;
    char executeAbilityType;
    char loading;
    vs_main_CdQueueSlot* cdQueue;
} vs_battle_menuState_t;

typedef struct {
    u_int unk0_0 : 4;
    u_int unk0_4 : 2;
    u_int unk0_6 : 2;
    u_int unk0_8 : 4;
    u_int unk0_12 : 4;
    u_int arrowAnimFrame : 8;
    u_int unk0_24 : 6;
    u_int done : 1;
    u_int unk0_31 : 1;
} vs_battle_textBox_fields;

typedef struct {
    vs_battle_textBox_fields unk0;
    short unk4;
    short unk6;
    char* string;
    u_short speed;
    u_short prevChunksPrinted;
    short xIndent;
    short yIndent;
    short x;
    short y;
    short centerX;
    short centerY;
    short state;
    u_char brightness;
    u_char unk1F;
    char charsPerLine;
    char lineCount;
    char unk22;
    char unk23;
    short unk24;
    short unk26;
    short unk28;
    short unk2A;
    short unk2C;
    short unk2E;
} vs_battle_textBox;

typedef struct {
    char cursorMemories[52];
    char unk34[6];
    struct {
        char currentItemCategory;
        char unk1;
        union {
            struct {
                u_char index;
                u_char page;
            } cursor;
            u_short value;
        } unk2[8];
    } unk3A;
    char unk4C[4];
    char unk50;
    char unk51[51];
    char selectedEquipment;
    char unk85[25];
    u_short unk9E;
    char unkA0[0x12];
    char unkB2[0x40];
} D_800F4EE8_t;

typedef struct {
    short unk0;
    short unk2;
    union {
        struct {
            u_int unk0_0 : 9;
            u_int unk0_9 : 5;
            u_int unk0_14 : 5;
            u_int unk0_19 : 13;
        } fields;
        u_short u16[2];
        int s32;
    } executeAbility;
} D_800F18EC_t;

typedef struct {
    int integers[10];
    char* strings[10];
} vs_battle_stringContext_t;

typedef struct {
    short unk0[6];
    short unkC[2];
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    u_char unk14;
    u_char unk15;
} pFileBlock9;

typedef struct {
    u_short count;
    u_short dataOffset;
    u_char subBlockSizes[0];
} pFileBlock4;

typedef struct {
    short unk0;
    short unk2;
} func_800CFE1C_t;

typedef struct {
    int unk0;
    short unk4;
    u_char unk6;
    u_char unk7;
    int unk8;
    short unkC;
    short unkE;
    int unk10;
    short unk14;
    u_char unk16;
    u_char unk17;
    u_char* unk18;
} func_800D6CF_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    u_int unk4_0 : 26;
    u_int unk4_26 : 6;
    u_char unk8;
    u_char unk9;
    u_char unkA;
    u_char unkB;
    u_char unkC;
    u_char unkD;
    u_char unkE;
    u_char unkF;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    u_char unk14;
    u_char unk15;
    u_char unk16;
    u_char unk17;
    u_char unk18[0x18];
    short unk30[2];
    short unk34[8][6];
    short unk94[5][4];
    int unkBC;
    short unkC0[2];
    u_char unkC4;
    u_char unkC5;
    u_char unkC6;
    u_char unkC7;
    u_char unkC8;
    u_char unkC9;
    u_char unkCA;
    u_char unkCB;
} func_800FA098_arg0;

typedef struct {
    u_char unk0[0x24];
    u_int unk24;
    int unk28;
    SVECTOR unk2C;
    VECTOR unk34;
    VECTOR unk44;
    u_char unk54[0x10];
    MATRIX unk64;
    u_char unk84[0x14];
    VECTOR unk98;
    VECTOR unkA8;
    VECTOR unkB8;
    VECTOR unkC8;
    VECTOR unkD8;
    VECTOR unkE8;
    SVECTOR unkF8;
    SVECTOR unk100;
    SVECTOR unk108;
    SVECTOR unk110;
    int unk118[2];
    int unk120;
    int unk124[2];
    int unk12C[2];
    int unk134;
    int unk138;
    SVECTOR unk13C;
    SVECTOR unk144;
    u_char unk14C[0x1C];
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
} func_800FA098_arg1;

typedef struct {
    int count;
    func_800FA098_arg0 unk4[0];
} pFileBlock5;

typedef struct {
    int unk0;
    int unk4;
    pFileBlock5* block5Data;
    u_char* block4SubBlocks[4];
    char unk1C[0x70];
    pFileBlock4* block4Data;
    char* block8Data;
    int block1TableCount;
    void* block1Tables[4];
    void* block1Data;
    int block2Count;
    u_short* block2Data;
    pFileBlock9* block9Data;
    void* block10Data;
    void* block3Data;
    u_char* block11Data;
    void* block12Data;
    void* block13Data;
    int unkCC;
    void* unkD0;
} D_800F569C_t;

typedef struct func_800D2904_t {
    struct func_800D2904_t* previous;
    struct func_800D2904_t* next;
    char unk8[4];
    int unkC;
    int unk10;
    int unk14;
    VECTOR unk18;
    u_char unk28[0x14];
    int unk3C[8];
    char unk5C[0x1B];
    u_char unk77;
} func_800D2904_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    u_char unk34;
    u_char unk35;
    u_char unk36;
    u_char unk37;
    MATRIX unk38;
    u_char unk58[0x78];
} func_800CE714_t2_2;

typedef struct {
    u_short unk0;
    u_short unk2;
    func_8006CE70_t unk4;
} D_800F53B8_t3_2;

typedef struct {
    D_800F53B8_t3_2 unk0;
    D_800F53B8_t3_2 unkC;
    D_800F53B8_t3_2 unk18;
    D_800F53B8_t3_2 unk24;
    D_800F53B8_t4* unk30;
    func_800D4910_t* unk34;
    short unk38;
    short unk3A;
    int unk3C;
} D_800F53B8_t3;

typedef struct D_800F53B8_t {
    struct D_800F53B8_t* next;
    struct D_800F53B8_t* previous;
    char unk8;
    char unk9;
    u_short unkA;
    char* unkC;
    char unk10[4];
    u_int unk14_0 : 8;
    u_int unk14_8 : 3;
    u_int unk14_11 : 5;
    u_int unk14_16 : 16;
    func_800D2904_t* unk18;
    func_800CE714_t2_2 unk1C[16];
    D_800F53B8_t3 unkD1C;
} D_800F53B8_t;

typedef struct {
    u_char unk0[0xC];
    VECTOR unkC;
    u_char unk1C[0x44];
    u_char unk60;
    u_char unk61[23];
} func_800FB4C0_t;

enum vs_battle_limbStatus {
    limbStatusCritical,
    limbStatusDamaged,
    limbStatusWounded,
    limbStatusGood,
    limbStatusExcellent
};

int func_800C4794(SVECTOR*);
int func_800C58F8(void*);
int vs_battle_setTextBox(int, char*);
int vs_battle_selectTextBox(u_char);
char* vs_battle_printf(char*, char*);

/**
 * Renders ASCII text and chains it to the provided OT.
 */
void vs_battle_renderTextRawColor(char const* text, int xy, int color, void* nextPrim);

/**
 * Same as vs_battle_renderTextRawColor, except color is predefined as gray midpoint
 * (0x808080).
 */
void vs_battle_renderTextRaw(char const* text, int xy, void* nextPrim);

/**
 * Renders a glyph from the font table at the specified location.
 * @return Glyph width
 */
int vs_battle_printVariableWidthFontChar(u_int glyphId, int x, int y, u_long* ot);
void vs_battle_setFontStyle(int arg0);
void vs_battle_loadGim(int, int);
void func_800C8550(u_int, void*, u_char*);
void func_800C86AC(void);
int vs_battle_loadMenuPrg(int arg0);

enum vs_battle_informationTextBoxHeader {
    informationTextBoxHeaderNone,
    informationTextBoxHeaderCaution,
    informationTextBoxHeaderInformation,
    informationTextBoxHeaderCheck
};

/**
 * Initializes textbox ID 7
 */
void vs_battle_initInformationTextBox(enum vs_battle_informationTextBoxHeader flags);

/**
 * Lerps between two predefined colors, used for menu item backgrounds.
 *
 * @param gradient Lerp weight from 0-8
 * @param colorIndex Valid indices are 0-8, 16, and 24
 */
int vs_battle_uiGradientStop(u_int gradient, u_int colorIndex, int brightness);

/**
 * Gets menu row element.
 */
vs_battle_menuItem_t* vs_battle_getMenuItem(int row);

/**
 * Initializes a menu row element.
 *
 * @return The populated row.
 */
vs_battle_menuItem_t* vs_battle_setMenuItem(
    int row, int x, int y, int w, int backgroundWidth, char* text);
void vs_battle_renderMenuItem(vs_battle_menuItem_t*);
int func_800C930C(int);
void func_800C97BC(void);

/**
 * Renders a digit or symbol from the battle digits.
 *
 * @param font 0 = small, 1 = large, 2 = symbols
 * @param before Can be NULL, in which case the pointer at (scratchpad + 4)[1] is used.
 * @return The position immediately to the left of the rendered value.
 */
int vs_battle_renderValue(int font, int xy, int value, u_long* before);

/**
 * Renders HP / MP / Risk bars
 */
void vs_battle_renderStatBar(int colorIndex, int w, u_long* before, int xy);

/**
 * Retrieves the status effects currently applied.
 *
 * @return Packed bits.
 */
int vs_battle_getStatusFlags(vs_battle_actor2*);
int vs_battle_getLimbStatus(vs_battle_uiEquipment_limb*);
void func_800CAB40(void);
int func_800CABE0(int);

/**
 * Determines whether the selected spell class is available
 *
 * @param spellClass Class from 0-3
 * @return Bool
 */
int vs_battle_isSpellClassUnlocked(int spellClass);
int vs_battle_chainAbilitiesUnlocked(int);
void func_800CB23C(void);
void func_800CB660(int arg0);
D_800F18EC_t* func_800CB66C(void);
void func_800CB114(void);
void func_800CB158(vs_battle_lootListNode*);
void func_800CB18C(vs_battle_loot*);
void func_800CB1C0(int);
void _setArtAndAbilityToUnlock(int art, int battleAbility);
void vs_battle_displaySceneMessage(int, int, int);
int func_800CB45C(void);
void func_800CB50C(void);
void func_800CB550(void);
void func_800CB560(void);
void func_800CB654(int);
void func_800CB7DC(void);
void vs_battle_rMemzero(void* arg0, int arg1);
void vs_battle_rMemcpy(void* dest, void const* src, int size);

/**
 * Converts the lowest decimal digit to BCD.
 *
 * @return Packed value
 * - Bits 0-3: Lowest decimal digit from 0-9
 * - Bits 4+: value / 10
 */
int vs_battle_toBCD(int value);
int vs_battle_drawCursor(int animStep, int position);
u_int vs_battle_keystreamBits(int value);
int vs_battle_decreaseMiscCount(int);
void vs_battle_addTile(u_long* before, int rgb0, int xy, int wh);
void vs_battle_insertTpage(int arg0, u_long* arg1);
vs_battle_textBox* vs_battle_getTextBox(int arg0);
void vs_battle_initTextBox(
    int id, int flags, int x, int y, int w, int h, int centerX, int centerY);
int vs_battle_dismissTextBox(int);
void vs_battle_insertTpage(int, u_long*);
void vs_battle_renderImage(int xy, void* buffer, int wh);
void func_800CE64C(void);
int func_800CEEBC(void);
int func_800CEF74(int);
int func_800CF0E8(func_800CF0E8_t*, int, int);
void func_800CF1A8(void);
int func_800CF3F8(func_800CF0E8_t*, int);
int func_800CF48C(void);
void func_800CF7A8(int, int, int, int);
void func_800CF830(int, int);
void func_800CF920(void);
int vs_battle_getTextLineLength(char* str);
int vs_battle_validateShortcutSelection(int shortcut);
void func_800C8778(void);
void func_800C9F88(void);
void func_800CA2DC(void);
int func_800CACD0(int menuState, int arg1);
void func_800CB83C(void);
int func_800CF060(void);
void vs_battle_addVecToSvec(VECTOR* arg0, SVECTOR* arg1, VECTOR* arg2);
void vs_battle_lerp2DVector(short* src, int t, int* vec);
void vs_battle_lerpSvector(short* src, int t, SVECTOR* vec);
void vs_battle_lerpVector(short* src, int t, VECTOR* vec);
int func_800CFB80(int, int);
int func_800CFE1C(short* arg0, int arg1);
int func_800D118C(int arg0, int arg1);

/**
 * Evaluates a point on a spline segment between p1 and p2.
 *
 * The curve passes through p1 at t = 0 and p2 at t = ONE;
 *
 * @param p0  Control point before segment.
 * @param p1  Segment start point.
 * @param p2  Segment end point.
 * @param p3  Control point afater segment.
 * @param t   Interpolation value ([0, ONE] ?).
 * @param out Output vector.
 */
void vs_battle_splineInterpolate(
    SVECTOR* p0, SVECTOR* p1, SVECTOR* p2, SVECTOR* p3, int t, SVECTOR* out);

void vs_battle_svecToVec(SVECTOR* arg0, VECTOR* arg1);
void vs_battle_vecToSvec(VECTOR* arg0, SVECTOR* arg1);
void func_800D2ADC(D_800F53B8_t*, int, int, int, func_800FB4C0_t*);
void func_800D6CCC(int* arg0);
void func_800D6CF0(func_800D6CF_t* arg0, int arg1, int arg2);

extern u_short vs_battle_menuStrings[];
extern char* vs_battle_limbNames[];
extern char vs_battle_characterWidths[];
extern u_short vs_battle_statusStrings[];
extern char D_800EB9AE;
extern char D_800EB9AF;
extern int D_800EB9B0;
extern vs_battle_lootListNode* D_800EB9C4;
extern vs_battle_loot* D_800EB9C8;
extern vs_battle_menuItem_t* vs_battle_menuItems;
extern char vs_battle_rowAnimationSteps[];
extern int D_800EBBEC[];
extern char D_800EBBFC[];
extern char D_800EBC00[];
extern u_short vs_battle_statusIconTexOffsets[];
extern u_int D_800EBC54[];
extern char vs_battle_animationIndices[];
extern char vs_battle_warlockSpellIds[];
extern char vs_battle_shamanSpellIds[];
extern char vs_battle_sorcererSpellIds[];
extern char vs_battle_enchanterSpellIds[];
extern char vs_battle_cursorBrightnessAnimation[];
extern char vs_battle_chainAbilityOffsets[];
extern char vs_battle_defenseAbilityOffsets[];
extern char vs_battle_shortcutInvoked;
extern char D_800F4E6B;
extern int* vs_battle_rowTypeBuf;
extern char vs_battle_unlockedBreakArt;
extern char* vs_battle_stringBuf;
extern char vs_battle_submenuStates[16];
extern char vs_battle_lowerScreenUiState;
extern D_800F18EC_t D_800F4E98;
extern int D_800F4EA0;
extern D_800F4EE8_t D_800F4EE8;
extern char vs_battle_unlockedBattleAbility;
extern char D_800F4FDB;
extern D_800F569C_t* D_800F569C;
extern D_800F569C_t D_800F56C8;
extern vs_battle_textBox vs_battle_textBoxes[];
extern u_char vs_battle_miscItemInvoked;
extern vs_battle_stringContext_t vs_battle_stringContext;
extern vs_battle_menuState_t vs_battle_menuState;
extern SVECTOR D_800F5310[];
extern D_800F53B8_t* D_800F53BC;
extern effectExec vs_battle_effectRenderers[];
