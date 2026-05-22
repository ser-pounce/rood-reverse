nonmatching _initMemcard, 0x254

glabel _initMemcard
    /* 1BC4 801043C4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BC8 801043C8 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1BCC 801043CC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1BD0 801043D0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BD4 801043D4 29008010 */  beqz       $a0, .L8010447C
    /* 1BD8 801043D8 1800B0AF */   sw        $s0, 0x18($sp)
    /* 1BDC 801043DC 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 1BE0 801043E0 03000524 */  addiu      $a1, $zero, 0x3
    /* 1BE4 801043E4 FCF7010C */  jal        func_8007DFF0
    /* 1BE8 801043E8 06000624 */   addiu     $a2, $zero, 0x6
    /* 1BEC 801043EC 0100043C */  lui        $a0, (0x1C000 >> 16)
    /* 1BF0 801043F0 B10F010C */  jal        vs_main_allocHeap
    /* 1BF4 801043F4 00C08434 */   ori       $a0, $a0, (0x1C000 & 0xFFFF)
    /* 1BF8 801043F8 0100053C */  lui        $a1, (0x11400 >> 16)
    /* 1BFC 801043FC 0014A534 */  ori        $a1, $a1, (0x11400 & 0xFFFF)
    /* 1C00 80104400 0100073C */  lui        $a3, (0x14C98 >> 16)
    /* 1C04 80104404 984CE734 */  ori        $a3, $a3, (0x14C98 & 0xFFFF)
    /* 1C08 80104408 0100063C */  lui        $a2, (0x1C000 >> 16)
    /* 1C0C 8010440C 00C0C634 */  ori        $a2, $a2, (0x1C000 & 0xFFFF)
    /* 1C10 80104410 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1C14 80104414 1180103C */  lui        $s0, %hi(_spmcimg)
    /* 1C18 80104418 1180033C */  lui        $v1, %hi(_mcData)
    /* 1C1C 8010441C F0AD02AE */  sw         $v0, %lo(_spmcimg)($s0)
    /* 1C20 80104420 21104500 */  addu       $v0, $v0, $a1
    /* 1C24 80104424 1180053C */  lui        $a1, %hi(_textTable)
    /* 1C28 80104428 F4AD62AC */  sw         $v0, %lo(_mcData)($v1)
    /* 1C2C 8010442C 00104324 */  addiu      $v1, $v0, 0x1000
    /* 1C30 80104430 F8ADA3AC */  sw         $v1, %lo(_textTable)($a1)
    /* 1C34 80104434 1180053C */  lui        $a1, %hi(_saveFileInfo)
    /* 1C38 80104438 00204324 */  addiu      $v1, $v0, 0x2000
    /* 1C3C 8010443C 40AEA3AC */  sw         $v1, %lo(_saveFileInfo)($a1)
    /* 1C40 80104440 1180033C */  lui        $v1, %hi(_dirEntBuf)
    /* 1C44 80104444 80224224 */  addiu      $v0, $v0, 0x2280
    /* 1C48 80104448 3CAE62AC */  sw         $v0, %lo(_dirEntBuf)($v1)
    /* 1C4C 8010444C 1000A7AF */  sw         $a3, 0x10($sp)
    /* 1C50 80104450 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 1C54 80104454 1400A6AF */   sw        $a2, 0x14($sp)
    /* 1C58 80104458 21204000 */  addu       $a0, $v0, $zero
    /* 1C5C 8010445C F0AD058E */  lw         $a1, %lo(_spmcimg)($s0)
    /* 1C60 80104460 1180023C */  lui        $v0, %hi(_initMemcardCdQueueSlot)
    /* 1C64 80104464 F112010C */  jal        vs_main_cdEnqueue
    /* 1C68 80104468 A0AA44AC */   sw        $a0, %lo(_initMemcardCdQueueSlot)($v0)
    /* 1C6C 8010446C 21100000 */  addu       $v0, $zero, $zero
    /* 1C70 80104470 1180033C */  lui        $v1, %hi(_initMemcardState)
    /* 1C74 80104474 80110408 */  j          .L80104600
    /* 1C78 80104478 9CAA60A0 */   sb        $zero, %lo(_initMemcardState)($v1)
  .L8010447C:
    /* 1C7C 8010447C 1180103C */  lui        $s0, %hi(_initMemcardState)
    /* 1C80 80104480 9CAA0392 */  lbu        $v1, %lo(_initMemcardState)($s0)
    /* 1C84 80104484 01001124 */  addiu      $s1, $zero, 0x1
    /* 1C88 80104488 1D007110 */  beq        $v1, $s1, .L80104500
    /* 1C8C 8010448C 02006228 */   slti      $v0, $v1, 0x2
    /* 1C90 80104490 05004010 */  beqz       $v0, .L801044A8
    /* 1C94 80104494 02000224 */   addiu     $v0, $zero, 0x2
    /* 1C98 80104498 07006010 */  beqz       $v1, .L801044B8
    /* 1C9C 8010449C 21100000 */   addu      $v0, $zero, $zero
    /* 1CA0 801044A0 80110408 */  j          .L80104600
    /* 1CA4 801044A4 00000000 */   nop
  .L801044A8:
    /* 1CA8 801044A8 24006210 */  beq        $v1, $v0, .L8010453C
    /* 1CAC 801044AC 21100000 */   addu      $v0, $zero, $zero
    /* 1CB0 801044B0 80110408 */  j          .L80104600
    /* 1CB4 801044B4 00000000 */   nop
  .L801044B8:
    /* 1CB8 801044B8 1180023C */  lui        $v0, %hi(_initMemcardCdQueueSlot)
    /* 1CBC 801044BC A0AA448C */  lw         $a0, %lo(_initMemcardCdQueueSlot)($v0)
    /* 1CC0 801044C0 00000000 */  nop
    /* 1CC4 801044C4 00008384 */  lh         $v1, 0x0($a0)
    /* 1CC8 801044C8 04000224 */  addiu      $v0, $zero, 0x4
    /* 1CCC 801044CC 4C006214 */  bne        $v1, $v0, .L80104600
    /* 1CD0 801044D0 21100000 */   addu      $v0, $zero, $zero
    /* 1CD4 801044D4 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 1CD8 801044D8 00000000 */   nop
    /* 1CDC 801044DC 0001043C */  lui        $a0, (0x1000320 >> 16)
    /* 1CE0 801044E0 20038434 */  ori        $a0, $a0, (0x1000320 & 0xFFFF)
    /* 1CE4 801044E4 0001063C */  lui        $a2, (0x10000E0 >> 16)
    /* 1CE8 801044E8 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 1CEC 801044EC F0AD458C */  lw         $a1, %lo(_spmcimg)($v0)
    /* 1CF0 801044F0 CF0A040C */  jal        _drawImage
    /* 1CF4 801044F4 E000C634 */   ori       $a2, $a2, (0x10000E0 & 0xFFFF)
    /* 1CF8 801044F8 7F110408 */  j          .L801045FC
    /* 1CFC 801044FC 9CAA11A2 */   sb        $s1, %lo(_initMemcardState)($s0)
  .L80104500:
    /* 1D00 80104500 0100023C */  lui        $v0, (0x14CD0 >> 16)
    /* 1D04 80104504 D04C4234 */  ori        $v0, $v0, (0x14CD0 & 0xFFFF)
    /* 1D08 80104508 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1D0C 8010450C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1D10 80104510 00200224 */  addiu      $v0, $zero, 0x2000
    /* 1D14 80104514 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 1D18 80104518 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1D1C 8010451C 21204000 */  addu       $a0, $v0, $zero
    /* 1D20 80104520 1180023C */  lui        $v0, %hi(_mcData)
    /* 1D24 80104524 F4AD458C */  lw         $a1, %lo(_mcData)($v0)
    /* 1D28 80104528 1180023C */  lui        $v0, %hi(_initMemcardCdQueueSlot)
    /* 1D2C 8010452C F112010C */  jal        vs_main_cdEnqueue
    /* 1D30 80104530 A0AA44AC */   sw        $a0, %lo(_initMemcardCdQueueSlot)($v0)
    /* 1D34 80104534 02000224 */  addiu      $v0, $zero, 0x2
    /* 1D38 80104538 9CAA02A2 */  sb         $v0, %lo(_initMemcardState)($s0)
  .L8010453C:
    /* 1D3C 8010453C 1180023C */  lui        $v0, %hi(_initMemcardCdQueueSlot)
    /* 1D40 80104540 A0AA448C */  lw         $a0, %lo(_initMemcardCdQueueSlot)($v0)
    /* 1D44 80104544 00000000 */  nop
    /* 1D48 80104548 00008384 */  lh         $v1, 0x0($a0)
    /* 1D4C 8010454C 04000224 */  addiu      $v0, $zero, 0x4
    /* 1D50 80104550 2B006214 */  bne        $v1, $v0, .L80104600
    /* 1D54 80104554 21100000 */   addu      $v0, $zero, $zero
    /* 1D58 80104558 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 1D5C 8010455C 21800000 */   addu      $s0, $zero, $zero
    /* 1D60 80104560 250B010C */  jal        vs_main_enableReset
    /* 1D64 80104564 21200000 */   addu      $a0, $zero, $zero
    /* 1D68 80104568 5D9A000C */  jal        EnterCriticalSection
    /* 1D6C 8010456C 00000000 */   nop
    /* 1D70 80104570 1180023C */  lui        $v0, %hi(_eventSpecs)
    /* 1D74 80104574 B8A25224 */  addiu      $s2, $v0, %lo(_eventSpecs)
    /* 1D78 80104578 1180023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 1D7C 8010457C D0AD5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
  .L80104580:
    /* 1D80 80104580 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 1D84 80104584 04000232 */  andi       $v0, $s0, 0x4
    /* 1D88 80104588 03004010 */  beqz       $v0, .L80104598
    /* 1D8C 8010458C 01008434 */   ori       $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 1D90 80104590 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 1D94 80104594 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
  .L80104598:
    /* 1D98 80104598 00200624 */  addiu      $a2, $zero, 0x2000
    /* 1D9C 8010459C 03000232 */  andi       $v0, $s0, 0x3
    /* 1DA0 801045A0 01001026 */  addiu      $s0, $s0, 0x1
    /* 1DA4 801045A4 40100200 */  sll        $v0, $v0, 1
    /* 1DA8 801045A8 21105200 */  addu       $v0, $v0, $s2
    /* 1DAC 801045AC 00004594 */  lhu        $a1, 0x0($v0)
    /* 1DB0 801045B0 359A000C */  jal        OpenEvent
    /* 1DB4 801045B4 21380000 */   addu      $a3, $zero, $zero
    /* 1DB8 801045B8 000022AE */  sw         $v0, 0x0($s1)
    /* 1DBC 801045BC 0800022A */  slti       $v0, $s0, 0x8
    /* 1DC0 801045C0 EFFF4014 */  bnez       $v0, .L80104580
    /* 1DC4 801045C4 04003126 */   addiu     $s1, $s1, 0x4
    /* 1DC8 801045C8 619A000C */  jal        ExitCriticalSection
    /* 1DCC 801045CC 21800000 */   addu      $s0, $zero, $zero
    /* 1DD0 801045D0 1180023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 1DD4 801045D4 D0AD5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
  .L801045D8:
    /* 1DD8 801045D8 0000248E */  lw         $a0, 0x0($s1)
    /* 1DDC 801045DC 04003126 */  addiu      $s1, $s1, 0x4
    /* 1DE0 801045E0 459A000C */  jal        EnableEvent
    /* 1DE4 801045E4 01001026 */   addiu     $s0, $s0, 0x1
    /* 1DE8 801045E8 0800022A */  slti       $v0, $s0, 0x8
    /* 1DEC 801045EC FAFF4014 */  bnez       $v0, .L801045D8
    /* 1DF0 801045F0 01000224 */   addiu     $v0, $zero, 0x1
    /* 1DF4 801045F4 80110408 */  j          .L80104600
    /* 1DF8 801045F8 00000000 */   nop
  .L801045FC:
    /* 1DFC 801045FC 21100000 */  addu       $v0, $zero, $zero
  .L80104600:
    /* 1E00 80104600 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1E04 80104604 2000B28F */  lw         $s2, 0x20($sp)
    /* 1E08 80104608 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1E0C 8010460C 1800B08F */  lw         $s0, 0x18($sp)
    /* 1E10 80104610 0800E003 */  jr         $ra
    /* 1E14 80104614 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _initMemcard
