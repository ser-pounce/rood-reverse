#pragma once

#define gte_SetTransVector2(r0) __asm__ volatile (		\
	"lw	$12, 0( %0 );"					\
	"lw	$13, 4( %0 );"					\
	"ctc2	$12, $5;"					\
	"lw	$14, 8( %0 );"					\
	"ctc2	$13, $6;"					\
	"ctc2	$14, $7"					\
	:							\
	: "r"( r0 )						\
	: "$12", "$13", "$14" )

#define gte_rtv0tr2() __asm__ volatile ( \
    "nop;" \
    "nop;" \
    "rtv0tr")

#define gte_rtps2() __asm__ volatile ( \
    "nop;" \
    "nop;" \
    "rtps")

#define gte_zrtr() __asm__ volatile (		\
	"ctc2	$0, $5;"					\
	"ctc2	$0, $6;"					\
	"ctc2	$0, $7"						\
)

#define gte_nclip2() __asm__ volatile ( \
    "nop;" \
    "nop;" \
    "nclip")

#define gte_ldir1ir2(r0, r1) __asm__ volatile ( \
    "mtc2 %0, $9;" \
    "mtc2 %1, $10" \
    : \
    : "r"( r0 ), "r"( r1 ) )

#define gte_stmac1mac2(r0, r1) __asm__ volatile ( \
    "mfc2 %0, $25;" \
    "mfc2 %1, $26;" \
    "nop" \
    : "=r"( r0 ), "=r"( r1 ) )

#define gte_stlzcr(r0) __asm__ volatile ( \
    "mfc2 %0, $31;" \
    "nop" \
    : "=r"( r0 ) )

#define gte_sqr0_1nop() __asm__ volatile ( \
    "nop;" \
    "sqr 0")

// Loads the light matrix control registers (L11L12-L33) from registers
#define gte_ldlm2(r0, r1, r2, r3, r4) __asm__ volatile ( \
    "ctc2 %4, $8;" \
    "ctc2 %0, $9;" \
    "ctc2 %1, $10;" \
    "ctc2 %2, $11;" \
    "ctc2 %3, $12" \
    : "+r"( r1 ), "+r"( r2 ), "+r"( r3 ), "+r"( r4 ) \
    : "r"( r0 ) )

// Like gte_ldbkdir, but the operands are read-write
#define gte_ldbkdir2(r0, r1, r2) __asm__ volatile ( \
    "ctc2 %0, $13;" \
    "ctc2 %1, $14;" \
    "ctc2 %2, $15" \
    : "+r"( r0 ), "+r"( r1 ), "+r"( r2 ) )

// Copies IR1-3 into V0 (vx/vy packed into the first word)
#define gte_ldv0ir2(r0, r1, r2) __asm__ volatile ( \
    "mfc2 %0, $9;" \
    "mfc2 %1, $10;" \
    "mfc2 %2, $11;" \
    "andi $2, %0, 0xFFFF;" \
    "sll $3, %1, 16;" \
    "or %0, $2, $3;" \
    "mtc2 %0, $0;" \
    "mtc2 %2, $1" \
    : "+r"( r0 ), "+r"( r1 ), "+r"( r2 ) \
    : \
    : "$2", "$3" )

#define gte_rtps_b2() __asm__ volatile ( "rtps" )

#define gte_mvmva_b2(sf, mx, v, cv, lm) __asm__ volatile ( \
    "mvmva %0, %1, %2, %3, %4" \
    : \
    : "i"( sf ), "i"( mx ), "i"( v ), "i"( cv ), "i"( lm ) )
