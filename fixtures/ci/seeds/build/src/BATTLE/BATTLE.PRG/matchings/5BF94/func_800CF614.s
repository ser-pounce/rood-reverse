nonmatching func_800CF614, 0x80

glabel func_800CF614
    /* 66E14 800CF614 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 66E18 800CF618 1000B0AF */  sw         $s0, 0x10($sp)
    /* 66E1C 800CF61C 21808000 */  addu       $s0, $a0, $zero
    /* 66E20 800CF620 0F80043C */  lui        $a0, %hi(D_800F54B0)
    /* 66E24 800CF624 B054838C */  lw         $v1, %lo(D_800F54B0)($a0)
    /* 66E28 800CF628 00000000 */  nop
    /* 66E2C 800CF62C 0A007014 */  bne        $v1, $s0, .L800CF658
    /* 66E30 800CF630 1400BFAF */   sw        $ra, 0x14($sp)
    /* 66E34 800CF634 0000028E */  lw         $v0, 0x0($s0)
    /* 66E38 800CF638 9A3D0308 */  j          .L800CF668
    /* 66E3C 800CF63C B05482AC */   sw        $v0, %lo(D_800F54B0)($a0)
  .L800CF640:
    /* 66E40 800CF640 0000028E */  lw         $v0, 0x0($s0)
    /* 66E44 800CF644 9A3D0308 */  j          .L800CF668
    /* 66E48 800CF648 000062AC */   sw        $v0, 0x0($v1)
  .L800CF64C:
    /* 66E4C 800CF64C FCFF5010 */  beq        $v0, $s0, .L800CF640
    /* 66E50 800CF650 00000000 */   nop
    /* 66E54 800CF654 21184000 */  addu       $v1, $v0, $zero
  .L800CF658:
    /* 66E58 800CF658 0000628C */  lw         $v0, 0x0($v1)
    /* 66E5C 800CF65C 00000000 */  nop
    /* 66E60 800CF660 FAFF4014 */  bnez       $v0, .L800CF64C
    /* 66E64 800CF664 00000000 */   nop
  .L800CF668:
    /* 66E68 800CF668 414A030C */  jal        func_800D2904
    /* 66E6C 800CF66C 21200002 */   addu      $a0, $s0, $zero
    /* 66E70 800CF670 14000492 */  lbu        $a0, 0x14($s0)
    /* 66E74 800CF674 453D030C */  jal        func_800CF514
    /* 66E78 800CF678 00000000 */   nop
    /* 66E7C 800CF67C 180F010C */  jal        vs_main_freeHeapR
    /* 66E80 800CF680 21200002 */   addu      $a0, $s0, $zero
    /* 66E84 800CF684 1400BF8F */  lw         $ra, 0x14($sp)
    /* 66E88 800CF688 1000B08F */  lw         $s0, 0x10($sp)
    /* 66E8C 800CF68C 0800E003 */  jr         $ra
    /* 66E90 800CF690 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CF614
