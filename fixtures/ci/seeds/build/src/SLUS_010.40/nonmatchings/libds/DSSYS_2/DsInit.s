nonmatching DsInit, 0x144

glabel DsInit
    /* 140C4 800238C4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 140C8 800238C8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 140CC 800238CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 140D0 800238D0 DA95000C */  jal        DS_system_active
    /* 140D4 800238D4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 140D8 800238D8 46004014 */  bnez       $v0, .L800239F4
    /* 140DC 800238DC 21100000 */   addu      $v0, $zero, $zero
    /* 140E0 800238E0 21180000 */  addu       $v1, $zero, $zero
    /* 140E4 800238E4 0480023C */  lui        $v0, %hi(D_80039E60)
    /* 140E8 800238E8 609E4224 */  addiu      $v0, $v0, %lo(D_80039E60)
    /* 140EC 800238EC 000040AC */  sw         $zero, 0x0($v0)
    /* 140F0 800238F0 040040AC */  sw         $zero, 0x4($v0)
    /* 140F4 800238F4 080040AC */  sw         $zero, 0x8($v0)
    /* 140F8 800238F8 0480023C */  lui        $v0, %hi(D_80039CC0)
    /* 140FC 800238FC C09C4224 */  addiu      $v0, $v0, %lo(D_80039CC0)
    /* 14100 80023900 200040AC */  sw         $zero, 0x20($v0)
    /* 14104 80023904 100040AC */  sw         $zero, 0x10($v0)
    /* 14108 80023908 000040AC */  sw         $zero, 0x0($v0)
    /* 1410C 8002390C 240040A0 */  sb         $zero, 0x24($v0)
    /* 14110 80023910 140040A0 */  sb         $zero, 0x14($v0)
    /* 14114 80023914 040040A0 */  sb         $zero, 0x4($v0)
  .L80023918:
    /* 14118 80023918 0480013C */  lui        $at, %hi(D_80039CC5)
    /* 1411C 8002391C 21082300 */  addu       $at, $at, $v1
    /* 14120 80023920 C59C20A0 */  sb         $zero, %lo(D_80039CC5)($at)
    /* 14124 80023924 0480013C */  lui        $at, %hi(D_80039CD5)
    /* 14128 80023928 21082300 */  addu       $at, $at, $v1
    /* 1412C 8002392C D59C20A0 */  sb         $zero, %lo(D_80039CD5)($at)
    /* 14130 80023930 0480013C */  lui        $at, %hi(D_80039CE5)
    /* 14134 80023934 21082300 */  addu       $at, $at, $v1
    /* 14138 80023938 E59C20A0 */  sb         $zero, %lo(D_80039CE5)($at)
    /* 1413C 8002393C 01006324 */  addiu      $v1, $v1, 0x1
    /* 14140 80023940 08006228 */  slti       $v0, $v1, 0x8
    /* 14144 80023944 F4FF4014 */  bnez       $v0, .L80023918
    /* 14148 80023948 21880000 */   addu      $s1, $zero, $zero
    /* 1414C 8002394C 0480103C */  lui        $s0, %hi(D_80039CF0)
    /* 14150 80023950 F09C1026 */  addiu      $s0, $s0, %lo(D_80039CF0)
  .L80023954:
    /* 14154 80023954 798C000C */  jal        func_800231E4
    /* 14158 80023958 21200002 */   addu      $a0, $s0, $zero
    /* 1415C 8002395C 01003126 */  addiu      $s1, $s1, 0x1
    /* 14160 80023960 0800222A */  slti       $v0, $s1, 0x8
    /* 14164 80023964 FBFF4014 */  bnez       $v0, .L80023954
    /* 14168 80023968 18001026 */   addiu     $s0, $s0, 0x18
    /* 1416C 8002396C 07000324 */  addiu      $v1, $zero, 0x7
    /* 14170 80023970 70000224 */  addiu      $v0, $zero, 0x70
    /* 14174 80023974 0480013C */  lui        $at, %hi(D_80039DB4)
    /* 14178 80023978 B49D20AC */  sw         $zero, %lo(D_80039DB4)($at)
    /* 1417C 8002397C 0480013C */  lui        $at, %hi(D_80039DB0)
    /* 14180 80023980 B09D20AC */  sw         $zero, %lo(D_80039DB0)($at)
    /* 14184 80023984 0480013C */  lui        $at, %hi(D_80039DB8)
    /* 14188 80023988 B89D20AC */  sw         $zero, %lo(D_80039DB8)($at)
  .L8002398C:
    /* 1418C 8002398C 0480013C */  lui        $at, %hi(D_80039DC0)
    /* 14190 80023990 21082200 */  addu       $at, $at, $v0
    /* 14194 80023994 C09D20AC */  sw         $zero, %lo(D_80039DC0)($at)
    /* 14198 80023998 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1419C 8002399C FBFF6104 */  bgez       $v1, .L8002398C
    /* 141A0 800239A0 F0FF4224 */   addiu     $v0, $v0, -0x10
    /* 141A4 800239A4 0480013C */  lui        $at, %hi(D_80039E40)
    /* 141A8 800239A8 A591000C */  jal        DS_init
    /* 141AC 800239AC 409E20AC */   sw        $zero, %lo(D_80039E40)($at)
    /* 141B0 800239B0 0280043C */  lui        $a0, %hi(func_80023614)
    /* 141B4 800239B4 3592000C */  jal        DS_sync_callback
    /* 141B8 800239B8 14368424 */   addiu     $a0, $a0, %lo(func_80023614)
    /* 141BC 800239BC 0280043C */  lui        $a0, %hi(func_80024590)
    /* 141C0 800239C0 3892000C */  jal        DS_ready_callback
    /* 141C4 800239C4 90458424 */   addiu     $a0, $a0, %lo(func_80024590)
    /* 141C8 800239C8 0280043C */  lui        $a0, %hi(func_80024664)
    /* 141CC 800239CC 3B92000C */  jal        DS_start_callback
    /* 141D0 800239D0 64468424 */   addiu     $a0, $a0, %lo(func_80024664)
    /* 141D4 800239D4 0280043C */  lui        $a0, %hi(func_800244EC)
    /* 141D8 800239D8 3292000C */  jal        DS_vsync_callback
    /* 141DC 800239DC EC448424 */   addiu     $a0, $a0, %lo(func_800244EC)
    /* 141E0 800239E0 EB99000C */  jal        ER_clear
    /* 141E4 800239E4 00000000 */   nop
    /* 141E8 800239E8 D398000C */  jal        DsReadySystemMode
    /* 141EC 800239EC 21200000 */   addu      $a0, $zero, $zero
    /* 141F0 800239F0 01000224 */  addiu      $v0, $zero, 0x1
  .L800239F4:
    /* 141F4 800239F4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 141F8 800239F8 1400B18F */  lw         $s1, 0x14($sp)
    /* 141FC 800239FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 14200 80023A00 0800E003 */  jr         $ra
    /* 14204 80023A04 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel DsInit
