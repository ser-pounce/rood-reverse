nonmatching func_800CF514, 0x48

glabel func_800CF514
    /* 66D14 800CF514 21288000 */  addu       $a1, $a0, $zero
    /* 66D18 800CF518 2118A000 */  addu       $v1, $a1, $zero
    /* 66D1C 800CF51C 0F80023C */  lui        $v0, %hi(D_800F5320)
    /* 66D20 800CF520 0200A104 */  bgez       $a1, .L800CF52C
    /* 66D24 800CF524 20534224 */   addiu     $v0, $v0, %lo(D_800F5320)
    /* 66D28 800CF528 1F00A324 */  addiu      $v1, $a1, 0x1F
  .L800CF52C:
    /* 66D2C 800CF52C 43190300 */  sra        $v1, $v1, 5
    /* 66D30 800CF530 80200300 */  sll        $a0, $v1, 2
    /* 66D34 800CF534 21208200 */  addu       $a0, $a0, $v0
    /* 66D38 800CF538 40190300 */  sll        $v1, $v1, 5
    /* 66D3C 800CF53C 2318A300 */  subu       $v1, $a1, $v1
    /* 66D40 800CF540 01000224 */  addiu      $v0, $zero, 0x1
    /* 66D44 800CF544 04106200 */  sllv       $v0, $v0, $v1
    /* 66D48 800CF548 0000838C */  lw         $v1, 0x0($a0)
    /* 66D4C 800CF54C 27100200 */  nor        $v0, $zero, $v0
    /* 66D50 800CF550 24186200 */  and        $v1, $v1, $v0
    /* 66D54 800CF554 0800E003 */  jr         $ra
    /* 66D58 800CF558 000083AC */   sw        $v1, 0x0($a0)
endlabel func_800CF514
