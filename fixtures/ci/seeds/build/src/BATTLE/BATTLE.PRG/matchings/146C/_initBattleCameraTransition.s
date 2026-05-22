nonmatching _initBattleCameraTransition, 0x1F0

glabel _initBattleCameraTransition
    /* A8BC 800730BC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* A8C0 800730C0 3000B0AF */  sw         $s0, 0x30($sp)
    /* A8C4 800730C4 0F80103C */  lui        $s0, %hi(vs_battle_cameraTransition)
    /* A8C8 800730C8 0419028E */  lw         $v0, %lo(vs_battle_cameraTransition)($s0)
    /* A8CC 800730CC 00000000 */  nop
    /* A8D0 800730D0 04004014 */  bnez       $v0, .L800730E4
    /* A8D4 800730D4 3400BFAF */   sw        $ra, 0x34($sp)
    /* A8D8 800730D8 8F0F010C */  jal        vs_main_allocHeapR
    /* A8DC 800730DC F8000424 */   addiu     $a0, $zero, 0xF8
    /* A8E0 800730E0 041902AE */  sw         $v0, %lo(vs_battle_cameraTransition)($s0)
  .L800730E4:
    /* A8E4 800730E4 0F80023C */  lui        $v0, %hi(D_800F196C)
    /* A8E8 800730E8 6C19438C */  lw         $v1, %lo(D_800F196C)($v0)
    /* A8EC 800730EC 07000224 */  addiu      $v0, $zero, 0x7
    /* A8F0 800730F0 36006210 */  beq        $v1, $v0, .L800731CC
    /* A8F4 800730F4 801F023C */   lui       $v0, %hi(D_1F800000)
    /* A8F8 800730F8 0419048E */  lw         $a0, %lo(vs_battle_cameraTransition)($s0)
    /* A8FC 800730FC 00004224 */  addiu      $v0, $v0, %lo(D_1F800000)
    /* A900 80073100 34004324 */  addiu      $v1, $v0, 0x34
    /* A904 80073104 64004224 */  addiu      $v0, $v0, 0x64
  .L80073108:
    /* A908 80073108 0000688C */  lw         $t0, 0x0($v1)
    /* A90C 8007310C 0400698C */  lw         $t1, 0x4($v1)
    /* A910 80073110 08006A8C */  lw         $t2, 0x8($v1)
    /* A914 80073114 0C006B8C */  lw         $t3, 0xC($v1)
    /* A918 80073118 000088AC */  sw         $t0, 0x0($a0)
    /* A91C 8007311C 040089AC */  sw         $t1, 0x4($a0)
    /* A920 80073120 08008AAC */  sw         $t2, 0x8($a0)
    /* A924 80073124 0C008BAC */  sw         $t3, 0xC($a0)
    /* A928 80073128 10006324 */  addiu      $v1, $v1, 0x10
    /* A92C 8007312C F6FF6214 */  bne        $v1, $v0, .L80073108
    /* A930 80073130 10008424 */   addiu     $a0, $a0, 0x10
    /* A934 80073134 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* A938 80073138 D0194724 */  addiu      $a3, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* A93C 8007313C 0F80023C */  lui        $v0, %hi(vs_battle_cameraTransition)
    /* A940 80073140 0419428C */  lw         $v0, %lo(vs_battle_cameraTransition)($v0)
    /* A944 80073144 2000E524 */  addiu      $a1, $a3, 0x20
    /* A948 80073148 0000688C */  lw         $t0, 0x0($v1)
    /* A94C 8007314C 00000000 */  nop
    /* A950 80073150 000088AC */  sw         $t0, 0x0($a0)
    /* A954 80073154 34004624 */  addiu      $a2, $v0, 0x34
  .L80073158:
    /* A958 80073158 0000E88C */  lw         $t0, 0x0($a3)
    /* A95C 8007315C 0400E98C */  lw         $t1, 0x4($a3)
    /* A960 80073160 0800EA8C */  lw         $t2, 0x8($a3)
    /* A964 80073164 0C00EB8C */  lw         $t3, 0xC($a3)
    /* A968 80073168 0000C8AC */  sw         $t0, 0x0($a2)
    /* A96C 8007316C 0400C9AC */  sw         $t1, 0x4($a2)
    /* A970 80073170 0800CAAC */  sw         $t2, 0x8($a2)
    /* A974 80073174 0C00CBAC */  sw         $t3, 0xC($a2)
    /* A978 80073178 1000E724 */  addiu      $a3, $a3, 0x10
    /* A97C 8007317C F6FFE514 */  bne        $a3, $a1, .L80073158
    /* A980 80073180 1000C624 */   addiu     $a2, $a2, 0x10
    /* A984 80073184 0F80023C */  lui        $v0, %hi(vs_battle_cameraTransition)
    /* A988 80073188 0680043C */  lui        $a0, %hi(vs_main_nearClip)
    /* A98C 8007318C 0680053C */  lui        $a1, %hi(vs_main_projectionDistance)
    /* A990 80073190 0419438C */  lw         $v1, %lo(vs_battle_cameraTransition)($v0)
    /* A994 80073194 C8E0828C */  lw         $v0, %lo(vs_main_nearClip)($a0)
    /* A998 80073198 48E2A48C */  lw         $a0, %lo(vs_main_projectionDistance)($a1)
    /* A99C 8007319C 0000E88C */  lw         $t0, 0x0($a3)
    /* A9A0 800731A0 0400E98C */  lw         $t1, 0x4($a3)
    /* A9A4 800731A4 0800EA8C */  lw         $t2, 0x8($a3)
    /* A9A8 800731A8 0000C8AC */  sw         $t0, 0x0($a2)
    /* A9AC 800731AC 0400C9AC */  sw         $t1, 0x4($a2)
    /* A9B0 800731B0 0800CAAC */  sw         $t2, 0x8($a2)
    /* A9B4 800731B4 600062AC */  sw         $v0, 0x60($v1)
    /* A9B8 800731B8 801F023C */  lui        $v0, (0x1F800064 >> 16)
    /* A9BC 800731BC 640064AC */  sw         $a0, 0x64($v1)
    /* A9C0 800731C0 6400428C */  lw         $v0, (0x1F800064 & 0xFFFF)($v0)
    /* A9C4 800731C4 00000000 */  nop
    /* A9C8 800731C8 680062AC */  sw         $v0, 0x68($v1)
  .L800731CC:
    /* A9CC 800731CC 21200000 */  addu       $a0, $zero, $zero
    /* A9D0 800731D0 0F80103C */  lui        $s0, %hi(vs_battle_cameraTransition)
    /* A9D4 800731D4 04000224 */  addiu      $v0, $zero, 0x4
    /* A9D8 800731D8 0419038E */  lw         $v1, %lo(vs_battle_cameraTransition)($s0)
    /* A9DC 800731DC 2000A527 */  addiu      $a1, $sp, 0x20
    /* A9E0 800731E0 980062AC */  sw         $v0, 0x98($v1)
    /* A9E4 800731E4 E0000224 */  addiu      $v0, $zero, 0xE0
    /* A9E8 800731E8 9C0062AC */  sw         $v0, 0x9C($v1)
    /* A9EC 800731EC 00200224 */  addiu      $v0, $zero, 0x2000
    /* A9F0 800731F0 4284020C */  jal        func_800A1108
    /* A9F4 800731F4 A00062AC */   sw        $v0, 0xA0($v1)
    /* A9F8 800731F8 0419038E */  lw         $v1, %lo(vs_battle_cameraTransition)($s0)
    /* A9FC 800731FC 2A00A287 */  lh         $v0, 0x2A($sp)
    /* AA00 80073200 21800000 */  addu       $s0, $zero, $zero
    /* AA04 80073204 6C0062AC */  sw         $v0, 0x6C($v1)
    /* AA08 80073208 0F80023C */  lui        $v0, %hi(D_800F19D8)
    /* AA0C 8007320C 700060AC */  sw         $zero, 0x70($v1)
    /* AA10 80073210 D819428C */  lw         $v0, %lo(D_800F19D8)($v0)
    /* AA14 80073214 1000A427 */  addiu      $a0, $sp, 0x10
    /* AA18 80073218 740062AC */  sw         $v0, 0x74($v1)
    /* AA1C 8007321C 2400A287 */  lh         $v0, 0x24($sp)
    /* AA20 80073220 2600A387 */  lh         $v1, 0x26($sp)
    /* AA24 80073224 00130200 */  sll        $v0, $v0, 12
    /* AA28 80073228 4CFF6324 */  addiu      $v1, $v1, -0xB4
    /* AA2C 8007322C 1000A2AF */  sw         $v0, 0x10($sp)
    /* AA30 80073230 2800A287 */  lh         $v0, 0x28($sp)
    /* AA34 80073234 001B0300 */  sll        $v1, $v1, 12
    /* AA38 80073238 1400A3AF */  sw         $v1, 0x14($sp)
    /* AA3C 8007323C 00130200 */  sll        $v0, $v0, 12
    /* AA40 80073240 D7BB010C */  jal        _computeCameraTransition
    /* AA44 80073244 1800A2AF */   sw        $v0, 0x18($sp)
    /* AA48 80073248 01000424 */  addiu      $a0, $zero, 0x1
    /* AA4C 8007324C 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* AA50 80073250 07000224 */  addiu      $v0, $zero, 0x7
    /* AA54 80073254 6C1962AC */  sw         $v0, %lo(D_800F196C)($v1)
    /* AA58 80073258 0F80023C */  lui        $v0, %hi(_cameraMode)
    /* AA5C 8007325C 952D030C */  jal        func_800CB654
    /* AA60 80073260 F01840AC */   sw        $zero, %lo(_cameraMode)($v0)
  .L80073264:
    /* AA64 80073264 7179020C */  jal        func_8009E5C4
    /* AA68 80073268 21200002 */   addu      $a0, $s0, $zero
    /* AA6C 8007326C 01001026 */  addiu      $s0, $s0, 0x1
    /* AA70 80073270 1000022A */  slti       $v0, $s0, 0x10
    /* AA74 80073274 FBFF4014 */  bnez       $v0, .L80073264
    /* AA78 80073278 00000000 */   nop
    /* AA7C 8007327C 322D020C */  jal        func_8008B4C8
    /* AA80 80073280 21200000 */   addu      $a0, $zero, $zero
    /* AA84 80073284 6535020C */  jal        func_8008D594
    /* AA88 80073288 01000424 */   addiu     $a0, $zero, 0x1
    /* AA8C 8007328C DC56020C */  jal        func_80095B70
    /* AA90 80073290 01000424 */   addiu     $a0, $zero, 0x1
    /* AA94 80073294 1C82020C */  jal        func_800A0870
    /* AA98 80073298 01000424 */   addiu     $a0, $zero, 0x1
    /* AA9C 8007329C 3400BF8F */  lw         $ra, 0x34($sp)
    /* AAA0 800732A0 3000B08F */  lw         $s0, 0x30($sp)
    /* AAA4 800732A4 0800E003 */  jr         $ra
    /* AAA8 800732A8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _initBattleCameraTransition
