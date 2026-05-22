nonmatching func_800CF7A8, 0x88

glabel func_800CF7A8
    /* 66FA8 800CF7A8 00FFBD27 */  addiu      $sp, $sp, -0x100
    /* 66FAC 800CF7AC 36000224 */  addiu      $v0, $zero, 0x36
    /* 66FB0 800CF7B0 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 66FB4 800CF7B4 01000224 */  addiu      $v0, $zero, 0x1
    /* 66FB8 800CF7B8 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 66FBC 800CF7BC 05000224 */  addiu      $v0, $zero, 0x5
    /* 66FC0 800CF7C0 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 66FC4 800CF7C4 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 66FC8 800CF7C8 FF008230 */  andi       $v0, $a0, 0xFF
    /* 66FCC 800CF7CC FF00A530 */  andi       $a1, $a1, 0xFF
    /* 66FD0 800CF7D0 002A0500 */  sll        $a1, $a1, 8
    /* 66FD4 800CF7D4 25104500 */  or         $v0, $v0, $a1
    /* 66FD8 800CF7D8 0F00C630 */  andi       $a2, $a2, 0xF
    /* 66FDC 800CF7DC 00340600 */  sll        $a2, $a2, 16
    /* 66FE0 800CF7E0 25104600 */  or         $v0, $v0, $a2
    /* 66FE4 800CF7E4 0F00E730 */  andi       $a3, $a3, 0xF
    /* 66FE8 800CF7E8 003D0700 */  sll        $a3, $a3, 20
    /* 66FEC 800CF7EC 25104700 */  or         $v0, $v0, $a3
    /* 66FF0 800CF7F0 00FF053C */  lui        $a1, (0xFF000000 >> 16)
    /* 66FF4 800CF7F4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 66FF8 800CF7F8 25284500 */  or         $a1, $v0, $a1
    /* 66FFC 800CF7FC F800BFAF */  sw         $ra, 0xF8($sp)
    /* 67000 800CF800 1800A0A7 */  sh         $zero, 0x18($sp)
    /* 67004 800CF804 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 67008 800CF808 1C00A0A7 */  sh         $zero, 0x1C($sp)
    /* 6700C 800CF80C 2400A0A7 */  sh         $zero, 0x24($sp)
    /* 67010 800CF810 2600A0A7 */  sh         $zero, 0x26($sp)
    /* 67014 800CF814 2800A0A7 */  sh         $zero, 0x28($sp)
    /* 67018 800CF818 FE3C030C */  jal        func_800CF3F8
    /* 6701C 800CF81C 1300A0A3 */   sb        $zero, 0x13($sp)
    /* 67020 800CF820 F800BF8F */  lw         $ra, 0xF8($sp)
    /* 67024 800CF824 00000000 */  nop
    /* 67028 800CF828 0800E003 */  jr         $ra
    /* 6702C 800CF82C 0001BD27 */   addiu     $sp, $sp, 0x100
endlabel func_800CF7A8
