nonmatching func_8007CA20, 0x84

glabel func_8007CA20
    /* 14220 8007CA20 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 14224 8007CA24 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 14228 8007CA28 21888000 */  addu       $s1, $a0, $zero
    /* 1422C 8007CA2C 2138A000 */  addu       $a3, $a1, $zero
    /* 14230 8007CA30 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 14234 8007CA34 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 14238 8007CA38 80101100 */  sll        $v0, $s1, 2
    /* 1423C 8007CA3C 21104300 */  addu       $v0, $v0, $v1
    /* 14240 8007CA40 2400BFAF */  sw         $ra, 0x24($sp)
    /* 14244 8007CA44 2000B2AF */  sw         $s2, 0x20($sp)
    /* 14248 8007CA48 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1424C 8007CA4C 0000508C */  lw         $s0, 0x0($v0)
    /* 14250 8007CA50 00000000 */  nop
    /* 14254 8007CA54 0D000012 */  beqz       $s0, .L8007CA8C
    /* 14258 8007CA58 2190C000 */   addu      $s2, $a2, $zero
    /* 1425C 8007CA5C 21200002 */  addu       $a0, $s0, $zero
    /* 14260 8007CA60 21282002 */  addu       $a1, $s1, $zero
    /* 14264 8007CA64 2130E000 */  addu       $a2, $a3, $zero
    /* 14268 8007CA68 21380000 */  addu       $a3, $zero, $zero
    /* 1426C 8007CA6C 4CDC010C */  jal        func_80077130
    /* 14270 8007CA70 1000A0AF */   sw        $zero, 0x10($sp)
    /* 14274 8007CA74 21200002 */  addu       $a0, $s0, $zero
    /* 14278 8007CA78 21282002 */  addu       $a1, $s1, $zero
    /* 1427C 8007CA7C 21304002 */  addu       $a2, $s2, $zero
    /* 14280 8007CA80 01000724 */  addiu      $a3, $zero, 0x1
    /* 14284 8007CA84 4CDC010C */  jal        func_80077130
    /* 14288 8007CA88 1000A0AF */   sw        $zero, 0x10($sp)
  .L8007CA8C:
    /* 1428C 8007CA8C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 14290 8007CA90 2000B28F */  lw         $s2, 0x20($sp)
    /* 14294 8007CA94 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 14298 8007CA98 1800B08F */  lw         $s0, 0x18($sp)
    /* 1429C 8007CA9C 0800E003 */  jr         $ra
    /* 142A0 8007CAA0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007CA20
