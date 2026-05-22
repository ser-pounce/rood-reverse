nonmatching func_8007FF8C, 0x74

glabel func_8007FF8C
    /* 1778C 8007FF8C 64000824 */  addiu      $t0, $zero, 0x64
    /* 17790 8007FF90 21380000 */  addu       $a3, $zero, $zero
    /* 17794 8007FF94 2120E000 */  addu       $a0, $a3, $zero
    /* 17798 8007FF98 09000924 */  addiu      $t1, $zero, 0x9
  .L8007FF9C:
    /* 1779C 8007FF9C CA00C290 */  lbu        $v0, 0xCA($a2)
    /* 177A0 8007FFA0 00000000 */  nop
    /* 177A4 8007FFA4 02004914 */  bne        $v0, $t1, .L8007FFB0
    /* 177A8 8007FFA8 00000000 */   nop
    /* 177AC 8007FFAC 01000724 */  addiu      $a3, $zero, 0x1
  .L8007FFB0:
    /* 177B0 8007FFB0 01008424 */  addiu      $a0, $a0, 0x1
    /* 177B4 8007FFB4 03008228 */  slti       $v0, $a0, 0x3
    /* 177B8 8007FFB8 F8FF4014 */  bnez       $v0, .L8007FF9C
    /* 177BC 8007FFBC 3000C624 */   addiu     $a2, $a2, 0x30
    /* 177C0 8007FFC0 0200E010 */  beqz       $a3, .L8007FFCC
    /* 177C4 8007FFC4 001C0500 */   sll       $v1, $a1, 16
    /* 177C8 8007FFC8 05000825 */  addiu      $t0, $t0, 0x5
  .L8007FFCC:
    /* 177CC 8007FFCC 031C0300 */  sra        $v1, $v1, 16
    /* 177D0 8007FFD0 18006800 */  mult       $v1, $t0
    /* 177D4 8007FFD4 12180000 */  mflo       $v1
    /* 177D8 8007FFD8 EB51023C */  lui        $v0, (0x51EB851F >> 16)
    /* 177DC 8007FFDC 1F854234 */  ori        $v0, $v0, (0x51EB851F & 0xFFFF)
    /* 177E0 8007FFE0 18006200 */  mult       $v1, $v0
    /* 177E4 8007FFE4 C31F0300 */  sra        $v1, $v1, 31
    /* 177E8 8007FFE8 10200000 */  mfhi       $a0
    /* 177EC 8007FFEC 43110400 */  sra        $v0, $a0, 5
    /* 177F0 8007FFF0 23104300 */  subu       $v0, $v0, $v1
    /* 177F4 8007FFF4 00140200 */  sll        $v0, $v0, 16
    /* 177F8 8007FFF8 0800E003 */  jr         $ra
    /* 177FC 8007FFFC 03140200 */   sra       $v0, $v0, 16
endlabel func_8007FF8C
