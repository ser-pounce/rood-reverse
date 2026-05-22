nonmatching _warlockMagicMenu, 0x95C

glabel _warlockMagicMenu
    /* 308 80102B08 E8FEBD27 */  addiu      $sp, $sp, -0x118
    /* 30C 80102B0C 21188000 */  addu       $v1, $a0, $zero
    /* 310 80102B10 1401BFAF */  sw         $ra, 0x114($sp)
    /* 314 80102B14 1001BEAF */  sw         $fp, 0x110($sp)
    /* 318 80102B18 0C01B7AF */  sw         $s7, 0x10C($sp)
    /* 31C 80102B1C 0801B6AF */  sw         $s6, 0x108($sp)
    /* 320 80102B20 0401B5AF */  sw         $s5, 0x104($sp)
    /* 324 80102B24 0001B4AF */  sw         $s4, 0x100($sp)
    /* 328 80102B28 FC00B3AF */  sw         $s3, 0xFC($sp)
    /* 32C 80102B2C F800B2AF */  sw         $s2, 0xF8($sp)
    /* 330 80102B30 F400B1AF */  sw         $s1, 0xF4($sp)
    /* 334 80102B34 0C006010 */  beqz       $v1, .L80102B68
    /* 338 80102B38 F000B0AF */   sw        $s0, 0xF0($sp)
    /* 33C 80102B3C 21200000 */  addu       $a0, $zero, $zero
    /* 340 80102B40 01000524 */  addiu      $a1, $zero, 0x1
    /* 344 80102B44 1080023C */  lui        $v0, %hi(forceCursorMemory)
    /* 348 80102B48 02006338 */  xori       $v1, $v1, 0x2
    /* 34C 80102B4C 2B186500 */  sltu       $v1, $v1, $a1
    /* 350 80102B50 4BEA030C */  jal        func_800FA92C
    /* 354 80102B54 F06843AC */   sw        $v1, %lo(forceCursorMemory)($v0)
    /* 358 80102B58 21100000 */  addu       $v0, $zero, $zero
    /* 35C 80102B5C 1080033C */  lui        $v1, %hi(D_801068E8)
    /* 360 80102B60 0D0D0408 */  j          .L80103434
    /* 364 80102B64 E86860AC */   sw        $zero, %lo(D_801068E8)($v1)
  .L80102B68:
    /* 368 80102B68 1080023C */  lui        $v0, %hi(D_801068E8)
    /* 36C 80102B6C E868438C */  lw         $v1, %lo(D_801068E8)($v0)
    /* 370 80102B70 00000000 */  nop
    /* 374 80102B74 0500622C */  sltiu      $v0, $v1, 0x5
    /* 378 80102B78 2D024010 */  beqz       $v0, .L80103430
    /* 37C 80102B7C 1080023C */   lui       $v0, %hi(jtbl_80102818)
    /* 380 80102B80 18284224 */  addiu      $v0, $v0, %lo(jtbl_80102818)
    /* 384 80102B84 80180300 */  sll        $v1, $v1, 2
    /* 388 80102B88 21186200 */  addu       $v1, $v1, $v0
    /* 38C 80102B8C 0000628C */  lw         $v0, 0x0($v1)
    /* 390 80102B90 00000000 */  nop
    /* 394 80102B94 08004000 */  jr         $v0
    /* 398 80102B98 00000000 */   nop
    /* 39C 80102B9C 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 3A0 80102BA0 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* 3A4 80102BA4 00000000 */  nop
    /* 3A8 80102BA8 05004014 */  bnez       $v0, .L80102BC0
    /* 3AC 80102BAC 21980000 */   addu      $s3, $zero, $zero
    /* 3B0 80102BB0 74EA030C */  jal        vs_mainmenu_ready
    /* 3B4 80102BB4 00000000 */   nop
    /* 3B8 80102BB8 1E024010 */  beqz       $v0, .L80103434
    /* 3BC 80102BBC 21100000 */   addu      $v0, $zero, $zero
  .L80102BC0:
    /* 3C0 80102BC0 21886002 */  addu       $s1, $s3, $zero
    /* 3C4 80102BC4 1080023C */  lui        $v0, %hi(_baseStrings)
    /* 3C8 80102BC8 584A5E24 */  addiu      $fp, $v0, %lo(_baseStrings)
    /* 3CC 80102BCC 18001724 */  addiu      $s7, $zero, 0x18
    /* 3D0 80102BD0 7C001624 */  addiu      $s6, $zero, 0x7C
    /* 3D4 80102BD4 04001524 */  addiu      $s5, $zero, 0x4
    /* 3D8 80102BD8 1000AC27 */  addiu      $t4, $sp, 0x10
    /* 3DC 80102BDC E800ACAF */  sw         $t4, 0xE8($sp)
    /* 3E0 80102BE0 21A08001 */  addu       $s4, $t4, $zero
  .L80102BE4:
    /* 3E4 80102BE4 0F800C3C */  lui        $t4, %hi(vs_battle_warlockSpellIds)
    /* 3E8 80102BE8 70BD8C25 */  addiu      $t4, $t4, %lo(vs_battle_warlockSpellIds)
    /* 3EC 80102BEC 21102C02 */  addu       $v0, $s1, $t4
    /* 3F0 80102BF0 05800C3C */  lui        $t4, %hi(vs_main_skills)
    /* 3F4 80102BF4 00005290 */  lbu        $s2, 0x0($v0)
    /* 3F8 80102BF8 DCB98C25 */  addiu      $t4, $t4, %lo(vs_main_skills)
    /* 3FC 80102BFC 40101200 */  sll        $v0, $s2, 1
    /* 400 80102C00 21105200 */  addu       $v0, $v0, $s2
    /* 404 80102C04 80100200 */  sll        $v0, $v0, 2
    /* 408 80102C08 21105200 */  addu       $v0, $v0, $s2
    /* 40C 80102C0C 80100200 */  sll        $v0, $v0, 2
    /* 410 80102C10 21104C00 */  addu       $v0, $v0, $t4
    /* 414 80102C14 0C00428C */  lw         $v0, 0xC($v0)
    /* 418 80102C18 00000000 */  nop
    /* 41C 80102C1C C2130200 */  srl        $v0, $v0, 15
    /* 420 80102C20 01004230 */  andi       $v0, $v0, 0x1
    /* 424 80102C24 20004010 */  beqz       $v0, .L80102CA8
    /* 428 80102C28 21200000 */   addu      $a0, $zero, $zero
    /* 42C 80102C2C 2110DE02 */  addu       $v0, $s6, $fp
    /* 430 80102C30 00004294 */  lhu        $v0, 0x0($v0)
    /* 434 80102C34 21284002 */  addu       $a1, $s2, $zero
    /* 438 80102C38 40100200 */  sll        $v0, $v0, 1
    /* 43C 80102C3C 21105E00 */  addu       $v0, $v0, $fp
    /* 440 80102C40 000082AE */  sw         $v0, 0x0($s4)
    /* 444 80102C44 2110FE02 */  addu       $v0, $s7, $fp
    /* 448 80102C48 E800AC8F */  lw         $t4, 0xE8($sp)
    /* 44C 80102C4C 00004294 */  lhu        $v0, 0x0($v0)
    /* 450 80102C50 21189501 */  addu       $v1, $t4, $s5
    /* 454 80102C54 40100200 */  sll        $v0, $v0, 1
    /* 458 80102C58 21105E00 */  addu       $v0, $v0, $fp
    /* 45C 80102C5C 000062AC */  sw         $v0, 0x0($v1)
    /* 460 80102C60 80181300 */  sll        $v1, $s3, 2
    /* 464 80102C64 A000A227 */  addiu      $v0, $sp, 0xA0
    /* 468 80102C68 21804300 */  addu       $s0, $v0, $v1
    /* 46C 80102C6C 7429020C */  jal        vs_battle_getSkillFlags
    /* 470 80102C70 000000AE */   sw        $zero, 0x0($s0)
    /* 474 80102C74 06004010 */  beqz       $v0, .L80102C90
    /* 478 80102C78 1080023C */   lui       $v0, %hi(_availableWarlockSpells)
    /* 47C 80102C7C 0000028E */  lw         $v0, 0x0($s0)
    /* 480 80102C80 00000000 */  nop
    /* 484 80102C84 01004234 */  ori        $v0, $v0, 0x1
    /* 488 80102C88 000002AE */  sw         $v0, 0x0($s0)
    /* 48C 80102C8C 1080023C */  lui        $v0, %hi(_availableWarlockSpells)
  .L80102C90:
    /* 490 80102C90 38694224 */  addiu      $v0, $v0, %lo(_availableWarlockSpells)
    /* 494 80102C94 21106202 */  addu       $v0, $s3, $v0
    /* 498 80102C98 000052A0 */  sb         $s2, 0x0($v0)
    /* 49C 80102C9C 0800B526 */  addiu      $s5, $s5, 0x8
    /* 4A0 80102CA0 08009426 */  addiu      $s4, $s4, 0x8
    /* 4A4 80102CA4 01007326 */  addiu      $s3, $s3, 0x1
  .L80102CA8:
    /* 4A8 80102CA8 0200F726 */  addiu      $s7, $s7, 0x2
    /* 4AC 80102CAC 01003126 */  addiu      $s1, $s1, 0x1
    /* 4B0 80102CB0 1200222A */  slti       $v0, $s1, 0x12
    /* 4B4 80102CB4 CBFF4014 */  bnez       $v0, .L80102BE4
    /* 4B8 80102CB8 0200D626 */   addiu     $s6, $s6, 0x2
    /* 4BC 80102CBC 0F80023C */  lui        $v0, %hi(D_800F4EA0)
    /* 4C0 80102CC0 A04E428C */  lw         $v0, %lo(D_800F4EA0)($v0)
    /* 4C4 80102CC4 00000000 */  nop
    /* 4C8 80102CC8 B7004230 */  andi       $v0, $v0, 0xB7
    /* 4CC 80102CCC 09004010 */  beqz       $v0, .L80102CF4
    /* 4D0 80102CD0 21880000 */   addu      $s1, $zero, $zero
    /* 4D4 80102CD4 A000A327 */  addiu      $v1, $sp, 0xA0
  .L80102CD8:
    /* 4D8 80102CD8 0000628C */  lw         $v0, 0x0($v1)
    /* 4DC 80102CDC 01003126 */  addiu      $s1, $s1, 0x1
    /* 4E0 80102CE0 01004234 */  ori        $v0, $v0, 0x1
    /* 4E4 80102CE4 000062AC */  sw         $v0, 0x0($v1)
    /* 4E8 80102CE8 1200222A */  slti       $v0, $s1, 0x12
    /* 4EC 80102CEC FAFF4014 */  bnez       $v0, .L80102CD8
    /* 4F0 80102CF0 04006324 */   addiu     $v1, $v1, 0x4
  .L80102CF4:
    /* 4F4 80102CF4 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 4F8 80102CF8 20005024 */  addiu      $s0, $v0, %lo(vs_main_settings)
    /* 4FC 80102CFC 1080023C */  lui        $v0, %hi(forceCursorMemory)
    /* 500 80102D00 F068428C */  lw         $v0, %lo(forceCursorMemory)($v0)
    /* 504 80102D04 01001192 */  lbu        $s1, 0x1($s0)
    /* 508 80102D08 02004010 */  beqz       $v0, .L80102D14
    /* 50C 80102D0C 01000224 */   addiu     $v0, $zero, 0x1
    /* 510 80102D10 010002A2 */  sb         $v0, 0x1($s0)
  .L80102D14:
    /* 514 80102D14 21206002 */  addu       $a0, $s3, $zero
    /* 518 80102D18 07020524 */  addiu      $a1, $zero, 0x207
    /* 51C 80102D1C 1000A627 */  addiu      $a2, $sp, 0x10
    /* 520 80102D20 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 524 80102D24 A000A727 */   addiu     $a3, $sp, 0xA0
    /* 528 80102D28 1080033C */  lui        $v1, %hi(D_801068E8)
    /* 52C 80102D2C 01000224 */  addiu      $v0, $zero, 0x1
    /* 530 80102D30 010011A2 */  sb         $s1, 0x1($s0)
    /* 534 80102D34 0C0D0408 */  j          .L80103430
    /* 538 80102D38 E86862AC */   sw        $v0, %lo(D_801068E8)($v1)
    /* 53C 80102D3C 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 540 80102D40 1080103C */   lui       $s0, %hi(D_801068EC)
    /* 544 80102D44 01004424 */  addiu      $a0, $v0, 0x1
    /* 548 80102D48 4F008010 */  beqz       $a0, .L80102E88
    /* 54C 80102D4C EC6804AE */   sw        $a0, %lo(D_801068EC)($s0)
    /* 550 80102D50 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 554 80102D54 6A4E4390 */  lbu        $v1, %lo(vs_battle_shortcutInvoked)($v0)
    /* 558 80102D58 1080023C */  lui        $v0, %hi(vs_mainMenu_isLevelledSpell)
    /* 55C 80102D5C 06006010 */  beqz       $v1, .L80102D78
    /* 560 80102D60 D42240A0 */   sb        $zero, %lo(vs_mainMenu_isLevelledSpell)($v0)
    /* 564 80102D64 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 568 80102D68 0B008214 */  bne        $a0, $v0, .L80102D98
    /* 56C 80102D6C 1080023C */   lui       $v0, %hi(D_801068EC)
    /* 570 80102D70 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 574 80102D74 EC6802AE */  sw         $v0, %lo(D_801068EC)($s0)
  .L80102D78:
    /* 578 80102D78 EC68038E */  lw         $v1, %lo(D_801068EC)($s0)
    /* 57C 80102D7C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 580 80102D80 05006214 */  bne        $v1, $v0, .L80102D98
    /* 584 80102D84 1080023C */   lui       $v0, %hi(D_801068EC)
    /* 588 80102D88 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 58C 80102D8C 21200000 */   addu      $a0, $zero, $zero
    /* 590 80102D90 160C0408 */  j          .L80103058
    /* 594 80102D94 1080033C */   lui       $v1, %hi(D_801068E8)
  .L80102D98:
    /* 598 80102D98 EC68438C */  lw         $v1, %lo(D_801068EC)($v0)
    /* 59C 80102D9C 00000000 */  nop
    /* 5A0 80102DA0 31006018 */  blez       $v1, .L80102E68
    /* 5A4 80102DA4 21980000 */   addu      $s3, $zero, $zero
    /* 5A8 80102DA8 21804000 */  addu       $s0, $v0, $zero
    /* 5AC 80102DAC 1080023C */  lui        $v0, %hi(levelledSpells)
    /* 5B0 80102DB0 CC685424 */  addiu      $s4, $v0, %lo(levelledSpells)
    /* 5B4 80102DB4 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 5B8 80102DB8 DCB95224 */  addiu      $s2, $v0, %lo(vs_main_skills)
    /* 5BC 80102DBC 1080023C */  lui        $v0, %hi(_availableWarlockSpells)
    /* 5C0 80102DC0 38694224 */  addiu      $v0, $v0, %lo(_availableWarlockSpells)
    /* 5C4 80102DC4 21106200 */  addu       $v0, $v1, $v0
    /* 5C8 80102DC8 0F80033C */  lui        $v1, %hi(D_800F4EE8)
    /* 5CC 80102DCC FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 5D0 80102DD0 E84E7124 */  addiu      $s1, $v1, %lo(D_800F4EE8)
    /* 5D4 80102DD4 EC6802AE */  sw         $v0, %lo(D_801068EC)($s0)
    /* 5D8 80102DD8 21107402 */  addu       $v0, $s3, $s4
  .L80102DDC:
    /* 5DC 80102DDC 00004290 */  lbu        $v0, 0x0($v0)
    /* 5E0 80102DE0 EC68038E */  lw         $v1, %lo(D_801068EC)($s0)
    /* 5E4 80102DE4 00000000 */  nop
    /* 5E8 80102DE8 16006214 */  bne        $v1, $v0, .L80102E44
    /* 5EC 80102DEC 01006224 */   addiu     $v0, $v1, 0x1
    /* 5F0 80102DF0 40180200 */  sll        $v1, $v0, 1
    /* 5F4 80102DF4 21186200 */  addu       $v1, $v1, $v0
    /* 5F8 80102DF8 80180300 */  sll        $v1, $v1, 2
    /* 5FC 80102DFC 21186200 */  addu       $v1, $v1, $v0
    /* 600 80102E00 80180300 */  sll        $v1, $v1, 2
    /* 604 80102E04 21187200 */  addu       $v1, $v1, $s2
    /* 608 80102E08 0C00628C */  lw         $v0, 0xC($v1)
    /* 60C 80102E0C 00000000 */  nop
    /* 610 80102E10 C2130200 */  srl        $v0, $v0, 15
    /* 614 80102E14 01004230 */  andi       $v0, $v0, 0x1
    /* 618 80102E18 0A004010 */  beqz       $v0, .L80102E44
    /* 61C 80102E1C 00000000 */   nop
    /* 620 80102E20 0E002492 */  lbu        $a0, 0xE($s1)
    /* 624 80102E24 4BEA030C */  jal        func_800FA92C
    /* 628 80102E28 02000524 */   addiu     $a1, $zero, 0x2
    /* 62C 80102E2C 1080033C */  lui        $v1, %hi(vs_mainMenu_isLevelledSpell)
    /* 630 80102E30 01000224 */  addiu      $v0, $zero, 0x1
    /* 634 80102E34 D42262A0 */  sb         $v0, %lo(vs_mainMenu_isLevelledSpell)($v1)
    /* 638 80102E38 1080033C */  lui        $v1, %hi(D_801068E8)
    /* 63C 80102E3C 03000224 */  addiu      $v0, $zero, 0x3
    /* 640 80102E40 E86862AC */  sw         $v0, %lo(D_801068E8)($v1)
  .L80102E44:
    /* 644 80102E44 01007326 */  addiu      $s3, $s3, 0x1
    /* 648 80102E48 0700622A */  slti       $v0, $s3, 0x7
    /* 64C 80102E4C E3FF4014 */  bnez       $v0, .L80102DDC
    /* 650 80102E50 21107402 */   addu      $v0, $s3, $s4
    /* 654 80102E54 1080023C */  lui        $v0, %hi(D_801068E8)
    /* 658 80102E58 E868438C */  lw         $v1, %lo(D_801068E8)($v0)
    /* 65C 80102E5C 03000224 */  addiu      $v0, $zero, 0x3
    /* 660 80102E60 74016210 */  beq        $v1, $v0, .L80103434
    /* 664 80102E64 21100000 */   addu      $v0, $zero, $zero
  .L80102E68:
    /* 668 80102E68 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 66C 80102E6C 28000424 */   addiu     $a0, $zero, 0x28
    /* 670 80102E70 EAFE030C */  jal        func_800FFBA8
    /* 674 80102E74 00000000 */   nop
    /* 678 80102E78 A2FE030C */  jal        func_800FFA88
    /* 67C 80102E7C 21200000 */   addu      $a0, $zero, $zero
    /* 680 80102E80 160C0408 */  j          .L80103058
    /* 684 80102E84 1080033C */   lui       $v1, %hi(D_801068E8)
  .L80102E88:
    /* 688 80102E88 1080103C */  lui        $s0, %hi(_availableWarlockSpells)
    /* 68C 80102E8C 2C02040C */  jal        func_801008B0
    /* 690 80102E90 38691026 */   addiu     $s0, $s0, %lo(_availableWarlockSpells)
    /* 694 80102E94 21105000 */  addu       $v0, $v0, $s0
    /* 698 80102E98 00005190 */  lbu        $s1, 0x0($v0)
    /* 69C 80102E9C 21980000 */  addu       $s3, $zero, $zero
    /* 6A0 80102EA0 1080023C */  lui        $v0, %hi(levelledSpells)
    /* 6A4 80102EA4 CC684324 */  addiu      $v1, $v0, %lo(levelledSpells)
    /* 6A8 80102EA8 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 6AC 80102EAC DCB94424 */  addiu      $a0, $v0, %lo(vs_main_skills)
    /* 6B0 80102EB0 21106302 */  addu       $v0, $s3, $v1
  .L80102EB4:
    /* 6B4 80102EB4 00004290 */  lbu        $v0, 0x0($v0)
    /* 6B8 80102EB8 00000000 */  nop
    /* 6BC 80102EBC 10002216 */  bne        $s1, $v0, .L80102F00
    /* 6C0 80102EC0 01007326 */   addiu     $s3, $s3, 0x1
    /* 6C4 80102EC4 01002226 */  addiu      $v0, $s1, 0x1
    /* 6C8 80102EC8 40180200 */  sll        $v1, $v0, 1
    /* 6CC 80102ECC 21186200 */  addu       $v1, $v1, $v0
    /* 6D0 80102ED0 80180300 */  sll        $v1, $v1, 2
    /* 6D4 80102ED4 21186200 */  addu       $v1, $v1, $v0
    /* 6D8 80102ED8 80180300 */  sll        $v1, $v1, 2
    /* 6DC 80102EDC 21186400 */  addu       $v1, $v1, $a0
    /* 6E0 80102EE0 0C00628C */  lw         $v0, 0xC($v1)
    /* 6E4 80102EE4 00000000 */  nop
    /* 6E8 80102EE8 C2130200 */  srl        $v0, $v0, 15
    /* 6EC 80102EEC 01004230 */  andi       $v0, $v0, 0x1
    /* 6F0 80102EF0 06004010 */  beqz       $v0, .L80102F0C
    /* 6F4 80102EF4 00000000 */   nop
    /* 6F8 80102EF8 C30B0408 */  j          .L80102F0C
    /* 6FC 80102EFC 23881100 */   negu      $s1, $s1
  .L80102F00:
    /* 700 80102F00 0700622A */  slti       $v0, $s3, 0x7
    /* 704 80102F04 EBFF4014 */  bnez       $v0, .L80102EB4
    /* 708 80102F08 21106302 */   addu      $v0, $s3, $v1
  .L80102F0C:
    /* 70C 80102F0C 210A040C */  jal        _setMPCost
    /* 710 80102F10 21202002 */   addu      $a0, $s1, $zero
    /* 714 80102F14 0D0D0408 */  j          .L80103434
    /* 718 80102F18 21100000 */   addu      $v0, $zero, $zero
    /* 71C 80102F1C 74EA030C */  jal        vs_mainmenu_ready
    /* 720 80102F20 00000000 */   nop
    /* 724 80102F24 42014010 */  beqz       $v0, .L80103430
    /* 728 80102F28 1080023C */   lui       $v0, %hi(D_801068EC)
    /* 72C 80102F2C EC68428C */  lw         $v0, %lo(D_801068EC)($v0)
    /* 730 80102F30 0D0D0408 */  j          .L80103434
    /* 734 80102F34 00000000 */   nop
    /* 738 80102F38 74EA030C */  jal        vs_mainmenu_ready
    /* 73C 80102F3C 00000000 */   nop
    /* 740 80102F40 3B014010 */  beqz       $v0, .L80103430
    /* 744 80102F44 0580033C */   lui       $v1, %hi(vs_main_skills)
    /* 748 80102F48 1080023C */  lui        $v0, %hi(D_801068EC)
    /* 74C 80102F4C EC68448C */  lw         $a0, %lo(D_801068EC)($v0)
    /* 750 80102F50 DCB96524 */  addiu      $a1, $v1, %lo(vs_main_skills)
    /* 754 80102F54 02008324 */  addiu      $v1, $a0, 0x2
    /* 758 80102F58 40100300 */  sll        $v0, $v1, 1
    /* 75C 80102F5C 21104300 */  addu       $v0, $v0, $v1
    /* 760 80102F60 80100200 */  sll        $v0, $v0, 2
    /* 764 80102F64 21104300 */  addu       $v0, $v0, $v1
    /* 768 80102F68 80100200 */  sll        $v0, $v0, 2
    /* 76C 80102F6C 21104500 */  addu       $v0, $v0, $a1
    /* 770 80102F70 0C00428C */  lw         $v0, 0xC($v0)
    /* 774 80102F74 00000000 */  nop
    /* 778 80102F78 C2130200 */  srl        $v0, $v0, 15
    /* 77C 80102F7C 01004230 */  andi       $v0, $v0, 0x1
    /* 780 80102F80 0F004010 */  beqz       $v0, .L80102FC0
    /* 784 80102F84 02001124 */   addiu     $s1, $zero, 0x2
    /* 788 80102F88 03008224 */  addiu      $v0, $a0, 0x3
    /* 78C 80102F8C 40180200 */  sll        $v1, $v0, 1
    /* 790 80102F90 21186200 */  addu       $v1, $v1, $v0
    /* 794 80102F94 04182302 */  sllv       $v1, $v1, $s1
    /* 798 80102F98 21186200 */  addu       $v1, $v1, $v0
    /* 79C 80102F9C 04182302 */  sllv       $v1, $v1, $s1
    /* 7A0 80102FA0 21186500 */  addu       $v1, $v1, $a1
    /* 7A4 80102FA4 0C00628C */  lw         $v0, 0xC($v1)
    /* 7A8 80102FA8 00000000 */  nop
    /* 7AC 80102FAC C2130200 */  srl        $v0, $v0, 15
    /* 7B0 80102FB0 01004230 */  andi       $v0, $v0, 0x1
    /* 7B4 80102FB4 02004010 */  beqz       $v0, .L80102FC0
    /* 7B8 80102FB8 03001124 */   addiu     $s1, $zero, 0x3
    /* 7BC 80102FBC 04001124 */  addiu      $s1, $zero, 0x4
  .L80102FC0:
    /* 7C0 80102FC0 0F80023C */  lui        $v0, %hi(D_800F4EE8)
    /* 7C4 80102FC4 E84E4324 */  addiu      $v1, $v0, %lo(D_800F4EE8)
    /* 7C8 80102FC8 0C006290 */  lbu        $v0, 0xC($v1)
    /* 7CC 80102FCC 00000000 */  nop
    /* 7D0 80102FD0 2A105100 */  slt        $v0, $v0, $s1
    /* 7D4 80102FD4 03004014 */  bnez       $v0, .L80102FE4
    /* 7D8 80102FD8 0D0071A0 */   sb        $s1, 0xD($v1)
    /* 7DC 80102FDC FFFF2226 */  addiu      $v0, $s1, -0x1
    /* 7E0 80102FE0 0C0062A0 */  sb         $v0, 0xC($v1)
  .L80102FE4:
    /* 7E4 80102FE4 1080023C */  lui        $v0, %hi(D_8010694A)
    /* 7E8 80102FE8 1080033C */  lui        $v1, %hi(D_801068E8)
    /* 7EC 80102FEC 4A6940A0 */  sb         $zero, %lo(D_8010694A)($v0)
    /* 7F0 80102FF0 04000224 */  addiu      $v0, $zero, 0x4
    /* 7F4 80102FF4 0C0D0408 */  j          .L80103430
    /* 7F8 80102FF8 E86862AC */   sw        $v0, %lo(D_801068E8)($v1)
    /* 7FC 80102FFC 0F80023C */  lui        $v0, %hi(D_800F4EE8)
    /* 800 80103000 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 804 80103004 0680033C */  lui        $v1, %hi(vs_main_buttonsPressed)
    /* 808 80103008 0C005190 */  lbu        $s1, 0xC($v0)
    /* 80C 8010300C D0E1638C */  lw         $v1, %lo(vs_main_buttonsPressed)($v1)
    /* 810 80103010 0D005390 */  lbu        $s3, 0xD($v0)
    /* 814 80103014 10006230 */  andi       $v0, $v1, 0x10
    /* 818 80103018 12004010 */  beqz       $v0, .L80103064
    /* 81C 8010301C 40006230 */   andi      $v0, $v1, 0x40
    /* 820 80103020 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 824 80103024 00000000 */   nop
    /* 828 80103028 28000424 */  addiu      $a0, $zero, 0x28
    /* 82C 8010302C 1080023C */  lui        $v0, %hi(vs_mainMenu_isLevelledSpell)
    /* 830 80103030 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 834 80103034 D42240A0 */   sb        $zero, %lo(vs_mainMenu_isLevelledSpell)($v0)
    /* 838 80103038 EAFE030C */  jal        func_800FFBA8
    /* 83C 8010303C 00000000 */   nop
    /* 840 80103040 A2FE030C */  jal        func_800FFA88
    /* 844 80103044 21200000 */   addu      $a0, $zero, $zero
    /* 848 80103048 1080033C */  lui        $v1, %hi(D_801068EC)
    /* 84C 8010304C FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 850 80103050 EC6862AC */  sw         $v0, %lo(D_801068EC)($v1)
    /* 854 80103054 1080033C */  lui        $v1, %hi(D_801068E8)
  .L80103058:
    /* 858 80103058 02000224 */  addiu      $v0, $zero, 0x2
    /* 85C 8010305C 0C0D0408 */  j          .L80103430
    /* 860 80103060 E86862AC */   sw        $v0, %lo(D_801068E8)($v1)
  .L80103064:
    /* 864 80103064 0B004010 */  beqz       $v0, .L80103094
    /* 868 80103068 20006230 */   andi      $v0, $v1, 0x20
    /* 86C 8010306C BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 870 80103070 14001124 */   addiu     $s1, $zero, 0x14
  .L80103074:
    /* 874 80103074 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 878 80103078 21202002 */   addu      $a0, $s1, $zero
    /* 87C 8010307C 01003126 */  addiu      $s1, $s1, 0x1
    /* 880 80103080 1E00222A */  slti       $v0, $s1, 0x1E
    /* 884 80103084 FBFF4014 */  bnez       $v0, .L80103074
    /* 888 80103088 1080023C */   lui       $v0, %hi(D_801068E8)
    /* 88C 8010308C 0C0D0408 */  j          .L80103430
    /* 890 80103090 E86840AC */   sw        $zero, %lo(D_801068E8)($v0)
  .L80103094:
    /* 894 80103094 1A004010 */  beqz       $v0, .L80103100
    /* 898 80103098 1080103C */   lui       $s0, %hi(D_801068EC)
    /* 89C 8010309C EC68058E */  lw         $a1, %lo(D_801068EC)($s0)
    /* 8A0 801030A0 21200000 */  addu       $a0, $zero, $zero
    /* 8A4 801030A4 7429020C */  jal        vs_battle_getSkillFlags
    /* 8A8 801030A8 2128B100 */   addu      $a1, $a1, $s1
    /* 8AC 801030AC 12004014 */  bnez       $v0, .L801030F8
    /* 8B0 801030B0 00000000 */   nop
    /* 8B4 801030B4 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 8B8 801030B8 00000000 */   nop
    /* 8BC 801030BC 28000424 */  addiu      $a0, $zero, 0x28
    /* 8C0 801030C0 1080023C */  lui        $v0, %hi(vs_mainMenu_isLevelledSpell)
    /* 8C4 801030C4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 8C8 801030C8 D42240A0 */   sb        $zero, %lo(vs_mainMenu_isLevelledSpell)($v0)
    /* 8CC 801030CC EAFE030C */  jal        func_800FFBA8
    /* 8D0 801030D0 00000000 */   nop
    /* 8D4 801030D4 A2FE030C */  jal        func_800FFA88
    /* 8D8 801030D8 21200000 */   addu      $a0, $zero, $zero
    /* 8DC 801030DC 1080043C */  lui        $a0, %hi(D_801068E8)
    /* 8E0 801030E0 EC68028E */  lw         $v0, %lo(D_801068EC)($s0)
    /* 8E4 801030E4 02000324 */  addiu      $v1, $zero, 0x2
    /* 8E8 801030E8 E86883AC */  sw         $v1, %lo(D_801068E8)($a0)
    /* 8EC 801030EC 21105100 */  addu       $v0, $v0, $s1
    /* 8F0 801030F0 0C0D0408 */  j          .L80103430
    /* 8F4 801030F4 EC6802AE */   sw        $v0, %lo(D_801068EC)($s0)
  .L801030F8:
    /* 8F8 801030F8 B800030C */  jal        vs_battle_playInvalidSfx
    /* 8FC 801030FC 00000000 */   nop
  .L80103100:
    /* 900 80103100 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 904 80103104 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 908 80103108 00000000 */  nop
    /* 90C 8010310C 00204230 */  andi       $v0, $v0, 0x2000
    /* 910 80103110 05004010 */  beqz       $v0, .L80103128
    /* 914 80103114 FFFF6226 */   addiu     $v0, $s3, -0x1
    /* 918 80103118 2A102202 */  slt        $v0, $s1, $v0
    /* 91C 8010311C 03004010 */  beqz       $v0, .L8010312C
    /* 920 80103120 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 924 80103124 01003126 */  addiu      $s1, $s1, 0x1
  .L80103128:
    /* 928 80103128 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L8010312C:
    /* 92C 8010312C DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 930 80103130 00000000 */  nop
    /* 934 80103134 00804230 */  andi       $v0, $v0, 0x8000
    /* 938 80103138 05004010 */  beqz       $v0, .L80103150
    /* 93C 8010313C 0F80023C */   lui       $v0, %hi(D_800F4EE8)
    /* 940 80103140 0400201A */  blez       $s1, .L80103154
    /* 944 80103144 E84E5024 */   addiu     $s0, $v0, %lo(D_800F4EE8)
    /* 948 80103148 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 94C 8010314C 0F80023C */  lui        $v0, %hi(D_800F4EE8)
  .L80103150:
    /* 950 80103150 E84E5024 */  addiu      $s0, $v0, %lo(D_800F4EE8)
  .L80103154:
    /* 954 80103154 0C000292 */  lbu        $v0, 0xC($s0)
    /* 958 80103158 00000000 */  nop
    /* 95C 8010315C 04002212 */  beq        $s1, $v0, .L80103170
    /* 960 80103160 00000000 */   nop
    /* 964 80103164 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 968 80103168 00000000 */   nop
    /* 96C 8010316C 0C0011A2 */  sb         $s1, 0xC($s0)
  .L80103170:
    /* 970 80103170 21800000 */  addu       $s0, $zero, $zero
    /* 974 80103174 60001224 */  addiu      $s2, $zero, 0x60
    /* 978 80103178 66001E24 */  addiu      $fp, $zero, 0x66
    /* 97C 8010317C 1080023C */  lui        $v0, %hi(D_801068EC)
    /* 980 80103180 EC68448C */  lw         $a0, %lo(D_801068EC)($v0)
    /* 984 80103184 63001524 */  addiu      $s5, $zero, 0x63
    /* 988 80103188 210A040C */  jal        _setMPCost
    /* 98C 8010318C 21209100 */   addu      $a0, $a0, $s1
    /* 990 80103190 801F033C */  lui        $v1, (0x1F800004 >> 16)
    /* 994 80103194 0400628C */  lw         $v0, (0x1F800004 & 0xFFFF)($v1)
    /* 998 80103198 1080143C */  lui        $s4, %hi(spellLevels)
    /* 99C 8010319C D4689426 */  addiu      $s4, $s4, %lo(spellLevels)
    /* 9A0 801031A0 FCFF5624 */  addiu      $s6, $v0, -0x4
  .L801031A4:
    /* 9A4 801031A4 2A103002 */  slt        $v0, $s1, $s0
    /* 9A8 801031A8 21004014 */  bnez       $v0, .L80103230
    /* 9AC 801031AC 21B80000 */   addu      $s7, $zero, $zero
    /* 9B0 801031B0 67000C3C */  lui        $t4, (0x670000 >> 16)
    /* 9B4 801031B4 2528AC02 */  or         $a1, $s5, $t4
    /* 9B8 801031B8 0000848E */  lw         $a0, 0x0($s4)
    /* 9BC 801031BC 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 9C0 801031C0 2130E002 */   addu      $a2, $s7, $zero
    /* 9C4 801031C4 6400053C */  lui        $a1, (0x640000 >> 16)
    /* 9C8 801031C8 25284502 */  or         $a1, $s2, $a1
    /* 9CC 801031CC 1000063C */  lui        $a2, (0x100020 >> 16)
    /* 9D0 801031D0 10800C3C */  lui        $t4, %hi(D_8010694A)
    /* 9D4 801031D4 2000C634 */  ori        $a2, $a2, (0x100020 & 0xFFFF)
    /* 9D8 801031D8 4A698291 */  lbu        $v0, %lo(D_8010694A)($t4)
    /* 9DC 801031DC 0F800C3C */  lui        $t4, %hi(D_800EC270)
    /* 9E0 801031E0 70C28C25 */  addiu      $t4, $t4, %lo(D_800EC270)
    /* 9E4 801031E4 21104C00 */  addu       $v0, $v0, $t4
    /* 9E8 801031E8 00004490 */  lbu        $a0, 0x0($v0)
    /* 9EC 801031EC 8900030C */  jal        func_800C0224
    /* 9F0 801031F0 2138C002 */   addu      $a3, $s6, $zero
    /* 9F4 801031F4 21584000 */  addu       $t3, $v0, $zero
    /* 9F8 801031F8 FD37023C */  lui        $v0, (0x37FD70C0 >> 16)
    /* 9FC 801031FC C0704234 */  ori        $v0, $v0, (0x37FD70C0 & 0xFFFF)
    /* A00 80103200 10800C3C */  lui        $t4, %hi(D_8010694A)
    /* A04 80103204 100062AD */  sw         $v0, 0x10($t3)
    /* A08 80103208 4A698291 */  lbu        $v0, %lo(D_8010694A)($t4)
    /* A0C 8010320C 05001116 */  bne        $s0, $s1, .L80103224
    /* A10 80103210 00000000 */   nop
    /* A14 80103214 01004224 */  addiu      $v0, $v0, 0x1
    /* A18 80103218 0F004230 */  andi       $v0, $v0, 0xF
    /* A1C 8010321C B30C0408 */  j          .L801032CC
    /* A20 80103220 4A6982A1 */   sb        $v0, %lo(D_8010694A)($t4)
  .L80103224:
    /* A24 80103224 0F004230 */  andi       $v0, $v0, 0xF
    /* A28 80103228 B30C0408 */  j          .L801032CC
    /* A2C 8010322C 4A6982A1 */   sb        $v0, %lo(D_8010694A)($t4)
  .L80103230:
    /* A30 80103230 2A101302 */  slt        $v0, $s0, $s3
    /* A34 80103234 10004010 */  beqz       $v0, .L80103278
    /* A38 80103238 67000C3C */   lui       $t4, (0x670000 >> 16)
    /* A3C 8010323C 2528AC02 */  or         $a1, $s5, $t4
    /* A40 80103240 0000848E */  lw         $a0, 0x0($s4)
    /* A44 80103244 0A1A030C */  jal        vs_battle_renderTextRaw
    /* A48 80103248 21300000 */   addu      $a2, $zero, $zero
    /* A4C 8010324C 40000424 */  addiu      $a0, $zero, 0x40
    /* A50 80103250 6400053C */  lui        $a1, (0x640000 >> 16)
    /* A54 80103254 25284502 */  or         $a1, $s2, $a1
    /* A58 80103258 1000063C */  lui        $a2, (0x100020 >> 16)
    /* A5C 8010325C 2000C634 */  ori        $a2, $a2, (0x100020 & 0xFFFF)
    /* A60 80103260 8900030C */  jal        func_800C0224
    /* A64 80103264 2138C002 */   addu      $a3, $s6, $zero
    /* A68 80103268 21584000 */  addu       $t3, $v0, $zero
    /* A6C 8010326C FE37023C */  lui        $v0, (0x37FE70C0 >> 16)
    /* A70 80103270 B20C0408 */  j          .L801032C8
    /* A74 80103274 C0704234 */   ori       $v0, $v0, (0x37FE70C0 & 0xFFFF)
  .L80103278:
    /* A78 80103278 01001724 */  addiu      $s7, $zero, 0x1
    /* A7C 8010327C 2528CC03 */  or         $a1, $fp, $t4
    /* A80 80103280 10800C3C */  lui        $t4, %hi(spellLevels)
    /* A84 80103284 D4688C25 */  addiu      $t4, $t4, %lo(spellLevels)
    /* A88 80103288 1000848D */  lw         $a0, 0x10($t4)
    /* A8C 8010328C 0A1A030C */  jal        vs_battle_renderTextRaw
    /* A90 80103290 21300000 */   addu      $a2, $zero, $zero
    /* A94 80103294 21200000 */  addu       $a0, $zero, $zero
    /* A98 80103298 6400053C */  lui        $a1, (0x640000 >> 16)
    /* A9C 8010329C 25284502 */  or         $a1, $s2, $a1
    /* AA0 801032A0 1000063C */  lui        $a2, (0x100020 >> 16)
    /* AA4 801032A4 2000C634 */  ori        $a2, $a2, (0x100020 & 0xFFFF)
    /* AA8 801032A8 8900030C */  jal        func_800C0224
    /* AAC 801032AC 2138C002 */   addu      $a3, $s6, $zero
    /* AB0 801032B0 21584000 */  addu       $t3, $v0, $zero
    /* AB4 801032B4 6064033C */  lui        $v1, (0x64602000 >> 16)
    /* AB8 801032B8 00206334 */  ori        $v1, $v1, (0x64602000 & 0xFFFF)
    /* ABC 801032BC FE37023C */  lui        $v0, (0x37FE70C0 >> 16)
    /* AC0 801032C0 C0704234 */  ori        $v0, $v0, (0x37FE70C0 & 0xFFFF)
    /* AC4 801032C4 040063AD */  sw         $v1, 0x4($t3)
  .L801032C8:
    /* AC8 801032C8 100062AD */  sw         $v0, 0x10($t3)
  .L801032CC:
    /* ACC 801032CC F5370C3C */  lui        $t4, (0x37F50000 >> 16)
    /* AD0 801032D0 F4FF6295 */  lhu        $v0, -0xC($t3)
    /* AD4 801032D4 ECFF638D */  lw         $v1, -0x14($t3)
    /* AD8 801032D8 25104C00 */  or         $v0, $v0, $t4
    /* ADC 801032DC 00020C3C */  lui        $t4, (0x2000000 >> 16)
    /* AE0 801032E0 25186C00 */  or         $v1, $v1, $t4
    /* AE4 801032E4 F4FF62AD */  sw         $v0, -0xC($t3)
    /* AE8 801032E8 E0FF6295 */  lhu        $v0, -0x20($t3)
    /* AEC 801032EC F5370C3C */  lui        $t4, (0x37F50000 >> 16)
    /* AF0 801032F0 ECFF63AD */  sw         $v1, -0x14($t3)
    /* AF4 801032F4 D8FF638D */  lw         $v1, -0x28($t3)
    /* AF8 801032F8 25104C00 */  or         $v0, $v0, $t4
    /* AFC 801032FC 00020C3C */  lui        $t4, (0x2000000 >> 16)
    /* B00 80103300 25186C00 */  or         $v1, $v1, $t4
    /* B04 80103304 E0FF62AD */  sw         $v0, -0x20($t3)
    /* B08 80103308 0500E012 */  beqz       $s7, .L80103320
    /* B0C 8010330C D8FF63AD */   sw        $v1, -0x28($t3)
    /* B10 80103310 00E1023C */  lui        $v0, (0xE100002C >> 16)
    /* B14 80103314 2C004234 */  ori        $v0, $v0, (0xE100002C & 0xFFFF)
    /* B18 80103318 D30C0408 */  j          .L8010334C
    /* B1C 8010331C D0FF62AD */   sw        $v0, -0x30($t3)
  .L80103320:
    /* B20 80103320 00E1023C */  lui        $v0, (0xE100002C >> 16)
    /* B24 80103324 2C004234 */  ori        $v0, $v0, (0xE100002C & 0xFFFF)
    /* B28 80103328 F5370C3C */  lui        $t4, (0x37F50000 >> 16)
    /* B2C 8010332C BCFF62AD */  sw         $v0, -0x44($t3)
    /* B30 80103330 CCFF6295 */  lhu        $v0, -0x34($t3)
    /* B34 80103334 C4FF638D */  lw         $v1, -0x3C($t3)
    /* B38 80103338 25104C00 */  or         $v0, $v0, $t4
    /* B3C 8010333C 00020C3C */  lui        $t4, (0x2000000 >> 16)
    /* B40 80103340 25186C00 */  or         $v1, $v1, $t4
    /* B44 80103344 CCFF62AD */  sw         $v0, -0x34($t3)
    /* B48 80103348 C4FF63AD */  sw         $v1, -0x3C($t3)
  .L8010334C:
    /* B4C 8010334C 20005226 */  addiu      $s2, $s2, 0x20
    /* B50 80103350 2000DE27 */  addiu      $fp, $fp, 0x20
    /* B54 80103354 04009426 */  addiu      $s4, $s4, 0x4
    /* B58 80103358 01001026 */  addiu      $s0, $s0, 0x1
    /* B5C 8010335C 0400022A */  slti       $v0, $s0, 0x4
    /* B60 80103360 90FF4014 */  bnez       $v0, .L801031A4
    /* B64 80103364 2000B526 */   addiu     $s5, $s5, 0x20
    /* B68 80103368 80000424 */  addiu      $a0, $zero, 0x80
    /* B6C 8010336C 6400053C */  lui        $a1, (0x640050 >> 16)
    /* B70 80103370 5000A534 */  ori        $a1, $a1, (0x640050 & 0xFFFF)
    /* B74 80103374 1000063C */  lui        $a2, (0x100010 >> 16)
    /* B78 80103378 1000C634 */  ori        $a2, $a2, (0x100010 & 0xFFFF)
    /* B7C 8010337C 8900030C */  jal        func_800C0224
    /* B80 80103380 2138C002 */   addu      $a3, $s6, $zero
    /* B84 80103384 21584000 */  addu       $t3, $v0, $zero
    /* B88 80103388 FD37023C */  lui        $v0, (0x37FD3050 >> 16)
    /* B8C 8010338C 50304234 */  ori        $v0, $v0, (0x37FD3050 & 0xFFFF)
    /* B90 80103390 100062AD */  sw         $v0, 0x10($t3)
    /* B94 80103394 18006B25 */  addiu      $t3, $t3, 0x18
    /* B98 80103398 FF000A3C */  lui        $t2, (0xFFFFFF >> 16)
    /* B9C 8010339C FFFF4A35 */  ori        $t2, $t2, (0xFFFFFF & 0xFFFF)
    /* BA0 801033A0 802C093C */  lui        $t1, (0x2C808080 >> 16)
    /* BA4 801033A4 80802935 */  ori        $t1, $t1, (0x2C808080 & 0xFFFF)
    /* BA8 801033A8 6400083C */  lui        $t0, (0x6400E0 >> 16)
    /* BAC 801033AC E0000835 */  ori        $t0, $t0, (0x6400E0 & 0xFFFF)
    /* BB0 801033B0 FD37073C */  lui        $a3, (0x37FD305F >> 16)
    /* BB4 801033B4 5F30E734 */  ori        $a3, $a3, (0x37FD305F & 0xFFFF)
    /* BB8 801033B8 6400063C */  lui        $a2, (0x6400F0 >> 16)
    /* BBC 801033BC F000C634 */  ori        $a2, $a2, (0x6400F0 & 0xFFFF)
    /* BC0 801033C0 0C00043C */  lui        $a0, (0xC304F >> 16)
    /* BC4 801033C4 4F308434 */  ori        $a0, $a0, (0xC304F & 0xFFFF)
    /* BC8 801033C8 7400023C */  lui        $v0, (0x7400E0 >> 16)
    /* BCC 801033CC E0004234 */  ori        $v0, $v0, (0x7400E0 & 0xFFFF)
    /* BD0 801033D0 7400053C */  lui        $a1, (0x7400F0 >> 16)
    /* BD4 801033D4 0000C38E */  lw         $v1, 0x0($s6)
    /* BD8 801033D8 F000A534 */  ori        $a1, $a1, (0x7400F0 & 0xFFFF)
    /* BDC 801033DC 180062AD */  sw         $v0, 0x18($t3)
    /* BE0 801033E0 5F400224 */  addiu      $v0, $zero, 0x405F
    /* BE4 801033E4 1C0062AD */  sw         $v0, 0x1C($t3)
    /* BE8 801033E8 4F400224 */  addiu      $v0, $zero, 0x404F
    /* BEC 801033EC 240062AD */  sw         $v0, 0x24($t3)
    /* BF0 801033F0 0009023C */  lui        $v0, (0x9000000 >> 16)
    /* BF4 801033F4 040069AD */  sw         $t1, 0x4($t3)
    /* BF8 801033F8 080068AD */  sw         $t0, 0x8($t3)
    /* BFC 801033FC 0C0067AD */  sw         $a3, 0xC($t3)
    /* C00 80103400 100066AD */  sw         $a2, 0x10($t3)
    /* C04 80103404 140064AD */  sw         $a0, 0x14($t3)
    /* C08 80103408 200065AD */  sw         $a1, 0x20($t3)
    /* C0C 8010340C 24186A00 */  and        $v1, $v1, $t2
    /* C10 80103410 25186200 */  or         $v1, $v1, $v0
    /* C14 80103414 00120B00 */  sll        $v0, $t3, 8
    /* C18 80103418 02120200 */  srl        $v0, $v0, 8
    /* C1C 8010341C 000063AD */  sw         $v1, 0x0($t3)
    /* C20 80103420 801F033C */  lui        $v1, (0x1F800000 >> 16)
    /* C24 80103424 0000C2AE */  sw         $v0, 0x0($s6)
    /* C28 80103428 28006225 */  addiu      $v0, $t3, 0x28
    /* C2C 8010342C 000062AC */  sw         $v0, (0x1F800000 & 0xFFFF)($v1)
  .L80103430:
    /* C30 80103430 21100000 */  addu       $v0, $zero, $zero
  .L80103434:
    /* C34 80103434 1401BF8F */  lw         $ra, 0x114($sp)
    /* C38 80103438 1001BE8F */  lw         $fp, 0x110($sp)
    /* C3C 8010343C 0C01B78F */  lw         $s7, 0x10C($sp)
    /* C40 80103440 0801B68F */  lw         $s6, 0x108($sp)
    /* C44 80103444 0401B58F */  lw         $s5, 0x104($sp)
    /* C48 80103448 0001B48F */  lw         $s4, 0x100($sp)
    /* C4C 8010344C FC00B38F */  lw         $s3, 0xFC($sp)
    /* C50 80103450 F800B28F */  lw         $s2, 0xF8($sp)
    /* C54 80103454 F400B18F */  lw         $s1, 0xF4($sp)
    /* C58 80103458 F000B08F */  lw         $s0, 0xF0($sp)
    /* C5C 8010345C 0800E003 */  jr         $ra
    /* C60 80103460 1801BD27 */   addiu     $sp, $sp, 0x118
endlabel _warlockMagicMenu
