nonmatching SoundVM_FE03_SetMasterReverbSlide, 0xA8

glabel SoundVM_FE03_SetMasterReverbSlide
    /* BB7C 8001B37C 21288000 */  addu       $a1, $a0, $zero
    /* BB80 8001B380 0380063C */  lui        $a2, %hi(g_pActiveMusicConfig)
    /* BB84 8001B384 0000A28C */  lw         $v0, 0x0($a1)
    /* BB88 8001B388 2078C48C */  lw         $a0, %lo(g_pActiveMusicConfig)($a2)
    /* BB8C 8001B38C 00004390 */  lbu        $v1, 0x0($v0)
    /* BB90 8001B390 01004224 */  addiu      $v0, $v0, 0x1
    /* BB94 8001B394 6A0083A4 */  sh         $v1, 0x6A($a0)
    /* BB98 8001B398 0000A2AC */  sw         $v0, 0x0($a1)
    /* BB9C 8001B39C 6A008284 */  lh         $v0, 0x6A($a0)
    /* BBA0 8001B3A0 00000000 */  nop
    /* BBA4 8001B3A4 02004014 */  bnez       $v0, .L8001B3B0
    /* BBA8 8001B3A8 00010224 */   addiu     $v0, $zero, 0x100
    /* BBAC 8001B3AC 6A0082A4 */  sh         $v0, 0x6A($a0)
  .L8001B3B0:
    /* BBB0 8001B3B0 0000A28C */  lw         $v0, 0x0($a1)
    /* BBB4 8001B3B4 00000000 */  nop
    /* BBB8 8001B3B8 01004380 */  lb         $v1, 0x1($v0)
    /* BBBC 8001B3BC 00004490 */  lbu        $a0, 0x0($v0)
    /* BBC0 8001B3C0 02004224 */  addiu      $v0, $v0, 0x2
    /* BBC4 8001B3C4 0000A2AC */  sw         $v0, 0x0($a1)
    /* BBC8 8001B3C8 2078C58C */  lw         $a1, %lo(g_pActiveMusicConfig)($a2)
    /* BBCC 8001B3CC 001D0300 */  sll        $v1, $v1, 20
    /* BBD0 8001B3D0 00230400 */  sll        $a0, $a0, 12
    /* BBD4 8001B3D4 25186400 */  or         $v1, $v1, $a0
    /* BBD8 8001B3D8 5800A48C */  lw         $a0, 0x58($a1)
    /* BBDC 8001B3DC 00F00224 */  addiu      $v0, $zero, -0x1000
    /* BBE0 8001B3E0 24208200 */  and        $a0, $a0, $v0
    /* BBE4 8001B3E4 6A00A284 */  lh         $v0, 0x6A($a1)
    /* BBE8 8001B3E8 23186400 */  subu       $v1, $v1, $a0
    /* BBEC 8001B3EC 1A006200 */  div        $zero, $v1, $v0
    /* BBF0 8001B3F0 02004014 */  bnez       $v0, .L8001B3FC
    /* BBF4 8001B3F4 00000000 */   nop
    /* BBF8 8001B3F8 0D000700 */  break      7
  .L8001B3FC:
    /* BBFC 8001B3FC FFFF0124 */  addiu      $at, $zero, -0x1
    /* BC00 8001B400 04004114 */  bne        $v0, $at, .L8001B414
    /* BC04 8001B404 0080013C */   lui       $at, (0x80000000 >> 16)
    /* BC08 8001B408 02006114 */  bne        $v1, $at, .L8001B414
    /* BC0C 8001B40C 00000000 */   nop
    /* BC10 8001B410 0D000600 */  break      6
  .L8001B414:
    /* BC14 8001B414 12180000 */  mflo       $v1
    /* BC18 8001B418 5800A4AC */  sw         $a0, 0x58($a1)
    /* BC1C 8001B41C 0800E003 */  jr         $ra
    /* BC20 8001B420 5C00A3AC */   sw        $v1, 0x5C($a1)
endlabel SoundVM_FE03_SetMasterReverbSlide
