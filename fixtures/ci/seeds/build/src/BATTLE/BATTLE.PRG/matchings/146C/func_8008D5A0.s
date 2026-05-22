nonmatching func_8008D5A0, 0x5C

glabel func_8008D5A0
    /* 24DA0 8008D5A0 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x48)
    /* 24DA4 8008D5A4 401C438C */  lw         $v1, %lo(vs_battle_roomData + 0x48)($v0)
    /* 24DA8 8008D5A8 16B2023C */  lui        $v0, (0xB21642C9 >> 16)
    /* 24DAC 8008D5AC C9424234 */  ori        $v0, $v0, (0xB21642C9 & 0xFFFF)
    /* 24DB0 8008D5B0 19006200 */  multu      $v1, $v0
    /* 24DB4 8008D5B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 24DB8 8008D5B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 24DBC 8008D5BC 21808000 */  addu       $s0, $a0, $zero
    /* 24DC0 8008D5C0 10280000 */  mfhi       $a1
    /* 24DC4 8008D5C4 C2110500 */  srl        $v0, $a1, 7
    /* 24DC8 8008D5C8 08004010 */  beqz       $v0, .L8008D5EC
    /* 24DCC 8008D5CC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 24DD0 8008D5D0 02000012 */  beqz       $s0, .L8008D5DC
    /* 24DD4 8008D5D4 21200000 */   addu      $a0, $zero, $zero
    /* 24DD8 8008D5D8 01000424 */  addiu      $a0, $zero, 0x1
  .L8008D5DC:
    /* 24DDC 8008D5DC 3739020C */  jal        func_8008E4DC
    /* 24DE0 8008D5E0 00000000 */   nop
    /* 24DE4 8008D5E4 0F80023C */  lui        $v0, %hi(D_800F1D68)
    /* 24DE8 8008D5E8 681D50A4 */  sh         $s0, %lo(D_800F1D68)($v0)
  .L8008D5EC:
    /* 24DEC 8008D5EC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 24DF0 8008D5F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 24DF4 8008D5F4 0800E003 */  jr         $ra
    /* 24DF8 8008D5F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008D5A0
