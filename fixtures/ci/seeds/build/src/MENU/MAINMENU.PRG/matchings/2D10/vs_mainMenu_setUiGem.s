nonmatching vs_mainMenu_setUiGem, 0x9C

glabel vs_mainMenu_setUiGem
    /* 38E0 800FD0E0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 38E4 800FD0E4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 38E8 800FD0E8 21888000 */  addu       $s1, $a0, $zero
    /* 38EC 800FD0EC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 38F0 800FD0F0 2190A000 */  addu       $s2, $a1, $zero
    /* 38F4 800FD0F4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 38F8 800FD0F8 2198C000 */  addu       $s3, $a2, $zero
    /* 38FC 800FD0FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3900 800FD100 2180E000 */  addu       $s0, $a3, $zero
    /* 3904 800FD104 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 3908 800FD108 21200002 */  addu       $a0, $s0, $zero
    /* 390C 800FD10C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 3910 800FD110 00002296 */  lhu        $v0, 0x0($s1)
    /* 3914 800FD114 4025638C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 3918 800FD118 40100200 */  sll        $v0, $v0, 1
    /* 391C 800FD11C 21104300 */  addu       $v0, $v0, $v1
    /* 3920 800FD120 E8FE4594 */  lhu        $a1, -0x118($v0)
    /* 3924 800FD124 60000624 */  addiu      $a2, $zero, 0x60
    /* 3928 800FD128 40280500 */  sll        $a1, $a1, 1
    /* 392C 800FD12C 7800030C */  jal        vs_battle_memcpy
    /* 3930 800FD130 21286500 */   addu      $a1, $v1, $a1
    /* 3934 800FD134 00002396 */  lhu        $v1, 0x0($s1)
    /* 3938 800FD138 1080043C */  lui        $a0, %hi(vs_mainMenu_itemNames)
    /* 393C 800FD13C 040050AE */  sw         $s0, 0x4($s2)
    /* 3940 800FD140 40100300 */  sll        $v0, $v1, 1
    /* 3944 800FD144 21104300 */  addu       $v0, $v0, $v1
    /* 3948 800FD148 9C22838C */  lw         $v1, %lo(vs_mainMenu_itemNames)($a0)
    /* 394C 800FD14C C0100200 */  sll        $v0, $v0, 3
    /* 3950 800FD150 21186200 */  addu       $v1, $v1, $v0
    /* 3954 800FD154 0058023C */  lui        $v0, (0x58000000 >> 16)
    /* 3958 800FD158 000043AE */  sw         $v1, 0x0($s2)
    /* 395C 800FD15C 000062AE */  sw         $v0, 0x0($s3)
    /* 3960 800FD160 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3964 800FD164 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3968 800FD168 1800B28F */  lw         $s2, 0x18($sp)
    /* 396C 800FD16C 1400B18F */  lw         $s1, 0x14($sp)
    /* 3970 800FD170 1000B08F */  lw         $s0, 0x10($sp)
    /* 3974 800FD174 0800E003 */  jr         $ra
    /* 3978 800FD178 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_setUiGem
