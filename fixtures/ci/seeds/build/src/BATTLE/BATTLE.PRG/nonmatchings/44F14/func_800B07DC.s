/* Handwritten function */
nonmatching func_800B07DC, 0x12C

glabel func_800B07DC
    /* 47FDC 800B07DC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 47FE0 800B07E0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 47FE4 800B07E4 21888000 */  addu       $s1, $a0, $zero
    /* 47FE8 800B07E8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 47FEC 800B07EC 801F103C */  lui        $s0, (0x1F80035C >> 16)
    /* 47FF0 800B07F0 5C031036 */  ori        $s0, $s0, (0x1F80035C & 0xFFFF)
    /* 47FF4 800B07F4 801F043C */  lui        $a0, (0x1F8003E0 >> 16)
    /* 47FF8 800B07F8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 47FFC 800B07FC 24002296 */  lhu        $v0, 0x24($s1)
    /* 48000 800B0800 E0038434 */  ori        $a0, $a0, (0x1F8003E0 & 0xFFFF)
    /* 48004 800B0804 840002A6 */  sh         $v0, 0x84($s0)
    /* 48008 800B0808 26002296 */  lhu        $v0, 0x26($s1)
    /* 4800C 800B080C 801F053C */  lui        $a1, (0x1F8003C0 >> 16)
    /* 48010 800B0810 860002A6 */  sh         $v0, 0x86($s0)
    /* 48014 800B0814 28002296 */  lhu        $v0, 0x28($s1)
    /* 48018 800B0818 C003A534 */  ori        $a1, $a1, (0x1F8003C0 & 0xFFFF)
    /* 4801C 800B081C E303010C */  jal        func_80040F8C
    /* 48020 800B0820 880002A6 */   sh        $v0, 0x88($s0)
    /* 48024 800B0824 801F063C */  lui        $a2, (0x1F8003C0 >> 16)
    /* 48028 800B0828 C003C634 */  ori        $a2, $a2, (0x1F8003C0 & 0xFFFF)
    /* 4802C 800B082C 780000AE */  sw         $zero, 0x78($s0)
    /* 48030 800B0830 7C0000AE */  sw         $zero, 0x7C($s0)
    /* 48034 800B0834 800000AE */  sw         $zero, 0x80($s0)
    /* 48038 800B0838 0000CC8C */  lw         $t4, 0x0($a2)
    /* 4803C 800B083C 0400CD8C */  lw         $t5, 0x4($a2)
    /* 48040 800B0840 0000CC48 */  ctc2       $t4, $0 /* handwritten instruction */
    /* 48044 800B0844 0008CD48 */  ctc2       $t5, $1 /* handwritten instruction */
    /* 48048 800B0848 0800CC8C */  lw         $t4, 0x8($a2)
    /* 4804C 800B084C 0C00CD8C */  lw         $t5, 0xC($a2)
    /* 48050 800B0850 1000CE8C */  lw         $t6, 0x10($a2)
    /* 48054 800B0854 0010CC48 */  ctc2       $t4, $2 /* handwritten instruction */
    /* 48058 800B0858 0018CD48 */  ctc2       $t5, $3 /* handwritten instruction */
    /* 4805C 800B085C 0020CE48 */  ctc2       $t6, $4 /* handwritten instruction */
    /* 48060 800B0860 1400CC8C */  lw         $t4, 0x14($a2)
    /* 48064 800B0864 1800CD8C */  lw         $t5, 0x18($a2)
    /* 48068 800B0868 0028CC48 */  ctc2       $t4, $5 /* handwritten instruction */
    /* 4806C 800B086C 1C00CE8C */  lw         $t6, 0x1C($a2)
    /* 48070 800B0870 0030CD48 */  ctc2       $t5, $6 /* handwritten instruction */
    /* 48074 800B0874 0038CE48 */  ctc2       $t6, $7 /* handwritten instruction */
    /* 48078 800B0878 801F063C */  lui        $a2, (0x1F8003B0 >> 16)
    /* 4807C 800B087C B003C634 */  ori        $a2, $a2, (0x1F8003B0 & 0xFFFF)
    /* 48080 800B0880 0000C0C8 */  lwc2       $0, 0x0($a2)
    /* 48084 800B0884 0400C1C8 */  lwc2       $1, 0x4($a2)
    /* 48088 800B0888 00000000 */  nop
    /* 4808C 800B088C 00000000 */  nop
    /* 48090 800B0890 1200484A */  mvmva      1, 0, 0, 0, 0
    /* 48094 800B0894 801F063C */  lui        $a2, (0x1F8003D4 >> 16)
    /* 48098 800B0898 D403C634 */  ori        $a2, $a2, (0x1F8003D4 & 0xFFFF)
    /* 4809C 800B089C 0000D9E8 */  swc2       $25, 0x0($a2)
    /* 480A0 800B08A0 0400DAE8 */  swc2       $26, 0x4($a2) /* handwritten instruction */
    /* 480A4 800B08A4 0800DBE8 */  swc2       $27, 0x8($a2) /* handwritten instruction */
    /* 480A8 800B08A8 78000396 */  lhu        $v1, 0x78($s0)
    /* 480AC 800B08AC 7C000596 */  lhu        $a1, 0x7C($s0)
    /* 480B0 800B08B0 80000496 */  lhu        $a0, 0x80($s0)
    /* 480B4 800B08B4 540003A6 */  sh         $v1, 0x54($s0)
    /* 480B8 800B08B8 560005A6 */  sh         $a1, 0x56($s0)
    /* 480BC 800B08BC 580004A6 */  sh         $a0, 0x58($s0)
    /* 480C0 800B08C0 1C002296 */  lhu        $v0, 0x1C($s1)
    /* 480C4 800B08C4 00000000 */  nop
    /* 480C8 800B08C8 21186200 */  addu       $v1, $v1, $v0
    /* 480CC 800B08CC 540003A6 */  sh         $v1, 0x54($s0)
    /* 480D0 800B08D0 20002296 */  lhu        $v0, 0x20($s1)
    /* 480D4 800B08D4 00000000 */  nop
    /* 480D8 800B08D8 21208200 */  addu       $a0, $a0, $v0
    /* 480DC 800B08DC 580004A6 */  sh         $a0, 0x58($s0)
    /* 480E0 800B08E0 1E002296 */  lhu        $v0, 0x1E($s1)
    /* 480E4 800B08E4 00000000 */  nop
    /* 480E8 800B08E8 2128A200 */  addu       $a1, $a1, $v0
    /* 480EC 800B08EC 560005A6 */  sh         $a1, 0x56($s0)
    /* 480F0 800B08F0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 480F4 800B08F4 1400B18F */  lw         $s1, 0x14($sp)
    /* 480F8 800B08F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 480FC 800B08FC 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 48100 800B0900 0800E003 */  jr         $ra
    /* 48104 800B0904 00000000 */   nop
endlabel func_800B07DC
