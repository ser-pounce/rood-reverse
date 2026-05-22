nonmatching _breakArtsUnlocked, 0x74

glabel _breakArtsUnlocked
    /* 62740 800CAF40 21200000 */  addu       $a0, $zero, $zero
    /* 62744 800CAF44 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 62748 800CAF48 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 6274C 800CAF4C 0580033C */  lui        $v1, %hi(vs_main_skills)
    /* 62750 800CAF50 25004290 */  lbu        $v0, 0x25($v0)
    /* 62754 800CAF54 DCB96624 */  addiu      $a2, $v1, %lo(vs_main_skills)
    /* 62758 800CAF58 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6275C 800CAF5C 80280200 */  sll        $a1, $v0, 2
    /* 62760 800CAF60 B8008224 */  addiu      $v0, $a0, 0xB8
  .L800CAF64:
    /* 62764 800CAF64 2110A200 */  addu       $v0, $a1, $v0
    /* 62768 800CAF68 40180200 */  sll        $v1, $v0, 1
    /* 6276C 800CAF6C 21186200 */  addu       $v1, $v1, $v0
    /* 62770 800CAF70 80180300 */  sll        $v1, $v1, 2
    /* 62774 800CAF74 21186200 */  addu       $v1, $v1, $v0
    /* 62778 800CAF78 80180300 */  sll        $v1, $v1, 2
    /* 6277C 800CAF7C 21186600 */  addu       $v1, $v1, $a2
    /* 62780 800CAF80 0C00628C */  lw         $v0, 0xC($v1)
    /* 62784 800CAF84 00000000 */  nop
    /* 62788 800CAF88 C2130200 */  srl        $v0, $v0, 15
    /* 6278C 800CAF8C 01004230 */  andi       $v0, $v0, 0x1
    /* 62790 800CAF90 03004010 */  beqz       $v0, .L800CAFA0
    /* 62794 800CAF94 01008424 */   addiu     $a0, $a0, 0x1
    /* 62798 800CAF98 0800E003 */  jr         $ra
    /* 6279C 800CAF9C 01000224 */   addiu     $v0, $zero, 0x1
  .L800CAFA0:
    /* 627A0 800CAFA0 04008228 */  slti       $v0, $a0, 0x4
    /* 627A4 800CAFA4 EFFF4014 */  bnez       $v0, .L800CAF64
    /* 627A8 800CAFA8 B8008224 */   addiu     $v0, $a0, 0xB8
    /* 627AC 800CAFAC 0800E003 */  jr         $ra
    /* 627B0 800CAFB0 21100000 */   addu      $v0, $zero, $zero
endlabel _breakArtsUnlocked
