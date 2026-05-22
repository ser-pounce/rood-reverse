/* Handwritten function */
nonmatching func_800B17F0, 0x17C

glabel func_800B17F0
    /* 48FF0 800B17F0 0000828C */  lw         $v0, 0x0($a0)
    /* 48FF4 800B17F4 0400988C */  lw         $t8, 0x4($a0)
    /* 48FF8 800B17F8 0480063C */  lui        $a2, %hi(_trig_table)
    /* 48FFC 800B17FC 1002C624 */  addiu      $a2, $a2, %lo(_trig_table)
    /* 49000 800B1800 0B800F3C */  lui        $t7, %hi(func_800B16F4)
    /* 49004 800B1804 F416EF25 */  addiu      $t7, $t7, %lo(func_800B16F4)
    /* 49008 800B1808 0008C724 */  addiu      $a3, $a2, 0x800
  alabel D_800B180C
    /* 4900C 800B180C 02491800 */  srl        $t1, $t8, 4
    /* 49010 800B1810 E0002931 */  andi       $t1, $t1, 0xE0
    /* 49014 800B1814 21482F01 */  addu       $t1, $t1, $t7
    /* 49018 800B1818 0B80193C */  lui        $t9, %hi(D_800B180C)
    /* 4901C 800B181C 0C183927 */  addiu      $t9, $t9, %lo(D_800B180C)
    /* 49020 800B1820 80C01800 */  sll        $t8, $t8, 2
    /* 49024 800B1824 08002001 */  jr         $t1
    /* 49028 800B1828 FC071833 */   andi      $t8, $t8, 0x7FC
    /* 4902C 800B182C 40600800 */  sll        $t4, $t0, 1
    /* 49030 800B1830 40680900 */  sll        $t5, $t1, 1
    /* 49034 800B1834 80C00200 */  sll        $t8, $v0, 2
    /* 49038 800B1838 82491800 */  srl        $t1, $t8, 6
    /* 4903C 800B183C E0002931 */  andi       $t1, $t1, 0xE0
    /* 49040 800B1840 21482F01 */  addu       $t1, $t1, $t7
    /* 49044 800B1844 08002001 */  jr         $t1
    /* 49048 800B1848 FC071833 */   andi      $t8, $t8, 0x7FC
    /* 4904C 800B184C 40500800 */  sll        $t2, $t0, 1
    /* 49050 800B1850 40580900 */  sll        $t3, $t1, 1
    /* 49054 800B1854 82C30200 */  srl        $t8, $v0, 14
    /* 49058 800B1858 82491800 */  srl        $t1, $t8, 6
    /* 4905C 800B185C E0002931 */  andi       $t1, $t1, 0xE0
    /* 49060 800B1860 21482F01 */  addu       $t1, $t1, $t7
    /* 49064 800B1864 08002001 */  jr         $t1
    /* 49068 800B1868 FC071833 */   andi      $t8, $t8, 0x7FC
    /* 4906C 800B186C 18002B01 */  mult       $t1, $t3
    /* 49070 800B1870 21100500 */  addu       $v0, $zero, $a1
    /* 49074 800B1874 00408C48 */  mtc2       $t4, $8 /* handwritten instruction */
    /* 49078 800B1878 00488A48 */  mtc2       $t2, $9 /* handwritten instruction */
    /* 4907C 800B187C 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 49080 800B1880 00588948 */  mtc2       $t1, $11 /* handwritten instruction */
    /* 49084 800B1884 FFFF1831 */  andi       $t8, $t0, 0xFFFF
    /* 49088 800B1888 23C01800 */  negu       $t8, $t8
    /* 4908C 800B188C 3D00984B */  gpf        1
    /* 49090 800B1890 FFFF1833 */  andi       $t8, $t8, 0xFFFF
    /* 49094 800B1894 00480448 */  mfc2       $a0, $9 /* handwritten instruction */
    /* 49098 800B1898 00500548 */  mfc2       $a1, $10 /* handwritten instruction */
    /* 4909C 800B189C 00580C48 */  mfc2       $t4, $11 /* handwritten instruction */
    /* 490A0 800B18A0 00408D48 */  mtc2       $t5, $8 /* handwritten instruction */
    /* 490A4 800B18A4 00488A48 */  mtc2       $t2, $9 /* handwritten instruction */
    /* 490A8 800B18A8 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 490AC 800B18AC 00588948 */  mtc2       $t1, $11 /* handwritten instruction */
    /* 490B0 800B18B0 12780000 */  mflo       $t7
    /* 490B4 800B18B4 437B0F00 */  sra        $t7, $t7, 13
    /* 490B8 800B18B8 3D00984B */  gpf        1
    /* 490BC 800B18BC 18002A01 */  mult       $t1, $t2
    /* 490C0 800B18C0 10004FA4 */  sh         $t7, 0x10($v0)
    /* 490C4 800B18C4 43600C00 */  sra        $t4, $t4, 1
    /* 490C8 800B18C8 00640C00 */  sll        $t4, $t4, 16
    /* 490CC 800B18CC 00480648 */  mfc2       $a2, $9 /* handwritten instruction */
    /* 490D0 800B18D0 00500748 */  mfc2       $a3, $10 /* handwritten instruction */
    /* 490D4 800B18D4 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 490D8 800B18D8 00408848 */  mtc2       $t0, $8 /* handwritten instruction */
    /* 490DC 800B18DC 00488648 */  mtc2       $a2, $9 /* handwritten instruction */
    /* 490E0 800B18E0 00508448 */  mtc2       $a0, $10 /* handwritten instruction */
    /* 490E4 800B18E4 00588748 */  mtc2       $a3, $11 /* handwritten instruction */
    /* 490E8 800B18E8 43680D00 */  sra        $t5, $t5, 1
    /* 490EC 800B18EC FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 490F0 800B18F0 3D00984B */  gpf        1
    /* 490F4 800B18F4 12780000 */  mflo       $t7
    /* 490F8 800B18F8 437B0F00 */  sra        $t7, $t7, 13
    /* 490FC 800B18FC 007C0F00 */  sll        $t7, $t7, 16
    /* 49100 800B1900 18000501 */  mult       $t0, $a1
    /* 49104 800B1904 25C00F03 */  or         $t8, $t8, $t7
    /* 49108 800B1908 0C0058AC */  sw         $t8, 0xC($v0)
    /* 4910C 800B190C 00480A48 */  mfc2       $t2, $9 /* handwritten instruction */
    /* 49110 800B1910 00500B48 */  mfc2       $t3, $10 /* handwritten instruction */
    /* 49114 800B1914 00580E48 */  mfc2       $t6, $11 /* handwritten instruction */
    /* 49118 800B1918 23504501 */  subu       $t2, $t2, $a1
    /* 4911C 800B191C 21586701 */  addu       $t3, $t3, $a3
    /* 49120 800B1920 2170C401 */  addu       $t6, $t6, $a0
    /* 49124 800B1924 83500A00 */  sra        $t2, $t2, 2
    /* 49128 800B1928 00540A00 */  sll        $t2, $t2, 16
    /* 4912C 800B192C 25504D01 */  or         $t2, $t2, $t5
    /* 49130 800B1930 00004AAC */  sw         $t2, 0x0($v0)
    /* 49134 800B1934 83700E00 */  sra        $t6, $t6, 2
    /* 49138 800B1938 FFFFCE31 */  andi       $t6, $t6, 0xFFFF
    /* 4913C 800B193C 2570CC01 */  or         $t6, $t6, $t4
    /* 49140 800B1940 04004EAC */  sw         $t6, 0x4($v0)
    /* 49144 800B1944 83580B00 */  sra        $t3, $t3, 2
    /* 49148 800B1948 FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 4914C 800B194C 12780000 */  mflo       $t7
    /* 49150 800B1950 037B0F00 */  sra        $t7, $t7, 12
    /* 49154 800B1954 2378E601 */  subu       $t7, $t7, $a2
    /* 49158 800B1958 83780F00 */  sra        $t7, $t7, 2
    /* 4915C 800B195C 007C0F00 */  sll        $t7, $t7, 16
    /* 49160 800B1960 2578EB01 */  or         $t7, $t7, $t3
    /* 49164 800B1964 0800E003 */  jr         $ra
    /* 49168 800B1968 08004FAC */   sw        $t7, 0x8($v0)
endlabel func_800B17F0
