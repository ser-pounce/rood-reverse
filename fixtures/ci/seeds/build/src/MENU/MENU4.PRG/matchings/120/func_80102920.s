nonmatching func_80102920, 0x144

glabel func_80102920
    /* 120 80102920 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 124 80102924 1400B1AF */  sw         $s1, 0x14($sp)
    /* 128 80102928 21888000 */  addu       $s1, $a0, $zero
    /* 12C 8010292C 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 130 80102930 01000324 */  addiu      $v1, $zero, 0x1
    /* 134 80102934 1800BFAF */  sw         $ra, 0x18($sp)
    /* 138 80102938 1000B0AF */  sw         $s0, 0x10($sp)
    /* 13C 8010293C 88F4030C */  jal        vs_mainMenu_resetStats
    /* 140 80102940 452543A0 */   sb        $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 144 80102944 21200000 */  addu       $a0, $zero, $zero
    /* 148 80102948 21288000 */  addu       $a1, $a0, $zero
    /* 14C 8010294C 21308000 */  addu       $a2, $a0, $zero
    /* 150 80102950 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 154 80102954 01000724 */   addiu     $a3, $zero, 0x1
    /* 158 80102958 18002296 */  lhu        $v0, 0x18($s1)
    /* 15C 8010295C 00000000 */  nop
    /* 160 80102960 39004010 */  beqz       $v0, .L80102A48
    /* 164 80102964 1080103C */   lui       $s0, %hi(vs_mainMenu_equipmentStats)
    /* 168 80102968 C0241026 */  addiu      $s0, $s0, %lo(vs_mainMenu_equipmentStats)
    /* 16C 8010296C 21200002 */  addu       $a0, $s0, $zero
    /* 170 80102970 28012526 */  addiu      $a1, $s1, 0x128
    /* 174 80102974 7800030C */  jal        vs_battle_memcpy
    /* 178 80102978 40000624 */   addiu     $a2, $zero, 0x40
    /* 17C 8010297C 60000426 */  addiu      $a0, $s0, 0x60
    /* 180 80102980 78012526 */  addiu      $a1, $s1, 0x178
    /* 184 80102984 7800030C */  jal        vs_battle_memcpy
    /* 188 80102988 20000624 */   addiu     $a2, $zero, 0x20
    /* 18C 8010298C 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 190 80102990 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 194 80102994 21200000 */  addu       $a0, $zero, $zero
    /* 198 80102998 3C00428C */  lw         $v0, 0x3C($v0)
    /* 19C 8010299C 40000524 */  addiu      $a1, $zero, 0x40
    /* 1A0 801029A0 3C004224 */  addiu      $v0, $v0, 0x3C
    /* 1A4 801029A4 26102202 */  xor        $v0, $s1, $v0
    /* 1A8 801029A8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 1AC 801029AC 7E0002A6 */  sh         $v0, 0x7E($s0)
  .L801029B0:
    /* 1B0 801029B0 2118B000 */  addu       $v1, $a1, $s0
    /* 1B4 801029B4 21102402 */  addu       $v0, $s1, $a0
    /* 1B8 801029B8 64004290 */  lbu        $v0, 0x64($v0)
    /* 1BC 801029BC 01008424 */  addiu      $a0, $a0, 0x1
    /* 1C0 801029C0 00160200 */  sll        $v0, $v0, 24
    /* 1C4 801029C4 03160200 */  sra        $v0, $v0, 24
    /* 1C8 801029C8 000062A4 */  sh         $v0, 0x0($v1)
    /* 1CC 801029CC 04008228 */  slti       $v0, $a0, 0x4
    /* 1D0 801029D0 F7FF4014 */  bnez       $v0, .L801029B0
    /* 1D4 801029D4 0200A524 */   addiu     $a1, $a1, 0x2
    /* 1D8 801029D8 0E012392 */  lbu        $v1, 0x10E($s1)
    /* 1DC 801029DC 1080023C */  lui        $v0, %hi(D_80102508)
    /* 1E0 801029E0 082543A4 */  sh         $v1, %lo(D_80102508)($v0)
    /* 1E4 801029E4 14012496 */  lhu        $a0, 0x114($s1)
    /* 1E8 801029E8 16012596 */  lhu        $a1, 0x116($s1)
    /* 1EC 801029EC 10012696 */  lhu        $a2, 0x110($s1)
    /* 1F0 801029F0 12012796 */  lhu        $a3, 0x112($s1)
    /* 1F4 801029F4 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 1F8 801029F8 00000000 */   nop
    /* 1FC 801029FC 18012486 */  lh         $a0, 0x118($s1)
    /* 200 80102A00 1C012586 */  lh         $a1, 0x11C($s1)
    /* 204 80102A04 20012686 */  lh         $a2, 0x120($s1)
    /* 208 80102A08 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 20C 80102A0C 01000724 */   addiu     $a3, $zero, 0x1
    /* 210 80102A10 1080033C */  lui        $v1, %hi(vs_mainMenu_strIntAgi)
    /* 214 80102A14 1A012296 */  lhu        $v0, 0x11A($s1)
    /* 218 80102A18 A8246324 */  addiu      $v1, $v1, %lo(vs_mainMenu_strIntAgi)
    /* 21C 80102A1C 080062A4 */  sh         $v0, 0x8($v1)
    /* 220 80102A20 1E012296 */  lhu        $v0, 0x11E($s1)
    /* 224 80102A24 00000000 */  nop
    /* 228 80102A28 0A0062A4 */  sh         $v0, 0xA($v1)
    /* 22C 80102A2C 22012296 */  lhu        $v0, 0x122($s1)
    /* 230 80102A30 21300000 */  addu       $a2, $zero, $zero
    /* 234 80102A34 0C0062A4 */  sh         $v0, 0xC($v1)
    /* 238 80102A38 24012492 */  lbu        $a0, 0x124($s1)
    /* 23C 80102A3C 0A012592 */  lbu        $a1, 0x10A($s1)
    /* 240 80102A40 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 244 80102A44 01000724 */   addiu     $a3, $zero, 0x1
  .L80102A48:
    /* 248 80102A48 E3EE030C */  jal        func_800FBB8C
    /* 24C 80102A4C 07000424 */   addiu     $a0, $zero, 0x7
    /* 250 80102A50 1800BF8F */  lw         $ra, 0x18($sp)
    /* 254 80102A54 1400B18F */  lw         $s1, 0x14($sp)
    /* 258 80102A58 1000B08F */  lw         $s0, 0x10($sp)
    /* 25C 80102A5C 0800E003 */  jr         $ra
    /* 260 80102A60 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102920
