#include "common.h"
#include "5BF94.h"
#include "146C.h"
#include "2842C.h"
#include "40564.h"
#include "573B8.h"
#include "6E644.h"
#include "vs_string.h"
#include "gpu.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/overlay.h"
#include "../../SLUS_010.40/32154.h"
#include "../../MENU/MAINMENU.PRG/C48.h"
#include "../../GIM/SCREFF2.PRG/0.h"
#include "build/src/include/lbas.h"
#include "build/assets/BATTLE/BATTLE.PRG/menuStrings.h"
#include <memory.h>
#include <libetc.h>

typedef struct {
    u_char unk0;
    u_char unk1;
    u_short unk2;
    int unk4;
    int unk8;
    vs_main_CdQueueSlot* slot;
} D_800EB9B4_t;

typedef struct {
    short unk0;
    char unk2;
    char unk3;
    short unk4;
    short id;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    void* data;
    vs_main_CdQueueSlot* cdQueueSlot;
    int unk18[0xF7];
    int unk3F4;
} gim_t;

typedef struct {
    u_short unk0;
    u_short unk2;
    char unk4;
    char unk5;
    char unk6;
    char unk7;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    u_short unk18;
    u_short unk1A;
    func_8006CE70_t unk1C;
} D_800F53B8_t3;

typedef struct {
    D_800F53B8_t3* unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    char* unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
} D_800F53B8_t2;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    u_int unk14_0 : 11;
    u_int unk14_11 : 5;
    u_int unk14_16 : 16;
} D_800F53B8_t5;

typedef struct {
    int unk0;
    D_800F53B8_t5* unk4;
    char unk8;
    char unk9;
    u_short unkA;
    char* unkC;
    char unk10[4];
    char unk14[0x28];
    int unk3C;
    char unk40[0xCDC];
    D_800F53B8_t3 unkD1C;
} D_800F53B8_t;

typedef struct {
    short unk0;
    short unk2;
} func_800CFE1C_t;

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
    u_char order[8];
    u_char unk8;
    u_char unk9;
    u_char selectedIndex;
    u_char count;
    u_char unkC;
} _textBoxSelector_t;

int func_800A0BE0(int);
void _renderDigit(int, int, int, u_long*);
void func_800CA97C(void);
void func_800CBBCC(u_char* arg0, int arg1, u_long* arg2);
int _breakArtsUnlocked(void);
void func_800CE67C(void);
void func_800CE83C(D_800F53B8_t2*);
int func_800CF218(void);
void func_800CF694(D_800F53B8_t*, int, int);
void func_800CFEF0(D_800F53B8_t*);
void func_800CFE98(void*, int);
void func_800D0D08(D_800F53B8_t*);
void func_800D169C(int, int, int, int);
void func_800D17A8(int, int, int, int);
void func_800D268C(void);
void func_800D2ADC(D_800F53B8_t*, int, int, int, int);
void func_800D46DC(int, D_800F53B8_t*);
u_char func_800D5170(D_800F53B8_t*);
u_short func_800D5198(D_800F53B8_t*);
void func_800D55A4(D_800F53B8_t*, int, int);
void func_800D6AEC(D_800F53B8_t*, u_short);

extern u_long* D_1F800000[];

extern u_int _gimLbas[];
extern int _menuLbas[];
extern char D_800EB9AC;
extern signed char D_800EB9AD;
extern D_800EB9B4_t* D_800EB9B4;
extern int D_800EB9B8;
extern gim_t* D_800EB9BC;
extern char D_800EB9CC;
extern char D_800EB9CD;
extern char D_800EB9CE;
extern union {
    int s32;
    u_char u8[4];
} D_800EB9D0;
extern u_int* D_800EB9D4;
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
extern u_char _spellClassCounts[];
extern u_char* _spellIds[];
extern char D_800EBD68[];
extern u_short D_800EBDDC[];
extern u_int _keystreamState;
extern char D_800EBF58[][12];
extern char* D_800EC258;
extern int D_800EC2CC[];
extern int D_800EC2D8[];
extern int D_800EC324[];
extern char D_800EC32C[];
extern int (*D_800EC3F4[])(void*);
extern u_char D_800F522C;
extern char D_800F4CB8;
extern char _fontTable;
extern int _fontBrightness;
extern u_long D_800F4CD0;
extern char vs_battle_shortcutInvoked;
extern char D_800F4E68;
extern char D_800F4E69;
extern char D_800F4E90;
extern _textBoxSelector_t textBoxSelector;
extern int D_800F4ED4;
extern short D_800F4ED8[8];
extern u_long* D_800F51B8;
extern char D_800F51C8;
extern int D_800F521C;
extern int D_800F5224;
extern int D_800F5228;
extern char D_800F5310[];
extern u_int D_800F531C;
extern char D_800F54A8;
extern u_char D_800F4E80;
extern char D_800F5518;
extern int D_800F55E8;
extern int D_800F5600;
extern int D_800F5610;
extern int D_800F5618;
extern D_800F5620_t D_800F5620;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C4794);

