nonmatching _updateRoomIndex, 0xC8

glabel _updateRoomIndex
    /* 3E18 80106618 1180023C */  lui        $v0, %hi(_currentRoomIndex)
    /* 3E1C 8010661C 21284000 */  addu       $a1, $v0, $zero
    /* 3E20 80106620 0F80023C */  lui        $v0, %hi(vs_battle_sceneBuffer)
    /* 3E24 80106624 1180033C */  lui        $v1, %hi(_roomNamesTable)
    /* 3E28 80106628 648DA88C */  lw         $t0, %lo(_currentRoomIndex)($a1)
    /* 3E2C 8010662C C01B428C */  lw         $v0, %lo(vs_battle_sceneBuffer)($v0)
    /* 3E30 80106630 988D668C */  lw         $a2, %lo(_roomNamesTable)($v1)
    /* 3E34 80106634 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3E38 80106638 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3E3C 8010663C 04004724 */  addiu      $a3, $v0, 0x4
  .L80106640:
    /* 3E40 80106640 0A008018 */  blez       $a0, .L8010666C
    /* 3E44 80106644 00000000 */   nop
    /* 3E48 80106648 648DA28C */  lw         $v0, %lo(_currentRoomIndex)($a1)
    /* 3E4C 8010664C 00000000 */  nop
    /* 3E50 80106650 C0180200 */  sll        $v1, $v0, 3
    /* 3E54 80106654 21186200 */  addu       $v1, $v1, $v0
    /* 3E58 80106658 80180300 */  sll        $v1, $v1, 2
    /* 3E5C 8010665C 21186600 */  addu       $v1, $v1, $a2
    /* 3E60 80106660 22006284 */  lh         $v0, 0x22($v1)
    /* 3E64 80106664 A4190408 */  j          .L80106690
    /* 3E68 80106668 648DA2AC */   sw        $v0, %lo(_currentRoomIndex)($a1)
  .L8010666C:
    /* 3E6C 8010666C 648DA28C */  lw         $v0, %lo(_currentRoomIndex)($a1)
    /* 3E70 80106670 00000000 */  nop
    /* 3E74 80106674 C0180200 */  sll        $v1, $v0, 3
    /* 3E78 80106678 21186200 */  addu       $v1, $v1, $v0
    /* 3E7C 8010667C 80180300 */  sll        $v1, $v1, 2
    /* 3E80 80106680 21186600 */  addu       $v1, $v1, $a2
    /* 3E84 80106684 20006284 */  lh         $v0, 0x20($v1)
    /* 3E88 80106688 00000000 */  nop
    /* 3E8C 8010668C 648DA2AC */  sw         $v0, %lo(_currentRoomIndex)($a1)
  .L80106690:
    /* 3E90 80106690 648DA28C */  lw         $v0, %lo(_currentRoomIndex)($a1)
    /* 3E94 80106694 00000000 */  nop
    /* 3E98 80106698 40180200 */  sll        $v1, $v0, 1
    /* 3E9C 8010669C 21186200 */  addu       $v1, $v1, $v0
    /* 3EA0 801066A0 80180300 */  sll        $v1, $v1, 2
    /* 3EA4 801066A4 21186700 */  addu       $v1, $v1, $a3
    /* 3EA8 801066A8 0000628C */  lw         $v0, 0x0($v1)
    /* 3EAC 801066AC 00000000 */  nop
    /* 3EB0 801066B0 E3FF4010 */  beqz       $v0, .L80106640
    /* 3EB4 801066B4 1180023C */   lui       $v0, %hi(_currentRoomIndex)
    /* 3EB8 801066B8 648D428C */  lw         $v0, %lo(_currentRoomIndex)($v0)
    /* 3EBC 801066BC 00000000 */  nop
    /* 3EC0 801066C0 03000211 */  beq        $t0, $v0, .L801066D0
    /* 3EC4 801066C4 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 3EC8 801066C8 6216010C */  jal        vs_main_playSfxDefault
    /* 3ECC 801066CC 0B000524 */   addiu     $a1, $zero, 0xB
  .L801066D0:
    /* 3ED0 801066D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3ED4 801066D4 00000000 */  nop
    /* 3ED8 801066D8 0800E003 */  jr         $ra
    /* 3EDC 801066DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _updateRoomIndex
