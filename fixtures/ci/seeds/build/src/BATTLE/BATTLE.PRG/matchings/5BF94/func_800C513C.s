nonmatching func_800C513C, 0x28

glabel func_800C513C
    /* 5C93C 800C513C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5C940 800C5140 F0008230 */  andi       $v0, $a0, 0xF0
    /* 5C944 800C5144 03004014 */  bnez       $v0, .L800C5154
    /* 5C948 800C5148 1000BFAF */   sw        $ra, 0x10($sp)
    /* 5C94C 800C514C 9D7F020C */  jal        func_8009FE74
    /* 5C950 800C5150 00000000 */   nop
  .L800C5154:
    /* 5C954 800C5154 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5C958 800C5158 00000000 */  nop
    /* 5C95C 800C515C 0800E003 */  jr         $ra
    /* 5C960 800C5160 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800C513C
