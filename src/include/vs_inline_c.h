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
