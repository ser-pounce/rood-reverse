nonmatching func_801031A0, 0xD0

glabel func_801031A0
    /* 9A0 801031A0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 9A4 801031A4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 9A8 801031A8 1080113C */  lui        $s1, %hi(vs_menu_inventoryStorage)
    /* 9AC 801031AC 5C24228E */  lw         $v0, %lo(vs_menu_inventoryStorage)($s1)
    /* 9B0 801031B0 00040624 */  addiu      $a2, $zero, 0x400
    /* 9B4 801031B4 2400BFAF */  sw         $ra, 0x24($sp)
    /* 9B8 801031B8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 9BC 801031BC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 9C0 801031C0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 9C4 801031C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9C8 801031C8 B04B5224 */  addiu      $s2, $v0, 0x4BB0
    /* 9CC 801031CC 1180023C */  lui        $v0, %hi(D_80109A88)
    /* 9D0 801031D0 889A458C */  lw         $a1, %lo(D_80109A88)($v0)
    /* 9D4 801031D4 00384426 */  addiu      $a0, $s2, 0x3800
    /* 9D8 801031D8 7800030C */  jal        vs_battle_memcpy
    /* 9DC 801031DC 0038A524 */   addiu     $a1, $a1, 0x3800
    /* 9E0 801031E0 5C24228E */  lw         $v0, %lo(vs_menu_inventoryStorage)($s1)
    /* 9E4 801031E4 00800334 */  ori        $v1, $zero, 0x8000
    /* 9E8 801031E8 21104300 */  addu       $v0, $v0, $v1
    /* 9EC 801031EC B0434694 */  lhu        $a2, 0x43B0($v0)
    /* 9F0 801031F0 00000000 */  nop
    /* 9F4 801031F4 1600C010 */  beqz       $a2, .L80103250
    /* 9F8 801031F8 21800000 */   addu      $s0, $zero, $zero
    /* 9FC 801031FC 06001424 */  addiu      $s4, $zero, 0x6
    /* A00 80103200 B0871334 */  ori        $s3, $zero, 0x87B0
    /* A04 80103204 03120600 */  sra        $v0, $a2, 8
  .L80103208:
    /* A08 80103208 07005414 */  bne        $v0, $s4, .L80103228
    /* A0C 8010320C 16000424 */   addiu     $a0, $zero, 0x16
    /* A10 80103210 21284002 */  addu       $a1, $s2, $zero
    /* A14 80103214 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* A18 80103218 5C24278E */  lw         $a3, %lo(vs_menu_inventoryStorage)($s1)
    /* A1C 8010321C FF00C630 */  andi       $a2, $a2, 0xFF
    /* A20 80103220 AB0C040C */  jal        _copyContainerItem
    /* A24 80103224 2138F300 */   addu      $a3, $a3, $s3
  .L80103228:
    /* A28 80103228 01001026 */  addiu      $s0, $s0, 0x1
    /* A2C 8010322C 5C24228E */  lw         $v0, %lo(vs_menu_inventoryStorage)($s1)
    /* A30 80103230 40181000 */  sll        $v1, $s0, 1
    /* A34 80103234 21104300 */  addu       $v0, $v0, $v1
    /* A38 80103238 00800334 */  ori        $v1, $zero, 0x8000
    /* A3C 8010323C 21104300 */  addu       $v0, $v0, $v1
    /* A40 80103240 B0434694 */  lhu        $a2, 0x43B0($v0)
    /* A44 80103244 00000000 */  nop
    /* A48 80103248 EFFFC014 */  bnez       $a2, .L80103208
    /* A4C 8010324C 03120600 */   sra       $v0, $a2, 8
  .L80103250:
    /* A50 80103250 2400BF8F */  lw         $ra, 0x24($sp)
    /* A54 80103254 2000B48F */  lw         $s4, 0x20($sp)
    /* A58 80103258 1C00B38F */  lw         $s3, 0x1C($sp)
    /* A5C 8010325C 1800B28F */  lw         $s2, 0x18($sp)
    /* A60 80103260 1400B18F */  lw         $s1, 0x14($sp)
    /* A64 80103264 1000B08F */  lw         $s0, 0x10($sp)
    /* A68 80103268 0800E003 */  jr         $ra
    /* A6C 8010326C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_801031A0
