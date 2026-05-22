nonmatching SoundVM_A9_ChannelVolumeSlide, 0x8C

glabel SoundVM_A9_ChannelVolumeSlide
    /* BDC8 8001B5C8 21308000 */  addu       $a2, $a0, $zero
    /* BDCC 8001B5CC 0000C28C */  lw         $v0, 0x0($a2)
    /* BDD0 8001B5D0 00000000 */  nop
    /* BDD4 8001B5D4 00004390 */  lbu        $v1, 0x0($v0)
    /* BDD8 8001B5D8 01004224 */  addiu      $v0, $v0, 0x1
    /* BDDC 8001B5DC 0000C2AC */  sw         $v0, 0x0($a2)
    /* BDE0 8001B5E0 03006014 */  bnez       $v1, .L8001B5F0
    /* BDE4 8001B5E4 8800C3A4 */   sh        $v1, 0x88($a2)
    /* BDE8 8001B5E8 00010224 */  addiu      $v0, $zero, 0x100
    /* BDEC 8001B5EC 8800C2A4 */  sh         $v0, 0x88($a2)
  .L8001B5F0:
    /* BDF0 8001B5F0 FFFF033C */  lui        $v1, (0xFFFF0000 >> 16)
    /* BDF4 8001B5F4 4800C48C */  lw         $a0, 0x48($a2)
    /* BDF8 8001B5F8 0000C58C */  lw         $a1, 0x0($a2)
    /* BDFC 8001B5FC 24208300 */  and        $a0, $a0, $v1
    /* BE00 8001B600 0000A280 */  lb         $v0, 0x0($a1)
    /* BE04 8001B604 8800C394 */  lhu        $v1, 0x88($a2)
    /* BE08 8001B608 C0150200 */  sll        $v0, $v0, 23
    /* BE0C 8001B60C 23104400 */  subu       $v0, $v0, $a0
    /* BE10 8001B610 1A004300 */  div        $zero, $v0, $v1
    /* BE14 8001B614 02006014 */  bnez       $v1, .L8001B620
    /* BE18 8001B618 00000000 */   nop
    /* BE1C 8001B61C 0D000700 */  break      7
  .L8001B620:
    /* BE20 8001B620 FFFF0124 */  addiu      $at, $zero, -0x1
    /* BE24 8001B624 04006114 */  bne        $v1, $at, .L8001B638
    /* BE28 8001B628 0080013C */   lui       $at, (0x80000000 >> 16)
    /* BE2C 8001B62C 02004114 */  bne        $v0, $at, .L8001B638
    /* BE30 8001B630 00000000 */   nop
    /* BE34 8001B634 0D000600 */  break      6
  .L8001B638:
    /* BE38 8001B638 12100000 */  mflo       $v0
    /* BE3C 8001B63C 0100A524 */  addiu      $a1, $a1, 0x1
    /* BE40 8001B640 0000C5AC */  sw         $a1, 0x0($a2)
    /* BE44 8001B644 4800C4AC */  sw         $a0, 0x48($a2)
    /* BE48 8001B648 8A00C0A4 */  sh         $zero, 0x8A($a2)
    /* BE4C 8001B64C 0800E003 */  jr         $ra
    /* BE50 8001B650 4C00C2AC */   sw        $v0, 0x4C($a2)
endlabel SoundVM_A9_ChannelVolumeSlide
