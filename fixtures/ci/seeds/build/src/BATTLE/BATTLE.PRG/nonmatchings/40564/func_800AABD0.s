nonmatching func_800AABD0, 0xB0

glabel func_800AABD0
    /* 423D0 800AABD0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 423D4 800AABD4 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 423D8 800AABD8 80200400 */  sll        $a0, $a0, 2
    /* 423DC 800AABDC 21208200 */  addu       $a0, $a0, $v0
    /* 423E0 800AABE0 0000878C */  lw         $a3, 0x0($a0)
    /* 423E4 800AABE4 00000000 */  nop
    /* 423E8 800AABE8 2300E010 */  beqz       $a3, .L800AAC78
    /* 423EC 800AABEC 00000000 */   nop
    /* 423F0 800AABF0 0B00C014 */  bnez       $a2, .L800AAC20
    /* 423F4 800AABF4 00000000 */   nop
    /* 423F8 800AABF8 C805E0A4 */  sh         $zero, 0x5C8($a3)
    /* 423FC 800AABFC 0000A294 */  lhu        $v0, 0x0($a1)
    /* 42400 800AAC00 00000000 */  nop
    /* 42404 800AAC04 2C00E2A4 */  sh         $v0, 0x2C($a3)
    /* 42408 800AAC08 0200A294 */  lhu        $v0, 0x2($a1)
    /* 4240C 800AAC0C 00000000 */  nop
    /* 42410 800AAC10 2E00E2A4 */  sh         $v0, 0x2E($a3)
    /* 42414 800AAC14 0400A294 */  lhu        $v0, 0x4($a1)
    /* 42418 800AAC18 1EAB0208 */  j          .L800AAC78
    /* 4241C 800AAC1C 3000E2A4 */   sh        $v0, 0x30($a3)
  .L800AAC20:
    /* 42420 800AAC20 0000A294 */  lhu        $v0, 0x0($a1)
    /* 42424 800AAC24 2C00E394 */  lhu        $v1, 0x2C($a3)
    /* 42428 800AAC28 00000000 */  nop
    /* 4242C 800AAC2C 23104300 */  subu       $v0, $v0, $v1
    /* 42430 800AAC30 4400E2A4 */  sh         $v0, 0x44($a3)
    /* 42434 800AAC34 0200A294 */  lhu        $v0, 0x2($a1)
    /* 42438 800AAC38 2E00E394 */  lhu        $v1, 0x2E($a3)
    /* 4243C 800AAC3C 00000000 */  nop
    /* 42440 800AAC40 23104300 */  subu       $v0, $v0, $v1
    /* 42444 800AAC44 4600E2A4 */  sh         $v0, 0x46($a3)
    /* 42448 800AAC48 0400A394 */  lhu        $v1, 0x4($a1)
    /* 4244C 800AAC4C 3000E294 */  lhu        $v0, 0x30($a3)
    /* 42450 800AAC50 4400E48C */  lw         $a0, 0x44($a3)
    /* 42454 800AAC54 23106200 */  subu       $v0, $v1, $v0
    /* 42458 800AAC58 06008014 */  bnez       $a0, .L800AAC74
    /* 4245C 800AAC5C 4800E2A4 */   sh        $v0, 0x48($a3)
    /* 42460 800AAC60 00140200 */  sll        $v0, $v0, 16
    /* 42464 800AAC64 03004014 */  bnez       $v0, .L800AAC74
    /* 42468 800AAC68 00000000 */   nop
    /* 4246C 800AAC6C 1EAB0208 */  j          .L800AAC78
    /* 42470 800AAC70 C805E0A4 */   sh        $zero, 0x5C8($a3)
  .L800AAC74:
    /* 42474 800AAC74 C805E6A4 */  sh         $a2, 0x5C8($a3)
  .L800AAC78:
    /* 42478 800AAC78 0800E003 */  jr         $ra
    /* 4247C 800AAC7C 00000000 */   nop
endlabel func_800AABD0
