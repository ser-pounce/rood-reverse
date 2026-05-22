nonmatching vs_main_checkStreamXaEnd, 0x28

glabel vs_main_checkStreamXaEnd
    /* 35238 80044A38 0580043C */  lui        $a0, %hi(vs_main_disk)
    /* 3523C 80044A3C 105D8390 */  lbu        $v1, %lo(vs_main_disk)($a0)
    /* 35240 80044A40 07000224 */  addiu      $v0, $zero, 0x7
    /* 35244 80044A44 03006210 */  beq        $v1, $v0, .L80044A54
    /* 35248 80044A48 09000224 */   addiu     $v0, $zero, 0x9
    /* 3524C 80044A4C 0800E003 */  jr         $ra
    /* 35250 80044A50 21100000 */   addu      $v0, $zero, $zero
  .L80044A54:
    /* 35254 80044A54 105D82A0 */  sb         $v0, %lo(vs_main_disk)($a0)
    /* 35258 80044A58 0800E003 */  jr         $ra
    /* 3525C 80044A5C 01000224 */   addiu     $v0, $zero, 0x1
endlabel vs_main_checkStreamXaEnd