void func_800C513C(int arg0)
{
    if (!(arg0 & 0xF0)) {
        func_8009FE74(arg0);
    }
}

void func_800C5164(int arg0)
{
    if (!(arg0 & 0xF0)) {
        func_8009FD5C(arg0);
    }
}

void func_800C518C(int arg0, void* arg1)
{
    if (!(arg0 & 0xF0)) {
        func_800A07FC(arg0, arg1);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C51B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C5360);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C553C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C56C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C5798);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C58A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C58F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C64D0);

INCLUDE_ASM(
    "build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", vs_battle_renderTextRawColor);

void vs_battle_renderTextRaw(char const* text, int xy, void* arg2)
{
    vs_battle_renderTextRawColor(text, xy, vs_getRGB(128, 128, 128), arg2);
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

int vs_battle_printVariableWidthFontChar(u_int glyphId, int x, int y, u_long* arg3)
{
    int glyphRow;
    u_int glyphCol;
    u_long* sprite;

    if (glyphId == ' ') {
        return x + 6;
    }

    glyphId += _fontTable * 0xBD;
    sprite = vs_battle_setSprite(
        _fontBrightness, (x & 0xFFFF) | (y << 0x10), 0xC000C, arg3 + 3);
    sprite[1] = 0xE100002D;
    glyphRow = glyphId / 21;
    glyphCol = glyphId % 21;
    sprite[4] = ((glyphCol * 0xC) | (glyphRow * 0xC00)
                 | ((((((D_800F4CB8 * 0x10) + 0x340) >> 4) & 0x3F) | 0x3780) << 0x10));
    return x + vs_battle_characterWidths[glyphId];
}

void func_800C7210(int arg0)
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

void func_800C7EBC(void*, int, int, int);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7EBC);

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
    vs_battle_drawImage(
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
        var_s0 = vs_main_allocHeapR(sizeof(gim_t[3]));
        D_800EB9BC = var_s0;
        var_s0->data = vs_main_allocHeapR((char)_gimLbas[id] << 0xB);

        for (i = 0; i < 3; ++i) {
            var_s0->unk0 = 0;
            *(int*)&var_s0->unk0 = (((*(int*)&var_s0->unk0 | 2) & ~0x1C0) | 0x40);
            var_s0->unk2 = arg1;
            var_s0->unk3 = 0x80;
            var_s0->id = id;
            var_s0->unk8 = 0;
            var_s0->unkA = 0;
            var_s0->unkC = 0x1000;
            ++var_s0;
        }
        file.lba = _gimLbas[id] >> 8;
        file.size = (char)_gimLbas[id] << 0xB;
        D_800EB9BC->cdQueueSlot = vs_main_allocateCdQueueSlot(&file);
        vs_main_cdEnqueue(D_800EB9BC->cdQueueSlot, D_800EB9BC->data);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8550);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C86AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8778);

int func_800C8C50(int arg0)
{
    vs_main_CdFile file;
    int temp_s0;
    u_int var_v1;
    void* var_a1;
    vs_battle_menuState_t* s1 = &vs_battle_menuState;

    temp_s0 = arg0 & 0x1F;

    if (temp_s0 == 0x1F) {
        return 1;
    }

    if (temp_s0 == 0 && D_800EB9AD > 0) {
        return 1;
    }

    if (D_800EB9AD != temp_s0) {
        D_800EB9AD = temp_s0;
        s1->unk3 = 1;
        if (vs_battle_shortcutInvoked != 5) {
            var_v1 = _menuLbas[temp_s0];
        } else {
            var_v1 = VS_MAINMENU_PRG_LBA << 8 | VS_MAINMENU_PRG_SIZE >> 11;
        }
        file.lba = var_v1 >> 8;
        file.size = (var_v1 & 0xFF) << 11;
        s1->unk4 = vs_main_allocateCdQueueSlot(&file);
        if (temp_s0 == 0) {
            var_a1 = vs_overlay_slots[1];
        } else {
            var_a1 = vs_overlay_slots[2];
        }
        vs_main_cdEnqueue(s1->unk4, var_a1);
    }
    if (s1->unk3 == 0) {
        if (D_800EB9D4 != NULL) {
            vs_main_freeHeapR(D_800EB9D4);
            D_800EB9D4 = NULL;
            func_800FA448();
        }
        return 1;
    }
    if (s1->unk4->state == vs_main_CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(s1->unk4);
        vs_main_wait();
        s1->unk3 = 0;
        if (D_800F4FDB != 0) {
            if (vs_battle_shortcutInvoked == 5) {
                func_800FAEBC(1);
                return 0;
            }
            return 1;
        }
        if (temp_s0 == 0) {
            D_800EB9D4 = (u_int*)vs_main_allocHeapR(0xB400);
            func_8010044C(D_800EB9D4);
        }
    }
    return 0;
}

