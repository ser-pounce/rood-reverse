nonmatching func_800BAA58, 0x74

glabel func_800BAA58
    /* 52258 800BAA58 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5225C 800BAA5C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 52260 800BAA60 0F80103C */  lui        $s0, %hi(D_800F4BB9)
    /* 52264 800BAA64 B94B0292 */  lbu        $v0, %lo(D_800F4BB9)($s0)
    /* 52268 800BAA68 00000000 */  nop
    /* 5226C 800BAA6C 06004014 */  bnez       $v0, .L800BAA88
    /* 52270 800BAA70 1400BFAF */   sw        $ra, 0x14($sp)
    /* 52274 800BAA74 6A3C030C */  jal        func_800CF1A8
    /* 52278 800BAA78 00000000 */   nop
    /* 5227C 800BAA7C 01000224 */  addiu      $v0, $zero, 0x1
    /* 52280 800BAA80 AEEA0208 */  j          .L800BAAB8
    /* 52284 800BAA84 B94B02A2 */   sb        $v0, %lo(D_800F4BB9)($s0)
  .L800BAA88:
    /* 52288 800BAA88 B9EF010C */  jal        func_8007BEE4
    /* 5228C 800BAA8C 00000000 */   nop
    /* 52290 800BAA90 06004010 */  beqz       $v0, .L800BAAAC
    /* 52294 800BAA94 00000000 */   nop
    /* 52298 800BAA98 B9EF010C */  jal        func_8007BEE4
    /* 5229C 800BAA9C 00000000 */   nop
    /* 522A0 800BAAA0 05000324 */  addiu      $v1, $zero, 0x5
    /* 522A4 800BAAA4 05004314 */  bne        $v0, $v1, .L800BAABC
    /* 522A8 800BAAA8 01000224 */   addiu     $v0, $zero, 0x1
  .L800BAAAC:
    /* 522AC 800BAAAC B94B00A2 */  sb         $zero, %lo(D_800F4BB9)($s0)
    /* 522B0 800BAAB0 AFEA0208 */  j          .L800BAABC
    /* 522B4 800BAAB4 21100000 */   addu      $v0, $zero, $zero
  .L800BAAB8:
    /* 522B8 800BAAB8 01000224 */  addiu      $v0, $zero, 0x1
  .L800BAABC:
    /* 522BC 800BAABC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 522C0 800BAAC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 522C4 800BAAC4 0800E003 */  jr         $ra
    /* 522C8 800BAAC8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BAA58
