nonmatching func_80096444, 0xD8

glabel func_80096444
    /* 2DC44 80096444 0F80033C */  lui        $v1, %hi(D_800F227E)
    /* 2DC48 80096448 7E226294 */  lhu        $v0, %lo(D_800F227E)($v1)
    /* 2DC4C 8009644C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2DC50 80096450 2400BFAF */  sw         $ra, 0x24($sp)
    /* 2DC54 80096454 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2DC58 80096458 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2DC5C 8009645C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2DC60 80096460 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2DC64 80096464 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2DC68 80096468 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2DC6C 8009646C 7E2262A4 */  sh         $v0, %lo(D_800F227E)($v1)
    /* 2DC70 80096470 00140200 */  sll        $v0, $v0, 16
    /* 2DC74 80096474 03140200 */  sra        $v0, $v0, 16
    /* 2DC78 80096478 16008210 */  beq        $a0, $v0, .L800964D4
    /* 2DC7C 8009647C 21808000 */   addu      $s0, $a0, $zero
    /* 2DC80 80096480 2A100202 */  slt        $v0, $s0, $v0
    /* 2DC84 80096484 13004010 */  beqz       $v0, .L800964D4
    /* 2DC88 80096488 0F80143C */   lui       $s4, %hi(D_800F1BAC)
    /* 2DC8C 8009648C 21986000 */  addu       $s3, $v1, $zero
    /* 2DC90 80096490 40101000 */  sll        $v0, $s0, 1
    /* 2DC94 80096494 21105000 */  addu       $v0, $v0, $s0
    /* 2DC98 80096498 C0100200 */  sll        $v0, $v0, 3
    /* 2DC9C 8009649C 18005224 */  addiu      $s2, $v0, 0x18
    /* 2DCA0 800964A0 21884000 */  addu       $s1, $v0, $zero
  .L800964A4:
    /* 2DCA4 800964A4 01001026 */  addiu      $s0, $s0, 0x1
    /* 2DCA8 800964A8 AC1B858E */  lw         $a1, %lo(D_800F1BAC)($s4)
    /* 2DCAC 800964AC 18000624 */  addiu      $a2, $zero, 0x18
    /* 2DCB0 800964B0 2120B100 */  addu       $a0, $a1, $s1
    /* 2DCB4 800964B4 2C24010C */  jal        vs_main_memcpy
    /* 2DCB8 800964B8 2128B200 */   addu      $a1, $a1, $s2
    /* 2DCBC 800964BC 18005226 */  addiu      $s2, $s2, 0x18
    /* 2DCC0 800964C0 7E226286 */  lh         $v0, %lo(D_800F227E)($s3)
    /* 2DCC4 800964C4 00000000 */  nop
    /* 2DCC8 800964C8 2A100202 */  slt        $v0, $s0, $v0
    /* 2DCCC 800964CC F5FF4014 */  bnez       $v0, .L800964A4
    /* 2DCD0 800964D0 18003126 */   addiu     $s1, $s1, 0x18
  .L800964D4:
    /* 2DCD4 800964D4 18000524 */  addiu      $a1, $zero, 0x18
    /* 2DCD8 800964D8 0F80023C */  lui        $v0, %hi(D_800F227E)
    /* 2DCDC 800964DC 7E224284 */  lh         $v0, %lo(D_800F227E)($v0)
    /* 2DCE0 800964E0 0F80033C */  lui        $v1, %hi(D_800F1BAC)
    /* 2DCE4 800964E4 40200200 */  sll        $a0, $v0, 1
    /* 2DCE8 800964E8 21208200 */  addu       $a0, $a0, $v0
    /* 2DCEC 800964EC AC1B628C */  lw         $v0, %lo(D_800F1BAC)($v1)
    /* 2DCF0 800964F0 C0200400 */  sll        $a0, $a0, 3
    /* 2DCF4 800964F4 4424010C */  jal        vs_main_bzero
    /* 2DCF8 800964F8 21204400 */   addu      $a0, $v0, $a0
    /* 2DCFC 800964FC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2DD00 80096500 2000B48F */  lw         $s4, 0x20($sp)
    /* 2DD04 80096504 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2DD08 80096508 1800B28F */  lw         $s2, 0x18($sp)
    /* 2DD0C 8009650C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DD10 80096510 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DD14 80096514 0800E003 */  jr         $ra
    /* 2DD18 80096518 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80096444
