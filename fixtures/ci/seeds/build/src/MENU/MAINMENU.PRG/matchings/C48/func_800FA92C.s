nonmatching func_800FA92C, 0xA4

glabel func_800FA92C
    /* 112C 800FA92C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1130 800FA930 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1134 800FA934 21908000 */  addu       $s2, $a0, $zero
    /* 1138 800FA938 1400B1AF */  sw         $s1, 0x14($sp)
    /* 113C 800FA93C 2188A000 */  addu       $s1, $a1, $zero
    /* 1140 800FA940 80101100 */  sll        $v0, $s1, 2
    /* 1144 800FA944 21105100 */  addu       $v0, $v0, $s1
    /* 1148 800FA948 1000B0AF */  sw         $s0, 0x10($sp)
    /* 114C 800FA94C 40800200 */  sll        $s0, $v0, 1
    /* 1150 800FA950 1E00022A */  slti       $v0, $s0, 0x1E
    /* 1154 800FA954 07004010 */  beqz       $v0, .L800FA974
    /* 1158 800FA958 1C00BFAF */   sw        $ra, 0x1C($sp)
  .L800FA95C:
    /* 115C 800FA95C 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 1160 800FA960 21200002 */   addu      $a0, $s0, $zero
    /* 1164 800FA964 01001026 */  addiu      $s0, $s0, 0x1
    /* 1168 800FA968 1E00022A */  slti       $v0, $s0, 0x1E
    /* 116C 800FA96C FBFF4014 */  bnez       $v0, .L800FA95C
    /* 1170 800FA970 00000000 */   nop
  .L800FA974:
    /* 1174 800FA974 80201100 */  sll        $a0, $s1, 2
    /* 1178 800FA978 21209100 */  addu       $a0, $a0, $s1
    /* 117C 800FA97C 40200400 */  sll        $a0, $a0, 1
    /* 1180 800FA980 9223030C */  jal        vs_battle_getMenuItem
    /* 1184 800FA984 21204402 */   addu      $a0, $s2, $a0
    /* 1188 800FA988 21204000 */  addu       $a0, $v0, $zero
    /* 118C 800FA98C 04000224 */  addiu      $v0, $zero, 0x4
    /* 1190 800FA990 000082A0 */  sb         $v0, 0x0($a0)
    /* 1194 800FA994 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 1198 800FA998 180082A4 */  sh         $v0, 0x18($a0)
    /* 119C 800FA99C 00111100 */  sll        $v0, $s1, 4
    /* 11A0 800FA9A0 02008390 */  lbu        $v1, 0x2($a0)
    /* 11A4 800FA9A4 12004224 */  addiu      $v0, $v0, 0x12
    /* 11A8 800FA9A8 03006014 */  bnez       $v1, .L800FA9B8
    /* 11AC 800FA9AC 1A0082A4 */   sh        $v0, 0x1A($a0)
    /* 11B0 800FA9B0 01000224 */  addiu      $v0, $zero, 0x1
    /* 11B4 800FA9B4 020082A0 */  sb         $v0, 0x2($a0)
  .L800FA9B8:
    /* 11B8 800FA9B8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 11BC 800FA9BC 1800B28F */  lw         $s2, 0x18($sp)
    /* 11C0 800FA9C0 1400B18F */  lw         $s1, 0x14($sp)
    /* 11C4 800FA9C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 11C8 800FA9C8 0800E003 */  jr         $ra
    /* 11CC 800FA9CC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800FA92C
