nonmatching func_8009FC20, 0x40

glabel func_8009FC20
    /* 37420 8009FC20 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 37424 8009FC24 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 37428 8009FC28 80200400 */  sll        $a0, $a0, 2
    /* 3742C 8009FC2C 21208200 */  addu       $a0, $a0, $v0
    /* 37430 8009FC30 0000848C */  lw         $a0, 0x0($a0)
    /* 37434 8009FC34 00000000 */  nop
    /* 37438 8009FC38 05008010 */  beqz       $a0, .L8009FC50
    /* 3743C 8009FC3C F8FFBD27 */   addiu     $sp, $sp, -0x8
    /* 37440 8009FC40 E5068390 */  lbu        $v1, 0x6E5($a0)
    /* 37444 8009FC44 21100000 */  addu       $v0, $zero, $zero
    /* 37448 8009FC48 157F0208 */  j          .L8009FC54
    /* 3744C 8009FC4C 0000A3AC */   sw        $v1, 0x0($a1)
  .L8009FC50:
    /* 37450 8009FC50 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8009FC54:
    /* 37454 8009FC54 0800BD27 */  addiu      $sp, $sp, 0x8
    /* 37458 8009FC58 0800E003 */  jr         $ra
    /* 3745C 8009FC5C 00000000 */   nop
endlabel func_8009FC20
