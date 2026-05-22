nonmatching _promptFormat, 0x1B8

glabel _promptFormat
    /* 3B9C 8010639C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3BA0 801063A0 21188000 */  addu       $v1, $a0, $zero
    /* 3BA4 801063A4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3BA8 801063A8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3BAC 801063AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3BB0 801063B0 0E006010 */  beqz       $v1, .L801063EC
    /* 3BB4 801063B4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3BB8 801063B8 01000424 */  addiu      $a0, $zero, 0x1
    /* 3BBC 801063BC 1180023C */  lui        $v0, %hi(_promptFormatPort)
    /* 3BC0 801063C0 B7AA43A0 */  sb         $v1, %lo(_promptFormatPort)($v0)
    /* 3BC4 801063C4 1180023C */  lui        $v0, %hi(_textTable)
    /* 3BC8 801063C8 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 3BCC 801063CC 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 3BD0 801063D0 A8044224 */  addiu      $v0, $v0, 0x4A8
    /* 3BD4 801063D4 3218040C */  jal        _promptConfirm
    /* 3BD8 801063D8 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
    /* 3BDC 801063DC 21100000 */  addu       $v0, $zero, $zero
    /* 3BE0 801063E0 1180033C */  lui        $v1, %hi(_promptFormatState)
    /* 3BE4 801063E4 4F190408 */  j          .L8010653C
    /* 3BE8 801063E8 B6AA60A0 */   sb        $zero, %lo(_promptFormatState)($v1)
  .L801063EC:
    /* 3BEC 801063EC 1180113C */  lui        $s1, %hi(_promptFormatState)
    /* 3BF0 801063F0 B6AA3092 */  lbu        $s0, %lo(_promptFormatState)($s1)
    /* 3BF4 801063F4 01001224 */  addiu      $s2, $zero, 0x1
    /* 3BF8 801063F8 1C001212 */  beq        $s0, $s2, .L8010646C
    /* 3BFC 801063FC 0200022A */   slti      $v0, $s0, 0x2
    /* 3C00 80106400 05004010 */  beqz       $v0, .L80106418
    /* 3C04 80106404 02000224 */   addiu     $v0, $zero, 0x2
    /* 3C08 80106408 09000012 */  beqz       $s0, .L80106430
    /* 3C0C 8010640C 21100000 */   addu      $v0, $zero, $zero
    /* 3C10 80106410 4F190408 */  j          .L8010653C
    /* 3C14 80106414 00000000 */   nop
  .L80106418:
    /* 3C18 80106418 1E000212 */  beq        $s0, $v0, .L80106494
    /* 3C1C 8010641C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3C20 80106420 36000212 */  beq        $s0, $v0, .L801064FC
    /* 3C24 80106424 21100000 */   addu      $v0, $zero, $zero
    /* 3C28 80106428 4F190408 */  j          .L8010653C
    /* 3C2C 8010642C 00000000 */   nop
  .L80106430:
    /* 3C30 80106430 3218040C */  jal        _promptConfirm
    /* 3C34 80106434 21200000 */   addu      $a0, $zero, $zero
    /* 3C38 80106438 21184000 */  addu       $v1, $v0, $zero
    /* 3C3C 8010643C 3F006010 */  beqz       $v1, .L8010653C
    /* 3C40 80106440 21100000 */   addu      $v0, $zero, $zero
    /* 3C44 80106444 07006104 */  bgez       $v1, .L80106464
    /* 3C48 80106448 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3C4C 8010644C 1180033C */  lui        $v1, %hi(_textTable)
    /* 3C50 80106450 F8AD638C */  lw         $v1, %lo(_textTable)($v1)
    /* 3C54 80106454 1180043C */  lui        $a0, %hi(_memoryCardMessage)
    /* 3C58 80106458 5C056324 */  addiu      $v1, $v1, 0x55C
    /* 3C5C 8010645C 4F190408 */  j          .L8010653C
    /* 3C60 80106460 A4B083AC */   sw        $v1, %lo(_memoryCardMessage)($a0)
  .L80106464:
    /* 3C64 80106464 4E190408 */  j          .L80106538
    /* 3C68 80106468 B6AA32A2 */   sb        $s2, %lo(_promptFormatState)($s1)
  .L8010646C:
    /* 3C6C 8010646C C113040C */  jal        _fileMenuElementsActive
    /* 3C70 80106470 00000000 */   nop
    /* 3C74 80106474 30004010 */  beqz       $v0, .L80106538
    /* 3C78 80106478 1180023C */   lui       $v0, %hi(_promptFormatPort)
    /* 3C7C 8010647C B7AA4490 */  lbu        $a0, %lo(_promptFormatPort)($v0)
    /* 3C80 80106480 F70C040C */  jal        _memcardEventHandler
    /* 3C84 80106484 00000000 */   nop
    /* 3C88 80106488 02000224 */  addiu      $v0, $zero, 0x2
    /* 3C8C 8010648C 4E190408 */  j          .L80106538
    /* 3C90 80106490 B6AA22A2 */   sb        $v0, %lo(_promptFormatState)($s1)
  .L80106494:
    /* 3C94 80106494 F70C040C */  jal        _memcardEventHandler
    /* 3C98 80106498 21200000 */   addu      $a0, $zero, $zero
    /* 3C9C 8010649C 21184000 */  addu       $v1, $v0, $zero
    /* 3CA0 801064A0 25006010 */  beqz       $v1, .L80106538
    /* 3CA4 801064A4 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CA8 801064A8 07006214 */  bne        $v1, $v0, .L801064C8
    /* 3CAC 801064AC 1180023C */   lui       $v0, %hi(_textTable)
    /* 3CB0 801064B0 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 3CB4 801064B4 B6AA23A2 */  sb         $v1, %lo(_promptFormatState)($s1)
    /* 3CB8 801064B8 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 3CBC 801064BC E8044224 */  addiu      $v0, $v0, 0x4E8
    /* 3CC0 801064C0 4E190408 */  j          .L80106538
    /* 3CC4 801064C4 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
  .L801064C8:
    /* 3CC8 801064C8 05007014 */  bne        $v1, $s0, .L801064E0
    /* 3CCC 801064CC 1180033C */   lui       $v1, %hi(_memoryCardMessage)
    /* 3CD0 801064D0 1180023C */  lui        $v0, %hi(_textTable)
    /* 3CD4 801064D4 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 3CD8 801064D8 3C190408 */  j          .L801064F0
    /* 3CDC 801064DC C6014224 */   addiu     $v0, $v0, 0x1C6
  .L801064E0:
    /* 3CE0 801064E0 1180023C */  lui        $v0, %hi(_textTable)
    /* 3CE4 801064E4 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 3CE8 801064E8 00000000 */  nop
    /* 3CEC 801064EC BC034224 */  addiu      $v0, $v0, 0x3BC
  .L801064F0:
    /* 3CF0 801064F0 A4B062AC */  sw         $v0, %lo(_memoryCardMessage)($v1)
    /* 3CF4 801064F4 4F190408 */  j          .L8010653C
    /* 3CF8 801064F8 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L801064FC:
    /* 3CFC 801064FC 1180023C */  lui        $v0, %hi(_promptFormatPort)
    /* 3D00 80106500 B7AA4490 */  lbu        $a0, %lo(_promptFormatPort)($v0)
    /* 3D04 80106504 00000000 */  nop
    /* 3D08 80106508 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 3D0C 8010650C A1BC000C */  jal        _card_format
    /* 3D10 80106510 00210400 */   sll       $a0, $a0, 4
    /* 3D14 80106514 09004014 */  bnez       $v0, .L8010653C
    /* 3D18 80106518 01000224 */   addiu     $v0, $zero, 0x1
    /* 3D1C 8010651C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 3D20 80106520 1180033C */  lui        $v1, %hi(_textTable)
    /* 3D24 80106524 F8AD638C */  lw         $v1, %lo(_textTable)($v1)
    /* 3D28 80106528 1180043C */  lui        $a0, %hi(_memoryCardMessage)
    /* 3D2C 8010652C 40056324 */  addiu      $v1, $v1, 0x540
    /* 3D30 80106530 4F190408 */  j          .L8010653C
    /* 3D34 80106534 A4B083AC */   sw        $v1, %lo(_memoryCardMessage)($a0)
  .L80106538:
    /* 3D38 80106538 21100000 */  addu       $v0, $zero, $zero
  .L8010653C:
    /* 3D3C 8010653C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3D40 80106540 1800B28F */  lw         $s2, 0x18($sp)
    /* 3D44 80106544 1400B18F */  lw         $s1, 0x14($sp)
    /* 3D48 80106548 1000B08F */  lw         $s0, 0x10($sp)
    /* 3D4C 8010654C 0800E003 */  jr         $ra
    /* 3D50 80106550 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _promptFormat
