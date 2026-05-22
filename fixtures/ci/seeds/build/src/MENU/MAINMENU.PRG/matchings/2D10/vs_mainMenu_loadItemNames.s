nonmatching vs_mainMenu_loadItemNames, 0xC8

glabel vs_mainMenu_loadItemNames
    /* 4DCC 800FE5CC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4DD0 800FE5D0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4DD4 800FE5D4 1C008010 */  beqz       $a0, .L800FE648
    /* 4DD8 800FE5D8 1800B0AF */   sw        $s0, 0x18($sp)
    /* 4DDC 800FE5DC 8F0F010C */  jal        vs_main_allocHeapR
    /* 4DE0 800FE5E0 00B00434 */   ori       $a0, $zero, 0xB000
    /* 4DE4 800FE5E4 0100053C */  lui        $a1, (0x14D49 >> 16)
    /* 4DE8 800FE5E8 494DA534 */  ori        $a1, $a1, (0x14D49 & 0xFFFF)
    /* 4DEC 800FE5EC 1000A427 */  addiu      $a0, $sp, 0x10
    /* 4DF0 800FE5F0 1080103C */  lui        $s0, %hi(vs_mainMenu_itemNames)
    /* 4DF4 800FE5F4 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 4DF8 800FE5F8 9C2202AE */  sw         $v0, %lo(vs_mainMenu_itemNames)($s0)
    /* 4DFC 800FE5FC 00304224 */  addiu      $v0, $v0, 0x3000
    /* 4E00 800FE600 402562AC */  sw         $v0, %lo(vs_mainMenu_itemHelp)($v1)
    /* 4E04 800FE604 1080033C */  lui        $v1, %hi(vs_mainMenu_menu12Text)
    /* 4E08 800FE608 00704224 */  addiu      $v0, $v0, 0x7000
    /* 4E0C 800FE60C A42462AC */  sw         $v0, %lo(vs_mainMenu_menu12Text)($v1)
    /* 4E10 800FE610 00B00234 */  ori        $v0, $zero, 0xB000
    /* 4E14 800FE614 1000A5AF */  sw         $a1, 0x10($sp)
    /* 4E18 800FE618 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 4E1C 800FE61C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 4E20 800FE620 21204000 */  addu       $a0, $v0, $zero
    /* 4E24 800FE624 9C22058E */  lw         $a1, %lo(vs_mainMenu_itemNames)($s0)
    /* 4E28 800FE628 1080023C */  lui        $v0, %hi(_itemNamesCdQueueSlot)
    /* 4E2C 800FE62C F112010C */  jal        vs_main_cdEnqueue
    /* 4E30 800FE630 782444AC */   sw        $a0, %lo(_itemNamesCdQueueSlot)($v0)
    /* 4E34 800FE634 21100000 */  addu       $v0, $zero, $zero
    /* 4E38 800FE638 1080043C */  lui        $a0, %hi(_itemNamesLoading)
    /* 4E3C 800FE63C 01000324 */  addiu      $v1, $zero, 0x1
    /* 4E40 800FE640 A1F90308 */  j          .L800FE684
    /* 4E44 800FE644 7C2483A0 */   sb        $v1, %lo(_itemNamesLoading)($a0)
  .L800FE648:
    /* 4E48 800FE648 1080103C */  lui        $s0, %hi(_itemNamesLoading)
    /* 4E4C 800FE64C 7C240292 */  lbu        $v0, %lo(_itemNamesLoading)($s0)
    /* 4E50 800FE650 00000000 */  nop
    /* 4E54 800FE654 0A004010 */  beqz       $v0, .L800FE680
    /* 4E58 800FE658 1080023C */   lui       $v0, %hi(_itemNamesCdQueueSlot)
    /* 4E5C 800FE65C 7824448C */  lw         $a0, %lo(_itemNamesCdQueueSlot)($v0)
    /* 4E60 800FE660 00000000 */  nop
    /* 4E64 800FE664 00008384 */  lh         $v1, 0x0($a0)
    /* 4E68 800FE668 04000224 */  addiu      $v0, $zero, 0x4
    /* 4E6C 800FE66C 05006214 */  bne        $v1, $v0, .L800FE684
    /* 4E70 800FE670 21100000 */   addu      $v0, $zero, $zero
    /* 4E74 800FE674 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 4E78 800FE678 00000000 */   nop
    /* 4E7C 800FE67C 7C2400A2 */  sb         $zero, %lo(_itemNamesLoading)($s0)
  .L800FE680:
    /* 4E80 800FE680 01000224 */  addiu      $v0, $zero, 0x1
  .L800FE684:
    /* 4E84 800FE684 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4E88 800FE688 1800B08F */  lw         $s0, 0x18($sp)
    /* 4E8C 800FE68C 0800E003 */  jr         $ra
    /* 4E90 800FE690 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_mainMenu_loadItemNames
