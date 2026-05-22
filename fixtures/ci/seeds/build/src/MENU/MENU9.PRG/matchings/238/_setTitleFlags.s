nonmatching _setTitleFlags, 0x3F4

glabel _setTitleFlags
    /* 4EA4 801076A4 1180023C */  lui        $v0, %hi(_clearCount)
    /* 4EA8 801076A8 66A44294 */  lhu        $v0, %lo(_clearCount)($v0)
    /* 4EAC 801076AC 00000000 */  nop
    /* 4EB0 801076B0 05004010 */  beqz       $v0, .L801076C8
    /* 4EB4 801076B4 0680033C */   lui       $v1, %hi(vs_main_scoredata)
    /* 4EB8 801076B8 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 4EBC 801076BC 00000000 */  nop
    /* 4EC0 801076C0 01004234 */  ori        $v0, $v0, 0x1
    /* 4EC4 801076C4 A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L801076C8:
    /* 4EC8 801076C8 0680043C */  lui        $a0, %hi(vs_main_scoredata)
    /* 4ECC 801076CC A0FE8824 */  addiu      $t0, $a0, %lo(vs_main_scoredata)
    /* 4ED0 801076D0 9800028D */  lw         $v0, 0x98($t0)
    /* 4ED4 801076D4 00000000 */  nop
    /* 4ED8 801076D8 3400422C */  sltiu      $v0, $v0, 0x34
    /* 4EDC 801076DC 05004014 */  bnez       $v0, .L801076F4
    /* 4EE0 801076E0 00000000 */   nop
    /* 4EE4 801076E4 A0FE828C */  lw         $v0, %lo(vs_main_scoredata)($a0)
    /* 4EE8 801076E8 00000000 */  nop
    /* 4EEC 801076EC 04004234 */  ori        $v0, $v0, 0x4
    /* 4EF0 801076F0 A0FE82AC */  sw         $v0, %lo(vs_main_scoredata)($a0)
  .L801076F4:
    /* 4EF4 801076F4 9400028D */  lw         $v0, 0x94($t0)
    /* 4EF8 801076F8 00000000 */  nop
    /* 4EFC 801076FC 6901422C */  sltiu      $v0, $v0, 0x169
    /* 4F00 80107700 06004014 */  bnez       $v0, .L8010771C
    /* 4F04 80107704 0680023C */   lui       $v0, %hi(vs_main_stateFlags)
    /* 4F08 80107708 A0FE828C */  lw         $v0, %lo(vs_main_scoredata)($a0)
    /* 4F0C 8010770C 00000000 */  nop
    /* 4F10 80107710 08004234 */  ori        $v0, $v0, 0x8
    /* 4F14 80107714 A0FE82AC */  sw         $v0, %lo(vs_main_scoredata)($a0)
    /* 4F18 80107718 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
  .L8010771C:
    /* 4F1C 8010771C 98154324 */  addiu      $v1, $v0, %lo(vs_main_stateFlags)
    /* 4F20 80107720 CC006290 */  lbu        $v0, 0xCC($v1)
    /* 4F24 80107724 00000000 */  nop
    /* 4F28 80107728 05004010 */  beqz       $v0, .L80107740
    /* 4F2C 8010772C 00000000 */   nop
    /* 4F30 80107730 A0FE828C */  lw         $v0, %lo(vs_main_scoredata)($a0)
    /* 4F34 80107734 00000000 */  nop
    /* 4F38 80107738 10004234 */  ori        $v0, $v0, 0x10
    /* 4F3C 8010773C A0FE82AC */  sw         $v0, %lo(vs_main_scoredata)($a0)
  .L80107740:
    /* 4F40 80107740 CD006290 */  lbu        $v0, 0xCD($v1)
    /* 4F44 80107744 00000000 */  nop
    /* 4F48 80107748 05004010 */  beqz       $v0, .L80107760
    /* 4F4C 8010774C 00000000 */   nop
    /* 4F50 80107750 A0FE828C */  lw         $v0, %lo(vs_main_scoredata)($a0)
    /* 4F54 80107754 00000000 */  nop
    /* 4F58 80107758 20004234 */  ori        $v0, $v0, 0x20
    /* 4F5C 8010775C A0FE82AC */  sw         $v0, %lo(vs_main_scoredata)($a0)
  .L80107760:
    /* 4F60 80107760 CE006290 */  lbu        $v0, 0xCE($v1)
    /* 4F64 80107764 00000000 */  nop
    /* 4F68 80107768 05004010 */  beqz       $v0, .L80107780
    /* 4F6C 8010776C 00000000 */   nop
    /* 4F70 80107770 A0FE828C */  lw         $v0, %lo(vs_main_scoredata)($a0)
    /* 4F74 80107774 00000000 */  nop
    /* 4F78 80107778 40004234 */  ori        $v0, $v0, 0x40
    /* 4F7C 8010777C A0FE82AC */  sw         $v0, %lo(vs_main_scoredata)($a0)
  .L80107780:
    /* 4F80 80107780 CF006290 */  lbu        $v0, 0xCF($v1)
    /* 4F84 80107784 00000000 */  nop
    /* 4F88 80107788 05004010 */  beqz       $v0, .L801077A0
    /* 4F8C 8010778C 00000000 */   nop
    /* 4F90 80107790 A0FE828C */  lw         $v0, %lo(vs_main_scoredata)($a0)
    /* 4F94 80107794 00000000 */  nop
    /* 4F98 80107798 80004234 */  ori        $v0, $v0, 0x80
    /* 4F9C 8010779C A0FE82AC */  sw         $v0, %lo(vs_main_scoredata)($a0)
  .L801077A0:
    /* 4FA0 801077A0 D0006290 */  lbu        $v0, 0xD0($v1)
    /* 4FA4 801077A4 00000000 */  nop
    /* 4FA8 801077A8 05004010 */  beqz       $v0, .L801077C0
    /* 4FAC 801077AC 00000000 */   nop
    /* 4FB0 801077B0 A0FE828C */  lw         $v0, %lo(vs_main_scoredata)($a0)
    /* 4FB4 801077B4 00000000 */  nop
    /* 4FB8 801077B8 00014234 */  ori        $v0, $v0, 0x100
    /* 4FBC 801077BC A0FE82AC */  sw         $v0, %lo(vs_main_scoredata)($a0)
  .L801077C0:
    /* 4FC0 801077C0 D1006290 */  lbu        $v0, 0xD1($v1)
    /* 4FC4 801077C4 00000000 */  nop
    /* 4FC8 801077C8 05004010 */  beqz       $v0, .L801077E0
    /* 4FCC 801077CC 21180000 */   addu      $v1, $zero, $zero
    /* 4FD0 801077D0 A0FE828C */  lw         $v0, %lo(vs_main_scoredata)($a0)
    /* 4FD4 801077D4 00000000 */  nop
    /* 4FD8 801077D8 00024234 */  ori        $v0, $v0, 0x200
    /* 4FDC 801077DC A0FE82AC */  sw         $v0, %lo(vs_main_scoredata)($a0)
  .L801077E0:
    /* 4FE0 801077E0 21288000 */  addu       $a1, $a0, $zero
    /* 4FE4 801077E4 FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* 4FE8 801077E8 FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* 4FEC 801077EC 8000073C */  lui        $a3, (0x800000 >> 16)
    /* 4FF0 801077F0 21200001 */  addu       $a0, $t0, $zero
  .L801077F4:
    /* 4FF4 801077F4 2800828C */  lw         $v0, 0x28($a0)
    /* 4FF8 801077F8 00000000 */  nop
    /* 4FFC 801077FC 24104600 */  and        $v0, $v0, $a2
    /* 5000 80107800 06004710 */  beq        $v0, $a3, .L8010781C
    /* 5004 80107804 08000224 */   addiu     $v0, $zero, 0x8
    /* 5008 80107808 01006324 */  addiu      $v1, $v1, 0x1
    /* 500C 8010780C 08006228 */  slti       $v0, $v1, 0x8
    /* 5010 80107810 F8FF4014 */  bnez       $v0, .L801077F4
    /* 5014 80107814 0C008424 */   addiu     $a0, $a0, 0xC
    /* 5018 80107818 08000224 */  addiu      $v0, $zero, 0x8
  .L8010781C:
    /* 501C 8010781C 05006214 */  bne        $v1, $v0, .L80107834
    /* 5020 80107820 00000000 */   nop
    /* 5024 80107824 A0FEA28C */  lw         $v0, %lo(vs_main_scoredata)($a1)
    /* 5028 80107828 00000000 */  nop
    /* 502C 8010782C 00044234 */  ori        $v0, $v0, 0x400
    /* 5030 80107830 A0FEA2AC */  sw         $v0, %lo(vs_main_scoredata)($a1)
  .L80107834:
    /* 5034 80107834 88000295 */  lhu        $v0, 0x88($t0)
    /* 5038 80107838 00000000 */  nop
    /* 503C 8010783C 1E00422C */  sltiu      $v0, $v0, 0x1E
    /* 5040 80107840 06004014 */  bnez       $v0, .L8010785C
    /* 5044 80107844 0680023C */   lui       $v0, %hi(vs_main_stateFlags)
    /* 5048 80107848 A0FEA28C */  lw         $v0, %lo(vs_main_scoredata)($a1)
    /* 504C 8010784C 00000000 */  nop
    /* 5050 80107850 00084234 */  ori        $v0, $v0, 0x800
    /* 5054 80107854 A0FEA2AC */  sw         $v0, %lo(vs_main_scoredata)($a1)
    /* 5058 80107858 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
  .L8010785C:
    /* 505C 8010785C 98154324 */  addiu      $v1, $v0, %lo(vs_main_stateFlags)
    /* 5060 80107860 83036290 */  lbu        $v0, 0x383($v1)
    /* 5064 80107864 00000000 */  nop
    /* 5068 80107868 05004010 */  beqz       $v0, .L80107880
    /* 506C 8010786C 00000000 */   nop
    /* 5070 80107870 A0FEA28C */  lw         $v0, %lo(vs_main_scoredata)($a1)
    /* 5074 80107874 00000000 */  nop
    /* 5078 80107878 00104234 */  ori        $v0, $v0, 0x1000
    /* 507C 8010787C A0FEA2AC */  sw         $v0, %lo(vs_main_scoredata)($a1)
  .L80107880:
    /* 5080 80107880 87036290 */  lbu        $v0, 0x387($v1)
    /* 5084 80107884 00000000 */  nop
    /* 5088 80107888 05004010 */  beqz       $v0, .L801078A0
    /* 508C 8010788C B8000324 */   addiu     $v1, $zero, 0xB8
    /* 5090 80107890 A0FEA28C */  lw         $v0, %lo(vs_main_scoredata)($a1)
    /* 5094 80107894 00000000 */  nop
    /* 5098 80107898 00204234 */  ori        $v0, $v0, 0x2000
    /* 509C 8010789C A0FEA2AC */  sw         $v0, %lo(vs_main_scoredata)($a1)
  .L801078A0:
    /* 50A0 801078A0 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 50A4 801078A4 DCB94224 */  addiu      $v0, $v0, %lo(vs_main_skills)
    /* 50A8 801078A8 60254424 */  addiu      $a0, $v0, 0x2560
  .L801078AC:
    /* 50AC 801078AC 0C00828C */  lw         $v0, 0xC($a0)
    /* 50B0 801078B0 00000000 */  nop
    /* 50B4 801078B4 C2130200 */  srl        $v0, $v0, 15
    /* 50B8 801078B8 01004230 */  andi       $v0, $v0, 0x1
    /* 50BC 801078BC 06004010 */  beqz       $v0, .L801078D8
    /* 50C0 801078C0 E0000224 */   addiu     $v0, $zero, 0xE0
    /* 50C4 801078C4 01006324 */  addiu      $v1, $v1, 0x1
    /* 50C8 801078C8 E0006228 */  slti       $v0, $v1, 0xE0
    /* 50CC 801078CC F7FF4014 */  bnez       $v0, .L801078AC
    /* 50D0 801078D0 34008424 */   addiu     $a0, $a0, 0x34
    /* 50D4 801078D4 E0000224 */  addiu      $v0, $zero, 0xE0
  .L801078D8:
    /* 50D8 801078D8 07006214 */  bne        $v1, $v0, .L801078F8
    /* 50DC 801078DC 16000324 */   addiu     $v1, $zero, 0x16
    /* 50E0 801078E0 0680033C */  lui        $v1, %hi(vs_main_scoredata)
    /* 50E4 801078E4 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 50E8 801078E8 00000000 */  nop
    /* 50EC 801078EC 00404234 */  ori        $v0, $v0, 0x4000
    /* 50F0 801078F0 A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
    /* 50F4 801078F4 16000324 */  addiu      $v1, $zero, 0x16
  .L801078F8:
    /* 50F8 801078F8 21000824 */  addiu      $t0, $zero, 0x21
    /* 50FC 801078FC 24000724 */  addiu      $a3, $zero, 0x24
    /* 5100 80107900 26000624 */  addiu      $a2, $zero, 0x26
    /* 5104 80107904 27000524 */  addiu      $a1, $zero, 0x27
    /* 5108 80107908 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 510C 8010790C DCB94224 */  addiu      $v0, $v0, %lo(vs_main_skills)
    /* 5110 80107910 78044424 */  addiu      $a0, $v0, 0x478
  .L80107914:
    /* 5114 80107914 0D006810 */  beq        $v1, $t0, .L8010794C
    /* 5118 80107918 00000000 */   nop
    /* 511C 8010791C 0B006710 */  beq        $v1, $a3, .L8010794C
    /* 5120 80107920 00000000 */   nop
    /* 5124 80107924 09006610 */  beq        $v1, $a2, .L8010794C
    /* 5128 80107928 00000000 */   nop
    /* 512C 8010792C 07006510 */  beq        $v1, $a1, .L8010794C
    /* 5130 80107930 00000000 */   nop
    /* 5134 80107934 0C00828C */  lw         $v0, 0xC($a0)
    /* 5138 80107938 00000000 */  nop
    /* 513C 8010793C C2130200 */  srl        $v0, $v0, 15
    /* 5140 80107940 01004230 */  andi       $v0, $v0, 0x1
    /* 5144 80107944 06004010 */  beqz       $v0, .L80107960
    /* 5148 80107948 36000224 */   addiu     $v0, $zero, 0x36
  .L8010794C:
    /* 514C 8010794C 01006324 */  addiu      $v1, $v1, 0x1
    /* 5150 80107950 36006228 */  slti       $v0, $v1, 0x36
    /* 5154 80107954 EFFF4014 */  bnez       $v0, .L80107914
    /* 5158 80107958 34008424 */   addiu     $a0, $a0, 0x34
    /* 515C 8010795C 36000224 */  addiu      $v0, $zero, 0x36
  .L80107960:
    /* 5160 80107960 07006214 */  bne        $v1, $v0, .L80107980
    /* 5164 80107964 21180000 */   addu      $v1, $zero, $zero
    /* 5168 80107968 0680033C */  lui        $v1, %hi(vs_main_scoredata)
    /* 516C 8010796C A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 5170 80107970 00000000 */  nop
    /* 5174 80107974 00804234 */  ori        $v0, $v0, 0x8000
    /* 5178 80107978 A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
    /* 517C 8010797C 21180000 */  addu       $v1, $zero, $zero
  .L80107980:
    /* 5180 80107980 0680053C */  lui        $a1, %hi(vs_main_scoredata)
    /* 5184 80107984 A0FEA424 */  addiu      $a0, $a1, %lo(vs_main_scoredata)
  .L80107988:
    /* 5188 80107988 04008294 */  lhu        $v0, 0x4($a0)
    /* 518C 8010798C 00000000 */  nop
    /* 5190 80107990 8813422C */  sltiu      $v0, $v0, 0x1388
    /* 5194 80107994 06004014 */  bnez       $v0, .L801079B0
    /* 5198 80107998 06000224 */   addiu     $v0, $zero, 0x6
    /* 519C 8010799C 01006324 */  addiu      $v1, $v1, 0x1
    /* 51A0 801079A0 06006228 */  slti       $v0, $v1, 0x6
    /* 51A4 801079A4 F8FF4014 */  bnez       $v0, .L80107988
    /* 51A8 801079A8 02008424 */   addiu     $a0, $a0, 0x2
    /* 51AC 801079AC 06000224 */  addiu      $v0, $zero, 0x6
  .L801079B0:
    /* 51B0 801079B0 06006214 */  bne        $v1, $v0, .L801079CC
    /* 51B4 801079B4 21180000 */   addu      $v1, $zero, $zero
    /* 51B8 801079B8 A0FEA28C */  lw         $v0, %lo(vs_main_scoredata)($a1)
    /* 51BC 801079BC 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 51C0 801079C0 25104300 */  or         $v0, $v0, $v1
    /* 51C4 801079C4 A0FEA2AC */  sw         $v0, %lo(vs_main_scoredata)($a1)
    /* 51C8 801079C8 21180000 */  addu       $v1, $zero, $zero
  .L801079CC:
    /* 51CC 801079CC 0680053C */  lui        $a1, %hi(vs_main_scoredata)
    /* 51D0 801079D0 A0FEA424 */  addiu      $a0, $a1, %lo(vs_main_scoredata)
  .L801079D4:
    /* 51D4 801079D4 14008294 */  lhu        $v0, 0x14($a0)
    /* 51D8 801079D8 00000000 */  nop
    /* 51DC 801079DC 8813422C */  sltiu      $v0, $v0, 0x1388
    /* 51E0 801079E0 06004014 */  bnez       $v0, .L801079FC
    /* 51E4 801079E4 0A000224 */   addiu     $v0, $zero, 0xA
    /* 51E8 801079E8 01006324 */  addiu      $v1, $v1, 0x1
    /* 51EC 801079EC 0A006228 */  slti       $v0, $v1, 0xA
    /* 51F0 801079F0 F8FF4014 */  bnez       $v0, .L801079D4
    /* 51F4 801079F4 02008424 */   addiu     $a0, $a0, 0x2
    /* 51F8 801079F8 0A000224 */  addiu      $v0, $zero, 0xA
  .L801079FC:
    /* 51FC 801079FC 06006214 */  bne        $v1, $v0, .L80107A18
    /* 5200 80107A00 21180000 */   addu      $v1, $zero, $zero
    /* 5204 80107A04 A0FEA28C */  lw         $v0, %lo(vs_main_scoredata)($a1)
    /* 5208 80107A08 2000033C */  lui        $v1, (0x200000 >> 16)
    /* 520C 80107A0C 25104300 */  or         $v0, $v0, $v1
    /* 5210 80107A10 A0FEA2AC */  sw         $v0, %lo(vs_main_scoredata)($a1)
    /* 5214 80107A14 21180000 */  addu       $v1, $zero, $zero
  .L80107A18:
    /* 5218 80107A18 0680053C */  lui        $a1, %hi(vs_main_scoredata)
    /* 521C 80107A1C A0FEA724 */  addiu      $a3, $a1, %lo(vs_main_scoredata)
    /* 5220 80107A20 01000624 */  addiu      $a2, $zero, 0x1
    /* 5224 80107A24 01006424 */  addiu      $a0, $v1, 0x1
  .L80107A28:
    /* 5228 80107A28 40100400 */  sll        $v0, $a0, 1
    /* 522C 80107A2C 21104700 */  addu       $v0, $v0, $a3
    /* 5230 80107A30 14004294 */  lhu        $v0, 0x14($v0)
    /* 5234 80107A34 00000000 */  nop
    /* 5238 80107A38 F401422C */  sltiu      $v0, $v0, 0x1F4
    /* 523C 80107A3C 05004014 */  bnez       $v0, .L80107A54
    /* 5240 80107A40 16006224 */   addiu     $v0, $v1, 0x16
    /* 5244 80107A44 A0FEA38C */  lw         $v1, %lo(vs_main_scoredata)($a1)
    /* 5248 80107A48 04104600 */  sllv       $v0, $a2, $v0
    /* 524C 80107A4C 25186200 */  or         $v1, $v1, $v0
    /* 5250 80107A50 A0FEA3AC */  sw         $v1, %lo(vs_main_scoredata)($a1)
  .L80107A54:
    /* 5254 80107A54 21188000 */  addu       $v1, $a0, $zero
    /* 5258 80107A58 09008228 */  slti       $v0, $a0, 0x9
    /* 525C 80107A5C F2FF4014 */  bnez       $v0, .L80107A28
    /* 5260 80107A60 01006424 */   addiu     $a0, $v1, 0x1
    /* 5264 80107A64 0680043C */  lui        $a0, %hi(vs_main_scoredata)
    /* 5268 80107A68 A0FE8224 */  addiu      $v0, $a0, %lo(vs_main_scoredata)
    /* 526C 80107A6C 14004294 */  lhu        $v0, 0x14($v0)
    /* 5270 80107A70 00000000 */  nop
    /* 5274 80107A74 F401422C */  sltiu      $v0, $v0, 0x1F4
    /* 5278 80107A78 05004014 */  bnez       $v0, .L80107A90
    /* 527C 80107A7C 0080033C */   lui       $v1, (0x80000000 >> 16)
    /* 5280 80107A80 A0FE828C */  lw         $v0, %lo(vs_main_scoredata)($a0)
    /* 5284 80107A84 00000000 */  nop
    /* 5288 80107A88 25104300 */  or         $v0, $v0, $v1
    /* 528C 80107A8C A0FE82AC */  sw         $v0, %lo(vs_main_scoredata)($a0)
  .L80107A90:
    /* 5290 80107A90 0800E003 */  jr         $ra
    /* 5294 80107A94 00000000 */   nop
endlabel _setTitleFlags
