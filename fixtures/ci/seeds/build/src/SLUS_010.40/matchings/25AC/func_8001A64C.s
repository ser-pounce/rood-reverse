nonmatching func_8001A64C, 0x28C

glabel func_8001A64C
    /* AE4C 8001A64C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* AE50 8001A650 1000B0AF */  sw         $s0, 0x10($sp)
    /* AE54 8001A654 21808000 */  addu       $s0, $a0, $zero
    /* AE58 8001A658 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* AE5C 8001A65C 2198A000 */  addu       $s3, $a1, $zero
    /* AE60 8001A660 0380053C */  lui        $a1, %hi(g_pActiveMusicConfig)
    /* AE64 8001A664 2078A48C */  lw         $a0, %lo(g_pActiveMusicConfig)($a1)
    /* AE68 8001A668 C0300600 */  sll        $a2, $a2, 3
    /* AE6C 8001A66C 2000BFAF */  sw         $ra, 0x20($sp)
    /* AE70 8001A670 1800B2AF */  sw         $s2, 0x18($sp)
    /* AE74 8001A674 1400B1AF */  sw         $s1, 0x14($sp)
    /* AE78 8001A678 4000918C */  lw         $s1, 0x40($a0)
    /* AE7C 8001A67C 1000828C */  lw         $v0, 0x10($a0)
    /* AE80 8001A680 1400838C */  lw         $v1, 0x14($a0)
    /* AE84 8001A684 21882602 */  addu       $s1, $s1, $a2
    /* AE88 8001A688 25105300 */  or         $v0, $v0, $s3
    /* AE8C 8001A68C 24187300 */  and        $v1, $v1, $s3
    /* AE90 8001A690 05006010 */  beqz       $v1, .L8001A6A8
    /* AE94 8001A694 100082AC */   sw        $v0, 0x10($a0)
    /* AE98 8001A698 1800828C */  lw         $v0, 0x18($a0)
    /* AE9C 8001A69C 00000000 */  nop
    /* AEA0 8001A6A0 25105300 */  or         $v0, $v0, $s3
    /* AEA4 8001A6A4 180082AC */  sw         $v0, 0x18($a0)
  .L8001A6A8:
    /* AEA8 8001A6A8 2078A28C */  lw         $v0, %lo(g_pActiveMusicConfig)($a1)
    /* AEAC 8001A6AC 00002592 */  lbu        $a1, 0x0($s1)
    /* AEB0 8001A6B0 0000448C */  lw         $a0, 0x0($v0)
    /* AEB4 8001A6B4 3400128E */  lw         $s2, 0x34($s0)
    /* AEB8 8001A6B8 8B68000C */  jal        func_8001A22C
    /* AEBC 8001A6BC 00000000 */   nop
    /* AEC0 8001A6C0 6A0002A6 */  sh         $v0, 0x6A($s0)
    /* AEC4 8001A6C4 00110200 */  sll        $v0, $v0, 4
    /* AEC8 8001A6C8 0380033C */  lui        $v1, %hi(g_InstrumentInfo)
    /* AECC 8001A6CC 88676324 */  addiu      $v1, $v1, %lo(g_InstrumentInfo)
    /* AED0 8001A6D0 21204300 */  addu       $a0, $v0, $v1
    /* AED4 8001A6D4 0000828C */  lw         $v0, 0x0($a0)
    /* AED8 8001A6D8 00000000 */  nop
    /* AEDC 8001A6DC FC0002AE */  sw         $v0, 0xFC($s0)
    /* AEE0 8001A6E0 0400828C */  lw         $v0, 0x4($a0)
    /* AEE4 8001A6E4 00000000 */  nop
    /* AEE8 8001A6E8 000102AE */  sw         $v0, 0x100($s0)
    /* AEEC 8001A6EC 0001023C */  lui        $v0, (0x1000000 >> 16)
    /* AEF0 8001A6F0 24104202 */  and        $v0, $s2, $v0
    /* AEF4 8001A6F4 04004014 */  bnez       $v0, .L8001A708
    /* AEF8 8001A6F8 00000000 */   nop
    /* AEFC 8001A6FC 02002292 */  lbu        $v0, 0x2($s1)
    /* AF00 8001A700 C5690008 */  j          .L8001A714
    /* AF04 8001A704 00120200 */   sll       $v0, $v0, 8
  .L8001A708:
    /* AF08 8001A708 06010296 */  lhu        $v0, 0x106($s0)
    /* AF0C 8001A70C 00000000 */  nop
    /* AF10 8001A710 007F4230 */  andi       $v0, $v0, 0x7F00
  .L8001A714:
    /* AF14 8001A714 060102A6 */  sh         $v0, 0x106($s0)
    /* AF18 8001A718 0C008294 */  lhu        $v0, 0xC($a0)
    /* AF1C 8001A71C 06010396 */  lhu        $v1, 0x106($s0)
    /* AF20 8001A720 FF804230 */  andi       $v0, $v0, 0x80FF
    /* AF24 8001A724 25186200 */  or         $v1, $v1, $v0
    /* AF28 8001A728 0008023C */  lui        $v0, (0x8000000 >> 16)
    /* AF2C 8001A72C 24104202 */  and        $v0, $s2, $v0
    /* AF30 8001A730 0B004014 */  bnez       $v0, .L8001A760
    /* AF34 8001A734 060103A6 */   sh        $v1, 0x106($s0)
    /* AF38 8001A738 08010396 */  lhu        $v1, 0x108($s0)
    /* AF3C 8001A73C 00000000 */  nop
    /* AF40 8001A740 1F206330 */  andi       $v1, $v1, 0x201F
    /* AF44 8001A744 080103A6 */  sh         $v1, 0x108($s0)
    /* AF48 8001A748 03002292 */  lbu        $v0, 0x3($s1)
    /* AF4C 8001A74C 00000000 */  nop
    /* AF50 8001A750 80110200 */  sll        $v0, $v0, 6
    /* AF54 8001A754 25186200 */  or         $v1, $v1, $v0
    /* AF58 8001A758 DC690008 */  j          .L8001A770
    /* AF5C 8001A75C 080103A6 */   sh        $v1, 0x108($s0)
  .L8001A760:
    /* AF60 8001A760 08010296 */  lhu        $v0, 0x108($s0)
    /* AF64 8001A764 00000000 */  nop
    /* AF68 8001A768 DF3F4230 */  andi       $v0, $v0, 0x3FDF
    /* AF6C 8001A76C 080102A6 */  sh         $v0, 0x108($s0)
  .L8001A770:
    /* AF70 8001A770 04002392 */  lbu        $v1, 0x4($s1)
    /* AF74 8001A774 05000224 */  addiu      $v0, $zero, 0x5
    /* AF78 8001A778 10006210 */  beq        $v1, $v0, .L8001A7BC
    /* AF7C 8001A77C 00000000 */   nop
    /* AF80 8001A780 06006228 */  slti       $v0, $v1, 0x6
    /* AF84 8001A784 05004010 */  beqz       $v0, .L8001A79C
    /* AF88 8001A788 03000224 */   addiu     $v0, $zero, 0x3
    /* AF8C 8001A78C 08006210 */  beq        $v1, $v0, .L8001A7B0
    /* AF90 8001A790 00000000 */   nop
    /* AF94 8001A794 F7690008 */  j          .L8001A7DC
    /* AF98 8001A798 0010023C */   lui       $v0, (0x10000000 >> 16)
  .L8001A79C:
    /* AF9C 8001A79C 07000224 */  addiu      $v0, $zero, 0x7
    /* AFA0 8001A7A0 09006210 */  beq        $v1, $v0, .L8001A7C8
    /* AFA4 8001A7A4 0010023C */   lui       $v0, (0x10000000 >> 16)
    /* AFA8 8001A7A8 F8690008 */  j          .L8001A7E0
    /* AFAC 8001A7AC 24104202 */   and       $v0, $s2, $v0
  .L8001A7B0:
    /* AFB0 8001A7B0 08010296 */  lhu        $v0, 0x108($s0)
    /* AFB4 8001A7B4 F5690008 */  j          .L8001A7D4
    /* AFB8 8001A7B8 00404234 */   ori       $v0, $v0, 0x4000
  .L8001A7BC:
    /* AFBC 8001A7BC 08010296 */  lhu        $v0, 0x108($s0)
    /* AFC0 8001A7C0 F5690008 */  j          .L8001A7D4
    /* AFC4 8001A7C4 00804234 */   ori       $v0, $v0, 0x8000
  .L8001A7C8:
    /* AFC8 8001A7C8 08010296 */  lhu        $v0, 0x108($s0)
    /* AFCC 8001A7CC 00000000 */  nop
    /* AFD0 8001A7D0 00C04234 */  ori        $v0, $v0, 0xC000
  .L8001A7D4:
    /* AFD4 8001A7D4 080102A6 */  sh         $v0, 0x108($s0)
    /* AFD8 8001A7D8 0010023C */  lui        $v0, (0x10000000 >> 16)
  .L8001A7DC:
    /* AFDC 8001A7DC 24104202 */  and        $v0, $s2, $v0
  .L8001A7E0:
    /* AFE0 8001A7E0 09004014 */  bnez       $v0, .L8001A808
    /* AFE4 8001A7E4 00000000 */   nop
    /* AFE8 8001A7E8 08010296 */  lhu        $v0, 0x108($s0)
    /* AFEC 8001A7EC 00000000 */  nop
    /* AFF0 8001A7F0 E0FF4230 */  andi       $v0, $v0, 0xFFE0
    /* AFF4 8001A7F4 080102A6 */  sh         $v0, 0x108($s0)
    /* AFF8 8001A7F8 05002392 */  lbu        $v1, 0x5($s1)
    /* AFFC 8001A7FC 00000000 */  nop
    /* B000 8001A800 25104300 */  or         $v0, $v0, $v1
    /* B004 8001A804 080102A6 */  sh         $v0, 0x108($s0)
  .L8001A808:
    /* B008 8001A808 0E008294 */  lhu        $v0, 0xE($a0)
    /* B00C 8001A80C 08010396 */  lhu        $v1, 0x108($s0)
    /* B010 8001A810 E4000686 */  lh         $a2, 0xE4($s0)
    /* B014 8001A814 20004230 */  andi       $v0, $v0, 0x20
    /* B018 8001A818 25186200 */  or         $v1, $v1, $v0
    /* B01C 8001A81C 080103A6 */  sh         $v1, 0x108($s0)
    /* B020 8001A820 01002592 */  lbu        $a1, 0x1($s1)
    /* B024 8001A824 2F69000C */  jal        func_8001A4BC
    /* B028 8001A828 54000726 */   addiu     $a3, $s0, 0x54
    /* B02C 8001A82C 06002392 */  lbu        $v1, 0x6($s1)
    /* B030 8001A830 00000000 */  nop
    /* B034 8001A834 0A0103A6 */  sh         $v1, 0x10A($s0)
    /* B038 8001A838 07002392 */  lbu        $v1, 0x7($s1)
    /* B03C 8001A83C 00000000 */  nop
    /* B040 8001A840 7F006330 */  andi       $v1, $v1, 0x7F
    /* B044 8001A844 40006324 */  addiu      $v1, $v1, 0x40
    /* B048 8001A848 001A0300 */  sll        $v1, $v1, 8
    /* B04C 8001A84C 8E0003A6 */  sh         $v1, 0x8E($s0)
    /* B050 8001A850 07002392 */  lbu        $v1, 0x7($s1)
    /* B054 8001A854 00000000 */  nop
    /* B058 8001A858 80006330 */  andi       $v1, $v1, 0x80
    /* B05C 8001A85C 09006010 */  beqz       $v1, .L8001A884
    /* B060 8001A860 21284000 */   addu      $a1, $v0, $zero
    /* B064 8001A864 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* B068 8001A868 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* B06C 8001A86C 00000000 */  nop
    /* B070 8001A870 5000628C */  lw         $v0, 0x50($v1)
    /* B074 8001A874 00000000 */  nop
    /* B078 8001A878 25105300 */  or         $v0, $v0, $s3
    /* B07C 8001A87C 286A0008 */  j          .L8001A8A0
    /* B080 8001A880 500062AC */   sw        $v0, 0x50($v1)
  .L8001A884:
    /* B084 8001A884 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* B088 8001A888 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* B08C 8001A88C 00000000 */  nop
    /* B090 8001A890 5000828C */  lw         $v0, 0x50($a0)
    /* B094 8001A894 27181300 */  nor        $v1, $zero, $s3
    /* B098 8001A898 24104300 */  and        $v0, $v0, $v1
    /* B09C 8001A89C 500082AC */  sw         $v0, 0x50($a0)
  .L8001A8A0:
    /* B0A0 8001A8A0 0480043C */  lui        $a0, %hi(g_Sound_GlobalFlags)
    /* B0A4 8001A8A4 F89A8424 */  addiu      $a0, $a0, %lo(g_Sound_GlobalFlags)
    /* B0A8 8001A8A8 0800838C */  lw         $v1, 0x8($a0)
    /* B0AC 8001A8AC 00000000 */  nop
    /* B0B0 8001A8B0 00016334 */  ori        $v1, $v1, 0x100
    /* B0B4 8001A8B4 080083AC */  sw         $v1, 0x8($a0)
    /* B0B8 8001A8B8 2000BF8F */  lw         $ra, 0x20($sp)
    /* B0BC 8001A8BC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* B0C0 8001A8C0 1800B28F */  lw         $s2, 0x18($sp)
    /* B0C4 8001A8C4 1400B18F */  lw         $s1, 0x14($sp)
    /* B0C8 8001A8C8 1000B08F */  lw         $s0, 0x10($sp)
    /* B0CC 8001A8CC 2110A000 */  addu       $v0, $a1, $zero
    /* B0D0 8001A8D0 0800E003 */  jr         $ra
    /* B0D4 8001A8D4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8001A64C
