nonmatching _calculateShieldClassAffinity, 0xD4

glabel _calculateShieldClassAffinity
    /* 15AAC 8007E2AC 21408000 */  addu       $t0, $a0, $zero
    /* 15AB0 8007E2B0 21300000 */  addu       $a2, $zero, $zero
    /* 15AB4 8007E2B4 21380001 */  addu       $a3, $t0, $zero
  .L8007E2B8:
    /* 15AB8 8007E2B8 21100601 */  addu       $v0, $t0, $a2
    /* 15ABC 8007E2BC 0100C624 */  addiu      $a2, $a2, 0x1
    /* 15AC0 8007E2C0 0C024490 */  lbu        $a0, 0x20C($v0)
    /* 15AC4 8007E2C4 3C024590 */  lbu        $a1, 0x23C($v0)
    /* 15AC8 8007E2C8 6C024390 */  lbu        $v1, 0x26C($v0)
    /* 15ACC 8007E2CC 9C024290 */  lbu        $v0, 0x29C($v0)
    /* 15AD0 8007E2D0 00260400 */  sll        $a0, $a0, 24
    /* 15AD4 8007E2D4 03260400 */  sra        $a0, $a0, 24
    /* 15AD8 8007E2D8 002E0500 */  sll        $a1, $a1, 24
    /* 15ADC 8007E2DC 032E0500 */  sra        $a1, $a1, 24
    /* 15AE0 8007E2E0 001E0300 */  sll        $v1, $v1, 24
    /* 15AE4 8007E2E4 031E0300 */  sra        $v1, $v1, 24
    /* 15AE8 8007E2E8 00160200 */  sll        $v0, $v0, 24
    /* 15AEC 8007E2EC 03160200 */  sra        $v0, $v0, 24
    /* 15AF0 8007E2F0 21208500 */  addu       $a0, $a0, $a1
    /* 15AF4 8007E2F4 21186400 */  addu       $v1, $v1, $a0
    /* 15AF8 8007E2F8 21104300 */  addu       $v0, $v0, $v1
    /* 15AFC 8007E2FC D802E2A4 */  sh         $v0, 0x2D8($a3)
    /* 15B00 8007E300 C802E2A4 */  sh         $v0, 0x2C8($a3)
    /* 15B04 8007E304 0600C228 */  slti       $v0, $a2, 0x6
    /* 15B08 8007E308 EBFF4014 */  bnez       $v0, .L8007E2B8
    /* 15B0C 8007E30C 0200E724 */   addiu     $a3, $a3, 0x2
    /* 15B10 8007E310 21300000 */  addu       $a2, $zero, $zero
    /* 15B14 8007E314 21380001 */  addu       $a3, $t0, $zero
  .L8007E318:
    /* 15B18 8007E318 21100601 */  addu       $v0, $t0, $a2
    /* 15B1C 8007E31C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 15B20 8007E320 14024490 */  lbu        $a0, 0x214($v0)
    /* 15B24 8007E324 44024590 */  lbu        $a1, 0x244($v0)
    /* 15B28 8007E328 74024390 */  lbu        $v1, 0x274($v0)
    /* 15B2C 8007E32C A4024290 */  lbu        $v0, 0x2A4($v0)
    /* 15B30 8007E330 00260400 */  sll        $a0, $a0, 24
    /* 15B34 8007E334 03260400 */  sra        $a0, $a0, 24
    /* 15B38 8007E338 002E0500 */  sll        $a1, $a1, 24
    /* 15B3C 8007E33C 032E0500 */  sra        $a1, $a1, 24
    /* 15B40 8007E340 001E0300 */  sll        $v1, $v1, 24
    /* 15B44 8007E344 031E0300 */  sra        $v1, $v1, 24
    /* 15B48 8007E348 00160200 */  sll        $v0, $v0, 24
    /* 15B4C 8007E34C 03160200 */  sra        $v0, $v0, 24
    /* 15B50 8007E350 21208500 */  addu       $a0, $a0, $a1
    /* 15B54 8007E354 21186400 */  addu       $v1, $v1, $a0
    /* 15B58 8007E358 0803E494 */  lhu        $a0, 0x308($a3)
    /* 15B5C 8007E35C 21104300 */  addu       $v0, $v0, $v1
    /* 15B60 8007E360 F802E2A4 */  sh         $v0, 0x2F8($a3)
    /* 15B64 8007E364 21104400 */  addu       $v0, $v0, $a0
    /* 15B68 8007E368 E802E2A4 */  sh         $v0, 0x2E8($a3)
    /* 15B6C 8007E36C 0700C228 */  slti       $v0, $a2, 0x7
    /* 15B70 8007E370 E9FF4014 */  bnez       $v0, .L8007E318
    /* 15B74 8007E374 0200E724 */   addiu     $a3, $a3, 0x2
    /* 15B78 8007E378 0800E003 */  jr         $ra
    /* 15B7C 8007E37C 00000000 */   nop
endlabel _calculateShieldClassAffinity
