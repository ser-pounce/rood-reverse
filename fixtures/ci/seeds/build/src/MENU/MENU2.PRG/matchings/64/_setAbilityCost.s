nonmatching _setAbilityCost, 0xC4

glabel _setAbilityCost
    /* 64 80102864 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 68 80102868 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C 8010286C 21808000 */  addu       $s0, $a0, $zero
    /* 70 80102870 01000424 */  addiu      $a0, $zero, 0x1
    /* 74 80102874 1080053C */  lui        $a1, %hi(D_80102800)
    /* 78 80102878 0028A524 */  addiu      $a1, $a1, %lo(D_80102800)
    /* 7C 8010287C 08000624 */  addiu      $a2, $zero, 0x8
    /* 80 80102880 21380000 */  addu       $a3, $zero, $zero
    /* 84 80102884 1800BFAF */  sw         $ra, 0x18($sp)
    /* 88 80102888 4000040C */  jal        vs_mainmenu_setAbilityCost
    /* 8C 8010288C 1400B1AF */   sw        $s1, 0x14($sp)
    /* 90 80102890 0F001124 */  addiu      $s1, $zero, 0xF
    /* 94 80102894 0580033C */  lui        $v1, %hi(vs_main_skills)
    /* 98 80102898 DCB96324 */  addiu      $v1, $v1, %lo(vs_main_skills)
    /* 9C 8010289C 40101000 */  sll        $v0, $s0, 1
    /* A0 801028A0 21105000 */  addu       $v0, $v0, $s0
    /* A4 801028A4 80100200 */  sll        $v0, $v0, 2
    /* A8 801028A8 21105000 */  addu       $v0, $v0, $s0
    /* AC 801028AC 80100200 */  sll        $v0, $v0, 2
    /* B0 801028B0 21104300 */  addu       $v0, $v0, $v1
    /* B4 801028B4 03004490 */  lbu        $a0, 0x3($v0)
    /* B8 801028B8 1080023C */  lui        $v0, %hi(_stringBuffer)
    /* BC 801028BC B0504224 */  addiu      $v0, $v0, %lo(_stringBuffer)
    /* C0 801028C0 21804000 */  addu       $s0, $v0, $zero
    /* C4 801028C4 0F0000A2 */  sb         $zero, 0xF($s0)
  .L801028C8:
    /* C8 801028C8 1533030C */  jal        vs_battle_toBCD
    /* CC 801028CC FFFF3126 */   addiu     $s1, $s1, -0x1
    /* D0 801028D0 21204000 */  addu       $a0, $v0, $zero
    /* D4 801028D4 21183002 */  addu       $v1, $s1, $s0
    /* D8 801028D8 0F008230 */  andi       $v0, $a0, 0xF
    /* DC 801028DC 30004224 */  addiu      $v0, $v0, 0x30
    /* E0 801028E0 03210400 */  sra        $a0, $a0, 4
    /* E4 801028E4 F8FF8014 */  bnez       $a0, .L801028C8
    /* E8 801028E8 000062A0 */   sb        $v0, 0x0($v1)
    /* EC 801028EC FFFF3126 */  addiu      $s1, $s1, -0x1
    /* F0 801028F0 1080053C */  lui        $a1, %hi(_stringBuffer)
    /* F4 801028F4 B050A524 */  addiu      $a1, $a1, %lo(_stringBuffer)
    /* F8 801028F8 21282502 */  addu       $a1, $s1, $a1
    /* FC 801028FC 23000224 */  addiu      $v0, $zero, 0x23
    /* 100 80102900 21200000 */  addu       $a0, $zero, $zero
    /* 104 80102904 48000624 */  addiu      $a2, $zero, 0x48
    /* 108 80102908 21388000 */  addu       $a3, $a0, $zero
    /* 10C 8010290C 4000040C */  jal        vs_mainmenu_setAbilityCost
    /* 110 80102910 0000A2A0 */   sb        $v0, 0x0($a1)
    /* 114 80102914 1800BF8F */  lw         $ra, 0x18($sp)
    /* 118 80102918 1400B18F */  lw         $s1, 0x14($sp)
    /* 11C 8010291C 1000B08F */  lw         $s0, 0x10($sp)
    /* 120 80102920 0800E003 */  jr         $ra
    /* 124 80102924 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _setAbilityCost
