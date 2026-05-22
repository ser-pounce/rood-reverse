nonmatching _setMPCost, 0x134

glabel _setMPCost
    /* 84 80102884 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 88 80102888 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8C 8010288C 21808000 */  addu       $s0, $a0, $zero
    /* 90 80102890 1800B2AF */  sw         $s2, 0x18($sp)
    /* 94 80102894 21900000 */  addu       $s2, $zero, $zero
    /* 98 80102898 2400BFAF */  sw         $ra, 0x24($sp)
    /* 9C 8010289C 2000B4AF */  sw         $s4, 0x20($sp)
    /* A0 801028A0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* A4 801028A4 03000106 */  bgez       $s0, .L801028B4
    /* A8 801028A8 1400B1AF */   sw        $s1, 0x14($sp)
    /* AC 801028AC 01001224 */  addiu      $s2, $zero, 0x1
    /* B0 801028B0 23801000 */  negu       $s0, $s0
  .L801028B4:
    /* B4 801028B4 21200000 */  addu       $a0, $zero, $zero
    /* B8 801028B8 7429020C */  jal        vs_battle_getSkillFlags
    /* BC 801028BC 21280002 */   addu      $a1, $s0, $zero
    /* C0 801028C0 01000424 */  addiu      $a0, $zero, 0x1
    /* C4 801028C4 1080053C */  lui        $a1, %hi(D_80102800)
    /* C8 801028C8 0028A524 */  addiu      $a1, $a1, %lo(D_80102800)
    /* CC 801028CC 08000624 */  addiu      $a2, $zero, 0x8
    /* D0 801028D0 21A04000 */  addu       $s4, $v0, $zero
    /* D4 801028D4 07389400 */  srav       $a3, $s4, $a0
    /* D8 801028D8 4000040C */  jal        vs_mainmenu_setAbilityCost
    /* DC 801028DC 2438E400 */   and       $a3, $a3, $a0
    /* E0 801028E0 0F001124 */  addiu      $s1, $zero, 0xF
    /* E4 801028E4 0580033C */  lui        $v1, %hi(vs_main_skills)
    /* E8 801028E8 DCB96324 */  addiu      $v1, $v1, %lo(vs_main_skills)
    /* EC 801028EC 40101000 */  sll        $v0, $s0, 1
    /* F0 801028F0 21105000 */  addu       $v0, $v0, $s0
    /* F4 801028F4 80100200 */  sll        $v0, $v0, 2
    /* F8 801028F8 21105000 */  addu       $v0, $v0, $s0
    /* FC 801028FC 80100200 */  sll        $v0, $v0, 2
    /* 100 80102900 21104300 */  addu       $v0, $v0, $v1
    /* 104 80102904 03004490 */  lbu        $a0, 0x3($v0)
    /* 108 80102908 1080023C */  lui        $v0, %hi(_MPCostTextBuffer)
    /* 10C 8010290C 18694324 */  addiu      $v1, $v0, %lo(_MPCostTextBuffer)
    /* 110 80102910 06004012 */  beqz       $s2, .L8010292C
    /* 114 80102914 0F0060A0 */   sb        $zero, 0xF($v1)
    /* 118 80102918 0D001124 */  addiu      $s1, $zero, 0xD
    /* 11C 8010291C 2D000224 */  addiu      $v0, $zero, 0x2D
    /* 120 80102920 0E0062A0 */  sb         $v0, 0xE($v1)
    /* 124 80102924 5B000224 */  addiu      $v0, $zero, 0x5B
    /* 128 80102928 0D0062A0 */  sb         $v0, 0xD($v1)
  .L8010292C:
    /* 12C 8010292C 5B001324 */  addiu      $s3, $zero, 0x5B
    /* 130 80102930 21802302 */  addu       $s0, $s1, $v1
  .L80102934:
    /* 134 80102934 1533030C */  jal        vs_battle_toBCD
    /* 138 80102938 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 13C 8010293C 21204000 */  addu       $a0, $v0, $zero
    /* 140 80102940 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 144 80102944 0F008230 */  andi       $v0, $a0, 0xF
    /* 148 80102948 30004224 */  addiu      $v0, $v0, 0x30
    /* 14C 8010294C 000002A2 */  sb         $v0, 0x0($s0)
    /* 150 80102950 04004012 */  beqz       $s2, .L80102964
    /* 154 80102954 03210400 */   sra       $a0, $a0, 4
    /* 158 80102958 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 15C 8010295C FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 160 80102960 000013A2 */  sb         $s3, 0x0($s0)
  .L80102964:
    /* 164 80102964 F3FF8014 */  bnez       $a0, .L80102934
    /* 168 80102968 1080053C */   lui       $a1, %hi(_MPCostTextBuffer)
    /* 16C 8010296C FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 170 80102970 1869A524 */  addiu      $a1, $a1, %lo(_MPCostTextBuffer)
    /* 174 80102974 21282502 */  addu       $a1, $s1, $a1
    /* 178 80102978 23000224 */  addiu      $v0, $zero, 0x23
    /* 17C 8010297C 21200000 */  addu       $a0, $zero, $zero
    /* 180 80102980 80301200 */  sll        $a2, $s2, 2
    /* 184 80102984 4800C634 */  ori        $a2, $a2, 0x48
    /* 188 80102988 43381400 */  sra        $a3, $s4, 1
    /* 18C 8010298C 0100E730 */  andi       $a3, $a3, 0x1
    /* 190 80102990 4000040C */  jal        vs_mainmenu_setAbilityCost
    /* 194 80102994 0000A2A0 */   sb        $v0, 0x0($a1)
    /* 198 80102998 2400BF8F */  lw         $ra, 0x24($sp)
    /* 19C 8010299C 2000B48F */  lw         $s4, 0x20($sp)
    /* 1A0 801029A0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1A4 801029A4 1800B28F */  lw         $s2, 0x18($sp)
    /* 1A8 801029A8 1400B18F */  lw         $s1, 0x14($sp)
    /* 1AC 801029AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B0 801029B0 0800E003 */  jr         $ra
    /* 1B4 801029B4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _setMPCost
