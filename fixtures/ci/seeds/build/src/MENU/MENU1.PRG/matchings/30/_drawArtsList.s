nonmatching _drawArtsList, 0x51C

glabel _drawArtsList
    /* 24C 80102A4C 80FFBD27 */  addiu      $sp, $sp, -0x80
    /* 250 80102A50 5800B0AF */  sw         $s0, 0x58($sp)
    /* 254 80102A54 21808000 */  addu       $s0, $a0, $zero
    /* 258 80102A58 7C00BFAF */  sw         $ra, 0x7C($sp)
    /* 25C 80102A5C 7800BEAF */  sw         $fp, 0x78($sp)
    /* 260 80102A60 7400B7AF */  sw         $s7, 0x74($sp)
    /* 264 80102A64 7000B6AF */  sw         $s6, 0x70($sp)
    /* 268 80102A68 6C00B5AF */  sw         $s5, 0x6C($sp)
    /* 26C 80102A6C 6800B4AF */  sw         $s4, 0x68($sp)
    /* 270 80102A70 6400B3AF */  sw         $s3, 0x64($sp)
    /* 274 80102A74 6000B2AF */  sw         $s2, 0x60($sp)
    /* 278 80102A78 2A000012 */  beqz       $s0, .L80102B24
    /* 27C 80102A7C 5C00B1AF */   sw        $s1, 0x5C($sp)
    /* 280 80102A80 03411000 */  sra        $t0, $s0, 4
    /* 284 80102A84 0F001032 */  andi       $s0, $s0, 0xF
    /* 288 80102A88 0A000424 */  addiu      $a0, $zero, 0xA
    /* 28C 80102A8C 40010524 */  addiu      $a1, $zero, 0x140
    /* 290 80102A90 22000624 */  addiu      $a2, $zero, 0x22
    /* 294 80102A94 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 298 80102A98 1080023C */  lui        $v0, %hi(D_8010452C)
    /* 29C 80102A9C 1080033C */  lui        $v1, %hi(D_8010452D)
    /* 2A0 80102AA0 2C4540A0 */  sb         $zero, %lo(D_8010452C)($v0)
    /* 2A4 80102AA4 21108000 */  addu       $v0, $a0, $zero
    /* 2A8 80102AA8 2D4562A0 */  sb         $v0, %lo(D_8010452D)($v1)
    /* 2AC 80102AAC 1080023C */  lui        $v0, %hi(D_80104508)
    /* 2B0 80102AB0 084548AC */  sw         $t0, %lo(D_80104508)($v0)
    /* 2B4 80102AB4 08000224 */  addiu      $v0, $zero, 0x8
    /* 2B8 80102AB8 1080083C */  lui        $t0, %hi(_strings)
    /* 2BC 80102ABC 78340825 */  addiu      $t0, $t0, %lo(_strings)
    /* 2C0 80102AC0 FFFF0326 */  addiu      $v1, $s0, -0x1
    /* 2C4 80102AC4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2C8 80102AC8 40100300 */  sll        $v0, $v1, 1
    /* 2CC 80102ACC 21104300 */  addu       $v0, $v0, $v1
    /* 2D0 80102AD0 40100200 */  sll        $v0, $v0, 1
    /* 2D4 80102AD4 21104800 */  addu       $v0, $v0, $t0
    /* 2D8 80102AD8 00004294 */  lhu        $v0, 0x0($v0)
    /* 2DC 80102ADC 1080033C */  lui        $v1, %hi(D_8010450C)
    /* 2E0 80102AE0 0C4570AC */  sw         $s0, %lo(D_8010450C)($v1)
    /* 2E4 80102AE4 40100200 */  sll        $v0, $v0, 1
    /* 2E8 80102AE8 21104800 */  addu       $v0, $v0, $t0
    /* 2EC 80102AEC 9723030C */  jal        vs_battle_setMenuItem
    /* 2F0 80102AF0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2F4 80102AF4 21204000 */  addu       $a0, $v0, $zero
    /* 2F8 80102AF8 21100000 */  addu       $v0, $zero, $zero
    /* 2FC 80102AFC 02000324 */  addiu      $v1, $zero, 0x2
    /* 300 80102B00 000083A0 */  sb         $v1, 0x0($a0)
    /* 304 80102B04 B4000324 */  addiu      $v1, $zero, 0xB4
    /* 308 80102B08 180083A4 */  sh         $v1, 0x18($a0)
    /* 30C 80102B0C 01000324 */  addiu      $v1, $zero, 0x1
    /* 310 80102B10 060083A0 */  sb         $v1, 0x6($a0)
    /* 314 80102B14 1080033C */  lui        $v1, %hi(D_80104500)
    /* 318 80102B18 090090A0 */  sb         $s0, 0x9($a0)
    /* 31C 80102B1C CE0B0408 */  j          .L80102F38
    /* 320 80102B20 004560AC */   sw        $zero, %lo(D_80104500)($v1)
  .L80102B24:
    /* 324 80102B24 1080023C */  lui        $v0, %hi(D_80104500)
    /* 328 80102B28 0045438C */  lw         $v1, %lo(D_80104500)($v0)
    /* 32C 80102B2C 01000224 */  addiu      $v0, $zero, 0x1
    /* 330 80102B30 99006210 */  beq        $v1, $v0, .L80102D98
    /* 334 80102B34 02006228 */   slti      $v0, $v1, 0x2
    /* 338 80102B38 05004010 */  beqz       $v0, .L80102B50
    /* 33C 80102B3C 02000224 */   addiu     $v0, $zero, 0x2
    /* 340 80102B40 07006010 */  beqz       $v1, .L80102B60
    /* 344 80102B44 1080023C */   lui       $v0, %hi(D_8010452C)
    /* 348 80102B48 AF0B0408 */  j          .L80102EBC
    /* 34C 80102B4C 00000000 */   nop
  .L80102B50:
    /* 350 80102B50 D2006210 */  beq        $v1, $v0, .L80102E9C
    /* 354 80102B54 1080023C */   lui       $v0, %hi(D_8010452C)
    /* 358 80102B58 AF0B0408 */  j          .L80102EBC
    /* 35C 80102B5C 00000000 */   nop
  .L80102B60:
    /* 360 80102B60 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 364 80102B64 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* 368 80102B68 00000000 */  nop
    /* 36C 80102B6C 05004014 */  bnez       $v0, .L80102B84
    /* 370 80102B70 21980000 */   addu      $s3, $zero, $zero
    /* 374 80102B74 74EA030C */  jal        vs_mainmenu_ready
    /* 378 80102B78 00000000 */   nop
    /* 37C 80102B7C CF004010 */  beqz       $v0, .L80102EBC
    /* 380 80102B80 1080023C */   lui       $v0, %hi(D_8010452C)
  .L80102B84:
    /* 384 80102B84 21886002 */  addu       $s1, $s3, $zero
    /* 388 80102B88 1080023C */  lui        $v0, %hi(_strings)
    /* 38C 80102B8C 78345E24 */  addiu      $fp, $v0, %lo(_strings)
    /* 390 80102B90 1080023C */  lui        $v0, %hi(D_8010453C)
    /* 394 80102B94 3C455624 */  addiu      $s6, $v0, %lo(D_8010453C)
    /* 398 80102B98 04001524 */  addiu      $s5, $zero, 0x4
    /* 39C 80102B9C 1800B727 */  addiu      $s7, $sp, 0x18
    /* 3A0 80102BA0 21A0E002 */  addu       $s4, $s7, $zero
    /* 3A4 80102BA4 1080023C */  lui        $v0, %hi(D_8010450C)
  .L80102BA8:
    /* 3A8 80102BA8 0580093C */  lui        $t1, %hi(vs_main_skills)
    /* 3AC 80102BAC 0C45458C */  lw         $a1, %lo(D_8010450C)($v0)
    /* 3B0 80102BB0 DCB92925 */  addiu      $t1, $t1, %lo(vs_main_skills)
    /* 3B4 80102BB4 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 3B8 80102BB8 80200200 */  sll        $a0, $v0, 2
    /* 3BC 80102BBC B8002226 */  addiu      $v0, $s1, 0xB8
    /* 3C0 80102BC0 21908200 */  addu       $s2, $a0, $v0
    /* 3C4 80102BC4 40101200 */  sll        $v0, $s2, 1
    /* 3C8 80102BC8 21105200 */  addu       $v0, $v0, $s2
    /* 3CC 80102BCC 80100200 */  sll        $v0, $v0, 2
    /* 3D0 80102BD0 21105200 */  addu       $v0, $v0, $s2
    /* 3D4 80102BD4 80180200 */  sll        $v1, $v0, 2
    /* 3D8 80102BD8 21106900 */  addu       $v0, $v1, $t1
    /* 3DC 80102BDC 0C00428C */  lw         $v0, 0xC($v0)
    /* 3E0 80102BE0 00000000 */  nop
    /* 3E4 80102BE4 C2130200 */  srl        $v0, $v0, 15
    /* 3E8 80102BE8 01004230 */  andi       $v0, $v0, 0x1
    /* 3EC 80102BEC 22004010 */  beqz       $v0, .L80102C78
    /* 3F0 80102BF0 0580093C */   lui       $t1, %hi(D_8004B9F8)
    /* 3F4 80102BF4 F8B92925 */  addiu      $t1, $t1, %lo(D_8004B9F8)
    /* 3F8 80102BF8 21106900 */  addu       $v0, $v1, $t1
    /* 3FC 80102BFC 000082AE */  sw         $v0, 0x0($s4)
    /* 400 80102C00 20008224 */  addiu      $v0, $a0, 0x20
    /* 404 80102C04 21102202 */  addu       $v0, $s1, $v0
    /* 408 80102C08 40100200 */  sll        $v0, $v0, 1
    /* 40C 80102C0C 21105E00 */  addu       $v0, $v0, $fp
    /* 410 80102C10 2118F502 */  addu       $v1, $s7, $s5
    /* 414 80102C14 00004294 */  lhu        $v0, 0x0($v0)
    /* 418 80102C18 80201300 */  sll        $a0, $s3, 2
    /* 41C 80102C1C 40100200 */  sll        $v0, $v0, 1
    /* 420 80102C20 21105E00 */  addu       $v0, $v0, $fp
    /* 424 80102C24 000062AC */  sw         $v0, 0x0($v1)
    /* 428 80102C28 4000A327 */  addiu      $v1, $sp, 0x40
    /* 42C 80102C2C 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 430 80102C30 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 434 80102C34 21806400 */  addu       $s0, $v1, $a0
    /* 438 80102C38 000000AE */  sw         $zero, 0x0($s0)
    /* 43C 80102C3C 25004290 */  lbu        $v0, 0x25($v0)
    /* 440 80102C40 00000000 */  nop
    /* 444 80102C44 0600A214 */  bne        $a1, $v0, .L80102C60
    /* 448 80102C48 01000224 */   addiu     $v0, $zero, 0x1
    /* 44C 80102C4C 21200000 */  addu       $a0, $zero, $zero
    /* 450 80102C50 7429020C */  jal        vs_battle_getSkillFlags
    /* 454 80102C54 21284002 */   addu      $a1, $s2, $zero
    /* 458 80102C58 02004010 */  beqz       $v0, .L80102C64
    /* 45C 80102C5C 01000224 */   addiu     $v0, $zero, 0x1
  .L80102C60:
    /* 460 80102C60 000002AE */  sw         $v0, 0x0($s0)
  .L80102C64:
    /* 464 80102C64 0000D2A6 */  sh         $s2, 0x0($s6)
    /* 468 80102C68 0200D626 */  addiu      $s6, $s6, 0x2
    /* 46C 80102C6C 0800B526 */  addiu      $s5, $s5, 0x8
    /* 470 80102C70 08009426 */  addiu      $s4, $s4, 0x8
    /* 474 80102C74 01007326 */  addiu      $s3, $s3, 0x1
  .L80102C78:
    /* 478 80102C78 01003126 */  addiu      $s1, $s1, 0x1
    /* 47C 80102C7C 0400222A */  slti       $v0, $s1, 0x4
    /* 480 80102C80 C9FF4014 */  bnez       $v0, .L80102BA8
    /* 484 80102C84 1080023C */   lui       $v0, %hi(D_8010450C)
    /* 488 80102C88 21880000 */  addu       $s1, $zero, $zero
    /* 48C 80102C8C 0F80023C */  lui        $v0, %hi(D_800F4EA0)
    /* 490 80102C90 A04E428C */  lw         $v0, %lo(D_800F4EA0)($v0)
    /* 494 80102C94 4000A327 */  addiu      $v1, $sp, 0x40
    /* 498 80102C98 5F014430 */  andi       $a0, $v0, 0x15F
  .L80102C9C:
    /* 49C 80102C9C 05008010 */  beqz       $a0, .L80102CB4
    /* 4A0 80102CA0 00000000 */   nop
    /* 4A4 80102CA4 0000628C */  lw         $v0, 0x0($v1)
    /* 4A8 80102CA8 00000000 */  nop
    /* 4AC 80102CAC 01004234 */  ori        $v0, $v0, 0x1
    /* 4B0 80102CB0 000062AC */  sw         $v0, 0x0($v1)
  .L80102CB4:
    /* 4B4 80102CB4 01003126 */  addiu      $s1, $s1, 0x1
    /* 4B8 80102CB8 0400222A */  slti       $v0, $s1, 0x4
    /* 4BC 80102CBC F7FF4014 */  bnez       $v0, .L80102C9C
    /* 4C0 80102CC0 04006324 */   addiu     $v1, $v1, 0x4
    /* 4C4 80102CC4 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 4C8 80102CC8 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* 4CC 80102CCC 00000000 */  nop
    /* 4D0 80102CD0 18004014 */  bnez       $v0, .L80102D34
    /* 4D4 80102CD4 0680023C */   lui       $v0, %hi(vs_main_settings)
    /* 4D8 80102CD8 C0101300 */  sll        $v0, $s3, 3
    /* 4DC 80102CDC 40281300 */  sll        $a1, $s3, 1
    /* 4E0 80102CE0 80301300 */  sll        $a2, $s3, 2
    /* 4E4 80102CE4 01007326 */  addiu      $s3, $s3, 0x1
    /* 4E8 80102CE8 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4EC 80102CEC 21108200 */  addu       $v0, $a0, $v0
    /* 4F0 80102CF0 1080033C */  lui        $v1, %hi(D_801038EA)
    /* 4F4 80102CF4 EA386324 */  addiu      $v1, $v1, %lo(D_801038EA)
    /* 4F8 80102CF8 000043AC */  sw         $v1, 0x0($v0)
    /* 4FC 80102CFC 0100A224 */  addiu      $v0, $a1, 0x1
    /* 500 80102D00 80100200 */  sll        $v0, $v0, 2
    /* 504 80102D04 21208200 */  addu       $a0, $a0, $v0
    /* 508 80102D08 0A006324 */  addiu      $v1, $v1, 0xA
    /* 50C 80102D0C 000083AC */  sw         $v1, 0x0($a0)
    /* 510 80102D10 2118A603 */  addu       $v1, $sp, $a2
    /* 514 80102D14 02000224 */  addiu      $v0, $zero, 0x2
    /* 518 80102D18 400062AC */  sw         $v0, 0x40($v1)
    /* 51C 80102D1C 1080023C */  lui        $v0, %hi(D_8010453C)
    /* 520 80102D20 3C454224 */  addiu      $v0, $v0, %lo(D_8010453C)
    /* 524 80102D24 2128A200 */  addu       $a1, $a1, $v0
    /* 528 80102D28 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 52C 80102D2C 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 530 80102D30 0680023C */  lui        $v0, %hi(vs_main_settings)
  .L80102D34:
    /* 534 80102D34 20005024 */  addiu      $s0, $v0, %lo(vs_main_settings)
    /* 538 80102D38 1080033C */  lui        $v1, %hi(D_80104508)
    /* 53C 80102D3C 0845628C */  lw         $v0, %lo(D_80104508)($v1)
    /* 540 80102D40 01001192 */  lbu        $s1, 0x1($s0)
    /* 544 80102D44 03004010 */  beqz       $v0, .L80102D54
    /* 548 80102D48 01000224 */   addiu     $v0, $zero, 0x1
    /* 54C 80102D4C 010002A2 */  sb         $v0, 0x1($s0)
    /* 550 80102D50 084560AC */  sw         $zero, %lo(D_80104508)($v1)
  .L80102D54:
    /* 554 80102D54 21206002 */  addu       $a0, $s3, $zero
    /* 558 80102D58 1800A627 */  addiu      $a2, $sp, 0x18
    /* 55C 80102D5C 1080023C */  lui        $v0, %hi(D_8010450C)
    /* 560 80102D60 0C45458C */  lw         $a1, %lo(D_8010450C)($v0)
    /* 564 80102D64 4000A727 */  addiu      $a3, $sp, 0x40
    /* 568 80102D68 0B00A524 */  addiu      $a1, $a1, 0xB
    /* 56C 80102D6C 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 570 80102D70 0002A534 */   ori       $a1, $a1, 0x200
    /* 574 80102D74 1080033C */  lui        $v1, %hi(D_80104500)
    /* 578 80102D78 01000224 */  addiu      $v0, $zero, 0x1
    /* 57C 80102D7C 010011A2 */  sb         $s1, 0x1($s0)
    /* 580 80102D80 004562AC */  sw         $v0, %lo(D_80104500)($v1)
    /* 584 80102D84 1080023C */  lui        $v0, %hi(D_8010452E)
    /* 588 80102D88 2E4553A0 */  sb         $s3, %lo(D_8010452E)($v0)
    /* 58C 80102D8C 1080023C */  lui        $v0, %hi(D_8010452F)
    /* 590 80102D90 AE0B0408 */  j          .L80102EB8
    /* 594 80102D94 2F4553A0 */   sb        $s3, %lo(D_8010452F)($v0)
  .L80102D98:
    /* 598 80102D98 1080033C */  lui        $v1, %hi(D_8010452F)
    /* 59C 80102D9C 2F456290 */  lbu        $v0, %lo(D_8010452F)($v1)
    /* 5A0 80102DA0 00000000 */  nop
    /* 5A4 80102DA4 02004010 */  beqz       $v0, .L80102DB0
    /* 5A8 80102DA8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 5AC 80102DAC 2F4562A0 */  sb         $v0, %lo(D_8010452F)($v1)
  .L80102DB0:
    /* 5B0 80102DB0 2F456290 */  lbu        $v0, %lo(D_8010452F)($v1)
    /* 5B4 80102DB4 1080113C */  lui        $s1, %hi(D_8010452C)
    /* 5B8 80102DB8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 5BC 80102DBC 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 5C0 80102DC0 2C4522A2 */   sb        $v0, %lo(D_8010452C)($s1)
    /* 5C4 80102DC4 1080103C */  lui        $s0, %hi(D_80104504)
    /* 5C8 80102DC8 21184000 */  addu       $v1, $v0, $zero
    /* 5CC 80102DCC 01006424 */  addiu      $a0, $v1, 0x1
    /* 5D0 80102DD0 1080023C */  lui        $v0, %hi(vs_mainMenu_isLevelledSpell)
    /* 5D4 80102DD4 044504AE */  sw         $a0, %lo(D_80104504)($s0)
    /* 5D8 80102DD8 23008010 */  beqz       $a0, .L80102E68
    /* 5DC 80102DDC D42240A0 */   sb        $zero, %lo(vs_mainMenu_isLevelledSpell)($v0)
    /* 5E0 80102DE0 08008018 */  blez       $a0, .L80102E04
    /* 5E4 80102DE4 2C4520A2 */   sb        $zero, %lo(D_8010452C)($s1)
    /* 5E8 80102DE8 1080023C */  lui        $v0, %hi(D_8010453C)
    /* 5EC 80102DEC 3C454224 */  addiu      $v0, $v0, %lo(D_8010453C)
    /* 5F0 80102DF0 40180300 */  sll        $v1, $v1, 1
    /* 5F4 80102DF4 21186200 */  addu       $v1, $v1, $v0
    /* 5F8 80102DF8 00006294 */  lhu        $v0, 0x0($v1)
    /* 5FC 80102DFC 870B0408 */  j          .L80102E1C
    /* 600 80102E00 044502AE */   sw        $v0, %lo(D_80104504)($s0)
  .L80102E04:
    /* 604 80102E04 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 608 80102E08 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* 60C 80102E0C 00000000 */  nop
    /* 610 80102E10 02004010 */  beqz       $v0, .L80102E1C
    /* 614 80102E14 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 618 80102E18 044502AE */  sw         $v0, %lo(D_80104504)($s0)
  .L80102E1C:
    /* 61C 80102E1C 1080023C */  lui        $v0, %hi(D_80104504)
    /* 620 80102E20 0445438C */  lw         $v1, %lo(D_80104504)($v0)
    /* 624 80102E24 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 628 80102E28 05006214 */  bne        $v1, $v0, .L80102E40
    /* 62C 80102E2C 00000000 */   nop
    /* 630 80102E30 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 634 80102E34 01000424 */   addiu     $a0, $zero, 0x1
    /* 638 80102E38 970B0408 */  j          .L80102E5C
    /* 63C 80102E3C 1080033C */   lui       $v1, %hi(D_80104500)
  .L80102E40:
    /* 640 80102E40 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 644 80102E44 28000424 */   addiu     $a0, $zero, 0x28
    /* 648 80102E48 EAFE030C */  jal        func_800FFBA8
    /* 64C 80102E4C 00000000 */   nop
    /* 650 80102E50 A2FE030C */  jal        func_800FFA88
    /* 654 80102E54 21200000 */   addu      $a0, $zero, $zero
    /* 658 80102E58 1080033C */  lui        $v1, %hi(D_80104500)
  .L80102E5C:
    /* 65C 80102E5C 02000224 */  addiu      $v0, $zero, 0x2
    /* 660 80102E60 AE0B0408 */  j          .L80102EB8
    /* 664 80102E64 004562AC */   sw        $v0, %lo(D_80104500)($v1)
  .L80102E68:
    /* 668 80102E68 1080103C */  lui        $s0, %hi(D_8010453C)
    /* 66C 80102E6C 2C02040C */  jal        func_801008B0
    /* 670 80102E70 3C451026 */   addiu     $s0, $s0, %lo(D_8010453C)
    /* 674 80102E74 40100200 */  sll        $v0, $v0, 1
    /* 678 80102E78 21105000 */  addu       $v0, $v0, $s0
    /* 67C 80102E7C 00005194 */  lhu        $s1, 0x0($v0)
    /* 680 80102E80 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 684 80102E84 0D002212 */  beq        $s1, $v0, .L80102EBC
    /* 688 80102E88 1080023C */   lui       $v0, %hi(D_8010452C)
    /* 68C 80102E8C 0C0A040C */  jal        _setArtCost
    /* 690 80102E90 21202002 */   addu      $a0, $s1, $zero
    /* 694 80102E94 AF0B0408 */  j          .L80102EBC
    /* 698 80102E98 1080023C */   lui       $v0, %hi(D_8010452C)
  .L80102E9C:
    /* 69C 80102E9C 74EA030C */  jal        vs_mainmenu_ready
    /* 6A0 80102EA0 00000000 */   nop
    /* 6A4 80102EA4 04004010 */  beqz       $v0, .L80102EB8
    /* 6A8 80102EA8 1080023C */   lui       $v0, %hi(D_80104504)
    /* 6AC 80102EAC 0445428C */  lw         $v0, %lo(D_80104504)($v0)
    /* 6B0 80102EB0 CE0B0408 */  j          .L80102F38
    /* 6B4 80102EB4 00000000 */   nop
  .L80102EB8:
    /* 6B8 80102EB8 1080023C */  lui        $v0, %hi(D_8010452C)
  .L80102EBC:
    /* 6BC 80102EBC 2C454290 */  lbu        $v0, %lo(D_8010452C)($v0)
    /* 6C0 80102EC0 00000000 */  nop
    /* 6C4 80102EC4 07004010 */  beqz       $v0, .L80102EE4
    /* 6C8 80102EC8 1080033C */   lui       $v1, %hi(D_8010452D)
    /* 6CC 80102ECC 2D456290 */  lbu        $v0, %lo(D_8010452D)($v1)
    /* 6D0 80102ED0 00000000 */  nop
    /* 6D4 80102ED4 0B004010 */  beqz       $v0, .L80102F04
    /* 6D8 80102ED8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6DC 80102EDC C10B0408 */  j          .L80102F04
    /* 6E0 80102EE0 2D4562A0 */   sb        $v0, %lo(D_8010452D)($v1)
  .L80102EE4:
    /* 6E4 80102EE4 1080043C */  lui        $a0, %hi(D_8010452D)
    /* 6E8 80102EE8 0F80023C */  lui        $v0, %hi(vs_battle_animationIndices)
    /* 6EC 80102EEC 2D458390 */  lbu        $v1, %lo(D_8010452D)($a0)
    /* 6F0 80102EF0 7CBC4224 */  addiu      $v0, $v0, %lo(vs_battle_animationIndices)
    /* 6F4 80102EF4 21186200 */  addu       $v1, $v1, $v0
    /* 6F8 80102EF8 00006290 */  lbu        $v0, 0x0($v1)
    /* 6FC 80102EFC 00000000 */  nop
    /* 700 80102F00 2D4582A0 */  sb         $v0, %lo(D_8010452D)($a0)
  .L80102F04:
    /* 704 80102F04 1080023C */  lui        $v0, %hi(D_8010450C)
    /* 708 80102F08 0C45458C */  lw         $a1, %lo(D_8010450C)($v0)
    /* 70C 80102F0C 1080023C */  lui        $v0, %hi(D_8010452E)
    /* 710 80102F10 0F80033C */  lui        $v1, %hi(vs_battle_rowAnimationSteps)
    /* 714 80102F14 2E454690 */  lbu        $a2, %lo(D_8010452E)($v0)
    /* 718 80102F18 1080023C */  lui        $v0, %hi(D_8010452D)
    /* 71C 80102F1C 2D454290 */  lbu        $v0, %lo(D_8010452D)($v0)
    /* 720 80102F20 C8BB6324 */  addiu      $v1, $v1, %lo(vs_battle_rowAnimationSteps)
    /* 724 80102F24 21104300 */  addu       $v0, $v0, $v1
    /* 728 80102F28 00004490 */  lbu        $a0, 0x0($v0)
    /* 72C 80102F2C 450A040C */  jal        _drawPointsRemaining
    /* 730 80102F30 00000000 */   nop
    /* 734 80102F34 21100000 */  addu       $v0, $zero, $zero
  .L80102F38:
    /* 738 80102F38 7C00BF8F */  lw         $ra, 0x7C($sp)
    /* 73C 80102F3C 7800BE8F */  lw         $fp, 0x78($sp)
    /* 740 80102F40 7400B78F */  lw         $s7, 0x74($sp)
    /* 744 80102F44 7000B68F */  lw         $s6, 0x70($sp)
    /* 748 80102F48 6C00B58F */  lw         $s5, 0x6C($sp)
    /* 74C 80102F4C 6800B48F */  lw         $s4, 0x68($sp)
    /* 750 80102F50 6400B38F */  lw         $s3, 0x64($sp)
    /* 754 80102F54 6000B28F */  lw         $s2, 0x60($sp)
    /* 758 80102F58 5C00B18F */  lw         $s1, 0x5C($sp)
    /* 75C 80102F5C 5800B08F */  lw         $s0, 0x58($sp)
    /* 760 80102F60 0800E003 */  jr         $ra
    /* 764 80102F64 8000BD27 */   addiu     $sp, $sp, 0x80
endlabel _drawArtsList
