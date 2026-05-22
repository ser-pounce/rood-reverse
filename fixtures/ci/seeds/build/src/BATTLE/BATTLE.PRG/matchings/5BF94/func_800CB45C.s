nonmatching func_800CB45C, 0xB0

glabel func_800CB45C
    /* 62C5C 800CB45C 0F80023C */  lui        $v0, %hi(D_800EB9D8)
    /* 62C60 800CB460 D8B9428C */  lw         $v0, %lo(D_800EB9D8)($v0)
    /* 62C64 800CB464 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62C68 800CB468 23004010 */  beqz       $v0, .L800CB4F8
    /* 62C6C 800CB46C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 62C70 800CB470 0F80023C */  lui        $v0, %hi(D_800F5130)
    /* 62C74 800CB474 3051428C */  lw         $v0, %lo(D_800F5130)($v0)
    /* 62C78 800CB478 00000000 */  nop
    /* 62C7C 800CB47C 82170200 */  srl        $v0, $v0, 30
    /* 62C80 800CB480 01004230 */  andi       $v0, $v0, 0x1
    /* 62C84 800CB484 03004014 */  bnez       $v0, .L800CB494
    /* 62C88 800CB488 0F80023C */   lui       $v0, %hi(D_800F4E69)
    /* 62C8C 800CB48C 3F2D0308 */  j          .L800CB4FC
    /* 62C90 800CB490 01000224 */   addiu     $v0, $zero, 0x1
  .L800CB494:
    /* 62C94 800CB494 694E4290 */  lbu        $v0, %lo(D_800F4E69)($v0)
    /* 62C98 800CB498 00000000 */  nop
    /* 62C9C 800CB49C 11004010 */  beqz       $v0, .L800CB4E4
    /* 62CA0 800CB4A0 0F80043C */   lui       $a0, %hi(D_800F4E68)
    /* 62CA4 800CB4A4 684E8390 */  lbu        $v1, %lo(D_800F4E68)($a0)
    /* 62CA8 800CB4A8 00000000 */  nop
    /* 62CAC 800CB4AC 0400622C */  sltiu      $v0, $v1, 0x4
    /* 62CB0 800CB4B0 03004010 */  beqz       $v0, .L800CB4C0
    /* 62CB4 800CB4B4 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 62CB8 800CB4B8 342D0308 */  j          .L800CB4D0
    /* 62CBC 800CB4BC 684E80A0 */   sb        $zero, %lo(D_800F4E68)($a0)
  .L800CB4C0:
    /* 62CC0 800CB4C0 4CE24290 */  lbu        $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 62CC4 800CB4C4 00000000 */  nop
    /* 62CC8 800CB4C8 23106200 */  subu       $v0, $v1, $v0
    /* 62CCC 800CB4CC 684E82A0 */  sb         $v0, %lo(D_800F4E68)($a0)
  .L800CB4D0:
    /* 62CD0 800CB4D0 0F80023C */  lui        $v0, %hi(D_800F4E68)
    /* 62CD4 800CB4D4 684E4290 */  lbu        $v0, %lo(D_800F4E68)($v0)
    /* 62CD8 800CB4D8 00000000 */  nop
    /* 62CDC 800CB4DC 06004010 */  beqz       $v0, .L800CB4F8
    /* 62CE0 800CB4E0 00000000 */   nop
  .L800CB4E4:
    /* 62CE4 800CB4E4 07000424 */  addiu      $a0, $zero, 0x7
    /* 62CE8 800CB4E8 FC1A030C */  jal        vs_battle_setTextBox
    /* 62CEC 800CB4EC 21280000 */   addu      $a1, $zero, $zero
    /* 62CF0 800CB4F0 3F2D0308 */  j          .L800CB4FC
    /* 62CF4 800CB4F4 23100200 */   negu      $v0, $v0
  .L800CB4F8:
    /* 62CF8 800CB4F8 21100000 */  addu       $v0, $zero, $zero
  .L800CB4FC:
    /* 62CFC 800CB4FC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 62D00 800CB500 00000000 */  nop
    /* 62D04 800CB504 0800E003 */  jr         $ra
    /* 62D08 800CB508 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB45C
