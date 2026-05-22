nonmatching func_800BF5F0, 0x260

glabel func_800BF5F0
    /* 56DF0 800BF5F0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 56DF4 800BF5F4 21308000 */  addu       $a2, $a0, $zero
    /* 56DF8 800BF5F8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 56DFC 800BF5FC 09001124 */  addiu      $s1, $zero, 0x9
    /* 56E00 800BF600 1800BFAF */  sw         $ra, 0x18($sp)
    /* 56E04 800BF604 1000B0AF */  sw         $s0, 0x10($sp)
    /* 56E08 800BF608 0200C294 */  lhu        $v0, 0x2($a2)
    /* 56E0C 800BF60C 0F80033C */  lui        $v1, %hi(D_800F4BB0)
    /* 56E10 800BF610 2110C200 */  addu       $v0, $a2, $v0
    /* 56E14 800BF614 B04B62AC */  sw         $v0, %lo(D_800F4BB0)($v1)
    /* 56E18 800BF618 0F80023C */  lui        $v0, %hi(D_800EB588)
    /* 56E1C 800BF61C 0400C394 */  lhu        $v1, 0x4($a2)
    /* 56E20 800BF620 88B54724 */  addiu      $a3, $v0, %lo(D_800EB588)
    /* 56E24 800BF624 2128C300 */  addu       $a1, $a2, $v1
    /* 56E28 800BF628 00141100 */  sll        $v0, $s1, 16
  .L800BF62C:
    /* 56E2C 800BF62C 03140200 */  sra        $v0, $v0, 16
    /* 56E30 800BF630 80180200 */  sll        $v1, $v0, 2
    /* 56E34 800BF634 40100200 */  sll        $v0, $v0, 1
    /* 56E38 800BF638 21204500 */  addu       $a0, $v0, $a1
    /* 56E3C 800BF63C F0FF8294 */  lhu        $v0, -0x10($a0)
    /* 56E40 800BF640 00000000 */  nop
    /* 56E44 800BF644 03004010 */  beqz       $v0, .L800BF654
    /* 56E48 800BF648 21186700 */   addu      $v1, $v1, $a3
    /* 56E4C 800BF64C 96FD0208 */  j          .L800BF658
    /* 56E50 800BF650 2110A200 */   addu      $v0, $a1, $v0
  .L800BF654:
    /* 56E54 800BF654 21100000 */  addu       $v0, $zero, $zero
  .L800BF658:
    /* 56E58 800BF658 000062AC */  sw         $v0, 0x0($v1)
    /* 56E5C 800BF65C 01002226 */  addiu      $v0, $s1, 0x1
    /* 56E60 800BF660 21884000 */  addu       $s1, $v0, $zero
    /* 56E64 800BF664 00140200 */  sll        $v0, $v0, 16
    /* 56E68 800BF668 03140200 */  sra        $v0, $v0, 16
    /* 56E6C 800BF66C 10004228 */  slti       $v0, $v0, 0x10
    /* 56E70 800BF670 EEFF4014 */  bnez       $v0, .L800BF62C
    /* 56E74 800BF674 00141100 */   sll       $v0, $s1, 16
    /* 56E78 800BF678 21880000 */  addu       $s1, $zero, $zero
    /* 56E7C 800BF67C 0600C394 */  lhu        $v1, 0x6($a2)
    /* 56E80 800BF680 0F80023C */  lui        $v0, %hi(D_800F4BC0)
    /* 56E84 800BF684 C04B4724 */  addiu      $a3, $v0, %lo(D_800F4BC0)
    /* 56E88 800BF688 2128C300 */  addu       $a1, $a2, $v1
    /* 56E8C 800BF68C 00141100 */  sll        $v0, $s1, 16
  .L800BF690:
    /* 56E90 800BF690 03140200 */  sra        $v0, $v0, 16
    /* 56E94 800BF694 80180200 */  sll        $v1, $v0, 2
    /* 56E98 800BF698 40100200 */  sll        $v0, $v0, 1
    /* 56E9C 800BF69C 21204500 */  addu       $a0, $v0, $a1
    /* 56EA0 800BF6A0 00008294 */  lhu        $v0, 0x0($a0)
    /* 56EA4 800BF6A4 00000000 */  nop
    /* 56EA8 800BF6A8 03004010 */  beqz       $v0, .L800BF6B8
    /* 56EAC 800BF6AC 21186700 */   addu      $v1, $v1, $a3
    /* 56EB0 800BF6B0 AFFD0208 */  j          .L800BF6BC
    /* 56EB4 800BF6B4 2110A200 */   addu      $v0, $a1, $v0
  .L800BF6B8:
    /* 56EB8 800BF6B8 21100000 */  addu       $v0, $zero, $zero
  .L800BF6BC:
    /* 56EBC 800BF6BC 000062AC */  sw         $v0, 0x0($v1)
    /* 56EC0 800BF6C0 01002226 */  addiu      $v0, $s1, 0x1
    /* 56EC4 800BF6C4 21884000 */  addu       $s1, $v0, $zero
    /* 56EC8 800BF6C8 00140200 */  sll        $v0, $v0, 16
    /* 56ECC 800BF6CC 03140200 */  sra        $v0, $v0, 16
    /* 56ED0 800BF6D0 08004228 */  slti       $v0, $v0, 0x8
    /* 56ED4 800BF6D4 EEFF4014 */  bnez       $v0, .L800BF690
    /* 56ED8 800BF6D8 00141100 */   sll       $v0, $s1, 16
    /* 56EDC 800BF6DC A8000424 */  addiu      $a0, $zero, 0xA8
    /* 56EE0 800BF6E0 21280000 */  addu       $a1, $zero, $zero
    /* 56EE4 800BF6E4 0F80023C */  lui        $v0, %hi(D_800F4C38)
    /* 56EE8 800BF6E8 1000C324 */  addiu      $v1, $a2, 0x10
    /* 56EEC 800BF6EC 384C43AC */  sw         $v1, %lo(D_800F4C38)($v0)
    /* 56EF0 800BF6F0 384C4224 */  addiu      $v0, $v0, %lo(D_800F4C38)
    /* 56EF4 800BF6F4 0C0040AC */  sw         $zero, 0xC($v0)
    /* 56EF8 800BF6F8 080040AC */  sw         $zero, 0x8($v0)
    /* 56EFC 800BF6FC 040040AC */  sw         $zero, 0x4($v0)
    /* 56F00 800BF700 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 56F04 800BF704 2C4C40A0 */  sb         $zero, %lo(D_800F4C2C)($v0)
    /* 56F08 800BF708 0F80023C */  lui        $v0, %hi(D_800F4C68)
    /* 56F0C 800BF70C 05FB020C */  jal        vs_battle_setStateFlag
    /* 56F10 800BF710 684C40A0 */   sb        $zero, %lo(D_800F4C68)($v0)
    /* 56F14 800BF714 21880000 */  addu       $s1, $zero, $zero
    /* 56F18 800BF718 0F80023C */  lui        $v0, %hi(vs_battle_textBoxStatuses)
    /* 56F1C 800BF71C 004C4424 */  addiu      $a0, $v0, %lo(vs_battle_textBoxStatuses)
    /* 56F20 800BF720 0F80033C */  lui        $v1, %hi(D_800F4C58)
    /* 56F24 800BF724 584C6224 */  addiu      $v0, $v1, %lo(D_800F4C58)
    /* 56F28 800BF728 060040A4 */  sh         $zero, 0x6($v0)
    /* 56F2C 800BF72C 040040A4 */  sh         $zero, 0x4($v0)
    /* 56F30 800BF730 020040A4 */  sh         $zero, 0x2($v0)
    /* 56F34 800BF734 0F80023C */  lui        $v0, %hi(D_800F4BB9)
    /* 56F38 800BF738 B94B40A0 */  sb         $zero, %lo(D_800F4BB9)($v0)
    /* 56F3C 800BF73C 0F80023C */  lui        $v0, %hi(D_800F4C4E)
    /* 56F40 800BF740 4E4C40A0 */  sb         $zero, %lo(D_800F4C4E)($v0)
    /* 56F44 800BF744 0F80023C */  lui        $v0, %hi(_textBoxSelectionPending)
    /* 56F48 800BF748 604C40A0 */  sb         $zero, %lo(_textBoxSelectionPending)($v0)
    /* 56F4C 800BF74C 0F80023C */  lui        $v0, %hi(D_800F4BE4)
    /* 56F50 800BF750 E44B40A0 */  sb         $zero, %lo(D_800F4BE4)($v0)
    /* 56F54 800BF754 0F80023C */  lui        $v0, %hi(D_800F4BF8)
    /* 56F58 800BF758 F84B40A0 */  sb         $zero, %lo(D_800F4BF8)($v0)
    /* 56F5C 800BF75C 0F80023C */  lui        $v0, %hi(D_800F4BE2)
    /* 56F60 800BF760 E24B40A4 */  sh         $zero, %lo(D_800F4BE2)($v0)
    /* 56F64 800BF764 0F80023C */  lui        $v0, %hi(D_800F4BB6)
    /* 56F68 800BF768 B64B40A4 */  sh         $zero, %lo(D_800F4BB6)($v0)
    /* 56F6C 800BF76C 0F80023C */  lui        $v0, %hi(D_800F4C22)
    /* 56F70 800BF770 584C60A4 */  sh         $zero, %lo(D_800F4C58)($v1)
    /* 56F74 800BF774 224C40A4 */  sh         $zero, %lo(D_800F4C22)($v0)
    /* 56F78 800BF778 00141100 */  sll        $v0, $s1, 16
  .L800BF77C:
    /* 56F7C 800BF77C 03140200 */  sra        $v0, $v0, 16
    /* 56F80 800BF780 21104400 */  addu       $v0, $v0, $a0
    /* 56F84 800BF784 000040A0 */  sb         $zero, 0x0($v0)
    /* 56F88 800BF788 01002226 */  addiu      $v0, $s1, 0x1
    /* 56F8C 800BF78C 21884000 */  addu       $s1, $v0, $zero
    /* 56F90 800BF790 00140200 */  sll        $v0, $v0, 16
    /* 56F94 800BF794 03140200 */  sra        $v0, $v0, 16
    /* 56F98 800BF798 08004228 */  slti       $v0, $v0, 0x8
    /* 56F9C 800BF79C F7FF4014 */  bnez       $v0, .L800BF77C
    /* 56FA0 800BF7A0 00141100 */   sll       $v0, $s1, 16
    /* 56FA4 800BF7A4 21880000 */  addu       $s1, $zero, $zero
    /* 56FA8 800BF7A8 0F80023C */  lui        $v0, %hi(D_800F4B28)
    /* 56FAC 800BF7AC 284B4424 */  addiu      $a0, $v0, %lo(D_800F4B28)
  .L800BF7B0:
    /* 56FB0 800BF7B0 001C1100 */  sll        $v1, $s1, 16
    /* 56FB4 800BF7B4 01002226 */  addiu      $v0, $s1, 0x1
    /* 56FB8 800BF7B8 21884000 */  addu       $s1, $v0, $zero
    /* 56FBC 800BF7BC C31B0300 */  sra        $v1, $v1, 15
    /* 56FC0 800BF7C0 21186400 */  addu       $v1, $v1, $a0
    /* 56FC4 800BF7C4 00140200 */  sll        $v0, $v0, 16
    /* 56FC8 800BF7C8 03140200 */  sra        $v0, $v0, 16
    /* 56FCC 800BF7CC 04004228 */  slti       $v0, $v0, 0x4
    /* 56FD0 800BF7D0 010060A0 */  sb         $zero, 0x1($v1)
    /* 56FD4 800BF7D4 F6FF4014 */  bnez       $v0, .L800BF7B0
    /* 56FD8 800BF7D8 000060A0 */   sb        $zero, 0x0($v1)
    /* 56FDC 800BF7DC 10001124 */  addiu      $s1, $zero, 0x10
    /* 56FE0 800BF7E0 0F80023C */  lui        $v0, %hi(D_800F4B8B)
    /* 56FE4 800BF7E4 8B4B40A0 */  sb         $zero, %lo(D_800F4B8B)($v0)
    /* 56FE8 800BF7E8 0F80023C */  lui        $v0, %hi(D_800F4B30)
    /* 56FEC 800BF7EC 304B4224 */  addiu      $v0, $v0, %lo(D_800F4B30)
    /* 56FF0 800BF7F0 0F80103C */  lui        $s0, %hi(D_800F4C69)
    /* 56FF4 800BF7F4 2B0040A0 */  sb         $zero, 0x2B($v0)
    /* 56FF8 800BF7F8 170040A0 */  sb         $zero, 0x17($v0)
    /* 56FFC 800BF7FC 3514010C */  jal        vs_main_getcurrentMusicSlot
    /* 57000 800BF800 030040A0 */   sb        $zero, 0x3($v0)
    /* 57004 800BF804 694C02A2 */  sb         $v0, %lo(D_800F4C69)($s0)
    /* 57008 800BF808 0F80023C */  lui        $v0, %hi(D_800F4BBC)
    /* 5700C 800BF80C BC4B40AC */  sw         $zero, %lo(D_800F4BBC)($v0)
    /* 57010 800BF810 00241100 */  sll        $a0, $s1, 16
  .L800BF814:
    /* 57014 800BF814 03240400 */  sra        $a0, $a0, 16
    /* 57018 800BF818 05FB020C */  jal        vs_battle_setStateFlag
    /* 5701C 800BF81C 21280000 */   addu      $a1, $zero, $zero
    /* 57020 800BF820 01002226 */  addiu      $v0, $s1, 0x1
    /* 57024 800BF824 21884000 */  addu       $s1, $v0, $zero
    /* 57028 800BF828 00140200 */  sll        $v0, $v0, 16
    /* 5702C 800BF82C 03140200 */  sra        $v0, $v0, 16
    /* 57030 800BF830 20004228 */  slti       $v0, $v0, 0x20
    /* 57034 800BF834 F7FF4014 */  bnez       $v0, .L800BF814
    /* 57038 800BF838 00241100 */   sll       $a0, $s1, 16
    /* 5703C 800BF83C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 57040 800BF840 1400B18F */  lw         $s1, 0x14($sp)
    /* 57044 800BF844 1000B08F */  lw         $s0, 0x10($sp)
    /* 57048 800BF848 0800E003 */  jr         $ra
    /* 5704C 800BF84C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BF5F0
