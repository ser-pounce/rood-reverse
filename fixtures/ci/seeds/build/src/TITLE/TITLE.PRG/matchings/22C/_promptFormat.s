nonmatching _promptFormat, 0x1B8

glabel _promptFormat
    /* 4940 8006D140 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4944 8006D144 21188000 */  addu       $v1, $a0, $zero
    /* 4948 8006D148 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 494C 8006D14C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4950 8006D150 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4954 8006D154 0E006010 */  beqz       $v1, .L8006D190
    /* 4958 8006D158 1000B0AF */   sw        $s0, 0x10($sp)
    /* 495C 8006D15C 01000424 */  addiu      $a0, $zero, 0x1
    /* 4960 8006D160 0E80023C */  lui        $v0, %hi(_memcardStatePort)
    /* 4964 8006D164 F3C843A0 */  sb         $v1, %lo(_memcardStatePort)($v0)
    /* 4968 8006D168 0E80023C */  lui        $v0, %hi(_textTable)
    /* 496C 8006D16C C0EA428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4970 8006D170 0E80033C */  lui        $v1, %hi(_selectSaveMemoryCardMessage)
    /* 4974 8006D174 A8044224 */  addiu      $v0, $v0, 0x4A8
    /* 4978 8006D178 9BB3010C */  jal        _promptConfirm
    /* 497C 8006D17C 6CED62AC */   sw        $v0, %lo(_selectSaveMemoryCardMessage)($v1)
    /* 4980 8006D180 21100000 */  addu       $v0, $zero, $zero
    /* 4984 8006D184 0E80033C */  lui        $v1, %hi(_promptFormatState)
    /* 4988 8006D188 B8B40108 */  j          .L8006D2E0
    /* 498C 8006D18C F2C860A0 */   sb        $zero, %lo(_promptFormatState)($v1)
  .L8006D190:
    /* 4990 8006D190 0E80113C */  lui        $s1, %hi(_promptFormatState)
    /* 4994 8006D194 F2C83092 */  lbu        $s0, %lo(_promptFormatState)($s1)
    /* 4998 8006D198 01001224 */  addiu      $s2, $zero, 0x1
    /* 499C 8006D19C 1C001212 */  beq        $s0, $s2, .L8006D210
    /* 49A0 8006D1A0 0200022A */   slti      $v0, $s0, 0x2
    /* 49A4 8006D1A4 05004010 */  beqz       $v0, .L8006D1BC
    /* 49A8 8006D1A8 02000224 */   addiu     $v0, $zero, 0x2
    /* 49AC 8006D1AC 09000012 */  beqz       $s0, .L8006D1D4
    /* 49B0 8006D1B0 21100000 */   addu      $v0, $zero, $zero
    /* 49B4 8006D1B4 B8B40108 */  j          .L8006D2E0
    /* 49B8 8006D1B8 00000000 */   nop
  .L8006D1BC:
    /* 49BC 8006D1BC 1E000212 */  beq        $s0, $v0, .L8006D238
    /* 49C0 8006D1C0 03000224 */   addiu     $v0, $zero, 0x3
    /* 49C4 8006D1C4 36000212 */  beq        $s0, $v0, .L8006D2A0
    /* 49C8 8006D1C8 21100000 */   addu      $v0, $zero, $zero
    /* 49CC 8006D1CC B8B40108 */  j          .L8006D2E0
    /* 49D0 8006D1D0 00000000 */   nop
  .L8006D1D4:
    /* 49D4 8006D1D4 9BB3010C */  jal        _promptConfirm
    /* 49D8 8006D1D8 21200000 */   addu      $a0, $zero, $zero
    /* 49DC 8006D1DC 21184000 */  addu       $v1, $v0, $zero
    /* 49E0 8006D1E0 3F006010 */  beqz       $v1, .L8006D2E0
    /* 49E4 8006D1E4 21100000 */   addu      $v0, $zero, $zero
    /* 49E8 8006D1E8 07006104 */  bgez       $v1, .L8006D208
    /* 49EC 8006D1EC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 49F0 8006D1F0 0E80033C */  lui        $v1, %hi(_textTable)
    /* 49F4 8006D1F4 C0EA638C */  lw         $v1, %lo(_textTable)($v1)
    /* 49F8 8006D1F8 0E80043C */  lui        $a0, %hi(_selectSaveMemoryCardMessage)
    /* 49FC 8006D1FC 5C056324 */  addiu      $v1, $v1, 0x55C
    /* 4A00 8006D200 B8B40108 */  j          .L8006D2E0
    /* 4A04 8006D204 6CED83AC */   sw        $v1, %lo(_selectSaveMemoryCardMessage)($a0)
  .L8006D208:
    /* 4A08 8006D208 B7B40108 */  j          .L8006D2DC
    /* 4A0C 8006D20C F2C832A2 */   sb        $s2, %lo(_promptFormatState)($s1)
  .L8006D210:
    /* 4A10 8006D210 EFAB010C */  jal        _fileMenuElementsActive
    /* 4A14 8006D214 00000000 */   nop
    /* 4A18 8006D218 30004010 */  beqz       $v0, .L8006D2DC
    /* 4A1C 8006D21C 0E80023C */   lui       $v0, %hi(_memcardStatePort)
    /* 4A20 8006D220 F3C84490 */  lbu        $a0, %lo(_memcardStatePort)($v0)
    /* 4A24 8006D224 1FA5010C */  jal        _memcardEventHandler
    /* 4A28 8006D228 00000000 */   nop
    /* 4A2C 8006D22C 02000224 */  addiu      $v0, $zero, 0x2
    /* 4A30 8006D230 B7B40108 */  j          .L8006D2DC
    /* 4A34 8006D234 F2C822A2 */   sb        $v0, %lo(_promptFormatState)($s1)
  .L8006D238:
    /* 4A38 8006D238 1FA5010C */  jal        _memcardEventHandler
    /* 4A3C 8006D23C 21200000 */   addu      $a0, $zero, $zero
    /* 4A40 8006D240 21184000 */  addu       $v1, $v0, $zero
    /* 4A44 8006D244 25006010 */  beqz       $v1, .L8006D2DC
    /* 4A48 8006D248 03000224 */   addiu     $v0, $zero, 0x3
    /* 4A4C 8006D24C 07006214 */  bne        $v1, $v0, .L8006D26C
    /* 4A50 8006D250 0E80023C */   lui       $v0, %hi(_textTable)
    /* 4A54 8006D254 C0EA428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4A58 8006D258 F2C823A2 */  sb         $v1, %lo(_promptFormatState)($s1)
    /* 4A5C 8006D25C 0E80033C */  lui        $v1, %hi(_selectSaveMemoryCardMessage)
    /* 4A60 8006D260 E8044224 */  addiu      $v0, $v0, 0x4E8
    /* 4A64 8006D264 B7B40108 */  j          .L8006D2DC
    /* 4A68 8006D268 6CED62AC */   sw        $v0, %lo(_selectSaveMemoryCardMessage)($v1)
  .L8006D26C:
    /* 4A6C 8006D26C 05007014 */  bne        $v1, $s0, .L8006D284
    /* 4A70 8006D270 0E80033C */   lui       $v1, %hi(_selectSaveMemoryCardMessage)
    /* 4A74 8006D274 0E80023C */  lui        $v0, %hi(_textTable)
    /* 4A78 8006D278 C0EA428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4A7C 8006D27C A5B40108 */  j          .L8006D294
    /* 4A80 8006D280 C6014224 */   addiu     $v0, $v0, 0x1C6
  .L8006D284:
    /* 4A84 8006D284 0E80023C */  lui        $v0, %hi(_textTable)
    /* 4A88 8006D288 C0EA428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4A8C 8006D28C 00000000 */  nop
    /* 4A90 8006D290 BC034224 */  addiu      $v0, $v0, 0x3BC
  .L8006D294:
    /* 4A94 8006D294 6CED62AC */  sw         $v0, %lo(_selectSaveMemoryCardMessage)($v1)
    /* 4A98 8006D298 B8B40108 */  j          .L8006D2E0
    /* 4A9C 8006D29C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8006D2A0:
    /* 4AA0 8006D2A0 0E80023C */  lui        $v0, %hi(_memcardStatePort)
    /* 4AA4 8006D2A4 F3C84490 */  lbu        $a0, %lo(_memcardStatePort)($v0)
    /* 4AA8 8006D2A8 00000000 */  nop
    /* 4AAC 8006D2AC FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 4AB0 8006D2B0 A1BC000C */  jal        _card_format
    /* 4AB4 8006D2B4 00210400 */   sll       $a0, $a0, 4
    /* 4AB8 8006D2B8 09004014 */  bnez       $v0, .L8006D2E0
    /* 4ABC 8006D2BC 01000224 */   addiu     $v0, $zero, 0x1
    /* 4AC0 8006D2C0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 4AC4 8006D2C4 0E80033C */  lui        $v1, %hi(_textTable)
    /* 4AC8 8006D2C8 C0EA638C */  lw         $v1, %lo(_textTable)($v1)
    /* 4ACC 8006D2CC 0E80043C */  lui        $a0, %hi(_selectSaveMemoryCardMessage)
    /* 4AD0 8006D2D0 40056324 */  addiu      $v1, $v1, 0x540
    /* 4AD4 8006D2D4 B8B40108 */  j          .L8006D2E0
    /* 4AD8 8006D2D8 6CED83AC */   sw        $v1, %lo(_selectSaveMemoryCardMessage)($a0)
  .L8006D2DC:
    /* 4ADC 8006D2DC 21100000 */  addu       $v0, $zero, $zero
  .L8006D2E0:
    /* 4AE0 8006D2E0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4AE4 8006D2E4 1800B28F */  lw         $s2, 0x18($sp)
    /* 4AE8 8006D2E8 1400B18F */  lw         $s1, 0x14($sp)
    /* 4AEC 8006D2EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 4AF0 8006D2F0 0800E003 */  jr         $ra
    /* 4AF4 8006D2F4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _promptFormat
