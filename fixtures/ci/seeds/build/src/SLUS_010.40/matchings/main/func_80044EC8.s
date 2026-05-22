nonmatching func_80044EC8, 0x98

glabel func_80044EC8
    /* 356C8 80044EC8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 356CC 80044ECC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 356D0 80044ED0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 356D4 80044ED4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 356D8 80044ED8 1A008010 */  beqz       $a0, .L80044F44
    /* 356DC 80044EDC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 356E0 80044EE0 0680033C */  lui        $v1, %hi(vs_main_soundData)
    /* 356E4 80044EE4 38E07124 */  addiu      $s1, $v1, %lo(vs_main_soundData)
    /* 356E8 80044EE8 FFFF9224 */  addiu      $s2, $a0, -0x1
    /* 356EC 80044EEC 80101200 */  sll        $v0, $s2, 2
    /* 356F0 80044EF0 21805100 */  addu       $s0, $v0, $s1
    /* 356F4 80044EF4 2400028E */  lw         $v0, 0x24($s0)
    /* 356F8 80044EF8 00000000 */  nop
    /* 356FC 80044EFC 0E004010 */  beqz       $v0, .L80044F38
    /* 35700 80044F00 0680023C */   lui       $v0, %hi(vs_main_soundData + 0x4)
    /* 35704 80044F04 38E064AC */  sw         $a0, %lo(vs_main_soundData)($v1)
    /* 35708 80044F08 2400048E */  lw         $a0, 0x24($s0)
    /* 3570C 80044F0C 3A48000C */  jal        func_800120E8
    /* 35710 80044F10 0C0024AE */   sw        $a0, 0xC($s1)
    /* 35714 80044F14 03004010 */  beqz       $v0, .L80044F24
    /* 35718 80044F18 00000000 */   nop
    /* 3571C 80044F1C 140002AE */  sw         $v0, 0x14($s0)
    /* 35720 80044F20 040022AE */  sw         $v0, 0x4($s1)
  .L80044F24:
    /* 35724 80044F24 21105102 */  addu       $v0, $s2, $s1
    /* 35728 80044F28 10004290 */  lbu        $v0, 0x10($v0)
    /* 3572C 80044F2C 00000000 */  nop
    /* 35730 80044F30 080022AE */  sw         $v0, 0x8($s1)
    /* 35734 80044F34 0680023C */  lui        $v0, %hi(vs_main_soundData + 0x4)
  .L80044F38:
    /* 35738 80044F38 3CE0428C */  lw         $v0, %lo(vs_main_soundData + 0x4)($v0)
    /* 3573C 80044F3C D2130108 */  j          .L80044F48
    /* 35740 80044F40 00000000 */   nop
  .L80044F44:
    /* 35744 80044F44 21100000 */  addu       $v0, $zero, $zero
  .L80044F48:
    /* 35748 80044F48 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3574C 80044F4C 1800B28F */  lw         $s2, 0x18($sp)
    /* 35750 80044F50 1400B18F */  lw         $s1, 0x14($sp)
    /* 35754 80044F54 1000B08F */  lw         $s0, 0x10($sp)
    /* 35758 80044F58 0800E003 */  jr         $ra
    /* 3575C 80044F5C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80044EC8
