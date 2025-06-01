.include "macro.inc"
.set noreorder

.data 
SAVERA:
.word 0

.text

.word 0x00097350
.word 0x00450000

.macro ctc2w value, reg
    li         $t0, \value
    ctc2       $t0, \reg
    .nop
.endm

glabel InitGeom
    sw         $ra, SAVERA
    jal        _patch_gte
    .nop
    lw         $ra, SAVERA
    .nop
    mfc0       $v0, $12
    li         $v1, 0x40000000
    or         $v0, $v0, $v1
    mtc0       $v0, $12
    .nop
    ctc2w      0x155, $29
    ctc2w      0x100, $30
    ctc2w      0x3E8, $26
    ctc2w      -0x1062, $27
    ctc2w      0x1400000, $28
    ctc2       $zero, $24
    ctc2       $zero, $25
    .nop
    j          $ra
