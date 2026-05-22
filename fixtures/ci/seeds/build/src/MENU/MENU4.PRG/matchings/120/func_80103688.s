nonmatching func_80103688, 0xBC

glabel func_80103688
    /* E88 80103688 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* E8C 8010368C 1000B0AF */  sw         $s0, 0x10($sp)
    /* E90 80103690 21808000 */  addu       $s0, $a0, $zero
    /* E94 80103694 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* E98 80103698 2198A000 */  addu       $s3, $a1, $zero
    /* E9C 8010369C 1400B1AF */  sw         $s1, 0x14($sp)
    /* EA0 801036A0 8888113C */  lui        $s1, (0x88888889 >> 16)
    /* EA4 801036A4 89883136 */  ori        $s1, $s1, (0x88888889 & 0xFFFF)
    /* EA8 801036A8 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* EAC 801036AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* EB0 801036B0 28195224 */  addiu      $s2, $v0, %lo(vs_battle_actors)
    /* EB4 801036B4 2000BFAF */  sw         $ra, 0x20($sp)
  .L801036B8:
    /* EB8 801036B8 21201302 */  addu       $a0, $s0, $s3
    /* EBC 801036BC 18009100 */  mult       $a0, $s1
    /* EC0 801036C0 C31F0400 */  sra        $v1, $a0, 31
    /* EC4 801036C4 10300000 */  mfhi       $a2
    /* EC8 801036C8 2110C400 */  addu       $v0, $a2, $a0
    /* ECC 801036CC C3100200 */  sra        $v0, $v0, 3
    /* ED0 801036D0 23804300 */  subu       $s0, $v0, $v1
    /* ED4 801036D4 00111000 */  sll        $v0, $s0, 4
    /* ED8 801036D8 23105000 */  subu       $v0, $v0, $s0
    /* EDC 801036DC 23808200 */  subu       $s0, $a0, $v0
    /* EE0 801036E0 F882020C */  jal        func_800A0BE0
    /* EE4 801036E4 21200002 */   addu      $a0, $s0, $zero
    /* EE8 801036E8 80181000 */  sll        $v1, $s0, 2
    /* EEC 801036EC 21187200 */  addu       $v1, $v1, $s2
    /* EF0 801036F0 0000638C */  lw         $v1, 0x0($v1)
    /* EF4 801036F4 00000000 */  nop
    /* EF8 801036F8 EFFF6010 */  beqz       $v1, .L801036B8
    /* EFC 801036FC 21204000 */   addu      $a0, $v0, $zero
    /* F00 80103700 1C006294 */  lhu        $v0, 0x1C($v1)
    /* F04 80103704 00000000 */  nop
    /* F08 80103708 0500422C */  sltiu      $v0, $v0, 0x5
    /* F0C 8010370C EAFF4010 */  beqz       $v0, .L801036B8
    /* F10 80103710 0001033C */   lui       $v1, (0x1000001 >> 16)
    /* F14 80103714 01006334 */  ori        $v1, $v1, (0x1000001 & 0xFFFF)
    /* F18 80103718 24188300 */  and        $v1, $a0, $v1
    /* F1C 8010371C 01000224 */  addiu      $v0, $zero, 0x1
    /* F20 80103720 E5FF6214 */  bne        $v1, $v0, .L801036B8
    /* F24 80103724 21100002 */   addu      $v0, $s0, $zero
    /* F28 80103728 2000BF8F */  lw         $ra, 0x20($sp)
    /* F2C 8010372C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* F30 80103730 1800B28F */  lw         $s2, 0x18($sp)
    /* F34 80103734 1400B18F */  lw         $s1, 0x14($sp)
    /* F38 80103738 1000B08F */  lw         $s0, 0x10($sp)
    /* F3C 8010373C 0800E003 */  jr         $ra
    /* F40 80103740 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80103688
