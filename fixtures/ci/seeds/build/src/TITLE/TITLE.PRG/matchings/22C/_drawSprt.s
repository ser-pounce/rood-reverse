nonmatching _drawSprt, 0xA4

glabel _drawSprt
    /* 1F78 8006A778 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1F7C 8006A77C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1F80 8006A780 21888000 */  addu       $s1, $a0, $zero
    /* 1F84 8006A784 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1F88 8006A788 2190A000 */  addu       $s2, $a1, $zero
    /* 1F8C 8006A78C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1F90 8006A790 2198C000 */  addu       $s3, $a2, $zero
    /* 1F94 8006A794 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1F98 8006A798 2180E000 */  addu       $s0, $a3, $zero
    /* 1F9C 8006A79C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1FA0 8006A7A0 94A1000C */  jal        DrawSync
    /* 1FA4 8006A7A4 21200000 */   addu      $a0, $zero, $zero
    /* 1FA8 8006A7A8 0E80033C */  lui        $v1, %hi(_primBuf)
    /* 1FAC 8006A7AC 28ED6424 */  addiu      $a0, $v1, %lo(_primBuf)
    /* 1FB0 8006A7B0 0005023C */  lui        $v0, (0x5000000 >> 16)
    /* 1FB4 8006A7B4 28ED62AC */  sw         $v0, %lo(_primBuf)($v1)
    /* 1FB8 8006A7B8 FF090232 */  andi       $v0, $s0, 0x9FF
    /* 1FBC 8006A7BC 00E1033C */  lui        $v1, (0xE1000000 >> 16)
    /* 1FC0 8006A7C0 25104300 */  or         $v0, $v0, $v1
    /* 1FC4 8006A7C4 03841000 */  sra        $s0, $s0, 16
    /* 1FC8 8006A7C8 80000324 */  addiu      $v1, $zero, 0x80
    /* 1FCC 8006A7CC 23187000 */  subu       $v1, $v1, $s0
    /* 1FD0 8006A7D0 040082AC */  sw         $v0, 0x4($a0)
    /* 1FD4 8006A7D4 00120300 */  sll        $v0, $v1, 8
    /* 1FD8 8006A7D8 21104300 */  addu       $v0, $v0, $v1
    /* 1FDC 8006A7DC 00120200 */  sll        $v0, $v0, 8
    /* 1FE0 8006A7E0 21104300 */  addu       $v0, $v0, $v1
    /* 1FE4 8006A7E4 0064033C */  lui        $v1, (0x64000000 >> 16)
    /* 1FE8 8006A7E8 25104300 */  or         $v0, $v0, $v1
    /* 1FEC 8006A7EC 080082AC */  sw         $v0, 0x8($a0)
    /* 1FF0 8006A7F0 0C0091AC */  sw         $s1, 0xC($a0)
    /* 1FF4 8006A7F4 100092AC */  sw         $s2, 0x10($a0)
    /* 1FF8 8006A7F8 FAA2000C */  jal        DrawPrim
    /* 1FFC 8006A7FC 140093AC */   sw        $s3, 0x14($a0)
    /* 2000 8006A800 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2004 8006A804 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2008 8006A808 1800B28F */  lw         $s2, 0x18($sp)
    /* 200C 8006A80C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2010 8006A810 1000B08F */  lw         $s0, 0x10($sp)
    /* 2014 8006A814 0800E003 */  jr         $ra
    /* 2018 8006A818 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _drawSprt
