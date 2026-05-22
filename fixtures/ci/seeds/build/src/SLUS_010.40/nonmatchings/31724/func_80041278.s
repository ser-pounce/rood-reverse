/* Handwritten function */
nonmatching func_80041278, 0x104

glabel func_80041278
    /* 31A78 80041278 FC071833 */  andi       $t8, $t8, 0x7FC
    /* 31A7C 8004127C 00408C48 */  mtc2       $t4, $8 /* handwritten instruction */
    /* 31A80 80041280 00488A48 */  mtc2       $t2, $9 /* handwritten instruction */
    /* 31A84 80041284 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 31A88 80041288 00588948 */  mtc2       $t1, $11 /* handwritten instruction */
    /* 31A8C 8004128C 18002B01 */  mult       $t1, $t3
    /* 31A90 80041290 21100500 */  addu       $v0, $zero, $a1
    /* 31A94 80041294 3D00984B */  gpf        1
    /* 31A98 80041298 FFFF1831 */  andi       $t8, $t0, 0xFFFF
    /* 31A9C 8004129C 00480448 */  mfc2       $a0, $9 /* handwritten instruction */
    /* 31AA0 800412A0 00500548 */  mfc2       $a1, $10 /* handwritten instruction */
    /* 31AA4 800412A4 00580C48 */  mfc2       $t4, $11 /* handwritten instruction */
    /* 31AA8 800412A8 00408D48 */  mtc2       $t5, $8 /* handwritten instruction */
    /* 31AAC 800412AC 00488A48 */  mtc2       $t2, $9 /* handwritten instruction */
    /* 31AB0 800412B0 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 31AB4 800412B4 00588948 */  mtc2       $t1, $11 /* handwritten instruction */
    /* 31AB8 800412B8 43600C00 */  sra        $t4, $t4, 1
    /* 31ABC 800412BC 23600C00 */  negu       $t4, $t4
    /* 31AC0 800412C0 3D00984B */  gpf        1
    /* 31AC4 800412C4 12780000 */  mflo       $t7
    /* 31AC8 800412C8 00640C00 */  sll        $t4, $t4, 16
    /* 31ACC 800412CC 437B0F00 */  sra        $t7, $t7, 13
    /* 31AD0 800412D0 18002A01 */  mult       $t1, $t2
    /* 31AD4 800412D4 10004FA4 */  sh         $t7, 0x10($v0)
    /* 31AD8 800412D8 00480648 */  mfc2       $a2, $9 /* handwritten instruction */
    /* 31ADC 800412DC 00500748 */  mfc2       $a3, $10 /* handwritten instruction */
    /* 31AE0 800412E0 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 31AE4 800412E4 00408848 */  mtc2       $t0, $8 /* handwritten instruction */
    /* 31AE8 800412E8 00488648 */  mtc2       $a2, $9 /* handwritten instruction */
    /* 31AEC 800412EC 00508448 */  mtc2       $a0, $10 /* handwritten instruction */
    /* 31AF0 800412F0 00588748 */  mtc2       $a3, $11 /* handwritten instruction */
    /* 31AF4 800412F4 43680D00 */  sra        $t5, $t5, 1
    /* 31AF8 800412F8 FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 31AFC 800412FC 3D00984B */  gpf        1
    /* 31B00 80041300 2568AC01 */  or         $t5, $t5, $t4
    /* 31B04 80041304 00004DAC */  sw         $t5, 0x0($v0)
    /* 31B08 80041308 12780000 */  mflo       $t7
    /* 31B0C 8004130C 437B0F00 */  sra        $t7, $t7, 13
    /* 31B10 80041310 23780F00 */  negu       $t7, $t7
    /* 31B14 80041314 18000501 */  mult       $t0, $a1
    /* 31B18 80041318 007C0F00 */  sll        $t7, $t7, 16
    /* 31B1C 8004131C 00480A48 */  mfc2       $t2, $9 /* handwritten instruction */
    /* 31B20 80041320 00500B48 */  mfc2       $t3, $10 /* handwritten instruction */
    /* 31B24 80041324 00580C48 */  mfc2       $t4, $11 /* handwritten instruction */
    /* 31B28 80041328 21504501 */  addu       $t2, $t2, $a1
    /* 31B2C 8004132C 2358EB00 */  subu       $t3, $a3, $t3
    /* 31B30 80041330 23608C00 */  subu       $t4, $a0, $t4
    /* 31B34 80041334 83500A00 */  sra        $t2, $t2, 2
    /* 31B38 80041338 00540A00 */  sll        $t2, $t2, 16
    /* 31B3C 8004133C 25505801 */  or         $t2, $t2, $t8
    /* 31B40 80041340 04004AAC */  sw         $t2, 0x4($v0)
    /* 31B44 80041344 83580B00 */  sra        $t3, $t3, 2
    /* 31B48 80041348 FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 31B4C 8004134C 25586F01 */  or         $t3, $t3, $t7
    /* 31B50 80041350 08004BAC */  sw         $t3, 0x8($v0)
    /* 31B54 80041354 83600C00 */  sra        $t4, $t4, 2
    /* 31B58 80041358 FFFF8C31 */  andi       $t4, $t4, 0xFFFF
    /* 31B5C 8004135C 12680000 */  mflo       $t5
    /* 31B60 80041360 036B0D00 */  sra        $t5, $t5, 12
    /* 31B64 80041364 2168A601 */  addu       $t5, $t5, $a2
    /* 31B68 80041368 83680D00 */  sra        $t5, $t5, 2
    /* 31B6C 8004136C 006C0D00 */  sll        $t5, $t5, 16
    /* 31B70 80041370 25608D01 */  or         $t4, $t4, $t5
    /* 31B74 80041374 0800E003 */  jr         $ra
    /* 31B78 80041378 0C004CAC */   sw        $t4, 0xC($v0)
endlabel func_80041278
