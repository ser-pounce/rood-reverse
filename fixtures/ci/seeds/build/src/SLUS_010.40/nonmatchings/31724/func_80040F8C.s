/* Handwritten function */
nonmatching func_80040F8C, 0x178

glabel func_80040F8C
    /* 3178C 80040F8C 0000828C */  lw         $v0, 0x0($a0)
    /* 31790 80040F90 0400988C */  lw         $t8, 0x4($a0)
    /* 31794 80040F94 0480063C */  lui        $a2, %hi(_trig_table)
    /* 31798 80040F98 1002C624 */  addiu      $a2, $a2, %lo(_trig_table)
    /* 3179C 80040F9C 04800F3C */  lui        $t7, %hi(func_80041104)
    /* 317A0 80040FA0 0411EF25 */  addiu      $t7, $t7, %lo(func_80041104)
    /* 317A4 80040FA4 0008C724 */  addiu      $a3, $a2, 0x800
  alabel D_80040FA8
    /* 317A8 80040FA8 02491800 */  srl        $t1, $t8, 4
    /* 317AC 80040FAC E0002931 */  andi       $t1, $t1, 0xE0
    /* 317B0 80040FB0 21482F01 */  addu       $t1, $t1, $t7
    /* 317B4 80040FB4 0480193C */  lui        $t9, %hi(D_80040FA8)
    /* 317B8 80040FB8 A80F3927 */  addiu      $t9, $t9, %lo(D_80040FA8)
    /* 317BC 80040FBC 80C01800 */  sll        $t8, $t8, 2
    /* 317C0 80040FC0 08002001 */  jr         $t1
    /* 317C4 80040FC4 FC071833 */   andi      $t8, $t8, 0x7FC
    /* 317C8 80040FC8 40600800 */  sll        $t4, $t0, 1
    /* 317CC 80040FCC 40680900 */  sll        $t5, $t1, 1
    /* 317D0 80040FD0 82C30200 */  srl        $t8, $v0, 14
    /* 317D4 80040FD4 82491800 */  srl        $t1, $t8, 6
    /* 317D8 80040FD8 E0002931 */  andi       $t1, $t1, 0xE0
    /* 317DC 80040FDC 21482F01 */  addu       $t1, $t1, $t7
    /* 317E0 80040FE0 08002001 */  jr         $t1
    /* 317E4 80040FE4 FC071833 */   andi      $t8, $t8, 0x7FC
    /* 317E8 80040FE8 40500800 */  sll        $t2, $t0, 1
    /* 317EC 80040FEC 40580900 */  sll        $t3, $t1, 1
    /* 317F0 80040FF0 80C00200 */  sll        $t8, $v0, 2
    /* 317F4 80040FF4 82491800 */  srl        $t1, $t8, 6
    /* 317F8 80040FF8 E0002931 */  andi       $t1, $t1, 0xE0
    /* 317FC 80040FFC 21482F01 */  addu       $t1, $t1, $t7
    /* 31800 80041000 08002001 */  jr         $t1
    /* 31804 80041004 FC071833 */   andi      $t8, $t8, 0x7FC
    /* 31808 80041008 00408C48 */  mtc2       $t4, $8 /* handwritten instruction */
    /* 3180C 8004100C 00488A48 */  mtc2       $t2, $9 /* handwritten instruction */
    /* 31810 80041010 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 31814 80041014 00588948 */  mtc2       $t1, $11 /* handwritten instruction */
    /* 31818 80041018 18002A01 */  mult       $t1, $t2
    /* 3181C 8004101C 21100500 */  addu       $v0, $zero, $a1
    /* 31820 80041020 3D00984B */  gpf        1
    /* 31824 80041024 23C00800 */  negu       $t8, $t0
    /* 31828 80041028 00C41800 */  sll        $t8, $t8, 16
    /* 3182C 8004102C 00480448 */  mfc2       $a0, $9 /* handwritten instruction */
    /* 31830 80041030 00500548 */  mfc2       $a1, $10 /* handwritten instruction */
    /* 31834 80041034 00580C48 */  mfc2       $t4, $11 /* handwritten instruction */
    /* 31838 80041038 00408D48 */  mtc2       $t5, $8 /* handwritten instruction */
    /* 3183C 8004103C 00488A48 */  mtc2       $t2, $9 /* handwritten instruction */
    /* 31840 80041040 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 31844 80041044 00588948 */  mtc2       $t1, $11 /* handwritten instruction */
    /* 31848 80041048 43600C00 */  sra        $t4, $t4, 1
    /* 3184C 8004104C 00640C00 */  sll        $t4, $t4, 16
    /* 31850 80041050 3D00984B */  gpf        1
    /* 31854 80041054 12780000 */  mflo       $t7
    /* 31858 80041058 437B0F00 */  sra        $t7, $t7, 13
    /* 3185C 8004105C FFFFEF31 */  andi       $t7, $t7, 0xFFFF
    /* 31860 80041060 18002B01 */  mult       $t1, $t3
    /* 31864 80041064 25608F01 */  or         $t4, $t4, $t7
    /* 31868 80041068 04004CAC */  sw         $t4, 0x4($v0)
    /* 3186C 8004106C 00480648 */  mfc2       $a2, $9 /* handwritten instruction */
    /* 31870 80041070 00500748 */  mfc2       $a3, $10 /* handwritten instruction */
    /* 31874 80041074 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 31878 80041078 00408848 */  mtc2       $t0, $8 /* handwritten instruction */
    /* 3187C 8004107C 00488448 */  mtc2       $a0, $9 /* handwritten instruction */
    /* 31880 80041080 00508648 */  mtc2       $a2, $10 /* handwritten instruction */
    /* 31884 80041084 00588548 */  mtc2       $a1, $11 /* handwritten instruction */
    /* 31888 80041088 43680D00 */  sra        $t5, $t5, 1
    /* 3188C 8004108C FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 31890 80041090 3D00984B */  gpf        1
    /* 31894 80041094 2568B801 */  or         $t5, $t5, $t8
    /* 31898 80041098 08004DAC */  sw         $t5, 0x8($v0)
    /* 3189C 8004109C 12780000 */  mflo       $t7
    /* 318A0 800410A0 437B0F00 */  sra        $t7, $t7, 13
    /* 318A4 800410A4 10004FA4 */  sh         $t7, 0x10($v0)
    /* 318A8 800410A8 18000701 */  mult       $t0, $a3
    /* 318AC 800410AC 00480A48 */  mfc2       $t2, $9 /* handwritten instruction */
    /* 318B0 800410B0 00500B48 */  mfc2       $t3, $10 /* handwritten instruction */
    /* 318B4 800410B4 00580C48 */  mfc2       $t4, $11 /* handwritten instruction */
    /* 318B8 800410B8 21504701 */  addu       $t2, $t2, $a3
    /* 318BC 800410BC 23586501 */  subu       $t3, $t3, $a1
    /* 318C0 800410C0 23608601 */  subu       $t4, $t4, $a2
    /* 318C4 800410C4 83500A00 */  sra        $t2, $t2, 2
    /* 318C8 800410C8 FFFF4A31 */  andi       $t2, $t2, 0xFFFF
    /* 318CC 800410CC 83580B00 */  sra        $t3, $t3, 2
    /* 318D0 800410D0 005C0B00 */  sll        $t3, $t3, 16
    /* 318D4 800410D4 25504B01 */  or         $t2, $t2, $t3
    /* 318D8 800410D8 00004AAC */  sw         $t2, 0x0($v0)
    /* 318DC 800410DC 83600C00 */  sra        $t4, $t4, 2
    /* 318E0 800410E0 FFFF8C31 */  andi       $t4, $t4, 0xFFFF
    /* 318E4 800410E4 12680000 */  mflo       $t5
    /* 318E8 800410E8 036B0D00 */  sra        $t5, $t5, 12
    /* 318EC 800410EC 2168A401 */  addu       $t5, $t5, $a0
    /* 318F0 800410F0 83680D00 */  sra        $t5, $t5, 2
    /* 318F4 800410F4 006C0D00 */  sll        $t5, $t5, 16
    /* 318F8 800410F8 25608D01 */  or         $t4, $t4, $t5
    /* 318FC 800410FC 0800E003 */  jr         $ra
    /* 31900 80041100 0C004CAC */   sw        $t4, 0xC($v0)
endlabel func_80040F8C
