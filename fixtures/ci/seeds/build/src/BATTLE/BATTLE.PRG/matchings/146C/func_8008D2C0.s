nonmatching func_8008D2C0, 0x110

glabel func_8008D2C0
    /* 24AC0 8008D2C0 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 24AC4 8008D2C4 F81B4224 */  addiu      $v0, $v0, %lo(vs_battle_roomData)
    /* 24AC8 8008D2C8 A800458C */  lw         $a1, 0xA8($v0)
    /* 24ACC 8008D2CC 00000000 */  nop
    /* 24AD0 8008D2D0 3D00A010 */  beqz       $a1, .L8008D3C8
    /* 24AD4 8008D2D4 21508000 */   addu      $t2, $a0, $zero
    /* 24AD8 8008D2D8 4800438C */  lw         $v1, 0x48($v0)
    /* 24ADC 8008D2DC 16B2023C */  lui        $v0, (0xB21642C9 >> 16)
    /* 24AE0 8008D2E0 C9424234 */  ori        $v0, $v0, (0xB21642C9 & 0xFFFF)
    /* 24AE4 8008D2E4 19006200 */  multu      $v1, $v0
    /* 24AE8 8008D2E8 2140A000 */  addu       $t0, $a1, $zero
    /* 24AEC 8008D2EC 21380000 */  addu       $a3, $zero, $zero
    /* 24AF0 8008D2F0 10700000 */  mfhi       $t6
    /* 24AF4 8008D2F4 C2590E00 */  srl        $t3, $t6, 7
    /* 24AF8 8008D2F8 31006011 */  beqz       $t3, .L8008D3C0
    /* 24AFC 8008D2FC 2148E000 */   addu      $t1, $a3, $zero
    /* 24B00 8008D300 0780023C */  lui        $v0, %hi(D_80068BEC)
    /* 24B04 8008D304 EC8B4D24 */  addiu      $t5, $v0, %lo(D_80068BEC)
    /* 24B08 8008D308 0F80023C */  lui        $v0, %hi(D_800F1D70)
    /* 24B0C 8008D30C 701D4C24 */  addiu      $t4, $v0, %lo(D_800F1D70)
    /* 24B10 8008D310 B0000625 */  addiu      $a2, $t0, 0xB0
    /* 24B14 8008D314 06008424 */  addiu      $a0, $a0, 0x6
  .L8008D318:
    /* 24B18 8008D318 0000028D */  lw         $v0, 0x0($t0)
    /* 24B1C 8008D31C 00000000 */  nop
    /* 24B20 8008D320 42120200 */  srl        $v0, $v0, 9
    /* 24B24 8008D324 01004230 */  andi       $v0, $v0, 0x1
    /* 24B28 8008D328 20004014 */  bnez       $v0, .L8008D3AC
    /* 24B2C 8008D32C 00000000 */   nop
    /* 24B30 8008D330 F8FFC28C */  lw         $v0, -0x8($a2)
    /* 24B34 8008D334 00000000 */  nop
    /* 24B38 8008D338 02004104 */  bgez       $v0, .L8008D344
    /* 24B3C 8008D33C 00000000 */   nop
    /* 24B40 8008D340 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8008D344:
    /* 24B44 8008D344 03130200 */  sra        $v0, $v0, 12
    /* 24B48 8008D348 000042A5 */  sh         $v0, 0x0($t2)
    /* 24B4C 8008D34C FCFFC58C */  lw         $a1, -0x4($a2)
    /* 24B50 8008D350 00000000 */  nop
    /* 24B54 8008D354 0200A104 */  bgez       $a1, .L8008D360
    /* 24B58 8008D358 2110EC00 */   addu      $v0, $a3, $t4
    /* 24B5C 8008D35C FF0FA524 */  addiu      $a1, $a1, 0xFFF
  .L8008D360:
    /* 24B60 8008D360 00004290 */  lbu        $v0, 0x0($v0)
    /* 24B64 8008D364 00000000 */  nop
    /* 24B68 8008D368 40100200 */  sll        $v0, $v0, 1
    /* 24B6C 8008D36C 21104D00 */  addu       $v0, $v0, $t5
    /* 24B70 8008D370 00004394 */  lhu        $v1, 0x0($v0)
    /* 24B74 8008D374 03130500 */  sra        $v0, $a1, 12
    /* 24B78 8008D378 23186200 */  subu       $v1, $v1, $v0
    /* 24B7C 8008D37C FCFF83A4 */  sh         $v1, -0x4($a0)
    /* 24B80 8008D380 0000C28C */  lw         $v0, 0x0($a2)
    /* 24B84 8008D384 00000000 */  nop
    /* 24B88 8008D388 02004104 */  bgez       $v0, .L8008D394
    /* 24B8C 8008D38C 00000000 */   nop
    /* 24B90 8008D390 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8008D394:
    /* 24B94 8008D394 03130200 */  sra        $v0, $v0, 12
    /* 24B98 8008D398 FEFF82A4 */  sh         $v0, -0x2($a0)
    /* 24B9C 8008D39C 000087A4 */  sh         $a3, 0x0($a0)
    /* 24BA0 8008D3A0 08008424 */  addiu      $a0, $a0, 0x8
    /* 24BA4 8008D3A4 08004A25 */  addiu      $t2, $t2, 0x8
    /* 24BA8 8008D3A8 01002925 */  addiu      $t1, $t1, 0x1
  .L8008D3AC:
    /* 24BAC 8008D3AC 0100E724 */  addiu      $a3, $a3, 0x1
    /* 24BB0 8008D3B0 B800C624 */  addiu      $a2, $a2, 0xB8
    /* 24BB4 8008D3B4 2A10EB00 */  slt        $v0, $a3, $t3
    /* 24BB8 8008D3B8 D7FF4014 */  bnez       $v0, .L8008D318
    /* 24BBC 8008D3BC B8000825 */   addiu     $t0, $t0, 0xB8
  .L8008D3C0:
    /* 24BC0 8008D3C0 0800E003 */  jr         $ra
    /* 24BC4 8008D3C4 21102001 */   addu      $v0, $t1, $zero
  .L8008D3C8:
    /* 24BC8 8008D3C8 0800E003 */  jr         $ra
    /* 24BCC 8008D3CC 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008D2C0
