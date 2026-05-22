nonmatching vs_mainMenu_setUiItem, 0xA4

glabel vs_mainMenu_setUiItem
    /* 397C 800FD17C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3980 800FD180 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3984 800FD184 21808000 */  addu       $s0, $a0, $zero
    /* 3988 800FD188 1800B2AF */  sw         $s2, 0x18($sp)
    /* 398C 800FD18C 2190A000 */  addu       $s2, $a1, $zero
    /* 3990 800FD190 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3994 800FD194 2198C000 */  addu       $s3, $a2, $zero
    /* 3998 800FD198 1400B1AF */  sw         $s1, 0x14($sp)
    /* 399C 800FD19C 2188E000 */  addu       $s1, $a3, $zero
    /* 39A0 800FD1A0 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 39A4 800FD1A4 21202002 */  addu       $a0, $s1, $zero
    /* 39A8 800FD1A8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 39AC 800FD1AC 00000296 */  lhu        $v0, 0x0($s0)
    /* 39B0 800FD1B0 4025638C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 39B4 800FD1B4 40100200 */  sll        $v0, $v0, 1
    /* 39B8 800FD1B8 21104300 */  addu       $v0, $v0, $v1
    /* 39BC 800FD1BC E8FE4594 */  lhu        $a1, -0x118($v0)
    /* 39C0 800FD1C0 60000624 */  addiu      $a2, $zero, 0x60
    /* 39C4 800FD1C4 40280500 */  sll        $a1, $a1, 1
    /* 39C8 800FD1C8 7800030C */  jal        vs_battle_memcpy
    /* 39CC 800FD1CC 21286500 */   addu      $a1, $v1, $a1
    /* 39D0 800FD1D0 00000396 */  lhu        $v1, 0x0($s0)
    /* 39D4 800FD1D4 1080043C */  lui        $a0, %hi(vs_mainMenu_itemNames)
    /* 39D8 800FD1D8 040051AE */  sw         $s1, 0x4($s2)
    /* 39DC 800FD1DC 40100300 */  sll        $v0, $v1, 1
    /* 39E0 800FD1E0 21104300 */  addu       $v0, $v0, $v1
    /* 39E4 800FD1E4 9C22838C */  lw         $v1, %lo(vs_mainMenu_itemNames)($a0)
    /* 39E8 800FD1E8 C0100200 */  sll        $v0, $v0, 3
    /* 39EC 800FD1EC 21186200 */  addu       $v1, $v1, $v0
    /* 39F0 800FD1F0 000043AE */  sw         $v1, 0x0($s2)
    /* 39F4 800FD1F4 02000292 */  lbu        $v0, 0x2($s0)
    /* 39F8 800FD1F8 00000000 */  nop
    /* 39FC 800FD1FC 40120200 */  sll        $v0, $v0, 9
    /* 3A00 800FD200 000062AE */  sw         $v0, 0x0($s3)
    /* 3A04 800FD204 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3A08 800FD208 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3A0C 800FD20C 1800B28F */  lw         $s2, 0x18($sp)
    /* 3A10 800FD210 1400B18F */  lw         $s1, 0x14($sp)
    /* 3A14 800FD214 1000B08F */  lw         $s0, 0x10($sp)
    /* 3A18 800FD218 0800E003 */  jr         $ra
    /* 3A1C 800FD21C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_setUiItem
