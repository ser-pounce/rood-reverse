nonmatching func_800AA984, 0xE4

glabel func_800AA984
    /* 42184 800AA984 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 42188 800AA988 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4218C 800AA98C 80200400 */  sll        $a0, $a0, 2
    /* 42190 800AA990 21208200 */  addu       $a0, $a0, $v0
    /* 42194 800AA994 0000848C */  lw         $a0, 0x0($a0)
    /* 42198 800AA998 00000000 */  nop
    /* 4219C 800AA99C 30008010 */  beqz       $a0, .L800AAA60
    /* 421A0 800AA9A0 00140500 */   sll       $v0, $a1, 16
    /* 421A4 800AA9A4 031C0200 */  sra        $v1, $v0, 16
    /* 421A8 800AA9A8 3E0083A4 */  sh         $v1, 0x3E($a0)
    /* 421AC 800AA9AC 3C0080A4 */  sh         $zero, 0x3C($a0)
    /* 421B0 800AA9B0 1100C014 */  bnez       $a2, .L800AA9F8
    /* 421B4 800AA9B4 400080A4 */   sh        $zero, 0x40($a0)
    /* 421B8 800AA9B8 180080A4 */  sh         $zero, 0x18($a0)
  .L800AA9BC:
    /* 421BC 800AA9BC 26008294 */  lhu        $v0, 0x26($a0)
    /* 421C0 800AA9C0 3E008394 */  lhu        $v1, 0x3E($a0)
    /* 421C4 800AA9C4 00000000 */  nop
    /* 421C8 800AA9C8 21104300 */  addu       $v0, $v0, $v1
    /* 421CC 800AA9CC 001C0200 */  sll        $v1, $v0, 16
    /* 421D0 800AA9D0 031C0300 */  sra        $v1, $v1, 16
    /* 421D4 800AA9D4 21286000 */  addu       $a1, $v1, $zero
    /* 421D8 800AA9D8 02006104 */  bgez       $v1, .L800AA9E4
    /* 421DC 800AA9DC 260082A4 */   sh        $v0, 0x26($a0)
    /* 421E0 800AA9E0 FF0F6524 */  addiu      $a1, $v1, 0xFFF
  .L800AA9E4:
    /* 421E4 800AA9E4 03130500 */  sra        $v0, $a1, 12
    /* 421E8 800AA9E8 00130200 */  sll        $v0, $v0, 12
    /* 421EC 800AA9EC 23106200 */  subu       $v0, $v1, $v0
    /* 421F0 800AA9F0 98AA0208 */  j          .L800AAA60
    /* 421F4 800AA9F4 260082A4 */   sh        $v0, 0x26($a0)
  .L800AA9F8:
    /* 421F8 800AA9F8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 421FC 800AA9FC 1700C214 */  bne        $a2, $v0, .L800AAA5C
    /* 42200 800AAA00 00000000 */   nop
    /* 42204 800AAA04 02006104 */  bgez       $v1, .L800AAA10
    /* 42208 800AAA08 00000000 */   nop
    /* 4220C 800AAA0C 23180300 */  negu       $v1, $v1
  .L800AAA10:
    /* 42210 800AAA10 C0058294 */  lhu        $v0, 0x5C0($a0)
    /* 42214 800AAA14 00000000 */  nop
    /* 42218 800AAA18 18006200 */  mult       $v1, $v0
    /* 4221C 800AAA1C 12180000 */  mflo       $v1
    /* 42220 800AAA20 02006104 */  bgez       $v1, .L800AAA2C
    /* 42224 800AAA24 21106000 */   addu      $v0, $v1, $zero
    /* 42228 800AAA28 FF0F6224 */  addiu      $v0, $v1, 0xFFF
  .L800AAA2C:
    /* 4222C 800AAA2C 032B0200 */  sra        $a1, $v0, 12
    /* 42230 800AAA30 FF0F6230 */  andi       $v0, $v1, 0xFFF
    /* 42234 800AAA34 03004010 */  beqz       $v0, .L800AAA44
    /* 42238 800AAA38 180085A4 */   sh        $a1, 0x18($a0)
    /* 4223C 800AAA3C 0100A224 */  addiu      $v0, $a1, 0x1
    /* 42240 800AAA40 180082A4 */  sh         $v0, 0x18($a0)
  .L800AAA44:
    /* 42244 800AAA44 18008294 */  lhu        $v0, 0x18($a0)
    /* 42248 800AAA48 00000000 */  nop
    /* 4224C 800AAA4C DBFF4010 */  beqz       $v0, .L800AA9BC
    /* 42250 800AAA50 00000000 */   nop
    /* 42254 800AAA54 98AA0208 */  j          .L800AAA60
    /* 42258 800AAA58 00000000 */   nop
  .L800AAA5C:
    /* 4225C 800AAA5C 180086A4 */  sh         $a2, 0x18($a0)
  .L800AAA60:
    /* 42260 800AAA60 0800E003 */  jr         $ra
    /* 42264 800AAA64 00000000 */   nop
endlabel func_800AA984
