nonmatching func_800FA188, 0xB0

glabel func_800FA188
    /* 988 800FA188 21500000 */  addu       $t2, $zero, $zero
    /* 98C 800FA18C 21584001 */  addu       $t3, $t2, $zero
    /* 990 800FA190 21484001 */  addu       $t1, $t2, $zero
    /* 994 800FA194 20000C24 */  addiu      $t4, $zero, 0x20
    /* 998 800FA198 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 99C 800FA19C E0454824 */  addiu      $t0, $v0, %lo(D_800F45E0)
  .L800FA1A0:
    /* 9A0 800FA1A0 0000038D */  lw         $v1, 0x0($t0)
    /* 9A4 800FA1A4 00000000 */  nop
    /* 9A8 800FA1A8 1C006010 */  beqz       $v1, .L800FA21C
    /* 9AC 800FA1AC 00000000 */   nop
    /* 9B0 800FA1B0 0800678C */  lw         $a3, 0x8($v1)
    /* 9B4 800FA1B4 00000000 */  nop
    /* 9B8 800FA1B8 0100E230 */  andi       $v0, $a3, 0x1
    /* 9BC 800FA1BC 17004014 */  bnez       $v0, .L800FA21C
    /* 9C0 800FA1C0 000FE230 */   andi      $v0, $a3, 0xF00
    /* 9C4 800FA1C4 15004014 */  bnez       $v0, .L800FA21C
    /* 9C8 800FA1C8 00000000 */   nop
    /* 9CC 800FA1CC 1A006284 */  lh         $v0, 0x1A($v1)
    /* 9D0 800FA1D0 00000000 */  nop
    /* 9D4 800FA1D4 11004014 */  bnez       $v0, .L800FA21C
    /* 9D8 800FA1D8 00000000 */   nop
    /* 9DC 800FA1DC 5C006290 */  lbu        $v0, 0x5C($v1)
    /* 9E0 800FA1E0 00000000 */  nop
    /* 9E4 800FA1E4 0D004414 */  bne        $v0, $a0, .L800FA21C
    /* 9E8 800FA1E8 00000000 */   nop
    /* 9EC 800FA1EC 5E006290 */  lbu        $v0, 0x5E($v1)
    /* 9F0 800FA1F0 00000000 */  nop
    /* 9F4 800FA1F4 09004514 */  bne        $v0, $a1, .L800FA21C
    /* 9F8 800FA1F8 00000000 */   nop
    /* 9FC 800FA1FC 6C01628C */  lw         $v0, 0x16C($v1)
    /* A00 800FA200 00000000 */  nop
    /* A04 800FA204 30004230 */  andi       $v0, $v0, 0x30
    /* A08 800FA208 03004C14 */  bne        $v0, $t4, .L800FA218
    /* A0C 800FA20C 00000000 */   nop
    /* A10 800FA210 87E80308 */  j          .L800FA21C
    /* A14 800FA214 01000B24 */   addiu     $t3, $zero, 0x1
  .L800FA218:
    /* A18 800FA218 80FF4A25 */  addiu      $t2, $t2, -0x80
  .L800FA21C:
    /* A1C 800FA21C 01002925 */  addiu      $t1, $t1, 0x1
    /* A20 800FA220 10002229 */  slti       $v0, $t1, 0x10
    /* A24 800FA224 DEFF4014 */  bnez       $v0, .L800FA1A0
    /* A28 800FA228 04000825 */   addiu     $t0, $t0, 0x4
    /* A2C 800FA22C 0000CAAC */  sw         $t2, 0x0($a2)
    /* A30 800FA230 0800E003 */  jr         $ra
    /* A34 800FA234 21106001 */   addu      $v0, $t3, $zero
endlabel func_800FA188
