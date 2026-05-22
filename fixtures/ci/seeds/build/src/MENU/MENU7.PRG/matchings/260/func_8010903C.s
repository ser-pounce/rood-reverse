nonmatching func_8010903C, 0x250

glabel func_8010903C
    /* 683C 8010903C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6840 80109040 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6844 80109044 21808000 */  addu       $s0, $a0, $zero
    /* 6848 80109048 2000BFAF */  sw         $ra, 0x20($sp)
    /* 684C 8010904C 1A000012 */  beqz       $s0, .L801090B8
    /* 6850 80109050 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 6854 80109054 1E000424 */  addiu      $a0, $zero, 0x1E
    /* 6858 80109058 40010524 */  addiu      $a1, $zero, 0x140
    /* 685C 8010905C 92000624 */  addiu      $a2, $zero, 0x92
    /* 6860 80109060 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 6864 80109064 1180023C */  lui        $v0, %hi(D_8010A9D0)
    /* 6868 80109068 D0A94224 */  addiu      $v0, $v0, %lo(D_8010A9D0)
    /* 686C 8010906C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6870 80109070 9723030C */  jal        vs_battle_setMenuItem
    /* 6874 80109074 1400A2AF */   sw        $v0, 0x14($sp)
    /* 6878 80109078 21204000 */  addu       $a0, $v0, $zero
    /* 687C 8010907C 21100000 */  addu       $v0, $zero, $zero
    /* 6880 80109080 02000324 */  addiu      $v1, $zero, 0x2
    /* 6884 80109084 000083A0 */  sb         $v1, 0x0($a0)
    /* 6888 80109088 C2000324 */  addiu      $v1, $zero, 0xC2
    /* 688C 8010908C 180083A4 */  sh         $v1, 0x18($a0)
    /* 6890 80109090 1180033C */  lui        $v1, %hi(D_8010ADAC)
    /* 6894 80109094 1180043C */  lui        $a0, %hi(D_8010ADA8)
    /* 6898 80109098 ACAD60A0 */  sb         $zero, %lo(D_8010ADAC)($v1)
    /* 689C 8010909C FFFF0326 */  addiu      $v1, $s0, -0x1
    /* 68A0 801090A0 01006330 */  andi       $v1, $v1, 0x1
    /* 68A4 801090A4 A8AD83AC */  sw         $v1, %lo(D_8010ADA8)($a0)
    /* 68A8 801090A8 1180043C */  lui        $a0, %hi(D_8010ADAD)
    /* 68AC 801090AC 83181000 */  sra        $v1, $s0, 2
    /* 68B0 801090B0 9E240408 */  j          .L80109278
    /* 68B4 801090B4 ADAD83A0 */   sb        $v1, %lo(D_8010ADAD)($a0)
  .L801090B8:
    /* 68B8 801090B8 1180103C */  lui        $s0, %hi(D_8010ADAC)
    /* 68BC 801090BC ACAD0392 */  lbu        $v1, %lo(D_8010ADAC)($s0)
    /* 68C0 801090C0 01001124 */  addiu      $s1, $zero, 0x1
    /* 68C4 801090C4 1D007110 */  beq        $v1, $s1, .L8010913C
    /* 68C8 801090C8 02006228 */   slti      $v0, $v1, 0x2
    /* 68CC 801090CC 05004010 */  beqz       $v0, .L801090E4
    /* 68D0 801090D0 02000224 */   addiu     $v0, $zero, 0x2
    /* 68D4 801090D4 09006010 */  beqz       $v1, .L801090FC
    /* 68D8 801090D8 21100000 */   addu      $v0, $zero, $zero
    /* 68DC 801090DC 9E240408 */  j          .L80109278
    /* 68E0 801090E0 00000000 */   nop
  .L801090E4:
    /* 68E4 801090E4 1C006210 */  beq        $v1, $v0, .L80109158
    /* 68E8 801090E8 03000224 */   addiu     $v0, $zero, 0x3
    /* 68EC 801090EC 5A006210 */  beq        $v1, $v0, .L80109258
    /* 68F0 801090F0 21100000 */   addu      $v0, $zero, $zero
    /* 68F4 801090F4 9E240408 */  j          .L80109278
    /* 68F8 801090F8 00000000 */   nop
  .L801090FC:
    /* 68FC 801090FC 1F000424 */  addiu      $a0, $zero, 0x1F
    /* 6900 80109100 40010524 */  addiu      $a1, $zero, 0x140
    /* 6904 80109104 A2000624 */  addiu      $a2, $zero, 0xA2
    /* 6908 80109108 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 690C 8010910C 1180023C */  lui        $v0, %hi(D_8010A9D4)
    /* 6910 80109110 D4A94224 */  addiu      $v0, $v0, %lo(D_8010A9D4)
    /* 6914 80109114 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6918 80109118 9723030C */  jal        vs_battle_setMenuItem
    /* 691C 8010911C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 6920 80109120 21204000 */  addu       $a0, $v0, $zero
    /* 6924 80109124 02000224 */  addiu      $v0, $zero, 0x2
    /* 6928 80109128 000082A0 */  sb         $v0, 0x0($a0)
    /* 692C 8010912C C2000224 */  addiu      $v0, $zero, 0xC2
    /* 6930 80109130 180082A4 */  sh         $v0, 0x18($a0)
    /* 6934 80109134 9D240408 */  j          .L80109274
    /* 6938 80109138 ACAD11A2 */   sb        $s1, %lo(D_8010ADAC)($s0)
  .L8010913C:
    /* 693C 8010913C 74EA030C */  jal        vs_mainmenu_ready
    /* 6940 80109140 00000000 */   nop
    /* 6944 80109144 ACAD0392 */  lbu        $v1, %lo(D_8010ADAC)($s0)
    /* 6948 80109148 00000000 */  nop
    /* 694C 8010914C 21186200 */  addu       $v1, $v1, $v0
    /* 6950 80109150 9D240408 */  j          .L80109274
    /* 6954 80109154 ACAD03A2 */   sb        $v1, %lo(D_8010ADAC)($s0)
  .L80109158:
    /* 6958 80109158 1180103C */  lui        $s0, %hi(D_8010ADA8)
    /* 695C 8010915C A8AD048E */  lw         $a0, %lo(D_8010ADA8)($s0)
    /* 6960 80109160 9223030C */  jal        vs_battle_getMenuItem
    /* 6964 80109164 1E008424 */   addiu     $a0, $a0, 0x1E
    /* 6968 80109168 060051A0 */  sb         $s1, 0x6($v0)
    /* 696C 8010916C A8AD028E */  lw         $v0, %lo(D_8010ADA8)($s0)
    /* 6970 80109170 1F000424 */  addiu      $a0, $zero, 0x1F
    /* 6974 80109174 9223030C */  jal        vs_battle_getMenuItem
    /* 6978 80109178 23208200 */   subu      $a0, $a0, $v0
    /* 697C 8010917C 0680033C */  lui        $v1, %hi(vs_main_buttonsPressed)
    /* 6980 80109180 060040A0 */  sb         $zero, 0x6($v0)
    /* 6984 80109184 1180023C */  lui        $v0, %hi(D_8010ADAD)
    /* 6988 80109188 ADAD4290 */  lbu        $v0, %lo(D_8010ADAD)($v0)
    /* 698C 8010918C D0E1708C */  lw         $s0, %lo(vs_main_buttonsPressed)($v1)
    /* 6990 80109190 07004014 */  bnez       $v0, .L801091B0
    /* 6994 80109194 70000232 */   andi      $v0, $s0, 0x70
    /* 6998 80109198 10000232 */  andi       $v0, $s0, 0x10
    /* 699C 8010919C 04004010 */  beqz       $v0, .L801091B0
    /* 69A0 801091A0 70000232 */   andi      $v0, $s0, 0x70
    /* 69A4 801091A4 B800030C */  jal        vs_battle_playInvalidSfx
    /* 69A8 801091A8 F0FF1026 */   addiu     $s0, $s0, -0x10
    /* 69AC 801091AC 70000232 */  andi       $v0, $s0, 0x70
  .L801091B0:
    /* 69B0 801091B0 17004010 */  beqz       $v0, .L80109210
    /* 69B4 801091B4 1180113C */   lui       $s1, %hi(D_8010ADA8)
    /* 69B8 801091B8 A8AD228E */  lw         $v0, %lo(D_8010ADA8)($s1)
    /* 69BC 801091BC 00000000 */  nop
    /* 69C0 801091C0 03004014 */  bnez       $v0, .L801091D0
    /* 69C4 801091C4 50000232 */   andi      $v0, $s0, 0x50
    /* 69C8 801091C8 07004010 */  beqz       $v0, .L801091E8
    /* 69CC 801091CC 00000000 */   nop
  .L801091D0:
    /* 69D0 801091D0 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 69D4 801091D4 00000000 */   nop
    /* 69D8 801091D8 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 69DC 801091DC 28000424 */   addiu     $a0, $zero, 0x28
    /* 69E0 801091E0 7F240408 */  j          .L801091FC
    /* 69E4 801091E4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L801091E8:
    /* 69E8 801091E8 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 69EC 801091EC 00000000 */   nop
    /* 69F0 801091F0 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 69F4 801091F4 21200000 */   addu      $a0, $zero, $zero
    /* 69F8 801091F8 01000224 */  addiu      $v0, $zero, 0x1
  .L801091FC:
    /* 69FC 801091FC A8AD22AE */  sw         $v0, %lo(D_8010ADA8)($s1)
    /* 6A00 80109200 1180033C */  lui        $v1, %hi(D_8010ADAC)
    /* 6A04 80109204 03000224 */  addiu      $v0, $zero, 0x3
    /* 6A08 80109208 9D240408 */  j          .L80109274
    /* 6A0C 8010920C ACAD62A0 */   sb        $v0, %lo(D_8010ADAC)($v1)
  .L80109210:
    /* 6A10 80109210 1180103C */  lui        $s0, %hi(D_8010AA2A)
    /* 6A14 80109214 A8AD258E */  lw         $a1, %lo(D_8010ADA8)($s1)
    /* 6A18 80109218 2AAA0492 */  lbu        $a0, %lo(D_8010AA2A)($s0)
    /* 6A1C 8010921C 5033030C */  jal        vs_battle_drawCursor
    /* 6A20 80109220 0800A524 */   addiu     $a1, $a1, 0x8
    /* 6A24 80109224 0680033C */  lui        $v1, %hi(vs_main_buttonRepeat)
    /* 6A28 80109228 DCDF638C */  lw         $v1, %lo(vs_main_buttonRepeat)($v1)
    /* 6A2C 8010922C 00000000 */  nop
    /* 6A30 80109230 00506330 */  andi       $v1, $v1, 0x5000
    /* 6A34 80109234 0F006010 */  beqz       $v1, .L80109274
    /* 6A38 80109238 2AAA02A2 */   sb        $v0, %lo(D_8010AA2A)($s0)
    /* 6A3C 8010923C BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 6A40 80109240 00000000 */   nop
    /* 6A44 80109244 A8AD238E */  lw         $v1, %lo(D_8010ADA8)($s1)
    /* 6A48 80109248 01000224 */  addiu      $v0, $zero, 0x1
    /* 6A4C 8010924C 23104300 */  subu       $v0, $v0, $v1
    /* 6A50 80109250 9D240408 */  j          .L80109274
    /* 6A54 80109254 A8AD22AE */   sw        $v0, %lo(D_8010ADA8)($s1)
  .L80109258:
    /* 6A58 80109258 74EA030C */  jal        vs_mainmenu_ready
    /* 6A5C 8010925C 00000000 */   nop
    /* 6A60 80109260 04004010 */  beqz       $v0, .L80109274
    /* 6A64 80109264 1180023C */   lui       $v0, %hi(D_8010ADA8)
    /* 6A68 80109268 A8AD428C */  lw         $v0, %lo(D_8010ADA8)($v0)
    /* 6A6C 8010926C 9E240408 */  j          .L80109278
    /* 6A70 80109270 00000000 */   nop
  .L80109274:
    /* 6A74 80109274 21100000 */  addu       $v0, $zero, $zero
  .L80109278:
    /* 6A78 80109278 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6A7C 8010927C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6A80 80109280 1800B08F */  lw         $s0, 0x18($sp)
    /* 6A84 80109284 0800E003 */  jr         $ra
    /* 6A88 80109288 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8010903C
