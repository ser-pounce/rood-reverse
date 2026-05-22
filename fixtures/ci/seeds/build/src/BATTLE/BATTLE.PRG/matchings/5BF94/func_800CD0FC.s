nonmatching func_800CD0FC, 0x5C

glabel func_800CD0FC
    /* 648FC 800CD0FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64900 800CD100 0300A22C */  sltiu      $v0, $a1, 0x3
    /* 64904 800CD104 1400BFAF */  sw         $ra, 0x14($sp)
    /* 64908 800CD108 0F004010 */  beqz       $v0, .L800CD148
    /* 6490C 800CD10C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 64910 800CD110 0F80023C */  lui        $v0, %hi(D_800EC2CC)
    /* 64914 800CD114 CCC24224 */  addiu      $v0, $v0, %lo(D_800EC2CC)
    /* 64918 800CD118 80800500 */  sll        $s0, $a1, 2
    /* 6491C 800CD11C 21100202 */  addu       $v0, $s0, $v0
    /* 64920 800CD120 002C0400 */  sll        $a1, $a0, 16
    /* 64924 800CD124 0000448C */  lw         $a0, 0x0($v0)
    /* 64928 800CD128 8500030C */  jal        func_800C0214
    /* 6492C 800CD12C 0A00A534 */   ori       $a1, $a1, 0xA
    /* 64930 800CD130 0F80033C */  lui        $v1, %hi(D_800EC2D8)
    /* 64934 800CD134 D8C26324 */  addiu      $v1, $v1, %lo(D_800EC2D8)
    /* 64938 800CD138 21800302 */  addu       $s0, $s0, $v1
    /* 6493C 800CD13C 0000038E */  lw         $v1, 0x0($s0)
    /* 64940 800CD140 00000000 */  nop
    /* 64944 800CD144 100043AC */  sw         $v1, 0x10($v0)
  .L800CD148:
    /* 64948 800CD148 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6494C 800CD14C 1000B08F */  lw         $s0, 0x10($sp)
    /* 64950 800CD150 0800E003 */  jr         $ra
    /* 64954 800CD154 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CD0FC
