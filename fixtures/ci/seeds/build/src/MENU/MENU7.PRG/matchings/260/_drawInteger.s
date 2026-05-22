nonmatching _drawInteger, 0x98

glabel _drawInteger
    /* 1FA8 801047A8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1FAC 801047AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1FB0 801047B0 21908000 */  addu       $s2, $a0, $zero
    /* 1FB4 801047B4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1FB8 801047B8 2188C000 */  addu       $s1, $a2, $zero
    /* 1FBC 801047BC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1FC0 801047C0 F437143C */  lui        $s4, (0x37F40000 >> 16)
    /* 1FC4 801047C4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1FC8 801047C8 CCCC133C */  lui        $s3, (0xCCCCCCCD >> 16)
    /* 1FCC 801047CC CDCC7336 */  ori        $s3, $s3, (0xCCCCCCCD & 0xFFFF)
    /* 1FD0 801047D0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1FD4 801047D4 1000B0AF */  sw         $s0, 0x10($sp)
  .L801047D8:
    /* 1FD8 801047D8 1B00B100 */  divu       $zero, $a1, $s1
    /* 1FDC 801047DC 12100000 */  mflo       $v0
    /* 1FE0 801047E0 10800000 */  mfhi       $s0
    /* 1FE4 801047E4 0A00063C */  lui        $a2, (0xA0006 >> 16)
    /* 1FE8 801047E8 0600C634 */  ori        $a2, $a2, (0xA0006 & 0xFFFF)
    /* 1FEC 801047EC 21204002 */  addu       $a0, $s2, $zero
    /* 1FF0 801047F0 0C000724 */  addiu      $a3, $zero, 0xC
    /* 1FF4 801047F4 40280200 */  sll        $a1, $v0, 1
    /* 1FF8 801047F8 2128A200 */  addu       $a1, $a1, $v0
    /* 1FFC 801047FC 40280500 */  sll        $a1, $a1, 1
    /* 2000 80104800 B011040C */  jal        _drawSprt
    /* 2004 80104804 2528B400 */   or        $a1, $a1, $s4
    /* 2008 80104808 19003302 */  multu      $s1, $s3
    /* 200C 8010480C 21280002 */  addu       $a1, $s0, $zero
    /* 2010 80104810 10100000 */  mfhi       $v0
    /* 2014 80104814 C2880200 */  srl        $s1, $v0, 3
    /* 2018 80104818 EFFF2016 */  bnez       $s1, .L801047D8
    /* 201C 8010481C 05005226 */   addiu     $s2, $s2, 0x5
    /* 2020 80104820 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2024 80104824 2000B48F */  lw         $s4, 0x20($sp)
    /* 2028 80104828 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 202C 8010482C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2030 80104830 1400B18F */  lw         $s1, 0x14($sp)
    /* 2034 80104834 1000B08F */  lw         $s0, 0x10($sp)
    /* 2038 80104838 0800E003 */  jr         $ra
    /* 203C 8010483C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _drawInteger
