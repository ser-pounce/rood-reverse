nonmatching func_800846F0, 0x80

glabel func_800846F0
    /* 1BEF0 800846F0 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 1BEF4 800846F4 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 1BEF8 800846F8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BEFC 800846FC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BF00 80084700 21808000 */  addu       $s0, $a0, $zero
    /* 1BF04 80084704 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BF08 80084708 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1BF0C 8008470C 0A004290 */  lbu        $v0, 0xA($v0)
    /* 1BF10 80084710 04000324 */  addiu      $v1, $zero, 0x4
    /* 1BF14 80084714 11004314 */  bne        $v0, $v1, .L8008475C
    /* 1BF18 80084718 2188C000 */   addu      $s1, $a2, $zero
    /* 1BF1C 8008471C 3800A28F */  lw         $v0, 0x38($sp)
    /* 1BF20 80084720 3B0E020C */  jal        _calculateDamage
    /* 1BF24 80084724 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1BF28 80084728 21200002 */  addu       $a0, $s0, $zero
    /* 1BF2C 8008472C 21282002 */  addu       $a1, $s1, $zero
    /* 1BF30 80084730 00340200 */  sll        $a2, $v0, 16
    /* 1BF34 80084734 03340600 */  sra        $a2, $a2, 16
    /* 1BF38 80084738 1C00A78C */  lw         $a3, 0x1C($a1)
    /* 1BF3C 8008473C FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1BF40 80084740 2438E300 */  and        $a3, $a3, $v1
    /* 1BF44 80084744 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1BF48 80084748 0200E734 */  ori        $a3, $a3, 0x2
    /* 1BF4C 8008474C 1C00A7AC */  sw         $a3, 0x1C($a1)
    /* 1BF50 80084750 21186200 */  addu       $v1, $v1, $v0
    /* 1BF54 80084754 7800020C */  jal        func_800801E0
    /* 1BF58 80084758 0400A3A4 */   sh        $v1, 0x4($a1)
  .L8008475C:
    /* 1BF5C 8008475C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BF60 80084760 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BF64 80084764 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BF68 80084768 0800E003 */  jr         $ra
    /* 1BF6C 8008476C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800846F0
