nonmatching func_800D2888, 0x7C

glabel func_800D2888
    /* 6A088 800D2888 21308000 */  addu       $a2, $a0, $zero
    /* 6A08C 800D288C 0400C38C */  lw         $v1, 0x4($a2)
    /* 6A090 800D2890 00000000 */  nop
    /* 6A094 800D2894 04006010 */  beqz       $v1, .L800D28A8
    /* 6A098 800D2898 2138A000 */   addu      $a3, $a1, $zero
    /* 6A09C 800D289C 0000C28C */  lw         $v0, 0x0($a2)
    /* 6A0A0 800D28A0 00000000 */  nop
    /* 6A0A4 800D28A4 000062AC */  sw         $v0, 0x0($v1)
  .L800D28A8:
    /* 6A0A8 800D28A8 0000C38C */  lw         $v1, 0x0($a2)
    /* 6A0AC 800D28AC 00000000 */  nop
    /* 6A0B0 800D28B0 04006010 */  beqz       $v1, .L800D28C4
    /* 6A0B4 800D28B4 00000000 */   nop
    /* 6A0B8 800D28B8 0400C28C */  lw         $v0, 0x4($a2)
    /* 6A0BC 800D28BC 344A0308 */  j          .L800D28D0
    /* 6A0C0 800D28C0 040062AC */   sw        $v0, 0x4($v1)
  .L800D28C4:
    /* 6A0C4 800D28C4 0400C28C */  lw         $v0, 0x4($a2)
    /* 6A0C8 800D28C8 00000000 */  nop
    /* 6A0CC 800D28CC 1800E2AC */  sw         $v0, 0x18($a3)
  .L800D28D0:
    /* 6A0D0 800D28D0 0F80033C */  lui        $v1, %hi(D_800F55F4)
    /* 6A0D4 800D28D4 0F80053C */  lui        $a1, %hi(D_800F55F8)
    /* 6A0D8 800D28D8 F455648C */  lw         $a0, %lo(D_800F55F4)($v1)
    /* 6A0DC 800D28DC F855A28C */  lw         $v0, %lo(D_800F55F8)($a1)
    /* 6A0E0 800D28E0 F45566AC */  sw         $a2, %lo(D_800F55F4)($v1)
    /* 6A0E4 800D28E4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6A0E8 800D28E8 0400C4AC */  sw         $a0, 0x4($a2)
    /* 6A0EC 800D28EC F855A2AC */  sw         $v0, %lo(D_800F55F8)($a1)
    /* 6A0F0 800D28F0 0800E290 */  lbu        $v0, 0x8($a3)
    /* 6A0F4 800D28F4 00000000 */  nop
    /* 6A0F8 800D28F8 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6A0FC 800D28FC 0800E003 */  jr         $ra
    /* 6A100 800D2900 0800E2A0 */   sb        $v0, 0x8($a3)
endlabel func_800D2888
