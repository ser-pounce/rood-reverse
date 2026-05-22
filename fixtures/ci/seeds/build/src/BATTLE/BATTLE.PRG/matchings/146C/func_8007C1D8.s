nonmatching func_8007C1D8, 0x40

glabel func_8007C1D8
    /* 139D8 8007C1D8 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 139DC 8007C1DC 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 139E0 8007C1E0 80200400 */  sll        $a0, $a0, 2
    /* 139E4 8007C1E4 21208200 */  addu       $a0, $a0, $v0
    /* 139E8 8007C1E8 0000848C */  lw         $a0, 0x0($a0)
    /* 139EC 8007C1EC 00000000 */  nop
    /* 139F0 8007C1F0 07008010 */  beqz       $a0, .L8007C210
    /* 139F4 8007C1F4 00000000 */   nop
    /* 139F8 8007C1F8 0400A010 */  beqz       $a1, .L8007C20C
    /* 139FC 8007C1FC 08000224 */   addiu     $v0, $zero, 0x8
    /* 13A00 8007C200 04000224 */  addiu      $v0, $zero, 0x4
    /* 13A04 8007C204 0800E003 */  jr         $ra
    /* 13A08 8007C208 1C0082A4 */   sh        $v0, 0x1C($a0)
  .L8007C20C:
    /* 13A0C 8007C20C 1C0082A4 */  sh         $v0, 0x1C($a0)
  .L8007C210:
    /* 13A10 8007C210 0800E003 */  jr         $ra
    /* 13A14 8007C214 00000000 */   nop
endlabel func_8007C1D8
