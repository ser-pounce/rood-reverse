nonmatching func_8009352C, 0x8C

glabel func_8009352C
    /* 2AD2C 8009352C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2AD30 80093530 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2AD34 80093534 2180A000 */  addu       $s0, $a1, $zero
    /* 2AD38 80093538 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 2AD3C 8009353C F81B4324 */  addiu      $v1, $v0, %lo(vs_battle_roomData)
    /* 2AD40 80093540 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2AD44 80093544 B000658C */  lw         $a1, 0xB0($v1)
    /* 2AD48 80093548 00000000 */  nop
    /* 2AD4C 8009354C 1500A010 */  beqz       $a1, .L800935A4
    /* 2AD50 80093550 00000000 */   nop
    /* 2AD54 80093554 04000296 */  lhu        $v0, 0x4($s0)
    /* 2AD58 80093558 00000000 */  nop
    /* 2AD5C 8009355C 05004010 */  beqz       $v0, .L80093574
    /* 2AD60 80093560 0F80023C */   lui       $v0, %hi(D_800F1D00)
    /* 2AD64 80093564 001D4284 */  lh         $v0, %lo(D_800F1D00)($v0)
    /* 2AD68 80093568 00000000 */  nop
    /* 2AD6C 8009356C 06004010 */  beqz       $v0, .L80093588
    /* 2AD70 80093570 00020424 */   addiu     $a0, $zero, 0x200
  .L80093574:
    /* 2AD74 80093574 06000696 */  lhu        $a2, 0x6($s0)
    /* 2AD78 80093578 BA18010C */  jal        func_800462E8
    /* 2AD7C 8009357C 00020424 */   addiu     $a0, $zero, 0x200
    /* 2AD80 80093580 664D0208 */  j          .L80093598
    /* 2AD84 80093584 00000000 */   nop
  .L80093588:
    /* 2AD88 80093588 06000696 */  lhu        $a2, 0x6($s0)
    /* 2AD8C 8009358C 80000724 */  addiu      $a3, $zero, 0x80
    /* 2AD90 80093590 7318010C */  jal        func_800461CC
    /* 2AD94 80093594 1000A0AF */   sw        $zero, 0x10($sp)
  .L80093598:
    /* 2AD98 80093598 06000396 */  lhu        $v1, 0x6($s0)
    /* 2AD9C 8009359C 0F80023C */  lui        $v0, %hi(D_800F2258)
    /* 2ADA0 800935A0 582243A4 */  sh         $v1, %lo(D_800F2258)($v0)
  .L800935A4:
    /* 2ADA4 800935A4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2ADA8 800935A8 1800B08F */  lw         $s0, 0x18($sp)
    /* 2ADAC 800935AC 21100000 */  addu       $v0, $zero, $zero
    /* 2ADB0 800935B0 0800E003 */  jr         $ra
    /* 2ADB4 800935B4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8009352C
