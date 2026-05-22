nonmatching DsSystemStatus, 0x4C

glabel DsSystemStatus
    /* 14C30 80024430 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14C34 80024434 21200000 */  addu       $a0, $zero, $zero
    /* 14C38 80024438 1400BFAF */  sw         $ra, 0x14($sp)
    /* 14C3C 8002443C 3E92000C */  jal        DS_system_status
    /* 14C40 80024440 1000B0AF */   sw        $s0, 0x10($sp)
    /* 14C44 80024444 21804000 */  addu       $s0, $v0, $zero
    /* 14C48 80024448 01000224 */  addiu      $v0, $zero, 0x1
    /* 14C4C 8002444C 07000216 */  bne        $s0, $v0, .L8002446C
    /* 14C50 80024450 21100002 */   addu      $v0, $s0, $zero
    /* 14C54 80024454 1F91000C */  jal        DsQueueLen
    /* 14C58 80024458 00000000 */   nop
    /* 14C5C 8002445C 03004018 */  blez       $v0, .L8002446C
    /* 14C60 80024460 21100002 */   addu      $v0, $s0, $zero
    /* 14C64 80024464 02001024 */  addiu      $s0, $zero, 0x2
    /* 14C68 80024468 21100002 */  addu       $v0, $s0, $zero
  .L8002446C:
    /* 14C6C 8002446C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 14C70 80024470 1000B08F */  lw         $s0, 0x10($sp)
    /* 14C74 80024474 0800E003 */  jr         $ra
    /* 14C78 80024478 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DsSystemStatus
