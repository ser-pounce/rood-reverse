nonmatching func_801087E4, 0x124

glabel func_801087E4
    /* 5FE4 801087E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5FE8 801087E8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5FEC 801087EC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5FF0 801087F0 88F4030C */  jal        vs_mainMenu_resetStats
    /* 5FF4 801087F4 04009024 */   addiu     $s0, $a0, 0x4
    /* 5FF8 801087F8 21280000 */  addu       $a1, $zero, $zero
    /* 5FFC 801087FC 20000724 */  addiu      $a3, $zero, 0x20
    /* 6000 80108800 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 6004 80108804 C0244824 */  addiu      $t0, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 6008 80108808 21300001 */  addu       $a2, $t0, $zero
  .L8010880C:
    /* 600C 8010880C 2120E800 */  addu       $a0, $a3, $t0
    /* 6010 80108810 0200E724 */  addiu      $a3, $a3, 0x2
    /* 6014 80108814 0700A330 */  andi       $v1, $a1, 0x7
    /* 6018 80108818 21180302 */  addu       $v1, $s0, $v1
    /* 601C 8010881C 14006290 */  lbu        $v0, 0x14($v1)
    /* 6020 80108820 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6024 80108824 00160200 */  sll        $v0, $v0, 24
    /* 6028 80108828 03160200 */  sra        $v0, $v0, 24
    /* 602C 8010882C 0000C2A4 */  sh         $v0, 0x0($a2)
    /* 6030 80108830 1C006290 */  lbu        $v0, 0x1C($v1)
    /* 6034 80108834 00000000 */  nop
    /* 6038 80108838 00160200 */  sll        $v0, $v0, 24
    /* 603C 8010883C 03160200 */  sra        $v0, $v0, 24
    /* 6040 80108840 000082A4 */  sh         $v0, 0x0($a0)
    /* 6044 80108844 1000A228 */  slti       $v0, $a1, 0x10
    /* 6048 80108848 F0FF4014 */  bnez       $v0, .L8010880C
    /* 604C 8010884C 0200C624 */   addiu     $a2, $a2, 0x2
    /* 6050 80108850 21280000 */  addu       $a1, $zero, $zero
    /* 6054 80108854 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 6058 80108858 C0244624 */  addiu      $a2, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 605C 8010885C 40000424 */  addiu      $a0, $zero, 0x40
  .L80108860:
    /* 6060 80108860 21188600 */  addu       $v1, $a0, $a2
    /* 6064 80108864 21100502 */  addu       $v0, $s0, $a1
    /* 6068 80108868 10004290 */  lbu        $v0, 0x10($v0)
    /* 606C 8010886C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6070 80108870 00160200 */  sll        $v0, $v0, 24
    /* 6074 80108874 03160200 */  sra        $v0, $v0, 24
    /* 6078 80108878 000062A4 */  sh         $v0, 0x0($v1)
    /* 607C 8010887C 0400A228 */  slti       $v0, $a1, 0x4
    /* 6080 80108880 F7FF4014 */  bnez       $v0, .L80108860
    /* 6084 80108884 02008424 */   addiu     $a0, $a0, 0x2
    /* 6088 80108888 21300000 */  addu       $a2, $zero, $zero
    /* 608C 8010888C 08000496 */  lhu        $a0, 0x8($s0)
    /* 6090 80108890 04000596 */  lhu        $a1, 0x4($s0)
    /* 6094 80108894 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 6098 80108898 2138C000 */   addu      $a3, $a2, $zero
    /* 609C 8010889C 0D000482 */  lb         $a0, 0xD($s0)
    /* 60A0 801088A0 0E000582 */  lb         $a1, 0xE($s0)
    /* 60A4 801088A4 0F000682 */  lb         $a2, 0xF($s0)
    /* 60A8 801088A8 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 60AC 801088AC 01000724 */   addiu     $a3, $zero, 0x1
    /* 60B0 801088B0 1080043C */  lui        $a0, %hi(vs_mainMenu_strIntAgi)
    /* 60B4 801088B4 0D000292 */  lbu        $v0, 0xD($s0)
    /* 60B8 801088B8 A8248424 */  addiu      $a0, $a0, %lo(vs_mainMenu_strIntAgi)
    /* 60BC 801088BC 00160200 */  sll        $v0, $v0, 24
    /* 60C0 801088C0 03160200 */  sra        $v0, $v0, 24
    /* 60C4 801088C4 080082A4 */  sh         $v0, 0x8($a0)
    /* 60C8 801088C8 0E000292 */  lbu        $v0, 0xE($s0)
    /* 60CC 801088CC 00000000 */  nop
    /* 60D0 801088D0 00160200 */  sll        $v0, $v0, 24
    /* 60D4 801088D4 03160200 */  sra        $v0, $v0, 24
    /* 60D8 801088D8 0A0082A4 */  sh         $v0, 0xA($a0)
    /* 60DC 801088DC 0F000292 */  lbu        $v0, 0xF($s0)
    /* 60E0 801088E0 1080053C */  lui        $a1, %hi(vs_mainMenu_equipmentSubtype)
    /* 60E4 801088E4 00160200 */  sll        $v0, $v0, 24
    /* 60E8 801088E8 03160200 */  sra        $v0, $v0, 24
    /* 60EC 801088EC 0C0082A4 */  sh         $v0, 0xC($a0)
    /* 60F0 801088F0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 60F4 801088F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 60F8 801088F8 08000324 */  addiu      $v1, $zero, 0x8
    /* 60FC 801088FC 4525A3A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($a1)
    /* 6100 80108900 0800E003 */  jr         $ra
    /* 6104 80108904 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_801087E4
