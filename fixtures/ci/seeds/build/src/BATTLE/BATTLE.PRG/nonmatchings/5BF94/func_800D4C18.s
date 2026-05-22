nonmatching func_800D4C18, 0x12C

glabel func_800D4C18
    /* 6C418 800D4C18 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6C41C 800D4C1C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6C420 800D4C20 21908000 */  addu       $s2, $a0, $zero
    /* 6C424 800D4C24 2400BFAF */  sw         $ra, 0x24($sp)
    /* 6C428 800D4C28 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6C42C 800D4C2C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6C430 800D4C30 1800518E */  lw         $s1, 0x18($s2)
    /* 6C434 800D4C34 A954030C */  jal        func_800D52A4
    /* 6C438 800D4C38 21202002 */   addu      $a0, $s1, $zero
    /* 6C43C 800D4C3C 801F053C */  lui        $a1, (0x1F80015C >> 16)
    /* 6C440 800D4C40 5C01A534 */  ori        $a1, $a1, (0x1F80015C & 0xFFFF)
    /* 6C444 800D4C44 1800448E */  lw         $a0, 0x18($s2)
    /* 6C448 800D4C48 895B030C */  jal        func_800D6E24
    /* 6C44C 800D4C4C 21802002 */   addu      $s0, $s1, $zero
    /* 6C450 800D4C50 35002012 */  beqz       $s1, .L800D4D28
    /* 6C454 800D4C54 00000000 */   nop
  .L800D4C58:
    /* 6C458 800D4C58 0400118E */  lw         $s1, 0x4($s0)
    /* 6C45C 800D4C5C 77000292 */  lbu        $v0, 0x77($s0)
    /* 6C460 800D4C60 6D000392 */  lbu        $v1, 0x6D($s0)
    /* 6C464 800D4C64 01004224 */  addiu      $v0, $v0, 0x1
    /* 6C468 800D4C68 08006010 */  beqz       $v1, .L800D4C8C
    /* 6C46C 800D4C6C 770002A2 */   sb        $v0, 0x77($s0)
    /* 6C470 800D4C70 21204002 */  addu       $a0, $s2, $zero
    /* 6C474 800D4C74 21300000 */  addu       $a2, $zero, $zero
    /* 6C478 800D4C78 21286000 */  addu       $a1, $v1, $zero
    /* 6C47C 800D4C7C 2138C000 */  addu       $a3, $a2, $zero
    /* 6C480 800D4C80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C484 800D4C84 B74A030C */  jal        func_800D2ADC
    /* 6C488 800D4C88 FFFFA524 */   addiu     $a1, $a1, -0x1
  .L800D4C8C:
    /* 6C48C 800D4C8C FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 6C490 800D4C90 68000286 */  lh         $v0, 0x68($s0)
    /* 6C494 800D4C94 68000496 */  lhu        $a0, 0x68($s0)
    /* 6C498 800D4C98 0F004314 */  bne        $v0, $v1, .L800D4CD8
    /* 6C49C 800D4C9C FFFF8224 */   addiu     $v0, $a0, -0x1
    /* 6C4A0 800D4CA0 42000292 */  lbu        $v0, 0x42($s0)
    /* 6C4A4 800D4CA4 00000000 */  nop
    /* 6C4A8 800D4CA8 1D004014 */  bnez       $v0, .L800D4D20
    /* 6C4AC 800D4CAC 00000000 */   nop
    /* 6C4B0 800D4CB0 6C000292 */  lbu        $v0, 0x6C($s0)
    /* 6C4B4 800D4CB4 00000000 */  nop
    /* 6C4B8 800D4CB8 16004010 */  beqz       $v0, .L800D4D14
    /* 6C4BC 800D4CBC 21204002 */   addu      $a0, $s2, $zero
    /* 6C4C0 800D4CC0 21300000 */  addu       $a2, $zero, $zero
    /* 6C4C4 800D4CC4 21284000 */  addu       $a1, $v0, $zero
    /* 6C4C8 800D4CC8 2138C000 */  addu       $a3, $a2, $zero
    /* 6C4CC 800D4CCC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C4D0 800D4CD0 43530308 */  j          .L800D4D0C
    /* 6C4D4 800D4CD4 2128A300 */   addu      $a1, $a1, $v1
  .L800D4CD8:
    /* 6C4D8 800D4CD8 680002A6 */  sh         $v0, 0x68($s0)
    /* 6C4DC 800D4CDC 00140200 */  sll        $v0, $v0, 16
    /* 6C4E0 800D4CE0 0F004014 */  bnez       $v0, .L800D4D20
    /* 6C4E4 800D4CE4 00000000 */   nop
    /* 6C4E8 800D4CE8 6C000292 */  lbu        $v0, 0x6C($s0)
    /* 6C4EC 800D4CEC 00000000 */  nop
    /* 6C4F0 800D4CF0 08004010 */  beqz       $v0, .L800D4D14
    /* 6C4F4 800D4CF4 21204002 */   addu      $a0, $s2, $zero
    /* 6C4F8 800D4CF8 21300000 */  addu       $a2, $zero, $zero
    /* 6C4FC 800D4CFC 21284000 */  addu       $a1, $v0, $zero
    /* 6C500 800D4D00 2138C000 */  addu       $a3, $a2, $zero
    /* 6C504 800D4D04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C508 800D4D08 FFFFA524 */  addiu      $a1, $a1, -0x1
  .L800D4D0C:
    /* 6C50C 800D4D0C B74A030C */  jal        func_800D2ADC
    /* 6C510 800D4D10 00000000 */   nop
  .L800D4D14:
    /* 6C514 800D4D14 21200002 */  addu       $a0, $s0, $zero
    /* 6C518 800D4D18 224A030C */  jal        func_800D2888
    /* 6C51C 800D4D1C 21284002 */   addu      $a1, $s2, $zero
  .L800D4D20:
    /* 6C520 800D4D20 CDFF2016 */  bnez       $s1, .L800D4C58
    /* 6C524 800D4D24 21802002 */   addu      $s0, $s1, $zero
  .L800D4D28:
    /* 6C528 800D4D28 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6C52C 800D4D2C 2000B28F */  lw         $s2, 0x20($sp)
    /* 6C530 800D4D30 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6C534 800D4D34 1800B08F */  lw         $s0, 0x18($sp)
    /* 6C538 800D4D38 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C53C 800D4D3C 0800E003 */  jr         $ra
    /* 6C540 800D4D40 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800D4C18