void func_800C8E04(int arg0)
{
    vs_battle_initTextBox(7, (arg0 << 8) | 4, 0, 1, 0, 4, 0, 0);
}

vs_battle_menuItem_t* vs_battle_getMenuItem(int id) { return vs_battle_menuItems + id; }

vs_battle_menuItem_t* vs_battle_setMenuItem(
    int id, int x, int y, int w, int arg4, char* text)
{
    vs_battle_menuItem_t* menuItem;
    vs_battle_menuItem_t* var_a0;
    int i;
    u_int c;

    menuItem = &vs_battle_menuItems[id];
    menuItem->state = 1;
    menuItem->w = w;
    menuItem->unk2 = arg4;

    vs_battle_rMemzero(&menuItem->animationState, 0x3C);

    var_a0 = menuItem;
    menuItem->initialX = x;
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

int vs_battle_uiGradientStop(u_int arg0, u_int arg1, int arg2)
{
    u_int var_a0;
    u_int var_v0;

    if (arg1 < 9) {
        var_a0 = _lerpColor(0x6B4100, 0x6C8219, 0x80, arg1);
        var_v0 = _lerpColor(0x330500, 0x262801, 0x80, arg1);
    } else {
        var_a0 = D_800EBBB8[((arg1 >> 3) - 2)];
        var_v0 = D_800EBBC0[((arg1 >> 3) - 2)];
    }
    return _lerpColor(var_a0, var_v0, arg2, arg0);
}

void func_800C9078(vs_battle_menuItem_t* arg0)
{
    int sp10;
    int temp_v1;
    int x;
    int var_s1;
    int var_s2;
    int y;
    char* var_s0;
    u_long* temp_s6;
    int temp_s5;
    int var_v0;
    u_long* temp_v1_2;
    char* text;
    char** v;

    y = arg0->animationState;
    temp_s6 = *(void**)0x1F800008 + 8;
    sp10 = arg0->w;
    temp_s5 = arg0->unk2;
    text = arg0->text;

    if (arg0->state != 0) {
        if (((arg0->selected | arg0->unkB) != 0) && (arg0->unk7 == 0)) {
            y = 8;
        }

        var_v0 = arg0->unkA;

        if (var_v0 == 0) {
            var_v0 = arg0->unk7 * 3;
        }

        func_800C7210(var_v0 + 4);

        temp_v1 = arg0->initialX;
        var_s2 = temp_v1 + 6;

        if ((arg0->icon - 1) < 0x17u) {
            var_s2 = temp_v1 + 0x16;
        }

        var_s1 = text[0];
        var_s0 = text + 1;

        while (var_s1 != 0xFF) {
            if (var_s1 == 0xFA) {
                var_s2 += *var_s0++;
            } else {
                var_s2 = vs_battle_printVariableWidthFontChar(
                    var_s1, var_s2, arg0->y, temp_s6 - 3);
            }
            var_s1 = *var_s0++;
        }

        var_s1 = vs_battle_uiGradientStop(8 - y, temp_s5, 0x80);
        var_s2 = vs_battle_uiGradientStop(y, temp_s5, 0x80);

        if (temp_s5 & 7) {
            arg0->unk2 = (temp_s5 + 1) & 0xF;
        }

        if (y != 0) {
            arg0->animationState = y - 1;
        }

        x = *(int*)&arg0->initialX;
        y = x >> 0x10;
        x &= 0xFFFF;
        func_800CCCB8(temp_s6 + 1, 0x60000000, ((x + 2) & 0xFFFF) | ((y + 2) << 0x10),
            sp10 | 0xC0000);
        temp_v1_2 = *(void**)0x1F800000;

        temp_v1_2[0] = ((*temp_s6 & 0xFFFFFF) | 0x0A000000);
        temp_v1_2[1] = 0xE1000200;
        temp_v1_2[2] = (var_s1 | 0x38000000);
        temp_v1_2[3] = (x | (y << 0x10));
        temp_v1_2[4] = var_s2;
        temp_v1_2[5] = (((x + sp10) & 0xFFFF) | (y << 0x10));
        temp_v1_2[6] = var_s1;
        temp_v1_2[7] = (x | ((y + 0xC) << 0x10));
        temp_v1_2[8] = var_s2;
        temp_v1_2[9] = (((x + sp10) & 0xFFFF) | ((y + 0xC) << 0x10));
        temp_v1_2[10] = 0xE1000000;

        *temp_s6 = (u_int)((u_long)temp_v1_2 << 8) >> 8;
        *(void**)0x1F800000 = temp_v1_2 + 11;

        v = (char**)&arg0->subText;
        if (*v != NULL) {
            vs_battle_renderTextRaw(*v, (x - 10) | ((y + 1) << 0x10), temp_s6);
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C930C);

void func_800C97BC(void)
{
    vs_battle_menuItem_t* var_s2;
    int temp_s1;
    int miscIndex;
    int i;
    int var_s0;

    var_s2 = vs_battle_menuItems;
    var_s0 = vs_battle_menuState.currentState;

    if (var_s0 == 0x7F) {
        D_800F4E98.unk0 = 2;
        vs_battle_menuState.currentState = 0x3F;
    }

    temp_s1 = var_s0 & 0x3F;

    if (temp_s1 != 0x3F) {
        if (func_800C8C50(0) != 0) {
            if (vs_battle_shortcutInvoked == 5) {
                func_800FAEBC(0);
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
                vs_battle_menuState.currentState = var_s0;
            }
        }
        if ((var_s0 >= 0x1F) || (temp_s1 == 0)) {
            for (i = 0; i < 10; ++i) {
                func_800C9078(var_s2);
                ++var_s2;
            }
        }
    }
}

void _renderDigit(int arg0, int xy, int digit, u_long* prim)
{
    u_long* temp_v0 = func_800C0224(
        0x80, xy + ((arg0 & 2) << 0x10), (0x05CA0576 >> (arg0 * 4)) & 0xF000F, prim);
    temp_v0[4] = 0x37F40B20;
    if (arg0 != 2) {
        ((short*)temp_v0)[8] = ((((digit * 2) + 0x40) * (arg0 + 3)) - 0xC0);
    }
}

int vs_battle_renderValue(int arg0, int xy, int value, u_long* prim)
{
    int new_var;

    if (prim == NULL) {
        prim = D_1F800000[1] - 4;
    }

    do {
        value = vs_battle_toBCD(value);
        _renderDigit(arg0, xy, value & 0xF, prim);
        new_var = xy - 5;
        xy = new_var - arg0;
        value >>= 4;
    } while (value != 0);

    return xy;
}

void vs_battle_drawStatBar(int colorIndex, int w, u_long* nextPrim, int xy)
{
    int rgb0;
    u_int rgb1;
    u_long* primBuf;

    rgb1 = D_800EBC04[colorIndex];
    primBuf = D_1F800000[0];

    rgb0 = (((w * 0xFF) + ((rgb1 & 0xFF) * (0x40 - w))) >> 6)
         | ((((w * 0xF0) + (((rgb1 >> 8) & 0xFF) * (0x40 - w))) >> 6) << 8)
         | ((((w * 0x9E) + ((rgb1 >> 16) * (0x40 - w))) >> 6) << 16);

    primBuf[0] = (*nextPrim & 0xFFFFFF) | (w == 0 ? 0x03000000 : 0x0D000000);
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
    *nextPrim = ((u_long)primBuf << 8) >> 8;
    D_1F800000[0] = primBuf + 14;
}

void _drawStatBar(int colorIndex, int current, int max)
{
    u_long* prim = D_1F800000[1] - 3;
    int xy = D_800EBBDC[colorIndex] - D_800EB9B0;

    if (max != 0) {
        vs_battle_drawStatBar(colorIndex, (((current << 6) + max) - 1) / max, prim, xy);
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
        func_800C0224(0x180, D_800EBBEC[colorIndex] - D_800EB9B0,
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

        var_s2 = D_800EBC14[arg0];
        arg2 = (arg2 * 0x10) + 0xA0;

        if (arg1 < 0) {
            var_s2 -= arg1;
            var_s1 = arg1 + 0x10;
        } else {
            arg2 += arg1;
            var_s1 = 0x10 - arg1;
        }

        temp_a0 =
            func_800C0224(0x80, arg2 | 0x80000, var_s1 | 0x100000, D_1F800000[1] - 1);

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

            func_800C0224(0x80, arg2 | 0x80000, var_s1 | 0x80000, D_1F800000[1] - 1)[4] =
                var_s2 | 0x37FF0000;
        }
    }
}

int vs_battle_getStatusFlags(vs_battle_actor2* arg0)
{
    int i;
    int temp_v1 = (u_int)arg0->unk948 >> 5;
    int var_a2 = temp_v1 & 0xFFFF;
    temp_v1 >>= 0x10;

    for (i = 0; i < 8; ++i) {
        if ((temp_v1 >> i) & 1) {
            var_a2 |= D_800EBC68[i] << 0x10;
        }
    }

    return var_a2;
}

int vs_battle_getHitLocationStatus(vs_battle_uiEquipment_bodyPart* limb)
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
        if (vs_battle_spellClassUnlocked((0x3021 >> (arg0 * 4)) & 0xF) == 0) {
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
    u_long* temp_v0 = func_800C0224(arg1, arg0, 0x60006, D_1F800000[2]);
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
                temp_v0_2 = func_800C0224(temp_v0,
                    ((temp_s3 + D_800EBCA0[i]) & 0xFFFF) | (D_800EBCA0[i + 4] << 0x10),
                    D_800EBCA8[i], D_1F800000[2]);
                temp_v0_2[1] = 0xE1000017;
                temp_v0_2[4] = (*((i) + D_800EBCB8) | 0x373D0000);
            }
        }

        func_800C0224(0x180, ((temp_s3 + 0x48) & 0xFFFF) | 0x660000, 0x1E001E,
            D_1F800000[2])[4] = 0x37FBA0B8;
        temp_s3 = (0xA0 - temp_s3);

        for (i = 0; i < 4; ++i) {
            temp_v0 = func_800C9EB8(i);
            if (temp_v0 != 0) {
                func_800C9F98(
                    ((temp_s3 + D_800EBCC0[i]) & 0xFFFF) | (D_800EBCC0[i + 4] << 0x10),
                    temp_v0);
                temp_v0_2 = func_800C0224(temp_v0,
                    (((temp_s3 + D_800EBCC8[i]) - 2) & 0xFFFF)
                        | (D_800EBCC8[i + 4] << 0x10),
                    D_800EBCD0[i], D_1F800000[2]);
                temp_v0_2[1] = 0xE1000017;
                temp_v0_2[4] = D_800EBCE0[i] | 0x373D0000;
            }
            func_800C0224(0x80, temp_s3 + D_800EBC88[3 - i], 0x100010, D_1F800000[2])[4] =
                (((3 - i) * 0x10) | 0x37FB8000);
        }
    }
    D_800EBC78 = 0;
}

