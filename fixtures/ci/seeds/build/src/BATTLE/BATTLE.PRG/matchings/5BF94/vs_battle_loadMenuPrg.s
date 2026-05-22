nonmatching vs_battle_loadMenuPrg, 0x1B4

glabel vs_battle_loadMenuPrg
    /* 60450 800C8C50 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 60454 800C8C54 0F80023C */  lui        $v0, %hi(vs_battle_menuState)
    /* 60458 800C8C58 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6045C 800C8C5C C0515124 */  addiu      $s1, $v0, %lo(vs_battle_menuState)
    /* 60460 800C8C60 1800B0AF */  sw         $s0, 0x18($sp)
    /* 60464 800C8C64 1F009030 */  andi       $s0, $a0, 0x1F
    /* 60468 800C8C68 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 6046C 800C8C6C 55000212 */  beq        $s0, $v0, .L800C8DC4
    /* 60470 800C8C70 2000BFAF */   sw        $ra, 0x20($sp)
    /* 60474 800C8C74 07000016 */  bnez       $s0, .L800C8C94
    /* 60478 800C8C78 0F80033C */   lui       $v1, %hi(_loadedSubMenu)
    /* 6047C 800C8C7C 0F80023C */  lui        $v0, %hi(_loadedSubMenu)
    /* 60480 800C8C80 ADB94280 */  lb         $v0, %lo(_loadedSubMenu)($v0)
    /* 60484 800C8C84 00000000 */  nop
    /* 60488 800C8C88 5900401C */  bgtz       $v0, .L800C8DF0
    /* 6048C 800C8C8C 01000224 */   addiu     $v0, $zero, 0x1
    /* 60490 800C8C90 0F80033C */  lui        $v1, %hi(_loadedSubMenu)
  .L800C8C94:
    /* 60494 800C8C94 ADB96280 */  lb         $v0, %lo(_loadedSubMenu)($v1)
    /* 60498 800C8C98 00000000 */  nop
    /* 6049C 800C8C9C 22005010 */  beq        $v0, $s0, .L800C8D28
    /* 604A0 800C8CA0 01000224 */   addiu     $v0, $zero, 0x1
    /* 604A4 800C8CA4 ADB970A0 */  sb         $s0, %lo(_loadedSubMenu)($v1)
    /* 604A8 800C8CA8 030022A2 */  sb         $v0, 0x3($s1)
    /* 604AC 800C8CAC 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 604B0 800C8CB0 6A4E4390 */  lbu        $v1, %lo(vs_battle_shortcutInvoked)($v0)
    /* 604B4 800C8CB4 05000224 */  addiu      $v0, $zero, 0x5
    /* 604B8 800C8CB8 07006210 */  beq        $v1, $v0, .L800C8CD8
    /* 604BC 800C8CBC 0F80033C */   lui       $v1, %hi(_menuLbas)
    /* 604C0 800C8CC0 C8B56324 */  addiu      $v1, $v1, %lo(_menuLbas)
    /* 604C4 800C8CC4 80101000 */  sll        $v0, $s0, 2
    /* 604C8 800C8CC8 21104300 */  addu       $v0, $v0, $v1
    /* 604CC 800C8CCC 0000438C */  lw         $v1, 0x0($v0)
    /* 604D0 800C8CD0 39230308 */  j          .L800C8CE4
    /* 604D4 800C8CD4 1000A427 */   addiu     $a0, $sp, 0x10
  .L800C8CD8:
    /* 604D8 800C8CD8 4C01033C */  lui        $v1, (0x14C0812 >> 16)
    /* 604DC 800C8CDC 12086334 */  ori        $v1, $v1, (0x14C0812 & 0xFFFF)
    /* 604E0 800C8CE0 1000A427 */  addiu      $a0, $sp, 0x10
  .L800C8CE4:
    /* 604E4 800C8CE4 02120300 */  srl        $v0, $v1, 8
    /* 604E8 800C8CE8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 604EC 800C8CEC FF006230 */  andi       $v0, $v1, 0xFF
    /* 604F0 800C8CF0 C0120200 */  sll        $v0, $v0, 11
    /* 604F4 800C8CF4 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 604F8 800C8CF8 1400A2AF */   sw        $v0, 0x14($sp)
    /* 604FC 800C8CFC 05000016 */  bnez       $s0, .L800C8D14
    /* 60500 800C8D00 040022AE */   sw        $v0, 0x4($s1)
    /* 60504 800C8D04 0180023C */  lui        $v0, %hi(vs_overlay_slots + 0x4)
    /* 60508 800C8D08 0400458C */  lw         $a1, %lo(vs_overlay_slots + 0x4)($v0)
    /* 6050C 800C8D0C 47230308 */  j          .L800C8D1C
    /* 60510 800C8D10 00000000 */   nop
  .L800C8D14:
    /* 60514 800C8D14 0180023C */  lui        $v0, %hi(vs_overlay_slots + 0x8)
    /* 60518 800C8D18 0800458C */  lw         $a1, %lo(vs_overlay_slots + 0x8)($v0)
  .L800C8D1C:
    /* 6051C 800C8D1C 0400248E */  lw         $a0, 0x4($s1)
    /* 60520 800C8D20 F112010C */  jal        vs_main_cdEnqueue
    /* 60524 800C8D24 00000000 */   nop
  .L800C8D28:
    /* 60528 800C8D28 03002292 */  lbu        $v0, 0x3($s1)
    /* 6052C 800C8D2C 00000000 */  nop
    /* 60530 800C8D30 0C004014 */  bnez       $v0, .L800C8D64
    /* 60534 800C8D34 04000224 */   addiu     $v0, $zero, 0x4
    /* 60538 800C8D38 0F80103C */  lui        $s0, %hi(_menuBgUnpackedBuf)
    /* 6053C 800C8D3C D4B9048E */  lw         $a0, %lo(_menuBgUnpackedBuf)($s0)
    /* 60540 800C8D40 00000000 */  nop
    /* 60544 800C8D44 2A008010 */  beqz       $a0, .L800C8DF0
    /* 60548 800C8D48 01000224 */   addiu     $v0, $zero, 0x1
    /* 6054C 800C8D4C 180F010C */  jal        vs_main_freeHeapR
    /* 60550 800C8D50 00000000 */   nop
    /* 60554 800C8D54 12E9030C */  jal        vs_mainMenu_initInventory
    /* 60558 800C8D58 D4B900AE */   sw        $zero, %lo(_menuBgUnpackedBuf)($s0)
    /* 6055C 800C8D5C 7C230308 */  j          .L800C8DF0
    /* 60560 800C8D60 01000224 */   addiu     $v0, $zero, 0x1
  .L800C8D64:
    /* 60564 800C8D64 0400248E */  lw         $a0, 0x4($s1)
    /* 60568 800C8D68 00000000 */  nop
    /* 6056C 800C8D6C 00008384 */  lh         $v1, 0x0($a0)
    /* 60570 800C8D70 00000000 */  nop
    /* 60574 800C8D74 1E006214 */  bne        $v1, $v0, .L800C8DF0
    /* 60578 800C8D78 21100000 */   addu      $v0, $zero, $zero
    /* 6057C 800C8D7C E012010C */  jal        vs_main_freeCdQueueSlot
    /* 60580 800C8D80 00000000 */   nop
    /* 60584 800C8D84 1D0B010C */  jal        vs_main_wait
    /* 60588 800C8D88 00000000 */   nop
    /* 6058C 800C8D8C 0F80023C */  lui        $v0, %hi(D_800F4FDB)
    /* 60590 800C8D90 DB4F4290 */  lbu        $v0, %lo(D_800F4FDB)($v0)
    /* 60594 800C8D94 00000000 */  nop
    /* 60598 800C8D98 0C004010 */  beqz       $v0, .L800C8DCC
    /* 6059C 800C8D9C 030020A2 */   sb        $zero, 0x3($s1)
    /* 605A0 800C8DA0 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 605A4 800C8DA4 6A4E4390 */  lbu        $v1, %lo(vs_battle_shortcutInvoked)($v0)
    /* 605A8 800C8DA8 05000224 */  addiu      $v0, $zero, 0x5
    /* 605AC 800C8DAC 10006214 */  bne        $v1, $v0, .L800C8DF0
    /* 605B0 800C8DB0 01000224 */   addiu     $v0, $zero, 0x1
    /* 605B4 800C8DB4 AFEB030C */  jal        func_800FAEBC
    /* 605B8 800C8DB8 01000424 */   addiu     $a0, $zero, 0x1
    /* 605BC 800C8DBC 7C230308 */  j          .L800C8DF0
    /* 605C0 800C8DC0 21100000 */   addu      $v0, $zero, $zero
  .L800C8DC4:
    /* 605C4 800C8DC4 7C230308 */  j          .L800C8DF0
    /* 605C8 800C8DC8 01000224 */   addiu     $v0, $zero, 0x1
  .L800C8DCC:
    /* 605CC 800C8DCC 08000016 */  bnez       $s0, .L800C8DF0
    /* 605D0 800C8DD0 21100000 */   addu      $v0, $zero, $zero
    /* 605D4 800C8DD4 8F0F010C */  jal        vs_main_allocHeapR
    /* 605D8 800C8DD8 00B40434 */   ori       $a0, $zero, 0xB400
    /* 605DC 800C8DDC 0F80033C */  lui        $v1, %hi(_menuBgUnpackedBuf)
    /* 605E0 800C8DE0 D4B962AC */  sw         $v0, %lo(_menuBgUnpackedBuf)($v1)
    /* 605E4 800C8DE4 1301040C */  jal        vs_mainMenu_unpackMenubg
    /* 605E8 800C8DE8 21204000 */   addu      $a0, $v0, $zero
    /* 605EC 800C8DEC 21100000 */  addu       $v0, $zero, $zero
  .L800C8DF0:
    /* 605F0 800C8DF0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 605F4 800C8DF4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 605F8 800C8DF8 1800B08F */  lw         $s0, 0x18($sp)
    /* 605FC 800C8DFC 0800E003 */  jr         $ra
    /* 60600 800C8E00 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_battle_loadMenuPrg
