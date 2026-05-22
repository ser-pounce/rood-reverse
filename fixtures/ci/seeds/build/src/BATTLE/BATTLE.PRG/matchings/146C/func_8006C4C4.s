nonmatching func_8006C4C4, 0xE8

glabel func_8006C4C4
    /* 3CC4 8006C4C4 2138A000 */  addu       $a3, $a1, $zero
    /* 3CC8 8006C4C8 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 3CCC 8006C4CC CC19458C */  lw         $a1, %lo(D_800F19CC)($v0)
    /* 3CD0 8006C4D0 00FFBD27 */  addiu      $sp, $sp, -0x100
    /* 3CD4 8006C4D4 FC00BFAF */  sw         $ra, 0xFC($sp)
    /* 3CD8 8006C4D8 F800B0AF */  sw         $s0, 0xF8($sp)
    /* 3CDC 8006C4DC 0000A38C */  lw         $v1, 0x0($a1)
    /* 3CE0 8006C4E0 01000224 */  addiu      $v0, $zero, 0x1
    /* 3CE4 8006C4E4 1000A4A7 */  sh         $a0, 0x10($sp)
    /* 3CE8 8006C4E8 04000424 */  addiu      $a0, $zero, 0x4
    /* 3CEC 8006C4EC 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 3CF0 8006C4F0 1300A0A3 */  sb         $zero, 0x13($sp)
    /* 3CF4 8006C4F4 1400A4A7 */  sh         $a0, 0x14($sp)
    /* 3CF8 8006C4F8 03006330 */  andi       $v1, $v1, 0x3
    /* 3CFC 8006C4FC 40110300 */  sll        $v0, $v1, 5
    /* 3D00 8006C500 21104300 */  addu       $v0, $v0, $v1
    /* 3D04 8006C504 80100200 */  sll        $v0, $v0, 2
    /* 3D08 8006C508 21104300 */  addu       $v0, $v0, $v1
    /* 3D0C 8006C50C 80100200 */  sll        $v0, $v0, 2
    /* 3D10 8006C510 23104300 */  subu       $v0, $v0, $v1
    /* 3D14 8006C514 80100200 */  sll        $v0, $v0, 2
    /* 3D18 8006C518 54084224 */  addiu      $v0, $v0, 0x854
    /* 3D1C 8006C51C 2180A200 */  addu       $s0, $a1, $v0
    /* 3D20 8006C520 04000292 */  lbu        $v0, 0x4($s0)
    /* 3D24 8006C524 1A00A0A3 */  sb         $zero, 0x1A($sp)
    /* 3D28 8006C528 1800A2A3 */  sb         $v0, 0x18($sp)
    /* 3D2C 8006C52C 4000E28C */  lw         $v0, 0x40($a3)
    /* 3D30 8006C530 00000000 */  nop
    /* 3D34 8006C534 0B004014 */  bnez       $v0, .L8006C564
    /* 3D38 8006C538 05000224 */   addiu     $v0, $zero, 0x5
    /* 3D3C 8006C53C 2000A4A7 */  sh         $a0, 0x20($sp)
    /* 3D40 8006C540 0000E290 */  lbu        $v0, 0x0($a3)
    /* 3D44 8006C544 2500A6A3 */  sb         $a2, 0x25($sp)
    /* 3D48 8006C548 2400A2A3 */  sb         $v0, 0x24($sp)
    /* 3D4C 8006C54C 0000E490 */  lbu        $a0, 0x0($a3)
    /* 3D50 8006C550 0100E580 */  lb         $a1, 0x1($a3)
    /* 3D54 8006C554 4B85020C */  jal        func_800A152C
    /* 3D58 8006C558 02000624 */   addiu     $a2, $zero, 0x2
    /* 3D5C 8006C55C 62B10108 */  j          .L8006C588
    /* 3D60 8006C560 2600A2A3 */   sb        $v0, 0x26($sp)
  .L8006C564:
    /* 3D64 8006C564 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 3D68 8006C568 0300E888 */  lwl        $t0, 0x3($a3)
    /* 3D6C 8006C56C 0000E898 */  lwr        $t0, 0x0($a3)
    /* 3D70 8006C570 0700E988 */  lwl        $t1, 0x7($a3)
    /* 3D74 8006C574 0400E998 */  lwr        $t1, 0x4($a3)
    /* 3D78 8006C578 2700A8AB */  swl        $t0, 0x27($sp)
    /* 3D7C 8006C57C 2400A8BB */  swr        $t0, 0x24($sp)
    /* 3D80 8006C580 2B00A9AB */  swl        $t1, 0x2B($sp)
    /* 3D84 8006C584 2800A9BB */  swr        $t1, 0x28($sp)
  .L8006C588:
    /* 3D88 8006C588 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3D8C 8006C58C 02000292 */  lbu        $v0, 0x2($s0)
    /* 3D90 8006C590 21280000 */  addu       $a1, $zero, $zero
    /* 3D94 8006C594 FE3C030C */  jal        func_800CF3F8
    /* 3D98 8006C598 2200A2A7 */   sh        $v0, 0x22($sp)
    /* 3D9C 8006C59C FC00BF8F */  lw         $ra, 0xFC($sp)
    /* 3DA0 8006C5A0 F800B08F */  lw         $s0, 0xF8($sp)
    /* 3DA4 8006C5A4 0800E003 */  jr         $ra
    /* 3DA8 8006C5A8 0001BD27 */   addiu     $sp, $sp, 0x100
endlabel func_8006C4C4
