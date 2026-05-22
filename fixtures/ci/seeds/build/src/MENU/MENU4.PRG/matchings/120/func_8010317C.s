nonmatching func_8010317C, 0x148

glabel func_8010317C
    /* 97C 8010317C 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 980 80103180 4025428C */  lw         $v0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 984 80103184 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 988 80103188 2800B2AF */  sw         $s2, 0x28($sp)
    /* 98C 8010318C 21908000 */  addu       $s2, $a0, $zero
    /* 990 80103190 2400B1AF */  sw         $s1, 0x24($sp)
    /* 994 80103194 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 998 80103198 2000B0AF */  sw         $s0, 0x20($sp)
    /* 99C 8010319C 1C684224 */  addiu      $v0, $v0, 0x681C
    /* 9A0 801031A0 1400A2AF */  sw         $v0, 0x14($sp)
    /* 9A4 801031A4 0600422E */  sltiu      $v0, $s2, 0x6
    /* 9A8 801031A8 3B004010 */  beqz       $v0, .L80103298
    /* 9AC 801031AC 2188A000 */   addu      $s1, $a1, $zero
    /* 9B0 801031B0 1080023C */  lui        $v0, %hi(jtbl_80102828)
    /* 9B4 801031B4 28284224 */  addiu      $v0, $v0, %lo(jtbl_80102828)
    /* 9B8 801031B8 80181200 */  sll        $v1, $s2, 2
    /* 9BC 801031BC 21186200 */  addu       $v1, $v1, $v0
    /* 9C0 801031C0 0000628C */  lw         $v0, 0x0($v1)
    /* 9C4 801031C4 00000000 */  nop
    /* 9C8 801031C8 08004000 */  jr         $v0
    /* 9CC 801031CC 00000000 */   nop
    /* 9D0 801031D0 21202002 */  addu       $a0, $s1, $zero
    /* 9D4 801031D4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 9D8 801031D8 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 9DC 801031DC 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 9E0 801031E0 17F2030C */  jal        vs_mainMenu_setUiWeapon
    /* 9E4 801031E4 1800A627 */   addiu     $a2, $sp, 0x18
    /* 9E8 801031E8 A60C0408 */  j          .L80103298
    /* 9EC 801031EC 1000B1AF */   sw        $s1, 0x10($sp)
    /* 9F0 801031F0 18002426 */  addiu      $a0, $s1, 0x18
    /* 9F4 801031F4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 9F8 801031F8 D90B040C */  jal        func_80102F64
    /* 9FC 801031FC 1800A627 */   addiu     $a2, $sp, 0x18
    /* A00 80103200 590B040C */  jal        func_80102D64
    /* A04 80103204 21202002 */   addu      $a0, $s1, $zero
    /* A08 80103208 A60C0408 */  j          .L80103298
    /* A0C 8010320C 00000000 */   nop
    /* A10 80103210 48003026 */  addiu      $s0, $s1, 0x48
    /* A14 80103214 21200002 */  addu       $a0, $s0, $zero
    /* A18 80103218 1000A527 */  addiu      $a1, $sp, 0x10
    /* A1C 8010321C 200C040C */  jal        func_80103080
    /* A20 80103220 1800A627 */   addiu     $a2, $sp, 0x18
    /* A24 80103224 8F0B040C */  jal        func_80102E3C
    /* A28 80103228 21200002 */   addu      $a0, $s0, $zero
    /* A2C 8010322C A60C0408 */  j          .L80103298
    /* A30 80103230 00000000 */   nop
    /* A34 80103234 FDFF4226 */  addiu      $v0, $s2, -0x3
    /* A38 80103238 40180200 */  sll        $v1, $v0, 1
    /* A3C 8010323C 21186200 */  addu       $v1, $v1, $v0
    /* A40 80103240 00190300 */  sll        $v1, $v1, 4
    /* A44 80103244 21182302 */  addu       $v1, $s1, $v1
    /* A48 80103248 78006294 */  lhu        $v0, 0x78($v1)
    /* A4C 8010324C 00000000 */  nop
    /* A50 80103250 0D004010 */  beqz       $v0, .L80103288
    /* A54 80103254 40801200 */   sll       $s0, $s2, 1
    /* A58 80103258 21801202 */  addu       $s0, $s0, $s2
    /* A5C 8010325C 00811000 */  sll        $s0, $s0, 4
    /* A60 80103260 E8FF1026 */  addiu      $s0, $s0, -0x18
    /* A64 80103264 21803002 */  addu       $s0, $s1, $s0
    /* A68 80103268 21200002 */  addu       $a0, $s0, $zero
    /* A6C 8010326C 1000A527 */  addiu      $a1, $sp, 0x10
    /* A70 80103270 460C040C */  jal        func_80103118
    /* A74 80103274 1800A627 */   addiu     $a2, $sp, 0x18
    /* A78 80103278 B00B040C */  jal        func_80102EC0
    /* A7C 8010327C 21200002 */   addu      $a0, $s0, $zero
    /* A80 80103280 A60C0408 */  j          .L80103298
    /* A84 80103284 00000000 */   nop
  .L80103288:
    /* A88 80103288 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* A8C 8010328C 08000424 */   addiu     $a0, $zero, 0x8
    /* A90 80103290 88F4030C */  jal        vs_mainMenu_resetStats
    /* A94 80103294 00000000 */   nop
  .L80103298:
    /* A98 80103298 9223030C */  jal        vs_battle_getMenuItem
    /* A9C 8010329C 14004426 */   addiu     $a0, $s2, 0x14
    /* AA0 801032A0 01000324 */  addiu      $v1, $zero, 0x1
    /* AA4 801032A4 060043A0 */  sb         $v1, 0x6($v0)
    /* AA8 801032A8 1400A28F */  lw         $v0, 0x14($sp)
    /* AAC 801032AC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* AB0 801032B0 2800B28F */  lw         $s2, 0x28($sp)
    /* AB4 801032B4 2400B18F */  lw         $s1, 0x24($sp)
    /* AB8 801032B8 2000B08F */  lw         $s0, 0x20($sp)
    /* ABC 801032BC 0800E003 */  jr         $ra
    /* AC0 801032C0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8010317C
