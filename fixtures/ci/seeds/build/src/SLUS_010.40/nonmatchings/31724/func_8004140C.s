/* Handwritten function */
nonmatching func_8004140C, 0xFC

glabel func_8004140C
    /* 31C0C 8004140C 0000888C */  lw         $t0, 0x0($a0)
    /* 31C10 80041410 0400898C */  lw         $t1, 0x4($a0)
    /* 31C14 80041414 08008A8C */  lw         $t2, 0x8($a0)
    /* 31C18 80041418 0C008B8C */  lw         $t3, 0xC($a0)
    /* 31C1C 8004141C 0000AC8C */  lw         $t4, 0x0($a1)
    /* 31C20 80041420 007C0800 */  sll        $t7, $t0, 16
    /* 31C24 80041424 037C0F00 */  sra        $t7, $t7, 16
    /* 31C28 80041428 03C40900 */  sra        $t8, $t1, 16
    /* 31C2C 8004142C 00CC0B00 */  sll        $t9, $t3, 16
    /* 31C30 80041430 03CC1900 */  sra        $t9, $t9, 16
    /* 31C34 80041434 00408C48 */  mtc2       $t4, $8 /* handwritten instruction */
    /* 31C38 80041438 00488F48 */  mtc2       $t7, $9 /* handwritten instruction */
    /* 31C3C 8004143C 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 31C40 80041440 00589948 */  mtc2       $t9, $11 /* handwritten instruction */
    /* 31C44 80041444 037C0800 */  sra        $t7, $t0, 16
    /* 31C48 80041448 03CC0B00 */  sra        $t9, $t3, 16
    /* 31C4C 8004144C 3D00984B */  gpf        1
    /* 31C50 80041450 0400AD8C */  lw         $t5, 0x4($a1)
    /* 31C54 80041454 00C40A00 */  sll        $t8, $t2, 16
    /* 31C58 80041458 03C41800 */  sra        $t8, $t8, 16
    /* 31C5C 8004145C 21100400 */  addu       $v0, $zero, $a0
    /* 31C60 80041460 00480348 */  mfc2       $v1, $9 /* handwritten instruction */
    /* 31C64 80041464 00500648 */  mfc2       $a2, $10 /* handwritten instruction */
    /* 31C68 80041468 00580748 */  mfc2       $a3, $11 /* handwritten instruction */
    /* 31C6C 8004146C 00408D48 */  mtc2       $t5, $8 /* handwritten instruction */
    /* 31C70 80041470 00488F48 */  mtc2       $t7, $9 /* handwritten instruction */
    /* 31C74 80041474 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 31C78 80041478 00589948 */  mtc2       $t9, $11 /* handwritten instruction */
    /* 31C7C 8004147C 007C0900 */  sll        $t7, $t1, 16
    /* 31C80 80041480 037C0F00 */  sra        $t7, $t7, 16
    /* 31C84 80041484 3D00984B */  gpf        1
    /* 31C88 80041488 10008C84 */  lh         $t4, 0x10($a0)
    /* 31C8C 8004148C 0800AE8C */  lw         $t6, 0x8($a1)
    /* 31C90 80041490 03C40A00 */  sra        $t8, $t2, 16
    /* 31C94 80041494 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 31C98 80041498 FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 31C9C 8004149C 00480948 */  mfc2       $t1, $9 /* handwritten instruction */
    /* 31CA0 800414A0 00500A48 */  mfc2       $t2, $10 /* handwritten instruction */
    /* 31CA4 800414A4 00580B48 */  mfc2       $t3, $11 /* handwritten instruction */
    /* 31CA8 800414A8 00408E48 */  mtc2       $t6, $8 /* handwritten instruction */
    /* 31CAC 800414AC 00488F48 */  mtc2       $t7, $9 /* handwritten instruction */
    /* 31CB0 800414B0 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 31CB4 800414B4 00588C48 */  mtc2       $t4, $11 /* handwritten instruction */
    /* 31CB8 800414B8 00340600 */  sll        $a2, $a2, 16
    /* 31CBC 800414BC 004C0900 */  sll        $t1, $t1, 16
    /* 31CC0 800414C0 3D00984B */  gpf        1
    /* 31CC4 800414C4 FFFF4A31 */  andi       $t2, $t2, 0xFFFF
    /* 31CC8 800414C8 005C0B00 */  sll        $t3, $t3, 16
    /* 31CCC 800414CC 25482301 */  or         $t1, $t1, $v1
    /* 31CD0 800414D0 000049AC */  sw         $t1, 0x0($v0)
    /* 31CD4 800414D4 25586701 */  or         $t3, $t3, $a3
    /* 31CD8 800414D8 00480C48 */  mfc2       $t4, $9 /* handwritten instruction */
    /* 31CDC 800414DC 00500D48 */  mfc2       $t5, $10 /* handwritten instruction */
    /* 31CE0 800414E0 00580E48 */  mfc2       $t6, $11 /* handwritten instruction */
    /* 31CE4 800414E4 FFFF8C31 */  andi       $t4, $t4, 0xFFFF
    /* 31CE8 800414E8 25608601 */  or         $t4, $t4, $a2
    /* 31CEC 800414EC 006C0D00 */  sll        $t5, $t5, 16
    /* 31CF0 800414F0 2568AA01 */  or         $t5, $t5, $t2
    /* 31CF4 800414F4 04004CAC */  sw         $t4, 0x4($v0)
    /* 31CF8 800414F8 08004DAC */  sw         $t5, 0x8($v0)
    /* 31CFC 800414FC 0C004BAC */  sw         $t3, 0xC($v0)
    /* 31D00 80041500 0800E003 */  jr         $ra
    /* 31D04 80041504 10004EA4 */   sh        $t6, 0x10($v0)
endlabel func_8004140C
