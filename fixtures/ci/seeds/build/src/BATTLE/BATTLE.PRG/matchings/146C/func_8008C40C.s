nonmatching func_8008C40C, 0x4C

glabel func_8008C40C
    /* 23C0C 8008C40C 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x64)
    /* 23C10 8008C410 5C1C428C */  lw         $v0, %lo(vs_battle_roomData + 0x64)($v0)
    /* 23C14 8008C414 00000000 */  nop
    /* 23C18 8008C418 0D004010 */  beqz       $v0, .L8008C450
    /* 23C1C 8008C41C 04004424 */   addiu     $a0, $v0, 0x4
    /* 23C20 8008C420 0000458C */  lw         $a1, 0x0($v0)
    /* 23C24 8008C424 00000000 */  nop
    /* 23C28 8008C428 0900A018 */  blez       $a1, .L8008C450
    /* 23C2C 8008C42C 21180000 */   addu      $v1, $zero, $zero
    /* 23C30 8008C430 FFEF0624 */  addiu      $a2, $zero, -0x1001
  .L8008C434:
    /* 23C34 8008C434 0000828C */  lw         $v0, 0x0($a0)
    /* 23C38 8008C438 01006324 */  addiu      $v1, $v1, 0x1
    /* 23C3C 8008C43C 24104600 */  and        $v0, $v0, $a2
    /* 23C40 8008C440 000082AC */  sw         $v0, 0x0($a0)
    /* 23C44 8008C444 2A106500 */  slt        $v0, $v1, $a1
    /* 23C48 8008C448 FAFF4014 */  bnez       $v0, .L8008C434
    /* 23C4C 8008C44C 40008424 */   addiu     $a0, $a0, 0x40
  .L8008C450:
    /* 23C50 8008C450 0800E003 */  jr         $ra
    /* 23C54 8008C454 00000000 */   nop
endlabel func_8008C40C
