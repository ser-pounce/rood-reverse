nonmatching func_80103418, 0x26C

glabel func_80103418
    /* C18 80103418 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* C1C 8010341C 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* C20 80103420 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* C24 80103424 98155324 */  addiu      $s3, $v0, %lo(vs_main_stateFlags)
    /* C28 80103428 1800B2AF */  sw         $s2, 0x18($sp)
    /* C2C 8010342C 0F80123C */  lui        $s2, %hi(vs_battle_sceneBuffer)
    /* C30 80103430 C01B438E */  lw         $v1, %lo(vs_battle_sceneBuffer)($s2)
    /* C34 80103434 01000224 */  addiu      $v0, $zero, 0x1
    /* C38 80103438 2000BFAF */  sw         $ra, 0x20($sp)
    /* C3C 8010343C 1400B1AF */  sw         $s1, 0x14($sp)
    /* C40 80103440 1000B0AF */  sw         $s0, 0x10($sp)
    /* C44 80103444 57006014 */  bnez       $v1, .L801035A4
    /* C48 80103448 350162A2 */   sb        $v0, 0x135($s3)
    /* C4C 8010344C 0680023C */  lui        $v0, %hi(vs_main_mapStatus)
    /* C50 80103450 D8FF4424 */  addiu      $a0, $v0, %lo(vs_main_mapStatus)
    /* C54 80103454 0400838C */  lw         $v1, 0x4($a0)
    /* C58 80103458 8000023C */  lui        $v0, (0x800000 >> 16)
    /* C5C 8010345C 24106200 */  and        $v0, $v1, $v0
    /* C60 80103460 03004010 */  beqz       $v0, .L80103470
    /* C64 80103464 4000023C */   lui       $v0, (0x400000 >> 16)
    /* C68 80103468 25106200 */  or         $v0, $v1, $v0
    /* C6C 8010346C 040082AC */  sw         $v0, 0x4($a0)
  .L80103470:
    /* C70 80103470 1180113C */  lui        $s1, %hi(D_80108DA4)
    /* C74 80103474 A48D3026 */  addiu      $s0, $s1, %lo(D_80108DA4)
    /* C78 80103478 21200002 */  addu       $a0, $s0, $zero
    /* C7C 8010347C 08000524 */  addiu      $a1, $zero, 0x8
    /* C80 80103480 1180023C */  lui        $v0, %hi(D_80108D8C)
    /* C84 80103484 8C8D40AC */  sw         $zero, %lo(D_80108D8C)($v0)
    /* C88 80103488 1180023C */  lui        $v0, %hi(D_80108D94)
    /* C8C 8010348C 4424010C */  jal        vs_main_bzero
    /* C90 80103490 948D40AC */   sw        $zero, %lo(D_80108D94)($v0)
    /* C94 80103494 1180043C */  lui        $a0, %hi(D_80108DAC)
    /* C98 80103498 AC8D8424 */  addiu      $a0, $a0, %lo(D_80108DAC)
    /* C9C 8010349C 4424010C */  jal        vs_main_bzero
    /* CA0 801034A0 08000524 */   addiu     $a1, $zero, 0x8
    /* CA4 801034A4 801F033C */  lui        $v1, (0x1F800058 >> 16)
    /* CA8 801034A8 58006394 */  lhu        $v1, (0x1F800058 & 0xFFFF)($v1)
    /* CAC 801034AC 38020224 */  addiu      $v0, $zero, 0x238
    /* CB0 801034B0 A48D22A6 */  sh         $v0, %lo(D_80108DA4)($s1)
    /* CB4 801034B4 1180023C */  lui        $v0, %hi(_currentRoomIndex)
    /* CB8 801034B8 648D40AC */  sw         $zero, %lo(_currentRoomIndex)($v0)
    /* CBC 801034BC 00080224 */  addiu      $v0, $zero, 0x800
    /* CC0 801034C0 23104300 */  subu       $v0, $v0, $v1
    /* CC4 801034C4 020002A6 */  sh         $v0, 0x2($s0)
    /* CC8 801034C8 0035020C */  jal        vs_battle_getCurrentSceneId
    /* CCC 801034CC 040002A6 */   sh        $v0, 0x4($s0)
    /* CD0 801034D0 1180113C */  lui        $s1, %hi(_currentScene)
    /* CD4 801034D4 808D22AE */  sw         $v0, %lo(_currentScene)($s1)
    /* CD8 801034D8 20004228 */  slti       $v0, $v0, 0x20
    /* CDC 801034DC 02004014 */  bnez       $v0, .L801034E8
    /* CE0 801034E0 1080103C */   lui       $s0, %hi(_sceneArmFiles)
    /* CE4 801034E4 808D20AE */  sw         $zero, %lo(_currentScene)($s1)
  .L801034E8:
    /* CE8 801034E8 808D238E */  lw         $v1, %lo(_currentScene)($s1)
    /* CEC 801034EC 002B1026 */  addiu      $s0, $s0, %lo(_sceneArmFiles)
    /* CF0 801034F0 C0100300 */  sll        $v0, $v1, 3
    /* CF4 801034F4 21105000 */  addu       $v0, $v0, $s0
    /* CF8 801034F8 0400448C */  lw         $a0, 0x4($v0)
    /* CFC 801034FC 21107300 */  addu       $v0, $v1, $s3
    /* D00 80103500 35014590 */  lbu        $a1, 0x135($v0)
    /* D04 80103504 1180023C */  lui        $v0, %hi(D_80108D90)
    /* D08 80103508 908D43AC */  sw         $v1, %lo(D_80108D90)($v0)
    /* D0C 8010350C 1180023C */  lui        $v0, %hi(D_80108D60)
    /* D10 80103510 1180033C */  lui        $v1, %hi(D_80108D68)
    /* D14 80103514 608D40AC */  sw         $zero, %lo(D_80108D60)($v0)
    /* D18 80103518 80000224 */  addiu      $v0, $zero, 0x80
    /* D1C 8010351C 688D62AC */  sw         $v0, %lo(D_80108D68)($v1)
    /* D20 80103520 1180023C */  lui        $v0, %hi(D_80108D6C)
    /* D24 80103524 1180033C */  lui        $v1, %hi(_geomOffsetX)
    /* D28 80103528 6C8D40AC */  sw         $zero, %lo(D_80108D6C)($v0)
    /* D2C 8010352C 80FE0224 */  addiu      $v0, $zero, -0x180
    /* D30 80103530 708D62AC */  sw         $v0, %lo(_geomOffsetX)($v1)
    /* D34 80103534 1180023C */  lui        $v0, %hi(_geomOffsetY)
    /* D38 80103538 1180033C */  lui        $v1, %hi(D_80108E44)
    /* D3C 8010353C 748D40AC */  sw         $zero, %lo(_geomOffsetY)($v0)
    /* D40 80103540 01000224 */  addiu      $v0, $zero, 0x1
    /* D44 80103544 448E62AC */  sw         $v0, %lo(D_80108E44)($v1)
    /* D48 80103548 1180033C */  lui        $v1, %hi(D_80108D7C)
    /* D4C 8010354C 00030224 */  addiu      $v0, $zero, 0x300
    /* D50 80103550 7C8D62AC */  sw         $v0, %lo(D_80108D7C)($v1)
    /* D54 80103554 1180033C */  lui        $v1, %hi(D_80108D9C)
    /* D58 80103558 05000224 */  addiu      $v0, $zero, 0x5
    /* D5C 8010355C 9C8D62A4 */  sh         $v0, %lo(D_80108D9C)($v1)
    /* D60 80103560 1180023C */  lui        $v0, %hi(D_80108D9E)
    /* D64 80103564 9E8D40A4 */  sh         $zero, %lo(D_80108D9E)($v0)
    /* D68 80103568 1180023C */  lui        $v0, %hi(D_80108D88)
    /* D6C 8010356C 8F0F010C */  jal        vs_main_allocHeapR
    /* D70 80103570 888D45AC */   sw        $a1, %lo(D_80108D88)($v0)
    /* D74 80103574 808D248E */  lw         $a0, %lo(_currentScene)($s1)
    /* D78 80103578 C01B42AE */  sw         $v0, %lo(vs_battle_sceneBuffer)($s2)
    /* D7C 8010357C C0200400 */  sll        $a0, $a0, 3
    /* D80 80103580 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* D84 80103584 21209000 */   addu      $a0, $a0, $s0
    /* D88 80103588 21204000 */  addu       $a0, $v0, $zero
    /* D8C 8010358C C01B458E */  lw         $a1, %lo(vs_battle_sceneBuffer)($s2)
    /* D90 80103590 1180023C */  lui        $v0, %hi(_sceneCdQueueSlot)
    /* D94 80103594 F112010C */  jal        vs_main_cdEnqueue
    /* D98 80103598 BC8D44AC */   sw        $a0, %lo(_sceneCdQueueSlot)($v0)
    /* D9C 8010359C 9A0D0408 */  j          .L80103668
    /* DA0 801035A0 21100000 */   addu      $v0, $zero, $zero
  .L801035A4:
    /* DA4 801035A4 1180023C */  lui        $v0, %hi(_sceneCdQueueSlot)
    /* DA8 801035A8 BC8D448C */  lw         $a0, %lo(_sceneCdQueueSlot)($v0)
    /* DAC 801035AC 00000000 */  nop
    /* DB0 801035B0 00008384 */  lh         $v1, 0x0($a0)
    /* DB4 801035B4 04000224 */  addiu      $v0, $zero, 0x4
    /* DB8 801035B8 2A006214 */  bne        $v1, $v0, .L80103664
    /* DBC 801035BC 00000000 */   nop
    /* DC0 801035C0 E012010C */  jal        vs_main_freeCdQueueSlot
    /* DC4 801035C4 00000000 */   nop
    /* DC8 801035C8 C01B448E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s2)
    /* DCC 801035CC D363020C */  jal        vs_battle_initSceneAndGetRoomNames
    /* DD0 801035D0 00000000 */   nop
    /* DD4 801035D4 C01B448E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s2)
    /* DD8 801035D8 1180033C */  lui        $v1, %hi(_roomNamesTable)
    /* DDC 801035DC 362D020C */  jal        vs_battle_setRoomsUnk0
    /* DE0 801035E0 988D62AC */   sw        $v0, %lo(_roomNamesTable)($v1)
    /* DE4 801035E4 C01B448E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s2)
    /* DE8 801035E8 3818040C */  jal        _scaleRoomVertices
    /* DEC 801035EC 04000524 */   addiu     $a1, $zero, 0x4
    /* DF0 801035F0 C01B448E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s2)
    /* DF4 801035F4 5C19040C */  jal        _getCurrentRoomIndex
    /* DF8 801035F8 00000000 */   nop
    /* DFC 801035FC 21284000 */  addu       $a1, $v0, $zero
    /* E00 80103600 C01B448E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s2)
    /* E04 80103604 1180023C */  lui        $v0, %hi(_currentRoomIndex)
    /* E08 80103608 C616040C */  jal        _snapMapToRoom
    /* E0C 8010360C 648D45AC */   sw        $a1, %lo(_currentRoomIndex)($v0)
    /* E10 80103610 0680023C */  lui        $v0, %hi(vs_main_projectionDistance)
    /* E14 80103614 48E2458C */  lw         $a1, %lo(vs_main_projectionDistance)($v0)
    /* E18 80103618 5506010C */  jal        SetFogNear
    /* E1C 8010361C 00030424 */   addiu     $a0, $zero, 0x300
    /* E20 80103620 21200000 */  addu       $a0, $zero, $zero
    /* E24 80103624 21288000 */  addu       $a1, $a0, $zero
    /* E28 80103628 5605010C */  jal        SetFarColor
    /* E2C 8010362C 21308000 */   addu      $a2, $a0, $zero
    /* E30 80103630 1180033C */  lui        $v1, %hi(_mapNames)
    /* E34 80103634 1180023C */  lui        $v0, %hi(_currentScene)
    /* E38 80103638 808D428C */  lw         $v0, %lo(_currentScene)($v0)
    /* E3C 8010363C FC836324 */  addiu      $v1, $v1, %lo(_mapNames)
    /* E40 80103640 40100200 */  sll        $v0, $v0, 1
    /* E44 80103644 21104300 */  addu       $v0, $v0, $v1
    /* E48 80103648 00004494 */  lhu        $a0, 0x0($v0)
    /* E4C 8010364C 01000524 */  addiu      $a1, $zero, 0x1
    /* E50 80103650 0420A400 */  sllv       $a0, $a0, $a1
    /* E54 80103654 CC0B040C */  jal        _setMenuItemMapName
    /* E58 80103658 21208300 */   addu      $a0, $a0, $v1
    /* E5C 8010365C 9A0D0408 */  j          .L80103668
    /* E60 80103660 01000224 */   addiu     $v0, $zero, 0x1
  .L80103664:
    /* E64 80103664 21100000 */  addu       $v0, $zero, $zero
  .L80103668:
    /* E68 80103668 2000BF8F */  lw         $ra, 0x20($sp)
    /* E6C 8010366C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* E70 80103670 1800B28F */  lw         $s2, 0x18($sp)
    /* E74 80103674 1400B18F */  lw         $s1, 0x14($sp)
    /* E78 80103678 1000B08F */  lw         $s0, 0x10($sp)
    /* E7C 8010367C 0800E003 */  jr         $ra
    /* E80 80103680 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80103418
