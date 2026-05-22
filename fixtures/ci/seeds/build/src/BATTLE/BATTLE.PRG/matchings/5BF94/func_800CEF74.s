nonmatching func_800CEF74, 0xEC

glabel func_800CEF74
    /* 66774 800CEF74 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 66778 800CEF78 3800B0AF */  sw         $s0, 0x38($sp)
    /* 6677C 800CEF7C 21808000 */  addu       $s0, $a0, $zero
    /* 66780 800CEF80 01000424 */  addiu      $a0, $zero, 0x1
    /* 66784 800CEF84 4800BFAF */  sw         $ra, 0x48($sp)
    /* 66788 800CEF88 4400B3AF */  sw         $s3, 0x44($sp)
    /* 6678C 800CEF8C 4000B2AF */  sw         $s2, 0x40($sp)
    /* 66790 800CEF90 245E030C */  jal        func_800D7890
    /* 66794 800CEF94 3C00B1AF */   sw        $s1, 0x3C($sp)
    /* 66798 800CEF98 AF3B030C */  jal        func_800CEEBC
    /* 6679C 800CEF9C 00000000 */   nop
    /* 667A0 800CEFA0 21984000 */  addu       $s3, $v0, $zero
    /* 667A4 800CEFA4 26006012 */  beqz       $s3, .L800CF040
    /* 667A8 800CEFA8 0F80113C */   lui       $s1, %hi(D_800F521C)
    /* 667AC 800CEFAC 01000324 */  addiu      $v1, $zero, 0x1
    /* 667B0 800CEFB0 1C52228E */  lw         $v0, %lo(D_800F521C)($s1)
    /* 667B4 800CEFB4 04900302 */  sllv       $s2, $v1, $s0
    /* 667B8 800CEFB8 24105200 */  and        $v0, $v0, $s2
    /* 667BC 800CEFBC 20004010 */  beqz       $v0, .L800CF040
    /* 667C0 800CEFC0 0F80023C */   lui       $v0, %hi(D_800F569C)
    /* 667C4 800CEFC4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 667C8 800CEFC8 9C56438C */  lw         $v1, %lo(D_800F569C)($v0)
    /* 667CC 800CEFCC 40101000 */  sll        $v0, $s0, 1
    /* 667D0 800CEFD0 9000658C */  lw         $a1, 0x90($v1)
    /* 667D4 800CEFD4 21105000 */  addu       $v0, $v0, $s0
    /* 667D8 800CEFD8 2800A2AF */  sw         $v0, 0x28($sp)
    /* 667DC 800CEFDC 0F80023C */  lui        $v0, %hi(D_800F5234)
    /* 667E0 800CEFE0 0F80033C */  lui        $v1, %hi(D_800F5318)
    /* 667E4 800CEFE4 18536390 */  lbu        $v1, %lo(D_800F5318)($v1)
    /* 667E8 800CEFE8 34524224 */  addiu      $v0, $v0, %lo(D_800F5234)
    /* 667EC 800CEFEC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 667F0 800CEFF0 1400A2AF */  sw         $v0, 0x14($sp)
    /* 667F4 800CEFF4 0C004224 */  addiu      $v0, $v0, 0xC
    /* 667F8 800CEFF8 2000A0AF */  sw         $zero, 0x20($sp)
    /* 667FC 800CEFFC 1800A2AF */  sw         $v0, 0x18($sp)
    /* 66800 800CF000 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 66804 800CF004 2C00A0AF */  sw         $zero, 0x2C($sp)
    /* 66808 800CF008 3000A3A3 */  sb         $v1, 0x30($sp)
    /* 6680C 800CF00C 0F3A030C */  jal        func_800CE83C
    /* 66810 800CF010 2400A5AF */   sw        $a1, 0x24($sp)
    /* 66814 800CF014 1E3D030C */  jal        func_800CF478
    /* 66818 800CF018 04000424 */   addiu     $a0, $zero, 0x4
    /* 6681C 800CF01C 0F80033C */  lui        $v1, %hi(D_800F5228)
    /* 66820 800CF020 2852628C */  lw         $v0, %lo(D_800F5228)($v1)
    /* 66824 800CF024 00000000 */  nop
    /* 66828 800CF028 01004224 */  addiu      $v0, $v0, 0x1
    /* 6682C 800CF02C 285262AC */  sw         $v0, %lo(D_800F5228)($v1)
    /* 66830 800CF030 1C52228E */  lw         $v0, %lo(D_800F521C)($s1)
    /* 66834 800CF034 27181200 */  nor        $v1, $zero, $s2
    /* 66838 800CF038 24104300 */  and        $v0, $v0, $v1
    /* 6683C 800CF03C 1C5222AE */  sw         $v0, %lo(D_800F521C)($s1)
  .L800CF040:
    /* 66840 800CF040 21106002 */  addu       $v0, $s3, $zero
    /* 66844 800CF044 4800BF8F */  lw         $ra, 0x48($sp)
    /* 66848 800CF048 4400B38F */  lw         $s3, 0x44($sp)
    /* 6684C 800CF04C 4000B28F */  lw         $s2, 0x40($sp)
    /* 66850 800CF050 3C00B18F */  lw         $s1, 0x3C($sp)
    /* 66854 800CF054 3800B08F */  lw         $s0, 0x38($sp)
    /* 66858 800CF058 0800E003 */  jr         $ra
    /* 6685C 800CF05C 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_800CEF74
