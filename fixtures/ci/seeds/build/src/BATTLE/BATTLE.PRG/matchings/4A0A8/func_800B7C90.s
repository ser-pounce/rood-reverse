nonmatching func_800B7C90, 0x80

glabel func_800B7C90
    /* 4F490 800B7C90 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4F494 800B7C94 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4F498 800B7C98 21808000 */  addu       $s0, $a0, $zero
    /* 4F49C 800B7C9C 01000426 */  addiu      $a0, $s0, 0x1
    /* 4F4A0 800B7CA0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4F4A4 800B7CA4 80FF020C */  jal        vs_battle_getShort
    /* 4F4A8 800B7CA8 1400B1AF */   sw        $s1, 0x14($sp)
    /* 4F4AC 800B7CAC 94FF020C */  jal        func_800BFE50
    /* 4F4B0 800B7CB0 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F4B4 800B7CB4 03000426 */  addiu      $a0, $s0, 0x3
    /* 4F4B8 800B7CB8 80FF020C */  jal        vs_battle_getShort
    /* 4F4BC 800B7CBC 21884000 */   addu      $s1, $v0, $zero
    /* 4F4C0 800B7CC0 94FF020C */  jal        func_800BFE50
    /* 4F4C4 800B7CC4 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F4C8 800B7CC8 FFFF4530 */  andi       $a1, $v0, 0xFFFF
    /* 4F4CC 800B7CCC 0020A22C */  sltiu      $v0, $a1, 0x2000
    /* 4F4D0 800B7CD0 05004014 */  bnez       $v0, .L800B7CE8
    /* 4F4D4 800B7CD4 00000000 */   nop
    /* 4F4D8 800B7CD8 EA7F020C */  jal        func_8009FFA8
    /* 4F4DC 800B7CDC FFFF2432 */   andi      $a0, $s1, 0xFFFF
    /* 4F4E0 800B7CE0 3EDF0208 */  j          .L800B7CF8
    /* 4F4E4 800B7CE4 00000000 */   nop
  .L800B7CE8:
    /* 4F4E8 800B7CE8 05000692 */  lbu        $a2, 0x5($s0)
    /* 4F4EC 800B7CEC 06000792 */  lbu        $a3, 0x6($s0)
    /* 4F4F0 800B7CF0 C27F020C */  jal        func_8009FF08
    /* 4F4F4 800B7CF4 FFFF2432 */   andi      $a0, $s1, 0xFFFF
  .L800B7CF8:
    /* 4F4F8 800B7CF8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4F4FC 800B7CFC 1400B18F */  lw         $s1, 0x14($sp)
    /* 4F500 800B7D00 1000B08F */  lw         $s0, 0x10($sp)
    /* 4F504 800B7D04 21100000 */  addu       $v0, $zero, $zero
    /* 4F508 800B7D08 0800E003 */  jr         $ra
    /* 4F50C 800B7D0C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B7C90
