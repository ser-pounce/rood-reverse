/* Handwritten function */
nonmatching func_800B196C, 0xFC

glabel func_800B196C
    /* 4916C 800B196C 0000888C */  lw         $t0, 0x0($a0)
    /* 49170 800B1970 0400898C */  lw         $t1, 0x4($a0)
    /* 49174 800B1974 08008A8C */  lw         $t2, 0x8($a0)
    /* 49178 800B1978 0C008B8C */  lw         $t3, 0xC($a0)
    /* 4917C 800B197C 10008C8C */  lw         $t4, 0x10($a0)
    /* 49180 800B1980 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 49184 800B1984 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 49188 800B1988 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 4918C 800B198C 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 49190 800B1990 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 49194 800B1994 0400A98C */  lw         $t1, 0x4($a1)
    /* 49198 800B1998 0800AA8C */  lw         $t2, 0x8($a1)
    /* 4919C 800B199C 1000AC8C */  lw         $t4, 0x10($a1)
    /* 491A0 800B19A0 FFFF193C */  lui        $t9, (0xFFFF0000 >> 16)
    /* 491A4 800B19A4 24685901 */  and        $t5, $t2, $t9
    /* 491A8 800B19A8 FFFF2E31 */  andi       $t6, $t1, 0xFFFF
    /* 491AC 800B19AC 2568AE01 */  or         $t5, $t5, $t6
    /* 491B0 800B19B0 00008D48 */  mtc2       $t5, $0 /* handwritten instruction */
    /* 491B4 800B19B4 00088C48 */  mtc2       $t4, $1 /* handwritten instruction */
    /* 491B8 800B19B8 00740A00 */  sll        $t6, $t2, 16
    /* 491BC 800B19BC 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 491C0 800B19C0 0000A88C */  lw         $t0, 0x0($a1)
    /* 491C4 800B19C4 0C00AB8C */  lw         $t3, 0xC($a1)
    /* 491C8 800B19C8 026C0800 */  srl        $t5, $t0, 16
    /* 491CC 800B19CC 2568AE01 */  or         $t5, $t5, $t6
    /* 491D0 800B19D0 02740B00 */  srl        $t6, $t3, 16
    /* 491D4 800B19D4 00480448 */  mfc2       $a0, $9 /* handwritten instruction */
    /* 491D8 800B19D8 00500648 */  mfc2       $a2, $10 /* handwritten instruction */
    /* 491DC 800B19DC 00580748 */  mfc2       $a3, $11 /* handwritten instruction */
    /* 491E0 800B19E0 00008D48 */  mtc2       $t5, $0 /* handwritten instruction */
    /* 491E4 800B19E4 00088E48 */  mtc2       $t6, $1 /* handwritten instruction */
    /* 491E8 800B19E8 00340600 */  sll        $a2, $a2, 16
    /* 491EC 800B19EC 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 491F0 800B19F0 24783901 */  and        $t7, $t1, $t9
    /* 491F4 800B19F4 FFFF1831 */  andi       $t8, $t0, 0xFFFF
    /* 491F8 800B19F8 2578F801 */  or         $t7, $t7, $t8
    /* 491FC 800B19FC FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 49200 800B1A00 1000A7A4 */  sh         $a3, 0x10($a1)
    /* 49204 800B1A04 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 49208 800B1A08 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 4920C 800B1A0C 00580A48 */  mfc2       $t2, $11 /* handwritten instruction */
    /* 49210 800B1A10 00008F48 */  mtc2       $t7, $0 /* handwritten instruction */
    /* 49214 800B1A14 00088B48 */  mtc2       $t3, $1 /* handwritten instruction */
    /* 49218 800B1A18 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 4921C 800B1A1C 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 49220 800B1A20 21100500 */  addu       $v0, $zero, $a1
    /* 49224 800B1A24 25482601 */  or         $t1, $t1, $a2
    /* 49228 800B1A28 0800A9AC */  sw         $t1, 0x8($a1)
    /* 4922C 800B1A2C 00440800 */  sll        $t0, $t0, 16
    /* 49230 800B1A30 00540A00 */  sll        $t2, $t2, 16
    /* 49234 800B1A34 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 49238 800B1A38 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 4923C 800B1A3C 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 49240 800B1A40 FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 49244 800B1A44 25586801 */  or         $t3, $t3, $t0
    /* 49248 800B1A48 0000ABAC */  sw         $t3, 0x0($a1)
    /* 4924C 800B1A4C 00640C00 */  sll        $t4, $t4, 16
    /* 49250 800B1A50 25608401 */  or         $t4, $t4, $a0
    /* 49254 800B1A54 0400ACAC */  sw         $t4, 0x4($a1)
    /* 49258 800B1A58 FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 4925C 800B1A5C 2568AA01 */  or         $t5, $t5, $t2
    /* 49260 800B1A60 0800E003 */  jr         $ra
    /* 49264 800B1A64 0C00ADAC */   sw        $t5, 0xC($a1)
endlabel func_800B196C
