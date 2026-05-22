nonmatching func_80045CEC, 0x78

glabel func_80045CEC
    /* 364EC 80045CEC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 364F0 80045CF0 21108000 */  addu       $v0, $a0, $zero
    /* 364F4 80045CF4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 364F8 80045CF8 2180A000 */  addu       $s0, $a1, $zero
    /* 364FC 80045CFC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 36500 80045D00 2190C000 */  addu       $s2, $a2, $zero
    /* 36504 80045D04 1400B1AF */  sw         $s1, 0x14($sp)
    /* 36508 80045D08 2188E000 */  addu       $s1, $a3, $zero
    /* 3650C 80045D0C 0A000012 */  beqz       $s0, .L80045D38
    /* 36510 80045D10 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 36514 80045D14 CA16010C */  jal        func_80045B28
    /* 36518 80045D18 00000000 */   nop
    /* 3651C 80045D1C 03004010 */  beqz       $v0, .L80045D2C
    /* 36520 80045D20 21204000 */   addu      $a0, $v0, $zero
    /* 36524 80045D24 50170108 */  j          .L80045D40
    /* 36528 80045D28 21280000 */   addu      $a1, $zero, $zero
  .L80045D2C:
    /* 3652C 80045D2C 21200002 */  addu       $a0, $s0, $zero
    /* 36530 80045D30 50170108 */  j          .L80045D40
    /* 36534 80045D34 21280000 */   addu      $a1, $zero, $zero
  .L80045D38:
    /* 36538 80045D38 21200000 */  addu       $a0, $zero, $zero
    /* 3653C 80045D3C 21284000 */  addu       $a1, $v0, $zero
  .L80045D40:
    /* 36540 80045D40 FF002632 */  andi       $a2, $s1, 0xFF
    /* 36544 80045D44 CE49000C */  jal        func_80012738
    /* 36548 80045D48 21384002 */   addu      $a3, $s2, $zero
    /* 3654C 80045D4C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 36550 80045D50 1800B28F */  lw         $s2, 0x18($sp)
    /* 36554 80045D54 1400B18F */  lw         $s1, 0x14($sp)
    /* 36558 80045D58 1000B08F */  lw         $s0, 0x10($sp)
    /* 3655C 80045D5C 0800E003 */  jr         $ra
    /* 36560 80045D60 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80045CEC
