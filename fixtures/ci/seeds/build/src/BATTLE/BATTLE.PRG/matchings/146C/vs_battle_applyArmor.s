nonmatching vs_battle_applyArmor, 0x84

glabel vs_battle_applyArmor
    /* 2910 8006B110 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2914 8006B114 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2918 8006B118 21908000 */  addu       $s2, $a0, $zero
    /* 291C 8006B11C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2920 8006B120 2188A000 */  addu       $s1, $a1, $zero
    /* 2924 8006B124 34000424 */  addiu      $a0, $zero, 0x34
    /* 2928 8006B128 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 292C 8006B12C 8F0F010C */  jal        vs_main_allocHeapR
    /* 2930 8006B130 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2934 8006B134 21804000 */  addu       $s0, $v0, $zero
    /* 2938 8006B138 21200002 */  addu       $a0, $s0, $zero
    /* 293C 8006B13C 4424010C */  jal        vs_main_bzero
    /* 2940 8006B140 34000524 */   addiu     $a1, $zero, 0x34
    /* 2944 8006B144 08002012 */  beqz       $s1, .L8006B168
    /* 2948 8006B148 21282002 */   addu      $a1, $s1, $zero
    /* 294C 8006B14C 21200002 */  addu       $a0, $s0, $zero
    /* 2950 8006B150 27002292 */  lbu        $v0, 0x27($s1)
    /* 2954 8006B154 3FAB010C */  jal        vs_battle_copyInventoryArmorStats
    /* 2958 8006B158 330002A2 */   sb        $v0, 0x33($s0)
    /* 295C 8006B15C 24002292 */  lbu        $v0, 0x24($s1)
    /* 2960 8006B160 00000000 */  nop
    /* 2964 8006B164 300002A2 */  sb         $v0, 0x30($s0)
  .L8006B168:
    /* 2968 8006B168 21204002 */  addu       $a0, $s2, $zero
    /* 296C 8006B16C 7CAA010C */  jal        _applyArmorStats
    /* 2970 8006B170 21280002 */   addu      $a1, $s0, $zero
    /* 2974 8006B174 180F010C */  jal        vs_main_freeHeapR
    /* 2978 8006B178 21200002 */   addu      $a0, $s0, $zero
    /* 297C 8006B17C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2980 8006B180 1800B28F */  lw         $s2, 0x18($sp)
    /* 2984 8006B184 1400B18F */  lw         $s1, 0x14($sp)
    /* 2988 8006B188 1000B08F */  lw         $s0, 0x10($sp)
    /* 298C 8006B18C 0800E003 */  jr         $ra
    /* 2990 8006B190 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_applyArmor
