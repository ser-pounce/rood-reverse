nonmatching func_800D4B34, 0x5C

glabel func_800D4B34
    /* 6C334 800D4B34 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C338 800D4B38 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6C33C 800D4B3C 21888000 */  addu       $s1, $a0, $zero
    /* 6C340 800D4B40 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6C344 800D4B44 5C54030C */  jal        func_800D5170
    /* 6C348 800D4B48 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6C34C 800D4B4C 21202002 */  addu       $a0, $s1, $zero
    /* 6C350 800D4B50 6654030C */  jal        func_800D5198
    /* 6C354 800D4B54 21804000 */   addu      $s0, $v0, $zero
    /* 6C358 800D4B58 FF001032 */  andi       $s0, $s0, 0xFF
    /* 6C35C 800D4B5C 21803002 */  addu       $s0, $s1, $s0
    /* 6C360 800D4B60 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 6C364 800D4B64 10000492 */  lbu        $a0, 0x10($s0)
    /* 6C368 800D4B68 21282002 */  addu       $a1, $s1, $zero
    /* 6C36C 800D4B6C 26208200 */  xor        $a0, $a0, $v0
    /* 6C370 800D4B70 B751030C */  jal        func_800D46DC
    /* 6C374 800D4B74 0100842C */   sltiu     $a0, $a0, 0x1
    /* 6C378 800D4B78 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6C37C 800D4B7C 1400B18F */  lw         $s1, 0x14($sp)
    /* 6C380 800D4B80 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C384 800D4B84 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C388 800D4B88 0800E003 */  jr         $ra
    /* 6C38C 800D4B8C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D4B34
