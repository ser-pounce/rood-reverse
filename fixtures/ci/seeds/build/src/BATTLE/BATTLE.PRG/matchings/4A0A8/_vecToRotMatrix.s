nonmatching _vecToRotMatrix, 0xA4

glabel _vecToRotMatrix
    /* 5609C 800BE89C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 560A0 800BE8A0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 560A4 800BE8A4 2000B0AF */  sw         $s0, 0x20($sp)
    /* 560A8 800BE8A8 0000838C */  lw         $v1, 0x0($a0)
    /* 560AC 800BE8AC 2180A000 */  addu       $s0, $a1, $zero
    /* 560B0 800BE8B0 031B0300 */  sra        $v1, $v1, 12
    /* 560B4 800BE8B4 1800A3A7 */  sh         $v1, 0x18($sp)
    /* 560B8 800BE8B8 0400828C */  lw         $v0, 0x4($a0)
    /* 560BC 800BE8BC 001C0300 */  sll        $v1, $v1, 16
    /* 560C0 800BE8C0 03130200 */  sra        $v0, $v0, 12
    /* 560C4 800BE8C4 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 560C8 800BE8C8 0800828C */  lw         $v0, 0x8($a0)
    /* 560CC 800BE8CC 03240300 */  sra        $a0, $v1, 16
    /* 560D0 800BE8D0 03130200 */  sra        $v0, $v0, 12
    /* 560D4 800BE8D4 002C0200 */  sll        $a1, $v0, 16
    /* 560D8 800BE8D8 032C0500 */  sra        $a1, $a1, 16
    /* 560DC 800BE8DC DF04010C */  jal        ratan2
    /* 560E0 800BE8E0 1C00A2A7 */   sh        $v0, 0x1C($sp)
    /* 560E4 800BE8E4 1800A387 */  lh         $v1, 0x18($sp)
    /* 560E8 800BE8E8 00000000 */  nop
    /* 560EC 800BE8EC 18006300 */  mult       $v1, $v1
    /* 560F0 800BE8F0 12200000 */  mflo       $a0
    /* 560F4 800BE8F4 1C00A387 */  lh         $v1, 0x1C($sp)
    /* 560F8 800BE8F8 00000000 */  nop
    /* 560FC 800BE8FC 18006300 */  mult       $v1, $v1
    /* 56100 800BE900 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 56104 800BE904 12180000 */  mflo       $v1
    /* 56108 800BE908 E506010C */  jal        vs_gte_rsqrt
    /* 5610C 800BE90C 21208300 */   addu      $a0, $a0, $v1
    /* 56110 800BE910 1A00A487 */  lh         $a0, 0x1A($sp)
    /* 56114 800BE914 DF04010C */  jal        ratan2
    /* 56118 800BE918 21284000 */   addu      $a1, $v0, $zero
    /* 5611C 800BE91C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 56120 800BE920 21280002 */  addu       $a1, $s0, $zero
    /* 56124 800BE924 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 56128 800BE928 8004010C */  jal        RotMatrix_gte
    /* 5612C 800BE92C 1400A0A7 */   sh        $zero, 0x14($sp)
    /* 56130 800BE930 2400BF8F */  lw         $ra, 0x24($sp)
    /* 56134 800BE934 2000B08F */  lw         $s0, 0x20($sp)
    /* 56138 800BE938 0800E003 */  jr         $ra
    /* 5613C 800BE93C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _vecToRotMatrix
