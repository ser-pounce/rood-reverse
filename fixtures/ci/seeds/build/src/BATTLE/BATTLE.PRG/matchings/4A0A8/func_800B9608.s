nonmatching func_800B9608, 0x68

glabel func_800B9608
    /* 50E08 800B9608 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50E0C 800B960C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50E10 800B9610 21808000 */  addu       $s0, $a0, $zero
    /* 50E14 800B9614 1400BFAF */  sw         $ra, 0x14($sp)
    /* 50E18 800B9618 80FF020C */  jal        vs_battle_getShort
    /* 50E1C 800B961C 01000426 */   addiu     $a0, $s0, 0x1
    /* 50E20 800B9620 94FF020C */  jal        func_800BFE50
    /* 50E24 800B9624 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 50E28 800B9628 21204000 */  addu       $a0, $v0, $zero
    /* 50E2C 800B962C 03000392 */  lbu        $v1, 0x3($s0)
    /* 50E30 800B9630 FE000224 */  addiu      $v0, $zero, 0xFE
    /* 50E34 800B9634 05006214 */  bne        $v1, $v0, .L800B964C
    /* 50E38 800B9638 00000000 */   nop
    /* 50E3C 800B963C A9F2010C */  jal        func_8007CAA4
    /* 50E40 800B9640 FFFF8430 */   andi      $a0, $a0, 0xFFFF
    /* 50E44 800B9644 97E50208 */  j          .L800B965C
    /* 50E48 800B9648 00000000 */   nop
  .L800B964C:
    /* 50E4C 800B964C 03000592 */  lbu        $a1, 0x3($s0)
    /* 50E50 800B9650 05000692 */  lbu        $a2, 0x5($s0)
    /* 50E54 800B9654 88F2010C */  jal        func_8007CA20
    /* 50E58 800B9658 FFFF8430 */   andi      $a0, $a0, 0xFFFF
  .L800B965C:
    /* 50E5C 800B965C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 50E60 800B9660 1000B08F */  lw         $s0, 0x10($sp)
    /* 50E64 800B9664 21100000 */  addu       $v0, $zero, $zero
    /* 50E68 800B9668 0800E003 */  jr         $ra
    /* 50E6C 800B966C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9608
