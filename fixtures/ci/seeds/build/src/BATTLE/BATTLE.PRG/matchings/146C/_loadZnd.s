nonmatching _loadZnd, 0xE8

glabel _loadZnd
    /* 20608 80088E08 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2060C 80088E0C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 20610 80088E10 21888000 */  addu       $s1, $a0, $zero
    /* 20614 80088E14 0580023C */  lui        $v0, %hi(vs_main_zndFiles)
    /* 20618 80088E18 CCF44224 */  addiu      $v0, $v0, %lo(vs_main_zndFiles)
    /* 2061C 80088E1C C0181100 */  sll        $v1, $s1, 3
    /* 20620 80088E20 21186200 */  addu       $v1, $v1, $v0
    /* 20624 80088E24 2000BFAF */  sw         $ra, 0x20($sp)
    /* 20628 80088E28 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2062C 80088E2C 0000628C */  lw         $v0, 0x0($v1)
    /* 20630 80088E30 00000000 */  nop
    /* 20634 80088E34 1000A2AF */  sw         $v0, 0x10($sp)
    /* 20638 80088E38 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 2063C 80088E3C 80185024 */  addiu      $s0, $v0, %lo(_zoneContext)
    /* 20640 80088E40 0400628C */  lw         $v0, 0x4($v1)
    /* 20644 80088E44 2000038E */  lw         $v1, 0x20($s0)
    /* 20648 80088E48 00000000 */  nop
    /* 2064C 80088E4C 04006010 */  beqz       $v1, .L80088E60
    /* 20650 80088E50 1400A2AF */   sw        $v0, 0x14($sp)
    /* 20654 80088E54 87000424 */  addiu      $a0, $zero, 0x87
    /* 20658 80088E58 2624010C */  jal        vs_main_nop9
    /* 2065C 80088E5C 21280000 */   addu      $a1, $zero, $zero
  .L80088E60:
    /* 20660 80088E60 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 20664 80088E64 1000A427 */   addiu     $a0, $sp, 0x10
    /* 20668 80088E68 2400038E */  lw         $v1, 0x24($s0)
    /* 2066C 80088E6C 00000000 */  nop
    /* 20670 80088E70 04006010 */  beqz       $v1, .L80088E84
    /* 20674 80088E74 200002AE */   sw        $v0, 0x20($s0)
    /* 20678 80088E78 88000424 */  addiu      $a0, $zero, 0x88
    /* 2067C 80088E7C 2624010C */  jal        vs_main_nop9
    /* 20680 80088E80 21280000 */   addu      $a1, $zero, $zero
  .L80088E84:
    /* 20684 80088E84 1400A48F */  lw         $a0, 0x14($sp)
    /* 20688 80088E88 8F0F010C */  jal        vs_main_allocHeapR
    /* 2068C 80088E8C 00000000 */   nop
    /* 20690 80088E90 2000048E */  lw         $a0, 0x20($s0)
    /* 20694 80088E94 21284000 */  addu       $a1, $v0, $zero
    /* 20698 80088E98 FD12010C */  jal        vs_main_cdEnqueuePriority
    /* 2069C 80088E9C 240005AE */   sw        $a1, 0x24($s0)
    /* 206A0 80088EA0 3000028E */  lw         $v0, 0x30($s0)
    /* 206A4 80088EA4 00000000 */  nop
    /* 206A8 80088EA8 0C004010 */  beqz       $v0, .L80088EDC
    /* 206AC 80088EAC 0580023C */   lui       $v0, %hi(D_8004FCCC)
    /* 206B0 80088EB0 CCFC4224 */  addiu      $v0, $v0, %lo(D_8004FCCC)
    /* 206B4 80088EB4 21102202 */  addu       $v0, $s1, $v0
    /* 206B8 80088EB8 00005090 */  lbu        $s0, 0x0($v0)
    /* 206BC 80088EBC 3914010C */  jal        vs_main_getCurrentMusicId
    /* 206C0 80088EC0 00000000 */   nop
    /* 206C4 80088EC4 05005010 */  beq        $v0, $s0, .L80088EDC
    /* 206C8 80088EC8 0680023C */   lui       $v0, %hi(vs_main_soundData)
    /* 206CC 80088ECC 38E0448C */  lw         $a0, %lo(vs_main_soundData)($v0)
    /* 206D0 80088ED0 21280000 */  addu       $a1, $zero, $zero
    /* 206D4 80088ED4 4B15010C */  jal        func_8004552C
    /* 206D8 80088ED8 78000624 */   addiu     $a2, $zero, 0x78
  .L80088EDC:
    /* 206DC 80088EDC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 206E0 80088EE0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 206E4 80088EE4 1800B08F */  lw         $s0, 0x18($sp)
    /* 206E8 80088EE8 0800E003 */  jr         $ra
    /* 206EC 80088EEC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _loadZnd
