nonmatching _setMPCostDirect, 0xB0

glabel _setMPCostDirect
    /* 1B8 801029B8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1BC 801029BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C0 801029C0 21808000 */  addu       $s0, $a0, $zero
    /* 1C4 801029C4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1C8 801029C8 2190A000 */  addu       $s2, $a1, $zero
    /* 1CC 801029CC 01000424 */  addiu      $a0, $zero, 0x1
    /* 1D0 801029D0 1080053C */  lui        $a1, %hi(D_80102800)
    /* 1D4 801029D4 0028A524 */  addiu      $a1, $a1, %lo(D_80102800)
    /* 1D8 801029D8 08000624 */  addiu      $a2, $zero, 0x8
    /* 1DC 801029DC 21384002 */  addu       $a3, $s2, $zero
    /* 1E0 801029E0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1E4 801029E4 4000040C */  jal        vs_mainmenu_setAbilityCost
    /* 1E8 801029E8 1400B1AF */   sw        $s1, 0x14($sp)
    /* 1EC 801029EC 21200002 */  addu       $a0, $s0, $zero
    /* 1F0 801029F0 0F001024 */  addiu      $s0, $zero, 0xF
    /* 1F4 801029F4 1080023C */  lui        $v0, %hi(_MPCostDirectTextBuffer)
    /* 1F8 801029F8 28694224 */  addiu      $v0, $v0, %lo(_MPCostDirectTextBuffer)
    /* 1FC 801029FC 21884000 */  addu       $s1, $v0, $zero
    /* 200 80102A00 0F0040A0 */  sb         $zero, 0xF($v0)
  .L80102A04:
    /* 204 80102A04 1533030C */  jal        vs_battle_toBCD
    /* 208 80102A08 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 20C 80102A0C 21204000 */  addu       $a0, $v0, $zero
    /* 210 80102A10 21181102 */  addu       $v1, $s0, $s1
    /* 214 80102A14 0F008230 */  andi       $v0, $a0, 0xF
    /* 218 80102A18 30004224 */  addiu      $v0, $v0, 0x30
    /* 21C 80102A1C 03210400 */  sra        $a0, $a0, 4
    /* 220 80102A20 F8FF8014 */  bnez       $a0, .L80102A04
    /* 224 80102A24 000062A0 */   sb        $v0, 0x0($v1)
    /* 228 80102A28 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 22C 80102A2C 1080053C */  lui        $a1, %hi(_MPCostDirectTextBuffer)
    /* 230 80102A30 2869A524 */  addiu      $a1, $a1, %lo(_MPCostDirectTextBuffer)
    /* 234 80102A34 21280502 */  addu       $a1, $s0, $a1
    /* 238 80102A38 23000224 */  addiu      $v0, $zero, 0x23
    /* 23C 80102A3C 21200000 */  addu       $a0, $zero, $zero
    /* 240 80102A40 48000624 */  addiu      $a2, $zero, 0x48
    /* 244 80102A44 21384002 */  addu       $a3, $s2, $zero
    /* 248 80102A48 4000040C */  jal        vs_mainmenu_setAbilityCost
    /* 24C 80102A4C 0000A2A0 */   sb        $v0, 0x0($a1)
    /* 250 80102A50 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 254 80102A54 1800B28F */  lw         $s2, 0x18($sp)
    /* 258 80102A58 1400B18F */  lw         $s1, 0x14($sp)
    /* 25C 80102A5C 1000B08F */  lw         $s0, 0x10($sp)
    /* 260 80102A60 0800E003 */  jr         $ra
    /* 264 80102A64 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _setMPCostDirect
