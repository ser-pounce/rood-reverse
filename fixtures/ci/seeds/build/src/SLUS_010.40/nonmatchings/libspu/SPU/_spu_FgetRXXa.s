nonmatching _spu_FgetRXXa, 0x3C

glabel _spu_FgetRXXa
    /* EC48 8001E448 0380023C */  lui        $v0, %hi(D_80030860)
    /* EC4C 8001E44C 6008428C */  lw         $v0, %lo(D_80030860)($v0)
    /* EC50 8001E450 40200400 */  sll        $a0, $a0, 1
    /* EC54 8001E454 21208200 */  addu       $a0, $a0, $v0
    /* EC58 8001E458 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* EC5C 8001E45C 00008494 */  lhu        $a0, 0x0($a0)
    /* EC60 8001E460 0500A210 */  beq        $a1, $v0, .L8001E478
    /* EC64 8001E464 00000000 */   nop
    /* EC68 8001E468 0380023C */  lui        $v0, %hi(D_80030888)
    /* EC6C 8001E46C 8808428C */  lw         $v0, %lo(D_80030888)($v0)
    /* EC70 8001E470 1F790008 */  j          .L8001E47C
    /* EC74 8001E474 04104400 */   sllv      $v0, $a0, $v0
  .L8001E478:
    /* EC78 8001E478 21108000 */  addu       $v0, $a0, $zero
  .L8001E47C:
    /* EC7C 8001E47C 0800E003 */  jr         $ra
    /* EC80 8001E480 00000000 */   nop
endlabel _spu_FgetRXXa
