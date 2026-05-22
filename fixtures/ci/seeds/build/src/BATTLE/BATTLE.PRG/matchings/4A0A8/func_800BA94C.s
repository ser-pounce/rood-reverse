nonmatching func_800BA94C, 0xB8

glabel func_800BA94C
    /* 5214C 800BA94C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 52150 800BA950 1400B1AF */  sw         $s1, 0x14($sp)
    /* 52154 800BA954 21888000 */  addu       $s1, $a0, $zero
    /* 52158 800BA958 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 5215C 800BA95C 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 52160 800BA960 02000224 */  addiu      $v0, $zero, 0x2
    /* 52164 800BA964 1800BFAF */  sw         $ra, 0x18($sp)
    /* 52168 800BA968 1B006214 */  bne        $v1, $v0, .L800BA9D8
    /* 5216C 800BA96C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 52170 800BA970 01002392 */  lbu        $v1, 0x1($s1)
    /* 52174 800BA974 00000000 */  nop
    /* 52178 800BA978 03006010 */  beqz       $v1, .L800BA988
    /* 5217C 800BA97C 05000224 */   addiu     $v0, $zero, 0x5
    /* 52180 800BA980 15006214 */  bne        $v1, $v0, .L800BA9D8
    /* 52184 800BA984 00000000 */   nop
  .L800BA988:
    /* 52188 800BA988 0F80103C */  lui        $s0, %hi(D_800F4BB9)
    /* 5218C 800BA98C B94B0292 */  lbu        $v0, %lo(D_800F4BB9)($s0)
    /* 52190 800BA990 00000000 */  nop
    /* 52194 800BA994 0A004010 */  beqz       $v0, .L800BA9C0
    /* 52198 800BA998 00000000 */   nop
    /* 5219C 800BA99C B9EF010C */  jal        func_8007BEE4
    /* 521A0 800BA9A0 00000000 */   nop
    /* 521A4 800BA9A4 01002392 */  lbu        $v1, 0x1($s1)
    /* 521A8 800BA9A8 00000000 */  nop
    /* 521AC 800BA9AC 10004314 */  bne        $v0, $v1, .L800BA9F0
    /* 521B0 800BA9B0 01000224 */   addiu     $v0, $zero, 0x1
    /* 521B4 800BA9B4 B94B00A2 */  sb         $zero, %lo(D_800F4BB9)($s0)
    /* 521B8 800BA9B8 7CEA0208 */  j          .L800BA9F0
    /* 521BC 800BA9BC 21100000 */   addu      $v0, $zero, $zero
  .L800BA9C0:
    /* 521C0 800BA9C0 6A3C030C */  jal        func_800CF1A8
    /* 521C4 800BA9C4 00000000 */   nop
    /* 521C8 800BA9C8 01000224 */  addiu      $v0, $zero, 0x1
    /* 521CC 800BA9CC B94B02A2 */  sb         $v0, %lo(D_800F4BB9)($s0)
    /* 521D0 800BA9D0 7CEA0208 */  j          .L800BA9F0
    /* 521D4 800BA9D4 01000224 */   addiu     $v0, $zero, 0x1
  .L800BA9D8:
    /* 521D8 800BA9D8 B9EF010C */  jal        func_8007BEE4
    /* 521DC 800BA9DC 00000000 */   nop
    /* 521E0 800BA9E0 01002392 */  lbu        $v1, 0x1($s1)
    /* 521E4 800BA9E4 00000000 */  nop
    /* 521E8 800BA9E8 26104300 */  xor        $v0, $v0, $v1
    /* 521EC 800BA9EC 2B100200 */  sltu       $v0, $zero, $v0
  .L800BA9F0:
    /* 521F0 800BA9F0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 521F4 800BA9F4 1400B18F */  lw         $s1, 0x14($sp)
    /* 521F8 800BA9F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 521FC 800BA9FC 0800E003 */  jr         $ra
    /* 52200 800BAA00 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BA94C
