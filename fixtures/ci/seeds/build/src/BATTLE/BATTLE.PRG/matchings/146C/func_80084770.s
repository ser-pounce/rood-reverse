nonmatching func_80084770, 0x80

glabel func_80084770
    /* 1BF70 80084770 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 1BF74 80084774 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 1BF78 80084778 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BF7C 8008477C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BF80 80084780 21808000 */  addu       $s0, $a0, $zero
    /* 1BF84 80084784 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BF88 80084788 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1BF8C 8008478C 0A004290 */  lbu        $v0, 0xA($v0)
    /* 1BF90 80084790 05000324 */  addiu      $v1, $zero, 0x5
    /* 1BF94 80084794 11004314 */  bne        $v0, $v1, .L800847DC
    /* 1BF98 80084798 2188C000 */   addu      $s1, $a2, $zero
    /* 1BF9C 8008479C 3800A28F */  lw         $v0, 0x38($sp)
    /* 1BFA0 800847A0 3B0E020C */  jal        _calculateDamage
    /* 1BFA4 800847A4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1BFA8 800847A8 21200002 */  addu       $a0, $s0, $zero
    /* 1BFAC 800847AC 21282002 */  addu       $a1, $s1, $zero
    /* 1BFB0 800847B0 00340200 */  sll        $a2, $v0, 16
    /* 1BFB4 800847B4 03340600 */  sra        $a2, $a2, 16
    /* 1BFB8 800847B8 1C00A78C */  lw         $a3, 0x1C($a1)
    /* 1BFBC 800847BC FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1BFC0 800847C0 2438E300 */  and        $a3, $a3, $v1
    /* 1BFC4 800847C4 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1BFC8 800847C8 0200E734 */  ori        $a3, $a3, 0x2
    /* 1BFCC 800847CC 1C00A7AC */  sw         $a3, 0x1C($a1)
    /* 1BFD0 800847D0 21186200 */  addu       $v1, $v1, $v0
    /* 1BFD4 800847D4 7800020C */  jal        func_800801E0
    /* 1BFD8 800847D8 0400A3A4 */   sh        $v1, 0x4($a1)
  .L800847DC:
    /* 1BFDC 800847DC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BFE0 800847E0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BFE4 800847E4 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BFE8 800847E8 0800E003 */  jr         $ra
    /* 1BFEC 800847EC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80084770
