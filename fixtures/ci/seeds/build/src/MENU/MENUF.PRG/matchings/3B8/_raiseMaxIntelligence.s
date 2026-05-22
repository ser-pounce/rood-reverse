nonmatching _raiseMaxIntelligence, 0x90

glabel _raiseMaxIntelligence
    /* 6798 80108F98 21308000 */  addu       $a2, $a0, $zero
    /* 679C 80108F9C 0F80053C */  lui        $a1, %hi(vs_battle_characterState)
    /* 67A0 80108FA0 FC19A48C */  lw         $a0, %lo(vs_battle_characterState)($a1)
    /* 67A4 80108FA4 00000000 */  nop
    /* 67A8 80108FA8 3C00838C */  lw         $v1, 0x3C($a0)
    /* 67AC 80108FAC 00000000 */  nop
    /* 67B0 80108FB0 28006294 */  lhu        $v0, 0x28($v1)
    /* 67B4 80108FB4 00000000 */  nop
    /* 67B8 80108FB8 21104600 */  addu       $v0, $v0, $a2
    /* 67BC 80108FBC 280062A4 */  sh         $v0, 0x28($v1)
    /* 67C0 80108FC0 3C00838C */  lw         $v1, 0x3C($a0)
    /* 67C4 80108FC4 00000000 */  nop
    /* 67C8 80108FC8 28006294 */  lhu        $v0, 0x28($v1)
    /* 67CC 80108FCC 00000000 */  nop
    /* 67D0 80108FD0 E803422C */  sltiu      $v0, $v0, 0x3E8
    /* 67D4 80108FD4 02004014 */  bnez       $v0, .L80108FE0
    /* 67D8 80108FD8 E7030224 */   addiu     $v0, $zero, 0x3E7
    /* 67DC 80108FDC 280062A4 */  sh         $v0, 0x28($v1)
  .L80108FE0:
    /* 67E0 80108FE0 FC19A48C */  lw         $a0, %lo(vs_battle_characterState)($a1)
    /* 67E4 80108FE4 00000000 */  nop
    /* 67E8 80108FE8 3C00838C */  lw         $v1, 0x3C($a0)
    /* 67EC 80108FEC 00000000 */  nop
    /* 67F0 80108FF0 26006294 */  lhu        $v0, 0x26($v1)
    /* 67F4 80108FF4 00000000 */  nop
    /* 67F8 80108FF8 21104600 */  addu       $v0, $v0, $a2
    /* 67FC 80108FFC 260062A4 */  sh         $v0, 0x26($v1)
    /* 6800 80109000 3C00838C */  lw         $v1, 0x3C($a0)
    /* 6804 80109004 00000000 */  nop
    /* 6808 80109008 26006294 */  lhu        $v0, 0x26($v1)
    /* 680C 8010900C 00000000 */  nop
    /* 6810 80109010 E803422C */  sltiu      $v0, $v0, 0x3E8
    /* 6814 80109014 02004014 */  bnez       $v0, .L80109020
    /* 6818 80109018 E7030224 */   addiu     $v0, $zero, 0x3E7
    /* 681C 8010901C 260062A4 */  sh         $v0, 0x26($v1)
  .L80109020:
    /* 6820 80109020 0800E003 */  jr         $ra
    /* 6824 80109024 00000000 */   nop
endlabel _raiseMaxIntelligence
