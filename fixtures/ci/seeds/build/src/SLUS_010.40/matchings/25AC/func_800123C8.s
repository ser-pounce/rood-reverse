nonmatching func_800123C8, 0x44

glabel func_800123C8
    /* 2BC8 800123C8 04008104 */  bgez       $a0, .L800123DC
    /* 2BCC 800123CC 21280000 */   addu      $a1, $zero, $zero
    /* 2BD0 800123D0 09008290 */  lbu        $v0, 0x9($a0)
    /* 2BD4 800123D4 01490008 */  j          .L80012404
    /* 2BD8 800123D8 C2290200 */   srl       $a1, $v0, 7
  .L800123DC:
    /* 2BDC 800123DC 0380023C */  lui        $v0, %hi(g_Sound_SfxMetadataTable)
    /* 2BE0 800123E0 F477438C */  lw         $v1, %lo(g_Sound_SfxMetadataTable)($v0)
    /* 2BE4 800123E4 40100400 */  sll        $v0, $a0, 1
    /* 2BE8 800123E8 21104300 */  addu       $v0, $v0, $v1
    /* 2BEC 800123EC 00004294 */  lhu        $v0, 0x0($v0)
    /* 2BF0 800123F0 00000000 */  nop
    /* 2BF4 800123F4 00804230 */  andi       $v0, $v0, 0x8000
    /* 2BF8 800123F8 02004010 */  beqz       $v0, .L80012404
    /* 2BFC 800123FC 00000000 */   nop
    /* 2C00 80012400 01000524 */  addiu      $a1, $zero, 0x1
  .L80012404:
    /* 2C04 80012404 0800E003 */  jr         $ra
    /* 2C08 80012408 2110A000 */   addu      $v0, $a1, $zero
endlabel func_800123C8
