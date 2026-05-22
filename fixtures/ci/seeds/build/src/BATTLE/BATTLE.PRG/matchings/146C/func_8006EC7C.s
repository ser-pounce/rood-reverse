nonmatching func_8006EC7C, 0x294

glabel func_8006EC7C
    /* 647C 8006EC7C 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 6480 8006EC80 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 6484 8006EC84 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6488 8006EC88 2400BFAF */  sw         $ra, 0x24($sp)
    /* 648C 8006EC8C 00104230 */  andi       $v0, $v0, 0x1000
    /* 6490 8006EC90 0D004010 */  beqz       $v0, .L8006ECC8
    /* 6494 8006EC94 2000B0AF */   sw        $s0, 0x20($sp)
    /* 6498 8006EC98 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 649C 8006EC9C D0194524 */  addiu      $a1, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 64A0 8006ECA0 0400A48C */  lw         $a0, 0x4($a1)
    /* 64A4 8006ECA4 00000000 */  nop
    /* 64A8 8006ECA8 E0FF8324 */  addiu      $v1, $a0, -0x20
    /* 64AC 8006ECAC 02006104 */  bgez       $v1, .L8006ECB8
    /* 64B0 8006ECB0 21106000 */   addu      $v0, $v1, $zero
    /* 64B4 8006ECB4 DF0F8224 */  addiu      $v0, $a0, 0xFDF
  .L8006ECB8:
    /* 64B8 8006ECB8 03130200 */  sra        $v0, $v0, 12
    /* 64BC 8006ECBC 00130200 */  sll        $v0, $v0, 12
    /* 64C0 8006ECC0 23106200 */  subu       $v0, $v1, $v0
    /* 64C4 8006ECC4 0400A2AC */  sw         $v0, 0x4($a1)
  .L8006ECC8:
    /* 64C8 8006ECC8 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 64CC 8006ECCC C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 64D0 8006ECD0 00000000 */  nop
    /* 64D4 8006ECD4 00404230 */  andi       $v0, $v0, 0x4000
    /* 64D8 8006ECD8 0C004010 */  beqz       $v0, .L8006ED0C
    /* 64DC 8006ECDC 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 64E0 8006ECE0 D0194524 */  addiu      $a1, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 64E4 8006ECE4 0400A48C */  lw         $a0, 0x4($a1)
    /* 64E8 8006ECE8 00000000 */  nop
    /* 64EC 8006ECEC 20008324 */  addiu      $v1, $a0, 0x20
    /* 64F0 8006ECF0 02006104 */  bgez       $v1, .L8006ECFC
    /* 64F4 8006ECF4 21106000 */   addu      $v0, $v1, $zero
    /* 64F8 8006ECF8 1F108224 */  addiu      $v0, $a0, 0x101F
  .L8006ECFC:
    /* 64FC 8006ECFC 03130200 */  sra        $v0, $v0, 12
    /* 6500 8006ED00 00130200 */  sll        $v0, $v0, 12
    /* 6504 8006ED04 23106200 */  subu       $v0, $v1, $v0
    /* 6508 8006ED08 0400A2AC */  sw         $v0, 0x4($a1)
  .L8006ED0C:
    /* 650C 8006ED0C 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 6510 8006ED10 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 6514 8006ED14 00000000 */  nop
    /* 6518 8006ED18 00804230 */  andi       $v0, $v0, 0x8000
    /* 651C 8006ED1C 0B004010 */  beqz       $v0, .L8006ED4C
    /* 6520 8006ED20 0F80053C */   lui       $a1, %hi(vs_battle_cameraCurrentSpherical)
    /* 6524 8006ED24 D019A48C */  lw         $a0, %lo(vs_battle_cameraCurrentSpherical)($a1)
    /* 6528 8006ED28 00000000 */  nop
    /* 652C 8006ED2C E0FF8324 */  addiu      $v1, $a0, -0x20
    /* 6530 8006ED30 02006104 */  bgez       $v1, .L8006ED3C
    /* 6534 8006ED34 21106000 */   addu      $v0, $v1, $zero
    /* 6538 8006ED38 DF0F8224 */  addiu      $v0, $a0, 0xFDF
  .L8006ED3C:
    /* 653C 8006ED3C 03130200 */  sra        $v0, $v0, 12
    /* 6540 8006ED40 00130200 */  sll        $v0, $v0, 12
    /* 6544 8006ED44 23106200 */  subu       $v0, $v1, $v0
    /* 6548 8006ED48 D019A2AC */  sw         $v0, %lo(vs_battle_cameraCurrentSpherical)($a1)
  .L8006ED4C:
    /* 654C 8006ED4C 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 6550 8006ED50 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 6554 8006ED54 00000000 */  nop
    /* 6558 8006ED58 00204230 */  andi       $v0, $v0, 0x2000
    /* 655C 8006ED5C 0B004010 */  beqz       $v0, .L8006ED8C
    /* 6560 8006ED60 0F80053C */   lui       $a1, %hi(vs_battle_cameraCurrentSpherical)
    /* 6564 8006ED64 D019A48C */  lw         $a0, %lo(vs_battle_cameraCurrentSpherical)($a1)
    /* 6568 8006ED68 00000000 */  nop
    /* 656C 8006ED6C 20008324 */  addiu      $v1, $a0, 0x20
    /* 6570 8006ED70 02006104 */  bgez       $v1, .L8006ED7C
    /* 6574 8006ED74 21106000 */   addu      $v0, $v1, $zero
    /* 6578 8006ED78 1F108224 */  addiu      $v0, $a0, 0x101F
  .L8006ED7C:
    /* 657C 8006ED7C 03130200 */  sra        $v0, $v0, 12
    /* 6580 8006ED80 00130200 */  sll        $v0, $v0, 12
    /* 6584 8006ED84 23106200 */  subu       $v0, $v1, $v0
    /* 6588 8006ED88 D019A2AC */  sw         $v0, %lo(vs_battle_cameraCurrentSpherical)($a1)
  .L8006ED8C:
    /* 658C 8006ED8C 0580023C */  lui        $v0, %hi(_portInfo)
    /* 6590 8006ED90 90014424 */  addiu      $a0, $v0, %lo(_portInfo)
    /* 6594 8006ED94 90014390 */  lbu        $v1, %lo(_portInfo)($v0)
    /* 6598 8006ED98 07000224 */  addiu      $v0, $zero, 0x7
    /* 659C 8006ED9C 35006214 */  bne        $v1, $v0, .L8006EE74
    /* 65A0 8006EDA0 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 65A4 8006EDA4 03008390 */  lbu        $v1, 0x3($a0)
    /* 65A8 8006EDA8 04008290 */  lbu        $v0, 0x4($a0)
    /* 65AC 8006EDAC 00000000 */  nop
    /* 65B0 8006EDB0 80FF4524 */  addiu      $a1, $v0, -0x80
    /* 65B4 8006EDB4 C0FF6624 */  addiu      $a2, $v1, -0x40
    /* 65B8 8006EDB8 8100C22C */  sltiu      $v0, $a2, 0x81
    /* 65BC 8006EDBC 14004014 */  bnez       $v0, .L8006EE10
    /* 65C0 8006EDC0 80FF6424 */   addiu     $a0, $v1, -0x80
    /* 65C4 8006EDC4 0200801C */  bgtz       $a0, .L8006EDD0
    /* 65C8 8006EDC8 40FF6424 */   addiu     $a0, $v1, -0xC0
    /* 65CC 8006EDCC 2120C000 */  addu       $a0, $a2, $zero
  .L8006EDD0:
    /* 65D0 8006EDD0 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* 65D4 8006EDD4 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 65D8 8006EDD8 18008200 */  mult       $a0, $v0
    /* 65DC 8006EDDC 0F80063C */  lui        $a2, %hi(vs_battle_cameraCurrentSpherical)
    /* 65E0 8006EDE0 C3170400 */  sra        $v0, $a0, 31
    /* 65E4 8006EDE4 D019C38C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($a2)
    /* 65E8 8006EDE8 10380000 */  mfhi       $a3
    /* 65EC 8006EDEC 2310E200 */  subu       $v0, $a3, $v0
    /* 65F0 8006EDF0 21186200 */  addu       $v1, $v1, $v0
    /* 65F4 8006EDF4 02006104 */  bgez       $v1, .L8006EE00
    /* 65F8 8006EDF8 21106000 */   addu      $v0, $v1, $zero
    /* 65FC 8006EDFC FF0F6224 */  addiu      $v0, $v1, 0xFFF
  .L8006EE00:
    /* 6600 8006EE00 03130200 */  sra        $v0, $v0, 12
    /* 6604 8006EE04 00130200 */  sll        $v0, $v0, 12
    /* 6608 8006EE08 23106200 */  subu       $v0, $v1, $v0
    /* 660C 8006EE0C D019C2AC */  sw         $v0, %lo(vs_battle_cameraCurrentSpherical)($a2)
  .L8006EE10:
    /* 6610 8006EE10 4000A324 */  addiu      $v1, $a1, 0x40
    /* 6614 8006EE14 8100622C */  sltiu      $v0, $v1, 0x81
    /* 6618 8006EE18 15004014 */  bnez       $v0, .L8006EE70
    /* 661C 8006EE1C 00000000 */   nop
    /* 6620 8006EE20 0200A01C */  bgtz       $a1, .L8006EE2C
    /* 6624 8006EE24 C0FFA524 */   addiu     $a1, $a1, -0x40
    /* 6628 8006EE28 21286000 */  addu       $a1, $v1, $zero
  .L8006EE2C:
    /* 662C 8006EE2C 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* 6630 8006EE30 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 6634 8006EE34 1800A200 */  mult       $a1, $v0
    /* 6638 8006EE38 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 663C 8006EE3C D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 6640 8006EE40 C3170500 */  sra        $v0, $a1, 31
    /* 6644 8006EE44 0400838C */  lw         $v1, 0x4($a0)
    /* 6648 8006EE48 10380000 */  mfhi       $a3
    /* 664C 8006EE4C 2310E200 */  subu       $v0, $a3, $v0
    /* 6650 8006EE50 21186200 */  addu       $v1, $v1, $v0
    /* 6654 8006EE54 02006104 */  bgez       $v1, .L8006EE60
    /* 6658 8006EE58 21106000 */   addu      $v0, $v1, $zero
    /* 665C 8006EE5C FF0F6224 */  addiu      $v0, $v1, 0xFFF
  .L8006EE60:
    /* 6660 8006EE60 03130200 */  sra        $v0, $v0, 12
    /* 6664 8006EE64 00130200 */  sll        $v0, $v0, 12
    /* 6668 8006EE68 23106200 */  subu       $v0, $v1, $v0
    /* 666C 8006EE6C 040082AC */  sw         $v0, 0x4($a0)
  .L8006EE70:
    /* 6670 8006EE70 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006EE74:
    /* 6674 8006EE74 D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 6678 8006EE78 0400838C */  lw         $v1, 0x4($a0)
    /* 667C 8006EE7C 00000000 */  nop
    /* 6680 8006EE80 81036228 */  slti       $v0, $v1, 0x381
    /* 6684 8006EE84 03004014 */  bnez       $v0, .L8006EE94
    /* 6688 8006EE88 80FC6228 */   slti      $v0, $v1, -0x380
    /* 668C 8006EE8C A7BB0108 */  j          .L8006EE9C
    /* 6690 8006EE90 80030224 */   addiu     $v0, $zero, 0x380
  .L8006EE94:
    /* 6694 8006EE94 02004010 */  beqz       $v0, .L8006EEA0
    /* 6698 8006EE98 80FC0224 */   addiu     $v0, $zero, -0x380
  .L8006EE9C:
    /* 669C 8006EE9C 040082AC */  sw         $v0, 0x4($a0)
  .L8006EEA0:
    /* 66A0 8006EEA0 0F80103C */  lui        $s0, %hi(vs_battle_cameraCurrentSpherical)
    /* 66A4 8006EEA4 21200000 */  addu       $a0, $zero, $zero
    /* 66A8 8006EEA8 D0190596 */  lhu        $a1, %lo(vs_battle_cameraCurrentSpherical)($s0)
    /* 66AC 8006EEAC D0191026 */  addiu      $s0, $s0, %lo(vs_battle_cameraCurrentSpherical)
    /* 66B0 8006EEB0 21308000 */  addu       $a2, $a0, $zero
    /* 66B4 8006EEB4 14AA020C */  jal        func_800AA850
    /* 66B8 8006EEB8 FF0FA530 */   andi      $a1, $a1, 0xFFF
    /* 66BC 8006EEBC 21200000 */  addu       $a0, $zero, $zero
    /* 66C0 8006EEC0 4284020C */  jal        func_800A1108
    /* 66C4 8006EEC4 1000A527 */   addiu     $a1, $sp, 0x10
    /* 66C8 8006EEC8 21200002 */  addu       $a0, $s0, $zero
    /* 66CC 8006EECC 801F053C */  lui        $a1, %hi(D_1F800000)
    /* 66D0 8006EED0 1400A287 */  lh         $v0, 0x14($sp)
    /* 66D4 8006EED4 0000A524 */  addiu      $a1, $a1, %lo(D_1F800000)
    /* 66D8 8006EED8 00130200 */  sll        $v0, $v0, 12
    /* 66DC 8006EEDC 3400A2AC */  sw         $v0, 0x34($a1)
    /* 66E0 8006EEE0 1800A287 */  lh         $v0, 0x18($sp)
    /* 66E4 8006EEE4 1600A387 */  lh         $v1, 0x16($sp)
    /* 66E8 8006EEE8 00130200 */  sll        $v0, $v0, 12
    /* 66EC 8006EEEC 4CFF6324 */  addiu      $v1, $v1, -0xB4
    /* 66F0 8006EEF0 001B0300 */  sll        $v1, $v1, 12
    /* 66F4 8006EEF4 3C00A2AC */  sw         $v0, 0x3C($a1)
    /* 66F8 8006EEF8 BEEA010C */  jal        _setCameraLookAtFromAngles
    /* 66FC 8006EEFC 3800A3AC */   sw        $v1, 0x38($a1)
    /* 6700 8006EF00 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6704 8006EF04 2000B08F */  lw         $s0, 0x20($sp)
    /* 6708 8006EF08 0800E003 */  jr         $ra
    /* 670C 8006EF0C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006EC7C
