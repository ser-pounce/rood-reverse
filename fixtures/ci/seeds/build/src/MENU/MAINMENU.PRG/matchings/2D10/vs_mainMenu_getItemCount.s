nonmatching vs_mainMenu_getItemCount, 0x9C

glabel vs_mainMenu_getItemCount
    /* 526C 800FEA6C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 5270 800FEA70 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5274 800FEA74 21988000 */  addu       $s3, $a0, $zero
    /* 5278 800FEA78 2000B4AF */  sw         $s4, 0x20($sp)
    /* 527C 800FEA7C 21A0A000 */  addu       $s4, $a1, $zero
    /* 5280 800FEA80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5284 800FEA84 21800000 */  addu       $s0, $zero, $zero
    /* 5288 800FEA88 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 528C 800FEA8C A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 5290 800FEA90 21186202 */  addu       $v1, $s3, $v0
    /* 5294 800FEA94 2400BFAF */  sw         $ra, 0x24($sp)
    /* 5298 800FEA98 1800B2AF */  sw         $s2, 0x18($sp)
    /* 529C 800FEA9C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 52A0 800FEAA0 00006290 */  lbu        $v0, 0x0($v1)
    /* 52A4 800FEAA4 00000000 */  nop
    /* 52A8 800FEAA8 0E004010 */  beqz       $v0, .L800FEAE4
    /* 52AC 800FEAAC 21880002 */   addu      $s1, $s0, $zero
    /* 52B0 800FEAB0 21906000 */  addu       $s2, $v1, $zero
    /* 52B4 800FEAB4 21206002 */  addu       $a0, $s3, $zero
  .L800FEAB8:
    /* 52B8 800FEAB8 21280002 */  addu       $a1, $s0, $zero
    /* 52BC 800FEABC BBF9030C */  jal        _getItemId
    /* 52C0 800FEAC0 21308002 */   addu      $a2, $s4, $zero
    /* 52C4 800FEAC4 02004010 */  beqz       $v0, .L800FEAD0
    /* 52C8 800FEAC8 00000000 */   nop
    /* 52CC 800FEACC 01003126 */  addiu      $s1, $s1, 0x1
  .L800FEAD0:
    /* 52D0 800FEAD0 00004292 */  lbu        $v0, 0x0($s2)
    /* 52D4 800FEAD4 01001026 */  addiu      $s0, $s0, 0x1
    /* 52D8 800FEAD8 2A100202 */  slt        $v0, $s0, $v0
    /* 52DC 800FEADC F6FF4014 */  bnez       $v0, .L800FEAB8
    /* 52E0 800FEAE0 21206002 */   addu      $a0, $s3, $zero
  .L800FEAE4:
    /* 52E4 800FEAE4 21102002 */  addu       $v0, $s1, $zero
    /* 52E8 800FEAE8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 52EC 800FEAEC 2000B48F */  lw         $s4, 0x20($sp)
    /* 52F0 800FEAF0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 52F4 800FEAF4 1800B28F */  lw         $s2, 0x18($sp)
    /* 52F8 800FEAF8 1400B18F */  lw         $s1, 0x14($sp)
    /* 52FC 800FEAFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 5300 800FEB00 0800E003 */  jr         $ra
    /* 5304 800FEB04 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_getItemCount
