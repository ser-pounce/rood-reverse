nonmatching func_80073D30, 0x100

glabel func_80073D30
    /* B530 80073D30 F8FEBD27 */  addiu      $sp, $sp, -0x108
    /* B534 80073D34 0001B2AF */  sw         $s2, 0x100($sp)
    /* B538 80073D38 21908000 */  addu       $s2, $a0, $zero
    /* B53C 80073D3C F800B0AF */  sw         $s0, 0xF8($sp)
    /* B540 80073D40 2180C000 */  addu       $s0, $a2, $zero
    /* B544 80073D44 0F80043C */  lui        $a0, %hi(D_800F19CC)
    /* B548 80073D48 CC19838C */  lw         $v1, %lo(D_800F19CC)($a0)
    /* B54C 80073D4C 03000224 */  addiu      $v0, $zero, 0x3
    /* B550 80073D50 FC00B1AF */  sw         $s1, 0xFC($sp)
    /* B554 80073D54 01001124 */  addiu      $s1, $zero, 0x1
    /* B558 80073D58 0401BFAF */  sw         $ra, 0x104($sp)
    /* B55C 80073D5C 4C0062AC */  sw         $v0, 0x4C($v1)
    /* B560 80073D60 520071A4 */  sh         $s1, 0x52($v1)
    /* B564 80073D64 940060AC */  sw         $zero, 0x94($v1)
    /* B568 80073D68 540070A0 */  sb         $s0, 0x54($v1)
    /* B56C 80073D6C 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* B570 80073D70 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* B574 80073D74 80101000 */  sll        $v0, $s0, 2
    /* B578 80073D78 21104300 */  addu       $v0, $v0, $v1
    /* B57C 80073D7C 0000428C */  lw         $v0, 0x0($v0)
    /* B580 80073D80 00000000 */  nop
    /* B584 80073D84 3C00428C */  lw         $v0, 0x3C($v0)
    /* B588 80073D88 CC19838C */  lw         $v1, %lo(D_800F19CC)($a0)
    /* B58C 80073D8C 36004290 */  lbu        $v0, 0x36($v0)
    /* B590 80073D90 00000000 */  nop
    /* B594 80073D94 550062A0 */  sb         $v0, 0x55($v1)
    /* B598 80073D98 CC19868C */  lw         $a2, %lo(D_800F19CC)($a0)
    /* B59C 80073D9C 01000224 */  addiu      $v0, $zero, 0x1
    /* B5A0 80073DA0 0400C2AC */  sw         $v0, 0x4($a2)
    /* B5A4 80073DA4 0000C0AC */  sw         $zero, 0x0($a2)
    /* B5A8 80073DA8 0400A294 */  lhu        $v0, 0x4($a1)
    /* B5AC 80073DAC 00000000 */  nop
    /* B5B0 80073DB0 A829C2A4 */  sh         $v0, 0x29A8($a2)
    /* B5B4 80073DB4 0600A294 */  lhu        $v0, 0x6($a1)
    /* B5B8 80073DB8 01000724 */  addiu      $a3, $zero, 0x1
    /* B5BC 80073DBC AA29C2A4 */  sh         $v0, 0x29AA($a2)
    /* B5C0 80073DC0 0800A294 */  lhu        $v0, 0x8($a1)
    /* B5C4 80073DC4 5408C524 */  addiu      $a1, $a2, 0x854
    /* B5C8 80073DC8 AC29C2A4 */  sh         $v0, 0x29AC($a2)
    /* B5CC 80073DCC 06004486 */  lh         $a0, 0x6($s2)
    /* B5D0 80073DD0 0800C624 */  addiu      $a2, $a2, 0x8
    /* B5D4 80073DD4 C416020C */  jal        func_80085B10
    /* B5D8 80073DD8 06008424 */   addiu     $a0, $a0, 0x6
    /* B5DC 80073DDC 1000A427 */  addiu      $a0, $sp, 0x10
    /* B5E0 80073DE0 21280000 */  addu       $a1, $zero, $zero
    /* B5E4 80073DE4 06004396 */  lhu        $v1, 0x6($s2)
    /* B5E8 80073DE8 05000224 */  addiu      $v0, $zero, 0x5
    /* B5EC 80073DEC 1400A2A7 */  sh         $v0, 0x14($sp)
    /* B5F0 80073DF0 04000224 */  addiu      $v0, $zero, 0x4
    /* B5F4 80073DF4 2000A2A7 */  sh         $v0, 0x20($sp)
    /* B5F8 80073DF8 FD000224 */  addiu      $v0, $zero, 0xFD
    /* B5FC 80073DFC 1200B1A3 */  sb         $s1, 0x12($sp)
    /* B600 80073E00 1300A0A3 */  sb         $zero, 0x13($sp)
    /* B604 80073E04 2400B0A3 */  sb         $s0, 0x24($sp)
    /* B608 80073E08 2600A2A3 */  sb         $v0, 0x26($sp)
    /* B60C 80073E0C 06006324 */  addiu      $v1, $v1, 0x6
    /* B610 80073E10 FE3C030C */  jal        func_800CF3F8
    /* B614 80073E14 1000A3A7 */   sh        $v1, 0x10($sp)
    /* B618 80073E18 0401BF8F */  lw         $ra, 0x104($sp)
    /* B61C 80073E1C 0001B28F */  lw         $s2, 0x100($sp)
    /* B620 80073E20 FC00B18F */  lw         $s1, 0xFC($sp)
    /* B624 80073E24 F800B08F */  lw         $s0, 0xF8($sp)
    /* B628 80073E28 0800E003 */  jr         $ra
    /* B62C 80073E2C 0801BD27 */   addiu     $sp, $sp, 0x108
endlabel func_80073D30
