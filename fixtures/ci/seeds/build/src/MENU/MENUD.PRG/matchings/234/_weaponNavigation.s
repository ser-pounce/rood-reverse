nonmatching _weaponNavigation, 0x264

glabel _weaponNavigation
    /* 1AD0 801042D0 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 1AD4 801042D4 21288000 */  addu       $a1, $a0, $zero
    /* 1AD8 801042D8 3800BFAF */  sw         $ra, 0x38($sp)
    /* 1ADC 801042DC 3400B3AF */  sw         $s3, 0x34($sp)
    /* 1AE0 801042E0 3000B2AF */  sw         $s2, 0x30($sp)
    /* 1AE4 801042E4 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 1AE8 801042E8 1100A010 */  beqz       $a1, .L80104330
    /* 1AEC 801042EC 2800B0AF */   sw        $s0, 0x28($sp)
    /* 1AF0 801042F0 1180033C */  lui        $v1, %hi(D_80109A32)
    /* 1AF4 801042F4 03120500 */  sra        $v0, $a1, 8
    /* 1AF8 801042F8 329A62A0 */  sb         $v0, %lo(D_80109A32)($v1)
    /* 1AFC 801042FC FF004430 */  andi       $a0, $v0, 0xFF
    /* 1B00 80104300 1180033C */  lui        $v1, %hi(_selectedWeapon)
    /* 1B04 80104304 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 1B08 80104308 D90F040C */  jal        func_80103F64
    /* 1B0C 8010430C 339A62A0 */   sb        $v0, %lo(_selectedWeapon)($v1)
    /* 1B10 80104310 21100000 */  addu       $v0, $zero, $zero
    /* 1B14 80104314 1180033C */  lui        $v1, %hi(D_80109A34)
    /* 1B18 80104318 349A60A0 */  sb         $zero, %lo(D_80109A34)($v1)
    /* 1B1C 8010431C 1180033C */  lui        $v1, %hi(D_80109A31)
    /* 1B20 80104320 319A60A0 */  sb         $zero, %lo(D_80109A31)($v1)
    /* 1B24 80104324 1180033C */  lui        $v1, %hi(D_80109A30)
    /* 1B28 80104328 46110408 */  j          .L80104518
    /* 1B2C 8010432C 309A60A0 */   sb        $zero, %lo(D_80109A30)($v1)
  .L80104330:
    /* 1B30 80104330 1180103C */  lui        $s0, %hi(D_80109A30)
    /* 1B34 80104334 309A0392 */  lbu        $v1, %lo(D_80109A30)($s0)
    /* 1B38 80104338 01001124 */  addiu      $s1, $zero, 0x1
    /* 1B3C 8010433C 21007110 */  beq        $v1, $s1, .L801043C4
    /* 1B40 80104340 02006228 */   slti      $v0, $v1, 0x2
    /* 1B44 80104344 05004010 */  beqz       $v0, .L8010435C
    /* 1B48 80104348 02000224 */   addiu     $v0, $zero, 0x2
    /* 1B4C 8010434C 09006010 */  beqz       $v1, .L80104374
    /* 1B50 80104350 21100000 */   addu      $v0, $zero, $zero
    /* 1B54 80104354 46110408 */  j          .L80104518
    /* 1B58 80104358 00000000 */   nop
  .L8010435C:
    /* 1B5C 8010435C 32006210 */  beq        $v1, $v0, .L80104428
    /* 1B60 80104360 03000224 */   addiu     $v0, $zero, 0x3
    /* 1B64 80104364 67006210 */  beq        $v1, $v0, .L80104504
    /* 1B68 80104368 21100000 */   addu      $v0, $zero, $zero
    /* 1B6C 8010436C 46110408 */  j          .L80104518
    /* 1B70 80104370 00000000 */   nop
  .L80104374:
    /* 1B74 80104374 74EA030C */  jal        vs_mainmenu_ready
    /* 1B78 80104378 00000000 */   nop
    /* 1B7C 8010437C 65004010 */  beqz       $v0, .L80104514
    /* 1B80 80104380 1180023C */   lui       $v0, %hi(D_80109A32)
    /* 1B84 80104384 329A4490 */  lbu        $a0, %lo(D_80109A32)($v0)
    /* 1B88 80104388 0D10040C */  jal        func_80104034
    /* 1B8C 8010438C 07000524 */   addiu     $a1, $zero, 0x7
    /* 1B90 80104390 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 1B94 80104394 1180023C */  lui        $v0, %hi(_selectedWeapon)
    /* 1B98 80104398 339A4290 */  lbu        $v0, %lo(_selectedWeapon)($v0)
    /* 1B9C 8010439C 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 1BA0 801043A0 40100200 */  sll        $v0, $v0, 1
    /* 1BA4 801043A4 21186200 */  addu       $v1, $v1, $v0
    /* 1BA8 801043A8 003C6494 */  lhu        $a0, 0x3C00($v1)
    /* 1BAC 801043AC 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 1BB0 801043B0 00000000 */   nop
    /* 1BB4 801043B4 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 1BB8 801043B8 03000424 */   addiu     $a0, $zero, 0x3
    /* 1BBC 801043BC 45110408 */  j          .L80104514
    /* 1BC0 801043C0 309A11A2 */   sb        $s1, %lo(D_80109A30)($s0)
  .L801043C4:
    /* 1BC4 801043C4 1180043C */  lui        $a0, %hi(D_80109A31)
    /* 1BC8 801043C8 319A8390 */  lbu        $v1, %lo(D_80109A31)($a0)
    /* 1BCC 801043CC 00000000 */  nop
    /* 1BD0 801043D0 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 1BD4 801043D4 11004010 */  beqz       $v0, .L8010441C
    /* 1BD8 801043D8 01006224 */   addiu     $v0, $v1, 0x1
    /* 1BDC 801043DC 319A82A0 */  sb         $v0, %lo(D_80109A31)($a0)
    /* 1BE0 801043E0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1BE4 801043E4 0600422C */  sltiu      $v0, $v0, 0x6
    /* 1BE8 801043E8 4A004010 */  beqz       $v0, .L80104514
    /* 1BEC 801043EC 1180033C */   lui       $v1, %hi(vs_menuD_containerData)
    /* 1BF0 801043F0 1180023C */  lui        $v0, %hi(_selectedWeapon)
    /* 1BF4 801043F4 319A8490 */  lbu        $a0, %lo(D_80109A31)($a0)
    /* 1BF8 801043F8 339A4290 */  lbu        $v0, %lo(_selectedWeapon)($v0)
    /* 1BFC 801043FC 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 1C00 80104400 40100200 */  sll        $v0, $v0, 1
    /* 1C04 80104404 21186200 */  addu       $v1, $v1, $v0
    /* 1C08 80104408 003C6594 */  lhu        $a1, 0x3C00($v1)
    /* 1C0C 8010440C 44F1030C */  jal        vs_mainMenu_initSetWeaponGemMenu
    /* 1C10 80104410 01000624 */   addiu     $a2, $zero, 0x1
    /* 1C14 80104414 46110408 */  j          .L80104518
    /* 1C18 80104418 21100000 */   addu      $v0, $zero, $zero
  .L8010441C:
    /* 1C1C 8010441C 02000224 */  addiu      $v0, $zero, 0x2
    /* 1C20 80104420 45110408 */  j          .L80104514
    /* 1C24 80104424 309A02A2 */   sb        $v0, %lo(D_80109A30)($s0)
  .L80104428:
    /* 1C28 80104428 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 1C2C 8010442C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 1C30 80104430 00000000 */  nop
    /* 1C34 80104434 50004230 */  andi       $v0, $v0, 0x50
    /* 1C38 80104438 06004010 */  beqz       $v0, .L80104454
    /* 1C3C 8010443C 00000000 */   nop
    /* 1C40 80104440 5C10040C */  jal        func_80104170
    /* 1C44 80104444 01000424 */   addiu     $a0, $zero, 0x1
    /* 1C48 80104448 03000224 */  addiu      $v0, $zero, 0x3
    /* 1C4C 8010444C 45110408 */  j          .L80104514
    /* 1C50 80104450 309A02A2 */   sb        $v0, %lo(D_80109A30)($s0)
  .L80104454:
    /* 1C54 80104454 1180103C */  lui        $s0, %hi(_selectedWeapon)
    /* 1C58 80104458 339A0592 */  lbu        $a1, %lo(_selectedWeapon)($s0)
    /* 1C5C 8010445C 5B0F040C */  jal        _pollItemNavigation
    /* 1C60 80104460 21200000 */   addu      $a0, $zero, $zero
    /* 1C64 80104464 339A0392 */  lbu        $v1, %lo(_selectedWeapon)($s0)
    /* 1C68 80104468 21884000 */  addu       $s1, $v0, $zero
    /* 1C6C 8010446C 29002312 */  beq        $s1, $v1, .L80104514
    /* 1C70 80104470 21200000 */   addu      $a0, $zero, $zero
    /* 1C74 80104474 21282002 */  addu       $a1, $s1, $zero
    /* 1C78 80104478 4510040C */  jal        func_80104114
    /* 1C7C 8010447C 339A11A2 */   sb        $s1, %lo(_selectedWeapon)($s0)
    /* 1C80 80104480 21804000 */  addu       $s0, $v0, $zero
    /* 1C84 80104484 1800A527 */  addiu      $a1, $sp, 0x18
    /* 1C88 80104488 2000A627 */  addiu      $a2, $sp, 0x20
    /* 1C8C 8010448C 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 1C90 80104490 21904000 */  addu       $s2, $v0, $zero
    /* 1C94 80104494 40981100 */  sll        $s3, $s1, 1
    /* 1C98 80104498 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 1C9C 8010449C 8C9A448E */  lw         $a0, %lo(vs_menuD_containerData)($s2)
    /* 1CA0 801044A0 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 1CA4 801044A4 FFFF0226 */  addiu      $v0, $s0, -0x1
    /* 1CA8 801044A8 7810040C */  jal        _setWeaponUi
    /* 1CAC 801044AC 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1CB0 801044B0 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 1CB4 801044B4 21200002 */   addu      $a0, $s0, $zero
    /* 1CB8 801044B8 1800A527 */  addiu      $a1, $sp, 0x18
    /* 1CBC 801044BC 21382002 */  addu       $a3, $s1, $zero
    /* 1CC0 801044C0 1180023C */  lui        $v0, %hi(D_80109A32)
    /* 1CC4 801044C4 329A4490 */  lbu        $a0, %lo(D_80109A32)($v0)
    /* 1CC8 801044C8 2000A68F */  lw         $a2, 0x20($sp)
    /* 1CCC 801044CC 1E10040C */  jal        func_80104078
    /* 1CD0 801044D0 01001024 */   addiu     $s0, $zero, 0x1
    /* 1CD4 801044D4 21200002 */  addu       $a0, $s0, $zero
  .L801044D8:
    /* 1CD8 801044D8 8C9A428E */  lw         $v0, %lo(vs_menuD_containerData)($s2)
    /* 1CDC 801044DC 21300000 */  addu       $a2, $zero, $zero
    /* 1CE0 801044E0 21105300 */  addu       $v0, $v0, $s3
    /* 1CE4 801044E4 003C4594 */  lhu        $a1, 0x3C00($v0)
    /* 1CE8 801044E8 44F1030C */  jal        vs_mainMenu_initSetWeaponGemMenu
    /* 1CEC 801044EC 01001026 */   addiu     $s0, $s0, 0x1
    /* 1CF0 801044F0 0600022A */  slti       $v0, $s0, 0x6
    /* 1CF4 801044F4 F8FF4014 */  bnez       $v0, .L801044D8
    /* 1CF8 801044F8 21200002 */   addu      $a0, $s0, $zero
    /* 1CFC 801044FC 46110408 */  j          .L80104518
    /* 1D00 80104500 21100000 */   addu      $v0, $zero, $zero
  .L80104504:
    /* 1D04 80104504 74EA030C */  jal        vs_mainmenu_ready
    /* 1D08 80104508 00000000 */   nop
    /* 1D0C 8010450C 46110408 */  j          .L80104518
    /* 1D10 80104510 00000000 */   nop
  .L80104514:
    /* 1D14 80104514 21100000 */  addu       $v0, $zero, $zero
  .L80104518:
    /* 1D18 80104518 3800BF8F */  lw         $ra, 0x38($sp)
    /* 1D1C 8010451C 3400B38F */  lw         $s3, 0x34($sp)
    /* 1D20 80104520 3000B28F */  lw         $s2, 0x30($sp)
    /* 1D24 80104524 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 1D28 80104528 2800B08F */  lw         $s0, 0x28($sp)
    /* 1D2C 8010452C 0800E003 */  jr         $ra
    /* 1D30 80104530 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _weaponNavigation
