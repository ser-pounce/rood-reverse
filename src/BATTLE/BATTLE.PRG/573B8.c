#include "common.h"
#include "146C.h"
#include "573B8.h"
#include "4A0A8.h"
#include "src/SLUS_010.40/main.h"
#include "build/src/include/lbas.h"

extern u_char D_800E9C30[];
extern unsigned char D_800F4B70[17];
extern vs_main_CdQueueSlot* D_800F4BBC;
extern vs_main_CdFile D_800F4BF0;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    int unk4;
    int unk8;
    int unkC;
} D_800EB9B8_t2;

typedef struct {
    D_800EB9B8_t2 unk0;
    D_800EB9B8_t2 unk10;
    int unk20;
    short unk24;
    short unk26;
    short unk28;
    short unk2A;
    char unk2C;
    char unk2D;
    u_char unk2E;
    char unk2F;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
} D_800EB9B8_t;

extern D_800EB9B8_t* D_800EB9B8;
extern u_char D_800EB9AC;

extern void func_8007D260(int);
void func_800A0204(int, int, int, int);
extern void func_800BBDDC(void);

typedef int (*eventOpcodeHandler)(u_char*, int);
extern eventOpcodeHandler _opcodeFunctionTable[];
extern u_char D_800F4C20, D_800F4C2C, D_800F4C68;
extern short D_800F4C58[];
extern char vs_battle_textBoxStatuses[];
int func_800BFE34(u_char*);
void func_800C0150(void);

int func_800BFBB8(u_char** cursor, short actor)
{
    u_char* script = *cursor;
    int result;
    if (actor == 0 && D_800F4C2C == 1) {
        if ((vs_main_buttonsPressed.all & 0x800) || D_800F4C68) {
            D_800F4C68 = 0;
            D_800F4C58[0] = D_800F4C58[1] = D_800F4C58[2] = D_800F4C58[3] = 0;
            vs_battle_textBoxStatuses[0] = vs_battle_textBoxStatuses[1] =
                vs_battle_textBoxStatuses[2] = vs_battle_textBoxStatuses[3] = 0;
            if (D_800F4C20)
                func_80044DF4(0);
            func_80045DC0();
            func_800434A4(0, 2);
            func_800C0150();
            func_8007C46C(0, 255, 0);
            func_8007C424();
            vs_battle_setStateFlag(0xA8, 1);
            D_800F4C2C = 2;
        }
    }
    while (1) {
        if (D_800F4C2C != 2)
            result = _opcodeFunctionTable[*script](script, actor);
        else
            result = ((eventOpcodeHandler*)D_800F4C28)[*script](script, actor);
        switch (result) {
        case 0:
            script += func_800BFE34(script);
            break;
        case 3:
            *cursor = NULL;
            goto done;
        case 2:
            return 1;
        case 4:
            script += func_800BFE34(script);
            goto save;
        case 1:
            goto save;
        default:
            script = (u_char*)result;
        }
    }
save:
    *cursor = script;
done:
    return 0;
}

void func_800BFD9C(void)
{
    int i;

    for (i = 0; i < 17; i++) {
        if (D_800F4B70[i] != 0) {
            func_8007D260(i);
        }
    }

    func_800BBDDC();
}

short vs_battle_getShort(u_char* arg0)
{
    if (!((long)arg0 & 1)) {
        return *(short*)arg0;
    }
    return arg0[0] | (arg0[1] << 8);
}

int func_800BFE34(u_char* arg0) { return D_800E9C30[arg0[0]]; }

int func_800BFE50(u_short arg0)
{
    switch (arg0 >> 12) {
    case 0:
        return func_8007CF18(arg0 & 0xFFF);
    case 1:
        return arg0 & 0x1F;
    case 2:
        return arg0;
    }
}

extern signed char D_800F4B28[][2];

