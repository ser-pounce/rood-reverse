nonmatching func_8009F298, 0x7C

glabel func_8009F298
    /* 36A98 8009F298 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 36A9C 8009F29C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 36AA0 8009F2A0 21888000 */  addu       $s1, $a0, $zero
    /* 36AA4 8009F2A4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 36AA8 8009F2A8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 36AAC 8009F2AC FB7B020C */  jal        func_8009EFEC
    /* 36AB0 8009F2B0 2180C000 */   addu      $s0, $a2, $zero
    /* 36AB4 8009F2B4 01000224 */  addiu      $v0, $zero, 0x1
    /* 36AB8 8009F2B8 10000216 */  bne        $s0, $v0, .L8009F2FC
    /* 36ABC 8009F2BC FE000524 */   addiu     $a1, $zero, 0xFE
    /* 36AC0 8009F2C0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 36AC4 8009F2C4 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 36AC8 8009F2C8 80181100 */  sll        $v1, $s1, 2
    /* 36ACC 8009F2CC 21186200 */  addu       $v1, $v1, $v0
    /* 36AD0 8009F2D0 0000648C */  lw         $a0, 0x0($v1)
    /* 36AD4 8009F2D4 25B5020C */  jal        func_800AD494
    /* 36AD8 8009F2D8 1000A627 */   addiu     $a2, $sp, 0x10
    /* 36ADC 8009F2DC 1000A28F */  lw         $v0, 0x10($sp)
    /* 36AE0 8009F2E0 00000000 */  nop
    /* 36AE4 8009F2E4 05004010 */  beqz       $v0, .L8009F2FC
    /* 36AE8 8009F2E8 21202002 */   addu      $a0, $s1, $zero
    /* 36AEC 8009F2EC FE000524 */  addiu      $a1, $zero, 0xFE
    /* 36AF0 8009F2F0 08000624 */  addiu      $a2, $zero, 0x8
    /* 36AF4 8009F2F4 7280020C */  jal        func_800A01C8
    /* 36AF8 8009F2F8 21380000 */   addu      $a3, $zero, $zero
  .L8009F2FC:
    /* 36AFC 8009F2FC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 36B00 8009F300 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 36B04 8009F304 1800B08F */  lw         $s0, 0x18($sp)
    /* 36B08 8009F308 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 36B0C 8009F30C 0800E003 */  jr         $ra
    /* 36B10 8009F310 00000000 */   nop
endlabel func_8009F298
