#include "common.h"
#include "build/src/include/lbas.h"
#include "146C.h"
#include "573B8.h"
#include "../SLUS_010.40/main.h"

extern u_char D_800E9C30[];
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

extern MATRIX D_1F800014_mat;
extern char D_800F4B70[];

void func_800BBDDC(void);
void func_8007D260(int arg0);
int func_800A0204(int, int, int, int);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFBB8);

void func_800BFD9C(void)
{
    int i;

    for (i = 0; i < 17; ++i) {
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800BFEBC);

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

/* Hand-written too, and it has to be: vs_battle_copyAligned above branches
 * straight into it, and its `jr $ra` carries no delay slot of its own, so the
 * first instruction of vs_battle_setSpriteDefault below runs as one. Copies
 * four shorts per iteration until src reaches src + numBytes. */
__asm__("glabel vs_battle_memcpy;"
        "addu      $a2, $a1, $a2;"
        ".L800C01E4:;"
        "lh        $t0, 0x0($a1);"
        "lh        $t1, 0x2($a1);"
        "lh        $t2, 0x4($a1);"
        "lh        $t3, 0x6($a1);"
        "addiu     $a1, $a1, 0x8;"
        "sh        $t0, 0x0($a0);"
        "sh        $t1, 0x2($a0);"
        "sh        $t2, 0x4($a0);"
        "sh        $t3, 0x6($a0);"
        "bne       $a1, $a2, .L800C01E4;"
        "addiu     $a0, $a0, 0x8;"
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

/* Hand-written, like the blocks around it, not compiler output: it makes two
 * calls out of an 8-byte frame. Every function in this project that the
 * compiler produced reserves at least 0x18 when it calls anything, because gcc
 * always lays down the 0x10 outgoing-argument area. Trying to match it from C
 * costs a session; the closest C gets is `SetRotMatrix(&D_1F800014_mat);
 * SetTransMatrix(&D_1F800014_mat);`, which CSEs the address into `s0`. */
__asm__("glabel func_800C02A8;"
        "addiu     $sp, $sp, -0x8;"
        "sw        $ra, ($sp);"
        "lui       $a0, %hi(D_1F800014_mat);"
        "jal       SetRotMatrix;"
        "addiu     $a0, $a0, %lo(D_1F800014_mat);"
        "lui       $a0, %hi(D_1F800014_mat);"
        "jal       SetTransMatrix;"
        "addiu     $a0, $a0, %lo(D_1F800014_mat);"
        "lw        $ra, ($sp);"
        "nop;"
        "jr        $ra;"
        "addiu     $sp, $sp, 0x8;"
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C031C);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0758);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C085C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0990);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/573B8", func_800C0B50);
