nonmatching _weaponStatusOptionMenu, 0x1B0

glabel _weaponStatusOptionMenu
    /* 40C 80102C0C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 410 80102C10 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 414 80102C14 04008010 */  beqz       $a0, .L80102C28
    /* 418 80102C18 2800B0AF */   sw        $s0, 0x28($sp)
    /* 41C 80102C1C 1080023C */  lui        $v0, %hi(D_80105D78)
    /* 420 80102C20 6A0B0408 */  j          .L80102DA8
    /* 424 80102C24 785D40AC */   sw        $zero, %lo(D_80105D78)($v0)
  .L80102C28:
    /* 428 80102C28 1080023C */  lui        $v0, %hi(D_80105D78)
    /* 42C 80102C2C 785D438C */  lw         $v1, %lo(D_80105D78)($v0)
    /* 430 80102C30 01000224 */  addiu      $v0, $zero, 0x1
    /* 434 80102C34 3E006210 */  beq        $v1, $v0, .L80102D30
    /* 438 80102C38 02006228 */   slti      $v0, $v1, 0x2
    /* 43C 80102C3C 05004010 */  beqz       $v0, .L80102C54
    /* 440 80102C40 02000224 */   addiu     $v0, $zero, 0x2
    /* 444 80102C44 07006010 */  beqz       $v1, .L80102C64
    /* 448 80102C48 21100000 */   addu      $v0, $zero, $zero
    /* 44C 80102C4C 6B0B0408 */  j          .L80102DAC
    /* 450 80102C50 00000000 */   nop
  .L80102C54:
    /* 454 80102C54 4D006210 */  beq        $v1, $v0, .L80102D8C
    /* 458 80102C58 21100000 */   addu      $v0, $zero, $zero
    /* 45C 80102C5C 6B0B0408 */  j          .L80102DAC
    /* 460 80102C60 00000000 */   nop
  .L80102C64:
    /* 464 80102C64 74EA030C */  jal        vs_mainmenu_ready
    /* 468 80102C68 00000000 */   nop
    /* 46C 80102C6C 4E004010 */  beqz       $v0, .L80102DA8
    /* 470 80102C70 21280000 */   addu      $a1, $zero, $zero
    /* 474 80102C74 1080023C */  lui        $v0, %hi(_menuStrings)
    /* 478 80102C78 58554B24 */  addiu      $t3, $v0, %lo(_menuStrings)
    /* 47C 80102C7C 2000AA27 */  addiu      $t2, $sp, 0x20
    /* 480 80102C80 3E000924 */  addiu      $t1, $zero, 0x3E
    /* 484 80102C84 04000824 */  addiu      $t0, $zero, 0x4
    /* 488 80102C88 1000AC27 */  addiu      $t4, $sp, 0x10
    /* 48C 80102C8C 21388001 */  addu       $a3, $t4, $zero
    /* 490 80102C90 3C000624 */  addiu      $a2, $zero, 0x3C
  .L80102C94:
    /* 494 80102C94 21182B01 */  addu       $v1, $t1, $t3
    /* 498 80102C98 04002925 */  addiu      $t1, $t1, 0x4
    /* 49C 80102C9C 21208801 */  addu       $a0, $t4, $t0
    /* 4A0 80102CA0 08000825 */  addiu      $t0, $t0, 0x8
    /* 4A4 80102CA4 2110CB00 */  addu       $v0, $a2, $t3
    /* 4A8 80102CA8 0400C624 */  addiu      $a2, $a2, 0x4
    /* 4AC 80102CAC 00004294 */  lhu        $v0, 0x0($v0)
    /* 4B0 80102CB0 0100A524 */  addiu      $a1, $a1, 0x1
    /* 4B4 80102CB4 40100200 */  sll        $v0, $v0, 1
    /* 4B8 80102CB8 21104B00 */  addu       $v0, $v0, $t3
    /* 4BC 80102CBC 0000E2AC */  sw         $v0, 0x0($a3)
    /* 4C0 80102CC0 00006294 */  lhu        $v0, 0x0($v1)
    /* 4C4 80102CC4 0800E724 */  addiu      $a3, $a3, 0x8
    /* 4C8 80102CC8 40100200 */  sll        $v0, $v0, 1
    /* 4CC 80102CCC 21104B00 */  addu       $v0, $v0, $t3
    /* 4D0 80102CD0 000082AC */  sw         $v0, 0x0($a0)
    /* 4D4 80102CD4 000040AD */  sw         $zero, 0x0($t2)
    /* 4D8 80102CD8 0200A228 */  slti       $v0, $a1, 0x2
    /* 4DC 80102CDC EDFF4014 */  bnez       $v0, .L80102C94
    /* 4E0 80102CE0 04004A25 */   addiu     $t2, $t2, 0x4
    /* 4E4 80102CE4 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 4E8 80102CE8 01001024 */  addiu      $s0, $zero, 0x1
    /* 4EC 80102CEC 2000A727 */  addiu      $a3, $sp, 0x20
    /* 4F0 80102CF0 02000424 */  addiu      $a0, $zero, 0x2
    /* 4F4 80102CF4 2000428C */  lw         $v0, %lo(vs_main_settings)($v0)
    /* 4F8 80102CF8 1000A627 */  addiu      $a2, $sp, 0x10
    /* 4FC 80102CFC 82110200 */  srl        $v0, $v0, 6
    /* 500 80102D00 01004230 */  andi       $v0, $v0, 0x1
    /* 504 80102D04 23280202 */  subu       $a1, $s0, $v0
    /* 508 80102D08 80180500 */  sll        $v1, $a1, 2
    /* 50C 80102D0C 2118E300 */  addu       $v1, $a3, $v1
    /* 510 80102D10 0000628C */  lw         $v0, 0x0($v1)
    /* 514 80102D14 48020524 */  addiu      $a1, $zero, 0x248
    /* 518 80102D18 04004234 */  ori        $v0, $v0, 0x4
    /* 51C 80102D1C 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 520 80102D20 000062AC */   sw        $v0, 0x0($v1)
    /* 524 80102D24 1080023C */  lui        $v0, %hi(D_80105D78)
    /* 528 80102D28 6A0B0408 */  j          .L80102DA8
    /* 52C 80102D2C 785D50AC */   sw        $s0, %lo(D_80105D78)($v0)
  .L80102D30:
    /* 530 80102D30 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 534 80102D34 00000000 */   nop
    /* 538 80102D38 1080033C */  lui        $v1, %hi(D_80105D7C)
    /* 53C 80102D3C 01004424 */  addiu      $a0, $v0, 0x1
    /* 540 80102D40 19008010 */  beqz       $a0, .L80102DA8
    /* 544 80102D44 7C5D64AC */   sw        $a0, %lo(D_80105D7C)($v1)
    /* 548 80102D48 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 54C 80102D4C 09008214 */  bne        $a0, $v0, .L80102D74
    /* 550 80102D50 00000000 */   nop
    /* 554 80102D54 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 558 80102D58 28000424 */   addiu     $a0, $zero, 0x28
    /* 55C 80102D5C EAFE030C */  jal        func_800FFBA8
    /* 560 80102D60 00000000 */   nop
    /* 564 80102D64 A2FE030C */  jal        func_800FFA88
    /* 568 80102D68 21200000 */   addu      $a0, $zero, $zero
    /* 56C 80102D6C 600B0408 */  j          .L80102D80
    /* 570 80102D70 1080033C */   lui       $v1, %hi(D_80105D78)
  .L80102D74:
    /* 574 80102D74 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 578 80102D78 07000424 */   addiu     $a0, $zero, 0x7
    /* 57C 80102D7C 1080033C */  lui        $v1, %hi(D_80105D78)
  .L80102D80:
    /* 580 80102D80 02000224 */  addiu      $v0, $zero, 0x2
    /* 584 80102D84 6A0B0408 */  j          .L80102DA8
    /* 588 80102D88 785D62AC */   sw        $v0, %lo(D_80105D78)($v1)
  .L80102D8C:
    /* 58C 80102D8C 74EA030C */  jal        vs_mainmenu_ready
    /* 590 80102D90 00000000 */   nop
    /* 594 80102D94 04004010 */  beqz       $v0, .L80102DA8
    /* 598 80102D98 1080023C */   lui       $v0, %hi(D_80105D7C)
    /* 59C 80102D9C 7C5D428C */  lw         $v0, %lo(D_80105D7C)($v0)
    /* 5A0 80102DA0 6B0B0408 */  j          .L80102DAC
    /* 5A4 80102DA4 00000000 */   nop
  .L80102DA8:
    /* 5A8 80102DA8 21100000 */  addu       $v0, $zero, $zero
  .L80102DAC:
    /* 5AC 80102DAC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 5B0 80102DB0 2800B08F */  lw         $s0, 0x28($sp)
    /* 5B4 80102DB4 0800E003 */  jr         $ra
    /* 5B8 80102DB8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _weaponStatusOptionMenu
