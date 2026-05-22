nonmatching vs_battle_script_jumpFwdIfFlagContext, 0x4C

glabel vs_battle_script_jumpFwdIfFlagContext
    /* 503F8 800B8BF8 0F80023C */  lui        $v0, %hi(D_800F4BB4)
    /* 503FC 800B8BFC B44B4390 */  lbu        $v1, %lo(D_800F4BB4)($v0)
    /* 50400 800B8C00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50404 800B8C04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50408 800B8C08 21808000 */  addu       $s0, $a0, $zero
    /* 5040C 800B8C0C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 50410 800B8C10 01000292 */  lbu        $v0, 0x1($s0)
    /* 50414 800B8C14 00000000 */  nop
    /* 50418 800B8C18 06006214 */  bne        $v1, $v0, .L800B8C34
    /* 5041C 800B8C1C 21100000 */   addu      $v0, $zero, $zero
    /* 50420 800B8C20 80FF020C */  jal        vs_battle_getShort
    /* 50424 800B8C24 02000426 */   addiu     $a0, $s0, 0x2
    /* 50428 800B8C28 00140200 */  sll        $v0, $v0, 16
    /* 5042C 800B8C2C 03140200 */  sra        $v0, $v0, 16
    /* 50430 800B8C30 21100202 */  addu       $v0, $s0, $v0
  .L800B8C34:
    /* 50434 800B8C34 1400BF8F */  lw         $ra, 0x14($sp)
    /* 50438 800B8C38 1000B08F */  lw         $s0, 0x10($sp)
    /* 5043C 800B8C3C 0800E003 */  jr         $ra
    /* 50440 800B8C40 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_jumpFwdIfFlagContext
