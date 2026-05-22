nonmatching _pollItemNavigation, 0xB8

glabel _pollItemNavigation
    /* 156C 80103D6C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1570 80103D70 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1574 80103D74 2180A000 */  addu       $s0, $a1, $zero
    /* 1578 80103D78 0680023C */  lui        $v0, %hi(vs_main_buttonsState)
    /* 157C 80103D7C 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 1580 80103D80 0C000324 */  addiu      $v1, $zero, 0xC
    /* 1584 80103D84 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1588 80103D88 0C004230 */  andi       $v0, $v0, 0xC
    /* 158C 80103D8C 1F004310 */  beq        $v0, $v1, .L80103E0C
    /* 1590 80103D90 1400B1AF */   sw        $s1, 0x14($sp)
    /* 1594 80103D94 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 1598 80103D98 8C9A458C */  lw         $a1, %lo(vs_menuD_containerData)($v0)
    /* 159C 80103D9C 1C0C040C */  jal        _countContainerItems
    /* 15A0 80103DA0 21880002 */   addu      $s1, $s0, $zero
    /* 15A4 80103DA4 21284000 */  addu       $a1, $v0, $zero
    /* 15A8 80103DA8 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 15AC 80103DAC DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 15B0 80103DB0 00000000 */  nop
    /* 15B4 80103DB4 04006230 */  andi       $v0, $v1, 0x4
    /* 15B8 80103DB8 03004010 */  beqz       $v0, .L80103DC8
    /* 15BC 80103DBC 2120A000 */   addu      $a0, $a1, $zero
    /* 15C0 80103DC0 FFFF0226 */  addiu      $v0, $s0, -0x1
    /* 15C4 80103DC4 21804500 */  addu       $s0, $v0, $a1
  .L80103DC8:
    /* 15C8 80103DC8 08006230 */  andi       $v0, $v1, 0x8
    /* 15CC 80103DCC 03004010 */  beqz       $v0, .L80103DDC
    /* 15D0 80103DD0 2A100402 */   slt       $v0, $s0, $a0
    /* 15D4 80103DD4 01001026 */  addiu      $s0, $s0, 0x1
    /* 15D8 80103DD8 2A100402 */  slt        $v0, $s0, $a0
  .L80103DDC:
    /* 15DC 80103DDC 02004014 */  bnez       $v0, .L80103DE8
    /* 15E0 80103DE0 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 15E4 80103DE4 23800402 */  subu       $s0, $s0, $a0
  .L80103DE8:
    /* 15E8 80103DE8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 15EC 80103DEC 00000000 */  nop
    /* 15F0 80103DF0 0C004230 */  andi       $v0, $v0, 0xC
    /* 15F4 80103DF4 06004010 */  beqz       $v0, .L80103E10
    /* 15F8 80103DF8 21100002 */   addu      $v0, $s0, $zero
    /* 15FC 80103DFC 04001116 */  bne        $s0, $s1, .L80103E10
    /* 1600 80103E00 00000000 */   nop
    /* 1604 80103E04 B800030C */  jal        vs_battle_playInvalidSfx
    /* 1608 80103E08 00000000 */   nop
  .L80103E0C:
    /* 160C 80103E0C 21100002 */  addu       $v0, $s0, $zero
  .L80103E10:
    /* 1610 80103E10 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1614 80103E14 1400B18F */  lw         $s1, 0x14($sp)
    /* 1618 80103E18 1000B08F */  lw         $s0, 0x10($sp)
    /* 161C 80103E1C 0800E003 */  jr         $ra
    /* 1620 80103E20 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _pollItemNavigation
