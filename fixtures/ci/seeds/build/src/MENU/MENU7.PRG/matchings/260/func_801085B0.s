nonmatching func_801085B0, 0x12C

glabel func_801085B0
    /* 5DB0 801085B0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5DB4 801085B4 01000224 */  addiu      $v0, $zero, 0x1
    /* 5DB8 801085B8 2800BFAF */  sw         $ra, 0x28($sp)
    /* 5DBC 801085BC 2400B1AF */  sw         $s1, 0x24($sp)
    /* 5DC0 801085C0 2D008210 */  beq        $a0, $v0, .L80108678
    /* 5DC4 801085C4 2000B0AF */   sw        $s0, 0x20($sp)
    /* 5DC8 801085C8 02008228 */  slti       $v0, $a0, 0x2
    /* 5DCC 801085CC 05004010 */  beqz       $v0, .L801085E4
    /* 5DD0 801085D0 02000224 */   addiu     $v0, $zero, 0x2
    /* 5DD4 801085D4 07008010 */  beqz       $a0, .L801085F4
    /* 5DD8 801085D8 21100000 */   addu      $v0, $zero, $zero
    /* 5DDC 801085DC B2210408 */  j          .L801086C8
    /* 5DE0 801085E0 00000000 */   nop
  .L801085E4:
    /* 5DE4 801085E4 27008210 */  beq        $a0, $v0, .L80108684
    /* 5DE8 801085E8 21100000 */   addu      $v0, $zero, $zero
    /* 5DEC 801085EC B2210408 */  j          .L801086C8
    /* 5DF0 801085F0 00000000 */   nop
  .L801085F4:
    /* 5DF4 801085F4 1180023C */  lui        $v0, %hi(_opmcimgSlot)
    /* 5DF8 801085F8 04AB448C */  lw         $a0, %lo(_opmcimgSlot)($v0)
    /* 5DFC 801085FC 00000000 */  nop
    /* 5E00 80108600 00008384 */  lh         $v1, 0x0($a0)
    /* 5E04 80108604 04000224 */  addiu      $v0, $zero, 0x4
    /* 5E08 80108608 2E006214 */  bne        $v1, $v0, .L801086C4
    /* 5E0C 8010860C 00000000 */   nop
    /* 5E10 80108610 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 5E14 80108614 0680113C */   lui       $s1, %hi(vs_main_gametime)
    /* 5E18 80108618 01000424 */  addiu      $a0, $zero, 0x1
    /* 5E1C 8010861C 1180103C */  lui        $s0, %hi(_opMcImg)
    /* 5E20 80108620 08AB028E */  lw         $v0, %lo(_opMcImg)($s0)
    /* 5E24 80108624 1180033C */  lui        $v1, %hi(_spmcimg)
    /* 5E28 80108628 74102926 */  addiu      $t1, $s1, %lo(vs_main_gametime)
    /* 5E2C 8010862C 03002689 */  lwl        $a2, 0x3($t1)
    /* 5E30 80108630 00002699 */  lwr        $a2, 0x0($t1)
    /* 5E34 80108634 00000000 */  nop
    /* 5E38 80108638 1B00A6AB */  swl        $a2, 0x1B($sp)
    /* 5E3C 8010863C 1800A6BB */  swr        $a2, 0x18($sp)
    /* 5E40 80108640 00A44224 */  addiu      $v0, $v0, -0x5C00
    /* 5E44 80108644 8C0D040C */  jal        _applyLoadedSaveFile
    /* 5E48 80108648 F0AD62AC */   sw        $v0, %lo(_spmcimg)($v1)
    /* 5E4C 8010864C 08AB048E */  lw         $a0, %lo(_opMcImg)($s0)
    /* 5E50 80108650 74102926 */  addiu      $t1, $s1, %lo(vs_main_gametime)
    /* 5E54 80108654 1B00A68B */  lwl        $a2, 0x1B($sp)
    /* 5E58 80108658 1800A69B */  lwr        $a2, 0x18($sp)
    /* 5E5C 8010865C 00000000 */  nop
    /* 5E60 80108660 030026A9 */  swl        $a2, 0x3($t1)
    /* 5E64 80108664 000026B9 */  swr        $a2, 0x0($t1)
    /* 5E68 80108668 180F010C */  jal        vs_main_freeHeapR
    /* 5E6C 8010866C 00000000 */   nop
    /* 5E70 80108670 B2210408 */  j          .L801086C8
    /* 5E74 80108674 01000224 */   addiu     $v0, $zero, 0x1
  .L80108678:
    /* 5E78 80108678 0100023C */  lui        $v0, (0x14CD7 >> 16)
    /* 5E7C 8010867C A3210408 */  j          .L8010868C
    /* 5E80 80108680 D74C4234 */   ori       $v0, $v0, (0x14CD7 & 0xFFFF)
  .L80108684:
    /* 5E84 80108684 0100023C */  lui        $v0, (0x14CDB >> 16)
    /* 5E88 80108688 DB4C4234 */  ori        $v0, $v0, (0x14CDB & 0xFFFF)
  .L8010868C:
    /* 5E8C 8010868C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 5E90 80108690 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5E94 80108694 00200224 */  addiu      $v0, $zero, 0x2000
    /* 5E98 80108698 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 5E9C 8010869C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 5EA0 801086A0 005C0424 */  addiu      $a0, $zero, 0x5C00
    /* 5EA4 801086A4 1180103C */  lui        $s0, %hi(_opmcimgSlot)
    /* 5EA8 801086A8 8F0F010C */  jal        vs_main_allocHeapR
    /* 5EAC 801086AC 04AB02AE */   sw        $v0, %lo(_opmcimgSlot)($s0)
    /* 5EB0 801086B0 21284000 */  addu       $a1, $v0, $zero
    /* 5EB4 801086B4 04AB048E */  lw         $a0, %lo(_opmcimgSlot)($s0)
    /* 5EB8 801086B8 1180023C */  lui        $v0, %hi(_opMcImg)
    /* 5EBC 801086BC F112010C */  jal        vs_main_cdEnqueue
    /* 5EC0 801086C0 08AB45AC */   sw        $a1, %lo(_opMcImg)($v0)
  .L801086C4:
    /* 5EC4 801086C4 21100000 */  addu       $v0, $zero, $zero
  .L801086C8:
    /* 5EC8 801086C8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 5ECC 801086CC 2400B18F */  lw         $s1, 0x24($sp)
    /* 5ED0 801086D0 2000B08F */  lw         $s0, 0x20($sp)
    /* 5ED4 801086D4 0800E003 */  jr         $ra
    /* 5ED8 801086D8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_801085B0