// https://decomp.me/scratch/NSW3O
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CA2DC);

void func_800CA97C(void)
{
    D_800EB9B4 = NULL;
    memset(&D_800F4ED8, 0, sizeof D_800F4ED8);
    D_800F4ED8[2] = 0x1000;
}

void func_800CA9C0(void* arg0)
{
    D_800EB9AC = 0;
    D_800EB9AD = 0;
    D_800EB9AE = 0;
    D_800EB9B0 = 0;
    D_800F4ED4 = 0;
    D_800EB9B4 = 0;
    D_800EB9B8 = 0;
    D_800EB9BC = 0;
    vs_battle_menuItems = 0;
    D_800EB9CE = 0;
    D_800F4E90 = 0;
    D_800EB9AF = 0;
    D_800EB9CC = 0;
    D_800EB9CD = 0;
    D_800EB9D0.s32 = 0xFFFFFF;
    D_800EB9D4 = 0;
    D_800EB9D8 = 0;
    func_800CA97C();
    vs_battle_rMemzero(&vs_battle_menuState, 8);
    vs_battle_menuState.currentState = 0x3F;
    vs_battle_rMemzero(&D_800F4E98, sizeof(D_800F4E98));
    vs_battle_rMemzero(&vs_battle_textBoxes[0], sizeof(vs_battle_textBoxes[0]));
    vs_battle_rMemzero(D_800F4E70, sizeof(D_800F4E70));
    D_800F4EE8 = (D_800F4EE8_t) { { 0 } };
    D_800F51B8 = &D_800F4CD0;
    vs_battle_drawImage(0x340, arg0, 0xE00040);
    vs_battle_drawImage(0x380, arg0 + 0x7000, 0xE00040);
    vs_battle_drawImage(0x4203C0, arg0 + 0xE000, 0x9E0040);
    DrawSync(0);
    ClearOTag(D_800F51B8, 0x22);
}

