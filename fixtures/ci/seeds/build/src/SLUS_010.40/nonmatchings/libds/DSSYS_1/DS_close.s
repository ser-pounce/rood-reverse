nonmatching DS_close, 0xC8

glabel DS_close
    /* 14F44 80024744 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14F48 80024748 000040AC */  sw         $zero, 0x0($v0)
    /* 14F4C 8002474C 040040A0 */  sb         $zero, 0x4($v0)
  .L80024750:
    /* 14F50 80024750 000080A0 */  sb         $zero, 0x0($a0)
    /* 14F54 80024754 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 14F58 80024758 FDFF6104 */  bgez       $v1, .L80024750
    /* 14F5C 8002475C FFFF8424 */   addiu     $a0, $a0, -0x1
    /* 14F60 80024760 0380023C */  lui        $v0, %hi(D_80032688)
    /* 14F64 80024764 88264224 */  addiu      $v0, $v0, %lo(D_80032688)
    /* 14F68 80024768 000040AC */  sw         $zero, 0x0($v0)
    /* 14F6C 8002476C 07000324 */  addiu      $v1, $zero, 0x7
    /* 14F70 80024770 0B004224 */  addiu      $v0, $v0, 0xB
  .L80024774:
    /* 14F74 80024774 000040A0 */  sb         $zero, 0x0($v0)
    /* 14F78 80024778 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 14F7C 8002477C FDFF6104 */  bgez       $v1, .L80024774
    /* 14F80 80024780 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 14F84 80024784 0380103C */  lui        $s0, %hi(D_80032694)
    /* 14F88 80024788 94261026 */  addiu      $s0, $s0, %lo(D_80032694)
    /* 14F8C 8002478C 02000224 */  addiu      $v0, $zero, 0x2
    /* 14F90 80024790 080002AE */  sw         $v0, 0x8($s0)
    /* 14F94 80024794 0E000224 */  addiu      $v0, $zero, 0xE
    /* 14F98 80024798 0C0002AE */  sw         $v0, 0xC($s0)
    /* 14F9C 8002479C 15000224 */  addiu      $v0, $zero, 0x15
    /* 14FA0 800247A0 21200000 */  addu       $a0, $zero, $zero
    /* 14FA4 800247A4 16000526 */  addiu      $a1, $s0, 0x16
    /* 14FA8 800247A8 000000A2 */  sb         $zero, 0x0($s0)
    /* 14FAC 800247AC 040000AE */  sw         $zero, 0x4($s0)
    /* 14FB0 800247B0 100002AE */  sw         $v0, 0x10($s0)
    /* 14FB4 800247B4 140000A2 */  sb         $zero, 0x14($s0)
    /* 14FB8 800247B8 5996000C */  jal        DsIntToPos
    /* 14FBC 800247BC 150000A2 */   sb        $zero, 0x15($s0)
    /* 14FC0 800247C0 01000224 */  addiu      $v0, $zero, 0x1
    /* 14FC4 800247C4 1A0000A2 */  sb         $zero, 0x1A($s0)
    /* 14FC8 800247C8 1B0000A2 */  sb         $zero, 0x1B($s0)
    /* 14FCC 800247CC 1C0000A2 */  sb         $zero, 0x1C($s0)
    /* 14FD0 800247D0 1D0000A2 */  sb         $zero, 0x1D($s0)
    /* 14FD4 800247D4 1E0000A2 */  sb         $zero, 0x1E($s0)
    /* 14FD8 800247D8 1F0000A2 */  sb         $zero, 0x1F($s0)
    /* 14FDC 800247DC 200000AE */  sw         $zero, 0x20($s0)
    /* 14FE0 800247E0 240002AE */  sw         $v0, 0x24($s0)
    /* 14FE4 800247E4 280000AE */  sw         $zero, 0x28($s0)
    /* 14FE8 800247E8 300000AE */  sw         $zero, 0x30($s0)
    /* 14FEC 800247EC 2C0000AE */  sw         $zero, 0x2C($s0)
    /* 14FF0 800247F0 340000AE */  sw         $zero, 0x34($s0)
    /* 14FF4 800247F4 380000A2 */  sb         $zero, 0x38($s0)
    /* 14FF8 800247F8 390000A2 */  sb         $zero, 0x39($s0)
    /* 14FFC 800247FC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 15000 80024800 1000B08F */  lw         $s0, 0x10($sp)
    /* 15004 80024804 0800E003 */  jr         $ra
    /* 15008 80024808 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DS_close
