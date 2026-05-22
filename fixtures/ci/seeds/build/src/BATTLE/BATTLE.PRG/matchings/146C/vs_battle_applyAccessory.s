nonmatching vs_battle_applyAccessory, 0x78

glabel vs_battle_applyAccessory
    /* 2994 8006B194 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2998 8006B198 1800B2AF */  sw         $s2, 0x18($sp)
    /* 299C 8006B19C 21908000 */  addu       $s2, $a0, $zero
    /* 29A0 8006B1A0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 29A4 8006B1A4 2188A000 */  addu       $s1, $a1, $zero
    /* 29A8 8006B1A8 34000424 */  addiu      $a0, $zero, 0x34
    /* 29AC 8006B1AC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 29B0 8006B1B0 8F0F010C */  jal        vs_main_allocHeapR
    /* 29B4 8006B1B4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 29B8 8006B1B8 21804000 */  addu       $s0, $v0, $zero
    /* 29BC 8006B1BC 21200002 */  addu       $a0, $s0, $zero
    /* 29C0 8006B1C0 4424010C */  jal        vs_main_bzero
    /* 29C4 8006B1C4 34000524 */   addiu     $a1, $zero, 0x34
    /* 29C8 8006B1C8 05002012 */  beqz       $s1, .L8006B1E0
    /* 29CC 8006B1CC 21282002 */   addu      $a1, $s1, $zero
    /* 29D0 8006B1D0 21200002 */  addu       $a0, $s0, $zero
    /* 29D4 8006B1D4 27002292 */  lbu        $v0, 0x27($s1)
    /* 29D8 8006B1D8 3FAB010C */  jal        vs_battle_copyInventoryArmorStats
    /* 29DC 8006B1DC 310002A2 */   sb        $v0, 0x31($s0)
  .L8006B1E0:
    /* 29E0 8006B1E0 21204002 */  addu       $a0, $s2, $zero
    /* 29E4 8006B1E4 3BAA010C */  jal        _applyAccessoryStats
    /* 29E8 8006B1E8 21280002 */   addu      $a1, $s0, $zero
    /* 29EC 8006B1EC 180F010C */  jal        vs_main_freeHeapR
    /* 29F0 8006B1F0 21200002 */   addu      $a0, $s0, $zero
    /* 29F4 8006B1F4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 29F8 8006B1F8 1800B28F */  lw         $s2, 0x18($sp)
    /* 29FC 8006B1FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 2A00 8006B200 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A04 8006B204 0800E003 */  jr         $ra
    /* 2A08 8006B208 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_applyAccessory