void func_800CAB40(void)
{
    D_800F4E98.unk2 = 0;
    D_800F4E98.unk0 = 1;
    if (vs_battle_shortcutInvoked == 5) {
        vs_battle_menuState.currentState = 4;
        func_800FAEBC(2);
    } else {
        vs_battle_menuState.currentState = vs_battle_menuState.returnState;
        D_800F4E70[vs_battle_menuState.returnState & 0xF] = vs_battle_menuState.unk2;
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

    if (!(vs_battle_characterState->unk44->unk8 & 0x800000)) {
        var_a0 |= 8;
    }

    ret = var_a0;

    if (actor->currentMP == 0) {
        ret |= 0x20;
    }

    if (actor->currentHP == 0) {
        ret |= 0x40;
    }

    if (actor->unk948 & 0x1001) {
        ret |= 0x80;
    }

    if (actor->unk948 & 0x2000) {
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

    if (vs_battle_menuState.currentState == 0x3F) {
        vs_battle_shortcutInvoked = 0;
        D_800F4FDB = 0;
        D_800F4EA0 = func_800CABE0(arg1);
        D_800F4E98.unk2 = 0;
        vs_battle_menuState.currentState = menuState;
        D_800F4E98.unk0 = 1;

        if (arg1 == 0) {
            vs_battle_playSfx10();
        }

        if (vs_battle_menuItems == 0) {
            D_800EB9AD = -1;

            func_8007E180(6);

            miscIndex = vs_main_allocHeapR(0xB24);
            var_a1 = vs_main_settings.menuFlags;
            vs_battle_stringBuf = miscIndex + 0xA00;
            vs_battle_menuItems = miscIndex;
            vs_battle_rowTypeBuf = miscIndex + 0xA60;

            for (i = 0; i < 3; ++i) {
                for (var_a0 = D_800EBD68[i * 2]; var_a0 < D_800EBD68[i * 2 + 1];
                     ++var_a0) {
                    if (vs_main_skills[var_a0].unlocked) {
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

int vs_battle_spellClassUnlocked(int spellClass)
{
    int i;

    for (i = 0; i < _spellClassCounts[spellClass]; ++i) {
        if (vs_main_skills[_spellIds[spellClass][i]].unlocked) {
            return 1;
        }
    }
    return 0;
}

int _breakArtsUnlocked(void)
{
    int i;
    for (i = 0; i < 4; ++i) {
        if ((vs_main_skills[0xB8
                            + ((vs_battle_characterState->equippedWeaponCategory - 1) * 4)
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
    vs_skill_t* v0;

    for (i = 0; i < 14; ++i) {
        v0 = vs_main_skills;
        if (v0[defense == 0 ? vs_battle_chainAbilityOffsets[i]
                            : vs_battle_defenseAbilityOffsets[i]]
                .unlocked) {
            return 1;
        }
    }
    return 0;
}

int _validateShortcutSelection(int shortcut)
{
    int noneUnlocked = 0;
    int menuState = 0;

    switch (shortcut) {
    case 1:
    case 2:
    case 3:
    case 4:
        noneUnlocked = vs_battle_spellClassUnlocked(shortcut - 1) == 0;
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

void func_800CB208(int art, int battleAbility)
{
    D_800F4E88 = art;
    D_800F4FDA = battleAbility;
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
    vs_battle_stringContext.strings[0] = vs_main_skills[arg1].name;

    if (arg0 == 12) {
        vs_battle_printf((char*)&D_800EB9D8[1],
            (char*)&vs_battle_menuStrings[VS_menuStrings_OFFSET_spellMastered]);
    } else if (arg0 == 11) {
        vs_battle_textBoxes[7].unk0.unk0_8 = 0;
        vs_battle_printf((char*)&D_800EB9D8[1],
            (char*)&vs_battle_menuStrings[vs_battle_menuStrings[vs_main_skills[arg1].type
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

        if (!((D_800F5130 >> 0x1E) & 1)) {
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

void func_800CB550(void) { D_800F4E90 = 1; }

void func_800CB560(void) { D_800F4E90 = 0; }

char const D_80069998[] = "00:00:00";

void _renderTimer(int* value)
{
    char sp10[4];
    int i;

    *(int*)sp10 = *value;
    sp10[0] = vs_main_stateFlags.unkA0;

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

    vs_battle_renderTextRaw(D_800EC258, vs_getXY(128, 200), D_1F800000[1] - 1);
}

void func_800CB654(int arg0) { D_800EB9AF = arg0; }

void func_800CB660(int arg0) { D_800EB9CC = arg0; }

D_800F4E98_t* func_800CB66C(void) { return &D_800F4E98; }

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
        if (temp_s0->unk4 != 0x1000) {
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB83C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CBBCC);

void func_800CC128(u_char* arg0, int arg1, u_long* arg2)
{
    int var_s1;
    int new_var;

    int temp_s0 = arg0[3];

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CC204);

void func_800CC580(u_long* arg0, int arg1)
{
    func_800CCCB8(arg0, arg1 | 0xE3040000, (arg1 + 0x3F) | 0xE407FC00, arg1 | 0xE5080000);
}

void func_800CC5C0(u_long* arg0, int arg1)
{
    func_800CCCB8(
        arg0, arg1 | 0xE3000000, (arg1 + 0x13F) | 0xE403BC00, arg1 | 0xE5000000);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CC600);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCA90);

int vs_battle_decreaseMiscCount(int miscId)
{
    int i;

    if (miscId < 0x143) {
        D_800F5210 = 0;
    }

    for (i = 0; i < 64; ++i) {
        int miscIndex = (D_800F5210 + i) & 0x3F;
        if (vs_battle_inventory.misc[miscIndex].id == miscId) {
            int count = vs_battle_inventory.misc[miscIndex].count - 1;
            vs_battle_inventory.misc[miscIndex].count = count;
            if (count == 0) {
                vs_battle_inventory.misc[miscIndex].id = 0;
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

int vs_battle_toBCD(int arg0) { return (arg0 % 10) | ((arg0 / 10) * 16); }

u_int vs_battle_keystreamBits(int value)
{
    u_int temp_a1 = _keystreamState;
    _keystreamState = temp_a1 * 0x19660D;
    return temp_a1 >> (32 - value);
}

void func_800CCCB8(u_long* arg0, int arg1, int arg2, int arg3)
{
    u_long* temp_v1;

    temp_v1 = D_1F800000[0];
    temp_v1[0] = (int)((*arg0 & 0xFFFFFF) | 0x03000000);
    temp_v1[1] = arg1;
    temp_v1[2] = arg2;
    temp_v1[3] = arg3;
    *arg0 = ((u_long)temp_v1 << 8) >> 8;
    D_1F800000[0] = temp_v1 + 4;
}

void func_800CCD00(int arg0, u_long* arg1)
{
    u_long* temp_v1;

    temp_v1 = D_1F800000[0];
    temp_v1[0] = (int)((*arg1 & 0xFFFFFF) | 0x01000000);
    temp_v1[1] = arg0;
    *arg1 = (u_int)((int)temp_v1 << 8) >> 8;
    D_1F800000[0] = temp_v1 + 2;
}

int vs_battle_drawCursor(int animStep, int position)
{
    func_800C0224(D_800EC270[animStep], (((position * 0x10) + 0xA) << 0x10) | 0xB4,
        0x100010, D_1F800000[2])[4] = 0x37F83020;
    return (animStep + 1) & 0xF;
}

void vs_battle_drawImage(int xy, void* buffer, int wh)
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCE10);

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
        func_800C0214(D_800EC2CC[arg1], (arg0 << 0x10) | 0xA)[4] = D_800EC2D8[arg1];
    }
}

// https://decomp.me/scratch/qBmPY
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD158);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD3E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CDCBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE174);

int func_800CE644(int arg0 __attribute__((unused))) { }

void func_800CE64C(void)
{
    func_800CE67C();
    func_800D7814();
    func_800D268C();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE67C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE714);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE83C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE8F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE9B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CED60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEEBC);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEF74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF060);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF0E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF1A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF218);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF3F8);

char func_800CF458(void) { return func_800CF218(); }

void func_800CF478(int arg0) { D_800F531C = arg0; }

void func_800CF484(int arg0, D_800F53B8_t* arg1) { arg1->unkD1C.unk1C.unk1E = arg0; }

int func_800CF48C(void) { return D_800F531C; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF49C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF514);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF55C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF614);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF694);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF70C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF7A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF830);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF8BC);

void func_800CF920(void) { D_800F522C = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF92C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF988);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFAAC);

int func_800CFB68(int arg0, int arg1, int arg2)
{
    return (((arg1 - arg0) * arg2) >> 7) + arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFB80);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFBF8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFC48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFC8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFCF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFD60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFDD0);

int func_800CFE1C(func_800CFE1C_t* arg0, int arg1)
{
    int new_var = arg0->unk0;
    return (((arg0->unk2 - new_var) * arg1) >> 7) + new_var;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFE40);

void func_800CFE7C(int* arg0)
{
    arg0[4] = 0x1000;
    arg0[2] = 0x1000;
    arg0[0] = 0x1000;
    arg0[3] = 0;
    arg0[1] = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFE98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFEF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D01E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D037C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0548);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D05F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0984);

void func_800D0B08(int arg0) { func_800CFE98(D_800F5310, arg0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0B30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0C60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0D08);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1104);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D118C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D11F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D12D8);

int vs_battle_lerpRatio(int arg0, int arg1, int arg2, int arg3)
{
    int var_v0 = (arg1 - arg0) * ((arg2 * ONE) / arg3);
    return arg0 + var_v0 / ONE;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1390);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D155C);

int vs_battle_lerp(int arg0, int arg1, int arg2)
{
    int var_v0 = (arg1 - arg0) * arg2;
    return arg0 + (var_v0 / (ONE * 2));
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D169C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1718);

void func_800D1778(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    func_800D169C(arg0, arg1, (arg3 * (ONE * 2)) / arg2, arg4);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D17A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1824);

void func_800D1884(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    func_800D17A8(arg0, arg1, (arg3 * (ONE * 2)) / arg2, arg4);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D18B4);

void func_800D1904(int arg0, int arg1, int arg2, int arg3)
{
    vs_battle_lerp(arg0, arg1, (arg3 * (ONE * 2)) / arg2);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1930);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D197C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1B18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1B80);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1E2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1E78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1EF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1FEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D206C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D21C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D236C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2518);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2560);

void func_800D268C(void) { D_800F5600 = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2698);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D278C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D27F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2888);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2904);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2970);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D29B0);

