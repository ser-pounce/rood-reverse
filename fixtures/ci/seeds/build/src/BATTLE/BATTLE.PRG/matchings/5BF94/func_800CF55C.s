nonmatching func_800CF55C, 0xB8

glabel func_800CF55C
    /* 66D5C 800CF55C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 66D60 800CF560 1400B1AF */  sw         $s1, 0x14($sp)
    /* 66D64 800CF564 21888000 */  addu       $s1, $a0, $zero
    /* 66D68 800CF568 5C0D0424 */  addiu      $a0, $zero, 0xD5C
    /* 66D6C 800CF56C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 66D70 800CF570 8F0F010C */  jal        vs_main_allocHeapR
    /* 66D74 800CF574 1000B0AF */   sw        $s0, 0x10($sp)
    /* 66D78 800CF578 21202002 */  addu       $a0, $s1, $zero
    /* 66D7C 800CF57C 21804000 */  addu       $s0, $v0, $zero
    /* 66D80 800CF580 C539030C */  jal        func_800CE714
    /* 66D84 800CF584 21280002 */   addu      $a1, $s0, $zero
    /* 66D88 800CF588 0F80043C */  lui        $a0, %hi(D_800F54B0)
    /* 66D8C 800CF58C B054858C */  lw         $a1, %lo(D_800F54B0)($a0)
    /* 66D90 800CF590 00000000 */  nop
    /* 66D94 800CF594 0700A010 */  beqz       $a1, .L800CF5B4
    /* 66D98 800CF598 00000000 */   nop
    /* 66D9C 800CF59C 0900A390 */  lbu        $v1, 0x9($a1)
    /* 66DA0 800CF5A0 1000228E */  lw         $v0, 0x10($s1)
    /* 66DA4 800CF5A4 00000000 */  nop
    /* 66DA8 800CF5A8 2A104300 */  slt        $v0, $v0, $v1
    /* 66DAC 800CF5AC 04004010 */  beqz       $v0, .L800CF5C0
    /* 66DB0 800CF5B0 00000000 */   nop
  .L800CF5B4:
    /* 66DB4 800CF5B4 000005AE */  sw         $a1, 0x0($s0)
    /* 66DB8 800CF5B8 7F3D0308 */  j          .L800CF5FC
    /* 66DBC 800CF5BC B05490AC */   sw        $s0, %lo(D_800F54B0)($a0)
  .L800CF5C0:
    /* 66DC0 800CF5C0 0000A48C */  lw         $a0, 0x0($a1)
    /* 66DC4 800CF5C4 00000000 */  nop
    /* 66DC8 800CF5C8 07008010 */  beqz       $a0, .L800CF5E8
    /* 66DCC 800CF5CC 00000000 */   nop
    /* 66DD0 800CF5D0 09008390 */  lbu        $v1, 0x9($a0)
    /* 66DD4 800CF5D4 1000228E */  lw         $v0, 0x10($s1)
    /* 66DD8 800CF5D8 00000000 */  nop
    /* 66DDC 800CF5DC 2A104300 */  slt        $v0, $v0, $v1
    /* 66DE0 800CF5E0 04004010 */  beqz       $v0, .L800CF5F4
    /* 66DE4 800CF5E4 00000000 */   nop
  .L800CF5E8:
    /* 66DE8 800CF5E8 000004AE */  sw         $a0, 0x0($s0)
    /* 66DEC 800CF5EC 7F3D0308 */  j          .L800CF5FC
    /* 66DF0 800CF5F0 0000B0AC */   sw        $s0, 0x0($a1)
  .L800CF5F4:
    /* 66DF4 800CF5F4 703D0308 */  j          .L800CF5C0
    /* 66DF8 800CF5F8 21288000 */   addu      $a1, $a0, $zero
  .L800CF5FC:
    /* 66DFC 800CF5FC 21100002 */  addu       $v0, $s0, $zero
    /* 66E00 800CF600 1800BF8F */  lw         $ra, 0x18($sp)
    /* 66E04 800CF604 1400B18F */  lw         $s1, 0x14($sp)
    /* 66E08 800CF608 1000B08F */  lw         $s0, 0x10($sp)
    /* 66E0C 800CF60C 0800E003 */  jr         $ra
    /* 66E10 800CF610 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CF55C
