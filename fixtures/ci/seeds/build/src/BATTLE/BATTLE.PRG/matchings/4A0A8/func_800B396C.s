/* Handwritten function */
nonmatching func_800B396C, 0xFC

glabel func_800B396C
    /* 4B16C 800B396C 0000888C */  lw         $t0, 0x0($a0)
    /* 4B170 800B3970 0400898C */  lw         $t1, 0x4($a0)
    /* 4B174 800B3974 08008A8C */  lw         $t2, 0x8($a0)
    /* 4B178 800B3978 0C008B8C */  lw         $t3, 0xC($a0)
    /* 4B17C 800B397C 0000AC8C */  lw         $t4, 0x0($a1)
    /* 4B180 800B3980 007C0800 */  sll        $t7, $t0, 16
    /* 4B184 800B3984 037C0F00 */  sra        $t7, $t7, 16
    /* 4B188 800B3988 03C40900 */  sra        $t8, $t1, 16
    /* 4B18C 800B398C 00CC0B00 */  sll        $t9, $t3, 16
    /* 4B190 800B3990 03CC1900 */  sra        $t9, $t9, 16
    /* 4B194 800B3994 00408C48 */  mtc2       $t4, $8 /* handwritten instruction */
    /* 4B198 800B3998 00488F48 */  mtc2       $t7, $9 /* handwritten instruction */
    /* 4B19C 800B399C 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 4B1A0 800B39A0 00589948 */  mtc2       $t9, $11 /* handwritten instruction */
    /* 4B1A4 800B39A4 037C0800 */  sra        $t7, $t0, 16
    /* 4B1A8 800B39A8 03CC0B00 */  sra        $t9, $t3, 16
    /* 4B1AC 800B39AC 3D00984B */  gpf        1
    /* 4B1B0 800B39B0 0400AD8C */  lw         $t5, 0x4($a1)
    /* 4B1B4 800B39B4 00C40A00 */  sll        $t8, $t2, 16
    /* 4B1B8 800B39B8 03C41800 */  sra        $t8, $t8, 16
    /* 4B1BC 800B39BC 21100400 */  addu       $v0, $zero, $a0
    /* 4B1C0 800B39C0 00480348 */  mfc2       $v1, $9 /* handwritten instruction */
    /* 4B1C4 800B39C4 00500648 */  mfc2       $a2, $10 /* handwritten instruction */
    /* 4B1C8 800B39C8 00580748 */  mfc2       $a3, $11 /* handwritten instruction */
    /* 4B1CC 800B39CC 00408D48 */  mtc2       $t5, $8 /* handwritten instruction */
    /* 4B1D0 800B39D0 00488F48 */  mtc2       $t7, $9 /* handwritten instruction */
    /* 4B1D4 800B39D4 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 4B1D8 800B39D8 00589948 */  mtc2       $t9, $11 /* handwritten instruction */
    /* 4B1DC 800B39DC 007C0900 */  sll        $t7, $t1, 16
    /* 4B1E0 800B39E0 037C0F00 */  sra        $t7, $t7, 16
    /* 4B1E4 800B39E4 3D00984B */  gpf        1
    /* 4B1E8 800B39E8 10008C84 */  lh         $t4, 0x10($a0)
    /* 4B1EC 800B39EC 0800AE8C */  lw         $t6, 0x8($a1)
    /* 4B1F0 800B39F0 03C40A00 */  sra        $t8, $t2, 16
    /* 4B1F4 800B39F4 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 4B1F8 800B39F8 FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 4B1FC 800B39FC 00480948 */  mfc2       $t1, $9 /* handwritten instruction */
    /* 4B200 800B3A00 00500A48 */  mfc2       $t2, $10 /* handwritten instruction */
    /* 4B204 800B3A04 00580B48 */  mfc2       $t3, $11 /* handwritten instruction */
    /* 4B208 800B3A08 00408E48 */  mtc2       $t6, $8 /* handwritten instruction */
    /* 4B20C 800B3A0C 00488F48 */  mtc2       $t7, $9 /* handwritten instruction */
    /* 4B210 800B3A10 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 4B214 800B3A14 00588C48 */  mtc2       $t4, $11 /* handwritten instruction */
    /* 4B218 800B3A18 00340600 */  sll        $a2, $a2, 16
    /* 4B21C 800B3A1C 004C0900 */  sll        $t1, $t1, 16
    /* 4B220 800B3A20 3D00984B */  gpf        1
    /* 4B224 800B3A24 FFFF4A31 */  andi       $t2, $t2, 0xFFFF
    /* 4B228 800B3A28 005C0B00 */  sll        $t3, $t3, 16
    /* 4B22C 800B3A2C 25482301 */  or         $t1, $t1, $v1
    /* 4B230 800B3A30 000049AC */  sw         $t1, 0x0($v0)
    /* 4B234 800B3A34 25586701 */  or         $t3, $t3, $a3
    /* 4B238 800B3A38 00480C48 */  mfc2       $t4, $9 /* handwritten instruction */
    /* 4B23C 800B3A3C 00500D48 */  mfc2       $t5, $10 /* handwritten instruction */
    /* 4B240 800B3A40 00580E48 */  mfc2       $t6, $11 /* handwritten instruction */
    /* 4B244 800B3A44 FFFF8C31 */  andi       $t4, $t4, 0xFFFF
    /* 4B248 800B3A48 25608601 */  or         $t4, $t4, $a2
    /* 4B24C 800B3A4C 006C0D00 */  sll        $t5, $t5, 16
    /* 4B250 800B3A50 2568AA01 */  or         $t5, $t5, $t2
    /* 4B254 800B3A54 04004CAC */  sw         $t4, 0x4($v0)
    /* 4B258 800B3A58 08004DAC */  sw         $t5, 0x8($v0)
    /* 4B25C 800B3A5C 0C004BAC */  sw         $t3, 0xC($v0)
    /* 4B260 800B3A60 0800E003 */  jr         $ra
    /* 4B264 800B3A64 10004EA4 */   sh        $t6, 0x10($v0)
endlabel func_800B396C
