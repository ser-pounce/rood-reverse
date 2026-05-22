nonmatching func_80102B50, 0xBC

glabel func_80102B50
    /* 350 80102B50 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 354 80102B54 1800B0AF */  sw         $s0, 0x18($sp)
    /* 358 80102B58 2180A000 */  addu       $s0, $a1, $zero
    /* 35C 80102B5C 40400400 */  sll        $t0, $a0, 1
    /* 360 80102B60 20000424 */  addiu      $a0, $zero, 0x20
    /* 364 80102B64 5CFF0524 */  addiu      $a1, $zero, -0xA4
    /* 368 80102B68 12000624 */  addiu      $a2, $zero, 0x12
    /* 36C 80102B6C A4000724 */  addiu      $a3, $zero, 0xA4
    /* 370 80102B70 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 374 80102B74 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 378 80102B78 08000324 */  addiu      $v1, $zero, 0x8
    /* 37C 80102B7C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 380 80102B80 1000A3AF */  sw         $v1, 0x10($sp)
    /* 384 80102B84 21104800 */  addu       $v0, $v0, $t0
    /* 388 80102B88 9723030C */  jal        vs_battle_setMenuItem
    /* 38C 80102B8C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 390 80102B90 05000324 */  addiu      $v1, $zero, 0x5
    /* 394 80102B94 000043A0 */  sb         $v1, 0x0($v0)
    /* 398 80102B98 10000324 */  addiu      $v1, $zero, 0x10
    /* 39C 80102B9C 180043A4 */  sh         $v1, 0x18($v0)
    /* 3A0 80102BA0 01000324 */  addiu      $v1, $zero, 0x1
    /* 3A4 80102BA4 060043A0 */  sb         $v1, 0x6($v0)
    /* 3A8 80102BA8 88F4030C */  jal        vs_mainMenu_resetStats
    /* 3AC 80102BAC 090050A0 */   sb        $s0, 0x9($v0)
    /* 3B0 80102BB0 18000224 */  addiu      $v0, $zero, 0x18
    /* 3B4 80102BB4 07000216 */  bne        $s0, $v0, .L80102BD4
    /* 3B8 80102BB8 07000424 */   addiu     $a0, $zero, 0x7
    /* 3BC 80102BBC 21200000 */  addu       $a0, $zero, $zero
    /* 3C0 80102BC0 21288000 */  addu       $a1, $a0, $zero
    /* 3C4 80102BC4 21308000 */  addu       $a2, $a0, $zero
    /* 3C8 80102BC8 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 3CC 80102BCC 01000724 */   addiu     $a3, $zero, 0x1
    /* 3D0 80102BD0 03000424 */  addiu      $a0, $zero, 0x3
  .L80102BD4:
    /* 3D4 80102BD4 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 3D8 80102BD8 00000000 */   nop
    /* 3DC 80102BDC 1C000224 */  addiu      $v0, $zero, 0x1C
    /* 3E0 80102BE0 02000216 */  bne        $s0, $v0, .L80102BEC
    /* 3E4 80102BE4 03000424 */   addiu     $a0, $zero, 0x3
    /* 3E8 80102BE8 01000424 */  addiu      $a0, $zero, 0x1
  .L80102BEC:
    /* 3EC 80102BEC 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 3F0 80102BF0 00000000 */   nop
    /* 3F4 80102BF4 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 3F8 80102BF8 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FC 80102BFC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 400 80102C00 1800B08F */  lw         $s0, 0x18($sp)
    /* 404 80102C04 0800E003 */  jr         $ra
    /* 408 80102C08 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102B50
