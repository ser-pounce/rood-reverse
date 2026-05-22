nonmatching func_801077DC, 0x80

glabel func_801077DC
    /* 4FDC 801077DC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4FE0 801077E0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4FE4 801077E4 0B00A014 */  bnez       $a1, .L80107814
    /* 4FE8 801077E8 1000A0AF */   sw        $zero, 0x10($sp)
    /* 4FEC 801077EC 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 4FF0 801077F0 A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 4FF4 801077F4 40100400 */  sll        $v0, $a0, 1
    /* 4FF8 801077F8 21104300 */  addu       $v0, $v0, $v1
    /* 4FFC 801077FC 9E004294 */  lhu        $v0, 0x9E($v0)
    /* 5000 80107800 00000000 */  nop
    /* 5004 80107804 40100200 */  sll        $v0, $v0, 1
    /* 5008 80107808 21186200 */  addu       $v1, $v1, $v0
    /* 500C 8010780C 0C1E0408 */  j          .L80107830
    /* 5010 80107810 1400A3AF */   sw        $v1, 0x14($sp)
  .L80107814:
    /* 5014 80107814 1080023C */  lui        $v0, %hi(vs_mainMenu_itemNames)
    /* 5018 80107818 40180500 */  sll        $v1, $a1, 1
    /* 501C 8010781C 21186500 */  addu       $v1, $v1, $a1
    /* 5020 80107820 9C22428C */  lw         $v0, %lo(vs_mainMenu_itemNames)($v0)
    /* 5024 80107824 C0180300 */  sll        $v1, $v1, 3
    /* 5028 80107828 21104300 */  addu       $v0, $v0, $v1
    /* 502C 8010782C 1400A2AF */  sw         $v0, 0x14($sp)
  .L80107830:
    /* 5030 80107830 21200000 */  addu       $a0, $zero, $zero
    /* 5034 80107834 9B000524 */  addiu      $a1, $zero, 0x9B
    /* 5038 80107838 12000624 */  addiu      $a2, $zero, 0x12
    /* 503C 8010783C 9723030C */  jal        vs_battle_setMenuItem
    /* 5040 80107840 A5000724 */   addiu     $a3, $zero, 0xA5
    /* 5044 80107844 01000324 */  addiu      $v1, $zero, 0x1
    /* 5048 80107848 060043A0 */  sb         $v1, 0x6($v0)
    /* 504C 8010784C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5050 80107850 00000000 */  nop
    /* 5054 80107854 0800E003 */  jr         $ra
    /* 5058 80107858 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_801077DC
