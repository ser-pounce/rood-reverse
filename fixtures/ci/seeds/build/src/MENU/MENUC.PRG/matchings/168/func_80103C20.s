nonmatching func_80103C20, 0xCC

glabel func_80103C20
    /* 1420 80103C20 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1424 80103C24 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1428 80103C28 21888000 */  addu       $s1, $a0, $zero
    /* 142C 80103C2C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1430 80103C30 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1434 80103C34 88F4030C */  jal        vs_mainMenu_resetStats
    /* 1438 80103C38 2180A000 */   addu      $s0, $a1, $zero
    /* 143C 80103C3C 21200000 */  addu       $a0, $zero, $zero
    /* 1440 80103C40 21288000 */  addu       $a1, $a0, $zero
    /* 1444 80103C44 21308000 */  addu       $a2, $a0, $zero
    /* 1448 80103C48 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 144C 80103C4C 01000724 */   addiu     $a3, $zero, 0x1
    /* 1450 80103C50 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 1454 80103C54 2B181100 */  sltu       $v1, $zero, $s1
    /* 1458 80103C58 02000012 */  beqz       $s0, .L80103C64
    /* 145C 80103C5C 452540A0 */   sb        $zero, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 1460 80103C60 02006324 */  addiu      $v1, $v1, 0x2
  .L80103C64:
    /* 1464 80103C64 02000224 */  addiu      $v0, $zero, 0x2
    /* 1468 80103C68 10006210 */  beq        $v1, $v0, .L80103CAC
    /* 146C 80103C6C 03006228 */   slti      $v0, $v1, 0x3
    /* 1470 80103C70 05004010 */  beqz       $v0, .L80103C88
    /* 1474 80103C74 01000224 */   addiu     $v0, $zero, 0x1
    /* 1478 80103C78 08006210 */  beq        $v1, $v0, .L80103C9C
    /* 147C 80103C7C 00000000 */   nop
    /* 1480 80103C80 320F0408 */  j          .L80103CC8
    /* 1484 80103C84 00000000 */   nop
  .L80103C88:
    /* 1488 80103C88 03000224 */  addiu      $v0, $zero, 0x3
    /* 148C 80103C8C 0B006210 */  beq        $v1, $v0, .L80103CBC
    /* 1490 80103C90 1180023C */   lui       $v0, %hi(_combiningItem)
    /* 1494 80103C94 320F0408 */  j          .L80103CC8
    /* 1498 80103C98 00000000 */   nop
  .L80103C9C:
    /* 149C 80103C9C 01F5030C */  jal        vs_mainMenu_setUiBladeStats
    /* 14A0 80103CA0 21202002 */   addu      $a0, $s1, $zero
    /* 14A4 80103CA4 320F0408 */  j          .L80103CC8
    /* 14A8 80103CA8 00000000 */   nop
  .L80103CAC:
    /* 14AC 80103CAC 41F5030C */  jal        vs_mainMenu_setUiGripStats
    /* 14B0 80103CB0 21200002 */   addu      $a0, $s0, $zero
    /* 14B4 80103CB4 320F0408 */  j          .L80103CC8
    /* 14B8 80103CB8 00000000 */   nop
  .L80103CBC:
    /* 14BC 80103CBC 81BC4490 */  lbu        $a0, %lo(_combiningItem)($v0)
    /* 14C0 80103CC0 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 14C4 80103CC4 01008424 */   addiu     $a0, $a0, 0x1
  .L80103CC8:
    /* 14C8 80103CC8 E3EE030C */  jal        func_800FBB8C
    /* 14CC 80103CCC 07000424 */   addiu     $a0, $zero, 0x7
    /* 14D0 80103CD0 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 14D4 80103CD4 0B000424 */   addiu     $a0, $zero, 0xB
    /* 14D8 80103CD8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 14DC 80103CDC 1400B18F */  lw         $s1, 0x14($sp)
    /* 14E0 80103CE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 14E4 80103CE4 0800E003 */  jr         $ra
    /* 14E8 80103CE8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80103C20