void func_800D29F0(short* arg0, int* arg1)
{
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
}

void func_800D2A14(u_short* arg0, u_short* arg1)
{
    arg1[0] = arg0[0];
    arg1[1] = arg0[2];
    arg1[2] = arg0[4];
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2A38);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2ADC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D46DC);

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
    sp10.unk18 = func_800D5198(arg0) & 0xFFFF;
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

    temp_s2 = func_800D5170(arg0) & 0xFF;
    temp_s0 = func_800D5198(arg0) & 0xFFFF;
    temp_s0 = temp_s0 + (func_800D5198(arg0) << 0x10);

    if (arg0->unkD1C.unk1C.unk20 != 0) {
        temp_s0 = arg0->unkD1C.unk1C.unk20;
    }

    func_800CF694(arg0, D_800EC324[temp_s2], temp_s0);
    return 1;
}

int func_800D487C(D_800F53B8_t* arg0)
{
    func_800D46DC(arg0->unkD1C.unk1C.unk18 == 0, arg0);
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

void func_800CF70C(D_800F53B8_t*, void*);

int func_800D4910(D_800F53B8_t* arg0)
{
    func_800D4910_t* var_s0 = arg0->unkD1C.unk1C.unk18;

    while (var_s0 != 0) {
        func_800D4910_t* s1 = var_s0->next;
        if (var_s0->unk4(var_s0, 2, 0) == 0) {
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

int func_800D49A4(D_800F53B8_t* arg0);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D49A4);

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
    func_800D2ADC(arg0, arg0->unk10[func_800D5170(arg0)], 0, 0, 0);
    return 1;
}

int func_800D4C18(D_800F53B8_t* arg0);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4C18);

int func_800D4D44(D_800F53B8_t* arg0 __attribute__((unused)))
{
    func_800D78F0();
    return 1;
}

int func_800D4D64(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk0 == 4) {
        func_8006CDB8(arg0->unkD1C.unk4);
    }
    return 1;
}

