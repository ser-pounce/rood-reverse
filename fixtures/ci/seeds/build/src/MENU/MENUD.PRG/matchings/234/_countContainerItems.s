nonmatching _countContainerItems, 0xA0

glabel _countContainerItems
    /* 870 80103070 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 874 80103074 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 878 80103078 21988000 */  addu       $s3, $a0, $zero
    /* 87C 8010307C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 880 80103080 21A0A000 */  addu       $s4, $a1, $zero
    /* 884 80103084 1000B0AF */  sw         $s0, 0x10($sp)
    /* 888 80103088 21800000 */  addu       $s0, $zero, $zero
    /* 88C 8010308C 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 890 80103090 44994224 */  addiu      $v0, $v0, %lo(_containerItemCapacities)
    /* 894 80103094 40181300 */  sll        $v1, $s3, 1
    /* 898 80103098 21186200 */  addu       $v1, $v1, $v0
    /* 89C 8010309C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 8A0 801030A0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8A4 801030A4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8A8 801030A8 00006294 */  lhu        $v0, 0x0($v1)
    /* 8AC 801030AC 00000000 */  nop
    /* 8B0 801030B0 0E004010 */  beqz       $v0, .L801030EC
    /* 8B4 801030B4 21880002 */   addu      $s1, $s0, $zero
    /* 8B8 801030B8 21906000 */  addu       $s2, $v1, $zero
    /* 8BC 801030BC 21206002 */  addu       $a0, $s3, $zero
  .L801030C0:
    /* 8C0 801030C0 21280002 */  addu       $a1, $s0, $zero
    /* 8C4 801030C4 E20B040C */  jal        _getContainerItemId
    /* 8C8 801030C8 21308002 */   addu      $a2, $s4, $zero
    /* 8CC 801030CC 02004010 */  beqz       $v0, .L801030D8
    /* 8D0 801030D0 00000000 */   nop
    /* 8D4 801030D4 01003126 */  addiu      $s1, $s1, 0x1
  .L801030D8:
    /* 8D8 801030D8 00004296 */  lhu        $v0, 0x0($s2)
    /* 8DC 801030DC 01001026 */  addiu      $s0, $s0, 0x1
    /* 8E0 801030E0 2A100202 */  slt        $v0, $s0, $v0
    /* 8E4 801030E4 F6FF4014 */  bnez       $v0, .L801030C0
    /* 8E8 801030E8 21206002 */   addu      $a0, $s3, $zero
  .L801030EC:
    /* 8EC 801030EC 21102002 */  addu       $v0, $s1, $zero
    /* 8F0 801030F0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 8F4 801030F4 2000B48F */  lw         $s4, 0x20($sp)
    /* 8F8 801030F8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8FC 801030FC 1800B28F */  lw         $s2, 0x18($sp)
    /* 900 80103100 1400B18F */  lw         $s1, 0x14($sp)
    /* 904 80103104 1000B08F */  lw         $s0, 0x10($sp)
    /* 908 80103108 0800E003 */  jr         $ra
    /* 90C 8010310C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _countContainerItems
