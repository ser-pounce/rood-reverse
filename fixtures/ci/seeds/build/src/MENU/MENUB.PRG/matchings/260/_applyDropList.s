nonmatching _applyDropList, 0x1E0

glabel _applyDropList
    /* 5EF4 801086F4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 5EF8 801086F8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5EFC 801086FC 21988000 */  addu       $s3, $a0, $zero
    /* 5F00 80108700 2000BFAF */  sw         $ra, 0x20($sp)
    /* 5F04 80108704 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5F08 80108708 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5F0C 8010870C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5F10 80108710 00006492 */  lbu        $a0, 0x0($s3)
    /* 5F14 80108714 B721040C */  jal        _droppableUnderCurrentDifficulty
    /* 5F18 80108718 00000000 */   nop
    /* 5F1C 8010871C 06004010 */  beqz       $v0, .L80108738
    /* 5F20 80108720 00000000 */   nop
    /* 5F24 80108724 841F040C */  jal        _copyWeaponToInventory
    /* 5F28 80108728 21206002 */   addu      $a0, $s3, $zero
    /* 5F2C 8010872C 21200000 */  addu       $a0, $zero, $zero
    /* 5F30 80108730 8B20040C */  jal        func_8010822C
    /* 5F34 80108734 21284000 */   addu      $a1, $v0, $zero
  .L80108738:
    /* 5F38 80108738 AC006492 */  lbu        $a0, 0xAC($s3)
    /* 5F3C 8010873C B721040C */  jal        _droppableUnderCurrentDifficulty
    /* 5F40 80108740 00000000 */   nop
    /* 5F44 80108744 06004010 */  beqz       $v0, .L80108760
    /* 5F48 80108748 B0006426 */   addiu     $a0, $s3, 0xB0
    /* 5F4C 8010874C 151F040C */  jal        _copyBladeToInventory
    /* 5F50 80108750 21280000 */   addu      $a1, $zero, $zero
    /* 5F54 80108754 01000424 */  addiu      $a0, $zero, 0x1
    /* 5F58 80108758 8B20040C */  jal        func_8010822C
    /* 5F5C 8010875C 21284000 */   addu      $a1, $v0, $zero
  .L80108760:
    /* 5F60 80108760 DC006492 */  lbu        $a0, 0xDC($s3)
    /* 5F64 80108764 B721040C */  jal        _droppableUnderCurrentDifficulty
    /* 5F68 80108768 00000000 */   nop
    /* 5F6C 8010876C 06004010 */  beqz       $v0, .L80108788
    /* 5F70 80108770 E0006426 */   addiu     $a0, $s3, 0xE0
    /* 5F74 80108774 3A1F040C */  jal        _copyGripToInventory
    /* 5F78 80108778 21280000 */   addu      $a1, $zero, $zero
    /* 5F7C 8010877C 02000424 */  addiu      $a0, $zero, 0x2
    /* 5F80 80108780 8B20040C */  jal        func_8010822C
    /* 5F84 80108784 21284000 */   addu      $a1, $v0, $zero
  .L80108788:
    /* 5F88 80108788 F0006492 */  lbu        $a0, 0xF0($s3)
    /* 5F8C 8010878C B721040C */  jal        _droppableUnderCurrentDifficulty
    /* 5F90 80108790 00000000 */   nop
    /* 5F94 80108794 07004010 */  beqz       $v0, .L801087B4
    /* 5F98 80108798 21880000 */   addu      $s1, $zero, $zero
    /* 5F9C 8010879C E71F040C */  jal        _copyShieldToInventory
    /* 5FA0 801087A0 F0006426 */   addiu     $a0, $s3, 0xF0
    /* 5FA4 801087A4 03000424 */  addiu      $a0, $zero, 0x3
    /* 5FA8 801087A8 8B20040C */  jal        func_8010822C
    /* 5FAC 801087AC 21284000 */   addu      $a1, $v0, $zero
    /* 5FB0 801087B0 21880000 */  addu       $s1, $zero, $zero
  .L801087B4:
    /* 5FB4 801087B4 70011224 */  addiu      $s2, $zero, 0x170
    /* 5FB8 801087B8 21806002 */  addu       $s0, $s3, $zero
  .L801087BC:
    /* 5FBC 801087BC 70010492 */  lbu        $a0, 0x170($s0)
    /* 5FC0 801087C0 B721040C */  jal        _droppableUnderCurrentDifficulty
    /* 5FC4 801087C4 00000000 */   nop
    /* 5FC8 801087C8 06004010 */  beqz       $v0, .L801087E4
    /* 5FCC 801087CC 21207202 */   addu      $a0, $s3, $s2
    /* 5FD0 801087D0 C71F040C */  jal        _copyArmorToInventory
    /* 5FD4 801087D4 04008424 */   addiu     $a0, $a0, 0x4
    /* 5FD8 801087D8 04000424 */  addiu      $a0, $zero, 0x4
    /* 5FDC 801087DC 8B20040C */  jal        func_8010822C
    /* 5FE0 801087E0 21284000 */   addu      $a1, $v0, $zero
  .L801087E4:
    /* 5FE4 801087E4 2C005226 */  addiu      $s2, $s2, 0x2C
    /* 5FE8 801087E8 01003126 */  addiu      $s1, $s1, 0x1
    /* 5FEC 801087EC 0200222A */  slti       $v0, $s1, 0x2
    /* 5FF0 801087F0 F2FF4014 */  bnez       $v0, .L801087BC
    /* 5FF4 801087F4 2C001026 */   addiu     $s0, $s0, 0x2C
    /* 5FF8 801087F8 C8016492 */  lbu        $a0, 0x1C8($s3)
    /* 5FFC 801087FC B721040C */  jal        _droppableUnderCurrentDifficulty
    /* 6000 80108800 00000000 */   nop
    /* 6004 80108804 06004010 */  beqz       $v0, .L80108820
    /* 6008 80108808 00000000 */   nop
    /* 600C 8010880C C71F040C */  jal        _copyArmorToInventory
    /* 6010 80108810 CC016426 */   addiu     $a0, $s3, 0x1CC
    /* 6014 80108814 04000424 */  addiu      $a0, $zero, 0x4
    /* 6018 80108818 8B20040C */  jal        func_8010822C
    /* 601C 8010881C 21284000 */   addu      $a1, $v0, $zero
  .L80108820:
    /* 6020 80108820 F4016492 */  lbu        $a0, 0x1F4($s3)
    /* 6024 80108824 B721040C */  jal        _droppableUnderCurrentDifficulty
    /* 6028 80108828 00000000 */   nop
    /* 602C 8010882C 06004010 */  beqz       $v0, .L80108848
    /* 6030 80108830 F8016426 */   addiu     $a0, $s3, 0x1F8
    /* 6034 80108834 5F1F040C */  jal        _copyGemToInventory
    /* 6038 80108838 21280000 */   addu      $a1, $zero, $zero
    /* 603C 8010883C 05000424 */  addiu      $a0, $zero, 0x5
    /* 6040 80108840 8B20040C */  jal        func_8010822C
    /* 6044 80108844 21284000 */   addu      $a1, $v0, $zero
  .L80108848:
    /* 6048 80108848 21880000 */  addu       $s1, $zero, $zero
    /* 604C 8010884C 14021224 */  addiu      $s2, $zero, 0x214
    /* 6050 80108850 21806002 */  addu       $s0, $s3, $zero
  .L80108854:
    /* 6054 80108854 16020492 */  lbu        $a0, 0x216($s0)
    /* 6058 80108858 B721040C */  jal        _droppableUnderCurrentDifficulty
    /* 605C 8010885C 00000000 */   nop
    /* 6060 80108860 0E004010 */  beqz       $v0, .L8010889C
    /* 6064 80108864 00000000 */   nop
    /* 6068 80108868 14020296 */  lhu        $v0, 0x214($s0)
    /* 606C 8010886C 00000000 */  nop
    /* 6070 80108870 0A004010 */  beqz       $v0, .L8010889C
    /* 6074 80108874 00000000 */   nop
    /* 6078 80108878 17020292 */  lbu        $v0, 0x217($s0)
    /* 607C 8010887C 00000000 */  nop
    /* 6080 80108880 06004010 */  beqz       $v0, .L8010889C
    /* 6084 80108884 00000000 */   nop
    /* 6088 80108888 2320040C */  jal        _copyMiscToInventory
    /* 608C 8010888C 21207202 */   addu      $a0, $s3, $s2
    /* 6090 80108890 06000424 */  addiu      $a0, $zero, 0x6
    /* 6094 80108894 8B20040C */  jal        func_8010822C
    /* 6098 80108898 21284000 */   addu      $a1, $v0, $zero
  .L8010889C:
    /* 609C 8010889C 04005226 */  addiu      $s2, $s2, 0x4
    /* 60A0 801088A0 01003126 */  addiu      $s1, $s1, 0x1
    /* 60A4 801088A4 0300222A */  slti       $v0, $s1, 0x3
    /* 60A8 801088A8 EAFF4014 */  bnez       $v0, .L80108854
    /* 60AC 801088AC 04001026 */   addiu     $s0, $s0, 0x4
    /* 60B0 801088B0 3C20040C */  jal        func_801080F0
    /* 60B4 801088B4 00000000 */   nop
    /* 60B8 801088B8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 60BC 801088BC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 60C0 801088C0 1800B28F */  lw         $s2, 0x18($sp)
    /* 60C4 801088C4 1400B18F */  lw         $s1, 0x14($sp)
    /* 60C8 801088C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 60CC 801088CC 0800E003 */  jr         $ra
    /* 60D0 801088D0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _applyDropList
