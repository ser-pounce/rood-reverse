nonmatching SpuSetReverbModeType, 0x1CC

glabel SpuSetReverbModeType
    /* F4C4 8001ECC4 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* F4C8 8001ECC8 5800B0AF */  sw         $s0, 0x58($sp)
    /* F4CC 8001ECCC 21808000 */  addu       $s0, $a0, $zero
    /* F4D0 8001ECD0 6000B2AF */  sw         $s2, 0x60($sp)
    /* F4D4 8001ECD4 21900000 */  addu       $s2, $zero, $zero
    /* F4D8 8001ECD8 00010232 */  andi       $v0, $s0, 0x100
    /* F4DC 8001ECDC 6400BFAF */  sw         $ra, 0x64($sp)
    /* F4E0 8001ECE0 04004010 */  beqz       $v0, .L8001ECF4
    /* F4E4 8001ECE4 5C00B1AF */   sw        $s1, 0x5C($sp)
    /* F4E8 8001ECE8 FFFE0224 */  addiu      $v0, $zero, -0x101
    /* F4EC 8001ECEC 24800202 */  and        $s0, $s0, $v0
    /* F4F0 8001ECF0 01001224 */  addiu      $s2, $zero, 0x1
  .L8001ECF4:
    /* F4F4 8001ECF4 0A00022E */  sltiu      $v0, $s0, 0xA
    /* F4F8 8001ECF8 09004010 */  beqz       $v0, .L8001ED20
    /* F4FC 8001ECFC 80101000 */   sll       $v0, $s0, 2
    /* F500 8001ED00 0380033C */  lui        $v1, %hi(D_80030CD0)
    /* F504 8001ED04 D00C6324 */  addiu      $v1, $v1, %lo(D_80030CD0)
    /* F508 8001ED08 21884300 */  addu       $s1, $v0, $v1
    /* F50C 8001ED0C 0000248E */  lw         $a0, 0x0($s1)
    /* F510 8001ED10 217A000C */  jal        _SpuIsInAllocateArea_
    /* F514 8001ED14 00000000 */   nop
    /* F518 8001ED18 03004010 */  beqz       $v0, .L8001ED28
    /* F51C 8001ED1C 1000A527 */   addiu     $a1, $sp, 0x10
  .L8001ED20:
    /* F520 8001ED20 9E7B0008 */  j          .L8001EE78
    /* F524 8001ED24 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8001ED28:
    /* F528 8001ED28 00111000 */  sll        $v0, $s0, 4
    /* F52C 8001ED2C 21105000 */  addu       $v0, $v0, $s0
    /* F530 8001ED30 80100200 */  sll        $v0, $v0, 2
    /* F534 8001ED34 0380033C */  lui        $v1, %hi(D_80030D00)
    /* F538 8001ED38 000D6324 */  addiu      $v1, $v1, %lo(D_80030D00)
    /* F53C 8001ED3C 21204300 */  addu       $a0, $v0, $v1
    /* F540 8001ED40 43000324 */  addiu      $v1, $zero, 0x43
    /* F544 8001ED44 0380013C */  lui        $at, %hi(D_80030804)
    /* F548 8001ED48 040830AC */  sw         $s0, %lo(D_80030804)($at)
    /* F54C 8001ED4C 0000228E */  lw         $v0, 0x0($s1)
    /* F550 8001ED50 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* F554 8001ED54 0380013C */  lui        $at, %hi(D_800307FC)
    /* F558 8001ED58 FC0722AC */  sw         $v0, %lo(D_800307FC)($at)
  .L8001ED5C:
    /* F55C 8001ED5C 00008290 */  lbu        $v0, 0x0($a0)
    /* F560 8001ED60 01008424 */  addiu      $a0, $a0, 0x1
    /* F564 8001ED64 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* F568 8001ED68 0000A2A0 */  sb         $v0, 0x0($a1)
    /* F56C 8001ED6C FBFF6614 */  bne        $v1, $a2, .L8001ED5C
    /* F570 8001ED70 0100A524 */   addiu     $a1, $a1, 0x1
    /* F574 8001ED74 07000224 */  addiu      $v0, $zero, 0x7
    /* F578 8001ED78 06000212 */  beq        $s0, $v0, .L8001ED94
    /* F57C 8001ED7C 1000A0AF */   sw        $zero, 0x10($sp)
    /* F580 8001ED80 08000224 */  addiu      $v0, $zero, 0x8
    /* F584 8001ED84 09000212 */  beq        $s0, $v0, .L8001EDAC
    /* F588 8001ED88 7F000224 */   addiu     $v0, $zero, 0x7F
    /* F58C 8001ED8C 707B0008 */  j          .L8001EDC0
    /* F590 8001ED90 00000000 */   nop
  .L8001ED94:
    /* F594 8001ED94 0380033C */  lui        $v1, %hi(D_80030810)
    /* F598 8001ED98 10086324 */  addiu      $v1, $v1, %lo(D_80030810)
    /* F59C 8001ED9C 7F000224 */  addiu      $v0, $zero, 0x7F
    /* F5A0 8001EDA0 000062AC */  sw         $v0, 0x0($v1)
    /* F5A4 8001EDA4 747B0008 */  j          .L8001EDD0
    /* F5A8 8001EDA8 FCFF62AC */   sw        $v0, -0x4($v1)
  .L8001EDAC:
    /* F5AC 8001EDAC 0380033C */  lui        $v1, %hi(D_80030810)
    /* F5B0 8001EDB0 10086324 */  addiu      $v1, $v1, %lo(D_80030810)
    /* F5B4 8001EDB4 000060AC */  sw         $zero, 0x0($v1)
    /* F5B8 8001EDB8 747B0008 */  j          .L8001EDD0
    /* F5BC 8001EDBC FCFF62AC */   sw        $v0, -0x4($v1)
  .L8001EDC0:
    /* F5C0 8001EDC0 0380023C */  lui        $v0, %hi(D_80030810)
    /* F5C4 8001EDC4 10084224 */  addiu      $v0, $v0, %lo(D_80030810)
    /* F5C8 8001EDC8 000040AC */  sw         $zero, 0x0($v0)
    /* F5CC 8001EDCC FCFF40AC */  sw         $zero, -0x4($v0)
  .L8001EDD0:
    /* F5D0 8001EDD0 0380033C */  lui        $v1, %hi(D_80030860)
    /* F5D4 8001EDD4 6008638C */  lw         $v1, %lo(D_80030860)($v1)
    /* F5D8 8001EDD8 00000000 */  nop
    /* F5DC 8001EDDC AA016294 */  lhu        $v0, 0x1AA($v1)
    /* F5E0 8001EDE0 00000000 */  nop
    /* F5E4 8001EDE4 C2110200 */  srl        $v0, $v0, 7
    /* F5E8 8001EDE8 01004230 */  andi       $v0, $v0, 0x1
    /* F5EC 8001EDEC 05004010 */  beqz       $v0, .L8001EE04
    /* F5F0 8001EDF0 21884000 */   addu      $s1, $v0, $zero
    /* F5F4 8001EDF4 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* F5F8 8001EDF8 00000000 */  nop
    /* F5FC 8001EDFC 7FFF4230 */  andi       $v0, $v0, 0xFF7F
    /* F600 8001EE00 AA0162A4 */  sh         $v0, 0x1AA($v1)
  .L8001EE04:
    /* F604 8001EE04 0380023C */  lui        $v0, %hi(D_80030860)
    /* F608 8001EE08 6008428C */  lw         $v0, %lo(D_80030860)($v0)
    /* F60C 8001EE0C 1000A427 */  addiu      $a0, $sp, 0x10
    /* F610 8001EE10 840140A4 */  sh         $zero, 0x184($v0)
    /* F614 8001EE14 860140A4 */  sh         $zero, 0x186($v0)
    /* F618 8001EE18 0380023C */  lui        $v0, %hi(D_80030808)
    /* F61C 8001EE1C 08084224 */  addiu      $v0, $v0, %lo(D_80030808)
    /* F620 8001EE20 000040A4 */  sh         $zero, 0x0($v0)
    /* F624 8001EE24 A57B000C */  jal        _spu_setReverbAttr
    /* F628 8001EE28 020040A4 */   sh        $zero, 0x2($v0)
    /* F62C 8001EE2C 04004012 */  beqz       $s2, .L8001EE40
    /* F630 8001EE30 D1000424 */   addiu     $a0, $zero, 0xD1
    /* F634 8001EE34 D97C000C */  jal        SpuClearReverbWorkArea
    /* F638 8001EE38 21200002 */   addu      $a0, $s0, $zero
    /* F63C 8001EE3C D1000424 */  addiu      $a0, $zero, 0xD1
  .L8001EE40:
    /* F640 8001EE40 0380053C */  lui        $a1, %hi(D_800307FC)
    /* F644 8001EE44 FC07A58C */  lw         $a1, %lo(D_800307FC)($a1)
    /* F648 8001EE48 D878000C */  jal        _spu_FsetRXX
    /* F64C 8001EE4C 21300000 */   addu      $a2, $zero, $zero
    /* F650 8001EE50 09002012 */  beqz       $s1, .L8001EE78
    /* F654 8001EE54 21100000 */   addu      $v0, $zero, $zero
    /* F658 8001EE58 0380033C */  lui        $v1, %hi(D_80030860)
    /* F65C 8001EE5C 6008638C */  lw         $v1, %lo(D_80030860)($v1)
    /* F660 8001EE60 00000000 */  nop
    /* F664 8001EE64 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* F668 8001EE68 00000000 */  nop
    /* F66C 8001EE6C 80004234 */  ori        $v0, $v0, 0x80
    /* F670 8001EE70 AA0162A4 */  sh         $v0, 0x1AA($v1)
    /* F674 8001EE74 21100000 */  addu       $v0, $zero, $zero
  .L8001EE78:
    /* F678 8001EE78 6400BF8F */  lw         $ra, 0x64($sp)
    /* F67C 8001EE7C 6000B28F */  lw         $s2, 0x60($sp)
    /* F680 8001EE80 5C00B18F */  lw         $s1, 0x5C($sp)
    /* F684 8001EE84 5800B08F */  lw         $s0, 0x58($sp)
    /* F688 8001EE88 0800E003 */  jr         $ra
    /* F68C 8001EE8C 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel SpuSetReverbModeType
    /* F690 8001EE90 00000000 */  nop