int func_800BFEBC(short mode, short frame, short duration)
{
    short position = frame;
    int value, power, i, magnitude;
    if (frame > duration)
        position = duration;
    switch (mode) {
    case 0:
        return (position << 12) / duration;
    case 1:
        return rsin((position << 10) / duration);
    case 2:
        return (rcos((position << 11) / duration + 0x800) + 0x1000) >> 1;
    case 3:
        return rsin((position << 10) / duration - 0x400) + 0x1000;
    default:
        mode -= 4;
        power = D_800F4B28[mode][1];
        value = (position << 12) / duration;
        if (power != 0) {
            if (power > 0) {
                for (i = 0; i < power; ++i)
                    value = (value * value) >> 12;
            } else {
                value = 0x1000 - value;
                magnitude = -power;
                for (i = 0; i < magnitude; ++i)
                    value = (value * value) >> 12;
                value = 0x1000 - value;
            }
        }
        switch ((int)(u_char)D_800F4B28[mode][0]) {
        case 1:
            return rsin(value / 4);
        case 2:
            return (rcos(value / 2 + 0x800) + 0x1000) >> 1;
        case 3:
            return rsin(value / 4 - 0x400) + 0x1000;
        case 0:
        default:
            return value;
        }
    }
}

void func_800C00E8(int arg0, void* arg1)
{
    D_800F4BF0.size = VS_0000_EVT_SIZE;
    D_800F4BF0.lba = (_evtFile * 3) + VS_0000_EVT_LBA; // .EVT files must be sequential
    D_800F4BBC = vs_main_allocateCdQueueSlot(&D_800F4BF0);
    vs_main_cdEnqueue(D_800F4BBC, arg1);
}

void func_800C0150(void)
{
    short i;

    for (i = 0; i < 17; ++i) {
        if (func_8007CF64(i) != NULL) {
            func_800A0204(i, 1, 0, 0);
        }
    }
}

__asm__("glabel vs_battle_copyAligned;"
        "and       $t0, $a2, 0x7;"
        "beqz      $t0, vs_battle_memcpy;"
        "lh        $t0, ($a1);"
        "addu      $a1, 2;"
        "sh        $t0, ($a0);"
        "addu      $a0, 2;"
        "j         vs_battle_copyAligned;"
        "add       $a2, -2;"
        "endlabel vs_battle_copyAligned;");

__asm__("glabel vs_battle_memcpy;"
        "addu      $a2, $a1, $a2;"
        "0:;"
        "lh        $t0, ($a1);"
        "lh        $t1, 2($a1);"
        "lh        $t2, 4($a1);"
        "lh        $t3, 6($a1);"
        "addu      $a1, 8;"
        "sh        $t0, ($a0);"
        "sh        $t1, 2($a0);"
        "sh        $t2, 4($a0);"
        "sh        $t3, 6($a0);"
        "bne       $a1, $a2, 0b;"
        "addu      $a0, 8;"
        "jr        $ra;"
        "endlabel vs_battle_memcpy;");

__asm__("glabel vs_battle_setSpriteDefault;"
        "lui      $v1, 0x1F80;"
        "addu     $a2, $a0, $zero;"
        "li       $a0, 0x80;"
        "lw       $a3, 0x8($v1);"
        "alabel vs_battle_setSpriteDefaultTexPage;"
        "lui      $t1, 0xE100;"
        "j        .L800C0234;"
        "or       $t1, 0xC;"
        "endlabel vs_battle_setSpriteDefault;"

        "glabel vs_battle_setSprite;"
        "addu       $t1, $zero, $zero;"
        ".L800C0234:;"
        "lw         $t0, ($a3);"
        "lui        $v1, 0x1F80;"
        "lui        $t2, 0x500;"
        "lw         $v0, ($v1);"
        "sll        $t0, 8;"
        "srl        $t0, 8;"
        "or         $t0, $t2;"
        "and        $t3, $a0, 0xFF;"
        "sll        $t4, $t3, 8;"
        "or         $t2, $t3, $t4;"
        "sll        $t3, 16;"
        "or         $t2, $t3;"
        "srl        $t3, $a0, 7;"
        "and        $t3, 0x2;"
        "addu       $t3, 100;"
        "sll        $t3, 24;"
        "or         $t2, $t3;"
        "sll        $t3, $v0, 8;"
        "srl        $t3, 8;"
        "addiu      $t4, $v0, 0x18;"
        "sw         $t0, ($v0);"
        "sw         $t1, 0x4($v0);"
        "sw         $t2, 0x8($v0);"
        "sw         $a1, 0xC($v0);"
        "sw         $zero, 0x10($v0);"
        "sw         $a2, 0x14($v0);"
        "sw         $t3, ($a3);"
        "j          $ra;"
        "sw         $t4, ($v1);"
        "endlabel vs_battle_setSprite;");

