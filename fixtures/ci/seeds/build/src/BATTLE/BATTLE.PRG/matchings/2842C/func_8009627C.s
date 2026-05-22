nonmatching func_8009627C, 0x68

glabel func_8009627C
    /* 2DA7C 8009627C 0F80023C */  lui        $v0, %hi(D_800F2270)
    /* 2DA80 80096280 70224284 */  lh         $v0, %lo(D_800F2270)($v0)
    /* 2DA84 80096284 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2DA88 80096288 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2DA8C 8009628C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2DA90 80096290 0F004014 */  bnez       $v0, .L800962D0
    /* 2DA94 80096294 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2DA98 80096298 01001024 */  addiu      $s0, $zero, 0x1
    /* 2DA9C 8009629C 0F80023C */  lui        $v0, %hi(D_800F2260)
    /* 2DAA0 800962A0 60225124 */  addiu      $s1, $v0, %lo(D_800F2260)
    /* 2DAA4 800962A4 21181102 */  addu       $v1, $s0, $s1
  .L800962A8:
    /* 2DAA8 800962A8 00006290 */  lbu        $v0, 0x0($v1)
    /* 2DAAC 800962AC 00000000 */  nop
    /* 2DAB0 800962B0 03004010 */  beqz       $v0, .L800962C0
    /* 2DAB4 800962B4 21284000 */   addu      $a1, $v0, $zero
    /* 2DAB8 800962B8 0657020C */  jal        func_80095C18
    /* 2DABC 800962BC 21200002 */   addu      $a0, $s0, $zero
  .L800962C0:
    /* 2DAC0 800962C0 01001026 */  addiu      $s0, $s0, 0x1
    /* 2DAC4 800962C4 1000022A */  slti       $v0, $s0, 0x10
    /* 2DAC8 800962C8 F7FF4014 */  bnez       $v0, .L800962A8
    /* 2DACC 800962CC 21181102 */   addu      $v1, $s0, $s1
  .L800962D0:
    /* 2DAD0 800962D0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2DAD4 800962D4 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DAD8 800962D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DADC 800962DC 0800E003 */  jr         $ra
    /* 2DAE0 800962E0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8009627C
