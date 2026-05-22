nonmatching Sound_SetReverbMode, 0x50

glabel Sound_SetReverbMode
    /* 93E0 80018BE0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 93E4 80018BE4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 93E8 80018BE8 21808000 */  addu       $s0, $a0, $zero
    /* 93EC 80018BEC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 93F0 80018BF0 4D7D000C */  jal        SpuGetReverbModeType
    /* 93F4 80018BF4 1000A427 */   addiu     $a0, $sp, 0x10
    /* 93F8 80018BF8 1000A28F */  lw         $v0, 0x10($sp)
    /* 93FC 80018BFC 00000000 */  nop
    /* 9400 80018C00 07005010 */  beq        $v0, $s0, .L80018C20
    /* 9404 80018C04 00000000 */   nop
    /* 9408 80018C08 CD79000C */  jal        SpuSetReverb
    /* 940C 80018C0C 21200000 */   addu      $a0, $zero, $zero
    /* 9410 80018C10 317B000C */  jal        SpuSetReverbModeType
    /* 9414 80018C14 00010436 */   ori       $a0, $s0, 0x100
    /* 9418 80018C18 CD79000C */  jal        SpuSetReverb
    /* 941C 80018C1C 01000424 */   addiu     $a0, $zero, 0x1
  .L80018C20:
    /* 9420 80018C20 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 9424 80018C24 1800B08F */  lw         $s0, 0x18($sp)
    /* 9428 80018C28 0800E003 */  jr         $ra
    /* 942C 80018C2C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_SetReverbMode
