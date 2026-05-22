nonmatching func_8006B760, 0x124

glabel func_8006B760
    /* 2F60 8006B760 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2F64 8006B764 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* 2F68 8006B768 A0FE4624 */  addiu      $a2, $v0, %lo(vs_main_scoredata)
    /* 2F6C 8006B76C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2F70 8006B770 9000C58C */  lw         $a1, 0x90($a2)
    /* 2F74 8006B774 00000000 */  nop
    /* 2F78 8006B778 0D00A014 */  bnez       $a1, .L8006B7B0
    /* 2F7C 8006B77C 0680033C */   lui       $v1, %hi(vs_main_gametime)
    /* 2F80 8006B780 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 2F84 8006B784 74106324 */  addiu      $v1, $v1, %lo(vs_main_gametime)
    /* 2F88 8006B788 98154290 */  lbu        $v0, %lo(vs_main_stateFlags)($v0)
    /* 2F8C 8006B78C 03006480 */  lb         $a0, 0x3($v1)
    /* 2F90 8006B790 8C00C2AC */  sw         $v0, 0x8C($a2)
    /* 2F94 8006B794 00110400 */  sll        $v0, $a0, 4
    /* 2F98 8006B798 23104400 */  subu       $v0, $v0, $a0
    /* 2F9C 8006B79C 02006380 */  lb         $v1, 0x2($v1)
    /* 2FA0 8006B7A0 80100200 */  sll        $v0, $v0, 2
    /* 2FA4 8006B7A4 21104300 */  addu       $v0, $v0, $v1
    /* 2FA8 8006B7A8 F9AD0108 */  j          .L8006B7E4
    /* 2FAC 8006B7AC 9000C2AC */   sw        $v0, 0x90($a2)
  .L8006B7B0:
    /* 2FB0 8006B7B0 74106324 */  addiu      $v1, $v1, %lo(vs_main_gametime)
    /* 2FB4 8006B7B4 03006480 */  lb         $a0, 0x3($v1)
    /* 2FB8 8006B7B8 02006380 */  lb         $v1, 0x2($v1)
    /* 2FBC 8006B7BC 00110400 */  sll        $v0, $a0, 4
    /* 2FC0 8006B7C0 23104400 */  subu       $v0, $v0, $a0
    /* 2FC4 8006B7C4 80100200 */  sll        $v0, $v0, 2
    /* 2FC8 8006B7C8 21184300 */  addu       $v1, $v0, $v1
    /* 2FCC 8006B7CC 2B106500 */  sltu       $v0, $v1, $a1
    /* 2FD0 8006B7D0 04004010 */  beqz       $v0, .L8006B7E4
    /* 2FD4 8006B7D4 0680023C */   lui       $v0, %hi(vs_main_stateFlags)
    /* 2FD8 8006B7D8 98154290 */  lbu        $v0, %lo(vs_main_stateFlags)($v0)
    /* 2FDC 8006B7DC 9000C3AC */  sw         $v1, 0x90($a2)
    /* 2FE0 8006B7E0 8C00C2AC */  sw         $v0, 0x8C($a2)
  .L8006B7E4:
    /* 2FE4 8006B7E4 7FAE010C */  jal        func_8006B9FC
    /* 2FE8 8006B7E8 00000000 */   nop
    /* 2FEC 8006B7EC 0680043C */  lui        $a0, %hi(vs_main_mapStatus)
    /* 2FF0 8006B7F0 D8FF8424 */  addiu      $a0, $a0, %lo(vs_main_mapStatus)
    /* 2FF4 8006B7F4 4424010C */  jal        vs_main_bzero
    /* 2FF8 8006B7F8 48000524 */   addiu     $a1, $zero, 0x48
    /* 2FFC 8006B7FC 10000324 */  addiu      $v1, $zero, 0x10
    /* 3000 8006B800 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 3004 8006B804 98154424 */  addiu      $a0, $v0, %lo(vs_main_stateFlags)
    /* 3008 8006B808 21106400 */  addu       $v0, $v1, $a0
  .L8006B80C:
    /* 300C 8006B80C 000040A0 */  sb         $zero, 0x0($v0)
    /* 3010 8006B810 01006324 */  addiu      $v1, $v1, 0x1
    /* 3014 8006B814 40046228 */  slti       $v0, $v1, 0x440
    /* 3018 8006B818 FCFF4014 */  bnez       $v0, .L8006B80C
    /* 301C 8006B81C 21106400 */   addu      $v0, $v1, $a0
    /* 3020 8006B820 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 3024 8006B824 98154324 */  addiu      $v1, $v0, %lo(vs_main_stateFlags)
    /* 3028 8006B828 01006290 */  lbu        $v0, 0x1($v1)
    /* 302C 8006B82C 00000000 */  nop
    /* 3030 8006B830 03004010 */  beqz       $v0, .L8006B840
    /* 3034 8006B834 01000224 */   addiu     $v0, $zero, 0x1
    /* 3038 8006B838 11AE0108 */  j          .L8006B844
    /* 303C 8006B83C 020062A0 */   sb        $v0, 0x2($v1)
  .L8006B840:
    /* 3040 8006B840 010062A0 */  sb         $v0, 0x1($v1)
  .L8006B844:
    /* 3044 8006B844 0680043C */  lui        $a0, %hi(vs_main_stateFlags)
    /* 3048 8006B848 98158390 */  lbu        $v1, %lo(vs_main_stateFlags)($a0)
    /* 304C 8006B84C 00000000 */  nop
    /* 3050 8006B850 6300622C */  sltiu      $v0, $v1, 0x63
    /* 3054 8006B854 02004010 */  beqz       $v0, .L8006B860
    /* 3058 8006B858 01006224 */   addiu     $v0, $v1, 0x1
    /* 305C 8006B85C 981582A0 */  sb         $v0, %lo(vs_main_stateFlags)($a0)
  .L8006B860:
    /* 3060 8006B860 0680023C */  lui        $v0, %hi(D_80061068)
    /* 3064 8006B864 01000324 */  addiu      $v1, $zero, 0x1
    /* 3068 8006B868 681043A0 */  sb         $v1, %lo(D_80061068)($v0)
    /* 306C 8006B86C 68104224 */  addiu      $v0, $v0, %lo(D_80061068)
    /* 3070 8006B870 010040A0 */  sb         $zero, 0x1($v0)
    /* 3074 8006B874 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3078 8006B878 00000000 */  nop
    /* 307C 8006B87C 0800E003 */  jr         $ra
    /* 3080 8006B880 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006B760
