nonmatching func_80084670, 0x80

glabel func_80084670
    /* 1BE70 80084670 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 1BE74 80084674 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 1BE78 80084678 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BE7C 8008467C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BE80 80084680 21808000 */  addu       $s0, $a0, $zero
    /* 1BE84 80084684 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BE88 80084688 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1BE8C 8008468C 0A004290 */  lbu        $v0, 0xA($v0)
    /* 1BE90 80084690 03000324 */  addiu      $v1, $zero, 0x3
    /* 1BE94 80084694 11004314 */  bne        $v0, $v1, .L800846DC
    /* 1BE98 80084698 2188C000 */   addu      $s1, $a2, $zero
    /* 1BE9C 8008469C 3800A28F */  lw         $v0, 0x38($sp)
    /* 1BEA0 800846A0 3B0E020C */  jal        _calculateDamage
    /* 1BEA4 800846A4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1BEA8 800846A8 21200002 */  addu       $a0, $s0, $zero
    /* 1BEAC 800846AC 21282002 */  addu       $a1, $s1, $zero
    /* 1BEB0 800846B0 00340200 */  sll        $a2, $v0, 16
    /* 1BEB4 800846B4 03340600 */  sra        $a2, $a2, 16
    /* 1BEB8 800846B8 1C00A78C */  lw         $a3, 0x1C($a1)
    /* 1BEBC 800846BC FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1BEC0 800846C0 2438E300 */  and        $a3, $a3, $v1
    /* 1BEC4 800846C4 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1BEC8 800846C8 0200E734 */  ori        $a3, $a3, 0x2
    /* 1BECC 800846CC 1C00A7AC */  sw         $a3, 0x1C($a1)
    /* 1BED0 800846D0 21186200 */  addu       $v1, $v1, $v0
    /* 1BED4 800846D4 7800020C */  jal        func_800801E0
    /* 1BED8 800846D8 0400A3A4 */   sh        $v1, 0x4($a1)
  .L800846DC:
    /* 1BEDC 800846DC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BEE0 800846E0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BEE4 800846E4 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BEE8 800846E8 0800E003 */  jr         $ra
    /* 1BEEC 800846EC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80084670
