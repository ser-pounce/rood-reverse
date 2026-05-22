nonmatching CdIntstr, 0x34

glabel CdIntstr
    /* 10CC4 800204C4 FF008430 */  andi       $a0, $a0, 0xFF
    /* 10CC8 800204C8 0700822C */  sltiu      $v0, $a0, 0x7
    /* 10CCC 800204CC 06004010 */  beqz       $v0, .L800204E8
    /* 10CD0 800204D0 80100400 */   sll       $v0, $a0, 2
    /* 10CD4 800204D4 0380013C */  lui        $at, %hi(D_800322A0)
    /* 10CD8 800204D8 21082200 */  addu       $at, $at, $v0
    /* 10CDC 800204DC A022228C */  lw         $v0, %lo(D_800322A0)($at)
    /* 10CE0 800204E0 3C810008 */  j          .L800204F0
    /* 10CE4 800204E4 00000000 */   nop
  .L800204E8:
    /* 10CE8 800204E8 0180023C */  lui        $v0, %hi(D_80010284)
    /* 10CEC 800204EC 84024224 */  addiu      $v0, $v0, %lo(D_80010284)
  .L800204F0:
    /* 10CF0 800204F0 0800E003 */  jr         $ra
    /* 10CF4 800204F4 00000000 */   nop
endlabel CdIntstr
