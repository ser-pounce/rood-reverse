nonmatching _hasBlade0, 0x64

glabel _hasBlade0
    /* 17108 8007F908 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1710C 8007F90C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17110 8007F910 2180A000 */  addu       $s0, $a1, $zero
    /* 17114 8007F914 1400BFAF */  sw         $ra, 0x14($sp)
    /* 17118 8007F918 2CFD010C */  jal        func_8007F4B0
    /* 1711C 8007F91C 15000424 */   addiu     $a0, $zero, 0x15
    /* 17120 8007F920 0D004014 */  bnez       $v0, .L8007F958
    /* 17124 8007F924 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* 17128 8007F928 00000292 */  lbu        $v0, 0x0($s0)
    /* 1712C 8007F92C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 17130 8007F930 80100200 */  sll        $v0, $v0, 2
    /* 17134 8007F934 21104300 */  addu       $v0, $v0, $v1
    /* 17138 8007F938 0000428C */  lw         $v0, 0x0($v0)
    /* 1713C 8007F93C 00000000 */  nop
    /* 17140 8007F940 3C00428C */  lw         $v0, 0x3C($v0)
    /* 17144 8007F944 00000000 */  nop
    /* 17148 8007F948 54004394 */  lhu        $v1, 0x54($v0)
    /* 1714C 8007F94C 00000000 */  nop
    /* 17150 8007F950 02006014 */  bnez       $v1, .L8007F95C
    /* 17154 8007F954 01000224 */   addiu     $v0, $zero, 0x1
  .L8007F958:
    /* 17158 8007F958 21100000 */  addu       $v0, $zero, $zero
  .L8007F95C:
    /* 1715C 8007F95C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 17160 8007F960 1000B08F */  lw         $s0, 0x10($sp)
    /* 17164 8007F964 0800E003 */  jr         $ra
    /* 17168 8007F968 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasBlade0
