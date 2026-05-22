nonmatching func_800AD494, 0x198

glabel func_800AD494
    /* 44C94 800AD494 0400A014 */  bnez       $a1, .L800AD4A8
    /* 44C98 800AD498 0000C0AC */   sw        $zero, 0x0($a2)
    /* 44C9C 800AD49C D005878C */  lw         $a3, 0x5D0($a0)
    /* 44CA0 800AD4A0 72B50208 */  j          .L800AD5C8
    /* 44CA4 800AD4A4 21280000 */   addu      $a1, $zero, $zero
  .L800AD4A8:
    /* 44CA8 800AD4A8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 44CAC 800AD4AC 1A00A214 */  bne        $a1, $v0, .L800AD518
    /* 44CB0 800AD4B0 FE000224 */   addiu     $v0, $zero, 0xFE
    /* 44CB4 800AD4B4 0F008290 */  lbu        $v0, 0xF($a0)
    /* 44CB8 800AD4B8 E805878C */  lw         $a3, 0x5E8($a0)
    /* 44CBC 800AD4BC 05004010 */  beqz       $v0, .L800AD4D4
    /* 44CC0 800AD4C0 02000224 */   addiu     $v0, $zero, 0x2
    /* 44CC4 800AD4C4 E6068394 */  lhu        $v1, 0x6E6($a0)
    /* 44CC8 800AD4C8 00000000 */  nop
    /* 44CCC 800AD4CC 05006214 */  bne        $v1, $v0, .L800AD4E4
    /* 44CD0 800AD4D0 00000000 */   nop
  .L800AD4D4:
    /* 44CD4 800AD4D4 0F80023C */  lui        $v0, %hi(D_800F49E4)
    /* 44CD8 800AD4D8 E4494590 */  lbu        $a1, %lo(D_800F49E4)($v0)
    /* 44CDC 800AD4DC 43B50208 */  j          .L800AD50C
    /* 44CE0 800AD4E0 00000000 */   nop
  .L800AD4E4:
    /* 44CE4 800AD4E4 B1058290 */  lbu        $v0, 0x5B1($a0)
    /* 44CE8 800AD4E8 00000000 */  nop
    /* 44CEC 800AD4EC 10004010 */  beqz       $v0, .L800AD530
    /* 44CF0 800AD4F0 0F80033C */   lui       $v1, %hi(D_800F49E4)
    /* 44CF4 800AD4F4 B1058290 */  lbu        $v0, 0x5B1($a0)
    /* 44CF8 800AD4F8 E4496390 */  lbu        $v1, %lo(D_800F49E4)($v1)
    /* 44CFC 800AD4FC FFFF4524 */  addiu      $a1, $v0, -0x1
    /* 44D00 800AD500 40100500 */  sll        $v0, $a1, 1
    /* 44D04 800AD504 21104500 */  addu       $v0, $v0, $a1
    /* 44D08 800AD508 21284300 */  addu       $a1, $v0, $v1
  .L800AD50C:
    /* 44D0C 800AD50C B6058290 */  lbu        $v0, 0x5B6($a0)
    /* 44D10 800AD510 70B50208 */  j          .L800AD5C0
    /* 44D14 800AD514 2A10A200 */   slt       $v0, $a1, $v0
  .L800AD518:
    /* 44D18 800AD518 1000A214 */  bne        $a1, $v0, .L800AD55C
    /* 44D1C 800AD51C DC00A228 */   slti      $v0, $a1, 0xDC
    /* 44D20 800AD520 B1058290 */  lbu        $v0, 0x5B1($a0)
    /* 44D24 800AD524 E805878C */  lw         $a3, 0x5E8($a0)
    /* 44D28 800AD528 03004014 */  bnez       $v0, .L800AD538
    /* 44D2C 800AD52C FFFF4524 */   addiu     $a1, $v0, -0x1
  .L800AD530:
    /* 44D30 800AD530 89B50208 */  j          .L800AD624
    /* 44D34 800AD534 21100000 */   addu      $v0, $zero, $zero
  .L800AD538:
    /* 44D38 800AD538 B6058390 */  lbu        $v1, 0x5B6($a0)
    /* 44D3C 800AD53C 40100500 */  sll        $v0, $a1, 1
    /* 44D40 800AD540 21104500 */  addu       $v0, $v0, $a1
    /* 44D44 800AD544 1F004524 */  addiu      $a1, $v0, 0x1F
    /* 44D48 800AD548 2A18A300 */  slt        $v1, $a1, $v1
    /* 44D4C 800AD54C 1E006014 */  bnez       $v1, .L800AD5C8
    /* 44D50 800AD550 21100000 */   addu      $v0, $zero, $zero
    /* 44D54 800AD554 89B50208 */  j          .L800AD624
    /* 44D58 800AD558 00000000 */   nop
  .L800AD55C:
    /* 44D5C 800AD55C 09004014 */  bnez       $v0, .L800AD584
    /* 44D60 800AD560 CA00A228 */   slti      $v0, $a1, 0xCA
    /* 44D64 800AD564 0F80023C */  lui        $v0, %hi(D_800E8F2C)
    /* 44D68 800AD568 2C8F4290 */  lbu        $v0, %lo(D_800E8F2C)($v0)
    /* 44D6C 800AD56C 00000000 */  nop
    /* 44D70 800AD570 80100200 */  sll        $v0, $v0, 2
    /* 44D74 800AD574 21104400 */  addu       $v0, $v0, $a0
    /* 44D78 800AD578 DC05478C */  lw         $a3, 0x5DC($v0)
    /* 44D7C 800AD57C 72B50208 */  j          .L800AD5C8
    /* 44D80 800AD580 24FFA524 */   addiu     $a1, $a1, -0xDC
  .L800AD584:
    /* 44D84 800AD584 05004014 */  bnez       $v0, .L800AD59C
    /* 44D88 800AD588 6400A228 */   slti      $v0, $a1, 0x64
    /* 44D8C 800AD58C 0F80023C */  lui        $v0, %hi(D_800F4768)
    /* 44D90 800AD590 6847478C */  lw         $a3, %lo(D_800F4768)($v0)
    /* 44D94 800AD594 72B50208 */  j          .L800AD5C8
    /* 44D98 800AD598 36FFA524 */   addiu     $a1, $a1, -0xCA
  .L800AD59C:
    /* 44D9C 800AD59C 05004014 */  bnez       $v0, .L800AD5B4
    /* 44DA0 800AD5A0 00000000 */   nop
    /* 44DA4 800AD5A4 B5058290 */  lbu        $v0, 0x5B5($a0)
    /* 44DA8 800AD5A8 D805878C */  lw         $a3, 0x5D8($a0)
    /* 44DAC 800AD5AC 6FB50208 */  j          .L800AD5BC
    /* 44DB0 800AD5B0 9CFFA524 */   addiu     $a1, $a1, -0x64
  .L800AD5B4:
    /* 44DB4 800AD5B4 B4058290 */  lbu        $v0, 0x5B4($a0)
    /* 44DB8 800AD5B8 D405878C */  lw         $a3, 0x5D4($a0)
  .L800AD5BC:
    /* 44DBC 800AD5BC 2A10A200 */  slt        $v0, $a1, $v0
  .L800AD5C0:
    /* 44DC0 800AD5C0 18004010 */  beqz       $v0, .L800AD624
    /* 44DC4 800AD5C4 21100000 */   addu      $v0, $zero, $zero
  .L800AD5C8:
    /* 44DC8 800AD5C8 1600E010 */  beqz       $a3, .L800AD624
    /* 44DCC 800AD5CC 21100000 */   addu      $v0, $zero, $zero
    /* 44DD0 800AD5D0 0400E28C */  lw         $v0, 0x4($a3)
    /* 44DD4 800AD5D4 00000000 */  nop
    /* 44DD8 800AD5D8 21104500 */  addu       $v0, $v0, $a1
    /* 44DDC 800AD5DC 00004590 */  lbu        $a1, 0x0($v0)
    /* 44DE0 800AD5E0 0F80023C */  lui        $v0, %hi(D_800F49DC)
    /* 44DE4 800AD5E4 DC4945A0 */  sb         $a1, %lo(D_800F49DC)($v0)
    /* 44DE8 800AD5E8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 44DEC 800AD5EC 0300A214 */  bne        $a1, $v0, .L800AD5FC
    /* 44DF0 800AD5F0 00000000 */   nop
    /* 44DF4 800AD5F4 88B50208 */  j          .L800AD620
    /* 44DF8 800AD5F8 0000C0AC */   sw        $zero, 0x0($a2)
  .L800AD5FC:
    /* 44DFC 800AD5FC 00008290 */  lbu        $v0, 0x0($a0)
    /* 44E00 800AD600 00000000 */  nop
    /* 44E04 800AD604 80100200 */  sll        $v0, $v0, 2
    /* 44E08 800AD608 0A004224 */  addiu      $v0, $v0, 0xA
    /* 44E0C 800AD60C 18004500 */  mult       $v0, $a1
    /* 44E10 800AD610 12400000 */  mflo       $t0
    /* 44E14 800AD614 08000225 */  addiu      $v0, $t0, 0x8
    /* 44E18 800AD618 2110E200 */  addu       $v0, $a3, $v0
    /* 44E1C 800AD61C 0000C2AC */  sw         $v0, 0x0($a2)
  .L800AD620:
    /* 44E20 800AD620 2110E000 */  addu       $v0, $a3, $zero
  .L800AD624:
    /* 44E24 800AD624 0800E003 */  jr         $ra
    /* 44E28 800AD628 00000000 */   nop
endlabel func_800AD494
