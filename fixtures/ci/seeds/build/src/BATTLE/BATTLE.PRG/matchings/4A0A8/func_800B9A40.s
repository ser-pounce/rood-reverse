nonmatching func_800B9A40, 0x54

glabel func_800B9A40
    /* 51240 800B9A40 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51244 800B9A44 1000B0AF */  sw         $s0, 0x10($sp)
    /* 51248 800B9A48 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5124C 800B9A4C E6F0010C */  jal        func_8007C398
    /* 51250 800B9A50 21808000 */   addu      $s0, $a0, $zero
    /* 51254 800B9A54 21184000 */  addu       $v1, $v0, $zero
    /* 51258 800B9A58 05000224 */  addiu      $v0, $zero, 0x5
    /* 5125C 800B9A5C 09006210 */  beq        $v1, $v0, .L800B9A84
    /* 51260 800B9A60 21100000 */   addu      $v0, $zero, $zero
    /* 51264 800B9A64 07006014 */  bnez       $v1, .L800B9A84
    /* 51268 800B9A68 01000224 */   addiu     $v0, $zero, 0x1
    /* 5126C 800B9A6C 03000692 */  lbu        $a2, 0x3($s0)
    /* 51270 800B9A70 01000492 */  lbu        $a0, 0x1($s0)
    /* 51274 800B9A74 02000592 */  lbu        $a1, 0x2($s0)
    /* 51278 800B9A78 1BF1010C */  jal        func_8007C46C
    /* 5127C 800B9A7C 00310600 */   sll       $a2, $a2, 4
    /* 51280 800B9A80 01000224 */  addiu      $v0, $zero, 0x1
  .L800B9A84:
    /* 51284 800B9A84 1400BF8F */  lw         $ra, 0x14($sp)
    /* 51288 800B9A88 1000B08F */  lw         $s0, 0x10($sp)
    /* 5128C 800B9A8C 0800E003 */  jr         $ra
    /* 51290 800B9A90 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9A40
