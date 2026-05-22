nonmatching func_800A2C48, 0x8C

glabel func_800A2C48
    /* 3A448 800A2C48 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3A44C 800A2C4C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3A450 800A2C50 21808000 */  addu       $s0, $a0, $zero
    /* 3A454 800A2C54 EC050526 */  addiu      $a1, $s0, 0x5EC
    /* 3A458 800A2C58 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3A45C 800A2C5C 0F000492 */  lbu        $a0, 0xF($s0)
    /* 3A460 800A2C60 15A7020C */  jal        func_800A9C54
    /* 3A464 800A2C64 21300000 */   addu      $a2, $zero, $zero
    /* 3A468 800A2C68 FFF0033C */  lui        $v1, (0xF0FFFFFF >> 16)
    /* 3A46C 800A2C6C FFFF6334 */  ori        $v1, $v1, (0xF0FFFFFF & 0xFFFF)
    /* 3A470 800A2C70 0800028E */  lw         $v0, 0x8($s0)
    /* 3A474 800A2C74 21200002 */  addu       $a0, $s0, $zero
    /* 3A478 800A2C78 E00600A2 */  sb         $zero, 0x6E0($s0)
    /* 3A47C 800A2C7C 24104300 */  and        $v0, $v0, $v1
    /* 3A480 800A2C80 0004033C */  lui        $v1, (0x4000000 >> 16)
    /* 3A484 800A2C84 25104300 */  or         $v0, $v0, $v1
    /* 3A488 800A2C88 688A020C */  jal        func_800A29A0
    /* 3A48C 800A2C8C 080002AE */   sw        $v0, 0x8($s0)
    /* 3A490 800A2C90 FD170292 */  lbu        $v0, 0x17FD($s0)
    /* 3A494 800A2C94 00000000 */  nop
    /* 3A498 800A2C98 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3A49C 800A2C9C 08004014 */  bnez       $v0, .L800A2CC0
    /* 3A4A0 800A2CA0 0F80033C */   lui       $v1, %hi(D_800F4538)
    /* 3A4A4 800A2CA4 FD170292 */  lbu        $v0, 0x17FD($s0)
    /* 3A4A8 800A2CA8 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 3A4AC 800A2CAC 80100200 */  sll        $v0, $v0, 2
    /* 3A4B0 800A2CB0 21104300 */  addu       $v0, $v0, $v1
    /* 3A4B4 800A2CB4 0000448C */  lw         $a0, 0x0($v0)
    /* 3A4B8 800A2CB8 128B020C */  jal        func_800A2C48
    /* 3A4BC 800A2CBC 00000000 */   nop
  .L800A2CC0:
    /* 3A4C0 800A2CC0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3A4C4 800A2CC4 1000B08F */  lw         $s0, 0x10($sp)
    /* 3A4C8 800A2CC8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 3A4CC 800A2CCC 0800E003 */  jr         $ra
    /* 3A4D0 800A2CD0 00000000 */   nop
endlabel func_800A2C48