__asm__("glabel func_800C02A8;"
        "addu     $sp, -0x8;"
        "sw       $ra, ($sp);"
        "lui      $a0, 0x1F80;"
        "jal      SetRotMatrix;"
        "addu     $a0, 0x14;"
        "lui      $a0, 0x1F80;"
        "jal      SetTransMatrix;"
        "addu     $a0, 0x14;"
        "lw       $ra, ($sp);"
        ".nop;"
        "j        $ra;"
        "addu     $sp, 0x8;"
        "endlabel func_800C02A8;");

__asm__("glabel vs_battle_playSfx10;"
        "j         .L800C02FC;"
        "li        $a1, 10;"
        "endlabel  vs_battle_playSfx10;"

        "glabel vs_battle_playInvalidSfx;"
        "j         .L800C02FC;"
        "li        $a1, 7;"
        "endlabel  vs_battle_playInvalidSfx;"

        "glabel vs_battle_playMenuLeaveSfx;"
        "j         .L800C02FC;"
        "li        $a1, 6;"
        "endlabel  vs_battle_playMenuLeaveSfx;"

        "glabel vs_battle_playMenuSelectSfx;"
        "j         .L800C02FC;"
        "li        $a1, 5;"
        "endlabel  vs_battle_playMenuSelectSfx;"

        "glabel vs_battle_playMenuChangeSfx;"
        "li       $a1, 0x4;"
        ".L800C02FC:;"
        "addu     $sp, -0x8;"
        "sw       $ra, ($sp);"
        "jal      vs_main_playSfxDefault;"
        "li       $a0, 0x7E;"
        "lw       $ra, ($sp);"
        ".nop;"
        "j        $ra;"
        "addu     $sp, 0x8;"
        "endlabel vs_battle_playMenuChangeSfx;");

void vs_battle_rMemzero(void*, int);

void func_800C031C(void)
{
    int index;
    int x, y;
    short* edges;
    if (D_800EB9B8 == NULL)
        D_800EB9B8 = vs_main_allocHeap(0x4B1C);
    vs_battle_rMemzero(D_800EB9B8, 0x4B1C);
    index = 0;
    D_800EB9B8->unk2D = -1;
    edges = (short*)((char*)D_800EB9B8 + 0x44B4);
    for (y = 0;; ++y) {
        for (x = 0; x < 9; ++x)
            edges[index++] = x + (y << 4) + ((x + 1) << 8) + (y << 12);
        if (y == 9)
            break;
        for (x = 0; x < 10; ++x)
            edges[index++] = x + (y << 4) + (x << 8) + ((y + 1) << 12);
    }
    for (x = 0;; ++x) {
        for (y = 9; y > 0; --y)
            edges[index++] = x + (y << 4) + (x << 8) + ((y - 1) << 12);
        if (x == 9)
            break;
        for (y = 9; y >= 0; --y)
            edges[index++] = x + (y << 4) + ((x + 1) << 8) + (y << 12);
    }
    for (y = 9;; --y) {
        for (x = 9; x > 0; --x)
            edges[index++] = x + (y << 4) + ((x - 1) << 8) + (y << 12);
        if (y == 0)
            break;
        for (x = 9; x >= 0; --x)
            edges[index++] = x + (y << 4) + (x << 8) + ((y - 1) << 12);
    }
    for (x = 9;; --x) {
        for (y = 0; y < 9; ++y)
            edges[index++] = x + (y << 4) + (x << 8) + ((y + 1) << 12);
        if (x == 0)
            break;
        for (y = 0; y < 10; ++y)
            edges[index++] = x + (y << 4) + ((x - 1) << 8) + (y << 12);
    }
}

void func_800C05B4(void)
{
    if (D_800EB9B8 != NULL) {
        vs_main_freeHeap(D_800EB9B8);
        D_800EB9B8 = NULL;
    }
}

