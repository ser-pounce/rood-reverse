nonmatching vs_main_allocateCdQueueSlot, 0x70

glabel vs_main_allocateCdQueueSlot
    /* 35310 80044B10 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35314 80044B14 1000BFAF */  sw         $ra, 0x10($sp)
    /* 35318 80044B18 21280000 */  addu       $a1, $zero, $zero
    /* 3531C 80044B1C 01000624 */  addiu      $a2, $zero, 0x1
    /* 35320 80044B20 0580023C */  lui        $v0, %hi(_cdQueue)
    /* 35324 80044B24 E0014324 */  addiu      $v1, $v0, %lo(_cdQueue)
  .L80044B28:
    /* 35328 80044B28 00006284 */  lh         $v0, 0x0($v1)
    /* 3532C 80044B2C 00000000 */  nop
    /* 35330 80044B30 08004014 */  bnez       $v0, .L80044B54
    /* 35334 80044B34 21106000 */   addu      $v0, $v1, $zero
    /* 35338 80044B38 000046A4 */  sh         $a2, 0x0($v0)
    /* 3533C 80044B3C 0000878C */  lw         $a3, 0x0($a0)
    /* 35340 80044B40 0400888C */  lw         $t0, 0x4($a0)
    /* 35344 80044B44 040047AC */  sw         $a3, 0x4($v0)
    /* 35348 80044B48 080048AC */  sw         $t0, 0x8($v0)
    /* 3534C 80044B4C DC120108 */  j          .L80044B70
    /* 35350 80044B50 00000000 */   nop
  .L80044B54:
    /* 35354 80044B54 0100A524 */  addiu      $a1, $a1, 0x1
    /* 35358 80044B58 2000A228 */  slti       $v0, $a1, 0x20
    /* 3535C 80044B5C F2FF4014 */  bnez       $v0, .L80044B28
    /* 35360 80044B60 14006324 */   addiu     $v1, $v1, 0x14
    /* 35364 80044B64 A2000424 */  addiu      $a0, $zero, 0xA2
    /* 35368 80044B68 2624010C */  jal        vs_main_nop9
    /* 3536C 80044B6C 21280000 */   addu      $a1, $zero, $zero
  .L80044B70:
    /* 35370 80044B70 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35374 80044B74 00000000 */  nop
    /* 35378 80044B78 0800E003 */  jr         $ra
    /* 3537C 80044B7C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_allocateCdQueueSlot
