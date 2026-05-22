nonmatching _setArtCost, 0xE4

glabel _setArtCost
    /* 30 80102830 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 34 80102834 1000B0AF */  sw         $s0, 0x10($sp)
    /* 38 80102838 21808000 */  addu       $s0, $a0, $zero
    /* 3C 8010283C 21200000 */  addu       $a0, $zero, $zero
    /* 40 80102840 21280002 */  addu       $a1, $s0, $zero
    /* 44 80102844 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 48 80102848 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4C 8010284C 7429020C */  jal        vs_battle_getSkillFlags
    /* 50 80102850 1400B1AF */   sw        $s1, 0x14($sp)
    /* 54 80102854 01000424 */  addiu      $a0, $zero, 0x1
    /* 58 80102858 1080053C */  lui        $a1, %hi(D_80102800)
    /* 5C 8010285C 0028A524 */  addiu      $a1, $a1, %lo(D_80102800)
    /* 60 80102860 08000624 */  addiu      $a2, $zero, 0x8
    /* 64 80102864 21904000 */  addu       $s2, $v0, $zero
    /* 68 80102868 07389200 */  srav       $a3, $s2, $a0
    /* 6C 8010286C 4000040C */  jal        vs_mainmenu_setAbilityCost
    /* 70 80102870 2438E400 */   and       $a3, $a3, $a0
    /* 74 80102874 0F001124 */  addiu      $s1, $zero, 0xF
    /* 78 80102878 0580033C */  lui        $v1, %hi(vs_main_skills)
    /* 7C 8010287C DCB96324 */  addiu      $v1, $v1, %lo(vs_main_skills)
    /* 80 80102880 40101000 */  sll        $v0, $s0, 1
    /* 84 80102884 21105000 */  addu       $v0, $v0, $s0
    /* 88 80102888 80100200 */  sll        $v0, $v0, 2
    /* 8C 8010288C 21105000 */  addu       $v0, $v0, $s0
    /* 90 80102890 80100200 */  sll        $v0, $v0, 2
    /* 94 80102894 21104300 */  addu       $v0, $v0, $v1
    /* 98 80102898 03004490 */  lbu        $a0, 0x3($v0)
    /* 9C 8010289C 1080023C */  lui        $v0, %hi(_digitBuffer)
    /* A0 801028A0 1C454224 */  addiu      $v0, $v0, %lo(_digitBuffer)
    /* A4 801028A4 21804000 */  addu       $s0, $v0, $zero
    /* A8 801028A8 0F0000A2 */  sb         $zero, 0xF($s0)
  .L801028AC:
    /* AC 801028AC 1533030C */  jal        vs_battle_toBCD
    /* B0 801028B0 FFFF3126 */   addiu     $s1, $s1, -0x1
    /* B4 801028B4 21204000 */  addu       $a0, $v0, $zero
    /* B8 801028B8 21183002 */  addu       $v1, $s1, $s0
    /* BC 801028BC 0F008230 */  andi       $v0, $a0, 0xF
    /* C0 801028C0 30004224 */  addiu      $v0, $v0, 0x30
    /* C4 801028C4 03210400 */  sra        $a0, $a0, 4
    /* C8 801028C8 F8FF8014 */  bnez       $a0, .L801028AC
    /* CC 801028CC 000062A0 */   sb        $v0, 0x0($v1)
    /* D0 801028D0 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* D4 801028D4 1080053C */  lui        $a1, %hi(_digitBuffer)
    /* D8 801028D8 1C45A524 */  addiu      $a1, $a1, %lo(_digitBuffer)
    /* DC 801028DC 21282502 */  addu       $a1, $s1, $a1
    /* E0 801028E0 23000224 */  addiu      $v0, $zero, 0x23
    /* E4 801028E4 21200000 */  addu       $a0, $zero, $zero
    /* E8 801028E8 48000624 */  addiu      $a2, $zero, 0x48
    /* EC 801028EC 43381200 */  sra        $a3, $s2, 1
    /* F0 801028F0 0100E730 */  andi       $a3, $a3, 0x1
    /* F4 801028F4 4000040C */  jal        vs_mainmenu_setAbilityCost
    /* F8 801028F8 0000A2A0 */   sb        $v0, 0x0($a1)
    /* FC 801028FC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 100 80102900 1800B28F */  lw         $s2, 0x18($sp)
    /* 104 80102904 1400B18F */  lw         $s1, 0x14($sp)
    /* 108 80102908 1000B08F */  lw         $s0, 0x10($sp)
    /* 10C 8010290C 0800E003 */  jr         $ra
    /* 110 80102910 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _setArtCost
