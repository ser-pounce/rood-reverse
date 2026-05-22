nonmatching StopSound, 0xA4

glabel StopSound
    /* 4228 80013A28 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 422C 80013A2C 0380023C */  lui        $v0, %hi(_isSpuTransfer)
    /* 4230 80013A30 F077438C */  lw         $v1, %lo(_isSpuTransfer)($v0)
    /* 4234 80013A34 01000224 */  addiu      $v0, $zero, 0x1
    /* 4238 80013A38 1400BFAF */  sw         $ra, 0x14($sp)
    /* 423C 80013A3C 07006214 */  bne        $v1, $v0, .L80013A5C
    /* 4240 80013A40 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4244 80013A44 0380043C */  lui        $a0, %hi(_soundFlush)
    /* 4248 80013A48 60F58424 */  addiu      $a0, $a0, %lo(_soundFlush)
    /* 424C 80013A4C 344D000C */  jal        _writeSpu
    /* 4250 80013A50 40000524 */   addiu     $a1, $zero, 0x40
    /* 4254 80013A54 574D000C */  jal        _waitTransferAvailable
    /* 4258 80013A58 00000000 */   nop
  .L80013A5C:
    /* 425C 80013A5C 00F2043C */  lui        $a0, (0xF2000002 >> 16)
  .L80013A60:
    /* 4260 80013A60 CA9A000C */  jal        StopRCnt
    /* 4264 80013A64 02008434 */   ori       $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 4268 80013A68 FDFF4010 */  beqz       $v0, .L80013A60
    /* 426C 80013A6C 00F2043C */   lui       $a0, (0xF2000002 >> 16)
    /* 4270 80013A70 02008434 */  ori        $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 4274 80013A74 599A000C */  jal        UnDeliverEvent
    /* 4278 80013A78 02000524 */   addiu     $a1, $zero, 0x2
    /* 427C 80013A7C 0380103C */  lui        $s0, %hi(_soundEvent)
  .L80013A80:
    /* 4280 80013A80 44F5048E */  lw         $a0, %lo(_soundEvent)($s0)
    /* 4284 80013A84 499A000C */  jal        DisableEvent
    /* 4288 80013A88 00000000 */   nop
    /* 428C 80013A8C FCFF4010 */  beqz       $v0, .L80013A80
    /* 4290 80013A90 00000000 */   nop
    /* 4294 80013A94 0380103C */  lui        $s0, %hi(_soundEvent)
  .L80013A98:
    /* 4298 80013A98 44F5048E */  lw         $a0, %lo(_soundEvent)($s0)
    /* 429C 80013A9C 399A000C */  jal        CloseEvent
    /* 42A0 80013AA0 00000000 */   nop
    /* 42A4 80013AA4 FCFF4010 */  beqz       $v0, .L80013A98
    /* 42A8 80013AA8 FF00043C */   lui       $a0, (0xFFFFFF >> 16)
    /* 42AC 80013AAC BA4E000C */  jal        SetVoiceKeyOff
    /* 42B0 80013AB0 FFFF8434 */   ori       $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* 42B4 80013AB4 8179000C */  jal        SpuQuit
    /* 42B8 80013AB8 00000000 */   nop
    /* 42BC 80013ABC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 42C0 80013AC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 42C4 80013AC4 0800E003 */  jr         $ra
    /* 42C8 80013AC8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel StopSound