void func_800C05EC(D_800EB9B8_t2* arg0, D_800EB9B8_t2* arg1, u_char arg2, int arg3)
{
    D_800EB9B8->unk0 = *arg0;

    if (arg0->unk0 != 1) {
        D_800EB9B8->unk24 = 0;
        D_800EB9B8->unk28 = 0;
    }

    if (D_800EB9AC != 0) {
        D_800EB9B8->unk0.unk0 |= 0x80;
        D_800EB9B8->unk10.unk0 = arg1->unk0;
        D_800EB9AC = 0;
        return;
    }

    D_800EB9B8->unk38 = 0;
    D_800EB9B8->unk3C = 0;
    D_800EB9B8->unk2A = 0xF;

    if (arg1 != NULL) {
        D_800EB9B8->unk10 = *arg1;
        D_800EB9B8->unk10.unk0 |= 0x80;
        D_800EB9B8->unk2E = arg2;
        D_800EB9B8->unk44 = arg3;
        return;
    }

    D_800EB9B8->unk10.unk0 = 0;
}

void func_800C06E0(void)
{
    if (D_800EB9B8 != NULL) {
        D_800EB9B8->unk0.unk0 = 0;
    }
}

void func_800C0700(D_800EB9B8_t2* arg0)
{
    D_800EB9B8->unk10 = *arg0;
    D_800EB9B8->unk2A = 0;
}

void func_800C0738(void)
{
    if (D_800EB9B8 != NULL) {
        D_800EB9B8->unk10.unk0 = 0;
    }
}

typedef struct {
    short xyz[3];
    short flags;
} menuCurveVertex;

int func_800C0758(int phase, int segments, int index)
{
    short* trig = (short*)0x1F8003B0;
    short (*basis)[4] = (void*)0x1F800398;
    int i, component;
    menuCurveVertex* vertex = (void*)((char*)D_800EB9B8 + 0x48 + index * 8);
    for (i = 0; i <= segments; ++index, ++i, ++vertex) {
        for (component = 0; component < 3; ++component) {
            vertex->xyz[component] =
                basis[0][component]
                + ((basis[1][component] * trig[(i + phase + 8) & 31]) >> 12)
                + ((basis[2][component] * trig[(i + phase) & 31]) >> 12);
        }
        component = i != 0;
        if (component && segments != 32)
            component += segments - i < 2;
        vertex->flags = component;
    }
    return index;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C085C);

extern u_char D_80040A14[];

void func_800C0990(SVECTOR* start, SVECTOR* end, u_int color, int intensity)
{
    int depth = (start->vz + end->vz) >> 1;
    int dx, dy, ax, ay, angle, shift;
    u_long link;
    u_long* primitive;
    u_long* orderingTable;
    if ((u_int)depth >= 2048)
        return;
    dy = end->vy - start->vy;
    dx = end->vx - start->vx;
    angle = 0;
    shift = dy | dx;
    if (shift) {
        ax = dx;
        ay = dy;
        if (ax < 0)
            ax = -ax;
        if (ay < 0)
            ay = -ay;
        shift = 512;
        if (ax < ay) {
            angle = ax << 9;
            angle /= ay;
            angle = D_80040A14[angle];
            angle = shift - angle;
        } else {
            angle = ay << 9;
            angle /= ax;
            angle = D_80040A14[angle];
        }
        shift = 1024;
        if (ax != dx)
            angle = shift - angle;
        angle *= 2;
        if (ay != dy)
            angle = -angle;
    }
    shift = 30 - (((angle + 256) >> 8) & 14);
    ay = start->vx + ((0x4FC5 << shift) >> 30);
    ax = start->vy + ((0xFC54 << shift) >> 30);
    if (intensity < 0)
        intensity = 0;
    else if (intensity >= 64)
        intensity = 63;
    primitive = vs_scratch.unk0;
    orderingTable = (u_long*)vs_scratch.unk4 + depth;
    link = *orderingTable;
    link &= 0xFFFFFF;
    primitive[1] = 0xE1000200;
    primitive[3] = (ay & 0xFFFF) | (ax << 16);
    primitive[0] = link | 0x04000000;
    primitive[2] = (((color << 8) >> 8) * intensity) | ((color >> 24) << 24);
    primitive[4] = *(u_long*)end;
    *orderingTable = ((u_int)primitive << 8) >> 8;
    vs_scratch.unk0 = primitive + 5;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0B50);
