nonmatching func_800CA9C0, 0x180

glabel func_800CA9C0
    /* 621C0 800CA9C0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 621C4 800CA9C4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 621C8 800CA9C8 21888000 */  addu       $s1, $a0, $zero
    /* 621CC 800CA9CC FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 621D0 800CA9D0 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 621D4 800CA9D4 0F80023C */  lui        $v0, %hi(D_800EB9AC)
    /* 621D8 800CA9D8 ACB940A0 */  sb         $zero, %lo(D_800EB9AC)($v0)
    /* 621DC 800CA9DC 0F80023C */  lui        $v0, %hi(_loadedSubMenu)
    /* 621E0 800CA9E0 ADB940A0 */  sb         $zero, %lo(_loadedSubMenu)($v0)
    /* 621E4 800CA9E4 0F80023C */  lui        $v0, %hi(D_800EB9AE)
    /* 621E8 800CA9E8 AEB940A0 */  sb         $zero, %lo(D_800EB9AE)($v0)
    /* 621EC 800CA9EC 0F80023C */  lui        $v0, %hi(D_800EB9B0)
    /* 621F0 800CA9F0 B0B940AC */  sw         $zero, %lo(D_800EB9B0)($v0)
    /* 621F4 800CA9F4 0F80023C */  lui        $v0, %hi(D_800F4ED4)
    /* 621F8 800CA9F8 D44E40AC */  sw         $zero, %lo(D_800F4ED4)($v0)
    /* 621FC 800CA9FC 0F80023C */  lui        $v0, %hi(D_800EB9B4)
    /* 62200 800CAA00 B4B940AC */  sw         $zero, %lo(D_800EB9B4)($v0)
    /* 62204 800CAA04 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 62208 800CAA08 B8B940AC */  sw         $zero, %lo(D_800EB9B8)($v0)
    /* 6220C 800CAA0C 0F80023C */  lui        $v0, %hi(D_800EB9BC)
    /* 62210 800CAA10 BCB940AC */  sw         $zero, %lo(D_800EB9BC)($v0)
    /* 62214 800CAA14 0F80023C */  lui        $v0, %hi(vs_battle_menuItems)
    /* 62218 800CAA18 C0B940AC */  sw         $zero, %lo(vs_battle_menuItems)($v0)
    /* 6221C 800CAA1C 0F80023C */  lui        $v0, %hi(D_800EB9CE)
    /* 62220 800CAA20 CEB940A0 */  sb         $zero, %lo(D_800EB9CE)($v0)
    /* 62224 800CAA24 0F80023C */  lui        $v0, %hi(D_800F4E90)
    /* 62228 800CAA28 904E40A0 */  sb         $zero, %lo(D_800F4E90)($v0)
    /* 6222C 800CAA2C 0F80023C */  lui        $v0, %hi(D_800EB9AF)
    /* 62230 800CAA30 AFB940A0 */  sb         $zero, %lo(D_800EB9AF)($v0)
    /* 62234 800CAA34 0F80023C */  lui        $v0, %hi(D_800EB9CC)
    /* 62238 800CAA38 CCB940A0 */  sb         $zero, %lo(D_800EB9CC)($v0)
    /* 6223C 800CAA3C 0F80023C */  lui        $v0, %hi(D_800EB9CD)
    /* 62240 800CAA40 CDB940A0 */  sb         $zero, %lo(D_800EB9CD)($v0)
    /* 62244 800CAA44 0F80023C */  lui        $v0, %hi(D_800EB9D0)
    /* 62248 800CAA48 D0B943AC */  sw         $v1, %lo(D_800EB9D0)($v0)
    /* 6224C 800CAA4C 0F80023C */  lui        $v0, %hi(_menuBgUnpackedBuf)
    /* 62250 800CAA50 D4B940AC */  sw         $zero, %lo(_menuBgUnpackedBuf)($v0)
    /* 62254 800CAA54 0F80023C */  lui        $v0, %hi(D_800EB9D8)
    /* 62258 800CAA58 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6225C 800CAA5C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62260 800CAA60 5F2A030C */  jal        func_800CA97C
    /* 62264 800CAA64 D8B940AC */   sw        $zero, %lo(D_800EB9D8)($v0)
    /* 62268 800CAA68 0F80103C */  lui        $s0, %hi(vs_battle_menuState)
    /* 6226C 800CAA6C C0510426 */  addiu      $a0, $s0, %lo(vs_battle_menuState)
    /* 62270 800CAA70 0733030C */  jal        vs_battle_rMemzero
    /* 62274 800CAA74 08000524 */   addiu     $a1, $zero, 0x8
    /* 62278 800CAA78 0F80043C */  lui        $a0, %hi(D_800F4E98)
    /* 6227C 800CAA7C 984E8424 */  addiu      $a0, $a0, %lo(D_800F4E98)
    /* 62280 800CAA80 08000524 */  addiu      $a1, $zero, 0x8
    /* 62284 800CAA84 3F000224 */  addiu      $v0, $zero, 0x3F
    /* 62288 800CAA88 0733030C */  jal        vs_battle_rMemzero
    /* 6228C 800CAA8C C05102A2 */   sb        $v0, %lo(vs_battle_menuState)($s0)
    /* 62290 800CAA90 0F80043C */  lui        $a0, %hi(vs_battle_textBoxes)
    /* 62294 800CAA94 E04F8424 */  addiu      $a0, $a0, %lo(vs_battle_textBoxes)
    /* 62298 800CAA98 0733030C */  jal        vs_battle_rMemzero
    /* 6229C 800CAA9C 30000524 */   addiu     $a1, $zero, 0x30
    /* 622A0 800CAAA0 0F80043C */  lui        $a0, %hi(vs_battle_submenuStates)
    /* 622A4 800CAAA4 704E8424 */  addiu      $a0, $a0, %lo(vs_battle_submenuStates)
    /* 622A8 800CAAA8 0733030C */  jal        vs_battle_rMemzero
    /* 622AC 800CAAAC 10000524 */   addiu     $a1, $zero, 0x10
    /* 622B0 800CAAB0 0F80043C */  lui        $a0, %hi(D_800F4EE8)
    /* 622B4 800CAAB4 E84E8424 */  addiu      $a0, $a0, %lo(D_800F4EE8)
    /* 622B8 800CAAB8 21280000 */  addu       $a1, $zero, $zero
    /* 622BC 800CAABC AD9B000C */  jal        memset
    /* 622C0 800CAAC0 F2000624 */   addiu     $a2, $zero, 0xF2
    /* 622C4 800CAAC4 40030424 */  addiu      $a0, $zero, 0x340
    /* 622C8 800CAAC8 21282002 */  addu       $a1, $s1, $zero
    /* 622CC 800CAACC E000063C */  lui        $a2, (0xE00040 >> 16)
    /* 622D0 800CAAD0 4000C634 */  ori        $a2, $a2, (0xE00040 & 0xFFFF)
    /* 622D4 800CAAD4 0F80103C */  lui        $s0, %hi(D_800F51B8)
    /* 622D8 800CAAD8 0F80023C */  lui        $v0, %hi(D_800F4CD0)
    /* 622DC 800CAADC D04C4224 */  addiu      $v0, $v0, %lo(D_800F4CD0)
    /* 622E0 800CAAE0 6A33030C */  jal        vs_battle_drawImage
    /* 622E4 800CAAE4 B85102AE */   sw        $v0, %lo(D_800F51B8)($s0)
    /* 622E8 800CAAE8 80030424 */  addiu      $a0, $zero, 0x380
    /* 622EC 800CAAEC 00702526 */  addiu      $a1, $s1, 0x7000
    /* 622F0 800CAAF0 E000063C */  lui        $a2, (0xE00040 >> 16)
    /* 622F4 800CAAF4 6A33030C */  jal        vs_battle_drawImage
    /* 622F8 800CAAF8 4000C634 */   ori       $a2, $a2, (0xE00040 & 0xFFFF)
    /* 622FC 800CAAFC 4200043C */  lui        $a0, (0x4203C0 >> 16)
    /* 62300 800CAB00 C0038434 */  ori        $a0, $a0, (0x4203C0 & 0xFFFF)
    /* 62304 800CAB04 00E00534 */  ori        $a1, $zero, 0xE000
    /* 62308 800CAB08 21282502 */  addu       $a1, $s1, $a1
    /* 6230C 800CAB0C 9E00063C */  lui        $a2, (0x9E0040 >> 16)
    /* 62310 800CAB10 6A33030C */  jal        vs_battle_drawImage
    /* 62314 800CAB14 4000C634 */   ori       $a2, $a2, (0x9E0040 & 0xFFFF)
    /* 62318 800CAB18 94A1000C */  jal        DrawSync
    /* 6231C 800CAB1C 21200000 */   addu      $a0, $zero, $zero
    /* 62320 800CAB20 B851048E */  lw         $a0, %lo(D_800F51B8)($s0)
    /* 62324 800CAB24 9DA2000C */  jal        ClearOTag
    /* 62328 800CAB28 22000524 */   addiu     $a1, $zero, 0x22
    /* 6232C 800CAB2C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 62330 800CAB30 1400B18F */  lw         $s1, 0x14($sp)
    /* 62334 800CAB34 1000B08F */  lw         $s0, 0x10($sp)
    /* 62338 800CAB38 0800E003 */  jr         $ra
    /* 6233C 800CAB3C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CA9C0
