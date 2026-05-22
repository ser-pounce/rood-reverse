nonmatching func_8009A98C, 0xF8

glabel func_8009A98C
    /* 3218C 8009A98C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 32190 8009A990 0F80023C */  lui        $v0, %hi(D_800F4588)
    /* 32194 8009A994 88454224 */  addiu      $v0, $v0, %lo(D_800F4588)
    /* 32198 8009A998 80200400 */  sll        $a0, $a0, 2
    /* 3219C 8009A99C 21208200 */  addu       $a0, $a0, $v0
    /* 321A0 8009A9A0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 321A4 8009A9A4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 321A8 8009A9A8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 321AC 8009A9AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 321B0 8009A9B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 321B4 8009A9B4 0000918C */  lw         $s1, 0x0($a0)
    /* 321B8 8009A9B8 FFFF023C */  lui        $v0, (0xFFFF0FFF >> 16)
    /* 321BC 8009A9BC 0800238E */  lw         $v1, 0x8($s1)
    /* 321C0 8009A9C0 FF0F4234 */  ori        $v0, $v0, (0xFFFF0FFF & 0xFFFF)
    /* 321C4 8009A9C4 24186200 */  and        $v1, $v1, $v0
    /* 321C8 8009A9C8 0F00A230 */  andi       $v0, $a1, 0xF
    /* 321CC 8009A9CC 00130200 */  sll        $v0, $v0, 12
    /* 321D0 8009A9D0 25186200 */  or         $v1, $v1, $v0
    /* 321D4 8009A9D4 0F80023C */  lui        $v0, %hi(D_800E8FC8)
    /* 321D8 8009A9D8 C88F4224 */  addiu      $v0, $v0, %lo(D_800E8FC8)
    /* 321DC 8009A9DC 2128A200 */  addu       $a1, $a1, $v0
    /* 321E0 8009A9E0 080023AE */  sw         $v1, 0x8($s1)
    /* 321E4 8009A9E4 80006330 */  andi       $v1, $v1, 0x80
    /* 321E8 8009A9E8 0000A590 */  lbu        $a1, 0x0($a1)
    /* 321EC 8009A9EC 03006010 */  beqz       $v1, .L8009A9FC
    /* 321F0 8009A9F0 20001324 */   addiu     $s3, $zero, 0x20
    /* 321F4 8009A9F4 816A0208 */  j          .L8009AA04
    /* 321F8 8009A9F8 40001224 */   addiu     $s2, $zero, 0x40
  .L8009A9FC:
    /* 321FC 8009A9FC 10001324 */  addiu      $s3, $zero, 0x10
    /* 32200 8009AA00 20001224 */  addiu      $s2, $zero, 0x20
  .L8009AA04:
    /* 32204 8009AA04 40201300 */  sll        $a0, $s3, 1
    /* 32208 8009AA08 40048424 */  addiu      $a0, $a0, 0x440
    /* 3220C 8009AA0C 21202402 */  addu       $a0, $s1, $a0
    /* 32210 8009AA10 C0290500 */  sll        $a1, $a1, 7
    /* 32214 8009AA14 C000A524 */  addiu      $a1, $a1, 0xC0
    /* 32218 8009AA18 21282502 */  addu       $a1, $s1, $a1
    /* 3221C 8009AA1C 2C24010C */  jal        vs_main_memcpy
    /* 32220 8009AA20 40301200 */   sll       $a2, $s2, 1
    /* 32224 8009AA24 00053026 */  addiu      $s0, $s1, 0x500
    /* 32228 8009AA28 21200002 */  addu       $a0, $s0, $zero
    /* 3222C 8009AA2C 40042526 */  addiu      $a1, $s1, 0x440
    /* 32230 8009AA30 2C24010C */  jal        vs_main_memcpy
    /* 32234 8009AA34 C0000624 */   addiu     $a2, $zero, 0xC0
    /* 32238 8009AA38 10002292 */  lbu        $v0, 0x10($s1)
    /* 3223C 8009AA3C 21200002 */  addu       $a0, $s0, $zero
    /* 32240 8009AA40 21387202 */  addu       $a3, $s3, $s2
    /* 32244 8009AA44 42280200 */  srl        $a1, $v0, 1
    /* 32248 8009AA48 0400A524 */  addiu      $a1, $a1, 0x4
    /* 3224C 8009AA4C 01004230 */  andi       $v0, $v0, 0x1
    /* 32250 8009AA50 40300200 */  sll        $a2, $v0, 1
    /* 32254 8009AA54 2130C200 */  addu       $a2, $a2, $v0
    /* 32258 8009AA58 00310600 */  sll        $a2, $a2, 4
    /* 3225C 8009AA5C 9922010C */  jal        vs_main_loadClut
    /* 32260 8009AA60 A000C624 */   addiu     $a2, $a2, 0xA0
    /* 32264 8009AA64 2000BF8F */  lw         $ra, 0x20($sp)
    /* 32268 8009AA68 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3226C 8009AA6C 1800B28F */  lw         $s2, 0x18($sp)
    /* 32270 8009AA70 1400B18F */  lw         $s1, 0x14($sp)
    /* 32274 8009AA74 1000B08F */  lw         $s0, 0x10($sp)
    /* 32278 8009AA78 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 3227C 8009AA7C 0800E003 */  jr         $ra
    /* 32280 8009AA80 00000000 */   nop
endlabel func_8009A98C
