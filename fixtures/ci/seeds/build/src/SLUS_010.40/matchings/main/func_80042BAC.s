nonmatching func_80042BAC, 0x8C

glabel func_80042BAC
    /* 333AC 80042BAC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 333B0 80042BB0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 333B4 80042BB4 0680103C */  lui        $s0, %hi(sp)
    /* 333B8 80042BB8 D0DF1026 */  addiu      $s0, $s0, %lo(sp)
    /* 333BC 80042BBC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 333C0 80042BC0 A942000C */  jal        vs_overlay_getSp
    /* 333C4 80042BC4 21200002 */   addu      $a0, $s0, $zero
    /* 333C8 80042BC8 990A010C */  jal        func_80042A64
    /* 333CC 80042BCC 00000000 */   nop
    /* 333D0 80042BD0 CD07010C */  jal        func_80041F34
    /* 333D4 80042BD4 00000000 */   nop
    /* 333D8 80042BD8 CDC4010C */  jal        vs_title_exec
    /* 333DC 80042BDC 00000000 */   nop
    /* 333E0 80042BE0 0580033C */  lui        $v1, %hi(vs_main_startState)
    /* 333E4 80042BE4 700462AC */  sw         $v0, %lo(vs_main_startState)($v1)
    /* 333E8 80042BE8 0680023C */  lui        $v0, %hi(vs_main_saveGameClearData)
    /* 333EC 80042BEC 2F08010C */  jal        _displayLoadingScreen
    /* 333F0 80042BF0 14E240AC */   sw        $zero, %lo(vs_main_saveGameClearData)($v0)
    /* 333F4 80042BF4 9307010C */  jal        func_80041E4C
    /* 333F8 80042BF8 00000000 */   nop
    /* 333FC 80042BFC A942000C */  jal        vs_overlay_getSp
    /* 33400 80042C00 21200002 */   addu      $a0, $s0, $zero
    /* 33404 80042C04 0680033C */  lui        $v1, %hi(_inGame)
    /* 33408 80042C08 01000224 */  addiu      $v0, $zero, 0x1
    /* 3340C 80042C0C 29E6010C */  jal        vs_battle_exec
    /* 33410 80042C10 40E262AC */   sw        $v0, %lo(_inGame)($v1)
    /* 33414 80042C14 6EA1000C */  jal        SetDispMask
    /* 33418 80042C18 21200000 */   addu      $a0, $zero, $zero
    /* 3341C 80042C1C 7D15010C */  jal        vs_main_stopMusic
    /* 33420 80042C20 00000000 */   nop
    /* 33424 80042C24 1400BF8F */  lw         $ra, 0x14($sp)
    /* 33428 80042C28 1000B08F */  lw         $s0, 0x10($sp)
    /* 3342C 80042C2C 21100000 */  addu       $v0, $zero, $zero
    /* 33430 80042C30 0800E003 */  jr         $ra
    /* 33434 80042C34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80042BAC
