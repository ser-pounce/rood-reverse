nonmatching func_800A46A4, 0x120

glabel func_800A46A4
    /* 3BEA4 800A46A4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3BEA8 800A46A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3BEAC 800A46AC 21888000 */  addu       $s1, $a0, $zero
    /* 3BEB0 800A46B0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3BEB4 800A46B4 E7FF133C */  lui        $s3, (0xFFE7FFFF >> 16)
    /* 3BEB8 800A46B8 FFFF7336 */  ori        $s3, $s3, (0xFFE7FFFF & 0xFFFF)
    /* 3BEBC 800A46BC 00020424 */  addiu      $a0, $zero, 0x200
    /* 3BEC0 800A46C0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3BEC4 800A46C4 F0FF1424 */  addiu      $s4, $zero, -0x10
    /* 3BEC8 800A46C8 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3BECC 800A46CC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3BED0 800A46D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3BED4 800A46D4 0C002592 */  lbu        $a1, 0xC($s1)
    /* 3BED8 800A46D8 0C00228E */  lw         $v0, 0xC($s1)
    /* 3BEDC 800A46DC 0800238E */  lw         $v1, 0x8($s1)
    /* 3BEE0 800A46E0 3C063096 */  lhu        $s0, 0x63C($s1)
    /* 3BEE4 800A46E4 24105400 */  and        $v0, $v0, $s4
    /* 3BEE8 800A46E8 24187300 */  and        $v1, $v1, $s3
    /* 3BEEC 800A46EC 0C0022AE */  sw         $v0, 0xC($s1)
    /* 3BEF0 800A46F0 FFBF0224 */  addiu      $v0, $zero, -0x4001
    /* 3BEF4 800A46F4 24186200 */  and        $v1, $v1, $v0
    /* 3BEF8 800A46F8 0F00B230 */  andi       $s2, $a1, 0xF
    /* 3BEFC 800A46FC CA03010C */  jal        rsin
    /* 3BF00 800A4700 080023AE */   sw        $v1, 0x8($s1)
    /* 3BF04 800A4704 18005000 */  mult       $v0, $s0
    /* 3BF08 800A4708 801F103C */  lui        $s0, (0x1F8003BC >> 16)
    /* 3BF0C 800A470C 12100000 */  mflo       $v0
    /* 3BF10 800A4710 02004104 */  bgez       $v0, .L800A471C
    /* 3BF14 800A4714 BC031036 */   ori       $s0, $s0, (0x1F8003BC & 0xFFFF)
    /* 3BF18 800A4718 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L800A471C:
    /* 3BF1C 800A471C 21202002 */  addu       $a0, $s1, $zero
    /* 3BF20 800A4720 379C020C */  jal        func_800A70DC
    /* 3BF24 800A4724 032B0200 */   sra       $a1, $v0, 12
    /* 3BF28 800A4728 1000023C */  lui        $v0, (0x100000 >> 16)
    /* 3BF2C 800A472C 0C00258E */  lw         $a1, 0xC($s1)
    /* 3BF30 800A4730 0800248E */  lw         $a0, 0x8($s1)
    /* 3BF34 800A4734 00182396 */  lhu        $v1, 0x1800($s1)
    /* 3BF38 800A4738 2428B400 */  and        $a1, $a1, $s4
    /* 3BF3C 800A473C 2528B200 */  or         $a1, $a1, $s2
    /* 3BF40 800A4740 24209300 */  and        $a0, $a0, $s3
    /* 3BF44 800A4744 25208200 */  or         $a0, $a0, $v0
    /* 3BF48 800A4748 42320300 */  srl        $a2, $v1, 9
    /* 3BF4C 800A474C 2110D000 */  addu       $v0, $a2, $s0
    /* 3BF50 800A4750 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 3BF54 800A4754 0700C630 */  andi       $a2, $a2, 0x7
    /* 3BF58 800A4758 2118D000 */  addu       $v1, $a2, $s0
    /* 3BF5C 800A475C 21300000 */  addu       $a2, $zero, $zero
    /* 3BF60 800A4760 0C0025AE */  sw         $a1, 0xC($s1)
    /* 3BF64 800A4764 080024AE */  sw         $a0, 0x8($s1)
    /* 3BF68 800A4768 2C0040A0 */  sb         $zero, 0x2C($v0)
    /* 3BF6C 800A476C 2D0040A0 */  sb         $zero, 0x2D($v0)
    /* 3BF70 800A4770 2C0060A0 */  sb         $zero, 0x2C($v1)
    /* 3BF74 800A4774 21100602 */  addu       $v0, $s0, $a2
  .L800A4778:
    /* 3BF78 800A4778 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 3BF7C 800A477C 00000000 */  nop
    /* 3BF80 800A4780 03004010 */  beqz       $v0, .L800A4790
    /* 3BF84 800A4784 0100C624 */   addiu     $a2, $a2, 0x1
    /* 3BF88 800A4788 E8910208 */  j          .L800A47A0
    /* 3BF8C 800A478C 01000224 */   addiu     $v0, $zero, 0x1
  .L800A4790:
    /* 3BF90 800A4790 0800C228 */  slti       $v0, $a2, 0x8
    /* 3BF94 800A4794 F8FF4014 */  bnez       $v0, .L800A4778
    /* 3BF98 800A4798 21100602 */   addu      $v0, $s0, $a2
    /* 3BF9C 800A479C 21100000 */  addu       $v0, $zero, $zero
  .L800A47A0:
    /* 3BFA0 800A47A0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 3BFA4 800A47A4 2000B48F */  lw         $s4, 0x20($sp)
    /* 3BFA8 800A47A8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3BFAC 800A47AC 1800B28F */  lw         $s2, 0x18($sp)
    /* 3BFB0 800A47B0 1400B18F */  lw         $s1, 0x14($sp)
    /* 3BFB4 800A47B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 3BFB8 800A47B8 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 3BFBC 800A47BC 0800E003 */  jr         $ra
    /* 3BFC0 800A47C0 00000000 */   nop
endlabel func_800A46A4
