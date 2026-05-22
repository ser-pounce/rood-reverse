nonmatching func_8001FE58, 0xA0

glabel func_8001FE58
    /* 10658 8001FE58 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1065C 8001FE5C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 10660 8001FE60 0380103C */  lui        $s0, %hi(D_8003104C)
    /* 10664 8001FE64 4C101026 */  addiu      $s0, $s0, %lo(D_8003104C)
    /* 10668 8001FE68 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1066C 8001FE6C 00000296 */  lhu        $v0, 0x0($s0)
    /* 10670 8001FE70 00000000 */  nop
    /* 10674 8001FE74 1C004010 */  beqz       $v0, .L8001FEE8
    /* 10678 8001FE78 21100000 */   addu      $v0, $zero, $zero
    /* 1067C 8001FE7C 5D9A000C */  jal        EnterCriticalSection
    /* 10680 8001FE80 00000000 */   nop
    /* 10684 8001FE84 0380023C */  lui        $v0, %hi(D_800320DC)
    /* 10688 8001FE88 DC20428C */  lw         $v0, %lo(D_800320DC)($v0)
    /* 1068C 8001FE8C 0380043C */  lui        $a0, %hi(D_800320E0)
    /* 10690 8001FE90 E020848C */  lw         $a0, %lo(D_800320E0)($a0)
    /* 10694 8001FE94 00004394 */  lhu        $v1, 0x0($v0)
    /* 10698 8001FE98 00000000 */  nop
    /* 1069C 8001FE9C 320003A6 */  sh         $v1, 0x32($s0)
    /* 106A0 8001FEA0 0000838C */  lw         $v1, 0x0($a0)
    /* 106A4 8001FEA4 0380043C */  lui        $a0, %hi(D_800320D8)
    /* 106A8 8001FEA8 D820848C */  lw         $a0, %lo(D_800320D8)($a0)
    /* 106AC 8001FEAC 340003AE */  sw         $v1, 0x34($s0)
    /* 106B0 8001FEB0 000040A4 */  sh         $zero, 0x0($v0)
    /* 106B4 8001FEB4 00004294 */  lhu        $v0, 0x0($v0)
    /* 106B8 8001FEB8 00000000 */  nop
    /* 106BC 8001FEBC 000082A4 */  sh         $v0, 0x0($a0)
    /* 106C0 8001FEC0 0380043C */  lui        $a0, %hi(D_800320E0)
    /* 106C4 8001FEC4 E020848C */  lw         $a0, %lo(D_800320E0)($a0)
    /* 106C8 8001FEC8 7777033C */  lui        $v1, (0x77777777 >> 16)
    /* 106CC 8001FECC 0000828C */  lw         $v0, 0x0($a0)
    /* 106D0 8001FED0 77776334 */  ori        $v1, $v1, (0x77777777 & 0xFFFF)
    /* 106D4 8001FED4 24104300 */  and        $v0, $v0, $v1
    /* 106D8 8001FED8 519A000C */  jal        ResetEntryInt
    /* 106DC 8001FEDC 000082AC */   sw        $v0, 0x0($a0)
    /* 106E0 8001FEE0 21100002 */  addu       $v0, $s0, $zero
    /* 106E4 8001FEE4 000040A4 */  sh         $zero, 0x0($v0)
  .L8001FEE8:
    /* 106E8 8001FEE8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 106EC 8001FEEC 1000B08F */  lw         $s0, 0x10($sp)
    /* 106F0 8001FEF0 0800E003 */  jr         $ra
    /* 106F4 8001FEF4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001FE58
