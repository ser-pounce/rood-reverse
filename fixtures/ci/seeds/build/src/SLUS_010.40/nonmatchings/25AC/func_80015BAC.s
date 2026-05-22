nonmatching func_80015BAC, 0xF0

glabel func_80015BAC
    /* 63AC 80015BAC 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 63B0 80015BB0 2866478C */  lw         $a3, %lo(g_pSavedMousicConfig)($v0)
    /* 63B4 80015BB4 00000000 */  nop
    /* 63B8 80015BB8 3600E010 */  beqz       $a3, .L80015C94
    /* 63BC 80015BBC FF00063C */   lui       $a2, (0xFFFFFF >> 16)
    /* 63C0 80015BC0 FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* 63C4 80015BC4 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 63C8 80015BC8 21400000 */  addu       $t0, $zero, $zero
    /* 63CC 80015BCC 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 63D0 80015BD0 0800E48C */  lw         $a0, 0x8($a3)
    /* 63D4 80015BD4 0800628C */  lw         $v0, 0x8($v1)
    /* 63D8 80015BD8 0C00658C */  lw         $a1, 0xC($v1)
    /* 63DC 80015BDC 0C00E38C */  lw         $v1, 0xC($a3)
    /* 63E0 80015BE0 24104500 */  and        $v0, $v0, $a1
    /* 63E4 80015BE4 24208300 */  and        $a0, $a0, $v1
    /* 63E8 80015BE8 27100200 */  nor        $v0, $zero, $v0
    /* 63EC 80015BEC 25384400 */  or         $a3, $v0, $a0
    /* 63F0 80015BF0 24186700 */  and        $v1, $v1, $a3
    /* 63F4 80015BF4 27180300 */  nor        $v1, $zero, $v1
    /* 63F8 80015BF8 24186500 */  and        $v1, $v1, $a1
    /* 63FC 80015BFC 24186600 */  and        $v1, $v1, $a2
    /* 6400 80015C00 1A006010 */  beqz       $v1, .L80015C6C
    /* 6404 80015C04 21380001 */   addu      $a3, $t0, $zero
    /* 6408 80015C08 01000924 */  addiu      $t1, $zero, 0x1
    /* 640C 80015C0C 03800B3C */  lui        $t3, %hi(g_pSecondaryMusicChannels)
    /* 6410 80015C10 18000A24 */  addiu      $t2, $zero, 0x18
  .L80015C14:
    /* 6414 80015C14 0420E900 */  sllv       $a0, $t1, $a3
    /* 6418 80015C18 24106400 */  and        $v0, $v1, $a0
    /* 641C 80015C1C 11004010 */  beqz       $v0, .L80015C64
    /* 6420 80015C20 00000000 */   nop
    /* 6424 80015C24 20000524 */  addiu      $a1, $zero, 0x20
    /* 6428 80015C28 D465628D */  lw         $v0, %lo(g_pSecondaryMusicChannels)($t3)
    /* 642C 80015C2C 21308000 */  addu       $a2, $a0, $zero
    /* 6430 80015C30 F4004424 */  addiu      $a0, $v0, 0xF4
  .L80015C34:
    /* 6434 80015C34 0000828C */  lw         $v0, 0x0($a0)
    /* 6438 80015C38 00000000 */  nop
    /* 643C 80015C3C 03004714 */  bne        $v0, $a3, .L80015C4C
    /* 6440 80015C40 00000000 */   nop
    /* 6444 80015C44 00008AAC */  sw         $t2, 0x0($a0)
    /* 6448 80015C48 25400601 */  or         $t0, $t0, $a2
  .L80015C4C:
    /* 644C 80015C4C FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 6450 80015C50 F8FFA014 */  bnez       $a1, .L80015C34
    /* 6454 80015C54 10018424 */   addiu     $a0, $a0, 0x110
    /* 6458 80015C58 0410E900 */  sllv       $v0, $t1, $a3
    /* 645C 80015C5C 27100200 */  nor        $v0, $zero, $v0
    /* 6460 80015C60 24186200 */  and        $v1, $v1, $v0
  .L80015C64:
    /* 6464 80015C64 EBFF6014 */  bnez       $v1, .L80015C14
    /* 6468 80015C68 0100E724 */   addiu     $a3, $a3, 0x1
  .L80015C6C:
    /* 646C 80015C6C 0380043C */  lui        $a0, %hi(g_Sound_VoiceSchedulerState)
    /* 6470 80015C70 0480023C */  lui        $v0, %hi(D_80039B14)
    /* 6474 80015C74 9078858C */  lw         $a1, %lo(g_Sound_VoiceSchedulerState)($a0)
    /* 6478 80015C78 90788424 */  addiu      $a0, $a0, %lo(g_Sound_VoiceSchedulerState)
    /* 647C 80015C7C 149B438C */  lw         $v1, %lo(D_80039B14)($v0)
    /* 6480 80015C80 0C00828C */  lw         $v0, 0xC($a0)
    /* 6484 80015C84 27186500 */  nor        $v1, $v1, $a1
    /* 6488 80015C88 24180301 */  and        $v1, $t0, $v1
    /* 648C 80015C8C 25104300 */  or         $v0, $v0, $v1
    /* 6490 80015C90 0C0082AC */  sw         $v0, 0xC($a0)
  .L80015C94:
    /* 6494 80015C94 0800E003 */  jr         $ra
    /* 6498 80015C98 00000000 */   nop
endlabel func_80015BAC
