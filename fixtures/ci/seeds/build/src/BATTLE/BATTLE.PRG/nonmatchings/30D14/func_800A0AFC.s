nonmatching func_800A0AFC, 0x60

glabel func_800A0AFC
    /* 382FC 800A0AFC 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 38300 800A0B00 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 38304 800A0B04 80200400 */  sll        $a0, $a0, 2
    /* 38308 800A0B08 21208200 */  addu       $a0, $a0, $v0
    /* 3830C 800A0B0C 0000848C */  lw         $a0, 0x0($a0)
    /* 38310 800A0B10 00000000 */  nop
    /* 38314 800A0B14 0F008010 */  beqz       $a0, .L800A0B54
    /* 38318 800A0B18 00000000 */   nop
    /* 3831C 800A0B1C 0200A104 */  bgez       $a1, .L800A0B28
    /* 38320 800A0B20 2110A000 */   addu      $v0, $a1, $zero
    /* 38324 800A0B24 FF0FA224 */  addiu      $v0, $a1, 0xFFF
  .L800A0B28:
    /* 38328 800A0B28 03130200 */  sra        $v0, $v0, 12
    /* 3832C 800A0B2C BA0582A0 */  sb         $v0, 0x5BA($a0)
    /* 38330 800A0B30 0200C104 */  bgez       $a2, .L800A0B3C
    /* 38334 800A0B34 2110C000 */   addu      $v0, $a2, $zero
    /* 38338 800A0B38 FF0FC224 */  addiu      $v0, $a2, 0xFFF
  .L800A0B3C:
    /* 3833C 800A0B3C 03130200 */  sra        $v0, $v0, 12
    /* 38340 800A0B40 B90582A0 */  sb         $v0, 0x5B9($a0)
    /* 38344 800A0B44 2A10A600 */  slt        $v0, $a1, $a2
    /* 38348 800A0B48 02004014 */  bnez       $v0, .L800A0B54
    /* 3834C 800A0B4C FF000224 */   addiu     $v0, $zero, 0xFF
    /* 38350 800A0B50 B90582A0 */  sb         $v0, 0x5B9($a0)
  .L800A0B54:
    /* 38354 800A0B54 0800E003 */  jr         $ra
    /* 38358 800A0B58 00000000 */   nop
endlabel func_800A0AFC
