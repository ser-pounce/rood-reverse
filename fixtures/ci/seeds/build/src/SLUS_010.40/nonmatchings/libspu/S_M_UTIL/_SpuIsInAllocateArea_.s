nonmatching _SpuIsInAllocateArea_, 0x8C

glabel _SpuIsInAllocateArea_
    /* F084 8001E884 0380023C */  lui        $v0, %hi(D_80030888)
    /* F088 8001E888 8808428C */  lw         $v0, %lo(D_80030888)($v0)
    /* F08C 8001E88C 0380033C */  lui        $v1, %hi(D_800308C8)
    /* F090 8001E890 C808638C */  lw         $v1, %lo(D_800308C8)($v1)
    /* F094 8001E894 00000000 */  nop
    /* F098 8001E898 03006014 */  bnez       $v1, .L8001E8A8
    /* F09C 8001E89C 04204400 */   sllv      $a0, $a0, $v0
    /* F0A0 8001E8A0 427A0008 */  j          .L8001E908
    /* F0A4 8001E8A4 21100000 */   addu      $v0, $zero, $zero
  .L8001E8A8:
    /* F0A8 8001E8A8 0080083C */  lui        $t0, (0x80000000 >> 16)
    /* F0AC 8001E8AC 0040073C */  lui        $a3, (0x40000000 >> 16)
    /* F0B0 8001E8B0 FF0F063C */  lui        $a2, (0xFFFFFFF >> 16)
    /* F0B4 8001E8B4 FFFFC634 */  ori        $a2, $a2, (0xFFFFFFF & 0xFFFF)
    /* F0B8 8001E8B8 21286000 */  addu       $a1, $v1, $zero
  .L8001E8BC:
    /* F0BC 8001E8BC 0000A38C */  lw         $v1, 0x0($a1)
    /* F0C0 8001E8C0 00000000 */  nop
    /* F0C4 8001E8C4 24106800 */  and        $v0, $v1, $t0
    /* F0C8 8001E8C8 0C004014 */  bnez       $v0, .L8001E8FC
    /* F0CC 8001E8CC 24106700 */   and       $v0, $v1, $a3
    /* F0D0 8001E8D0 0C004014 */  bnez       $v0, .L8001E904
    /* F0D4 8001E8D4 24186600 */   and       $v1, $v1, $a2
    /* F0D8 8001E8D8 2B106400 */  sltu       $v0, $v1, $a0
    /* F0DC 8001E8DC 0A004010 */  beqz       $v0, .L8001E908
    /* F0E0 8001E8E0 01000224 */   addiu     $v0, $zero, 0x1
    /* F0E4 8001E8E4 0400A28C */  lw         $v0, 0x4($a1)
    /* F0E8 8001E8E8 00000000 */  nop
    /* F0EC 8001E8EC 21106200 */  addu       $v0, $v1, $v0
    /* F0F0 8001E8F0 2B108200 */  sltu       $v0, $a0, $v0
    /* F0F4 8001E8F4 04004014 */  bnez       $v0, .L8001E908
    /* F0F8 8001E8F8 01000224 */   addiu     $v0, $zero, 0x1
  .L8001E8FC:
    /* F0FC 8001E8FC 2F7A0008 */  j          .L8001E8BC
    /* F100 8001E900 0800A524 */   addiu     $a1, $a1, 0x8
  .L8001E904:
    /* F104 8001E904 21100000 */  addu       $v0, $zero, $zero
  .L8001E908:
    /* F108 8001E908 0800E003 */  jr         $ra
    /* F10C 8001E90C 00000000 */   nop
endlabel _SpuIsInAllocateArea_
    /* F110 8001E910 00000000 */  nop
