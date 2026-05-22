nonmatching func_800C930C, 0x4B0

glabel func_800C930C
    /* 60B0C 800C930C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 60B10 800C9310 1800B0AF */  sw         $s0, 0x18($sp)
    /* 60B14 800C9314 21808000 */  addu       $s0, $a0, $zero
    /* 60B18 800C9318 0F80023C */  lui        $v0, %hi(vs_battle_submenuStates)
    /* 60B1C 800C931C 0F80033C */  lui        $v1, %hi(vs_battle_menuItems)
    /* 60B20 800C9320 2000B2AF */  sw         $s2, 0x20($sp)
    /* 60B24 800C9324 704E5290 */  lbu        $s2, %lo(vs_battle_submenuStates)($v0)
    /* 60B28 800C9328 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 60B2C 800C932C 2400B3AF */  sw         $s3, 0x24($sp)
    /* 60B30 800C9330 C0B9738C */  lw         $s3, %lo(vs_battle_menuItems)($v1)
    /* 60B34 800C9334 20004424 */  addiu      $a0, $v0, %lo(vs_main_settings)
    /* 60B38 800C9338 3800BFAF */  sw         $ra, 0x38($sp)
    /* 60B3C 800C933C 3400B7AF */  sw         $s7, 0x34($sp)
    /* 60B40 800C9340 3000B6AF */  sw         $s6, 0x30($sp)
    /* 60B44 800C9344 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 60B48 800C9348 2800B4AF */  sw         $s4, 0x28($sp)
    /* 60B4C 800C934C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 60B50 800C9350 02009594 */  lhu        $s5, 0x2($a0)
    /* 60B54 800C9354 31000012 */  beqz       $s0, .L800C941C
    /* 60B58 800C9358 02000224 */   addiu     $v0, $zero, 0x2
    /* 60B5C 800C935C 07000216 */  bne        $s0, $v0, .L800C937C
    /* 60B60 800C9360 06105502 */   srlv      $v0, $s5, $s2
    /* 60B64 800C9364 01008290 */  lbu        $v0, 0x1($a0)
    /* 60B68 800C9368 00000000 */  nop
    /* 60B6C 800C936C 03004014 */  bnez       $v0, .L800C937C
    /* 60B70 800C9370 06105502 */   srlv      $v0, $s5, $s2
    /* 60B74 800C9374 21900000 */  addu       $s2, $zero, $zero
    /* 60B78 800C9378 06105502 */  srlv       $v0, $s5, $s2
  .L800C937C:
    /* 60B7C 800C937C 01004230 */  andi       $v0, $v0, 0x1
    /* 60B80 800C9380 10004014 */  bnez       $v0, .L800C93C4
    /* 60B84 800C9384 240B0524 */   addiu     $a1, $zero, 0xB24
    /* 60B88 800C9388 CCCC043C */  lui        $a0, (0xCCCCCCCD >> 16)
    /* 60B8C 800C938C CDCC8434 */  ori        $a0, $a0, (0xCCCCCCCD & 0xFFFF)
    /* 60B90 800C9390 01004326 */  addiu      $v1, $s2, 0x1
  .L800C9394:
    /* 60B94 800C9394 19006400 */  multu      $v1, $a0
    /* 60B98 800C9398 10400000 */  mfhi       $t0
    /* 60B9C 800C939C C2900800 */  srl        $s2, $t0, 3
    /* 60BA0 800C93A0 80101200 */  sll        $v0, $s2, 2
    /* 60BA4 800C93A4 21105200 */  addu       $v0, $v0, $s2
    /* 60BA8 800C93A8 40100200 */  sll        $v0, $v0, 1
    /* 60BAC 800C93AC 23906200 */  subu       $s2, $v1, $v0
    /* 60BB0 800C93B0 06105502 */  srlv       $v0, $s5, $s2
    /* 60BB4 800C93B4 01004230 */  andi       $v0, $v0, 0x1
    /* 60BB8 800C93B8 F6FF4010 */  beqz       $v0, .L800C9394
    /* 60BBC 800C93BC 01004326 */   addiu     $v1, $s2, 0x1
    /* 60BC0 800C93C0 240B0524 */  addiu      $a1, $zero, 0xB24
  .L800C93C4:
    /* 60BC4 800C93C4 0F80023C */  lui        $v0, %hi(vs_battle_menuItems)
    /* 60BC8 800C93C8 C0B9448C */  lw         $a0, %lo(vs_battle_menuItems)($v0)
    /* 60BCC 800C93CC 0F80023C */  lui        $v0, %hi(vs_battle_submenuStates)
    /* 60BD0 800C93D0 0733030C */  jal        vs_battle_rMemzero
    /* 60BD4 800C93D4 704E52A0 */   sb        $s2, %lo(vs_battle_submenuStates)($v0)
    /* 60BD8 800C93D8 09000424 */  addiu      $a0, $zero, 0x9
    /* 60BDC 800C93DC 21800000 */  addu       $s0, $zero, $zero
    /* 60BE0 800C93E0 21186002 */  addu       $v1, $s3, $zero
  .L800C93E4:
    /* 60BE4 800C93E4 06101502 */  srlv       $v0, $s5, $s0
    /* 60BE8 800C93E8 01004230 */  andi       $v0, $v0, 0x1
    /* 60BEC 800C93EC 03004010 */  beqz       $v0, .L800C93FC
    /* 60BF0 800C93F0 00000000 */   nop
    /* 60BF4 800C93F4 030064A0 */  sb         $a0, 0x3($v1)
    /* 60BF8 800C93F8 01008424 */  addiu      $a0, $a0, 0x1
  .L800C93FC:
    /* 60BFC 800C93FC 01001026 */  addiu      $s0, $s0, 0x1
    /* 60C00 800C9400 0A00022A */  slti       $v0, $s0, 0xA
    /* 60C04 800C9404 F7FF4014 */  bnez       $v0, .L800C93E4
    /* 60C08 800C9408 40006324 */   addiu     $v1, $v1, 0x40
    /* 60C0C 800C940C 0F80033C */  lui        $v1, %hi(D_800F4CC0)
    /* 60C10 800C9410 23100400 */  negu       $v0, $a0
    /* 60C14 800C9414 E3250308 */  j          .L800C978C
    /* 60C18 800C9418 C04C62AC */   sw        $v0, %lo(D_800F4CC0)($v1)
  .L800C941C:
    /* 60C1C 800C941C 0F80033C */  lui        $v1, %hi(D_800F4CC0)
    /* 60C20 800C9420 C04C628C */  lw         $v0, %lo(D_800F4CC0)($v1)
    /* 60C24 800C9424 00000000 */  nop
    /* 60C28 800C9428 3C004104 */  bgez       $v0, .L800C951C
    /* 60C2C 800C942C 01004224 */   addiu     $v0, $v0, 0x1
    /* 60C30 800C9430 C04C62AC */  sw         $v0, %lo(D_800F4CC0)($v1)
    /* 60C34 800C9434 0F80023C */  lui        $v0, %hi(vs_battle_rowAnimationSteps)
    /* 60C38 800C9438 C8BB5724 */  addiu      $s7, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 60C3C 800C943C 0F80023C */  lui        $v0, %hi(vs_battle_menuStrings)
    /* 60C40 800C9440 DCB95624 */  addiu      $s6, $v0, %lo(vs_battle_menuStrings)
    /* 60C44 800C9444 21A0C002 */  addu       $s4, $s6, $zero
    /* 60C48 800C9448 21886002 */  addu       $s1, $s3, $zero
    /* 60C4C 800C944C 12001224 */  addiu      $s2, $zero, 0x12
  .L800C9450:
    /* 60C50 800C9450 06101502 */  srlv       $v0, $s5, $s0
    /* 60C54 800C9454 01004230 */  andi       $v0, $v0, 0x1
    /* 60C58 800C9458 29004010 */  beqz       $v0, .L800C9500
    /* 60C5C 800C945C 00000000 */   nop
    /* 60C60 800C9460 03002392 */  lbu        $v1, 0x3($s1)
    /* 60C64 800C9464 00000000 */  nop
    /* 60C68 800C9468 03006010 */  beqz       $v1, .L800C9478
    /* 60C6C 800C946C FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 60C70 800C9470 21184000 */  addu       $v1, $v0, $zero
    /* 60C74 800C9474 030022A2 */  sb         $v0, 0x3($s1)
  .L800C9478:
    /* 60C78 800C9478 FF006230 */  andi       $v0, $v1, 0xFF
    /* 60C7C 800C947C 21105700 */  addu       $v0, $v0, $s7
    /* 60C80 800C9480 00004290 */  lbu        $v0, 0x0($v0)
    /* 60C84 800C9484 00000000 */  nop
    /* 60C88 800C9488 C2004524 */  addiu      $a1, $v0, 0xC2
    /* 60C8C 800C948C 0A000224 */  addiu      $v0, $zero, 0xA
    /* 60C90 800C9490 04000216 */  bne        $s0, $v0, .L800C94A4
    /* 60C94 800C9494 21304002 */   addu      $a2, $s2, $zero
    /* 60C98 800C9498 18000224 */  addiu      $v0, $zero, 0x18
    /* 60C9C 800C949C 2A250308 */  j          .L800C94A8
    /* 60CA0 800C94A0 1000A2AF */   sw        $v0, 0x10($sp)
  .L800C94A4:
    /* 60CA4 800C94A4 1000A0AF */  sw         $zero, 0x10($sp)
  .L800C94A8:
    /* 60CA8 800C94A8 21200002 */  addu       $a0, $s0, $zero
    /* 60CAC 800C94AC 00008296 */  lhu        $v0, 0x0($s4)
    /* 60CB0 800C94B0 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 60CB4 800C94B4 40100200 */  sll        $v0, $v0, 1
    /* 60CB8 800C94B8 21105600 */  addu       $v0, $v0, $s6
    /* 60CBC 800C94BC 9723030C */  jal        vs_battle_setMenuItem
    /* 60CC0 800C94C0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 60CC4 800C94C4 0F80023C */  lui        $v0, %hi(D_800F4EA0)
    /* 60CC8 800C94C8 A04E448C */  lw         $a0, %lo(D_800F4EA0)($v0)
    /* 60CCC 800C94CC 10005226 */  addiu      $s2, $s2, 0x10
    /* 60CD0 800C94D0 B7008230 */  andi       $v0, $a0, 0xB7
    /* 60CD4 800C94D4 2B100200 */  sltu       $v0, $zero, $v0
    /* 60CD8 800C94D8 070062A2 */  sb         $v0, 0x7($s3)
    /* 60CDC 800C94DC 5F018230 */  andi       $v0, $a0, 0x15F
    /* 60CE0 800C94E0 2B100200 */  sltu       $v0, $zero, $v0
    /* 60CE4 800C94E4 470062A2 */  sb         $v0, 0x47($s3)
    /* 60CE8 800C94E8 07008230 */  andi       $v0, $a0, 0x7
    /* 60CEC 800C94EC 2B100200 */  sltu       $v0, $zero, $v0
    /* 60CF0 800C94F0 0035020C */  jal        vs_battle_getCurrentSceneId
    /* 60CF4 800C94F4 C70062A2 */   sb        $v0, 0xC7($s3)
    /* 60CF8 800C94F8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 60CFC 800C94FC 470162A2 */  sb         $v0, 0x147($s3)
  .L800C9500:
    /* 60D00 800C9500 02009426 */  addiu      $s4, $s4, 0x2
    /* 60D04 800C9504 01001026 */  addiu      $s0, $s0, 0x1
    /* 60D08 800C9508 0A00022A */  slti       $v0, $s0, 0xA
    /* 60D0C 800C950C D0FF4014 */  bnez       $v0, .L800C9450
    /* 60D10 800C9510 40003126 */   addiu     $s1, $s1, 0x40
    /* 60D14 800C9514 E4250308 */  j          .L800C9790
    /* 60D18 800C9518 21100000 */   addu      $v0, $zero, $zero
  .L800C951C:
    /* 60D1C 800C951C 0680033C */  lui        $v1, %hi(vs_main_buttonsPressed)
    /* 60D20 800C9520 D0E1628C */  lw         $v0, %lo(vs_main_buttonsPressed)($v1)
    /* 60D24 800C9524 00000000 */  nop
    /* 60D28 800C9528 20004230 */  andi       $v0, $v0, 0x20
    /* 60D2C 800C952C 0C004010 */  beqz       $v0, .L800C9560
    /* 60D30 800C9530 80111200 */   sll       $v0, $s2, 6
    /* 60D34 800C9534 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 60D38 800C9538 00000000 */   nop
    /* 60D3C 800C953C 01004226 */  addiu      $v0, $s2, 0x1
    /* 60D40 800C9540 80191200 */  sll        $v1, $s2, 6
    /* 60D44 800C9544 21187300 */  addu       $v1, $v1, $s3
    /* 60D48 800C9548 01000424 */  addiu      $a0, $zero, 0x1
    /* 60D4C 800C954C 060064A0 */  sb         $a0, 0x6($v1)
    /* 60D50 800C9550 020064A0 */  sb         $a0, 0x2($v1)
    /* 60D54 800C9554 0F80033C */  lui        $v1, %hi(D_800F514C)
    /* 60D58 800C9558 E4250308 */  j          .L800C9790
    /* 60D5C 800C955C 4C5160A4 */   sh        $zero, %lo(D_800F514C)($v1)
  .L800C9560:
    /* 60D60 800C9560 21105300 */  addu       $v0, $v0, $s3
    /* 60D64 800C9564 060040A0 */  sb         $zero, 0x6($v0)
    /* 60D68 800C9568 D0E1628C */  lw         $v0, %lo(vs_main_buttonsPressed)($v1)
    /* 60D6C 800C956C 00000000 */  nop
    /* 60D70 800C9570 50004230 */  andi       $v0, $v0, 0x50
    /* 60D74 800C9574 07004010 */  beqz       $v0, .L800C9594
    /* 60D78 800C9578 00000000 */   nop
    /* 60D7C 800C957C BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 60D80 800C9580 00000000 */   nop
    /* 60D84 800C9584 0F80023C */  lui        $v0, %hi(D_800F514C)
    /* 60D88 800C9588 4C5140A4 */  sh         $zero, %lo(D_800F514C)($v0)
    /* 60D8C 800C958C E4250308 */  j          .L800C9790
    /* 60D90 800C9590 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L800C9594:
    /* 60D94 800C9594 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 60D98 800C9598 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 60D9C 800C959C 00000000 */  nop
    /* 60DA0 800C95A0 00104230 */  andi       $v0, $v0, 0x1000
    /* 60DA4 800C95A4 10004010 */  beqz       $v0, .L800C95E8
    /* 60DA8 800C95A8 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 60DAC 800C95AC CCCC043C */  lui        $a0, (0xCCCCCCCD >> 16)
    /* 60DB0 800C95B0 CDCC8434 */  ori        $a0, $a0, (0xCCCCCCCD & 0xFFFF)
    /* 60DB4 800C95B4 09004326 */  addiu      $v1, $s2, 0x9
  .L800C95B8:
    /* 60DB8 800C95B8 19006400 */  multu      $v1, $a0
    /* 60DBC 800C95BC 10400000 */  mfhi       $t0
    /* 60DC0 800C95C0 C2900800 */  srl        $s2, $t0, 3
    /* 60DC4 800C95C4 80101200 */  sll        $v0, $s2, 2
    /* 60DC8 800C95C8 21105200 */  addu       $v0, $v0, $s2
    /* 60DCC 800C95CC 40100200 */  sll        $v0, $v0, 1
    /* 60DD0 800C95D0 23906200 */  subu       $s2, $v1, $v0
    /* 60DD4 800C95D4 06105502 */  srlv       $v0, $s5, $s2
    /* 60DD8 800C95D8 01004230 */  andi       $v0, $v0, 0x1
    /* 60DDC 800C95DC F6FF4010 */  beqz       $v0, .L800C95B8
    /* 60DE0 800C95E0 09004326 */   addiu     $v1, $s2, 0x9
    /* 60DE4 800C95E4 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L800C95E8:
    /* 60DE8 800C95E8 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 60DEC 800C95EC 00000000 */  nop
    /* 60DF0 800C95F0 00404230 */  andi       $v0, $v0, 0x4000
    /* 60DF4 800C95F4 0A004010 */  beqz       $v0, .L800C9620
    /* 60DF8 800C95F8 01004326 */   addiu     $v1, $s2, 0x1
    /* 60DFC 800C95FC CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 60E00 800C9600 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 60E04 800C9604 19006200 */  multu      $v1, $v0
    /* 60E08 800C9608 10400000 */  mfhi       $t0
    /* 60E0C 800C960C C2900800 */  srl        $s2, $t0, 3
    /* 60E10 800C9610 80101200 */  sll        $v0, $s2, 2
    /* 60E14 800C9614 21105200 */  addu       $v0, $v0, $s2
    /* 60E18 800C9618 40100200 */  sll        $v0, $v0, 1
    /* 60E1C 800C961C 23906200 */  subu       $s2, $v1, $v0
  .L800C9620:
    /* 60E20 800C9620 06105502 */  srlv       $v0, $s5, $s2
    /* 60E24 800C9624 01004230 */  andi       $v0, $v0, 0x1
    /* 60E28 800C9628 10004014 */  bnez       $v0, .L800C966C
    /* 60E2C 800C962C 0F80103C */   lui       $s0, %hi(vs_battle_submenuStates)
    /* 60E30 800C9630 CCCC043C */  lui        $a0, (0xCCCCCCCD >> 16)
    /* 60E34 800C9634 CDCC8434 */  ori        $a0, $a0, (0xCCCCCCCD & 0xFFFF)
    /* 60E38 800C9638 01004326 */  addiu      $v1, $s2, 0x1
  .L800C963C:
    /* 60E3C 800C963C 19006400 */  multu      $v1, $a0
    /* 60E40 800C9640 10400000 */  mfhi       $t0
    /* 60E44 800C9644 C2900800 */  srl        $s2, $t0, 3
    /* 60E48 800C9648 80101200 */  sll        $v0, $s2, 2
    /* 60E4C 800C964C 21105200 */  addu       $v0, $v0, $s2
    /* 60E50 800C9650 40100200 */  sll        $v0, $v0, 1
    /* 60E54 800C9654 23906200 */  subu       $s2, $v1, $v0
    /* 60E58 800C9658 06105502 */  srlv       $v0, $s5, $s2
    /* 60E5C 800C965C 01004230 */  andi       $v0, $v0, 0x1
    /* 60E60 800C9660 F6FF4010 */  beqz       $v0, .L800C963C
    /* 60E64 800C9664 01004326 */   addiu     $v1, $s2, 0x1
    /* 60E68 800C9668 0F80103C */  lui        $s0, %hi(vs_battle_submenuStates)
  .L800C966C:
    /* 60E6C 800C966C 704E0292 */  lbu        $v0, %lo(vs_battle_submenuStates)($s0)
    /* 60E70 800C9670 00000000 */  nop
    /* 60E74 800C9674 04004212 */  beq        $s2, $v0, .L800C9688
    /* 60E78 800C9678 00000000 */   nop
    /* 60E7C 800C967C BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 60E80 800C9680 00000000 */   nop
    /* 60E84 800C9684 704E12A2 */  sb         $s2, %lo(vs_battle_submenuStates)($s0)
  .L800C9688:
    /* 60E88 800C9688 80811200 */  sll        $s0, $s2, 6
    /* 60E8C 800C968C 21801302 */  addu       $s0, $s0, $s3
    /* 60E90 800C9690 01000224 */  addiu      $v0, $zero, 0x1
    /* 60E94 800C9694 16000596 */  lhu        $a1, 0x16($s0)
    /* 60E98 800C9698 0F80113C */  lui        $s1, %hi(D_800F4CC0)
    /* 60E9C 800C969C 060002A2 */  sb         $v0, 0x6($s0)
    /* 60EA0 800C96A0 C04C248E */  lw         $a0, %lo(D_800F4CC0)($s1)
    /* 60EA4 800C96A4 002C0500 */  sll        $a1, $a1, 16
    /* 60EA8 800C96A8 032D0500 */  sra        $a1, $a1, 20
    /* 60EAC 800C96AC 5033030C */  jal        vs_battle_drawCursor
    /* 60EB0 800C96B0 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 60EB4 800C96B4 C04C22AE */  sw         $v0, %lo(D_800F4CC0)($s1)
    /* 60EB8 800C96B8 07000292 */  lbu        $v0, 0x7($s0)
    /* 60EBC 800C96BC 00000000 */  nop
    /* 60EC0 800C96C0 30004010 */  beqz       $v0, .L800C9784
    /* 60EC4 800C96C4 0680023C */   lui       $v0, %hi(vs_main_buttonsState)
    /* 60EC8 800C96C8 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 60ECC 800C96CC 00000000 */  nop
    /* 60ED0 800C96D0 00504230 */  andi       $v0, $v0, 0x5000
    /* 60ED4 800C96D4 2E004014 */  bnez       $v0, .L800C9790
    /* 60ED8 800C96D8 21100000 */   addu      $v0, $zero, $zero
    /* 60EDC 800C96DC 8123030C */  jal        func_800C8E04
    /* 60EE0 800C96E0 01000424 */   addiu     $a0, $zero, 0x1
    /* 60EE4 800C96E4 0F80023C */  lui        $v0, %hi(D_800F514C)
    /* 60EE8 800C96E8 0B000324 */  addiu      $v1, $zero, 0xB
    /* 60EEC 800C96EC 4C5143A4 */  sh         $v1, %lo(D_800F514C)($v0)
    /* 60EF0 800C96F0 07000424 */  addiu      $a0, $zero, 0x7
    /* 60EF4 800C96F4 0F80053C */  lui        $a1, %hi(D_800EBA78)
    /* 60EF8 800C96F8 FC1A030C */  jal        vs_battle_setTextBox
    /* 60EFC 800C96FC 78BAA524 */   addiu     $a1, $a1, %lo(D_800EBA78)
    /* 60F00 800C9700 02004016 */  bnez       $s2, .L800C970C
    /* 60F04 800C9704 21200000 */   addu      $a0, $zero, $zero
    /* 60F08 800C9708 B7000424 */  addiu      $a0, $zero, 0xB7
  .L800C970C:
    /* 60F0C 800C970C 01000224 */  addiu      $v0, $zero, 0x1
    /* 60F10 800C9710 02004216 */  bne        $s2, $v0, .L800C971C
    /* 60F14 800C9714 03000224 */   addiu     $v0, $zero, 0x3
    /* 60F18 800C9718 5F010424 */  addiu      $a0, $zero, 0x15F
  .L800C971C:
    /* 60F1C 800C971C 02004216 */  bne        $s2, $v0, .L800C9728
    /* 60F20 800C9720 21800000 */   addu      $s0, $zero, $zero
    /* 60F24 800C9724 07000424 */  addiu      $a0, $zero, 0x7
  .L800C9728:
    /* 60F28 800C9728 0F80023C */  lui        $v0, %hi(D_800F4EA0)
    /* 60F2C 800C972C A04E428C */  lw         $v0, %lo(D_800F4EA0)($v0)
    /* 60F30 800C9730 01000524 */  addiu      $a1, $zero, 0x1
    /* 60F34 800C9734 24184400 */  and        $v1, $v0, $a0
    /* 60F38 800C9738 04100502 */  sllv       $v0, $a1, $s0
  .L800C973C:
    /* 60F3C 800C973C 24106200 */  and        $v0, $v1, $v0
    /* 60F40 800C9740 05004014 */  bnez       $v0, .L800C9758
    /* 60F44 800C9744 00000000 */   nop
    /* 60F48 800C9748 01001026 */  addiu      $s0, $s0, 0x1
    /* 60F4C 800C974C 0900022A */  slti       $v0, $s0, 0x9
    /* 60F50 800C9750 FAFF4014 */  bnez       $v0, .L800C973C
    /* 60F54 800C9754 04100502 */   sllv      $v0, $a1, $s0
  .L800C9758:
    /* 60F58 800C9758 0F80033C */  lui        $v1, %hi(vs_battle_menuStrings)
    /* 60F5C 800C975C DCB96324 */  addiu      $v1, $v1, %lo(vs_battle_menuStrings)
    /* 60F60 800C9760 0C000226 */  addiu      $v0, $s0, 0xC
    /* 60F64 800C9764 40100200 */  sll        $v0, $v0, 1
    /* 60F68 800C9768 21104300 */  addu       $v0, $v0, $v1
    /* 60F6C 800C976C 00004294 */  lhu        $v0, 0x0($v0)
    /* 60F70 800C9770 0F80043C */  lui        $a0, %hi(vs_battle_stringContext + 0x28)
    /* 60F74 800C9774 40100200 */  sll        $v0, $v0, 1
    /* 60F78 800C9778 21104300 */  addu       $v0, $v0, $v1
    /* 60F7C 800C977C E3250308 */  j          .L800C978C
    /* 60F80 800C9780 905182AC */   sw        $v0, %lo(vs_battle_stringContext + 0x28)($a0)
  .L800C9784:
    /* 60F84 800C9784 0F80023C */  lui        $v0, %hi(D_800F514C)
    /* 60F88 800C9788 4C5140A4 */  sh         $zero, %lo(D_800F514C)($v0)
  .L800C978C:
    /* 60F8C 800C978C 21100000 */  addu       $v0, $zero, $zero
  .L800C9790:
    /* 60F90 800C9790 3800BF8F */  lw         $ra, 0x38($sp)
    /* 60F94 800C9794 3400B78F */  lw         $s7, 0x34($sp)
    /* 60F98 800C9798 3000B68F */  lw         $s6, 0x30($sp)
    /* 60F9C 800C979C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 60FA0 800C97A0 2800B48F */  lw         $s4, 0x28($sp)
    /* 60FA4 800C97A4 2400B38F */  lw         $s3, 0x24($sp)
    /* 60FA8 800C97A8 2000B28F */  lw         $s2, 0x20($sp)
    /* 60FAC 800C97AC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 60FB0 800C97B0 1800B08F */  lw         $s0, 0x18($sp)
    /* 60FB4 800C97B4 0800E003 */  jr         $ra
    /* 60FB8 800C97B8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800C930C
