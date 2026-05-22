nonmatching func_8007D41C, 0x318

glabel func_8007D41C
    /* 14C1C 8007D41C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 14C20 8007D420 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14C24 8007D424 0F80103C */  lui        $s0, %hi(D_800F1ABC)
    /* 14C28 8007D428 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14C2C 8007D42C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 14C30 8007D430 2000B4AF */  sw         $s4, 0x20($sp)
    /* 14C34 8007D434 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 14C38 8007D438 1800B2AF */  sw         $s2, 0x18($sp)
    /* 14C3C 8007D43C 71AD000C */  jal        SetPolyFT4
    /* 14C40 8007D440 1400B1AF */   sw        $s1, 0x14($sp)
    /* 14C44 8007D444 0F80033C */  lui        $v1, %hi(D_800F1A78)
    /* 14C48 8007D448 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14C4C 8007D44C 781A6290 */  lbu        $v0, %lo(D_800F1A78)($v1)
    /* 14C50 8007D450 781A6324 */  addiu      $v1, $v1, %lo(D_800F1A78)
    /* 14C54 8007D454 040082A0 */  sb         $v0, 0x4($a0)
    /* 14C58 8007D458 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14C5C 8007D45C 01006290 */  lbu        $v0, 0x1($v1)
    /* 14C60 8007D460 00000000 */  nop
    /* 14C64 8007D464 050082A0 */  sb         $v0, 0x5($a0)
    /* 14C68 8007D468 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14C6C 8007D46C 02006290 */  lbu        $v0, 0x2($v1)
    /* 14C70 8007D470 00000000 */  nop
    /* 14C74 8007D474 060082A0 */  sb         $v0, 0x6($a0)
    /* 14C78 8007D478 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14C7C 8007D47C 5DAD000C */  jal        SetSemiTrans
    /* 14C80 8007D480 01000524 */   addiu     $a1, $zero, 0x1
    /* 14C84 8007D484 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14C88 8007D488 00000000 */  nop
    /* 14C8C 8007D48C 0C0040A0 */  sb         $zero, 0xC($v0)
    /* 14C90 8007D490 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14C94 8007D494 21880000 */  addu       $s1, $zero, $zero
    /* 14C98 8007D498 0D0040A0 */  sb         $zero, 0xD($v0)
    /* 14C9C 8007D49C BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14CA0 8007D4A0 40000424 */  addiu      $a0, $zero, 0x40
    /* 14CA4 8007D4A4 140044A0 */  sb         $a0, 0x14($v0)
    /* 14CA8 8007D4A8 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14CAC 8007D4AC 21980002 */  addu       $s3, $s0, $zero
    /* 14CB0 8007D4B0 150040A0 */  sb         $zero, 0x15($v0)
    /* 14CB4 8007D4B4 BC1A628E */  lw         $v0, %lo(D_800F1ABC)($s3)
    /* 14CB8 8007D4B8 DF001424 */  addiu      $s4, $zero, 0xDF
    /* 14CBC 8007D4BC 1C0040A0 */  sb         $zero, 0x1C($v0)
    /* 14CC0 8007D4C0 BC1A628E */  lw         $v0, %lo(D_800F1ABC)($s3)
    /* 14CC4 8007D4C4 21188002 */  addu       $v1, $s4, $zero
    /* 14CC8 8007D4C8 1D0043A0 */  sb         $v1, 0x1D($v0)
    /* 14CCC 8007D4CC BC1A628E */  lw         $v0, %lo(D_800F1ABC)($s3)
    /* 14CD0 8007D4D0 40001224 */  addiu      $s2, $zero, 0x40
    /* 14CD4 8007D4D4 240044A0 */  sb         $a0, 0x24($v0)
    /* 14CD8 8007D4D8 BC1A628E */  lw         $v0, %lo(D_800F1ABC)($s3)
    /* 14CDC 8007D4DC 21802002 */  addu       $s0, $s1, $zero
    /* 14CE0 8007D4E0 250043A0 */  sb         $v1, 0x25($v0)
  .L8007D4E4:
    /* 14CE4 8007D4E4 BC1A628E */  lw         $v0, %lo(D_800F1ABC)($s3)
    /* 14CE8 8007D4E8 00000000 */  nop
    /* 14CEC 8007D4EC 21380202 */  addu       $a3, $s0, $v0
    /* 14CF0 8007D4F0 21184000 */  addu       $v1, $v0, $zero
    /* 14CF4 8007D4F4 20006224 */  addiu      $v0, $v1, 0x20
  .L8007D4F8:
    /* 14CF8 8007D4F8 0000688C */  lw         $t0, 0x0($v1)
    /* 14CFC 8007D4FC 0400698C */  lw         $t1, 0x4($v1)
    /* 14D00 8007D500 08006A8C */  lw         $t2, 0x8($v1)
    /* 14D04 8007D504 0C006B8C */  lw         $t3, 0xC($v1)
    /* 14D08 8007D508 0000E8AC */  sw         $t0, 0x0($a3)
    /* 14D0C 8007D50C 0400E9AC */  sw         $t1, 0x4($a3)
    /* 14D10 8007D510 0800EAAC */  sw         $t2, 0x8($a3)
    /* 14D14 8007D514 0C00EBAC */  sw         $t3, 0xC($a3)
    /* 14D18 8007D518 10006324 */  addiu      $v1, $v1, 0x10
    /* 14D1C 8007D51C F6FF6214 */  bne        $v1, $v0, .L8007D4F8
    /* 14D20 8007D520 1000E724 */   addiu     $a3, $a3, 0x10
    /* 14D24 8007D524 02000424 */  addiu      $a0, $zero, 0x2
    /* 14D28 8007D528 21280000 */  addu       $a1, $zero, $zero
    /* 14D2C 8007D52C 80311100 */  sll        $a2, $s1, 6
    /* 14D30 8007D530 BC1A628E */  lw         $v0, %lo(D_800F1ABC)($s3)
    /* 14D34 8007D534 01003126 */  addiu      $s1, $s1, 0x1
    /* 14D38 8007D538 0000688C */  lw         $t0, 0x0($v1)
    /* 14D3C 8007D53C 0400698C */  lw         $t1, 0x4($v1)
    /* 14D40 8007D540 0000E8AC */  sw         $t0, 0x0($a3)
    /* 14D44 8007D544 0400E9AC */  sw         $t1, 0x4($a3)
    /* 14D48 8007D548 2138A000 */  addu       $a3, $a1, $zero
    /* 14D4C 8007D54C 21100202 */  addu       $v0, $s0, $v0
    /* 14D50 8007D550 080046A4 */  sh         $a2, 0x8($v0)
    /* 14D54 8007D554 0A0040A4 */  sh         $zero, 0xA($v0)
    /* 14D58 8007D558 100052A4 */  sh         $s2, 0x10($v0)
    /* 14D5C 8007D55C 120040A4 */  sh         $zero, 0x12($v0)
    /* 14D60 8007D560 180046A4 */  sh         $a2, 0x18($v0)
    /* 14D64 8007D564 1A0054A4 */  sh         $s4, 0x1A($v0)
    /* 14D68 8007D568 200052A4 */  sh         $s2, 0x20($v0)
    /* 14D6C 8007D56C 1DAD000C */  jal        GetTPage
    /* 14D70 8007D570 220054A4 */   sh        $s4, 0x22($v0)
    /* 14D74 8007D574 BC1A638E */  lw         $v1, %lo(D_800F1ABC)($s3)
    /* 14D78 8007D578 40005226 */  addiu      $s2, $s2, 0x40
    /* 14D7C 8007D57C 21187000 */  addu       $v1, $v1, $s0
    /* 14D80 8007D580 160062A4 */  sh         $v0, 0x16($v1)
    /* 14D84 8007D584 0A00222A */  slti       $v0, $s1, 0xA
    /* 14D88 8007D588 D6FF4014 */  bnez       $v0, .L8007D4E4
    /* 14D8C 8007D58C 28001026 */   addiu     $s0, $s0, 0x28
    /* 14D90 8007D590 0F80103C */  lui        $s0, %hi(D_800F1ABC)
    /* 14D94 8007D594 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14D98 8007D598 00000000 */  nop
    /* 14D9C 8007D59C AC0040A0 */  sb         $zero, 0xAC($v0)
    /* 14DA0 8007D5A0 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14DA4 8007D5A4 00000000 */  nop
    /* 14DA8 8007D5A8 AD0040A0 */  sb         $zero, 0xAD($v0)
    /* 14DAC 8007D5AC BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14DB0 8007D5B0 3F000424 */  addiu      $a0, $zero, 0x3F
    /* 14DB4 8007D5B4 B40044A0 */  sb         $a0, 0xB4($v0)
    /* 14DB8 8007D5B8 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14DBC 8007D5BC 00000000 */  nop
    /* 14DC0 8007D5C0 B50040A0 */  sb         $zero, 0xB5($v0)
    /* 14DC4 8007D5C4 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14DC8 8007D5C8 00000000 */  nop
    /* 14DCC 8007D5CC BC0040A0 */  sb         $zero, 0xBC($v0)
    /* 14DD0 8007D5D0 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14DD4 8007D5D4 DF000324 */  addiu      $v1, $zero, 0xDF
    /* 14DD8 8007D5D8 BD0043A0 */  sb         $v1, 0xBD($v0)
    /* 14DDC 8007D5DC BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14DE0 8007D5E0 00000000 */  nop
    /* 14DE4 8007D5E4 C40044A0 */  sb         $a0, 0xC4($v0)
    /* 14DE8 8007D5E8 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14DEC 8007D5EC 00000000 */  nop
    /* 14DF0 8007D5F0 C50043A0 */  sb         $v1, 0xC5($v0)
    /* 14DF4 8007D5F4 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14DF8 8007D5F8 00000000 */  nop
    /* 14DFC 8007D5FC 740140A0 */  sb         $zero, 0x174($v0)
    /* 14E00 8007D600 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14E04 8007D604 00000000 */  nop
    /* 14E08 8007D608 750140A0 */  sb         $zero, 0x175($v0)
    /* 14E0C 8007D60C BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14E10 8007D610 00000000 */  nop
    /* 14E14 8007D614 7C0144A0 */  sb         $a0, 0x17C($v0)
    /* 14E18 8007D618 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14E1C 8007D61C 00000000 */  nop
    /* 14E20 8007D620 7D0140A0 */  sb         $zero, 0x17D($v0)
    /* 14E24 8007D624 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14E28 8007D628 00000000 */  nop
    /* 14E2C 8007D62C 840140A0 */  sb         $zero, 0x184($v0)
    /* 14E30 8007D630 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14E34 8007D634 00000000 */  nop
    /* 14E38 8007D638 850143A0 */  sb         $v1, 0x185($v0)
    /* 14E3C 8007D63C BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14E40 8007D640 00000000 */  nop
    /* 14E44 8007D644 8C0144A0 */  sb         $a0, 0x18C($v0)
    /* 14E48 8007D648 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14E4C 8007D64C 00000000 */  nop
    /* 14E50 8007D650 8D0143A0 */  sb         $v1, 0x18D($v0)
    /* 14E54 8007D654 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14E58 8007D658 89AD000C */  jal        SetSprt
    /* 14E5C 8007D65C 90018424 */   addiu     $a0, $a0, 0x190
    /* 14E60 8007D660 0F80033C */  lui        $v1, %hi(D_800F1A78)
    /* 14E64 8007D664 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14E68 8007D668 781A6290 */  lbu        $v0, %lo(D_800F1A78)($v1)
    /* 14E6C 8007D66C 781A6324 */  addiu      $v1, $v1, %lo(D_800F1A78)
    /* 14E70 8007D670 940182A0 */  sb         $v0, 0x194($a0)
    /* 14E74 8007D674 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14E78 8007D678 01006290 */  lbu        $v0, 0x1($v1)
    /* 14E7C 8007D67C 00000000 */  nop
    /* 14E80 8007D680 950182A0 */  sb         $v0, 0x195($a0)
    /* 14E84 8007D684 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14E88 8007D688 02006290 */  lbu        $v0, 0x2($v1)
    /* 14E8C 8007D68C 00000000 */  nop
    /* 14E90 8007D690 960182A0 */  sb         $v0, 0x196($a0)
    /* 14E94 8007D694 BC1A048E */  lw         $a0, %lo(D_800F1ABC)($s0)
    /* 14E98 8007D698 01000524 */  addiu      $a1, $zero, 0x1
    /* 14E9C 8007D69C 5DAD000C */  jal        SetSemiTrans
    /* 14EA0 8007D6A0 90018424 */   addiu     $a0, $a0, 0x190
    /* 14EA4 8007D6A4 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14EA8 8007D6A8 21880000 */  addu       $s1, $zero, $zero
    /* 14EAC 8007D6AC 9C0140A0 */  sb         $zero, 0x19C($v0)
    /* 14EB0 8007D6B0 BC1A028E */  lw         $v0, %lo(D_800F1ABC)($s0)
    /* 14EB4 8007D6B4 21202002 */  addu       $a0, $s1, $zero
    /* 14EB8 8007D6B8 9D0140A0 */  sb         $zero, 0x19D($v0)
    /* 14EBC 8007D6BC BC1A038E */  lw         $v1, %lo(D_800F1ABC)($s0)
    /* 14EC0 8007D6C0 40000224 */  addiu      $v0, $zero, 0x40
    /* 14EC4 8007D6C4 A00162A4 */  sh         $v0, 0x1A0($v1)
    /* 14EC8 8007D6C8 DF000224 */  addiu      $v0, $zero, 0xDF
    /* 14ECC 8007D6CC A20162A4 */  sh         $v0, 0x1A2($v1)
  .L8007D6D0:
    /* 14ED0 8007D6D0 BC1A038E */  lw         $v1, %lo(D_800F1ABC)($s0)
    /* 14ED4 8007D6D4 01003126 */  addiu      $s1, $s1, 0x1
    /* 14ED8 8007D6D8 21108300 */  addu       $v0, $a0, $v1
    /* 14EDC 8007D6DC 9001688C */  lw         $t0, 0x190($v1)
    /* 14EE0 8007D6E0 9401698C */  lw         $t1, 0x194($v1)
    /* 14EE4 8007D6E4 98016A8C */  lw         $t2, 0x198($v1)
    /* 14EE8 8007D6E8 9C016B8C */  lw         $t3, 0x19C($v1)
    /* 14EEC 8007D6EC 900148AC */  sw         $t0, 0x190($v0)
    /* 14EF0 8007D6F0 940149AC */  sw         $t1, 0x194($v0)
    /* 14EF4 8007D6F4 98014AAC */  sw         $t2, 0x198($v0)
    /* 14EF8 8007D6F8 9C014BAC */  sw         $t3, 0x19C($v0)
    /* 14EFC 8007D6FC A001688C */  lw         $t0, 0x1A0($v1)
    /* 14F00 8007D700 00000000 */  nop
    /* 14F04 8007D704 A00148AC */  sw         $t0, 0x1A0($v0)
    /* 14F08 8007D708 0A00222A */  slti       $v0, $s1, 0xA
    /* 14F0C 8007D70C F0FF4014 */  bnez       $v0, .L8007D6D0
    /* 14F10 8007D710 14008424 */   addiu     $a0, $a0, 0x14
    /* 14F14 8007D714 2400BF8F */  lw         $ra, 0x24($sp)
    /* 14F18 8007D718 2000B48F */  lw         $s4, 0x20($sp)
    /* 14F1C 8007D71C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 14F20 8007D720 1800B28F */  lw         $s2, 0x18($sp)
    /* 14F24 8007D724 1400B18F */  lw         $s1, 0x14($sp)
    /* 14F28 8007D728 1000B08F */  lw         $s0, 0x10($sp)
    /* 14F2C 8007D72C 0800E003 */  jr         $ra
    /* 14F30 8007D730 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007D41C
