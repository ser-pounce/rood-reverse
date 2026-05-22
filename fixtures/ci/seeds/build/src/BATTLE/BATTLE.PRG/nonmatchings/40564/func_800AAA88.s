nonmatching func_800AAA88, 0x148

glabel func_800AAA88
    /* 42288 800AAA88 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4228C 800AAA8C 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 42290 800AAA90 80200400 */  sll        $a0, $a0, 2
    /* 42294 800AAA94 21208200 */  addu       $a0, $a0, $v0
    /* 42298 800AAA98 0000878C */  lw         $a3, 0x0($a0)
    /* 4229C 800AAA9C 0000A294 */  lhu        $v0, 0x0($a1)
    /* 422A0 800AAAA0 00000000 */  nop
    /* 422A4 800AAAA4 3C00E2A4 */  sh         $v0, 0x3C($a3)
    /* 422A8 800AAAA8 0200A294 */  lhu        $v0, 0x2($a1)
    /* 422AC 800AAAAC 00000000 */  nop
    /* 422B0 800AAAB0 3E00E2A4 */  sh         $v0, 0x3E($a3)
    /* 422B4 800AAAB4 0400A594 */  lhu        $a1, 0x4($a1)
    /* 422B8 800AAAB8 1800C014 */  bnez       $a2, .L800AAB1C
    /* 422BC 800AAABC 4000E5A4 */   sh        $a1, 0x40($a3)
    /* 422C0 800AAAC0 1800E0A4 */  sh         $zero, 0x18($a3)
  .L800AAAC4:
    /* 422C4 800AAAC4 2400E294 */  lhu        $v0, 0x24($a3)
    /* 422C8 800AAAC8 3C00E494 */  lhu        $a0, 0x3C($a3)
    /* 422CC 800AAACC 2600E394 */  lhu        $v1, 0x26($a3)
    /* 422D0 800AAAD0 3E00E594 */  lhu        $a1, 0x3E($a3)
    /* 422D4 800AAAD4 21104400 */  addu       $v0, $v0, $a0
    /* 422D8 800AAAD8 2400E2A4 */  sh         $v0, 0x24($a3)
    /* 422DC 800AAADC 2800E294 */  lhu        $v0, 0x28($a3)
    /* 422E0 800AAAE0 4000E494 */  lhu        $a0, 0x40($a3)
    /* 422E4 800AAAE4 21186500 */  addu       $v1, $v1, $a1
    /* 422E8 800AAAE8 2600E3A4 */  sh         $v1, 0x26($a3)
    /* 422EC 800AAAEC 2400E394 */  lhu        $v1, 0x24($a3)
    /* 422F0 800AAAF0 21104400 */  addu       $v0, $v0, $a0
    /* 422F4 800AAAF4 2800E2A4 */  sh         $v0, 0x28($a3)
    /* 422F8 800AAAF8 2600E294 */  lhu        $v0, 0x26($a3)
    /* 422FC 800AAAFC FF0F6330 */  andi       $v1, $v1, 0xFFF
    /* 42300 800AAB00 2400E3A4 */  sh         $v1, 0x24($a3)
    /* 42304 800AAB04 2800E394 */  lhu        $v1, 0x28($a3)
    /* 42308 800AAB08 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 4230C 800AAB0C FF0F6330 */  andi       $v1, $v1, 0xFFF
    /* 42310 800AAB10 2600E2A4 */  sh         $v0, 0x26($a3)
    /* 42314 800AAB14 F2AA0208 */  j          .L800AABC8
    /* 42318 800AAB18 2800E3A4 */   sh        $v1, 0x28($a3)
  .L800AAB1C:
    /* 4231C 800AAB1C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 42320 800AAB20 2800C214 */  bne        $a2, $v0, .L800AABC4
    /* 42324 800AAB24 00000000 */   nop
    /* 42328 800AAB28 3C00E284 */  lh         $v0, 0x3C($a3)
    /* 4232C 800AAB2C 3E00E384 */  lh         $v1, 0x3E($a3)
    /* 42330 800AAB30 02004104 */  bgez       $v0, .L800AAB3C
    /* 42334 800AAB34 21204000 */   addu      $a0, $v0, $zero
    /* 42338 800AAB38 23200400 */  negu       $a0, $a0
  .L800AAB3C:
    /* 4233C 800AAB3C 02006104 */  bgez       $v1, .L800AAB48
    /* 42340 800AAB40 00000000 */   nop
    /* 42344 800AAB44 23180300 */  negu       $v1, $v1
  .L800AAB48:
    /* 42348 800AAB48 2A108300 */  slt        $v0, $a0, $v1
    /* 4234C 800AAB4C 02004010 */  beqz       $v0, .L800AAB58
    /* 42350 800AAB50 00140500 */   sll       $v0, $a1, 16
    /* 42354 800AAB54 21206000 */  addu       $a0, $v1, $zero
  .L800AAB58:
    /* 42358 800AAB58 03140200 */  sra        $v0, $v0, 16
    /* 4235C 800AAB5C 02004104 */  bgez       $v0, .L800AAB68
    /* 42360 800AAB60 21184000 */   addu      $v1, $v0, $zero
    /* 42364 800AAB64 23180300 */  negu       $v1, $v1
  .L800AAB68:
    /* 42368 800AAB68 2A108300 */  slt        $v0, $a0, $v1
    /* 4236C 800AAB6C 02004010 */  beqz       $v0, .L800AAB78
    /* 42370 800AAB70 00000000 */   nop
    /* 42374 800AAB74 21206000 */  addu       $a0, $v1, $zero
  .L800AAB78:
    /* 42378 800AAB78 C005E294 */  lhu        $v0, 0x5C0($a3)
    /* 4237C 800AAB7C 00000000 */  nop
    /* 42380 800AAB80 18008200 */  mult       $a0, $v0
    /* 42384 800AAB84 12200000 */  mflo       $a0
    /* 42388 800AAB88 02008104 */  bgez       $a0, .L800AAB94
    /* 4238C 800AAB8C 21108000 */   addu      $v0, $a0, $zero
    /* 42390 800AAB90 FF0F8224 */  addiu      $v0, $a0, 0xFFF
  .L800AAB94:
    /* 42394 800AAB94 031B0200 */  sra        $v1, $v0, 12
    /* 42398 800AAB98 FF0F8230 */  andi       $v0, $a0, 0xFFF
    /* 4239C 800AAB9C 03004010 */  beqz       $v0, .L800AABAC
    /* 423A0 800AABA0 1800E3A4 */   sh        $v1, 0x18($a3)
    /* 423A4 800AABA4 01006224 */  addiu      $v0, $v1, 0x1
    /* 423A8 800AABA8 1800E2A4 */  sh         $v0, 0x18($a3)
  .L800AABAC:
    /* 423AC 800AABAC 1800E294 */  lhu        $v0, 0x18($a3)
    /* 423B0 800AABB0 00000000 */  nop
    /* 423B4 800AABB4 C3FF4010 */  beqz       $v0, .L800AAAC4
    /* 423B8 800AABB8 00000000 */   nop
    /* 423BC 800AABBC F2AA0208 */  j          .L800AABC8
    /* 423C0 800AABC0 00000000 */   nop
  .L800AABC4:
    /* 423C4 800AABC4 1800E6A4 */  sh         $a2, 0x18($a3)
  .L800AABC8:
    /* 423C8 800AABC8 0800E003 */  jr         $ra
    /* 423CC 800AABCC 00000000 */   nop
endlabel func_800AAA88
