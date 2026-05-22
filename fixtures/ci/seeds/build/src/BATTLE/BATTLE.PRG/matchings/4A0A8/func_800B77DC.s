nonmatching func_800B77DC, 0x70

glabel func_800B77DC
    /* 4EFDC 800B77DC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4EFE0 800B77E0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4EFE4 800B77E4 03008290 */  lbu        $v0, 0x3($a0)
    /* 4EFE8 800B77E8 00000000 */  nop
    /* 4EFEC 800B77EC 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 4EFF0 800B77F0 04008290 */  lbu        $v0, 0x4($a0)
    /* 4EFF4 800B77F4 00000000 */  nop
    /* 4EFF8 800B77F8 1100A2A3 */  sb         $v0, 0x11($sp)
    /* 4EFFC 800B77FC 05008290 */  lbu        $v0, 0x5($a0)
    /* 4F000 800B7800 00000000 */  nop
    /* 4F004 800B7804 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 4F008 800B7808 06008290 */  lbu        $v0, 0x6($a0)
    /* 4F00C 800B780C 01008424 */  addiu      $a0, $a0, 0x1
    /* 4F010 800B7810 80FF020C */  jal        vs_battle_getShort
    /* 4F014 800B7814 1300A2A3 */   sb        $v0, 0x13($sp)
    /* 4F018 800B7818 94FF020C */  jal        func_800BFE50
    /* 4F01C 800B781C FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F020 800B7820 21204000 */  addu       $a0, $v0, $zero
    /* 4F024 800B7824 01200224 */  addiu      $v0, $zero, 0x2001
    /* 4F028 800B7828 02008214 */  bne        $a0, $v0, .L800B7834
    /* 4F02C 800B782C 00000000 */   nop
    /* 4F030 800B7830 FFFF0424 */  addiu      $a0, $zero, -0x1
  .L800B7834:
    /* 4F034 800B7834 647E020C */  jal        func_8009F990
    /* 4F038 800B7838 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F03C 800B783C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4F040 800B7840 21100000 */  addu       $v0, $zero, $zero
    /* 4F044 800B7844 0800E003 */  jr         $ra
    /* 4F048 800B7848 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B77DC
