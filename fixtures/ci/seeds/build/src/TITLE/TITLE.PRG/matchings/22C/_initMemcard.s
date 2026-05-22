nonmatching _initMemcard, 0x244

glabel _initMemcard
    /* 1C9C 8006A49C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1CA0 8006A4A0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1CA4 8006A4A4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1CA8 8006A4A8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1CAC 8006A4AC 25008010 */  beqz       $a0, .L8006A544
    /* 1CB0 8006A4B0 1800B0AF */   sw        $s0, 0x18($sp)
    /* 1CB4 8006A4B4 0100043C */  lui        $a0, (0x1C000 >> 16)
    /* 1CB8 8006A4B8 B10F010C */  jal        vs_main_allocHeap
    /* 1CBC 8006A4BC 00C08434 */   ori       $a0, $a0, (0x1C000 & 0xFFFF)
    /* 1CC0 8006A4C0 0100053C */  lui        $a1, (0x11400 >> 16)
    /* 1CC4 8006A4C4 0014A534 */  ori        $a1, $a1, (0x11400 & 0xFFFF)
    /* 1CC8 8006A4C8 0100073C */  lui        $a3, (0x14C98 >> 16)
    /* 1CCC 8006A4CC 984CE734 */  ori        $a3, $a3, (0x14C98 & 0xFFFF)
    /* 1CD0 8006A4D0 0100063C */  lui        $a2, (0x1C000 >> 16)
    /* 1CD4 8006A4D4 00C0C634 */  ori        $a2, $a2, (0x1C000 & 0xFFFF)
    /* 1CD8 8006A4D8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1CDC 8006A4DC 0E80103C */  lui        $s0, %hi(_spmcimg)
    /* 1CE0 8006A4E0 0E80033C */  lui        $v1, %hi(_mcData)
    /* 1CE4 8006A4E4 B8EA02AE */  sw         $v0, %lo(_spmcimg)($s0)
    /* 1CE8 8006A4E8 21104500 */  addu       $v0, $v0, $a1
    /* 1CEC 8006A4EC 0E80053C */  lui        $a1, %hi(_textTable)
    /* 1CF0 8006A4F0 BCEA62AC */  sw         $v0, %lo(_mcData)($v1)
    /* 1CF4 8006A4F4 00104324 */  addiu      $v1, $v0, 0x1000
    /* 1CF8 8006A4F8 C0EAA3AC */  sw         $v1, %lo(_textTable)($a1)
    /* 1CFC 8006A4FC 0E80053C */  lui        $a1, %hi(_saveFileInfo)
    /* 1D00 8006A500 00204324 */  addiu      $v1, $v0, 0x2000
    /* 1D04 8006A504 08EBA3AC */  sw         $v1, %lo(_saveFileInfo)($a1)
    /* 1D08 8006A508 0E80033C */  lui        $v1, %hi(_dirEntBuf)
    /* 1D0C 8006A50C 80224224 */  addiu      $v0, $v0, 0x2280
    /* 1D10 8006A510 04EB62AC */  sw         $v0, %lo(_dirEntBuf)($v1)
    /* 1D14 8006A514 1000A7AF */  sw         $a3, 0x10($sp)
    /* 1D18 8006A518 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 1D1C 8006A51C 1400A6AF */   sw        $a2, 0x14($sp)
    /* 1D20 8006A520 21204000 */  addu       $a0, $v0, $zero
    /* 1D24 8006A524 B8EA058E */  lw         $a1, %lo(_spmcimg)($s0)
    /* 1D28 8006A528 0E80023C */  lui        $v0, %hi(_mcDataLoad)
    /* 1D2C 8006A52C F112010C */  jal        vs_main_cdEnqueue
    /* 1D30 8006A530 C8C844AC */   sw        $a0, %lo(_mcDataLoad)($v0)
    /* 1D34 8006A534 21100000 */  addu       $v0, $zero, $zero
    /* 1D38 8006A538 0E80033C */  lui        $v1, %hi(_diskState)
    /* 1D3C 8006A53C B2A90108 */  j          .L8006A6C8
    /* 1D40 8006A540 C4C860A0 */   sb        $zero, %lo(_diskState)($v1)
  .L8006A544:
    /* 1D44 8006A544 0E80103C */  lui        $s0, %hi(_diskState)
    /* 1D48 8006A548 C4C80392 */  lbu        $v1, %lo(_diskState)($s0)
    /* 1D4C 8006A54C 01001124 */  addiu      $s1, $zero, 0x1
    /* 1D50 8006A550 1D007110 */  beq        $v1, $s1, .L8006A5C8
    /* 1D54 8006A554 02006228 */   slti      $v0, $v1, 0x2
    /* 1D58 8006A558 05004010 */  beqz       $v0, .L8006A570
    /* 1D5C 8006A55C 02000224 */   addiu     $v0, $zero, 0x2
    /* 1D60 8006A560 07006010 */  beqz       $v1, .L8006A580
    /* 1D64 8006A564 21100000 */   addu      $v0, $zero, $zero
    /* 1D68 8006A568 B2A90108 */  j          .L8006A6C8
    /* 1D6C 8006A56C 00000000 */   nop
  .L8006A570:
    /* 1D70 8006A570 24006210 */  beq        $v1, $v0, .L8006A604
    /* 1D74 8006A574 21100000 */   addu      $v0, $zero, $zero
    /* 1D78 8006A578 B2A90108 */  j          .L8006A6C8
    /* 1D7C 8006A57C 00000000 */   nop
  .L8006A580:
    /* 1D80 8006A580 0E80023C */  lui        $v0, %hi(_mcDataLoad)
    /* 1D84 8006A584 C8C8448C */  lw         $a0, %lo(_mcDataLoad)($v0)
    /* 1D88 8006A588 00000000 */  nop
    /* 1D8C 8006A58C 00008384 */  lh         $v1, 0x0($a0)
    /* 1D90 8006A590 04000224 */  addiu      $v0, $zero, 0x4
    /* 1D94 8006A594 4C006214 */  bne        $v1, $v0, .L8006A6C8
    /* 1D98 8006A598 21100000 */   addu      $v0, $zero, $zero
    /* 1D9C 8006A59C E012010C */  jal        vs_main_freeCdQueueSlot
    /* 1DA0 8006A5A0 00000000 */   nop
    /* 1DA4 8006A5A4 0001043C */  lui        $a0, (0x1000320 >> 16)
    /* 1DA8 8006A5A8 20038434 */  ori        $a0, $a0, (0x1000320 & 0xFFFF)
    /* 1DAC 8006A5AC 0001063C */  lui        $a2, (0x10000E0 >> 16)
    /* 1DB0 8006A5B0 0E80023C */  lui        $v0, %hi(_spmcimg)
    /* 1DB4 8006A5B4 B8EA458C */  lw         $a1, %lo(_spmcimg)($v0)
    /* 1DB8 8006A5B8 F7A2010C */  jal        _drawImage
    /* 1DBC 8006A5BC E000C634 */   ori       $a2, $a2, (0x10000E0 & 0xFFFF)
    /* 1DC0 8006A5C0 B1A90108 */  j          .L8006A6C4
    /* 1DC4 8006A5C4 C4C811A2 */   sb        $s1, %lo(_diskState)($s0)
  .L8006A5C8:
    /* 1DC8 8006A5C8 0100023C */  lui        $v0, (0x14CD0 >> 16)
    /* 1DCC 8006A5CC D04C4234 */  ori        $v0, $v0, (0x14CD0 & 0xFFFF)
    /* 1DD0 8006A5D0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1DD4 8006A5D4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1DD8 8006A5D8 00200224 */  addiu      $v0, $zero, 0x2000
    /* 1DDC 8006A5DC C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 1DE0 8006A5E0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1DE4 8006A5E4 21204000 */  addu       $a0, $v0, $zero
    /* 1DE8 8006A5E8 0E80023C */  lui        $v0, %hi(_mcData)
    /* 1DEC 8006A5EC BCEA458C */  lw         $a1, %lo(_mcData)($v0)
    /* 1DF0 8006A5F0 0E80023C */  lui        $v0, %hi(_mcDataLoad)
    /* 1DF4 8006A5F4 F112010C */  jal        vs_main_cdEnqueue
    /* 1DF8 8006A5F8 C8C844AC */   sw        $a0, %lo(_mcDataLoad)($v0)
    /* 1DFC 8006A5FC 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E00 8006A600 C4C802A2 */  sb         $v0, %lo(_diskState)($s0)
  .L8006A604:
    /* 1E04 8006A604 0E80023C */  lui        $v0, %hi(_mcDataLoad)
    /* 1E08 8006A608 C8C8448C */  lw         $a0, %lo(_mcDataLoad)($v0)
    /* 1E0C 8006A60C 00000000 */  nop
    /* 1E10 8006A610 00008384 */  lh         $v1, 0x0($a0)
    /* 1E14 8006A614 04000224 */  addiu      $v0, $zero, 0x4
    /* 1E18 8006A618 2B006214 */  bne        $v1, $v0, .L8006A6C8
    /* 1E1C 8006A61C 21100000 */   addu      $v0, $zero, $zero
    /* 1E20 8006A620 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 1E24 8006A624 21800000 */   addu      $s0, $zero, $zero
    /* 1E28 8006A628 250B010C */  jal        vs_main_enableReset
    /* 1E2C 8006A62C 21200000 */   addu      $a0, $zero, $zero
    /* 1E30 8006A630 5D9A000C */  jal        EnterCriticalSection
    /* 1E34 8006A634 00000000 */   nop
    /* 1E38 8006A638 0780023C */  lui        $v0, %hi(_eventSpecs)
    /* 1E3C 8006A63C 94285224 */  addiu      $s2, $v0, %lo(_eventSpecs)
    /* 1E40 8006A640 0E80023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 1E44 8006A644 98EA5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
  .L8006A648:
    /* 1E48 8006A648 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 1E4C 8006A64C 04000232 */  andi       $v0, $s0, 0x4
    /* 1E50 8006A650 03004010 */  beqz       $v0, .L8006A660
    /* 1E54 8006A654 01008434 */   ori       $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 1E58 8006A658 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 1E5C 8006A65C 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
  .L8006A660:
    /* 1E60 8006A660 00200624 */  addiu      $a2, $zero, 0x2000
    /* 1E64 8006A664 03000232 */  andi       $v0, $s0, 0x3
    /* 1E68 8006A668 01001026 */  addiu      $s0, $s0, 0x1
    /* 1E6C 8006A66C 40100200 */  sll        $v0, $v0, 1
    /* 1E70 8006A670 21105200 */  addu       $v0, $v0, $s2
    /* 1E74 8006A674 00004594 */  lhu        $a1, 0x0($v0)
    /* 1E78 8006A678 359A000C */  jal        OpenEvent
    /* 1E7C 8006A67C 21380000 */   addu      $a3, $zero, $zero
    /* 1E80 8006A680 000022AE */  sw         $v0, 0x0($s1)
    /* 1E84 8006A684 0800022A */  slti       $v0, $s0, 0x8
    /* 1E88 8006A688 EFFF4014 */  bnez       $v0, .L8006A648
    /* 1E8C 8006A68C 04003126 */   addiu     $s1, $s1, 0x4
    /* 1E90 8006A690 619A000C */  jal        ExitCriticalSection
    /* 1E94 8006A694 21800000 */   addu      $s0, $zero, $zero
    /* 1E98 8006A698 0E80023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 1E9C 8006A69C 98EA5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
  .L8006A6A0:
    /* 1EA0 8006A6A0 0000248E */  lw         $a0, 0x0($s1)
    /* 1EA4 8006A6A4 04003126 */  addiu      $s1, $s1, 0x4
    /* 1EA8 8006A6A8 459A000C */  jal        EnableEvent
    /* 1EAC 8006A6AC 01001026 */   addiu     $s0, $s0, 0x1
    /* 1EB0 8006A6B0 0800022A */  slti       $v0, $s0, 0x8
    /* 1EB4 8006A6B4 FAFF4014 */  bnez       $v0, .L8006A6A0
    /* 1EB8 8006A6B8 01000224 */   addiu     $v0, $zero, 0x1
    /* 1EBC 8006A6BC B2A90108 */  j          .L8006A6C8
    /* 1EC0 8006A6C0 00000000 */   nop
  .L8006A6C4:
    /* 1EC4 8006A6C4 21100000 */  addu       $v0, $zero, $zero
  .L8006A6C8:
    /* 1EC8 8006A6C8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1ECC 8006A6CC 2000B28F */  lw         $s2, 0x20($sp)
    /* 1ED0 8006A6D0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1ED4 8006A6D4 1800B08F */  lw         $s0, 0x18($sp)
    /* 1ED8 8006A6D8 0800E003 */  jr         $ra
    /* 1EDC 8006A6DC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _initMemcard
