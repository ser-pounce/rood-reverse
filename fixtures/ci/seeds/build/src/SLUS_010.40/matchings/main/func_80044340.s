nonmatching func_80044340, 0x8C

glabel func_80044340
    /* 34B40 80044340 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 34B44 80044344 2138A000 */  addu       $a3, $a1, $zero
    /* 34B48 80044348 1000B0AF */  sw         $s0, 0x10($sp)
    /* 34B4C 8004434C 0580103C */  lui        $s0, %hi(vs_main_disk)
    /* 34B50 80044350 105D0292 */  lbu        $v0, %lo(vs_main_disk)($s0)
    /* 34B54 80044354 105D0526 */  addiu      $a1, $s0, %lo(vs_main_disk)
    /* 34B58 80044358 17004014 */  bnez       $v0, .L800443B8
    /* 34B5C 8004435C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 34B60 80044360 C21A0700 */  srl        $v1, $a3, 11
    /* 34B64 80044364 FF07E230 */  andi       $v0, $a3, 0x7FF
    /* 34B68 80044368 0C00A4AC */  sw         $a0, 0xC($a1)
    /* 34B6C 8004436C 1000A7AC */  sw         $a3, 0x10($a1)
    /* 34B70 80044370 1400A6AC */  sw         $a2, 0x14($a1)
    /* 34B74 80044374 4000A0AC */  sw         $zero, 0x40($a1)
    /* 34B78 80044378 3C00A0AC */  sw         $zero, 0x3C($a1)
    /* 34B7C 8004437C 3000A0AC */  sw         $zero, 0x30($a1)
    /* 34B80 80044380 3400A0AC */  sw         $zero, 0x34($a1)
    /* 34B84 80044384 0400A0AC */  sw         $zero, 0x4($a1)
    /* 34B88 80044388 0300A0A0 */  sb         $zero, 0x3($a1)
    /* 34B8C 8004438C 3800A0AC */  sw         $zero, 0x38($a1)
    /* 34B90 80044390 03004010 */  beqz       $v0, .L800443A0
    /* 34B94 80044394 0800A3AC */   sw        $v1, 0x8($a1)
    /* 34B98 80044398 01006224 */  addiu      $v0, $v1, 0x1
    /* 34B9C 8004439C 0800A2AC */  sw         $v0, 0x8($a1)
  .L800443A0:
    /* 34BA0 800443A0 5996000C */  jal        DsIntToPos
    /* 34BA4 800443A4 1C00A524 */   addiu     $a1, $a1, 0x1C
    /* 34BA8 800443A8 05000224 */  addiu      $v0, $zero, 0x5
    /* 34BAC 800443AC 105D02A2 */  sb         $v0, %lo(vs_main_disk)($s0)
    /* 34BB0 800443B0 EF100108 */  j          .L800443BC
    /* 34BB4 800443B4 01000224 */   addiu     $v0, $zero, 0x1
  .L800443B8:
    /* 34BB8 800443B8 21100000 */  addu       $v0, $zero, $zero
  .L800443BC:
    /* 34BBC 800443BC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 34BC0 800443C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 34BC4 800443C4 0800E003 */  jr         $ra
    /* 34BC8 800443C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80044340
