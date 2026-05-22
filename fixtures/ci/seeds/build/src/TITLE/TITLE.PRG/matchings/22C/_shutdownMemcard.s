nonmatching _shutdownMemcard, 0x98

glabel _shutdownMemcard
    /* 1EE0 8006A6E0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1EE4 8006A6E4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1EE8 8006A6E8 21800000 */  addu       $s0, $zero, $zero
    /* 1EEC 8006A6EC 0E80023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 1EF0 8006A6F0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1EF4 8006A6F4 98EA5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
    /* 1EF8 8006A6F8 1800BFAF */  sw         $ra, 0x18($sp)
  .L8006A6FC:
    /* 1EFC 8006A6FC 0000248E */  lw         $a0, 0x0($s1)
    /* 1F00 8006A700 04003126 */  addiu      $s1, $s1, 0x4
    /* 1F04 8006A704 499A000C */  jal        DisableEvent
    /* 1F08 8006A708 01001026 */   addiu     $s0, $s0, 0x1
    /* 1F0C 8006A70C 0800022A */  slti       $v0, $s0, 0x8
    /* 1F10 8006A710 FAFF4014 */  bnez       $v0, .L8006A6FC
    /* 1F14 8006A714 00000000 */   nop
    /* 1F18 8006A718 5D9A000C */  jal        EnterCriticalSection
    /* 1F1C 8006A71C 21800000 */   addu      $s0, $zero, $zero
    /* 1F20 8006A720 0E80023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 1F24 8006A724 98EA5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
  .L8006A728:
    /* 1F28 8006A728 0000248E */  lw         $a0, 0x0($s1)
    /* 1F2C 8006A72C 04003126 */  addiu      $s1, $s1, 0x4
    /* 1F30 8006A730 399A000C */  jal        CloseEvent
    /* 1F34 8006A734 01001026 */   addiu     $s0, $s0, 0x1
    /* 1F38 8006A738 0800022A */  slti       $v0, $s0, 0x8
    /* 1F3C 8006A73C FAFF4014 */  bnez       $v0, .L8006A728
    /* 1F40 8006A740 00000000 */   nop
    /* 1F44 8006A744 619A000C */  jal        ExitCriticalSection
    /* 1F48 8006A748 00000000 */   nop
    /* 1F4C 8006A74C 250B010C */  jal        vs_main_enableReset
    /* 1F50 8006A750 01000424 */   addiu     $a0, $zero, 0x1
    /* 1F54 8006A754 0E80023C */  lui        $v0, %hi(_spmcimg)
    /* 1F58 8006A758 B8EA448C */  lw         $a0, %lo(_spmcimg)($v0)
    /* 1F5C 8006A75C 540F010C */  jal        vs_main_freeHeap
    /* 1F60 8006A760 00000000 */   nop
    /* 1F64 8006A764 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1F68 8006A768 1400B18F */  lw         $s1, 0x14($sp)
    /* 1F6C 8006A76C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F70 8006A770 0800E003 */  jr         $ra
    /* 1F74 8006A774 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _shutdownMemcard
