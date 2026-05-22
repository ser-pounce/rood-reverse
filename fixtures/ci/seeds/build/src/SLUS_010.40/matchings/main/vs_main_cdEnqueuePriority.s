nonmatching vs_main_cdEnqueuePriority, 0x78

glabel vs_main_cdEnqueuePriority
    /* 353F4 80044BF4 0580023C */  lui        $v0, %hi(_cdQueue)
    /* 353F8 80044BF8 E0014624 */  addiu      $a2, $v0, %lo(_cdQueue)
    /* 353FC 80044BFC 21380000 */  addu       $a3, $zero, $zero
    /* 35400 80044C00 03000824 */  addiu      $t0, $zero, 0x3
    /* 35404 80044C04 0200C324 */  addiu      $v1, $a2, 0x2
  .L80044C08:
    /* 35408 80044C08 0000C284 */  lh         $v0, 0x0($a2)
    /* 3540C 80044C0C 00000000 */  nop
    /* 35410 80044C10 05004814 */  bne        $v0, $t0, .L80044C28
    /* 35414 80044C14 00000000 */   nop
    /* 35418 80044C18 00006294 */  lhu        $v0, 0x0($v1)
    /* 3541C 80044C1C 00000000 */  nop
    /* 35420 80044C20 01004224 */  addiu      $v0, $v0, 0x1
    /* 35424 80044C24 000062A4 */  sh         $v0, 0x0($v1)
  .L80044C28:
    /* 35428 80044C28 0100E724 */  addiu      $a3, $a3, 0x1
    /* 3542C 80044C2C 14006324 */  addiu      $v1, $v1, 0x14
    /* 35430 80044C30 2000E228 */  slti       $v0, $a3, 0x20
    /* 35434 80044C34 F4FF4014 */  bnez       $v0, .L80044C08
    /* 35438 80044C38 1400C624 */   addiu     $a2, $a2, 0x14
    /* 3543C 80044C3C 03000224 */  addiu      $v0, $zero, 0x3
    /* 35440 80044C40 0580033C */  lui        $v1, %hi(_cdQueueCount)
    /* 35444 80044C44 60046324 */  addiu      $v1, $v1, %lo(_cdQueueCount)
    /* 35448 80044C48 000082A4 */  sh         $v0, 0x0($a0)
    /* 3544C 80044C4C 100085AC */  sw         $a1, 0x10($a0)
    /* 35450 80044C50 0C0080AC */  sw         $zero, 0xC($a0)
    /* 35454 80044C54 020080A4 */  sh         $zero, 0x2($a0)
    /* 35458 80044C58 02006294 */  lhu        $v0, 0x2($v1)
    /* 3545C 80044C5C 00000000 */  nop
    /* 35460 80044C60 01004224 */  addiu      $v0, $v0, 0x1
    /* 35464 80044C64 0800E003 */  jr         $ra
    /* 35468 80044C68 020062A4 */   sh        $v0, 0x2($v1)
endlabel vs_main_cdEnqueuePriority
