#pragma once

#define COS22 (ONE * 0.9239)
#define SIN22 (ONE * 0.3827)
#define COS45 (ONE * 0.7071)

// Magnitudes of the negative-side values (truncate toward zero when negated)
#define K8536 (ONE * 0.8536)  // cos22 * cos22
#define K6534 (ONE * 0.6534)  // cos22 * cos45
#define K5000 (ONE * 0.5)     // cos45 * cos45
#define K3536 (ONE * 0.3536)  // cos22 * sin22
#define K2706 (ONE * 0.2706)  // sin22 * cos45
#define K1466 (ONE * 0.1466)  // sin22 * sin22

// Positive-side values are one LSB smaller than the matching negative magnitude
#define POS(m) ((m) - 1)

#define POLE { 0, ONE, 0 }

#ifndef VS_SURFACE_VERTICES
#ifndef VS_CAT
#define VS_CAT_(a, b) a##b
#define VS_CAT(a, b) VS_CAT_(a, b)
#endif
#ifdef VS_MIRROR_SURFACE_FUNCTION
#define VS_SURFACE_VERTICES VS_CAT(VS_MIRROR_SURFACE_FUNCTION, _vertices)
#else
#define VS_SURFACE_VERTICES VS_CAT(VS_SURFACE_FUNCTION, _vertices)
#endif
#endif

// clang-format off
static SVECTOR VS_SURFACE_VERTICES[][16] = {
    // ring 0: y = 0
    {
        {  ONE,    0,  0     },
        {  COS22,  0,  SIN22 },
        {  COS45,  0,  COS45 },
        {  SIN22,  0,  COS22 },
        {  0,      0,  ONE   },
        { -SIN22,  0,  COS22 },
        { -COS45,  0,  COS45 },
        { -COS22,  0,  SIN22 },
        { -ONE,    0,  0     },
        { -COS22,  0, -SIN22 },
        { -COS45,  0, -COS45 },
        { -SIN22,  0, -COS22 },
        {  0,      0, -ONE   },
        {  SIN22,  0, -COS22 },
        {  COS45,  0, -COS45 },
        {  COS22,  0, -SIN22 },
    },
    // ring 1: y = SIN22
    {
        {  COS22,         SIN22,  0              },
        {  POS(K8536),    SIN22,  POS(K3536)     },
        {  POS(K6534),    SIN22,  POS(K6534)     },
        {  POS(K3536),    SIN22,  POS(K8536)     },
        {  0,             SIN22,  COS22          },
        { -K3536,         SIN22,  POS(K8536)     },
        { -K6534,         SIN22,  POS(K6534)     },
        { -K8536,         SIN22,  POS(K3536)     },
        { -COS22,         SIN22,  0              },
        { -K8536,         SIN22, -K3536          },
        { -K6534,         SIN22, -K6534          },
        { -K3536,         SIN22, -K8536          },
        {  0,             SIN22, -COS22          },
        {  POS(K3536),    SIN22, -K8536          },
        {  POS(K6534),    SIN22, -K6534          },
        {  POS(K8536),    SIN22, -K3536          },
    },
    // ring 2: y = COS45
    {
        {  COS45,         COS45,  0              },
        {  POS(K6534),    COS45,  POS(K2706)     },
        {  POS(K5000),    COS45,  POS(K5000)     },
        {  POS(K2706),    COS45,  POS(K6534)     },
        {  0,             COS45,  COS45          },
        { -K2706,         COS45,  POS(K6534)     },
        { -K5000,         COS45,  POS(K5000)     },
        { -K6534,         COS45,  POS(K2706)     },
        { -COS45,         COS45,  0              },
        { -K6534,         COS45, -K2706          },
        { -K5000,         COS45, -K5000          },
        { -K2706,         COS45, -K6534          },
        {  0,             COS45, -COS45          },
        {  POS(K2706),    COS45, -K6534          },
        {  POS(K5000),    COS45, -K5000          },
        {  POS(K6534),    COS45, -K2706          },
    },
    // ring 3: y = COS22
    {
        {  SIN22,         COS22,  0              },
        {  POS(K3536),    COS22,  POS(K1466)     },
        {  POS(K2706),    COS22,  POS(K2706)     },
        {  POS(K1466),    COS22,  POS(K3536)     },
        {  0,             COS22,  SIN22          },
        { -K1466,         COS22,  POS(K3536)     },
        { -K2706,         COS22,  POS(K2706)     },
        { -K3536,         COS22,  POS(K1466)     },
        { -SIN22,         COS22,  0              },
        { -K3536,         COS22, -K1466          },
        { -K2706,         COS22, -K2706          },
        { -K1466,         COS22, -K3536          },
        {  0,             COS22, -SIN22          },
        {  POS(K1466),    COS22, -K3536          },
        {  POS(K2706),    COS22, -K2706          },
        {  POS(K3536),    COS22, -K1466          },
    },
    // ring 4: pole
    {
        POLE, POLE, POLE, POLE, POLE, POLE, POLE, POLE,
        POLE, POLE, POLE, POLE, POLE, POLE, POLE, POLE,
    },
};
// clang-format on

#undef COS22
#undef SIN22
#undef COS45
#undef K8536
#undef K6534
#undef K5000
#undef K3536
#undef K2706
#undef K1466
#undef POS
#undef POLE
