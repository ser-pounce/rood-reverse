nonmatching func_800A6798, 0x21C

glabel func_800A6798
    /* 3DF98 800A6798 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 3DF9C 800A679C 2000B0AF */  sw         $s0, 0x20($sp)
    /* 3DFA0 800A67A0 21808000 */  addu       $s0, $a0, $zero
    /* 3DFA4 800A67A4 2400B1AF */  sw         $s1, 0x24($sp)
    /* 3DFA8 800A67A8 2188A000 */  addu       $s1, $a1, $zero
    /* 3DFAC 800A67AC 2128C000 */  addu       $a1, $a2, $zero
    /* 3DFB0 800A67B0 0F80023C */  lui        $v0, %hi(D_800F4B0A)
    /* 3DFB4 800A67B4 3000BFAF */  sw         $ra, 0x30($sp)
    /* 3DFB8 800A67B8 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 3DFBC 800A67BC 2800B2AF */  sw         $s2, 0x28($sp)
    /* 3DFC0 800A67C0 EC060386 */  lh         $v1, 0x6EC($s0)
    /* 3DFC4 800A67C4 0A4B4284 */  lh         $v0, %lo(D_800F4B0A)($v0)
    /* 3DFC8 800A67C8 00000000 */  nop
    /* 3DFCC 800A67CC 2A104300 */  slt        $v0, $v0, $v1
    /* 3DFD0 800A67D0 03004014 */  bnez       $v0, .L800A67E0
    /* 3DFD4 800A67D4 21980000 */   addu      $s3, $zero, $zero
    /* 3DFD8 800A67D8 659A0208 */  j          .L800A6994
    /* 3DFDC 800A67DC 21106002 */   addu      $v0, $s3, $zero
  .L800A67E0:
    /* 3DFE0 800A67E0 E7FF093C */  lui        $t1, (0xFFE7FFFF >> 16)
    /* 3DFE4 800A67E4 FFFF2935 */  ori        $t1, $t1, (0xFFE7FFFF & 0xFFFF)
    /* 3DFE8 800A67E8 21200002 */  addu       $a0, $s0, $zero
    /* 3DFEC 800A67EC 02002296 */  lhu        $v0, 0x2($s1)
    /* 3DFF0 800A67F0 1800A627 */  addiu      $a2, $sp, 0x18
    /* 3DFF4 800A67F4 000020A6 */  sh         $zero, 0x0($s1)
    /* 3DFF8 800A67F8 040020A6 */  sh         $zero, 0x4($s1)
    /* 3DFFC 800A67FC EC004224 */  addiu      $v0, $v0, 0xEC
    /* 3E000 800A6800 020022A6 */  sh         $v0, 0x2($s1)
    /* 3E004 800A6804 1C00028E */  lw         $v0, 0x1C($s0)
    /* 3E008 800A6808 2000038E */  lw         $v1, 0x20($s0)
    /* 3E00C 800A680C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3E010 800A6810 1400A3AF */  sw         $v1, 0x14($sp)
    /* 3E014 800A6814 1C000296 */  lhu        $v0, 0x1C($s0)
    /* 3E018 800A6818 00002396 */  lhu        $v1, 0x0($s1)
    /* 3E01C 800A681C 21380000 */  addu       $a3, $zero, $zero
    /* 3E020 800A6820 21104300 */  addu       $v0, $v0, $v1
    /* 3E024 800A6824 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* 3E028 800A6828 1E000296 */  lhu        $v0, 0x1E($s0)
    /* 3E02C 800A682C 0800038E */  lw         $v1, 0x8($s0)
    /* 3E030 800A6830 02002896 */  lhu        $t0, 0x2($s1)
    /* 3E034 800A6834 24186900 */  and        $v1, $v1, $t1
    /* 3E038 800A6838 21104800 */  addu       $v0, $v0, $t0
    /* 3E03C 800A683C 1000083C */  lui        $t0, (0x100000 >> 16)
    /* 3E040 800A6840 1E0002A6 */  sh         $v0, 0x1E($s0)
    /* 3E044 800A6844 20000296 */  lhu        $v0, 0x20($s0)
    /* 3E048 800A6848 04002996 */  lhu        $t1, 0x4($s1)
    /* 3E04C 800A684C 25186800 */  or         $v1, $v1, $t0
    /* 3E050 800A6850 080003AE */  sw         $v1, 0x8($s0)
    /* 3E054 800A6854 21104900 */  addu       $v0, $v0, $t1
    /* 3E058 800A6858 AF9D020C */  jal        func_800A76BC
    /* 3E05C 800A685C 200002A6 */   sh        $v0, 0x20($s0)
    /* 3E060 800A6860 03000324 */  addiu      $v1, $zero, 0x3
    /* 3E064 800A6864 3E004310 */  beq        $v0, $v1, .L800A6960
    /* 3E068 800A6868 E7FF043C */   lui       $a0, (0xFFE7FFFF >> 16)
    /* 3E06C 800A686C AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3E070 800A6870 00000000 */  nop
    /* 3E074 800A6874 00204230 */  andi       $v0, $v0, 0x2000
    /* 3E078 800A6878 3A004014 */  bnez       $v0, .L800A6964
    /* 3E07C 800A687C FFFF8434 */   ori       $a0, $a0, (0xFFE7FFFF & 0xFFFF)
    /* 3E080 800A6880 1800A28F */  lw         $v0, 0x18($sp)
    /* 3E084 800A6884 00000000 */  nop
    /* 3E088 800A6888 05004228 */  slti       $v0, $v0, 0x5
    /* 3E08C 800A688C 34004010 */  beqz       $v0, .L800A6960
    /* 3E090 800A6890 E7FF043C */   lui       $a0, (0xFFE7FFFF >> 16)
    /* 3E094 800A6894 CA03010C */  jal        rsin
    /* 3E098 800A6898 00020424 */   addiu     $a0, $zero, 0x200
    /* 3E09C 800A689C 3C060396 */  lhu        $v1, 0x63C($s0)
    /* 3E0A0 800A68A0 00000000 */  nop
    /* 3E0A4 800A68A4 18004300 */  mult       $v0, $v1
    /* 3E0A8 800A68A8 12180000 */  mflo       $v1
    /* 3E0AC 800A68AC 02006104 */  bgez       $v1, .L800A68B8
    /* 3E0B0 800A68B0 1800A2AF */   sw        $v0, 0x18($sp)
    /* 3E0B4 800A68B4 FF0F6324 */  addiu      $v1, $v1, 0xFFF
  .L800A68B8:
    /* 3E0B8 800A68B8 0F80023C */  lui        $v0, %hi(D_800F49F9)
    /* 3E0BC 800A68BC F9494290 */  lbu        $v0, %lo(D_800F49F9)($v0)
    /* 3E0C0 800A68C0 031B0300 */  sra        $v1, $v1, 12
    /* 3E0C4 800A68C4 42100200 */  srl        $v0, $v0, 1
    /* 3E0C8 800A68C8 01004230 */  andi       $v0, $v0, 0x1
    /* 3E0CC 800A68CC 04004010 */  beqz       $v0, .L800A68E0
    /* 3E0D0 800A68D0 1800A3AF */   sw        $v1, 0x18($sp)
    /* 3E0D4 800A68D4 1800A297 */  lhu        $v0, 0x18($sp)
    /* 3E0D8 800A68D8 3B9A0208 */  j          .L800A68EC
    /* 3E0DC 800A68DC 040022A6 */   sh        $v0, 0x4($s1)
  .L800A68E0:
    /* 3E0E0 800A68E0 1800A297 */  lhu        $v0, 0x18($sp)
    /* 3E0E4 800A68E4 00000000 */  nop
    /* 3E0E8 800A68E8 000022A6 */  sh         $v0, 0x0($s1)
  .L800A68EC:
    /* 3E0EC 800A68EC 0F80023C */  lui        $v0, %hi(D_800F4B08)
    /* 3E0F0 800A68F0 084B5224 */  addiu      $s2, $v0, %lo(D_800F4B08)
    /* 3E0F4 800A68F4 21204002 */  addu       $a0, $s2, $zero
    /* 3E0F8 800A68F8 00002586 */  lh         $a1, 0x0($s1)
    /* 3E0FC 800A68FC 04002686 */  lh         $a2, 0x4($s1)
    /* 3E100 800A6900 BA9B020C */  jal        func_800A6EE8
    /* 3E104 800A6904 01000724 */   addiu     $a3, $zero, 0x1
    /* 3E108 800A6908 02004386 */  lh         $v1, 0x2($s2)
    /* 3E10C 800A690C 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3E110 800A6910 23104300 */  subu       $v0, $v0, $v1
    /* 3E114 800A6914 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3E118 800A6918 C1FF4228 */  slti       $v0, $v0, -0x3F
    /* 3E11C 800A691C 10004014 */  bnez       $v0, .L800A6960
    /* 3E120 800A6920 E7FF043C */   lui       $a0, (0xFFE7FFFF >> 16)
    /* 3E124 800A6924 21204002 */  addu       $a0, $s2, $zero
    /* 3E128 800A6928 01000724 */  addiu      $a3, $zero, 0x1
    /* 3E12C 800A692C 00002586 */  lh         $a1, 0x0($s1)
    /* 3E130 800A6930 04002686 */  lh         $a2, 0x4($s1)
    /* 3E134 800A6934 23280500 */  negu       $a1, $a1
    /* 3E138 800A6938 BA9B020C */  jal        func_800A6EE8
    /* 3E13C 800A693C 23300600 */   negu      $a2, $a2
    /* 3E140 800A6940 02004386 */  lh         $v1, 0x2($s2)
    /* 3E144 800A6944 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3E148 800A6948 23104300 */  subu       $v0, $v0, $v1
    /* 3E14C 800A694C 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3E150 800A6950 C1FF4228 */  slti       $v0, $v0, -0x3F
    /* 3E154 800A6954 02004014 */  bnez       $v0, .L800A6960
    /* 3E158 800A6958 E7FF043C */   lui       $a0, (0xFFE7FFFF >> 16)
    /* 3E15C 800A695C 01001324 */  addiu      $s3, $zero, 0x1
  .L800A6960:
    /* 3E160 800A6960 FFFF8434 */  ori        $a0, $a0, (0xFFE7FFFF & 0xFFFF)
  .L800A6964:
    /* 3E164 800A6964 0800038E */  lw         $v1, 0x8($s0)
    /* 3E168 800A6968 21106002 */  addu       $v0, $s3, $zero
    /* 3E16C 800A696C 24186400 */  and        $v1, $v1, $a0
    /* 3E170 800A6970 FFBF0424 */  addiu      $a0, $zero, -0x4001
    /* 3E174 800A6974 24186400 */  and        $v1, $v1, $a0
    /* 3E178 800A6978 080003AE */  sw         $v1, 0x8($s0)
    /* 3E17C 800A697C 000020A6 */  sh         $zero, 0x0($s1)
    /* 3E180 800A6980 040020A6 */  sh         $zero, 0x4($s1)
    /* 3E184 800A6984 1000A38F */  lw         $v1, 0x10($sp)
    /* 3E188 800A6988 1400A48F */  lw         $a0, 0x14($sp)
    /* 3E18C 800A698C 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 3E190 800A6990 200004AE */  sw         $a0, 0x20($s0)
  .L800A6994:
    /* 3E194 800A6994 3000BF8F */  lw         $ra, 0x30($sp)
    /* 3E198 800A6998 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 3E19C 800A699C 2800B28F */  lw         $s2, 0x28($sp)
    /* 3E1A0 800A69A0 2400B18F */  lw         $s1, 0x24($sp)
    /* 3E1A4 800A69A4 2000B08F */  lw         $s0, 0x20($sp)
    /* 3E1A8 800A69A8 3800BD27 */  addiu      $sp, $sp, 0x38
    /* 3E1AC 800A69AC 0800E003 */  jr         $ra
    /* 3E1B0 800A69B0 00000000 */   nop
endlabel func_800A6798
