nonmatching _armorNavigation, 0x238

glabel _armorNavigation
    /* 23DC 80104BDC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 23E0 80104BE0 21288000 */  addu       $a1, $a0, $zero
    /* 23E4 80104BE4 3000BFAF */  sw         $ra, 0x30($sp)
    /* 23E8 80104BE8 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 23EC 80104BEC 2800B2AF */  sw         $s2, 0x28($sp)
    /* 23F0 80104BF0 2400B1AF */  sw         $s1, 0x24($sp)
    /* 23F4 80104BF4 1000A010 */  beqz       $a1, .L80104C38
    /* 23F8 80104BF8 2000B0AF */   sw        $s0, 0x20($sp)
    /* 23FC 80104BFC 1180033C */  lui        $v1, %hi(D_80109A45)
    /* 2400 80104C00 03120500 */  sra        $v0, $a1, 8
    /* 2404 80104C04 459A62A0 */  sb         $v0, %lo(D_80109A45)($v1)
    /* 2408 80104C08 FF004430 */  andi       $a0, $v0, 0xFF
    /* 240C 80104C0C 1180033C */  lui        $v1, %hi(D_80109A46)
    /* 2410 80104C10 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 2414 80104C14 D90F040C */  jal        func_80103F64
    /* 2418 80104C18 469A62A0 */   sb        $v0, %lo(D_80109A46)($v1)
    /* 241C 80104C1C 21100000 */  addu       $v0, $zero, $zero
    /* 2420 80104C20 1180043C */  lui        $a0, %hi(D_80109A44)
    /* 2424 80104C24 0A000324 */  addiu      $v1, $zero, 0xA
    /* 2428 80104C28 449A83A0 */  sb         $v1, %lo(D_80109A44)($a0)
    /* 242C 80104C2C 1180033C */  lui        $v1, %hi(D_80109A43)
    /* 2430 80104C30 7E130408 */  j          .L80104DF8
    /* 2434 80104C34 439A60A0 */   sb        $zero, %lo(D_80109A43)($v1)
  .L80104C38:
    /* 2438 80104C38 1180123C */  lui        $s2, %hi(D_80109A43)
    /* 243C 80104C3C 439A4392 */  lbu        $v1, %lo(D_80109A43)($s2)
    /* 2440 80104C40 01001324 */  addiu      $s3, $zero, 0x1
    /* 2444 80104C44 31007310 */  beq        $v1, $s3, .L80104D0C
    /* 2448 80104C48 02006228 */   slti      $v0, $v1, 0x2
    /* 244C 80104C4C 05004010 */  beqz       $v0, .L80104C64
    /* 2450 80104C50 02000224 */   addiu     $v0, $zero, 0x2
    /* 2454 80104C54 09006010 */  beqz       $v1, .L80104C7C
    /* 2458 80104C58 21100000 */   addu      $v0, $zero, $zero
    /* 245C 80104C5C 7E130408 */  j          .L80104DF8
    /* 2460 80104C60 00000000 */   nop
  .L80104C64:
    /* 2464 80104C64 33006210 */  beq        $v1, $v0, .L80104D34
    /* 2468 80104C68 03000224 */   addiu     $v0, $zero, 0x3
    /* 246C 80104C6C 5D006210 */  beq        $v1, $v0, .L80104DE4
    /* 2470 80104C70 21100000 */   addu      $v0, $zero, $zero
    /* 2474 80104C74 7E130408 */  j          .L80104DF8
    /* 2478 80104C78 00000000 */   nop
  .L80104C7C:
    /* 247C 80104C7C 74EA030C */  jal        vs_mainmenu_ready
    /* 2480 80104C80 00000000 */   nop
    /* 2484 80104C84 5B004010 */  beqz       $v0, .L80104DF4
    /* 2488 80104C88 1180023C */   lui       $v0, %hi(D_80109A45)
    /* 248C 80104C8C 459A4490 */  lbu        $a0, %lo(D_80109A45)($v0)
    /* 2490 80104C90 0D10040C */  jal        func_80104034
    /* 2494 80104C94 07000524 */   addiu     $a1, $zero, 0x7
    /* 2498 80104C98 1180113C */  lui        $s1, %hi(vs_menuD_containerData)
    /* 249C 80104C9C 1180103C */  lui        $s0, %hi(D_80109A46)
    /* 24A0 80104CA0 469A0292 */  lbu        $v0, %lo(D_80109A46)($s0)
    /* 24A4 80104CA4 8C9A238E */  lw         $v1, %lo(vs_menuD_containerData)($s1)
    /* 24A8 80104CA8 40100200 */  sll        $v0, $v0, 1
    /* 24AC 80104CAC 21186200 */  addu       $v1, $v1, $v0
    /* 24B0 80104CB0 803D6494 */  lhu        $a0, 0x3D80($v1)
    /* 24B4 80104CB4 C0F5030C */  jal        vs_mainMenu_setArmorStats
    /* 24B8 80104CB8 00000000 */   nop
    /* 24BC 80104CBC 0680043C */  lui        $a0, %hi(vs_battle_inventory)
    /* 24C0 80104CC0 469A0292 */  lbu        $v0, %lo(D_80109A46)($s0)
    /* 24C4 80104CC4 8C9A238E */  lw         $v1, %lo(vs_menuD_containerData)($s1)
    /* 24C8 80104CC8 40100200 */  sll        $v0, $v0, 1
    /* 24CC 80104CCC 21186200 */  addu       $v1, $v1, $v0
    /* 24D0 80104CD0 803D6394 */  lhu        $v1, 0x3D80($v1)
    /* 24D4 80104CD4 68018424 */  addiu      $a0, $a0, %lo(vs_battle_inventory)
    /* 24D8 80104CD8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 24DC 80104CDC 80100300 */  sll        $v0, $v1, 2
    /* 24E0 80104CE0 21104300 */  addu       $v0, $v0, $v1
    /* 24E4 80104CE4 C0100200 */  sll        $v0, $v0, 3
    /* 24E8 80104CE8 21104400 */  addu       $v0, $v0, $a0
    /* 24EC 80104CEC 43064390 */  lbu        $v1, 0x643($v0)
    /* 24F0 80104CF0 07000224 */  addiu      $v0, $zero, 0x7
    /* 24F4 80104CF4 03006210 */  beq        $v1, $v0, .L80104D04
    /* 24F8 80104CF8 00000000 */   nop
    /* 24FC 80104CFC 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 2500 80104D00 01000424 */   addiu     $a0, $zero, 0x1
  .L80104D04:
    /* 2504 80104D04 7D130408 */  j          .L80104DF4
    /* 2508 80104D08 439A53A2 */   sb        $s3, %lo(D_80109A43)($s2)
  .L80104D0C:
    /* 250C 80104D0C 1180033C */  lui        $v1, %hi(D_80109A44)
    /* 2510 80104D10 449A6290 */  lbu        $v0, %lo(D_80109A44)($v1)
    /* 2514 80104D14 00000000 */  nop
    /* 2518 80104D18 03004010 */  beqz       $v0, .L80104D28
    /* 251C 80104D1C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 2520 80104D20 7D130408 */  j          .L80104DF4
    /* 2524 80104D24 449A62A0 */   sb        $v0, %lo(D_80109A44)($v1)
  .L80104D28:
    /* 2528 80104D28 02000224 */  addiu      $v0, $zero, 0x2
    /* 252C 80104D2C 7D130408 */  j          .L80104DF4
    /* 2530 80104D30 439A42A2 */   sb        $v0, %lo(D_80109A43)($s2)
  .L80104D34:
    /* 2534 80104D34 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 2538 80104D38 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 253C 80104D3C 00000000 */  nop
    /* 2540 80104D40 50004230 */  andi       $v0, $v0, 0x50
    /* 2544 80104D44 06004010 */  beqz       $v0, .L80104D60
    /* 2548 80104D48 1180103C */   lui       $s0, %hi(D_80109A46)
    /* 254C 80104D4C 5C10040C */  jal        func_80104170
    /* 2550 80104D50 01000424 */   addiu     $a0, $zero, 0x1
    /* 2554 80104D54 03000224 */  addiu      $v0, $zero, 0x3
    /* 2558 80104D58 7D130408 */  j          .L80104DF4
    /* 255C 80104D5C 439A42A2 */   sb        $v0, %lo(D_80109A43)($s2)
  .L80104D60:
    /* 2560 80104D60 469A0592 */  lbu        $a1, %lo(D_80109A46)($s0)
    /* 2564 80104D64 5B0F040C */  jal        _pollItemNavigation
    /* 2568 80104D68 04000424 */   addiu     $a0, $zero, 0x4
    /* 256C 80104D6C 469A0392 */  lbu        $v1, %lo(D_80109A46)($s0)
    /* 2570 80104D70 21884000 */  addu       $s1, $v0, $zero
    /* 2574 80104D74 1F002312 */  beq        $s1, $v1, .L80104DF4
    /* 2578 80104D78 04000424 */   addiu     $a0, $zero, 0x4
    /* 257C 80104D7C 21282002 */  addu       $a1, $s1, $zero
    /* 2580 80104D80 4510040C */  jal        func_80104114
    /* 2584 80104D84 469A11A2 */   sb        $s1, %lo(D_80109A46)($s0)
    /* 2588 80104D88 1000A527 */  addiu      $a1, $sp, 0x10
    /* 258C 80104D8C 1800A627 */  addiu      $a2, $sp, 0x18
    /* 2590 80104D90 0F80033C */  lui        $v1, %hi(vs_battle_stringBuf)
    /* 2594 80104D94 21804000 */  addu       $s0, $v0, $zero
    /* 2598 80104D98 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 259C 80104D9C 80201000 */  sll        $a0, $s0, 2
    /* 25A0 80104DA0 21209000 */  addu       $a0, $a0, $s0
    /* 25A4 80104DA4 C0200400 */  sll        $a0, $a0, 3
    /* 25A8 80104DA8 D8188424 */  addiu      $a0, $a0, 0x18D8
    /* 25AC 80104DAC 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 25B0 80104DB0 8C4E678C */  lw         $a3, %lo(vs_battle_stringBuf)($v1)
    /* 25B4 80104DB4 21F4030C */  jal        vs_mainMenu_initUiArmor
    /* 25B8 80104DB8 21204400 */   addu      $a0, $v0, $a0
    /* 25BC 80104DBC C0F5030C */  jal        vs_mainMenu_setArmorStats
    /* 25C0 80104DC0 21200002 */   addu      $a0, $s0, $zero
    /* 25C4 80104DC4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 25C8 80104DC8 1180023C */  lui        $v0, %hi(D_80109A45)
    /* 25CC 80104DCC 459A4490 */  lbu        $a0, %lo(D_80109A45)($v0)
    /* 25D0 80104DD0 1800A68F */  lw         $a2, 0x18($sp)
    /* 25D4 80104DD4 1E10040C */  jal        func_80104078
    /* 25D8 80104DD8 21382002 */   addu      $a3, $s1, $zero
    /* 25DC 80104DDC 7E130408 */  j          .L80104DF8
    /* 25E0 80104DE0 21100000 */   addu      $v0, $zero, $zero
  .L80104DE4:
    /* 25E4 80104DE4 74EA030C */  jal        vs_mainmenu_ready
    /* 25E8 80104DE8 00000000 */   nop
    /* 25EC 80104DEC 7E130408 */  j          .L80104DF8
    /* 25F0 80104DF0 00000000 */   nop
  .L80104DF4:
    /* 25F4 80104DF4 21100000 */  addu       $v0, $zero, $zero
  .L80104DF8:
    /* 25F8 80104DF8 3000BF8F */  lw         $ra, 0x30($sp)
    /* 25FC 80104DFC 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 2600 80104E00 2800B28F */  lw         $s2, 0x28($sp)
    /* 2604 80104E04 2400B18F */  lw         $s1, 0x24($sp)
    /* 2608 80104E08 2000B08F */  lw         $s0, 0x20($sp)
    /* 260C 80104E0C 0800E003 */  jr         $ra
    /* 2610 80104E10 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _armorNavigation
