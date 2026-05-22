nonmatching _copyMiscToInventory, 0x64

glabel _copyMiscToInventory
    /* 588C 8010808C 1180023C */  lui        $v0, %hi(_inventory)
    /* 5890 80108090 A8A6428C */  lw         $v0, %lo(_inventory)($v0)
    /* 5894 80108094 01000624 */  addiu      $a2, $zero, 0x1
    /* 5898 80108098 000E4394 */  lhu        $v1, 0xE00($v0)
    /* 589C 8010809C 00000000 */  nop
    /* 58A0 801080A0 0C006010 */  beqz       $v1, .L801080D4
    /* 58A4 801080A4 000E4524 */   addiu     $a1, $v0, 0xE00
    /* 58A8 801080A8 40000324 */  addiu      $v1, $zero, 0x40
    /* 58AC 801080AC 0100C624 */  addiu      $a2, $a2, 0x1
  .L801080B0:
    /* 58B0 801080B0 0300C314 */  bne        $a2, $v1, .L801080C0
    /* 58B4 801080B4 0400A524 */   addiu     $a1, $a1, 0x4
    /* 58B8 801080B8 0800E003 */  jr         $ra
    /* 58BC 801080BC 21100000 */   addu      $v0, $zero, $zero
  .L801080C0:
    /* 58C0 801080C0 0000A294 */  lhu        $v0, 0x0($a1)
    /* 58C4 801080C4 00000000 */  nop
    /* 58C8 801080C8 F9FF4014 */  bnez       $v0, .L801080B0
    /* 58CC 801080CC 0100C624 */   addiu     $a2, $a2, 0x1
    /* 58D0 801080D0 FFFFC624 */  addiu      $a2, $a2, -0x1
  .L801080D4:
    /* 58D4 801080D4 00008294 */  lhu        $v0, 0x0($a0)
    /* 58D8 801080D8 00000000 */  nop
    /* 58DC 801080DC 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 58E0 801080E0 03008390 */  lbu        $v1, 0x3($a0)
    /* 58E4 801080E4 2110C000 */  addu       $v0, $a2, $zero
    /* 58E8 801080E8 0800E003 */  jr         $ra
    /* 58EC 801080EC 0200A3A0 */   sb        $v1, 0x2($a1)
endlabel _copyMiscToInventory
