nonmatching _showLoadFilesMenu, 0x61C

glabel _showLoadFilesMenu
    /* 507C 8010787C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5080 80107880 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5084 80107884 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5088 80107888 1400B1AF */  sw         $s1, 0x14($sp)
    /* 508C 8010788C 1D008010 */  beqz       $a0, .L80107904
    /* 5090 80107890 1000B0AF */   sw        $s0, 0x10($sp)
    /* 5094 80107894 1180023C */  lui        $v0, %hi(_showLoadFilesMenuPort)
    /* 5098 80107898 2D0B040C */  jal        _getNewestSaveFile
    /* 509C 8010789C F9AA44A0 */   sb        $a0, %lo(_showLoadFilesMenuPort)($v0)
    /* 50A0 801078A0 1180103C */  lui        $s0, %hi(_showLoadFilesMenuSelectedSlot)
    /* 50A4 801078A4 21184000 */  addu       $v1, $v0, $zero
    /* 50A8 801078A8 1180053C */  lui        $a1, %hi(_showLoadFilesMenuPage)
    /* 50AC 801078AC FF006430 */  andi       $a0, $v1, 0xFF
    /* 50B0 801078B0 04000224 */  addiu      $v0, $zero, 0x4
    /* 50B4 801078B4 FBAA03A2 */  sb         $v1, %lo(_showLoadFilesMenuSelectedSlot)($s0)
    /* 50B8 801078B8 04008214 */  bne        $a0, $v0, .L801078CC
    /* 50BC 801078BC FAAAA0A0 */   sb        $zero, %lo(_showLoadFilesMenuPage)($a1)
    /* 50C0 801078C0 02000224 */  addiu      $v0, $zero, 0x2
    /* 50C4 801078C4 371E0408 */  j          .L801078DC
    /* 50C8 801078C8 FAAAA2A0 */   sb        $v0, %lo(_showLoadFilesMenuPage)($a1)
  .L801078CC:
    /* 50CC 801078CC 04008010 */  beqz       $a0, .L801078E0
    /* 50D0 801078D0 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 50D4 801078D4 FAAAA2A0 */  sb         $v0, %lo(_showLoadFilesMenuPage)($a1)
    /* 50D8 801078D8 01000224 */  addiu      $v0, $zero, 0x1
  .L801078DC:
    /* 50DC 801078DC FBAA02A2 */  sb         $v0, %lo(_showLoadFilesMenuSelectedSlot)($s0)
  .L801078E0:
    /* 50E0 801078E0 21100000 */  addu       $v0, $zero, $zero
    /* 50E4 801078E4 1180043C */  lui        $a0, %hi(_showLoadFilesMenuFileLoaded)
    /* 50E8 801078E8 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 50EC 801078EC F4AA83AC */  sw         $v1, %lo(_showLoadFilesMenuFileLoaded)($a0)
    /* 50F0 801078F0 1180033C */  lui        $v1, %hi(_showLoadFilesMenuCompleteTimer)
    /* 50F4 801078F4 FDAA60A0 */  sb         $zero, %lo(_showLoadFilesMenuCompleteTimer)($v1)
    /* 50F8 801078F8 1180033C */  lui        $v1, %hi(_showLoadFilesMenuState)
    /* 50FC 801078FC A01F0408 */  j          .L80107E80
    /* 5100 80107900 F8AA60A0 */   sb        $zero, %lo(_showLoadFilesMenuState)($v1)
  .L80107904:
    /* 5104 80107904 1180023C */  lui        $v0, %hi(_showLoadFilesMenuState)
    /* 5108 80107908 F8AA4390 */  lbu        $v1, %lo(_showLoadFilesMenuState)($v0)
    /* 510C 8010790C 00000000 */  nop
    /* 5110 80107910 0600622C */  sltiu      $v0, $v1, 0x6
    /* 5114 80107914 59014010 */  beqz       $v0, .L80107E7C
    /* 5118 80107918 1080023C */   lui       $v0, %hi(jtbl_80102948)
    /* 511C 8010791C 48294224 */  addiu      $v0, $v0, %lo(jtbl_80102948)
    /* 5120 80107920 80180300 */  sll        $v1, $v1, 2
    /* 5124 80107924 21186200 */  addu       $v1, $v1, $v0
    /* 5128 80107928 0000628C */  lw         $v0, 0x0($v1)
    /* 512C 8010792C 00000000 */  nop
    /* 5130 80107930 08004000 */  jr         $v0
    /* 5134 80107934 00000000 */   nop
    /* 5138 80107938 21800000 */  addu       $s0, $zero, $zero
    /* 513C 8010793C 1180123C */  lui        $s2, %hi(_saveFileInfo)
    /* 5140 80107940 4800113C */  lui        $s1, (0x480040 >> 16)
    /* 5144 80107944 05000426 */  addiu      $a0, $s0, 0x5
  .L80107948:
    /* 5148 80107948 40002536 */  ori        $a1, $s1, (0x480040 & 0xFFFF)
    /* 514C 8010794C 2000063C */  lui        $a2, (0x200100 >> 16)
    /* 5150 80107950 0001C634 */  ori        $a2, $a2, (0x200100 & 0xFFFF)
    /* 5154 80107954 6E13040C */  jal        _initFileMenuElement
    /* 5158 80107958 21380000 */   addu      $a3, $zero, $zero
    /* 515C 8010795C 010050A0 */  sb         $s0, 0x1($v0)
    /* 5160 80107960 40AE438E */  lw         $v1, %lo(_saveFileInfo)($s2)
    /* 5164 80107964 C0291000 */  sll        $a1, $s0, 7
    /* 5168 80107968 2118A300 */  addu       $v1, $a1, $v1
    /* 516C 8010796C 0400638C */  lw         $v1, 0x4($v1)
    /* 5170 80107970 00000000 */  nop
    /* 5174 80107974 0300632C */  sltiu      $v1, $v1, 0x3
    /* 5178 80107978 050043A0 */  sb         $v1, 0x5($v0)
    /* 517C 8010797C 2800033C */  lui        $v1, (0x280000 >> 16)
    /* 5180 80107980 40AE448E */  lw         $a0, %lo(_saveFileInfo)($s2)
    /* 5184 80107984 21882302 */  addu       $s1, $s1, $v1
    /* 5188 80107988 2128A400 */  addu       $a1, $a1, $a0
    /* 518C 8010798C 1C00A390 */  lbu        $v1, 0x1C($a1)
    /* 5190 80107990 01001026 */  addiu      $s0, $s0, 0x1
    /* 5194 80107994 060043A0 */  sb         $v1, 0x6($v0)
    /* 5198 80107998 0500022A */  slti       $v0, $s0, 0x5
    /* 519C 8010799C EAFF4014 */  bnez       $v0, .L80107948
    /* 51A0 801079A0 05000426 */   addiu     $a0, $s0, 0x5
    /* 51A4 801079A4 1180033C */  lui        $v1, %hi(_showLoadFilesMenuState)
    /* 51A8 801079A8 01000224 */  addiu      $v0, $zero, 0x1
    /* 51AC 801079AC F8AA62A0 */  sb         $v0, %lo(_showLoadFilesMenuState)($v1)
    /* 51B0 801079B0 1180023C */  lui        $v0, %hi(_textTable)
    /* 51B4 801079B4 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 51B8 801079B8 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 51BC 801079BC 76024224 */  addiu      $v0, $v0, 0x276
    /* 51C0 801079C0 A4B062AC */  sw         $v0, %lo(_memoryCardMessage)($v1)
    /* 51C4 801079C4 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 51C8 801079C8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 51CC 801079CC 00000000 */  nop
    /* 51D0 801079D0 40004230 */  andi       $v0, $v0, 0x40
    /* 51D4 801079D4 0D004010 */  beqz       $v0, .L80107A0C
    /* 51D8 801079D8 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 51DC 801079DC 6216010C */  jal        vs_main_playSfxDefault
    /* 51E0 801079E0 06000524 */   addiu     $a1, $zero, 0x6
    /* 51E4 801079E4 05001024 */  addiu      $s0, $zero, 0x5
  .L801079E8:
    /* 51E8 801079E8 B013040C */  jal        _clearFileMenuElement
    /* 51EC 801079EC 21200002 */   addu      $a0, $s0, $zero
    /* 51F0 801079F0 01001026 */  addiu      $s0, $s0, 0x1
    /* 51F4 801079F4 0A00022A */  slti       $v0, $s0, 0xA
    /* 51F8 801079F8 FBFF4014 */  bnez       $v0, .L801079E8
    /* 51FC 801079FC 1180023C */   lui       $v0, %hi(_selectCursorXy)
    /* 5200 80107A00 A0B040AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 5204 80107A04 A01F0408 */  j          .L80107E80
    /* 5208 80107A08 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80107A0C:
    /* 520C 80107A0C 21800000 */  addu       $s0, $zero, $zero
    /* 5210 80107A10 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 5214 80107A14 50AE4724 */  addiu      $a3, $v0, %lo(_fileMenuElements)
    /* 5218 80107A18 1180063C */  lui        $a2, %hi(_showLoadFilesMenuPage)
    /* 521C 80107A1C 04010524 */  addiu      $a1, $zero, 0x104
  .L80107A20:
    /* 5220 80107A20 2120A700 */  addu       $a0, $a1, $a3
    /* 5224 80107A24 FAAAC390 */  lbu        $v1, %lo(_showLoadFilesMenuPage)($a2)
    /* 5228 80107A28 040080A0 */  sb         $zero, 0x4($a0)
    /* 522C 80107A2C 23180302 */  subu       $v1, $s0, $v1
    /* 5230 80107A30 01001026 */  addiu      $s0, $s0, 0x1
    /* 5234 80107A34 80100300 */  sll        $v0, $v1, 2
    /* 5238 80107A38 21104300 */  addu       $v0, $v0, $v1
    /* 523C 80107A3C C0100200 */  sll        $v0, $v0, 3
    /* 5240 80107A40 48004224 */  addiu      $v0, $v0, 0x48
    /* 5244 80107A44 0E0082A4 */  sh         $v0, 0xE($a0)
    /* 5248 80107A48 0500022A */  slti       $v0, $s0, 0x5
    /* 524C 80107A4C F4FF4014 */  bnez       $v0, .L80107A20
    /* 5250 80107A50 3400A524 */   addiu     $a1, $a1, 0x34
    /* 5254 80107A54 1180023C */  lui        $v0, %hi(_showLoadFilesMenuSelectedSlot)
    /* 5258 80107A58 1180033C */  lui        $v1, %hi(_showLoadFilesMenuPage)
    /* 525C 80107A5C 0680043C */  lui        $a0, %hi(vs_main_buttonsPressed)
    /* 5260 80107A60 FBAA4590 */  lbu        $a1, %lo(_showLoadFilesMenuSelectedSlot)($v0)
    /* 5264 80107A64 FAAA6390 */  lbu        $v1, %lo(_showLoadFilesMenuPage)($v1)
    /* 5268 80107A68 D0E1828C */  lw         $v0, %lo(vs_main_buttonsPressed)($a0)
    /* 526C 80107A6C 00000000 */  nop
    /* 5270 80107A70 20004230 */  andi       $v0, $v0, 0x20
    /* 5274 80107A74 23004010 */  beqz       $v0, .L80107B04
    /* 5278 80107A78 2180A300 */   addu      $s0, $a1, $v1
    /* 527C 80107A7C 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* 5280 80107A80 40AE438C */  lw         $v1, %lo(_saveFileInfo)($v0)
    /* 5284 80107A84 C0111000 */  sll        $v0, $s0, 7
    /* 5288 80107A88 21104300 */  addu       $v0, $v0, $v1
    /* 528C 80107A8C 0400428C */  lw         $v0, 0x4($v0)
    /* 5290 80107A90 00000000 */  nop
    /* 5294 80107A94 0300422C */  sltiu      $v0, $v0, 0x3
    /* 5298 80107A98 18004014 */  bnez       $v0, .L80107AFC
    /* 529C 80107A9C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 52A0 80107AA0 6216010C */  jal        vs_main_playSfxDefault
    /* 52A4 80107AA4 05000524 */   addiu     $a1, $zero, 0x5
    /* 52A8 80107AA8 1180043C */  lui        $a0, %hi(_fileMenuElements)
    /* 52AC 80107AAC 50AE8424 */  addiu      $a0, $a0, %lo(_fileMenuElements)
    /* 52B0 80107AB0 05000326 */  addiu      $v1, $s0, 0x5
    /* 52B4 80107AB4 40100300 */  sll        $v0, $v1, 1
    /* 52B8 80107AB8 21104300 */  addu       $v0, $v0, $v1
    /* 52BC 80107ABC 80100200 */  sll        $v0, $v0, 2
    /* 52C0 80107AC0 21104300 */  addu       $v0, $v0, $v1
    /* 52C4 80107AC4 80100200 */  sll        $v0, $v0, 2
    /* 52C8 80107AC8 21104400 */  addu       $v0, $v0, $a0
    /* 52CC 80107ACC 01000324 */  addiu      $v1, $zero, 0x1
    /* 52D0 80107AD0 040043A0 */  sb         $v1, 0x4($v0)
    /* 52D4 80107AD4 1180023C */  lui        $v0, %hi(_showLoadFilesMenuPort)
    /* 52D8 80107AD8 F9AA4490 */  lbu        $a0, %lo(_showLoadFilesMenuPort)($v0)
    /* 52DC 80107ADC 1180023C */  lui        $v0, %hi(_selectCursorXy)
    /* 52E0 80107AE0 A0B040AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 52E4 80107AE4 7D14040C */  jal        _memcardMaskedHandler
    /* 52E8 80107AE8 70008424 */   addiu     $a0, $a0, 0x70
    /* 52EC 80107AEC 1180033C */  lui        $v1, %hi(_showLoadFilesMenuState)
    /* 52F0 80107AF0 02000224 */  addiu      $v0, $zero, 0x2
    /* 52F4 80107AF4 9F1F0408 */  j          .L80107E7C
    /* 52F8 80107AF8 F8AA62A0 */   sb        $v0, %lo(_showLoadFilesMenuState)($v1)
  .L80107AFC:
    /* 52FC 80107AFC 6216010C */  jal        vs_main_playSfxDefault
    /* 5300 80107B00 07000524 */   addiu     $a1, $zero, 0x7
  .L80107B04:
    /* 5304 80107B04 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 5308 80107B08 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 530C 80107B0C 00000000 */  nop
    /* 5310 80107B10 00104230 */  andi       $v0, $v0, 0x1000
    /* 5314 80107B14 0D004010 */  beqz       $v0, .L80107B4C
    /* 5318 80107B18 1180033C */   lui       $v1, %hi(_showLoadFilesMenuSelectedSlot)
    /* 531C 80107B1C FBAA6290 */  lbu        $v0, %lo(_showLoadFilesMenuSelectedSlot)($v1)
    /* 5320 80107B20 00000000 */  nop
    /* 5324 80107B24 08004014 */  bnez       $v0, .L80107B48
    /* 5328 80107B28 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 532C 80107B2C 1180033C */  lui        $v1, %hi(_showLoadFilesMenuPage)
    /* 5330 80107B30 FAAA6290 */  lbu        $v0, %lo(_showLoadFilesMenuPage)($v1)
    /* 5334 80107B34 00000000 */  nop
    /* 5338 80107B38 04004010 */  beqz       $v0, .L80107B4C
    /* 533C 80107B3C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 5340 80107B40 D31E0408 */  j          .L80107B4C
    /* 5344 80107B44 FAAA62A0 */   sb        $v0, %lo(_showLoadFilesMenuPage)($v1)
  .L80107B48:
    /* 5348 80107B48 FBAA62A0 */  sb         $v0, %lo(_showLoadFilesMenuSelectedSlot)($v1)
  .L80107B4C:
    /* 534C 80107B4C 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 5350 80107B50 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 5354 80107B54 00000000 */  nop
    /* 5358 80107B58 00404230 */  andi       $v0, $v0, 0x4000
    /* 535C 80107B5C 0E004010 */  beqz       $v0, .L80107B98
    /* 5360 80107B60 1180043C */   lui       $a0, %hi(_showLoadFilesMenuSelectedSlot)
    /* 5364 80107B64 FBAA8390 */  lbu        $v1, %lo(_showLoadFilesMenuSelectedSlot)($a0)
    /* 5368 80107B68 02000224 */  addiu      $v0, $zero, 0x2
    /* 536C 80107B6C 09006214 */  bne        $v1, $v0, .L80107B94
    /* 5370 80107B70 01006224 */   addiu     $v0, $v1, 0x1
    /* 5374 80107B74 1180043C */  lui        $a0, %hi(_showLoadFilesMenuPage)
    /* 5378 80107B78 FAAA8390 */  lbu        $v1, %lo(_showLoadFilesMenuPage)($a0)
    /* 537C 80107B7C 00000000 */  nop
    /* 5380 80107B80 0200622C */  sltiu      $v0, $v1, 0x2
    /* 5384 80107B84 04004010 */  beqz       $v0, .L80107B98
    /* 5388 80107B88 01006224 */   addiu     $v0, $v1, 0x1
    /* 538C 80107B8C E61E0408 */  j          .L80107B98
    /* 5390 80107B90 FAAA82A0 */   sb        $v0, %lo(_showLoadFilesMenuPage)($a0)
  .L80107B94:
    /* 5394 80107B94 FBAA82A0 */  sb         $v0, %lo(_showLoadFilesMenuSelectedSlot)($a0)
  .L80107B98:
    /* 5398 80107B98 1180113C */  lui        $s1, %hi(_showLoadFilesMenuSelectedSlot)
    /* 539C 80107B9C 1180023C */  lui        $v0, %hi(_showLoadFilesMenuPage)
    /* 53A0 80107BA0 FBAA2392 */  lbu        $v1, %lo(_showLoadFilesMenuSelectedSlot)($s1)
    /* 53A4 80107BA4 FAAA4290 */  lbu        $v0, %lo(_showLoadFilesMenuPage)($v0)
    /* 53A8 80107BA8 00000000 */  nop
    /* 53AC 80107BAC 21186200 */  addu       $v1, $v1, $v0
    /* 53B0 80107BB0 03000312 */  beq        $s0, $v1, .L80107BC0
    /* 53B4 80107BB4 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 53B8 80107BB8 6216010C */  jal        vs_main_playSfxDefault
    /* 53BC 80107BBC 04000524 */   addiu     $a1, $zero, 0x4
  .L80107BC0:
    /* 53C0 80107BC0 FBAA2392 */  lbu        $v1, %lo(_showLoadFilesMenuSelectedSlot)($s1)
    /* 53C4 80107BC4 1180043C */  lui        $a0, %hi(_selectCursorXy)
    /* 53C8 80107BC8 80100300 */  sll        $v0, $v1, 2
    /* 53CC 80107BCC 21104300 */  addu       $v0, $v0, $v1
    /* 53D0 80107BD0 C0100200 */  sll        $v0, $v0, 3
    /* 53D4 80107BD4 3E004224 */  addiu      $v0, $v0, 0x3E
    /* 53D8 80107BD8 00140200 */  sll        $v0, $v0, 16
    /* 53DC 80107BDC 18004234 */  ori        $v0, $v0, 0x18
    /* 53E0 80107BE0 A0B082AC */  sw         $v0, %lo(_selectCursorXy)($a0)
    /* 53E4 80107BE4 1180043C */  lui        $a0, %hi(_fileMenuElements)
    /* 53E8 80107BE8 50AE8424 */  addiu      $a0, $a0, %lo(_fileMenuElements)
    /* 53EC 80107BEC 05000326 */  addiu      $v1, $s0, 0x5
    /* 53F0 80107BF0 40100300 */  sll        $v0, $v1, 1
    /* 53F4 80107BF4 21104300 */  addu       $v0, $v0, $v1
    /* 53F8 80107BF8 80100200 */  sll        $v0, $v0, 2
    /* 53FC 80107BFC 21104300 */  addu       $v0, $v0, $v1
    /* 5400 80107C00 80100200 */  sll        $v0, $v0, 2
    /* 5404 80107C04 21104400 */  addu       $v0, $v0, $a0
    /* 5408 80107C08 01000324 */  addiu      $v1, $zero, 0x1
    /* 540C 80107C0C 9F1F0408 */  j          .L80107E7C
    /* 5410 80107C10 040043A0 */   sb        $v1, 0x4($v0)
    /* 5414 80107C14 7D14040C */  jal        _memcardMaskedHandler
    /* 5418 80107C18 21200000 */   addu      $a0, $zero, $zero
    /* 541C 80107C1C 21804000 */  addu       $s0, $v0, $zero
    /* 5420 80107C20 97000012 */  beqz       $s0, .L80107E80
    /* 5424 80107C24 21100000 */   addu      $v0, $zero, $zero
    /* 5428 80107C28 4E000006 */  bltz       $s0, .L80107D64
    /* 542C 80107C2C 1180023C */   lui       $v0, %hi(_showLoadFilesMenuSelectedSlot)
    /* 5430 80107C30 1180043C */  lui        $a0, %hi(_showLoadFilesMenuPage)
    /* 5434 80107C34 FBAA4390 */  lbu        $v1, %lo(_showLoadFilesMenuSelectedSlot)($v0)
    /* 5438 80107C38 FAAA8290 */  lbu        $v0, %lo(_showLoadFilesMenuPage)($a0)
    /* 543C 80107C3C 00000000 */  nop
    /* 5440 80107C40 21186200 */  addu       $v1, $v1, $v0
    /* 5444 80107C44 1180023C */  lui        $v0, %hi(_showLoadFilesMenuPort)
    /* 5448 80107C48 F9AA4490 */  lbu        $a0, %lo(_showLoadFilesMenuPort)($v0)
    /* 544C 80107C4C 01006324 */  addiu      $v1, $v1, 0x1
    /* 5450 80107C50 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 5454 80107C54 00240400 */  sll        $a0, $a0, 16
    /* 5458 80107C58 00018434 */  ori        $a0, $a0, 0x100
    /* 545C 80107C5C 740F040C */  jal        _loadSaveData
    /* 5460 80107C60 25206400 */   or        $a0, $v1, $a0
    /* 5464 80107C64 1180033C */  lui        $v1, %hi(_showLoadFilesMenuState)
    /* 5468 80107C68 03000224 */  addiu      $v0, $zero, 0x3
    /* 546C 80107C6C F8AA62A0 */  sb         $v0, %lo(_showLoadFilesMenuState)($v1)
    /* 5470 80107C70 1180023C */  lui        $v0, %hi(_textTable)
    /* 5474 80107C74 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 5478 80107C78 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 547C 80107C7C 26034224 */  addiu      $v0, $v0, 0x326
    /* 5480 80107C80 9F1F0408 */  j          .L80107E7C
    /* 5484 80107C84 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
    /* 5488 80107C88 740F040C */  jal        _loadSaveData
    /* 548C 80107C8C 21200000 */   addu      $a0, $zero, $zero
    /* 5490 80107C90 1180113C */  lui        $s1, %hi(_fileProgressCounter)
    /* 5494 80107C94 4CAE238E */  lw         $v1, %lo(_fileProgressCounter)($s1)
    /* 5498 80107C98 21804000 */  addu       $s0, $v0, $zero
    /* 549C 80107C9C 01006324 */  addiu      $v1, $v1, 0x1
    /* 54A0 80107CA0 76000012 */  beqz       $s0, .L80107E7C
    /* 54A4 80107CA4 4CAE23AE */   sw        $v1, %lo(_fileProgressCounter)($s1)
    /* 54A8 80107CA8 1180123C */  lui        $s2, %hi(_showLoadFilesMenuLeaveTimer)
    /* 54AC 80107CAC 4CAE20AE */  sw         $zero, %lo(_fileProgressCounter)($s1)
    /* 54B0 80107CB0 06000106 */  bgez       $s0, .L80107CCC
    /* 54B4 80107CB4 FCAA40A2 */   sb        $zero, %lo(_showLoadFilesMenuLeaveTimer)($s2)
    /* 54B8 80107CB8 1180023C */  lui        $v0, %hi(_textTable)
    /* 54BC 80107CBC F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 54C0 80107CC0 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 54C4 80107CC4 4F1F0408 */  j          .L80107D3C
    /* 54C8 80107CC8 3C024224 */   addiu     $v0, $v0, 0x23C
  .L80107CCC:
    /* 54CC 80107CCC 8C0D040C */  jal        _applyLoadedSaveFile
    /* 54D0 80107CD0 01000424 */   addiu     $a0, $zero, 0x1
    /* 54D4 80107CD4 21184000 */  addu       $v1, $v0, $zero
    /* 54D8 80107CD8 06006010 */  beqz       $v1, .L80107CF4
    /* 54DC 80107CDC 08000524 */   addiu     $a1, $zero, 0x8
    /* 54E0 80107CE0 01000224 */  addiu      $v0, $zero, 0x1
    /* 54E4 80107CE4 11006210 */  beq        $v1, $v0, .L80107D2C
    /* 54E8 80107CE8 1180033C */   lui       $v1, %hi(_showLoadFilesMenuBackupTime)
    /* 54EC 80107CEC 521F0408 */  j          .L80107D48
    /* 54F0 80107CF0 0680023C */   lui       $v0, %hi(vs_main_gametime)
  .L80107CF4:
    /* 54F4 80107CF4 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 54F8 80107CF8 F0FF0224 */  addiu      $v0, $zero, -0x10
    /* 54FC 80107CFC 6216010C */  jal        vs_main_playSfxDefault
    /* 5500 80107D00 4CAE22AE */   sw        $v0, %lo(_fileProgressCounter)($s1)
    /* 5504 80107D04 10000224 */  addiu      $v0, $zero, 0x10
    /* 5508 80107D08 1180033C */  lui        $v1, %hi(_showLoadFilesMenuFileLoaded)
    /* 550C 80107D0C FCAA42A2 */  sb         $v0, %lo(_showLoadFilesMenuLeaveTimer)($s2)
    /* 5510 80107D10 01000224 */  addiu      $v0, $zero, 0x1
    /* 5514 80107D14 F4AA62AC */  sw         $v0, %lo(_showLoadFilesMenuFileLoaded)($v1)
    /* 5518 80107D18 1180023C */  lui        $v0, %hi(_textTable)
    /* 551C 80107D1C F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 5520 80107D20 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 5524 80107D24 4F1F0408 */  j          .L80107D3C
    /* 5528 80107D28 64034224 */   addiu     $v0, $v0, 0x364
  .L80107D2C:
    /* 552C 80107D2C 1180023C */  lui        $v0, %hi(_textTable)
    /* 5530 80107D30 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 5534 80107D34 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 5538 80107D38 AA024224 */  addiu      $v0, $v0, 0x2AA
  .L80107D3C:
    /* 553C 80107D3C A4B062AC */  sw         $v0, %lo(_memoryCardMessage)($v1)
    /* 5540 80107D40 1180033C */  lui        $v1, %hi(_showLoadFilesMenuBackupTime)
    /* 5544 80107D44 0680023C */  lui        $v0, %hi(vs_main_gametime)
  .L80107D48:
    /* 5548 80107D48 74104B24 */  addiu      $t3, $v0, %lo(vs_main_gametime)
    /* 554C 80107D4C F0AA6A24 */  addiu      $t2, $v1, %lo(_showLoadFilesMenuBackupTime)
    /* 5550 80107D50 03006889 */  lwl        $t0, 0x3($t3)
    /* 5554 80107D54 00006899 */  lwr        $t0, 0x0($t3)
    /* 5558 80107D58 00000000 */  nop
    /* 555C 80107D5C 030048A9 */  swl        $t0, 0x3($t2)
    /* 5560 80107D60 000048B9 */  swr        $t0, 0x0($t2)
  .L80107D64:
    /* 5564 80107D64 1180033C */  lui        $v1, %hi(_showLoadFilesMenuState)
    /* 5568 80107D68 04000224 */  addiu      $v0, $zero, 0x4
    /* 556C 80107D6C 9F1F0408 */  j          .L80107E7C
    /* 5570 80107D70 F8AA62A0 */   sb        $v0, %lo(_showLoadFilesMenuState)($v1)
    /* 5574 80107D74 1180033C */  lui        $v1, %hi(_showLoadFilesMenuLeaveTimer)
    /* 5578 80107D78 FCAA6290 */  lbu        $v0, %lo(_showLoadFilesMenuLeaveTimer)($v1)
    /* 557C 80107D7C 00000000 */  nop
    /* 5580 80107D80 02004010 */  beqz       $v0, .L80107D8C
    /* 5584 80107D84 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 5588 80107D88 FCAA62A0 */  sb         $v0, %lo(_showLoadFilesMenuLeaveTimer)($v1)
  .L80107D8C:
    /* 558C 80107D8C 1180023C */  lui        $v0, %hi(_showLoadFilesMenuFileLoaded)
    /* 5590 80107D90 F4AA448C */  lw         $a0, %lo(_showLoadFilesMenuFileLoaded)($v0)
    /* 5594 80107D94 01000224 */  addiu      $v0, $zero, 0x1
    /* 5598 80107D98 07008214 */  bne        $a0, $v0, .L80107DB8
    /* 559C 80107D9C 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 55A0 80107DA0 1180033C */  lui        $v1, %hi(_showLoadFilesMenuCompleteTimer)
    /* 55A4 80107DA4 FDAA6290 */  lbu        $v0, %lo(_showLoadFilesMenuCompleteTimer)($v1)
    /* 55A8 80107DA8 00000000 */  nop
    /* 55AC 80107DAC 01004224 */  addiu      $v0, $v0, 0x1
    /* 55B0 80107DB0 FDAA62A0 */  sb         $v0, %lo(_showLoadFilesMenuCompleteTimer)($v1)
    /* 55B4 80107DB4 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L80107DB8:
    /* 55B8 80107DB8 D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 55BC 80107DBC 00000000 */  nop
    /* 55C0 80107DC0 05004014 */  bnez       $v0, .L80107DD8
    /* 55C4 80107DC4 1180023C */   lui       $v0, %hi(_showLoadFilesMenuCompleteTimer)
    /* 55C8 80107DC8 FDAA4390 */  lbu        $v1, %lo(_showLoadFilesMenuCompleteTimer)($v0)
    /* 55CC 80107DCC 96000224 */  addiu      $v0, $zero, 0x96
    /* 55D0 80107DD0 2B006214 */  bne        $v1, $v0, .L80107E80
    /* 55D4 80107DD4 21100000 */   addu      $v0, $zero, $zero
  .L80107DD8:
    /* 55D8 80107DD8 05008104 */  bgez       $a0, .L80107DF0
    /* 55DC 80107DDC 1180033C */   lui       $v1, %hi(_showLoadFilesMenuState)
    /* 55E0 80107DE0 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 55E4 80107DE4 6216010C */  jal        vs_main_playSfxDefault
    /* 55E8 80107DE8 06000524 */   addiu     $a1, $zero, 0x6
    /* 55EC 80107DEC 1180033C */  lui        $v1, %hi(_showLoadFilesMenuState)
  .L80107DF0:
    /* 55F0 80107DF0 05000224 */  addiu      $v0, $zero, 0x5
    /* 55F4 80107DF4 9F1F0408 */  j          .L80107E7C
    /* 55F8 80107DF8 F8AA62A0 */   sb        $v0, %lo(_showLoadFilesMenuState)($v1)
    /* 55FC 80107DFC 1180033C */  lui        $v1, %hi(_showLoadFilesMenuLeaveTimer)
    /* 5600 80107E00 FCAA6290 */  lbu        $v0, %lo(_showLoadFilesMenuLeaveTimer)($v1)
    /* 5604 80107E04 00000000 */  nop
    /* 5608 80107E08 03004010 */  beqz       $v0, .L80107E18
    /* 560C 80107E0C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 5610 80107E10 9F1F0408 */  j          .L80107E7C
    /* 5614 80107E14 FCAA62A0 */   sb        $v0, %lo(_showLoadFilesMenuLeaveTimer)($v1)
  .L80107E18:
    /* 5618 80107E18 1180023C */  lui        $v0, %hi(_showLoadFilesMenuFileLoaded)
    /* 561C 80107E1C F4AA438C */  lw         $v1, %lo(_showLoadFilesMenuFileLoaded)($v0)
    /* 5620 80107E20 01000224 */  addiu      $v0, $zero, 0x1
    /* 5624 80107E24 0C006214 */  bne        $v1, $v0, .L80107E58
    /* 5628 80107E28 05001024 */   addiu     $s0, $zero, 0x5
    /* 562C 80107E2C 0680033C */  lui        $v1, %hi(vs_main_gametime)
    /* 5630 80107E30 1180023C */  lui        $v0, %hi(_showLoadFilesMenuBackupTime)
    /* 5634 80107E34 F0AA4B24 */  addiu      $t3, $v0, %lo(_showLoadFilesMenuBackupTime)
    /* 5638 80107E38 74106A24 */  addiu      $t2, $v1, %lo(vs_main_gametime)
    /* 563C 80107E3C 03006889 */  lwl        $t0, 0x3($t3)
    /* 5640 80107E40 00006899 */  lwr        $t0, 0x0($t3)
    /* 5644 80107E44 00000000 */  nop
    /* 5648 80107E48 030048A9 */  swl        $t0, 0x3($t2)
    /* 564C 80107E4C 000048B9 */  swr        $t0, 0x0($t2)
    /* 5650 80107E50 9C1F0408 */  j          .L80107E70
    /* 5654 80107E54 1180023C */   lui       $v0, %hi(_showLoadFilesMenuFileLoaded)
  .L80107E58:
    /* 5658 80107E58 B013040C */  jal        _clearFileMenuElement
    /* 565C 80107E5C 21200002 */   addu      $a0, $s0, $zero
    /* 5660 80107E60 01001026 */  addiu      $s0, $s0, 0x1
    /* 5664 80107E64 0A00022A */  slti       $v0, $s0, 0xA
    /* 5668 80107E68 FBFF4014 */  bnez       $v0, .L80107E58
    /* 566C 80107E6C 1180023C */   lui       $v0, %hi(_showLoadFilesMenuFileLoaded)
  .L80107E70:
    /* 5670 80107E70 F4AA428C */  lw         $v0, %lo(_showLoadFilesMenuFileLoaded)($v0)
    /* 5674 80107E74 A01F0408 */  j          .L80107E80
    /* 5678 80107E78 00000000 */   nop
  .L80107E7C:
    /* 567C 80107E7C 21100000 */  addu       $v0, $zero, $zero
  .L80107E80:
    /* 5680 80107E80 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 5684 80107E84 1800B28F */  lw         $s2, 0x18($sp)
    /* 5688 80107E88 1400B18F */  lw         $s1, 0x14($sp)
    /* 568C 80107E8C 1000B08F */  lw         $s0, 0x10($sp)
    /* 5690 80107E90 0800E003 */  jr         $ra
    /* 5694 80107E94 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _showLoadFilesMenu
