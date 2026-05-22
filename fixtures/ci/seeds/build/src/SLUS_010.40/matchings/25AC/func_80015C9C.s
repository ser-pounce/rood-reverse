nonmatching func_80015C9C, 0x9C

glabel func_80015C9C
    /* 649C 80015C9C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64A0 80015CA0 006E0224 */  addiu      $v0, $zero, 0x6E00
    /* 64A4 80015CA4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 64A8 80015CA8 820082A4 */  sh         $v0, 0x82($a0)
    /* 64AC 80015CAC 0032023C */  lui        $v0, (0x32000000 >> 16)
    /* 64B0 80015CB0 480082AC */  sw         $v0, 0x48($a0)
    /* 64B4 80015CB4 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 64B8 80015CB8 000085AC */  sw         $a1, 0x0($a0)
    /* 64BC 80015CBC 21280000 */  addu       $a1, $zero, $zero
    /* 64C0 80015CC0 E20080A4 */  sh         $zero, 0xE2($a0)
    /* 64C4 80015CC4 E40080A4 */  sh         $zero, 0xE4($a0)
    /* 64C8 80015CC8 9A0080A4 */  sh         $zero, 0x9A($a0)
    /* 64CC 80015CCC 300080AC */  sw         $zero, 0x30($a0)
    /* 64D0 80015CD0 E80080A4 */  sh         $zero, 0xE8($a0)
    /* 64D4 80015CD4 920080A4 */  sh         $zero, 0x92($a0)
    /* 64D8 80015CD8 D60080A4 */  sh         $zero, 0xD6($a0)
    /* 64DC 80015CDC D40080A4 */  sh         $zero, 0xD4($a0)
    /* 64E0 80015CE0 880080A4 */  sh         $zero, 0x88($a0)
    /* 64E4 80015CE4 540080AC */  sw         $zero, 0x54($a0)
    /* 64E8 80015CE8 D20080A4 */  sh         $zero, 0xD2($a0)
    /* 64EC 80015CEC D00080A4 */  sh         $zero, 0xD0($a0)
    /* 64F0 80015CF0 340080AC */  sw         $zero, 0x34($a0)
    /* 64F4 80015CF4 F00080A4 */  sh         $zero, 0xF0($a0)
    /* 64F8 80015CF8 9C0080A4 */  sh         $zero, 0x9C($a0)
    /* 64FC 80015CFC 700082A4 */  sh         $v0, 0x70($a0)
    /* 6500 80015D00 0A0180A4 */  sh         $zero, 0x10A($a0)
    /* 6504 80015D04 C60080A4 */  sh         $zero, 0xC6($a0)
    /* 6508 80015D08 BA0080A4 */  sh         $zero, 0xBA($a0)
    /* 650C 80015D0C AA0080A4 */  sh         $zero, 0xAA($a0)
    /* 6510 80015D10 C80080A4 */  sh         $zero, 0xC8($a0)
    /* 6514 80015D14 BC0080A4 */  sh         $zero, 0xBC($a0)
    /* 6518 80015D18 AC0080A4 */  sh         $zero, 0xAC($a0)
    /* 651C 80015D1C CE0080A4 */  sh         $zero, 0xCE($a0)
    /* 6520 80015D20 256C000C */  jal        func_8001B094
    /* 6524 80015D24 CC0080A4 */   sh        $zero, 0xCC($a0)
    /* 6528 80015D28 1000BF8F */  lw         $ra, 0x10($sp)
    /* 652C 80015D2C 00000000 */  nop
    /* 6530 80015D30 0800E003 */  jr         $ra
    /* 6534 80015D34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015C9C
