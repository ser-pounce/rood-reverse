nonmatching vs_battle_script_setFlag, 0x294

glabel vs_battle_script_setFlag
    /* 506DC 800B8EDC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 506E0 800B8EE0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 506E4 800B8EE4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 506E8 800B8EE8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 506EC 800B8EEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 506F0 800B8EF0 02008390 */  lbu        $v1, 0x2($a0)
    /* 506F4 800B8EF4 01008690 */  lbu        $a2, 0x1($a0)
    /* 506F8 800B8EF8 82280300 */  srl        $a1, $v1, 2
    /* 506FC 800B8EFC 0F00C230 */  andi       $v0, $a2, 0xF
    /* 50700 800B8F00 80110200 */  sll        $v0, $v0, 6
    /* 50704 800B8F04 2180A200 */  addu       $s0, $a1, $v0
    /* 50708 800B8F08 03006330 */  andi       $v1, $v1, 0x3
    /* 5070C 800B8F0C 001A0300 */  sll        $v1, $v1, 8
    /* 50710 800B8F10 03008290 */  lbu        $v0, 0x3($a0)
    /* 50714 800B8F14 F000C630 */  andi       $a2, $a2, 0xF0
    /* 50718 800B8F18 21904300 */  addu       $s2, $v0, $v1
    /* 5071C 800B8F1C 40000224 */  addiu      $v0, $zero, 0x40
    /* 50720 800B8F20 4D00C210 */  beq        $a2, $v0, .L800B9058
    /* 50724 800B8F24 4100C228 */   slti      $v0, $a2, 0x41
    /* 50728 800B8F28 0F004010 */  beqz       $v0, .L800B8F68
    /* 5072C 800B8F2C 10000224 */   addiu     $v0, $zero, 0x10
    /* 50730 800B8F30 2800C210 */  beq        $a2, $v0, .L800B8FD4
    /* 50734 800B8F34 1100C228 */   slti      $v0, $a2, 0x11
    /* 50738 800B8F38 05004010 */  beqz       $v0, .L800B8F50
    /* 5073C 800B8F3C 20000224 */   addiu     $v0, $zero, 0x20
    /* 50740 800B8F40 1B00C010 */  beqz       $a2, .L800B8FB0
    /* 50744 800B8F44 21880002 */   addu      $s1, $s0, $zero
    /* 50748 800B8F48 55E40208 */  j          .L800B9154
    /* 5074C 800B8F4C 00000000 */   nop
  .L800B8F50:
    /* 50750 800B8F50 2A00C210 */  beq        $a2, $v0, .L800B8FFC
    /* 50754 800B8F54 30000224 */   addiu     $v0, $zero, 0x30
    /* 50758 800B8F58 3300C210 */  beq        $a2, $v0, .L800B9028
    /* 5075C 800B8F5C 21880002 */   addu      $s1, $s0, $zero
    /* 50760 800B8F60 55E40208 */  j          .L800B9154
    /* 50764 800B8F64 00000000 */   nop
  .L800B8F68:
    /* 50768 800B8F68 70000224 */  addiu      $v0, $zero, 0x70
    /* 5076C 800B8F6C 5900C210 */  beq        $a2, $v0, .L800B90D4
    /* 50770 800B8F70 7100C228 */   slti      $v0, $a2, 0x71
    /* 50774 800B8F74 07004010 */  beqz       $v0, .L800B8F94
    /* 50778 800B8F78 50000224 */   addiu     $v0, $zero, 0x50
    /* 5077C 800B8F7C 4200C210 */  beq        $a2, $v0, .L800B9088
    /* 50780 800B8F80 60000224 */   addiu     $v0, $zero, 0x60
    /* 50784 800B8F84 4A00C210 */  beq        $a2, $v0, .L800B90B0
    /* 50788 800B8F88 21880002 */   addu      $s1, $s0, $zero
    /* 5078C 800B8F8C 55E40208 */  j          .L800B9154
    /* 50790 800B8F90 00000000 */   nop
  .L800B8F94:
    /* 50794 800B8F94 80000224 */  addiu      $v0, $zero, 0x80
    /* 50798 800B8F98 5300C210 */  beq        $a2, $v0, .L800B90E8
    /* 5079C 800B8F9C 90000224 */   addiu     $v0, $zero, 0x90
    /* 507A0 800B8FA0 5F00C210 */  beq        $a2, $v0, .L800B9120
    /* 507A4 800B8FA4 00000000 */   nop
    /* 507A8 800B8FA8 55E40208 */  j          .L800B9154
    /* 507AC 800B8FAC 00000000 */   nop
  .L800B8FB0:
    /* 507B0 800B8FB0 FDFA020C */  jal        vs_battle_getStateFlag
    /* 507B4 800B8FB4 21202002 */   addu      $a0, $s1, $zero
    /* 507B8 800B8FB8 21204002 */  addu       $a0, $s2, $zero
    /* 507BC 800B8FBC FDFA020C */  jal        vs_battle_getStateFlag
    /* 507C0 800B8FC0 21804000 */   addu      $s0, $v0, $zero
    /* 507C4 800B8FC4 21202002 */  addu       $a0, $s1, $zero
    /* 507C8 800B8FC8 21800202 */  addu       $s0, $s0, $v0
    /* 507CC 800B8FCC 53E40208 */  j          .L800B914C
    /* 507D0 800B8FD0 FF000532 */   andi      $a1, $s0, 0xFF
  .L800B8FD4:
    /* 507D4 800B8FD4 21880002 */  addu       $s1, $s0, $zero
    /* 507D8 800B8FD8 FDFA020C */  jal        vs_battle_getStateFlag
    /* 507DC 800B8FDC 21202002 */   addu      $a0, $s1, $zero
    /* 507E0 800B8FE0 21204002 */  addu       $a0, $s2, $zero
    /* 507E4 800B8FE4 FDFA020C */  jal        vs_battle_getStateFlag
    /* 507E8 800B8FE8 21804000 */   addu      $s0, $v0, $zero
    /* 507EC 800B8FEC 21202002 */  addu       $a0, $s1, $zero
    /* 507F0 800B8FF0 23800202 */  subu       $s0, $s0, $v0
    /* 507F4 800B8FF4 53E40208 */  j          .L800B914C
    /* 507F8 800B8FF8 FF000532 */   andi      $a1, $s0, 0xFF
  .L800B8FFC:
    /* 507FC 800B8FFC 21880002 */  addu       $s1, $s0, $zero
    /* 50800 800B9000 FDFA020C */  jal        vs_battle_getStateFlag
    /* 50804 800B9004 21202002 */   addu      $a0, $s1, $zero
    /* 50808 800B9008 21204002 */  addu       $a0, $s2, $zero
    /* 5080C 800B900C FDFA020C */  jal        vs_battle_getStateFlag
    /* 50810 800B9010 21804000 */   addu      $s0, $v0, $zero
    /* 50814 800B9014 18000202 */  mult       $s0, $v0
    /* 50818 800B9018 21202002 */  addu       $a0, $s1, $zero
    /* 5081C 800B901C 12380000 */  mflo       $a3
    /* 50820 800B9020 53E40208 */  j          .L800B914C
    /* 50824 800B9024 FF00E530 */   andi      $a1, $a3, 0xFF
  .L800B9028:
    /* 50828 800B9028 FDFA020C */  jal        vs_battle_getStateFlag
    /* 5082C 800B902C 21202002 */   addu      $a0, $s1, $zero
    /* 50830 800B9030 21204002 */  addu       $a0, $s2, $zero
    /* 50834 800B9034 FDFA020C */  jal        vs_battle_getStateFlag
    /* 50838 800B9038 21804000 */   addu      $s0, $v0, $zero
    /* 5083C 800B903C FF001032 */  andi       $s0, $s0, 0xFF
    /* 50840 800B9040 FF004230 */  andi       $v0, $v0, 0xFF
    /* 50844 800B9044 1B000202 */  divu       $zero, $s0, $v0
    /* 50848 800B9048 12800000 */  mflo       $s0
    /* 5084C 800B904C 21202002 */  addu       $a0, $s1, $zero
    /* 50850 800B9050 53E40208 */  j          .L800B914C
    /* 50854 800B9054 21280002 */   addu      $a1, $s0, $zero
  .L800B9058:
    /* 50858 800B9058 21880002 */  addu       $s1, $s0, $zero
    /* 5085C 800B905C FDFA020C */  jal        vs_battle_getStateFlag
    /* 50860 800B9060 21202002 */   addu      $a0, $s1, $zero
    /* 50864 800B9064 21204002 */  addu       $a0, $s2, $zero
    /* 50868 800B9068 FDFA020C */  jal        vs_battle_getStateFlag
    /* 5086C 800B906C 21804000 */   addu      $s0, $v0, $zero
    /* 50870 800B9070 FF001032 */  andi       $s0, $s0, 0xFF
    /* 50874 800B9074 FF004230 */  andi       $v0, $v0, 0xFF
    /* 50878 800B9078 1B000202 */  divu       $zero, $s0, $v0
    /* 5087C 800B907C 10280000 */  mfhi       $a1
    /* 50880 800B9080 53E40208 */  j          .L800B914C
    /* 50884 800B9084 21202002 */   addu      $a0, $s1, $zero
  .L800B9088:
    /* 50888 800B9088 21880002 */  addu       $s1, $s0, $zero
    /* 5088C 800B908C FDFA020C */  jal        vs_battle_getStateFlag
    /* 50890 800B9090 21202002 */   addu      $a0, $s1, $zero
    /* 50894 800B9094 21204002 */  addu       $a0, $s2, $zero
    /* 50898 800B9098 FDFA020C */  jal        vs_battle_getStateFlag
    /* 5089C 800B909C 21804000 */   addu      $s0, $v0, $zero
    /* 508A0 800B90A0 21202002 */  addu       $a0, $s1, $zero
    /* 508A4 800B90A4 24800202 */  and        $s0, $s0, $v0
    /* 508A8 800B90A8 53E40208 */  j          .L800B914C
    /* 508AC 800B90AC FF000532 */   andi      $a1, $s0, 0xFF
  .L800B90B0:
    /* 508B0 800B90B0 FDFA020C */  jal        vs_battle_getStateFlag
    /* 508B4 800B90B4 21202002 */   addu      $a0, $s1, $zero
    /* 508B8 800B90B8 21204002 */  addu       $a0, $s2, $zero
    /* 508BC 800B90BC FDFA020C */  jal        vs_battle_getStateFlag
    /* 508C0 800B90C0 21804000 */   addu      $s0, $v0, $zero
    /* 508C4 800B90C4 21202002 */  addu       $a0, $s1, $zero
    /* 508C8 800B90C8 25800202 */  or         $s0, $s0, $v0
    /* 508CC 800B90CC 53E40208 */  j          .L800B914C
    /* 508D0 800B90D0 FF000532 */   andi      $a1, $s0, 0xFF
  .L800B90D4:
    /* 508D4 800B90D4 FDFA020C */  jal        vs_battle_getStateFlag
    /* 508D8 800B90D8 21204002 */   addu      $a0, $s2, $zero
    /* 508DC 800B90DC 21200002 */  addu       $a0, $s0, $zero
    /* 508E0 800B90E0 53E40208 */  j          .L800B914C
    /* 508E4 800B90E4 FF004530 */   andi      $a1, $v0, 0xFF
  .L800B90E8:
    /* 508E8 800B90E8 FDFA020C */  jal        vs_battle_getStateFlag
    /* 508EC 800B90EC 21200002 */   addu      $a0, $s0, $zero
    /* 508F0 800B90F0 21204002 */  addu       $a0, $s2, $zero
    /* 508F4 800B90F4 FDFA020C */  jal        vs_battle_getStateFlag
    /* 508F8 800B90F8 21884000 */   addu      $s1, $v0, $zero
    /* 508FC 800B90FC 21200002 */  addu       $a0, $s0, $zero
    /* 50900 800B9100 FF003132 */  andi       $s1, $s1, 0xFF
    /* 50904 800B9104 FF004230 */  andi       $v0, $v0, 0xFF
    /* 50908 800B9108 23882202 */  subu       $s1, $s1, $v0
    /* 5090C 800B910C 02002106 */  bgez       $s1, .L800B9118
    /* 50910 800B9110 00000000 */   nop
    /* 50914 800B9114 23881100 */  negu       $s1, $s1
  .L800B9118:
    /* 50918 800B9118 53E40208 */  j          .L800B914C
    /* 5091C 800B911C FF002532 */   andi      $a1, $s1, 0xFF
  .L800B9120:
    /* 50920 800B9120 FDFA020C */  jal        vs_battle_getStateFlag
    /* 50924 800B9124 21200002 */   addu      $a0, $s0, $zero
    /* 50928 800B9128 21884002 */  addu       $s1, $s2, $zero
    /* 5092C 800B912C 21202002 */  addu       $a0, $s1, $zero
    /* 50930 800B9130 FDFA020C */  jal        vs_battle_getStateFlag
    /* 50934 800B9134 21904000 */   addu      $s2, $v0, $zero
    /* 50938 800B9138 21200002 */  addu       $a0, $s0, $zero
    /* 5093C 800B913C 05FB020C */  jal        vs_battle_setStateFlag
    /* 50940 800B9140 FF004530 */   andi      $a1, $v0, 0xFF
    /* 50944 800B9144 21202002 */  addu       $a0, $s1, $zero
    /* 50948 800B9148 FF004532 */  andi       $a1, $s2, 0xFF
  .L800B914C:
    /* 5094C 800B914C 05FB020C */  jal        vs_battle_setStateFlag
    /* 50950 800B9150 00000000 */   nop
  .L800B9154:
    /* 50954 800B9154 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 50958 800B9158 1800B28F */  lw         $s2, 0x18($sp)
    /* 5095C 800B915C 1400B18F */  lw         $s1, 0x14($sp)
    /* 50960 800B9160 1000B08F */  lw         $s0, 0x10($sp)
    /* 50964 800B9164 21100000 */  addu       $v0, $zero, $zero
    /* 50968 800B9168 0800E003 */  jr         $ra
    /* 5096C 800B916C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_script_setFlag
