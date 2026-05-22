nonmatching DsFlush, 0x90

glabel DsFlush
    /* 14BA0 800243A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14BA4 800243A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14BA8 800243A8 B895000C */  jal        DS_stop
    /* 14BAC 800243AC 00000000 */   nop
    /* 14BB0 800243B0 21280000 */  addu       $a1, $zero, $zero
    /* 14BB4 800243B4 0480043C */  lui        $a0, %hi(D_80039CF0)
    /* 14BB8 800243B8 F09C8424 */  addiu      $a0, $a0, %lo(D_80039CF0)
    /* 14BBC 800243BC 0480013C */  lui        $at, %hi(D_80039DB8)
    /* 14BC0 800243C0 B89D20AC */  sw         $zero, %lo(D_80039DB8)($at)
    /* 14BC4 800243C4 0480013C */  lui        $at, %hi(D_80039DB4)
    /* 14BC8 800243C8 B49D20AC */  sw         $zero, %lo(D_80039DB4)($at)
    /* 14BCC 800243CC 0480013C */  lui        $at, %hi(D_80039DB0)
    /* 14BD0 800243D0 B09D20AC */  sw         $zero, %lo(D_80039DB0)($at)
  .L800243D4:
    /* 14BD4 800243D4 03000324 */  addiu      $v1, $zero, 0x3
    /* 14BD8 800243D8 03008224 */  addiu      $v0, $a0, 0x3
    /* 14BDC 800243DC 000080AC */  sw         $zero, 0x0($a0)
    /* 14BE0 800243E0 040080A0 */  sb         $zero, 0x4($a0)
  .L800243E4:
    /* 14BE4 800243E4 050040A0 */  sb         $zero, 0x5($v0)
    /* 14BE8 800243E8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 14BEC 800243EC FDFF6104 */  bgez       $v1, .L800243E4
    /* 14BF0 800243F0 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 14BF4 800243F4 0C0080AC */  sw         $zero, 0xC($a0)
    /* 14BF8 800243F8 100080AC */  sw         $zero, 0x10($a0)
    /* 14BFC 800243FC 140080AC */  sw         $zero, 0x14($a0)
    /* 14C00 80024400 0100A524 */  addiu      $a1, $a1, 0x1
    /* 14C04 80024404 0800A228 */  slti       $v0, $a1, 0x8
    /* 14C08 80024408 F2FF4014 */  bnez       $v0, .L800243D4
    /* 14C0C 8002440C 18008424 */   addiu     $a0, $a0, 0x18
    /* 14C10 80024410 BA98000C */  jal        DsEndReadySystem
    /* 14C14 80024414 00000000 */   nop
    /* 14C18 80024418 D695000C */  jal        DS_restart
    /* 14C1C 8002441C 00000000 */   nop
    /* 14C20 80024420 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14C24 80024424 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 14C28 80024428 0800E003 */  jr         $ra
    /* 14C2C 8002442C 00000000 */   nop
endlabel DsFlush
