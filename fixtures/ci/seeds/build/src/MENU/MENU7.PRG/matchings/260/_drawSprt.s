nonmatching _drawSprt, 0xA4

glabel _drawSprt
    /* 1EC0 801046C0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1EC4 801046C4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1EC8 801046C8 21888000 */  addu       $s1, $a0, $zero
    /* 1ECC 801046CC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1ED0 801046D0 2190A000 */  addu       $s2, $a1, $zero
    /* 1ED4 801046D4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1ED8 801046D8 2198C000 */  addu       $s3, $a2, $zero
    /* 1EDC 801046DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1EE0 801046E0 2180E000 */  addu       $s0, $a3, $zero
    /* 1EE4 801046E4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1EE8 801046E8 94A1000C */  jal        DrawSync
    /* 1EEC 801046EC 21200000 */   addu      $a0, $zero, $zero
    /* 1EF0 801046F0 1180033C */  lui        $v1, %hi(_primBuf)
    /* 1EF4 801046F4 60B06424 */  addiu      $a0, $v1, %lo(_primBuf)
    /* 1EF8 801046F8 0005023C */  lui        $v0, (0x5000000 >> 16)
    /* 1EFC 801046FC 60B062AC */  sw         $v0, %lo(_primBuf)($v1)
    /* 1F00 80104700 FF090232 */  andi       $v0, $s0, 0x9FF
    /* 1F04 80104704 00E1033C */  lui        $v1, (0xE1000000 >> 16)
    /* 1F08 80104708 25104300 */  or         $v0, $v0, $v1
    /* 1F0C 8010470C 03841000 */  sra        $s0, $s0, 16
    /* 1F10 80104710 80000324 */  addiu      $v1, $zero, 0x80
    /* 1F14 80104714 23187000 */  subu       $v1, $v1, $s0
    /* 1F18 80104718 040082AC */  sw         $v0, 0x4($a0)
    /* 1F1C 8010471C 00120300 */  sll        $v0, $v1, 8
    /* 1F20 80104720 21104300 */  addu       $v0, $v0, $v1
    /* 1F24 80104724 00120200 */  sll        $v0, $v0, 8
    /* 1F28 80104728 21104300 */  addu       $v0, $v0, $v1
    /* 1F2C 8010472C 0064033C */  lui        $v1, (0x64000000 >> 16)
    /* 1F30 80104730 25104300 */  or         $v0, $v0, $v1
    /* 1F34 80104734 080082AC */  sw         $v0, 0x8($a0)
    /* 1F38 80104738 0C0091AC */  sw         $s1, 0xC($a0)
    /* 1F3C 8010473C 100092AC */  sw         $s2, 0x10($a0)
    /* 1F40 80104740 FAA2000C */  jal        DrawPrim
    /* 1F44 80104744 140093AC */   sw        $s3, 0x14($a0)
    /* 1F48 80104748 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1F4C 8010474C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1F50 80104750 1800B28F */  lw         $s2, 0x18($sp)
    /* 1F54 80104754 1400B18F */  lw         $s1, 0x14($sp)
    /* 1F58 80104758 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F5C 8010475C 0800E003 */  jr         $ra
    /* 1F60 80104760 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _drawSprt
