nonmatching func_800CF3F8, 0x60

glabel func_800CF3F8
    /* 66BF8 800CF3F8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 66BFC 800CF3FC 2000B0AF */  sw         $s0, 0x20($sp)
    /* 66C00 800CF400 21808000 */  addu       $s0, $a0, $zero
    /* 66C04 800CF404 2400B1AF */  sw         $s1, 0x24($sp)
    /* 66C08 800CF408 2188A000 */  addu       $s1, $a1, $zero
    /* 66C0C 800CF40C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 66C10 800CF410 245E030C */  jal        func_800D7890
    /* 66C14 800CF414 21200000 */   addu      $a0, $zero, $zero
    /* 66C18 800CF418 0F80043C */  lui        $a0, %hi(D_800F55A8)
    /* 66C1C 800CF41C C646030C */  jal        func_800D1B18
    /* 66C20 800CF420 A8558424 */   addiu     $a0, $a0, %lo(D_800F55A8)
    /* 66C24 800CF424 0F80043C */  lui        $a0, %hi(D_800F54D8)
    /* 66C28 800CF428 C646030C */  jal        func_800D1B18
    /* 66C2C 800CF42C D8548424 */   addiu     $a0, $a0, %lo(D_800F54D8)
    /* 66C30 800CF430 21200002 */  addu       $a0, $s0, $zero
    /* 66C34 800CF434 21280000 */  addu       $a1, $zero, $zero
    /* 66C38 800CF438 863C030C */  jal        func_800CF218
    /* 66C3C 800CF43C 21302002 */   addu      $a2, $s1, $zero
    /* 66C40 800CF440 2800BF8F */  lw         $ra, 0x28($sp)
    /* 66C44 800CF444 2400B18F */  lw         $s1, 0x24($sp)
    /* 66C48 800CF448 2000B08F */  lw         $s0, 0x20($sp)
    /* 66C4C 800CF44C FF004230 */  andi       $v0, $v0, 0xFF
    /* 66C50 800CF450 0800E003 */  jr         $ra
    /* 66C54 800CF454 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800CF3F8
