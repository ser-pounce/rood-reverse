nonmatching func_80102988, 0xB4

glabel func_80102988
    /* 188 80102988 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 18C 8010298C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 190 80102990 2180A000 */  addu       $s0, $a1, $zero
    /* 194 80102994 0680023C */  lui        $v0, %hi(vs_main_buttonsState)
    /* 198 80102998 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 19C 8010299C 0C000324 */  addiu      $v1, $zero, 0xC
    /* 1A0 801029A0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1A4 801029A4 0C004230 */  andi       $v0, $v0, 0xC
    /* 1A8 801029A8 1E004310 */  beq        $v0, $v1, .L80102A24
    /* 1AC 801029AC 1400B1AF */   sw        $s1, 0x14($sp)
    /* 1B0 801029B0 21880002 */  addu       $s1, $s0, $zero
    /* 1B4 801029B4 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 1B8 801029B8 21280000 */   addu      $a1, $zero, $zero
    /* 1BC 801029BC 21284000 */  addu       $a1, $v0, $zero
    /* 1C0 801029C0 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 1C4 801029C4 DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 1C8 801029C8 00000000 */  nop
    /* 1CC 801029CC 04006230 */  andi       $v0, $v1, 0x4
    /* 1D0 801029D0 03004010 */  beqz       $v0, .L801029E0
    /* 1D4 801029D4 2120A000 */   addu      $a0, $a1, $zero
    /* 1D8 801029D8 FFFF0226 */  addiu      $v0, $s0, -0x1
    /* 1DC 801029DC 21804500 */  addu       $s0, $v0, $a1
  .L801029E0:
    /* 1E0 801029E0 08006230 */  andi       $v0, $v1, 0x8
    /* 1E4 801029E4 03004010 */  beqz       $v0, .L801029F4
    /* 1E8 801029E8 2A100402 */   slt       $v0, $s0, $a0
    /* 1EC 801029EC 01001026 */  addiu      $s0, $s0, 0x1
    /* 1F0 801029F0 2A100402 */  slt        $v0, $s0, $a0
  .L801029F4:
    /* 1F4 801029F4 02004014 */  bnez       $v0, .L80102A00
    /* 1F8 801029F8 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 1FC 801029FC 23800402 */  subu       $s0, $s0, $a0
  .L80102A00:
    /* 200 80102A00 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 204 80102A04 00000000 */  nop
    /* 208 80102A08 0C004230 */  andi       $v0, $v0, 0xC
    /* 20C 80102A0C 06004010 */  beqz       $v0, .L80102A28
    /* 210 80102A10 21100002 */   addu      $v0, $s0, $zero
    /* 214 80102A14 04001116 */  bne        $s0, $s1, .L80102A28
    /* 218 80102A18 00000000 */   nop
    /* 21C 80102A1C B800030C */  jal        vs_battle_playInvalidSfx
    /* 220 80102A20 00000000 */   nop
  .L80102A24:
    /* 224 80102A24 21100002 */  addu       $v0, $s0, $zero
  .L80102A28:
    /* 228 80102A28 1800BF8F */  lw         $ra, 0x18($sp)
    /* 22C 80102A2C 1400B18F */  lw         $s1, 0x14($sp)
    /* 230 80102A30 1000B08F */  lw         $s0, 0x10($sp)
    /* 234 80102A34 0800E003 */  jr         $ra
    /* 238 80102A38 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102988
