nonmatching vs_mainMenu_drawClassAffinityType, 0x138

glabel vs_mainMenu_drawClassAffinityType
    /* 23D4 800FBBD4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 23D8 800FBBD8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23DC 800FBBDC 21808000 */  addu       $s0, $a0, $zero
    /* 23E0 800FBBE0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 23E4 800FBBE4 01001124 */  addiu      $s1, $zero, 0x1
    /* 23E8 800FBBE8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 23EC 800FBBEC 0C000012 */  beqz       $s0, .L800FBC20
    /* 23F0 800FBBF0 1800B2AF */   sw        $s2, 0x18($sp)
    /* 23F4 800FBBF4 0400001A */  blez       $s0, .L800FBC08
    /* 23F8 800FBBF8 1080033C */   lui       $v1, %hi(D_801024B9)
    /* 23FC 800FBBFC 03000224 */  addiu      $v0, $zero, 0x3
    /* 2400 800FBC00 E3EE030C */  jal        func_800FBB8C
    /* 2404 800FBC04 B92462A0 */   sb        $v0, %lo(D_801024B9)($v1)
  .L800FBC08:
    /* 2408 800FBC08 1080023C */  lui        $v0, %hi(D_801020F4)
    /* 240C 800FBC0C 1080033C */  lui        $v1, %hi(D_801020F8)
    /* 2410 800FBC10 F42050AC */  sw         $s0, %lo(D_801020F4)($v0)
    /* 2414 800FBC14 0A000224 */  addiu      $v0, $zero, 0xA
    /* 2418 800FBC18 3DEF0308 */  j          .L800FBCF4
    /* 241C 800FBC1C F82062A0 */   sb        $v0, %lo(D_801020F8)($v1)
  .L800FBC20:
    /* 2420 800FBC20 1080123C */  lui        $s2, %hi(D_801024B9)
    /* 2424 800FBC24 1080023C */  lui        $v0, %hi(D_801020F4)
    /* 2428 800FBC28 F420428C */  lw         $v0, %lo(D_801020F4)($v0)
    /* 242C 800FBC2C B9245092 */  lbu        $s0, %lo(D_801024B9)($s2)
    /* 2430 800FBC30 1F004018 */  blez       $v0, .L800FBCB0
    /* 2434 800FBC34 0F80023C */   lui       $v0, %hi(vs_battle_rowAnimationSteps)
    /* 2438 800FBC38 1080043C */  lui        $a0, %hi(D_801020F8)
    /* 243C 800FBC3C F8208390 */  lbu        $v1, %lo(D_801020F8)($a0)
    /* 2440 800FBC40 C8BB4224 */  addiu      $v0, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 2444 800FBC44 21106200 */  addu       $v0, $v1, $v0
    /* 2448 800FBC48 00004290 */  lbu        $v0, 0x0($v0)
    /* 244C 800FBC4C 04006010 */  beqz       $v1, .L800FBC60
    /* 2450 800FBC50 23880200 */   negu      $s1, $v0
    /* 2454 800FBC54 FFFF6224 */  addiu      $v0, $v1, -0x1
    /* 2458 800FBC58 37EF0308 */  j          .L800FBCDC
    /* 245C 800FBC5C F82082A0 */   sb        $v0, %lo(D_801020F8)($a0)
  .L800FBC60:
    /* 2460 800FBC60 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 2464 800FBC64 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 2468 800FBC68 00000000 */  nop
    /* 246C 800FBC6C 80004230 */  andi       $v0, $v0, 0x80
    /* 2470 800FBC70 1A004010 */  beqz       $v0, .L800FBCDC
    /* 2474 800FBC74 00000000 */   nop
    /* 2478 800FBC78 D9EE030C */  jal        func_800FBB64
    /* 247C 800FBC7C 21200002 */   addu      $a0, $s0, $zero
    /* 2480 800FBC80 B9244392 */  lbu        $v1, %lo(D_801024B9)($s2)
    /* 2484 800FBC84 21804000 */  addu       $s0, $v0, $zero
    /* 2488 800FBC88 05000312 */  beq        $s0, $v1, .L800FBCA0
    /* 248C 800FBC8C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 2490 800FBC90 6216010C */  jal        vs_main_playSfxDefault
    /* 2494 800FBC94 0E000524 */   addiu     $a1, $zero, 0xE
    /* 2498 800FBC98 37EF0308 */  j          .L800FBCDC
    /* 249C 800FBC9C 00000000 */   nop
  .L800FBCA0:
    /* 24A0 800FBCA0 B800030C */  jal        vs_battle_playInvalidSfx
    /* 24A4 800FBCA4 00000000 */   nop
    /* 24A8 800FBCA8 37EF0308 */  j          .L800FBCDC
    /* 24AC 800FBCAC 00000000 */   nop
  .L800FBCB0:
    /* 24B0 800FBCB0 1080033C */  lui        $v1, %hi(D_801020F8)
    /* 24B4 800FBCB4 F8206290 */  lbu        $v0, %lo(D_801020F8)($v1)
    /* 24B8 800FBCB8 00000000 */  nop
    /* 24BC 800FBCBC 07004010 */  beqz       $v0, .L800FBCDC
    /* 24C0 800FBCC0 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 24C4 800FBCC4 F82062A0 */  sb         $v0, %lo(D_801020F8)($v1)
    /* 24C8 800FBCC8 FF004330 */  andi       $v1, $v0, 0xFF
    /* 24CC 800FBCCC F6FF6324 */  addiu      $v1, $v1, -0xA
    /* 24D0 800FBCD0 40100300 */  sll        $v0, $v1, 1
    /* 24D4 800FBCD4 21104300 */  addu       $v0, $v0, $v1
    /* 24D8 800FBCD8 C0880200 */  sll        $s1, $v0, 3
  .L800FBCDC:
    /* 24DC 800FBCDC 0400201E */  bgtz       $s1, .L800FBCF0
    /* 24E0 800FBCE0 1080023C */   lui       $v0, %hi(D_801024B9)
    /* 24E4 800FBCE4 F2EC030C */  jal        func_800FB3C8
    /* 24E8 800FBCE8 21202002 */   addu      $a0, $s1, $zero
    /* 24EC 800FBCEC 1080023C */  lui        $v0, %hi(D_801024B9)
  .L800FBCF0:
    /* 24F0 800FBCF0 B92450A0 */  sb         $s0, %lo(D_801024B9)($v0)
  .L800FBCF4:
    /* 24F4 800FBCF4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 24F8 800FBCF8 1800B28F */  lw         $s2, 0x18($sp)
    /* 24FC 800FBCFC 1400B18F */  lw         $s1, 0x14($sp)
    /* 2500 800FBD00 1000B08F */  lw         $s0, 0x10($sp)
    /* 2504 800FBD04 0800E003 */  jr         $ra
    /* 2508 800FBD08 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_mainMenu_drawClassAffinityType
