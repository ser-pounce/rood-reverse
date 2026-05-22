nonmatching _getAbilityDescription, 0x48

glabel _getAbilityDescription
    /* 15D8 80103DD8 1080023C */  lui        $v0, %hi(abilityDescLookup)
    /* 15DC 80103DDC 78504224 */  addiu      $v0, $v0, %lo(abilityDescLookup)
    /* 15E0 80103DE0 21208200 */  addu       $a0, $a0, $v0
    /* 15E4 80103DE4 00008390 */  lbu        $v1, 0x0($a0)
    /* 15E8 80103DE8 00000000 */  nop
    /* 15EC 80103DEC 09006010 */  beqz       $v1, .L80103E14
    /* 15F0 80103DF0 40180300 */   sll       $v1, $v1, 1
    /* 15F4 80103DF4 1080023C */  lui        $v0, %hi(_battleAbilityStrings)
    /* 15F8 80103DF8 90464224 */  addiu      $v0, $v0, %lo(_battleAbilityStrings)
    /* 15FC 80103DFC 21186200 */  addu       $v1, $v1, $v0
    /* 1600 80103E00 00006394 */  lhu        $v1, 0x0($v1)
    /* 1604 80103E04 00000000 */  nop
    /* 1608 80103E08 40180300 */  sll        $v1, $v1, 1
    /* 160C 80103E0C 0800E003 */  jr         $ra
    /* 1610 80103E10 21106200 */   addu      $v0, $v1, $v0
  .L80103E14:
    /* 1614 80103E14 1080023C */  lui        $v0, %hi(D_8010505A)
    /* 1618 80103E18 0800E003 */  jr         $ra
    /* 161C 80103E1C 5A504224 */   addiu     $v0, $v0, %lo(D_8010505A)
endlabel _getAbilityDescription
