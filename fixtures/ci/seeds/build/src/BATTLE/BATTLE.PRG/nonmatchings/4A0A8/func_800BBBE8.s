nonmatching func_800BBBE8, 0x1F4

glabel func_800BBBE8
    /* 533E8 800BBBE8 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 533EC 800BBBEC 8C020424 */  addiu      $a0, $zero, 0x28C
    /* 533F0 800BBBF0 5000BFAF */  sw         $ra, 0x50($sp)
    /* 533F4 800BBBF4 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* 533F8 800BBBF8 4800B2AF */  sw         $s2, 0x48($sp)
    /* 533FC 800BBBFC 4400B1AF */  sw         $s1, 0x44($sp)
    /* 53400 800BBC00 8F0F010C */  jal        vs_main_allocHeapR
    /* 53404 800BBC04 4000B0AF */   sw        $s0, 0x40($sp)
    /* 53408 800BBC08 2000B127 */  addiu      $s1, $sp, 0x20
    /* 5340C 800BBC0C 21202002 */  addu       $a0, $s1, $zero
    /* 53410 800BBC10 0F80103C */  lui        $s0, %hi(D_800F4BA4)
    /* 53414 800BBC14 A44B02AE */  sw         $v0, %lo(D_800F4BA4)($s0)
    /* 53418 800BBC18 0F80023C */  lui        $v0, %hi(D_800F4BA0)
    /* 5341C 800BBC1C FBEA010C */  jal        vs_battle_getCameraPosition
    /* 53420 800BBC20 A04B40A0 */   sb        $zero, %lo(D_800F4BA0)($v0)
    /* 53424 800BBC24 3000B227 */  addiu      $s2, $sp, 0x30
    /* 53428 800BBC28 10EB010C */  jal        vs_battle_getCameraLookAt
    /* 5342C 800BBC2C 21204002 */   addu      $a0, $s2, $zero
    /* 53430 800BBC30 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 53434 800BBC34 21282002 */  addu       $a1, $s1, $zero
    /* 53438 800BBC38 C7F9020C */  jal        _copyVector
    /* 5343C 800BBC3C 48018424 */   addiu     $a0, $a0, 0x148
    /* 53440 800BBC40 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 53444 800BBC44 21282002 */  addu       $a1, $s1, $zero
    /* 53448 800BBC48 C7F9020C */  jal        _copyVector
    /* 5344C 800BBC4C A4008424 */   addiu     $a0, $a0, 0xA4
    /* 53450 800BBC50 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 53454 800BBC54 21284002 */  addu       $a1, $s2, $zero
    /* 53458 800BBC58 C7F9020C */  jal        _copyVector
    /* 5345C 800BBC5C 94008424 */   addiu     $a0, $a0, 0x94
    /* 53460 800BBC60 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 53464 800BBC64 21284002 */  addu       $a1, $s2, $zero
    /* 53468 800BBC68 C7F9020C */  jal        _copyVector
    /* 5346C 800BBC6C 58018424 */   addiu     $a0, $a0, 0x158
    /* 53470 800BBC70 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 53474 800BBC74 0F000324 */  addiu      $v1, $zero, 0xF
    /* 53478 800BBC78 000043A0 */  sb         $v1, 0x0($v0)
    /* 5347C 800BBC7C A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 53480 800BBC80 00000000 */  nop
    /* 53484 800BBC84 070040A0 */  sb         $zero, 0x7($v0)
    /* 53488 800BBC88 060040A0 */  sb         $zero, 0x6($v0)
    /* 5348C 800BBC8C A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 53490 800BBC90 00000000 */  nop
    /* 53494 800BBC94 B40043A0 */  sb         $v1, 0xB4($v0)
    /* 53498 800BBC98 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 5349C 800BBC9C 21200000 */  addu       $a0, $zero, $zero
    /* 534A0 800BBCA0 BB0040A0 */  sb         $zero, 0xBB($v0)
    /* 534A4 800BBCA4 BA0040A0 */  sb         $zero, 0xBA($v0)
    /* 534A8 800BBCA8 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 534AC 800BBCAC 01001324 */  addiu      $s3, $zero, 0x1
    /* 534B0 800BBCB0 720140A4 */  sh         $zero, 0x172($v0)
    /* 534B4 800BBCB4 6A0140A4 */  sh         $zero, 0x16A($v0)
    /* 534B8 800BBCB8 54F7010C */  jal        func_8007DD50
    /* 534BC 800BBCBC 680153A0 */   sb        $s3, 0x168($v0)
    /* 534C0 800BBCC0 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 534C4 800BBCC4 21200000 */  addu       $a0, $zero, $zero
    /* 534C8 800BBCC8 7E0140A4 */  sh         $zero, 0x17E($v0)
    /* 534CC 800BBCCC 6BF7010C */  jal        func_8007DDAC
    /* 534D0 800BBCD0 760140A4 */   sh        $zero, 0x176($v0)
    /* 534D4 800BBCD4 0F80113C */  lui        $s1, %hi(D_800E9C0C)
    /* 534D8 800BBCD8 0C9C3126 */  addiu      $s1, $s1, %lo(D_800E9C0C)
    /* 534DC 800BBCDC A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 534E0 800BBCE0 21202002 */  addu       $a0, $s1, $zero
    /* 534E4 800BBCE4 740153A0 */  sb         $s3, 0x174($v0)
    /* 534E8 800BBCE8 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 534EC 800BBCEC 00101224 */  addiu      $s2, $zero, 0x1000
    /* 534F0 800BBCF0 000252A4 */  sh         $s2, 0x200($v0)
    /* 534F4 800BBCF4 6EF7010C */  jal        func_8007DDB8
    /* 534F8 800BBCF8 FE0152A4 */   sh        $s2, 0x1FE($v0)
    /* 534FC 800BBCFC 0F80043C */  lui        $a0, %hi(D_800E9C08)
    /* 53500 800BBD00 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 53504 800BBD04 089C8424 */  addiu      $a0, $a0, %lo(D_800E9C08)
    /* 53508 800BBD08 1A0240A4 */  sh         $zero, 0x21A($v0)
    /* 5350C 800BBD0C 220240A4 */  sh         $zero, 0x222($v0)
    /* 53510 800BBD10 200240A4 */  sh         $zero, 0x220($v0)
    /* 53514 800BBD14 75F7010C */  jal        func_8007DDD4
    /* 53518 800BBD18 1E0240A4 */   sh        $zero, 0x21E($v0)
    /* 5351C 800BBD1C A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 53520 800BBD20 21202002 */  addu       $a0, $s1, $zero
    /* 53524 800BBD24 3A0240A4 */  sh         $zero, 0x23A($v0)
    /* 53528 800BBD28 400252A4 */  sh         $s2, 0x240($v0)
    /* 5352C 800BBD2C 7EF7010C */  jal        func_8007DDF8
    /* 53530 800BBD30 3E0252A4 */   sh        $s2, 0x23E($v0)
    /* 53534 800BBD34 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 53538 800BBD38 01000424 */  addiu      $a0, $zero, 0x1
    /* 5353C 800BBD3C 8BF7010C */  jal        func_8007DE2C
    /* 53540 800BBD40 5A0240A4 */   sh        $zero, 0x25A($v0)
    /* 53544 800BBD44 A44B038E */  lw         $v1, %lo(D_800F4BA4)($s0)
    /* 53548 800BBD48 00000000 */  nop
    /* 5354C 800BBD4C 890160A0 */  sb         $zero, 0x189($v1)
    /* 53550 800BBD50 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 53554 800BBD54 00020224 */  addiu      $v0, $zero, 0x200
    /* 53558 800BBD58 5E0272A4 */  sh         $s2, 0x25E($v1)
    /* 5355C 800BBD5C 600260A4 */  sh         $zero, 0x260($v1)
    /* 53560 800BBD60 7A0260A4 */  sh         $zero, 0x27A($v1)
    /* 53564 800BBD64 820162A4 */  sh         $v0, 0x182($v1)
    /* 53568 800BBD68 800193A0 */  sb         $s3, 0x180($a0)
    /* 5356C 800BBD6C A44B038E */  lw         $v1, %lo(D_800F4BA4)($s0)
    /* 53570 800BBD70 00000000 */  nop
    /* 53574 800BBD74 950160A0 */  sb         $zero, 0x195($v1)
    /* 53578 800BBD78 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 5357C 800BBD7C 40000224 */  addiu      $v0, $zero, 0x40
    /* 53580 800BBD80 8E0162A4 */  sh         $v0, 0x18E($v1)
    /* 53584 800BBD84 8C0193A0 */  sb         $s3, 0x18C($a0)
    /* 53588 800BBD88 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 5358C 800BBD8C 00000000 */  nop
    /* 53590 800BBD90 A10140A0 */  sb         $zero, 0x1A1($v0)
    /* 53594 800BBD94 A44B038E */  lw         $v1, %lo(D_800F4BA4)($s0)
    /* 53598 800BBD98 9A0152A4 */  sh         $s2, 0x19A($v0)
    /* 5359C 800BBD9C 980173A0 */  sb         $s3, 0x198($v1)
    /* 535A0 800BBDA0 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 535A4 800BBDA4 00000000 */  nop
    /* 535A8 800BBDA8 BB0140A0 */  sb         $zero, 0x1BB($v0)
    /* 535AC 800BBDAC AF0140A0 */  sb         $zero, 0x1AF($v0)
    /* 535B0 800BBDB0 A44B038E */  lw         $v1, %lo(D_800F4BA4)($s0)
    /* 535B4 800BBDB4 A40140A4 */  sh         $zero, 0x1A4($v0)
    /* 535B8 800BBDB8 00200224 */  addiu      $v0, $zero, 0x2000
    /* 535BC 800BBDBC E80162A4 */  sh         $v0, 0x1E8($v1)
    /* 535C0 800BBDC0 5000BF8F */  lw         $ra, 0x50($sp)
    /* 535C4 800BBDC4 4C00B38F */  lw         $s3, 0x4C($sp)
    /* 535C8 800BBDC8 4800B28F */  lw         $s2, 0x48($sp)
    /* 535CC 800BBDCC 4400B18F */  lw         $s1, 0x44($sp)
    /* 535D0 800BBDD0 4000B08F */  lw         $s0, 0x40($sp)
    /* 535D4 800BBDD4 0800E003 */  jr         $ra
    /* 535D8 800BBDD8 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel func_800BBBE8
