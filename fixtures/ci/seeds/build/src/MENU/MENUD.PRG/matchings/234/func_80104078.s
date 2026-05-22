nonmatching func_80104078, 0x9C

glabel func_80104078
    /* 1878 80104078 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 187C 8010407C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1880 80104080 21908000 */  addu       $s2, $a0, $zero
    /* 1884 80104084 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1888 80104088 2198A000 */  addu       $s3, $a1, $zero
    /* 188C 8010408C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1890 80104090 2180C000 */  addu       $s0, $a2, $zero
    /* 1894 80104094 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1898 80104098 2800BFAF */  sw         $ra, 0x28($sp)
    /* 189C 8010409C BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 18A0 801040A0 2188E000 */   addu      $s1, $a3, $zero
    /* 18A4 801040A4 21204002 */  addu       $a0, $s2, $zero
    /* 18A8 801040A8 9B000524 */  addiu      $a1, $zero, 0x9B
    /* 18AC 801040AC 12000624 */  addiu      $a2, $zero, 0x12
    /* 18B0 801040B0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 18B4 801040B4 0000628E */  lw         $v0, 0x0($s3)
    /* 18B8 801040B8 A5000724 */  addiu      $a3, $zero, 0xA5
    /* 18BC 801040BC 9723030C */  jal        vs_battle_setMenuItem
    /* 18C0 801040C0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 18C4 801040C4 01000324 */  addiu      $v1, $zero, 0x1
    /* 18C8 801040C8 060043A0 */  sb         $v1, 0x6($v0)
    /* 18CC 801040CC 821E1000 */  srl        $v1, $s0, 26
    /* 18D0 801040D0 02841000 */  srl        $s0, $s0, 16
    /* 18D4 801040D4 07001032 */  andi       $s0, $s0, 0x7
    /* 18D8 801040D8 090043A0 */  sb         $v1, 0x9($v0)
    /* 18DC 801040DC 0C0050A0 */  sb         $s0, 0xC($v0)
    /* 18E0 801040E0 0400648E */  lw         $a0, 0x4($s3)
    /* 18E4 801040E4 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 18E8 801040E8 01003126 */   addiu     $s1, $s1, 0x1
    /* 18EC 801040EC 9223030C */  jal        vs_battle_getMenuItem
    /* 18F0 801040F0 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 18F4 801040F4 0E0051A4 */  sh         $s1, 0xE($v0)
    /* 18F8 801040F8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 18FC 801040FC 2400B38F */  lw         $s3, 0x24($sp)
    /* 1900 80104100 2000B28F */  lw         $s2, 0x20($sp)
    /* 1904 80104104 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1908 80104108 1800B08F */  lw         $s0, 0x18($sp)
    /* 190C 8010410C 0800E003 */  jr         $ra
    /* 1910 80104110 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80104078
