nonmatching func_80047AB4, 0x7C

glabel func_80047AB4
    /* 382B4 80047AB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 382B8 80047AB8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 382BC 80047ABC 2180A000 */  addu       $s0, $a1, $zero
    /* 382C0 80047AC0 0580023C */  lui        $v0, %hi(_clutState)
    /* 382C4 80047AC4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 382C8 80047AC8 585D5124 */  addiu      $s1, $v0, %lo(_clutState)
    /* 382CC 80047ACC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 382D0 80047AD0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 382D4 80047AD4 02002296 */  lhu        $v0, 0x2($s1)
    /* 382D8 80047AD8 00000000 */  nop
    /* 382DC 80047ADC 0E004010 */  beqz       $v0, .L80047B18
    /* 382E0 80047AE0 2190C000 */   addu      $s2, $a2, $zero
    /* 382E4 80047AE4 441E010C */  jal        func_80047910
    /* 382E8 80047AE8 00000000 */   nop
    /* 382EC 80047AEC 40101000 */  sll        $v0, $s0, 1
    /* 382F0 80047AF0 21105000 */  addu       $v0, $v0, $s0
    /* 382F4 80047AF4 80100200 */  sll        $v0, $v0, 2
    /* 382F8 80047AF8 23105000 */  subu       $v0, $v0, $s0
    /* 382FC 80047AFC 80100200 */  sll        $v0, $v0, 2
    /* 38300 80047B00 21105100 */  addu       $v0, $v0, $s1
    /* 38304 80047B04 0300438A */  lwl        $v1, 0x3($s2)
    /* 38308 80047B08 0000439A */  lwr        $v1, 0x0($s2)
    /* 3830C 80047B0C 00000000 */  nop
    /* 38310 80047B10 537F43A8 */  swl        $v1, 0x7F53($v0)
    /* 38314 80047B14 507F43B8 */  swr        $v1, 0x7F50($v0)
  .L80047B18:
    /* 38318 80047B18 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3831C 80047B1C 1800B28F */  lw         $s2, 0x18($sp)
    /* 38320 80047B20 1400B18F */  lw         $s1, 0x14($sp)
    /* 38324 80047B24 1000B08F */  lw         $s0, 0x10($sp)
    /* 38328 80047B28 0800E003 */  jr         $ra
    /* 3832C 80047B2C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80047AB4
