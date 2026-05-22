nonmatching CdReset, 0x6C

glabel CdReset
    /* 10BF0 800203F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10BF4 800203F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 10BF8 800203F8 21808000 */  addu       $s0, $a0, $zero
    /* 10BFC 800203FC 02000224 */  addiu      $v0, $zero, 0x2
    /* 10C00 80020400 05000216 */  bne        $s0, $v0, .L80020418
    /* 10C04 80020404 1400BFAF */   sw        $ra, 0x14($sp)
    /* 10C08 80020408 B286000C */  jal        CD_initintr
    /* 10C0C 8002040C 00000000 */   nop
    /* 10C10 80020410 13810008 */  j          .L8002044C
    /* 10C14 80020414 01000224 */   addiu     $v0, $zero, 0x1
  .L80020418:
    /* 10C18 80020418 C586000C */  jal        CD_init
    /* 10C1C 8002041C 00000000 */   nop
    /* 10C20 80020420 0A004014 */  bnez       $v0, .L8002044C
    /* 10C24 80020424 21100000 */   addu      $v0, $zero, $zero
    /* 10C28 80020428 01000224 */  addiu      $v0, $zero, 0x1
    /* 10C2C 8002042C 07000216 */  bne        $s0, $v0, .L8002044C
    /* 10C30 80020430 00000000 */   nop
    /* 10C34 80020434 7686000C */  jal        CD_initvol
    /* 10C38 80020438 00000000 */   nop
    /* 10C3C 8002043C 21184000 */  addu       $v1, $v0, $zero
    /* 10C40 80020440 02006014 */  bnez       $v1, .L8002044C
    /* 10C44 80020444 21100000 */   addu      $v0, $zero, $zero
    /* 10C48 80020448 01000224 */  addiu      $v0, $zero, 0x1
  .L8002044C:
    /* 10C4C 8002044C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 10C50 80020450 1000B08F */  lw         $s0, 0x10($sp)
    /* 10C54 80020454 0800E003 */  jr         $ra
    /* 10C58 80020458 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel CdReset
