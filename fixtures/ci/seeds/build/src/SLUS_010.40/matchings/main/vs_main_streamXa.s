nonmatching vs_main_streamXa, 0x50

glabel vs_main_streamXa
    /* 351E8 800449E8 0580063C */  lui        $a2, %hi(vs_main_disk)
    /* 351EC 800449EC 105DC290 */  lbu        $v0, %lo(vs_main_disk)($a2)
    /* 351F0 800449F0 00000000 */  nop
    /* 351F4 800449F4 03004010 */  beqz       $v0, .L80044A04
    /* 351F8 800449F8 105DC324 */   addiu     $v1, $a2, %lo(vs_main_disk)
    /* 351FC 800449FC 0800E003 */  jr         $ra
    /* 35200 80044A00 21100000 */   addu      $v0, $zero, $zero
  .L80044A04:
    /* 35204 80044A04 01000224 */  addiu      $v0, $zero, 0x1
    /* 35208 80044A08 0C0064AC */  sw         $a0, 0xC($v1)
    /* 3520C 80044A0C 100065AC */  sw         $a1, 0x10($v1)
    /* 35210 80044A10 400060AC */  sw         $zero, 0x40($v1)
    /* 35214 80044A14 3C0060AC */  sw         $zero, 0x3C($v1)
    /* 35218 80044A18 300060AC */  sw         $zero, 0x30($v1)
    /* 3521C 80044A1C 340060AC */  sw         $zero, 0x34($v1)
    /* 35220 80044A20 040060AC */  sw         $zero, 0x4($v1)
    /* 35224 80044A24 030060A0 */  sb         $zero, 0x3($v1)
    /* 35228 80044A28 380060AC */  sw         $zero, 0x38($v1)
    /* 3522C 80044A2C 06000324 */  addiu      $v1, $zero, 0x6
    /* 35230 80044A30 0800E003 */  jr         $ra
    /* 35234 80044A34 105DC3A0 */   sb        $v1, %lo(vs_main_disk)($a2)
endlabel vs_main_streamXa
