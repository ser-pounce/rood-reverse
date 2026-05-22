nonmatching func_800D6298, 0x78

glabel func_800D6298
    /* 6DA98 800D6298 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6DA9C 800D629C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6DAA0 800D62A0 2180A000 */  addu       $s0, $a1, $zero
    /* 6DAA4 800D62A4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6DAA8 800D62A8 06000286 */  lh         $v0, 0x6($s0)
    /* 6DAAC 800D62AC 0000038E */  lw         $v1, 0x0($s0)
    /* 6DAB0 800D62B0 C0100200 */  sll        $v0, $v0, 3
    /* 6DAB4 800D62B4 21386200 */  addu       $a3, $v1, $v0
    /* 6DAB8 800D62B8 4C0D828C */  lw         $v0, 0xD4C($a0)
    /* 6DABC 800D62BC 0000E384 */  lh         $v1, 0x0($a3)
    /* 6DAC0 800D62C0 02004284 */  lh         $v0, 0x2($v0)
    /* 6DAC4 800D62C4 00000000 */  nop
    /* 6DAC8 800D62C8 0D006214 */  bne        $v1, $v0, .L800D6300
    /* 6DACC 800D62CC 01000224 */   addiu     $v0, $zero, 0x1
    /* 6DAD0 800D62D0 0700E490 */  lbu        $a0, 0x7($a3)
    /* 6DAD4 800D62D4 0200E584 */  lh         $a1, 0x2($a3)
    /* 6DAD8 800D62D8 0400E690 */  lbu        $a2, 0x4($a3)
    /* 6DADC 800D62DC 0600E290 */  lbu        $v0, 0x6($a3)
    /* 6DAE0 800D62E0 0500E790 */  lbu        $a3, 0x5($a3)
    /* 6DAE4 800D62E4 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 6DAE8 800D62E8 80FFC624 */  addiu      $a2, $a2, -0x80
    /* 6DAEC 800D62EC 80FFE724 */  addiu      $a3, $a3, -0x80
    /* 6DAF0 800D62F0 6EEC010C */  jal        func_8007B1B8
    /* 6DAF4 800D62F4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 6DAF8 800D62F8 E055030C */  jal        func_800D5780
    /* 6DAFC 800D62FC 21200002 */   addu      $a0, $s0, $zero
  .L800D6300:
    /* 6DB00 800D6300 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6DB04 800D6304 1800B08F */  lw         $s0, 0x18($sp)
    /* 6DB08 800D6308 0800E003 */  jr         $ra
    /* 6DB0C 800D630C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D6298
