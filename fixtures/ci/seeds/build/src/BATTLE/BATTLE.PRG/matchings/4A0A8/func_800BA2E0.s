nonmatching func_800BA2E0, 0x7C

glabel func_800BA2E0
    /* 51AE0 800BA2E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51AE4 800BA2E4 21388000 */  addu       $a3, $a0, $zero
    /* 51AE8 800BA2E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51AEC 800BA2EC 0100E390 */  lbu        $v1, 0x1($a3)
    /* 51AF0 800BA2F0 02000224 */  addiu      $v0, $zero, 0x2
    /* 51AF4 800BA2F4 0A006214 */  bne        $v1, $v0, .L800BA320
    /* 51AF8 800BA2F8 0F80033C */   lui       $v1, %hi(D_800E9B34)
    /* 51AFC 800BA2FC 0F80023C */  lui        $v0, %hi(D_800F4C08)
    /* 51B00 800BA300 084C4290 */  lbu        $v0, %lo(D_800F4C08)($v0)
    /* 51B04 800BA304 00000000 */  nop
    /* 51B08 800BA308 0F004010 */  beqz       $v0, .L800BA348
    /* 51B0C 800BA30C 0F80023C */   lui       $v0, %hi(D_800F4C4C)
    /* 51B10 800BA310 0200E390 */  lbu        $v1, 0x2($a3)
    /* 51B14 800BA314 00000000 */  nop
    /* 51B18 800BA318 4C4C43A4 */  sh         $v1, %lo(D_800F4C4C)($v0)
    /* 51B1C 800BA31C 0F80033C */  lui        $v1, %hi(D_800E9B34)
  .L800BA320:
    /* 51B20 800BA320 349B6324 */  addiu      $v1, $v1, %lo(D_800E9B34)
    /* 51B24 800BA324 0100E290 */  lbu        $v0, 0x1($a3)
    /* 51B28 800BA328 0200E590 */  lbu        $a1, 0x2($a3)
    /* 51B2C 800BA32C 0300E690 */  lbu        $a2, 0x3($a3)
    /* 51B30 800BA330 0400E790 */  lbu        $a3, 0x4($a3)
    /* 51B34 800BA334 80100200 */  sll        $v0, $v0, 2
    /* 51B38 800BA338 21104300 */  addu       $v0, $v0, $v1
    /* 51B3C 800BA33C 0000448C */  lw         $a0, 0x0($v0)
    /* 51B40 800BA340 D515010C */  jal        vs_main_playSfx
    /* 51B44 800BA344 00000000 */   nop
  .L800BA348:
    /* 51B48 800BA348 21100000 */  addu       $v0, $zero, $zero
    /* 51B4C 800BA34C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51B50 800BA350 00000000 */  nop
    /* 51B54 800BA354 0800E003 */  jr         $ra
    /* 51B58 800BA358 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA2E0
