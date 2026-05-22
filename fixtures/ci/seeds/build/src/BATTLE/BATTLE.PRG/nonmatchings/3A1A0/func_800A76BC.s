nonmatching func_800A76BC, 0x1478

glabel func_800A76BC
    /* 3EEBC 800A76BC 50FFBD27 */  addiu      $sp, $sp, -0xB0
    /* 3EEC0 800A76C0 A000B6AF */  sw         $s6, 0xA0($sp)
    /* 3EEC4 800A76C4 21B08000 */  addu       $s6, $a0, $zero
    /* 3EEC8 800A76C8 8800B0AF */  sw         $s0, 0x88($sp)
    /* 3EECC 800A76CC 2180E000 */  addu       $s0, $a3, $zero
    /* 3EED0 800A76D0 801F083C */  lui        $t0, (0x1F8003BC >> 16)
    /* 3EED4 800A76D4 BC030835 */  ori        $t0, $t0, (0x1F8003BC & 0xFFFF)
    /* 3EED8 800A76D8 00020424 */  addiu      $a0, $zero, 0x200
    /* 3EEDC 800A76DC FFBF0224 */  addiu      $v0, $zero, -0x4001
    /* 3EEE0 800A76E0 AC00BFAF */  sw         $ra, 0xAC($sp)
    /* 3EEE4 800A76E4 A800BEAF */  sw         $fp, 0xA8($sp)
    /* 3EEE8 800A76E8 A400B7AF */  sw         $s7, 0xA4($sp)
    /* 3EEEC 800A76EC 9C00B5AF */  sw         $s5, 0x9C($sp)
    /* 3EEF0 800A76F0 9800B4AF */  sw         $s4, 0x98($sp)
    /* 3EEF4 800A76F4 9400B3AF */  sw         $s3, 0x94($sp)
    /* 3EEF8 800A76F8 9000B2AF */  sw         $s2, 0x90($sp)
    /* 3EEFC 800A76FC 8C00B1AF */  sw         $s1, 0x8C($sp)
    /* 3EF00 800A7700 B400A5AF */  sw         $a1, 0xB4($sp)
    /* 3EF04 800A7704 B800A6AF */  sw         $a2, 0xB8($sp)
    /* 3EF08 800A7708 8000A8AF */  sw         $t0, 0x80($sp)
    /* 3EF0C 800A770C 180016AD */  sw         $s6, 0x18($t0)
    /* 3EF10 800A7710 AC05C38E */  lw         $v1, 0x5AC($s6)
    /* 3EF14 800A7714 3C06C896 */  lhu        $t0, 0x63C($s6)
    /* 3EF18 800A7718 24106200 */  and        $v0, $v1, $v0
    /* 3EF1C 800A771C 40180300 */  sll        $v1, $v1, 1
    /* 3EF20 800A7720 00406330 */  andi       $v1, $v1, 0x4000
    /* 3EF24 800A7724 25104300 */  or         $v0, $v0, $v1
    /* 3EF28 800A7728 FFDF0324 */  addiu      $v1, $zero, -0x2001
    /* 3EF2C 800A772C 24104300 */  and        $v0, $v0, $v1
    /* 3EF30 800A7730 AC05C2AE */  sw         $v0, 0x5AC($s6)
    /* 3EF34 800A7734 CA03010C */  jal        rsin
    /* 3EF38 800A7738 7C00A8AF */   sw        $t0, 0x7C($sp)
    /* 3EF3C 800A773C 7C00A88F */  lw         $t0, 0x7C($sp)
    /* 3EF40 800A7740 00000000 */  nop
    /* 3EF44 800A7744 18004800 */  mult       $v0, $t0
    /* 3EF48 800A7748 12280000 */  mflo       $a1
    /* 3EF4C 800A774C 0200A104 */  bgez       $a1, .L800A7758
    /* 3EF50 800A7750 40FF0224 */   addiu     $v0, $zero, -0xC0
    /* 3EF54 800A7754 FF0FA524 */  addiu      $a1, $a1, 0xFFF
  .L800A7758:
    /* 3EF58 800A7758 8000A88F */  lw         $t0, 0x80($sp)
    /* 3EF5C 800A775C 032B0500 */  sra        $a1, $a1, 12
    /* 3EF60 800A7760 000002AD */  sw         $v0, 0x0($t0)
    /* 3EF64 800A7764 7800A5AF */  sw         $a1, 0x78($sp)
    /* 3EF68 800A7768 0800C28E */  lw         $v0, 0x8($s6)
    /* 3EF6C 800A776C 8000033C */  lui        $v1, (0x800000 >> 16)
    /* 3EF70 800A7770 24104300 */  and        $v0, $v0, $v1
    /* 3EF74 800A7774 0D004014 */  bnez       $v0, .L800A77AC
    /* 3EF78 800A7778 C0FF0224 */   addiu     $v0, $zero, -0x40
    /* 3EF7C 800A777C AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3EF80 800A7780 00000000 */  nop
    /* 3EF84 800A7784 08004230 */  andi       $v0, $v0, 0x8
    /* 3EF88 800A7788 06004010 */  beqz       $v0, .L800A77A4
    /* 3EF8C 800A778C C0FE0224 */   addiu     $v0, $zero, -0x140
    /* 3EF90 800A7790 8000A88F */  lw         $t0, 0x80($sp)
    /* 3EF94 800A7794 00000000 */  nop
    /* 3EF98 800A7798 000002AD */  sw         $v0, 0x0($t0)
    /* 3EF9C 800A779C EB9D0208 */  j          .L800A77AC
    /* 3EFA0 800A77A0 C0FF0224 */   addiu     $v0, $zero, -0x40
  .L800A77A4:
    /* 3EFA4 800A77A4 8000A88F */  lw         $t0, 0x80($sp)
    /* 3EFA8 800A77A8 00FF0224 */  addiu      $v0, $zero, -0x100
  .L800A77AC:
    /* 3EFAC 800A77AC 42000012 */  beqz       $s0, .L800A78B8
    /* 3EFB0 800A77B0 400002AD */   sw        $v0, 0x40($t0)
    /* 3EFB4 800A77B4 00FF0224 */  addiu      $v0, $zero, -0x100
    /* 3EFB8 800A77B8 8000A88F */  lw         $t0, 0x80($sp)
    /* 3EFBC 800A77BC FFFB0324 */  addiu      $v1, $zero, -0x401
    /* 3EFC0 800A77C0 400002AD */  sw         $v0, 0x40($t0)
    /* 3EFC4 800A77C4 AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3EFC8 800A77C8 FFEF0424 */  addiu      $a0, $zero, -0x1001
    /* 3EFCC 800A77CC 24104300 */  and        $v0, $v0, $v1
    /* 3EFD0 800A77D0 0C00C38E */  lw         $v1, 0xC($s6)
    /* 3EFD4 800A77D4 24104400 */  and        $v0, $v0, $a0
    /* 3EFD8 800A77D8 0F006330 */  andi       $v1, $v1, 0xF
    /* 3EFDC 800A77DC 0A006014 */  bnez       $v1, .L800A7808
    /* 3EFE0 800A77E0 AC05C2AE */   sw        $v0, 0x5AC($s6)
    /* 3EFE4 800A77E4 5D00C592 */  lbu        $a1, 0x5D($s6)
    /* 3EFE8 800A77E8 59A3020C */  jal        func_800A8D64
    /* 3EFEC 800A77EC 1C00C426 */   addiu     $a0, $s6, 0x1C
    /* 3EFF0 800A77F0 05004014 */  bnez       $v0, .L800A7808
    /* 3EFF4 800A77F4 6800A2AF */   sw        $v0, 0x68($sp)
    /* 3EFF8 800A77F8 AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3EFFC 800A77FC 00000000 */  nop
    /* 3F000 800A7800 00044234 */  ori        $v0, $v0, 0x400
    /* 3F004 800A7804 AC05C2AE */  sw         $v0, 0x5AC($s6)
  .L800A7808:
    /* 3F008 800A7808 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F00C 800A780C 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3F010 800A7810 00000395 */  lhu        $v1, 0x0($t0)
    /* 3F014 800A7814 4800A427 */  addiu      $a0, $sp, 0x48
    /* 3F018 800A7818 21104300 */  addu       $v0, $v0, $v1
    /* 3F01C 800A781C 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3F020 800A7820 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3F024 800A7824 04000395 */  lhu        $v1, 0x4($t0)
    /* 3F028 800A7828 8000A88F */  lw         $t0, 0x80($sp)
    /* 3F02C 800A782C 21104300 */  addu       $v0, $v0, $v1
    /* 3F030 800A7830 4C00A2A7 */  sh         $v0, 0x4C($sp)
    /* 3F034 800A7834 1E00C296 */  lhu        $v0, 0x1E($s6)
    /* 3F038 800A7838 21280000 */  addu       $a1, $zero, $zero
    /* 3F03C 800A783C 000000AD */  sw         $zero, 0x0($t0)
    /* 3F040 800A7840 CDA2020C */  jal        func_800A8B34
    /* 3F044 800A7844 1C0002A5 */   sh        $v0, 0x1C($t0)
    /* 3F048 800A7848 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3F04C 800A784C 0F80023C */  lui        $v0, %hi(D_800F4B08)
    /* 3F050 800A7850 084B4624 */  addiu      $a2, $v0, %lo(D_800F4B08)
    /* 3F054 800A7854 4B00A38B */  lwl        $v1, 0x4B($sp)
    /* 3F058 800A7858 4800A39B */  lwr        $v1, 0x48($sp)
    /* 3F05C 800A785C 4F00A48B */  lwl        $a0, 0x4F($sp)
    /* 3F060 800A7860 4C00A49B */  lwr        $a0, 0x4C($sp)
    /* 3F064 800A7864 0300C3A8 */  swl        $v1, 0x3($a2)
    /* 3F068 800A7868 0000C3B8 */  swr        $v1, 0x0($a2)
    /* 3F06C 800A786C 0700C4A8 */  swl        $a0, 0x7($a2)
    /* 3F070 800A7870 0400C4B8 */  swr        $a0, 0x4($a2)
    /* 3F074 800A7874 1000A48F */  lw         $a0, 0x10($sp)
    /* 3F078 800A7878 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3F07C 800A787C 04008214 */  bne        $a0, $v0, .L800A7890
    /* 3F080 800A7880 0F80033C */   lui       $v1, %hi(D_800F49F0)
    /* 3F084 800A7884 B800A88F */  lw         $t0, 0xB8($sp)
    /* 3F088 800A7888 BFA20208 */  j          .L800A8AFC
    /* 3F08C 800A788C 000000AD */   sw        $zero, 0x0($t0)
  .L800A7890:
    /* 3F090 800A7890 6800A28F */  lw         $v0, 0x68($sp)
    /* 3F094 800A7894 B800A88F */  lw         $t0, 0xB8($sp)
    /* 3F098 800A7898 F04962AC */  sw         $v0, %lo(D_800F49F0)($v1)
    /* 3F09C 800A789C 02008228 */  slti       $v0, $a0, 0x2
    /* 3F0A0 800A78A0 03004014 */  bnez       $v0, .L800A78B0
    /* 3F0A4 800A78A4 000004AD */   sw        $a0, 0x0($t0)
    /* 3F0A8 800A78A8 01000224 */  addiu      $v0, $zero, 0x1
    /* 3F0AC 800A78AC 000002AD */  sw         $v0, 0x0($t0)
  .L800A78B0:
    /* 3F0B0 800A78B0 C0A20208 */  j          .L800A8B00
    /* 3F0B4 800A78B4 21100000 */   addu      $v0, $zero, $zero
  .L800A78B8:
    /* 3F0B8 800A78B8 B400A58F */  lw         $a1, 0xB4($sp)
    /* 3F0BC 800A78BC F5A3020C */  jal        func_800A8FD4
    /* 3F0C0 800A78C0 2120C002 */   addu      $a0, $s6, $zero
    /* 3F0C4 800A78C4 8E044010 */  beqz       $v0, .L800A8B00
    /* 3F0C8 800A78C8 03000224 */   addiu     $v0, $zero, 0x3
    /* 3F0CC 800A78CC 7800A58F */  lw         $a1, 0x78($sp)
    /* 3F0D0 800A78D0 379C020C */  jal        func_800A70DC
    /* 3F0D4 800A78D4 2120C002 */   addu      $a0, $s6, $zero
    /* 3F0D8 800A78D8 B400A58F */  lw         $a1, 0xB4($sp)
    /* 3F0DC 800A78DC 499D020C */  jal        func_800A7524
    /* 3F0E0 800A78E0 2120C002 */   addu      $a0, $s6, $zero
    /* 3F0E4 800A78E4 FFFB1024 */  addiu      $s0, $zero, -0x401
    /* 3F0E8 800A78E8 AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3F0EC 800A78EC 0C00C38E */  lw         $v1, 0xC($s6)
    /* 3F0F0 800A78F0 24105000 */  and        $v0, $v0, $s0
    /* 3F0F4 800A78F4 0F006330 */  andi       $v1, $v1, 0xF
    /* 3F0F8 800A78F8 0D006014 */  bnez       $v1, .L800A7930
    /* 3F0FC 800A78FC AC05C2AE */   sw        $v0, 0x5AC($s6)
    /* 3F100 800A7900 5D00C592 */  lbu        $a1, 0x5D($s6)
    /* 3F104 800A7904 59A3020C */  jal        func_800A8D64
    /* 3F108 800A7908 1C00C426 */   addiu     $a0, $s6, 0x1C
    /* 3F10C 800A790C 04004014 */  bnez       $v0, .L800A7920
    /* 3F110 800A7910 6800A2AF */   sw        $v0, 0x68($sp)
    /* 3F114 800A7914 AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3F118 800A7918 4B9E0208 */  j          .L800A792C
    /* 3F11C 800A791C 00044234 */   ori       $v0, $v0, 0x400
  .L800A7920:
    /* 3F120 800A7920 AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3F124 800A7924 00000000 */  nop
    /* 3F128 800A7928 24105000 */  and        $v0, $v0, $s0
  .L800A792C:
    /* 3F12C 800A792C AC05C2AE */  sw         $v0, 0x5AC($s6)
  .L800A7930:
    /* 3F130 800A7930 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F134 800A7934 00000000 */  nop
    /* 3F138 800A7938 00000385 */  lh         $v1, 0x0($t0)
    /* 3F13C 800A793C 00000000 */  nop
    /* 3F140 800A7940 03006014 */  bnez       $v1, .L800A7950
    /* 3F144 800A7944 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 3F148 800A7948 539F0208 */  j          .L800A7D4C
    /* 3F14C 800A794C 1000A2AF */   sw        $v0, 0x10($sp)
  .L800A7950:
    /* 3F150 800A7950 04000285 */  lh         $v0, 0x4($t0)
    /* 3F154 800A7954 00000000 */  nop
    /* 3F158 800A7958 03004014 */  bnez       $v0, .L800A7968
    /* 3F15C 800A795C FF000224 */   addiu     $v0, $zero, 0xFF
    /* 3F160 800A7960 FF9E0208 */  j          .L800A7BFC
    /* 3F164 800A7964 2800A2AF */   sw        $v0, 0x28($sp)
  .L800A7968:
    /* 3F168 800A7968 08006104 */  bgez       $v1, .L800A798C
    /* 3F16C 800A796C 06001324 */   addiu     $s3, $zero, 0x6
    /* 3F170 800A7970 7C00A88F */  lw         $t0, 0x7C($sp)
    /* 3F174 800A7974 00000000 */  nop
    /* 3F178 800A7978 23A00800 */  negu       $s4, $t0
    /* 3F17C 800A797C 7800A88F */  lw         $t0, 0x78($sp)
    /* 3F180 800A7980 02001324 */  addiu      $s3, $zero, 0x2
    /* 3F184 800A7984 659E0208 */  j          .L800A7994
    /* 3F188 800A7988 23A80800 */   negu      $s5, $t0
  .L800A798C:
    /* 3F18C 800A798C 7C00B48F */  lw         $s4, 0x7C($sp)
    /* 3F190 800A7990 7800B58F */  lw         $s5, 0x78($sp)
  .L800A7994:
    /* 3F194 800A7994 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F198 800A7998 00000000 */  nop
    /* 3F19C 800A799C 04000285 */  lh         $v0, 0x4($t0)
    /* 3F1A0 800A79A0 00000000 */  nop
    /* 3F1A4 800A79A4 0B004104 */  bgez       $v0, .L800A79D4
    /* 3F1A8 800A79A8 02000224 */   addiu     $v0, $zero, 0x2
    /* 3F1AC 800A79AC 7C00A88F */  lw         $t0, 0x7C($sp)
    /* 3F1B0 800A79B0 00000000 */  nop
    /* 3F1B4 800A79B4 23B80800 */  negu       $s7, $t0
    /* 3F1B8 800A79B8 7800A88F */  lw         $t0, 0x78($sp)
    /* 3F1BC 800A79BC 03006216 */  bne        $s3, $v0, .L800A79CC
    /* 3F1C0 800A79C0 23F00800 */   negu      $fp, $t0
    /* 3F1C4 800A79C4 7A9E0208 */  j          .L800A79E8
    /* 3F1C8 800A79C8 01001324 */   addiu     $s3, $zero, 0x1
  .L800A79CC:
    /* 3F1CC 800A79CC 7A9E0208 */  j          .L800A79E8
    /* 3F1D0 800A79D0 07001324 */   addiu     $s3, $zero, 0x7
  .L800A79D4:
    /* 3F1D4 800A79D4 7C00B78F */  lw         $s7, 0x7C($sp)
    /* 3F1D8 800A79D8 7800BE8F */  lw         $fp, 0x78($sp)
    /* 3F1DC 800A79DC 02006216 */  bne        $s3, $v0, .L800A79E8
    /* 3F1E0 800A79E0 05001324 */   addiu     $s3, $zero, 0x5
    /* 3F1E4 800A79E4 03001324 */  addiu      $s3, $zero, 0x3
  .L800A79E8:
    /* 3F1E8 800A79E8 4800B127 */  addiu      $s1, $sp, 0x48
    /* 3F1EC 800A79EC 21202002 */  addu       $a0, $s1, $zero
    /* 3F1F0 800A79F0 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F1F4 800A79F4 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3F1F8 800A79F8 00000395 */  lhu        $v1, 0x0($t0)
    /* 3F1FC 800A79FC 21286002 */  addu       $a1, $s3, $zero
    /* 3F200 800A7A00 21104300 */  addu       $v0, $v0, $v1
    /* 3F204 800A7A04 21105500 */  addu       $v0, $v0, $s5
    /* 3F208 800A7A08 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3F20C 800A7A0C 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3F210 800A7A10 04000395 */  lhu        $v1, 0x4($t0)
    /* 3F214 800A7A14 FEFF7326 */  addiu      $s3, $s3, -0x2
    /* 3F218 800A7A18 21104300 */  addu       $v0, $v0, $v1
    /* 3F21C 800A7A1C 21105E00 */  addu       $v0, $v0, $fp
    /* 3F220 800A7A20 CDA2020C */  jal        func_800A8B34
    /* 3F224 800A7A24 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F228 800A7A28 0F80123C */  lui        $s2, %hi(D_800F4B08)
    /* 3F22C 800A7A2C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3F230 800A7A30 084B4526 */  addiu      $a1, $s2, %lo(D_800F4B08)
    /* 3F234 800A7A34 4B00A28B */  lwl        $v0, 0x4B($sp)
    /* 3F238 800A7A38 4800A29B */  lwr        $v0, 0x48($sp)
    /* 3F23C 800A7A3C 4F00A38B */  lwl        $v1, 0x4F($sp)
    /* 3F240 800A7A40 4C00A39B */  lwr        $v1, 0x4C($sp)
    /* 3F244 800A7A44 0300A2A8 */  swl        $v0, 0x3($a1)
    /* 3F248 800A7A48 0000A2B8 */  swr        $v0, 0x0($a1)
    /* 3F24C 800A7A4C 0700A3A8 */  swl        $v1, 0x7($a1)
    /* 3F250 800A7A50 0400A3B8 */  swr        $v1, 0x4($a1)
    /* 3F254 800A7A54 21202002 */  addu       $a0, $s1, $zero
    /* 3F258 800A7A58 21286002 */  addu       $a1, $s3, $zero
    /* 3F25C 800A7A5C 0F80083C */  lui        $t0, %hi(D_800F49F0)
    /* 3F260 800A7A60 04007326 */  addiu      $s3, $s3, 0x4
    /* 3F264 800A7A64 F049028D */  lw         $v0, %lo(D_800F49F0)($t0)
    /* 3F268 800A7A68 40801500 */  sll        $s0, $s5, 1
    /* 3F26C 800A7A6C 6800A2AF */  sw         $v0, 0x68($sp)
    /* 3F270 800A7A70 4800A297 */  lhu        $v0, 0x48($sp)
    /* 3F274 800A7A74 084B5226 */  addiu      $s2, $s2, %lo(D_800F4B08)
    /* 3F278 800A7A78 23105000 */  subu       $v0, $v0, $s0
    /* 3F27C 800A7A7C CDA2020C */  jal        func_800A8B34
    /* 3F280 800A7A80 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 3F284 800A7A84 21202002 */  addu       $a0, $s1, $zero
    /* 3F288 800A7A88 21286002 */  addu       $a1, $s3, $zero
    /* 3F28C 800A7A8C 4800A397 */  lhu        $v1, 0x48($sp)
    /* 3F290 800A7A90 FDFF7326 */  addiu      $s3, $s3, -0x3
    /* 3F294 800A7A94 1400A2AF */  sw         $v0, 0x14($sp)
    /* 3F298 800A7A98 4C00A297 */  lhu        $v0, 0x4C($sp)
    /* 3F29C 800A7A9C 21187000 */  addu       $v1, $v1, $s0
    /* 3F2A0 800A7AA0 4800A3A7 */  sh         $v1, 0x48($sp)
    /* 3F2A4 800A7AA4 40181E00 */  sll        $v1, $fp, 1
    /* 3F2A8 800A7AA8 23104300 */  subu       $v0, $v0, $v1
    /* 3F2AC 800A7AAC CDA2020C */  jal        func_800A8B34
    /* 3F2B0 800A7AB0 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F2B4 800A7AB4 21202002 */  addu       $a0, $s1, $zero
    /* 3F2B8 800A7AB8 21286002 */  addu       $a1, $s3, $zero
    /* 3F2BC 800A7ABC 4800A397 */  lhu        $v1, 0x48($sp)
    /* 3F2C0 800A7AC0 02007326 */  addiu      $s3, $s3, 0x2
    /* 3F2C4 800A7AC4 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3F2C8 800A7AC8 4C00A297 */  lhu        $v0, 0x4C($sp)
    /* 3F2CC 800A7ACC 23187500 */  subu       $v1, $v1, $s5
    /* 3F2D0 800A7AD0 4800A3A7 */  sh         $v1, 0x48($sp)
    /* 3F2D4 800A7AD4 2118D703 */  addu       $v1, $fp, $s7
    /* 3F2D8 800A7AD8 21104300 */  addu       $v0, $v0, $v1
    /* 3F2DC 800A7ADC CDA2020C */  jal        func_800A8B34
    /* 3F2E0 800A7AE0 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F2E4 800A7AE4 21202002 */  addu       $a0, $s1, $zero
    /* 3F2E8 800A7AE8 21286002 */  addu       $a1, $s3, $zero
    /* 3F2EC 800A7AEC 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 3F2F0 800A7AF0 4800A297 */  lhu        $v0, 0x48($sp)
    /* 3F2F4 800A7AF4 4C00A397 */  lhu        $v1, 0x4C($sp)
    /* 3F2F8 800A7AF8 21105400 */  addu       $v0, $v0, $s4
    /* 3F2FC 800A7AFC 23187700 */  subu       $v1, $v1, $s7
    /* 3F300 800A7B00 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3F304 800A7B04 CDA2020C */  jal        func_800A8B34
    /* 3F308 800A7B08 4C00A3A7 */   sh        $v1, 0x4C($sp)
    /* 3F30C 800A7B0C 21204000 */  addu       $a0, $v0, $zero
    /* 3F310 800A7B10 2000A4AF */  sw         $a0, 0x20($sp)
    /* 3F314 800A7B14 02004386 */  lh         $v1, 0x2($s2)
    /* 3F318 800A7B18 1E00C286 */  lh         $v0, 0x1E($s6)
    /* 3F31C 800A7B1C 00000000 */  nop
    /* 3F320 800A7B20 23A06200 */  subu       $s4, $v1, $v0
    /* 3F324 800A7B24 02008106 */  bgez       $s4, .L800A7B30
    /* 3F328 800A7B28 21108002 */   addu      $v0, $s4, $zero
    /* 3F32C 800A7B2C 3F008226 */  addiu      $v0, $s4, 0x3F
  .L800A7B30:
    /* 3F330 800A7B30 83A90200 */  sra        $s5, $v0, 6
    /* 3F334 800A7B34 3F008232 */  andi       $v0, $s4, 0x3F
    /* 3F338 800A7B38 02004010 */  beqz       $v0, .L800A7B44
    /* 3F33C 800A7B3C 00000000 */   nop
    /* 3F340 800A7B40 FFFFB526 */  addiu      $s5, $s5, -0x1
  .L800A7B44:
    /* 3F344 800A7B44 23A81500 */  negu       $s5, $s5
    /* 3F348 800A7B48 0200A01E */  bgtz       $s5, .L800A7B54
    /* 3F34C 800A7B4C 00000000 */   nop
    /* 3F350 800A7B50 01001524 */  addiu      $s5, $zero, 0x1
  .L800A7B54:
    /* 3F354 800A7B54 1000A68F */  lw         $a2, 0x10($sp)
    /* 3F358 800A7B58 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3F35C 800A7B5C 2100C210 */  beq        $a2, $v0, .L800A7BE4
    /* 3F360 800A7B60 00000000 */   nop
    /* 3F364 800A7B64 1400A28F */  lw         $v0, 0x14($sp)
    /* 3F368 800A7B68 00000000 */  nop
    /* 3F36C 800A7B6C 2A10A202 */  slt        $v0, $s5, $v0
    /* 3F370 800A7B70 1C004014 */  bnez       $v0, .L800A7BE4
    /* 3F374 800A7B74 00000000 */   nop
    /* 3F378 800A7B78 1800A28F */  lw         $v0, 0x18($sp)
    /* 3F37C 800A7B7C 00000000 */  nop
    /* 3F380 800A7B80 2A10A202 */  slt        $v0, $s5, $v0
    /* 3F384 800A7B84 17004014 */  bnez       $v0, .L800A7BE4
    /* 3F388 800A7B88 00000000 */   nop
    /* 3F38C 800A7B8C 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 3F390 800A7B90 00000000 */  nop
    /* 3F394 800A7B94 2A10A202 */  slt        $v0, $s5, $v0
    /* 3F398 800A7B98 12004014 */  bnez       $v0, .L800A7BE4
    /* 3F39C 800A7B9C 2A10A402 */   slt       $v0, $s5, $a0
    /* 3F3A0 800A7BA0 10004014 */  bnez       $v0, .L800A7BE4
    /* 3F3A4 800A7BA4 0400C228 */   slti      $v0, $a2, 0x4
    /* 3F3A8 800A7BA8 04004014 */  bnez       $v0, .L800A7BBC
    /* 3F3AC 800A7BAC 21100000 */   addu      $v0, $zero, $zero
    /* 3F3B0 800A7BB0 01006232 */  andi       $v0, $s3, 0x1
    /* 3F3B4 800A7BB4 0B004010 */  beqz       $v0, .L800A7BE4
    /* 3F3B8 800A7BB8 21100000 */   addu      $v0, $zero, $zero
  .L800A7BBC:
    /* 3F3BC 800A7BBC 0F80033C */  lui        $v1, %hi(D_800F49F9)
    /* 3F3C0 800A7BC0 FFFF6426 */  addiu      $a0, $s3, -0x1
    /* 3F3C4 800A7BC4 6800A58F */  lw         $a1, 0x68($sp)
    /* 3F3C8 800A7BC8 0F80083C */  lui        $t0, %hi(D_800F49F0)
    /* 3F3CC 800A7BCC F04905AD */  sw         $a1, %lo(D_800F49F0)($t0)
    /* 3F3D0 800A7BD0 B800A88F */  lw         $t0, 0xB8($sp)
    /* 3F3D4 800A7BD4 07008430 */  andi       $a0, $a0, 0x7
    /* 3F3D8 800A7BD8 F94964A0 */  sb         $a0, %lo(D_800F49F9)($v1)
    /* 3F3DC 800A7BDC C0A20208 */  j          .L800A8B00
    /* 3F3E0 800A7BE0 000006AD */   sw        $a2, 0x0($t0)
  .L800A7BE4:
    /* 3F3E4 800A7BE4 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F3E8 800A7BE8 00000000 */  nop
    /* 3F3EC 800A7BEC 00000285 */  lh         $v0, 0x0($t0)
    /* 3F3F0 800A7BF0 00000000 */  nop
    /* 3F3F4 800A7BF4 4E004010 */  beqz       $v0, .L800A7D30
    /* 3F3F8 800A7BF8 FF000224 */   addiu     $v0, $zero, 0xFF
  .L800A7BFC:
    /* 3F3FC 800A7BFC B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F400 800A7C00 00000000 */  nop
    /* 3F404 800A7C04 00000285 */  lh         $v0, 0x0($t0)
    /* 3F408 800A7C08 00000000 */  nop
    /* 3F40C 800A7C0C 08004104 */  bgez       $v0, .L800A7C30
    /* 3F410 800A7C10 06001324 */   addiu     $s3, $zero, 0x6
    /* 3F414 800A7C14 7C00A88F */  lw         $t0, 0x7C($sp)
    /* 3F418 800A7C18 00000000 */  nop
    /* 3F41C 800A7C1C 23A00800 */  negu       $s4, $t0
    /* 3F420 800A7C20 7800A88F */  lw         $t0, 0x78($sp)
    /* 3F424 800A7C24 02001324 */  addiu      $s3, $zero, 0x2
    /* 3F428 800A7C28 0E9F0208 */  j          .L800A7C38
    /* 3F42C 800A7C2C 23A80800 */   negu      $s5, $t0
  .L800A7C30:
    /* 3F430 800A7C30 7C00B48F */  lw         $s4, 0x7C($sp)
    /* 3F434 800A7C34 7800B58F */  lw         $s5, 0x78($sp)
  .L800A7C38:
    /* 3F438 800A7C38 4800B027 */  addiu      $s0, $sp, 0x48
    /* 3F43C 800A7C3C B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F440 800A7C40 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3F444 800A7C44 00000395 */  lhu        $v1, 0x0($t0)
    /* 3F448 800A7C48 21200002 */  addu       $a0, $s0, $zero
    /* 3F44C 800A7C4C 21104300 */  addu       $v0, $v0, $v1
    /* 3F450 800A7C50 21105400 */  addu       $v0, $v0, $s4
    /* 3F454 800A7C54 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3F458 800A7C58 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3F45C 800A7C5C 21286002 */  addu       $a1, $s3, $zero
    /* 3F460 800A7C60 CDA2020C */  jal        func_800A8B34
    /* 3F464 800A7C64 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F468 800A7C68 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3F46C 800A7C6C 4800A28F */  lw         $v0, 0x48($sp)
    /* 3F470 800A7C70 4C00A38F */  lw         $v1, 0x4C($sp)
    /* 3F474 800A7C74 5800A2AF */  sw         $v0, 0x58($sp)
    /* 3F478 800A7C78 5C00A3AF */  sw         $v1, 0x5C($sp)
    /* 3F47C 800A7C7C 4000B3AF */  sw         $s3, 0x40($sp)
    /* 3F480 800A7C80 FEFF7326 */  addiu      $s3, $s3, -0x2
    /* 3F484 800A7C84 21200002 */  addu       $a0, $s0, $zero
    /* 3F488 800A7C88 21286002 */  addu       $a1, $s3, $zero
    /* 3F48C 800A7C8C 0F80023C */  lui        $v0, %hi(D_800F49F0)
    /* 3F490 800A7C90 F049428C */  lw         $v0, %lo(D_800F49F0)($v0)
    /* 3F494 800A7C94 4C00A397 */  lhu        $v1, 0x4C($sp)
    /* 3F498 800A7C98 04007326 */  addiu      $s3, $s3, 0x4
    /* 3F49C 800A7C9C 6800A2AF */  sw         $v0, 0x68($sp)
    /* 3F4A0 800A7CA0 4800A297 */  lhu        $v0, 0x48($sp)
    /* 3F4A4 800A7CA4 21187400 */  addu       $v1, $v1, $s4
    /* 3F4A8 800A7CA8 4C00A3A7 */  sh         $v1, 0x4C($sp)
    /* 3F4AC 800A7CAC 23105400 */  subu       $v0, $v0, $s4
    /* 3F4B0 800A7CB0 CDA2020C */  jal        func_800A8B34
    /* 3F4B4 800A7CB4 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 3F4B8 800A7CB8 21200002 */  addu       $a0, $s0, $zero
    /* 3F4BC 800A7CBC 21286002 */  addu       $a1, $s3, $zero
    /* 3F4C0 800A7CC0 FDFF7326 */  addiu      $s3, $s3, -0x3
    /* 3F4C4 800A7CC4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 3F4C8 800A7CC8 4C00A297 */  lhu        $v0, 0x4C($sp)
    /* 3F4CC 800A7CCC 40181400 */  sll        $v1, $s4, 1
    /* 3F4D0 800A7CD0 23104300 */  subu       $v0, $v0, $v1
    /* 3F4D4 800A7CD4 CDA2020C */  jal        func_800A8B34
    /* 3F4D8 800A7CD8 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F4DC 800A7CDC 21200002 */  addu       $a0, $s0, $zero
    /* 3F4E0 800A7CE0 4800A397 */  lhu        $v1, 0x48($sp)
    /* 3F4E4 800A7CE4 21286002 */  addu       $a1, $s3, $zero
    /* 3F4E8 800A7CE8 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3F4EC 800A7CEC 4C00A297 */  lhu        $v0, 0x4C($sp)
    /* 3F4F0 800A7CF0 21187500 */  addu       $v1, $v1, $s5
    /* 3F4F4 800A7CF4 4800A3A7 */  sh         $v1, 0x48($sp)
    /* 3F4F8 800A7CF8 21189502 */  addu       $v1, $s4, $s5
    /* 3F4FC 800A7CFC 21104300 */  addu       $v0, $v0, $v1
    /* 3F500 800A7D00 CDA2020C */  jal        func_800A8B34
    /* 3F504 800A7D04 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F508 800A7D08 21200002 */  addu       $a0, $s0, $zero
    /* 3F50C 800A7D0C 02006526 */  addiu      $a1, $s3, 0x2
    /* 3F510 800A7D10 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 3F514 800A7D14 4C00A297 */  lhu        $v0, 0x4C($sp)
    /* 3F518 800A7D18 40181500 */  sll        $v1, $s5, 1
    /* 3F51C 800A7D1C 23104300 */  subu       $v0, $v0, $v1
    /* 3F520 800A7D20 CDA2020C */  jal        func_800A8B34
    /* 3F524 800A7D24 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F528 800A7D28 4D9F0208 */  j          .L800A7D34
    /* 3F52C 800A7D2C 2000A2AF */   sw        $v0, 0x20($sp)
  .L800A7D30:
    /* 3F530 800A7D30 1000A2AF */  sw         $v0, 0x10($sp)
  .L800A7D34:
    /* 3F534 800A7D34 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F538 800A7D38 00000000 */  nop
    /* 3F53C 800A7D3C 04000285 */  lh         $v0, 0x4($t0)
    /* 3F540 800A7D40 00000000 */  nop
    /* 3F544 800A7D44 4E004010 */  beqz       $v0, .L800A7E80
    /* 3F548 800A7D48 FF000224 */   addiu     $v0, $zero, 0xFF
  .L800A7D4C:
    /* 3F54C 800A7D4C B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F550 800A7D50 00000000 */  nop
    /* 3F554 800A7D54 04000285 */  lh         $v0, 0x4($t0)
    /* 3F558 800A7D58 00000000 */  nop
    /* 3F55C 800A7D5C 08004104 */  bgez       $v0, .L800A7D80
    /* 3F560 800A7D60 04001324 */   addiu     $s3, $zero, 0x4
    /* 3F564 800A7D64 7C00A88F */  lw         $t0, 0x7C($sp)
    /* 3F568 800A7D68 00000000 */  nop
    /* 3F56C 800A7D6C 23A00800 */  negu       $s4, $t0
    /* 3F570 800A7D70 7800A88F */  lw         $t0, 0x78($sp)
    /* 3F574 800A7D74 21980000 */  addu       $s3, $zero, $zero
    /* 3F578 800A7D78 629F0208 */  j          .L800A7D88
    /* 3F57C 800A7D7C 23A80800 */   negu      $s5, $t0
  .L800A7D80:
    /* 3F580 800A7D80 7C00B48F */  lw         $s4, 0x7C($sp)
    /* 3F584 800A7D84 7800B58F */  lw         $s5, 0x78($sp)
  .L800A7D88:
    /* 3F588 800A7D88 4800B027 */  addiu      $s0, $sp, 0x48
    /* 3F58C 800A7D8C 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3F590 800A7D90 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F594 800A7D94 21200002 */  addu       $a0, $s0, $zero
    /* 3F598 800A7D98 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3F59C 800A7D9C 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3F5A0 800A7DA0 04000395 */  lhu        $v1, 0x4($t0)
    /* 3F5A4 800A7DA4 21286002 */  addu       $a1, $s3, $zero
    /* 3F5A8 800A7DA8 21104300 */  addu       $v0, $v0, $v1
    /* 3F5AC 800A7DAC 21105400 */  addu       $v0, $v0, $s4
    /* 3F5B0 800A7DB0 CDA2020C */  jal        func_800A8B34
    /* 3F5B4 800A7DB4 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F5B8 800A7DB8 2800A2AF */  sw         $v0, 0x28($sp)
    /* 3F5BC 800A7DBC 4800A28F */  lw         $v0, 0x48($sp)
    /* 3F5C0 800A7DC0 4C00A38F */  lw         $v1, 0x4C($sp)
    /* 3F5C4 800A7DC4 6000A2AF */  sw         $v0, 0x60($sp)
    /* 3F5C8 800A7DC8 6400A3AF */  sw         $v1, 0x64($sp)
    /* 3F5CC 800A7DCC 4400B3AF */  sw         $s3, 0x44($sp)
    /* 3F5D0 800A7DD0 FEFF7326 */  addiu      $s3, $s3, -0x2
    /* 3F5D4 800A7DD4 21200002 */  addu       $a0, $s0, $zero
    /* 3F5D8 800A7DD8 21286002 */  addu       $a1, $s3, $zero
    /* 3F5DC 800A7DDC 0F80023C */  lui        $v0, %hi(D_800F49F0)
    /* 3F5E0 800A7DE0 F049428C */  lw         $v0, %lo(D_800F49F0)($v0)
    /* 3F5E4 800A7DE4 4C00A397 */  lhu        $v1, 0x4C($sp)
    /* 3F5E8 800A7DE8 04007326 */  addiu      $s3, $s3, 0x4
    /* 3F5EC 800A7DEC 6C00A2AF */  sw         $v0, 0x6C($sp)
    /* 3F5F0 800A7DF0 4800A297 */  lhu        $v0, 0x48($sp)
    /* 3F5F4 800A7DF4 23187400 */  subu       $v1, $v1, $s4
    /* 3F5F8 800A7DF8 4C00A3A7 */  sh         $v1, 0x4C($sp)
    /* 3F5FC 800A7DFC 23105400 */  subu       $v0, $v0, $s4
    /* 3F600 800A7E00 CDA2020C */  jal        func_800A8B34
    /* 3F604 800A7E04 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 3F608 800A7E08 21200002 */  addu       $a0, $s0, $zero
    /* 3F60C 800A7E0C 21286002 */  addu       $a1, $s3, $zero
    /* 3F610 800A7E10 FDFF7326 */  addiu      $s3, $s3, -0x3
    /* 3F614 800A7E14 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 3F618 800A7E18 4800A297 */  lhu        $v0, 0x48($sp)
    /* 3F61C 800A7E1C 40181400 */  sll        $v1, $s4, 1
    /* 3F620 800A7E20 21104300 */  addu       $v0, $v0, $v1
    /* 3F624 800A7E24 CDA2020C */  jal        func_800A8B34
    /* 3F628 800A7E28 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 3F62C 800A7E2C 21200002 */  addu       $a0, $s0, $zero
    /* 3F630 800A7E30 21286002 */  addu       $a1, $s3, $zero
    /* 3F634 800A7E34 21309502 */  addu       $a2, $s4, $s5
    /* 3F638 800A7E38 3000A2AF */  sw         $v0, 0x30($sp)
    /* 3F63C 800A7E3C 4800A297 */  lhu        $v0, 0x48($sp)
    /* 3F640 800A7E40 4C00A397 */  lhu        $v1, 0x4C($sp)
    /* 3F644 800A7E44 23104600 */  subu       $v0, $v0, $a2
    /* 3F648 800A7E48 21187500 */  addu       $v1, $v1, $s5
    /* 3F64C 800A7E4C 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3F650 800A7E50 CDA2020C */  jal        func_800A8B34
    /* 3F654 800A7E54 4C00A3A7 */   sh        $v1, 0x4C($sp)
    /* 3F658 800A7E58 21200002 */  addu       $a0, $s0, $zero
    /* 3F65C 800A7E5C 02006526 */  addiu      $a1, $s3, 0x2
    /* 3F660 800A7E60 3400A2AF */  sw         $v0, 0x34($sp)
    /* 3F664 800A7E64 4800A297 */  lhu        $v0, 0x48($sp)
    /* 3F668 800A7E68 40181500 */  sll        $v1, $s5, 1
    /* 3F66C 800A7E6C 21104300 */  addu       $v0, $v0, $v1
    /* 3F670 800A7E70 CDA2020C */  jal        func_800A8B34
    /* 3F674 800A7E74 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 3F678 800A7E78 A19F0208 */  j          .L800A7E84
    /* 3F67C 800A7E7C 3800A2AF */   sw        $v0, 0x38($sp)
  .L800A7E80:
    /* 3F680 800A7E80 2800A2AF */  sw         $v0, 0x28($sp)
  .L800A7E84:
    /* 3F684 800A7E84 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F688 800A7E88 00000000 */  nop
    /* 3F68C 800A7E8C 00000585 */  lh         $a1, 0x0($t0)
    /* 3F690 800A7E90 04000485 */  lh         $a0, 0x4($t0)
    /* 3F694 800A7E94 0200A104 */  bgez       $a1, .L800A7EA0
    /* 3F698 800A7E98 2110A000 */   addu      $v0, $a1, $zero
    /* 3F69C 800A7E9C 23100200 */  negu       $v0, $v0
  .L800A7EA0:
    /* 3F6A0 800A7EA0 02008104 */  bgez       $a0, .L800A7EAC
    /* 3F6A4 800A7EA4 21188000 */   addu      $v1, $a0, $zero
    /* 3F6A8 800A7EA8 23180300 */  negu       $v1, $v1
  .L800A7EAC:
    /* 3F6AC 800A7EAC 04004310 */  beq        $v0, $v1, .L800A7EC0
    /* 3F6B0 800A7EB0 00000000 */   nop
    /* 3F6B4 800A7EB4 2A104300 */  slt        $v0, $v0, $v1
    /* 3F6B8 800A7EB8 79014014 */  bnez       $v0, .L800A84A0
    /* 3F6BC 800A7EBC 00000000 */   nop
  .L800A7EC0:
    /* 3F6C0 800A7EC0 5A00A387 */  lh         $v1, 0x5A($sp)
    /* 3F6C4 800A7EC4 1E00C286 */  lh         $v0, 0x1E($s6)
    /* 3F6C8 800A7EC8 00000000 */  nop
    /* 3F6CC 800A7ECC 23A06200 */  subu       $s4, $v1, $v0
    /* 3F6D0 800A7ED0 02008106 */  bgez       $s4, .L800A7EDC
    /* 3F6D4 800A7ED4 21108002 */   addu      $v0, $s4, $zero
    /* 3F6D8 800A7ED8 3F008226 */  addiu      $v0, $s4, 0x3F
  .L800A7EDC:
    /* 3F6DC 800A7EDC 83A90200 */  sra        $s5, $v0, 6
    /* 3F6E0 800A7EE0 3F008232 */  andi       $v0, $s4, 0x3F
    /* 3F6E4 800A7EE4 02004010 */  beqz       $v0, .L800A7EF0
    /* 3F6E8 800A7EE8 00000000 */   nop
    /* 3F6EC 800A7EEC FFFFB526 */  addiu      $s5, $s5, -0x1
  .L800A7EF0:
    /* 3F6F0 800A7EF0 23A81500 */  negu       $s5, $s5
    /* 3F6F4 800A7EF4 0200A01E */  bgtz       $s5, .L800A7F00
    /* 3F6F8 800A7EF8 00000000 */   nop
    /* 3F6FC 800A7EFC 01001524 */  addiu      $s5, $zero, 0x1
  .L800A7F00:
    /* 3F700 800A7F00 1000A38F */  lw         $v1, 0x10($sp)
    /* 3F704 800A7F04 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3F708 800A7F08 25006210 */  beq        $v1, $v0, .L800A7FA0
    /* 3F70C 800A7F0C 00000000 */   nop
    /* 3F710 800A7F10 1400A28F */  lw         $v0, 0x14($sp)
    /* 3F714 800A7F14 00000000 */  nop
    /* 3F718 800A7F18 2A10A202 */  slt        $v0, $s5, $v0
    /* 3F71C 800A7F1C 20004014 */  bnez       $v0, .L800A7FA0
    /* 3F720 800A7F20 00000000 */   nop
    /* 3F724 800A7F24 1800A28F */  lw         $v0, 0x18($sp)
    /* 3F728 800A7F28 00000000 */  nop
    /* 3F72C 800A7F2C 2A10A202 */  slt        $v0, $s5, $v0
    /* 3F730 800A7F30 1B004014 */  bnez       $v0, .L800A7FA0
    /* 3F734 800A7F34 00000000 */   nop
    /* 3F738 800A7F38 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 3F73C 800A7F3C 00000000 */  nop
    /* 3F740 800A7F40 2A10A202 */  slt        $v0, $s5, $v0
    /* 3F744 800A7F44 16004014 */  bnez       $v0, .L800A7FA0
    /* 3F748 800A7F48 00000000 */   nop
    /* 3F74C 800A7F4C 2000A28F */  lw         $v0, 0x20($sp)
    /* 3F750 800A7F50 00000000 */  nop
    /* 3F754 800A7F54 2A10A202 */  slt        $v0, $s5, $v0
    /* 3F758 800A7F58 11004014 */  bnez       $v0, .L800A7FA0
    /* 3F75C 800A7F5C 00000000 */   nop
    /* 3F760 800A7F60 AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3F764 800A7F64 00000000 */  nop
    /* 3F768 800A7F68 00404230 */  andi       $v0, $v0, 0x4000
    /* 3F76C 800A7F6C C6014010 */  beqz       $v0, .L800A8688
    /* 3F770 800A7F70 00000000 */   nop
    /* 3F774 800A7F74 0400A104 */  bgez       $a1, .L800A7F88
    /* 3F778 800A7F78 02000224 */   addiu     $v0, $zero, 0x2
    /* 3F77C 800A7F7C FE17C392 */  lbu        $v1, 0x17FE($s6)
    /* 3F780 800A7F80 E39F0208 */  j          .L800A7F8C
    /* 3F784 800A7F84 06000224 */   addiu     $v0, $zero, 0x6
  .L800A7F88:
    /* 3F788 800A7F88 FE17C392 */  lbu        $v1, 0x17FE($s6)
  .L800A7F8C:
    /* 3F78C 800A7F8C 00000000 */  nop
    /* 3F790 800A7F90 47006210 */  beq        $v1, $v0, .L800A80B0
    /* 3F794 800A7F94 00000000 */   nop
    /* 3F798 800A7F98 A2A10208 */  j          .L800A8688
    /* 3F79C 800A7F9C 00000000 */   nop
  .L800A7FA0:
    /* 3F7A0 800A7FA0 2800A38F */  lw         $v1, 0x28($sp)
    /* 3F7A4 800A7FA4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3F7A8 800A7FA8 41006210 */  beq        $v1, $v0, .L800A80B0
    /* 3F7AC 800A7FAC 00000000 */   nop
    /* 3F7B0 800A7FB0 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 3F7B4 800A7FB4 00000000 */  nop
    /* 3F7B8 800A7FB8 02004228 */  slti       $v0, $v0, 0x2
    /* 3F7BC 800A7FBC 3C004010 */  beqz       $v0, .L800A80B0
    /* 3F7C0 800A7FC0 00000000 */   nop
    /* 3F7C4 800A7FC4 3000A28F */  lw         $v0, 0x30($sp)
    /* 3F7C8 800A7FC8 00000000 */  nop
    /* 3F7CC 800A7FCC 02004228 */  slti       $v0, $v0, 0x2
    /* 3F7D0 800A7FD0 37004010 */  beqz       $v0, .L800A80B0
    /* 3F7D4 800A7FD4 00000000 */   nop
    /* 3F7D8 800A7FD8 3400A28F */  lw         $v0, 0x34($sp)
    /* 3F7DC 800A7FDC 00000000 */  nop
    /* 3F7E0 800A7FE0 02004228 */  slti       $v0, $v0, 0x2
    /* 3F7E4 800A7FE4 32004010 */  beqz       $v0, .L800A80B0
    /* 3F7E8 800A7FE8 00000000 */   nop
    /* 3F7EC 800A7FEC 3800A28F */  lw         $v0, 0x38($sp)
    /* 3F7F0 800A7FF0 00000000 */  nop
    /* 3F7F4 800A7FF4 02004228 */  slti       $v0, $v0, 0x2
    /* 3F7F8 800A7FF8 2D004010 */  beqz       $v0, .L800A80B0
    /* 3F7FC 800A7FFC 00000000 */   nop
    /* 3F800 800A8000 AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3F804 800A8004 00000000 */  nop
    /* 3F808 800A8008 00404230 */  andi       $v0, $v0, 0x4000
    /* 3F80C 800A800C 11004010 */  beqz       $v0, .L800A8054
    /* 3F810 800A8010 00000000 */   nop
    /* 3F814 800A8014 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F818 800A8018 00000000 */  nop
    /* 3F81C 800A801C 04000285 */  lh         $v0, 0x4($t0)
    /* 3F820 800A8020 00000000 */  nop
    /* 3F824 800A8024 07004104 */  bgez       $v0, .L800A8044
    /* 3F828 800A8028 04000224 */   addiu     $v0, $zero, 0x4
    /* 3F82C 800A802C FE17C392 */  lbu        $v1, 0x17FE($s6)
    /* 3F830 800A8030 00000000 */  nop
    /* 3F834 800A8034 1E006210 */  beq        $v1, $v0, .L800A80B0
    /* 3F838 800A8038 00000000 */   nop
    /* 3F83C 800A803C 18A00208 */  j          .L800A8060
    /* 3F840 800A8040 000000A5 */   sh        $zero, 0x0($t0)
  .L800A8044:
    /* 3F844 800A8044 FE17C292 */  lbu        $v0, 0x17FE($s6)
    /* 3F848 800A8048 00000000 */  nop
    /* 3F84C 800A804C 18004010 */  beqz       $v0, .L800A80B0
    /* 3F850 800A8050 00000000 */   nop
  .L800A8054:
    /* 3F854 800A8054 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F858 800A8058 00000000 */  nop
    /* 3F85C 800A805C 000000A5 */  sh         $zero, 0x0($t0)
  .L800A8060:
    /* 3F860 800A8060 2800A38F */  lw         $v1, 0x28($sp)
    /* 3F864 800A8064 B800A88F */  lw         $t0, 0xB8($sp)
    /* 3F868 800A8068 00000000 */  nop
    /* 3F86C 800A806C 000003AD */  sw         $v1, 0x0($t0)
    /* 3F870 800A8070 0F80033C */  lui        $v1, %hi(D_800F4B08)
    /* 3F874 800A8074 084B6724 */  addiu      $a3, $v1, %lo(D_800F4B08)
    /* 3F878 800A8078 6300A48B */  lwl        $a0, 0x63($sp)
    /* 3F87C 800A807C 6000A49B */  lwr        $a0, 0x60($sp)
    /* 3F880 800A8080 6700A58B */  lwl        $a1, 0x67($sp)
    /* 3F884 800A8084 6400A59B */  lwr        $a1, 0x64($sp)
    /* 3F888 800A8088 0300E4A8 */  swl        $a0, 0x3($a3)
    /* 3F88C 800A808C 0000E4B8 */  swr        $a0, 0x0($a3)
    /* 3F890 800A8090 0700E5A8 */  swl        $a1, 0x7($a3)
    /* 3F894 800A8094 0400E5B8 */  swr        $a1, 0x4($a3)
    /* 3F898 800A8098 6C00A48F */  lw         $a0, 0x6C($sp)
    /* 3F89C 800A809C 0F80033C */  lui        $v1, %hi(D_800F49F0)
    /* 3F8A0 800A80A0 F04964AC */  sw         $a0, %lo(D_800F49F0)($v1)
    /* 3F8A4 800A80A4 4400A493 */  lbu        $a0, 0x44($sp)
    /* 3F8A8 800A80A8 B7A10208 */  j          .L800A86DC
    /* 3F8AC 800A80AC 02000224 */   addiu     $v0, $zero, 0x2
  .L800A80B0:
    /* 3F8B0 800A80B0 0800C28E */  lw         $v0, 0x8($s6)
    /* 3F8B4 800A80B4 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3F8B8 800A80B8 24104300 */  and        $v0, $v0, $v1
    /* 3F8BC 800A80BC 90024014 */  bnez       $v0, .L800A8B00
    /* 3F8C0 800A80C0 03000224 */   addiu     $v0, $zero, 0x3
    /* 3F8C4 800A80C4 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F8C8 800A80C8 00000000 */  nop
    /* 3F8CC 800A80CC 00000285 */  lh         $v0, 0x0($t0)
    /* 3F8D0 800A80D0 00000000 */  nop
    /* 3F8D4 800A80D4 08004104 */  bgez       $v0, .L800A80F8
    /* 3F8D8 800A80D8 06001324 */   addiu     $s3, $zero, 0x6
    /* 3F8DC 800A80DC 7C00A88F */  lw         $t0, 0x7C($sp)
    /* 3F8E0 800A80E0 00000000 */  nop
    /* 3F8E4 800A80E4 23A00800 */  negu       $s4, $t0
    /* 3F8E8 800A80E8 7800A88F */  lw         $t0, 0x78($sp)
    /* 3F8EC 800A80EC 02001324 */  addiu      $s3, $zero, 0x2
    /* 3F8F0 800A80F0 40A00208 */  j          .L800A8100
    /* 3F8F4 800A80F4 23A80800 */   negu      $s5, $t0
  .L800A80F8:
    /* 3F8F8 800A80F8 7C00B48F */  lw         $s4, 0x7C($sp)
    /* 3F8FC 800A80FC 7800B58F */  lw         $s5, 0x78($sp)
  .L800A8100:
    /* 3F900 800A8100 FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 3F904 800A8104 4800A427 */  addiu      $a0, $sp, 0x48
    /* 3F908 800A8108 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F90C 800A810C 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3F910 800A8110 00000395 */  lhu        $v1, 0x0($t0)
    /* 3F914 800A8114 21286002 */  addu       $a1, $s3, $zero
    /* 3F918 800A8118 21104300 */  addu       $v0, $v0, $v1
    /* 3F91C 800A811C 21105400 */  addu       $v0, $v0, $s4
    /* 3F920 800A8120 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3F924 800A8124 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3F928 800A8128 02007326 */  addiu      $s3, $s3, 0x2
    /* 3F92C 800A812C 21105400 */  addu       $v0, $v0, $s4
    /* 3F930 800A8130 CDA2020C */  jal        func_800A8B34
    /* 3F934 800A8134 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F938 800A8138 4800A397 */  lhu        $v1, 0x48($sp)
    /* 3F93C 800A813C 5000A427 */  addiu      $a0, $sp, 0x50
    /* 3F940 800A8140 2800A2AF */  sw         $v0, 0x28($sp)
    /* 3F944 800A8144 5000A3A7 */  sh         $v1, 0x50($sp)
    /* 3F948 800A8148 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3F94C 800A814C 21286002 */  addu       $a1, $s3, $zero
    /* 3F950 800A8150 23105400 */  subu       $v0, $v0, $s4
    /* 3F954 800A8154 CDA2020C */  jal        func_800A8B34
    /* 3F958 800A8158 5400A2A7 */   sh        $v0, 0x54($sp)
    /* 3F95C 800A815C 21204000 */  addu       $a0, $v0, $zero
    /* 3F960 800A8160 2800A38F */  lw         $v1, 0x28($sp)
    /* 3F964 800A8164 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3F968 800A8168 03006214 */  bne        $v1, $v0, .L800A8178
    /* 3F96C 800A816C 2C00A4AF */   sw        $a0, 0x2C($sp)
    /* 3F970 800A8170 63028310 */  beq        $a0, $v1, .L800A8B00
    /* 3F974 800A8174 03000224 */   addiu     $v0, $zero, 0x3
  .L800A8178:
    /* 3F978 800A8178 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3F97C 800A817C 00000000 */  nop
    /* 3F980 800A8180 00000695 */  lhu        $a2, 0x0($t0)
    /* 3F984 800A8184 00000000 */  nop
    /* 3F988 800A8188 00140600 */  sll        $v0, $a2, 16
    /* 3F98C 800A818C 031C0200 */  sra        $v1, $v0, 16
    /* 3F990 800A8190 C2170200 */  srl        $v0, $v0, 31
    /* 3F994 800A8194 21186200 */  addu       $v1, $v1, $v0
    /* 3F998 800A8198 2800A28F */  lw         $v0, 0x28($sp)
    /* 3F99C 800A819C 00000000 */  nop
    /* 3F9A0 800A81A0 02004228 */  slti       $v0, $v0, 0x2
    /* 3F9A4 800A81A4 B1004010 */  beqz       $v0, .L800A846C
    /* 3F9A8 800A81A8 43B80300 */   sra       $s7, $v1, 1
    /* 3F9AC 800A81AC 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 3F9B0 800A81B0 00000000 */  nop
    /* 3F9B4 800A81B4 02004228 */  slti       $v0, $v0, 0x2
    /* 3F9B8 800A81B8 37004010 */  beqz       $v0, .L800A8298
    /* 3F9BC 800A81BC 4800A427 */   addiu     $a0, $sp, 0x48
    /* 3F9C0 800A81C0 FEFF7326 */  addiu      $s3, $s3, -0x2
    /* 3F9C4 800A81C4 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3F9C8 800A81C8 21286002 */  addu       $a1, $s3, $zero
    /* 3F9CC 800A81CC 21104600 */  addu       $v0, $v0, $a2
    /* 3F9D0 800A81D0 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3F9D4 800A81D4 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3F9D8 800A81D8 02007326 */  addiu      $s3, $s3, 0x2
    /* 3F9DC 800A81DC 21105400 */  addu       $v0, $v0, $s4
    /* 3F9E0 800A81E0 CDA2020C */  jal        func_800A8B34
    /* 3F9E4 800A81E4 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3F9E8 800A81E8 4800A397 */  lhu        $v1, 0x48($sp)
    /* 3F9EC 800A81EC 5000A427 */  addiu      $a0, $sp, 0x50
    /* 3F9F0 800A81F0 3000A2AF */  sw         $v0, 0x30($sp)
    /* 3F9F4 800A81F4 5000A3A7 */  sh         $v1, 0x50($sp)
    /* 3F9F8 800A81F8 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3F9FC 800A81FC 21286002 */  addu       $a1, $s3, $zero
    /* 3FA00 800A8200 23105400 */  subu       $v0, $v0, $s4
    /* 3FA04 800A8204 CDA2020C */  jal        func_800A8B34
    /* 3FA08 800A8208 5400A2A7 */   sh        $v0, 0x54($sp)
    /* 3FA0C 800A820C 21204000 */  addu       $a0, $v0, $zero
    /* 3FA10 800A8210 3000A38F */  lw         $v1, 0x30($sp)
    /* 3FA14 800A8214 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3FA18 800A8218 03006214 */  bne        $v1, $v0, .L800A8228
    /* 3FA1C 800A821C 3400A4AF */   sw        $a0, 0x34($sp)
    /* 3FA20 800A8220 37028310 */  beq        $a0, $v1, .L800A8B00
    /* 3FA24 800A8224 03000224 */   addiu     $v0, $zero, 0x3
  .L800A8228:
    /* 3FA28 800A8228 3000A28F */  lw         $v0, 0x30($sp)
    /* 3FA2C 800A822C 00000000 */  nop
    /* 3FA30 800A8230 9300401C */  bgtz       $v0, .L800A8480
    /* 3FA34 800A8234 00000000 */   nop
    /* 3FA38 800A8238 3400A28F */  lw         $v0, 0x34($sp)
    /* 3FA3C 800A823C 00000000 */  nop
    /* 3FA40 800A8240 1500401C */  bgtz       $v0, .L800A8298
    /* 3FA44 800A8244 00000000 */   nop
    /* 3FA48 800A8248 2800A48F */  lw         $a0, 0x28($sp)
    /* 3FA4C 800A824C 00000000 */  nop
    /* 3FA50 800A8250 05008014 */  bnez       $a0, .L800A8268
    /* 3FA54 800A8254 01000224 */   addiu     $v0, $zero, 0x1
    /* 3FA58 800A8258 2C00A38F */  lw         $v1, 0x2C($sp)
    /* 3FA5C 800A825C 00000000 */  nop
    /* 3FA60 800A8260 0D006210 */  beq        $v1, $v0, .L800A8298
    /* 3FA64 800A8264 00000000 */   nop
  .L800A8268:
    /* 3FA68 800A8268 05008214 */  bne        $a0, $v0, .L800A8280
    /* 3FA6C 800A826C 00000000 */   nop
    /* 3FA70 800A8270 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 3FA74 800A8274 00000000 */  nop
    /* 3FA78 800A8278 81004410 */  beq        $v0, $a0, .L800A8480
    /* 3FA7C 800A827C 00000000 */   nop
  .L800A8280:
    /* 3FA80 800A8280 4A00A387 */  lh         $v1, 0x4A($sp)
    /* 3FA84 800A8284 5200A287 */  lh         $v0, 0x52($sp)
    /* 3FA88 800A8288 00000000 */  nop
    /* 3FA8C 800A828C 2A104300 */  slt        $v0, $v0, $v1
    /* 3FA90 800A8290 7B004010 */  beqz       $v0, .L800A8480
    /* 3FA94 800A8294 00000000 */   nop
  .L800A8298:
    /* 3FA98 800A8298 7000B4AF */  sw         $s4, 0x70($sp)
    /* 3FA9C 800A829C 23881500 */  negu       $s1, $s5
    /* 3FAA0 800A82A0 2180E002 */  addu       $s0, $s7, $zero
    /* 3FAA4 800A82A4 01001E24 */  addiu      $fp, $zero, 0x1
    /* 3FAA8 800A82A8 FDFF0824 */  addiu      $t0, $zero, -0x3
  .L800A82AC:
    /* 3FAAC 800A82AC 7400A8AF */  sw         $t0, 0x74($sp)
    /* 3FAB0 800A82B0 23987E02 */  subu       $s3, $s3, $fp
    /* 3FAB4 800A82B4 4800B227 */  addiu      $s2, $sp, 0x48
    /* 3FAB8 800A82B8 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3FABC 800A82BC 21204002 */  addu       $a0, $s2, $zero
    /* 3FAC0 800A82C0 21105700 */  addu       $v0, $v0, $s7
    /* 3FAC4 800A82C4 21105400 */  addu       $v0, $v0, $s4
    /* 3FAC8 800A82C8 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3FACC 800A82CC 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3FAD0 800A82D0 21286002 */  addu       $a1, $s3, $zero
    /* 3FAD4 800A82D4 21105000 */  addu       $v0, $v0, $s0
    /* 3FAD8 800A82D8 CDA2020C */  jal        func_800A8B34
    /* 3FADC 800A82DC 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3FAE0 800A82E0 8000A88F */  lw         $t0, 0x80($sp)
    /* 3FAE4 800A82E4 00000000 */  nop
    /* 3FAE8 800A82E8 4000038D */  lw         $v1, 0x40($t0)
    /* 3FAEC 800A82EC 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 3FAF0 800A82F0 2A104300 */  slt        $v0, $v0, $v1
    /* 3FAF4 800A82F4 02004010 */  beqz       $v0, .L800A8300
    /* 3FAF8 800A82F8 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 3FAFC 800A82FC 2C00A2AF */  sw         $v0, 0x2C($sp)
  .L800A8300:
    /* 3FB00 800A8300 21987E02 */  addu       $s3, $s3, $fp
    /* 3FB04 800A8304 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3FB08 800A8308 21204002 */  addu       $a0, $s2, $zero
    /* 3FB0C 800A830C 21105700 */  addu       $v0, $v0, $s7
    /* 3FB10 800A8310 21105500 */  addu       $v0, $v0, $s5
    /* 3FB14 800A8314 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3FB18 800A8318 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3FB1C 800A831C 21286002 */  addu       $a1, $s3, $zero
    /* 3FB20 800A8320 21105000 */  addu       $v0, $v0, $s0
    /* 3FB24 800A8324 21105100 */  addu       $v0, $v0, $s1
    /* 3FB28 800A8328 CDA2020C */  jal        func_800A8B34
    /* 3FB2C 800A832C 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3FB30 800A8330 8000A88F */  lw         $t0, 0x80($sp)
    /* 3FB34 800A8334 00000000 */  nop
    /* 3FB38 800A8338 4000038D */  lw         $v1, 0x40($t0)
    /* 3FB3C 800A833C 3000A2AF */  sw         $v0, 0x30($sp)
    /* 3FB40 800A8340 2A104300 */  slt        $v0, $v0, $v1
    /* 3FB44 800A8344 02004010 */  beqz       $v0, .L800A8350
    /* 3FB48 800A8348 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 3FB4C 800A834C 3000A2AF */  sw         $v0, 0x30($sp)
  .L800A8350:
    /* 3FB50 800A8350 21204002 */  addu       $a0, $s2, $zero
    /* 3FB54 800A8354 7400A88F */  lw         $t0, 0x74($sp)
    /* 3FB58 800A8358 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3FB5C 800A835C 21986802 */  addu       $s3, $s3, $t0
    /* 3FB60 800A8360 21286002 */  addu       $a1, $s3, $zero
    /* 3FB64 800A8364 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3FB68 800A8368 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3FB6C 800A836C 7000A88F */  lw         $t0, 0x70($sp)
    /* 3FB70 800A8370 21105700 */  addu       $v0, $v0, $s7
    /* 3FB74 800A8374 21104800 */  addu       $v0, $v0, $t0
    /* 3FB78 800A8378 CDA2020C */  jal        func_800A8B34
    /* 3FB7C 800A837C 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3FB80 800A8380 8000A88F */  lw         $t0, 0x80($sp)
    /* 3FB84 800A8384 00000000 */  nop
    /* 3FB88 800A8388 4000038D */  lw         $v1, 0x40($t0)
    /* 3FB8C 800A838C 3400A2AF */  sw         $v0, 0x34($sp)
    /* 3FB90 800A8390 2A104300 */  slt        $v0, $v0, $v1
    /* 3FB94 800A8394 02004010 */  beqz       $v0, .L800A83A0
    /* 3FB98 800A8398 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 3FB9C 800A839C 3400A2AF */  sw         $v0, 0x34($sp)
  .L800A83A0:
    /* 3FBA0 800A83A0 0F80033C */  lui        $v1, %hi(D_800F4B08)
    /* 3FBA4 800A83A4 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 3FBA8 800A83A8 084B6724 */  addiu      $a3, $v1, %lo(D_800F4B08)
    /* 3FBAC 800A83AC 4B00A48B */  lwl        $a0, 0x4B($sp)
    /* 3FBB0 800A83B0 4800A49B */  lwr        $a0, 0x48($sp)
    /* 3FBB4 800A83B4 4F00A58B */  lwl        $a1, 0x4F($sp)
    /* 3FBB8 800A83B8 4C00A59B */  lwr        $a1, 0x4C($sp)
    /* 3FBBC 800A83BC 0300E4A8 */  swl        $a0, 0x3($a3)
    /* 3FBC0 800A83C0 0000E4B8 */  swr        $a0, 0x0($a3)
    /* 3FBC4 800A83C4 0700E5A8 */  swl        $a1, 0x7($a3)
    /* 3FBC8 800A83C8 0400E5B8 */  swr        $a1, 0x4($a3)
    /* 3FBCC 800A83CC 02004228 */  slti       $v0, $v0, 0x2
    /* 3FBD0 800A83D0 1F004010 */  beqz       $v0, .L800A8450
    /* 3FBD4 800A83D4 00000000 */   nop
    /* 3FBD8 800A83D8 3000A28F */  lw         $v0, 0x30($sp)
    /* 3FBDC 800A83DC 00000000 */  nop
    /* 3FBE0 800A83E0 02004228 */  slti       $v0, $v0, 0x2
    /* 3FBE4 800A83E4 1A004010 */  beqz       $v0, .L800A8450
    /* 3FBE8 800A83E8 00000000 */   nop
    /* 3FBEC 800A83EC 3400A28F */  lw         $v0, 0x34($sp)
    /* 3FBF0 800A83F0 00000000 */  nop
    /* 3FBF4 800A83F4 02004228 */  slti       $v0, $v0, 0x2
    /* 3FBF8 800A83F8 C0014010 */  beqz       $v0, .L800A8AFC
    /* 3FBFC 800A83FC 21204002 */   addu      $a0, $s2, $zero
    /* 3FC00 800A8400 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3FC04 800A8404 21286002 */  addu       $a1, $s3, $zero
    /* 3FC08 800A8408 21105700 */  addu       $v0, $v0, $s7
    /* 3FC0C 800A840C 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 3FC10 800A8410 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3FC14 800A8414 7000A88F */  lw         $t0, 0x70($sp)
    /* 3FC18 800A8418 21105000 */  addu       $v0, $v0, $s0
    /* 3FC1C 800A841C 21104800 */  addu       $v0, $v0, $t0
    /* 3FC20 800A8420 CDA2020C */  jal        func_800A8B34
    /* 3FC24 800A8424 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 3FC28 800A8428 2800A2AF */  sw         $v0, 0x28($sp)
    /* 3FC2C 800A842C 02004228 */  slti       $v0, $v0, 0x2
    /* 3FC30 800A8430 B2014010 */  beqz       $v0, .L800A8AFC
    /* 3FC34 800A8434 21987E02 */   addu      $s3, $s3, $fp
    /* 3FC38 800A8438 21A00000 */  addu       $s4, $zero, $zero
  .L800A843C:
    /* 3FC3C 800A843C B400A88F */  lw         $t0, 0xB4($sp)
    /* 3FC40 800A8440 00000000 */  nop
    /* 3FC44 800A8444 000017A5 */  sh         $s7, 0x0($t0)
    /* 3FC48 800A8448 A2A20208 */  j          .L800A8A88
    /* 3FC4C 800A844C 040010A5 */   sh        $s0, 0x4($t0)
  .L800A8450:
    /* 3FC50 800A8450 3400A28F */  lw         $v0, 0x34($sp)
    /* 3FC54 800A8454 00000000 */  nop
    /* 3FC58 800A8458 02004228 */  slti       $v0, $v0, 0x2
    /* 3FC5C 800A845C A7014010 */  beqz       $v0, .L800A8AFC
    /* 3FC60 800A8460 21B80000 */   addu      $s7, $zero, $zero
    /* 3FC64 800A8464 0FA10208 */  j          .L800A843C
    /* 3FC68 800A8468 02001424 */   addiu     $s4, $zero, 0x2
  .L800A846C:
    /* 3FC6C 800A846C 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 3FC70 800A8470 00000000 */  nop
    /* 3FC74 800A8474 02004228 */  slti       $v0, $v0, 0x2
    /* 3FC78 800A8478 A1014010 */  beqz       $v0, .L800A8B00
    /* 3FC7C 800A847C 03000224 */   addiu     $v0, $zero, 0x3
  .L800A8480:
    /* 3FC80 800A8480 FEFF7326 */  addiu      $s3, $s3, -0x2
    /* 3FC84 800A8484 23401400 */  negu       $t0, $s4
    /* 3FC88 800A8488 2188A002 */  addu       $s1, $s5, $zero
    /* 3FC8C 800A848C 23801700 */  negu       $s0, $s7
    /* 3FC90 800A8490 FFFF1E24 */  addiu      $fp, $zero, -0x1
    /* 3FC94 800A8494 7000A8AF */  sw         $t0, 0x70($sp)
    /* 3FC98 800A8498 ABA00208 */  j          .L800A82AC
    /* 3FC9C 800A849C 03000824 */   addiu     $t0, $zero, 0x3
  .L800A84A0:
    /* 3FCA0 800A84A0 6200A387 */  lh         $v1, 0x62($sp)
    /* 3FCA4 800A84A4 1E00C286 */  lh         $v0, 0x1E($s6)
    /* 3FCA8 800A84A8 00000000 */  nop
    /* 3FCAC 800A84AC 23A06200 */  subu       $s4, $v1, $v0
    /* 3FCB0 800A84B0 02008106 */  bgez       $s4, .L800A84BC
    /* 3FCB4 800A84B4 21108002 */   addu      $v0, $s4, $zero
    /* 3FCB8 800A84B8 3F008226 */  addiu      $v0, $s4, 0x3F
  .L800A84BC:
    /* 3FCBC 800A84BC 83A90200 */  sra        $s5, $v0, 6
    /* 3FCC0 800A84C0 3F008232 */  andi       $v0, $s4, 0x3F
    /* 3FCC4 800A84C4 02004010 */  beqz       $v0, .L800A84D0
    /* 3FCC8 800A84C8 00000000 */   nop
    /* 3FCCC 800A84CC FFFFB526 */  addiu      $s5, $s5, -0x1
  .L800A84D0:
    /* 3FCD0 800A84D0 23A81500 */  negu       $s5, $s5
    /* 3FCD4 800A84D4 0200A01E */  bgtz       $s5, .L800A84E0
    /* 3FCD8 800A84D8 00000000 */   nop
    /* 3FCDC 800A84DC 01001524 */  addiu      $s5, $zero, 0x1
  .L800A84E0:
    /* 3FCE0 800A84E0 2800A38F */  lw         $v1, 0x28($sp)
    /* 3FCE4 800A84E4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3FCE8 800A84E8 3D006210 */  beq        $v1, $v0, .L800A85E0
    /* 3FCEC 800A84EC 00000000 */   nop
    /* 3FCF0 800A84F0 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 3FCF4 800A84F4 00000000 */  nop
    /* 3FCF8 800A84F8 2A10A202 */  slt        $v0, $s5, $v0
    /* 3FCFC 800A84FC 38004014 */  bnez       $v0, .L800A85E0
    /* 3FD00 800A8500 00000000 */   nop
    /* 3FD04 800A8504 3000A28F */  lw         $v0, 0x30($sp)
    /* 3FD08 800A8508 00000000 */  nop
    /* 3FD0C 800A850C 2A10A202 */  slt        $v0, $s5, $v0
    /* 3FD10 800A8510 33004014 */  bnez       $v0, .L800A85E0
    /* 3FD14 800A8514 00000000 */   nop
    /* 3FD18 800A8518 3400A28F */  lw         $v0, 0x34($sp)
    /* 3FD1C 800A851C 00000000 */  nop
    /* 3FD20 800A8520 2A10A202 */  slt        $v0, $s5, $v0
    /* 3FD24 800A8524 2E004014 */  bnez       $v0, .L800A85E0
    /* 3FD28 800A8528 00000000 */   nop
    /* 3FD2C 800A852C 3800A28F */  lw         $v0, 0x38($sp)
    /* 3FD30 800A8530 00000000 */  nop
    /* 3FD34 800A8534 2A10A202 */  slt        $v0, $s5, $v0
    /* 3FD38 800A8538 29004014 */  bnez       $v0, .L800A85E0
    /* 3FD3C 800A853C 00000000 */   nop
    /* 3FD40 800A8540 AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3FD44 800A8544 00000000 */  nop
    /* 3FD48 800A8548 00404230 */  andi       $v0, $v0, 0x4000
    /* 3FD4C 800A854C 0D004010 */  beqz       $v0, .L800A8584
    /* 3FD50 800A8550 00000000 */   nop
    /* 3FD54 800A8554 07008104 */  bgez       $a0, .L800A8574
    /* 3FD58 800A8558 04000224 */   addiu     $v0, $zero, 0x4
    /* 3FD5C 800A855C FE17C392 */  lbu        $v1, 0x17FE($s6)
    /* 3FD60 800A8560 00000000 */  nop
    /* 3FD64 800A8564 60006210 */  beq        $v1, $v0, .L800A86E8
    /* 3FD68 800A8568 00000000 */   nop
    /* 3FD6C 800A856C 61A10208 */  j          .L800A8584
    /* 3FD70 800A8570 00000000 */   nop
  .L800A8574:
    /* 3FD74 800A8574 FE17C292 */  lbu        $v0, 0x17FE($s6)
    /* 3FD78 800A8578 00000000 */  nop
    /* 3FD7C 800A857C 5A004010 */  beqz       $v0, .L800A86E8
    /* 3FD80 800A8580 00000000 */   nop
  .L800A8584:
    /* 3FD84 800A8584 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3FD88 800A8588 00000000 */  nop
    /* 3FD8C 800A858C 000000A5 */  sh         $zero, 0x0($t0)
    /* 3FD90 800A8590 2800A38F */  lw         $v1, 0x28($sp)
    /* 3FD94 800A8594 B800A88F */  lw         $t0, 0xB8($sp)
    /* 3FD98 800A8598 00000000 */  nop
    /* 3FD9C 800A859C 000003AD */  sw         $v1, 0x0($t0)
    /* 3FDA0 800A85A0 0F80033C */  lui        $v1, %hi(D_800F4B08)
    /* 3FDA4 800A85A4 084B6724 */  addiu      $a3, $v1, %lo(D_800F4B08)
    /* 3FDA8 800A85A8 6300A48B */  lwl        $a0, 0x63($sp)
    /* 3FDAC 800A85AC 6000A49B */  lwr        $a0, 0x60($sp)
    /* 3FDB0 800A85B0 6700A58B */  lwl        $a1, 0x67($sp)
    /* 3FDB4 800A85B4 6400A59B */  lwr        $a1, 0x64($sp)
    /* 3FDB8 800A85B8 0300E4A8 */  swl        $a0, 0x3($a3)
    /* 3FDBC 800A85BC 0000E4B8 */  swr        $a0, 0x0($a3)
    /* 3FDC0 800A85C0 0700E5A8 */  swl        $a1, 0x7($a3)
    /* 3FDC4 800A85C4 0400E5B8 */  swr        $a1, 0x4($a3)
    /* 3FDC8 800A85C8 6C00A48F */  lw         $a0, 0x6C($sp)
    /* 3FDCC 800A85CC 0F80033C */  lui        $v1, %hi(D_800F49F0)
    /* 3FDD0 800A85D0 F04964AC */  sw         $a0, %lo(D_800F49F0)($v1)
    /* 3FDD4 800A85D4 4400A493 */  lbu        $a0, 0x44($sp)
    /* 3FDD8 800A85D8 B7A10208 */  j          .L800A86DC
    /* 3FDDC 800A85DC 02000224 */   addiu     $v0, $zero, 0x2
  .L800A85E0:
    /* 3FDE0 800A85E0 1000A38F */  lw         $v1, 0x10($sp)
    /* 3FDE4 800A85E4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3FDE8 800A85E8 3F006210 */  beq        $v1, $v0, .L800A86E8
    /* 3FDEC 800A85EC 00000000 */   nop
    /* 3FDF0 800A85F0 1400A28F */  lw         $v0, 0x14($sp)
    /* 3FDF4 800A85F4 00000000 */  nop
    /* 3FDF8 800A85F8 02004228 */  slti       $v0, $v0, 0x2
    /* 3FDFC 800A85FC 3A004010 */  beqz       $v0, .L800A86E8
    /* 3FE00 800A8600 00000000 */   nop
    /* 3FE04 800A8604 1800A28F */  lw         $v0, 0x18($sp)
    /* 3FE08 800A8608 00000000 */  nop
    /* 3FE0C 800A860C 02004228 */  slti       $v0, $v0, 0x2
    /* 3FE10 800A8610 35004010 */  beqz       $v0, .L800A86E8
    /* 3FE14 800A8614 00000000 */   nop
    /* 3FE18 800A8618 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 3FE1C 800A861C 00000000 */  nop
    /* 3FE20 800A8620 02004228 */  slti       $v0, $v0, 0x2
    /* 3FE24 800A8624 30004010 */  beqz       $v0, .L800A86E8
    /* 3FE28 800A8628 00000000 */   nop
    /* 3FE2C 800A862C 2000A28F */  lw         $v0, 0x20($sp)
    /* 3FE30 800A8630 00000000 */  nop
    /* 3FE34 800A8634 02004228 */  slti       $v0, $v0, 0x2
    /* 3FE38 800A8638 2B004010 */  beqz       $v0, .L800A86E8
    /* 3FE3C 800A863C 00000000 */   nop
    /* 3FE40 800A8640 AC05C28E */  lw         $v0, 0x5AC($s6)
    /* 3FE44 800A8644 00000000 */  nop
    /* 3FE48 800A8648 00404230 */  andi       $v0, $v0, 0x4000
    /* 3FE4C 800A864C 0E004010 */  beqz       $v0, .L800A8688
    /* 3FE50 800A8650 00000000 */   nop
    /* 3FE54 800A8654 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3FE58 800A8658 00000000 */  nop
    /* 3FE5C 800A865C 00000285 */  lh         $v0, 0x0($t0)
    /* 3FE60 800A8660 00000000 */  nop
    /* 3FE64 800A8664 04004104 */  bgez       $v0, .L800A8678
    /* 3FE68 800A8668 02000224 */   addiu     $v0, $zero, 0x2
    /* 3FE6C 800A866C FE17C392 */  lbu        $v1, 0x17FE($s6)
    /* 3FE70 800A8670 9FA10208 */  j          .L800A867C
    /* 3FE74 800A8674 06000224 */   addiu     $v0, $zero, 0x6
  .L800A8678:
    /* 3FE78 800A8678 FE17C392 */  lbu        $v1, 0x17FE($s6)
  .L800A867C:
    /* 3FE7C 800A867C 00000000 */  nop
    /* 3FE80 800A8680 19006210 */  beq        $v1, $v0, .L800A86E8
    /* 3FE84 800A8684 00000000 */   nop
  .L800A8688:
    /* 3FE88 800A8688 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3FE8C 800A868C 00000000 */  nop
    /* 3FE90 800A8690 040000A5 */  sh         $zero, 0x4($t0)
    /* 3FE94 800A8694 1000A38F */  lw         $v1, 0x10($sp)
    /* 3FE98 800A8698 B800A88F */  lw         $t0, 0xB8($sp)
    /* 3FE9C 800A869C 01000224 */  addiu      $v0, $zero, 0x1
    /* 3FEA0 800A86A0 000003AD */  sw         $v1, 0x0($t0)
    /* 3FEA4 800A86A4 0F80033C */  lui        $v1, %hi(D_800F4B08)
    /* 3FEA8 800A86A8 084B6724 */  addiu      $a3, $v1, %lo(D_800F4B08)
    /* 3FEAC 800A86AC 5B00A48B */  lwl        $a0, 0x5B($sp)
    /* 3FEB0 800A86B0 5800A49B */  lwr        $a0, 0x58($sp)
    /* 3FEB4 800A86B4 5F00A58B */  lwl        $a1, 0x5F($sp)
    /* 3FEB8 800A86B8 5C00A59B */  lwr        $a1, 0x5C($sp)
    /* 3FEBC 800A86BC 0300E4A8 */  swl        $a0, 0x3($a3)
    /* 3FEC0 800A86C0 0000E4B8 */  swr        $a0, 0x0($a3)
    /* 3FEC4 800A86C4 0700E5A8 */  swl        $a1, 0x7($a3)
    /* 3FEC8 800A86C8 0400E5B8 */  swr        $a1, 0x4($a3)
    /* 3FECC 800A86CC 6800A48F */  lw         $a0, 0x68($sp)
    /* 3FED0 800A86D0 0F80033C */  lui        $v1, %hi(D_800F49F0)
    /* 3FED4 800A86D4 F04964AC */  sw         $a0, %lo(D_800F49F0)($v1)
    /* 3FED8 800A86D8 4000A493 */  lbu        $a0, 0x40($sp)
  .L800A86DC:
    /* 3FEDC 800A86DC 0F80033C */  lui        $v1, %hi(D_800F49F9)
    /* 3FEE0 800A86E0 C0A20208 */  j          .L800A8B00
    /* 3FEE4 800A86E4 F94964A0 */   sb        $a0, %lo(D_800F49F9)($v1)
  .L800A86E8:
    /* 3FEE8 800A86E8 0800C28E */  lw         $v0, 0x8($s6)
    /* 3FEEC 800A86EC 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3FEF0 800A86F0 24104300 */  and        $v0, $v0, $v1
    /* 3FEF4 800A86F4 02014014 */  bnez       $v0, .L800A8B00
    /* 3FEF8 800A86F8 03000224 */   addiu     $v0, $zero, 0x3
    /* 3FEFC 800A86FC B400A88F */  lw         $t0, 0xB4($sp)
    /* 3FF00 800A8700 00000000 */  nop
    /* 3FF04 800A8704 04000285 */  lh         $v0, 0x4($t0)
    /* 3FF08 800A8708 00000000 */  nop
    /* 3FF0C 800A870C 08004104 */  bgez       $v0, .L800A8730
    /* 3FF10 800A8710 04001324 */   addiu     $s3, $zero, 0x4
    /* 3FF14 800A8714 7C00A88F */  lw         $t0, 0x7C($sp)
    /* 3FF18 800A8718 00000000 */  nop
    /* 3FF1C 800A871C 23A00800 */  negu       $s4, $t0
    /* 3FF20 800A8720 7800A88F */  lw         $t0, 0x78($sp)
    /* 3FF24 800A8724 21980000 */  addu       $s3, $zero, $zero
    /* 3FF28 800A8728 CEA10208 */  j          .L800A8738
    /* 3FF2C 800A872C 23A80800 */   negu      $s5, $t0
  .L800A8730:
    /* 3FF30 800A8730 7C00B48F */  lw         $s4, 0x7C($sp)
    /* 3FF34 800A8734 7800B58F */  lw         $s5, 0x78($sp)
  .L800A8738:
    /* 3FF38 800A8738 FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 3FF3C 800A873C 4800A427 */  addiu      $a0, $sp, 0x48
    /* 3FF40 800A8740 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3FF44 800A8744 2000C296 */  lhu        $v0, 0x20($s6)
    /* 3FF48 800A8748 04000395 */  lhu        $v1, 0x4($t0)
    /* 3FF4C 800A874C 21286002 */  addu       $a1, $s3, $zero
    /* 3FF50 800A8750 21104300 */  addu       $v0, $v0, $v1
    /* 3FF54 800A8754 21105400 */  addu       $v0, $v0, $s4
    /* 3FF58 800A8758 4C00A2A7 */  sh         $v0, 0x4C($sp)
    /* 3FF5C 800A875C 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3FF60 800A8760 02007326 */  addiu      $s3, $s3, 0x2
    /* 3FF64 800A8764 23105400 */  subu       $v0, $v0, $s4
    /* 3FF68 800A8768 CDA2020C */  jal        func_800A8B34
    /* 3FF6C 800A876C 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 3FF70 800A8770 4C00A397 */  lhu        $v1, 0x4C($sp)
    /* 3FF74 800A8774 5000A427 */  addiu      $a0, $sp, 0x50
    /* 3FF78 800A8778 2800A2AF */  sw         $v0, 0x28($sp)
    /* 3FF7C 800A877C 5400A3A7 */  sh         $v1, 0x54($sp)
    /* 3FF80 800A8780 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 3FF84 800A8784 21286002 */  addu       $a1, $s3, $zero
    /* 3FF88 800A8788 21105400 */  addu       $v0, $v0, $s4
    /* 3FF8C 800A878C CDA2020C */  jal        func_800A8B34
    /* 3FF90 800A8790 5000A2A7 */   sh        $v0, 0x50($sp)
    /* 3FF94 800A8794 21204000 */  addu       $a0, $v0, $zero
    /* 3FF98 800A8798 2800A38F */  lw         $v1, 0x28($sp)
    /* 3FF9C 800A879C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3FFA0 800A87A0 03006214 */  bne        $v1, $v0, .L800A87B0
    /* 3FFA4 800A87A4 2C00A4AF */   sw        $a0, 0x2C($sp)
    /* 3FFA8 800A87A8 D5008310 */  beq        $a0, $v1, .L800A8B00
    /* 3FFAC 800A87AC 03000224 */   addiu     $v0, $zero, 0x3
  .L800A87B0:
    /* 3FFB0 800A87B0 B400A88F */  lw         $t0, 0xB4($sp)
    /* 3FFB4 800A87B4 00000000 */  nop
    /* 3FFB8 800A87B8 04000695 */  lhu        $a2, 0x4($t0)
    /* 3FFBC 800A87BC 00000000 */  nop
    /* 3FFC0 800A87C0 00140600 */  sll        $v0, $a2, 16
    /* 3FFC4 800A87C4 031C0200 */  sra        $v1, $v0, 16
    /* 3FFC8 800A87C8 C2170200 */  srl        $v0, $v0, 31
    /* 3FFCC 800A87CC 21186200 */  addu       $v1, $v1, $v0
    /* 3FFD0 800A87D0 2800A28F */  lw         $v0, 0x28($sp)
    /* 3FFD4 800A87D4 00000000 */  nop
    /* 3FFD8 800A87D8 02004228 */  slti       $v0, $v0, 0x2
    /* 3FFDC 800A87DC BB004010 */  beqz       $v0, .L800A8ACC
    /* 3FFE0 800A87E0 43B80300 */   sra       $s7, $v1, 1
    /* 3FFE4 800A87E4 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 3FFE8 800A87E8 00000000 */  nop
    /* 3FFEC 800A87EC 02004228 */  slti       $v0, $v0, 0x2
    /* 3FFF0 800A87F0 37004010 */  beqz       $v0, .L800A88D0
    /* 3FFF4 800A87F4 4800A427 */   addiu     $a0, $sp, 0x48
    /* 3FFF8 800A87F8 FEFF7326 */  addiu      $s3, $s3, -0x2
    /* 3FFFC 800A87FC 2000C296 */  lhu        $v0, 0x20($s6)
    /* 40000 800A8800 21286002 */  addu       $a1, $s3, $zero
    /* 40004 800A8804 21104600 */  addu       $v0, $v0, $a2
    /* 40008 800A8808 4C00A2A7 */  sh         $v0, 0x4C($sp)
    /* 4000C 800A880C 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 40010 800A8810 02007326 */  addiu      $s3, $s3, 0x2
    /* 40014 800A8814 23105400 */  subu       $v0, $v0, $s4
    /* 40018 800A8818 CDA2020C */  jal        func_800A8B34
    /* 4001C 800A881C 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 40020 800A8820 4C00A397 */  lhu        $v1, 0x4C($sp)
    /* 40024 800A8824 5000A427 */  addiu      $a0, $sp, 0x50
    /* 40028 800A8828 3000A2AF */  sw         $v0, 0x30($sp)
    /* 4002C 800A882C 5400A3A7 */  sh         $v1, 0x54($sp)
    /* 40030 800A8830 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 40034 800A8834 21286002 */  addu       $a1, $s3, $zero
    /* 40038 800A8838 21105400 */  addu       $v0, $v0, $s4
    /* 4003C 800A883C CDA2020C */  jal        func_800A8B34
    /* 40040 800A8840 5000A2A7 */   sh        $v0, 0x50($sp)
    /* 40044 800A8844 21204000 */  addu       $a0, $v0, $zero
    /* 40048 800A8848 3000A38F */  lw         $v1, 0x30($sp)
    /* 4004C 800A884C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 40050 800A8850 03006214 */  bne        $v1, $v0, .L800A8860
    /* 40054 800A8854 3400A4AF */   sw        $a0, 0x34($sp)
    /* 40058 800A8858 A9008310 */  beq        $a0, $v1, .L800A8B00
    /* 4005C 800A885C 03000224 */   addiu     $v0, $zero, 0x3
  .L800A8860:
    /* 40060 800A8860 3000A28F */  lw         $v0, 0x30($sp)
    /* 40064 800A8864 00000000 */  nop
    /* 40068 800A8868 9D00401C */  bgtz       $v0, .L800A8AE0
    /* 4006C 800A886C 00000000 */   nop
    /* 40070 800A8870 3400A28F */  lw         $v0, 0x34($sp)
    /* 40074 800A8874 00000000 */  nop
    /* 40078 800A8878 1600401C */  bgtz       $v0, .L800A88D4
    /* 4007C 800A887C 23401400 */   negu      $t0, $s4
    /* 40080 800A8880 2800A48F */  lw         $a0, 0x28($sp)
    /* 40084 800A8884 00000000 */  nop
    /* 40088 800A8888 05008014 */  bnez       $a0, .L800A88A0
    /* 4008C 800A888C 01000224 */   addiu     $v0, $zero, 0x1
    /* 40090 800A8890 2C00A38F */  lw         $v1, 0x2C($sp)
    /* 40094 800A8894 00000000 */  nop
    /* 40098 800A8898 0E006210 */  beq        $v1, $v0, .L800A88D4
    /* 4009C 800A889C 00000000 */   nop
  .L800A88A0:
    /* 400A0 800A88A0 05008214 */  bne        $a0, $v0, .L800A88B8
    /* 400A4 800A88A4 00000000 */   nop
    /* 400A8 800A88A8 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 400AC 800A88AC 00000000 */  nop
    /* 400B0 800A88B0 8B004410 */  beq        $v0, $a0, .L800A8AE0
    /* 400B4 800A88B4 00000000 */   nop
  .L800A88B8:
    /* 400B8 800A88B8 4A00A387 */  lh         $v1, 0x4A($sp)
    /* 400BC 800A88BC 5200A287 */  lh         $v0, 0x52($sp)
    /* 400C0 800A88C0 00000000 */  nop
    /* 400C4 800A88C4 2A104300 */  slt        $v0, $v0, $v1
    /* 400C8 800A88C8 85004010 */  beqz       $v0, .L800A8AE0
    /* 400CC 800A88CC 00000000 */   nop
  .L800A88D0:
    /* 400D0 800A88D0 23401400 */  negu       $t0, $s4
  .L800A88D4:
    /* 400D4 800A88D4 7000A8AF */  sw         $t0, 0x70($sp)
    /* 400D8 800A88D8 2188A002 */  addu       $s1, $s5, $zero
    /* 400DC 800A88DC 23801700 */  negu       $s0, $s7
    /* 400E0 800A88E0 01001E24 */  addiu      $fp, $zero, 0x1
    /* 400E4 800A88E4 FDFF0824 */  addiu      $t0, $zero, -0x3
  .L800A88E8:
    /* 400E8 800A88E8 7400A8AF */  sw         $t0, 0x74($sp)
    /* 400EC 800A88EC 23987E02 */  subu       $s3, $s3, $fp
    /* 400F0 800A88F0 4800B227 */  addiu      $s2, $sp, 0x48
    /* 400F4 800A88F4 2000C296 */  lhu        $v0, 0x20($s6)
    /* 400F8 800A88F8 21204002 */  addu       $a0, $s2, $zero
    /* 400FC 800A88FC 21105700 */  addu       $v0, $v0, $s7
    /* 40100 800A8900 21105400 */  addu       $v0, $v0, $s4
    /* 40104 800A8904 4C00A2A7 */  sh         $v0, 0x4C($sp)
    /* 40108 800A8908 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 4010C 800A890C 21286002 */  addu       $a1, $s3, $zero
    /* 40110 800A8910 21105000 */  addu       $v0, $v0, $s0
    /* 40114 800A8914 CDA2020C */  jal        func_800A8B34
    /* 40118 800A8918 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 4011C 800A891C 8000A88F */  lw         $t0, 0x80($sp)
    /* 40120 800A8920 00000000 */  nop
    /* 40124 800A8924 4000038D */  lw         $v1, 0x40($t0)
    /* 40128 800A8928 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 4012C 800A892C 2A104300 */  slt        $v0, $v0, $v1
    /* 40130 800A8930 02004010 */  beqz       $v0, .L800A893C
    /* 40134 800A8934 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 40138 800A8938 2C00A2AF */  sw         $v0, 0x2C($sp)
  .L800A893C:
    /* 4013C 800A893C 21987E02 */  addu       $s3, $s3, $fp
    /* 40140 800A8940 2000C296 */  lhu        $v0, 0x20($s6)
    /* 40144 800A8944 21204002 */  addu       $a0, $s2, $zero
    /* 40148 800A8948 21105700 */  addu       $v0, $v0, $s7
    /* 4014C 800A894C 21105500 */  addu       $v0, $v0, $s5
    /* 40150 800A8950 4C00A2A7 */  sh         $v0, 0x4C($sp)
    /* 40154 800A8954 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 40158 800A8958 21286002 */  addu       $a1, $s3, $zero
    /* 4015C 800A895C 21105000 */  addu       $v0, $v0, $s0
    /* 40160 800A8960 21105100 */  addu       $v0, $v0, $s1
    /* 40164 800A8964 CDA2020C */  jal        func_800A8B34
    /* 40168 800A8968 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 4016C 800A896C 8000A88F */  lw         $t0, 0x80($sp)
    /* 40170 800A8970 00000000 */  nop
    /* 40174 800A8974 4000038D */  lw         $v1, 0x40($t0)
    /* 40178 800A8978 3000A2AF */  sw         $v0, 0x30($sp)
    /* 4017C 800A897C 2A104300 */  slt        $v0, $v0, $v1
    /* 40180 800A8980 02004010 */  beqz       $v0, .L800A898C
    /* 40184 800A8984 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 40188 800A8988 3000A2AF */  sw         $v0, 0x30($sp)
  .L800A898C:
    /* 4018C 800A898C 21204002 */  addu       $a0, $s2, $zero
    /* 40190 800A8990 7400A88F */  lw         $t0, 0x74($sp)
    /* 40194 800A8994 2000C296 */  lhu        $v0, 0x20($s6)
    /* 40198 800A8998 21986802 */  addu       $s3, $s3, $t0
    /* 4019C 800A899C 21286002 */  addu       $a1, $s3, $zero
    /* 401A0 800A89A0 4C00A2A7 */  sh         $v0, 0x4C($sp)
    /* 401A4 800A89A4 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 401A8 800A89A8 7000A88F */  lw         $t0, 0x70($sp)
    /* 401AC 800A89AC 21105000 */  addu       $v0, $v0, $s0
    /* 401B0 800A89B0 21104800 */  addu       $v0, $v0, $t0
    /* 401B4 800A89B4 CDA2020C */  jal        func_800A8B34
    /* 401B8 800A89B8 4800A2A7 */   sh        $v0, 0x48($sp)
    /* 401BC 800A89BC 8000A88F */  lw         $t0, 0x80($sp)
    /* 401C0 800A89C0 00000000 */  nop
    /* 401C4 800A89C4 4000038D */  lw         $v1, 0x40($t0)
    /* 401C8 800A89C8 3400A2AF */  sw         $v0, 0x34($sp)
    /* 401CC 800A89CC 2A104300 */  slt        $v0, $v0, $v1
    /* 401D0 800A89D0 02004010 */  beqz       $v0, .L800A89DC
    /* 401D4 800A89D4 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 401D8 800A89D8 3400A2AF */  sw         $v0, 0x34($sp)
  .L800A89DC:
    /* 401DC 800A89DC 0F80033C */  lui        $v1, %hi(D_800F4B08)
    /* 401E0 800A89E0 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 401E4 800A89E4 084B6724 */  addiu      $a3, $v1, %lo(D_800F4B08)
    /* 401E8 800A89E8 4B00A48B */  lwl        $a0, 0x4B($sp)
    /* 401EC 800A89EC 4800A49B */  lwr        $a0, 0x48($sp)
    /* 401F0 800A89F0 4F00A58B */  lwl        $a1, 0x4F($sp)
    /* 401F4 800A89F4 4C00A59B */  lwr        $a1, 0x4C($sp)
    /* 401F8 800A89F8 0300E4A8 */  swl        $a0, 0x3($a3)
    /* 401FC 800A89FC 0000E4B8 */  swr        $a0, 0x0($a3)
    /* 40200 800A8A00 0700E5A8 */  swl        $a1, 0x7($a3)
    /* 40204 800A8A04 0400E5B8 */  swr        $a1, 0x4($a3)
    /* 40208 800A8A08 02004228 */  slti       $v0, $v0, 0x2
    /* 4020C 800A8A0C 28004010 */  beqz       $v0, .L800A8AB0
    /* 40210 800A8A10 00000000 */   nop
    /* 40214 800A8A14 3000A28F */  lw         $v0, 0x30($sp)
    /* 40218 800A8A18 00000000 */  nop
    /* 4021C 800A8A1C 02004228 */  slti       $v0, $v0, 0x2
    /* 40220 800A8A20 23004010 */  beqz       $v0, .L800A8AB0
    /* 40224 800A8A24 00000000 */   nop
    /* 40228 800A8A28 3400A28F */  lw         $v0, 0x34($sp)
    /* 4022C 800A8A2C 00000000 */  nop
    /* 40230 800A8A30 02004228 */  slti       $v0, $v0, 0x2
    /* 40234 800A8A34 31004010 */  beqz       $v0, .L800A8AFC
    /* 40238 800A8A38 21204002 */   addu      $a0, $s2, $zero
    /* 4023C 800A8A3C 1C00C296 */  lhu        $v0, 0x1C($s6)
    /* 40240 800A8A40 7000A88F */  lw         $t0, 0x70($sp)
    /* 40244 800A8A44 21105000 */  addu       $v0, $v0, $s0
    /* 40248 800A8A48 21104800 */  addu       $v0, $v0, $t0
    /* 4024C 800A8A4C 4800A2A7 */  sh         $v0, 0x48($sp)
    /* 40250 800A8A50 2000C296 */  lhu        $v0, 0x20($s6)
    /* 40254 800A8A54 21286002 */  addu       $a1, $s3, $zero
    /* 40258 800A8A58 21105700 */  addu       $v0, $v0, $s7
    /* 4025C 800A8A5C CDA2020C */  jal        func_800A8B34
    /* 40260 800A8A60 4C00A2A7 */   sh        $v0, 0x4C($sp)
    /* 40264 800A8A64 2800A2AF */  sw         $v0, 0x28($sp)
    /* 40268 800A8A68 02004228 */  slti       $v0, $v0, 0x2
    /* 4026C 800A8A6C 23004010 */  beqz       $v0, .L800A8AFC
    /* 40270 800A8A70 21987E02 */   addu      $s3, $s3, $fp
    /* 40274 800A8A74 21A00000 */  addu       $s4, $zero, $zero
  .L800A8A78:
    /* 40278 800A8A78 B400A88F */  lw         $t0, 0xB4($sp)
    /* 4027C 800A8A7C 00000000 */  nop
    /* 40280 800A8A80 040017A5 */  sh         $s7, 0x4($t0)
    /* 40284 800A8A84 000010A5 */  sh         $s0, 0x0($t0)
  .L800A8A88:
    /* 40288 800A8A88 3400A38F */  lw         $v1, 0x34($sp)
    /* 4028C 800A8A8C B800A88F */  lw         $t0, 0xB8($sp)
    /* 40290 800A8A90 21108002 */  addu       $v0, $s4, $zero
    /* 40294 800A8A94 000003AD */  sw         $v1, 0x0($t0)
    /* 40298 800A8A98 AC05C38E */  lw         $v1, 0x5AC($s6)
    /* 4029C 800A8A9C 07006432 */  andi       $a0, $s3, 0x7
    /* 402A0 800A8AA0 FE17C4A2 */  sb         $a0, 0x17FE($s6)
    /* 402A4 800A8AA4 00206334 */  ori        $v1, $v1, 0x2000
    /* 402A8 800A8AA8 C0A20208 */  j          .L800A8B00
    /* 402AC 800A8AAC AC05C3AE */   sw        $v1, 0x5AC($s6)
  .L800A8AB0:
    /* 402B0 800A8AB0 3400A28F */  lw         $v0, 0x34($sp)
    /* 402B4 800A8AB4 00000000 */  nop
    /* 402B8 800A8AB8 02004228 */  slti       $v0, $v0, 0x2
    /* 402BC 800A8ABC 0F004010 */  beqz       $v0, .L800A8AFC
    /* 402C0 800A8AC0 21B80000 */   addu      $s7, $zero, $zero
    /* 402C4 800A8AC4 9EA20208 */  j          .L800A8A78
    /* 402C8 800A8AC8 01001424 */   addiu     $s4, $zero, 0x1
  .L800A8ACC:
    /* 402CC 800A8ACC 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 402D0 800A8AD0 00000000 */  nop
    /* 402D4 800A8AD4 02004228 */  slti       $v0, $v0, 0x2
    /* 402D8 800A8AD8 09004010 */  beqz       $v0, .L800A8B00
    /* 402DC 800A8ADC 03000224 */   addiu     $v0, $zero, 0x3
  .L800A8AE0:
    /* 402E0 800A8AE0 FEFF7326 */  addiu      $s3, $s3, -0x2
    /* 402E4 800A8AE4 23881500 */  negu       $s1, $s5
    /* 402E8 800A8AE8 2180E002 */  addu       $s0, $s7, $zero
    /* 402EC 800A8AEC FFFF1E24 */  addiu      $fp, $zero, -0x1
    /* 402F0 800A8AF0 03000824 */  addiu      $t0, $zero, 0x3
    /* 402F4 800A8AF4 3AA20208 */  j          .L800A88E8
    /* 402F8 800A8AF8 7000B4AF */   sw        $s4, 0x70($sp)
  .L800A8AFC:
    /* 402FC 800A8AFC 03000224 */  addiu      $v0, $zero, 0x3
  .L800A8B00:
    /* 40300 800A8B00 AC00BF8F */  lw         $ra, 0xAC($sp)
    /* 40304 800A8B04 A800BE8F */  lw         $fp, 0xA8($sp)
    /* 40308 800A8B08 A400B78F */  lw         $s7, 0xA4($sp)
    /* 4030C 800A8B0C A000B68F */  lw         $s6, 0xA0($sp)
    /* 40310 800A8B10 9C00B58F */  lw         $s5, 0x9C($sp)
    /* 40314 800A8B14 9800B48F */  lw         $s4, 0x98($sp)
    /* 40318 800A8B18 9400B38F */  lw         $s3, 0x94($sp)
    /* 4031C 800A8B1C 9000B28F */  lw         $s2, 0x90($sp)
    /* 40320 800A8B20 8C00B18F */  lw         $s1, 0x8C($sp)
    /* 40324 800A8B24 8800B08F */  lw         $s0, 0x88($sp)
    /* 40328 800A8B28 B000BD27 */  addiu      $sp, $sp, 0xB0
    /* 4032C 800A8B2C 0800E003 */  jr         $ra
    /* 40330 800A8B30 00000000 */   nop
endlabel func_800A76BC
