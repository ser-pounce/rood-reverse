nonmatching vs_battle_applyCameraState, 0x2B8

glabel vs_battle_applyCameraState
    /* 53714 800BBF14 0F80023C */  lui        $v0, %hi(D_800F4BA0)
    /* 53718 800BBF18 A04B4290 */  lbu        $v0, %lo(D_800F4BA0)($v0)
    /* 5371C 800BBF1C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 53720 800BBF20 3800BFAF */  sw         $ra, 0x38($sp)
    /* 53724 800BBF24 3400B1AF */  sw         $s1, 0x34($sp)
    /* 53728 800BBF28 12004010 */  beqz       $v0, .L800BBF74
    /* 5372C 800BBF2C 3000B0AF */   sw        $s0, 0x30($sp)
    /* 53730 800BBF30 2000B127 */  addiu      $s1, $sp, 0x20
    /* 53734 800BBF34 21202002 */  addu       $a0, $s1, $zero
    /* 53738 800BBF38 1000A527 */  addiu      $a1, $sp, 0x10
    /* 5373C 800BBF3C FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 53740 800BBF40 5CF3010C */  jal        vs_battle_initialiseCameraFromSpherical
    /* 53744 800BBF44 2138C000 */   addu      $a3, $a2, $zero
    /* 53748 800BBF48 0F80103C */  lui        $s0, %hi(D_800F4BA4)
    /* 5374C 800BBF4C A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 53750 800BBF50 1000A527 */  addiu      $a1, $sp, 0x10
    /* 53754 800BBF54 C7F9020C */  jal        _copyVector
    /* 53758 800BBF58 94008424 */   addiu     $a0, $a0, 0x94
    /* 5375C 800BBF5C A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 53760 800BBF60 21282002 */  addu       $a1, $s1, $zero
    /* 53764 800BBF64 C7F9020C */  jal        _copyVector
    /* 53768 800BBF68 48018424 */   addiu     $a0, $a0, 0x148
    /* 5376C 800BBF6C F6EF0208 */  j          .L800BBFD8
    /* 53770 800BBF70 0F80113C */   lui       $s1, %hi(D_800F4BA4)
  .L800BBF74:
    /* 53774 800BBF74 0F80103C */  lui        $s0, %hi(D_800F4BA4)
    /* 53778 800BBF78 A44B058E */  lw         $a1, %lo(D_800F4BA4)($s0)
    /* 5377C 800BBF7C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 53780 800BBF80 C7F9020C */  jal        _copyVector
    /* 53784 800BBF84 9400A524 */   addiu     $a1, $a1, 0x94
    /* 53788 800BBF88 2000B127 */  addiu      $s1, $sp, 0x20
    /* 5378C 800BBF8C A44B058E */  lw         $a1, %lo(D_800F4BA4)($s0)
    /* 53790 800BBF90 21202002 */  addu       $a0, $s1, $zero
    /* 53794 800BBF94 C7F9020C */  jal        _copyVector
    /* 53798 800BBF98 4801A524 */   addiu     $a1, $a1, 0x148
    /* 5379C 800BBF9C A44B068E */  lw         $a2, %lo(D_800F4BA4)($s0)
    /* 537A0 800BBFA0 00000000 */  nop
    /* 537A4 800BBFA4 E801C394 */  lhu        $v1, 0x1E8($a2)
    /* 537A8 800BBFA8 00200224 */  addiu      $v0, $zero, 0x2000
    /* 537AC 800BBFAC 09006210 */  beq        $v1, $v0, .L800BBFD4
    /* 537B0 800BBFB0 1000A427 */   addiu     $a0, $sp, 0x10
    /* 537B4 800BBFB4 21288000 */  addu       $a1, $a0, $zero
    /* 537B8 800BBFB8 8AF9020C */  jal        _vectorAdd
    /* 537BC 800BBFBC EC01C624 */   addiu     $a2, $a2, 0x1EC
    /* 537C0 800BBFC0 21202002 */  addu       $a0, $s1, $zero
    /* 537C4 800BBFC4 A44B068E */  lw         $a2, %lo(D_800F4BA4)($s0)
    /* 537C8 800BBFC8 21288000 */  addu       $a1, $a0, $zero
    /* 537CC 800BBFCC 8AF9020C */  jal        _vectorAdd
    /* 537D0 800BBFD0 EC01C624 */   addiu     $a2, $a2, 0x1EC
  .L800BBFD4:
    /* 537D4 800BBFD4 0F80113C */  lui        $s1, %hi(D_800F4BA4)
  .L800BBFD8:
    /* 537D8 800BBFD8 A44B258E */  lw         $a1, %lo(D_800F4BA4)($s1)
    /* 537DC 800BBFDC 00000000 */  nop
    /* 537E0 800BBFE0 A401A284 */  lh         $v0, 0x1A4($a1)
    /* 537E4 800BBFE4 00000000 */  nop
    /* 537E8 800BBFE8 32004010 */  beqz       $v0, .L800BC0B4
    /* 537EC 800BBFEC 801F043C */   lui       $a0, (0x1F800098 >> 16)
    /* 537F0 800BBFF0 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 537F4 800BBFF4 09FA020C */  jal        _sVectorToFixedPointVector
    /* 537F8 800BBFF8 BE01A524 */   addiu     $a1, $a1, 0x1BE
    /* 537FC 800BBFFC 801F043C */  lui        $a0, (0x1F8000A8 >> 16)
    /* 53800 800BC000 A8008434 */  ori        $a0, $a0, (0x1F8000A8 & 0xFFFF)
    /* 53804 800BC004 801F103C */  lui        $s0, (0x1F800088 >> 16)
    /* 53808 800BC008 A44B258E */  lw         $a1, %lo(D_800F4BA4)($s1)
    /* 5380C 800BC00C 88001036 */  ori        $s0, $s0, (0x1F800088 & 0xFFFF)
    /* 53810 800BC010 09FA020C */  jal        _sVectorToFixedPointVector
    /* 53814 800BC014 C601A524 */   addiu     $a1, $a1, 0x1C6
    /* 53818 800BC018 540000A6 */  sh         $zero, 0x54($s0)
    /* 5381C 800BC01C 500000A6 */  sh         $zero, 0x50($s0)
    /* 53820 800BC020 1000A38F */  lw         $v1, 0x10($sp)
    /* 53824 800BC024 2000A48F */  lw         $a0, 0x20($sp)
    /* 53828 800BC028 1800A28F */  lw         $v0, 0x18($sp)
    /* 5382C 800BC02C 2800A58F */  lw         $a1, 0x28($sp)
    /* 53830 800BC030 23206400 */  subu       $a0, $v1, $a0
    /* 53834 800BC034 1EFA020C */  jal        _atan2FixedPoint
    /* 53838 800BC038 23284500 */   subu      $a1, $v0, $a1
    /* 5383C 800BC03C 801F043C */  lui        $a0, (0x1F8000D8 >> 16)
    /* 53840 800BC040 D8008434 */  ori        $a0, $a0, (0x1F8000D8 & 0xFFFF)
    /* 53844 800BC044 801F053C */  lui        $a1, (0x1F8000F8 >> 16)
    /* 53848 800BC048 F800A534 */  ori        $a1, $a1, (0x1F8000F8 & 0xFFFF)
    /* 5384C 800BC04C 8004010C */  jal        RotMatrix_gte
    /* 53850 800BC050 520002A6 */   sh        $v0, 0x52($s0)
    /* 53854 800BC054 801F043C */  lui        $a0, (0x1F8000F8 >> 16)
    /* 53858 800BC058 F8008434 */  ori        $a0, $a0, (0x1F8000F8 & 0xFFFF)
    /* 5385C 800BC05C 801F053C */  lui        $a1, (0x1F800098 >> 16)
    /* 53860 800BC060 9800A534 */  ori        $a1, $a1, (0x1F800098 & 0xFFFF)
    /* 53864 800BC064 801F063C */  lui        $a2, (0x1F800098 >> 16)
    /* 53868 800BC068 7205010C */  jal        ApplyMatrixLV
    /* 5386C 800BC06C 9800C634 */   ori       $a2, $a2, (0x1F800098 & 0xFFFF)
    /* 53870 800BC070 801F043C */  lui        $a0, (0x1F8000F8 >> 16)
    /* 53874 800BC074 F8008434 */  ori        $a0, $a0, (0x1F8000F8 & 0xFFFF)
    /* 53878 800BC078 801F053C */  lui        $a1, (0x1F8000A8 >> 16)
    /* 5387C 800BC07C A800A534 */  ori        $a1, $a1, (0x1F8000A8 & 0xFFFF)
    /* 53880 800BC080 801F063C */  lui        $a2, (0x1F8000A8 >> 16)
    /* 53884 800BC084 7205010C */  jal        ApplyMatrixLV
    /* 53888 800BC088 A800C634 */   ori       $a2, $a2, (0x1F8000A8 & 0xFFFF)
    /* 5388C 800BC08C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 53890 800BC090 21288000 */  addu       $a1, $a0, $zero
    /* 53894 800BC094 801F063C */  lui        $a2, (0x1F800098 >> 16)
    /* 53898 800BC098 8AF9020C */  jal        _vectorAdd
    /* 5389C 800BC09C 9800C634 */   ori       $a2, $a2, (0x1F800098 & 0xFFFF)
    /* 538A0 800BC0A0 2000A427 */  addiu      $a0, $sp, 0x20
    /* 538A4 800BC0A4 21288000 */  addu       $a1, $a0, $zero
    /* 538A8 800BC0A8 801F063C */  lui        $a2, (0x1F8000A8 >> 16)
    /* 538AC 800BC0AC 8AF9020C */  jal        _vectorAdd
    /* 538B0 800BC0B0 A800C634 */   ori       $a2, $a2, (0x1F8000A8 & 0xFFFF)
  .L800BC0B4:
    /* 538B4 800BC0B4 1BEB010C */  jal        vs_battle_setCameraLookAt
    /* 538B8 800BC0B8 1000A427 */   addiu     $a0, $sp, 0x10
    /* 538BC 800BC0BC 06EB010C */  jal        vs_battle_setCameraPosition
    /* 538C0 800BC0C0 2000A427 */   addiu     $a0, $sp, 0x20
    /* 538C4 800BC0C4 A44B238E */  lw         $v1, %lo(D_800F4BA4)($s1)
    /* 538C8 800BC0C8 00000000 */  nop
    /* 538CC 800BC0CC 68016290 */  lbu        $v0, 0x168($v1)
    /* 538D0 800BC0D0 00000000 */  nop
    /* 538D4 800BC0D4 08004010 */  beqz       $v0, .L800BC0F8
    /* 538D8 800BC0D8 00000000 */   nop
    /* 538DC 800BC0DC 6A016484 */  lh         $a0, 0x16A($v1)
    /* 538E0 800BC0E0 25EB010C */  jal        func_8007AC94
    /* 538E4 800BC0E4 00000000 */   nop
    /* 538E8 800BC0E8 A44B228E */  lw         $v0, %lo(D_800F4BA4)($s1)
    /* 538EC 800BC0EC 00000000 */  nop
    /* 538F0 800BC0F0 680140A0 */  sb         $zero, 0x168($v0)
    /* 538F4 800BC0F4 A44B238E */  lw         $v1, %lo(D_800F4BA4)($s1)
  .L800BC0F8:
    /* 538F8 800BC0F8 00000000 */  nop
    /* 538FC 800BC0FC 74016290 */  lbu        $v0, 0x174($v1)
    /* 53900 800BC100 00000000 */  nop
    /* 53904 800BC104 07004010 */  beqz       $v0, .L800BC124
    /* 53908 800BC108 00000000 */   nop
    /* 5390C 800BC10C 76016484 */  lh         $a0, 0x176($v1)
    /* 53910 800BC110 6BF7010C */  jal        func_8007DDAC
    /* 53914 800BC114 00000000 */   nop
    /* 53918 800BC118 A44B228E */  lw         $v0, %lo(D_800F4BA4)($s1)
    /* 5391C 800BC11C 00000000 */  nop
    /* 53920 800BC120 740140A0 */  sb         $zero, 0x174($v0)
  .L800BC124:
    /* 53924 800BC124 A44B238E */  lw         $v1, %lo(D_800F4BA4)($s1)
    /* 53928 800BC128 00000000 */  nop
    /* 5392C 800BC12C 80016290 */  lbu        $v0, 0x180($v1)
    /* 53930 800BC130 00000000 */  nop
    /* 53934 800BC134 08004010 */  beqz       $v0, .L800BC158
    /* 53938 800BC138 00000000 */   nop
    /* 5393C 800BC13C 82016484 */  lh         $a0, 0x182($v1)
    /* 53940 800BC140 3CF3010C */  jal        vs_battle_setProjectionDistance
    /* 53944 800BC144 00000000 */   nop
    /* 53948 800BC148 A44B228E */  lw         $v0, %lo(D_800F4BA4)($s1)
    /* 5394C 800BC14C 00000000 */  nop
    /* 53950 800BC150 800140A0 */  sb         $zero, 0x180($v0)
    /* 53954 800BC154 A44B238E */  lw         $v1, %lo(D_800F4BA4)($s1)
  .L800BC158:
    /* 53958 800BC158 00000000 */  nop
    /* 5395C 800BC15C 8C016290 */  lbu        $v0, 0x18C($v1)
    /* 53960 800BC160 00000000 */  nop
    /* 53964 800BC164 07004010 */  beqz       $v0, .L800BC184
    /* 53968 800BC168 00000000 */   nop
    /* 5396C 800BC16C 8E016484 */  lh         $a0, 0x18E($v1)
    /* 53970 800BC170 33F3010C */  jal        vs_battle_setNearClip
    /* 53974 800BC174 00000000 */   nop
    /* 53978 800BC178 A44B228E */  lw         $v0, %lo(D_800F4BA4)($s1)
    /* 5397C 800BC17C 00000000 */  nop
    /* 53980 800BC180 8C0140A0 */  sb         $zero, 0x18C($v0)
  .L800BC184:
    /* 53984 800BC184 A44B238E */  lw         $v1, %lo(D_800F4BA4)($s1)
    /* 53988 800BC188 00000000 */  nop
    /* 5398C 800BC18C 98016290 */  lbu        $v0, 0x198($v1)
    /* 53990 800BC190 00000000 */  nop
    /* 53994 800BC194 08004010 */  beqz       $v0, .L800BC1B8
    /* 53998 800BC198 0F80023C */   lui       $v0, %hi(D_800F4C6A)
    /* 5399C 800BC19C 9A016484 */  lh         $a0, 0x19A($v1)
    /* 539A0 800BC1A0 6A4C4590 */  lbu        $a1, %lo(D_800F4C6A)($v0)
    /* 539A4 800BC1A4 45F3010C */  jal        vs_battle_setFarClip
    /* 539A8 800BC1A8 00000000 */   nop
    /* 539AC 800BC1AC A44B228E */  lw         $v0, %lo(D_800F4BA4)($s1)
    /* 539B0 800BC1B0 00000000 */  nop
    /* 539B4 800BC1B4 980140A0 */  sb         $zero, 0x198($v0)
  .L800BC1B8:
    /* 539B8 800BC1B8 3800BF8F */  lw         $ra, 0x38($sp)
    /* 539BC 800BC1BC 3400B18F */  lw         $s1, 0x34($sp)
    /* 539C0 800BC1C0 3000B08F */  lw         $s0, 0x30($sp)
    /* 539C4 800BC1C4 0800E003 */  jr         $ra
    /* 539C8 800BC1C8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel vs_battle_applyCameraState
