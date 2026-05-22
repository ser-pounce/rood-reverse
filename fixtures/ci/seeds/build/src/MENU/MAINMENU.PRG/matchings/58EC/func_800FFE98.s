nonmatching func_800FFE98, 0xA0

glabel func_800FFE98
    /* 6698 800FFE98 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 669C 800FFE9C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 66A0 800FFEA0 2180A000 */  addu       $s0, $a1, $zero
    /* 66A4 800FFEA4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 66A8 800FFEA8 2188C000 */  addu       $s1, $a2, $zero
    /* 66AC 800FFEAC 2400B5AF */  sw         $s5, 0x24($sp)
    /* 66B0 800FFEB0 21A8E000 */  addu       $s5, $a3, $zero
    /* 66B4 800FFEB4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 66B8 800FFEB8 21900000 */  addu       $s2, $zero, $zero
    /* 66BC 800FFEBC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 66C0 800FFEC0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 66C4 800FFEC4 04008104 */  bgez       $a0, .L800FFED8
    /* 66C8 800FFEC8 1C00B3AF */   sw        $s3, 0x1C($sp)
    /* 66CC 800FFECC 0F00023C */  lui        $v0, (0xF0000 >> 16)
    /* 66D0 800FFED0 21800202 */  addu       $s0, $s0, $v0
    /* 66D4 800FFED4 000F3126 */  addiu      $s1, $s1, 0xF00
  .L800FFED8:
    /* 66D8 800FFED8 00A40400 */  sll        $s4, $a0, 16
    /* 66DC 800FFEDC 009A0400 */  sll        $s3, $a0, 8
  .L800FFEE0:
    /* 66E0 800FFEE0 01005226 */  addiu      $s2, $s2, 0x1
    /* 66E4 800FFEE4 0100063C */  lui        $a2, (0x10010 >> 16)
    /* 66E8 800FFEE8 1000C634 */  ori        $a2, $a2, (0x10010 & 0xFFFF)
    /* 66EC 800FFEEC C0201200 */  sll        $a0, $s2, 3
    /* 66F0 800FFEF0 00018434 */  ori        $a0, $a0, 0x100
    /* 66F4 800FFEF4 21280002 */  addu       $a1, $s0, $zero
    /* 66F8 800FFEF8 8900030C */  jal        func_800C0224
    /* 66FC 800FFEFC 2138A002 */   addu      $a3, $s5, $zero
    /* 6700 800FFF00 100051AC */  sw         $s1, 0x10($v0)
    /* 6704 800FFF04 21801402 */  addu       $s0, $s0, $s4
    /* 6708 800FFF08 1000422A */  slti       $v0, $s2, 0x10
    /* 670C 800FFF0C F4FF4014 */  bnez       $v0, .L800FFEE0
    /* 6710 800FFF10 21883302 */   addu      $s1, $s1, $s3
    /* 6714 800FFF14 2800BF8F */  lw         $ra, 0x28($sp)
    /* 6718 800FFF18 2400B58F */  lw         $s5, 0x24($sp)
    /* 671C 800FFF1C 2000B48F */  lw         $s4, 0x20($sp)
    /* 6720 800FFF20 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6724 800FFF24 1800B28F */  lw         $s2, 0x18($sp)
    /* 6728 800FFF28 1400B18F */  lw         $s1, 0x14($sp)
    /* 672C 800FFF2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6730 800FFF30 0800E003 */  jr         $ra
    /* 6734 800FFF34 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800FFE98
