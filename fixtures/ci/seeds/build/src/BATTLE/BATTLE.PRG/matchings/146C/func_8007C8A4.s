nonmatching func_8007C8A4, 0x4C

glabel func_8007C8A4
    /* 140A4 8007C8A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 140A8 8007C8A8 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 140AC 8007C8AC 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 140B0 8007C8B0 80100400 */  sll        $v0, $a0, 2
    /* 140B4 8007C8B4 21104300 */  addu       $v0, $v0, $v1
    /* 140B8 8007C8B8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 140BC 8007C8BC 0000438C */  lw         $v1, 0x0($v0)
    /* 140C0 8007C8C0 00000000 */  nop
    /* 140C4 8007C8C4 06006010 */  beqz       $v1, .L8007C8E0
    /* 140C8 8007C8C8 10008228 */   slti      $v0, $a0, 0x10
    /* 140CC 8007C8CC 04004010 */  beqz       $v0, .L8007C8E0
    /* 140D0 8007C8D0 00000000 */   nop
    /* 140D4 8007C8D4 4400648C */  lw         $a0, 0x44($v1)
    /* 140D8 8007C8D8 3FB9020C */  jal        func_800AE4FC
    /* 140DC 8007C8DC 00000000 */   nop
  .L8007C8E0:
    /* 140E0 8007C8E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 140E4 8007C8E4 00000000 */  nop
    /* 140E8 8007C8E8 0800E003 */  jr         $ra
    /* 140EC 8007C8EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C8A4
