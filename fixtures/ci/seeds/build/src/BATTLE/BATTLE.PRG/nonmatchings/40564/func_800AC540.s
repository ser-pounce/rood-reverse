nonmatching func_800AC540, 0x150

glabel func_800AC540
    /* 43D40 800AC540 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 43D44 800AC544 1000B0AF */  sw         $s0, 0x10($sp)
    /* 43D48 800AC548 2180A000 */  addu       $s0, $a1, $zero
    /* 43D4C 800AC54C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 43D50 800AC550 1400B1AF */  sw         $s1, 0x14($sp)
    /* 43D54 800AC554 AC050292 */  lbu        $v0, 0x5AC($s0)
    /* 43D58 800AC558 00000000 */  nop
    /* 43D5C 800AC55C 03004330 */  andi       $v1, $v0, 0x3
    /* 43D60 800AC560 01000224 */  addiu      $v0, $zero, 0x1
    /* 43D64 800AC564 06006210 */  beq        $v1, $v0, .L800AC580
    /* 43D68 800AC568 21888000 */   addu      $s1, $a0, $zero
    /* 43D6C 800AC56C 02000224 */  addiu      $v0, $zero, 0x2
    /* 43D70 800AC570 24006210 */  beq        $v1, $v0, .L800AC604
    /* 43D74 800AC574 00000000 */   nop
    /* 43D78 800AC578 9EB10208 */  j          .L800AC678
    /* 43D7C 800AC57C 00000000 */   nop
  .L800AC580:
    /* 43D80 800AC580 18000296 */  lhu        $v0, 0x18($s0)
    /* 43D84 800AC584 00000000 */  nop
    /* 43D88 800AC588 3B004014 */  bnez       $v0, .L800AC678
    /* 43D8C 800AC58C 2000033C */   lui       $v1, (0x200000 >> 16)
    /* 43D90 800AC590 0800028E */  lw         $v0, 0x8($s0)
    /* 43D94 800AC594 00000000 */  nop
    /* 43D98 800AC598 24104300 */  and        $v0, $v0, $v1
    /* 43D9C 800AC59C 03004010 */  beqz       $v0, .L800AC5AC
    /* 43DA0 800AC5A0 21202002 */   addu      $a0, $s1, $zero
    /* 43DA4 800AC5A4 6CB10208 */  j          .L800AC5B0
    /* 43DA8 800AC5A8 1F000524 */   addiu     $a1, $zero, 0x1F
  .L800AC5AC:
    /* 43DAC 800AC5AC E5060592 */  lbu        $a1, 0x6E5($s0)
  .L800AC5B0:
    /* 43DB0 800AC5B0 21300000 */  addu       $a2, $zero, $zero
    /* 43DB4 800AC5B4 8180020C */  jal        func_800A0204
    /* 43DB8 800AC5B8 08000724 */   addiu     $a3, $zero, 0x8
    /* 43DBC 800AC5BC AC05028E */  lw         $v0, 0x5AC($s0)
    /* 43DC0 800AC5C0 00000000 */  nop
    /* 43DC4 800AC5C4 04004230 */  andi       $v0, $v0, 0x4
    /* 43DC8 800AC5C8 06004014 */  bnez       $v0, .L800AC5E4
    /* 43DCC 800AC5CC 21202002 */   addu      $a0, $s1, $zero
    /* 43DD0 800AC5D0 C4050696 */  lhu        $a2, 0x5C4($s0)
    /* 43DD4 800AC5D4 64A7020C */  jal        func_800A9D90
    /* 43DD8 800AC5D8 EC050526 */   addiu     $a1, $s0, 0x5EC
    /* 43DDC 800AC5DC 7CB10208 */  j          .L800AC5F0
    /* 43DE0 800AC5E0 00000000 */   nop
  .L800AC5E4:
    /* 43DE4 800AC5E4 C4050696 */  lhu        $a2, 0x5C4($s0)
    /* 43DE8 800AC5E8 88A9020C */  jal        func_800AA620
    /* 43DEC 800AC5EC EC050526 */   addiu     $a1, $s0, 0x5EC
  .L800AC5F0:
    /* 43DF0 800AC5F0 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 43DF4 800AC5F4 FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 43DF8 800AC5F8 24104300 */  and        $v0, $v0, $v1
    /* 43DFC 800AC5FC 9DB10208 */  j          .L800AC674
    /* 43E00 800AC600 02004234 */   ori       $v0, $v0, 0x2
  .L800AC604:
    /* 43E04 800AC604 1A000296 */  lhu        $v0, 0x1A($s0)
    /* 43E08 800AC608 00000000 */  nop
    /* 43E0C 800AC60C 1A004014 */  bnez       $v0, .L800AC678
    /* 43E10 800AC610 21202002 */   addu      $a0, $s1, $zero
    /* 43E14 800AC614 01000524 */  addiu      $a1, $zero, 0x1
    /* 43E18 800AC618 21300000 */  addu       $a2, $zero, $zero
    /* 43E1C 800AC61C 8180020C */  jal        func_800A0204
    /* 43E20 800AC620 08000724 */   addiu     $a3, $zero, 0x8
    /* 43E24 800AC624 F2050596 */  lhu        $a1, 0x5F2($s0)
    /* 43E28 800AC628 00800234 */  ori        $v0, $zero, 0x8000
    /* 43E2C 800AC62C 0E00A210 */  beq        $a1, $v0, .L800AC668
    /* 43E30 800AC630 00000000 */   nop
    /* 43E34 800AC634 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 43E38 800AC638 00000000 */  nop
    /* 43E3C 800AC63C 04004230 */  andi       $v0, $v0, 0x4
    /* 43E40 800AC640 06004014 */  bnez       $v0, .L800AC65C
    /* 43E44 800AC644 FF0FA530 */   andi      $a1, $a1, 0xFFF
    /* 43E48 800AC648 C6050696 */  lhu        $a2, 0x5C6($s0)
    /* 43E4C 800AC64C ADA7020C */  jal        func_800A9EB4
    /* 43E50 800AC650 21202002 */   addu      $a0, $s1, $zero
    /* 43E54 800AC654 9AB10208 */  j          .L800AC668
    /* 43E58 800AC658 00000000 */   nop
  .L800AC65C:
    /* 43E5C 800AC65C C6050696 */  lhu        $a2, 0x5C6($s0)
    /* 43E60 800AC660 14AA020C */  jal        func_800AA850
    /* 43E64 800AC664 21202002 */   addu      $a0, $s1, $zero
  .L800AC668:
    /* 43E68 800AC668 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 43E6C 800AC66C FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 43E70 800AC670 24104300 */  and        $v0, $v0, $v1
  .L800AC674:
    /* 43E74 800AC674 AC0502AE */  sw         $v0, 0x5AC($s0)
  .L800AC678:
    /* 43E78 800AC678 1800BF8F */  lw         $ra, 0x18($sp)
    /* 43E7C 800AC67C 1400B18F */  lw         $s1, 0x14($sp)
    /* 43E80 800AC680 1000B08F */  lw         $s0, 0x10($sp)
    /* 43E84 800AC684 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 43E88 800AC688 0800E003 */  jr         $ra
    /* 43E8C 800AC68C 00000000 */   nop
endlabel func_800AC540
