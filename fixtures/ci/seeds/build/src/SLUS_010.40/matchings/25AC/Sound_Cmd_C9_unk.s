nonmatching Sound_Cmd_C9_unk, 0x68

glabel Sound_Cmd_C9_unk
    /* 7F98 80017798 0000828C */  lw         $v0, 0x0($a0)
    /* 7F9C 8001779C 00000000 */  nop
    /* 7FA0 800177A0 02004010 */  beqz       $v0, .L800177AC
    /* 7FA4 800177A4 01000524 */   addiu     $a1, $zero, 0x1
    /* 7FA8 800177A8 21284000 */  addu       $a1, $v0, $zero
  .L800177AC:
    /* 7FAC 800177AC 0380033C */  lui        $v1, %hi(g_CdVolume)
    /* 7FB0 800177B0 04008294 */  lhu        $v0, 0x4($a0)
    /* 7FB4 800177B4 E078638C */  lw         $v1, %lo(g_CdVolume)($v1)
    /* 7FB8 800177B8 00140200 */  sll        $v0, $v0, 16
    /* 7FBC 800177BC 23104300 */  subu       $v0, $v0, $v1
    /* 7FC0 800177C0 1A004500 */  div        $zero, $v0, $a1
    /* 7FC4 800177C4 0200A014 */  bnez       $a1, .L800177D0
    /* 7FC8 800177C8 00000000 */   nop
    /* 7FCC 800177CC 0D000700 */  break      7
  .L800177D0:
    /* 7FD0 800177D0 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7FD4 800177D4 0400A114 */  bne        $a1, $at, .L800177E8
    /* 7FD8 800177D8 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 7FDC 800177DC 02004114 */  bne        $v0, $at, .L800177E8
    /* 7FE0 800177E0 00000000 */   nop
    /* 7FE4 800177E4 0D000600 */  break      6
  .L800177E8:
    /* 7FE8 800177E8 12100000 */  mflo       $v0
    /* 7FEC 800177EC 0380033C */  lui        $v1, %hi(g_Sound_CdVolumeFadeLength)
    /* 7FF0 800177F0 4C7865A4 */  sh         $a1, %lo(g_Sound_CdVolumeFadeLength)($v1)
    /* 7FF4 800177F4 0380033C */  lui        $v1, %hi(g_Sound_CdVolumeFadeStep)
    /* 7FF8 800177F8 0800E003 */  jr         $ra
    /* 7FFC 800177FC 487862AC */   sw        $v0, %lo(g_Sound_CdVolumeFadeStep)($v1)
endlabel Sound_Cmd_C9_unk
