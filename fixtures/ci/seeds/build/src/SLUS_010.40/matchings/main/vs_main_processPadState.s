nonmatching vs_main_processPadState, 0x320

glabel vs_main_processPadState
    /* 34140 80043940 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 34144 80043944 21200000 */  addu       $a0, $zero, $zero
    /* 34148 80043948 1800B0AF */  sw         $s0, 0x18($sp)
    /* 3414C 8004394C 0680103C */  lui        $s0, %hi(vs_main_padBuffer)
    /* 34150 80043950 F0DF1026 */  addiu      $s0, $s0, %lo(vs_main_padBuffer)
    /* 34154 80043954 21280002 */  addu       $a1, $s0, $zero
    /* 34158 80043958 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3415C 8004395C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 34160 80043960 3D0C010C */  jal        vs_main_updatePadState
    /* 34164 80043964 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 34168 80043968 10000424 */  addiu      $a0, $zero, 0x10
    /* 3416C 8004396C 22001126 */  addiu      $s1, $s0, 0x22
    /* 34170 80043970 21282002 */  addu       $a1, $s1, $zero
    /* 34174 80043974 0680123C */  lui        $s2, %hi(vs_main_buttonsState)
    /* 34178 80043978 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 3417C 8004397C 3D0C010C */  jal        vs_main_updatePadState
    /* 34180 80043980 38E242AE */   sw        $v0, %lo(vs_main_buttonsState)($s2)
    /* 34184 80043984 21200000 */  addu       $a0, $zero, $zero
    /* 34188 80043988 21280002 */  addu       $a1, $s0, $zero
    /* 3418C 8004398C 38E2438E */  lw         $v1, %lo(vs_main_buttonsState)($s2)
    /* 34190 80043990 00140200 */  sll        $v0, $v0, 16
    /* 34194 80043994 25186200 */  or         $v1, $v1, $v0
    /* 34198 80043998 940C010C */  jal        vs_main_padConnect
    /* 3419C 8004399C 38E243AE */   sw        $v1, %lo(vs_main_buttonsState)($s2)
    /* 341A0 800439A0 10000424 */  addiu      $a0, $zero, 0x10
    /* 341A4 800439A4 940C010C */  jal        vs_main_padConnect
    /* 341A8 800439A8 21282002 */   addu      $a1, $s1, $zero
    /* 341AC 800439AC 0580023C */  lui        $v0, %hi(_portInfo)
    /* 341B0 800439B0 90014824 */  addiu      $t0, $v0, %lo(_portInfo)
    /* 341B4 800439B4 90014390 */  lbu        $v1, %lo(_portInfo)($v0)
    /* 341B8 800439B8 04000224 */  addiu      $v0, $zero, 0x4
    /* 341BC 800439BC 4D006210 */  beq        $v1, $v0, .L80043AF4
    /* 341C0 800439C0 07000224 */   addiu     $v0, $zero, 0x7
    /* 341C4 800439C4 4C006214 */  bne        $v1, $v0, .L80043AF8
    /* 341C8 800439C8 0680043C */   lui       $a0, %hi(vs_main_stickPosBuf)
    /* 341CC 800439CC 0680033C */  lui        $v1, %hi(vs_main_stickPosBuf)
    /* 341D0 800439D0 C0DF6224 */  addiu      $v0, $v1, %lo(vs_main_stickPosBuf)
    /* 341D4 800439D4 03000491 */  lbu        $a0, 0x3($t0)
    /* 341D8 800439D8 04000591 */  lbu        $a1, 0x4($t0)
    /* 341DC 800439DC 05000691 */  lbu        $a2, 0x5($t0)
    /* 341E0 800439E0 06000791 */  lbu        $a3, 0x6($t0)
    /* 341E4 800439E4 21488000 */  addu       $t1, $a0, $zero
    /* 341E8 800439E8 080044AC */  sw         $a0, 0x8($v0)
    /* 341EC 800439EC 0C0045AC */  sw         $a1, 0xC($v0)
    /* 341F0 800439F0 C0DF66AC */  sw         $a2, %lo(vs_main_stickPosBuf)($v1)
    /* 341F4 800439F4 040047AC */  sw         $a3, 0x4($v0)
    /* 341F8 800439F8 1000222D */  sltiu      $v0, $t1, 0x10
    /* 341FC 800439FC 06004010 */  beqz       $v0, .L80043A18
    /* 34200 80043A00 F100222D */   sltiu     $v0, $t1, 0xF1
    /* 34204 80043A04 38E2428E */  lw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 34208 80043A08 00000000 */  nop
    /* 3420C 80043A0C 00804234 */  ori        $v0, $v0, 0x8000
    /* 34210 80043A10 38E242AE */  sw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 34214 80043A14 F100222D */  sltiu      $v0, $t1, 0xF1
  .L80043A18:
    /* 34218 80043A18 05004014 */  bnez       $v0, .L80043A30
    /* 3421C 80043A1C 00000000 */   nop
    /* 34220 80043A20 38E2428E */  lw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 34224 80043A24 00000000 */  nop
    /* 34228 80043A28 00204234 */  ori        $v0, $v0, 0x2000
    /* 3422C 80043A2C 38E242AE */  sw         $v0, %lo(vs_main_buttonsState)($s2)
  .L80043A30:
    /* 34230 80043A30 04000391 */  lbu        $v1, 0x4($t0)
    /* 34234 80043A34 00000000 */  nop
    /* 34238 80043A38 1000622C */  sltiu      $v0, $v1, 0x10
    /* 3423C 80043A3C 06004010 */  beqz       $v0, .L80043A58
    /* 34240 80043A40 F100622C */   sltiu     $v0, $v1, 0xF1
    /* 34244 80043A44 38E2428E */  lw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 34248 80043A48 00000000 */  nop
    /* 3424C 80043A4C 00104234 */  ori        $v0, $v0, 0x1000
    /* 34250 80043A50 38E242AE */  sw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 34254 80043A54 F100622C */  sltiu      $v0, $v1, 0xF1
  .L80043A58:
    /* 34258 80043A58 05004014 */  bnez       $v0, .L80043A70
    /* 3425C 80043A5C 00000000 */   nop
    /* 34260 80043A60 38E2428E */  lw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 34264 80043A64 00000000 */  nop
    /* 34268 80043A68 00404234 */  ori        $v0, $v0, 0x4000
    /* 3426C 80043A6C 38E242AE */  sw         $v0, %lo(vs_main_buttonsState)($s2)
  .L80043A70:
    /* 34270 80043A70 05000391 */  lbu        $v1, 0x5($t0)
    /* 34274 80043A74 00000000 */  nop
    /* 34278 80043A78 2000622C */  sltiu      $v0, $v1, 0x20
    /* 3427C 80043A7C 06004010 */  beqz       $v0, .L80043A98
    /* 34280 80043A80 E100622C */   sltiu     $v0, $v1, 0xE1
    /* 34284 80043A84 38E2428E */  lw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 34288 80043A88 00000000 */  nop
    /* 3428C 80043A8C 00044234 */  ori        $v0, $v0, 0x400
    /* 34290 80043A90 38E242AE */  sw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 34294 80043A94 E100622C */  sltiu      $v0, $v1, 0xE1
  .L80043A98:
    /* 34298 80043A98 05004014 */  bnez       $v0, .L80043AB0
    /* 3429C 80043A9C 00000000 */   nop
    /* 342A0 80043AA0 38E2428E */  lw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 342A4 80043AA4 00000000 */  nop
    /* 342A8 80043AA8 00044234 */  ori        $v0, $v0, 0x400
    /* 342AC 80043AAC 38E242AE */  sw         $v0, %lo(vs_main_buttonsState)($s2)
  .L80043AB0:
    /* 342B0 80043AB0 06000391 */  lbu        $v1, 0x6($t0)
    /* 342B4 80043AB4 00000000 */  nop
    /* 342B8 80043AB8 2000622C */  sltiu      $v0, $v1, 0x20
    /* 342BC 80043ABC 06004010 */  beqz       $v0, .L80043AD8
    /* 342C0 80043AC0 E100622C */   sltiu     $v0, $v1, 0xE1
    /* 342C4 80043AC4 38E2428E */  lw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 342C8 80043AC8 00000000 */  nop
    /* 342CC 80043ACC 00044234 */  ori        $v0, $v0, 0x400
    /* 342D0 80043AD0 38E242AE */  sw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 342D4 80043AD4 E100622C */  sltiu      $v0, $v1, 0xE1
  .L80043AD8:
    /* 342D8 80043AD8 0E004014 */  bnez       $v0, .L80043B14
    /* 342DC 80043ADC 0580023C */   lui       $v0, %hi(_buttonHeldFrameCount)
    /* 342E0 80043AE0 38E2428E */  lw         $v0, %lo(vs_main_buttonsState)($s2)
    /* 342E4 80043AE4 00000000 */  nop
    /* 342E8 80043AE8 00044234 */  ori        $v0, $v0, 0x400
    /* 342EC 80043AEC C40E0108 */  j          .L80043B10
    /* 342F0 80043AF0 38E242AE */   sw        $v0, %lo(vs_main_buttonsState)($s2)
  .L80043AF4:
    /* 342F4 80043AF4 0680043C */  lui        $a0, %hi(vs_main_stickPosBuf)
  .L80043AF8:
    /* 342F8 80043AF8 C0DF8324 */  addiu      $v1, $a0, %lo(vs_main_stickPosBuf)
    /* 342FC 80043AFC 80000224 */  addiu      $v0, $zero, 0x80
    /* 34300 80043B00 040062AC */  sw         $v0, 0x4($v1)
    /* 34304 80043B04 C0DF82AC */  sw         $v0, %lo(vs_main_stickPosBuf)($a0)
    /* 34308 80043B08 0C0062AC */  sw         $v0, 0xC($v1)
    /* 3430C 80043B0C 080062AC */  sw         $v0, 0x8($v1)
  .L80043B10:
    /* 34310 80043B10 0580023C */  lui        $v0, %hi(_buttonHeldFrameCount)
  .L80043B14:
    /* 34314 80043B14 905C4624 */  addiu      $a2, $v0, %lo(_buttonHeldFrameCount)
    /* 34318 80043B18 8000C924 */  addiu      $t1, $a2, 0x80
    /* 3431C 80043B1C 0680023C */  lui        $v0, %hi(vs_main_buttonsState)
    /* 34320 80043B20 0680033C */  lui        $v1, %hi(vs_gametime_tickspeed)
    /* 34324 80043B24 0680053C */  lui        $a1, %hi(vs_main_buttonsPreviousState)
    /* 34328 80043B28 0680043C */  lui        $a0, %hi(vs_main_buttonsPressed)
    /* 3432C 80043B2C 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 34330 80043B30 4CE2688C */  lw         $t0, %lo(vs_gametime_tickspeed)($v1)
    /* 34334 80043B34 C0E1A38C */  lw         $v1, %lo(vs_main_buttonsPreviousState)($a1)
    /* 34338 80043B38 21384000 */  addu       $a3, $v0, $zero
    /* 3433C 80043B3C 27100300 */  nor        $v0, $zero, $v1
    /* 34340 80043B40 24104700 */  and        $v0, $v0, $a3
    /* 34344 80043B44 D0E182AC */  sw         $v0, %lo(vs_main_buttonsPressed)($a0)
    /* 34348 80043B48 0580043C */  lui        $a0, %hi(vs_main_buttonsReleased)
    /* 3434C 80043B4C 27100700 */  nor        $v0, $zero, $a3
    /* 34350 80043B50 24186200 */  and        $v1, $v1, $v0
    /* 34354 80043B54 785C83AC */  sw         $v1, %lo(vs_main_buttonsReleased)($a0)
    /* 34358 80043B58 C0E1A7AC */  sw         $a3, %lo(vs_main_buttonsPreviousState)($a1)
  .L80043B5C:
    /* 3435C 80043B5C 0100E230 */  andi       $v0, $a3, 0x1
    /* 34360 80043B60 06004010 */  beqz       $v0, .L80043B7C
    /* 34364 80043B64 00000000 */   nop
    /* 34368 80043B68 0000C28C */  lw         $v0, 0x0($a2)
    /* 3436C 80043B6C 00000000 */  nop
    /* 34370 80043B70 21104800 */  addu       $v0, $v0, $t0
    /* 34374 80043B74 E00E0108 */  j          .L80043B80
    /* 34378 80043B78 0000C2AC */   sw        $v0, 0x0($a2)
  .L80043B7C:
    /* 3437C 80043B7C 0000C0AC */  sw         $zero, 0x0($a2)
  .L80043B80:
    /* 34380 80043B80 0400C624 */  addiu      $a2, $a2, 0x4
    /* 34384 80043B84 2A10C900 */  slt        $v0, $a2, $t1
    /* 34388 80043B88 F4FF4014 */  bnez       $v0, .L80043B5C
    /* 3438C 80043B8C 42380700 */   srl       $a3, $a3, 1
    /* 34390 80043B90 21200000 */  addu       $a0, $zero, $zero
    /* 34394 80043B94 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 34398 80043B98 21304000 */  addu       $a2, $v0, $zero
    /* 3439C 80043B9C 01000724 */  addiu      $a3, $zero, 0x1
    /* 343A0 80043BA0 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 343A4 80043BA4 0580033C */  lui        $v1, %hi(_buttonHeldFrameCount)
    /* 343A8 80043BA8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 343AC 80043BAC 905C6524 */  addiu      $a1, $v1, %lo(_buttonHeldFrameCount)
    /* 343B0 80043BB0 DCDFC2AC */  sw         $v0, %lo(vs_main_buttonRepeat)($a2)
  .L80043BB4:
    /* 343B4 80043BB4 0000A38C */  lw         $v1, 0x0($a1)
    /* 343B8 80043BB8 00000000 */  nop
    /* 343BC 80043BBC 1400622C */  sltiu      $v0, $v1, 0x14
    /* 343C0 80043BC0 08004014 */  bnez       $v0, .L80043BE4
    /* 343C4 80043BC4 ECFF6224 */   addiu     $v0, $v1, -0x14
    /* 343C8 80043BC8 03004230 */  andi       $v0, $v0, 0x3
    /* 343CC 80043BCC 05004014 */  bnez       $v0, .L80043BE4
    /* 343D0 80043BD0 04188700 */   sllv      $v1, $a3, $a0
    /* 343D4 80043BD4 DCDFC28C */  lw         $v0, %lo(vs_main_buttonRepeat)($a2)
    /* 343D8 80043BD8 00000000 */  nop
    /* 343DC 80043BDC 25104300 */  or         $v0, $v0, $v1
    /* 343E0 80043BE0 DCDFC2AC */  sw         $v0, %lo(vs_main_buttonRepeat)($a2)
  .L80043BE4:
    /* 343E4 80043BE4 01008424 */  addiu      $a0, $a0, 0x1
    /* 343E8 80043BE8 20008228 */  slti       $v0, $a0, 0x20
    /* 343EC 80043BEC F1FF4014 */  bnez       $v0, .L80043BB4
    /* 343F0 80043BF0 0400A524 */   addiu     $a1, $a1, 0x4
    /* 343F4 80043BF4 0580023C */  lui        $v0, %hi(_resetEnabled)
    /* 343F8 80043BF8 885C428C */  lw         $v0, %lo(_resetEnabled)($v0)
    /* 343FC 80043BFC 00000000 */  nop
    /* 34400 80043C00 10004010 */  beqz       $v0, .L80043C44
    /* 34404 80043C04 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 34408 80043C08 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 3440C 80043C0C 0F090324 */  addiu      $v1, $zero, 0x90F
    /* 34410 80043C10 0F094230 */  andi       $v0, $v0, 0x90F
    /* 34414 80043C14 0B004314 */  bne        $v0, $v1, .L80043C44
    /* 34418 80043C18 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 3441C 80043C1C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 34420 80043C20 00000000 */  nop
    /* 34424 80043C24 24104300 */  and        $v0, $v0, $v1
    /* 34428 80043C28 06004010 */  beqz       $v0, .L80043C44
    /* 3442C 80043C2C 0680023C */   lui       $v0, %hi(vs_main_settings)
    /* 34430 80043C30 20004224 */  addiu      $v0, $v0, %lo(vs_main_settings)
    /* 34434 80043C34 01000324 */  addiu      $v1, $zero, 0x1
    /* 34438 80043C38 0A0040A0 */  sb         $zero, 0xA($v0)
    /* 3443C 80043C3C D908010C */  jal        vs_main_resetGame
    /* 34440 80043C40 0B0043A0 */   sb        $v1, 0xB($v0)
  .L80043C44:
    /* 34444 80043C44 2400BF8F */  lw         $ra, 0x24($sp)
    /* 34448 80043C48 2000B28F */  lw         $s2, 0x20($sp)
    /* 3444C 80043C4C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 34450 80043C50 1800B08F */  lw         $s0, 0x18($sp)
    /* 34454 80043C54 01000224 */  addiu      $v0, $zero, 0x1
    /* 34458 80043C58 0800E003 */  jr         $ra
    /* 3445C 80043C5C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_main_processPadState
