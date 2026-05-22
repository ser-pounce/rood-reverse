nonmatching func_8006FA20, 0x128

glabel func_8006FA20
    /* 7220 8006FA20 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7224 8006FA24 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7228 8006FA28 0F80103C */  lui        $s0, %hi(D_800F19CC)
    /* 722C 8006FA2C CC19048E */  lw         $a0, %lo(D_800F19CC)($s0)
    /* 7230 8006FA30 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7234 8006FA34 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7238 8006FA38 08008294 */  lhu        $v0, 0x8($a0)
    /* 723C 8006FA3C 00000000 */  nop
    /* 7240 8006FA40 32004010 */  beqz       $v0, .L8006FB0C
    /* 7244 8006FA44 0580023C */   lui       $v0, %hi(vs_main_skills)
    /* 7248 8006FA48 08008394 */  lhu        $v1, 0x8($a0)
    /* 724C 8006FA4C DCB95124 */  addiu      $s1, $v0, %lo(vs_main_skills)
    /* 7250 8006FA50 40100300 */  sll        $v0, $v1, 1
    /* 7254 8006FA54 21104300 */  addu       $v0, $v0, $v1
    /* 7258 8006FA58 80100200 */  sll        $v0, $v0, 2
    /* 725C 8006FA5C 21104300 */  addu       $v0, $v0, $v1
    /* 7260 8006FA60 80100200 */  sll        $v0, $v0, 2
    /* 7264 8006FA64 21105100 */  addu       $v0, $v0, $s1
    /* 7268 8006FA68 0C00428C */  lw         $v0, 0xC($v0)
    /* 726C 8006FA6C 00000000 */  nop
    /* 7270 8006FA70 C2130200 */  srl        $v0, $v0, 15
    /* 7274 8006FA74 01004230 */  andi       $v0, $v0, 0x1
    /* 7278 8006FA78 24004014 */  bnez       $v0, .L8006FB0C
    /* 727C 8006FA7C 00000000 */   nop
    /* 7280 8006FA80 4C00828C */  lw         $v0, 0x4C($a0)
    /* 7284 8006FA84 00000000 */  nop
    /* 7288 8006FA88 20004014 */  bnez       $v0, .L8006FB0C
    /* 728C 8006FA8C 00000000 */   nop
    /* 7290 8006FA90 072C8290 */  lbu        $v0, 0x2C07($a0)
    /* 7294 8006FA94 00000000 */  nop
    /* 7298 8006FA98 1C004014 */  bnez       $v0, .L8006FB0C
    /* 729C 8006FA9C 00000000 */   nop
    /* 72A0 8006FAA0 0C008290 */  lbu        $v0, 0xC($a0)
    /* 72A4 8006FAA4 00000000 */  nop
    /* 72A8 8006FAA8 18004014 */  bnez       $v0, .L8006FB0C
    /* 72AC 8006FAAC 0F80033C */   lui       $v1, %hi(_cameraMode)
    /* 72B0 8006FAB0 0E000224 */  addiu      $v0, $zero, 0xE
    /* 72B4 8006FAB4 E7B0010C */  jal        func_8006C39C
    /* 72B8 8006FAB8 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* 72BC 8006FABC CC19028E */  lw         $v0, %lo(D_800F19CC)($s0)
    /* 72C0 8006FAC0 0C000424 */  addiu      $a0, $zero, 0xC
    /* 72C4 8006FAC4 08004594 */  lhu        $a1, 0x8($v0)
    /* 72C8 8006FAC8 AE2C030C */  jal        vs_battle_displaySceneMessage
    /* 72CC 8006FACC 01000624 */   addiu     $a2, $zero, 0x1
    /* 72D0 8006FAD0 CC19028E */  lw         $v0, %lo(D_800F19CC)($s0)
    /* 72D4 8006FAD4 00000000 */  nop
    /* 72D8 8006FAD8 08004394 */  lhu        $v1, 0x8($v0)
    /* 72DC 8006FADC 00000000 */  nop
    /* 72E0 8006FAE0 40100300 */  sll        $v0, $v1, 1
    /* 72E4 8006FAE4 21104300 */  addu       $v0, $v0, $v1
    /* 72E8 8006FAE8 80100200 */  sll        $v0, $v0, 2
    /* 72EC 8006FAEC 21104300 */  addu       $v0, $v0, $v1
    /* 72F0 8006FAF0 80100200 */  sll        $v0, $v0, 2
    /* 72F4 8006FAF4 21105100 */  addu       $v0, $v0, $s1
    /* 72F8 8006FAF8 0C00438C */  lw         $v1, 0xC($v0)
    /* 72FC 8006FAFC 00000000 */  nop
    /* 7300 8006FB00 00806334 */  ori        $v1, $v1, 0x8000
    /* 7304 8006FB04 CDBE0108 */  j          .L8006FB34
    /* 7308 8006FB08 0C0043AC */   sw        $v1, 0xC($v0)
  .L8006FB0C:
    /* 730C 8006FB0C D8BD010C */  jal        _isArtOrAbilityUnlocked
    /* 7310 8006FB10 00000000 */   nop
    /* 7314 8006FB14 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 7318 8006FB18 0E000424 */  addiu      $a0, $zero, 0xE
    /* 731C 8006FB1C F01864AC */  sw         $a0, %lo(_cameraMode)($v1)
    /* 7320 8006FB20 E7B0010C */  jal        func_8006C39C
    /* 7324 8006FB24 21804000 */   addu      $s0, $v0, $zero
    /* 7328 8006FB28 02241000 */  srl        $a0, $s0, 16
    /* 732C 8006FB2C 822C030C */  jal        func_800CB208
    /* 7330 8006FB30 FFFF0532 */   andi      $a1, $s0, 0xFFFF
  .L8006FB34:
    /* 7334 8006FB34 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7338 8006FB38 1400B18F */  lw         $s1, 0x14($sp)
    /* 733C 8006FB3C 1000B08F */  lw         $s0, 0x10($sp)
    /* 7340 8006FB40 0800E003 */  jr         $ra
    /* 7344 8006FB44 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006FA20
