nonmatching func_800B8C54, 0x28

glabel func_800B8C54
    /* 50454 800B8C54 01008390 */  lbu        $v1, 0x1($a0)
    /* 50458 800B8C58 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 5045C 800B8C5C 05006210 */  beq        $v1, $v0, .L800B8C74
    /* 50460 800B8C60 0F80023C */   lui       $v0, %hi(D_800F4C10)
    /* 50464 800B8C64 104C4224 */  addiu      $v0, $v0, %lo(D_800F4C10)
    /* 50468 800B8C68 02008490 */  lbu        $a0, 0x2($a0)
    /* 5046C 800B8C6C 21186200 */  addu       $v1, $v1, $v0
    /* 50470 800B8C70 000064A0 */  sb         $a0, 0x0($v1)
  .L800B8C74:
    /* 50474 800B8C74 0800E003 */  jr         $ra
    /* 50478 800B8C78 21100000 */   addu      $v0, $zero, $zero
endlabel func_800B8C54
