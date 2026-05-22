nonmatching func_8008418C, 0x3C

glabel func_8008418C
    /* 1B98C 8008418C 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1B990 80084190 0000C290 */  lbu        $v0, 0x0($a2)
    /* 1B994 80084194 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1B998 80084198 80100200 */  sll        $v0, $v0, 2
    /* 1B99C 8008419C 21104300 */  addu       $v0, $v0, $v1
    /* 1B9A0 800841A0 0000428C */  lw         $v0, 0x0($v0)
    /* 1B9A4 800841A4 FE1F043C */  lui        $a0, (0x1FFE1FE0 >> 16)
    /* 1B9A8 800841A8 3C00428C */  lw         $v0, 0x3C($v0)
    /* 1B9AC 800841AC E01F8434 */  ori        $a0, $a0, (0x1FFE1FE0 & 0xFFFF)
    /* 1B9B0 800841B0 4809428C */  lw         $v0, 0x948($v0)
    /* 1B9B4 800841B4 1800C38C */  lw         $v1, 0x18($a2)
    /* 1B9B8 800841B8 24104400 */  and        $v0, $v0, $a0
    /* 1B9BC 800841BC 25186200 */  or         $v1, $v1, $v0
    /* 1B9C0 800841C0 0800E003 */  jr         $ra
    /* 1B9C4 800841C4 1800C3AC */   sw        $v1, 0x18($a2)
endlabel func_8008418C