int func_800D4D98(D_800F53B8_t* arg0 __attribute__((unused)))
{
    D_800F522C = 0;
    return 1;
}

int func_800D4DA8(D_800F53B8_t* arg0 __attribute__((unused))) { return 1; }

int func_800D4DB0(D_800F53B8_t* arg0);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4DB0);

int func_800D4E5C(D_800F53B8_t* arg0)
{
    func_800D6AEC(arg0, func_800D5198(arg0));
    return 1;
}

int func_800D4E90(D_800F53B8_t* arg0)
{
    func_800D46DC(arg0->unkD1C.unk1C.unk14->unk4 == 0, arg0);
    return 1;
}

int func_800D4EC0(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk1C.unk14 != NULL) {
        vs_main_freeHeapR(arg0->unkD1C.unk1C.unk14);
        arg0->unkD1C.unk1C.unk14 = NULL;
    }
    return 1;
}

int func_800D4F00(D_800F53B8_t* arg0);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4F00);

int func_800D4FB4(D_800F53B8_t* arg0);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4FB4);

int func_800D5048(D_800F53B8_t* arg0)
{
    if (arg0->unk4 != 0) {
        --arg0->unk4->unk14_11;
    }
    return 1;
}

int func_800D5088(D_800F53B8_t* arg0);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5088);

