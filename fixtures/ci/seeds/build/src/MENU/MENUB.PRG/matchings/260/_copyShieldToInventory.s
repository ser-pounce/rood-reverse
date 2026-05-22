nonmatching _copyShieldToInventory, 0xF0

glabel _copyShieldToInventory
    /* 579C 80107F9C 1180023C */  lui        $v0, %hi(_inventory)
    /* 57A0 80107FA0 A8A6428C */  lw         $v0, %lo(_inventory)($v0)
    /* 57A4 80107FA4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 57A8 80107FA8 2400B5AF */  sw         $s5, 0x24($sp)
    /* 57AC 80107FAC 21A88000 */  addu       $s5, $a0, $zero
    /* 57B0 80107FB0 2800BFAF */  sw         $ra, 0x28($sp)
    /* 57B4 80107FB4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 57B8 80107FB8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 57BC 80107FBC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 57C0 80107FC0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 57C4 80107FC4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 57C8 80107FC8 00015124 */  addiu      $s1, $v0, 0x100
    /* 57CC 80107FCC 04002292 */  lbu        $v0, 0x4($s1)
    /* 57D0 80107FD0 00000000 */  nop
    /* 57D4 80107FD4 0B004010 */  beqz       $v0, .L80108004
    /* 57D8 80107FD8 01001324 */   addiu     $s3, $zero, 0x1
    /* 57DC 80107FDC 08000324 */  addiu      $v1, $zero, 0x8
    /* 57E0 80107FE0 30003126 */  addiu      $s1, $s1, 0x30
  .L80107FE4:
    /* 57E4 80107FE4 01007326 */  addiu      $s3, $s3, 0x1
    /* 57E8 80107FE8 1F006312 */  beq        $s3, $v1, .L80108068
    /* 57EC 80107FEC 21100000 */   addu      $v0, $zero, $zero
    /* 57F0 80107FF0 04002292 */  lbu        $v0, 0x4($s1)
    /* 57F4 80107FF4 00000000 */  nop
    /* 57F8 80107FF8 FAFF4014 */  bnez       $v0, .L80107FE4
    /* 57FC 80107FFC 30003126 */   addiu     $s1, $s1, 0x30
    /* 5800 80108000 D0FF3126 */  addiu      $s1, $s1, -0x30
  .L80108004:
    /* 5804 80108004 21202002 */  addu       $a0, $s1, $zero
    /* 5808 80108008 0733030C */  jal        vs_battle_rMemzero
    /* 580C 8010800C 30000524 */   addiu     $a1, $zero, 0x30
    /* 5810 80108010 04002426 */  addiu      $a0, $s1, 0x4
    /* 5814 80108014 0400A526 */  addiu      $a1, $s5, 0x4
    /* 5818 80108018 7000030C */  jal        vs_battle_copyAligned
    /* 581C 8010801C 28000624 */   addiu     $a2, $zero, 0x28
    /* 5820 80108020 2A0033A2 */  sb         $s3, 0x2A($s1)
    /* 5824 80108024 21800000 */  addu       $s0, $zero, $zero
    /* 5828 80108028 2C001424 */  addiu      $s4, $zero, 0x2C
    /* 582C 8010802C 2190A002 */  addu       $s2, $s5, $zero
  .L80108030:
    /* 5830 80108030 2C004296 */  lhu        $v0, 0x2C($s2)
    /* 5834 80108034 00000000 */  nop
    /* 5838 80108038 05004010 */  beqz       $v0, .L80108050
    /* 583C 8010803C 2120B402 */   addu      $a0, $s5, $s4
    /* 5840 80108040 5F1F040C */  jal        _copyGemToInventory
    /* 5844 80108044 80006536 */   ori       $a1, $s3, 0x80
    /* 5848 80108048 21183002 */  addu       $v1, $s1, $s0
    /* 584C 8010804C 2C0062A0 */  sb         $v0, 0x2C($v1)
  .L80108050:
    /* 5850 80108050 1C009426 */  addiu      $s4, $s4, 0x1C
    /* 5854 80108054 01001026 */  addiu      $s0, $s0, 0x1
    /* 5858 80108058 0300022A */  slti       $v0, $s0, 0x3
    /* 585C 8010805C F4FF4014 */  bnez       $v0, .L80108030
    /* 5860 80108060 1C005226 */   addiu     $s2, $s2, 0x1C
    /* 5864 80108064 21106002 */  addu       $v0, $s3, $zero
  .L80108068:
    /* 5868 80108068 2800BF8F */  lw         $ra, 0x28($sp)
    /* 586C 8010806C 2400B58F */  lw         $s5, 0x24($sp)
    /* 5870 80108070 2000B48F */  lw         $s4, 0x20($sp)
    /* 5874 80108074 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5878 80108078 1800B28F */  lw         $s2, 0x18($sp)
    /* 587C 8010807C 1400B18F */  lw         $s1, 0x14($sp)
    /* 5880 80108080 1000B08F */  lw         $s0, 0x10($sp)
    /* 5884 80108084 0800E003 */  jr         $ra
    /* 5888 80108088 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _copyShieldToInventory
