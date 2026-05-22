nonmatching func_800B7D10, 0xB4

glabel func_800B7D10
    /* 4F510 800B7D10 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4F514 800B7D14 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4F518 800B7D18 21808000 */  addu       $s0, $a0, $zero
    /* 4F51C 800B7D1C 01000426 */  addiu      $a0, $s0, 0x1
    /* 4F520 800B7D20 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4F524 800B7D24 80FF020C */  jal        vs_battle_getShort
    /* 4F528 800B7D28 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 4F52C 800B7D2C 94FF020C */  jal        func_800BFE50
    /* 4F530 800B7D30 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F534 800B7D34 03000426 */  addiu      $a0, $s0, 0x3
    /* 4F538 800B7D38 80FF020C */  jal        vs_battle_getShort
    /* 4F53C 800B7D3C 21884000 */   addu      $s1, $v0, $zero
    /* 4F540 800B7D40 05000426 */  addiu      $a0, $s0, 0x5
    /* 4F544 800B7D44 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 4F548 800B7D48 80FF020C */  jal        vs_battle_getShort
    /* 4F54C 800B7D4C 1200A0A7 */   sh        $zero, 0x12($sp)
    /* 4F550 800B7D50 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 4F554 800B7D54 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4F558 800B7D58 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 4F55C 800B7D5C 02000224 */  addiu      $v0, $zero, 0x2
    /* 4F560 800B7D60 08006214 */  bne        $v1, $v0, .L800B7D84
    /* 4F564 800B7D64 FFFF2432 */   andi      $a0, $s1, 0xFFFF
    /* 4F568 800B7D68 00800224 */  addiu      $v0, $zero, -0x8000
    /* 4F56C 800B7D6C 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 4F570 800B7D70 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4F574 800B7D74 64A7020C */  jal        func_800A9D90
    /* 4F578 800B7D78 21300000 */   addu      $a2, $zero, $zero
    /* 4F57C 800B7D7C 64DF0208 */  j          .L800B7D90
    /* 4F580 800B7D80 FFFF3032 */   andi      $s0, $s1, 0xFFFF
  .L800B7D84:
    /* 4F584 800B7D84 FEF3010C */  jal        func_8007CFF8
    /* 4F588 800B7D88 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F58C 800B7D8C FFFF3032 */  andi       $s0, $s1, 0xFFFF
  .L800B7D90:
    /* 4F590 800B7D90 2377020C */  jal        func_8009DC8C
    /* 4F594 800B7D94 21200002 */   addu      $a0, $s0, $zero
    /* 4F598 800B7D98 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 4F59C 800B7D9C 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4F5A0 800B7DA0 21800202 */  addu       $s0, $s0, $v0
    /* 4F5A4 800B7DA4 01000224 */  addiu      $v0, $zero, 0x1
    /* 4F5A8 800B7DA8 000002A2 */  sb         $v0, 0x0($s0)
    /* 4F5AC 800B7DAC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4F5B0 800B7DB0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 4F5B4 800B7DB4 1800B08F */  lw         $s0, 0x18($sp)
    /* 4F5B8 800B7DB8 21100000 */  addu       $v0, $zero, $zero
    /* 4F5BC 800B7DBC 0800E003 */  jr         $ra
    /* 4F5C0 800B7DC0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800B7D10
