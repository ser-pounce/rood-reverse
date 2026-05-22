nonmatching func_8006F450, 0x60

glabel func_8006F450
    /* 6C50 8006F450 00FFBD27 */  addiu      $sp, $sp, -0x100
    /* 6C54 8006F454 24000224 */  addiu      $v0, $zero, 0x24
    /* 6C58 8006F458 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 6C5C 8006F45C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C60 8006F460 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 6C64 8006F464 04000224 */  addiu      $v0, $zero, 0x4
    /* 6C68 8006F468 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 6C6C 8006F46C 05000224 */  addiu      $v0, $zero, 0x5
    /* 6C70 8006F470 F800BFAF */  sw         $ra, 0xF8($sp)
    /* 6C74 8006F474 1300A0A3 */  sb         $zero, 0x13($sp)
    /* 6C78 8006F478 1800A0A3 */  sb         $zero, 0x18($sp)
    /* 6C7C 8006F47C 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 6C80 8006F480 00008294 */  lhu        $v0, 0x0($a0)
    /* 6C84 8006F484 21280000 */  addu       $a1, $zero, $zero
    /* 6C88 8006F488 2400A2A7 */  sh         $v0, 0x24($sp)
    /* 6C8C 8006F48C 04008294 */  lhu        $v0, 0x4($a0)
    /* 6C90 8006F490 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6C94 8006F494 2600A0A7 */  sh         $zero, 0x26($sp)
    /* 6C98 8006F498 FE3C030C */  jal        func_800CF3F8
    /* 6C9C 8006F49C 2800A2A7 */   sh        $v0, 0x28($sp)
    /* 6CA0 8006F4A0 F800BF8F */  lw         $ra, 0xF8($sp)
    /* 6CA4 8006F4A4 00000000 */  nop
    /* 6CA8 8006F4A8 0800E003 */  jr         $ra
    /* 6CAC 8006F4AC 0001BD27 */   addiu     $sp, $sp, 0x100
endlabel func_8006F450
