nonmatching func_8007647C, 0x134

glabel func_8007647C
    /* DC7C 8007647C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* DC80 80076480 1800B2AF */  sw         $s2, 0x18($sp)
    /* DC84 80076484 21908000 */  addu       $s2, $a0, $zero
    /* DC88 80076488 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* DC8C 8007648C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* DC90 80076490 80101200 */  sll        $v0, $s2, 2
    /* DC94 80076494 21104300 */  addu       $v0, $v0, $v1
    /* DC98 80076498 2000BFAF */  sw         $ra, 0x20($sp)
    /* DC9C 8007649C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* DCA0 800764A0 1400B1AF */  sw         $s1, 0x14($sp)
    /* DCA4 800764A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* DCA8 800764A8 0000518C */  lw         $s1, 0x0($v0)
    /* DCAC 800764AC 2198A000 */  addu       $s3, $a1, $zero
    /* DCB0 800764B0 3C00308E */  lw         $s0, 0x3C($s1)
    /* DCB4 800764B4 64090524 */  addiu      $a1, $zero, 0x964
    /* DCB8 800764B8 4424010C */  jal        vs_main_bzero
    /* DCBC 800764BC 21200002 */   addu      $a0, $s0, $zero
    /* DCC0 800764C0 21200000 */  addu       $a0, $zero, $zero
    /* DCC4 800764C4 0580023C */  lui        $v0, %hi(D_8004FDD0)
    /* DCC8 800764C8 D0FD4524 */  addiu      $a1, $v0, %lo(D_8004FDD0)
    /* DCCC 800764CC 01000224 */  addiu      $v0, $zero, 0x1
    /* DCD0 800764D0 1A0002A6 */  sh         $v0, 0x1A($s0)
    /* DCD4 800764D4 180002A6 */  sh         $v0, 0x18($s0)
    /* DCD8 800764D8 21108500 */  addu       $v0, $a0, $a1
  .L800764DC:
    /* DCDC 800764DC 3C00238E */  lw         $v1, 0x3C($s1)
    /* DCE0 800764E0 00004290 */  lbu        $v0, 0x0($v0)
    /* DCE4 800764E4 21186400 */  addu       $v1, $v1, $a0
    /* DCE8 800764E8 01008424 */  addiu      $a0, $a0, 0x1
    /* DCEC 800764EC 000062A0 */  sb         $v0, 0x0($v1)
    /* DCF0 800764F0 18008228 */  slti       $v0, $a0, 0x18
    /* DCF4 800764F4 F9FF4014 */  bnez       $v0, .L800764DC
    /* DCF8 800764F8 21108500 */   addu      $v0, $a0, $a1
    /* DCFC 800764FC FF006532 */  andi       $a1, $s3, 0xFF
    /* DD00 80076500 02000224 */  addiu      $v0, $zero, 0x2
    /* DD04 80076504 1500A210 */  beq        $a1, $v0, .L8007655C
    /* DD08 80076508 00000000 */   nop
    /* DD0C 8007650C 0300A228 */  slti       $v0, $a1, 0x3
    /* DD10 80076510 05004010 */  beqz       $v0, .L80076528
    /* DD14 80076514 01000224 */   addiu     $v0, $zero, 0x1
    /* DD18 80076518 0800A210 */  beq        $a1, $v0, .L8007653C
    /* DD1C 8007651C 21204002 */   addu      $a0, $s2, $zero
    /* DD20 80076520 5CD90108 */  j          .L80076570
    /* DD24 80076524 00000000 */   nop
  .L80076528:
    /* DD28 80076528 04000224 */  addiu      $v0, $zero, 0x4
    /* DD2C 8007652C 0C00A210 */  beq        $a1, $v0, .L80076560
    /* DD30 80076530 FEFF033C */   lui       $v1, (0xFFFEFFFF >> 16)
    /* DD34 80076534 5CD90108 */  j          .L80076570
    /* DD38 80076538 00000000 */   nop
  .L8007653C:
    /* DD3C 8007653C 08000524 */  addiu      $a1, $zero, 0x8
    /* DD40 80076540 5409028E */  lw         $v0, 0x954($s0)
    /* DD44 80076544 0100033C */  lui        $v1, (0x10000 >> 16)
    /* DD48 80076548 25104300 */  or         $v0, $v0, $v1
    /* DD4C 8007654C DF56020C */  jal        func_80095B7C
    /* DD50 80076550 540902AE */   sw        $v0, 0x954($s0)
    /* DD54 80076554 61D90108 */  j          .L80076584
    /* DD58 80076558 80000224 */   addiu     $v0, $zero, 0x80
  .L8007655C:
    /* DD5C 8007655C FEFF033C */  lui        $v1, (0xFFFEFFFF >> 16)
  .L80076560:
    /* DD60 80076560 5409028E */  lw         $v0, 0x954($s0)
    /* DD64 80076564 FFFF6334 */  ori        $v1, $v1, (0xFFFEFFFF & 0xFFFF)
    /* DD68 80076568 5FD90108 */  j          .L8007657C
    /* DD6C 8007656C 24104300 */   and       $v0, $v0, $v1
  .L80076570:
    /* DD70 80076570 5409028E */  lw         $v0, 0x954($s0)
    /* DD74 80076574 0100033C */  lui        $v1, (0x10000 >> 16)
    /* DD78 80076578 25104300 */  or         $v0, $v0, $v1
  .L8007657C:
    /* DD7C 8007657C 540902AE */  sw         $v0, 0x954($s0)
    /* DD80 80076580 80000224 */  addiu      $v0, $zero, 0x80
  .L80076584:
    /* DD84 80076584 270022A2 */  sb         $v0, 0x27($s1)
    /* DD88 80076588 290020A2 */  sb         $zero, 0x29($s1)
    /* DD8C 8007658C 280020A2 */  sb         $zero, 0x28($s1)
    /* DD90 80076590 570902A2 */  sb         $v0, 0x957($s0)
    /* DD94 80076594 2000BF8F */  lw         $ra, 0x20($sp)
    /* DD98 80076598 1C00B38F */  lw         $s3, 0x1C($sp)
    /* DD9C 8007659C 1800B28F */  lw         $s2, 0x18($sp)
    /* DDA0 800765A0 1400B18F */  lw         $s1, 0x14($sp)
    /* DDA4 800765A4 1000B08F */  lw         $s0, 0x10($sp)
    /* DDA8 800765A8 0800E003 */  jr         $ra
    /* DDAC 800765AC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007647C
