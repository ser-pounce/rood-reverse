nonmatching _findCurrentSave, 0x150

glabel _findCurrentSave
    /* 2938 8006B138 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 293C 8006B13C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2940 8006B140 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2944 8006B144 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2948 8006B148 07008010 */  beqz       $a0, .L8006B168
    /* 294C 8006B14C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2950 8006B150 21100000 */  addu       $v0, $zero, $zero
    /* 2954 8006B154 0E80033C */  lui        $v1, %hi(_findCurrentSaveState)
    /* 2958 8006B158 CCC860A0 */  sb         $zero, %lo(_findCurrentSaveState)($v1)
    /* 295C 8006B15C 0E80033C */  lui        $v1, %hi(_findCurrentSaveSubState)
    /* 2960 8006B160 9CAC0108 */  j          .L8006B270
    /* 2964 8006B164 CDC860A0 */   sb        $zero, %lo(_findCurrentSaveSubState)($v1)
  .L8006B168:
    /* 2968 8006B168 0E80123C */  lui        $s2, %hi(_findCurrentSaveState)
    /* 296C 8006B16C CCC84292 */  lbu        $v0, %lo(_findCurrentSaveState)($s2)
    /* 2970 8006B170 00000000 */  nop
    /* 2974 8006B174 42880200 */  srl        $s1, $v0, 1
    /* 2978 8006B178 01004230 */  andi       $v0, $v0, 0x1
    /* 297C 8006B17C 11004014 */  bnez       $v0, .L8006B1C4
    /* 2980 8006B180 01003026 */   addiu     $s0, $s1, 0x1
    /* 2984 8006B184 21200002 */  addu       $a0, $s0, $zero
    /* 2988 8006B188 0E80023C */  lui        $v0, %hi(_textTable)
    /* 298C 8006B18C C0EA438C */  lw         $v1, %lo(_textTable)($v0)
    /* 2990 8006B190 40100400 */  sll        $v0, $a0, 1
    /* 2994 8006B194 21104300 */  addu       $v0, $v0, $v1
    /* 2998 8006B198 2A004294 */  lhu        $v0, 0x2A($v0)
    /* 299C 8006B19C 0E80053C */  lui        $a1, %hi(_selectSaveMemoryCardMessage)
    /* 29A0 8006B1A0 40100200 */  sll        $v0, $v0, 1
    /* 29A4 8006B1A4 21186200 */  addu       $v1, $v1, $v0
    /* 29A8 8006B1A8 1FA5010C */  jal        _memcardEventHandler
    /* 29AC 8006B1AC 6CEDA3AC */   sw        $v1, %lo(_selectSaveMemoryCardMessage)($a1)
    /* 29B0 8006B1B0 CCC84292 */  lbu        $v0, %lo(_findCurrentSaveState)($s2)
    /* 29B4 8006B1B4 00000000 */  nop
    /* 29B8 8006B1B8 01004224 */  addiu      $v0, $v0, 0x1
    /* 29BC 8006B1BC 95AC0108 */  j          .L8006B254
    /* 29C0 8006B1C0 CCC842A2 */   sb        $v0, %lo(_findCurrentSaveState)($s2)
  .L8006B1C4:
    /* 29C4 8006B1C4 1FA5010C */  jal        _memcardEventHandler
    /* 29C8 8006B1C8 21200000 */   addu      $a0, $zero, $zero
    /* 29CC 8006B1CC 03004330 */  andi       $v1, $v0, 0x3
    /* 29D0 8006B1D0 20006010 */  beqz       $v1, .L8006B254
    /* 29D4 8006B1D4 01000424 */   addiu     $a0, $zero, 0x1
    /* 29D8 8006B1D8 0C006414 */  bne        $v1, $a0, .L8006B20C
    /* 29DC 8006B1DC 02000224 */   addiu     $v0, $zero, 0x2
    /* 29E0 8006B1E0 75A4010C */  jal        _initSaveFileInfo
    /* 29E4 8006B1E4 21200002 */   addu      $a0, $s0, $zero
    /* 29E8 8006B1E8 16004014 */  bnez       $v0, .L8006B244
    /* 29EC 8006B1EC 0E80033C */   lui       $v1, %hi(_findCurrentSaveState)
    /* 29F0 8006B1F0 6DA3010C */  jal        _findCurrentSaveOnActiveMemcard
    /* 29F4 8006B1F4 00000000 */   nop
    /* 29F8 8006B1F8 21184000 */  addu       $v1, $v0, $zero
    /* 29FC 8006B1FC 10006010 */  beqz       $v1, .L8006B240
    /* 2A00 8006B200 00111100 */   sll       $v0, $s1, 4
    /* 2A04 8006B204 9CAC0108 */  j          .L8006B270
    /* 2A08 8006B208 21106200 */   addu      $v0, $v1, $v0
  .L8006B20C:
    /* 2A0C 8006B20C 0D006214 */  bne        $v1, $v0, .L8006B244
    /* 2A10 8006B210 0E80033C */   lui       $v1, %hi(_findCurrentSaveState)
    /* 2A14 8006B214 CCC84392 */  lbu        $v1, %lo(_findCurrentSaveState)($s2)
    /* 2A18 8006B218 00000000 */  nop
    /* 2A1C 8006B21C 07006410 */  beq        $v1, $a0, .L8006B23C
    /* 2A20 8006B220 0E80023C */   lui       $v0, %hi(_findCurrentSaveSubState)
    /* 2A24 8006B224 CDC84290 */  lbu        $v0, %lo(_findCurrentSaveSubState)($v0)
    /* 2A28 8006B228 00000000 */  nop
    /* 2A2C 8006B22C 04004010 */  beqz       $v0, .L8006B240
    /* 2A30 8006B230 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 2A34 8006B234 9CAC0108 */  j          .L8006B270
    /* 2A38 8006B238 00000000 */   nop
  .L8006B23C:
    /* 2A3C 8006B23C CDC843A0 */  sb         $v1, %lo(_findCurrentSaveSubState)($v0)
  .L8006B240:
    /* 2A40 8006B240 0E80033C */  lui        $v1, %hi(_findCurrentSaveState)
  .L8006B244:
    /* 2A44 8006B244 CCC86290 */  lbu        $v0, %lo(_findCurrentSaveState)($v1)
    /* 2A48 8006B248 00000000 */  nop
    /* 2A4C 8006B24C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2A50 8006B250 CCC862A0 */  sb         $v0, %lo(_findCurrentSaveState)($v1)
  .L8006B254:
    /* 2A54 8006B254 0E80023C */  lui        $v0, %hi(_findCurrentSaveState)
    /* 2A58 8006B258 CCC84390 */  lbu        $v1, %lo(_findCurrentSaveState)($v0)
    /* 2A5C 8006B25C 04000224 */  addiu      $v0, $zero, 0x4
    /* 2A60 8006B260 02006214 */  bne        $v1, $v0, .L8006B26C
    /* 2A64 8006B264 21200000 */   addu      $a0, $zero, $zero
    /* 2A68 8006B268 FFFF0424 */  addiu      $a0, $zero, -0x1
  .L8006B26C:
    /* 2A6C 8006B26C 21108000 */  addu       $v0, $a0, $zero
  .L8006B270:
    /* 2A70 8006B270 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2A74 8006B274 1800B28F */  lw         $s2, 0x18($sp)
    /* 2A78 8006B278 1400B18F */  lw         $s1, 0x14($sp)
    /* 2A7C 8006B27C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A80 8006B280 0800E003 */  jr         $ra
    /* 2A84 8006B284 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _findCurrentSave
