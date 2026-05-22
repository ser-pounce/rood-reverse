nonmatching _spu_Fr, 0x64

glabel _spu_Fr
    /* EAFC 8001E2FC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* EB00 8001E300 1400B1AF */  sw         $s1, 0x14($sp)
    /* EB04 8001E304 21888000 */  addu       $s1, $a0, $zero
    /* EB08 8001E308 1000B0AF */  sw         $s0, 0x10($sp)
    /* EB0C 8001E30C 2180A000 */  addu       $s0, $a1, $zero
    /* EB10 8001E310 0380023C */  lui        $v0, %hi(D_80030878)
    /* EB14 8001E314 78084294 */  lhu        $v0, %lo(D_80030878)($v0)
    /* EB18 8001E318 0380053C */  lui        $a1, %hi(D_80030888)
    /* EB1C 8001E31C 8808A58C */  lw         $a1, %lo(D_80030888)($a1)
    /* EB20 8001E320 02000424 */  addiu      $a0, $zero, 0x2
    /* EB24 8001E324 1800BFAF */  sw         $ra, 0x18($sp)
    /* EB28 8001E328 FE77000C */  jal        _spu_t
    /* EB2C 8001E32C 0428A200 */   sllv      $a1, $v0, $a1
    /* EB30 8001E330 FE77000C */  jal        _spu_t
    /* EB34 8001E334 21200000 */   addu      $a0, $zero, $zero
    /* EB38 8001E338 03000424 */  addiu      $a0, $zero, 0x3
    /* EB3C 8001E33C 21282002 */  addu       $a1, $s1, $zero
    /* EB40 8001E340 FE77000C */  jal        _spu_t
    /* EB44 8001E344 21300002 */   addu      $a2, $s0, $zero
    /* EB48 8001E348 21100002 */  addu       $v0, $s0, $zero
    /* EB4C 8001E34C 1800BF8F */  lw         $ra, 0x18($sp)
    /* EB50 8001E350 1400B18F */  lw         $s1, 0x14($sp)
    /* EB54 8001E354 1000B08F */  lw         $s0, 0x10($sp)
    /* EB58 8001E358 0800E003 */  jr         $ra
    /* EB5C 8001E35C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _spu_Fr
