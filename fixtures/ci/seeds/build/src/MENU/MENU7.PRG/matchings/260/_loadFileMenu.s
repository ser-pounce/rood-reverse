nonmatching _loadFileMenu, 0x3D4

glabel _loadFileMenu
    /* 59DC 801081DC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 59E0 801081E0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 59E4 801081E4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 59E8 801081E8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 59EC 801081EC 15008010 */  beqz       $a0, .L80108244
    /* 59F0 801081F0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 59F4 801081F4 1180033C */  lui        $v1, %hi(_loadFileMenuFadeout)
    /* 59F8 801081F8 FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 59FC 801081FC 1180043C */  lui        $a0, %hi(_loadFileMenuSelectedFile)
    /* 5A00 80108200 02AB62A0 */  sb         $v0, %lo(_loadFileMenuFadeout)($v1)
    /* 5A04 80108204 0680023C */  lui        $v0, %hi(D_80060021)
    /* 5A08 80108208 21004390 */  lbu        $v1, %lo(D_80060021)($v0)
    /* 5A0C 8010820C 01000224 */  addiu      $v0, $zero, 0x1
    /* 5A10 80108210 06006010 */  beqz       $v1, .L8010822C
    /* 5A14 80108214 01AB82A0 */   sb        $v0, %lo(_loadFileMenuSelectedFile)($a0)
    /* 5A18 80108218 0F80023C */  lui        $v0, %hi(D_800F4EE8 + 0x88)
    /* 5A1C 8010821C 704F4290 */  lbu        $v0, %lo(D_800F4EE8 + 0x88)($v0)
    /* 5A20 80108220 00000000 */  nop
    /* 5A24 80108224 01004224 */  addiu      $v0, $v0, 0x1
    /* 5A28 80108228 01AB82A0 */  sb         $v0, %lo(_loadFileMenuSelectedFile)($a0)
  .L8010822C:
    /* 5A2C 8010822C 21100000 */  addu       $v0, $zero, $zero
    /* 5A30 80108230 1180033C */  lui        $v1, %hi(_isSaving)
    /* 5A34 80108234 A8B060A0 */  sb         $zero, %lo(_isSaving)($v1)
    /* 5A38 80108238 1180033C */  lui        $v1, %hi(_loadFileMenuState)
    /* 5A3C 8010823C 66210408 */  j          .L80108598
    /* 5A40 80108240 00AB60A0 */   sb        $zero, %lo(_loadFileMenuState)($v1)
  .L80108244:
    /* 5A44 80108244 1180023C */  lui        $v0, %hi(_loadFileMenuState)
    /* 5A48 80108248 00AB4390 */  lbu        $v1, %lo(_loadFileMenuState)($v0)
    /* 5A4C 8010824C 00000000 */  nop
    /* 5A50 80108250 0900622C */  sltiu      $v0, $v1, 0x9
    /* 5A54 80108254 CF004010 */  beqz       $v0, .L80108594
    /* 5A58 80108258 1080023C */   lui       $v0, %hi(jtbl_80102980)
    /* 5A5C 8010825C 80294224 */  addiu      $v0, $v0, %lo(jtbl_80102980)
    /* 5A60 80108260 80180300 */  sll        $v1, $v1, 2
    /* 5A64 80108264 21186200 */  addu       $v1, $v1, $v0
    /* 5A68 80108268 0000628C */  lw         $v0, 0x0($v1)
    /* 5A6C 8010826C 00000000 */  nop
    /* 5A70 80108270 08004000 */  jr         $v0
    /* 5A74 80108274 00000000 */   nop
    /* 5A78 80108278 21200000 */  addu       $a0, $zero, $zero
    /* 5A7C 8010827C 2200053C */  lui        $a1, (0x220140 >> 16)
    /* 5A80 80108280 4001A534 */  ori        $a1, $a1, (0x220140 & 0xFFFF)
    /* 5A84 80108284 0C00063C */  lui        $a2, (0xC008C >> 16)
    /* 5A88 80108288 1180023C */  lui        $v0, %hi(_textTable)
    /* 5A8C 8010828C F8AD478C */  lw         $a3, %lo(_textTable)($v0)
    /* 5A90 80108290 8C00C634 */  ori        $a2, $a2, (0xC008C & 0xFFFF)
    /* 5A94 80108294 6E13040C */  jal        _initFileMenuElement
    /* 5A98 80108298 2801E724 */   addiu     $a3, $a3, 0x128
    /* 5A9C 8010829C 21204000 */  addu       $a0, $v0, $zero
    /* 5AA0 801082A0 02000224 */  addiu      $v0, $zero, 0x2
    /* 5AA4 801082A4 000082A0 */  sb         $v0, 0x0($a0)
    /* 5AA8 801082A8 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 5AAC 801082AC 01000324 */  addiu      $v1, $zero, 0x1
    /* 5AB0 801082B0 080082A4 */  sh         $v0, 0x8($a0)
    /* 5AB4 801082B4 08000224 */  addiu      $v0, $zero, 0x8
    /* 5AB8 801082B8 030082A0 */  sb         $v0, 0x3($a0)
    /* 5ABC 801082BC 1180023C */  lui        $v0, %hi(_loadFileMenuState)
    /* 5AC0 801082C0 040083A0 */  sb         $v1, 0x4($a0)
    /* 5AC4 801082C4 65210408 */  j          .L80108594
    /* 5AC8 801082C8 00AB43A0 */   sb        $v1, %lo(_loadFileMenuState)($v0)
    /* 5ACC 801082CC C113040C */  jal        _fileMenuElementsActive
    /* 5AD0 801082D0 00000000 */   nop
    /* 5AD4 801082D4 AF004010 */  beqz       $v0, .L80108594
    /* 5AD8 801082D8 01000424 */   addiu     $a0, $zero, 0x1
    /* 5ADC 801082DC 3200053C */  lui        $a1, (0x320140 >> 16)
    /* 5AE0 801082E0 4001A534 */  ori        $a1, $a1, (0x320140 & 0xFFFF)
    /* 5AE4 801082E4 0C00063C */  lui        $a2, (0xC007E >> 16)
    /* 5AE8 801082E8 1180023C */  lui        $v0, %hi(_textTable)
    /* 5AEC 801082EC F8AD478C */  lw         $a3, %lo(_textTable)($v0)
    /* 5AF0 801082F0 7E00C634 */  ori        $a2, $a2, (0xC007E & 0xFFFF)
    /* 5AF4 801082F4 6E13040C */  jal        _initFileMenuElement
    /* 5AF8 801082F8 4401E724 */   addiu     $a3, $a3, 0x144
    /* 5AFC 801082FC 21204000 */  addu       $a0, $v0, $zero
    /* 5B00 80108300 02000324 */  addiu      $v1, $zero, 0x2
    /* 5B04 80108304 C2000224 */  addiu      $v0, $zero, 0xC2
    /* 5B08 80108308 080082A4 */  sh         $v0, 0x8($a0)
    /* 5B0C 8010830C 1180023C */  lui        $v0, %hi(_loadFileMenuState)
    /* 5B10 80108310 000083A0 */  sb         $v1, 0x0($a0)
    /* 5B14 80108314 65210408 */  j          .L80108594
    /* 5B18 80108318 00AB43A0 */   sb        $v1, %lo(_loadFileMenuState)($v0)
    /* 5B1C 8010831C 02000424 */  addiu      $a0, $zero, 0x2
    /* 5B20 80108320 4200053C */  lui        $a1, (0x420140 >> 16)
    /* 5B24 80108324 4001A534 */  ori        $a1, $a1, (0x420140 & 0xFFFF)
    /* 5B28 80108328 0C00063C */  lui        $a2, (0xC007E >> 16)
    /* 5B2C 8010832C 1180023C */  lui        $v0, %hi(_textTable)
    /* 5B30 80108330 F8AD478C */  lw         $a3, %lo(_textTable)($v0)
    /* 5B34 80108334 7E00C634 */  ori        $a2, $a2, (0xC007E & 0xFFFF)
    /* 5B38 80108338 6E13040C */  jal        _initFileMenuElement
    /* 5B3C 8010833C 5801E724 */   addiu     $a3, $a3, 0x158
    /* 5B40 80108340 21204000 */  addu       $a0, $v0, $zero
    /* 5B44 80108344 02000224 */  addiu      $v0, $zero, 0x2
    /* 5B48 80108348 000082A0 */  sb         $v0, 0x0($a0)
    /* 5B4C 8010834C C2000224 */  addiu      $v0, $zero, 0xC2
    /* 5B50 80108350 1180033C */  lui        $v1, %hi(_loadFileMenuState)
    /* 5B54 80108354 080082A4 */  sh         $v0, 0x8($a0)
    /* 5B58 80108358 03000224 */  addiu      $v0, $zero, 0x3
    /* 5B5C 8010835C 65210408 */  j          .L80108594
    /* 5B60 80108360 00AB62A0 */   sb        $v0, %lo(_loadFileMenuState)($v1)
    /* 5B64 80108364 C113040C */  jal        _fileMenuElementsActive
    /* 5B68 80108368 00000000 */   nop
    /* 5B6C 8010836C 89004010 */  beqz       $v0, .L80108594
    /* 5B70 80108370 1180033C */   lui       $v1, %hi(_loadFileMenuState)
    /* 5B74 80108374 04000224 */  addiu      $v0, $zero, 0x4
    /* 5B78 80108378 00AB62A0 */  sb         $v0, %lo(_loadFileMenuState)($v1)
    /* 5B7C 8010837C 1180023C */  lui        $v0, %hi(_textTable)
    /* 5B80 80108380 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 5B84 80108384 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 5B88 80108388 6C014224 */  addiu      $v0, $v0, 0x16C
    /* 5B8C 8010838C 65210408 */  j          .L80108594
    /* 5B90 80108390 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
    /* 5B94 80108394 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 5B98 80108398 1180103C */  lui        $s0, %hi(_loadFileMenuSelectedFile)
    /* 5B9C 8010839C 01AB0392 */  lbu        $v1, %lo(_loadFileMenuSelectedFile)($s0)
    /* 5BA0 801083A0 50AE5124 */  addiu      $s1, $v0, %lo(_fileMenuElements)
    /* 5BA4 801083A4 40100300 */  sll        $v0, $v1, 1
    /* 5BA8 801083A8 21104300 */  addu       $v0, $v0, $v1
    /* 5BAC 801083AC 80100200 */  sll        $v0, $v0, 2
    /* 5BB0 801083B0 21104300 */  addu       $v0, $v0, $v1
    /* 5BB4 801083B4 80100200 */  sll        $v0, $v0, 2
    /* 5BB8 801083B8 21105100 */  addu       $v0, $v0, $s1
    /* 5BBC 801083BC 01000324 */  addiu      $v1, $zero, 0x1
    /* 5BC0 801083C0 040043A0 */  sb         $v1, 0x4($v0)
    /* 5BC4 801083C4 01AB0392 */  lbu        $v1, %lo(_loadFileMenuSelectedFile)($s0)
    /* 5BC8 801083C8 03001224 */  addiu      $s2, $zero, 0x3
    /* 5BCC 801083CC 23184302 */  subu       $v1, $s2, $v1
    /* 5BD0 801083D0 40100300 */  sll        $v0, $v1, 1
    /* 5BD4 801083D4 21104300 */  addu       $v0, $v0, $v1
    /* 5BD8 801083D8 80100200 */  sll        $v0, $v0, 2
    /* 5BDC 801083DC 21104300 */  addu       $v0, $v0, $v1
    /* 5BE0 801083E0 80100200 */  sll        $v0, $v0, 2
    /* 5BE4 801083E4 21105100 */  addu       $v0, $v0, $s1
    /* 5BE8 801083E8 040040A0 */  sb         $zero, 0x4($v0)
    /* 5BEC 801083EC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 5BF0 801083F0 D0E1438C */  lw         $v1, %lo(vs_main_buttonsPressed)($v0)
    /* 5BF4 801083F4 00000000 */  nop
    /* 5BF8 801083F8 40006230 */  andi       $v0, $v1, 0x40
    /* 5BFC 801083FC 13004010 */  beqz       $v0, .L8010844C
    /* 5C00 80108400 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 5C04 80108404 6216010C */  jal        vs_main_playSfxDefault
    /* 5C08 80108408 06000524 */   addiu     $a1, $zero, 0x6
    /* 5C0C 8010840C 1180023C */  lui        $v0, %hi(_selectCursorXy)
    /* 5C10 80108410 A0B040AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 5C14 80108414 21200000 */  addu       $a0, $zero, $zero
    /* 5C18 80108418 02000624 */  addiu      $a2, $zero, 0x2
    /* 5C1C 8010841C 40010524 */  addiu      $a1, $zero, 0x140
    /* 5C20 80108420 21182002 */  addu       $v1, $s1, $zero
  .L80108424:
    /* 5C24 80108424 000066A0 */  sb         $a2, 0x0($v1)
    /* 5C28 80108428 080065A4 */  sh         $a1, 0x8($v1)
    /* 5C2C 8010842C 01008424 */  addiu      $a0, $a0, 0x1
    /* 5C30 80108430 03008228 */  slti       $v0, $a0, 0x3
    /* 5C34 80108434 FBFF4014 */  bnez       $v0, .L80108424
    /* 5C38 80108438 34006324 */   addiu     $v1, $v1, 0x34
    /* 5C3C 8010843C 1180033C */  lui        $v1, %hi(_loadFileMenuState)
    /* 5C40 80108440 06000224 */  addiu      $v0, $zero, 0x6
    /* 5C44 80108444 65210408 */  j          .L80108594
    /* 5C48 80108448 00AB62A0 */   sb        $v0, %lo(_loadFileMenuState)($v1)
  .L8010844C:
    /* 5C4C 8010844C 20006230 */  andi       $v0, $v1, 0x20
    /* 5C50 80108450 0C004010 */  beqz       $v0, .L80108484
    /* 5C54 80108454 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 5C58 80108458 6216010C */  jal        vs_main_playSfxDefault
    /* 5C5C 8010845C 05000524 */   addiu     $a1, $zero, 0x5
    /* 5C60 80108460 01AB0492 */  lbu        $a0, %lo(_loadFileMenuSelectedFile)($s0)
    /* 5C64 80108464 A61F040C */  jal        _selectLoadMemoryCard
    /* 5C68 80108468 00000000 */   nop
    /* 5C6C 8010846C 1180023C */  lui        $v0, %hi(_selectCursorXy)
    /* 5C70 80108470 1180033C */  lui        $v1, %hi(_loadFileMenuState)
    /* 5C74 80108474 A0B040AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 5C78 80108478 05000224 */  addiu      $v0, $zero, 0x5
    /* 5C7C 8010847C 65210408 */  j          .L80108594
    /* 5C80 80108480 00AB62A0 */   sb        $v0, %lo(_loadFileMenuState)($v1)
  .L80108484:
    /* 5C84 80108484 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 5C88 80108488 00000000 */  nop
    /* 5C8C 8010848C 00504230 */  andi       $v0, $v0, 0x5000
    /* 5C90 80108490 09004010 */  beqz       $v0, .L801084B8
    /* 5C94 80108494 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 5C98 80108498 6216010C */  jal        vs_main_playSfxDefault
    /* 5C9C 8010849C 04000524 */   addiu     $a1, $zero, 0x4
    /* 5CA0 801084A0 01AB0292 */  lbu        $v0, %lo(_loadFileMenuSelectedFile)($s0)
    /* 5CA4 801084A4 0F80033C */  lui        $v1, %hi(D_800F4EE8 + 0x88)
    /* 5CA8 801084A8 23104202 */  subu       $v0, $s2, $v0
    /* 5CAC 801084AC 01AB02A2 */  sb         $v0, %lo(_loadFileMenuSelectedFile)($s0)
    /* 5CB0 801084B0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 5CB4 801084B4 704F62A0 */  sb         $v0, %lo(D_800F4EE8 + 0x88)($v1)
  .L801084B8:
    /* 5CB8 801084B8 01AB0292 */  lbu        $v0, %lo(_loadFileMenuSelectedFile)($s0)
    /* 5CBC 801084BC 1180033C */  lui        $v1, %hi(_selectCursorXy)
    /* 5CC0 801084C0 01004224 */  addiu      $v0, $v0, 0x1
    /* 5CC4 801084C4 00110200 */  sll        $v0, $v0, 4
    /* 5CC8 801084C8 0A004224 */  addiu      $v0, $v0, 0xA
    /* 5CCC 801084CC 00140200 */  sll        $v0, $v0, 16
    /* 5CD0 801084D0 B4004234 */  ori        $v0, $v0, 0xB4
    /* 5CD4 801084D4 65210408 */  j          .L80108594
    /* 5CD8 801084D8 A0B062AC */   sw        $v0, %lo(_selectCursorXy)($v1)
    /* 5CDC 801084DC A61F040C */  jal        _selectLoadMemoryCard
    /* 5CE0 801084E0 21200000 */   addu      $a0, $zero, $zero
    /* 5CE4 801084E4 21204000 */  addu       $a0, $v0, $zero
    /* 5CE8 801084E8 2B008010 */  beqz       $a0, .L80108598
    /* 5CEC 801084EC 21100000 */   addu      $v0, $zero, $zero
    /* 5CF0 801084F0 04008104 */  bgez       $a0, .L80108504
    /* 5CF4 801084F4 1180033C */   lui       $v1, %hi(_loadFileMenuState)
    /* 5CF8 801084F8 01000224 */  addiu      $v0, $zero, 0x1
    /* 5CFC 801084FC 65210408 */  j          .L80108594
    /* 5D00 80108500 00AB62A0 */   sb        $v0, %lo(_loadFileMenuState)($v1)
  .L80108504:
    /* 5D04 80108504 07000224 */  addiu      $v0, $zero, 0x7
    /* 5D08 80108508 65210408 */  j          .L80108594
    /* 5D0C 8010850C 00AB62A0 */   sb        $v0, %lo(_loadFileMenuState)($v1)
    /* 5D10 80108510 C113040C */  jal        _fileMenuElementsActive
    /* 5D14 80108514 00000000 */   nop
    /* 5D18 80108518 1E004010 */  beqz       $v0, .L80108594
    /* 5D1C 8010851C 1180023C */   lui       $v0, %hi(_loadFileMenuFadeout)
    /* 5D20 80108520 02AB4290 */  lbu        $v0, %lo(_loadFileMenuFadeout)($v0)
    /* 5D24 80108524 00000000 */  nop
    /* 5D28 80108528 03004014 */  bnez       $v0, .L80108538
    /* 5D2C 8010852C 1180033C */   lui       $v1, %hi(_loadFileMenuState)
    /* 5D30 80108530 66210408 */  j          .L80108598
    /* 5D34 80108534 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80108538:
    /* 5D38 80108538 08000224 */  addiu      $v0, $zero, 0x8
    /* 5D3C 8010853C 65210408 */  j          .L80108594
    /* 5D40 80108540 00AB62A0 */   sb        $v0, %lo(_loadFileMenuState)($v1)
    /* 5D44 80108544 1180033C */  lui        $v1, %hi(_fileMenuScreenFade)
    /* 5D48 80108548 AAB06290 */  lbu        $v0, %lo(_fileMenuScreenFade)($v1)
    /* 5D4C 8010854C 00000000 */  nop
    /* 5D50 80108550 01004224 */  addiu      $v0, $v0, 0x1
    /* 5D54 80108554 AAB062A0 */  sb         $v0, %lo(_fileMenuScreenFade)($v1)
    /* 5D58 80108558 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5D5C 8010855C 1F00422C */  sltiu      $v0, $v0, 0x1F
    /* 5D60 80108560 0D004014 */  bnez       $v0, .L80108598
    /* 5D64 80108564 21100000 */   addu      $v0, $zero, $zero
    /* 5D68 80108568 66210408 */  j          .L80108598
    /* 5D6C 8010856C 01000224 */   addiu     $v0, $zero, 0x1
    /* 5D70 80108570 1180043C */  lui        $a0, %hi(_fileMenuScreenFade)
    /* 5D74 80108574 AAB08390 */  lbu        $v1, %lo(_fileMenuScreenFade)($a0)
    /* 5D78 80108578 00000000 */  nop
    /* 5D7C 8010857C 01006324 */  addiu      $v1, $v1, 0x1
    /* 5D80 80108580 AAB083A0 */  sb         $v1, %lo(_fileMenuScreenFade)($a0)
    /* 5D84 80108584 FF006330 */  andi       $v1, $v1, 0xFF
    /* 5D88 80108588 1F00632C */  sltiu      $v1, $v1, 0x1F
    /* 5D8C 8010858C 02006010 */  beqz       $v1, .L80108598
    /* 5D90 80108590 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80108594:
    /* 5D94 80108594 21100000 */  addu       $v0, $zero, $zero
  .L80108598:
    /* 5D98 80108598 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 5D9C 8010859C 1800B28F */  lw         $s2, 0x18($sp)
    /* 5DA0 801085A0 1400B18F */  lw         $s1, 0x14($sp)
    /* 5DA4 801085A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 5DA8 801085A8 0800E003 */  jr         $ra
    /* 5DAC 801085AC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _loadFileMenu
