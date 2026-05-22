nonmatching func_800199C4, 0x94

glabel func_800199C4
    /* A1C4 800199C4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* A1C8 800199C8 21308000 */  addu       $a2, $a0, $zero
    /* A1CC 800199CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* A1D0 800199D0 0380113C */  lui        $s1, %hi(g_Sound_MasterFadeTimer)
    /* A1D4 800199D4 38782426 */  addiu      $a0, $s1, %lo(g_Sound_MasterFadeTimer)
    /* A1D8 800199D8 1800BFAF */  sw         $ra, 0x18($sp)
    /* A1DC 800199DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* A1E0 800199E0 0800828C */  lw         $v0, 0x8($a0)
    /* A1E4 800199E4 00000000 */  nop
    /* A1E8 800199E8 16004010 */  beqz       $v0, .L80019A44
    /* A1EC 800199EC FFFF4224 */   addiu     $v0, $v0, -0x1
    /* A1F0 800199F0 08004014 */  bnez       $v0, .L80019A14
    /* A1F4 800199F4 080082AC */   sw        $v0, 0x8($a0)
    /* A1F8 800199F8 0400C28C */  lw         $v0, 0x4($a2)
    /* A1FC 800199FC 6E00C0A4 */  sh         $zero, 0x6E($a2)
    /* A200 80019A00 0400C0AC */  sw         $zero, 0x4($a2)
    /* A204 80019A04 1000C0AC */  sw         $zero, 0x10($a2)
    /* A208 80019A08 1400C0AC */  sw         $zero, 0x14($a2)
    /* A20C 80019A0C 91660008 */  j          .L80019A44
    /* A210 80019A10 1800C2AC */   sw        $v0, 0x18($a2)
  .L80019A14:
    /* A214 80019A14 3878238E */  lw         $v1, %lo(g_Sound_MasterFadeTimer)($s1)
    /* A218 80019A18 0400828C */  lw         $v0, 0x4($a0)
    /* A21C 80019A1C 00000000 */  nop
    /* A220 80019A20 21806200 */  addu       $s0, $v1, $v0
    /* A224 80019A24 FFFF023C */  lui        $v0, (0xFFFF0000 >> 16)
    /* A228 80019A28 24200202 */  and        $a0, $s0, $v0
    /* A22C 80019A2C 24186200 */  and        $v1, $v1, $v0
    /* A230 80019A30 03008310 */  beq        $a0, $v1, .L80019A40
    /* A234 80019A34 00000000 */   nop
    /* A238 80019A38 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* A23C 80019A3C 2120C000 */   addu      $a0, $a2, $zero
  .L80019A40:
    /* A240 80019A40 387830AE */  sw         $s0, %lo(g_Sound_MasterFadeTimer)($s1)
  .L80019A44:
    /* A244 80019A44 1800BF8F */  lw         $ra, 0x18($sp)
    /* A248 80019A48 1400B18F */  lw         $s1, 0x14($sp)
    /* A24C 80019A4C 1000B08F */  lw         $s0, 0x10($sp)
    /* A250 80019A50 0800E003 */  jr         $ra
    /* A254 80019A54 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800199C4
