nonmatching func_800FFCDC, 0x88

glabel func_800FFCDC
    /* 64DC 800FFCDC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 64E0 800FFCE0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 64E4 800FFCE4 1080113C */  lui        $s1, %hi(D_801022D5)
    /* 64E8 800FFCE8 801F033C */  lui        $v1, (0x1F800008 >> 16)
    /* 64EC 800FFCEC D5222292 */  lbu        $v0, %lo(D_801022D5)($s1)
    /* 64F0 800FFCF0 0800678C */  lw         $a3, (0x1F800008 & 0xFFFF)($v1)
    /* 64F4 800FFCF4 1000063C */  lui        $a2, (0x100010 >> 16)
    /* 64F8 800FFCF8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 64FC 800FFCFC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6500 800FFD00 C0100200 */  sll        $v0, $v0, 3
    /* 6504 800FFD04 06804400 */  srlv       $s0, $a0, $v0
    /* 6508 800FFD08 0F80023C */  lui        $v0, %hi(D_800EC270)
    /* 650C 800FFD0C 70C24224 */  addiu      $v0, $v0, %lo(D_800EC270)
    /* 6510 800FFD10 21100202 */  addu       $v0, $s0, $v0
    /* 6514 800FFD14 00004490 */  lbu        $a0, 0x0($v0)
    /* 6518 800FFD18 8900030C */  jal        func_800C0224
    /* 651C 800FFD1C 1000C634 */   ori       $a2, $a2, (0x100010 & 0xFFFF)
    /* 6520 800FFD20 FA37043C */  lui        $a0, (0x37FA3020 >> 16)
    /* 6524 800FFD24 20308434 */  ori        $a0, $a0, (0x37FA3020 & 0xFFFF)
    /* 6528 800FFD28 D5222392 */  lbu        $v1, %lo(D_801022D5)($s1)
    /* 652C 800FFD2C 00000000 */  nop
    /* 6530 800FFD30 03006014 */  bnez       $v1, .L800FFD40
    /* 6534 800FFD34 21284000 */   addu      $a1, $v0, $zero
    /* 6538 800FFD38 F837043C */  lui        $a0, (0x37F83020 >> 16)
    /* 653C 800FFD3C 20308434 */  ori        $a0, $a0, (0x37F83020 & 0xFFFF)
  .L800FFD40:
    /* 6540 800FFD40 1000A4AC */  sw         $a0, 0x10($a1)
    /* 6544 800FFD44 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6548 800FFD48 01000226 */  addiu      $v0, $s0, 0x1
    /* 654C 800FFD4C D52220A2 */  sb         $zero, %lo(D_801022D5)($s1)
    /* 6550 800FFD50 1400B18F */  lw         $s1, 0x14($sp)
    /* 6554 800FFD54 1000B08F */  lw         $s0, 0x10($sp)
    /* 6558 800FFD58 0F004230 */  andi       $v0, $v0, 0xF
    /* 655C 800FFD5C 0800E003 */  jr         $ra
    /* 6560 800FFD60 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800FFCDC
