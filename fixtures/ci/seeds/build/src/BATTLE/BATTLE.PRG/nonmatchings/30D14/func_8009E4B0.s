nonmatching func_8009E4B0, 0x114

glabel func_8009E4B0
    /* 35CB0 8009E4B0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 35CB4 8009E4B4 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 35CB8 8009E4B8 80200400 */  sll        $a0, $a0, 2
    /* 35CBC 8009E4BC 21108200 */  addu       $v0, $a0, $v0
    /* 35CC0 8009E4C0 0000458C */  lw         $a1, 0x0($v0)
    /* 35CC4 8009E4C4 00000000 */  nop
    /* 35CC8 8009E4C8 0900A014 */  bnez       $a1, .L8009E4F0
    /* 35CCC 8009E4CC 0F80023C */   lui       $v0, %hi(D_800F45E0)
    /* 35CD0 8009E4D0 E0454224 */  addiu      $v0, $v0, %lo(D_800F45E0)
    /* 35CD4 8009E4D4 21108200 */  addu       $v0, $a0, $v0
    /* 35CD8 8009E4D8 0000438C */  lw         $v1, 0x0($v0)
    /* 35CDC 8009E4DC 00000000 */  nop
    /* 35CE0 8009E4E0 36006010 */  beqz       $v1, .L8009E5BC
    /* 35CE4 8009E4E4 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 35CE8 8009E4E8 6F790208 */  j          .L8009E5BC
    /* 35CEC 8009E4EC 21100000 */   addu      $v0, $zero, $zero
  .L8009E4F0:
    /* 35CF0 8009E4F0 0800A28C */  lw         $v0, 0x8($a1)
    /* 35CF4 8009E4F4 00000000 */  nop
    /* 35CF8 8009E4F8 000F4330 */  andi       $v1, $v0, 0xF00
    /* 35CFC 8009E4FC 05006010 */  beqz       $v1, .L8009E514
    /* 35D00 8009E500 00050224 */   addiu     $v0, $zero, 0x500
    /* 35D04 8009E504 03006210 */  beq        $v1, $v0, .L8009E514
    /* 35D08 8009E508 000B0224 */   addiu     $v0, $zero, 0xB00
    /* 35D0C 8009E50C 2B006214 */  bne        $v1, $v0, .L8009E5BC
    /* 35D10 8009E510 01000224 */   addiu     $v0, $zero, 0x1
  .L8009E514:
    /* 35D14 8009E514 9C11A28C */  lw         $v0, 0x119C($a1)
    /* 35D18 8009E518 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 35D1C 8009E51C 24104300 */  and        $v0, $v0, $v1
    /* 35D20 8009E520 26004014 */  bnez       $v0, .L8009E5BC
    /* 35D24 8009E524 21100000 */   addu      $v0, $zero, $zero
    /* 35D28 8009E528 B805A490 */  lbu        $a0, 0x5B8($a1)
    /* 35D2C 8009E52C 00000000 */  nop
    /* 35D30 8009E530 64008228 */  slti       $v0, $a0, 0x64
    /* 35D34 8009E534 12004014 */  bnez       $v0, .L8009E580
    /* 35D38 8009E538 1C000224 */   addiu     $v0, $zero, 0x1C
    /* 35D3C 8009E53C 9CFF8424 */  addiu      $a0, $a0, -0x64
    /* 35D40 8009E540 F7FF8224 */  addiu      $v0, $a0, -0x9
    /* 35D44 8009E544 0400422C */  sltiu      $v0, $v0, 0x4
    /* 35D48 8009E548 03004010 */  beqz       $v0, .L8009E558
    /* 35D4C 8009E54C 1C000224 */   addiu     $v0, $zero, 0x1C
  .L8009E550:
    /* 35D50 8009E550 6F790208 */  j          .L8009E5BC
    /* 35D54 8009E554 01000224 */   addiu     $v0, $zero, 0x1
  .L8009E558:
    /* 35D58 8009E558 FDFF8210 */  beq        $a0, $v0, .L8009E550
    /* 35D5C 8009E55C 9EFF8224 */   addiu     $v0, $a0, -0x62
    /* 35D60 8009E560 0400422C */  sltiu      $v0, $v0, 0x4
    /* 35D64 8009E564 15004014 */  bnez       $v0, .L8009E5BC
    /* 35D68 8009E568 21100000 */   addu      $v0, $zero, $zero
    /* 35D6C 8009E56C 40008228 */  slti       $v0, $a0, 0x40
    /* 35D70 8009E570 12004014 */  bnez       $v0, .L8009E5BC
    /* 35D74 8009E574 21100000 */   addu      $v0, $zero, $zero
    /* 35D78 8009E578 6F790208 */  j          .L8009E5BC
    /* 35D7C 8009E57C 01000224 */   addiu     $v0, $zero, 0x1
  .L8009E580:
    /* 35D80 8009E580 F3FF8210 */  beq        $a0, $v0, .L8009E550
    /* 35D84 8009E584 3B000224 */   addiu     $v0, $zero, 0x3B
    /* 35D88 8009E588 F1FF8210 */  beq        $a0, $v0, .L8009E550
    /* 35D8C 8009E58C C0FF8224 */   addiu     $v0, $a0, -0x40
    /* 35D90 8009E590 0700422C */  sltiu      $v0, $v0, 0x7
    /* 35D94 8009E594 09004014 */  bnez       $v0, .L8009E5BC
    /* 35D98 8009E598 01000224 */   addiu     $v0, $zero, 0x1
    /* 35D9C 8009E59C ABFF8224 */  addiu      $v0, $a0, -0x55
    /* 35DA0 8009E5A0 0700422C */  sltiu      $v0, $v0, 0x7
    /* 35DA4 8009E5A4 05004014 */  bnez       $v0, .L8009E5BC
    /* 35DA8 8009E5A8 01000224 */   addiu     $v0, $zero, 0x1
    /* 35DAC 8009E5AC 5E000324 */  addiu      $v1, $zero, 0x5E
    /* 35DB0 8009E5B0 02008310 */  beq        $a0, $v1, .L8009E5BC
    /* 35DB4 8009E5B4 00000000 */   nop
    /* 35DB8 8009E5B8 21100000 */  addu       $v0, $zero, $zero
  .L8009E5BC:
    /* 35DBC 8009E5BC 0800E003 */  jr         $ra
    /* 35DC0 8009E5C0 00000000 */   nop
endlabel func_8009E4B0
