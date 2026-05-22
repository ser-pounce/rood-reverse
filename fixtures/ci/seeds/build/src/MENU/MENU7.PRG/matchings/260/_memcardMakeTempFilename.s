nonmatching _memcardMakeTempFilename, 0x7C

glabel _memcardMakeTempFilename
    /* 438 80102C38 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 43C 80102C3C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 440 80102C40 21808000 */  addu       $s0, $a0, $zero
    /* 444 80102C44 1800B2AF */  sw         $s2, 0x18($sp)
    /* 448 80102C48 2190A000 */  addu       $s2, $a1, $zero
    /* 44C 80102C4C 1180023C */  lui        $v0, %hi(_filename1)
    /* 450 80102C50 1400B1AF */  sw         $s1, 0x14($sp)
    /* 454 80102C54 60AA5124 */  addiu      $s1, $v0, %lo(_filename1)
    /* 458 80102C58 21202002 */  addu       $a0, $s1, $zero
    /* 45C 80102C5C 21280000 */  addu       $a1, $zero, $zero
    /* 460 80102C60 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 464 80102C64 AD9B000C */  jal        memset
    /* 468 80102C68 20000624 */   addiu     $a2, $zero, 0x20
    /* 46C 80102C6C 1180023C */  lui        $v0, %hi(_memcardFilenameTemplate)
    /* 470 80102C70 B4A2458C */  lw         $a1, %lo(_memcardFilenameTemplate)($v0)
    /* 474 80102C74 A19B000C */  jal        strcpy
    /* 478 80102C78 21202002 */   addu      $a0, $s1, $zero
    /* 47C 80102C7C 02000016 */  bnez       $s0, .L80102C88
    /* 480 80102C80 31000224 */   addiu     $v0, $zero, 0x31
    /* 484 80102C84 30000224 */  addiu      $v0, $zero, 0x30
  .L80102C88:
    /* 488 80102C88 020022A2 */  sb         $v0, 0x2($s1)
    /* 48C 80102C8C 1180023C */  lui        $v0, %hi(_filename1)
    /* 490 80102C90 60AA4224 */  addiu      $v0, $v0, %lo(_filename1)
    /* 494 80102C94 40004326 */  addiu      $v1, $s2, 0x40
    /* 498 80102C98 140043A0 */  sb         $v1, 0x14($v0)
    /* 49C 80102C9C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4A0 80102CA0 1800B28F */  lw         $s2, 0x18($sp)
    /* 4A4 80102CA4 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A8 80102CA8 1000B08F */  lw         $s0, 0x10($sp)
    /* 4AC 80102CAC 0800E003 */  jr         $ra
    /* 4B0 80102CB0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _memcardMakeTempFilename
