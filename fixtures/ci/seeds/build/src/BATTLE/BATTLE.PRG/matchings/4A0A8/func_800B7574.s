nonmatching func_800B7574, 0x80

glabel func_800B7574
    /* 4ED74 800B7574 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4ED78 800B7578 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4ED7C 800B757C 21808000 */  addu       $s0, $a0, $zero
    /* 4ED80 800B7580 2400BFAF */  sw         $ra, 0x24($sp)
    /* 4ED84 800B7584 05000292 */  lbu        $v0, 0x5($s0)
    /* 4ED88 800B7588 00000000 */  nop
    /* 4ED8C 800B758C 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 4ED90 800B7590 06000292 */  lbu        $v0, 0x6($s0)
    /* 4ED94 800B7594 00000000 */  nop
    /* 4ED98 800B7598 1100A2A3 */  sb         $v0, 0x11($sp)
    /* 4ED9C 800B759C 07000292 */  lbu        $v0, 0x7($s0)
    /* 4EDA0 800B75A0 00000000 */  nop
    /* 4EDA4 800B75A4 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 4EDA8 800B75A8 08000292 */  lbu        $v0, 0x8($s0)
    /* 4EDAC 800B75AC 01000426 */  addiu      $a0, $s0, 0x1
    /* 4EDB0 800B75B0 80FF020C */  jal        vs_battle_getShort
    /* 4EDB4 800B75B4 1300A2A3 */   sb        $v0, 0x13($sp)
    /* 4EDB8 800B75B8 94FF020C */  jal        func_800BFE50
    /* 4EDBC 800B75BC FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4EDC0 800B75C0 03000426 */  addiu      $a0, $s0, 0x3
    /* 4EDC4 800B75C4 80FF020C */  jal        vs_battle_getShort
    /* 4EDC8 800B75C8 21804000 */   addu      $s0, $v0, $zero
    /* 4EDCC 800B75CC 21200002 */  addu       $a0, $s0, $zero
    /* 4EDD0 800B75D0 00140200 */  sll        $v0, $v0, 16
    /* 4EDD4 800B75D4 032C0200 */  sra        $a1, $v0, 16
    /* 4EDD8 800B75D8 4AF2010C */  jal        func_8007C928
    /* 4EDDC 800B75DC 1000A627 */   addiu     $a2, $sp, 0x10
    /* 4EDE0 800B75E0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4EDE4 800B75E4 2000B08F */  lw         $s0, 0x20($sp)
    /* 4EDE8 800B75E8 21100000 */  addu       $v0, $zero, $zero
    /* 4EDEC 800B75EC 0800E003 */  jr         $ra
    /* 4EDF0 800B75F0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800B7574
