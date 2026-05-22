nonmatching vs_mainMenu_rebuildInventory, 0x1BC

glabel vs_mainMenu_rebuildInventory
    /* 50B0 800FE8B0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 50B4 800FE8B4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 50B8 800FE8B8 21A08000 */  addu       $s4, $a0, $zero
    /* 50BC 800FE8BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50C0 800FE8C0 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryIndices)
    /* 50C4 800FE8C4 A8224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryIndices)
    /* 50C8 800FE8C8 80181400 */  sll        $v1, $s4, 2
    /* 50CC 800FE8CC 21186200 */  addu       $v1, $v1, $v0
    /* 50D0 800FE8D0 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 50D4 800FE8D4 A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 50D8 800FE8D8 21108202 */  addu       $v0, $s4, $v0
    /* 50DC 800FE8DC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 50E0 800FE8E0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 50E4 800FE8E4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 50E8 800FE8E8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 50EC 800FE8EC 00005190 */  lbu        $s1, 0x0($v0)
    /* 50F0 800FE8F0 0000738C */  lw         $s3, 0x0($v1)
    /* 50F4 800FE8F4 10002012 */  beqz       $s1, .L800FE938
    /* 50F8 800FE8F8 21800000 */   addu      $s0, $zero, $zero
    /* 50FC 800FE8FC 21907002 */  addu       $s2, $s3, $s0
  .L800FE900:
    /* 5100 800FE900 00004592 */  lbu        $a1, 0x0($s2)
    /* 5104 800FE904 00000000 */  nop
    /* 5108 800FE908 0700A010 */  beqz       $a1, .L800FE928
    /* 510C 800FE90C 21208002 */   addu      $a0, $s4, $zero
    /* 5110 800FE910 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 5114 800FE914 BBF9030C */  jal        _getItemId
    /* 5118 800FE918 21300000 */   addu      $a2, $zero, $zero
    /* 511C 800FE91C 02004014 */  bnez       $v0, .L800FE928
    /* 5120 800FE920 00000000 */   nop
    /* 5124 800FE924 000040A2 */  sb         $zero, 0x0($s2)
  .L800FE928:
    /* 5128 800FE928 01001026 */  addiu      $s0, $s0, 0x1
    /* 512C 800FE92C 2A101102 */  slt        $v0, $s0, $s1
    /* 5130 800FE930 F3FF4014 */  bnez       $v0, .L800FE900
    /* 5134 800FE934 21907002 */   addu      $s2, $s3, $s0
  .L800FE938:
    /* 5138 800FE938 21800000 */  addu       $s0, $zero, $zero
    /* 513C 800FE93C FFFF2626 */  addiu      $a2, $s1, -0x1
    /* 5140 800FE940 21107002 */  addu       $v0, $s3, $s0
  .L800FE944:
    /* 5144 800FE944 00004290 */  lbu        $v0, 0x0($v0)
    /* 5148 800FE948 00000000 */  nop
    /* 514C 800FE94C 06004010 */  beqz       $v0, .L800FE968
    /* 5150 800FE950 01000526 */   addiu     $a1, $s0, 0x1
    /* 5154 800FE954 01001026 */  addiu      $s0, $s0, 0x1
    /* 5158 800FE958 2A000612 */  beq        $s0, $a2, .L800FEA04
    /* 515C 800FE95C 21107002 */   addu      $v0, $s3, $s0
    /* 5160 800FE960 51FA0308 */  j          .L800FE944
    /* 5164 800FE964 00000000 */   nop
  .L800FE968:
    /* 5168 800FE968 2A10B100 */  slt        $v0, $a1, $s1
    /* 516C 800FE96C 09004010 */  beqz       $v0, .L800FE994
    /* 5170 800FE970 21106502 */   addu      $v0, $s3, $a1
  .L800FE974:
    /* 5174 800FE974 00004290 */  lbu        $v0, 0x0($v0)
    /* 5178 800FE978 00000000 */  nop
    /* 517C 800FE97C 05004014 */  bnez       $v0, .L800FE994
    /* 5180 800FE980 00000000 */   nop
    /* 5184 800FE984 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5188 800FE988 2A10B100 */  slt        $v0, $a1, $s1
    /* 518C 800FE98C F9FF4014 */  bnez       $v0, .L800FE974
    /* 5190 800FE990 21106502 */   addu      $v0, $s3, $a1
  .L800FE994:
    /* 5194 800FE994 1B00B110 */  beq        $a1, $s1, .L800FEA04
    /* 5198 800FE998 2120A000 */   addu      $a0, $a1, $zero
    /* 519C 800FE99C 2A109100 */  slt        $v0, $a0, $s1
    /* 51A0 800FE9A0 0C004010 */  beqz       $v0, .L800FE9D4
    /* 51A4 800FE9A4 23100502 */   subu      $v0, $s0, $a1
    /* 51A8 800FE9A8 21109000 */  addu       $v0, $a0, $s0
  .L800FE9AC:
    /* 51AC 800FE9AC 21186402 */  addu       $v1, $s3, $a0
    /* 51B0 800FE9B0 01008424 */  addiu      $a0, $a0, 0x1
    /* 51B4 800FE9B4 23104500 */  subu       $v0, $v0, $a1
    /* 51B8 800FE9B8 00006390 */  lbu        $v1, 0x0($v1)
    /* 51BC 800FE9BC 21106202 */  addu       $v0, $s3, $v0
    /* 51C0 800FE9C0 000043A0 */  sb         $v1, 0x0($v0)
    /* 51C4 800FE9C4 2A109100 */  slt        $v0, $a0, $s1
    /* 51C8 800FE9C8 F8FF4014 */  bnez       $v0, .L800FE9AC
    /* 51CC 800FE9CC 21109000 */   addu      $v0, $a0, $s0
    /* 51D0 800FE9D0 23100502 */  subu       $v0, $s0, $a1
  .L800FE9D4:
    /* 51D4 800FE9D4 21208200 */  addu       $a0, $a0, $v0
    /* 51D8 800FE9D8 2A109100 */  slt        $v0, $a0, $s1
    /* 51DC 800FE9DC D9FF4010 */  beqz       $v0, .L800FE944
    /* 51E0 800FE9E0 21107002 */   addu      $v0, $s3, $s0
    /* 51E4 800FE9E4 21106402 */  addu       $v0, $s3, $a0
  .L800FE9E8:
    /* 51E8 800FE9E8 000040A0 */  sb         $zero, 0x0($v0)
    /* 51EC 800FE9EC 01008424 */  addiu      $a0, $a0, 0x1
    /* 51F0 800FE9F0 2A109100 */  slt        $v0, $a0, $s1
    /* 51F4 800FE9F4 FCFF4014 */  bnez       $v0, .L800FE9E8
    /* 51F8 800FE9F8 21106402 */   addu      $v0, $s3, $a0
    /* 51FC 800FE9FC 51FA0308 */  j          .L800FE944
    /* 5200 800FEA00 21107002 */   addu      $v0, $s3, $s0
  .L800FEA04:
    /* 5204 800FEA04 11002012 */  beqz       $s1, .L800FEA4C
    /* 5208 800FEA08 21800000 */   addu      $s0, $zero, $zero
    /* 520C 800FEA0C 21208002 */  addu       $a0, $s4, $zero
  .L800FEA10:
    /* 5210 800FEA10 21280002 */  addu       $a1, $s0, $zero
    /* 5214 800FEA14 BBF9030C */  jal        _getItemId
    /* 5218 800FEA18 21300000 */   addu      $a2, $zero, $zero
    /* 521C 800FEA1C 07004010 */  beqz       $v0, .L800FEA3C
    /* 5220 800FEA20 21208002 */   addu      $a0, $s4, $zero
    /* 5224 800FEA24 F8F9030C */  jal        vs_mainMenu_findItem
    /* 5228 800FEA28 21280002 */   addu      $a1, $s0, $zero
    /* 522C 800FEA2C 03004014 */  bnez       $v0, .L800FEA3C
    /* 5230 800FEA30 21208002 */   addu      $a0, $s4, $zero
    /* 5234 800FEA34 12FA030C */  jal        _setItemIndex
    /* 5238 800FEA38 21280002 */   addu      $a1, $s0, $zero
  .L800FEA3C:
    /* 523C 800FEA3C 01001026 */  addiu      $s0, $s0, 0x1
    /* 5240 800FEA40 2A101102 */  slt        $v0, $s0, $s1
    /* 5244 800FEA44 F2FF4014 */  bnez       $v0, .L800FEA10
    /* 5248 800FEA48 21208002 */   addu      $a0, $s4, $zero
  .L800FEA4C:
    /* 524C 800FEA4C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 5250 800FEA50 2000B48F */  lw         $s4, 0x20($sp)
    /* 5254 800FEA54 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5258 800FEA58 1800B28F */  lw         $s2, 0x18($sp)
    /* 525C 800FEA5C 1400B18F */  lw         $s1, 0x14($sp)
    /* 5260 800FEA60 1000B08F */  lw         $s0, 0x10($sp)
    /* 5264 800FEA64 0800E003 */  jr         $ra
    /* 5268 800FEA68 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_rebuildInventory
