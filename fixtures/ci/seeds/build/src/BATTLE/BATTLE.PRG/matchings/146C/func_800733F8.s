nonmatching func_800733F8, 0x8C

glabel func_800733F8
    /* ABF8 800733F8 00FFBD27 */  addiu      $sp, $sp, -0x100
    /* ABFC 800733FC 1000A4A7 */  sh         $a0, 0x10($sp)
    /* AC00 80073400 1000A427 */  addiu      $a0, $sp, 0x10
    /* AC04 80073404 0F80023C */  lui        $v0, %hi(D_800F196C)
    /* AC08 80073408 F800B0AF */  sw         $s0, 0xF8($sp)
    /* AC0C 8007340C 04001024 */  addiu      $s0, $zero, 0x4
    /* AC10 80073410 6C1950AC */  sw         $s0, %lo(D_800F196C)($v0)
    /* AC14 80073414 01000224 */  addiu      $v0, $zero, 0x1
    /* AC18 80073418 21280000 */  addu       $a1, $zero, $zero
    /* AC1C 8007341C 2130A000 */  addu       $a2, $a1, $zero
    /* AC20 80073420 FC00BFAF */  sw         $ra, 0xFC($sp)
    /* AC24 80073424 1200A2A3 */  sb         $v0, 0x12($sp)
    /* AC28 80073428 1300A0A3 */  sb         $zero, 0x13($sp)
    /* AC2C 8007342C 1400B0A7 */  sh         $s0, 0x14($sp)
    /* AC30 80073430 1800A0A3 */  sb         $zero, 0x18($sp)
    /* AC34 80073434 1900A0A3 */  sb         $zero, 0x19($sp)
    /* AC38 80073438 1A00A0A3 */  sb         $zero, 0x1A($sp)
    /* AC3C 8007343C 2000B0A7 */  sh         $s0, 0x20($sp)
    /* AC40 80073440 2400A0A3 */  sb         $zero, 0x24($sp)
    /* AC44 80073444 2500A0A3 */  sb         $zero, 0x25($sp)
    /* AC48 80073448 2600A0A3 */  sb         $zero, 0x26($sp)
    /* AC4C 8007344C F400A0A7 */  sh         $zero, 0xF4($sp)
    /* AC50 80073450 F200A0A7 */  sh         $zero, 0xF2($sp)
    /* AC54 80073454 3A3C030C */  jal        func_800CF0E8
    /* AC58 80073458 F000A0A7 */   sh        $zero, 0xF0($sp)
    /* AC5C 8007345C 01000424 */  addiu      $a0, $zero, 0x1
    /* AC60 80073460 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* AC64 80073464 952D030C */  jal        func_800CB654
    /* AC68 80073468 4CE250AC */   sw        $s0, %lo(vs_gametime_tickspeed)($v0)
    /* AC6C 8007346C 322D020C */  jal        func_8008B4C8
    /* AC70 80073470 21200000 */   addu      $a0, $zero, $zero
    /* AC74 80073474 FC00BF8F */  lw         $ra, 0xFC($sp)
    /* AC78 80073478 F800B08F */  lw         $s0, 0xF8($sp)
    /* AC7C 8007347C 0800E003 */  jr         $ra
    /* AC80 80073480 0001BD27 */   addiu     $sp, $sp, 0x100
endlabel func_800733F8
