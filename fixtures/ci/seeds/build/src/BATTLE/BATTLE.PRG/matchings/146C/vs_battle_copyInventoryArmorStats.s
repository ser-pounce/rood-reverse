nonmatching vs_battle_copyInventoryArmorStats, 0x110

glabel vs_battle_copyInventoryArmorStats
    /* 24FC 8006ACFC 0000A290 */  lbu        $v0, 0x0($a1)
    /* 2500 8006AD00 00000000 */  nop
    /* 2504 8006AD04 000082A4 */  sh         $v0, 0x0($a0)
    /* 2508 8006AD08 0100A290 */  lbu        $v0, 0x1($a1)
    /* 250C 8006AD0C 00000000 */  nop
    /* 2510 8006AD10 020082A0 */  sb         $v0, 0x2($a0)
    /* 2514 8006AD14 0200A290 */  lbu        $v0, 0x2($a1)
    /* 2518 8006AD18 00000000 */  nop
    /* 251C 8006AD1C 030082A0 */  sb         $v0, 0x3($a0)
    /* 2520 8006AD20 0300A290 */  lbu        $v0, 0x3($a1)
    /* 2524 8006AD24 00000000 */  nop
    /* 2528 8006AD28 040082A0 */  sb         $v0, 0x4($a0)
    /* 252C 8006AD2C 0800A294 */  lhu        $v0, 0x8($a1)
    /* 2530 8006AD30 00000000 */  nop
    /* 2534 8006AD34 080082A4 */  sh         $v0, 0x8($a0)
    /* 2538 8006AD38 0400A294 */  lhu        $v0, 0x4($a1)
    /* 253C 8006AD3C 00000000 */  nop
    /* 2540 8006AD40 0A0082A4 */  sh         $v0, 0xA($a0)
    /* 2544 8006AD44 0A00A294 */  lhu        $v0, 0xA($a1)
    /* 2548 8006AD48 00000000 */  nop
    /* 254C 8006AD4C 0C0082A4 */  sh         $v0, 0xC($a0)
    /* 2550 8006AD50 0600A294 */  lhu        $v0, 0x6($a1)
    /* 2554 8006AD54 00000000 */  nop
    /* 2558 8006AD58 0E0082A4 */  sh         $v0, 0xE($a0)
    /* 255C 8006AD5C 0C00A290 */  lbu        $v0, 0xC($a1)
    /* 2560 8006AD60 00000000 */  nop
    /* 2564 8006AD64 150082A0 */  sb         $v0, 0x15($a0)
    /* 2568 8006AD68 0D00A290 */  lbu        $v0, 0xD($a1)
    /* 256C 8006AD6C 00000000 */  nop
    /* 2570 8006AD70 050082A0 */  sb         $v0, 0x5($a0)
    /* 2574 8006AD74 0E00A290 */  lbu        $v0, 0xE($a1)
    /* 2578 8006AD78 00000000 */  nop
    /* 257C 8006AD7C 060082A0 */  sb         $v0, 0x6($a0)
    /* 2580 8006AD80 0F00A290 */  lbu        $v0, 0xF($a1)
    /* 2584 8006AD84 2138A000 */  addu       $a3, $a1, $zero
    /* 2588 8006AD88 070082A0 */  sb         $v0, 0x7($a0)
    /* 258C 8006AD8C 2700A290 */  lbu        $v0, 0x27($a1)
    /* 2590 8006AD90 21300000 */  addu       $a2, $zero, $zero
    /* 2594 8006AD94 170082A0 */  sb         $v0, 0x17($a0)
    /* 2598 8006AD98 21188600 */  addu       $v1, $a0, $a2
  .L8006AD9C:
    /* 259C 8006AD9C 2110E600 */  addu       $v0, $a3, $a2
    /* 25A0 8006ADA0 10004290 */  lbu        $v0, 0x10($v0)
    /* 25A4 8006ADA4 0100C624 */  addiu      $a2, $a2, 0x1
    /* 25A8 8006ADA8 1C0062A0 */  sb         $v0, 0x1C($v1)
    /* 25AC 8006ADAC 0400C228 */  slti       $v0, $a2, 0x4
    /* 25B0 8006ADB0 FAFF4014 */  bnez       $v0, .L8006AD9C
    /* 25B4 8006ADB4 21188600 */   addu      $v1, $a0, $a2
    /* 25B8 8006ADB8 21300000 */  addu       $a2, $zero, $zero
    /* 25BC 8006ADBC 21188600 */  addu       $v1, $a0, $a2
  .L8006ADC0:
    /* 25C0 8006ADC0 2110E600 */  addu       $v0, $a3, $a2
    /* 25C4 8006ADC4 14004290 */  lbu        $v0, 0x14($v0)
    /* 25C8 8006ADC8 0100C624 */  addiu      $a2, $a2, 0x1
    /* 25CC 8006ADCC 200062A0 */  sb         $v0, 0x20($v1)
    /* 25D0 8006ADD0 0600C228 */  slti       $v0, $a2, 0x6
    /* 25D4 8006ADD4 FAFF4014 */  bnez       $v0, .L8006ADC0
    /* 25D8 8006ADD8 21188600 */   addu      $v1, $a0, $a2
    /* 25DC 8006ADDC 21300000 */  addu       $a2, $zero, $zero
    /* 25E0 8006ADE0 21188600 */  addu       $v1, $a0, $a2
  .L8006ADE4:
    /* 25E4 8006ADE4 2110E600 */  addu       $v0, $a3, $a2
    /* 25E8 8006ADE8 1C004290 */  lbu        $v0, 0x1C($v0)
    /* 25EC 8006ADEC 0100C624 */  addiu      $a2, $a2, 0x1
    /* 25F0 8006ADF0 280062A0 */  sb         $v0, 0x28($v1)
    /* 25F4 8006ADF4 0700C228 */  slti       $v0, $a2, 0x7
    /* 25F8 8006ADF8 FAFF4014 */  bnez       $v0, .L8006ADE4
    /* 25FC 8006ADFC 21188600 */   addu      $v1, $a0, $a2
    /* 2600 8006AE00 2400A290 */  lbu        $v0, 0x24($a1)
    /* 2604 8006AE04 0800E003 */  jr         $ra
    /* 2608 8006AE08 130082A0 */   sb        $v0, 0x13($a0)
endlabel vs_battle_copyInventoryArmorStats
