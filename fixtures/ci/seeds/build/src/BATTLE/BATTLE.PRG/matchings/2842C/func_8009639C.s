nonmatching func_8009639C, 0xA8

glabel func_8009639C
    /* 2DB9C 8009639C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2DBA0 800963A0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2DBA4 800963A4 21908000 */  addu       $s2, $a0, $zero
    /* 2DBA8 800963A8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2DBAC 800963AC 21800000 */  addu       $s0, $zero, $zero
    /* 2DBB0 800963B0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2DBB4 800963B4 1D00401A */  blez       $s2, .L8009642C
    /* 2DBB8 800963B8 1400B1AF */   sw        $s1, 0x14($sp)
    /* 2DBBC 800963BC 0F80113C */  lui        $s1, %hi(D_800F1BAC)
  .L800963C0:
    /* 2DBC0 800963C0 0F80033C */  lui        $v1, %hi(D_800F227E)
    /* 2DBC4 800963C4 7E226284 */  lh         $v0, %lo(D_800F227E)($v1)
    /* 2DBC8 800963C8 00000000 */  nop
    /* 2DBCC 800963CC 13004018 */  blez       $v0, .L8009641C
    /* 2DBD0 800963D0 21200000 */   addu      $a0, $zero, $zero
    /* 2DBD4 800963D4 21286000 */  addu       $a1, $v1, $zero
    /* 2DBD8 800963D8 21188000 */  addu       $v1, $a0, $zero
  .L800963DC:
    /* 2DBDC 800963DC AC1B228E */  lw         $v0, %lo(D_800F1BAC)($s1)
    /* 2DBE0 800963E0 00000000 */  nop
    /* 2DBE4 800963E4 21106200 */  addu       $v0, $v1, $v0
    /* 2DBE8 800963E8 08004290 */  lbu        $v0, 0x8($v0)
    /* 2DBEC 800963EC 00000000 */  nop
    /* 2DBF0 800963F0 05004014 */  bnez       $v0, .L80096408
    /* 2DBF4 800963F4 00000000 */   nop
    /* 2DBF8 800963F8 1159020C */  jal        func_80096444
    /* 2DBFC 800963FC 01001026 */   addiu     $s0, $s0, 0x1
    /* 2DC00 80096400 09590208 */  j          .L80096424
    /* 2DC04 80096404 2A101202 */   slt       $v0, $s0, $s2
  .L80096408:
    /* 2DC08 80096408 7E22A284 */  lh         $v0, %lo(D_800F227E)($a1)
    /* 2DC0C 8009640C 01008424 */  addiu      $a0, $a0, 0x1
    /* 2DC10 80096410 2A108200 */  slt        $v0, $a0, $v0
    /* 2DC14 80096414 F1FF4014 */  bnez       $v0, .L800963DC
    /* 2DC18 80096418 18006324 */   addiu     $v1, $v1, 0x18
  .L8009641C:
    /* 2DC1C 8009641C 01001026 */  addiu      $s0, $s0, 0x1
    /* 2DC20 80096420 2A101202 */  slt        $v0, $s0, $s2
  .L80096424:
    /* 2DC24 80096424 E6FF4014 */  bnez       $v0, .L800963C0
    /* 2DC28 80096428 00000000 */   nop
  .L8009642C:
    /* 2DC2C 8009642C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2DC30 80096430 1800B28F */  lw         $s2, 0x18($sp)
    /* 2DC34 80096434 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DC38 80096438 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DC3C 8009643C 0800E003 */  jr         $ra
    /* 2DC40 80096440 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8009639C
