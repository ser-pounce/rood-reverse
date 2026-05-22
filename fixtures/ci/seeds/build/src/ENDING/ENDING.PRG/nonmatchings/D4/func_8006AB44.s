nonmatching func_8006AB44, 0x78

glabel func_8006AB44
    /* 2344 8006AB44 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2348 8006AB48 1000BFAF */  sw         $ra, 0x10($sp)
    /* 234C 8006AB4C 0E80023C */  lui        $v0, %hi(D_800DBBB8)
    /* 2350 8006AB50 B8BB4524 */  addiu      $a1, $v0, %lo(D_800DBBB8)
    /* 2354 8006AB54 01000624 */  addiu      $a2, $zero, 0x1
    /* 2358 8006AB58 2138C000 */  addu       $a3, $a2, $zero
    /* 235C 8006AB5C 0A00A324 */  addiu      $v1, $a1, 0xA
  .L8006AB60:
    /* 2360 8006AB60 FEFF6284 */  lh         $v0, -0x2($v1)
    /* 2364 8006AB64 00000000 */  nop
    /* 2368 8006AB68 06004014 */  bnez       $v0, .L8006AB84
    /* 236C 8006AB6C 0100C224 */   addiu     $v0, $a2, 0x1
    /* 2370 8006AB70 2110A000 */  addu       $v0, $a1, $zero
    /* 2374 8006AB74 000044AC */  sw         $a0, 0x0($v0)
    /* 2378 8006AB78 FEFF67A4 */  sh         $a3, -0x2($v1)
    /* 237C 8006AB7C EBAA0108 */  j          .L8006ABAC
    /* 2380 8006AB80 000060A4 */   sh        $zero, 0x0($v1)
  .L8006AB84:
    /* 2384 8006AB84 21304000 */  addu       $a2, $v0, $zero
    /* 2388 8006AB88 30006324 */  addiu      $v1, $v1, 0x30
    /* 238C 8006AB8C 00140200 */  sll        $v0, $v0, 16
    /* 2390 8006AB90 03140200 */  sra        $v0, $v0, 16
    /* 2394 8006AB94 20004228 */  slti       $v0, $v0, 0x20
    /* 2398 8006AB98 F1FF4014 */  bnez       $v0, .L8006AB60
    /* 239C 8006AB9C 3000A524 */   addiu     $a1, $a1, 0x30
    /* 23A0 8006ABA0 4D000424 */  addiu      $a0, $zero, 0x4D
    /* 23A4 8006ABA4 2D9A000C */  jal        SystemError
    /* 23A8 8006ABA8 64000524 */   addiu     $a1, $zero, 0x64
  .L8006ABAC:
    /* 23AC 8006ABAC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 23B0 8006ABB0 00000000 */  nop
    /* 23B4 8006ABB4 0800E003 */  jr         $ra
    /* 23B8 8006ABB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006AB44
