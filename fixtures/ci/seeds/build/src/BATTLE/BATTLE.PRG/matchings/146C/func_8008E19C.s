nonmatching func_8008E19C, 0x88

glabel func_8008E19C
    /* 2599C 8008E19C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 259A0 8008E1A0 0F80033C */  lui        $v1, %hi(D_800E8594)
    /* 259A4 8008E1A4 94856224 */  addiu      $v0, $v1, %lo(D_800E8594)
    /* 259A8 8008E1A8 0C004924 */  addiu      $t1, $v0, 0xC
    /* 259AC 8008E1AC 21500000 */  addu       $t2, $zero, $zero
    /* 259B0 8008E1B0 0E004824 */  addiu      $t0, $v0, 0xE
    /* 259B4 8008E1B4 80008424 */  addiu      $a0, $a0, 0x80
    /* 259B8 8008E1B8 8000A524 */  addiu      $a1, $a1, 0x80
    /* 259BC 8008E1BC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 259C0 8008E1C0 948564A4 */  sh         $a0, %lo(D_800E8594)($v1)
    /* 259C4 8008E1C4 040045A4 */  sh         $a1, 0x4($v0)
    /* 259C8 8008E1C8 020046A4 */  sh         $a2, 0x2($v0)
  .L8008E1CC:
    /* 259CC 8008E1CC 01004A25 */  addiu      $t2, $t2, 0x1
    /* 259D0 8008E1D0 000027A1 */  sb         $a3, 0x0($t1)
    /* 259D4 8008E1D4 FFFF07A1 */  sb         $a3, -0x1($t0)
    /* 259D8 8008E1D8 000007A1 */  sb         $a3, 0x0($t0)
    /* 259DC 8008E1DC 04000825 */  addiu      $t0, $t0, 0x4
    /* 259E0 8008E1E0 03004229 */  slti       $v0, $t2, 0x3
    /* 259E4 8008E1E4 F9FF4014 */  bnez       $v0, .L8008E1CC
    /* 259E8 8008E1E8 04002925 */   addiu     $t1, $t1, 0x4
    /* 259EC 8008E1EC 0C002925 */  addiu      $t1, $t1, 0xC
    /* 259F0 8008E1F0 0F80043C */  lui        $a0, %hi(D_800E85A0)
    /* 259F4 8008E1F4 A0858424 */  addiu      $a0, $a0, %lo(D_800E85A0)
    /* 259F8 8008E1F8 0F80023C */  lui        $v0, %hi(D_800F19C8)
    /* 259FC 8008E1FC 000027A1 */  sb         $a3, 0x0($t1)
    /* 25A00 8008E200 010027A1 */  sb         $a3, 0x1($t1)
    /* 25A04 8008E204 020027A1 */  sb         $a3, 0x2($t1)
    /* 25A08 8008E208 C819458C */  lw         $a1, %lo(D_800F19C8)($v0)
    /* 25A0C 8008E20C 8F5C020C */  jal        func_8009723C
    /* 25A10 8008E210 A8FF8424 */   addiu     $a0, $a0, -0x58
    /* 25A14 8008E214 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25A18 8008E218 00000000 */  nop
    /* 25A1C 8008E21C 0800E003 */  jr         $ra
    /* 25A20 8008E220 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008E19C
