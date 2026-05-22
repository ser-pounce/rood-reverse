nonmatching func_80102C94, 0x9C

glabel func_80102C94
    /* 494 80102C94 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 498 80102C98 2000B2AF */  sw         $s2, 0x20($sp)
    /* 49C 80102C9C 21908000 */  addu       $s2, $a0, $zero
    /* 4A0 80102CA0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 4A4 80102CA4 2198A000 */  addu       $s3, $a1, $zero
    /* 4A8 80102CA8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4AC 80102CAC 2180C000 */  addu       $s0, $a2, $zero
    /* 4B0 80102CB0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4B4 80102CB4 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4B8 80102CB8 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 4BC 80102CBC 2188E000 */   addu      $s1, $a3, $zero
    /* 4C0 80102CC0 21204002 */  addu       $a0, $s2, $zero
    /* 4C4 80102CC4 9B000524 */  addiu      $a1, $zero, 0x9B
    /* 4C8 80102CC8 12000624 */  addiu      $a2, $zero, 0x12
    /* 4CC 80102CCC 1000A0AF */  sw         $zero, 0x10($sp)
    /* 4D0 80102CD0 0000628E */  lw         $v0, 0x0($s3)
    /* 4D4 80102CD4 A5000724 */  addiu      $a3, $zero, 0xA5
    /* 4D8 80102CD8 9723030C */  jal        vs_battle_setMenuItem
    /* 4DC 80102CDC 1400A2AF */   sw        $v0, 0x14($sp)
    /* 4E0 80102CE0 01000324 */  addiu      $v1, $zero, 0x1
    /* 4E4 80102CE4 060043A0 */  sb         $v1, 0x6($v0)
    /* 4E8 80102CE8 821E1000 */  srl        $v1, $s0, 26
    /* 4EC 80102CEC 02841000 */  srl        $s0, $s0, 16
    /* 4F0 80102CF0 07001032 */  andi       $s0, $s0, 0x7
    /* 4F4 80102CF4 090043A0 */  sb         $v1, 0x9($v0)
    /* 4F8 80102CF8 0C0050A0 */  sb         $s0, 0xC($v0)
    /* 4FC 80102CFC 0400648E */  lw         $a0, 0x4($s3)
    /* 500 80102D00 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 504 80102D04 01003126 */   addiu     $s1, $s1, 0x1
    /* 508 80102D08 9223030C */  jal        vs_battle_getMenuItem
    /* 50C 80102D0C 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 510 80102D10 0E0051A4 */  sh         $s1, 0xE($v0)
    /* 514 80102D14 2800BF8F */  lw         $ra, 0x28($sp)
    /* 518 80102D18 2400B38F */  lw         $s3, 0x24($sp)
    /* 51C 80102D1C 2000B28F */  lw         $s2, 0x20($sp)
    /* 520 80102D20 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 524 80102D24 1800B08F */  lw         $s0, 0x18($sp)
    /* 528 80102D28 0800E003 */  jr         $ra
    /* 52C 80102D2C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80102C94
