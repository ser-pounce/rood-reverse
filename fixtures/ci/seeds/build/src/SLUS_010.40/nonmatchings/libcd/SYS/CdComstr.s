nonmatching CdComstr, 0x34

glabel CdComstr
    /* 10C90 80020490 FF008430 */  andi       $a0, $a0, 0xFF
    /* 10C94 80020494 1C00822C */  sltiu      $v0, $a0, 0x1C
    /* 10C98 80020498 06004010 */  beqz       $v0, .L800204B4
    /* 10C9C 8002049C 80100400 */   sll       $v0, $a0, 2
    /* 10CA0 800204A0 0380013C */  lui        $at, %hi(D_80032220)
    /* 10CA4 800204A4 21082200 */  addu       $at, $at, $v0
    /* 10CA8 800204A8 2022228C */  lw         $v0, %lo(D_80032220)($at)
    /* 10CAC 800204AC 2F810008 */  j          .L800204BC
    /* 10CB0 800204B0 00000000 */   nop
  .L800204B4:
    /* 10CB4 800204B4 0180023C */  lui        $v0, %hi(D_80010284)
    /* 10CB8 800204B8 84024224 */  addiu      $v0, $v0, %lo(D_80010284)
  .L800204BC:
    /* 10CBC 800204BC 0800E003 */  jr         $ra
    /* 10CC0 800204C0 00000000 */   nop
endlabel CdComstr
