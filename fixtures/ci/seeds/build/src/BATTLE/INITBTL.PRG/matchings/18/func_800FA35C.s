nonmatching func_800FA35C, 0x35C

glabel func_800FA35C
    /* B5C 800FA35C A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* B60 800FA360 1080023C */  lui        $v0, %hi(D_800F9800)
    /* B64 800FA364 5800BFAF */  sw         $ra, 0x58($sp)
    /* B68 800FA368 5400B1AF */  sw         $s1, 0x54($sp)
    /* B6C 800FA36C 5000B0AF */  sw         $s0, 0x50($sp)
    /* B70 800FA370 00984B24 */  addiu      $t3, $v0, %lo(D_800F9800)
    /* B74 800FA374 03006889 */  lwl        $t0, 0x3($t3)
    /* B78 800FA378 00006899 */  lwr        $t0, 0x0($t3)
    /* B7C 800FA37C 07006989 */  lwl        $t1, 0x7($t3)
    /* B80 800FA380 04006999 */  lwr        $t1, 0x4($t3)
    /* B84 800FA384 2300A8AB */  swl        $t0, 0x23($sp)
    /* B88 800FA388 2000A8BB */  swr        $t0, 0x20($sp)
    /* B8C 800FA38C 2700A9AB */  swl        $t1, 0x27($sp)
    /* B90 800FA390 2400A9BB */  swr        $t1, 0x24($sp)
    /* B94 800FA394 1080023C */  lui        $v0, %hi(D_800F9808)
    /* B98 800FA398 08984B24 */  addiu      $t3, $v0, %lo(D_800F9808)
    /* B9C 800FA39C 0000688D */  lw         $t0, 0x0($t3)
    /* BA0 800FA3A0 0400698D */  lw         $t1, 0x4($t3)
    /* BA4 800FA3A4 08006A8D */  lw         $t2, 0x8($t3)
    /* BA8 800FA3A8 2800A8AF */  sw         $t0, 0x28($sp)
    /* BAC 800FA3AC 2C00A9AF */  sw         $t1, 0x2C($sp)
    /* BB0 800FA3B0 3000AAAF */  sw         $t2, 0x30($sp)
    /* BB4 800FA3B4 0C00688D */  lw         $t0, 0xC($t3)
    /* BB8 800FA3B8 00000000 */  nop
    /* BBC 800FA3BC 3400A8AF */  sw         $t0, 0x34($sp)
    /* BC0 800FA3C0 94A1000C */  jal        DrawSync
    /* BC4 800FA3C4 21200000 */   addu      $a0, $zero, $zero
    /* BC8 800FA3C8 94A1000C */  jal        DrawSync
    /* BCC 800FA3CC 21200000 */   addu      $a0, $zero, $zero
    /* BD0 800FA3D0 8E1A010C */  jal        vs_main_resetSound
    /* BD4 800FA3D4 0580113C */   lui       $s1, %hi(D_80055C80)
    /* BD8 800FA3D8 1080043C */  lui        $a0, (0x8010C000 >> 16)
    /* BDC 800FA3DC 00C08434 */  ori        $a0, $a0, (0x8010C000 & 0xFFFF)
    /* BE0 800FA3E0 0F00053C */  lui        $a1, (0xF2000 >> 16)
    /* BE4 800FA3E4 DD0F010C */  jal        vs_main_initHeap
    /* BE8 800FA3E8 0020A534 */   ori       $a1, $a1, (0xF2000 & 0xFFFF)
    /* BEC 800FA3EC 88200424 */  addiu      $a0, $zero, 0x2088
    /* BF0 800FA3F0 0680033C */  lui        $v1, %hi(D_8005E0C0)
    /* BF4 800FA3F4 C0E06224 */  addiu      $v0, $v1, %lo(D_8005E0C0)
    /* BF8 800FA3F8 040040AC */  sw         $zero, 0x4($v0)
    /* BFC 800FA3FC B10F010C */  jal        vs_main_allocHeap
    /* C00 800FA400 C0E060AC */   sw        $zero, %lo(D_8005E0C0)($v1)
    /* C04 800FA404 88200424 */  addiu      $a0, $zero, 0x2088
    /* C08 800FA408 805C22AE */  sw         $v0, %lo(D_80055C80)($s1)
    /* C0C 800FA40C B10F010C */  jal        vs_main_allocHeap
    /* C10 800FA410 805C3126 */   addiu     $s1, $s1, %lo(D_80055C80)
    /* C14 800FA414 0F80103C */  lui        $s0, %hi(D_800F1970)
    /* C18 800FA418 70191026 */  addiu      $s0, $s0, %lo(D_800F1970)
    /* C1C 800FA41C 21200002 */  addu       $a0, $s0, $zero
    /* C20 800FA420 21280000 */  addu       $a1, $zero, $zero
    /* C24 800FA424 C5AD000C */  jal        SetDrawStp
    /* C28 800FA428 040022AE */   sw        $v0, 0x4($s1)
    /* C2C 800FA42C 0C000426 */  addiu      $a0, $s0, 0xC
    /* C30 800FA430 C5AD000C */  jal        SetDrawStp
    /* C34 800FA434 21280000 */   addu      $a1, $zero, $zero
    /* C38 800FA438 0F80103C */  lui        $s0, %hi(D_800F1988)
    /* C3C 800FA43C 88191026 */  addiu      $s0, $s0, %lo(D_800F1988)
    /* C40 800FA440 21200002 */  addu       $a0, $s0, $zero
    /* C44 800FA444 C5AD000C */  jal        SetDrawStp
    /* C48 800FA448 01000524 */   addiu     $a1, $zero, 0x1
    /* C4C 800FA44C 0C000426 */  addiu      $a0, $s0, 0xC
    /* C50 800FA450 C5AD000C */  jal        SetDrawStp
    /* C54 800FA454 01000524 */   addiu     $a1, $zero, 0x1
    /* C58 800FA458 FE23010C */  jal        vs_main_clutInit
    /* C5C 800FA45C 01001024 */   addiu     $s0, $zero, 0x1
    /* C60 800FA460 3BE8030C */  jal        _initTransitionState
    /* C64 800FA464 00000000 */   nop
    /* C68 800FA468 FEF4010C */  jal        func_8007D3F8
    /* C6C 800FA46C 00000000 */   nop
    /* C70 800FA470 ABEA030C */  jal        _initScriptFunctionTable
    /* C74 800FA474 00000000 */   nop
    /* C78 800FA478 9339030C */  jal        func_800CE64C
    /* C7C 800FA47C 00000000 */   nop
    /* C80 800FA480 AEE9030C */  jal        func_800FA6B8
    /* C84 800FA484 00000000 */   nop
    /* C88 800FA488 ECE9030C */  jal        func_800FA7B0
    /* C8C 800FA48C 00000000 */   nop
    /* C90 800FA490 D2F7010C */  jal        func_8007DF48
    /* C94 800FA494 00000000 */   nop
    /* C98 800FA498 27E6030C */  jal        _loadSystemDat
    /* C9C 800FA49C 00000000 */   nop
    /* CA0 800FA4A0 AB9B030C */  jal        func_800E6EAC
    /* CA4 800FA4A4 00000000 */   nop
    /* CA8 800FA4A8 9A0D010C */  jal        vs_main_resetPadAct
    /* CAC 800FA4AC 00000000 */   nop
    /* CB0 800FA4B0 06E6030C */  jal        func_800F9818
    /* CB4 800FA4B4 00000000 */   nop
    /* CB8 800FA4B8 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* CBC 800FA4BC 80184424 */  addiu      $a0, $v0, %lo(_zoneContext)
    /* CC0 800FA4C0 680080AC */  sw         $zero, 0x68($a0)
    /* CC4 800FA4C4 380080AC */  sw         $zero, 0x38($a0)
    /* CC8 800FA4C8 340080AC */  sw         $zero, 0x34($a0)
    /* CCC 800FA4CC 801840AC */  sw         $zero, %lo(_zoneContext)($v0)
    /* CD0 800FA4D0 0F80023C */  lui        $v0, %hi(D_800F1AB0)
    /* CD4 800FA4D4 0680053C */  lui        $a1, %hi(D_80061068)
    /* CD8 800FA4D8 180080AC */  sw         $zero, 0x18($a0)
    /* CDC 800FA4DC 580080AC */  sw         $zero, 0x58($a0)
    /* CE0 800FA4E0 200080AC */  sw         $zero, 0x20($a0)
    /* CE4 800FA4E4 5C0080AC */  sw         $zero, 0x5C($a0)
    /* CE8 800FA4E8 240080AC */  sw         $zero, 0x24($a0)
    /* CEC 800FA4EC 2C0080AC */  sw         $zero, 0x2C($a0)
    /* CF0 800FA4F0 280080AC */  sw         $zero, 0x28($a0)
    /* CF4 800FA4F4 300090AC */  sw         $s0, 0x30($a0)
    /* CF8 800FA4F8 140080AC */  sw         $zero, 0x14($a0)
    /* CFC 800FA4FC 6810AB24 */  addiu      $t3, $a1, %lo(D_80061068)
    /* D00 800FA500 B01A4A24 */  addiu      $t2, $v0, %lo(D_800F1AB0)
    /* D04 800FA504 03006889 */  lwl        $t0, 0x3($t3)
    /* D08 800FA508 00006899 */  lwr        $t0, 0x0($t3)
    /* D0C 800FA50C 07006989 */  lwl        $t1, 0x7($t3)
    /* D10 800FA510 04006999 */  lwr        $t1, 0x4($t3)
    /* D14 800FA514 030048A9 */  swl        $t0, 0x3($t2)
    /* D18 800FA518 000048B9 */  swr        $t0, 0x0($t2)
    /* D1C 800FA51C 070049A9 */  swl        $t1, 0x7($t2)
    /* D20 800FA520 040049B9 */  swr        $t1, 0x4($t2)
    /* D24 800FA524 0B006889 */  lwl        $t0, 0xB($t3)
    /* D28 800FA528 08006899 */  lwr        $t0, 0x8($t3)
    /* D2C 800FA52C 00000000 */  nop
    /* D30 800FA530 0B0048A9 */  swl        $t0, 0xB($t2)
    /* D34 800FA534 080048B9 */  swr        $t0, 0x8($t2)
    /* D38 800FA538 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionEffect)
    /* D3C 800FA53C 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionStep)
    /* D40 800FA540 981A40AC */  sw         $zero, %lo(vs_battle_screenTransitionEffect)($v0)
    /* D44 800FA544 04000224 */  addiu      $v0, $zero, 0x4
    /* D48 800FA548 481A62AC */  sw         $v0, %lo(vs_battle_screenTransitionStep)($v1)
    /* D4C 800FA54C 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionSpeed)
    /* D50 800FA550 08000224 */  addiu      $v0, $zero, 0x8
    /* D54 800FA554 A81A62AC */  sw         $v0, %lo(vs_battle_screenTransitionSpeed)($v1)
    /* D58 800FA558 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionWipeAngle)
    /* D5C 800FA55C 000C0224 */  addiu      $v0, $zero, 0xC00
    /* D60 800FA560 A41A62AC */  sw         $v0, %lo(vs_battle_screenTransitionWipeAngle)($v1)
    /* D64 800FA564 0F80023C */  lui        $v0, %hi(D_800F1968)
    /* D68 800FA568 681940AC */  sw         $zero, %lo(D_800F1968)($v0)
    /* D6C 800FA56C 0F80023C */  lui        $v0, %hi(_lootListHead)
    /* D70 800FA570 001940AC */  sw         $zero, %lo(_lootListHead)($v0)
    /* D74 800FA574 0F80023C */  lui        $v0, %hi(D_800F1874)
    /* D78 800FA578 741840AC */  sw         $zero, %lo(D_800F1874)($v0)
    /* D7C 800FA57C 0F80023C */  lui        $v0, %hi(D_800F196C)
    /* D80 800FA580 0680033C */  lui        $v1, %hi(vs_gametime_tickspeed)
    /* D84 800FA584 6C1940AC */  sw         $zero, %lo(D_800F196C)($v0)
    /* D88 800FA588 02000224 */  addiu      $v0, $zero, 0x2
    /* D8C 800FA58C 4CE262AC */  sw         $v0, %lo(vs_gametime_tickspeed)($v1)
    /* D90 800FA590 0680033C */  lui        $v1, %hi(vs_main_projectionDistance)
    /* D94 800FA594 00020224 */  addiu      $v0, $zero, 0x200
    /* D98 800FA598 48E262AC */  sw         $v0, %lo(vs_main_projectionDistance)($v1)
    /* D9C 800FA59C 0680033C */  lui        $v1, %hi(vs_main_nearClip)
    /* DA0 800FA5A0 40000224 */  addiu      $v0, $zero, 0x40
    /* DA4 800FA5A4 C8E062AC */  sw         $v0, %lo(vs_main_nearClip)($v1)
    /* DA8 800FA5A8 0580023C */  lui        $v0, %hi(D_80050468)
    /* DAC 800FA5AC 6810A524 */  addiu      $a1, $a1, %lo(D_80061068)
    /* DB0 800FA5B0 680440A0 */  sb         $zero, %lo(D_80050468)($v0)
    /* DB4 800FA5B4 0600A394 */  lhu        $v1, 0x6($a1)
    /* DB8 800FA5B8 68044224 */  addiu      $v0, $v0, %lo(D_80050468)
    /* DBC 800FA5BC 070040A0 */  sb         $zero, 0x7($v0)
    /* DC0 800FA5C0 060040A0 */  sb         $zero, 0x6($v0)
    /* DC4 800FA5C4 050040A0 */  sb         $zero, 0x5($v0)
    /* DC8 800FA5C8 040040A0 */  sb         $zero, 0x4($v0)
    /* DCC 800FA5CC 0F80023C */  lui        $v0, %hi(vs_battle_cameraTransition)
    /* DD0 800FA5D0 FF036330 */  andi       $v1, $v1, 0x3FF
    /* DD4 800FA5D4 680083AC */  sw         $v1, 0x68($a0)
    /* DD8 800FA5D8 B1DF010C */  jal        func_80077EC4
    /* DDC 800FA5DC 041940AC */   sw        $zero, %lo(vs_battle_cameraTransition)($v0)
    /* DE0 800FA5E0 2800A427 */  addiu      $a0, $sp, 0x28
    /* DE4 800FA5E4 801F033C */  lui        $v1, (0x1F800064 >> 16)
    /* DE8 800FA5E8 00100224 */  addiu      $v0, $zero, 0x1000
    /* DEC 800FA5EC 0F80053C */  lui        $a1, %hi(vs_battle_cameraCurrentSpherical)
    /* DF0 800FA5F0 640062AC */  sw         $v0, (0x1F800064 & 0xFFFF)($v1)
    /* DF4 800FA5F4 D019A224 */  addiu      $v0, $a1, %lo(vs_battle_cameraCurrentSpherical)
    /* DF8 800FA5F8 00080324 */  addiu      $v1, $zero, 0x800
    /* DFC 800FA5FC 140043AC */  sw         $v1, 0x14($v0)
    /* E00 800FA600 D019A3AC */  sw         $v1, %lo(vs_battle_cameraCurrentSpherical)($a1)
    /* E04 800FA604 80FE0324 */  addiu      $v1, $zero, -0x180
    /* E08 800FA608 040043AC */  sw         $v1, 0x4($v0)
    /* E0C 800FA60C 00060324 */  addiu      $v1, $zero, 0x600
    /* E10 800FA610 200043AC */  sw         $v1, 0x20($v0)
    /* E14 800FA614 080043AC */  sw         $v1, 0x8($v0)
    /* E18 800FA618 100040AC */  sw         $zero, 0x10($v0)
    /* E1C 800FA61C 180040AC */  sw         $zero, 0x18($v0)
    /* E20 800FA620 1C0050AC */  sw         $s0, 0x1C($v0)
    /* E24 800FA624 D97E020C */  jal        func_8009FB64
    /* E28 800FA628 240040AC */   sw        $zero, 0x24($v0)
    /* E2C 800FA62C 0F000324 */  addiu      $v1, $zero, 0xF
    /* E30 800FA630 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* E34 800FA634 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* E38 800FA638 3C004224 */  addiu      $v0, $v0, 0x3C
  .L800FA63C:
    /* E3C 800FA63C 000040AC */  sw         $zero, 0x0($v0)
    /* E40 800FA640 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* E44 800FA644 FDFF6104 */  bgez       $v1, .L800FA63C
    /* E48 800FA648 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* E4C 800FA64C 33E7030C */  jal        func_800F9CCC
    /* E50 800FA650 00000000 */   nop
    /* E54 800FA654 8F0F010C */  jal        vs_main_allocHeapR
    /* E58 800FA658 102C0424 */   addiu     $a0, $zero, 0x2C10
    /* E5C 800FA65C 21204000 */  addu       $a0, $v0, $zero
    /* E60 800FA660 102C0524 */  addiu      $a1, $zero, 0x2C10
    /* E64 800FA664 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* E68 800FA668 4424010C */  jal        vs_main_bzero
    /* E6C 800FA66C CC1944AC */   sw        $a0, %lo(D_800F19CC)($v0)
    /* E70 800FA670 40010424 */  addiu      $a0, $zero, 0x140
    /* E74 800FA674 F0000524 */  addiu      $a1, $zero, 0xF0
    /* E78 800FA678 0F80033C */  lui        $v1, %hi(D_800F190C)
    /* E7C 800FA67C 01000224 */  addiu      $v0, $zero, 0x1
    /* E80 800FA680 0C1962AC */  sw         $v0, %lo(D_800F190C)($v1)
    /* E84 800FA684 0F80023C */  lui        $v0, %hi(D_800F18F4)
    /* E88 800FA688 F41840AC */  sw         $zero, %lo(D_800F18F4)($v0)
    /* E8C 800FA68C 0680023C */  lui        $v0, %hi(vs_main_projectionDistance)
    /* E90 800FA690 48E2468C */  lw         $a2, %lo(vs_main_projectionDistance)($v0)
    /* E94 800FA694 21380000 */  addu       $a3, $zero, $zero
    /* E98 800FA698 1000A0AF */  sw         $zero, 0x10($sp)
    /* E9C 800FA69C 33D8010C */  jal        func_800760CC
    /* EA0 800FA6A0 1400A0AF */   sw        $zero, 0x14($sp)
    /* EA4 800FA6A4 5800BF8F */  lw         $ra, 0x58($sp)
    /* EA8 800FA6A8 5400B18F */  lw         $s1, 0x54($sp)
    /* EAC 800FA6AC 5000B08F */  lw         $s0, 0x50($sp)
    /* EB0 800FA6B0 0800E003 */  jr         $ra
    /* EB4 800FA6B4 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel func_800FA35C
