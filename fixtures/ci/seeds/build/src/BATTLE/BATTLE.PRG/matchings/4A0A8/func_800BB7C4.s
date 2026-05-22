nonmatching func_800BB7C4, 0xB0

glabel func_800BB7C4
    /* 52FC4 800BB7C4 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 52FC8 800BB7C8 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 52FCC 800BB7CC 21888000 */  addu       $s1, $a0, $zero
    /* 52FD0 800BB7D0 4800B0AF */  sw         $s0, 0x48($sp)
    /* 52FD4 800BB7D4 2180A000 */  addu       $s0, $a1, $zero
    /* 52FD8 800BB7D8 01000524 */  addiu      $a1, $zero, 0x1
    /* 52FDC 800BB7DC 1000A627 */  addiu      $a2, $sp, 0x10
    /* 52FE0 800BB7E0 3800A727 */  addiu      $a3, $sp, 0x38
    /* 52FE4 800BB7E4 18FC0224 */  addiu      $v0, $zero, -0x3E8
    /* 52FE8 800BB7E8 5000BFAF */  sw         $ra, 0x50($sp)
    /* 52FEC 800BB7EC 000000A6 */  sh         $zero, 0x0($s0)
    /* 52FF0 800BB7F0 020002A6 */  sh         $v0, 0x2($s0)
    /* 52FF4 800BB7F4 5E84020C */  jal        func_800A1178
    /* 52FF8 800BB7F8 040000A6 */   sh        $zero, 0x4($s0)
    /* 52FFC 800BB7FC 6605010C */  jal        SetRotMatrix
    /* 53000 800BB800 1000A427 */   addiu     $a0, $sp, 0x10
    /* 53004 800BB804 5E05010C */  jal        SetTransMatrix
    /* 53008 800BB808 1000A427 */   addiu     $a0, $sp, 0x10
    /* 5300C 800BB80C 21200002 */  addu       $a0, $s0, $zero
    /* 53010 800BB810 3000A527 */  addiu      $a1, $sp, 0x30
    /* 53014 800BB814 3C00A627 */  addiu      $a2, $sp, 0x3C
    /* 53018 800BB818 0506010C */  jal        RotTransPers
    /* 5301C 800BB81C 4000A727 */   addiu     $a3, $sp, 0x40
    /* 53020 800BB820 21202002 */  addu       $a0, $s1, $zero
    /* 53024 800BB824 01000524 */  addiu      $a1, $zero, 0x1
    /* 53028 800BB828 3800A78F */  lw         $a3, 0x38($sp)
    /* 5302C 800BB82C A084020C */  jal        func_800A1280
    /* 53030 800BB830 21300002 */   addu      $a2, $s0, $zero
    /* 53034 800BB834 3200A387 */  lh         $v1, 0x32($sp)
    /* 53038 800BB838 02000486 */  lh         $a0, 0x2($s0)
    /* 5303C 800BB83C 3000A287 */  lh         $v0, 0x30($sp)
    /* 53040 800BB840 00000586 */  lh         $a1, 0x0($s0)
    /* 53044 800BB844 23206400 */  subu       $a0, $v1, $a0
    /* 53048 800BB848 DF04010C */  jal        ratan2
    /* 5304C 800BB84C 23284500 */   subu      $a1, $v0, $a1
    /* 53050 800BB850 21184000 */  addu       $v1, $v0, $zero
    /* 53054 800BB854 00140300 */  sll        $v0, $v1, 16
    /* 53058 800BB858 040003A6 */  sh         $v1, 0x4($s0)
    /* 5305C 800BB85C 5000BF8F */  lw         $ra, 0x50($sp)
    /* 53060 800BB860 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 53064 800BB864 4800B08F */  lw         $s0, 0x48($sp)
    /* 53068 800BB868 03140200 */  sra        $v0, $v0, 16
    /* 5306C 800BB86C 0800E003 */  jr         $ra
    /* 53070 800BB870 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel func_800BB7C4
