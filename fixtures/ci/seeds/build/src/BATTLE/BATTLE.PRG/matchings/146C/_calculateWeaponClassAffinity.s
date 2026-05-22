nonmatching _calculateWeaponClassAffinity, 0xD4

glabel _calculateWeaponClassAffinity
    /* 15B80 8007E380 21408000 */  addu       $t0, $a0, $zero
    /* 15B84 8007E384 21300000 */  addu       $a2, $zero, $zero
    /* 15B88 8007E388 21380001 */  addu       $a3, $t0, $zero
  .L8007E38C:
    /* 15B8C 8007E38C 21100601 */  addu       $v0, $t0, $a2
    /* 15B90 8007E390 0100C624 */  addiu      $a2, $a2, 0x1
    /* 15B94 8007E394 74004490 */  lbu        $a0, 0x74($v0)
    /* 15B98 8007E398 D4004590 */  lbu        $a1, 0xD4($v0)
    /* 15B9C 8007E39C 04014390 */  lbu        $v1, 0x104($v0)
    /* 15BA0 8007E3A0 34014290 */  lbu        $v0, 0x134($v0)
    /* 15BA4 8007E3A4 00260400 */  sll        $a0, $a0, 24
    /* 15BA8 8007E3A8 03260400 */  sra        $a0, $a0, 24
    /* 15BAC 8007E3AC 002E0500 */  sll        $a1, $a1, 24
    /* 15BB0 8007E3B0 032E0500 */  sra        $a1, $a1, 24
    /* 15BB4 8007E3B4 001E0300 */  sll        $v1, $v1, 24
    /* 15BB8 8007E3B8 031E0300 */  sra        $v1, $v1, 24
    /* 15BBC 8007E3BC 00160200 */  sll        $v0, $v0, 24
    /* 15BC0 8007E3C0 03160200 */  sra        $v0, $v0, 24
    /* 15BC4 8007E3C4 21208500 */  addu       $a0, $a0, $a1
    /* 15BC8 8007E3C8 21186400 */  addu       $v1, $v1, $a0
    /* 15BCC 8007E3CC 21104300 */  addu       $v0, $v0, $v1
    /* 15BD0 8007E3D0 7401E2A4 */  sh         $v0, 0x174($a3)
    /* 15BD4 8007E3D4 6401E2A4 */  sh         $v0, 0x164($a3)
    /* 15BD8 8007E3D8 0600C228 */  slti       $v0, $a2, 0x6
    /* 15BDC 8007E3DC EBFF4014 */  bnez       $v0, .L8007E38C
    /* 15BE0 8007E3E0 0200E724 */   addiu     $a3, $a3, 0x2
    /* 15BE4 8007E3E4 21300000 */  addu       $a2, $zero, $zero
    /* 15BE8 8007E3E8 21380001 */  addu       $a3, $t0, $zero
  .L8007E3EC:
    /* 15BEC 8007E3EC 21100601 */  addu       $v0, $t0, $a2
    /* 15BF0 8007E3F0 0100C624 */  addiu      $a2, $a2, 0x1
    /* 15BF4 8007E3F4 7C004490 */  lbu        $a0, 0x7C($v0)
    /* 15BF8 8007E3F8 DC004590 */  lbu        $a1, 0xDC($v0)
    /* 15BFC 8007E3FC 0C014390 */  lbu        $v1, 0x10C($v0)
    /* 15C00 8007E400 3C014290 */  lbu        $v0, 0x13C($v0)
    /* 15C04 8007E404 00260400 */  sll        $a0, $a0, 24
    /* 15C08 8007E408 03260400 */  sra        $a0, $a0, 24
    /* 15C0C 8007E40C 002E0500 */  sll        $a1, $a1, 24
    /* 15C10 8007E410 032E0500 */  sra        $a1, $a1, 24
    /* 15C14 8007E414 001E0300 */  sll        $v1, $v1, 24
    /* 15C18 8007E418 031E0300 */  sra        $v1, $v1, 24
    /* 15C1C 8007E41C 00160200 */  sll        $v0, $v0, 24
    /* 15C20 8007E420 03160200 */  sra        $v0, $v0, 24
    /* 15C24 8007E424 21208500 */  addu       $a0, $a0, $a1
    /* 15C28 8007E428 21186400 */  addu       $v1, $v1, $a0
    /* 15C2C 8007E42C A401E494 */  lhu        $a0, 0x1A4($a3)
    /* 15C30 8007E430 21104300 */  addu       $v0, $v0, $v1
    /* 15C34 8007E434 9401E2A4 */  sh         $v0, 0x194($a3)
    /* 15C38 8007E438 21104400 */  addu       $v0, $v0, $a0
    /* 15C3C 8007E43C 8401E2A4 */  sh         $v0, 0x184($a3)
    /* 15C40 8007E440 0700C228 */  slti       $v0, $a2, 0x7
    /* 15C44 8007E444 E9FF4014 */  bnez       $v0, .L8007E3EC
    /* 15C48 8007E448 0200E724 */   addiu     $a3, $a3, 0x2
    /* 15C4C 8007E44C 0800E003 */  jr         $ra
    /* 15C50 8007E450 00000000 */   nop
endlabel _calculateWeaponClassAffinity
