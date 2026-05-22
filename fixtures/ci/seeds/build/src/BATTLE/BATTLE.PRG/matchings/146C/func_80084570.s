nonmatching func_80084570, 0x80

glabel func_80084570
    /* 1BD70 80084570 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 1BD74 80084574 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 1BD78 80084578 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BD7C 8008457C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BD80 80084580 21808000 */  addu       $s0, $a0, $zero
    /* 1BD84 80084584 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BD88 80084588 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1BD8C 8008458C 0A004290 */  lbu        $v0, 0xA($v0)
    /* 1BD90 80084590 01000324 */  addiu      $v1, $zero, 0x1
    /* 1BD94 80084594 11004314 */  bne        $v0, $v1, .L800845DC
    /* 1BD98 80084598 2188C000 */   addu      $s1, $a2, $zero
    /* 1BD9C 8008459C 3800A28F */  lw         $v0, 0x38($sp)
    /* 1BDA0 800845A0 3B0E020C */  jal        _calculateDamage
    /* 1BDA4 800845A4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1BDA8 800845A8 21200002 */  addu       $a0, $s0, $zero
    /* 1BDAC 800845AC 21282002 */  addu       $a1, $s1, $zero
    /* 1BDB0 800845B0 00340200 */  sll        $a2, $v0, 16
    /* 1BDB4 800845B4 03340600 */  sra        $a2, $a2, 16
    /* 1BDB8 800845B8 1C00A78C */  lw         $a3, 0x1C($a1)
    /* 1BDBC 800845BC FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1BDC0 800845C0 2438E300 */  and        $a3, $a3, $v1
    /* 1BDC4 800845C4 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1BDC8 800845C8 0200E734 */  ori        $a3, $a3, 0x2
    /* 1BDCC 800845CC 1C00A7AC */  sw         $a3, 0x1C($a1)
    /* 1BDD0 800845D0 21186200 */  addu       $v1, $v1, $v0
    /* 1BDD4 800845D4 7800020C */  jal        func_800801E0
    /* 1BDD8 800845D8 0400A3A4 */   sh        $v1, 0x4($a1)
  .L800845DC:
    /* 1BDDC 800845DC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BDE0 800845E0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BDE4 800845E4 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BDE8 800845E8 0800E003 */  jr         $ra
    /* 1BDEC 800845EC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80084570
