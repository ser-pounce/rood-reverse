nonmatching func_800D51D8, 0x88

glabel func_800D51D8
    /* 6C9D8 800D51D8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6C9DC 800D51DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C9E0 800D51E0 21808000 */  addu       $s0, $a0, $zero
    /* 6C9E4 800D51E4 0F80023C */  lui        $v0, %hi(D_800EC3F4)
    /* 6C9E8 800D51E8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6C9EC 800D51EC F4C35324 */  addiu      $s3, $v0, %lo(D_800EC3F4)
    /* 6C9F0 800D51F0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6C9F4 800D51F4 02001224 */  addiu      $s2, $zero, 0x2
    /* 6C9F8 800D51F8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6C9FC 800D51FC 01001124 */  addiu      $s1, $zero, 0x1
    /* 6CA00 800D5200 2000BFAF */  sw         $ra, 0x20($sp)
  .L800D5204:
    /* 6CA04 800D5204 5C54030C */  jal        func_800D5170
    /* 6CA08 800D5208 21200002 */   addu      $a0, $s0, $zero
    /* 6CA0C 800D520C FF004230 */  andi       $v0, $v0, 0xFF
    /* 6CA10 800D5210 80100200 */  sll        $v0, $v0, 2
    /* 6CA14 800D5214 21105300 */  addu       $v0, $v0, $s3
    /* 6CA18 800D5218 0000428C */  lw         $v0, 0x0($v0)
    /* 6CA1C 800D521C 00000000 */  nop
    /* 6CA20 800D5220 09F84000 */  jalr       $v0
    /* 6CA24 800D5224 21200002 */   addu      $a0, $s0, $zero
    /* 6CA28 800D5228 05005210 */  beq        $v0, $s2, .L800D5240
    /* 6CA2C 800D522C 00000000 */   nop
    /* 6CA30 800D5230 F4FF5110 */  beq        $v0, $s1, .L800D5204
    /* 6CA34 800D5234 01000224 */   addiu     $v0, $zero, 0x1
    /* 6CA38 800D5238 91540308 */  j          .L800D5244
    /* 6CA3C 800D523C 00000000 */   nop
  .L800D5240:
    /* 6CA40 800D5240 21100000 */  addu       $v0, $zero, $zero
  .L800D5244:
    /* 6CA44 800D5244 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6CA48 800D5248 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6CA4C 800D524C 1800B28F */  lw         $s2, 0x18($sp)
    /* 6CA50 800D5250 1400B18F */  lw         $s1, 0x14($sp)
    /* 6CA54 800D5254 1000B08F */  lw         $s0, 0x10($sp)
    /* 6CA58 800D5258 0800E003 */  jr         $ra
    /* 6CA5C 800D525C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800D51D8
