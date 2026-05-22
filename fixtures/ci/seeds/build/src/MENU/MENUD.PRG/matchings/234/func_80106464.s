nonmatching func_80106464, 0xA0

glabel func_80106464
    /* 3C64 80106464 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3C68 80106468 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C6C 8010646C 21888000 */  addu       $s1, $a0, $zero
    /* 3C70 80106470 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C74 80106474 2180A000 */  addu       $s0, $a1, $zero
    /* 3C78 80106478 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3C7C 8010647C 2198C000 */  addu       $s3, $a2, $zero
    /* 3C80 80106480 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3C84 80106484 8000123C */  lui        $s2, (0x808080 >> 16)
    /* 3C88 80106488 80805236 */  ori        $s2, $s2, (0x808080 & 0xFFFF)
    /* 3C8C 8010648C 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 3C90 80106490 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* 3C94 80106494 2000BFAF */  sw         $ra, 0x20($sp)
    /* 3C98 80106498 59FF030C */  jal        vs_mainMenu_renderIntColor
    /* 3C9C 8010649C 21380000 */   addu      $a3, $zero, $zero
    /* 3CA0 801064A0 1080043C */  lui        $a0, %hi(D_80102960)
    /* 3CA4 801064A4 60298424 */  addiu      $a0, $a0, %lo(D_80102960)
    /* 3CA8 801064A8 E0FF1026 */  addiu      $s0, $s0, -0x20
    /* 3CAC 801064AC 21280002 */  addu       $a1, $s0, $zero
    /* 3CB0 801064B0 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 3CB4 801064B4 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* 3CB8 801064B8 5019030C */  jal        vs_battle_renderTextRawColor
    /* 3CBC 801064BC 21380000 */   addu      $a3, $zero, $zero
    /* 3CC0 801064C0 40101300 */  sll        $v0, $s3, 1
    /* 3CC4 801064C4 2A105100 */  slt        $v0, $v0, $s1
    /* 3CC8 801064C8 03004010 */  beqz       $v0, .L801064D8
    /* 3CCC 801064CC 21206002 */   addu      $a0, $s3, $zero
    /* 3CD0 801064D0 8000123C */  lui        $s2, (0x804020 >> 16)
    /* 3CD4 801064D4 20405236 */  ori        $s2, $s2, (0x804020 & 0xFFFF)
  .L801064D8:
    /* 3CD8 801064D8 21280002 */  addu       $a1, $s0, $zero
    /* 3CDC 801064DC 21304002 */  addu       $a2, $s2, $zero
    /* 3CE0 801064E0 59FF030C */  jal        vs_mainMenu_renderIntColor
    /* 3CE4 801064E4 21380000 */   addu      $a3, $zero, $zero
    /* 3CE8 801064E8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3CEC 801064EC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3CF0 801064F0 1800B28F */  lw         $s2, 0x18($sp)
    /* 3CF4 801064F4 1400B18F */  lw         $s1, 0x14($sp)
    /* 3CF8 801064F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 3CFC 801064FC 0800E003 */  jr         $ra
    /* 3D00 80106500 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80106464
