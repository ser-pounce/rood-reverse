nonmatching _setVectorImm, 0x6C

glabel _setVectorImm
    /* 55FB8 800BE7B8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 55FBC 800BE7BC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 55FC0 800BE7C0 21888000 */  addu       $s1, $a0, $zero
    /* 55FC4 800BE7C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 55FC8 800BE7C8 2180A000 */  addu       $s0, $a1, $zero
    /* 55FCC 800BE7CC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 55FD0 800BE7D0 80FF020C */  jal        vs_battle_getShort
    /* 55FD4 800BE7D4 21200002 */   addu      $a0, $s0, $zero
    /* 55FD8 800BE7D8 02000426 */  addiu      $a0, $s0, 0x2
    /* 55FDC 800BE7DC 00140200 */  sll        $v0, $v0, 16
    /* 55FE0 800BE7E0 03110200 */  sra        $v0, $v0, 4
    /* 55FE4 800BE7E4 80FF020C */  jal        vs_battle_getShort
    /* 55FE8 800BE7E8 000022AE */   sw        $v0, 0x0($s1)
    /* 55FEC 800BE7EC 04000426 */  addiu      $a0, $s0, 0x4
    /* 55FF0 800BE7F0 00140200 */  sll        $v0, $v0, 16
    /* 55FF4 800BE7F4 03110200 */  sra        $v0, $v0, 4
    /* 55FF8 800BE7F8 80FF020C */  jal        vs_battle_getShort
    /* 55FFC 800BE7FC 040022AE */   sw        $v0, 0x4($s1)
    /* 56000 800BE800 001C0200 */  sll        $v1, $v0, 16
    /* 56004 800BE804 21102002 */  addu       $v0, $s1, $zero
    /* 56008 800BE808 03190300 */  sra        $v1, $v1, 4
    /* 5600C 800BE80C 080043AC */  sw         $v1, 0x8($v0)
    /* 56010 800BE810 1800BF8F */  lw         $ra, 0x18($sp)
    /* 56014 800BE814 1400B18F */  lw         $s1, 0x14($sp)
    /* 56018 800BE818 1000B08F */  lw         $s0, 0x10($sp)
    /* 5601C 800BE81C 0800E003 */  jr         $ra
    /* 56020 800BE820 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _setVectorImm
