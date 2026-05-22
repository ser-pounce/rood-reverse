nonmatching StartSound, 0xF0

glabel StartSound
    /* 4138 80013938 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 413C 8001393C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4140 80013940 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4144 80013944 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4148 80013948 7776000C */  jal        SpuStart
    /* 414C 8001394C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4150 80013950 04000424 */  addiu      $a0, $zero, 0x4
    /* 4154 80013954 0380053C */  lui        $a1, %hi(_spuMemInfo)
    /* 4158 80013958 A179000C */  jal        SpuInitMalloc
    /* 415C 8001395C B077A524 */   addiu     $a1, $a1, %lo(_spuMemInfo)
    /* 4160 80013960 097B000C */  jal        SpuSetTransferMode
    /* 4164 80013964 21200000 */   addu      $a0, $zero, $zero
    /* 4168 80013968 F17A000C */  jal        SpuSetTransferStartAddr
    /* 416C 8001396C 10100424 */   addiu     $a0, $zero, 0x1010
    /* 4170 80013970 0380043C */  lui        $a0, %hi(_soundFlush)
    /* 4174 80013974 60F58424 */  addiu      $a0, $a0, %lo(_soundFlush)
    /* 4178 80013978 344D000C */  jal        _writeSpu
    /* 417C 8001397C 40000524 */   addiu     $a1, $zero, 0x40
    /* 4180 80013980 574D000C */  jal        _waitTransferAvailable
    /* 4184 80013984 00000000 */   nop
    /* 4188 80013988 A74D000C */  jal        func_8001369C
    /* 418C 8001398C 00000000 */   nop
    /* 4190 80013990 457A000C */  jal        SpuSetIRQ
    /* 4194 80013994 21200000 */   addu      $a0, $zero, $zero
    /* 4198 80013998 A57A000C */  jal        SpuSetIRQCallback
    /* 419C 8001399C 21200000 */   addu      $a0, $zero, $zero
    /* 41A0 800139A0 00F2043C */  lui        $a0, (0xF2000002 >> 16)
  .L800139A4:
    /* 41A4 800139A4 02008434 */  ori        $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 41A8 800139A8 E8440524 */  addiu      $a1, $zero, 0x44E8
    /* 41AC 800139AC 899A000C */  jal        SetRCnt
    /* 41B0 800139B0 00100624 */   addiu     $a2, $zero, 0x1000
    /* 41B4 800139B4 FBFF4010 */  beqz       $v0, .L800139A4
    /* 41B8 800139B8 00F2043C */   lui       $a0, (0xF2000002 >> 16)
  .L800139BC:
    /* 41BC 800139BC BE9A000C */  jal        StartRCnt
    /* 41C0 800139C0 02008434 */   ori       $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 41C4 800139C4 FDFF4010 */  beqz       $v0, .L800139BC
    /* 41C8 800139C8 00F2043C */   lui       $a0, (0xF2000002 >> 16)
    /* 41CC 800139CC 0280123C */  lui        $s2, %hi(func_80019A58)
    /* 41D0 800139D0 0380113C */  lui        $s1, %hi(_soundEvent)
    /* 41D4 800139D4 FFFF1024 */  addiu      $s0, $zero, -0x1
  .L800139D8:
    /* 41D8 800139D8 00F2043C */  lui        $a0, (0xF2000002 >> 16)
    /* 41DC 800139DC 02008434 */  ori        $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 41E0 800139E0 02000524 */  addiu      $a1, $zero, 0x2
    /* 41E4 800139E4 00100624 */  addiu      $a2, $zero, 0x1000
    /* 41E8 800139E8 359A000C */  jal        OpenEvent
    /* 41EC 800139EC 589A4726 */   addiu     $a3, $s2, %lo(func_80019A58)
    /* 41F0 800139F0 F9FF5010 */  beq        $v0, $s0, .L800139D8
    /* 41F4 800139F4 44F522AE */   sw        $v0, %lo(_soundEvent)($s1)
    /* 41F8 800139F8 0380103C */  lui        $s0, %hi(_soundEvent)
  .L800139FC:
    /* 41FC 800139FC 44F5048E */  lw         $a0, %lo(_soundEvent)($s0)
    /* 4200 80013A00 459A000C */  jal        EnableEvent
    /* 4204 80013A04 00000000 */   nop
    /* 4208 80013A08 FCFF4010 */  beqz       $v0, .L800139FC
    /* 420C 80013A0C 00000000 */   nop
    /* 4210 80013A10 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4214 80013A14 1800B28F */  lw         $s2, 0x18($sp)
    /* 4218 80013A18 1400B18F */  lw         $s1, 0x14($sp)
    /* 421C 80013A1C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4220 80013A20 0800E003 */  jr         $ra
    /* 4224 80013A24 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel StartSound
