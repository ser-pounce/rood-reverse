/* Allocates the name of the next entry point of the effect being compiled. The overlay
 * defines VS_EFFECT_NAME, and each shared header that exports an entry point includes
 * this to take the next name in include order, VS_EFFECT_NAME_0, VS_EFFECT_NAME_1, and
 * so on, in VS_ENTRY_FUNCTION. */

#ifndef VS_CAT
#define VS_CAT_(a, b) a##b
#define VS_CAT(a, b) VS_CAT_(a, b)
#endif

#undef VS_ENTRY_FUNCTION

#if !defined(VS_ENTRY_0)
#define VS_ENTRY_0
#define VS_ENTRY_FUNCTION VS_CAT(VS_EFFECT_NAME, _0)
#elif !defined(VS_ENTRY_1)
#define VS_ENTRY_1
#define VS_ENTRY_FUNCTION VS_CAT(VS_EFFECT_NAME, _1)
#elif !defined(VS_ENTRY_2)
#define VS_ENTRY_2
#define VS_ENTRY_FUNCTION VS_CAT(VS_EFFECT_NAME, _2)
#elif !defined(VS_ENTRY_3)
#define VS_ENTRY_3
#define VS_ENTRY_FUNCTION VS_CAT(VS_EFFECT_NAME, _3)
#elif !defined(VS_ENTRY_4)
#define VS_ENTRY_4
#define VS_ENTRY_FUNCTION VS_CAT(VS_EFFECT_NAME, _4)
#elif !defined(VS_ENTRY_5)
#define VS_ENTRY_5
#define VS_ENTRY_FUNCTION VS_CAT(VS_EFFECT_NAME, _5)
#elif !defined(VS_ENTRY_6)
#define VS_ENTRY_6
#define VS_ENTRY_FUNCTION VS_CAT(VS_EFFECT_NAME, _6)
#elif !defined(VS_ENTRY_7)
#define VS_ENTRY_7
#define VS_ENTRY_FUNCTION VS_CAT(VS_EFFECT_NAME, _7)
#elif !defined(VS_ENTRY_8)
#define VS_ENTRY_8
#define VS_ENTRY_FUNCTION VS_CAT(VS_EFFECT_NAME, _8)
#else
#error "too many entry points"
#endif
