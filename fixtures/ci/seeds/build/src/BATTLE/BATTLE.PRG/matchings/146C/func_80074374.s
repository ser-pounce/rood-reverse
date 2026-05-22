nonmatching func_80074374, 0x6C

glabel func_80074374
    /* BB74 80074374 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* BB78 80074378 21200000 */  addu       $a0, $zero, $zero
    /* BB7C 8007437C 1800A527 */  addiu      $a1, $sp, 0x18
    /* BB80 80074380 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* BB84 80074384 4284020C */  jal        func_800A1108
    /* BB88 80074388 2800B0AF */   sw        $s0, 0x28($sp)
    /* BB8C 8007438C 1000A427 */  addiu      $a0, $sp, 0x10
    /* BB90 80074390 01000524 */  addiu      $a1, $zero, 0x1
    /* BB94 80074394 1C00A397 */  lhu        $v1, 0x1C($sp)
    /* BB98 80074398 1E00A297 */  lhu        $v0, 0x1E($sp)
    /* BB9C 8007439C 2000A697 */  lhu        $a2, 0x20($sp)
    /* BBA0 800743A0 A6FF4224 */  addiu      $v0, $v0, -0x5A
    /* BBA4 800743A4 1400A6A7 */  sh         $a2, 0x14($sp)
    /* BBA8 800743A8 28000624 */  addiu      $a2, $zero, 0x28
    /* BBAC 800743AC 1000A3A7 */  sh         $v1, 0x10($sp)
    /* BBB0 800743B0 BFB7010C */  jal        _stepTowardTarget
    /* BBB4 800743B4 1200A2A7 */   sh        $v0, 0x12($sp)
    /* BBB8 800743B8 2079020C */  jal        func_8009E480
    /* BBBC 800743BC 21804000 */   addu      $s0, $v0, $zero
    /* BBC0 800743C0 21184000 */  addu       $v1, $v0, $zero
    /* BBC4 800743C4 02006014 */  bnez       $v1, .L800743D0
    /* BBC8 800743C8 21100000 */   addu      $v0, $zero, $zero
    /* BBCC 800743CC 21100002 */  addu       $v0, $s0, $zero
  .L800743D0:
    /* BBD0 800743D0 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* BBD4 800743D4 2800B08F */  lw         $s0, 0x28($sp)
    /* BBD8 800743D8 0800E003 */  jr         $ra
    /* BBDC 800743DC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80074374
