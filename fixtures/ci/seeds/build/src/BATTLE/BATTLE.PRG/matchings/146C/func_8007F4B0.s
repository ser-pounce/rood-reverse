nonmatching func_8007F4B0, 0x68

glabel func_8007F4B0
    /* 16CB0 8007F4B0 00210400 */  sll        $a0, $a0, 4
    /* 16CB4 8007F4B4 0580063C */  lui        $a2, %hi(D_8004EECC)
    /* 16CB8 8007F4B8 CCEEC624 */  addiu      $a2, $a2, %lo(D_8004EECC)
    /* 16CBC 8007F4BC 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 16CC0 8007F4C0 0000A290 */  lbu        $v0, 0x0($a1)
    /* 16CC4 8007F4C4 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 16CC8 8007F4C8 80100200 */  sll        $v0, $v0, 2
    /* 16CCC 8007F4CC 21104300 */  addu       $v0, $v0, $v1
    /* 16CD0 8007F4D0 0000428C */  lw         $v0, 0x0($v0)
    /* 16CD4 8007F4D4 21208600 */  addu       $a0, $a0, $a2
    /* 16CD8 8007F4D8 3C00458C */  lw         $a1, 0x3C($v0)
    /* 16CDC 8007F4DC 0000828C */  lw         $v0, 0x0($a0)
    /* 16CE0 8007F4E0 4409A38C */  lw         $v1, 0x944($a1)
    /* 16CE4 8007F4E4 00000000 */  nop
    /* 16CE8 8007F4E8 24104300 */  and        $v0, $v0, $v1
    /* 16CEC 8007F4EC 08004014 */  bnez       $v0, .L8007F510
    /* 16CF0 8007F4F0 01000224 */   addiu     $v0, $zero, 0x1
    /* 16CF4 8007F4F4 0C00838C */  lw         $v1, 0xC($a0)
    /* 16CF8 8007F4F8 4809A48C */  lw         $a0, 0x948($a1)
    /* 16CFC 8007F4FC 00000000 */  nop
    /* 16D00 8007F500 24186400 */  and        $v1, $v1, $a0
    /* 16D04 8007F504 02006010 */  beqz       $v1, .L8007F510
    /* 16D08 8007F508 21100000 */   addu      $v0, $zero, $zero
    /* 16D0C 8007F50C 01000224 */  addiu      $v0, $zero, 0x1
  .L8007F510:
    /* 16D10 8007F510 0800E003 */  jr         $ra
    /* 16D14 8007F514 00000000 */   nop
endlabel func_8007F4B0
