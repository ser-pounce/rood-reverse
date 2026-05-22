nonmatching PadInitDirect, 0x160

glabel PadInitDirect
    /* 1E4C4 8002DCC4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1E4C8 8002DCC8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1E4CC 8002DCCC 21888000 */  addu       $s1, $a0, $zero
    /* 1E4D0 8002DCD0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1E4D4 8002DCD4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1E4D8 8002DCD8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1E4DC 8002DCDC 0380013C */  lui        $at, %hi(D_800335D4)
    /* 1E4E0 8002DCE0 D43520AC */  sw         $zero, %lo(D_800335D4)($at)
    /* 1E4E4 8002DCE4 0380013C */  lui        $at, %hi(D_800335E8)
    /* 1E4E8 8002DCE8 E83520AC */  sw         $zero, %lo(D_800335E8)($at)
    /* 1E4EC 8002DCEC CDB8000C */  jal        _padInitDirSeq
    /* 1E4F0 8002DCF0 2190A000 */   addu      $s2, $a1, $zero
    /* 1E4F4 8002DCF4 0480103C */  lui        $s0, %hi(D_8003FCC0)
    /* 1E4F8 8002DCF8 C0FC1026 */  addiu      $s0, $s0, %lo(D_8003FCC0)
    /* 1E4FC 8002DCFC 0380023C */  lui        $v0, %hi(func_8002DE8C)
    /* 1E500 8002DD00 8CDE4224 */  addiu      $v0, $v0, %lo(func_8002DE8C)
    /* 1E504 8002DD04 0380013C */  lui        $at, %hi(D_8003359C)
    /* 1E508 8002DD08 9C3522AC */  sw         $v0, %lo(D_8003359C)($at)
    /* 1E50C 8002DD0C 0380023C */  lui        $v0, %hi(func_8002DE24)
    /* 1E510 8002DD10 24DE4224 */  addiu      $v0, $v0, %lo(func_8002DE24)
    /* 1E514 8002DD14 0380013C */  lui        $at, %hi(D_800335A0)
    /* 1E518 8002DD18 A03522AC */  sw         $v0, %lo(D_800335A0)($at)
    /* 1E51C 8002DD1C 0380023C */  lui        $v0, %hi(func_8002DF90)
    /* 1E520 8002DD20 90DF4224 */  addiu      $v0, $v0, %lo(func_8002DF90)
    /* 1E524 8002DD24 0380013C */  lui        $at, %hi(D_800335A4)
    /* 1E528 8002DD28 A43522AC */  sw         $v0, %lo(D_800335A4)($at)
    /* 1E52C 8002DD2C 0380023C */  lui        $v0, %hi(func_8002E04C)
    /* 1E530 8002DD30 4CE04224 */  addiu      $v0, $v0, %lo(func_8002E04C)
    /* 1E534 8002DD34 0380013C */  lui        $at, %hi(D_800335A8)
    /* 1E538 8002DD38 A83522AC */  sw         $v0, %lo(D_800335A8)($at)
    /* 1E53C 8002DD3C 0380023C */  lui        $v0, %hi(func_8002E2C8)
    /* 1E540 8002DD40 C8E24224 */  addiu      $v0, $v0, %lo(func_8002E2C8)
    /* 1E544 8002DD44 0380013C */  lui        $at, %hi(D_800335AC)
    /* 1E548 8002DD48 AC3522AC */  sw         $v0, %lo(D_800335AC)($at)
    /* 1E54C 8002DD4C 0380023C */  lui        $v0, %hi(func_8002E300)
    /* 1E550 8002DD50 00E34224 */  addiu      $v0, $v0, %lo(func_8002E300)
    /* 1E554 8002DD54 0380013C */  lui        $at, %hi(D_800335B0)
    /* 1E558 8002DD58 B03522AC */  sw         $v0, %lo(D_800335B0)($at)
    /* 1E55C 8002DD5C 0380023C */  lui        $v0, %hi(func_8002DF80)
    /* 1E560 8002DD60 80DF4224 */  addiu      $v0, $v0, %lo(func_8002DF80)
    /* 1E564 8002DD64 21200002 */  addu       $a0, $s0, $zero
    /* 1E568 8002DD68 0380013C */  lui        $at, %hi(D_800335D0)
    /* 1E56C 8002DD6C D03530AC */  sw         $s0, %lo(D_800335D0)($at)
    /* 1E570 8002DD70 0380013C */  lui        $at, %hi(D_800335C0)
    /* 1E574 8002DD74 C03522AC */  sw         $v0, %lo(D_800335C0)($at)
    /* 1E578 8002DD78 C9B8000C */  jal        bzero
    /* 1E57C 8002DD7C E0010524 */   addiu     $a1, $zero, 0x1E0
    /* 1E580 8002DD80 21400000 */  addu       $t0, $zero, $zero
    /* 1E584 8002DD84 FF000924 */  addiu      $t1, $zero, 0xFF
    /* 1E588 8002DD88 40000426 */  addiu      $a0, $s0, 0x40
    /* 1E58C 8002DD8C 0480073C */  lui        $a3, %hi(D_8003FC78)
    /* 1E590 8002DD90 78FCE724 */  addiu      $a3, $a3, %lo(D_8003FC78)
    /* 1E594 8002DD94 0480063C */  lui        $a2, %hi(D_8003FC30)
    /* 1E598 8002DD98 30FCC624 */  addiu      $a2, $a2, %lo(D_8003FC30)
    /* 1E59C 8002DD9C 300011AE */  sw         $s1, 0x30($s0)
    /* 1E5A0 8002DDA0 200112AE */  sw         $s2, 0x120($s0)
  .L8002DDA4:
    /* 1E5A4 8002DDA4 F0FF828C */  lw         $v0, -0x10($a0)
    /* 1E5A8 8002DDA8 5D000526 */  addiu      $a1, $s0, 0x5D
    /* 1E5AC 8002DDAC CCFF80AC */  sw         $zero, -0x34($a0)
    /* 1E5B0 8002DDB0 D0FF90AC */  sw         $s0, -0x30($a0)
    /* 1E5B4 8002DDB4 000049A0 */  sb         $t1, 0x0($v0)
    /* 1E5B8 8002DDB8 F0FF828C */  lw         $v0, -0x10($a0)
    /* 1E5BC 8002DDBC 05000324 */  addiu      $v1, $zero, 0x5
    /* 1E5C0 8002DDC0 010040A0 */  sb         $zero, 0x1($v0)
    /* 1E5C4 8002DDC4 FCFF86AC */  sw         $a2, -0x4($a0)
    /* 1E5C8 8002DDC8 000087AC */  sw         $a3, 0x0($a0)
  .L8002DDCC:
    /* 1E5CC 8002DDCC 0000A9A0 */  sb         $t1, 0x0($a1)
    /* 1E5D0 8002DDD0 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1E5D4 8002DDD4 FDFF6104 */  bgez       $v1, .L8002DDCC
    /* 1E5D8 8002DDD8 0100A524 */   addiu     $a1, $a1, 0x1
    /* 1E5DC 8002DDDC 2300E724 */  addiu      $a3, $a3, 0x23
    /* 1E5E0 8002DDE0 2300C624 */  addiu      $a2, $a2, 0x23
    /* 1E5E4 8002DDE4 01000825 */  addiu      $t0, $t0, 0x1
    /* 1E5E8 8002DDE8 F0008424 */  addiu      $a0, $a0, 0xF0
    /* 1E5EC 8002DDEC 02000229 */  slti       $v0, $t0, 0x2
    /* 1E5F0 8002DDF0 ECFF4014 */  bnez       $v0, .L8002DDA4
    /* 1E5F4 8002DDF4 F0001026 */   addiu     $s0, $s0, 0xF0
    /* 1E5F8 8002DDF8 6FAF000C */  jal        _padSetVsyncParam
    /* 1E5FC 8002DDFC 00000000 */   nop
    /* 1E600 8002DE00 01000224 */  addiu      $v0, $zero, 0x1
    /* 1E604 8002DE04 0380013C */  lui        $at, %hi(D_800335D4)
    /* 1E608 8002DE08 D43522AC */  sw         $v0, %lo(D_800335D4)($at)
    /* 1E60C 8002DE0C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1E610 8002DE10 1800B28F */  lw         $s2, 0x18($sp)
    /* 1E614 8002DE14 1400B18F */  lw         $s1, 0x14($sp)
    /* 1E618 8002DE18 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E61C 8002DE1C 0800E003 */  jr         $ra
    /* 1E620 8002DE20 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel PadInitDirect
