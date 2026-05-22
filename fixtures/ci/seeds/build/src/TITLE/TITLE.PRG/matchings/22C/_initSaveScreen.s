nonmatching _initSaveScreen, 0xBC

glabel _initSaveScreen
    /* 5DD0 8006E5D0 58FFBD27 */  addiu      $sp, $sp, -0xA8
    /* 5DD4 8006E5D4 1800A427 */  addiu      $a0, $sp, 0x18
    /* 5DD8 8006E5D8 40010524 */  addiu      $a1, $zero, 0x140
    /* 5DDC 8006E5DC 21300000 */  addu       $a2, $zero, $zero
    /* 5DE0 8006E5E0 2138A000 */  addu       $a3, $a1, $zero
    /* 5DE4 8006E5E4 0E80023C */  lui        $v0, %hi(_frameBuf)
    /* 5DE8 8006E5E8 9800B0AF */  sw         $s0, 0x98($sp)
    /* 5DEC 8006E5EC F0001024 */  addiu      $s0, $zero, 0xF0
    /* 5DF0 8006E5F0 A000BFAF */  sw         $ra, 0xA0($sp)
    /* 5DF4 8006E5F4 9C00B1AF */  sw         $s1, 0x9C($sp)
    /* 5DF8 8006E5F8 76ED40A0 */  sb         $zero, %lo(_frameBuf)($v0)
    /* 5DFC 8006E5FC 0DAD000C */  jal        SetDefDispEnv
    /* 5E00 8006E600 1000B0AF */   sw        $s0, 0x10($sp)
    /* 5E04 8006E604 3000B127 */  addiu      $s1, $sp, 0x30
    /* 5E08 8006E608 21202002 */  addu       $a0, $s1, $zero
    /* 5E0C 8006E60C 21280000 */  addu       $a1, $zero, $zero
    /* 5E10 8006E610 2130A000 */  addu       $a2, $a1, $zero
    /* 5E14 8006E614 40010724 */  addiu      $a3, $zero, 0x140
    /* 5E18 8006E618 DDAC000C */  jal        SetDefDrawEnv
    /* 5E1C 8006E61C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 5E20 8006E620 1800A427 */  addiu      $a0, $sp, 0x18
    /* 5E24 8006E624 08000224 */  addiu      $v0, $zero, 0x8
    /* 5E28 8006E628 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 5E2C 8006E62C E0000224 */  addiu      $v0, $zero, 0xE0
    /* 5E30 8006E630 A0A3000C */  jal        PutDispEnv
    /* 5E34 8006E634 2600A2A7 */   sh        $v0, 0x26($sp)
    /* 5E38 8006E638 2DA3000C */  jal        PutDrawEnv
    /* 5E3C 8006E63C 21202002 */   addu      $a0, $s1, $zero
    /* 5E40 8006E640 9000A427 */  addiu      $a0, $sp, 0x90
    /* 5E44 8006E644 21280000 */  addu       $a1, $zero, $zero
    /* 5E48 8006E648 2130A000 */  addu       $a2, $a1, $zero
    /* 5E4C 8006E64C 2138A000 */  addu       $a3, $a1, $zero
    /* 5E50 8006E650 80020224 */  addiu      $v0, $zero, 0x280
    /* 5E54 8006E654 9000A0A7 */  sh         $zero, 0x90($sp)
    /* 5E58 8006E658 9200A0A7 */  sh         $zero, 0x92($sp)
    /* 5E5C 8006E65C 9400A2A7 */  sh         $v0, 0x94($sp)
    /* 5E60 8006E660 F5A1000C */  jal        ClearImage
    /* 5E64 8006E664 9600B0A7 */   sh        $s0, 0x96($sp)
    /* 5E68 8006E668 94A1000C */  jal        DrawSync
    /* 5E6C 8006E66C 21200000 */   addu      $a0, $zero, $zero
    /* 5E70 8006E670 6EA1000C */  jal        SetDispMask
    /* 5E74 8006E674 01000424 */   addiu     $a0, $zero, 0x1
    /* 5E78 8006E678 A000BF8F */  lw         $ra, 0xA0($sp)
    /* 5E7C 8006E67C 9C00B18F */  lw         $s1, 0x9C($sp)
    /* 5E80 8006E680 9800B08F */  lw         $s0, 0x98($sp)
    /* 5E84 8006E684 0800E003 */  jr         $ra
    /* 5E88 8006E688 A800BD27 */   addiu     $sp, $sp, 0xA8
endlabel _initSaveScreen
