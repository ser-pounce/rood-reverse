/* Handwritten function */
nonmatching func_800B5C30, 0x77C

glabel func_800B5C30
    /* 4D430 800B5C30 801F083C */  lui        $t0, (0x1F800390 >> 16)
    /* 4D434 800B5C34 580310AD */  sw         $s0, (0x1F800358 & 0xFFFF)($t0)
    /* 4D438 800B5C38 5C0311AD */  sw         $s1, (0x1F80035C & 0xFFFF)($t0)
    /* 4D43C 800B5C3C 600312AD */  sw         $s2, (0x1F800360 & 0xFFFF)($t0)
    /* 4D440 800B5C40 640313AD */  sw         $s3, (0x1F800364 & 0xFFFF)($t0)
    /* 4D444 800B5C44 680314AD */  sw         $s4, (0x1F800368 & 0xFFFF)($t0)
    /* 4D448 800B5C48 6C0315AD */  sw         $s5, (0x1F80036C & 0xFFFF)($t0)
    /* 4D44C 800B5C4C 700316AD */  sw         $s6, (0x1F800370 & 0xFFFF)($t0)
    /* 4D450 800B5C50 740317AD */  sw         $s7, (0x1F800374 & 0xFFFF)($t0)
    /* 4D454 800B5C54 78031FAD */  sw         $ra, (0x1F800378 & 0xFFFF)($t0)
    /* 4D458 800B5C58 7C031CAD */  sw         $gp, (0x1F80037C & 0xFFFF)($t0)
    /* 4D45C 800B5C5C 80031EAD */  sw         $fp, (0x1F800380 & 0xFFFF)($t0)
    /* 4D460 800B5C60 90031C8D */  lw         $gp, (0x1F800390 & 0xFFFF)($t0)
    /* 4D464 800B5C64 FF00143C */  lui        $s4, (0xFFFFFF >> 16)
    /* 4D468 800B5C68 FFFF9436 */  ori        $s4, $s4, (0xFFFFFF & 0xFFFF)
    /* 4D46C 800B5C6C 00FC1C00 */  sll        $ra, $gp, 16
    /* 4D470 800B5C70 02E41C00 */  srl        $gp, $gp, 16
    /* 4D474 800B5C74 00E41C00 */  sll        $gp, $gp, 16
    /* 4D478 800B5C78 00FF153C */  lui        $s5, (0xFF000000 >> 16)
    /* 4D47C 800B5C7C 801F103C */  lui        $s0, (0x1F800392 >> 16)
    /* 4D480 800B5C80 0200B394 */  lhu        $s3, 0x2($a1)
    /* 4D484 800B5C84 3C00F28C */  lw         $s2, 0x3C($a3)
    /* 4D488 800B5C88 000C9E24 */  addiu      $fp, $a0, 0xC00
    /* 4D48C 800B5C8C 0000118E */  lw         $s1, (0x1F800000 & 0xFFFF)($s0)
    /* 4D490 800B5C90 0400178E */  lw         $s7, (0x1F800004 & 0xFFFF)($s0)
    /* 4D494 800B5C94 0000C68C */  lw         $a2, 0x0($a2)
    /* 4D498 800B5C98 FCFFF722 */  addi       $s7, $s7, -0x4 /* handwritten instruction */
    /* 4D49C 800B5C9C 6400B690 */  lbu        $s6, 0x64($a1)
    /* 4D4A0 800B5CA0 0900A390 */  lbu        $v1, 0x9($a1)
    /* 4D4A4 800B5CA4 2430D400 */  and        $a2, $a2, $s4
    /* 4D4A8 800B5CA8 0F006330 */  andi       $v1, $v1, 0xF
    /* 4D4AC 800B5CAC 05006010 */  beqz       $v1, .L800B5CC4
    /* 4D4B0 800B5CB0 25C80000 */   or        $t9, $zero, $zero
    /* 4D4B4 800B5CB4 07006328 */  slti       $v1, $v1, 0x7
    /* 4D4B8 800B5CB8 02006014 */  bnez       $v1, .L800B5CC4
    /* 4D4BC 800B5CBC 4000193C */   lui       $t9, (0x400000 >> 16)
    /* 4D4C0 800B5CC0 2000193C */  lui        $t9, (0x200000 >> 16)
  .L800B5CC4:
    /* 4D4C4 800B5CC4 09000834 */  ori        $t0, $zero, 0x9
    /* 4D4C8 800B5CC8 9C0308AE */  sw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4D4CC 800B5CCC 69006012 */  beqz       $s3, .L800B5E74
    /* 4D4D0 800B5CD0 0009183C */   lui       $t8, (0x9000000 >> 16)
  .L800B5CD4:
    /* 4D4D4 800B5CD4 9C03088E */  lw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4D4D8 800B5CD8 00000000 */  nop
    /* 4D4DC 800B5CDC 024C0800 */  srl        $t1, $t0, 16
    /* 4D4E0 800B5CE0 FFFF0831 */  andi       $t0, $t0, 0xFFFF
  .L800B5CE4:
    /* 4D4E4 800B5CE4 FFFF0821 */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* 4D4E8 800B5CE8 62000005 */  bltz       $t0, .L800B5E74
    /* 4D4EC 800B5CEC 9C0308A6 */   sh        $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4D4F0 800B5CF0 0E000011 */  beqz       $t0, .L800B5D2C
    /* 4D4F4 800B5CF4 FFFF0B21 */   addi      $t3, $t0, -0x1 /* handwritten instruction */
    /* 4D4F8 800B5CF8 0000F384 */  lh         $s3, 0x0($a3)
    /* 4D4FC 800B5CFC 0200E724 */  addiu      $a3, $a3, 0x2
    /* 4D500 800B5D00 20483301 */  add        $t1, $t1, $s3 /* handwritten instruction */
    /* 4D504 800B5D04 F7FF6012 */  beqz       $s3, .L800B5CE4
    /* 4D508 800B5D08 9E0309A6 */   sh        $t1, (0x1F80039E & 0xFFFF)($s0)
    /* 4D50C 800B5D0C 06507601 */  srlv       $t2, $s6, $t3
    /* 4D510 800B5D10 01004A31 */  andi       $t2, $t2, 0x1
    /* 4D514 800B5D14 92031C86 */  lh         $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4D518 800B5D18 08004011 */  beqz       $t2, .L800B5D3C
    /* 4D51C 800B5D1C 00000000 */   nop
    /* 4D520 800B5D20 80049C27 */  addiu      $gp, $gp, 0x480
    /* 4D524 800B5D24 50D70208 */  j          .L800B5D40
    /* 4D528 800B5D28 00E41C00 */   sll       $gp, $gp, 16
  .L800B5D2C:
    /* 4D52C 800B5D2C 0200B394 */  lhu        $s3, 0x2($a1)
    /* 4D530 800B5D30 92031C86 */  lh         $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4D534 800B5D34 22986902 */  sub        $s3, $s3, $t1 /* handwritten instruction */
    /* 4D538 800B5D38 4E006012 */  beqz       $s3, .L800B5E74
  .L800B5D3C:
    /* 4D53C 800B5D3C 00E41C00 */   sll       $gp, $gp, 16
  .L800B5D40:
    /* 4D540 800B5D40 4C006012 */  beqz       $s3, .L800B5E74
    /* 4D544 800B5D44 0009183C */   lui       $t8, (0x9000000 >> 16)
    /* 4D548 800B5D48 00004B8E */  lw         $t3, 0x0($s2)
  .L800B5D4C:
    /* 4D54C 800B5D4C 04004F8E */  lw         $t7, 0x4($s2)
    /* 4D550 800B5D50 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4D554 800B5D54 024C0B00 */  srl        $t1, $t3, 16
    /* 4D558 800B5D58 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4D55C 800B5D5C 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4D560 800B5D60 00008C8D */  lw         $t4, 0x0($t4)
    /* 4D564 800B5D64 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4D568 800B5D68 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4D56C 800B5D6C 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4D570 800B5D70 0000CE8D */  lw         $t6, 0x0($t6)
    /* 4D574 800B5D74 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4D578 800B5D78 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4D57C 800B5D7C 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4D580 800B5D80 027C0F00 */  srl        $t7, $t7, 16
    /* 4D584 800B5D84 20401E01 */  add        $t0, $t0, $fp /* handwritten instruction */
    /* 4D588 800B5D88 0600404B */  nclip
    /* 4D58C 800B5D8C 0800438E */  lw         $v1, 0x8($s2)
    /* 4D590 800B5D90 20483E01 */  add        $t1, $t1, $fp /* handwritten instruction */
    /* 4D594 800B5D94 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4D598 800B5D98 20505E01 */  add        $t2, $t2, $fp /* handwritten instruction */
    /* 4D59C 800B5D9C 0500401C */  bgtz       $v0, .L800B5DB4
    /* 4D5A0 800B5DA0 FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4D5A4 800B5DA4 CBFF6012 */  beqz       $s3, .L800B5CD4
    /* 4D5A8 800B5DA8 18005226 */   addiu     $s2, $s2, 0x18
    /* 4D5AC 800B5DAC 53D70208 */  j          .L800B5D4C
    /* 4D5B0 800B5DB0 00004B8E */   lw        $t3, 0x0($s2)
  .L800B5DB4:
    /* 4D5B4 800B5DB4 0000088D */  lw         $t0, 0x0($t0)
    /* 4D5B8 800B5DB8 0000298D */  lw         $t1, 0x0($t1)
    /* 4D5BC 800B5DBC 00004A8D */  lw         $t2, 0x0($t2)
    /* 4D5C0 800B5DC0 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4D5C4 800B5DC4 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4D5C8 800B5DC8 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4D5CC 800B5DCC 05002013 */  beqz       $t9, .L800B5DE4
    /* 4D5D0 800B5DD0 00360B3C */   lui       $t3, (0x36000000 >> 16)
    /* 4D5D4 800B5DD4 2518CB00 */  or         $v1, $a2, $t3
    /* 4D5D8 800B5DD8 25400600 */  or         $t0, $zero, $a2
    /* 4D5DC 800B5DDC 7BD70208 */  j          .L800B5DEC
    /* 4D5E0 800B5DE0 25480600 */   or        $t1, $zero, $a2
  .L800B5DE4:
    /* 4D5E4 800B5DE4 0C00488E */  lw         $t0, 0xC($s2)
    /* 4D5E8 800B5DE8 1000498E */  lw         $t1, 0x10($s2)
  .L800B5DEC:
    /* 4D5EC 800B5DEC 2D00584B */  avsz3
    /* 4D5F0 800B5DF0 14004B8E */  lw         $t3, 0x14($s2)
    /* 4D5F4 800B5DF4 040023AE */  sw         $v1, 0x4($s1)
    /* 4D5F8 800B5DF8 08002CAE */  sw         $t4, 0x8($s1)
    /* 4D5FC 800B5DFC 021C0B00 */  srl        $v1, $t3, 16
    /* 4D600 800B5E00 25187F00 */  or         $v1, $v1, $ra
    /* 4D604 800B5E04 25187900 */  or         $v1, $v1, $t9
    /* 4D608 800B5E08 FFFF6231 */  andi       $v0, $t3, 0xFFFF
    /* 4D60C 800B5E0C 25105C00 */  or         $v0, $v0, $gp
    /* 4D610 800B5E10 0C0022AE */  sw         $v0, 0xC($s1)
    /* 4D614 800B5E14 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4D618 800B5E18 100028AE */  sw         $t0, 0x10($s1)
    /* 4D61C 800B5E1C C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4D620 800B5E20 10000011 */  beqz       $t0, .L800B5E64
    /* 4D624 800B5E24 14002DAE */   sw        $t5, 0x14($s1)
    /* 4D628 800B5E28 80100200 */  sll        $v0, $v0, 2
    /* 4D62C 800B5E2C 180023AE */  sw         $v1, 0x18($s1)
    /* 4D630 800B5E30 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4D634 800B5E34 1C0029AE */  sw         $t1, 0x1C($s1)
    /* 4D638 800B5E38 00004A8C */  lw         $t2, 0x0($v0)
    /* 4D63C 800B5E3C 20002EAE */  sw         $t6, 0x20($s1)
    /* 4D640 800B5E40 24483402 */  and        $t1, $s1, $s4
    /* 4D644 800B5E44 24002FAE */  sw         $t7, 0x24($s1)
    /* 4D648 800B5E48 24405401 */  and        $t0, $t2, $s4
    /* 4D64C 800B5E4C 25401801 */  or         $t0, $t0, $t8
    /* 4D650 800B5E50 000028AE */  sw         $t0, 0x0($s1)
    /* 4D654 800B5E54 24405501 */  and        $t0, $t2, $s5
    /* 4D658 800B5E58 25400901 */  or         $t0, $t0, $t1
    /* 4D65C 800B5E5C 000048AC */  sw         $t0, 0x0($v0)
    /* 4D660 800B5E60 28003126 */  addiu      $s1, $s1, 0x28
  .L800B5E64:
    /* 4D664 800B5E64 9BFF6012 */  beqz       $s3, .L800B5CD4
    /* 4D668 800B5E68 18005226 */   addiu     $s2, $s2, 0x18
    /* 4D66C 800B5E6C 53D70208 */  j          .L800B5D4C
    /* 4D670 800B5E70 00004B8E */   lw        $t3, 0x0($s2)
  .L800B5E74:
    /* 4D674 800B5E74 09000834 */  ori        $t0, $zero, 0x9
    /* 4D678 800B5E78 9C0308AE */  sw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4D67C 800B5E7C 0400B394 */  lhu        $s3, 0x4($a1)
    /* 4D680 800B5E80 000C183C */  lui        $t8, (0xC000000 >> 16)
    /* 4D684 800B5E84 72006012 */  beqz       $s3, .L800B6050
  .L800B5E88:
    /* 4D688 800B5E88 801F103C */   lui       $s0, (0x1F800392 >> 16)
    /* 4D68C 800B5E8C 9C03088E */  lw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4D690 800B5E90 00000000 */  nop
    /* 4D694 800B5E94 024C0800 */  srl        $t1, $t0, 16
    /* 4D698 800B5E98 FFFF0831 */  andi       $t0, $t0, 0xFFFF
  .L800B5E9C:
    /* 4D69C 800B5E9C FFFF0821 */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* 4D6A0 800B5EA0 6B000005 */  bltz       $t0, .L800B6050
    /* 4D6A4 800B5EA4 9C0308A6 */   sh        $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4D6A8 800B5EA8 0F000011 */  beqz       $t0, .L800B5EE8
    /* 4D6AC 800B5EAC FFFF0B21 */   addi      $t3, $t0, -0x1 /* handwritten instruction */
    /* 4D6B0 800B5EB0 0000F384 */  lh         $s3, 0x0($a3)
    /* 4D6B4 800B5EB4 6400B690 */  lbu        $s6, 0x64($a1)
    /* 4D6B8 800B5EB8 0200E724 */  addiu      $a3, $a3, 0x2
    /* 4D6BC 800B5EBC 20483301 */  add        $t1, $t1, $s3 /* handwritten instruction */
    /* 4D6C0 800B5EC0 F6FF6012 */  beqz       $s3, .L800B5E9C
    /* 4D6C4 800B5EC4 9E0309A6 */   sh        $t1, (0x1F80039E & 0xFFFF)($s0)
    /* 4D6C8 800B5EC8 06507601 */  srlv       $t2, $s6, $t3
    /* 4D6CC 800B5ECC 01004A31 */  andi       $t2, $t2, 0x1
    /* 4D6D0 800B5ED0 92031C86 */  lh         $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4D6D4 800B5ED4 08004011 */  beqz       $t2, .L800B5EF8
    /* 4D6D8 800B5ED8 00000000 */   nop
    /* 4D6DC 800B5EDC 80049C27 */  addiu      $gp, $gp, 0x480
    /* 4D6E0 800B5EE0 BFD70208 */  j          .L800B5EFC
    /* 4D6E4 800B5EE4 00E41C00 */   sll       $gp, $gp, 16
  .L800B5EE8:
    /* 4D6E8 800B5EE8 0400B394 */  lhu        $s3, 0x4($a1)
    /* 4D6EC 800B5EEC 92031C86 */  lh         $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4D6F0 800B5EF0 22986902 */  sub        $s3, $s3, $t1 /* handwritten instruction */
    /* 4D6F4 800B5EF4 56006012 */  beqz       $s3, .L800B6050
  .L800B5EF8:
    /* 4D6F8 800B5EF8 00E41C00 */   sll       $gp, $gp, 16
  .L800B5EFC:
    /* 4D6FC 800B5EFC 00004B8E */  lw         $t3, 0x0($s2)
  .L800B5F00:
    /* 4D700 800B5F00 04004F8E */  lw         $t7, 0x4($s2)
    /* 4D704 800B5F04 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4D708 800B5F08 024C0B00 */  srl        $t1, $t3, 16
    /* 4D70C 800B5F0C FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4D710 800B5F10 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4D714 800B5F14 00008C8D */  lw         $t4, 0x0($t4)
    /* 4D718 800B5F18 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4D71C 800B5F1C 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4D720 800B5F20 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4D724 800B5F24 0000CE8D */  lw         $t6, 0x0($t6)
    /* 4D728 800B5F28 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4D72C 800B5F2C 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4D730 800B5F30 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4D734 800B5F34 025C0F00 */  srl        $t3, $t7, 16
    /* 4D738 800B5F38 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4D73C 800B5F3C 0600404B */  nclip
    /* 4D740 800B5F40 20401E01 */  add        $t0, $t0, $fp /* handwritten instruction */
    /* 4D744 800B5F44 20483E01 */  add        $t1, $t1, $fp /* handwritten instruction */
    /* 4D748 800B5F48 20505E01 */  add        $t2, $t2, $fp /* handwritten instruction */
    /* 4D74C 800B5F4C 0800438E */  lw         $v1, 0x8($s2)
    /* 4D750 800B5F50 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4D754 800B5F54 20587E01 */  add        $t3, $t3, $fp /* handwritten instruction */
    /* 4D758 800B5F58 0500401C */  bgtz       $v0, .L800B5F70
    /* 4D75C 800B5F5C FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4D760 800B5F60 C9FF6012 */  beqz       $s3, .L800B5E88
    /* 4D764 800B5F64 20005226 */   addiu     $s2, $s2, 0x20
    /* 4D768 800B5F68 C0D70208 */  j          .L800B5F00
    /* 4D76C 800B5F6C 00004B8E */   lw        $t3, 0x0($s2)
  .L800B5F70:
    /* 4D770 800B5F70 0000088D */  lw         $t0, 0x0($t0)
    /* 4D774 800B5F74 0000298D */  lw         $t1, 0x0($t1)
    /* 4D778 800B5F78 00004A8D */  lw         $t2, 0x0($t2)
    /* 4D77C 800B5F7C 00006B8D */  lw         $t3, 0x0($t3)
    /* 4D780 800B5F80 20100901 */  add        $v0, $t0, $t1 /* handwritten instruction */
    /* 4D784 800B5F84 20104A00 */  add        $v0, $v0, $t2 /* handwritten instruction */
    /* 4D788 800B5F88 20104B00 */  add        $v0, $v0, $t3 /* handwritten instruction */
    /* 4D78C 800B5F8C 02110200 */  srl        $v0, $v0, 4
    /* 4D790 800B5F90 C007502C */  sltiu      $s0, $v0, 0x7C0
    /* 4D794 800B5F94 2A000012 */  beqz       $s0, .L800B6040
    /* 4D798 800B5F98 0000EF8D */   lw        $t7, 0x0($t7)
    /* 4D79C 800B5F9C 06002013 */  beqz       $t9, .L800B5FB8
    /* 4D7A0 800B5FA0 003E0B3C */   lui       $t3, (0x3E000000 >> 16)
    /* 4D7A4 800B5FA4 2518CB00 */  or         $v1, $a2, $t3
    /* 4D7A8 800B5FA8 25800600 */  or         $s0, $zero, $a2
    /* 4D7AC 800B5FAC 25B00600 */  or         $s6, $zero, $a2
    /* 4D7B0 800B5FB0 F1D70208 */  j          .L800B5FC4
    /* 4D7B4 800B5FB4 25580600 */   or        $t3, $zero, $a2
  .L800B5FB8:
    /* 4D7B8 800B5FB8 0C00508E */  lw         $s0, 0xC($s2)
    /* 4D7BC 800B5FBC 1000568E */  lw         $s6, 0x10($s2)
    /* 4D7C0 800B5FC0 14004B8E */  lw         $t3, 0x14($s2)
  .L800B5FC4:
    /* 4D7C4 800B5FC4 1800488E */  lw         $t0, 0x18($s2)
    /* 4D7C8 800B5FC8 1C004A8E */  lw         $t2, 0x1C($s2)
    /* 4D7CC 800B5FCC 024C0800 */  srl        $t1, $t0, 16
    /* 4D7D0 800B5FD0 25483F01 */  or         $t1, $t1, $ra
    /* 4D7D4 800B5FD4 25483901 */  or         $t1, $t1, $t9
    /* 4D7D8 800B5FD8 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4D7DC 800B5FDC 25401C01 */  or         $t0, $t0, $gp
    /* 4D7E0 800B5FE0 040023AE */  sw         $v1, 0x4($s1)
    /* 4D7E4 800B5FE4 08002CAE */  sw         $t4, 0x8($s1)
    /* 4D7E8 800B5FE8 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4D7EC 800B5FEC 100030AE */  sw         $s0, 0x10($s1)
    /* 4D7F0 800B5FF0 14002DAE */  sw         $t5, 0x14($s1)
    /* 4D7F4 800B5FF4 021C0A00 */  srl        $v1, $t2, 16
    /* 4D7F8 800B5FF8 180029AE */  sw         $t1, 0x18($s1)
    /* 4D7FC 800B5FFC 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 4D800 800B6000 80100200 */  sll        $v0, $v0, 2
    /* 4D804 800B6004 20002EAE */  sw         $t6, 0x20($s1)
    /* 4D808 800B6008 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4D80C 800B600C 24002AAE */  sw         $t2, 0x24($s1)
    /* 4D810 800B6010 0000508C */  lw         $s0, 0x0($v0)
    /* 4D814 800B6014 28002BAE */  sw         $t3, 0x28($s1)
    /* 4D818 800B6018 24483402 */  and        $t1, $s1, $s4
    /* 4D81C 800B601C 2C002FAE */  sw         $t7, 0x2C($s1)
    /* 4D820 800B6020 24401402 */  and        $t0, $s0, $s4
    /* 4D824 800B6024 300023AE */  sw         $v1, 0x30($s1)
    /* 4D828 800B6028 25401801 */  or         $t0, $t0, $t8
    /* 4D82C 800B602C 000028AE */  sw         $t0, 0x0($s1)
    /* 4D830 800B6030 24401502 */  and        $t0, $s0, $s5
    /* 4D834 800B6034 25400901 */  or         $t0, $t0, $t1
    /* 4D838 800B6038 000048AC */  sw         $t0, 0x0($v0)
    /* 4D83C 800B603C 34003126 */  addiu      $s1, $s1, 0x34
  .L800B6040:
    /* 4D840 800B6040 91FF6012 */  beqz       $s3, .L800B5E88
    /* 4D844 800B6044 20005226 */   addiu     $s2, $s2, 0x20
    /* 4D848 800B6048 C0D70208 */  j          .L800B5F00
    /* 4D84C 800B604C 00004B8E */   lw        $t3, 0x0($s2)
  .L800B6050:
    /* 4D850 800B6050 09000834 */  ori        $t0, $zero, 0x9
    /* 4D854 800B6054 9C0308AE */  sw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4D858 800B6058 A00305AE */  sw         $a1, (0x1F8003A0 & 0xFFFF)($s0)
    /* 4D85C 800B605C 0600B394 */  lhu        $s3, 0x6($a1)
    /* 4D860 800B6060 F0FFF722 */  addi       $s7, $s7, -0x10 /* handwritten instruction */
    /* 4D864 800B6064 C3006012 */  beqz       $s3, .L800B6374
    /* 4D868 800B6068 2528C003 */   or        $a1, $fp, $zero
  .L800B606C:
    /* 4D86C 800B606C 801F103C */  lui        $s0, (0x1F800392 >> 16)
    /* 4D870 800B6070 9C03088E */  lw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4D874 800B6074 A0030C8E */  lw         $t4, (0x1F8003A0 & 0xFFFF)($s0)
    /* 4D878 800B6078 024C0800 */  srl        $t1, $t0, 16
    /* 4D87C 800B607C FFFF0831 */  andi       $t0, $t0, 0xFFFF
  .L800B6080:
    /* 4D880 800B6080 FFFF0821 */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* 4D884 800B6084 BB000005 */  bltz       $t0, .L800B6374
    /* 4D888 800B6088 9C0308A6 */   sh        $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4D88C 800B608C 10000011 */  beqz       $t0, .L800B60D0
    /* 4D890 800B6090 FFFF0B21 */   addi      $t3, $t0, -0x1 /* handwritten instruction */
    /* 4D894 800B6094 0000F394 */  lhu        $s3, 0x0($a3)
    /* 4D898 800B6098 0200E724 */  addiu      $a3, $a3, 0x2
    /* 4D89C 800B609C 20483301 */  add        $t1, $t1, $s3 /* handwritten instruction */
    /* 4D8A0 800B60A0 F7FF6012 */  beqz       $s3, .L800B6080
    /* 4D8A4 800B60A4 9E0309A6 */   sh        $t1, (0x1F80039E & 0xFFFF)($s0)
    /* 4D8A8 800B60A8 64009691 */  lbu        $s6, 0x64($t4)
    /* 4D8AC 800B60AC 00000000 */  nop
    /* 4D8B0 800B60B0 06507601 */  srlv       $t2, $s6, $t3
    /* 4D8B4 800B60B4 01004A31 */  andi       $t2, $t2, 0x1
    /* 4D8B8 800B60B8 92031C96 */  lhu        $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4D8BC 800B60BC 08004011 */  beqz       $t2, .L800B60E0
    /* 4D8C0 800B60C0 00000000 */   nop
    /* 4D8C4 800B60C4 80049C27 */  addiu      $gp, $gp, 0x480
    /* 4D8C8 800B60C8 39D80208 */  j          .L800B60E4
    /* 4D8CC 800B60CC 00E41C00 */   sll       $gp, $gp, 16
  .L800B60D0:
    /* 4D8D0 800B60D0 06009395 */  lhu        $s3, 0x6($t4)
    /* 4D8D4 800B60D4 92031C96 */  lhu        $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4D8D8 800B60D8 22986902 */  sub        $s3, $s3, $t1 /* handwritten instruction */
    /* 4D8DC 800B60DC A5006012 */  beqz       $s3, .L800B6374
  .L800B60E0:
    /* 4D8E0 800B60E0 00E41C00 */   sll       $gp, $gp, 16
  .L800B60E4:
    /* 4D8E4 800B60E4 10005E8E */  lw         $fp, 0x10($s2)
  .L800B60E8:
    /* 4D8E8 800B60E8 00004B8E */  lw         $t3, 0x0($s2)
    /* 4D8EC 800B60EC 021E1E00 */  srl        $v1, $fp, 24
    /* 4D8F0 800B60F0 01006230 */  andi       $v0, $v1, 0x1
    /* 4D8F4 800B60F4 04004F8E */  lw         $t7, 0x4($s2)
    /* 4D8F8 800B60F8 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4D8FC 800B60FC 024C0B00 */  srl        $t1, $t3, 16
    /* 4D900 800B6100 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4D904 800B6104 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4D908 800B6108 00008C8D */  lw         $t4, 0x0($t4)
    /* 4D90C 800B610C 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4D910 800B6110 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4D914 800B6114 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4D918 800B6118 15004014 */  bnez       $v0, .L800B6170
    /* 4D91C 800B611C 0000CE8D */   lw        $t6, 0x0($t6)
    /* 4D920 800B6120 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4D924 800B6124 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4D928 800B6128 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4D92C 800B612C 025C0F00 */  srl        $t3, $t7, 16
    /* 4D930 800B6130 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4D934 800B6134 0600404B */  nclip
    /* 4D938 800B6138 20400501 */  add        $t0, $t0, $a1 /* handwritten instruction */
    /* 4D93C 800B613C 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 4D940 800B6140 20504501 */  add        $t2, $t2, $a1 /* handwritten instruction */
    /* 4D944 800B6144 20586501 */  add        $t3, $t3, $a1 /* handwritten instruction */
    /* 4D948 800B6148 0800588E */  lw         $t8, 0x8($s2)
    /* 4D94C 800B614C 0C00508E */  lw         $s0, 0xC($s2)
    /* 4D950 800B6150 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4D954 800B6154 02861000 */  srl        $s0, $s0, 24
    /* 4D958 800B6158 0E00401C */  bgtz       $v0, .L800B6194
    /* 4D95C 800B615C FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4D960 800B6160 C2FF6012 */  beqz       $s3, .L800B606C
    /* 4D964 800B6164 20905002 */   add       $s2, $s2, $s0 /* handwritten instruction */
    /* 4D968 800B6168 3AD80208 */  j          .L800B60E8
    /* 4D96C 800B616C 00005E8E */   lw        $fp, 0x0($s2)
  .L800B6170:
    /* 4D970 800B6170 FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 4D974 800B6174 025C0F00 */  srl        $t3, $t7, 16
    /* 4D978 800B6178 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4D97C 800B617C 20400501 */  add        $t0, $t0, $a1 /* handwritten instruction */
    /* 4D980 800B6180 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 4D984 800B6184 20504501 */  add        $t2, $t2, $a1 /* handwritten instruction */
    /* 4D988 800B6188 20586501 */  add        $t3, $t3, $a1 /* handwritten instruction */
    /* 4D98C 800B618C 0800588E */  lw         $t8, 0x8($s2)
    /* 4D990 800B6190 00000000 */  nop
  .L800B6194:
    /* 4D994 800B6194 02861800 */  srl        $s0, $t8, 24
    /* 4D998 800B6198 0000088D */  lw         $t0, 0x0($t0)
    /* 4D99C 800B619C 3C000234 */  ori        $v0, $zero, 0x3C
    /* 4D9A0 800B61A0 0000298D */  lw         $t1, 0x0($t1)
    /* 4D9A4 800B61A4 37000212 */  beq        $s0, $v0, .L800B6284
    /* 4D9A8 800B61A8 00004A8D */   lw        $t2, 0x0($t2)
    /* 4D9AC 800B61AC 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4D9B0 800B61B0 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4D9B4 800B61B4 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4D9B8 800B61B8 07002013 */  beqz       $t9, .L800B61D8
    /* 4D9BC 800B61BC 0036033C */   lui       $v1, (0x36000000 >> 16)
    /* 4D9C0 800B61C0 1000498E */  lw         $t1, 0x10($s2)
    /* 4D9C4 800B61C4 25C0C300 */  or         $t8, $a2, $v1
    /* 4D9C8 800B61C8 25400600 */  or         $t0, $zero, $a2
    /* 4D9CC 800B61CC 24483501 */  and        $t1, $t1, $s5
    /* 4D9D0 800B61D0 78D80208 */  j          .L800B61E0
    /* 4D9D4 800B61D4 25482601 */   or        $t1, $t1, $a2
  .L800B61D8:
    /* 4D9D8 800B61D8 0C00488E */  lw         $t0, 0xC($s2)
    /* 4D9DC 800B61DC 1000498E */  lw         $t1, 0x10($s2)
  .L800B61E0:
    /* 4D9E0 800B61E0 2D00584B */  avsz3
    /* 4D9E4 800B61E4 040038AE */  sw         $t8, 0x4($s1)
    /* 4D9E8 800B61E8 14004B8E */  lw         $t3, 0x14($s2)
    /* 4D9EC 800B61EC 0400588E */  lw         $t8, 0x4($s2)
    /* 4D9F0 800B61F0 02540B00 */  srl        $t2, $t3, 16
    /* 4D9F4 800B61F4 02C41800 */  srl        $t8, $t8, 16
    /* 4D9F8 800B61F8 25505F01 */  or         $t2, $t2, $ra
    /* 4D9FC 800B61FC 25505901 */  or         $t2, $t2, $t9
    /* 4DA00 800B6200 FFFF6F31 */  andi       $t7, $t3, 0xFFFF
    /* 4DA04 800B6204 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4DA08 800B6208 08002CAE */  sw         $t4, 0x8($s1)
    /* 4DA0C 800B620C C0074C2C */  sltiu      $t4, $v0, 0x7C0
    /* 4DA10 800B6210 18008011 */  beqz       $t4, .L800B6274
    /* 4DA14 800B6214 2578FC01 */   or        $t7, $t7, $gp
    /* 4DA18 800B6218 0C002FAE */  sw         $t7, 0xC($s1)
    /* 4DA1C 800B621C 100028AE */  sw         $t0, 0x10($s1)
    /* 4DA20 800B6220 821E0900 */  srl        $v1, $t1, 26
    /* 4DA24 800B6224 14002DAE */  sw         $t5, 0x14($s1)
    /* 4DA28 800B6228 03006330 */  andi       $v1, $v1, 0x3
    /* 4DA2C 800B622C 18002AAE */  sw         $t2, 0x18($s1)
    /* 4DA30 800B6230 80180300 */  sll        $v1, $v1, 2
    /* 4DA34 800B6234 1C0029AE */  sw         $t1, 0x1C($s1)
    /* 4DA38 800B6238 20104300 */  add        $v0, $v0, $v1 /* handwritten instruction */
    /* 4DA3C 800B623C 20002EAE */  sw         $t6, 0x20($s1)
    /* 4DA40 800B6240 80100200 */  sll        $v0, $v0, 2
    /* 4DA44 800B6244 240038AE */  sw         $t8, 0x24($s1)
    /* 4DA48 800B6248 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4DA4C 800B624C 0000438C */  lw         $v1, 0x0($v0)
    /* 4DA50 800B6250 0009183C */  lui        $t8, (0x9000000 >> 16)
    /* 4DA54 800B6254 24407400 */  and        $t0, $v1, $s4
    /* 4DA58 800B6258 25401801 */  or         $t0, $t0, $t8
    /* 4DA5C 800B625C 000028AE */  sw         $t0, 0x0($s1)
    /* 4DA60 800B6260 24483402 */  and        $t1, $s1, $s4
    /* 4DA64 800B6264 24407500 */  and        $t0, $v1, $s5
    /* 4DA68 800B6268 25400901 */  or         $t0, $t0, $t1
    /* 4DA6C 800B626C 000048AC */  sw         $t0, 0x0($v0)
    /* 4DA70 800B6270 28003126 */  addiu      $s1, $s1, 0x28
  .L800B6274:
    /* 4DA74 800B6274 7DFF6012 */  beqz       $s3, .L800B606C
    /* 4DA78 800B6278 18005226 */   addiu     $s2, $s2, 0x18
    /* 4DA7C 800B627C 3AD80208 */  j          .L800B60E8
    /* 4DA80 800B6280 10005E8E */   lw        $fp, 0x10($s2)
  .L800B6284:
    /* 4DA84 800B6284 00006B8D */  lw         $t3, 0x0($t3)
    /* 4DA88 800B6288 20100901 */  add        $v0, $t0, $t1 /* handwritten instruction */
    /* 4DA8C 800B628C 0000EF8D */  lw         $t7, 0x0($t7)
    /* 4DA90 800B6290 20104A00 */  add        $v0, $v0, $t2 /* handwritten instruction */
    /* 4DA94 800B6294 20104B00 */  add        $v0, $v0, $t3 /* handwritten instruction */
    /* 4DA98 800B6298 02110200 */  srl        $v0, $v0, 4
    /* 4DA9C 800B629C C007502C */  sltiu      $s0, $v0, 0x7C0
    /* 4DAA0 800B62A0 30000012 */  beqz       $s0, .L800B6364
    /* 4DAA4 800B62A4 003E033C */   lui       $v1, (0x3E000000 >> 16)
    /* 4DAA8 800B62A8 07002013 */  beqz       $t9, .L800B62C8
    /* 4DAAC 800B62AC 25B00600 */   or        $s6, $zero, $a2
    /* 4DAB0 800B62B0 1000508E */  lw         $s0, 0x10($s2)
    /* 4DAB4 800B62B4 25C0C300 */  or         $t8, $a2, $v1
    /* 4DAB8 800B62B8 25180600 */  or         $v1, $zero, $a2
    /* 4DABC 800B62BC 24801502 */  and        $s0, $s0, $s5
    /* 4DAC0 800B62C0 B5D80208 */  j          .L800B62D4
    /* 4DAC4 800B62C4 25800602 */   or        $s0, $s0, $a2
  .L800B62C8:
    /* 4DAC8 800B62C8 0C00438E */  lw         $v1, 0xC($s2)
    /* 4DACC 800B62CC 1000508E */  lw         $s0, 0x10($s2)
    /* 4DAD0 800B62D0 1400568E */  lw         $s6, 0x14($s2)
  .L800B62D4:
    /* 4DAD4 800B62D4 1800488E */  lw         $t0, 0x18($s2)
    /* 4DAD8 800B62D8 1C004A8E */  lw         $t2, 0x1C($s2)
    /* 4DADC 800B62DC 024C0800 */  srl        $t1, $t0, 16
    /* 4DAE0 800B62E0 25483F01 */  or         $t1, $t1, $ra
    /* 4DAE4 800B62E4 25483901 */  or         $t1, $t1, $t9
    /* 4DAE8 800B62E8 040038AE */  sw         $t8, 0x4($s1)
    /* 4DAEC 800B62EC FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4DAF0 800B62F0 08002CAE */  sw         $t4, 0x8($s1)
    /* 4DAF4 800B62F4 25401C01 */  or         $t0, $t0, $gp
    /* 4DAF8 800B62F8 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4DAFC 800B62FC 100023AE */  sw         $v1, 0x10($s1)
    /* 4DB00 800B6300 025C0A00 */  srl        $t3, $t2, 16
    /* 4DB04 800B6304 14002DAE */  sw         $t5, 0x14($s1)
    /* 4DB08 800B6308 180029AE */  sw         $t1, 0x18($s1)
    /* 4DB0C 800B630C 821E1000 */  srl        $v1, $s0, 26
    /* 4DB10 800B6310 1C0030AE */  sw         $s0, 0x1C($s1)
    /* 4DB14 800B6314 03006330 */  andi       $v1, $v1, 0x3
    /* 4DB18 800B6318 20002EAE */  sw         $t6, 0x20($s1)
    /* 4DB1C 800B631C 80180300 */  sll        $v1, $v1, 2
    /* 4DB20 800B6320 24002AAE */  sw         $t2, 0x24($s1)
    /* 4DB24 800B6324 20104300 */  add        $v0, $v0, $v1 /* handwritten instruction */
    /* 4DB28 800B6328 280036AE */  sw         $s6, 0x28($s1)
    /* 4DB2C 800B632C 2C002FAE */  sw         $t7, 0x2C($s1)
    /* 4DB30 800B6330 80100200 */  sll        $v0, $v0, 2
    /* 4DB34 800B6334 30002BAE */  sw         $t3, 0x30($s1)
    /* 4DB38 800B6338 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4DB3C 800B633C 0000438C */  lw         $v1, 0x0($v0)
    /* 4DB40 800B6340 000C183C */  lui        $t8, (0xC000000 >> 16)
    /* 4DB44 800B6344 24407400 */  and        $t0, $v1, $s4
    /* 4DB48 800B6348 25401801 */  or         $t0, $t0, $t8
    /* 4DB4C 800B634C 000028AE */  sw         $t0, 0x0($s1)
    /* 4DB50 800B6350 24483402 */  and        $t1, $s1, $s4
    /* 4DB54 800B6354 24407500 */  and        $t0, $v1, $s5
    /* 4DB58 800B6358 25400901 */  or         $t0, $t0, $t1
    /* 4DB5C 800B635C 000048AC */  sw         $t0, 0x0($v0)
    /* 4DB60 800B6360 34003126 */  addiu      $s1, $s1, 0x34
  .L800B6364:
    /* 4DB64 800B6364 41FF6012 */  beqz       $s3, .L800B606C
    /* 4DB68 800B6368 20005226 */   addiu     $s2, $s2, 0x20
    /* 4DB6C 800B636C 3AD80208 */  j          .L800B60E8
    /* 4DB70 800B6370 10005E8E */   lw        $fp, 0x10($s2)
  .L800B6374:
    /* 4DB74 800B6374 801F083C */  lui        $t0, (0x1F800380 >> 16)
    /* 4DB78 800B6378 000011AD */  sw         $s1, (0x1F800000 & 0xFFFF)($t0)
    /* 4DB7C 800B637C 5803108D */  lw         $s0, (0x1F800358 & 0xFFFF)($t0)
    /* 4DB80 800B6380 5C03118D */  lw         $s1, (0x1F80035C & 0xFFFF)($t0)
    /* 4DB84 800B6384 6003128D */  lw         $s2, (0x1F800360 & 0xFFFF)($t0)
    /* 4DB88 800B6388 6403138D */  lw         $s3, (0x1F800364 & 0xFFFF)($t0)
    /* 4DB8C 800B638C 6803148D */  lw         $s4, (0x1F800368 & 0xFFFF)($t0)
    /* 4DB90 800B6390 6C03158D */  lw         $s5, (0x1F80036C & 0xFFFF)($t0)
    /* 4DB94 800B6394 7003168D */  lw         $s6, (0x1F800370 & 0xFFFF)($t0)
    /* 4DB98 800B6398 7403178D */  lw         $s7, (0x1F800374 & 0xFFFF)($t0)
    /* 4DB9C 800B639C 78031F8D */  lw         $ra, (0x1F800378 & 0xFFFF)($t0)
    /* 4DBA0 800B63A0 7C031C8D */  lw         $gp, (0x1F80037C & 0xFFFF)($t0)
    /* 4DBA4 800B63A4 0800E003 */  jr         $ra
    /* 4DBA8 800B63A8 80031E8D */   lw        $fp, (0x1F800380 & 0xFFFF)($t0)
endlabel func_800B5C30
