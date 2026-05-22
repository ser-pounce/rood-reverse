nonmatching func_80084B70, 0x13C

glabel func_80084B70
    /* 1C370 80084B70 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 1C374 80084B74 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1C378 80084B78 21988000 */  addu       $s3, $a0, $zero
    /* 1C37C 80084B7C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1C380 80084B80 2188C000 */  addu       $s1, $a2, $zero
    /* 1C384 80084B84 0F80083C */  lui        $t0, %hi(vs_battle_actors)
    /* 1C388 80084B88 28190825 */  addiu      $t0, $t0, %lo(vs_battle_actors)
    /* 1C38C 80084B8C 3000BFAF */  sw         $ra, 0x30($sp)
    /* 1C390 80084B90 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 1C394 80084B94 2800B4AF */  sw         $s4, 0x28($sp)
    /* 1C398 80084B98 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1C39C 80084B9C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1C3A0 80084BA0 0000A390 */  lbu        $v1, 0x0($a1)
    /* 1C3A4 80084BA4 00002292 */  lbu        $v0, 0x0($s1)
    /* 1C3A8 80084BA8 4800B58F */  lw         $s5, 0x48($sp)
    /* 1C3AC 80084BAC 80180300 */  sll        $v1, $v1, 2
    /* 1C3B0 80084BB0 21186800 */  addu       $v1, $v1, $t0
    /* 1C3B4 80084BB4 80100200 */  sll        $v0, $v0, 2
    /* 1C3B8 80084BB8 21104800 */  addu       $v0, $v0, $t0
    /* 1C3BC 80084BBC 0000638C */  lw         $v1, 0x0($v1)
    /* 1C3C0 80084BC0 0000428C */  lw         $v0, 0x0($v0)
    /* 1C3C4 80084BC4 3C00748C */  lw         $s4, 0x3C($v1)
    /* 1C3C8 80084BC8 3C00528C */  lw         $s2, 0x3C($v0)
    /* 1C3CC 80084BCC 0F80103C */  lui        $s0, %hi(D_800F1A0C)
    /* 1C3D0 80084BD0 0C1A00AE */  sw         $zero, %lo(D_800F1A0C)($s0)
    /* 1C3D4 80084BD4 3B0E020C */  jal        _calculateDamage
    /* 1C3D8 80084BD8 1000B5AF */   sw        $s5, 0x10($sp)
    /* 1C3DC 80084BDC 21304000 */  addu       $a2, $v0, $zero
    /* 1C3E0 80084BE0 04002296 */  lhu        $v0, 0x4($s1)
    /* 1C3E4 80084BE4 0C1A038E */  lw         $v1, %lo(D_800F1A0C)($s0)
    /* 1C3E8 80084BE8 21104600 */  addu       $v0, $v0, $a2
    /* 1C3EC 80084BEC 04006010 */  beqz       $v1, .L80084C00
    /* 1C3F0 80084BF0 040022A6 */   sh        $v0, 0x4($s1)
    /* 1C3F4 80084BF4 1C00228E */  lw         $v0, 0x1C($s1)
    /* 1C3F8 80084BF8 04130208 */  j          .L80084C10
    /* 1C3FC 80084BFC 03004234 */   ori       $v0, $v0, 0x3
  .L80084C00:
    /* 1C400 80084C00 1C00228E */  lw         $v0, 0x1C($s1)
    /* 1C404 80084C04 FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1C408 80084C08 24104300 */  and        $v0, $v0, $v1
    /* 1C40C 80084C0C 01004234 */  ori        $v0, $v0, 0x1
  .L80084C10:
    /* 1C410 80084C10 1C0022AE */  sw         $v0, 0x1C($s1)
    /* 1C414 80084C14 4000228E */  lw         $v0, 0x40($s1)
    /* 1C418 80084C18 00000000 */  nop
    /* 1C41C 80084C1C 1A004014 */  bnez       $v0, .L80084C88
    /* 1C420 80084C20 21206002 */   addu      $a0, $s3, $zero
    /* 1C424 80084C24 21282002 */  addu       $a1, $s1, $zero
    /* 1C428 80084C28 00140600 */  sll        $v0, $a2, 16
    /* 1C42C 80084C2C 03840200 */  sra        $s0, $v0, 16
    /* 1C430 80084C30 0000020C */  jal        func_80080000
    /* 1C434 80084C34 21300002 */   addu      $a2, $s0, $zero
    /* 1C438 80084C38 57094392 */  lbu        $v1, 0x957($s2)
    /* 1C43C 80084C3C 80000224 */  addiu      $v0, $zero, 0x80
    /* 1C440 80084C40 06006210 */  beq        $v1, $v0, .L80084C5C
    /* 1C444 80084C44 00000000 */   nop
    /* 1C448 80084C48 4809428E */  lw         $v0, 0x948($s2)
    /* 1C44C 80084C4C 1800238E */  lw         $v1, 0x18($s1)
    /* 1C450 80084C50 00804230 */  andi       $v0, $v0, 0x8000
    /* 1C454 80084C54 25186200 */  or         $v1, $v1, $v0
    /* 1C458 80084C58 180023AE */  sw         $v1, 0x18($s1)
  .L80084C5C:
    /* 1C45C 80084C5C 0A00A012 */  beqz       $s5, .L80084C88
    /* 1C460 80084C60 21206002 */   addu      $a0, $s3, $zero
    /* 1C464 80084C64 21288002 */  addu       $a1, $s4, $zero
    /* 1C468 80084C68 21304002 */  addu       $a2, $s2, $zero
    /* 1C46C 80084C6C B100020C */  jal        _adjustDpPp
    /* 1C470 80084C70 21380002 */   addu      $a3, $s0, $zero
    /* 1C474 80084C74 21206002 */  addu       $a0, $s3, $zero
    /* 1C478 80084C78 21288002 */  addu       $a1, $s4, $zero
    /* 1C47C 80084C7C 21304002 */  addu       $a2, $s2, $zero
    /* 1C480 80084C80 E900020C */  jal        func_800803A4
    /* 1C484 80084C84 21380002 */   addu      $a3, $s0, $zero
  .L80084C88:
    /* 1C488 80084C88 3000BF8F */  lw         $ra, 0x30($sp)
    /* 1C48C 80084C8C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 1C490 80084C90 2800B48F */  lw         $s4, 0x28($sp)
    /* 1C494 80084C94 2400B38F */  lw         $s3, 0x24($sp)
    /* 1C498 80084C98 2000B28F */  lw         $s2, 0x20($sp)
    /* 1C49C 80084C9C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1C4A0 80084CA0 1800B08F */  lw         $s0, 0x18($sp)
    /* 1C4A4 80084CA4 0800E003 */  jr         $ra
    /* 1C4A8 80084CA8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80084B70
