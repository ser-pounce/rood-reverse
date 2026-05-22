nonmatching _spu_Fw, 0x84

glabel _spu_Fw
    /* EA78 8001E278 0380023C */  lui        $v0, %hi(D_8003087C)
    /* EA7C 8001E27C 7C08428C */  lw         $v0, %lo(D_8003087C)($v0)
    /* EA80 8001E280 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* EA84 8001E284 1400B1AF */  sw         $s1, 0x14($sp)
    /* EA88 8001E288 21888000 */  addu       $s1, $a0, $zero
    /* EA8C 8001E28C 1000B0AF */  sw         $s0, 0x10($sp)
    /* EA90 8001E290 2180A000 */  addu       $s0, $a1, $zero
    /* EA94 8001E294 10004014 */  bnez       $v0, .L8001E2D8
    /* EA98 8001E298 1800BFAF */   sw        $ra, 0x18($sp)
    /* EA9C 8001E29C 0380023C */  lui        $v0, %hi(D_80030878)
    /* EAA0 8001E2A0 78084294 */  lhu        $v0, %lo(D_80030878)($v0)
    /* EAA4 8001E2A4 0380053C */  lui        $a1, %hi(D_80030888)
    /* EAA8 8001E2A8 8808A58C */  lw         $a1, %lo(D_80030888)($a1)
    /* EAAC 8001E2AC 02000424 */  addiu      $a0, $zero, 0x2
    /* EAB0 8001E2B0 FE77000C */  jal        _spu_t
    /* EAB4 8001E2B4 0428A200 */   sllv      $a1, $v0, $a1
    /* EAB8 8001E2B8 FE77000C */  jal        _spu_t
    /* EABC 8001E2BC 01000424 */   addiu     $a0, $zero, 0x1
    /* EAC0 8001E2C0 03000424 */  addiu      $a0, $zero, 0x3
    /* EAC4 8001E2C4 21282002 */  addu       $a1, $s1, $zero
    /* EAC8 8001E2C8 FE77000C */  jal        _spu_t
    /* EACC 8001E2CC 21300002 */   addu      $a2, $s0, $zero
    /* EAD0 8001E2D0 BA780008 */  j          .L8001E2E8
    /* EAD4 8001E2D4 21100002 */   addu      $v0, $s0, $zero
  .L8001E2D8:
    /* EAD8 8001E2D8 21202002 */  addu       $a0, $s1, $zero
    /* EADC 8001E2DC 3577000C */  jal        func_8001DCD4
    /* EAE0 8001E2E0 21280002 */   addu      $a1, $s0, $zero
    /* EAE4 8001E2E4 21100002 */  addu       $v0, $s0, $zero
  .L8001E2E8:
    /* EAE8 8001E2E8 1800BF8F */  lw         $ra, 0x18($sp)
    /* EAEC 8001E2EC 1400B18F */  lw         $s1, 0x14($sp)
    /* EAF0 8001E2F0 1000B08F */  lw         $s0, 0x10($sp)
    /* EAF4 8001E2F4 0800E003 */  jr         $ra
    /* EAF8 8001E2F8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _spu_Fw
