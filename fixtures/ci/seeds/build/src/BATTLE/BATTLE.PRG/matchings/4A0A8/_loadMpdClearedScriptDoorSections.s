nonmatching _loadMpdClearedScriptDoorSections, 0x174

glabel _loadMpdClearedScriptDoorSections
    /* 5618C 800BE98C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 56190 800BE990 2000B4AF */  sw         $s4, 0x20($sp)
    /* 56194 800BE994 21A08000 */  addu       $s4, $a0, $zero
    /* 56198 800BE998 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5619C 800BE99C 4800B08F */  lw         $s0, 0x48($sp)
    /* 561A0 800BE9A0 A9000424 */  addiu      $a0, $zero, 0xA9
    /* 561A4 800BE9A4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 561A8 800BE9A8 2188A000 */  addu       $s1, $a1, $zero
    /* 561AC 800BE9AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 561B0 800BE9B0 4400B297 */  lhu        $s2, 0x44($sp)
    /* 561B4 800BE9B4 21280000 */  addu       $a1, $zero, $zero
    /* 561B8 800BE9B8 2400B5AF */  sw         $s5, 0x24($sp)
    /* 561BC 800BE9BC 21A8C000 */  addu       $s5, $a2, $zero
    /* 561C0 800BE9C0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 561C4 800BE9C4 2800BFAF */  sw         $ra, 0x28($sp)
    /* 561C8 800BE9C8 05FB020C */  jal        vs_battle_setStateFlag
    /* 561CC 800BE9CC 2198E000 */   addu      $s3, $a3, $zero
    /* 561D0 800BE9D0 0E000016 */  bnez       $s0, .L800BEA0C
    /* 561D4 800BE9D4 FFFF3032 */   andi      $s0, $s1, 0xFFFF
    /* 561D8 800BE9D8 20001024 */  addiu      $s0, $zero, 0x20
    /* 561DC 800BE9DC 00241000 */  sll        $a0, $s0, 16
  .L800BE9E0:
    /* 561E0 800BE9E0 03240400 */  sra        $a0, $a0, 16
    /* 561E4 800BE9E4 05FB020C */  jal        vs_battle_setStateFlag
    /* 561E8 800BE9E8 21280000 */   addu      $a1, $zero, $zero
    /* 561EC 800BE9EC 01000226 */  addiu      $v0, $s0, 0x1
    /* 561F0 800BE9F0 21804000 */  addu       $s0, $v0, $zero
    /* 561F4 800BE9F4 00140200 */  sll        $v0, $v0, 16
    /* 561F8 800BE9F8 03140200 */  sra        $v0, $v0, 16
    /* 561FC 800BE9FC 40004228 */  slti       $v0, $v0, 0x40
    /* 56200 800BEA00 F7FF4014 */  bnez       $v0, .L800BE9E0
    /* 56204 800BEA04 00241000 */   sll       $a0, $s0, 16
    /* 56208 800BEA08 FFFF3032 */  andi       $s0, $s1, 0xFFFF
  .L800BEA0C:
    /* 5620C 800BEA0C 0B000012 */  beqz       $s0, .L800BEA3C
    /* 56210 800BEA10 0F80023C */   lui       $v0, %hi(_mpdClearedSection)
    /* 56214 800BEA14 B10F010C */  jal        vs_main_allocHeap
    /* 56218 800BEA18 21200002 */   addu      $a0, $s0, $zero
    /* 5621C 800BEA1C 0F80033C */  lui        $v1, %hi(_mpdClearedSection)
    /* 56220 800BEA20 AC4B62AC */  sw         $v0, %lo(_mpdClearedSection)($v1)
    /* 56224 800BEA24 21204000 */  addu       $a0, $v0, $zero
    /* 56228 800BEA28 21288002 */  addu       $a1, $s4, $zero
    /* 5622C 800BEA2C A99B000C */  jal        memcpy
    /* 56230 800BEA30 21300002 */   addu      $a2, $s0, $zero
    /* 56234 800BEA34 91FA0208 */  j          .L800BEA44
    /* 56238 800BEA38 FFFF5032 */   andi      $s0, $s2, 0xFFFF
  .L800BEA3C:
    /* 5623C 800BEA3C AC4B40AC */  sw         $zero, %lo(_mpdClearedSection)($v0)
    /* 56240 800BEA40 FFFF5032 */  andi       $s0, $s2, 0xFFFF
  .L800BEA44:
    /* 56244 800BEA44 0B000012 */  beqz       $s0, .L800BEA74
    /* 56248 800BEA48 0F80023C */   lui       $v0, %hi(_mpdRoomDoorSection)
    /* 5624C 800BEA4C B10F010C */  jal        vs_main_allocHeap
    /* 56250 800BEA50 21200002 */   addu      $a0, $s0, $zero
    /* 56254 800BEA54 0F80033C */  lui        $v1, %hi(_mpdRoomDoorSection)
    /* 56258 800BEA58 21204000 */  addu       $a0, $v0, $zero
    /* 5625C 800BEA5C 4000A58F */  lw         $a1, 0x40($sp)
    /* 56260 800BEA60 21300002 */  addu       $a2, $s0, $zero
    /* 56264 800BEA64 A99B000C */  jal        memcpy
    /* 56268 800BEA68 E84B62AC */   sw        $v0, %lo(_mpdRoomDoorSection)($v1)
    /* 5626C 800BEA6C 9FFA0208 */  j          .L800BEA7C
    /* 56270 800BEA70 0F80043C */   lui       $a0, %hi(D_800F4BE2)
  .L800BEA74:
    /* 56274 800BEA74 E84B40AC */  sw         $zero, %lo(_mpdRoomDoorSection)($v0)
    /* 56278 800BEA78 0F80043C */  lui        $a0, %hi(D_800F4BE2)
  .L800BEA7C:
    /* 5627C 800BEA7C E24B8384 */  lh         $v1, %lo(D_800F4BE2)($a0)
    /* 56280 800BEA80 01000224 */  addiu      $v0, $zero, 0x1
    /* 56284 800BEA84 04006214 */  bne        $v1, $v0, .L800BEA98
    /* 56288 800BEA88 02000224 */   addiu     $v0, $zero, 0x2
    /* 5628C 800BEA8C E24B82A4 */  sh         $v0, %lo(D_800F4BE2)($a0)
    /* 56290 800BEA90 B7FA0208 */  j          .L800BEADC
    /* 56294 800BEA94 01000224 */   addiu     $v0, $zero, 0x1
  .L800BEA98:
    /* 56298 800BEA98 03000224 */  addiu      $v0, $zero, 0x3
    /* 5629C 800BEA9C 06006214 */  bne        $v1, $v0, .L800BEAB8
    /* 562A0 800BEAA0 0F80033C */   lui       $v1, %hi(_mpdScriptSection)
    /* 562A4 800BEAA4 0F80023C */  lui        $v0, %hi(D_800F4C34)
    /* 562A8 800BEAA8 344C40A0 */  sb         $zero, %lo(D_800F4C34)($v0)
    /* 562AC 800BEAAC 0F80023C */  lui        $v0, %hi(D_800F4BB8)
    /* 562B0 800BEAB0 E24B80A4 */  sh         $zero, %lo(D_800F4BE2)($a0)
    /* 562B4 800BEAB4 B84B40A0 */  sb         $zero, %lo(D_800F4BB8)($v0)
  .L800BEAB8:
    /* 562B8 800BEAB8 FFFF6632 */  andi       $a2, $s3, 0xFFFF
    /* 562BC 800BEABC 2B100600 */  sltu       $v0, $zero, $a2
    /* 562C0 800BEAC0 05004010 */  beqz       $v0, .L800BEAD8
    /* 562C4 800BEAC4 504C62A4 */   sh        $v0, %lo(_mpdScriptSection)($v1)
    /* 562C8 800BEAC8 0F80023C */  lui        $v0, %hi(D_800F4C30)
    /* 562CC 800BEACC 304C448C */  lw         $a0, %lo(D_800F4C30)($v0)
    /* 562D0 800BEAD0 A99B000C */  jal        memcpy
    /* 562D4 800BEAD4 2128A002 */   addu      $a1, $s5, $zero
  .L800BEAD8:
    /* 562D8 800BEAD8 21100000 */  addu       $v0, $zero, $zero
  .L800BEADC:
    /* 562DC 800BEADC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 562E0 800BEAE0 2400B58F */  lw         $s5, 0x24($sp)
    /* 562E4 800BEAE4 2000B48F */  lw         $s4, 0x20($sp)
    /* 562E8 800BEAE8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 562EC 800BEAEC 1800B28F */  lw         $s2, 0x18($sp)
    /* 562F0 800BEAF0 1400B18F */  lw         $s1, 0x14($sp)
    /* 562F4 800BEAF4 1000B08F */  lw         $s0, 0x10($sp)
    /* 562F8 800BEAF8 0800E003 */  jr         $ra
    /* 562FC 800BEAFC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _loadMpdClearedScriptDoorSections
