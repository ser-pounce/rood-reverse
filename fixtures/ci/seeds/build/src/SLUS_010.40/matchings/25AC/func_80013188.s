nonmatching func_80013188, 0x54

glabel func_80013188
    /* 3988 80013188 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 398C 8001318C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 3990 80013190 21808000 */  addu       $s0, $a0, $zero
    /* 3994 80013194 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 3998 80013198 2188A000 */  addu       $s1, $a1, $zero
    /* 399C 8001319C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 39A0 800131A0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 39A4 800131A4 054B000C */  jal        func_80012C14
    /* 39A8 800131A8 1400A627 */   addiu     $a2, $sp, 0x14
    /* 39AC 800131AC 21200002 */  addu       $a0, $s0, $zero
    /* 39B0 800131B0 21282002 */  addu       $a1, $s1, $zero
    /* 39B4 800131B4 1000A68F */  lw         $a2, 0x10($sp)
    /* 39B8 800131B8 1400A78F */  lw         $a3, 0x14($sp)
    /* 39BC 800131BC 764D000C */  jal        func_800135D8
    /* 39C0 800131C0 21804000 */   addu      $s0, $v0, $zero
    /* 39C4 800131C4 21100002 */  addu       $v0, $s0, $zero
    /* 39C8 800131C8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 39CC 800131CC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 39D0 800131D0 1800B08F */  lw         $s0, 0x18($sp)
    /* 39D4 800131D4 0800E003 */  jr         $ra
    /* 39D8 800131D8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80013188
