nonmatching _saveFileExists, 0xE8

glabel _saveFileExists
    /* 6188 8006E988 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* 618C 8006E98C 5C00B3AF */  sw         $s3, 0x5C($sp)
    /* 6190 8006E990 21980000 */  addu       $s3, $zero, $zero
    /* 6194 8006E994 01000424 */  addiu      $a0, $zero, 0x1
    /* 6198 8006E998 6400BFAF */  sw         $ra, 0x64($sp)
    /* 619C 8006E99C 6000B4AF */  sw         $s4, 0x60($sp)
    /* 61A0 8006E9A0 5800B2AF */  sw         $s2, 0x58($sp)
    /* 61A4 8006E9A4 5400B1AF */  sw         $s1, 0x54($sp)
    /* 61A8 8006E9A8 27A9010C */  jal        _initMemcard
    /* 61AC 8006E9AC 5000B0AF */   sw        $s0, 0x50($sp)
  .L8006E9B0:
    /* 61B0 8006E9B0 8709010C */  jal        vs_main_gametimeUpdate
    /* 61B4 8006E9B4 02000424 */   addiu     $a0, $zero, 0x2
    /* 61B8 8006E9B8 27A9010C */  jal        _initMemcard
    /* 61BC 8006E9BC 21200000 */   addu      $a0, $zero, $zero
    /* 61C0 8006E9C0 FBFF4010 */  beqz       $v0, .L8006E9B0
    /* 61C4 8006E9C4 01001124 */   addiu     $s1, $zero, 0x1
    /* 61C8 8006E9C8 3800B227 */  addiu      $s2, $sp, 0x38
    /* 61CC 8006E9CC 0780143C */  lui        $s4, %hi(_memcardFilenameTemplate)
  .L8006E9D0:
    /* 61D0 8006E9D0 1FA5010C */  jal        _memcardEventHandler
    /* 61D4 8006E9D4 21202002 */   addu      $a0, $s1, $zero
  .L8006E9D8:
    /* 61D8 8006E9D8 1FA5010C */  jal        _memcardEventHandler
    /* 61DC 8006E9DC 21200000 */   addu      $a0, $zero, $zero
    /* 61E0 8006E9E0 02000424 */  addiu      $a0, $zero, 0x2
    /* 61E4 8006E9E4 B17D000C */  jal        VSync
    /* 61E8 8006E9E8 03005030 */   andi      $s0, $v0, 0x3
    /* 61EC 8006E9EC FAFF0012 */  beqz       $s0, .L8006E9D8
    /* 61F0 8006E9F0 01000224 */   addiu     $v0, $zero, 0x1
    /* 61F4 8006E9F4 0F000216 */  bne        $s0, $v0, .L8006EA34
    /* 61F8 8006E9F8 21204002 */   addu      $a0, $s2, $zero
    /* 61FC 8006E9FC 8C28858E */  lw         $a1, %lo(_memcardFilenameTemplate)($s4)
    /* 6200 8006EA00 0FA3010C */  jal        _rMemcpy
    /* 6204 8006EA04 16000624 */   addiu     $a2, $zero, 0x16
    /* 6208 8006EA08 21204002 */  addu       $a0, $s2, $zero
    /* 620C 8006EA0C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6210 8006EA10 2F002226 */  addiu      $v0, $s1, 0x2F
    /* 6214 8006EA14 3A00A2A3 */  sb         $v0, 0x3A($sp)
    /* 6218 8006EA18 3F000224 */  addiu      $v0, $zero, 0x3F
    /* 621C 8006EA1C E59A000C */  jal        firstfile
    /* 6220 8006EA20 4C00A2A3 */   sb        $v0, 0x4C($sp)
    /* 6224 8006EA24 04004010 */  beqz       $v0, .L8006EA38
    /* 6228 8006EA28 01003126 */   addiu     $s1, $s1, 0x1
    /* 622C 8006EA2C 91BA0108 */  j          .L8006EA44
    /* 6230 8006EA30 01001324 */   addiu     $s3, $zero, 0x1
  .L8006EA34:
    /* 6234 8006EA34 01003126 */  addiu      $s1, $s1, 0x1
  .L8006EA38:
    /* 6238 8006EA38 0300222A */  slti       $v0, $s1, 0x3
    /* 623C 8006EA3C E4FF4014 */  bnez       $v0, .L8006E9D0
    /* 6240 8006EA40 00000000 */   nop
  .L8006EA44:
    /* 6244 8006EA44 B8A9010C */  jal        _shutdownMemcard
    /* 6248 8006EA48 00000000 */   nop
    /* 624C 8006EA4C 21106002 */  addu       $v0, $s3, $zero
    /* 6250 8006EA50 6400BF8F */  lw         $ra, 0x64($sp)
    /* 6254 8006EA54 6000B48F */  lw         $s4, 0x60($sp)
    /* 6258 8006EA58 5C00B38F */  lw         $s3, 0x5C($sp)
    /* 625C 8006EA5C 5800B28F */  lw         $s2, 0x58($sp)
    /* 6260 8006EA60 5400B18F */  lw         $s1, 0x54($sp)
    /* 6264 8006EA64 5000B08F */  lw         $s0, 0x50($sp)
    /* 6268 8006EA68 0800E003 */  jr         $ra
    /* 626C 8006EA6C 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel _saveFileExists
