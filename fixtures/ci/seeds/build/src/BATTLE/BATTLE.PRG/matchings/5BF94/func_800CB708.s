nonmatching func_800CB708, 0x94

glabel func_800CB708
    /* 62F08 800CB708 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62F0C 800CB70C 0F80023C */  lui        $v0, %hi(D_800EB9B4)
    /* 62F10 800CB710 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62F14 800CB714 B4B9508C */  lw         $s0, %lo(D_800EB9B4)($v0)
    /* 62F18 800CB718 00000000 */  nop
    /* 62F1C 800CB71C 1B000012 */  beqz       $s0, .L800CB78C
    /* 62F20 800CB720 1400BFAF */   sw        $ra, 0x14($sp)
    /* 62F24 800CB724 00000292 */  lbu        $v0, 0x0($s0)
    /* 62F28 800CB728 00000000 */  nop
    /* 62F2C 800CB72C 05004010 */  beqz       $v0, .L800CB744
    /* 62F30 800CB730 00100224 */   addiu     $v0, $zero, 0x1000
    /* 62F34 800CB734 9E2D030C */  jal        _loadScreff2
    /* 62F38 800CB738 21200000 */   addu      $a0, $zero, $zero
    /* 62F3C 800CB73C E32D0308 */  j          .L800CB78C
    /* 62F40 800CB740 00000000 */   nop
  .L800CB744:
    /* 62F44 800CB744 0400038E */  lw         $v1, 0x4($s0)
    /* 62F48 800CB748 00000000 */  nop
    /* 62F4C 800CB74C 03006210 */  beq        $v1, $v0, .L800CB75C
    /* 62F50 800CB750 00000000 */   nop
    /* 62F54 800CB754 F6E6030C */  jal        func_800F9BD8
    /* 62F58 800CB758 00000000 */   nop
  .L800CB75C:
    /* 62F5C 800CB75C 02000296 */  lhu        $v0, 0x2($s0)
    /* 62F60 800CB760 00000000 */  nop
    /* 62F64 800CB764 03004010 */  beqz       $v0, .L800CB774
    /* 62F68 800CB768 00000000 */   nop
    /* 62F6C 800CB76C 1BE6030C */  jal        func_800F986C
    /* 62F70 800CB770 00000000 */   nop
  .L800CB774:
    /* 62F74 800CB774 0800028E */  lw         $v0, 0x8($s0)
    /* 62F78 800CB778 00000000 */  nop
    /* 62F7C 800CB77C 03004010 */  beqz       $v0, .L800CB78C
    /* 62F80 800CB780 00000000 */   nop
    /* 62F84 800CB784 EEE7030C */  jal        func_800F9FB8
    /* 62F88 800CB788 00000000 */   nop
  .L800CB78C:
    /* 62F8C 800CB78C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 62F90 800CB790 1000B08F */  lw         $s0, 0x10($sp)
    /* 62F94 800CB794 0800E003 */  jr         $ra
    /* 62F98 800CB798 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB708
