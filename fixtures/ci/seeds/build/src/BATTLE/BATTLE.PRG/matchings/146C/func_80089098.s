nonmatching func_80089098, 0x6C

glabel func_80089098
    /* 20898 80089098 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2089C 8008909C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 208A0 800890A0 FBFA020C */  jal        func_800BEBEC
    /* 208A4 800890A4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 208A8 800890A8 622D020C */  jal        _nop2
    /* 208AC 800890AC 21200000 */   addu      $a0, $zero, $zero
    /* 208B0 800890B0 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 208B4 800890B4 80185024 */  addiu      $s0, $v0, %lo(_zoneContext)
    /* 208B8 800890B8 0C00048E */  lw         $a0, 0xC($s0)
    /* 208BC 800890BC 00000000 */  nop
    /* 208C0 800890C0 03008010 */  beqz       $a0, .L800890D0
    /* 208C4 800890C4 00000000 */   nop
    /* 208C8 800890C8 540F010C */  jal        vs_main_freeHeap
    /* 208CC 800890CC 00000000 */   nop
  .L800890D0:
    /* 208D0 800890D0 1000048E */  lw         $a0, 0x10($s0)
    /* 208D4 800890D4 00000000 */  nop
    /* 208D8 800890D8 03008010 */  beqz       $a0, .L800890E8
    /* 208DC 800890DC 00000000 */   nop
    /* 208E0 800890E0 540F010C */  jal        vs_main_freeHeap
    /* 208E4 800890E4 00000000 */   nop
  .L800890E8:
    /* 208E8 800890E8 0400048E */  lw         $a0, 0x4($s0)
    /* 208EC 800890EC 540F010C */  jal        vs_main_freeHeap
    /* 208F0 800890F0 00000000 */   nop
    /* 208F4 800890F4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 208F8 800890F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 208FC 800890FC 0800E003 */  jr         $ra
    /* 20900 80089100 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80089098
