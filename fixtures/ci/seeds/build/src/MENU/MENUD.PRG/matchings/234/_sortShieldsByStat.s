nonmatching _sortShieldsByStat, 0x17C

glabel _sortShieldsByStat
    /* 2C54 80105454 20FEBD27 */  addiu      $sp, $sp, -0x1E0
    /* 2C58 80105458 D801BEAF */  sw         $fp, 0x1D8($sp)
    /* 2C5C 8010545C 21F08000 */  addu       $fp, $a0, $zero
    /* 2C60 80105460 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 2C64 80105464 8C9A458C */  lw         $a1, %lo(vs_menuD_containerData)($v0)
    /* 2C68 80105468 03000424 */  addiu      $a0, $zero, 0x3
    /* 2C6C 8010546C C801B4AF */  sw         $s4, 0x1C8($sp)
    /* 2C70 80105470 21A00000 */  addu       $s4, $zero, $zero
    /* 2C74 80105474 D401B7AF */  sw         $s7, 0x1D4($sp)
    /* 2C78 80105478 21B84000 */  addu       $s7, $v0, $zero
    /* 2C7C 8010547C DC01BFAF */  sw         $ra, 0x1DC($sp)
    /* 2C80 80105480 D001B6AF */  sw         $s6, 0x1D0($sp)
    /* 2C84 80105484 CC01B5AF */  sw         $s5, 0x1CC($sp)
    /* 2C88 80105488 C401B3AF */  sw         $s3, 0x1C4($sp)
    /* 2C8C 8010548C C001B2AF */  sw         $s2, 0x1C0($sp)
    /* 2C90 80105490 BC01B1AF */  sw         $s1, 0x1BC($sp)
    /* 2C94 80105494 B801B0AF */  sw         $s0, 0x1B8($sp)
    /* 2C98 80105498 250B040C */  jal        _getContainerIndicesOffset
    /* 2C9C 8010549C 0004B524 */   addiu     $s5, $a1, 0x400
    /* 2CA0 801054A0 7801A427 */  addiu      $a0, $sp, 0x178
    /* 2CA4 801054A4 40000524 */  addiu      $a1, $zero, 0x40
    /* 2CA8 801054A8 0733030C */  jal        vs_battle_rMemzero
    /* 2CAC 801054AC 21B04000 */   addu      $s6, $v0, $zero
    /* 2CB0 801054B0 0080133C */  lui        $s3, (0x80000000 >> 16)
  .L801054B4:
    /* 2CB4 801054B4 21880000 */  addu       $s1, $zero, $zero
    /* 2CB8 801054B8 2190C002 */  addu       $s2, $s6, $zero
  .L801054BC:
    /* 2CBC 801054BC 00005096 */  lhu        $s0, 0x0($s2)
    /* 2CC0 801054C0 00000000 */  nop
    /* 2CC4 801054C4 10000012 */  beqz       $s0, .L80105508
    /* 2CC8 801054C8 1000A427 */   addiu     $a0, $sp, 0x10
    /* 2CCC 801054CC 8C9AE68E */  lw         $a2, %lo(vs_menuD_containerData)($s7)
    /* 2CD0 801054D0 40281000 */  sll        $a1, $s0, 1
    /* 2CD4 801054D4 2128B000 */  addu       $a1, $a1, $s0
    /* 2CD8 801054D8 00290500 */  sll        $a1, $a1, 4
    /* 2CDC 801054DC D0FFA524 */  addiu      $a1, $a1, -0x30
    /* 2CE0 801054E0 EC0A040C */  jal        vs_menuD_initUiShield
    /* 2CE4 801054E4 2128A502 */   addu      $a1, $s5, $a1
    /* 2CE8 801054E8 2120C003 */  addu       $a0, $fp, $zero
    /* 2CEC 801054EC DE14040C */  jal        _getShieldStat
    /* 2CF0 801054F0 1000A527 */   addiu     $a1, $sp, 0x10
    /* 2CF4 801054F4 21184000 */  addu       $v1, $v0, $zero
    /* 2CF8 801054F8 2A106302 */  slt        $v0, $s3, $v1
    /* 2CFC 801054FC 02004010 */  beqz       $v0, .L80105508
    /* 2D00 80105500 00000000 */   nop
    /* 2D04 80105504 21986000 */  addu       $s3, $v1, $zero
  .L80105508:
    /* 2D08 80105508 01003126 */  addiu      $s1, $s1, 0x1
    /* 2D0C 8010550C 2000222A */  slti       $v0, $s1, 0x20
    /* 2D10 80105510 EAFF4014 */  bnez       $v0, .L801054BC
    /* 2D14 80105514 02005226 */   addiu     $s2, $s2, 0x2
    /* 2D18 80105518 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 2D1C 8010551C 1C006212 */  beq        $s3, $v0, .L80105590
    /* 2D20 80105520 21880000 */   addu      $s1, $zero, $zero
    /* 2D24 80105524 2190C002 */  addu       $s2, $s6, $zero
  .L80105528:
    /* 2D28 80105528 00005096 */  lhu        $s0, 0x0($s2)
    /* 2D2C 8010552C 00000000 */  nop
    /* 2D30 80105530 11000012 */  beqz       $s0, .L80105578
    /* 2D34 80105534 1000A427 */   addiu     $a0, $sp, 0x10
    /* 2D38 80105538 8C9AE68E */  lw         $a2, %lo(vs_menuD_containerData)($s7)
    /* 2D3C 8010553C 40281000 */  sll        $a1, $s0, 1
    /* 2D40 80105540 2128B000 */  addu       $a1, $a1, $s0
    /* 2D44 80105544 00290500 */  sll        $a1, $a1, 4
    /* 2D48 80105548 D0FFA524 */  addiu      $a1, $a1, -0x30
    /* 2D4C 8010554C EC0A040C */  jal        vs_menuD_initUiShield
    /* 2D50 80105550 2128A502 */   addu      $a1, $s5, $a1
    /* 2D54 80105554 2120C003 */  addu       $a0, $fp, $zero
    /* 2D58 80105558 DE14040C */  jal        _getShieldStat
    /* 2D5C 8010555C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 2D60 80105560 05005314 */  bne        $v0, $s3, .L80105578
    /* 2D64 80105564 40101400 */   sll       $v0, $s4, 1
    /* 2D68 80105568 01009426 */  addiu      $s4, $s4, 0x1
    /* 2D6C 8010556C 2110A203 */  addu       $v0, $sp, $v0
    /* 2D70 80105570 780150A4 */  sh         $s0, 0x178($v0)
    /* 2D74 80105574 000040A6 */  sh         $zero, 0x0($s2)
  .L80105578:
    /* 2D78 80105578 01003126 */  addiu      $s1, $s1, 0x1
    /* 2D7C 8010557C 2000222A */  slti       $v0, $s1, 0x20
    /* 2D80 80105580 E9FF4014 */  bnez       $v0, .L80105528
    /* 2D84 80105584 02005226 */   addiu     $s2, $s2, 0x2
    /* 2D88 80105588 2D150408 */  j          .L801054B4
    /* 2D8C 8010558C 0080133C */   lui       $s3, (0x80000000 >> 16)
  .L80105590:
    /* 2D90 80105590 2120C002 */  addu       $a0, $s6, $zero
    /* 2D94 80105594 7801A527 */  addiu      $a1, $sp, 0x178
    /* 2D98 80105598 7800030C */  jal        vs_battle_memcpy
    /* 2D9C 8010559C 40000624 */   addiu     $a2, $zero, 0x40
    /* 2DA0 801055A0 DC01BF8F */  lw         $ra, 0x1DC($sp)
    /* 2DA4 801055A4 D801BE8F */  lw         $fp, 0x1D8($sp)
    /* 2DA8 801055A8 D401B78F */  lw         $s7, 0x1D4($sp)
    /* 2DAC 801055AC D001B68F */  lw         $s6, 0x1D0($sp)
    /* 2DB0 801055B0 CC01B58F */  lw         $s5, 0x1CC($sp)
    /* 2DB4 801055B4 C801B48F */  lw         $s4, 0x1C8($sp)
    /* 2DB8 801055B8 C401B38F */  lw         $s3, 0x1C4($sp)
    /* 2DBC 801055BC C001B28F */  lw         $s2, 0x1C0($sp)
    /* 2DC0 801055C0 BC01B18F */  lw         $s1, 0x1BC($sp)
    /* 2DC4 801055C4 B801B08F */  lw         $s0, 0x1B8($sp)
    /* 2DC8 801055C8 0800E003 */  jr         $ra
    /* 2DCC 801055CC E001BD27 */   addiu     $sp, $sp, 0x1E0
endlabel _sortShieldsByStat
