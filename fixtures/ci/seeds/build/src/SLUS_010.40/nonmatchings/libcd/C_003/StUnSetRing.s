nonmatching StUnSetRing, 0x80

glabel StUnSetRing
    /* 12994 80022194 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12998 80022198 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1299C 8002219C 5D9A000C */  jal        EnterCriticalSection
    /* 129A0 800221A0 00000000 */   nop
    /* 129A4 800221A4 0380033C */  lui        $v1, %hi(D_8003221C)
    /* 129A8 800221A8 1C22638C */  lw         $v1, %lo(D_8003221C)($v1)
    /* 129AC 800221AC 01000224 */  addiu      $v0, $zero, 0x1
    /* 129B0 800221B0 07006214 */  bne        $v1, $v0, .L800221D0
    /* 129B4 800221B4 00000000 */   nop
    /* 129B8 800221B8 109A000C */  jal        DsDataCallback
    /* 129BC 800221BC 21200000 */   addu      $a0, $zero, $zero
    /* 129C0 800221C0 069A000C */  jal        DsReadyCallback
    /* 129C4 800221C4 21200000 */   addu      $a0, $zero, $zero
    /* 129C8 800221C8 78880008 */  j          .L800221E0
    /* 129CC 800221CC 00000000 */   nop
  .L800221D0:
    /* 129D0 800221D0 5F82000C */  jal        CdDataCallback
    /* 129D4 800221D4 21200000 */   addu      $a0, $zero, $zero
    /* 129D8 800221D8 5381000C */  jal        CdReadyCallback
    /* 129DC 800221DC 21200000 */   addu      $a0, $zero, $zero
  .L800221E0:
    /* 129E0 800221E0 0380023C */  lui        $v0, %hi(D_80032524)
    /* 129E4 800221E4 2425428C */  lw         $v0, %lo(D_80032524)($v0)
    /* 129E8 800221E8 00000000 */  nop
    /* 129EC 800221EC 000040A0 */  sb         $zero, 0x0($v0)
    /* 129F0 800221F0 0380023C */  lui        $v0, %hi(D_80032530)
    /* 129F4 800221F4 3025428C */  lw         $v0, %lo(D_80032530)($v0)
    /* 129F8 800221F8 00000000 */  nop
    /* 129FC 800221FC 619A000C */  jal        ExitCriticalSection
    /* 12A00 80022200 000040A0 */   sb        $zero, 0x0($v0)
    /* 12A04 80022204 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12A08 80022208 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 12A0C 8002220C 0800E003 */  jr         $ra
    /* 12A10 80022210 00000000 */   nop
endlabel StUnSetRing
