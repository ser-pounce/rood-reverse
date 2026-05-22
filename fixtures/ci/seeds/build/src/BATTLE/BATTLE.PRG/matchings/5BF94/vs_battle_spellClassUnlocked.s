nonmatching vs_battle_spellClassUnlocked, 0x94

glabel vs_battle_spellClassUnlocked
    /* 626AC 800CAEAC 0F80023C */  lui        $v0, %hi(_spellClassCounts)
    /* 626B0 800CAEB0 A8BD4224 */  addiu      $v0, $v0, %lo(_spellClassCounts)
    /* 626B4 800CAEB4 21108200 */  addu       $v0, $a0, $v0
    /* 626B8 800CAEB8 00004690 */  lbu        $a2, 0x0($v0)
    /* 626BC 800CAEBC 00000000 */  nop
    /* 626C0 800CAEC0 1D00C010 */  beqz       $a2, .L800CAF38
    /* 626C4 800CAEC4 21280000 */   addu      $a1, $zero, $zero
    /* 626C8 800CAEC8 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 626CC 800CAECC DCB94824 */  addiu      $t0, $v0, %lo(vs_main_skills)
    /* 626D0 800CAED0 0F80033C */  lui        $v1, %hi(_spellIds)
    /* 626D4 800CAED4 ACBD6324 */  addiu      $v1, $v1, %lo(_spellIds)
    /* 626D8 800CAED8 80100400 */  sll        $v0, $a0, 2
    /* 626DC 800CAEDC 21104300 */  addu       $v0, $v0, $v1
    /* 626E0 800CAEE0 0000478C */  lw         $a3, 0x0($v0)
    /* 626E4 800CAEE4 2120C000 */  addu       $a0, $a2, $zero
    /* 626E8 800CAEE8 2110E500 */  addu       $v0, $a3, $a1
  .L800CAEEC:
    /* 626EC 800CAEEC 00004390 */  lbu        $v1, 0x0($v0)
    /* 626F0 800CAEF0 00000000 */  nop
    /* 626F4 800CAEF4 40100300 */  sll        $v0, $v1, 1
    /* 626F8 800CAEF8 21104300 */  addu       $v0, $v0, $v1
    /* 626FC 800CAEFC 80100200 */  sll        $v0, $v0, 2
    /* 62700 800CAF00 21104300 */  addu       $v0, $v0, $v1
    /* 62704 800CAF04 80100200 */  sll        $v0, $v0, 2
    /* 62708 800CAF08 21104800 */  addu       $v0, $v0, $t0
    /* 6270C 800CAF0C 0C00428C */  lw         $v0, 0xC($v0)
    /* 62710 800CAF10 00000000 */  nop
    /* 62714 800CAF14 C2130200 */  srl        $v0, $v0, 15
    /* 62718 800CAF18 01004230 */  andi       $v0, $v0, 0x1
    /* 6271C 800CAF1C 03004010 */  beqz       $v0, .L800CAF2C
    /* 62720 800CAF20 0100A524 */   addiu     $a1, $a1, 0x1
    /* 62724 800CAF24 0800E003 */  jr         $ra
    /* 62728 800CAF28 01000224 */   addiu     $v0, $zero, 0x1
  .L800CAF2C:
    /* 6272C 800CAF2C 2A10A400 */  slt        $v0, $a1, $a0
    /* 62730 800CAF30 EEFF4014 */  bnez       $v0, .L800CAEEC
    /* 62734 800CAF34 2110E500 */   addu      $v0, $a3, $a1
  .L800CAF38:
    /* 62738 800CAF38 0800E003 */  jr         $ra
    /* 6273C 800CAF3C 21100000 */   addu      $v0, $zero, $zero
endlabel vs_battle_spellClassUnlocked
