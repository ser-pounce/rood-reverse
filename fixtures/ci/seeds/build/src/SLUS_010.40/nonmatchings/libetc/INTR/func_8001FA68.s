nonmatching func_8001FA68, 0xD8

glabel func_8001FA68
    /* 10268 8001FA68 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1026C 8001FA6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 10270 8001FA70 0380103C */  lui        $s0, %hi(D_8003104C)
    /* 10274 8001FA74 4C101026 */  addiu      $s0, $s0, %lo(D_8003104C)
    /* 10278 8001FA78 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1027C 8001FA7C 00000296 */  lhu        $v0, 0x0($s0)
    /* 10280 8001FA80 00000000 */  nop
    /* 10284 8001FA84 2A004014 */  bnez       $v0, .L8001FB30
    /* 10288 8001FA88 21100000 */   addu      $v0, $zero, $zero
    /* 1028C 8001FA8C 0380033C */  lui        $v1, %hi(D_800320D8)
    /* 10290 8001FA90 D820638C */  lw         $v1, %lo(D_800320D8)($v1)
    /* 10294 8001FA94 0380023C */  lui        $v0, %hi(D_800320DC)
    /* 10298 8001FA98 DC20428C */  lw         $v0, %lo(D_800320DC)($v0)
    /* 1029C 8001FA9C 3333053C */  lui        $a1, (0x33333333 >> 16)
    /* 102A0 8001FAA0 000040A4 */  sh         $zero, 0x0($v0)
    /* 102A4 8001FAA4 00004294 */  lhu        $v0, 0x0($v0)
    /* 102A8 8001FAA8 3333A534 */  ori        $a1, $a1, (0x33333333 & 0xFFFF)
    /* 102AC 8001FAAC 000062A4 */  sh         $v0, 0x0($v1)
    /* 102B0 8001FAB0 0380023C */  lui        $v0, %hi(D_800320E0)
    /* 102B4 8001FAB4 E020428C */  lw         $v0, %lo(D_800320E0)($v0)
    /* 102B8 8001FAB8 21200002 */  addu       $a0, $s0, $zero
    /* 102BC 8001FABC 000045AC */  sw         $a1, 0x0($v0)
    /* 102C0 8001FAC0 DC7F000C */  jal        memzero
    /* 102C4 8001FAC4 1A040524 */   addiu     $a1, $zero, 0x41A
    /* 102C8 8001FAC8 999B000C */  jal        setjmp
    /* 102CC 8001FACC 38000426 */   addiu     $a0, $s0, 0x38
    /* 102D0 8001FAD0 03004010 */  beqz       $v0, .L8001FAE0
    /* 102D4 8001FAD4 00000000 */   nop
    /* 102D8 8001FAD8 D07E000C */  jal        func_8001FB40
    /* 102DC 8001FADC 00000000 */   nop
  .L8001FAE0:
    /* 102E0 8001FAE0 0380103C */  lui        $s0, %hi(D_80031088)
    /* 102E4 8001FAE4 88101026 */  addiu      $s0, $s0, %lo(D_80031088)
    /* 102E8 8001FAE8 FCFF0426 */  addiu      $a0, $s0, -0x4
    /* 102EC 8001FAEC DC0F0226 */  addiu      $v0, $s0, 0xFDC
    /* 102F0 8001FAF0 559A000C */  jal        HookEntryInt
    /* 102F4 8001FAF4 000002AE */   sw        $v0, 0x0($s0)
    /* 102F8 8001FAF8 01000224 */  addiu      $v0, $zero, 0x1
    /* 102FC 8001FAFC E57F000C */  jal        startIntrVSync
    /* 10300 8001FB00 C4FF02A6 */   sh        $v0, -0x3C($s0)
    /* 10304 8001FB04 0380033C */  lui        $v1, %hi(D_800320D4)
    /* 10308 8001FB08 D420638C */  lw         $v1, %lo(D_800320D4)($v1)
    /* 1030C 8001FB0C 2D80000C */  jal        startIntrDMA
    /* 10310 8001FB10 140062AC */   sw        $v0, 0x14($v1)
    /* 10314 8001FB14 0380043C */  lui        $a0, %hi(D_800320D4)
    /* 10318 8001FB18 D420848C */  lw         $a0, %lo(D_800320D4)($a0)
    /* 1031C 8001FB1C 279A000C */  jal        _96_remove
    /* 10320 8001FB20 040082AC */   sw        $v0, 0x4($a0)
    /* 10324 8001FB24 619A000C */  jal        ExitCriticalSection
    /* 10328 8001FB28 C4FF1026 */   addiu     $s0, $s0, -0x3C
    /* 1032C 8001FB2C 21100002 */  addu       $v0, $s0, $zero
  .L8001FB30:
    /* 10330 8001FB30 1400BF8F */  lw         $ra, 0x14($sp)
    /* 10334 8001FB34 1000B08F */  lw         $s0, 0x10($sp)
    /* 10338 8001FB38 0800E003 */  jr         $ra
    /* 1033C 8001FB3C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001FA68
