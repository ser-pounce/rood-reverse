nonmatching _memcardMakeTempFilename, 0x7C

glabel _memcardMakeTempFilename
    /* 4D8 80068CD8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4DC 80068CDC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4E0 80068CE0 21808000 */  addu       $s0, $a0, $zero
    /* 4E4 80068CE4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4E8 80068CE8 2190A000 */  addu       $s2, $a1, $zero
    /* 4EC 80068CEC 0E80023C */  lui        $v0, %hi(_memcardTempFilename)
    /* 4F0 80068CF0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4F4 80068CF4 88C85124 */  addiu      $s1, $v0, %lo(_memcardTempFilename)
    /* 4F8 80068CF8 21202002 */  addu       $a0, $s1, $zero
    /* 4FC 80068CFC 21280000 */  addu       $a1, $zero, $zero
    /* 500 80068D00 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 504 80068D04 AD9B000C */  jal        memset
    /* 508 80068D08 20000624 */   addiu     $a2, $zero, 0x20
    /* 50C 80068D0C 0780023C */  lui        $v0, %hi(_memcardFilenameTemplate)
    /* 510 80068D10 8C28458C */  lw         $a1, %lo(_memcardFilenameTemplate)($v0)
    /* 514 80068D14 A19B000C */  jal        strcpy
    /* 518 80068D18 21202002 */   addu      $a0, $s1, $zero
    /* 51C 80068D1C 02000016 */  bnez       $s0, .L80068D28
    /* 520 80068D20 31000224 */   addiu     $v0, $zero, 0x31
    /* 524 80068D24 30000224 */  addiu      $v0, $zero, 0x30
  .L80068D28:
    /* 528 80068D28 020022A2 */  sb         $v0, 0x2($s1)
    /* 52C 80068D2C 0E80023C */  lui        $v0, %hi(_memcardTempFilename)
    /* 530 80068D30 88C84224 */  addiu      $v0, $v0, %lo(_memcardTempFilename)
    /* 534 80068D34 40004326 */  addiu      $v1, $s2, 0x40
    /* 538 80068D38 140043A0 */  sb         $v1, 0x14($v0)
    /* 53C 80068D3C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 540 80068D40 1800B28F */  lw         $s2, 0x18($sp)
    /* 544 80068D44 1400B18F */  lw         $s1, 0x14($sp)
    /* 548 80068D48 1000B08F */  lw         $s0, 0x10($sp)
    /* 54C 80068D4C 0800E003 */  jr         $ra
    /* 550 80068D50 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _memcardMakeTempFilename
