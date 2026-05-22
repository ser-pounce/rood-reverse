nonmatching func_80104E90, 0x74

glabel func_80104E90
    /* 2690 80104E90 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2694 80104E94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2698 80104E98 21888000 */  addu       $s1, $a0, $zero
    /* 269C 80104E9C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 26A0 80104EA0 00840500 */  sll        $s0, $a1, 16
    /* 26A4 80104EA4 03841000 */  sra        $s0, $s0, 16
    /* 26A8 80104EA8 23801000 */  negu       $s0, $s0
    /* 26AC 80104EAC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 26B0 80104EB0 CA03010C */  jal        rsin
    /* 26B4 80104EB4 21200002 */   addu      $a0, $s0, $zero
    /* 26B8 80104EB8 21200002 */  addu       $a0, $s0, $zero
    /* 26BC 80104EBC C903010C */  jal        rcos
    /* 26C0 80104EC0 21804000 */   addu      $s0, $v0, $zero
    /* 26C4 80104EC4 23181000 */  negu       $v1, $s0
    /* 26C8 80104EC8 040023A6 */  sh         $v1, 0x4($s1)
    /* 26CC 80104ECC 00100324 */  addiu      $v1, $zero, 0x1000
    /* 26D0 80104ED0 000022A6 */  sh         $v0, 0x0($s1)
    /* 26D4 80104ED4 020020A6 */  sh         $zero, 0x2($s1)
    /* 26D8 80104ED8 060020A6 */  sh         $zero, 0x6($s1)
    /* 26DC 80104EDC 080023A6 */  sh         $v1, 0x8($s1)
    /* 26E0 80104EE0 0A0020A6 */  sh         $zero, 0xA($s1)
    /* 26E4 80104EE4 0C0030A6 */  sh         $s0, 0xC($s1)
    /* 26E8 80104EE8 0E0020A6 */  sh         $zero, 0xE($s1)
    /* 26EC 80104EEC 100022A6 */  sh         $v0, 0x10($s1)
    /* 26F0 80104EF0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 26F4 80104EF4 1400B18F */  lw         $s1, 0x14($sp)
    /* 26F8 80104EF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 26FC 80104EFC 0800E003 */  jr         $ra
    /* 2700 80104F00 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80104E90
