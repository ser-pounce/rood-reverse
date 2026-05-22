/* Handwritten function */
nonmatching func_800B4594, 0x580

glabel func_800B4594
    /* 4BD94 800B4594 801F083C */  lui        $t0, (0x1F800390 >> 16)
    /* 4BD98 800B4598 580310AD */  sw         $s0, (0x1F800358 & 0xFFFF)($t0)
    /* 4BD9C 800B459C 5C0311AD */  sw         $s1, (0x1F80035C & 0xFFFF)($t0)
    /* 4BDA0 800B45A0 600312AD */  sw         $s2, (0x1F800360 & 0xFFFF)($t0)
    /* 4BDA4 800B45A4 640313AD */  sw         $s3, (0x1F800364 & 0xFFFF)($t0)
    /* 4BDA8 800B45A8 680314AD */  sw         $s4, (0x1F800368 & 0xFFFF)($t0)
    /* 4BDAC 800B45AC 6C0315AD */  sw         $s5, (0x1F80036C & 0xFFFF)($t0)
    /* 4BDB0 800B45B0 700316AD */  sw         $s6, (0x1F800370 & 0xFFFF)($t0)
    /* 4BDB4 800B45B4 740317AD */  sw         $s7, (0x1F800374 & 0xFFFF)($t0)
    /* 4BDB8 800B45B8 78031FAD */  sw         $ra, (0x1F800378 & 0xFFFF)($t0)
    /* 4BDBC 800B45BC 7C031CAD */  sw         $gp, (0x1F80037C & 0xFFFF)($t0)
    /* 4BDC0 800B45C0 80031EAD */  sw         $fp, (0x1F800380 & 0xFFFF)($t0)
    /* 4BDC4 800B45C4 90031C8D */  lw         $gp, (0x1F800390 & 0xFFFF)($t0)
    /* 4BDC8 800B45C8 FF00143C */  lui        $s4, (0xFFFFFF >> 16)
    /* 4BDCC 800B45CC FFFF9436 */  ori        $s4, $s4, (0xFFFFFF & 0xFFFF)
    /* 4BDD0 800B45D0 00FC1C00 */  sll        $ra, $gp, 16
    /* 4BDD4 800B45D4 02E41C00 */  srl        $gp, $gp, 16
    /* 4BDD8 800B45D8 00E41C00 */  sll        $gp, $gp, 16
    /* 4BDDC 800B45DC 00FF153C */  lui        $s5, (0xFF000000 >> 16)
    /* 4BDE0 800B45E0 801F103C */  lui        $s0, (0x1F800004 >> 16)
    /* 4BDE4 800B45E4 0200B394 */  lhu        $s3, 0x2($a1)
    /* 4BDE8 800B45E8 3C00F28C */  lw         $s2, 0x3C($a3)
    /* 4BDEC 800B45EC 000C9E24 */  addiu      $fp, $a0, 0xC00
    /* 4BDF0 800B45F0 0000118E */  lw         $s1, (0x1F800000 & 0xFFFF)($s0)
    /* 4BDF4 800B45F4 0400178E */  lw         $s7, (0x1F800004 & 0xFFFF)($s0)
    /* 4BDF8 800B45F8 0000C68C */  lw         $a2, 0x0($a2)
    /* 4BDFC 800B45FC FCFFF722 */  addi       $s7, $s7, -0x4 /* handwritten instruction */
    /* 4BE00 800B4600 45006012 */  beqz       $s3, .L800B4718
    /* 4BE04 800B4604 0009183C */   lui       $t8, (0x9000000 >> 16)
    /* 4BE08 800B4608 00004B8E */  lw         $t3, 0x0($s2)
  .L800B460C:
    /* 4BE0C 800B460C 04004F8E */  lw         $t7, 0x4($s2)
    /* 4BE10 800B4610 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4BE14 800B4614 024C0B00 */  srl        $t1, $t3, 16
    /* 4BE18 800B4618 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4BE1C 800B461C 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4BE20 800B4620 00008C8D */  lw         $t4, 0x0($t4)
    /* 4BE24 800B4624 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4BE28 800B4628 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4BE2C 800B462C 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4BE30 800B4630 0000CE8D */  lw         $t6, 0x0($t6)
    /* 4BE34 800B4634 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4BE38 800B4638 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4BE3C 800B463C 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4BE40 800B4640 027C0F00 */  srl        $t7, $t7, 16
    /* 4BE44 800B4644 20401E01 */  add        $t0, $t0, $fp /* handwritten instruction */
    /* 4BE48 800B4648 0600404B */  nclip
    /* 4BE4C 800B464C 0800438E */  lw         $v1, 0x8($s2)
    /* 4BE50 800B4650 20483E01 */  add        $t1, $t1, $fp /* handwritten instruction */
    /* 4BE54 800B4654 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4BE58 800B4658 20505E01 */  add        $t2, $t2, $fp /* handwritten instruction */
    /* 4BE5C 800B465C 0500401C */  bgtz       $v0, .L800B4674
    /* 4BE60 800B4660 FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4BE64 800B4664 2C006012 */  beqz       $s3, .L800B4718
    /* 4BE68 800B4668 18005226 */   addiu     $s2, $s2, 0x18
    /* 4BE6C 800B466C 83D10208 */  j          .L800B460C
    /* 4BE70 800B4670 00004B8E */   lw        $t3, 0x0($s2)
  .L800B4674:
    /* 4BE74 800B4674 0000088D */  lw         $t0, 0x0($t0)
    /* 4BE78 800B4678 0000298D */  lw         $t1, 0x0($t1)
    /* 4BE7C 800B467C 00004A8D */  lw         $t2, 0x0($t2)
    /* 4BE80 800B4680 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4BE84 800B4684 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4BE88 800B4688 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4BE8C 800B468C 0C00488E */  lw         $t0, 0xC($s2)
    /* 4BE90 800B4690 1000498E */  lw         $t1, 0x10($s2)
    /* 4BE94 800B4694 14004B8E */  lw         $t3, 0x14($s2)
    /* 4BE98 800B4698 040023AE */  sw         $v1, 0x4($s1)
    /* 4BE9C 800B469C 2D00584B */  avsz3
    /* 4BEA0 800B46A0 08002CAE */  sw         $t4, 0x8($s1)
    /* 4BEA4 800B46A4 021C0B00 */  srl        $v1, $t3, 16
    /* 4BEA8 800B46A8 25187F00 */  or         $v1, $v1, $ra
    /* 4BEAC 800B46AC FFFF6231 */  andi       $v0, $t3, 0xFFFF
    /* 4BEB0 800B46B0 25105C00 */  or         $v0, $v0, $gp
    /* 4BEB4 800B46B4 0C0022AE */  sw         $v0, 0xC($s1)
    /* 4BEB8 800B46B8 100028AE */  sw         $t0, 0x10($s1)
    /* 4BEBC 800B46BC 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4BEC0 800B46C0 14002DAE */  sw         $t5, 0x14($s1)
    /* 4BEC4 800B46C4 C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4BEC8 800B46C8 0F000011 */  beqz       $t0, .L800B4708
    /* 4BECC 800B46CC 80100200 */   sll       $v0, $v0, 2
    /* 4BED0 800B46D0 180023AE */  sw         $v1, 0x18($s1)
    /* 4BED4 800B46D4 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4BED8 800B46D8 1C0029AE */  sw         $t1, 0x1C($s1)
    /* 4BEDC 800B46DC 00004A8C */  lw         $t2, 0x0($v0)
    /* 4BEE0 800B46E0 20002EAE */  sw         $t6, 0x20($s1)
    /* 4BEE4 800B46E4 24483402 */  and        $t1, $s1, $s4
    /* 4BEE8 800B46E8 24002FAE */  sw         $t7, 0x24($s1)
    /* 4BEEC 800B46EC 24405401 */  and        $t0, $t2, $s4
    /* 4BEF0 800B46F0 25401801 */  or         $t0, $t0, $t8
    /* 4BEF4 800B46F4 000028AE */  sw         $t0, 0x0($s1)
    /* 4BEF8 800B46F8 24405501 */  and        $t0, $t2, $s5
    /* 4BEFC 800B46FC 25400901 */  or         $t0, $t0, $t1
    /* 4BF00 800B4700 000048AC */  sw         $t0, 0x0($v0)
    /* 4BF04 800B4704 28003126 */  addiu      $s1, $s1, 0x28
  .L800B4708:
    /* 4BF08 800B4708 03006012 */  beqz       $s3, .L800B4718
    /* 4BF0C 800B470C 18005226 */   addiu     $s2, $s2, 0x18
    /* 4BF10 800B4710 83D10208 */  j          .L800B460C
    /* 4BF14 800B4714 00004B8E */   lw        $t3, 0x0($s2)
  .L800B4718:
    /* 4BF18 800B4718 0400B394 */  lhu        $s3, 0x4($a1)
    /* 4BF1C 800B471C 000C183C */  lui        $t8, (0xC000000 >> 16)
    /* 4BF20 800B4720 4D006012 */  beqz       $s3, .L800B4858
    /* 4BF24 800B4724 00004B8E */   lw        $t3, 0x0($s2)
  .L800B4728:
    /* 4BF28 800B4728 04004F8E */  lw         $t7, 0x4($s2)
    /* 4BF2C 800B472C FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4BF30 800B4730 024C0B00 */  srl        $t1, $t3, 16
    /* 4BF34 800B4734 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4BF38 800B4738 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4BF3C 800B473C 00008C8D */  lw         $t4, 0x0($t4)
    /* 4BF40 800B4740 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4BF44 800B4744 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4BF48 800B4748 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4BF4C 800B474C 0000CE8D */  lw         $t6, 0x0($t6)
    /* 4BF50 800B4750 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4BF54 800B4754 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4BF58 800B4758 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4BF5C 800B475C 025C0F00 */  srl        $t3, $t7, 16
    /* 4BF60 800B4760 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4BF64 800B4764 0600404B */  nclip
    /* 4BF68 800B4768 20401E01 */  add        $t0, $t0, $fp /* handwritten instruction */
    /* 4BF6C 800B476C 20483E01 */  add        $t1, $t1, $fp /* handwritten instruction */
    /* 4BF70 800B4770 20505E01 */  add        $t2, $t2, $fp /* handwritten instruction */
    /* 4BF74 800B4774 0800438E */  lw         $v1, 0x8($s2)
    /* 4BF78 800B4778 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4BF7C 800B477C 20587E01 */  add        $t3, $t3, $fp /* handwritten instruction */
    /* 4BF80 800B4780 0500401C */  bgtz       $v0, .L800B4798
    /* 4BF84 800B4784 FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4BF88 800B4788 33006012 */  beqz       $s3, .L800B4858
    /* 4BF8C 800B478C 20005226 */   addiu     $s2, $s2, 0x20
    /* 4BF90 800B4790 CAD10208 */  j          .L800B4728
    /* 4BF94 800B4794 00004B8E */   lw        $t3, 0x0($s2)
  .L800B4798:
    /* 4BF98 800B4798 0000088D */  lw         $t0, 0x0($t0)
    /* 4BF9C 800B479C 0000298D */  lw         $t1, 0x0($t1)
    /* 4BFA0 800B47A0 00004A8D */  lw         $t2, 0x0($t2)
    /* 4BFA4 800B47A4 00006B8D */  lw         $t3, 0x0($t3)
    /* 4BFA8 800B47A8 20100901 */  add        $v0, $t0, $t1 /* handwritten instruction */
    /* 4BFAC 800B47AC 0000EF8D */  lw         $t7, 0x0($t7)
    /* 4BFB0 800B47B0 20104A00 */  add        $v0, $v0, $t2 /* handwritten instruction */
    /* 4BFB4 800B47B4 0C00508E */  lw         $s0, 0xC($s2)
    /* 4BFB8 800B47B8 1000568E */  lw         $s6, 0x10($s2)
    /* 4BFBC 800B47BC 1400598E */  lw         $t9, 0x14($s2)
    /* 4BFC0 800B47C0 1800488E */  lw         $t0, 0x18($s2)
    /* 4BFC4 800B47C4 1C004A8E */  lw         $t2, 0x1C($s2)
    /* 4BFC8 800B47C8 024C0800 */  srl        $t1, $t0, 16
    /* 4BFCC 800B47CC 25483F01 */  or         $t1, $t1, $ra
    /* 4BFD0 800B47D0 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4BFD4 800B47D4 25401C01 */  or         $t0, $t0, $gp
    /* 4BFD8 800B47D8 040023AE */  sw         $v1, 0x4($s1)
    /* 4BFDC 800B47DC 08002CAE */  sw         $t4, 0x8($s1)
    /* 4BFE0 800B47E0 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4BFE4 800B47E4 100030AE */  sw         $s0, 0x10($s1)
    /* 4BFE8 800B47E8 20104B00 */  add        $v0, $v0, $t3 /* handwritten instruction */
    /* 4BFEC 800B47EC 14002DAE */  sw         $t5, 0x14($s1)
    /* 4BFF0 800B47F0 025C0A00 */  srl        $t3, $t2, 16
    /* 4BFF4 800B47F4 180029AE */  sw         $t1, 0x18($s1)
    /* 4BFF8 800B47F8 02110200 */  srl        $v0, $v0, 4
    /* 4BFFC 800B47FC 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 4C000 800B4800 C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4C004 800B4804 10000011 */  beqz       $t0, .L800B4848
    /* 4C008 800B4808 80100200 */   sll       $v0, $v0, 2
    /* 4C00C 800B480C 20002EAE */  sw         $t6, 0x20($s1)
    /* 4C010 800B4810 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4C014 800B4814 24002AAE */  sw         $t2, 0x24($s1)
    /* 4C018 800B4818 0000508C */  lw         $s0, 0x0($v0)
    /* 4C01C 800B481C 280039AE */  sw         $t9, 0x28($s1)
    /* 4C020 800B4820 24483402 */  and        $t1, $s1, $s4
    /* 4C024 800B4824 2C002FAE */  sw         $t7, 0x2C($s1)
    /* 4C028 800B4828 24401402 */  and        $t0, $s0, $s4
    /* 4C02C 800B482C 30002BAE */  sw         $t3, 0x30($s1)
    /* 4C030 800B4830 25401801 */  or         $t0, $t0, $t8
    /* 4C034 800B4834 000028AE */  sw         $t0, 0x0($s1)
    /* 4C038 800B4838 24401502 */  and        $t0, $s0, $s5
    /* 4C03C 800B483C 25400901 */  or         $t0, $t0, $t1
    /* 4C040 800B4840 000048AC */  sw         $t0, 0x0($v0)
    /* 4C044 800B4844 34003126 */  addiu      $s1, $s1, 0x34
  .L800B4848:
    /* 4C048 800B4848 03006012 */  beqz       $s3, .L800B4858
    /* 4C04C 800B484C 20005226 */   addiu     $s2, $s2, 0x20
    /* 4C050 800B4850 CAD10208 */  j          .L800B4728
    /* 4C054 800B4854 00004B8E */   lw        $t3, 0x0($s2)
  .L800B4858:
    /* 4C058 800B4858 0600B394 */  lhu        $s3, 0x6($a1)
    /* 4C05C 800B485C F0FFF722 */  addi       $s7, $s7, -0x10 /* handwritten instruction */
    /* 4C060 800B4860 9E006012 */  beqz       $s3, .L800B4ADC
    /* 4C064 800B4864 2528C003 */   or        $a1, $fp, $zero
    /* 4C068 800B4868 10005E8E */  lw         $fp, 0x10($s2)
  .L800B486C:
    /* 4C06C 800B486C 00004B8E */  lw         $t3, 0x0($s2)
    /* 4C070 800B4870 021E1E00 */  srl        $v1, $fp, 24
    /* 4C074 800B4874 01006230 */  andi       $v0, $v1, 0x1
    /* 4C078 800B4878 04004F8E */  lw         $t7, 0x4($s2)
    /* 4C07C 800B487C FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4C080 800B4880 024C0B00 */  srl        $t1, $t3, 16
    /* 4C084 800B4884 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4C088 800B4888 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4C08C 800B488C 00008C8D */  lw         $t4, 0x0($t4)
    /* 4C090 800B4890 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4C094 800B4894 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4C098 800B4898 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4C09C 800B489C 15004014 */  bnez       $v0, .L800B48F4
    /* 4C0A0 800B48A0 0000CE8D */   lw        $t6, 0x0($t6)
    /* 4C0A4 800B48A4 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4C0A8 800B48A8 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4C0AC 800B48AC 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4C0B0 800B48B0 025C0F00 */  srl        $t3, $t7, 16
    /* 4C0B4 800B48B4 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4C0B8 800B48B8 0600404B */  nclip
    /* 4C0BC 800B48BC 20400501 */  add        $t0, $t0, $a1 /* handwritten instruction */
    /* 4C0C0 800B48C0 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 4C0C4 800B48C4 20504501 */  add        $t2, $t2, $a1 /* handwritten instruction */
    /* 4C0C8 800B48C8 20586501 */  add        $t3, $t3, $a1 /* handwritten instruction */
    /* 4C0CC 800B48CC 0800588E */  lw         $t8, 0x8($s2)
    /* 4C0D0 800B48D0 0C00508E */  lw         $s0, 0xC($s2)
    /* 4C0D4 800B48D4 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4C0D8 800B48D8 02861000 */  srl        $s0, $s0, 24
    /* 4C0DC 800B48DC 0E00401C */  bgtz       $v0, .L800B4918
    /* 4C0E0 800B48E0 FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4C0E4 800B48E4 7D006012 */  beqz       $s3, .L800B4ADC
    /* 4C0E8 800B48E8 20905002 */   add       $s2, $s2, $s0 /* handwritten instruction */
    /* 4C0EC 800B48EC 1BD20208 */  j          .L800B486C
    /* 4C0F0 800B48F0 00005E8E */   lw        $fp, 0x0($s2)
  .L800B48F4:
    /* 4C0F4 800B48F4 FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 4C0F8 800B48F8 025C0F00 */  srl        $t3, $t7, 16
    /* 4C0FC 800B48FC 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4C100 800B4900 20400501 */  add        $t0, $t0, $a1 /* handwritten instruction */
    /* 4C104 800B4904 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 4C108 800B4908 20504501 */  add        $t2, $t2, $a1 /* handwritten instruction */
    /* 4C10C 800B490C 20586501 */  add        $t3, $t3, $a1 /* handwritten instruction */
    /* 4C110 800B4910 0800588E */  lw         $t8, 0x8($s2)
    /* 4C114 800B4914 00000000 */  nop
  .L800B4918:
    /* 4C118 800B4918 02861800 */  srl        $s0, $t8, 24
    /* 4C11C 800B491C 0000088D */  lw         $t0, 0x0($t0)
    /* 4C120 800B4920 3C000234 */  ori        $v0, $zero, 0x3C
    /* 4C124 800B4924 0000298D */  lw         $t1, 0x0($t1)
    /* 4C128 800B4928 34000212 */  beq        $s0, $v0, .L800B49FC
    /* 4C12C 800B492C 00004A8D */   lw        $t2, 0x0($t2)
    /* 4C130 800B4930 10007030 */  andi       $s0, $v1, 0x10
    /* 4C134 800B4934 40851000 */  sll        $s0, $s0, 21
    /* 4C138 800B4938 25C01003 */  or         $t8, $t8, $s0
    /* 4C13C 800B493C 040038AE */  sw         $t8, 0x4($s1)
    /* 4C140 800B4940 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4C144 800B4944 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4C148 800B4948 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4C14C 800B494C 60006330 */  andi       $v1, $v1, 0x60
    /* 4C150 800B4950 001C0300 */  sll        $v1, $v1, 16
    /* 4C154 800B4954 2D00584B */  avsz3
    /* 4C158 800B4958 0C00488E */  lw         $t0, 0xC($s2)
    /* 4C15C 800B495C 1000498E */  lw         $t1, 0x10($s2)
    /* 4C160 800B4960 14004B8E */  lw         $t3, 0x14($s2)
    /* 4C164 800B4964 0400588E */  lw         $t8, 0x4($s2)
    /* 4C168 800B4968 02540B00 */  srl        $t2, $t3, 16
    /* 4C16C 800B496C 02C41800 */  srl        $t8, $t8, 16
    /* 4C170 800B4970 25505F01 */  or         $t2, $t2, $ra
    /* 4C174 800B4974 25504301 */  or         $t2, $t2, $v1
    /* 4C178 800B4978 FFFF6F31 */  andi       $t7, $t3, 0xFFFF
    /* 4C17C 800B497C 08002CAE */  sw         $t4, 0x8($s1)
    /* 4C180 800B4980 2578FC01 */  or         $t7, $t7, $gp
    /* 4C184 800B4984 0C002FAE */  sw         $t7, 0xC($s1)
    /* 4C188 800B4988 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4C18C 800B498C 100028AE */  sw         $t0, 0x10($s1)
    /* 4C190 800B4990 821E0900 */  srl        $v1, $t1, 26
    /* 4C194 800B4994 14002DAE */  sw         $t5, 0x14($s1)
    /* 4C198 800B4998 03006330 */  andi       $v1, $v1, 0x3
    /* 4C19C 800B499C 18002AAE */  sw         $t2, 0x18($s1)
    /* 4C1A0 800B49A0 80180300 */  sll        $v1, $v1, 2
    /* 4C1A4 800B49A4 1C0029AE */  sw         $t1, 0x1C($s1)
    /* 4C1A8 800B49A8 20104300 */  add        $v0, $v0, $v1 /* handwritten instruction */
    /* 4C1AC 800B49AC 20002EAE */  sw         $t6, 0x20($s1)
    /* 4C1B0 800B49B0 C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4C1B4 800B49B4 0D000011 */  beqz       $t0, .L800B49EC
    /* 4C1B8 800B49B8 80100200 */   sll       $v0, $v0, 2
    /* 4C1BC 800B49BC 240038AE */  sw         $t8, 0x24($s1)
    /* 4C1C0 800B49C0 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4C1C4 800B49C4 0000438C */  lw         $v1, 0x0($v0)
    /* 4C1C8 800B49C8 0009183C */  lui        $t8, (0x9000000 >> 16)
    /* 4C1CC 800B49CC 24407400 */  and        $t0, $v1, $s4
    /* 4C1D0 800B49D0 25401801 */  or         $t0, $t0, $t8
    /* 4C1D4 800B49D4 000028AE */  sw         $t0, 0x0($s1)
    /* 4C1D8 800B49D8 24483402 */  and        $t1, $s1, $s4
    /* 4C1DC 800B49DC 24407500 */  and        $t0, $v1, $s5
    /* 4C1E0 800B49E0 25400901 */  or         $t0, $t0, $t1
    /* 4C1E4 800B49E4 000048AC */  sw         $t0, 0x0($v0)
    /* 4C1E8 800B49E8 28003126 */  addiu      $s1, $s1, 0x28
  .L800B49EC:
    /* 4C1EC 800B49EC 3B006012 */  beqz       $s3, .L800B4ADC
    /* 4C1F0 800B49F0 18005226 */   addiu     $s2, $s2, 0x18
    /* 4C1F4 800B49F4 1BD20208 */  j          .L800B486C
    /* 4C1F8 800B49F8 10005E8E */   lw        $fp, 0x10($s2)
  .L800B49FC:
    /* 4C1FC 800B49FC 10007030 */  andi       $s0, $v1, 0x10
    /* 4C200 800B4A00 40851000 */  sll        $s0, $s0, 21
    /* 4C204 800B4A04 25C01003 */  or         $t8, $t8, $s0
    /* 4C208 800B4A08 040038AE */  sw         $t8, 0x4($s1)
    /* 4C20C 800B4A0C 60007830 */  andi       $t8, $v1, 0x60
    /* 4C210 800B4A10 00C41800 */  sll        $t8, $t8, 16
    /* 4C214 800B4A14 00006B8D */  lw         $t3, 0x0($t3)
    /* 4C218 800B4A18 20100901 */  add        $v0, $t0, $t1 /* handwritten instruction */
    /* 4C21C 800B4A1C 0000EF8D */  lw         $t7, 0x0($t7)
    /* 4C220 800B4A20 0C00438E */  lw         $v1, 0xC($s2)
    /* 4C224 800B4A24 1000508E */  lw         $s0, 0x10($s2)
    /* 4C228 800B4A28 1400568E */  lw         $s6, 0x14($s2)
    /* 4C22C 800B4A2C 20104A00 */  add        $v0, $v0, $t2 /* handwritten instruction */
    /* 4C230 800B4A30 1800488E */  lw         $t0, 0x18($s2)
    /* 4C234 800B4A34 20104B00 */  add        $v0, $v0, $t3 /* handwritten instruction */
    /* 4C238 800B4A38 1C004A8E */  lw         $t2, 0x1C($s2)
    /* 4C23C 800B4A3C 024C0800 */  srl        $t1, $t0, 16
    /* 4C240 800B4A40 25483F01 */  or         $t1, $t1, $ra
    /* 4C244 800B4A44 25483801 */  or         $t1, $t1, $t8
    /* 4C248 800B4A48 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4C24C 800B4A4C 25401C01 */  or         $t0, $t0, $gp
    /* 4C250 800B4A50 08002CAE */  sw         $t4, 0x8($s1)
    /* 4C254 800B4A54 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4C258 800B4A58 100023AE */  sw         $v1, 0x10($s1)
    /* 4C25C 800B4A5C 025C0A00 */  srl        $t3, $t2, 16
    /* 4C260 800B4A60 14002DAE */  sw         $t5, 0x14($s1)
    /* 4C264 800B4A64 02110200 */  srl        $v0, $v0, 4
    /* 4C268 800B4A68 180029AE */  sw         $t1, 0x18($s1)
    /* 4C26C 800B4A6C 821E1000 */  srl        $v1, $s0, 26
    /* 4C270 800B4A70 1C0030AE */  sw         $s0, 0x1C($s1)
    /* 4C274 800B4A74 03006330 */  andi       $v1, $v1, 0x3
    /* 4C278 800B4A78 20002EAE */  sw         $t6, 0x20($s1)
    /* 4C27C 800B4A7C 80180300 */  sll        $v1, $v1, 2
    /* 4C280 800B4A80 24002AAE */  sw         $t2, 0x24($s1)
    /* 4C284 800B4A84 20104300 */  add        $v0, $v0, $v1 /* handwritten instruction */
    /* 4C288 800B4A88 280036AE */  sw         $s6, 0x28($s1)
    /* 4C28C 800B4A8C C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4C290 800B4A90 0E000011 */  beqz       $t0, .L800B4ACC
    /* 4C294 800B4A94 2C002FAE */   sw        $t7, 0x2C($s1)
    /* 4C298 800B4A98 80100200 */  sll        $v0, $v0, 2
    /* 4C29C 800B4A9C 30002BAE */  sw         $t3, 0x30($s1)
    /* 4C2A0 800B4AA0 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4C2A4 800B4AA4 0000438C */  lw         $v1, 0x0($v0)
    /* 4C2A8 800B4AA8 000C183C */  lui        $t8, (0xC000000 >> 16)
    /* 4C2AC 800B4AAC 24407400 */  and        $t0, $v1, $s4
    /* 4C2B0 800B4AB0 25401801 */  or         $t0, $t0, $t8
    /* 4C2B4 800B4AB4 000028AE */  sw         $t0, 0x0($s1)
    /* 4C2B8 800B4AB8 24483402 */  and        $t1, $s1, $s4
    /* 4C2BC 800B4ABC 24407500 */  and        $t0, $v1, $s5
    /* 4C2C0 800B4AC0 25400901 */  or         $t0, $t0, $t1
    /* 4C2C4 800B4AC4 000048AC */  sw         $t0, 0x0($v0)
    /* 4C2C8 800B4AC8 34003126 */  addiu      $s1, $s1, 0x34
  .L800B4ACC:
    /* 4C2CC 800B4ACC 03006012 */  beqz       $s3, .L800B4ADC
    /* 4C2D0 800B4AD0 20005226 */   addiu     $s2, $s2, 0x20
    /* 4C2D4 800B4AD4 1BD20208 */  j          .L800B486C
    /* 4C2D8 800B4AD8 10005E8E */   lw        $fp, 0x10($s2)
  .L800B4ADC:
    /* 4C2DC 800B4ADC 801F083C */  lui        $t0, (0x1F800380 >> 16)
    /* 4C2E0 800B4AE0 000011AD */  sw         $s1, (0x1F800000 & 0xFFFF)($t0)
    /* 4C2E4 800B4AE4 5803108D */  lw         $s0, (0x1F800358 & 0xFFFF)($t0)
    /* 4C2E8 800B4AE8 5C03118D */  lw         $s1, (0x1F80035C & 0xFFFF)($t0)
    /* 4C2EC 800B4AEC 6003128D */  lw         $s2, (0x1F800360 & 0xFFFF)($t0)
    /* 4C2F0 800B4AF0 6403138D */  lw         $s3, (0x1F800364 & 0xFFFF)($t0)
    /* 4C2F4 800B4AF4 6803148D */  lw         $s4, (0x1F800368 & 0xFFFF)($t0)
    /* 4C2F8 800B4AF8 6C03158D */  lw         $s5, (0x1F80036C & 0xFFFF)($t0)
    /* 4C2FC 800B4AFC 7003168D */  lw         $s6, (0x1F800370 & 0xFFFF)($t0)
    /* 4C300 800B4B00 7403178D */  lw         $s7, (0x1F800374 & 0xFFFF)($t0)
    /* 4C304 800B4B04 78031F8D */  lw         $ra, (0x1F800378 & 0xFFFF)($t0)
    /* 4C308 800B4B08 7C031C8D */  lw         $gp, (0x1F80037C & 0xFFFF)($t0)
    /* 4C30C 800B4B0C 0800E003 */  jr         $ra
    /* 4C310 800B4B10 80031E8D */   lw        $fp, (0x1F800380 & 0xFFFF)($t0)
endlabel func_800B4594
