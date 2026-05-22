nonmatching func_800AC690, 0x8C4

glabel func_800AC690
    /* 43E90 800AC690 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 43E94 800AC694 1400B1AF */  sw         $s1, 0x14($sp)
    /* 43E98 800AC698 2188A000 */  addu       $s1, $a1, $zero
    /* 43E9C 800AC69C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 43EA0 800AC6A0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 43EA4 800AC6A4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 43EA8 800AC6A8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 43EAC 800AC6AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 43EB0 800AC6B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 43EB4 800AC6B4 0800238E */  lw         $v1, 0x8($s1)
    /* 43EB8 800AC6B8 00000000 */  nop
    /* 43EBC 800AC6BC 000F6230 */  andi       $v0, $v1, 0xF00
    /* 43EC0 800AC6C0 03004010 */  beqz       $v0, .L800AC6D0
    /* 43EC4 800AC6C4 21A88000 */   addu      $s5, $a0, $zero
    /* 43EC8 800AC6C8 C4B10208 */  j          .L800AC710
    /* 43ECC 800AC6CC 03001424 */   addiu     $s4, $zero, 0x3
  .L800AC6D0:
    /* 43ED0 800AC6D0 4000023C */  lui        $v0, (0x400000 >> 16)
    /* 43ED4 800AC6D4 24106200 */  and        $v0, $v1, $v0
    /* 43ED8 800AC6D8 0D004014 */  bnez       $v0, .L800AC710
    /* 43EDC 800AC6DC 04001424 */   addiu     $s4, $zero, 0x4
    /* 43EE0 800AC6E0 2000023C */  lui        $v0, (0x200000 >> 16)
    /* 43EE4 800AC6E4 24106200 */  and        $v0, $v1, $v0
    /* 43EE8 800AC6E8 09004014 */  bnez       $v0, .L800AC710
    /* 43EEC 800AC6EC 05001424 */   addiu     $s4, $zero, 0x5
    /* 43EF0 800AC6F0 AC05228E */  lw         $v0, 0x5AC($s1)
    /* 43EF4 800AC6F4 00000000 */  nop
    /* 43EF8 800AC6F8 08004230 */  andi       $v0, $v0, 0x8
    /* 43EFC 800AC6FC 04004014 */  bnez       $v0, .L800AC710
    /* 43F00 800AC700 06001424 */   addiu     $s4, $zero, 0x6
    /* 43F04 800AC704 B0052292 */  lbu        $v0, 0x5B0($s1)
    /* 43F08 800AC708 00000000 */  nop
    /* 43F0C 800AC70C 03005430 */  andi       $s4, $v0, 0x3
  .L800AC710:
    /* 43F10 800AC710 0800248E */  lw         $a0, 0x8($s1)
    /* 43F14 800AC714 03001024 */  addiu      $s0, $zero, 0x3
    /* 43F18 800AC718 02140400 */  srl        $v0, $a0, 16
    /* 43F1C 800AC71C 07004330 */  andi       $v1, $v0, 0x7
    /* 43F20 800AC720 40007010 */  beq        $v1, $s0, .L800AC824
    /* 43F24 800AC724 04006228 */   slti      $v0, $v1, 0x4
    /* 43F28 800AC728 05004010 */  beqz       $v0, .L800AC740
    /* 43F2C 800AC72C 02000224 */   addiu     $v0, $zero, 0x2
    /* 43F30 800AC730 08006210 */  beq        $v1, $v0, .L800AC754
    /* 43F34 800AC734 00000000 */   nop
    /* 43F38 800AC738 CBB30208 */  j          .L800ACF2C
    /* 43F3C 800AC73C 00000000 */   nop
  .L800AC740:
    /* 43F40 800AC740 04000224 */  addiu      $v0, $zero, 0x4
    /* 43F44 800AC744 BD016210 */  beq        $v1, $v0, .L800ACE3C
    /* 43F48 800AC748 2000023C */   lui       $v0, (0x200000 >> 16)
    /* 43F4C 800AC74C CBB30208 */  j          .L800ACF2C
    /* 43F50 800AC750 00000000 */   nop
  .L800AC754:
    /* 43F54 800AC754 11002282 */  lb         $v0, 0x11($s1)
    /* 43F58 800AC758 11002492 */  lbu        $a0, 0x11($s1)
    /* 43F5C 800AC75C 16004018 */  blez       $v0, .L800AC7B8
    /* 43F60 800AC760 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 43F64 800AC764 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 43F68 800AC768 00000000 */  nop
    /* 43F6C 800AC76C C21F0200 */  srl        $v1, $v0, 31
    /* 43F70 800AC770 21104300 */  addu       $v0, $v0, $v1
    /* 43F74 800AC774 43100200 */  sra        $v0, $v0, 1
    /* 43F78 800AC778 23108200 */  subu       $v0, $a0, $v0
    /* 43F7C 800AC77C 110022A2 */  sb         $v0, 0x11($s1)
    /* 43F80 800AC780 00160200 */  sll        $v0, $v0, 24
    /* 43F84 800AC784 03160200 */  sra        $v0, $v0, 24
    /* 43F88 800AC788 02004228 */  slti       $v0, $v0, 0x2
    /* 43F8C 800AC78C E7014010 */  beqz       $v0, .L800ACF2C
    /* 43F90 800AC790 2120A002 */   addu      $a0, $s5, $zero
    /* 43F94 800AC794 21300000 */  addu       $a2, $zero, $zero
    /* 43F98 800AC798 0F80023C */  lui        $v0, %hi(D_800E92E8)
    /* 43F9C 800AC79C E8924224 */  addiu      $v0, $v0, %lo(D_800E92E8)
    /* 43FA0 800AC7A0 21108202 */  addu       $v0, $s4, $v0
    /* 43FA4 800AC7A4 00004590 */  lbu        $a1, 0x0($v0)
    /* 43FA8 800AC7A8 8180020C */  jal        func_800A0204
    /* 43FAC 800AC7AC 08000724 */   addiu     $a3, $zero, 0x8
    /* 43FB0 800AC7B0 CBB30208 */  j          .L800ACF2C
    /* 43FB4 800AC7B4 110020A2 */   sb        $zero, 0x11($s1)
  .L800AC7B8:
    /* 43FB8 800AC7B8 1A182286 */  lh         $v0, 0x181A($s1)
    /* 43FBC 800AC7BC 00000000 */  nop
    /* 43FC0 800AC7C0 04004014 */  bnez       $v0, .L800AC7D4
    /* 43FC4 800AC7C4 F8FF023C */   lui       $v0, (0xFFF8FFFF >> 16)
    /* 43FC8 800AC7C8 E2FF0224 */  addiu      $v0, $zero, -0x1E
    /* 43FCC 800AC7CC 360022A6 */  sh         $v0, 0x36($s1)
    /* 43FD0 800AC7D0 F8FF023C */  lui        $v0, (0xFFF8FFFF >> 16)
  .L800AC7D4:
    /* 43FD4 800AC7D4 FFFF4234 */  ori        $v0, $v0, (0xFFF8FFFF & 0xFFFF)
    /* 43FD8 800AC7D8 0800238E */  lw         $v1, 0x8($s1)
    /* 43FDC 800AC7DC 0300043C */  lui        $a0, (0x30000 >> 16)
    /* 43FE0 800AC7E0 B70520A2 */  sb         $zero, 0x5B7($s1)
    /* 43FE4 800AC7E4 24186200 */  and        $v1, $v1, $v0
    /* 43FE8 800AC7E8 0C00228E */  lw         $v0, 0xC($s1)
    /* 43FEC 800AC7EC 25186400 */  or         $v1, $v1, $a0
    /* 43FF0 800AC7F0 0F004230 */  andi       $v0, $v0, 0xF
    /* 43FF4 800AC7F4 CD014010 */  beqz       $v0, .L800ACF2C
    /* 43FF8 800AC7F8 080023AE */   sw        $v1, 0x8($s1)
    /* 43FFC 800AC7FC 0C002492 */  lbu        $a0, 0xC($s1)
    /* 44000 800AC800 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 44004 800AC804 0F008430 */  andi       $a0, $a0, 0xF
    /* 44008 800AC808 2731020C */  jal        func_8008C49C
    /* 4400C 800AC80C FEFF8424 */   addiu     $a0, $a0, -0x2
    /* 44010 800AC810 0C00228E */  lw         $v0, 0xC($s1)
    /* 44014 800AC814 F0FF0324 */  addiu      $v1, $zero, -0x10
    /* 44018 800AC818 24104300 */  and        $v0, $v0, $v1
    /* 4401C 800AC81C CBB30208 */  j          .L800ACF2C
    /* 44020 800AC820 0C0022AE */   sw        $v0, 0xC($s1)
  .L800AC824:
    /* 44024 800AC824 11002282 */  lb         $v0, 0x11($s1)
    /* 44028 800AC828 11002492 */  lbu        $a0, 0x11($s1)
    /* 4402C 800AC82C 10004018 */  blez       $v0, .L800AC870
    /* 44030 800AC830 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 44034 800AC834 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 44038 800AC838 00000000 */  nop
    /* 4403C 800AC83C C21F0200 */  srl        $v1, $v0, 31
    /* 44040 800AC840 21104300 */  addu       $v0, $v0, $v1
    /* 44044 800AC844 43100200 */  sra        $v0, $v0, 1
    /* 44048 800AC848 23108200 */  subu       $v0, $a0, $v0
    /* 4404C 800AC84C 110022A2 */  sb         $v0, 0x11($s1)
    /* 44050 800AC850 00160200 */  sll        $v0, $v0, 24
    /* 44054 800AC854 B501401C */  bgtz       $v0, .L800ACF2C
    /* 44058 800AC858 2F000524 */   addiu     $a1, $zero, 0x2F
    /* 4405C 800AC85C 21300000 */  addu       $a2, $zero, $zero
    /* 44060 800AC860 0F002492 */  lbu        $a0, 0xF($s1)
    /* 44064 800AC864 8180020C */  jal        func_800A0204
    /* 44068 800AC868 08000724 */   addiu     $a3, $zero, 0x8
    /* 4406C 800AC86C 110020A2 */  sb         $zero, 0x11($s1)
  .L800AC870:
    /* 44070 800AC870 0800228E */  lw         $v0, 0x8($s1)
    /* 44074 800AC874 4000033C */  lui        $v1, (0x400000 >> 16)
    /* 44078 800AC878 24104300 */  and        $v0, $v0, $v1
    /* 4407C 800AC87C 10004010 */  beqz       $v0, .L800AC8C0
    /* 44080 800AC880 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 44084 800AC884 4CE2438C */  lw         $v1, %lo(vs_gametime_tickspeed)($v0)
    /* 44088 800AC888 00000000 */  nop
    /* 4408C 800AC88C C2170300 */  srl        $v0, $v1, 31
    /* 44090 800AC890 21186200 */  addu       $v1, $v1, $v0
    /* 44094 800AC894 B7052292 */  lbu        $v0, 0x5B7($s1)
    /* 44098 800AC898 43900300 */  sra        $s2, $v1, 1
    /* 4409C 800AC89C 21105200 */  addu       $v0, $v0, $s2
    /* 440A0 800AC8A0 B70522A2 */  sb         $v0, 0x5B7($s1)
    /* 440A4 800AC8A4 B7052292 */  lbu        $v0, 0x5B7($s1)
    /* 440A8 800AC8A8 07001324 */  addiu      $s3, $zero, 0x7
    /* 440AC 800AC8AC 42900200 */  srl        $s2, $v0, 1
    /* 440B0 800AC8B0 40181200 */  sll        $v1, $s2, 1
    /* 440B4 800AC8B4 23104300 */  subu       $v0, $v0, $v1
    /* 440B8 800AC8B8 37B20208 */  j          .L800AC8DC
    /* 440BC 800AC8BC B70522A2 */   sb        $v0, 0x5B7($s1)
  .L800AC8C0:
    /* 440C0 800AC8C0 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 440C4 800AC8C4 09001324 */  addiu      $s3, $zero, 0x9
    /* 440C8 800AC8C8 C21F0200 */  srl        $v1, $v0, 31
    /* 440CC 800AC8CC 21104300 */  addu       $v0, $v0, $v1
    /* 440D0 800AC8D0 43100200 */  sra        $v0, $v0, 1
    /* 440D4 800AC8D4 18005000 */  mult       $v0, $s0
    /* 440D8 800AC8D8 12900000 */  mflo       $s2
  .L800AC8DC:
    /* 440DC 800AC8DC 36002296 */  lhu        $v0, 0x36($s1)
    /* 440E0 800AC8E0 00000000 */  nop
    /* 440E4 800AC8E4 21105200 */  addu       $v0, $v0, $s2
    /* 440E8 800AC8E8 360022A6 */  sh         $v0, 0x36($s1)
    /* 440EC 800AC8EC 00140200 */  sll        $v0, $v0, 16
    /* 440F0 800AC8F0 29004104 */  bgez       $v0, .L800AC998
    /* 440F4 800AC8F4 00000000 */   nop
    /* 440F8 800AC8F8 1C002486 */  lh         $a0, 0x1C($s1)
    /* 440FC 800AC8FC 20002586 */  lh         $a1, 0x20($s1)
    /* 44100 800AC900 4337020C */  jal        func_8008DD0C
    /* 44104 800AC904 01001224 */   addiu     $s2, $zero, 0x1
    /* 44108 800AC908 40840200 */  sll        $s0, $v0, 17
    /* 4410C 800AC90C 0600A012 */  beqz       $s5, .L800AC928
    /* 44110 800AC910 43841000 */   sra       $s0, $s0, 17
    /* 44114 800AC914 03001224 */  addiu      $s2, $zero, 0x3
    /* 44118 800AC918 3E062296 */  lhu        $v0, 0x63E($s1)
    /* 4411C 800AC91C 0F80033C */  lui        $v1, %hi(D_800F4B00)
    /* 44120 800AC920 40004224 */  addiu      $v0, $v0, 0x40
    /* 44124 800AC924 004B62A4 */  sh         $v0, %lo(D_800F4B00)($v1)
  .L800AC928:
    /* 44128 800AC928 1C002486 */  lh         $a0, 0x1C($s1)
    /* 4412C 800AC92C 1E002586 */  lh         $a1, 0x1E($s1)
    /* 44130 800AC930 20002686 */  lh         $a2, 0x20($s1)
    /* 44134 800AC934 DEA4020C */  jal        func_800A9378
    /* 44138 800AC938 21384002 */   addu      $a3, $s2, $zero
    /* 4413C 800AC93C 21184000 */  addu       $v1, $v0, $zero
    /* 44140 800AC940 04006010 */  beqz       $v1, .L800AC954
    /* 44144 800AC944 2A100302 */   slt       $v0, $s0, $v1
    /* 44148 800AC948 02004010 */  beqz       $v0, .L800AC954
    /* 4414C 800AC94C 00000000 */   nop
    /* 44150 800AC950 21806000 */  addu       $s0, $v1, $zero
  .L800AC954:
    /* 44154 800AC954 1E002286 */  lh         $v0, 0x1E($s1)
    /* 44158 800AC958 36002386 */  lh         $v1, 0x36($s1)
    /* 4415C 800AC95C 00000000 */  nop
    /* 44160 800AC960 21104300 */  addu       $v0, $v0, $v1
    /* 44164 800AC964 40FF4324 */  addiu      $v1, $v0, -0xC0
    /* 44168 800AC968 2A107000 */  slt        $v0, $v1, $s0
    /* 4416C 800AC96C 36002396 */  lhu        $v1, 0x36($s1)
    /* 44170 800AC970 09004010 */  beqz       $v0, .L800AC998
    /* 44174 800AC974 23100300 */   negu      $v0, $v1
    /* 44178 800AC978 0700A012 */  beqz       $s5, .L800AC998
    /* 4417C 800AC97C 360022A6 */   sh        $v0, 0x36($s1)
    /* 44180 800AC980 EC052492 */  lbu        $a0, 0x5EC($s1)
    /* 44184 800AC984 EE052592 */  lbu        $a1, 0x5EE($s1)
    /* 44188 800AC988 340020A6 */  sh         $zero, 0x34($s1)
    /* 4418C 800AC98C 380020A6 */  sh         $zero, 0x38($s1)
    /* 44190 800AC990 0A93030C */  jal        func_800E4C28
    /* 44194 800AC994 1A1820A6 */   sh        $zero, 0x181A($s1)
  .L800AC998:
    /* 44198 800AC998 36003286 */  lh         $s2, 0x36($s1)
    /* 4419C 800AC99C 00000000 */  nop
    /* 441A0 800AC9A0 2A107202 */  slt        $v0, $s3, $s2
    /* 441A4 800AC9A4 0B004014 */  bnez       $v0, .L800AC9D4
    /* 441A8 800AC9A8 2120A002 */   addu      $a0, $s5, $zero
    /* 441AC 800AC9AC 23101300 */  negu       $v0, $s3
    /* 441B0 800AC9B0 2A104202 */  slt        $v0, $s2, $v0
    /* 441B4 800AC9B4 0F004014 */  bnez       $v0, .L800AC9F4
    /* 441B8 800AC9B8 0F80023C */   lui       $v0, %hi(D_800E92F0)
    /* 441BC 800AC9BC F0924224 */  addiu      $v0, $v0, %lo(D_800E92F0)
    /* 441C0 800AC9C0 21108202 */  addu       $v0, $s4, $v0
    /* 441C4 800AC9C4 00004590 */  lbu        $a1, 0x0($v0)
    /* 441C8 800AC9C8 21300000 */  addu       $a2, $zero, $zero
    /* 441CC 800AC9CC 7BB20208 */  j          .L800AC9EC
    /* 441D0 800AC9D0 10000724 */   addiu     $a3, $zero, 0x10
  .L800AC9D4:
    /* 441D4 800AC9D4 0F80023C */  lui        $v0, %hi(D_800E92F8)
    /* 441D8 800AC9D8 F8924224 */  addiu      $v0, $v0, %lo(D_800E92F8)
    /* 441DC 800AC9DC 21108202 */  addu       $v0, $s4, $v0
    /* 441E0 800AC9E0 00004590 */  lbu        $a1, 0x0($v0)
    /* 441E4 800AC9E4 21300000 */  addu       $a2, $zero, $zero
    /* 441E8 800AC9E8 08000724 */  addiu      $a3, $zero, 0x8
  .L800AC9EC:
    /* 441EC 800AC9EC 8180020C */  jal        func_800A0204
    /* 441F0 800AC9F0 00000000 */   nop
  .L800AC9F4:
    /* 441F4 800AC9F4 1A182386 */  lh         $v1, 0x181A($s1)
    /* 441F8 800AC9F8 01000224 */  addiu      $v0, $zero, 0x1
    /* 441FC 800AC9FC 11006210 */  beq        $v1, $v0, .L800ACA44
    /* 44200 800ACA00 02006228 */   slti      $v0, $v1, 0x2
    /* 44204 800ACA04 05004010 */  beqz       $v0, .L800ACA1C
    /* 44208 800ACA08 02000224 */   addiu     $v0, $zero, 0x2
    /* 4420C 800ACA0C 07006010 */  beqz       $v1, .L800ACA2C
    /* 44210 800ACA10 1C003026 */   addiu     $s0, $s1, 0x1C
    /* 44214 800ACA14 ECB20208 */  j          .L800ACBB0
    /* 44218 800ACA18 21200002 */   addu      $a0, $s0, $zero
  .L800ACA1C:
    /* 4421C 800ACA1C 2A006210 */  beq        $v1, $v0, .L800ACAC8
    /* 44220 800ACA20 1C003026 */   addiu     $s0, $s1, 0x1C
    /* 44224 800ACA24 ECB20208 */  j          .L800ACBB0
    /* 44228 800ACA28 21200002 */   addu      $a0, $s0, $zero
  .L800ACA2C:
    /* 4422C 800ACA2C 36002286 */  lh         $v0, 0x36($s1)
    /* 44230 800ACA30 00000000 */  nop
    /* 44234 800ACA34 FB004004 */  bltz       $v0, .L800ACE24
    /* 44238 800ACA38 21200002 */   addu      $a0, $s0, $zero
    /* 4423C 800ACA3C ECB20208 */  j          .L800ACBB0
    /* 44240 800ACA40 00000000 */   nop
  .L800ACA44:
    /* 44244 800ACA44 34002386 */  lh         $v1, 0x34($s1)
    /* 44248 800ACA48 00000000 */  nop
    /* 4424C 800ACA4C 0D006010 */  beqz       $v1, .L800ACA84
    /* 44250 800ACA50 00000000 */   nop
    /* 44254 800ACA54 1C002286 */  lh         $v0, 0x1C($s1)
    /* 44258 800ACA58 04006018 */  blez       $v1, .L800ACA6C
    /* 4425C 800ACA5C 21204300 */   addu      $a0, $v0, $v1
    /* 44260 800ACA60 14182286 */  lh         $v0, 0x1814($s1)
    /* 44264 800ACA64 9EB20208 */  j          .L800ACA78
    /* 44268 800ACA68 2A104400 */   slt       $v0, $v0, $a0
  .L800ACA6C:
    /* 4426C 800ACA6C 14182286 */  lh         $v0, 0x1814($s1)
    /* 44270 800ACA70 00000000 */  nop
    /* 44274 800ACA74 2A108200 */  slt        $v0, $a0, $v0
  .L800ACA78:
    /* 44278 800ACA78 02004010 */  beqz       $v0, .L800ACA84
    /* 4427C 800ACA7C 00000000 */   nop
    /* 44280 800ACA80 340020A6 */  sh         $zero, 0x34($s1)
  .L800ACA84:
    /* 44284 800ACA84 38002386 */  lh         $v1, 0x38($s1)
    /* 44288 800ACA88 00000000 */  nop
    /* 4428C 800ACA8C 47006010 */  beqz       $v1, .L800ACBAC
    /* 44290 800ACA90 1C003026 */   addiu     $s0, $s1, 0x1C
    /* 44294 800ACA94 20002286 */  lh         $v0, 0x20($s1)
    /* 44298 800ACA98 04006018 */  blez       $v1, .L800ACAAC
    /* 4429C 800ACA9C 21204300 */   addu      $a0, $v0, $v1
    /* 442A0 800ACAA0 18182286 */  lh         $v0, 0x1818($s1)
    /* 442A4 800ACAA4 AEB20208 */  j          .L800ACAB8
    /* 442A8 800ACAA8 2A104400 */   slt       $v0, $v0, $a0
  .L800ACAAC:
    /* 442AC 800ACAAC 18182286 */  lh         $v0, 0x1818($s1)
    /* 442B0 800ACAB0 00000000 */  nop
    /* 442B4 800ACAB4 2A108200 */  slt        $v0, $a0, $v0
  .L800ACAB8:
    /* 442B8 800ACAB8 3C004010 */  beqz       $v0, .L800ACBAC
    /* 442BC 800ACABC 1C003026 */   addiu     $s0, $s1, 0x1C
    /* 442C0 800ACAC0 EBB20208 */  j          .L800ACBAC
    /* 442C4 800ACAC4 380020A6 */   sh        $zero, 0x38($s1)
  .L800ACAC8:
    /* 442C8 800ACAC8 16182296 */  lhu        $v0, 0x1816($s1)
    /* 442CC 800ACACC 36002386 */  lh         $v1, 0x36($s1)
    /* 442D0 800ACAD0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 442D4 800ACAD4 D3006004 */  bltz       $v1, .L800ACE24
    /* 442D8 800ACAD8 161822A6 */   sh        $v0, 0x1816($s1)
    /* 442DC 800ACADC 02000724 */  addiu      $a3, $zero, 0x2
    /* 442E0 800ACAE0 1C002286 */  lh         $v0, 0x1C($s1)
    /* 442E4 800ACAE4 34002486 */  lh         $a0, 0x34($s1)
    /* 442E8 800ACAE8 1E002586 */  lh         $a1, 0x1E($s1)
    /* 442EC 800ACAEC 38002686 */  lh         $a2, 0x38($s1)
    /* 442F0 800ACAF0 21204400 */  addu       $a0, $v0, $a0
    /* 442F4 800ACAF4 20002286 */  lh         $v0, 0x20($s1)
    /* 442F8 800ACAF8 2128A300 */  addu       $a1, $a1, $v1
    /* 442FC 800ACAFC DEA4020C */  jal        func_800A9378
    /* 44300 800ACB00 21304600 */   addu      $a2, $v0, $a2
    /* 44304 800ACB04 0F80103C */  lui        $s0, %hi(D_800F49F4)
    /* 44308 800ACB08 F449038E */  lw         $v1, %lo(D_800F49F4)($s0)
    /* 4430C 800ACB0C 00000000 */  nop
    /* 44310 800ACB10 20006010 */  beqz       $v1, .L800ACB94
    /* 44314 800ACB14 21904000 */   addu      $s2, $v0, $zero
    /* 44318 800ACB18 ED052292 */  lbu        $v0, 0x5ED($s1)
    /* 4431C 800ACB1C 00000000 */  nop
    /* 44320 800ACB20 1C006210 */  beq        $v1, $v0, .L800ACB94
    /* 44324 800ACB24 00000000 */   nop
    /* 44328 800ACB28 F4490292 */  lbu        $v0, %lo(D_800F49F4)($s0)
    /* 4432C 800ACB2C 1C002486 */  lh         $a0, 0x1C($s1)
    /* 44330 800ACB30 00000000 */  nop
    /* 44334 800ACB34 02008104 */  bgez       $a0, .L800ACB40
    /* 44338 800ACB38 E40622A2 */   sb        $v0, 0x6E4($s1)
    /* 4433C 800ACB3C 7F008424 */  addiu      $a0, $a0, 0x7F
  .L800ACB40:
    /* 44340 800ACB40 20002386 */  lh         $v1, 0x20($s1)
    /* 44344 800ACB44 C3110400 */  sra        $v0, $a0, 7
    /* 44348 800ACB48 02006104 */  bgez       $v1, .L800ACB54
    /* 4434C 800ACB4C 5C0022A2 */   sb        $v0, 0x5C($s1)
    /* 44350 800ACB50 7F006324 */  addiu      $v1, $v1, 0x7F
  .L800ACB54:
    /* 44354 800ACB54 C3110300 */  sra        $v0, $v1, 7
    /* 44358 800ACB58 5E0022A2 */  sb         $v0, 0x5E($s1)
    /* 4435C 800ACB5C 5D0020A2 */  sb         $zero, 0x5D($s1)
    /* 44360 800ACB60 F449048E */  lw         $a0, %lo(D_800F49F4)($s0)
    /* 44364 800ACB64 2128A002 */  addu       $a1, $s5, $zero
    /* 44368 800ACB68 2731020C */  jal        func_8008C49C
    /* 4436C 800ACB6C FEFF8424 */   addiu     $a0, $a0, -0x2
    /* 44370 800ACB70 F449048E */  lw         $a0, %lo(D_800F49F4)($s0)
    /* 44374 800ACB74 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 44378 800ACB78 2731020C */  jal        func_8008C49C
    /* 4437C 800ACB7C FEFF8424 */   addiu     $a0, $a0, -0x2
    /* 44380 800ACB80 2120A002 */  addu       $a0, $s5, $zero
    /* 44384 800ACB84 D999030C */  jal        func_800E6764
    /* 44388 800ACB88 F44900AE */   sw        $zero, %lo(D_800F49F4)($s0)
    /* 4438C 800ACB8C 1CB30208 */  j          .L800ACC70
    /* 44390 800ACB90 0F80033C */   lui       $v1, %hi(D_800F49F8)
  .L800ACB94:
    /* 44394 800ACB94 16182286 */  lh         $v0, 0x1816($s1)
    /* 44398 800ACB98 00000000 */  nop
    /* 4439C 800ACB9C A200401C */  bgtz       $v0, .L800ACE28
    /* 443A0 800ACBA0 2120A002 */   addu      $a0, $s5, $zero
    /* 443A4 800ACBA4 91B20208 */  j          .L800ACA44
    /* 443A8 800ACBA8 00000000 */   nop
  .L800ACBAC:
    /* 443AC 800ACBAC 21200002 */  addu       $a0, $s0, $zero
  .L800ACBB0:
    /* 443B0 800ACBB0 34002586 */  lh         $a1, 0x34($s1)
    /* 443B4 800ACBB4 38002686 */  lh         $a2, 0x38($s1)
    /* 443B8 800ACBB8 BA9B020C */  jal        func_800A6EE8
    /* 443BC 800ACBBC 01000724 */   addiu     $a3, $zero, 0x1
    /* 443C0 800ACBC0 21904000 */  addu       $s2, $v0, $zero
    /* 443C4 800ACBC4 B80B0224 */  addiu      $v0, $zero, 0xBB8
    /* 443C8 800ACBC8 17004216 */  bne        $s2, $v0, .L800ACC28
    /* 443CC 800ACBCC 0F80023C */   lui       $v0, %hi(D_800F49F0)
    /* 443D0 800ACBD0 F049428C */  lw         $v0, %lo(D_800F49F0)($v0)
    /* 443D4 800ACBD4 00000000 */  nop
    /* 443D8 800ACBD8 0000438C */  lw         $v1, 0x0($v0)
    /* 443DC 800ACBDC 0F80023C */  lui        $v0, %hi(D_800E9278)
    /* 443E0 800ACBE0 78924224 */  addiu      $v0, $v0, %lo(D_800E9278)
    /* 443E4 800ACBE4 1F006330 */  andi       $v1, $v1, 0x1F
    /* 443E8 800ACBE8 21186200 */  addu       $v1, $v1, $v0
    /* 443EC 800ACBEC 00006390 */  lbu        $v1, 0x0($v1)
    /* 443F0 800ACBF0 14000224 */  addiu      $v0, $zero, 0x14
    /* 443F4 800ACBF4 0C006214 */  bne        $v1, $v0, .L800ACC28
    /* 443F8 800ACBF8 00000000 */   nop
    /* 443FC 800ACBFC 1E002386 */  lh         $v1, 0x1E($s1)
    /* 44400 800ACC00 00000000 */  nop
    /* 44404 800ACC04 0800601C */  bgtz       $v1, .L800ACC28
    /* 44408 800ACC08 00000000 */   nop
    /* 4440C 800ACC0C 36002286 */  lh         $v0, 0x36($s1)
    /* 44410 800ACC10 00000000 */  nop
    /* 44414 800ACC14 21106200 */  addu       $v0, $v1, $v0
    /* 44418 800ACC18 03004004 */  bltz       $v0, .L800ACC28
    /* 4441C 800ACC1C 00000000 */   nop
    /* 44420 800ACC20 14BD010C */  jal        func_8006F450
    /* 44424 800ACC24 21200002 */   addu      $a0, $s0, $zero
  .L800ACC28:
    /* 44428 800ACC28 1E002286 */  lh         $v0, 0x1E($s1)
    /* 4442C 800ACC2C 36002386 */  lh         $v1, 0x36($s1)
    /* 44430 800ACC30 00000000 */  nop
    /* 44434 800ACC34 21184300 */  addu       $v1, $v0, $v1
    /* 44438 800ACC38 2A107200 */  slt        $v0, $v1, $s2
    /* 4443C 800ACC3C 79004014 */  bnez       $v0, .L800ACE24
    /* 44440 800ACC40 0F80023C */   lui       $v0, %hi(D_800F49F4)
    /* 44444 800ACC44 F449428C */  lw         $v0, %lo(D_800F49F4)($v0)
    /* 44448 800ACC48 00000000 */  nop
    /* 4444C 800ACC4C 07004010 */  beqz       $v0, .L800ACC6C
    /* 44450 800ACC50 23104302 */   subu      $v0, $s2, $v1
    /* 44454 800ACC54 80FF4228 */  slti       $v0, $v0, -0x80
    /* 44458 800ACC58 05004010 */  beqz       $v0, .L800ACC70
    /* 4445C 800ACC5C 0F80033C */   lui       $v1, %hi(D_800F49F8)
    /* 44460 800ACC60 340020A6 */  sh         $zero, 0x34($s1)
    /* 44464 800ACC64 89B30208 */  j          .L800ACE24
    /* 44468 800ACC68 380020A6 */   sh        $zero, 0x38($s1)
  .L800ACC6C:
    /* 4446C 800ACC6C 0F80033C */  lui        $v1, %hi(D_800F49F8)
  .L800ACC70:
    /* 44470 800ACC70 F8496290 */  lbu        $v0, %lo(D_800F49F8)($v1)
    /* 44474 800ACC74 00000000 */  nop
    /* 44478 800ACC78 11004010 */  beqz       $v0, .L800ACCC0
    /* 4447C 800ACC7C FF0F0B3C */   lui       $t3, (0xFFFFFFF >> 16)
    /* 44480 800ACC80 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 44484 800ACC84 F8496390 */  lbu        $v1, %lo(D_800F49F8)($v1)
    /* 44488 800ACC88 E0454224 */  addiu      $v0, $v0, %lo(D_800F45E0)
    /* 4448C 800ACC8C 80180300 */  sll        $v1, $v1, 2
    /* 44490 800ACC90 21186200 */  addu       $v1, $v1, $v0
    /* 44494 800ACC94 0000638C */  lw         $v1, 0x0($v1)
    /* 44498 800ACC98 00000000 */  nop
    /* 4449C 800ACC9C 1A006284 */  lh         $v0, 0x1A($v1)
    /* 444A0 800ACCA0 00000000 */  nop
    /* 444A4 800ACCA4 07004010 */  beqz       $v0, .L800ACCC4
    /* 444A8 800ACCA8 FFFF6B35 */   ori       $t3, $t3, (0xFFFFFFF & 0xFFFF)
    /* 444AC 800ACCAC 1E006294 */  lhu        $v0, 0x1E($v1)
    /* 444B0 800ACCB0 00000000 */  nop
    /* 444B4 800ACCB4 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 444B8 800ACCB8 CBB30208 */  j          .L800ACF2C
    /* 444BC 800ACCBC 1E0022A6 */   sh        $v0, 0x1E($s1)
  .L800ACCC0:
    /* 444C0 800ACCC0 FFFF6B35 */  ori        $t3, $t3, (0xFFFFFFF & 0xFFFF)
  .L800ACCC4:
    /* 444C4 800ACCC4 F8FF0A3C */  lui        $t2, (0xFFF8FFFF >> 16)
    /* 444C8 800ACCC8 FFFF4A35 */  ori        $t2, $t2, (0xFFF8FFFF & 0xFFFF)
    /* 444CC 800ACCCC 2120A002 */  addu       $a0, $s5, $zero
    /* 444D0 800ACCD0 34002526 */  addiu      $a1, $s1, 0x34
    /* 444D4 800ACCD4 21300000 */  addu       $a2, $zero, $zero
    /* 444D8 800ACCD8 0F80023C */  lui        $v0, %hi(D_800F49F4)
    /* 444DC 800ACCDC 0C00238E */  lw         $v1, 0xC($s1)
    /* 444E0 800ACCE0 F0FF0724 */  addiu      $a3, $zero, -0x10
    /* 444E4 800ACCE4 EE0620A6 */  sh         $zero, 0x6EE($s1)
    /* 444E8 800ACCE8 F4494990 */  lbu        $t1, %lo(D_800F49F4)($v0)
    /* 444EC 800ACCEC AC05288E */  lw         $t0, 0x5AC($s1)
    /* 444F0 800ACCF0 24186700 */  and        $v1, $v1, $a3
    /* 444F4 800ACCF4 0F002231 */  andi       $v0, $t1, 0xF
    /* 444F8 800ACCF8 25186200 */  or         $v1, $v1, $v0
    /* 444FC 800ACCFC 24400B01 */  and        $t0, $t0, $t3
    /* 44500 800ACD00 0800278E */  lw         $a3, 0x8($s1)
    /* 44504 800ACD04 0400023C */  lui        $v0, (0x40000 >> 16)
    /* 44508 800ACD08 0C0023AE */  sw         $v1, 0xC($s1)
    /* 4450C 800ACD0C 0F80033C */  lui        $v1, %hi(D_800F49F8)
    /* 44510 800ACD10 5D0029A2 */  sb         $t1, 0x5D($s1)
    /* 44514 800ACD14 F8496390 */  lbu        $v1, %lo(D_800F49F8)($v1)
    /* 44518 800ACD18 2438EA00 */  and        $a3, $a3, $t2
    /* 4451C 800ACD1C 2538E200 */  or         $a3, $a3, $v0
    /* 44520 800ACD20 001F0300 */  sll        $v1, $v1, 28
    /* 44524 800ACD24 1E002296 */  lhu        $v0, 0x1E($s1)
    /* 44528 800ACD28 25400301 */  or         $t0, $t0, $v1
    /* 4452C 800ACD2C 080027AE */  sw         $a3, 0x8($s1)
    /* 44530 800ACD30 AC0528AE */  sw         $t0, 0x5AC($s1)
    /* 44534 800ACD34 23104202 */  subu       $v0, $s2, $v0
    /* 44538 800ACD38 A6A9020C */  jal        func_800AA698
    /* 4453C 800ACD3C 360022A6 */   sh        $v0, 0x36($s1)
    /* 44540 800ACD40 1E002386 */  lh         $v1, 0x1E($s1)
    /* 44544 800ACD44 4E002286 */  lh         $v0, 0x4E($s1)
    /* 44548 800ACD48 00000000 */  nop
    /* 4454C 800ACD4C 23806200 */  subu       $s0, $v1, $v0
    /* 44550 800ACD50 02000106 */  bgez       $s0, .L800ACD5C
    /* 44554 800ACD54 21100002 */   addu      $v0, $s0, $zero
    /* 44558 800ACD58 3F000226 */  addiu      $v0, $s0, 0x3F
  .L800ACD5C:
    /* 4455C 800ACD5C 83810200 */  sra        $s0, $v0, 6
    /* 44560 800ACD60 B80B422A */  slti       $v0, $s2, 0xBB8
    /* 44564 800ACD64 1F004010 */  beqz       $v0, .L800ACDE4
    /* 44568 800ACD68 110020A2 */   sb        $zero, 0x11($s1)
    /* 4456C 800ACD6C 0F002292 */  lbu        $v0, 0xF($s1)
    /* 44570 800ACD70 00000000 */  nop
    /* 44574 800ACD74 0B004014 */  bnez       $v0, .L800ACDA4
    /* 44578 800ACD78 0400022A */   slti      $v0, $s0, 0x4
    /* 4457C 800ACD7C 0800238E */  lw         $v1, 0x8($s1)
    /* 44580 800ACD80 00000000 */  nop
    /* 44584 800ACD84 000F6230 */  andi       $v0, $v1, 0xF00
    /* 44588 800ACD88 05004010 */  beqz       $v0, .L800ACDA0
    /* 4458C 800ACD8C 02120300 */   srl       $v0, $v1, 8
    /* 44590 800ACD90 0F004230 */  andi       $v0, $v0, 0xF
    /* 44594 800ACD94 0600422C */  sltiu      $v0, $v0, 0x6
    /* 44598 800ACD98 13004014 */  bnez       $v0, .L800ACDE8
    /* 4459C 800ACD9C FFFB033C */   lui       $v1, (0xFBFFFFFF >> 16)
  .L800ACDA0:
    /* 445A0 800ACDA0 0400022A */  slti       $v0, $s0, 0x4
  .L800ACDA4:
    /* 445A4 800ACDA4 0C004014 */  bnez       $v0, .L800ACDD8
    /* 445A8 800ACDA8 2120A002 */   addu      $a0, $s5, $zero
    /* 445AC 800ACDAC 21282002 */  addu       $a1, $s1, $zero
    /* 445B0 800ACDB0 0ABA020C */  jal        func_800AE828
    /* 445B4 800ACDB4 42000624 */   addiu     $a2, $zero, 0x42
    /* 445B8 800ACDB8 0600022A */  slti       $v0, $s0, 0x6
    /* 445BC 800ACDBC 0A004014 */  bnez       $v0, .L800ACDE8
    /* 445C0 800ACDC0 FFFB033C */   lui       $v1, (0xFBFFFFFF >> 16)
    /* 445C4 800ACDC4 0900A016 */  bnez       $s5, .L800ACDEC
    /* 445C8 800ACDC8 FFFF6334 */   ori       $v1, $v1, (0xFBFFFFFF & 0xFFFF)
    /* 445CC 800ACDCC 08000224 */  addiu      $v0, $zero, 0x8
    /* 445D0 800ACDD0 79B30208 */  j          .L800ACDE4
    /* 445D4 800ACDD4 110022A2 */   sb        $v0, 0x11($s1)
  .L800ACDD8:
    /* 445D8 800ACDD8 21282002 */  addu       $a1, $s1, $zero
    /* 445DC 800ACDDC 0ABA020C */  jal        func_800AE828
    /* 445E0 800ACDE0 41000624 */   addiu     $a2, $zero, 0x41
  .L800ACDE4:
    /* 445E4 800ACDE4 FFFB033C */  lui        $v1, (0xFBFFFFFF >> 16)
  .L800ACDE8:
    /* 445E8 800ACDE8 FFFF6334 */  ori        $v1, $v1, (0xFBFFFFFF & 0xFFFF)
  .L800ACDEC:
    /* 445EC 800ACDEC 2120A002 */  addu       $a0, $s5, $zero
    /* 445F0 800ACDF0 AC05228E */  lw         $v0, 0x5AC($s1)
    /* 445F4 800ACDF4 21300000 */  addu       $a2, $zero, $zero
    /* 445F8 800ACDF8 1A1820A6 */  sh         $zero, 0x181A($s1)
    /* 445FC 800ACDFC 24104300 */  and        $v0, $v0, $v1
    /* 44600 800ACE00 AC0522AE */  sw         $v0, 0x5AC($s1)
    /* 44604 800ACE04 0F80023C */  lui        $v0, %hi(D_800E9300)
    /* 44608 800ACE08 00934224 */  addiu      $v0, $v0, %lo(D_800E9300)
    /* 4460C 800ACE0C 21108202 */  addu       $v0, $s4, $v0
    /* 44610 800ACE10 00004590 */  lbu        $a1, 0x0($v0)
    /* 44614 800ACE14 8180020C */  jal        func_800A0204
    /* 44618 800ACE18 08000724 */   addiu     $a3, $zero, 0x8
    /* 4461C 800ACE1C CBB30208 */  j          .L800ACF2C
    /* 44620 800ACE20 00000000 */   nop
  .L800ACE24:
    /* 44624 800ACE24 2120A002 */  addu       $a0, $s5, $zero
  .L800ACE28:
    /* 44628 800ACE28 34002526 */  addiu      $a1, $s1, 0x34
    /* 4462C 800ACE2C A6A9020C */  jal        func_800AA698
    /* 44630 800ACE30 21300000 */   addu      $a2, $zero, $zero
    /* 44634 800ACE34 CBB30208 */  j          .L800ACF2C
    /* 44638 800ACE38 00000000 */   nop
  .L800ACE3C:
    /* 4463C 800ACE3C 24108200 */  and        $v0, $a0, $v0
    /* 44640 800ACE40 07004010 */  beqz       $v0, .L800ACE60
    /* 44644 800ACE44 DFFF023C */   lui       $v0, (0xFFDFFFFF >> 16)
    /* 44648 800ACE48 FFFF4234 */  ori        $v0, $v0, (0xFFDFFFFF & 0xFFFF)
    /* 4464C 800ACE4C BFFF033C */  lui        $v1, (0xFFBFFFFF >> 16)
    /* 44650 800ACE50 FFFF6334 */  ori        $v1, $v1, (0xFFBFFFFF & 0xFFFF)
    /* 44654 800ACE54 24108200 */  and        $v0, $a0, $v0
    /* 44658 800ACE58 24104300 */  and        $v0, $v0, $v1
    /* 4465C 800ACE5C 080022AE */  sw         $v0, 0x8($s1)
  .L800ACE60:
    /* 44660 800ACE60 D5B3020C */  jal        func_800ACF54
    /* 44664 800ACE64 21202002 */   addu      $a0, $s1, $zero
    /* 44668 800ACE68 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* 4466C 800ACE6C 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 44670 800ACE70 00000000 */  nop
    /* 44674 800ACE74 C21F0200 */  srl        $v1, $v0, 31
    /* 44678 800ACE78 21104300 */  addu       $v0, $v0, $v1
    /* 4467C 800ACE7C 11002392 */  lbu        $v1, 0x11($s1)
    /* 44680 800ACE80 43100200 */  sra        $v0, $v0, 1
    /* 44684 800ACE84 23186200 */  subu       $v1, $v1, $v0
    /* 44688 800ACE88 110023A2 */  sb         $v1, 0x11($s1)
    /* 4468C 800ACE8C 001E0300 */  sll        $v1, $v1, 24
    /* 44690 800ACE90 02006104 */  bgez       $v1, .L800ACE9C
    /* 44694 800ACE94 00000000 */   nop
    /* 44698 800ACE98 110020A2 */  sb         $zero, 0x11($s1)
  .L800ACE9C:
    /* 4469C 800ACE9C 11002282 */  lb         $v0, 0x11($s1)
    /* 446A0 800ACEA0 00000000 */  nop
    /* 446A4 800ACEA4 21004014 */  bnez       $v0, .L800ACF2C
    /* 446A8 800ACEA8 00000000 */   nop
    /* 446AC 800ACEAC 0F002292 */  lbu        $v0, 0xF($s1)
    /* 446B0 800ACEB0 00000000 */  nop
    /* 446B4 800ACEB4 17004010 */  beqz       $v0, .L800ACF14
    /* 446B8 800ACEB8 EC0620A6 */   sh        $zero, 0x6EC($s1)
    /* 446BC 800ACEBC 0800228E */  lw         $v0, 0x8($s1)
    /* 446C0 800ACEC0 4000033C */  lui        $v1, (0x400000 >> 16)
    /* 446C4 800ACEC4 24104300 */  and        $v0, $v0, $v1
    /* 446C8 800ACEC8 05004014 */  bnez       $v0, .L800ACEE0
    /* 446CC 800ACECC 00000000 */   nop
    /* 446D0 800ACED0 CC052292 */  lbu        $v0, 0x5CC($s1)
    /* 446D4 800ACED4 00000000 */  nop
    /* 446D8 800ACED8 14004014 */  bnez       $v0, .L800ACF2C
    /* 446DC 800ACEDC 00000000 */   nop
  .L800ACEE0:
    /* 446E0 800ACEE0 05009012 */  beq        $s4, $s0, .L800ACEF8
    /* 446E4 800ACEE4 2120A002 */   addu      $a0, $s5, $zero
    /* 446E8 800ACEE8 01000524 */  addiu      $a1, $zero, 0x1
    /* 446EC 800ACEEC 21300000 */  addu       $a2, $zero, $zero
    /* 446F0 800ACEF0 8180020C */  jal        func_800A0204
    /* 446F4 800ACEF4 08000724 */   addiu     $a3, $zero, 0x8
  .L800ACEF8:
    /* 446F8 800ACEF8 5C002492 */  lbu        $a0, 0x5C($s1)
    /* 446FC 800ACEFC 5E002592 */  lbu        $a1, 0x5E($s1)
    /* 44700 800ACF00 0A93030C */  jal        func_800E4C28
    /* 44704 800ACF04 00000000 */   nop
    /* 44708 800ACF08 0F002492 */  lbu        $a0, 0xF($s1)
    /* 4470C 800ACF0C AC9B030C */  jal        func_800E6EB0
    /* 44710 800ACF10 00000000 */   nop
  .L800ACF14:
    /* 44714 800ACF14 F8FF033C */  lui        $v1, (0xFFF8FFFF >> 16)
    /* 44718 800ACF18 0800228E */  lw         $v0, 0x8($s1)
    /* 4471C 800ACF1C FFFF6334 */  ori        $v1, $v1, (0xFFF8FFFF & 0xFFFF)
    /* 44720 800ACF20 461820A2 */  sb         $zero, 0x1846($s1)
    /* 44724 800ACF24 24104300 */  and        $v0, $v0, $v1
    /* 44728 800ACF28 080022AE */  sw         $v0, 0x8($s1)
  .L800ACF2C:
    /* 4472C 800ACF2C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 44730 800ACF30 2400B58F */  lw         $s5, 0x24($sp)
    /* 44734 800ACF34 2000B48F */  lw         $s4, 0x20($sp)
    /* 44738 800ACF38 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4473C 800ACF3C 1800B28F */  lw         $s2, 0x18($sp)
    /* 44740 800ACF40 1400B18F */  lw         $s1, 0x14($sp)
    /* 44744 800ACF44 1000B08F */  lw         $s0, 0x10($sp)
    /* 44748 800ACF48 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 4474C 800ACF4C 0800E003 */  jr         $ra
    /* 44750 800ACF50 00000000 */   nop
endlabel func_800AC690
