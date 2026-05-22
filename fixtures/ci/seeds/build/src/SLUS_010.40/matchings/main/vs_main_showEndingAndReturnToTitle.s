nonmatching vs_main_showEndingAndReturnToTitle, 0x138

glabel vs_main_showEndingAndReturnToTitle
    /* 32CE4 800424E4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 32CE8 800424E8 21200000 */  addu       $a0, $zero, $zero
    /* 32CEC 800424EC 0680023C */  lui        $v0, %hi(_inGame)
    /* 32CF0 800424F0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 32CF4 800424F4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 32CF8 800424F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 32CFC 800424FC 94A1000C */  jal        DrawSync
    /* 32D00 80042500 40E240AC */   sw        $zero, %lo(_inGame)($v0)
    /* 32D04 80042504 94A1000C */  jal        DrawSync
    /* 32D08 80042508 21200000 */   addu      $a0, $zero, $zero
    /* 32D0C 8004250C 6EA1000C */  jal        SetDispMask
    /* 32D10 80042510 21200000 */   addu      $a0, $zero, $zero
    /* 32D14 80042514 21200000 */  addu       $a0, $zero, $zero
    /* 32D18 80042518 21288000 */  addu       $a1, $a0, $zero
    /* 32D1C 8004251C C80C010C */  jal        padSetActData
    /* 32D20 80042520 21308000 */   addu      $a2, $a0, $zero
    /* 32D24 80042524 21200000 */  addu       $a0, $zero, $zero
    /* 32D28 80042528 01000524 */  addiu      $a1, $zero, 0x1
    /* 32D2C 8004252C C80C010C */  jal        padSetActData
    /* 32D30 80042530 21308000 */   addu      $a2, $a0, $zero
    /* 32D34 80042534 21200000 */  addu       $a0, $zero, $zero
    /* 32D38 80042538 0680103C */  lui        $s0, %hi(vs_main_padBuffer)
    /* 32D3C 8004253C F0DF1026 */  addiu      $s0, $s0, %lo(vs_main_padBuffer)
    /* 32D40 80042540 940C010C */  jal        vs_main_padConnect
    /* 32D44 80042544 21280002 */   addu      $a1, $s0, $zero
    /* 32D48 80042548 10000424 */  addiu      $a0, $zero, 0x10
    /* 32D4C 8004254C 22001126 */  addiu      $s1, $s0, 0x22
    /* 32D50 80042550 940C010C */  jal        vs_main_padConnect
    /* 32D54 80042554 21282002 */   addu      $a1, $s1, $zero
    /* 32D58 80042558 B5A0000C */  jal        ResetGraph
    /* 32D5C 8004255C 03000424 */   addiu     $a0, $zero, 0x3
    /* 32D60 80042560 DE4A000C */  jal        func_80012B78
    /* 32D64 80042564 00000000 */   nop
    /* 32D68 80042568 E64A000C */  jal        func_80012B98
    /* 32D6C 8004256C 00000000 */   nop
    /* 32D70 80042570 2C0B010C */  jal        func_80042CB0
    /* 32D74 80042574 00000000 */   nop
    /* 32D78 80042578 F107010C */  jal        func_80041FC4
    /* 32D7C 8004257C 00000000 */   nop
    /* 32D80 80042580 70A9010C */  jal        func_8006A5C0
    /* 32D84 80042584 00000000 */   nop
    /* 32D88 80042588 94A1000C */  jal        DrawSync
    /* 32D8C 8004258C 21200000 */   addu      $a0, $zero, $zero
    /* 32D90 80042590 94A1000C */  jal        DrawSync
    /* 32D94 80042594 21200000 */   addu      $a0, $zero, $zero
    /* 32D98 80042598 6EA1000C */  jal        SetDispMask
    /* 32D9C 8004259C 21200000 */   addu      $a0, $zero, $zero
    /* 32DA0 800425A0 21200000 */  addu       $a0, $zero, $zero
    /* 32DA4 800425A4 21288000 */  addu       $a1, $a0, $zero
    /* 32DA8 800425A8 C80C010C */  jal        padSetActData
    /* 32DAC 800425AC 21308000 */   addu      $a2, $a0, $zero
    /* 32DB0 800425B0 21200000 */  addu       $a0, $zero, $zero
    /* 32DB4 800425B4 01000524 */  addiu      $a1, $zero, 0x1
    /* 32DB8 800425B8 C80C010C */  jal        padSetActData
    /* 32DBC 800425BC 21308000 */   addu      $a2, $a0, $zero
    /* 32DC0 800425C0 21200000 */  addu       $a0, $zero, $zero
    /* 32DC4 800425C4 940C010C */  jal        vs_main_padConnect
    /* 32DC8 800425C8 21280002 */   addu      $a1, $s0, $zero
    /* 32DCC 800425CC 10000424 */  addiu      $a0, $zero, 0x10
    /* 32DD0 800425D0 940C010C */  jal        vs_main_padConnect
    /* 32DD4 800425D4 21282002 */   addu      $a1, $s1, $zero
    /* 32DD8 800425D8 7347000C */  jal        TeardownSound
    /* 32DDC 800425DC 00000000 */   nop
    /* 32DE0 800425E0 8179000C */  jal        SpuQuit
    /* 32DE4 800425E4 00000000 */   nop
    /* 32DE8 800425E8 B5A0000C */  jal        ResetGraph
    /* 32DEC 800425EC 03000424 */   addiu     $a0, $zero, 0x3
    /* 32DF0 800425F0 0580043C */  lui        $a0, %hi(sp2)
    /* 32DF4 800425F4 74048424 */  addiu      $a0, $a0, %lo(sp2)
    /* 32DF8 800425F8 0680033C */  lui        $v1, %hi(vs_main_saveGameClearData)
    /* 32DFC 800425FC 01000224 */  addiu      $v0, $zero, 0x1
    /* 32E00 80042600 AD42000C */  jal        vs_overlay_jumpToTitle
    /* 32E04 80042604 14E262AC */   sw        $v0, %lo(vs_main_saveGameClearData)($v1)
    /* 32E08 80042608 1800BF8F */  lw         $ra, 0x18($sp)
    /* 32E0C 8004260C 1400B18F */  lw         $s1, 0x14($sp)
    /* 32E10 80042610 1000B08F */  lw         $s0, 0x10($sp)
    /* 32E14 80042614 0800E003 */  jr         $ra
    /* 32E18 80042618 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_main_showEndingAndReturnToTitle
