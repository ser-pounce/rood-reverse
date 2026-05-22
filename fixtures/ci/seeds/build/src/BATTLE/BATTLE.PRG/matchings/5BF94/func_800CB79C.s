nonmatching func_800CB79C, 0x40

glabel func_800CB79C
    /* 62F9C 800CB79C 0F80033C */  lui        $v1, %hi(D_800EB9B4)
    /* 62FA0 800CB7A0 B4B9628C */  lw         $v0, %lo(D_800EB9B4)($v1)
    /* 62FA4 800CB7A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62FA8 800CB7A8 08004014 */  bnez       $v0, .L800CB7CC
    /* 62FAC 800CB7AC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 62FB0 800CB7B0 0F80023C */  lui        $v0, %hi(D_800F4ED8)
    /* 62FB4 800CB7B4 D84E4224 */  addiu      $v0, $v0, %lo(D_800F4ED8)
    /* 62FB8 800CB7B8 B4B962AC */  sw         $v0, %lo(D_800EB9B4)($v1)
    /* 62FBC 800CB7BC 60F8010C */  jal        func_8007E180
    /* 62FC0 800CB7C0 06000424 */   addiu     $a0, $zero, 0x6
    /* 62FC4 800CB7C4 9E2D030C */  jal        _loadScreff2
    /* 62FC8 800CB7C8 01000424 */   addiu     $a0, $zero, 0x1
  .L800CB7CC:
    /* 62FCC 800CB7CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 62FD0 800CB7D0 00000000 */  nop
    /* 62FD4 800CB7D4 0800E003 */  jr         $ra
    /* 62FD8 800CB7D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB79C
