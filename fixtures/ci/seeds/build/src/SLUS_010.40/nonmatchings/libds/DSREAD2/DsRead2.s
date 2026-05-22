nonmatching DsRead2, 0xD4

glabel DsRead2
    /* 16964 80026164 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 16968 80026168 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1696C 8002616C 21908000 */  addu       $s2, $a0, $zero
    /* 16970 80026170 1800B0AF */  sw         $s0, 0x18($sp)
    /* 16974 80026174 2180A000 */  addu       $s0, $a1, $zero
    /* 16978 80026178 00010232 */  andi       $v0, $s0, 0x100
    /* 1697C 8002617C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 16980 80026180 20004010 */  beqz       $v0, .L80026204
    /* 16984 80026184 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 16988 80026188 20000232 */  andi       $v0, $s0, 0x20
    /* 1698C 8002618C 04004010 */  beqz       $v0, .L800261A0
    /* 16990 80026190 01000224 */   addiu     $v0, $zero, 0x1
    /* 16994 80026194 0480013C */  lui        $at, %hi(D_80039C80)
    /* 16998 80026198 6A980008 */  j          .L800261A8
    /* 1699C 8002619C 809C20AC */   sw        $zero, %lo(D_80039C80)($at)
  .L800261A0:
    /* 169A0 800261A0 0480013C */  lui        $at, %hi(D_80039C80)
    /* 169A4 800261A4 809C22AC */  sw         $v0, %lo(D_80039C80)($at)
  .L800261A8:
    /* 169A8 800261A8 0280043C */  lui        $a0, %hi(data_ready_callback)
    /* 169AC 800261AC 109A000C */  jal        DsDataCallback
    /* 169B0 800261B0 14228424 */   addiu     $a0, $a0, %lo(data_ready_callback)
    /* 169B4 800261B4 0280043C */  lui        $a0, %hi(func_80026238)
    /* 169B8 800261B8 38628424 */  addiu      $a0, $a0, %lo(func_80026238)
    /* 169BC 800261BC 069A000C */  jal        DsReadyCallback
    /* 169C0 800261C0 21884000 */   addu      $s1, $v0, $zero
    /* 169C4 800261C4 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 169C8 800261C8 1000A3AF */  sw         $v1, 0x10($sp)
    /* 169CC 800261CC FF000432 */  andi       $a0, $s0, 0xFF
    /* 169D0 800261D0 21284002 */  addu       $a1, $s2, $zero
    /* 169D4 800261D4 1B000624 */  addiu      $a2, $zero, 0x1B
    /* 169D8 800261D8 21380000 */  addu       $a3, $zero, $zero
    /* 169DC 800261DC 5E8F000C */  jal        DsPacket
    /* 169E0 800261E0 21804000 */   addu      $s0, $v0, $zero
    /* 169E4 800261E4 0E004014 */  bnez       $v0, .L80026220
    /* 169E8 800261E8 00000000 */   nop
    /* 169EC 800261EC 109A000C */  jal        DsDataCallback
    /* 169F0 800261F0 21202002 */   addu      $a0, $s1, $zero
    /* 169F4 800261F4 069A000C */  jal        DsReadyCallback
    /* 169F8 800261F8 21200002 */   addu      $a0, $s0, $zero
    /* 169FC 800261FC 88980008 */  j          .L80026220
    /* 16A00 80026200 21100000 */   addu      $v0, $zero, $zero
  .L80026204:
    /* 16A04 80026204 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 16A08 80026208 1000A2AF */  sw         $v0, 0x10($sp)
    /* 16A0C 8002620C FF000432 */  andi       $a0, $s0, 0xFF
    /* 16A10 80026210 21284002 */  addu       $a1, $s2, $zero
    /* 16A14 80026214 1B000624 */  addiu      $a2, $zero, 0x1B
    /* 16A18 80026218 5E8F000C */  jal        DsPacket
    /* 16A1C 8002621C 21380000 */   addu      $a3, $zero, $zero
  .L80026220:
    /* 16A20 80026220 2400BF8F */  lw         $ra, 0x24($sp)
    /* 16A24 80026224 2000B28F */  lw         $s2, 0x20($sp)
    /* 16A28 80026228 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 16A2C 8002622C 1800B08F */  lw         $s0, 0x18($sp)
    /* 16A30 80026230 0800E003 */  jr         $ra
    /* 16A34 80026234 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel DsRead2
