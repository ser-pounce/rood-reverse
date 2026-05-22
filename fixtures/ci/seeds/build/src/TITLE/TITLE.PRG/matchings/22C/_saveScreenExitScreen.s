nonmatching _saveScreenExitScreen, 0xC8

glabel _saveScreenExitScreen
    /* 64F4 8006ECF4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 64F8 8006ECF8 00010424 */  addiu      $a0, $zero, 0x100
    /* 64FC 8006ECFC 21280000 */  addu       $a1, $zero, $zero
    /* 6500 8006ED00 E000063C */  lui        $a2, (0xE00040 >> 16)
    /* 6504 8006ED04 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6508 8006ED08 0E80113C */  lui        $s1, %hi(_frameBuf)
    /* 650C 8006ED0C 76ED2292 */  lbu        $v0, %lo(_frameBuf)($s1)
    /* 6510 8006ED10 4000C634 */  ori        $a2, $a2, (0xE00040 & 0xFFFF)
    /* 6514 8006ED14 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6518 8006ED18 01001024 */  addiu      $s0, $zero, 0x1
    /* 651C 8006ED1C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6520 8006ED20 23100202 */  subu       $v0, $s0, $v0
    /* 6524 8006ED24 80380200 */  sll        $a3, $v0, 2
    /* 6528 8006ED28 2138E200 */  addu       $a3, $a3, $v0
    /* 652C 8006ED2C 80390700 */  sll        $a3, $a3, 6
    /* 6530 8006ED30 2138E400 */  addu       $a3, $a3, $a0
    /* 6534 8006ED34 FF03E730 */  andi       $a3, $a3, 0x3FF
    /* 6538 8006ED38 83390700 */  sra        $a3, $a3, 6
    /* 653C 8006ED3C DEA9010C */  jal        _drawSprt
    /* 6540 8006ED40 4001E734 */   ori       $a3, $a3, 0x140
    /* 6544 8006ED44 21200000 */  addu       $a0, $zero, $zero
    /* 6548 8006ED48 21288000 */  addu       $a1, $a0, $zero
    /* 654C 8006ED4C E000063C */  lui        $a2, (0xE00100 >> 16)
    /* 6550 8006ED50 76ED2292 */  lbu        $v0, %lo(_frameBuf)($s1)
    /* 6554 8006ED54 0001C634 */  ori        $a2, $a2, (0xE00100 & 0xFFFF)
    /* 6558 8006ED58 23800202 */  subu       $s0, $s0, $v0
    /* 655C 8006ED5C 80381000 */  sll        $a3, $s0, 2
    /* 6560 8006ED60 2138F000 */  addu       $a3, $a3, $s0
    /* 6564 8006ED64 0F00E730 */  andi       $a3, $a3, 0xF
    /* 6568 8006ED68 DEA9010C */  jal        _drawSprt
    /* 656C 8006ED6C 4001E734 */   ori       $a3, $a3, 0x140
    /* 6570 8006ED70 94A1000C */  jal        DrawSync
    /* 6574 8006ED74 21200000 */   addu      $a0, $zero, $zero
    /* 6578 8006ED78 0862053C */  lui        $a1, (0x62080808 >> 16)
    /* 657C 8006ED7C 0808A534 */  ori        $a1, $a1, (0x62080808 & 0xFFFF)
    /* 6580 8006ED80 E000063C */  lui        $a2, (0xE00140 >> 16)
    /* 6584 8006ED84 4001C634 */  ori        $a2, $a2, (0xE00140 & 0xFFFF)
    /* 6588 8006ED88 0E80033C */  lui        $v1, %hi(_primBuf)
    /* 658C 8006ED8C 28ED6424 */  addiu      $a0, $v1, %lo(_primBuf)
    /* 6590 8006ED90 0003023C */  lui        $v0, (0x3000000 >> 16)
    /* 6594 8006ED94 28ED62AC */  sw         $v0, %lo(_primBuf)($v1)
    /* 6598 8006ED98 040085AC */  sw         $a1, 0x4($a0)
    /* 659C 8006ED9C 080080AC */  sw         $zero, 0x8($a0)
    /* 65A0 8006EDA0 FAA2000C */  jal        DrawPrim
    /* 65A4 8006EDA4 0C0086AC */   sw        $a2, 0xC($a0)
    /* 65A8 8006EDA8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 65AC 8006EDAC 1400B18F */  lw         $s1, 0x14($sp)
    /* 65B0 8006EDB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 65B4 8006EDB4 0800E003 */  jr         $ra
    /* 65B8 8006EDB8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _saveScreenExitScreen
