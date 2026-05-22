nonmatching vs_main_panSfx, 0x80

glabel vs_main_panSfx
    /* 362A8 80045AA8 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 362AC 80045AAC 2800B2AF */  sw         $s2, 0x28($sp)
    /* 362B0 80045AB0 21908000 */  addu       $s2, $a0, $zero
    /* 362B4 80045AB4 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 362B8 80045AB8 2198A000 */  addu       $s3, $a1, $zero
    /* 362BC 80045ABC 2400B1AF */  sw         $s1, 0x24($sp)
    /* 362C0 80045AC0 2188C000 */  addu       $s1, $a2, $zero
    /* 362C4 80045AC4 2000B0AF */  sw         $s0, 0x20($sp)
    /* 362C8 80045AC8 801F103C */  lui        $s0, %hi(D_1F800014_mat)
    /* 362CC 80045ACC 14001026 */  addiu      $s0, $s0, %lo(D_1F800014_mat)
    /* 362D0 80045AD0 3000BFAF */  sw         $ra, 0x30($sp)
    /* 362D4 80045AD4 6605010C */  jal        SetRotMatrix
    /* 362D8 80045AD8 21200002 */   addu      $a0, $s0, $zero
    /* 362DC 80045ADC 5E05010C */  jal        SetTransMatrix
    /* 362E0 80045AE0 21200002 */   addu      $a0, $s0, $zero
    /* 362E4 80045AE4 21202002 */  addu       $a0, $s1, $zero
    /* 362E8 80045AE8 1000A527 */  addiu      $a1, $sp, 0x10
    /* 362EC 80045AEC 1400A627 */  addiu      $a2, $sp, 0x14
    /* 362F0 80045AF0 0506010C */  jal        RotTransPers
    /* 362F4 80045AF4 1800A727 */   addiu     $a3, $sp, 0x18
    /* 362F8 80045AF8 21204002 */  addu       $a0, $s2, $zero
    /* 362FC 80045AFC 21286002 */  addu       $a1, $s3, $zero
    /* 36300 80045B00 1000A68F */  lw         $a2, 0x10($sp)
    /* 36304 80045B04 9616010C */  jal        _do_panSfx
    /* 36308 80045B08 21384000 */   addu      $a3, $v0, $zero
    /* 3630C 80045B0C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 36310 80045B10 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 36314 80045B14 2800B28F */  lw         $s2, 0x28($sp)
    /* 36318 80045B18 2400B18F */  lw         $s1, 0x24($sp)
    /* 3631C 80045B1C 2000B08F */  lw         $s0, 0x20($sp)
    /* 36320 80045B20 0800E003 */  jr         $ra
    /* 36324 80045B24 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel vs_main_panSfx
