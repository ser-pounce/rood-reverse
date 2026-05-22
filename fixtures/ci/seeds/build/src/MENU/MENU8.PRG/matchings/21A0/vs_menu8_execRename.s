nonmatching vs_menu8_execRename, 0x244

glabel vs_menu8_execRename
    /* 2B14 80105314 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2B18 80105318 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B1C 8010531C 21888000 */  addu       $s1, $a0, $zero
    /* 2B20 80105320 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2B24 80105324 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B28 80105328 00003092 */  lbu        $s0, 0x0($s1)
    /* 2B2C 8010532C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2B30 80105330 4A000212 */  beq        $s0, $v0, .L8010545C
    /* 2B34 80105334 0200022A */   slti      $v0, $s0, 0x2
    /* 2B38 80105338 05004010 */  beqz       $v0, .L80105350
    /* 2B3C 8010533C 00000000 */   nop
    /* 2B40 80105340 0A000012 */  beqz       $s0, .L8010536C
    /* 2B44 80105344 0F80023C */   lui       $v0, %hi(vs_battle_stringBuf)
    /* 2B48 80105348 35150408 */  j          .L801054D4
    /* 2B4C 8010534C 1080023C */   lui       $v0, %hi(D_80105F30)
  .L80105350:
    /* 2B50 80105350 02000224 */  addiu      $v0, $zero, 0x2
    /* 2B54 80105354 48000212 */  beq        $s0, $v0, .L80105478
    /* 2B58 80105358 03000224 */   addiu     $v0, $zero, 0x3
    /* 2B5C 8010535C 53000212 */  beq        $s0, $v0, .L801054AC
    /* 2B60 80105360 1080023C */   lui       $v0, %hi(D_80105F30)
    /* 2B64 80105364 35150408 */  j          .L801054D4
    /* 2B68 80105368 00000000 */   nop
  .L8010536C:
    /* 2B6C 8010536C 1080043C */  lui        $a0, %hi(_charTable)
    /* 2B70 80105370 8C4E438C */  lw         $v1, %lo(vs_battle_stringBuf)($v0)
    /* 2B74 80105374 1080023C */  lui        $v0, %hi(D_80105E20)
    /* 2B78 80105378 01006390 */  lbu        $v1, 0x1($v1)
    /* 2B7C 8010537C 205E4224 */  addiu      $v0, $v0, %lo(D_80105E20)
    /* 2B80 80105380 345F82AC */  sw         $v0, %lo(_charTable)($a0)
    /* 2B84 80105384 1080023C */  lui        $v0, %hi(D_80105F2E)
    /* 2B88 80105388 EAFE030C */  jal        func_800FFBA8
    /* 2B8C 8010538C 2E5F43A0 */   sb        $v1, %lo(D_80105F2E)($v0)
    /* 2B90 80105390 8F000324 */  addiu      $v1, $zero, 0x8F
    /* 2B94 80105394 13000524 */  addiu      $a1, $zero, 0x13
    /* 2B98 80105398 1080023C */  lui        $v0, %hi(_stringBuf)
    /* 2B9C 8010539C 405F4224 */  addiu      $v0, $v0, %lo(_stringBuf)
    /* 2BA0 801053A0 21104500 */  addu       $v0, $v0, $a1
  .L801053A4:
    /* 2BA4 801053A4 000043A0 */  sb         $v1, 0x0($v0)
    /* 2BA8 801053A8 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 2BAC 801053AC FDFFA104 */  bgez       $a1, .L801053A4
    /* 2BB0 801053B0 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 2BB4 801053B4 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 2BB8 801053B8 8C4E428C */  lw         $v0, %lo(vs_battle_stringBuf)($v0)
    /* 2BBC 801053BC 00000000 */  nop
    /* 2BC0 801053C0 00004390 */  lbu        $v1, 0x0($v0)
    /* 2BC4 801053C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 2BC8 801053C8 1D006214 */  bne        $v1, $v0, .L80105440
    /* 2BCC 801053CC 1080023C */   lui       $v0, %hi(D_80105F30)
    /* 2BD0 801053D0 21280000 */  addu       $a1, $zero, $zero
    /* 2BD4 801053D4 E7000924 */  addiu      $t1, $zero, 0xE7
    /* 2BD8 801053D8 8F000824 */  addiu      $t0, $zero, 0x8F
    /* 2BDC 801053DC FA000724 */  addiu      $a3, $zero, 0xFA
    /* 2BE0 801053E0 1080023C */  lui        $v0, %hi(D_80105F2E)
    /* 2BE4 801053E4 2E5F4390 */  lbu        $v1, %lo(D_80105F2E)($v0)
    /* 2BE8 801053E8 1080023C */  lui        $v0, %hi(_stringBuf)
    /* 2BEC 801053EC 405F4624 */  addiu      $a2, $v0, %lo(_stringBuf)
    /* 2BF0 801053F0 0680023C */  lui        $v0, %hi(D_80060170)
    /* 2BF4 801053F4 70014224 */  addiu      $v0, $v0, %lo(D_80060170)
    /* 2BF8 801053F8 40190300 */  sll        $v1, $v1, 5
    /* 2BFC 801053FC 21186200 */  addu       $v1, $v1, $v0
  .L80105400:
    /* 2C00 80105400 00006490 */  lbu        $a0, 0x0($v1)
    /* 2C04 80105404 00000000 */  nop
    /* 2C08 80105408 0C008910 */  beq        $a0, $t1, .L8010543C
    /* 2C0C 8010540C 01006324 */   addiu     $v1, $v1, 0x1
    /* 2C10 80105410 06008810 */  beq        $a0, $t0, .L8010542C
    /* 2C14 80105414 00000000 */   nop
    /* 2C18 80105418 03008714 */  bne        $a0, $a3, .L80105428
    /* 2C1C 8010541C 2110A600 */   addu      $v0, $a1, $a2
    /* 2C20 80105420 0B150408 */  j          .L8010542C
    /* 2C24 80105424 01006324 */   addiu     $v1, $v1, 0x1
  .L80105428:
    /* 2C28 80105428 000044A0 */  sb         $a0, 0x0($v0)
  .L8010542C:
    /* 2C2C 8010542C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 2C30 80105430 1400A228 */  slti       $v0, $a1, 0x14
    /* 2C34 80105434 F2FF4014 */  bnez       $v0, .L80105400
    /* 2C38 80105438 00000000 */   nop
  .L8010543C:
    /* 2C3C 8010543C 1080023C */  lui        $v0, %hi(D_80105F30)
  .L80105440:
    /* 2C40 80105440 1080033C */  lui        $v1, %hi(_animStep)
    /* 2C44 80105444 305F40A0 */  sb         $zero, %lo(D_80105F30)($v0)
    /* 2C48 80105448 0A000224 */  addiu      $v0, $zero, 0xA
    /* 2C4C 8010544C 315F62A0 */  sb         $v0, %lo(_animStep)($v1)
    /* 2C50 80105450 01000224 */  addiu      $v0, $zero, 0x1
    /* 2C54 80105454 34150408 */  j          .L801054D0
    /* 2C58 80105458 000022A2 */   sb        $v0, 0x0($s1)
  .L8010545C:
    /* 2C5C 8010545C 6812040C */  jal        func_801049A0
    /* 2C60 80105460 01000424 */   addiu     $a0, $zero, 0x1
    /* 2C64 80105464 1080023C */  lui        $v0, %hi(D_80105F30)
    /* 2C68 80105468 305F50A0 */  sb         $s0, %lo(D_80105F30)($v0)
    /* 2C6C 8010546C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C70 80105470 34150408 */  j          .L801054D0
    /* 2C74 80105474 000022A2 */   sb        $v0, 0x0($s1)
  .L80105478:
    /* 2C78 80105478 6812040C */  jal        func_801049A0
    /* 2C7C 8010547C 21200000 */   addu      $a0, $zero, $zero
    /* 2C80 80105480 14004010 */  beqz       $v0, .L801054D4
    /* 2C84 80105484 1080023C */   lui       $v0, %hi(D_80105F30)
    /* 2C88 80105488 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 2C8C 8010548C 0A000424 */   addiu     $a0, $zero, 0xA
    /* 2C90 80105490 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 2C94 80105494 21200000 */   addu      $a0, $zero, $zero
    /* 2C98 80105498 F2FE030C */  jal        func_800FFBC8
    /* 2C9C 8010549C 00000000 */   nop
    /* 2CA0 801054A0 03000224 */  addiu      $v0, $zero, 0x3
    /* 2CA4 801054A4 34150408 */  j          .L801054D0
    /* 2CA8 801054A8 000022A2 */   sb        $v0, 0x0($s1)
  .L801054AC:
    /* 2CAC 801054AC 1080023C */  lui        $v0, %hi(_animStep)
    /* 2CB0 801054B0 315F4390 */  lbu        $v1, %lo(_animStep)($v0)
    /* 2CB4 801054B4 0A000224 */  addiu      $v0, $zero, 0xA
    /* 2CB8 801054B8 06006214 */  bne        $v1, $v0, .L801054D4
    /* 2CBC 801054BC 1080023C */   lui       $v0, %hi(D_80105F30)
    /* 2CC0 801054C0 0F80033C */  lui        $v1, %hi(vs_battle_menuState)
    /* 2CC4 801054C4 0D000224 */  addiu      $v0, $zero, 0xD
    /* 2CC8 801054C8 000020A2 */  sb         $zero, 0x0($s1)
    /* 2CCC 801054CC C05162A0 */  sb         $v0, %lo(vs_battle_menuState)($v1)
  .L801054D0:
    /* 2CD0 801054D0 1080023C */  lui        $v0, %hi(D_80105F30)
  .L801054D4:
    /* 2CD4 801054D4 305F4290 */  lbu        $v0, %lo(D_80105F30)($v0)
    /* 2CD8 801054D8 00000000 */  nop
    /* 2CDC 801054DC 0D004010 */  beqz       $v0, .L80105514
    /* 2CE0 801054E0 1080033C */   lui       $v1, %hi(_animStep)
    /* 2CE4 801054E4 315F6290 */  lbu        $v0, %lo(_animStep)($v1)
    /* 2CE8 801054E8 00000000 */  nop
    /* 2CEC 801054EC 02004010 */  beqz       $v0, .L801054F8
    /* 2CF0 801054F0 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 2CF4 801054F4 315F62A0 */  sb         $v0, %lo(_animStep)($v1)
  .L801054F8:
    /* 2CF8 801054F8 0F80023C */  lui        $v0, %hi(vs_battle_rowAnimationSteps)
    /* 2CFC 801054FC 315F6390 */  lbu        $v1, %lo(_animStep)($v1)
    /* 2D00 80105500 C8BB4224 */  addiu      $v0, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 2D04 80105504 21186200 */  addu       $v1, $v1, $v0
    /* 2D08 80105508 00006490 */  lbu        $a0, 0x0($v1)
    /* 2D0C 8010550C 4E150408 */  j          .L80105538
    /* 2D10 80105510 00000000 */   nop
  .L80105514:
    /* 2D14 80105514 1080043C */  lui        $a0, %hi(_animStep)
    /* 2D18 80105518 315F8390 */  lbu        $v1, %lo(_animStep)($a0)
    /* 2D1C 8010551C 00000000 */  nop
    /* 2D20 80105520 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 2D24 80105524 06004010 */  beqz       $v0, .L80105540
    /* 2D28 80105528 01006224 */   addiu     $v0, $v1, 0x1
    /* 2D2C 8010552C 315F82A0 */  sb         $v0, %lo(_animStep)($a0)
    /* 2D30 80105530 FF004430 */  andi       $a0, $v0, 0xFF
    /* 2D34 80105534 40210400 */  sll        $a0, $a0, 5
  .L80105538:
    /* 2D38 80105538 F60F040C */  jal        func_80103FD8
    /* 2D3C 8010553C 00000000 */   nop
  .L80105540:
    /* 2D40 80105540 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2D44 80105544 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D48 80105548 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D4C 8010554C 21100000 */  addu       $v0, $zero, $zero
    /* 2D50 80105550 0800E003 */  jr         $ra
    /* 2D54 80105554 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_menu8_execRename
