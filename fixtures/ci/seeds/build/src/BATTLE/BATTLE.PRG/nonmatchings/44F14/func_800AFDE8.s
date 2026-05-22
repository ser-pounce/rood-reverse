nonmatching func_800AFDE8, 0x244

glabel func_800AFDE8
    /* 475E8 800AFDE8 21688000 */  addu       $t5, $a0, $zero
    /* 475EC 800AFDEC 801F0C3C */  lui        $t4, (0x1F8003EC >> 16)
    /* 475F0 800AFDF0 EC038C35 */  ori        $t4, $t4, (0x1F8003EC & 0xFFFF)
    /* 475F4 800AFDF4 A002AA24 */  addiu      $t2, $a1, 0x2A0
    /* 475F8 800AFDF8 0600A794 */  lhu        $a3, 0x6($a1)
    /* 475FC 800AFDFC 1000828D */  lw         $v0, 0x10($t4)
    /* 47600 800AFE00 06004995 */  lhu        $t1, 0x6($t2)
    /* 47604 800AFE04 08008B8D */  lw         $t3, 0x8($t4)
    /* 47608 800AFE08 0000438C */  lw         $v1, 0x0($v0)
    /* 4760C 800AFE0C 0C00828D */  lw         $v0, 0xC($t4)
    /* 47610 800AFE10 2118A301 */  addu       $v1, $t5, $v1
    /* 47614 800AFE14 2A104B00 */  slt        $v0, $v0, $t3
    /* 47618 800AFE18 7A004014 */  bnez       $v0, .L800B0004
    /* 4761C 800AFE1C 2138E300 */   addu      $a3, $a3, $v1
  .L800AFE20:
    /* 47620 800AFE20 2A102B01 */  slt        $v0, $t1, $t3
  .L800AFE24:
    /* 47624 800AFE24 1A004014 */  bnez       $v0, .L800AFE90
    /* 47628 800AFE28 00000000 */   nop
    /* 4762C 800AFE2C 0000A294 */  lhu        $v0, 0x0($a1)
    /* 47630 800AFE30 00004395 */  lhu        $v1, 0x0($t2)
    /* 47634 800AFE34 00000000 */  nop
    /* 47638 800AFE38 21104300 */  addu       $v0, $v0, $v1
    /* 4763C 800AFE3C 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 47640 800AFE40 0200A294 */  lhu        $v0, 0x2($a1)
    /* 47644 800AFE44 02004395 */  lhu        $v1, 0x2($t2)
    /* 47648 800AFE48 00000000 */  nop
    /* 4764C 800AFE4C 21104300 */  addu       $v0, $v0, $v1
    /* 47650 800AFE50 0200A2A4 */  sh         $v0, 0x2($a1)
    /* 47654 800AFE54 0400A294 */  lhu        $v0, 0x4($a1)
    /* 47658 800AFE58 04004395 */  lhu        $v1, 0x4($t2)
    /* 4765C 800AFE5C 00000000 */  nop
    /* 47660 800AFE60 21104300 */  addu       $v0, $v0, $v1
    /* 47664 800AFE64 6200C010 */  beqz       $a2, .L800AFFF0
    /* 47668 800AFE68 0400A2A4 */   sh        $v0, 0x4($a1)
    /* 4766C 800AFE6C FF1F023C */  lui        $v0, (0x1FFF1FFF >> 16)
    /* 47670 800AFE70 FF1F4234 */  ori        $v0, $v0, (0x1FFF1FFF & 0xFFFF)
    /* 47674 800AFE74 0000A38C */  lw         $v1, 0x0($a1)
    /* 47678 800AFE78 0400A494 */  lhu        $a0, 0x4($a1)
    /* 4767C 800AFE7C 24186200 */  and        $v1, $v1, $v0
    /* 47680 800AFE80 FF1F8430 */  andi       $a0, $a0, 0x1FFF
    /* 47684 800AFE84 0000A3AC */  sw         $v1, 0x0($a1)
    /* 47688 800AFE88 FCBF0208 */  j          .L800AFFF0
    /* 4768C 800AFE8C 0400A4A4 */   sh        $a0, 0x4($a1)
  .L800AFE90:
    /* 47690 800AFE90 0000E490 */  lbu        $a0, 0x0($a3)
    /* 47694 800AFE94 00000000 */  nop
    /* 47698 800AFE98 62008010 */  beqz       $a0, .L800B0024
    /* 4769C 800AFE9C E0008230 */   andi      $v0, $a0, 0xE0
    /* 476A0 800AFEA0 0C004010 */  beqz       $v0, .L800AFED4
    /* 476A4 800AFEA4 1F008330 */   andi      $v1, $a0, 0x1F
    /* 476A8 800AFEA8 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 476AC 800AFEAC 06006214 */  bne        $v1, $v0, .L800AFEC8
    /* 476B0 800AFEB0 01002225 */   addiu     $v0, $t1, 0x1
    /* 476B4 800AFEB4 20002925 */  addiu      $t1, $t1, 0x20
    /* 476B8 800AFEB8 0100E290 */  lbu        $v0, 0x1($a3)
    /* 476BC 800AFEBC 0200E724 */  addiu      $a3, $a3, 0x2
    /* 476C0 800AFEC0 E3BF0208 */  j          .L800AFF8C
    /* 476C4 800AFEC4 21482201 */   addu      $t1, $t1, $v0
  .L800AFEC8:
    /* 476C8 800AFEC8 21484300 */  addu       $t1, $v0, $v1
    /* 476CC 800AFECC E3BF0208 */  j          .L800AFF8C
    /* 476D0 800AFED0 0100E724 */   addiu     $a3, $a3, 0x1
  .L800AFED4:
    /* 476D4 800AFED4 03008330 */  andi       $v1, $a0, 0x3
    /* 476D8 800AFED8 03000224 */  addiu      $v0, $zero, 0x3
    /* 476DC 800AFEDC 06006214 */  bne        $v1, $v0, .L800AFEF8
    /* 476E0 800AFEE0 01002225 */   addiu     $v0, $t1, 0x1
    /* 476E4 800AFEE4 04002925 */  addiu      $t1, $t1, 0x4
    /* 476E8 800AFEE8 0100E290 */  lbu        $v0, 0x1($a3)
    /* 476EC 800AFEEC 0200E724 */  addiu      $a3, $a3, 0x2
    /* 476F0 800AFEF0 C0BF0208 */  j          .L800AFF00
    /* 476F4 800AFEF4 21482201 */   addu      $t1, $t1, $v0
  .L800AFEF8:
    /* 476F8 800AFEF8 21484300 */  addu       $t1, $v0, $v1
    /* 476FC 800AFEFC 0100E724 */  addiu      $a3, $a3, 0x1
  .L800AFF00:
    /* 47700 800AFF00 C0200400 */  sll        $a0, $a0, 3
    /* 47704 800AFF04 0000E380 */  lb         $v1, 0x0($a3)
    /* 47708 800AFF08 0100E290 */  lbu        $v0, 0x1($a3)
    /* 4770C 800AFF0C 0200E724 */  addiu      $a3, $a3, 0x2
    /* 47710 800AFF10 001A0300 */  sll        $v1, $v1, 8
    /* 47714 800AFF14 25186200 */  or         $v1, $v1, $v0
    /* 47718 800AFF18 21406000 */  addu       $t0, $v1, $zero
    /* 4771C 800AFF1C 04000231 */  andi       $v0, $t0, 0x4
    /* 47720 800AFF20 0A004010 */  beqz       $v0, .L800AFF4C
    /* 47724 800AFF24 C3180300 */   sra       $v1, $v1, 3
    /* 47728 800AFF28 000043A5 */  sh         $v1, 0x0($t2)
    /* 4772C 800AFF2C 03000231 */  andi       $v0, $t0, 0x3
    /* 47730 800AFF30 06004010 */  beqz       $v0, .L800AFF4C
    /* 47734 800AFF34 60008430 */   andi      $a0, $a0, 0x60
    /* 47738 800AFF38 0000E380 */  lb         $v1, 0x0($a3)
    /* 4773C 800AFF3C 0100E290 */  lbu        $v0, 0x1($a3)
    /* 47740 800AFF40 0200E724 */  addiu      $a3, $a3, 0x2
    /* 47744 800AFF44 001A0300 */  sll        $v1, $v1, 8
    /* 47748 800AFF48 25186200 */  or         $v1, $v1, $v0
  .L800AFF4C:
    /* 4774C 800AFF4C 02000231 */  andi       $v0, $t0, 0x2
    /* 47750 800AFF50 09004010 */  beqz       $v0, .L800AFF78
    /* 47754 800AFF54 01000231 */   andi      $v0, $t0, 0x1
    /* 47758 800AFF58 020043A5 */  sh         $v1, 0x2($t2)
    /* 4775C 800AFF5C 0B004010 */  beqz       $v0, .L800AFF8C
    /* 47760 800AFF60 A0008430 */   andi      $a0, $a0, 0xA0
    /* 47764 800AFF64 0000E380 */  lb         $v1, 0x0($a3)
    /* 47768 800AFF68 0100E290 */  lbu        $v0, 0x1($a3)
    /* 4776C 800AFF6C 0200E724 */  addiu      $a3, $a3, 0x2
    /* 47770 800AFF70 001A0300 */  sll        $v1, $v1, 8
    /* 47774 800AFF74 25186200 */  or         $v1, $v1, $v0
  .L800AFF78:
    /* 47778 800AFF78 01000231 */  andi       $v0, $t0, 0x1
    /* 4777C 800AFF7C 04004010 */  beqz       $v0, .L800AFF90
    /* 47780 800AFF80 80008230 */   andi      $v0, $a0, 0x80
    /* 47784 800AFF84 040043A5 */  sh         $v1, 0x4($t2)
    /* 47788 800AFF88 C0008430 */  andi       $a0, $a0, 0xC0
  .L800AFF8C:
    /* 4778C 800AFF8C 80008230 */  andi       $v0, $a0, 0x80
  .L800AFF90:
    /* 47790 800AFF90 07004010 */  beqz       $v0, .L800AFFB0
    /* 47794 800AFF94 40008230 */   andi      $v0, $a0, 0x40
    /* 47798 800AFF98 0000E290 */  lbu        $v0, 0x0($a3)
    /* 4779C 800AFF9C 0100E724 */  addiu      $a3, $a3, 0x1
    /* 477A0 800AFFA0 00160200 */  sll        $v0, $v0, 24
    /* 477A4 800AFFA4 03160200 */  sra        $v0, $v0, 24
    /* 477A8 800AFFA8 000042A5 */  sh         $v0, 0x0($t2)
    /* 477AC 800AFFAC 40008230 */  andi       $v0, $a0, 0x40
  .L800AFFB0:
    /* 477B0 800AFFB0 07004010 */  beqz       $v0, .L800AFFD0
    /* 477B4 800AFFB4 20008230 */   andi      $v0, $a0, 0x20
    /* 477B8 800AFFB8 0000E290 */  lbu        $v0, 0x0($a3)
    /* 477BC 800AFFBC 0100E724 */  addiu      $a3, $a3, 0x1
    /* 477C0 800AFFC0 00160200 */  sll        $v0, $v0, 24
    /* 477C4 800AFFC4 03160200 */  sra        $v0, $v0, 24
    /* 477C8 800AFFC8 020042A5 */  sh         $v0, 0x2($t2)
    /* 477CC 800AFFCC 20008230 */  andi       $v0, $a0, 0x20
  .L800AFFD0:
    /* 477D0 800AFFD0 94FF4010 */  beqz       $v0, .L800AFE24
    /* 477D4 800AFFD4 2A102B01 */   slt       $v0, $t1, $t3
    /* 477D8 800AFFD8 0000E290 */  lbu        $v0, 0x0($a3)
    /* 477DC 800AFFDC 0100E724 */  addiu      $a3, $a3, 0x1
    /* 477E0 800AFFE0 00160200 */  sll        $v0, $v0, 24
    /* 477E4 800AFFE4 03160200 */  sra        $v0, $v0, 24
    /* 477E8 800AFFE8 88BF0208 */  j          .L800AFE20
    /* 477EC 800AFFEC 040042A5 */   sh        $v0, 0x4($t2)
  .L800AFFF0:
    /* 477F0 800AFFF0 0C00828D */  lw         $v0, 0xC($t4)
    /* 477F4 800AFFF4 01006B25 */  addiu      $t3, $t3, 0x1
    /* 477F8 800AFFF8 2A104B00 */  slt        $v0, $v0, $t3
    /* 477FC 800AFFFC 89FF4010 */  beqz       $v0, .L800AFE24
    /* 47800 800B0000 2A102B01 */   slt       $v0, $t1, $t3
  .L800B0004:
    /* 47804 800B0004 1000828D */  lw         $v0, 0x10($t4)
    /* 47808 800B0008 00000000 */  nop
    /* 4780C 800B000C 0000428C */  lw         $v0, 0x0($v0)
    /* 47810 800B0010 00000000 */  nop
    /* 47814 800B0014 2110A201 */  addu       $v0, $t5, $v0
    /* 47818 800B0018 2338E200 */  subu       $a3, $a3, $v0
    /* 4781C 800B001C 0600A7A4 */  sh         $a3, 0x6($a1)
    /* 47820 800B0020 060049A5 */  sh         $t1, 0x6($t2)
  .L800B0024:
    /* 47824 800B0024 0800E003 */  jr         $ra
    /* 47828 800B0028 00000000 */   nop
endlabel func_800AFDE8
