nonmatching func_800CFAAC, 0xBC

glabel func_800CFAAC
    /* 672AC 800CFAAC 21308000 */  addu       $a2, $a0, $zero
    /* 672B0 800CFAB0 0C00C38C */  lw         $v1, 0xC($a2)
    /* 672B4 800CFAB4 1000C28C */  lw         $v0, 0x10($a2)
    /* 672B8 800CFAB8 00000000 */  nop
    /* 672BC 800CFABC 28006210 */  beq        $v1, $v0, .L800CFB60
    /* 672C0 800CFAC0 FFFF0824 */   addiu     $t0, $zero, -0x1
    /* 672C4 800CFAC4 21380001 */  addu       $a3, $t0, $zero
    /* 672C8 800CFAC8 1000C584 */  lh         $a1, 0x10($a2)
    /* 672CC 800CFACC 0C00C384 */  lh         $v1, 0xC($a2)
    /* 672D0 800CFAD0 1200C484 */  lh         $a0, 0x12($a2)
    /* 672D4 800CFAD4 0E00C284 */  lh         $v0, 0xE($a2)
    /* 672D8 800CFAD8 1000C994 */  lhu        $t1, 0x10($a2)
    /* 672DC 800CFADC 2328A300 */  subu       $a1, $a1, $v1
    /* 672E0 800CFAE0 1200C394 */  lhu        $v1, 0x12($a2)
    /* 672E4 800CFAE4 0300A104 */  bgez       $a1, .L800CFAF4
    /* 672E8 800CFAE8 23208200 */   subu      $a0, $a0, $v0
    /* 672EC 800CFAEC 23280500 */  negu       $a1, $a1
    /* 672F0 800CFAF0 01000824 */  addiu      $t0, $zero, 0x1
  .L800CFAF4:
    /* 672F4 800CFAF4 04008104 */  bgez       $a0, .L800CFB08
    /* 672F8 800CFAF8 2A108500 */   slt       $v0, $a0, $a1
    /* 672FC 800CFAFC 23200400 */  negu       $a0, $a0
    /* 67300 800CFB00 01000724 */  addiu      $a3, $zero, 0x1
    /* 67304 800CFB04 2A108500 */  slt        $v0, $a0, $a1
  .L800CFB08:
    /* 67308 800CFB08 0B004010 */  beqz       $v0, .L800CFB38
    /* 6730C 800CFB0C 21102801 */   addu      $v0, $t1, $t0
    /* 67310 800CFB10 1000C2A4 */  sh         $v0, 0x10($a2)
    /* 67314 800CFB14 40100400 */  sll        $v0, $a0, 1
    /* 67318 800CFB18 2A10A200 */  slt        $v0, $a1, $v0
    /* 6731C 800CFB1C 10004010 */  beqz       $v0, .L800CFB60
    /* 67320 800CFB20 00000000 */   nop
    /* 67324 800CFB24 1200C294 */  lhu        $v0, 0x12($a2)
    /* 67328 800CFB28 00000000 */  nop
    /* 6732C 800CFB2C 21104700 */  addu       $v0, $v0, $a3
    /* 67330 800CFB30 0800E003 */  jr         $ra
    /* 67334 800CFB34 1200C2A4 */   sh        $v0, 0x12($a2)
  .L800CFB38:
    /* 67338 800CFB38 21106700 */  addu       $v0, $v1, $a3
    /* 6733C 800CFB3C 1200C2A4 */  sh         $v0, 0x12($a2)
    /* 67340 800CFB40 40100500 */  sll        $v0, $a1, 1
    /* 67344 800CFB44 2A108200 */  slt        $v0, $a0, $v0
    /* 67348 800CFB48 05004010 */  beqz       $v0, .L800CFB60
    /* 6734C 800CFB4C 00000000 */   nop
    /* 67350 800CFB50 1000C294 */  lhu        $v0, 0x10($a2)
    /* 67354 800CFB54 00000000 */  nop
    /* 67358 800CFB58 21104800 */  addu       $v0, $v0, $t0
    /* 6735C 800CFB5C 1000C2A4 */  sh         $v0, 0x10($a2)
  .L800CFB60:
    /* 67360 800CFB60 0800E003 */  jr         $ra
    /* 67364 800CFB64 00000000 */   nop
endlabel func_800CFAAC
