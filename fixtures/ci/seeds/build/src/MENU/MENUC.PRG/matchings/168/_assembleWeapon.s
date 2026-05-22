nonmatching _assembleWeapon, 0x144

glabel _assembleWeapon
    /* 988 80103188 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 98C 8010318C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 990 80103190 21808000 */  addu       $s0, $a0, $zero
    /* 994 80103194 1400B1AF */  sw         $s1, 0x14($sp)
    /* 998 80103198 2188A000 */  addu       $s1, $a1, $zero
    /* 99C 8010319C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 9A0 801031A0 1180023C */  lui        $v0, %hi(_combiningItem)
    /* 9A4 801031A4 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 9A8 801031A8 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 9AC 801031AC 81BC4490 */  lbu        $a0, %lo(_combiningItem)($v0)
    /* 9B0 801031B0 80026524 */  addiu      $a1, $v1, 0x280
    /* 9B4 801031B4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 9B8 801031B8 2800B6AF */  sw         $s6, 0x28($sp)
    /* 9BC 801031BC 2400B5AF */  sw         $s5, 0x24($sp)
    /* 9C0 801031C0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 9C4 801031C4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 9C8 801031C8 40110400 */  sll        $v0, $a0, 5
    /* 9CC 801031CC 21984300 */  addu       $s3, $v0, $v1
    /* 9D0 801031D0 40101000 */  sll        $v0, $s0, 1
    /* 9D4 801031D4 21105000 */  addu       $v0, $v0, $s0
    /* 9D8 801031D8 80100200 */  sll        $v0, $v0, 2
    /* 9DC 801031DC 23105000 */  subu       $v0, $v0, $s0
    /* 9E0 801031E0 80100200 */  sll        $v0, $v0, 2
    /* 9E4 801031E4 21B04500 */  addu       $s6, $v0, $a1
    /* 9E8 801031E8 00111100 */  sll        $v0, $s1, 4
    /* 9EC 801031EC 40056324 */  addiu      $v1, $v1, 0x540
    /* 9F0 801031F0 21A84300 */  addu       $s5, $v0, $v1
    /* 9F4 801031F4 0400B492 */  lbu        $s4, 0x4($s5)
    /* 9F8 801031F8 1B0C040C */  jal        _disassembleWeapon
    /* 9FC 801031FC 2190C000 */   addu      $s2, $a2, $zero
    /* A00 80103200 21200000 */  addu       $a0, $zero, $zero
    /* A04 80103204 01001026 */  addiu      $s0, $s0, 0x1
    /* A08 80103208 01003126 */  addiu      $s1, $s1, 0x1
    /* A0C 8010320C 010070A2 */  sb         $s0, 0x1($s3)
    /* A10 80103210 07008012 */  beqz       $s4, .L80103230
    /* A14 80103214 020071A2 */   sb        $s1, 0x2($s3)
  .L80103218:
    /* A18 80103218 21106402 */  addu       $v0, $s3, $a0
    /* A1C 8010321C 040052A0 */  sb         $s2, 0x4($v0)
    /* A20 80103220 01008424 */  addiu      $a0, $a0, 0x1
    /* A24 80103224 2A109400 */  slt        $v0, $a0, $s4
    /* A28 80103228 FBFF4014 */  bnez       $v0, .L80103218
    /* A2C 8010322C 03921200 */   sra       $s2, $s2, 8
  .L80103230:
    /* A30 80103230 1180023C */  lui        $v0, %hi(_combiningItem)
    /* A34 80103234 81BC4290 */  lbu        $v0, %lo(_combiningItem)($v0)
    /* A38 80103238 21200000 */  addu       $a0, $zero, $zero
    /* A3C 8010323C 01004524 */  addiu      $a1, $v0, 0x1
    /* A40 80103240 2A00C5A2 */  sb         $a1, 0x2A($s6)
    /* A44 80103244 11008012 */  beqz       $s4, .L8010328C
    /* A48 80103248 0C00A5A6 */   sh        $a1, 0xC($s5)
    /* A4C 8010324C 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* A50 80103250 68014624 */  addiu      $a2, $v0, %lo(vs_battle_inventory)
    /* A54 80103254 21106402 */  addu       $v0, $s3, $a0
  .L80103258:
    /* A58 80103258 04005290 */  lbu        $s2, 0x4($v0)
    /* A5C 8010325C 00000000 */  nop
    /* A60 80103260 06004012 */  beqz       $s2, .L8010327C
    /* A64 80103264 FFFF4326 */   addiu     $v1, $s2, -0x1
    /* A68 80103268 C0100300 */  sll        $v0, $v1, 3
    /* A6C 8010326C 23104300 */  subu       $v0, $v0, $v1
    /* A70 80103270 80100200 */  sll        $v0, $v0, 2
    /* A74 80103274 21104600 */  addu       $v0, $v0, $a2
    /* A78 80103278 D80845A4 */  sh         $a1, 0x8D8($v0)
  .L8010327C:
    /* A7C 8010327C 01008424 */  addiu      $a0, $a0, 0x1
    /* A80 80103280 2A109400 */  slt        $v0, $a0, $s4
    /* A84 80103284 F4FF4014 */  bnez       $v0, .L80103258
    /* A88 80103288 21106402 */   addu      $v0, $s3, $a0
  .L8010328C:
    /* A8C 8010328C 08006426 */  addiu      $a0, $s3, 0x8
    /* A90 80103290 E7000524 */  addiu      $a1, $zero, 0xE7
    /* A94 80103294 AD9B000C */  jal        memset
    /* A98 80103298 18000624 */   addiu     $a2, $zero, 0x18
    /* A9C 8010329C 2CFA030C */  jal        vs_mainMenu_rebuildInventory
    /* AA0 801032A0 21200000 */   addu      $a0, $zero, $zero
    /* AA4 801032A4 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* AA8 801032A8 2800B68F */  lw         $s6, 0x28($sp)
    /* AAC 801032AC 2400B58F */  lw         $s5, 0x24($sp)
    /* AB0 801032B0 2000B48F */  lw         $s4, 0x20($sp)
    /* AB4 801032B4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* AB8 801032B8 1800B28F */  lw         $s2, 0x18($sp)
    /* ABC 801032BC 1400B18F */  lw         $s1, 0x14($sp)
    /* AC0 801032C0 1000B08F */  lw         $s0, 0x10($sp)
    /* AC4 801032C4 0800E003 */  jr         $ra
    /* AC8 801032C8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _assembleWeapon
