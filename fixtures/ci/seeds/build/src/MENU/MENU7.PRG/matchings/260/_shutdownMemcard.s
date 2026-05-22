nonmatching _shutdownMemcard, 0xA8

glabel _shutdownMemcard
    /* 1E18 80104618 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1E1C 8010461C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1E20 80104620 21800000 */  addu       $s0, $zero, $zero
    /* 1E24 80104624 1180023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 1E28 80104628 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1E2C 8010462C D0AD5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
    /* 1E30 80104630 1800BFAF */  sw         $ra, 0x18($sp)
  .L80104634:
    /* 1E34 80104634 0000248E */  lw         $a0, 0x0($s1)
    /* 1E38 80104638 04003126 */  addiu      $s1, $s1, 0x4
    /* 1E3C 8010463C 499A000C */  jal        DisableEvent
    /* 1E40 80104640 01001026 */   addiu     $s0, $s0, 0x1
    /* 1E44 80104644 0800022A */  slti       $v0, $s0, 0x8
    /* 1E48 80104648 FAFF4014 */  bnez       $v0, .L80104634
    /* 1E4C 8010464C 00000000 */   nop
    /* 1E50 80104650 5D9A000C */  jal        EnterCriticalSection
    /* 1E54 80104654 21800000 */   addu      $s0, $zero, $zero
    /* 1E58 80104658 1180023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 1E5C 8010465C D0AD5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
  .L80104660:
    /* 1E60 80104660 0000248E */  lw         $a0, 0x0($s1)
    /* 1E64 80104664 04003126 */  addiu      $s1, $s1, 0x4
    /* 1E68 80104668 399A000C */  jal        CloseEvent
    /* 1E6C 8010466C 01001026 */   addiu     $s0, $s0, 0x1
    /* 1E70 80104670 0800022A */  slti       $v0, $s0, 0x8
    /* 1E74 80104674 FAFF4014 */  bnez       $v0, .L80104660
    /* 1E78 80104678 00000000 */   nop
    /* 1E7C 8010467C 619A000C */  jal        ExitCriticalSection
    /* 1E80 80104680 00000000 */   nop
    /* 1E84 80104684 250B010C */  jal        vs_main_enableReset
    /* 1E88 80104688 01000424 */   addiu     $a0, $zero, 0x1
    /* 1E8C 8010468C 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 1E90 80104690 F0AD448C */  lw         $a0, %lo(_spmcimg)($v0)
    /* 1E94 80104694 540F010C */  jal        vs_main_freeHeap
    /* 1E98 80104698 00000000 */   nop
    /* 1E9C 8010469C 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 1EA0 801046A0 03000524 */  addiu      $a1, $zero, 0x3
    /* 1EA4 801046A4 2AF8010C */  jal        func_8007E0A8
    /* 1EA8 801046A8 06000624 */   addiu     $a2, $zero, 0x6
    /* 1EAC 801046AC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1EB0 801046B0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1EB4 801046B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1EB8 801046B8 0800E003 */  jr         $ra
    /* 1EBC 801046BC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _shutdownMemcard
