nonmatching func_801029D0, 0x64

glabel func_801029D0
    /* 1D0 801029D0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1D4 801029D4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1D8 801029D8 02008010 */  beqz       $a0, .L801029E4
    /* 1DC 801029DC 12000624 */   addiu     $a2, $zero, 0x12
    /* 1E0 801029E0 22000624 */  addiu      $a2, $zero, 0x22
  .L801029E4:
    /* 1E4 801029E4 08000224 */  addiu      $v0, $zero, 0x8
    /* 1E8 801029E8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1EC 801029EC 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 1F0 801029F0 40180500 */  sll        $v1, $a1, 1
    /* 1F4 801029F4 40010524 */  addiu      $a1, $zero, 0x140
    /* 1F8 801029F8 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 1FC 801029FC 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 200 80102A00 21104300 */  addu       $v0, $v0, $v1
    /* 204 80102A04 9723030C */  jal        vs_battle_setMenuItem
    /* 208 80102A08 1400A2AF */   sw        $v0, 0x14($sp)
    /* 20C 80102A0C 02000324 */  addiu      $v1, $zero, 0x2
    /* 210 80102A10 000043A0 */  sb         $v1, 0x0($v0)
    /* 214 80102A14 B4000324 */  addiu      $v1, $zero, 0xB4
    /* 218 80102A18 180043A4 */  sh         $v1, 0x18($v0)
    /* 21C 80102A1C 01000324 */  addiu      $v1, $zero, 0x1
    /* 220 80102A20 060043A0 */  sb         $v1, 0x6($v0)
    /* 224 80102A24 1800BF8F */  lw         $ra, 0x18($sp)
    /* 228 80102A28 00000000 */  nop
    /* 22C 80102A2C 0800E003 */  jr         $ra
    /* 230 80102A30 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_801029D0
