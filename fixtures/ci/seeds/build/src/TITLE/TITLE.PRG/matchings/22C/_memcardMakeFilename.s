nonmatching _memcardMakeFilename, 0x7C

glabel _memcardMakeFilename
    /* 45C 80068C5C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 460 80068C60 1000B0AF */  sw         $s0, 0x10($sp)
    /* 464 80068C64 21808000 */  addu       $s0, $a0, $zero
    /* 468 80068C68 1800B2AF */  sw         $s2, 0x18($sp)
    /* 46C 80068C6C 2190A000 */  addu       $s2, $a1, $zero
    /* 470 80068C70 0E80023C */  lui        $v0, %hi(_memcardFilename)
    /* 474 80068C74 1400B1AF */  sw         $s1, 0x14($sp)
    /* 478 80068C78 68C85124 */  addiu      $s1, $v0, %lo(_memcardFilename)
    /* 47C 80068C7C 21202002 */  addu       $a0, $s1, $zero
    /* 480 80068C80 21280000 */  addu       $a1, $zero, $zero
    /* 484 80068C84 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 488 80068C88 AD9B000C */  jal        memset
    /* 48C 80068C8C 20000624 */   addiu     $a2, $zero, 0x20
    /* 490 80068C90 0780023C */  lui        $v0, %hi(_memcardFilenameTemplate)
    /* 494 80068C94 8C28458C */  lw         $a1, %lo(_memcardFilenameTemplate)($v0)
    /* 498 80068C98 A19B000C */  jal        strcpy
    /* 49C 80068C9C 21202002 */   addu      $a0, $s1, $zero
    /* 4A0 80068CA0 02000016 */  bnez       $s0, .L80068CAC
    /* 4A4 80068CA4 31000224 */   addiu     $v0, $zero, 0x31
    /* 4A8 80068CA8 30000224 */  addiu      $v0, $zero, 0x30
  .L80068CAC:
    /* 4AC 80068CAC 020022A2 */  sb         $v0, 0x2($s1)
    /* 4B0 80068CB0 0E80023C */  lui        $v0, %hi(_memcardFilename)
    /* 4B4 80068CB4 68C84224 */  addiu      $v0, $v0, %lo(_memcardFilename)
    /* 4B8 80068CB8 30004326 */  addiu      $v1, $s2, 0x30
    /* 4BC 80068CBC 140043A0 */  sb         $v1, 0x14($v0)
    /* 4C0 80068CC0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4C4 80068CC4 1800B28F */  lw         $s2, 0x18($sp)
    /* 4C8 80068CC8 1400B18F */  lw         $s1, 0x14($sp)
    /* 4CC 80068CCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 4D0 80068CD0 0800E003 */  jr         $ra
    /* 4D4 80068CD4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _memcardMakeFilename
