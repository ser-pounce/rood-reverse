nonmatching func_8010BA58, 0xC8

glabel func_8010BA58
    /* 9258 8010BA58 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 925C 8010BA5C 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 9260 8010BA60 3845438C */  lw         $v1, %lo(D_800F4538)($v0)
    /* 9264 8010BA64 01000524 */  addiu      $a1, $zero, 0x1
    /* 9268 8010BA68 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 926C 8010BA6C 07008514 */  bne        $a0, $a1, .L8010BA8C
    /* 9270 8010BA70 2800B0AF */   sw        $s0, 0x28($sp)
    /* 9274 8010BA74 A16A020C */  jal        func_8009AA84
    /* 9278 8010BA78 2120A000 */   addu      $a0, $a1, $zero
    /* 927C 8010BA7C B3E8030C */  jal        func_800FA2CC
    /* 9280 8010BA80 00000000 */   nop
    /* 9284 8010BA84 C32E0408 */  j          .L8010BB0C
    /* 9288 8010BA88 21100000 */   addu      $v0, $zero, $zero
  .L8010BA8C:
    /* 928C 8010BA8C 0F80103C */  lui        $s0, %hi(D_800E8F28)
    /* 9290 8010BA90 288F0292 */  lbu        $v0, %lo(D_800E8F28)($s0)
    /* 9294 8010BA94 00000000 */  nop
    /* 9298 8010BA98 05004010 */  beqz       $v0, .L8010BAB0
    /* 929C 8010BA9C 00000000 */   nop
    /* 92A0 8010BAA0 10004510 */  beq        $v0, $a1, .L8010BAE4
    /* 92A4 8010BAA4 01000224 */   addiu     $v0, $zero, 0x1
    /* 92A8 8010BAA8 C32E0408 */  j          .L8010BB0C
    /* 92AC 8010BAAC 00000000 */   nop
  .L8010BAB0:
    /* 92B0 8010BAB0 B1056390 */  lbu        $v1, 0x5B1($v1)
    /* 92B4 8010BAB4 0A000224 */  addiu      $v0, $zero, 0xA
    /* 92B8 8010BAB8 14006210 */  beq        $v1, $v0, .L8010BB0C
    /* 92BC 8010BABC 21100000 */   addu      $v0, $zero, $zero
    /* 92C0 8010BAC0 A16A020C */  jal        func_8009AA84
    /* 92C4 8010BAC4 21200000 */   addu      $a0, $zero, $zero
    /* 92C8 8010BAC8 FFE8030C */  jal        func_800FA3FC
    /* 92CC 8010BACC 0A000424 */   addiu     $a0, $zero, 0xA
    /* 92D0 8010BAD0 288F0292 */  lbu        $v0, %lo(D_800E8F28)($s0)
    /* 92D4 8010BAD4 00000000 */  nop
    /* 92D8 8010BAD8 01004224 */  addiu      $v0, $v0, 0x1
    /* 92DC 8010BADC C22E0408 */  j          .L8010BB08
    /* 92E0 8010BAE0 288F02A2 */   sb        $v0, %lo(D_800E8F28)($s0)
  .L8010BAE4:
    /* 92E4 8010BAE4 9F65020C */  jal        vs_battle_processObjectDataQueue
    /* 92E8 8010BAE8 00000000 */   nop
    /* 92EC 8010BAEC 07004014 */  bnez       $v0, .L8010BB0C
    /* 92F0 8010BAF0 01000224 */   addiu     $v0, $zero, 0x1
    /* 92F4 8010BAF4 B3E8030C */  jal        func_800FA2CC
    /* 92F8 8010BAF8 00000000 */   nop
    /* 92FC 8010BAFC 288F00A2 */  sb         $zero, %lo(D_800E8F28)($s0)
    /* 9300 8010BB00 C32E0408 */  j          .L8010BB0C
    /* 9304 8010BB04 21100000 */   addu      $v0, $zero, $zero
  .L8010BB08:
    /* 9308 8010BB08 01000224 */  addiu      $v0, $zero, 0x1
  .L8010BB0C:
    /* 930C 8010BB0C 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 9310 8010BB10 2800B08F */  lw         $s0, 0x28($sp)
    /* 9314 8010BB14 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 9318 8010BB18 0800E003 */  jr         $ra
    /* 931C 8010BB1C 00000000 */   nop
endlabel func_8010BA58
