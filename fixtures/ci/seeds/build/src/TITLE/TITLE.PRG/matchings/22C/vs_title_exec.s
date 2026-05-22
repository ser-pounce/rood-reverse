nonmatching vs_title_exec, 0x508

glabel vs_title_exec
    /* 8B34 80071334 0680033C */  lui        $v1, %hi(vs_main_saveGameClearData)
    /* 8B38 80071338 14E2628C */  lw         $v0, %lo(vs_main_saveGameClearData)($v1)
    /* 8B3C 8007133C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 8B40 80071340 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 8B44 80071344 3800BEAF */  sw         $fp, 0x38($sp)
    /* 8B48 80071348 3400B7AF */  sw         $s7, 0x34($sp)
    /* 8B4C 8007134C 3000B6AF */  sw         $s6, 0x30($sp)
    /* 8B50 80071350 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 8B54 80071354 2800B4AF */  sw         $s4, 0x28($sp)
    /* 8B58 80071358 2400B3AF */  sw         $s3, 0x24($sp)
    /* 8B5C 8007135C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 8B60 80071360 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 8B64 80071364 05004010 */  beqz       $v0, .L8007137C
    /* 8B68 80071368 1800B0AF */   sw        $s0, 0x18($sp)
    /* 8B6C 8007136C 0580023C */  lui        $v0, %hi(vs_main_titleScreenCount)
    /* 8B70 80071370 14E260AC */  sw         $zero, %lo(vs_main_saveGameClearData)($v1)
    /* 8B74 80071374 6FBB010C */  jal        _gameSaveScreen
    /* 8B78 80071378 28A540AC */   sw        $zero, %lo(vs_main_titleScreenCount)($v0)
  .L8007137C:
    /* 8B7C 8007137C C5C6010C */  jal        _initGameData
    /* 8B80 80071380 0E801E3C */   lui       $fp, %hi(_buttonsLastPressed)
    /* 8B84 80071384 95C4010C */  jal        _initEnvironment
    /* 8B88 80071388 01001724 */   addiu     $s7, $zero, 0x1
    /* 8B8C 8007138C 0580043C */  lui        $a0, %hi(vs_main_titleScreenCount)
    /* 8B90 80071390 28A5828C */  lw         $v0, %lo(vs_main_titleScreenCount)($a0)
    /* 8B94 80071394 0E80033C */  lui        $v1, %hi(_introMoviePlaying)
    /* 8B98 80071398 7CED60AC */  sw         $zero, %lo(_introMoviePlaying)($v1)
    /* 8B9C 8007139C 21105700 */  addu       $v0, $v0, $s7
    /* 8BA0 800713A0 62BA010C */  jal        _saveFileExists
    /* 8BA4 800713A4 28A582AC */   sw        $v0, %lo(vs_main_titleScreenCount)($a0)
    /* 8BA8 800713A8 21904000 */  addu       $s2, $v0, $zero
    /* 8BAC 800713AC 07001024 */  addiu      $s0, $zero, 0x7
  .L800713B0:
    /* 8BB0 800713B0 0F80063C */  lui        $a2, %hi(_menuItemStates)
    /* 8BB4 800713B4 F8FDC624 */  addiu      $a2, $a2, %lo(_menuItemStates)
    /* 8BB8 800713B8 3800C224 */  addiu      $v0, $a2, 0x38
  .L800713BC:
    /* 8BBC 800713BC 000040A0 */  sb         $zero, 0x0($v0)
    /* 8BC0 800713C0 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 8BC4 800713C4 FDFF0106 */  bgez       $s0, .L800713BC
    /* 8BC8 800713C8 F8FF4224 */   addiu     $v0, $v0, -0x8
    /* 8BCC 800713CC 1BBF010C */  jal        _copyTitleBgData
    /* 8BD0 800713D0 20001024 */   addiu     $s0, $zero, 0x20
    /* 8BD4 800713D4 07BE010C */  jal        _initAndPlayIntroMovie
    /* 8BD8 800713D8 00000000 */   nop
    /* 8BDC 800713DC 95BE010C */  jal        _playIntroMovie
    /* 8BE0 800713E0 00000000 */   nop
    /* 8BE4 800713E4 8CBF010C */  jal        func_8006FE30
    /* 8BE8 800713E8 00000000 */   nop
    /* 8BEC 800713EC 6EA1000C */  jal        SetDispMask
    /* 8BF0 800713F0 01000424 */   addiu     $a0, $zero, 0x1
    /* 8BF4 800713F4 B1BF010C */  jal        _initMenu
    /* 8BF8 800713F8 21204002 */   addu      $a0, $s2, $zero
    /* 8BFC 800713FC 21884000 */  addu       $s1, $v0, $zero
  .L80071400:
    /* 8C00 80071400 21202002 */  addu       $a0, $s1, $zero
    /* 8C04 80071404 62C0010C */  jal        _fadeInMenuCopyright
    /* 8C08 80071408 21280002 */   addu      $a1, $s0, $zero
    /* 8C0C 8007140C FEFF1026 */  addiu      $s0, $s0, -0x2
    /* 8C10 80071410 FBFF0106 */  bgez       $s0, .L80071400
    /* 8C14 80071414 00000000 */   nop
    /* 8C18 80071418 B17D000C */  jal        VSync
    /* 8C1C 8007141C 21200000 */   addu      $a0, $zero, $zero
    /* 8C20 80071420 1000A427 */  addiu      $a0, $sp, 0x10
    /* 8C24 80071424 21282002 */  addu       $a1, $s1, $zero
    /* 8C28 80071428 B0020224 */  addiu      $v0, $zero, 0x2B0
    /* 8C2C 8007142C 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 8C30 80071430 00010224 */  addiu      $v0, $zero, 0x100
    /* 8C34 80071434 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 8C38 80071438 A0000224 */  addiu      $v0, $zero, 0xA0
    /* 8C3C 8007143C 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 8C40 80071440 80000224 */  addiu      $v0, $zero, 0x80
    /* 8C44 80071444 57A2000C */  jal        StoreImage
    /* 8C48 80071448 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 8C4C 8007144C 94A1000C */  jal        DrawSync
    /* 8C50 80071450 21200000 */   addu      $a0, $zero, $zero
    /* 8C54 80071454 B17D000C */  jal        VSync
    /* 8C58 80071458 21200000 */   addu      $a0, $zero, $zero
    /* 8C5C 8007145C 20001024 */  addiu      $s0, $zero, 0x20
    /* 8C60 80071460 21202002 */  addu       $a0, $s1, $zero
  .L80071464:
    /* 8C64 80071464 09C0010C */  jal        _fadeInMenu
    /* 8C68 80071468 21280002 */   addu      $a1, $s0, $zero
    /* 8C6C 8007146C 4FC2010C */  jal        _drawTitleMenu
    /* 8C70 80071470 FCFF1026 */   addiu     $s0, $s0, -0x4
    /* 8C74 80071474 FBFF0106 */  bgez       $s0, .L80071464
    /* 8C78 80071478 21202002 */   addu      $a0, $s1, $zero
    /* 8C7C 8007147C 01C0010C */  jal        _freeHeap
    /* 8C80 80071480 21202002 */   addu      $a0, $s1, $zero
    /* 8C84 80071484 21800000 */  addu       $s0, $zero, $zero
  .L80071488:
    /* 8C88 80071488 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 8C8C 8007148C 01001026 */   addiu     $s0, $s0, 0x1
    /* 8C90 80071490 0800022A */  slti       $v0, $s0, 0x8
    /* 8C94 80071494 FCFF4014 */  bnez       $v0, .L80071488
    /* 8C98 80071498 00000000 */   nop
    /* 8C9C 8007149C F70B010C */  jal        vs_main_padDisconnectAll
    /* 8CA0 800714A0 02001124 */   addiu     $s1, $zero, 0x2
    /* 8CA4 800714A4 B17D000C */  jal        VSync
    /* 8CA8 800714A8 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 8CAC 800714AC FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 8CB0 800714B0 0E80033C */  lui        $v1, %hi(_introMovieLastPlayed)
    /* 8CB4 800714B4 B17D000C */  jal        VSync
    /* 8CB8 800714B8 8CEA62AC */   sw        $v0, %lo(_introMovieLastPlayed)($v1)
    /* 8CBC 800714BC 88EAC2AF */  sw         $v0, %lo(_buttonsLastPressed)($fp)
  .L800714C0:
    /* 8CC0 800714C0 B17D000C */  jal        VSync
    /* 8CC4 800714C4 21200000 */   addu      $a0, $zero, $zero
    /* 8CC8 800714C8 500E010C */  jal        vs_main_processPadState
    /* 8CCC 800714CC 00000000 */   nop
    /* 8CD0 800714D0 0E80023C */  lui        $v0, %hi(_introMoviePlaying)
    /* 8CD4 800714D4 7CED428C */  lw         $v0, %lo(_introMoviePlaying)($v0)
    /* 8CD8 800714D8 00000000 */  nop
    /* 8CDC 800714DC 06004010 */  beqz       $v0, .L800714F8
    /* 8CE0 800714E0 0680063C */   lui       $a2, %hi(vs_main_buttonsState)
    /* 8CE4 800714E4 B17D000C */  jal        VSync
    /* 8CE8 800714E8 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 8CEC 800714EC 0E80033C */  lui        $v1, %hi(_introMovieLastPlayed)
    /* 8CF0 800714F0 8CEA62AC */  sw         $v0, %lo(_introMovieLastPlayed)($v1)
    /* 8CF4 800714F4 0680063C */  lui        $a2, %hi(vs_main_buttonsState)
  .L800714F8:
    /* 8CF8 800714F8 38E2C294 */  lhu        $v0, %lo(vs_main_buttonsState)($a2)
    /* 8CFC 800714FC 00000000 */  nop
    /* 8D00 80071500 04004010 */  beqz       $v0, .L80071514
    /* 8D04 80071504 00000000 */   nop
    /* 8D08 80071508 B17D000C */  jal        VSync
    /* 8D0C 8007150C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 8D10 80071510 88EAC2AF */  sw         $v0, %lo(_buttonsLastPressed)($fp)
  .L80071514:
    /* 8D14 80071514 B17D000C */  jal        VSync
    /* 8D18 80071518 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 8D1C 8007151C 88EAC38F */  lw         $v1, %lo(_buttonsLastPressed)($fp)
    /* 8D20 80071520 00000000 */  nop
    /* 8D24 80071524 23104300 */  subu       $v0, $v0, $v1
    /* 8D28 80071528 E9034228 */  slti       $v0, $v0, 0x3E9
    /* 8D2C 8007152C 0A004014 */  bnez       $v0, .L80071558
    /* 8D30 80071530 0680063C */   lui       $a2, %hi(vs_main_buttonsState)
    /* 8D34 80071534 B17D000C */  jal        VSync
    /* 8D38 80071538 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 8D3C 8007153C 0E80033C */  lui        $v1, %hi(_introMovieLastPlayed)
    /* 8D40 80071540 8CEA638C */  lw         $v1, %lo(_introMovieLastPlayed)($v1)
    /* 8D44 80071544 00000000 */  nop
    /* 8D48 80071548 23104300 */  subu       $v0, $v0, $v1
    /* 8D4C 8007154C 65004228 */  slti       $v0, $v0, 0x65
    /* 8D50 80071550 74004010 */  beqz       $v0, .L80071724
    /* 8D54 80071554 0680063C */   lui       $a2, %hi(vs_main_buttonsState)
  .L80071558:
    /* 8D58 80071558 38E2C28C */  lw         $v0, %lo(vs_main_buttonsState)($a2)
    /* 8D5C 8007155C 00000000 */  nop
    /* 8D60 80071560 20084230 */  andi       $v0, $v0, 0x820
    /* 8D64 80071564 27004010 */  beqz       $v0, .L80071604
    /* 8D68 80071568 00000000 */   nop
    /* 8D6C 8007156C 11005712 */  beq        $s2, $s7, .L800715B4
    /* 8D70 80071570 0200422A */   slti      $v0, $s2, 0x2
    /* 8D74 80071574 05004010 */  beqz       $v0, .L8007158C
    /* 8D78 80071578 00000000 */   nop
    /* 8D7C 8007157C 09004012 */  beqz       $s2, .L800715A4
    /* 8D80 80071580 00000000 */   nop
    /* 8D84 80071584 7AC50108 */  j          .L800715E8
    /* 8D88 80071588 00000000 */   nop
  .L8007158C:
    /* 8D8C 8007158C 0B005112 */  beq        $s2, $s1, .L800715BC
    /* 8D90 80071590 03000224 */   addiu     $v0, $zero, 0x3
    /* 8D94 80071594 0F004212 */  beq        $s2, $v0, .L800715D4
    /* 8D98 80071598 0200422A */   slti      $v0, $s2, 0x2
    /* 8D9C 8007159C 7AC50108 */  j          .L800715E8
    /* 8DA0 800715A0 00000000 */   nop
  .L800715A4:
    /* 8DA4 800715A4 93C4010C */  jal        nop1
    /* 8DA8 800715A8 00000000 */   nop
    /* 8DAC 800715AC 79C50108 */  j          .L800715E4
    /* 8DB0 800715B0 21984000 */   addu      $s3, $v0, $zero
  .L800715B4:
    /* 8DB4 800715B4 79C50108 */  j          .L800715E4
    /* 8DB8 800715B8 01001324 */   addiu     $s3, $zero, 0x1
  .L800715BC:
    /* 8DBC 800715BC A3A2010C */  jal        _playMenuSelectSfx
    /* 8DC0 800715C0 00000000 */   nop
    /* 8DC4 800715C4 A2C2010C */  jal        func_80070A88
    /* 8DC8 800715C8 00000000 */   nop
    /* 8DCC 800715CC 7AC50108 */  j          .L800715E8
    /* 8DD0 800715D0 0200422A */   slti      $v0, $s2, 0x2
  .L800715D4:
    /* 8DD4 800715D4 A3A2010C */  jal        _playMenuSelectSfx
    /* 8DD8 800715D8 00000000 */   nop
    /* 8DDC 800715DC 99C3010C */  jal        func_80070E64
    /* 8DE0 800715E0 00000000 */   nop
  .L800715E4:
    /* 8DE4 800715E4 0200422A */  slti       $v0, $s2, 0x2
  .L800715E8:
    /* 8DE8 800715E8 03004010 */  beqz       $v0, .L800715F8
    /* 8DEC 800715EC 00000000 */   nop
    /* 8DF0 800715F0 40006106 */  bgez       $s3, .L800716F4
    /* 8DF4 800715F4 0E80023C */   lui       $v0, %hi(_introMoviePlaying)
  .L800715F8:
    /* 8DF8 800715F8 B17D000C */  jal        VSync
    /* 8DFC 800715FC FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 8E00 80071600 88EAC2AF */  sw         $v0, %lo(_buttonsLastPressed)($fp)
  .L80071604:
    /* 8E04 80071604 0680063C */  lui        $a2, %hi(vs_main_buttonsState)
    /* 8E08 80071608 38E2C38C */  lw         $v1, %lo(vs_main_buttonsState)($a2)
    /* 8E0C 8007160C 00000000 */  nop
    /* 8E10 80071610 00906230 */  andi       $v0, $v1, 0x9000
    /* 8E14 80071614 02004010 */  beqz       $v0, .L80071620
    /* 8E18 80071618 21800000 */   addu      $s0, $zero, $zero
    /* 8E1C 8007161C FFFF1024 */  addiu      $s0, $zero, -0x1
  .L80071620:
    /* 8E20 80071620 00616230 */  andi       $v0, $v1, 0x6100
    /* 8E24 80071624 02004010 */  beqz       $v0, .L80071630
    /* 8E28 80071628 00000000 */   nop
    /* 8E2C 8007162C 01001026 */  addiu      $s0, $s0, 0x1
  .L80071630:
    /* 8E30 80071630 2A000012 */  beqz       $s0, .L800716DC
    /* 8E34 80071634 21105002 */   addu      $v0, $s2, $s0
    /* 8E38 80071638 9AA2010C */  jal        _playMenuChangeSfx
    /* 8E3C 8007163C 03005230 */   andi      $s2, $v0, 0x3
    /* 8E40 80071640 12001716 */  bne        $s0, $s7, .L8007168C
    /* 8E44 80071644 FFFF4426 */   addiu     $a0, $s2, -0x1
    /* 8E48 80071648 01004426 */  addiu      $a0, $s2, 0x1
    /* 8E4C 8007164C 03008430 */  andi       $a0, $a0, 0x3
    /* 8E50 80071650 0DBF010C */  jal        func_8006FC34
    /* 8E54 80071654 80000524 */   addiu     $a1, $zero, 0x80
    /* 8E58 80071658 21800000 */  addu       $s0, $zero, $zero
    /* 8E5C 8007165C 0F80033C */  lui        $v1, %hi(_menuItemStates)
    /* 8E60 80071660 F8FD6324 */  addiu      $v1, $v1, %lo(_menuItemStates)
  .L80071664:
    /* 8E64 80071664 04006290 */  lbu        $v0, 0x4($v1)
    /* 8E68 80071668 01001026 */  addiu      $s0, $s0, 0x1
    /* 8E6C 8007166C 010077A0 */  sb         $s7, 0x1($v1)
    /* 8E70 80071670 E0FF4224 */  addiu      $v0, $v0, -0x20
    /* 8E74 80071674 050062A0 */  sb         $v0, 0x5($v1)
    /* 8E78 80071678 0400022A */  slti       $v0, $s0, 0x4
    /* 8E7C 8007167C F9FF4014 */  bnez       $v0, .L80071664
    /* 8E80 80071680 08006324 */   addiu     $v1, $v1, 0x8
    /* 8E84 80071684 B2C50108 */  j          .L800716C8
    /* 8E88 80071688 21800000 */   addu      $s0, $zero, $zero
  .L8007168C:
    /* 8E8C 8007168C 03008430 */  andi       $a0, $a0, 0x3
    /* 8E90 80071690 0DBF010C */  jal        func_8006FC34
    /* 8E94 80071694 21280000 */   addu      $a1, $zero, $zero
    /* 8E98 80071698 21800000 */  addu       $s0, $zero, $zero
    /* 8E9C 8007169C 0F80033C */  lui        $v1, %hi(_menuItemStates)
    /* 8EA0 800716A0 F8FD6324 */  addiu      $v1, $v1, %lo(_menuItemStates)
  .L800716A4:
    /* 8EA4 800716A4 04006290 */  lbu        $v0, 0x4($v1)
    /* 8EA8 800716A8 01001026 */  addiu      $s0, $s0, 0x1
    /* 8EAC 800716AC 010071A0 */  sb         $s1, 0x1($v1)
    /* 8EB0 800716B0 20004224 */  addiu      $v0, $v0, 0x20
    /* 8EB4 800716B4 050062A0 */  sb         $v0, 0x5($v1)
    /* 8EB8 800716B8 0400022A */  slti       $v0, $s0, 0x4
    /* 8EBC 800716BC F9FF4014 */  bnez       $v0, .L800716A4
    /* 8EC0 800716C0 08006324 */   addiu     $v1, $v1, 0x8
    /* 8EC4 800716C4 21800000 */  addu       $s0, $zero, $zero
  .L800716C8:
    /* 8EC8 800716C8 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 8ECC 800716CC 01001026 */   addiu     $s0, $s0, 0x1
    /* 8ED0 800716D0 0A00022A */  slti       $v0, $s0, 0xA
    /* 8ED4 800716D4 FCFF4014 */  bnez       $v0, .L800716C8
    /* 8ED8 800716D8 00000000 */   nop
  .L800716DC:
    /* 8EDC 800716DC 4FC2010C */  jal        _drawTitleMenu
    /* 8EE0 800716E0 00000000 */   nop
    /* 8EE4 800716E4 30C50108 */  j          .L800714C0
    /* 8EE8 800716E8 00000000 */   nop
  .L800716EC:
    /* 8EEC 800716EC 13006006 */  bltz       $s3, .L8007173C
    /* 8EF0 800716F0 0E80023C */   lui       $v0, %hi(_introMoviePlaying)
  .L800716F4:
    /* 8EF4 800716F4 7CED428C */  lw         $v0, %lo(_introMoviePlaying)($v0)
    /* 8EF8 800716F8 00000000 */  nop
    /* 8EFC 800716FC 03004010 */  beqz       $v0, .L8007170C
    /* 8F00 80071700 00000000 */   nop
    /* 8F04 80071704 55BE010C */  jal        func_8006F954
    /* 8F08 80071708 00000000 */   nop
  .L8007170C:
    /* 8F0C 8007170C 07007716 */  bne        $s3, $s7, .L8007172C
    /* 8F10 80071710 00000000 */   nop
    /* 8F14 80071714 A3A2010C */  jal        _playMenuSelectSfx
    /* 8F18 80071718 00000000 */   nop
    /* 8F1C 8007171C D0C50108 */  j          .L80071740
    /* 8F20 80071720 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80071724:
    /* 8F24 80071724 BBC50108 */  j          .L800716EC
    /* 8F28 80071728 FFFF1324 */   addiu     $s3, $zero, -0x1
  .L8007172C:
    /* 8F2C 8007172C 8BA2010C */  jal        _playNewGameSfx
    /* 8F30 80071730 00000000 */   nop
    /* 8F34 80071734 38C7010C */  jal        _setTitleExitFlags
    /* 8F38 80071738 21206002 */   addu      $a0, $s3, $zero
  .L8007173C:
    /* 8F3C 8007173C FFFF0224 */  addiu      $v0, $zero, -0x1
  .L80071740:
    /* 8F40 80071740 09006216 */  bne        $s3, $v0, .L80071768
    /* 8F44 80071744 40001024 */   addiu     $s0, $zero, 0x40
    /* 8F48 80071748 0580023C */  lui        $v0, %hi(vs_main_titleScreenCount)
    /* 8F4C 8007174C 28A5428C */  lw         $v0, %lo(vs_main_titleScreenCount)($v0)
    /* 8F50 80071750 04000324 */  addiu      $v1, $zero, 0x4
    /* 8F54 80071754 01004230 */  andi       $v0, $v0, 0x1
    /* 8F58 80071758 23986200 */  subu       $s3, $v1, $v0
    /* 8F5C 8007175C 38C7010C */  jal        _setTitleExitFlags
    /* 8F60 80071760 21206002 */   addu      $a0, $s3, $zero
    /* 8F64 80071764 40001024 */  addiu      $s0, $zero, 0x40
  .L80071768:
    /* 8F68 80071768 0E80163C */  lui        $s6, %hi(_titleScreenFade)
    /* 8F6C 8007176C 48EAD126 */  addiu      $s1, $s6, %lo(_titleScreenFade)
    /* 8F70 80071770 FF04153C */  lui        $s5, (0x4FFFFFF >> 16)
    /* 8F74 80071774 FFFFB536 */  ori        $s5, $s5, (0x4FFFFFF & 0xFFFF)
    /* 8F78 80071778 00E1143C */  lui        $s4, (0xE1000145 >> 16)
    /* 8F7C 8007177C 45019436 */  ori        $s4, $s4, (0xE1000145 & 0xFFFF)
  .L80071780:
    /* 8F80 80071780 B17D000C */  jal        VSync
    /* 8F84 80071784 21200000 */   addu      $a0, $zero, $zero
    /* 8F88 80071788 500E010C */  jal        vs_main_processPadState
    /* 8F8C 8007178C FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 8F90 80071790 0862023C */  lui        $v0, (0x62080808 >> 16)
    /* 8F94 80071794 08084234 */  ori        $v0, $v0, (0x62080808 & 0xFFFF)
    /* 8F98 80071798 E001033C */  lui        $v1, (0x1E00280 >> 16)
    /* 8F9C 8007179C 80026334 */  ori        $v1, $v1, (0x1E00280 & 0xFFFF)
    /* 8FA0 800717A0 21202002 */  addu       $a0, $s1, $zero
    /* 8FA4 800717A4 48EAD5AE */  sw         $s5, %lo(_titleScreenFade)($s6)
    /* 8FA8 800717A8 040034AE */  sw         $s4, 0x4($s1)
    /* 8FAC 800717AC 080022AE */  sw         $v0, 0x8($s1)
    /* 8FB0 800717B0 0C0020AE */  sw         $zero, 0xC($s1)
    /* 8FB4 800717B4 FAA2000C */  jal        DrawPrim
    /* 8FB8 800717B8 100023AE */   sw        $v1, 0x10($s1)
    /* 8FBC 800717BC AD0D010C */  jal        vs_main_setVibrateParams
    /* 8FC0 800717C0 00000000 */   nop
    /* 8FC4 800717C4 EEFF001E */  bgtz       $s0, .L80071780
    /* 8FC8 800717C8 00000000 */   nop
    /* 8FCC 800717CC B17D000C */  jal        VSync
    /* 8FD0 800717D0 21200000 */   addu      $a0, $zero, $zero
    /* 8FD4 800717D4 6EA1000C */  jal        SetDispMask
    /* 8FD8 800717D8 21200000 */   addu      $a0, $zero, $zero
    /* 8FDC 800717DC 08007716 */  bne        $s3, $s7, .L80071800
    /* 8FE0 800717E0 00000000 */   nop
    /* 8FE4 800717E4 CEB9010C */  jal        _gameLoadScreen
    /* 8FE8 800717E8 00000000 */   nop
    /* 8FEC 800717EC 21984000 */  addu       $s3, $v0, $zero
    /* 8FF0 800717F0 03007716 */  bne        $s3, $s7, .L80071800
    /* 8FF4 800717F4 00000000 */   nop
    /* 8FF8 800717F8 38C7010C */  jal        _setTitleExitFlags
    /* 8FFC 800717FC 01000424 */   addiu     $a0, $zero, 0x1
  .L80071800:
    /* 9000 80071800 EBFE6006 */  bltz       $s3, .L800713B0
    /* 9004 80071804 07001024 */   addiu     $s0, $zero, 0x7
    /* 9008 80071808 21106002 */  addu       $v0, $s3, $zero
    /* 900C 8007180C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 9010 80071810 3800BE8F */  lw         $fp, 0x38($sp)
    /* 9014 80071814 3400B78F */  lw         $s7, 0x34($sp)
    /* 9018 80071818 3000B68F */  lw         $s6, 0x30($sp)
    /* 901C 8007181C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 9020 80071820 2800B48F */  lw         $s4, 0x28($sp)
    /* 9024 80071824 2400B38F */  lw         $s3, 0x24($sp)
    /* 9028 80071828 2000B28F */  lw         $s2, 0x20($sp)
    /* 902C 8007182C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 9030 80071830 1800B08F */  lw         $s0, 0x18($sp)
    /* 9034 80071834 0800E003 */  jr         $ra
    /* 9038 80071838 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel vs_title_exec
