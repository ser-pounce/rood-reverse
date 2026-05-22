nonmatching func_80104C40, 0x1BC

glabel func_80104C40
    /* 2440 80104C40 60FFBD27 */  addiu      $sp, $sp, -0xA0
    /* 2444 80104C44 9000B2AF */  sw         $s2, 0x90($sp)
    /* 2448 80104C48 21908000 */  addu       $s2, $a0, $zero
    /* 244C 80104C4C 2138A000 */  addu       $a3, $a1, $zero
    /* 2450 80104C50 9800B4AF */  sw         $s4, 0x98($sp)
    /* 2454 80104C54 21A0C000 */  addu       $s4, $a2, $zero
    /* 2458 80104C58 8C00B1AF */  sw         $s1, 0x8C($sp)
    /* 245C 80104C5C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2460 80104C60 9C00BFAF */  sw         $ra, 0x9C($sp)
    /* 2464 80104C64 9400B3AF */  sw         $s3, 0x94($sp)
    /* 2468 80104C68 8800B0AF */  sw         $s0, 0x88($sp)
    /* 246C 80104C6C 5D00E390 */  lbu        $v1, 0x5D($a3)
    /* 2470 80104C70 0D004216 */  bne        $s2, $v0, .L80104CA8
    /* 2474 80104C74 9E001124 */   addiu     $s1, $zero, 0x9E
    /* 2478 80104C78 2000B027 */  addiu      $s0, $sp, 0x20
    /* 247C 80104C7C 21200002 */  addu       $a0, $s0, $zero
    /* 2480 80104C80 5FAD010C */  jal        vs_battle_copyUiBladeStats
    /* 2484 80104C84 1800E524 */   addiu     $a1, $a3, 0x18
    /* 2488 80104C88 21200002 */  addu       $a0, $s0, $zero
    /* 248C 80104C8C 1800A527 */  addiu      $a1, $sp, 0x18
    /* 2490 80104C90 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 2494 80104C94 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 2498 80104C98 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 249C 80104C9C 8000A627 */   addiu     $a2, $sp, 0x80
    /* 24A0 80104CA0 57130408 */  j          .L80104D5C
    /* 24A4 80104CA4 14005026 */   addiu     $s0, $s2, 0x14
  .L80104CA8:
    /* 24A8 80104CA8 02000224 */  addiu      $v0, $zero, 0x2
    /* 24AC 80104CAC 0C004216 */  bne        $s2, $v0, .L80104CE0
    /* 24B0 80104CB0 5000B027 */   addiu     $s0, $sp, 0x50
    /* 24B4 80104CB4 21200002 */  addu       $a0, $s0, $zero
    /* 24B8 80104CB8 ABAD010C */  jal        vs_battle_copyUiGripStats
    /* 24BC 80104CBC 4800E524 */   addiu     $a1, $a3, 0x48
    /* 24C0 80104CC0 21200002 */  addu       $a0, $s0, $zero
    /* 24C4 80104CC4 1800A527 */  addiu      $a1, $sp, 0x18
    /* 24C8 80104CC8 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 24CC 80104CCC 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 24D0 80104CD0 03F3030C */  jal        vs_mainMenu_setUiGrip
    /* 24D4 80104CD4 8000A627 */   addiu     $a2, $sp, 0x80
    /* 24D8 80104CD8 57130408 */  j          .L80104D5C
    /* 24DC 80104CDC 14005026 */   addiu     $s0, $s2, 0x14
  .L80104CE0:
    /* 24E0 80104CE0 FDFF5126 */  addiu      $s1, $s2, -0x3
    /* 24E4 80104CE4 2A102302 */  slt        $v0, $s1, $v1
    /* 24E8 80104CE8 1A004010 */  beqz       $v0, .L80104D54
    /* 24EC 80104CEC 1080023C */   lui       $v0, %hi(vs_mainMenu_itemHelp)
    /* 24F0 80104CF0 4025428C */  lw         $v0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 24F4 80104CF4 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 24F8 80104CF8 16684224 */  addiu      $v0, $v0, 0x6816
    /* 24FC 80104CFC 1800A2AF */  sw         $v0, 0x18($sp)
    /* 2500 80104D00 40101100 */  sll        $v0, $s1, 1
    /* 2504 80104D04 21105100 */  addu       $v0, $v0, $s1
    /* 2508 80104D08 00290200 */  sll        $a1, $v0, 4
    /* 250C 80104D0C 2110E500 */  addu       $v0, $a3, $a1
    /* 2510 80104D10 78004394 */  lhu        $v1, 0x78($v0)
    /* 2514 80104D14 0058023C */  lui        $v0, (0x58000000 >> 16)
    /* 2518 80104D18 0C006010 */  beqz       $v1, .L80104D4C
    /* 251C 80104D1C 8000A2AF */   sw        $v0, 0x80($sp)
    /* 2520 80104D20 6000B027 */  addiu      $s0, $sp, 0x60
    /* 2524 80104D24 21200002 */  addu       $a0, $s0, $zero
    /* 2528 80104D28 7800A524 */  addiu      $a1, $a1, 0x78
    /* 252C 80104D2C CAAD010C */  jal        vs_battle_copyUiGemStats
    /* 2530 80104D30 2128E500 */   addu      $a1, $a3, $a1
    /* 2534 80104D34 21200002 */  addu       $a0, $s0, $zero
    /* 2538 80104D38 1800A527 */  addiu      $a1, $sp, 0x18
    /* 253C 80104D3C 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 2540 80104D40 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 2544 80104D44 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 2548 80104D48 8000A627 */   addiu     $a2, $sp, 0x80
  .L80104D4C:
    /* 254C 80104D4C 56130408 */  j          .L80104D58
    /* 2550 80104D50 97001124 */   addiu     $s1, $zero, 0x97
  .L80104D54:
    /* 2554 80104D54 21880000 */  addu       $s1, $zero, $zero
  .L80104D58:
    /* 2558 80104D58 14005026 */  addiu      $s0, $s2, 0x14
  .L80104D5C:
    /* 255C 80104D5C E4FE030C */  jal        vs_mainMenu_deactivateMenuItem
    /* 2560 80104D60 21200002 */   addu      $a0, $s0, $zero
    /* 2564 80104D64 1D002012 */  beqz       $s1, .L80104DDC
    /* 2568 80104D68 21200002 */   addu      $a0, $s0, $zero
    /* 256C 80104D6C 40011324 */  addiu      $s3, $zero, 0x140
    /* 2570 80104D70 23807102 */  subu       $s0, $s3, $s1
    /* 2574 80104D74 21280002 */  addu       $a1, $s0, $zero
    /* 2578 80104D78 00311200 */  sll        $a2, $s2, 4
    /* 257C 80104D7C 1200C624 */  addiu      $a2, $a2, 0x12
    /* 2580 80104D80 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2584 80104D84 1800A28F */  lw         $v0, 0x18($sp)
    /* 2588 80104D88 21382002 */  addu       $a3, $s1, $zero
    /* 258C 80104D8C 9723030C */  jal        vs_battle_setMenuItem
    /* 2590 80104D90 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2594 80104D94 21204000 */  addu       $a0, $v0, $zero
    /* 2598 80104D98 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 259C 80104D9C 01008232 */  andi       $v0, $s4, 0x1
    /* 25A0 80104DA0 0100632C */  sltiu      $v1, $v1, 0x1
    /* 25A4 80104DA4 05004010 */  beqz       $v0, .L80104DBC
    /* 25A8 80104DA8 070083A0 */   sb        $v1, 0x7($a0)
    /* 25AC 80104DAC 02000224 */  addiu      $v0, $zero, 0x2
    /* 25B0 80104DB0 140093A4 */  sh         $s3, 0x14($a0)
    /* 25B4 80104DB4 000082A0 */  sb         $v0, 0x0($a0)
    /* 25B8 80104DB8 180090A4 */  sh         $s0, 0x18($a0)
  .L80104DBC:
    /* 25BC 80104DBC 8000A28F */  lw         $v0, 0x80($sp)
    /* 25C0 80104DC0 00000000 */  nop
    /* 25C4 80104DC4 82160200 */  srl        $v0, $v0, 26
    /* 25C8 80104DC8 090082A0 */  sb         $v0, 0x9($a0)
    /* 25CC 80104DCC 8200A297 */  lhu        $v0, 0x82($sp)
    /* 25D0 80104DD0 00000000 */  nop
    /* 25D4 80104DD4 07004230 */  andi       $v0, $v0, 0x7
    /* 25D8 80104DD8 0C0082A0 */  sb         $v0, 0xC($a0)
  .L80104DDC:
    /* 25DC 80104DDC 9C00BF8F */  lw         $ra, 0x9C($sp)
    /* 25E0 80104DE0 9800B48F */  lw         $s4, 0x98($sp)
    /* 25E4 80104DE4 9400B38F */  lw         $s3, 0x94($sp)
    /* 25E8 80104DE8 9000B28F */  lw         $s2, 0x90($sp)
    /* 25EC 80104DEC 8C00B18F */  lw         $s1, 0x8C($sp)
    /* 25F0 80104DF0 8800B08F */  lw         $s0, 0x88($sp)
    /* 25F4 80104DF4 0800E003 */  jr         $ra
    /* 25F8 80104DF8 A000BD27 */   addiu     $sp, $sp, 0xA0
endlabel func_80104C40
