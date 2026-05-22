nonmatching _getEmptyContainerSlot, 0x90

glabel _getEmptyContainerSlot
    /* 910 80103110 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 914 80103114 1800B2AF */  sw         $s2, 0x18($sp)
    /* 918 80103118 21908000 */  addu       $s2, $a0, $zero
    /* 91C 8010311C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 920 80103120 2198A000 */  addu       $s3, $a1, $zero
    /* 924 80103124 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 928 80103128 44994224 */  addiu      $v0, $v0, %lo(_containerItemCapacities)
    /* 92C 8010312C 40181200 */  sll        $v1, $s2, 1
    /* 930 80103130 21186200 */  addu       $v1, $v1, $v0
    /* 934 80103134 2000BFAF */  sw         $ra, 0x20($sp)
    /* 938 80103138 1400B1AF */  sw         $s1, 0x14($sp)
    /* 93C 8010313C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 940 80103140 00006294 */  lhu        $v0, 0x0($v1)
    /* 944 80103144 00000000 */  nop
    /* 948 80103148 0D004010 */  beqz       $v0, .L80103180
    /* 94C 8010314C 21800000 */   addu      $s0, $zero, $zero
    /* 950 80103150 21886000 */  addu       $s1, $v1, $zero
    /* 954 80103154 21204002 */  addu       $a0, $s2, $zero
  .L80103158:
    /* 958 80103158 21280002 */  addu       $a1, $s0, $zero
    /* 95C 8010315C E20B040C */  jal        _getContainerItemId
    /* 960 80103160 21306002 */   addu      $a2, $s3, $zero
    /* 964 80103164 07004010 */  beqz       $v0, .L80103184
    /* 968 80103168 21100002 */   addu      $v0, $s0, $zero
    /* 96C 8010316C 00002296 */  lhu        $v0, 0x0($s1)
    /* 970 80103170 01001026 */  addiu      $s0, $s0, 0x1
    /* 974 80103174 2A100202 */  slt        $v0, $s0, $v0
    /* 978 80103178 F7FF4014 */  bnez       $v0, .L80103158
    /* 97C 8010317C 21204002 */   addu      $a0, $s2, $zero
  .L80103180:
    /* 980 80103180 21100002 */  addu       $v0, $s0, $zero
  .L80103184:
    /* 984 80103184 2000BF8F */  lw         $ra, 0x20($sp)
    /* 988 80103188 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 98C 8010318C 1800B28F */  lw         $s2, 0x18($sp)
    /* 990 80103190 1400B18F */  lw         $s1, 0x14($sp)
    /* 994 80103194 1000B08F */  lw         $s0, 0x10($sp)
    /* 998 80103198 0800E003 */  jr         $ra
    /* 99C 8010319C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _getEmptyContainerSlot
