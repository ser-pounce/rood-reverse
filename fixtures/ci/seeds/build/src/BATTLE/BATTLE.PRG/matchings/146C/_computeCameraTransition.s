nonmatching _computeCameraTransition, 0x2A8

glabel _computeCameraTransition
    /* 675C 8006EF5C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6760 8006EF60 2000B0AF */  sw         $s0, 0x20($sp)
    /* 6764 8006EF64 21808000 */  addu       $s0, $a0, $zero
    /* 6768 8006EF68 801F023C */  lui        $v0, %hi(D_1F800000)
    /* 676C 8006EF6C 2800B2AF */  sw         $s2, 0x28($sp)
    /* 6770 8006EF70 00005224 */  addiu      $s2, $v0, %lo(D_1F800000)
    /* 6774 8006EF74 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 6778 8006EF78 2400B1AF */  sw         $s1, 0x24($sp)
    /* 677C 8006EF7C 0000038E */  lw         $v1, 0x0($s0)
    /* 6780 8006EF80 3400428E */  lw         $v0, 0x34($s2)
    /* 6784 8006EF84 00000000 */  nop
    /* 6788 8006EF88 23106200 */  subu       $v0, $v1, $v0
    /* 678C 8006EF8C 02004104 */  bgez       $v0, .L8006EF98
    /* 6790 8006EF90 00000000 */   nop
    /* 6794 8006EF94 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006EF98:
    /* 6798 8006EF98 03130200 */  sra        $v0, $v0, 12
    /* 679C 8006EF9C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 67A0 8006EFA0 0800038E */  lw         $v1, 0x8($s0)
    /* 67A4 8006EFA4 3C00428E */  lw         $v0, 0x3C($s2)
    /* 67A8 8006EFA8 00000000 */  nop
    /* 67AC 8006EFAC 23106200 */  subu       $v0, $v1, $v0
    /* 67B0 8006EFB0 02004104 */  bgez       $v0, .L8006EFBC
    /* 67B4 8006EFB4 00000000 */   nop
    /* 67B8 8006EFB8 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006EFBC:
    /* 67BC 8006EFBC 03130200 */  sra        $v0, $v0, 12
    /* 67C0 8006EFC0 1800A2AF */  sw         $v0, 0x18($sp)
    /* 67C4 8006EFC4 0400038E */  lw         $v1, 0x4($s0)
    /* 67C8 8006EFC8 3800428E */  lw         $v0, 0x38($s2)
    /* 67CC 8006EFCC 00000000 */  nop
    /* 67D0 8006EFD0 23106200 */  subu       $v0, $v1, $v0
    /* 67D4 8006EFD4 02004104 */  bgez       $v0, .L8006EFE0
    /* 67D8 8006EFD8 1000A427 */   addiu     $a0, $sp, 0x10
    /* 67DC 8006EFDC FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006EFE0:
    /* 67E0 8006EFE0 0F80113C */  lui        $s1, %hi(vs_battle_cameraTransition)
    /* 67E4 8006EFE4 0419258E */  lw         $a1, %lo(vs_battle_cameraTransition)($s1)
    /* 67E8 8006EFE8 03130200 */  sra        $v0, $v0, 12
    /* 67EC 8006EFEC 1400A2AF */  sw         $v0, 0x14($sp)
    /* 67F0 8006EFF0 A506010C */  jal        VectorNormal
    /* 67F4 8006EFF4 C400A524 */   addiu     $a1, $a1, 0xC4
    /* 67F8 8006EFF8 0419258E */  lw         $a1, %lo(vs_battle_cameraTransition)($s1)
    /* 67FC 8006EFFC 80000224 */  addiu      $v0, $zero, 0x80
    /* 6800 8006F000 F000A2AC */  sw         $v0, 0xF0($a1)
    /* 6804 8006F004 0000028E */  lw         $v0, 0x0($s0)
    /* 6808 8006F008 00000000 */  nop
    /* 680C 8006F00C A400A2AC */  sw         $v0, 0xA4($a1)
    /* 6810 8006F010 0400028E */  lw         $v0, 0x4($s0)
    /* 6814 8006F014 00000000 */  nop
    /* 6818 8006F018 A800A2AC */  sw         $v0, 0xA8($a1)
    /* 681C 8006F01C 0800028E */  lw         $v0, 0x8($s0)
    /* 6820 8006F020 00000000 */  nop
    /* 6824 8006F024 AC00A2AC */  sw         $v0, 0xAC($a1)
    /* 6828 8006F028 0400028E */  lw         $v0, 0x4($s0)
    /* 682C 8006F02C 3800438E */  lw         $v1, 0x38($s2)
    /* 6830 8006F030 00000000 */  nop
    /* 6834 8006F034 23104300 */  subu       $v0, $v0, $v1
    /* 6838 8006F038 1400A2AF */  sw         $v0, 0x14($sp)
    /* 683C 8006F03C C800A48C */  lw         $a0, 0xC8($a1)
    /* 6840 8006F040 F000A38C */  lw         $v1, 0xF0($a1)
    /* 6844 8006F044 00000000 */  nop
    /* 6848 8006F048 18008300 */  mult       $a0, $v1
    /* 684C 8006F04C 12180000 */  mflo       $v1
    /* 6850 8006F050 00000000 */  nop
    /* 6854 8006F054 00000000 */  nop
    /* 6858 8006F058 1A004300 */  div        $zero, $v0, $v1
    /* 685C 8006F05C 12100000 */  mflo       $v0
    /* 6860 8006F060 6C00A48C */  lw         $a0, 0x6C($a1)
    /* 6864 8006F064 CA03010C */  jal        rsin
    /* 6868 8006F068 F400A2AC */   sw        $v0, 0xF4($a1)
    /* 686C 8006F06C 0419238E */  lw         $v1, %lo(vs_battle_cameraTransition)($s1)
    /* 6870 8006F070 00000000 */  nop
    /* 6874 8006F074 6C00648C */  lw         $a0, 0x6C($v1)
    /* 6878 8006F078 23100200 */  negu       $v0, $v0
    /* 687C 8006F07C C903010C */  jal        rcos
    /* 6880 8006F080 B40062AC */   sw        $v0, 0xB4($v1)
    /* 6884 8006F084 0419238E */  lw         $v1, %lo(vs_battle_cameraTransition)($s1)
    /* 6888 8006F088 00000000 */  nop
    /* 688C 8006F08C 7000648C */  lw         $a0, 0x70($v1)
    /* 6890 8006F090 23100200 */  negu       $v0, $v0
    /* 6894 8006F094 CA03010C */  jal        rsin
    /* 6898 8006F098 BC0062AC */   sw        $v0, 0xBC($v1)
    /* 689C 8006F09C 0419238E */  lw         $v1, %lo(vs_battle_cameraTransition)($s1)
    /* 68A0 8006F0A0 00000000 */  nop
    /* 68A4 8006F0A4 7000648C */  lw         $a0, 0x70($v1)
    /* 68A8 8006F0A8 C903010C */  jal        rcos
    /* 68AC 8006F0AC 21804000 */   addu      $s0, $v0, $zero
    /* 68B0 8006F0B0 23801000 */  negu       $s0, $s0
    /* 68B4 8006F0B4 00831000 */  sll        $s0, $s0, 12
    /* 68B8 8006F0B8 1A000202 */  div        $zero, $s0, $v0
    /* 68BC 8006F0BC 12800000 */  mflo       $s0
    /* 68C0 8006F0C0 0419228E */  lw         $v0, %lo(vs_battle_cameraTransition)($s1)
    /* 68C4 8006F0C4 00000000 */  nop
    /* 68C8 8006F0C8 B4004424 */  addiu      $a0, $v0, 0xB4
    /* 68CC 8006F0CC 21288000 */  addu       $a1, $a0, $zero
    /* 68D0 8006F0D0 A506010C */  jal        VectorNormal
    /* 68D4 8006F0D4 B80050AC */   sw        $s0, 0xB8($v0)
    /* 68D8 8006F0D8 0419238E */  lw         $v1, %lo(vs_battle_cameraTransition)($s1)
    /* 68DC 8006F0DC 00000000 */  nop
    /* 68E0 8006F0E0 B400648C */  lw         $a0, 0xB4($v1)
    /* 68E4 8006F0E4 BC00658C */  lw         $a1, 0xBC($v1)
    /* 68E8 8006F0E8 C0100400 */  sll        $v0, $a0, 3
    /* 68EC 8006F0EC 21104400 */  addu       $v0, $v0, $a0
    /* 68F0 8006F0F0 A400648C */  lw         $a0, 0xA4($v1)
    /* 68F4 8006F0F4 00120200 */  sll        $v0, $v0, 8
    /* 68F8 8006F0F8 21104400 */  addu       $v0, $v0, $a0
    /* 68FC 8006F0FC B40062AC */  sw         $v0, 0xB4($v1)
    /* 6900 8006F100 C0100500 */  sll        $v0, $a1, 3
    /* 6904 8006F104 21104500 */  addu       $v0, $v0, $a1
    /* 6908 8006F108 00120200 */  sll        $v0, $v0, 8
    /* 690C 8006F10C AC00648C */  lw         $a0, 0xAC($v1)
    /* 6910 8006F110 B800658C */  lw         $a1, 0xB8($v1)
    /* 6914 8006F114 21104400 */  addu       $v0, $v0, $a0
    /* 6918 8006F118 BC0062AC */  sw         $v0, 0xBC($v1)
    /* 691C 8006F11C C0100500 */  sll        $v0, $a1, 3
    /* 6920 8006F120 21104500 */  addu       $v0, $v0, $a1
    /* 6924 8006F124 A800648C */  lw         $a0, 0xA8($v1)
    /* 6928 8006F128 00120200 */  sll        $v0, $v0, 8
    /* 692C 8006F12C 21104400 */  addu       $v0, $v0, $a0
    /* 6930 8006F130 B80062AC */  sw         $v0, 0xB8($v1)
    /* 6934 8006F134 B400628C */  lw         $v0, 0xB4($v1)
    /* 6938 8006F138 4400458E */  lw         $a1, 0x44($s2)
    /* 693C 8006F13C F400648C */  lw         $a0, 0xF4($v1)
    /* 6940 8006F140 23104500 */  subu       $v0, $v0, $a1
    /* 6944 8006F144 1A004400 */  div        $zero, $v0, $a0
    /* 6948 8006F148 12100000 */  mflo       $v0
    /* 694C 8006F14C 00000000 */  nop
    /* 6950 8006F150 D40062AC */  sw         $v0, 0xD4($v1)
    /* 6954 8006F154 BC00628C */  lw         $v0, 0xBC($v1)
    /* 6958 8006F158 4C00458E */  lw         $a1, 0x4C($s2)
    /* 695C 8006F15C F400648C */  lw         $a0, 0xF4($v1)
    /* 6960 8006F160 23104500 */  subu       $v0, $v0, $a1
    /* 6964 8006F164 1A004400 */  div        $zero, $v0, $a0
    /* 6968 8006F168 12100000 */  mflo       $v0
    /* 696C 8006F16C 00000000 */  nop
    /* 6970 8006F170 DC0062AC */  sw         $v0, 0xDC($v1)
    /* 6974 8006F174 B800628C */  lw         $v0, 0xB8($v1)
    /* 6978 8006F178 4800458E */  lw         $a1, 0x48($s2)
    /* 697C 8006F17C F400648C */  lw         $a0, 0xF4($v1)
    /* 6980 8006F180 23104500 */  subu       $v0, $v0, $a1
    /* 6984 8006F184 1A004400 */  div        $zero, $v0, $a0
    /* 6988 8006F188 12100000 */  mflo       $v0
    /* 698C 8006F18C A000678C */  lw         $a3, 0xA0($v1)
    /* 6990 8006F190 D80062AC */  sw         $v0, 0xD8($v1)
    /* 6994 8006F194 6400448E */  lw         $a0, 0x64($s2)
    /* 6998 8006F198 F400628C */  lw         $v0, 0xF4($v1)
    /* 699C 8006F19C 2338E400 */  subu       $a3, $a3, $a0
    /* 69A0 8006F1A0 1A00E200 */  div        $zero, $a3, $v0
    /* 69A4 8006F1A4 12380000 */  mflo       $a3
    /* 69A8 8006F1A8 9800658C */  lw         $a1, 0x98($v1)
    /* 69AC 8006F1AC 0680023C */  lui        $v0, %hi(vs_main_nearClip)
    /* 69B0 8006F1B0 C8E0448C */  lw         $a0, %lo(vs_main_nearClip)($v0)
    /* 69B4 8006F1B4 F400628C */  lw         $v0, 0xF4($v1)
    /* 69B8 8006F1B8 2328A400 */  subu       $a1, $a1, $a0
    /* 69BC 8006F1BC 1A00A200 */  div        $zero, $a1, $v0
    /* 69C0 8006F1C0 12280000 */  mflo       $a1
    /* 69C4 8006F1C4 0680043C */  lui        $a0, %hi(vs_main_projectionDistance)
    /* 69C8 8006F1C8 9C00628C */  lw         $v0, 0x9C($v1)
    /* 69CC 8006F1CC 48E2868C */  lw         $a2, %lo(vs_main_projectionDistance)($a0)
    /* 69D0 8006F1D0 F400648C */  lw         $a0, 0xF4($v1)
    /* 69D4 8006F1D4 23104600 */  subu       $v0, $v0, $a2
    /* 69D8 8006F1D8 1A004400 */  div        $zero, $v0, $a0
    /* 69DC 8006F1DC 12100000 */  mflo       $v0
    /* 69E0 8006F1E0 E40067AC */  sw         $a3, 0xE4($v1)
    /* 69E4 8006F1E4 E80065AC */  sw         $a1, 0xE8($v1)
    /* 69E8 8006F1E8 EC0062AC */  sw         $v0, 0xEC($v1)
    /* 69EC 8006F1EC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 69F0 8006F1F0 2800B28F */  lw         $s2, 0x28($sp)
    /* 69F4 8006F1F4 2400B18F */  lw         $s1, 0x24($sp)
    /* 69F8 8006F1F8 2000B08F */  lw         $s0, 0x20($sp)
    /* 69FC 8006F1FC 0800E003 */  jr         $ra
    /* 6A00 8006F200 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _computeCameraTransition
