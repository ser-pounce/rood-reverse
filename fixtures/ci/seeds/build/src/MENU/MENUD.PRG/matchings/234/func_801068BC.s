nonmatching func_801068BC, 0x8C

glabel func_801068BC
    /* 40BC 801068BC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 40C0 801068C0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 40C4 801068C4 1080133C */  lui        $s3, %hi(vs_menu_inventoryStorage)
    /* 40C8 801068C8 40200400 */  sll        $a0, $a0, 1
    /* 40CC 801068CC 5C24678E */  lw         $a3, %lo(vs_menu_inventoryStorage)($s3)
    /* 40D0 801068D0 00800234 */  ori        $v0, $zero, 0x8000
    /* 40D4 801068D4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 40D8 801068D8 B0871134 */  ori        $s1, $zero, 0x87B0
    /* 40DC 801068DC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 40E0 801068E0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 40E4 801068E4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 40E8 801068E8 2120E400 */  addu       $a0, $a3, $a0
    /* 40EC 801068EC 21208200 */  addu       $a0, $a0, $v0
    /* 40F0 801068F0 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 40F4 801068F4 2138F100 */  addu       $a3, $a3, $s1
    /* 40F8 801068F8 B0439094 */  lhu        $s0, 0x43B0($a0)
    /* 40FC 801068FC 8C9A458C */  lw         $a1, %lo(vs_menuD_containerData)($v0)
    /* 4100 80106900 03921000 */  sra        $s2, $s0, 8
    /* 4104 80106904 10004436 */  ori        $a0, $s2, 0x10
    /* 4108 80106908 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 410C 8010690C FF001032 */  andi       $s0, $s0, 0xFF
    /* 4110 80106910 AB0C040C */  jal        _copyContainerItem
    /* 4114 80106914 21300002 */   addu      $a2, $s0, $zero
    /* 4118 80106918 21204002 */  addu       $a0, $s2, $zero
    /* 411C 8010691C 5C24668E */  lw         $a2, %lo(vs_menu_inventoryStorage)($s3)
    /* 4120 80106920 21280002 */  addu       $a1, $s0, $zero
    /* 4124 80106924 600B040C */  jal        _initContainerObject
    /* 4128 80106928 2130D100 */   addu      $a2, $a2, $s1
    /* 412C 8010692C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4130 80106930 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4134 80106934 1800B28F */  lw         $s2, 0x18($sp)
    /* 4138 80106938 1400B18F */  lw         $s1, 0x14($sp)
    /* 413C 8010693C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4140 80106940 0800E003 */  jr         $ra
    /* 4144 80106944 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_801068BC