int func_800D5150(D_800F53B8_t* arg0 __attribute__((unused)))
{
    return func_800CE644(0x1E);
}

u_char func_800D5170(D_800F53B8_t* arg0) { return arg0->unkC[arg0->unkA++]; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5198);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D52A4);

void* func_800D5550(u_short* arg0, int arg1)
{
    u_short* v = arg0 + arg1;
    return (char*)arg0 + v[2];
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5564);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D55A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5700);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5738);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5780);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D57FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5904);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5A98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5D74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5E00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5F8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6048);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D61AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6298);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6310);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6388);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D63D0);

void func_800D6418(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk18 == 5) {
        func_8006CDD8(&arg0->unkD1C.unk1C);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6448);

void func_800D64E4(void) { func_800CF830(0, 0); }

void func_800D6508(func_800D6508_t* arg0, char arg1)
{
    arg0 += arg1;
    arg0->unk22_2 = 1;
}

void func_800D6538(D_800F53B8_t* arg0) { arg0->unkD1C.unk1C.unk14->unk1 |= 1; }

void func_800D6554(void) { func_8006CE50(); }

void func_800D6574(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk0 == 4) {
        func_8006CDB8(arg0->unkD1C.unk4);
    }
}

void func_800D65A8(func_800D6508_t* arg0, char arg1)
{
    arg0 += arg1;
    arg0->unk22_0 = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D65D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6628);

void func_800D66CC(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk18 == 5) {
        func_8006CE70(&arg0->unkD1C.unk1C);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D66FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D67C4);

void func_800D6860(D_800F53B8_t* arg0)
{
    if (arg0->unkD1C.unk1C.unk8 == 4) {
        func_80069C6C(arg0->unkD1C.unk1C.unkC);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6894);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6A18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6AEC);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6CF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6D24);

void func_800D6E24(void) { func_800D6E44(); }
