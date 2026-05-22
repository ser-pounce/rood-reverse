nonmatching _finishLoadZnd, 0x1A8

glabel _finishLoadZnd
    /* 206F0 80088EF0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 206F4 80088EF4 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 206F8 80088EF8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 206FC 80088EFC 80185024 */  addiu      $s0, $v0, %lo(_zoneContext)
    /* 20700 80088F00 2000BFAF */  sw         $ra, 0x20($sp)
    /* 20704 80088F04 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 20708 80088F08 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2070C 80088F0C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 20710 80088F10 2000028E */  lw         $v0, 0x20($s0)
    /* 20714 80088F14 00000000 */  nop
    /* 20718 80088F18 04004014 */  bnez       $v0, .L80088F2C
    /* 2071C 80088F1C 00000000 */   nop
    /* 20720 80088F20 8223020C */  jal        _loadZnd
    /* 20724 80088F24 00000000 */   nop
    /* 20728 80088F28 2000028E */  lw         $v0, 0x20($s0)
  .L80088F2C:
    /* 2072C 80088F2C 00000000 */  nop
    /* 20730 80088F30 00004384 */  lh         $v1, 0x0($v0)
    /* 20734 80088F34 04000224 */  addiu      $v0, $zero, 0x4
    /* 20738 80088F38 0A006210 */  beq        $v1, $v0, .L80088F64
    /* 2073C 80088F3C 21880002 */   addu      $s1, $s0, $zero
    /* 20740 80088F40 21804000 */  addu       $s0, $v0, $zero
  .L80088F44:
    /* 20744 80088F44 8709010C */  jal        vs_main_gametimeUpdate
    /* 20748 80088F48 21200000 */   addu      $a0, $zero, $zero
    /* 2074C 80088F4C 2000228E */  lw         $v0, 0x20($s1)
    /* 20750 80088F50 00000000 */  nop
    /* 20754 80088F54 00004284 */  lh         $v0, 0x0($v0)
    /* 20758 80088F58 00000000 */  nop
    /* 2075C 80088F5C F9FF5014 */  bne        $v0, $s0, .L80088F44
    /* 20760 80088F60 00000000 */   nop
  .L80088F64:
    /* 20764 80088F64 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 20768 80088F68 80185224 */  addiu      $s2, $v0, %lo(_zoneContext)
    /* 2076C 80088F6C 2000448E */  lw         $a0, 0x20($s2)
    /* 20770 80088F70 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 20774 80088F74 01001324 */   addiu     $s3, $zero, 0x1
    /* 20778 80088F78 0580023C */  lui        $v0, %hi(D_8005046A)
    /* 2077C 80088F7C 200040AE */  sw         $zero, 0x20($s2)
    /* 20780 80088F80 6A044294 */  lhu        $v0, %lo(D_8005046A)($v0)
    /* 20784 80088F84 00000000 */  nop
    /* 20788 80088F88 03005314 */  bne        $v0, $s3, .L80088F98
    /* 2078C 80088F8C 00000000 */   nop
    /* 20790 80088F90 33EF010C */  jal        func_8007BCCC
    /* 20794 80088F94 00000000 */   nop
  .L80088F98:
    /* 20798 80088F98 2400508E */  lw         $s0, 0x24($s2)
    /* 2079C 80088F9C 00000000 */  nop
    /* 207A0 80088FA0 0800048E */  lw         $a0, 0x8($s0)
    /* 207A4 80088FA4 0C00058E */  lw         $a1, 0xC($s0)
    /* 207A8 80088FA8 5023020C */  jal        _loadZndEnemies
    /* 207AC 80088FAC 21209000 */   addu      $a0, $a0, $s0
    /* 207B0 80088FB0 1000048E */  lw         $a0, 0x10($s0)
    /* 207B4 80088FB4 D129020C */  jal        _loadZndTims
    /* 207B8 80088FB8 21209000 */   addu      $a0, $a0, $s0
    /* 207BC 80088FBC 0000048E */  lw         $a0, 0x0($s0)
    /* 207C0 80088FC0 0400058E */  lw         $a1, 0x4($s0)
    /* 207C4 80088FC4 3923020C */  jal        _loadMpdLbas
    /* 207C8 80088FC8 21209000 */   addu      $a0, $a0, $s0
    /* 207CC 80088FCC 21200002 */  addu       $a0, $s0, $zero
    /* 207D0 80088FD0 1800918C */  lw         $s1, 0x18($a0)
    /* 207D4 80088FD4 180F010C */  jal        vs_main_freeHeapR
    /* 207D8 80088FD8 00000000 */   nop
    /* 207DC 80088FDC 0580023C */  lui        $v0, %hi(vs_main_startState)
    /* 207E0 80088FE0 7004428C */  lw         $v0, %lo(vs_main_startState)($v0)
    /* 207E4 80088FE4 240040AE */  sw         $zero, 0x24($s2)
    /* 207E8 80088FE8 02005314 */  bne        $v0, $s3, .L80088FF4
    /* 207EC 80088FEC 21200000 */   addu      $a0, $zero, $zero
    /* 207F0 80088FF0 01000424 */  addiu      $a0, $zero, 0x1
  .L80088FF4:
    /* 207F4 80088FF4 E7FA020C */  jal        func_800BEB9C
    /* 207F8 80088FF8 00000000 */   nop
    /* 207FC 80088FFC 3914010C */  jal        vs_main_getCurrentMusicId
    /* 20800 80089000 00000000 */   nop
    /* 20804 80089004 17005110 */  beq        $v0, $s1, .L80089064
    /* 20808 80089008 0F80023C */   lui       $v0, %hi(D_800F18B0)
    /* 2080C 8008900C B018428C */  lw         $v0, %lo(D_800F18B0)($v0)
    /* 20810 80089010 00000000 */  nop
    /* 20814 80089014 14004010 */  beqz       $v0, .L80089068
    /* 20818 80089018 0F80023C */   lui       $v0, %hi(_zoneContext)
    /* 2081C 8008901C 7D15010C */  jal        vs_main_stopMusic
    /* 20820 80089020 21800000 */   addu      $s0, $zero, $zero
    /* 20824 80089024 01001026 */  addiu      $s0, $s0, 0x1
  .L80089028:
    /* 20828 80089028 1015010C */  jal        vs_main_freeMusic
    /* 2082C 8008902C 21200002 */   addu      $a0, $s0, $zero
    /* 20830 80089030 0400022A */  slti       $v0, $s0, 0x4
    /* 20834 80089034 FCFF4014 */  bnez       $v0, .L80089028
    /* 20838 80089038 01001026 */   addiu     $s0, $s0, 0x1
    /* 2083C 8008903C 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 20840 80089040 80185024 */  addiu      $s0, $v0, %lo(_zoneContext)
    /* 20844 80089044 08002012 */  beqz       $s1, .L80089068
    /* 20848 80089048 2C0000AE */   sw        $zero, 0x2C($s0)
    /* 2084C 8008904C 1F1A010C */  jal        vs_main_loadAndWaitSoundSlot
    /* 20850 80089050 21202002 */   addu      $a0, $s1, $zero
    /* 20854 80089054 21202002 */  addu       $a0, $s1, $zero
    /* 20858 80089058 E714010C */  jal        vs_main_loadAndWaitMusicSlot
    /* 2085C 8008905C 03000524 */   addiu     $a1, $zero, 0x3
    /* 20860 80089060 2C0002AE */  sw         $v0, 0x2C($s0)
  .L80089064:
    /* 20864 80089064 0F80023C */  lui        $v0, %hi(_zoneContext)
  .L80089068:
    /* 20868 80089068 80184224 */  addiu      $v0, $v0, %lo(_zoneContext)
    /* 2086C 8008906C 01000324 */  addiu      $v1, $zero, 0x1
    /* 20870 80089070 280051AC */  sw         $s1, 0x28($v0)
    /* 20874 80089074 300043AC */  sw         $v1, 0x30($v0)
    /* 20878 80089078 380040AC */  sw         $zero, 0x38($v0)
    /* 2087C 8008907C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 20880 80089080 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 20884 80089084 1800B28F */  lw         $s2, 0x18($sp)
    /* 20888 80089088 1400B18F */  lw         $s1, 0x14($sp)
    /* 2088C 8008908C 1000B08F */  lw         $s0, 0x10($sp)
    /* 20890 80089090 0800E003 */  jr         $ra
    /* 20894 80089094 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _finishLoadZnd
