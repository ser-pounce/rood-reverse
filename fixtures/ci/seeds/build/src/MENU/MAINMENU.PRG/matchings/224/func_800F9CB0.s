nonmatching func_800F9CB0, 0x15C

glabel func_800F9CB0
    /* 4B0 800F9CB0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4B4 800F9CB4 0F80023C */  lui        $v0, %hi(D_800F453C)
    /* 4B8 800F9CB8 21280000 */  addu       $a1, $zero, $zero
    /* 4BC 800F9CBC 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4C0 800F9CC0 3C45508C */  lw         $s0, %lo(D_800F453C)($v0)
    /* 4C4 800F9CC4 0F80023C */  lui        $v0, %hi(D_800F4590)
    /* 4C8 800F9CC8 90454424 */  addiu      $a0, $v0, %lo(D_800F4590)
    /* 4CC 800F9CCC 2400BFAF */  sw         $ra, 0x24($sp)
  .L800F9CD0:
    /* 4D0 800F9CD0 0000838C */  lw         $v1, 0x0($a0)
    /* 4D4 800F9CD4 00000000 */  nop
    /* 4D8 800F9CD8 05006010 */  beqz       $v1, .L800F9CF0
    /* 4DC 800F9CDC 00000000 */   nop
    /* 4E0 800F9CE0 0800628C */  lw         $v0, 0x8($v1)
    /* 4E4 800F9CE4 00000000 */  nop
    /* 4E8 800F9CE8 10004234 */  ori        $v0, $v0, 0x10
    /* 4EC 800F9CEC 080062AC */  sw         $v0, 0x8($v1)
  .L800F9CF0:
    /* 4F0 800F9CF0 0100A524 */  addiu      $a1, $a1, 0x1
    /* 4F4 800F9CF4 0200A228 */  slti       $v0, $a1, 0x2
    /* 4F8 800F9CF8 F5FF4014 */  bnez       $v0, .L800F9CD0
    /* 4FC 800F9CFC 04008424 */   addiu     $a0, $a0, 0x4
    /* 500 800F9D00 1A75020C */  jal        func_8009D468
    /* 504 800F9D04 01000424 */   addiu     $a0, $zero, 0x1
    /* 508 800F9D08 FFFF043C */  lui        $a0, (0xFFFF7FFF >> 16)
    /* 50C 800F9D0C FF7F8434 */  ori        $a0, $a0, (0xFFFF7FFF & 0xFFFF)
    /* 510 800F9D10 FFFF053C */  lui        $a1, (0xFFFF00FF >> 16)
    /* 514 800F9D14 FF00A534 */  ori        $a1, $a1, (0xFFFF00FF & 0xFFFF)
    /* 518 800F9D18 EFFF0324 */  addiu      $v1, $zero, -0x11
    /* 51C 800F9D1C B005028E */  lw         $v0, 0x5B0($s0)
    /* 520 800F9D20 FEFF0624 */  addiu      $a2, $zero, -0x2
    /* 524 800F9D24 1C0000A6 */  sh         $zero, 0x1C($s0)
    /* 528 800F9D28 1E0000A6 */  sh         $zero, 0x1E($s0)
    /* 52C 800F9D2C 200000A6 */  sh         $zero, 0x20($s0)
    /* 530 800F9D30 24104300 */  and        $v0, $v0, $v1
    /* 534 800F9D34 B00502AE */  sw         $v0, 0x5B0($s0)
    /* 538 800F9D38 0800028E */  lw         $v0, 0x8($s0)
    /* 53C 800F9D3C 00FF0324 */  addiu      $v1, $zero, -0x100
    /* 540 800F9D40 24104600 */  and        $v0, $v0, $a2
    /* 544 800F9D44 24104400 */  and        $v0, $v0, $a0
    /* 548 800F9D48 080002AE */  sw         $v0, 0x8($s0)
    /* 54C 800F9D4C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 550 800F9D50 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 554 800F9D54 1100A2A3 */  sb         $v0, 0x11($sp)
    /* 558 800F9D58 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 55C 800F9D5C 1800A28F */  lw         $v0, 0x18($sp)
    /* 560 800F9D60 0010043C */  lui        $a0, (0x10000000 >> 16)
    /* 564 800F9D64 24104300 */  and        $v0, $v0, $v1
    /* 568 800F9D68 02004234 */  ori        $v0, $v0, 0x2
    /* 56C 800F9D6C 24104500 */  and        $v0, $v0, $a1
    /* 570 800F9D70 00FE4234 */  ori        $v0, $v0, 0xFE00
    /* 574 800F9D74 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 578 800F9D78 02FE4230 */  andi       $v0, $v0, 0xFE02
    /* 57C 800F9D7C 25104300 */  or         $v0, $v0, $v1
    /* 580 800F9D80 0F80033C */  lui        $v1, %hi(D_800F4578)
    /* 584 800F9D84 7845638C */  lw         $v1, %lo(D_800F4578)($v1)
    /* 588 800F9D88 25104400 */  or         $v0, $v0, $a0
    /* 58C 800F9D8C 08006014 */  bnez       $v1, .L800F9DB0
    /* 590 800F9D90 1800A2AF */   sw        $v0, 0x18($sp)
    /* 594 800F9D94 01000424 */  addiu      $a0, $zero, 0x1
    /* 598 800F9D98 21288000 */  addu       $a1, $a0, $zero
    /* 59C 800F9D9C 1800A627 */  addiu      $a2, $sp, 0x18
    /* 5A0 800F9DA0 507E020C */  jal        func_8009F940
    /* 5A4 800F9DA4 1000A727 */   addiu     $a3, $sp, 0x10
    /* 5A8 800F9DA8 71E70308 */  j          .L800F9DC4
    /* 5AC 800F9DAC 01000424 */   addiu     $a0, $zero, 0x1
  .L800F9DB0:
    /* 5B0 800F9DB0 0800628C */  lw         $v0, 0x8($v1)
    /* 5B4 800F9DB4 00000000 */  nop
    /* 5B8 800F9DB8 24104600 */  and        $v0, $v0, $a2
    /* 5BC 800F9DBC 080062AC */  sw         $v0, 0x8($v1)
    /* 5C0 800F9DC0 01000424 */  addiu      $a0, $zero, 0x1
  .L800F9DC4:
    /* 5C4 800F9DC4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 5C8 800F9DC8 1000A0A3 */  sb         $zero, 0x10($sp)
    /* 5CC 800F9DCC 1100A0A3 */  sb         $zero, 0x11($sp)
    /* 5D0 800F9DD0 DA81020C */  jal        func_800A0768
    /* 5D4 800F9DD4 1200A0A3 */   sb        $zero, 0x12($sp)
    /* 5D8 800F9DD8 01000424 */  addiu      $a0, $zero, 0x1
    /* 5DC 800F9DDC FF81020C */  jal        func_800A07FC
    /* 5E0 800F9DE0 21280000 */   addu      $a1, $zero, $zero
    /* 5E4 800F9DE4 FEFF033C */  lui        $v1, (0xFFFEFFFF >> 16)
    /* 5E8 800F9DE8 4806028E */  lw         $v0, 0x648($s0)
    /* 5EC 800F9DEC FFFF6334 */  ori        $v1, $v1, (0xFFFEFFFF & 0xFFFF)
    /* 5F0 800F9DF0 24104300 */  and        $v0, $v0, $v1
    /* 5F4 800F9DF4 480602AE */  sw         $v0, 0x648($s0)
    /* 5F8 800F9DF8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 5FC 800F9DFC 2000B08F */  lw         $s0, 0x20($sp)
    /* 600 800F9E00 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 604 800F9E04 0800E003 */  jr         $ra
    /* 608 800F9E08 00000000 */   nop
endlabel func_800F9CB0
