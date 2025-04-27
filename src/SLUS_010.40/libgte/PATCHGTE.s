.include "macro.inc"
.set noreorder

.data
glabel SAVERA2
.word 0

.text
glabel _patch_gte
    sw         $ra, SAVERA2
    jal        EnterCriticalSection
    .nop
    li         $t1, 0x56
    li         $t2, 0xB0
    jal        $t2
    .nop
    lw         $v0, 0x18($v0)
    .nop
    addu       $v0, 0x28
    addu       $t7, $v0, $zero
    la         $t2, 3f
    la         $t1, 4f
0:
    lw         $v1, 0x0($t2)
    lw         $t3, 0x0($v0)
    addu       $t2, 0x4
    bne        $v1, $t3, 2f
    addu       $v0, 0x4
    bne        $t2, $t1, 0b
    .nop
    addu       $v0, $t7, $zero
    la         $t2, 4f
    la         $t1, 5f
1:
    lw         $v1, 0x0($t2)
    .nop
    sw         $v1, 0x0($v0)
    addu       $t2, 0x4
    bne        $t2, $t1, 1b
    addu       $v0, 0x4
2:
    jal        FlushCache
    .nop
    jal        ExitCriticalSection
    .nop
    lw         $ra, SAVERA2
    .nop
    j         $ra
    .nop

.set noat
3:
    sw         $at, 0x4($k0)
    sw         $v0, 0x8($k0)
    sw         $v1, 0xC($k0)
    sw         $ra, 0x7C($k0)
    mfc0       $v1, $14
    .nop
4:
    sw         $at, 0x4($k0)
    sw         $v0, 0x8($k0)
    mfc0       $v0, $13
    sw         $v1, 0xC($k0)
    mfc0       $v1, $14
    sw         $ra, 0x7C($k0)
5:
