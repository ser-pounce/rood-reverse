nonmatching func_800845F0, 0x80

glabel func_800845F0
    /* 1BDF0 800845F0 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 1BDF4 800845F4 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 1BDF8 800845F8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BDFC 800845FC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BE00 80084600 21808000 */  addu       $s0, $a0, $zero
    /* 1BE04 80084604 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BE08 80084608 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1BE0C 8008460C 0A004290 */  lbu        $v0, 0xA($v0)
    /* 1BE10 80084610 02000324 */  addiu      $v1, $zero, 0x2
    /* 1BE14 80084614 11004314 */  bne        $v0, $v1, .L8008465C
    /* 1BE18 80084618 2188C000 */   addu      $s1, $a2, $zero
    /* 1BE1C 8008461C 3800A28F */  lw         $v0, 0x38($sp)
    /* 1BE20 80084620 3B0E020C */  jal        _calculateDamage
    /* 1BE24 80084624 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1BE28 80084628 21200002 */  addu       $a0, $s0, $zero
    /* 1BE2C 8008462C 21282002 */  addu       $a1, $s1, $zero
    /* 1BE30 80084630 00340200 */  sll        $a2, $v0, 16
    /* 1BE34 80084634 03340600 */  sra        $a2, $a2, 16
    /* 1BE38 80084638 1C00A78C */  lw         $a3, 0x1C($a1)
    /* 1BE3C 8008463C FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1BE40 80084640 2438E300 */  and        $a3, $a3, $v1
    /* 1BE44 80084644 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1BE48 80084648 0200E734 */  ori        $a3, $a3, 0x2
    /* 1BE4C 8008464C 1C00A7AC */  sw         $a3, 0x1C($a1)
    /* 1BE50 80084650 21186200 */  addu       $v1, $v1, $v0
    /* 1BE54 80084654 7800020C */  jal        func_800801E0
    /* 1BE58 80084658 0400A3A4 */   sh        $v1, 0x4($a1)
  .L8008465C:
    /* 1BE5C 8008465C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BE60 80084660 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BE64 80084664 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BE68 80084668 0800E003 */  jr         $ra
    /* 1BE6C 8008466C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800845F0
