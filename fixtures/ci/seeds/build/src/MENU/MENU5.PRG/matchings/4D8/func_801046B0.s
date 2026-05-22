nonmatching func_801046B0, 0xD0

glabel func_801046B0
    /* 1EB0 801046B0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 1EB4 801046B4 2000B0AF */  sw         $s0, 0x20($sp)
    /* 1EB8 801046B8 21808000 */  addu       $s0, $a0, $zero
    /* 1EBC 801046BC 1180023C */  lui        $v0, %hi(_geomOffsetX)
    /* 1EC0 801046C0 1180033C */  lui        $v1, %hi(_geomOffsetY)
    /* 1EC4 801046C4 708D428C */  lw         $v0, %lo(_geomOffsetX)($v0)
    /* 1EC8 801046C8 748D638C */  lw         $v1, %lo(_geomOffsetY)($v1)
    /* 1ECC 801046CC 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1ED0 801046D0 2800B2AF */  sw         $s2, 0x28($sp)
    /* 1ED4 801046D4 21900000 */  addu       $s2, $zero, $zero
    /* 1ED8 801046D8 3000BFAF */  sw         $ra, 0x30($sp)
    /* 1EDC 801046DC 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 1EE0 801046E0 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1EE4 801046E4 90004224 */  addiu      $v0, $v0, 0x90
    /* 1EE8 801046E8 88006324 */  addiu      $v1, $v1, 0x88
    /* 1EEC 801046EC 1800A2AF */  sw         $v0, 0x18($sp)
    /* 1EF0 801046F0 3565020C */  jal        vs_battle_getGeomOffset
    /* 1EF4 801046F4 1C00A3AF */   sw        $v1, 0x1C($sp)
    /* 1EF8 801046F8 3D65020C */  jal        vs_battle_setGeomOffset
    /* 1EFC 801046FC 1800A427 */   addiu     $a0, $sp, 0x18
    /* 1F00 80104700 1180023C */  lui        $v0, %hi(D_80108EB4)
    /* 1F04 80104704 B48E40AC */  sw         $zero, %lo(D_80108EB4)($v0)
    /* 1F08 80104708 0000138E */  lw         $s3, 0x0($s0)
    /* 1F0C 8010470C 00000000 */  nop
    /* 1F10 80104710 1000601A */  blez       $s3, .L80104754
    /* 1F14 80104714 04001126 */   addiu     $s1, $s0, 0x4
    /* 1F18 80104718 04003026 */  addiu      $s0, $s1, 0x4
  .L8010471C:
    /* 1F1C 8010471C 0000228E */  lw         $v0, 0x0($s1)
    /* 1F20 80104720 00000000 */  nop
    /* 1F24 80104724 06004010 */  beqz       $v0, .L80104740
    /* 1F28 80104728 00000000 */   nop
    /* 1F2C 8010472C 0000058E */  lw         $a1, 0x0($s0)
    /* 1F30 80104730 04000686 */  lh         $a2, 0x4($s0)
    /* 1F34 80104734 06000786 */  lh         $a3, 0x6($s0)
    /* 1F38 80104738 E011040C */  jal        func_80104780
    /* 1F3C 8010473C 21204002 */   addu      $a0, $s2, $zero
  .L80104740:
    /* 1F40 80104740 01005226 */  addiu      $s2, $s2, 0x1
    /* 1F44 80104744 0C001026 */  addiu      $s0, $s0, 0xC
    /* 1F48 80104748 2A105302 */  slt        $v0, $s2, $s3
    /* 1F4C 8010474C F3FF4014 */  bnez       $v0, .L8010471C
    /* 1F50 80104750 0C003126 */   addiu     $s1, $s1, 0xC
  .L80104754:
    /* 1F54 80104754 AA20040C */  jal        func_801082A8
    /* 1F58 80104758 00000000 */   nop
    /* 1F5C 8010475C 3D65020C */  jal        vs_battle_setGeomOffset
    /* 1F60 80104760 1000A427 */   addiu     $a0, $sp, 0x10
    /* 1F64 80104764 3000BF8F */  lw         $ra, 0x30($sp)
    /* 1F68 80104768 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 1F6C 8010476C 2800B28F */  lw         $s2, 0x28($sp)
    /* 1F70 80104770 2400B18F */  lw         $s1, 0x24($sp)
    /* 1F74 80104774 2000B08F */  lw         $s0, 0x20($sp)
    /* 1F78 80104778 0800E003 */  jr         $ra
    /* 1F7C 8010477C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_801046B0
