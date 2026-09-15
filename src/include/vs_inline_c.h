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
