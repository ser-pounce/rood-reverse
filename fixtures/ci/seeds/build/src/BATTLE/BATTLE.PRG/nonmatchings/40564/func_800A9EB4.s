nonmatching func_800A9EB4, 0xB0

glabel func_800A9EB4
    /* 416B4 800A9EB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 416B8 800A9EB8 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 416BC 800A9EBC 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 416C0 800A9EC0 80100400 */  sll        $v0, $a0, 2
    /* 416C4 800A9EC4 21104300 */  addu       $v0, $v0, $v1
    /* 416C8 800A9EC8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 416CC 800A9ECC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 416D0 800A9ED0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 416D4 800A9ED4 0000518C */  lw         $s1, 0x0($v0)
    /* 416D8 800A9ED8 00000000 */  nop
    /* 416DC 800A9EDC 26002296 */  lhu        $v0, 0x26($s1)
    /* 416E0 800A9EE0 2138C000 */  addu       $a3, $a2, $zero
    /* 416E4 800A9EE4 2328A200 */  subu       $a1, $a1, $v0
    /* 416E8 800A9EE8 00140500 */  sll        $v0, $a1, 16
    /* 416EC 800A9EEC 03140200 */  sra        $v0, $v0, 16
    /* 416F0 800A9EF0 01084228 */  slti       $v0, $v0, 0x801
    /* 416F4 800A9EF4 02004014 */  bnez       $v0, .L800A9F00
    /* 416F8 800A9EF8 2118A000 */   addu      $v1, $a1, $zero
    /* 416FC 800A9EFC 00F0A324 */  addiu      $v1, $a1, -0x1000
  .L800A9F00:
    /* 41700 800A9F00 00140300 */  sll        $v0, $v1, 16
    /* 41704 800A9F04 03140200 */  sra        $v0, $v0, 16
    /* 41708 800A9F08 00F84228 */  slti       $v0, $v0, -0x800
    /* 4170C 800A9F0C 02004010 */  beqz       $v0, .L800A9F18
    /* 41710 800A9F10 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 41714 800A9F14 00106324 */  addiu      $v1, $v1, 0x1000
  .L800A9F18:
    /* 41718 800A9F18 0600E214 */  bne        $a3, $v0, .L800A9F34
    /* 4171C 800A9F1C 002C0300 */   sll       $a1, $v1, 16
    /* 41720 800A9F20 032C0500 */  sra        $a1, $a1, 16
    /* 41724 800A9F24 61AA020C */  jal        func_800AA984
    /* 41728 800A9F28 21304000 */   addu      $a2, $v0, $zero
    /* 4172C 800A9F2C D3A70208 */  j          .L800A9F4C
    /* 41730 800A9F30 00000000 */   nop
  .L800A9F34:
    /* 41734 800A9F34 032C0500 */  sra        $a1, $a1, 16
    /* 41738 800A9F38 C0053096 */  lhu        $s0, 0x5C0($s1)
    /* 4173C 800A9F3C FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 41740 800A9F40 61AA020C */  jal        func_800AA984
    /* 41744 800A9F44 C00527A6 */   sh        $a3, 0x5C0($s1)
    /* 41748 800A9F48 C00530A6 */  sh         $s0, 0x5C0($s1)
  .L800A9F4C:
    /* 4174C 800A9F4C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 41750 800A9F50 1400B18F */  lw         $s1, 0x14($sp)
    /* 41754 800A9F54 1000B08F */  lw         $s0, 0x10($sp)
    /* 41758 800A9F58 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 4175C 800A9F5C 0800E003 */  jr         $ra
    /* 41760 800A9F60 00000000 */   nop
endlabel func_800A9EB4
