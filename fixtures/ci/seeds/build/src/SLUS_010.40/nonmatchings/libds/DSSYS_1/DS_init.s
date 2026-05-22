nonmatching DS_init, 0x98

glabel DS_init
    /* 14E94 80024694 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14E98 80024698 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14E9C 8002469C C586000C */  jal        CD_init
    /* 14EA0 800246A0 00000000 */   nop
    /* 14EA4 800246A4 7686000C */  jal        CD_initvol
    /* 14EA8 800246A8 00000000 */   nop
    /* 14EAC 800246AC 0480013C */  lui        $at, %hi(D_80039E58)
    /* 14EB0 800246B0 589E20AC */  sw         $zero, %lo(D_80039E58)($at)
    /* 14EB4 800246B4 0480023C */  lui        $v0, %hi(D_80039E58)
    /* 14EB8 800246B8 589E428C */  lw         $v0, %lo(D_80039E58)($v0)
    /* 14EBC 800246BC 0480013C */  lui        $at, %hi(D_80039E54)
    /* 14EC0 800246C0 549E22AC */  sw         $v0, %lo(D_80039E54)($at)
    /* 14EC4 800246C4 0480013C */  lui        $at, %hi(D_80039E50)
    /* 14EC8 800246C8 CB91000C */  jal        DS_reset_members
    /* 14ECC 800246CC 509E20AC */   sw        $zero, %lo(D_80039E50)($at)
    /* 14ED0 800246D0 5198000C */  jal        DsReadMode
    /* 14ED4 800246D4 21200000 */   addu      $a0, $zero, $zero
    /* 14ED8 800246D8 0280023C */  lui        $v0, %hi(func_80024F34)
    /* 14EDC 800246DC 344F4224 */  addiu      $v0, $v0, %lo(func_80024F34)
    /* 14EE0 800246E0 0380013C */  lui        $at, %hi(D_800321FC)
    /* 14EE4 800246E4 FC2122AC */  sw         $v0, %lo(D_800321FC)($at)
    /* 14EE8 800246E8 0280023C */  lui        $v0, %hi(func_8002559C)
    /* 14EEC 800246EC 9C554224 */  addiu      $v0, $v0, %lo(func_8002559C)
    /* 14EF0 800246F0 0280053C */  lui        $a1, %hi(func_80024BDC)
    /* 14EF4 800246F4 DC4BA524 */  addiu      $a1, $a1, %lo(func_80024BDC)
    /* 14EF8 800246F8 0380013C */  lui        $at, %hi(D_80032200)
    /* 14EFC 800246FC 002222AC */  sw         $v0, %lo(D_80032200)($at)
    /* 14F00 80024700 667E000C */  jal        VSyncCallbacks
    /* 14F04 80024704 21200000 */   addu      $a0, $zero, $zero
    /* 14F08 80024708 01000224 */  addiu      $v0, $zero, 0x1
    /* 14F0C 8002470C 0380013C */  lui        $at, %hi(D_8003221C)
    /* 14F10 80024710 1C2222AC */  sw         $v0, %lo(D_8003221C)($at)
    /* 14F14 80024714 0380013C */  lui        $at, %hi(D_8003267C)
    /* 14F18 80024718 7C2622AC */  sw         $v0, %lo(D_8003267C)($at)
    /* 14F1C 8002471C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14F20 80024720 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 14F24 80024724 0800E003 */  jr         $ra
    /* 14F28 80024728 00000000 */   nop
endlabel DS_init
