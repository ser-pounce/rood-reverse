nonmatching _promptOverwrite, 0xBC

glabel _promptOverwrite
    /* 4884 8006D084 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4888 8006D088 1400BFAF */  sw         $ra, 0x14($sp)
    /* 488C 8006D08C 0F008010 */  beqz       $a0, .L8006D0CC
    /* 4890 8006D090 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4894 8006D094 01000424 */  addiu      $a0, $zero, 0x1
    /* 4898 8006D098 0E80033C */  lui        $v1, %hi(_overwritePromptInitialized)
    /* 489C 8006D09C 21108000 */  addu       $v0, $a0, $zero
    /* 48A0 8006D0A0 F1C862A0 */  sb         $v0, %lo(_overwritePromptInitialized)($v1)
    /* 48A4 8006D0A4 0E80023C */  lui        $v0, %hi(_textTable)
    /* 48A8 8006D0A8 C0EA428C */  lw         $v0, %lo(_textTable)($v0)
    /* 48AC 8006D0AC 0E80033C */  lui        $v1, %hi(_selectSaveMemoryCardMessage)
    /* 48B0 8006D0B0 B0054224 */  addiu      $v0, $v0, 0x5B0
    /* 48B4 8006D0B4 9BB3010C */  jal        _promptConfirm
    /* 48B8 8006D0B8 6CED62AC */   sw        $v0, %lo(_selectSaveMemoryCardMessage)($v1)
    /* 48BC 8006D0BC 21100000 */  addu       $v0, $zero, $zero
    /* 48C0 8006D0C0 0E80033C */  lui        $v1, %hi(_promptOverwriteState)
    /* 48C4 8006D0C4 4CB40108 */  j          .L8006D130
    /* 48C8 8006D0C8 F0C860A0 */   sb        $zero, %lo(_promptOverwriteState)($v1)
  .L8006D0CC:
    /* 48CC 8006D0CC 0E80103C */  lui        $s0, %hi(_promptOverwriteState)
    /* 48D0 8006D0D0 F0C80392 */  lbu        $v1, %lo(_promptOverwriteState)($s0)
    /* 48D4 8006D0D4 00000000 */  nop
    /* 48D8 8006D0D8 05006010 */  beqz       $v1, .L8006D0F0
    /* 48DC 8006D0DC 01000224 */   addiu     $v0, $zero, 0x1
    /* 48E0 8006D0E0 0B006210 */  beq        $v1, $v0, .L8006D110
    /* 48E4 8006D0E4 21100000 */   addu      $v0, $zero, $zero
    /* 48E8 8006D0E8 4CB40108 */  j          .L8006D130
    /* 48EC 8006D0EC 00000000 */   nop
  .L8006D0F0:
    /* 48F0 8006D0F0 9BB3010C */  jal        _promptConfirm
    /* 48F4 8006D0F4 21200000 */   addu      $a0, $zero, $zero
    /* 48F8 8006D0F8 0E80033C */  lui        $v1, %hi(_promptOverwriteSelectedOption)
    /* 48FC 8006D0FC 0B004010 */  beqz       $v0, .L8006D12C
    /* 4900 8006D100 ECC862AC */   sw        $v0, %lo(_promptOverwriteSelectedOption)($v1)
    /* 4904 8006D104 01000224 */  addiu      $v0, $zero, 0x1
    /* 4908 8006D108 4BB40108 */  j          .L8006D12C
    /* 490C 8006D10C F0C802A2 */   sb        $v0, %lo(_promptOverwriteState)($s0)
  .L8006D110:
    /* 4910 8006D110 EFAB010C */  jal        _fileMenuElementsActive
    /* 4914 8006D114 00000000 */   nop
    /* 4918 8006D118 04004010 */  beqz       $v0, .L8006D12C
    /* 491C 8006D11C 0E80023C */   lui       $v0, %hi(_promptOverwriteSelectedOption)
    /* 4920 8006D120 ECC8428C */  lw         $v0, %lo(_promptOverwriteSelectedOption)($v0)
    /* 4924 8006D124 4CB40108 */  j          .L8006D130
    /* 4928 8006D128 00000000 */   nop
  .L8006D12C:
    /* 492C 8006D12C 21100000 */  addu       $v0, $zero, $zero
  .L8006D130:
    /* 4930 8006D130 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4934 8006D134 1000B08F */  lw         $s0, 0x10($sp)
    /* 4938 8006D138 0800E003 */  jr         $ra
    /* 493C 8006D13C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _promptOverwrite
