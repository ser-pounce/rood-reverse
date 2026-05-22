nonmatching _drawInteger, 0x98

glabel _drawInteger
    /* 2060 8006A860 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2064 8006A864 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2068 8006A868 21908000 */  addu       $s2, $a0, $zero
    /* 206C 8006A86C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2070 8006A870 2188C000 */  addu       $s1, $a2, $zero
    /* 2074 8006A874 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2078 8006A878 F437143C */  lui        $s4, (0x37F40000 >> 16)
    /* 207C 8006A87C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2080 8006A880 CCCC133C */  lui        $s3, (0xCCCCCCCD >> 16)
    /* 2084 8006A884 CDCC7336 */  ori        $s3, $s3, (0xCCCCCCCD & 0xFFFF)
    /* 2088 8006A888 2400BFAF */  sw         $ra, 0x24($sp)
    /* 208C 8006A88C 1000B0AF */  sw         $s0, 0x10($sp)
  .L8006A890:
    /* 2090 8006A890 1B00B100 */  divu       $zero, $a1, $s1
    /* 2094 8006A894 12100000 */  mflo       $v0
    /* 2098 8006A898 10800000 */  mfhi       $s0
    /* 209C 8006A89C 0A00063C */  lui        $a2, (0xA0006 >> 16)
    /* 20A0 8006A8A0 0600C634 */  ori        $a2, $a2, (0xA0006 & 0xFFFF)
    /* 20A4 8006A8A4 21204002 */  addu       $a0, $s2, $zero
    /* 20A8 8006A8A8 0C000724 */  addiu      $a3, $zero, 0xC
    /* 20AC 8006A8AC 40280200 */  sll        $a1, $v0, 1
    /* 20B0 8006A8B0 2128A200 */  addu       $a1, $a1, $v0
    /* 20B4 8006A8B4 40280500 */  sll        $a1, $a1, 1
    /* 20B8 8006A8B8 DEA9010C */  jal        _drawSprt
    /* 20BC 8006A8BC 2528B400 */   or        $a1, $a1, $s4
    /* 20C0 8006A8C0 19003302 */  multu      $s1, $s3
    /* 20C4 8006A8C4 21280002 */  addu       $a1, $s0, $zero
    /* 20C8 8006A8C8 10100000 */  mfhi       $v0
    /* 20CC 8006A8CC C2880200 */  srl        $s1, $v0, 3
    /* 20D0 8006A8D0 EFFF2016 */  bnez       $s1, .L8006A890
    /* 20D4 8006A8D4 05005226 */   addiu     $s2, $s2, 0x5
    /* 20D8 8006A8D8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 20DC 8006A8DC 2000B48F */  lw         $s4, 0x20($sp)
    /* 20E0 8006A8E0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 20E4 8006A8E4 1800B28F */  lw         $s2, 0x18($sp)
    /* 20E8 8006A8E8 1400B18F */  lw         $s1, 0x14($sp)
    /* 20EC 8006A8EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 20F0 8006A8F0 0800E003 */  jr         $ra
    /* 20F4 8006A8F4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _drawInteger
