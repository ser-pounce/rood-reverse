nonmatching func_800B8788, 0xC4

glabel func_800B8788
    /* 4FF88 800B8788 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4FF8C 800B878C 21288000 */  addu       $a1, $a0, $zero
    /* 4FF90 800B8790 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4FF94 800B8794 0700A290 */  lbu        $v0, 0x7($a1)
    /* 4FF98 800B8798 00000000 */  nop
    /* 4FF9C 800B879C 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 4FFA0 800B87A0 0800A490 */  lbu        $a0, 0x8($a1)
    /* 4FFA4 800B87A4 00000000 */  nop
    /* 4FFA8 800B87A8 1100A4A3 */  sb         $a0, 0x11($sp)
    /* 4FFAC 800B87AC 0900A390 */  lbu        $v1, 0x9($a1)
    /* 4FFB0 800B87B0 25104400 */  or         $v0, $v0, $a0
    /* 4FFB4 800B87B4 1200A3A3 */  sb         $v1, 0x12($sp)
    /* 4FFB8 800B87B8 25186200 */  or         $v1, $v1, $v0
    /* 4FFBC 800B87BC FF006330 */  andi       $v1, $v1, 0xFF
    /* 4FFC0 800B87C0 14006010 */  beqz       $v1, .L800B8814
    /* 4FFC4 800B87C4 0100A424 */   addiu     $a0, $a1, 0x1
    /* 4FFC8 800B87C8 0300A290 */  lbu        $v0, 0x3($a1)
    /* 4FFCC 800B87CC 00000000 */  nop
    /* 4FFD0 800B87D0 1800A2A3 */  sb         $v0, 0x18($sp)
    /* 4FFD4 800B87D4 0400A290 */  lbu        $v0, 0x4($a1)
    /* 4FFD8 800B87D8 00000000 */  nop
    /* 4FFDC 800B87DC 1900A2A3 */  sb         $v0, 0x19($sp)
    /* 4FFE0 800B87E0 0500A290 */  lbu        $v0, 0x5($a1)
    /* 4FFE4 800B87E4 00000000 */  nop
    /* 4FFE8 800B87E8 1A00A2A3 */  sb         $v0, 0x1A($sp)
    /* 4FFEC 800B87EC 0600A290 */  lbu        $v0, 0x6($a1)
    /* 4FFF0 800B87F0 80FF020C */  jal        vs_battle_getShort
    /* 4FFF4 800B87F4 1B00A2A3 */   sb        $v0, 0x1B($sp)
    /* 4FFF8 800B87F8 94FF020C */  jal        func_800BFE50
    /* 4FFFC 800B87FC FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 50000 800B8800 21204000 */  addu       $a0, $v0, $zero
    /* 50004 800B8804 01000524 */  addiu      $a1, $zero, 0x1
    /* 50008 800B8808 1800A627 */  addiu      $a2, $sp, 0x18
    /* 5000C 800B880C 0DE20208 */  j          .L800B8834
    /* 50010 800B8810 1000A727 */   addiu     $a3, $sp, 0x10
  .L800B8814:
    /* 50014 800B8814 80FF020C */  jal        vs_battle_getShort
    /* 50018 800B8818 0100A424 */   addiu     $a0, $a1, 0x1
    /* 5001C 800B881C 94FF020C */  jal        func_800BFE50
    /* 50020 800B8820 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 50024 800B8824 21204000 */  addu       $a0, $v0, $zero
    /* 50028 800B8828 21280000 */  addu       $a1, $zero, $zero
    /* 5002C 800B882C 2130A000 */  addu       $a2, $a1, $zero
    /* 50030 800B8830 2138A000 */  addu       $a3, $a1, $zero
  .L800B8834:
    /* 50034 800B8834 507E020C */  jal        func_8009F940
    /* 50038 800B8838 00000000 */   nop
    /* 5003C 800B883C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 50040 800B8840 21100000 */  addu       $v0, $zero, $zero
    /* 50044 800B8844 0800E003 */  jr         $ra
    /* 50048 800B8848 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800B8788
