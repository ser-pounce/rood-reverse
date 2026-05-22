nonmatching vs_mainMenu_unpackMenubg, 0x194

glabel vs_mainMenu_unpackMenubg
    /* 6C4C 8010044C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C50 80100450 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6C54 80100454 21908000 */  addu       $s2, $a0, $zero
    /* 6C58 80100458 21400000 */  addu       $t0, $zero, $zero
    /* 6C5C 8010045C 0180023C */  lui        $v0, %hi(vs_overlay_slots + 0x8)
    /* 6C60 80100460 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6C64 80100464 0800518C */  lw         $s1, %lo(vs_overlay_slots + 0x8)($v0)
    /* 6C68 80100468 21300001 */  addu       $a2, $t0, $zero
    /* 6C6C 8010046C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6C70 80100470 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C74 80100474 00022926 */  addiu      $t1, $s1, 0x200
    /* 6C78 80100478 21382001 */  addu       $a3, $t1, $zero
  .L8010047C:
    /* 6C7C 8010047C 0000E48C */  lw         $a0, 0x0($a3)
    /* 6C80 80100480 0400E724 */  addiu      $a3, $a3, 0x4
    /* 6C84 80100484 FFFF8330 */  andi       $v1, $a0, 0xFFFF
    /* 6C88 80100488 08006010 */  beqz       $v1, .L801004AC
    /* 6C8C 8010048C 01000825 */   addiu     $t0, $t0, 0x1
    /* 6C90 80100490 80100600 */  sll        $v0, $a2, 2
    /* 6C94 80100494 21105200 */  addu       $v0, $v0, $s2
  .L80100498:
    /* 6C98 80100498 000040AC */  sw         $zero, 0x0($v0)
    /* 6C9C 8010049C 04004224 */  addiu      $v0, $v0, 0x4
    /* 6CA0 801004A0 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 6CA4 801004A4 FCFF6014 */  bnez       $v1, .L80100498
    /* 6CA8 801004A8 0100C624 */   addiu     $a2, $a2, 0x1
  .L801004AC:
    /* 6CAC 801004AC 021C0400 */  srl        $v1, $a0, 16
    /* 6CB0 801004B0 0F006010 */  beqz       $v1, .L801004F0
    /* 6CB4 801004B4 80170229 */   slti      $v0, $t0, 0x1780
    /* 6CB8 801004B8 80100600 */  sll        $v0, $a2, 2
    /* 6CBC 801004BC 21285200 */  addu       $a1, $v0, $s2
    /* 6CC0 801004C0 80100800 */  sll        $v0, $t0, 2
    /* 6CC4 801004C4 21204900 */  addu       $a0, $v0, $t1
  .L801004C8:
    /* 6CC8 801004C8 0000828C */  lw         $v0, 0x0($a0)
    /* 6CCC 801004CC 04008424 */  addiu      $a0, $a0, 0x4
    /* 6CD0 801004D0 0400E724 */  addiu      $a3, $a3, 0x4
    /* 6CD4 801004D4 01000825 */  addiu      $t0, $t0, 0x1
    /* 6CD8 801004D8 0100C624 */  addiu      $a2, $a2, 0x1
    /* 6CDC 801004DC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 6CE0 801004E0 0000A2AC */  sw         $v0, 0x0($a1)
    /* 6CE4 801004E4 F8FF6014 */  bnez       $v1, .L801004C8
    /* 6CE8 801004E8 0400A524 */   addiu     $a1, $a1, 0x4
    /* 6CEC 801004EC 80170229 */  slti       $v0, $t0, 0x1780
  .L801004F0:
    /* 6CF0 801004F0 E2FF4014 */  bnez       $v0, .L8010047C
    /* 6CF4 801004F4 1A000424 */   addiu     $a0, $zero, 0x1A
    /* 6CF8 801004F8 03000524 */  addiu      $a1, $zero, 0x3
    /* 6CFC 801004FC FCF7010C */  jal        func_8007DFF0
    /* 6D00 80100500 06000624 */   addiu     $a2, $zero, 0x6
    /* 6D04 80100504 1080103C */  lui        $s0, %hi(D_801023C0)
    /* 6D08 80100508 C0231026 */  addiu      $s0, $s0, %lo(D_801023C0)
    /* 6D0C 8010050C 21200002 */  addu       $a0, $s0, $zero
    /* 6D10 80100510 21280000 */  addu       $a1, $zero, $zero
    /* 6D14 80100514 2130A000 */  addu       $a2, $a1, $zero
    /* 6D18 80100518 F5A1000C */  jal        ClearImage
    /* 6D1C 8010051C 2138A000 */   addu      $a3, $a1, $zero
    /* 6D20 80100520 08000426 */  addiu      $a0, $s0, 0x8
    /* 6D24 80100524 21280000 */  addu       $a1, $zero, $zero
    /* 6D28 80100528 2130A000 */  addu       $a2, $a1, $zero
    /* 6D2C 8010052C F5A1000C */  jal        ClearImage
    /* 6D30 80100530 2138A000 */   addu      $a3, $a1, $zero
    /* 6D34 80100534 0F80023C */  lui        $v0, %hi(vs_battle_menuState)
    /* 6D38 80100538 C0514290 */  lbu        $v0, %lo(vs_battle_menuState)($v0)
    /* 6D3C 8010053C 07000324 */  addiu      $v1, $zero, 0x7
    /* 6D40 80100540 3F004230 */  andi       $v0, $v0, 0x3F
    /* 6D44 80100544 13004314 */  bne        $v0, $v1, .L80100594
    /* 6D48 80100548 21202002 */   addu      $a0, $s1, $zero
    /* 6D4C 8010054C 0F80023C */  lui        $v0, %hi(D_800F4EA0)
    /* 6D50 80100550 A04E428C */  lw         $v0, %lo(D_800F4EA0)($v0)
    /* 6D54 80100554 00000000 */  nop
    /* 6D58 80100558 00024230 */  andi       $v0, $v0, 0x200
    /* 6D5C 8010055C 0D004010 */  beqz       $v0, .L80100594
    /* 6D60 80100560 0680023C */   lui       $v0, %hi(vs_main_stateFlags + 0xA4)
    /* 6D64 80100564 3C164390 */  lbu        $v1, %lo(vs_main_stateFlags + 0xA4)($v0)
    /* 6D68 80100568 01000224 */  addiu      $v0, $zero, 0x1
    /* 6D6C 8010056C 09006214 */  bne        $v1, $v0, .L80100594
    /* 6D70 80100570 00000000 */   nop
    /* 6D74 80100574 FF01043C */  lui        $a0, (0x1FF0280 >> 16)
    /* 6D78 80100578 80028434 */  ori        $a0, $a0, (0x1FF0280 & 0xFFFF)
    /* 6D7C 8010057C 21282002 */  addu       $a1, $s1, $zero
    /* 6D80 80100580 0100063C */  lui        $a2, (0x10100 >> 16)
    /* 6D84 80100584 6A33030C */  jal        vs_battle_drawImage
    /* 6D88 80100588 0001C634 */   ori       $a2, $a2, (0x10100 & 0xFFFF)
    /* 6D8C 8010058C 6A010408 */  j          .L801005A8
    /* 6D90 80100590 0001043C */   lui       $a0, (0x10002A0 >> 16)
  .L80100594:
    /* 6D94 80100594 03000524 */  addiu      $a1, $zero, 0x3
    /* 6D98 80100598 21300000 */  addu       $a2, $zero, $zero
    /* 6D9C 8010059C 9922010C */  jal        vs_main_loadClut
    /* 6DA0 801005A0 00010724 */   addiu     $a3, $zero, 0x100
    /* 6DA4 801005A4 0001043C */  lui        $a0, (0x10002A0 >> 16)
  .L801005A8:
    /* 6DA8 801005A8 A0028434 */  ori        $a0, $a0, (0x10002A0 & 0xFFFF)
    /* 6DAC 801005AC 21284002 */  addu       $a1, $s2, $zero
    /* 6DB0 801005B0 F000063C */  lui        $a2, (0xF00060 >> 16)
    /* 6DB4 801005B4 6A33030C */  jal        vs_battle_drawImage
    /* 6DB8 801005B8 6000C634 */   ori       $a2, $a2, (0xF00060 & 0xFFFF)
    /* 6DBC 801005BC FCFF0424 */  addiu      $a0, $zero, -0x4
    /* 6DC0 801005C0 0501040C */  jal        func_80100414
    /* 6DC4 801005C4 80000524 */   addiu     $a1, $zero, 0x80
    /* 6DC8 801005C8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6DCC 801005CC 1800B28F */  lw         $s2, 0x18($sp)
    /* 6DD0 801005D0 1400B18F */  lw         $s1, 0x14($sp)
    /* 6DD4 801005D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6DD8 801005D8 0800E003 */  jr         $ra
    /* 6DDC 801005DC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_mainMenu_unpackMenubg
