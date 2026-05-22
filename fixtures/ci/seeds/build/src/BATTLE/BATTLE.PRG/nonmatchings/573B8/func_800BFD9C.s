nonmatching func_800BFD9C, 0x64

glabel func_800BFD9C
    /* 5759C 800BFD9C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 575A0 800BFDA0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 575A4 800BFDA4 21800000 */  addu       $s0, $zero, $zero
    /* 575A8 800BFDA8 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 575AC 800BFDAC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 575B0 800BFDB0 704B5124 */  addiu      $s1, $v0, %lo(D_800F4B70)
    /* 575B4 800BFDB4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 575B8 800BFDB8 21101102 */  addu       $v0, $s0, $s1
  .L800BFDBC:
    /* 575BC 800BFDBC 00004290 */  lbu        $v0, 0x0($v0)
    /* 575C0 800BFDC0 00000000 */  nop
    /* 575C4 800BFDC4 03004010 */  beqz       $v0, .L800BFDD4
    /* 575C8 800BFDC8 00000000 */   nop
    /* 575CC 800BFDCC 98F4010C */  jal        func_8007D260
    /* 575D0 800BFDD0 21200002 */   addu      $a0, $s0, $zero
  .L800BFDD4:
    /* 575D4 800BFDD4 01001026 */  addiu      $s0, $s0, 0x1
    /* 575D8 800BFDD8 1100022A */  slti       $v0, $s0, 0x11
    /* 575DC 800BFDDC F7FF4014 */  bnez       $v0, .L800BFDBC
    /* 575E0 800BFDE0 21101102 */   addu      $v0, $s0, $s1
    /* 575E4 800BFDE4 77EF020C */  jal        func_800BBDDC
    /* 575E8 800BFDE8 00000000 */   nop
    /* 575EC 800BFDEC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 575F0 800BFDF0 1400B18F */  lw         $s1, 0x14($sp)
    /* 575F4 800BFDF4 1000B08F */  lw         $s0, 0x10($sp)
    /* 575F8 800BFDF8 0800E003 */  jr         $ra
    /* 575FC 800BFDFC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BFD9C
