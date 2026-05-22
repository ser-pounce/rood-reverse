nonmatching DecDCTGetEnv, 0x8C

glabel DecDCTGetEnv
    /* 95D0 80071DD0 21308000 */  addu       $a2, $a0, $zero
    /* 95D4 80071DD4 0780053C */  lui        $a1, %hi(D_80075B48)
    /* 95D8 80071DD8 485BA524 */  addiu      $a1, $a1, %lo(D_80075B48)
    /* 95DC 80071DDC 0F000324 */  addiu      $v1, $zero, 0xF
    /* 95E0 80071DE0 FFFF0724 */  addiu      $a3, $zero, -0x1
  .L80071DE4:
    /* 95E4 80071DE4 0000A28C */  lw         $v0, 0x0($a1)
    /* 95E8 80071DE8 0400A524 */  addiu      $a1, $a1, 0x4
    /* 95EC 80071DEC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 95F0 80071DF0 0000C2AC */  sw         $v0, 0x0($a2)
    /* 95F4 80071DF4 FBFF6714 */  bne        $v1, $a3, .L80071DE4
    /* 95F8 80071DF8 0400C624 */   addiu     $a2, $a2, 0x4
    /* 95FC 80071DFC 40008624 */  addiu      $a2, $a0, 0x40
    /* 9600 80071E00 0780053C */  lui        $a1, %hi(D_80075B88)
    /* 9604 80071E04 885BA524 */  addiu      $a1, $a1, %lo(D_80075B88)
    /* 9608 80071E08 0F000324 */  addiu      $v1, $zero, 0xF
    /* 960C 80071E0C FFFF0724 */  addiu      $a3, $zero, -0x1
  .L80071E10:
    /* 9610 80071E10 0000A28C */  lw         $v0, 0x0($a1)
    /* 9614 80071E14 0400A524 */  addiu      $a1, $a1, 0x4
    /* 9618 80071E18 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 961C 80071E1C 0000C2AC */  sw         $v0, 0x0($a2)
    /* 9620 80071E20 FBFF6714 */  bne        $v1, $a3, .L80071E10
    /* 9624 80071E24 0400C624 */   addiu     $a2, $a2, 0x4
    /* 9628 80071E28 80008624 */  addiu      $a2, $a0, 0x80
    /* 962C 80071E2C 0780053C */  lui        $a1, %hi(D_80075BCC)
    /* 9630 80071E30 CC5BA524 */  addiu      $a1, $a1, %lo(D_80075BCC)
    /* 9634 80071E34 1F000324 */  addiu      $v1, $zero, 0x1F
    /* 9638 80071E38 FFFF0724 */  addiu      $a3, $zero, -0x1
  .L80071E3C:
    /* 963C 80071E3C 0000A28C */  lw         $v0, 0x0($a1)
    /* 9640 80071E40 0400A524 */  addiu      $a1, $a1, 0x4
    /* 9644 80071E44 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 9648 80071E48 0000C2AC */  sw         $v0, 0x0($a2)
    /* 964C 80071E4C FBFF6714 */  bne        $v1, $a3, .L80071E3C
    /* 9650 80071E50 0400C624 */   addiu     $a2, $a2, 0x4
    /* 9654 80071E54 0800E003 */  jr         $ra
    /* 9658 80071E58 21108000 */   addu      $v0, $a0, $zero
endlabel DecDCTGetEnv
