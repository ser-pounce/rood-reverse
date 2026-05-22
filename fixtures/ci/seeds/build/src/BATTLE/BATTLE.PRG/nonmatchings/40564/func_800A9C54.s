nonmatching func_800A9C54, 0x88

glabel func_800A9C54
    /* 41454 800A9C54 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 41458 800A9C58 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4145C 800A9C5C 2138C000 */  addu       $a3, $a2, $zero
    /* 41460 800A9C60 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 41464 800A9C64 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 41468 800A9C68 80180400 */  sll        $v1, $a0, 2
    /* 4146C 800A9C6C 21186200 */  addu       $v1, $v1, $v0
    /* 41470 800A9C70 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 41474 800A9C74 1800BFAF */  sw         $ra, 0x18($sp)
    /* 41478 800A9C78 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4147C 800A9C7C 0000708C */  lw         $s0, 0x0($v1)
    /* 41480 800A9C80 0400E214 */  bne        $a3, $v0, .L800A9C94
    /* 41484 800A9C84 2188A000 */   addu      $s1, $a1, $zero
    /* 41488 800A9C88 C2050796 */  lhu        $a3, 0x5C2($s0)
    /* 4148C 800A9C8C 26A70208 */  j          .L800A9C98
    /* 41490 800A9C90 00000000 */   nop
  .L800A9C94:
    /* 41494 800A9C94 21282002 */  addu       $a1, $s1, $zero
  .L800A9C98:
    /* 41498 800A9C98 A4A8020C */  jal        func_800AA290
    /* 4149C 800A9C9C FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 414A0 800A9CA0 00002292 */  lbu        $v0, 0x0($s1)
    /* 414A4 800A9CA4 00000000 */  nop
    /* 414A8 800A9CA8 5C0002A2 */  sb         $v0, 0x5C($s0)
    /* 414AC 800A9CAC 01002292 */  lbu        $v0, 0x1($s1)
    /* 414B0 800A9CB0 00000000 */  nop
    /* 414B4 800A9CB4 5D0002A2 */  sb         $v0, 0x5D($s0)
    /* 414B8 800A9CB8 02002292 */  lbu        $v0, 0x2($s1)
    /* 414BC 800A9CBC 00000000 */  nop
    /* 414C0 800A9CC0 5E0002A2 */  sb         $v0, 0x5E($s0)
    /* 414C4 800A9CC4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 414C8 800A9CC8 1400B18F */  lw         $s1, 0x14($sp)
    /* 414CC 800A9CCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 414D0 800A9CD0 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 414D4 800A9CD4 0800E003 */  jr         $ra
    /* 414D8 800A9CD8 00000000 */   nop
endlabel func_800A9C54
