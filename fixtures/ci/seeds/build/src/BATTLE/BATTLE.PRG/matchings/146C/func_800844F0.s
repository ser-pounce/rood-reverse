nonmatching func_800844F0, 0x80

glabel func_800844F0
    /* 1BCF0 800844F0 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 1BCF4 800844F4 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 1BCF8 800844F8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BCFC 800844FC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BD00 80084500 21808000 */  addu       $s0, $a0, $zero
    /* 1BD04 80084504 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1BD08 80084508 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BD0C 8008450C 0A004290 */  lbu        $v0, 0xA($v0)
    /* 1BD10 80084510 00000000 */  nop
    /* 1BD14 80084514 11004014 */  bnez       $v0, .L8008455C
    /* 1BD18 80084518 2188C000 */   addu      $s1, $a2, $zero
    /* 1BD1C 8008451C 3800A28F */  lw         $v0, 0x38($sp)
    /* 1BD20 80084520 3B0E020C */  jal        _calculateDamage
    /* 1BD24 80084524 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1BD28 80084528 21200002 */  addu       $a0, $s0, $zero
    /* 1BD2C 8008452C 21282002 */  addu       $a1, $s1, $zero
    /* 1BD30 80084530 00340200 */  sll        $a2, $v0, 16
    /* 1BD34 80084534 03340600 */  sra        $a2, $a2, 16
    /* 1BD38 80084538 1C00A78C */  lw         $a3, 0x1C($a1)
    /* 1BD3C 8008453C FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1BD40 80084540 2438E300 */  and        $a3, $a3, $v1
    /* 1BD44 80084544 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1BD48 80084548 0200E734 */  ori        $a3, $a3, 0x2
    /* 1BD4C 8008454C 1C00A7AC */  sw         $a3, 0x1C($a1)
    /* 1BD50 80084550 21186200 */  addu       $v1, $v1, $v0
    /* 1BD54 80084554 7800020C */  jal        func_800801E0
    /* 1BD58 80084558 0400A3A4 */   sh        $v1, 0x4($a1)
  .L8008455C:
    /* 1BD5C 8008455C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BD60 80084560 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BD64 80084564 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BD68 80084568 0800E003 */  jr         $ra
    /* 1BD6C 8008456C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800844F0
