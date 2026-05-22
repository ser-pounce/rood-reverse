nonmatching _initMenu, 0x140

glabel _initMenu
    /* 76C4 8006FEC4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 76C8 8006FEC8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 76CC 8006FECC 21808000 */  addu       $s0, $a0, $zero
    /* 76D0 8006FED0 09000324 */  addiu      $v1, $zero, 0x9
    /* 76D4 8006FED4 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 76D8 8006FED8 F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 76DC 8006FEDC 48004224 */  addiu      $v0, $v0, 0x48
    /* 76E0 8006FEE0 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 76E4 8006FEE4 2800B4AF */  sw         $s4, 0x28($sp)
    /* 76E8 8006FEE8 2400B3AF */  sw         $s3, 0x24($sp)
    /* 76EC 8006FEEC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 76F0 8006FEF0 1C00B1AF */  sw         $s1, 0x1C($sp)
  .L8006FEF4:
    /* 76F4 8006FEF4 000040A0 */  sb         $zero, 0x0($v0)
    /* 76F8 8006FEF8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 76FC 8006FEFC FDFF6104 */  bgez       $v1, .L8006FEF4
    /* 7700 8006FF00 F8FF4224 */   addiu     $v0, $v0, -0x8
    /* 7704 8006FF04 21200002 */  addu       $a0, $s0, $zero
    /* 7708 8006FF08 0DBF010C */  jal        func_8006FC34
    /* 770C 8006FF0C 40000524 */   addiu     $a1, $zero, 0x40
    /* 7710 8006FF10 01000426 */  addiu      $a0, $s0, 0x1
    /* 7714 8006FF14 03008430 */  andi       $a0, $a0, 0x3
    /* 7718 8006FF18 0DBF010C */  jal        func_8006FC34
    /* 771C 8006FF1C 60000524 */   addiu     $a1, $zero, 0x60
    /* 7720 8006FF20 03000426 */  addiu      $a0, $s0, 0x3
    /* 7724 8006FF24 03008430 */  andi       $a0, $a0, 0x3
    /* 7728 8006FF28 0DBF010C */  jal        func_8006FC34
    /* 772C 8006FF2C 20000524 */   addiu     $a1, $zero, 0x20
    /* 7730 8006FF30 0200043C */  lui        $a0, (0x22380 >> 16)
    /* 7734 8006FF34 B10F010C */  jal        vs_main_allocHeap
    /* 7738 8006FF38 80238434 */   ori       $a0, $a0, (0x22380 & 0xFFFF)
    /* 773C 8006FF3C 21A04000 */  addu       $s4, $v0, $zero
    /* 7740 8006FF40 00A01034 */  ori        $s0, $zero, 0xA000
    /* 7744 8006FF44 21809002 */  addu       $s0, $s4, $s0
    /* 7748 8006FF48 1000A427 */  addiu      $a0, $sp, 0x10
    /* 774C 8006FF4C 21280002 */  addu       $a1, $s0, $zero
    /* 7750 8006FF50 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 7754 8006FF54 C0011324 */  addiu      $s3, $zero, 0x1C0
    /* 7758 8006FF58 A0001224 */  addiu      $s2, $zero, 0xA0
    /* 775C 8006FF5C 40001124 */  addiu      $s1, $zero, 0x40
    /* 7760 8006FF60 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 7764 8006FF64 1200B3A7 */  sh         $s3, 0x12($sp)
    /* 7768 8006FF68 1400B2A7 */  sh         $s2, 0x14($sp)
    /* 776C 8006FF6C 57A2000C */  jal        StoreImage
    /* 7770 8006FF70 1600B1A7 */   sh        $s1, 0x16($sp)
    /* 7774 8006FF74 94A1000C */  jal        DrawSync
    /* 7778 8006FF78 21200000 */   addu      $a0, $zero, $zero
    /* 777C 8006FF7C 00501026 */  addiu      $s0, $s0, 0x5000
    /* 7780 8006FF80 1000A427 */  addiu      $a0, $sp, 0x10
    /* 7784 8006FF84 21280002 */  addu       $a1, $s0, $zero
    /* 7788 8006FF88 60010224 */  addiu      $v0, $zero, 0x160
    /* 778C 8006FF8C 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 7790 8006FF90 1200B3A7 */  sh         $s3, 0x12($sp)
    /* 7794 8006FF94 1400B2A7 */  sh         $s2, 0x14($sp)
    /* 7798 8006FF98 57A2000C */  jal        StoreImage
    /* 779C 8006FF9C 1600B1A7 */   sh        $s1, 0x16($sp)
    /* 77A0 8006FFA0 94A1000C */  jal        DrawSync
    /* 77A4 8006FFA4 21200000 */   addu      $a0, $zero, $zero
    /* 77A8 8006FFA8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 77AC 8006FFAC 00F00534 */  ori        $a1, $zero, 0xF000
    /* 77B0 8006FFB0 21280502 */  addu       $a1, $s0, $a1
    /* 77B4 8006FFB4 A6020224 */  addiu      $v0, $zero, 0x2A6
    /* 77B8 8006FFB8 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 77BC 8006FFBC 78010224 */  addiu      $v0, $zero, 0x178
    /* 77C0 8006FFC0 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 77C4 8006FFC4 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 77C8 8006FFC8 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 77CC 8006FFCC 18000224 */  addiu      $v0, $zero, 0x18
    /* 77D0 8006FFD0 57A2000C */  jal        StoreImage
    /* 77D4 8006FFD4 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 77D8 8006FFD8 94A1000C */  jal        DrawSync
    /* 77DC 8006FFDC 21200000 */   addu      $a0, $zero, $zero
    /* 77E0 8006FFE0 21108002 */  addu       $v0, $s4, $zero
    /* 77E4 8006FFE4 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 77E8 8006FFE8 2800B48F */  lw         $s4, 0x28($sp)
    /* 77EC 8006FFEC 2400B38F */  lw         $s3, 0x24($sp)
    /* 77F0 8006FFF0 2000B28F */  lw         $s2, 0x20($sp)
    /* 77F4 8006FFF4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 77F8 8006FFF8 1800B08F */  lw         $s0, 0x18($sp)
    /* 77FC 8006FFFC 0800E003 */  jr         $ra
    /* 7800 80070000 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _initMenu
