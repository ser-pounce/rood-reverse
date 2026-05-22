nonmatching func_801088D4, 0x64

glabel func_801088D4
    /* 60D4 801088D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 60D8 801088D8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 60DC 801088DC 21808000 */  addu       $s0, $a0, $zero
    /* 60E0 801088E0 1180023C */  lui        $v0, %hi(_inventory)
    /* 60E4 801088E4 A8A6448C */  lw         $a0, %lo(_inventory)($v0)
    /* 60E8 801088E8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 60EC 801088EC 0733030C */  jal        vs_battle_rMemzero
    /* 60F0 801088F0 000F0524 */   addiu     $a1, $zero, 0xF00
    /* 60F4 801088F4 09000012 */  beqz       $s0, .L8010891C
    /* 60F8 801088F8 0F80023C */   lui       $v0, %hi(D_800EB9C8)
  .L801088FC:
    /* 60FC 801088FC BD21040C */  jal        _applyDropList
    /* 6100 80108900 08000426 */   addiu     $a0, $s0, 0x8
    /* 6104 80108904 0000108E */  lw         $s0, 0x0($s0)
    /* 6108 80108908 00000000 */  nop
    /* 610C 8010890C 06000012 */  beqz       $s0, .L80108928
    /* 6110 80108910 00000000 */   nop
    /* 6114 80108914 3F220408 */  j          .L801088FC
    /* 6118 80108918 00000000 */   nop
  .L8010891C:
    /* 611C 8010891C C8B9448C */  lw         $a0, %lo(D_800EB9C8)($v0)
    /* 6120 80108920 BD21040C */  jal        _applyDropList
    /* 6124 80108924 00000000 */   nop
  .L80108928:
    /* 6128 80108928 1400BF8F */  lw         $ra, 0x14($sp)
    /* 612C 8010892C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6130 80108930 0800E003 */  jr         $ra
    /* 6134 80108934 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_801088D4
