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
