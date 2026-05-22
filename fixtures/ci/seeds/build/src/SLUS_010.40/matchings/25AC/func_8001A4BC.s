nonmatching func_8001A4BC, 0x190

glabel func_8001A4BC
    /* ACBC 8001A4BC 21488000 */  addu       $t1, $a0, $zero
    /* ACC0 8001A4C0 0A002285 */  lh         $v0, 0xA($t1)
    /* ACC4 8001A4C4 00000000 */  nop
    /* ACC8 8001A4C8 2320A200 */  subu       $a0, $a1, $v0
    /* ACCC 8001A4CC 06008104 */  bgez       $a0, .L8001A4E8
    /* ACD0 8001A4D0 AA2A023C */   lui       $v0, (0x2AAAAAAB >> 16)
    /* ACD4 8001A4D4 0C008424 */  addiu      $a0, $a0, 0xC
  .L8001A4D8:
    /* ACD8 8001A4D8 FFFF8004 */  bltz       $a0, .L8001A4D8
    /* ACDC 8001A4DC 0C008424 */   addiu     $a0, $a0, 0xC
    /* ACE0 8001A4E0 F4FF8424 */  addiu      $a0, $a0, -0xC
    /* ACE4 8001A4E4 AA2A023C */  lui        $v0, (0x2AAAAAAB >> 16)
  .L8001A4E8:
    /* ACE8 8001A4E8 ABAA4234 */  ori        $v0, $v0, (0x2AAAAAAB & 0xFFFF)
    /* ACEC 8001A4EC 18008200 */  mult       $a0, $v0
    /* ACF0 8001A4F0 C3170400 */  sra        $v0, $a0, 31
    /* ACF4 8001A4F4 08002885 */  lh         $t0, 0x8($t1)
    /* ACF8 8001A4F8 10500000 */  mfhi       $t2
    /* ACFC 8001A4FC 43180A00 */  sra        $v1, $t2, 1
    /* AD00 8001A500 23186200 */  subu       $v1, $v1, $v0
    /* AD04 8001A504 40100300 */  sll        $v0, $v1, 1
    /* AD08 8001A508 21104300 */  addu       $v0, $v0, $v1
    /* AD0C 8001A50C 80100200 */  sll        $v0, $v0, 2
    /* AD10 8001A510 08000015 */  bnez       $t0, .L8001A534
    /* AD14 8001A514 23208200 */   subu      $a0, $a0, $v0
    /* AD18 8001A518 0380023C */  lui        $v0, %hi(D_8002F63C)
    /* AD1C 8001A51C 3CF64224 */  addiu      $v0, $v0, %lo(D_8002F63C)
    /* AD20 8001A520 80180400 */  sll        $v1, $a0, 2
    /* AD24 8001A524 21186200 */  addu       $v1, $v1, $v0
    /* AD28 8001A528 0000628C */  lw         $v0, 0x0($v1)
    /* AD2C 8001A52C 64690008 */  j          .L8001A590
    /* AD30 8001A530 00420200 */   sll       $t0, $v0, 8
  .L8001A534:
    /* AD34 8001A534 0C000105 */  bgez       $t0, .L8001A568
    /* AD38 8001A538 0380033C */   lui       $v1, %hi(D_8002F63C)
    /* AD3C 8001A53C 0380023C */  lui        $v0, %hi(D_8002F63C)
    /* AD40 8001A540 3CF64224 */  addiu      $v0, $v0, %lo(D_8002F63C)
    /* AD44 8001A544 80180400 */  sll        $v1, $a0, 2
    /* AD48 8001A548 21186200 */  addu       $v1, $v1, $v0
    /* AD4C 8001A54C 08002495 */  lhu        $a0, 0x8($t1)
    /* AD50 8001A550 0000628C */  lw         $v0, 0x0($v1)
    /* AD54 8001A554 00000000 */  nop
    /* AD58 8001A558 18004400 */  mult       $v0, $a0
    /* AD5C 8001A55C 12500000 */  mflo       $t2
    /* AD60 8001A560 64690008 */  j          .L8001A590
    /* AD64 8001A564 02420A00 */   srl       $t0, $t2, 8
  .L8001A568:
    /* AD68 8001A568 3CF66324 */  addiu      $v1, $v1, %lo(D_8002F63C)
    /* AD6C 8001A56C 80100400 */  sll        $v0, $a0, 2
    /* AD70 8001A570 21104300 */  addu       $v0, $v0, $v1
    /* AD74 8001A574 0000428C */  lw         $v0, 0x0($v0)
    /* AD78 8001A578 00000000 */  nop
    /* AD7C 8001A57C 18004800 */  mult       $v0, $t0
    /* AD80 8001A580 00120200 */  sll        $v0, $v0, 8
    /* AD84 8001A584 12500000 */  mflo       $t2
    /* AD88 8001A588 C2410A00 */  srl        $t0, $t2, 7
    /* AD8C 8001A58C 21400201 */  addu       $t0, $t0, $v0
  .L8001A590:
    /* AD90 8001A590 FF00C630 */  andi       $a2, $a2, 0xFF
    /* AD94 8001A594 0A00C010 */  beqz       $a2, .L8001A5C0
    /* AD98 8001A598 8000C22C */   sltiu     $v0, $a2, 0x80
    /* AD9C 8001A59C 04004010 */  beqz       $v0, .L8001A5B0
    /* ADA0 8001A5A0 18000601 */   mult      $t0, $a2
    /* ADA4 8001A5A4 12500000 */  mflo       $t2
    /* ADA8 8001A5A8 6F690008 */  j          .L8001A5BC
    /* ADAC 8001A5AC C2110A00 */   srl       $v0, $t2, 7
  .L8001A5B0:
    /* ADB0 8001A5B0 12500000 */  mflo       $t2
    /* ADB4 8001A5B4 02120A00 */  srl        $v0, $t2, 8
    /* ADB8 8001A5B8 23104800 */  subu       $v0, $v0, $t0
  .L8001A5BC:
    /* ADBC 8001A5BC 0000E2AC */  sw         $v0, 0x0($a3)
  .L8001A5C0:
    /* ADC0 8001A5C0 0A002485 */  lh         $a0, 0xA($t1)
    /* ADC4 8001A5C4 00000000 */  nop
    /* ADC8 8001A5C8 2A10A400 */  slt        $v0, $a1, $a0
    /* ADCC 8001A5CC 0C004010 */  beqz       $v0, .L8001A600
    /* ADD0 8001A5D0 AA2A033C */   lui       $v1, (0x2AAAAAAB >> 16)
  .L8001A5D4:
    /* ADD4 8001A5D4 0000E28C */  lw         $v0, 0x0($a3)
    /* ADD8 8001A5D8 00000000 */  nop
    /* ADDC 8001A5DC 43100200 */  sra        $v0, $v0, 1
    /* ADE0 8001A5E0 0000E2AC */  sw         $v0, 0x0($a3)
    /* ADE4 8001A5E4 0A002285 */  lh         $v0, 0xA($t1)
    /* ADE8 8001A5E8 0C00A524 */  addiu      $a1, $a1, 0xC
    /* ADEC 8001A5EC 2A10A200 */  slt        $v0, $a1, $v0
    /* ADF0 8001A5F0 F8FF4014 */  bnez       $v0, .L8001A5D4
    /* ADF4 8001A5F4 43400800 */   sra       $t0, $t0, 1
    /* ADF8 8001A5F8 8D690008 */  j          .L8001A634
    /* ADFC 8001A5FC 00000000 */   nop
  .L8001A600:
    /* AE00 8001A600 ABAA6334 */  ori        $v1, $v1, (0x2AAAAAAB & 0xFFFF)
    /* AE04 8001A604 2310A400 */  subu       $v0, $a1, $a0
    /* AE08 8001A608 18004300 */  mult       $v0, $v1
    /* AE0C 8001A60C C3170200 */  sra        $v0, $v0, 31
    /* AE10 8001A610 10500000 */  mfhi       $t2
    /* AE14 8001A614 43180A00 */  sra        $v1, $t2, 1
    /* AE18 8001A618 23206200 */  subu       $a0, $v1, $v0
    /* AE1C 8001A61C 05008010 */  beqz       $a0, .L8001A634
    /* AE20 8001A620 00000000 */   nop
    /* AE24 8001A624 0000E28C */  lw         $v0, 0x0($a3)
    /* AE28 8001A628 04408800 */  sllv       $t0, $t0, $a0
    /* AE2C 8001A62C 04108200 */  sllv       $v0, $v0, $a0
    /* AE30 8001A630 0000E2AC */  sw         $v0, 0x0($a3)
  .L8001A634:
    /* AE34 8001A634 0000E28C */  lw         $v0, 0x0($a3)
    /* AE38 8001A638 03420800 */  sra        $t0, $t0, 8
    /* AE3C 8001A63C 03120200 */  sra        $v0, $v0, 8
    /* AE40 8001A640 0000E2AC */  sw         $v0, 0x0($a3)
    /* AE44 8001A644 0800E003 */  jr         $ra
    /* AE48 8001A648 FFFF0231 */   andi      $v0, $t0, 0xFFFF
endlabel func_8001A4BC
