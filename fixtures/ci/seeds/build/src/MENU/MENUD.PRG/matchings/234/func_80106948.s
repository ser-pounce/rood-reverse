nonmatching func_80106948, 0x68

glabel func_80106948
    /* 4148 80106948 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 414C 8010694C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4150 80106950 21888000 */  addu       $s1, $a0, $zero
    /* 4154 80106954 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4158 80106958 2190A000 */  addu       $s2, $a1, $zero
    /* 415C 8010695C 10002436 */  ori        $a0, $s1, 0x10
    /* 4160 80106960 21304002 */  addu       $a2, $s2, $zero
    /* 4164 80106964 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 4168 80106968 1000B0AF */  sw         $s0, 0x10($sp)
    /* 416C 8010696C 1180103C */  lui        $s0, %hi(vs_menuD_containerData)
    /* 4170 80106970 5C24458C */  lw         $a1, %lo(vs_menu_inventoryStorage)($v0)
    /* 4174 80106974 8C9A078E */  lw         $a3, %lo(vs_menuD_containerData)($s0)
    /* 4178 80106978 B0870334 */  ori        $v1, $zero, 0x87B0
    /* 417C 8010697C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4180 80106980 AB0C040C */  jal        _copyContainerItem
    /* 4184 80106984 2128A300 */   addu      $a1, $a1, $v1
    /* 4188 80106988 21202002 */  addu       $a0, $s1, $zero
    /* 418C 8010698C 8C9A068E */  lw         $a2, %lo(vs_menuD_containerData)($s0)
    /* 4190 80106990 600B040C */  jal        _initContainerObject
    /* 4194 80106994 21284002 */   addu      $a1, $s2, $zero
    /* 4198 80106998 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 419C 8010699C 1800B28F */  lw         $s2, 0x18($sp)
    /* 41A0 801069A0 1400B18F */  lw         $s1, 0x14($sp)
    /* 41A4 801069A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 41A8 801069A8 0800E003 */  jr         $ra
    /* 41AC 801069AC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80106948
