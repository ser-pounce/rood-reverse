#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/32154.h"
#include "build/src/include/lbas.h"
#include "gpu.h"
#include "texture_t.h"
#include "scratch.h"
#include <abs.h>
#include <libetc.h>
#include <memory.h>
#include <stdio.h>

enum { maximumBrightness = 128 };

/**
 * Computes fixed-point sine.
 * Almost a byte-identical copy of rsin except for register differences
 */
static int _sin(int angle)
{
    u_long value = (u_long)_trig_table;
    int quadrant = angle & 0x400;
    int test = angle & 0x3FF;

    if (quadrant && !test) {
        value = ONE;
    } else {
        int index;

        if (quadrant) {
            angle = ONE / 2 - angle;
        }

        test = angle & 0x200;
        index = angle & 0x1FF;

        if (test) {
            quadrant = 512;
            index = quadrant - index;
            value += 2;
        }

        value += index * 4;
        value = *(u_short*)value;
    }

    if (angle & 0x800) {
        value = -value;
    }

    return value;
}

enum creditsElementState {
    creditsElementStateFinished = -1,
    creditsElementStateInactive = 0,
    creditsElementStateStarting,
    creditsElementStatePhase1,
    creditsElementStatePhase2,
    creditsElementStatePhase3,
    creditsElementStatePhase4,
};

typedef struct _creditsElement {
    void (*renderer)(struct _creditsElement*);
    u_char const* data;
    short state;
    u_short currentStep;
    u_short illustId;
    u_short width;
    int x;
    int y;
    int _[6] __attribute__((unused));
} _creditsElement;

enum easeMode {
    easeModeLinear,
    easeModeEaseOut,
    easeModeEaseInOut,
    easeModeEaseIn,
};

static int _ease(short mode, short currentStep, short totalSteps);

/**
 * Renders "The Phantom Pain" with a ripple effect.
 */
static void _renderPhantomPain(_creditsElement* element)
{
    enum phaseDurations {
        fadeInDuration = 90,
        holdDuration = 120,
        fadeOutDuration = 90,
    };

    static int wavePhase;
    static int rippleAge;
    static int _[2] __attribute__((unused));
    static u_char rippleDist[4][16];

    SVECTOR rot;
    SVECTOR vertices[4];
    MATRIX matrix;
    long depthCue;
    long flag;
    u_short brightness;
    u_short amplitude;
    u_short i;
    u_short j;
    POLY_FT4* poly = ((vs_scratch_t*)0x1F800000)->unk0;

    memset(&rot, 0, sizeof rot);

    switch (element->state) {
    case creditsElementStateStarting:
        wavePhase = 0;
        element->currentStep = 0;
        element->state = creditsElementStatePhase1;
        rippleAge = 0;

        for (i = 0; i < 4; ++i) {
            int shift = 2;
            int rowOffset = 2 - i;
            int dy = (ABS(rowOffset) << shift) * (ABS(rowOffset) << shift);

            for (j = 0; j < 16; ++j) {
                int dx = 8 - j;

                dx = ABS(dx) * 18;
                rippleDist[i][j] = vs_gte_rsqrt(dx * dx + dy);
            }
        }
        /* fallthrough */

    case creditsElementStatePhase1:
        brightness = element->currentStep * maximumBrightness / fadeInDuration;
        ++rippleAge;

        if (++element->currentStep == fadeInDuration) {
            element->currentStep = 0;
            element->state = creditsElementStatePhase2;
        }
        break;

    case creditsElementStatePhase2:
        brightness = maximumBrightness;

        if (++element->currentStep == holdDuration) {
            element->currentStep = 0;
            element->state = creditsElementStatePhase3;
        }
        break;

    case creditsElementStatePhase3:
        brightness = (fadeOutDuration - element->currentStep) * maximumBrightness
                   / fadeOutDuration;

        if (++element->currentStep == fadeOutDuration) {
            element->state = creditsElementStateFinished;
        }
        break;
    }

    wavePhase += 200;
    amplitude = (_ease(easeModeEaseIn, 90 - rippleAge, 90) * 65) >> 10;

    RotMatrix_gte(&rot, &matrix);
    matrix.t[0] = matrix.t[1] = 0;
    matrix.t[2] = 512;
    SetRotMatrix(&matrix);
    SetTransMatrix(&matrix);

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 16; ++j) {
            vertices[0].vx = vertices[2].vx = j * 9 - 72;
            vertices[1].vx = vertices[3].vx = (j + 1) * 9 - 72;
            vertices[0].vy = vertices[1].vy = i * 4 - 8;
            vertices[2].vy = vertices[3].vy = (i + 1) * 4 - 8;
            vertices[0].vz = (_sin(wavePhase + rippleDist[i][j] * 400) * amplitude) >> 12;
            // BUG: out of bounds read when i == 3 or j == 15
            vertices[1].vz =
                (_sin(wavePhase + rippleDist[i][j + 1] * 400) * amplitude) >> 12;
            vertices[2].vz =
                (_sin(wavePhase + rippleDist[i + 1][j] * 400) * amplitude) >> 12;
            vertices[3].vz =
                (_sin(wavePhase + rippleDist[i + 1][j + 1] * 400) * amplitude) >> 12;

            SetPolyFT4(poly);
            setSemiTrans(poly, 1);
            RotTransPers4(&vertices[0], &vertices[1], &vertices[2], &vertices[3],
                (long*)&poly->x0, (long*)&poly->x1, (long*)&poly->x2, (long*)&poly->x3,
                &depthCue, &flag);
            poly->u0 = poly->u2 = j * 9;
            poly->u1 = poly->u3 = (j + 1) * 9;
            poly->v0 = poly->v1 = i * 4 + 180;
            poly->v2 = poly->v3 = (i + 1) * 4 + 180;
            poly->clut = getClut(896, 83);
            poly->tpage = getTPage(clut4Bit, semiTransparencyFull, 896, 0);
            poly->r0 = poly->g0 = poly->b0 = brightness;
            AddPrim(((vs_scratch_t*)0x1F800000)->unk4 + 12, poly++);
        }
    }

    ((vs_scratch_t*)0x1F800000)->unk0 = poly;
}

static void* _insertTpage(int tPage, int otOffset);

/**
 * Renders the final "Fin" texture ("終劇" for the JP version).
 */
static void _renderFin(_creditsElement* element)
{
    enum phaseDurations {
        fadeInDuration = 60,
        holdDuration = 240,
        fadeOutDuration = 60,
    };

    int step0;
    int step1;
    u_char brightness;
    void** p;
    int index;

    SPRT* sprt = *(SPRT**)0x1F800000;

    switch (element->state) {
    case creditsElementStateStarting:
        element->currentStep = 0;
        element->state = creditsElementStatePhase1;
        /* fallthrough */

    case creditsElementStatePhase1:
        step0 = element->currentStep;
        element->currentStep = step0 + 1;
        brightness = (step0 * maximumBrightness) / fadeInDuration;

        if (element->currentStep == fadeInDuration) {
            element->currentStep = 0;
            element->state = creditsElementStatePhase2;
        }
        break;

    case creditsElementStatePhase2:
        brightness = maximumBrightness;

        if (++element->currentStep == holdDuration) {
            element->currentStep = 0;
            element->state = creditsElementStatePhase3;
        }
        break;

    case creditsElementStatePhase3:
        step1 = element->currentStep;
        element->currentStep = step1 + 1;
        brightness = ((fadeOutDuration - step1) * maximumBrightness) / fadeOutDuration;

        if (element->currentStep == fadeOutDuration) {
            element->state = creditsElementStateFinished;
        }

        break;
    }

    SetSprt(sprt);
    setXY0(sprt, 248, 184);
    setUV0(sprt, 0, 160);
    setWH(sprt, 36, 17);
    sprt->r0 = sprt->g0 = sprt->b0 = brightness;
    setClut(sprt, 896, 82);

    p = (void**)0x1F800000;
    setaddr(sprt, ((u_long*)p[1])[1]);
    setaddr(p[1] + 4, sprt++);

    index = 0;
    p[index] = sprt;
    p[index] = _insertTpage(getTPage(clut4Bit, semiTransparencyFull, 896, 0), 1);
}

static _creditsElement _creditsElements[32];
static u_char _creditsComplete;
static u_char _isFadedOut;
static u_char _skipInvoked;
static u_char _0 __attribute__((unused));
static int _currentCreditsFrame;
static int _textStreamDelay;
static u_char const* _creditsBytestreamHead;
static short _scrollSpeed;
static short _frameStartVsync;
static u_short _masterBrightness;
static u_short _1 __attribute__((unused));

/**
 * Renders the game title.
 */
static void _renderVagrantStory(_creditsElement* element)
{
    enum phaseDurations {
        fadeInDuration = 60,
        holdDuration = 60,
        scrollDuration = 60,
    };

    int brightness;
    void** p;
    int index;
    SPRT* sprt = *(SPRT**)0x1F800000;

    switch (element->state) {
    case creditsElementStateStarting:
        element->x = 61 * 256;
        element->y = 80 * 256;
        element->currentStep = 0;
        element->state = creditsElementStatePhase1;
        /* fallthrough */

    case creditsElementStatePhase1:
        brightness = (_masterBrightness * ++element->currentStep) / fadeInDuration;

        if (element->currentStep == fadeInDuration) {
            element->state = creditsElementStatePhase2;
            element->currentStep = 0;
        }
        break;

    case creditsElementStatePhase2:
        brightness = _masterBrightness;

        if (++element->currentStep == holdDuration) {
            element->state = creditsElementStatePhase3;
        }
        break;

    case creditsElementStatePhase3:
        brightness = _masterBrightness;
        element->y += _scrollSpeed;

        if (element->y < -(scrollDuration << 8)) {
            element->state = creditsElementStateFinished;
            return;
        }
        break;
    }

    SetSprt(sprt);
    setSemiTrans(sprt, 1);
    setXY0(sprt, element->x >> 8, element->y >> 8);
    setUV0(sprt, 0, 96);
    setWH(sprt, 208, 48);
    setClut(sprt, 896, 80);
    sprt->r0 = sprt->g0 = sprt->b0 = brightness;

    p = (void**)0x1F800000;
    setaddr(sprt, getaddr(p[1] + 12));
    setaddr(p[1] + 12, sprt++);

    index = 0;
    p[index] = sprt;

    sprt = _insertTpage(getTPage(clut4Bit, semiTransparencyFull, 896, 0), 3);

    SetSprt(sprt);
    setSemiTrans(sprt, 1);
    setXY0(sprt, element->x >> 8, element->y >> 8);
    setUV0(sprt, 0, 96);
    setWH(sprt, 208, 48);
    setClut(sprt, 896, 81);
    sprt->r0 = sprt->g0 = sprt->b0 = brightness;

    setaddr(sprt, getaddr(p[1] + 12));
    setaddr(p[1] + 12, sprt++);

    p[index] = sprt;
    p[index] = _insertTpage(getTPage(clut4Bit, semiTransparencySubtract, 896, 0), 3);
    return;
}

#pragma region dead_code

/**
 * Calculates the distance from the screen center, assuming a 320x224 screen size.
 */
static int _distanceFromScreencenter(int x, int y)
{
    x -= 160;
    y -= 112;
    return vs_gte_rsqrt(x * x + y * y);
}

#define CLAMP_HI(v) ((v) < 129 ? (v) : 128)
#define CLAMP_LO(v) ((v) >= 0 ? (v) : 0)

#define RADIAL_TERM(i) \
    (((200 - _distanceFromScreencenter(poly->x##i, poly->y##i)) * 128) / 400)

#define FADE(i, expr, clamp)                                                   \
    level = (expr);                                                            \
    poly->b##i = clamp(level);                                                 \
    poly->r##i = poly->g##i = poly->b##i;

#define FADE_IN(i) FADE(i, base + RADIAL_TERM(i), CLAMP_HI)
#define FADE_OUT(i) FADE(i, base - RADIAL_TERM(i), CLAMP_LO)

/**
 * Performs a radial fade in/out of the provided poly.
 */
__attribute__((unused)) static void _updateRadialFadePoly(
    POLY_GT4* poly, short progress, short fadeOut)
{
    short base;
    short level;

    if (fadeOut == 0) {
        base = (progress * 128) / 80;
        FADE_IN(0);
        FADE_IN(1);
        FADE_IN(2);
        FADE_IN(3);
    } else {
        base = ((80 - progress) * 128) / 80;
        FADE_OUT(0);
        FADE_OUT(1);
        FADE_OUT(2);
        FADE_OUT(3);
    }
}

#undef CLAMP_HI
#undef CLAMP_LO
#undef RADIAL_TERM
#undef FADE
#undef FADE_IN
#undef FADE_OUT

#pragma endregion

enum decompressionState {
    decompressionStateIdle,
    decompressionStateReady,
    decompressionStateActive,
};

static u_char _compressionState = decompressionStateIdle;

static int _illustLbas[] = { VS_ILLUST06_BIN_LBA, VS_ILLUST07_BIN_LBA,
    VS_ILLUST08_BIN_LBA, VS_ILLUST09_BIN_LBA, VS_ILLUST10_BIN_LBA, VS_ILLUST11_BIN_LBA,
    VS_ILLUST12_BIN_LBA, VS_ILLUST13_BIN_LBA, VS_ILLUST14_BIN_LBA, VS_ILLUST15_BIN_LBA,
    VS_ILLUST16_BIN_LBA, 0, 0, 0, 0, 0 };

static int _illustSizes[] = { VS_ILLUST06_BIN_SIZE, VS_ILLUST07_BIN_SIZE,
    VS_ILLUST08_BIN_SIZE, VS_ILLUST09_BIN_SIZE, VS_ILLUST10_BIN_SIZE,
    VS_ILLUST11_BIN_SIZE, VS_ILLUST12_BIN_SIZE, VS_ILLUST13_BIN_SIZE,
    VS_ILLUST14_BIN_SIZE, VS_ILLUST15_BIN_SIZE, VS_ILLUST16_BIN_SIZE, 0, 0, 0, 0, 0 };

typedef struct {
    int size;
    RECT rect;
    u_char data[0];
} _timChunk;

typedef struct {
    int magic;
    int flags;
    _timChunk chunk;
} _timData;

extern _timData _illustSydney;
static _timData* _decompressedIllustData = &_illustSydney;

static u_short _illustrationTimers[] = { 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600,
    1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600 };

static void const* _currentCompressedIllust;
static void* _currentDecompressedIllust;
static void* _compressedIllustBufs[16];

static void _loadTim(_timData const*);
static void _initTimDecompress(_timData*, void const*);

/**
 * Renders a background illustration. Illustration IDs greater
 * than 4 are first decompressed. The illustrations are rendered by
 * subtractive blending with the background.
 */
static void _renderllustration(_creditsElement* element)
{
    enum phaseDurations {
        fadeInDuration = 80,
        fadeOutDuration = 80,
    };

    static short brightness;
    static short tpageX;
    static u_short clutY;
    static u_short _ __attribute__((unused));

    SPRT* sprt;
    void** p;

    switch (element->state) {
    case creditsElementStateStarting:
        if ((element->illustId > 3) && (element->illustId != 15)) {
            _initTimDecompress(
                _decompressedIllustData, _compressedIllustBufs[element->illustId + 1]);
        }

        element->currentStep = 0;
        element->state = creditsElementStatePhase1;
        tpageX = (element->illustId % 5) * 192;
        clutY = (element->illustId % 5) + 480;
        /* fallthrough */

    case creditsElementStatePhase1:
        brightness = (_masterBrightness * element->currentStep) / fadeInDuration;

        if (++element->currentStep == fadeInDuration) {
            enum creditsElementState nextState = creditsElementStatePhase2;
            element->currentStep = 0;
            if (element->illustId == 15) {
                nextState = creditsElementStatePhase4;
            }
            element->state = nextState;
        }
        break;

    case creditsElementStatePhase2:
        brightness = maximumBrightness;

        if (++element->currentStep == _illustrationTimers[element->illustId]) {
            element->currentStep = 0;
            element->state = creditsElementStatePhase3;
        }

        break;

    case creditsElementStatePhase3:
        brightness = (_masterBrightness * (fadeOutDuration - element->currentStep))
                   / fadeOutDuration;

        if (++element->currentStep == fadeOutDuration) {
            if (++element->illustId > 4) {
                _loadTim(_decompressedIllustData);
            }
            element->state = creditsElementStateStarting;
        }
        break;

    case creditsElementStatePhase4:
        brightness = maximumBrightness;
        break;
    }

    p = (void**)0x1F800000;
    sprt = p[0];

    SetSprt(sprt);
    setXY0(sprt, 0, 0);
    setWH(sprt, 160, 224);
    setUV0(sprt, 0, 0);
    setSemiTrans(sprt, 1);
    setClut(sprt, 0, clutY);
    sprt->r0 = sprt->g0 = sprt->b0 = brightness;

    AddPrim(p[1] + 0x10, sprt++);

    p[0] = sprt;
    sprt = _insertTpage(getTPage(1, 2, tpageX, 256), 4);

    SetSprt(sprt);
    setXY0(sprt, 160, 0);
    setWH(sprt, 160, 224);
    setUV0(sprt, 32, 0);
    setSemiTrans(sprt, 1);
    setClut(sprt, 0, clutY);
    sprt->r0 = sprt->g0 = sprt->b0 = brightness;

    AddPrim(p[1] + 0x10, sprt++);

    p[0] = sprt;
    p[0] = _insertTpage(getTPage(1, 2, tpageX + 64, 256), 4);
}

extern u_char _glyphWidths[];

/**
 * Measures the rendered width of a string.
 */
static int _creditsStrWidth(u_char const* str)
{
    short len = *str++;
    short width = 0;
    unsigned short charTableOffset = 0;
    short i = 0;

    for (i = 0; i < len; ++i, ++str) {
        int _;
        int c = *str;

        if ((unsigned)c < ' ') {
            switch (c) {
            case 1:
                charTableOffset = 0;
                break;
            case 2:
                charTableOffset = 112;
                break;
            case 31:
                --width;
                break;
            }
        } else {
            width += _glyphWidths[(charTableOffset - (_ = 32)) + c] - 1;
        }
    }

    return width;
}

/**
 * Renders a string from the credits script.
 */
static void _renderText(_creditsElement* element)
{
    char const* str;
    short i;
    short len;
    short x;
    short y;
    SPRT* sprt = ((vs_scratch_t*)0x1F800000)->unk0;
    u_char charTableOffset = 0;
    short underline = 0;

    if (element->state == creditsElementStateStarting) {
        u_short width = element->width = _creditsStrWidth(element->data);
        element->x = ((320 - width) >> 1) << 8;
        element->y = 224 << 8;
        element->state = creditsElementStatePhase1;
    }

    element->y += _scrollSpeed;

    if (element->y < -(12 << 8)) {
        element->state = creditsElementStateFinished;
        return;
    }

    y = element->y >> 8;
    str = element->data;
    len = *str++;
    x = element->x >> 8;

    for (i = 0; i < len; ++i, ++str) {
        u_char c = *str;

        if (c < ' ') {
            switch (c) {
            case 1:
                charTableOffset = 0;
                break;

            case 2:
                charTableOffset = 112;
                break;

            case 3:
                underline = charTableOffset != 0 ? 18 : 17;
                break;

            case 31:
                --x;
                break;
            }
        } else {
            u_char glyph = charTableOffset + c - ' ';
            short glyphWidth;

            setSprt(sprt);
            setXY0(sprt, x, y);
            setUV0(sprt, (glyph & 0xF) * 16, (glyph >> 4) * 16);
            glyphWidth = _glyphWidths[glyph];
            setWH(sprt, glyphWidth, 16);
            setClut(sprt, 960, 480);
            x += glyphWidth - 1;
            sprt->r0 = sprt->g0 = sprt->b0 = _masterBrightness;
            addPrim(((vs_scratch_t*)0x1F800000)->unk4 + 12, sprt);
            ++sprt;
        }
    }

    if (underline != 0) {
        vs_scratch_t const* scratch = (vs_scratch_t*)0x1F800000;
        POLY_FT4* poly;

        x = 160 - ((element->width + 32) >> 1);

        SetSprt(sprt);
        y += underline;
        setXY0(sprt, x, y);
        setUV0(sprt, 0, 208);
        setWH(sprt, 16, 3);
        setClut(sprt, 960, 480);
        sprt->r0 = sprt->g0 = sprt->b0 = _masterBrightness;
        AddPrim(scratch->unk4 + 12, sprt++);

        poly = (POLY_FT4*)sprt;
        SetPolyFT4(poly);
        x += 16;
        poly->x0 = poly->x2 = x;
        x += element->width;
        poly->y0 = poly->y1 = y;
        poly->y2 = poly->y3 = y + 3;
        poly->u0 = poly->u2 = 8;
        poly->v2 = poly->v3 = 211;
        poly->u1 = poly->u3 = 16;
        poly->v0 = poly->v1 = 208;
        poly->tpage = getTPage(clut4Bit, semiTransparencyHalf, 960, 256);
        poly->clut = getClut(960, 480);
        poly->x1 = poly->x3 = x;
        poly->r0 = poly->g0 = poly->b0 = _masterBrightness;
        AddPrim(scratch->unk4 + 12, poly++);

        sprt = (SPRT*)poly;
        SetSprt(sprt);
        setUV0(sprt, 168, 208);
        setXY0(sprt, x, y);
        setWH(sprt, 16, 3);
        setClut(sprt, 960, 480);
        sprt->r0 = sprt->g0 = sprt->b0 = _masterBrightness;
        AddPrim(scratch->unk4 + 12, sprt++);
    }

    ((vs_scratch_t*)0x1F800000)->unk0 = sprt;
    ((vs_scratch_t*)0x1F800000)->unk0 =
        _insertTpage(getTPage(clut4Bit, semiTransparencyHalf, 960, 256), 3);
}

/**
 * Renders the copyright line.
 */
static void _renderCopyright(_creditsElement* element)
{
    int index;
    void** p = (void**)0x1F800000;
    SPRT* sprt = p[0];

    if (element->state == creditsElementStateStarting) {
        element->x = 100 << 8;
        element->y = 224 << 8;
        element->state = creditsElementStatePhase1;
    }

    element->y += _scrollSpeed;

    if (element->y < -(12 << 8)) {
        element->state = creditsElementStateFinished;
        return;
    }

    SetSprt(sprt);
    setXY0(sprt, element->x >> 8, element->y >> 8);
    setUV0(sprt, 0, 48);
    setWH(sprt, 120, 16);
    setClut(sprt, 960, 64);
    sprt->r0 = sprt->g0 = sprt->b0 = _masterBrightness;

    setaddr(sprt, ((u_long*)p[1])[3]);
    setaddr(p[1] + 12, sprt++);

    index = 0;
    p[index] = sprt;
    p[index] = _insertTpage(getTPage(clut4Bit, semiTransparencyFull, 960, 0), 3);
}

/**
 * Renders the credits background, including 10px letterboxing bars at the top
 * and bottom, along with a 20px fade.
 */
static void _renderBackground(_creditsElement* element __attribute__((unused)))
{
    TILE* tile;
    POLY_G4* poly;
    void** data = (void**)0x1F800000;
    SPRT* sprt = data[0];

    // Draw background proper
    SetSprt(sprt);
    setXY0(sprt, 0, 10);
    setUV0(sprt, 0, 10);
    setWH(sprt, 256, 204);
    setClut(sprt, 780, 255);
    sprt->r0 = sprt->g0 = sprt->b0 = _masterBrightness;
    AddPrim(data[1] + 0x1FFC, sprt++);
    data[0] = sprt;

    sprt = (SPRT*)_insertTpage(getTPage(clut4Bit, semiTransparencyFull, 768, 0), 0x7FF);
    SetSprt(sprt);
    setUV0(sprt, 0, 10);
    setXY0(sprt, 256, 10);
    setWH(sprt, 64, 204);
    setClut(sprt, 780, 255);
    sprt->r0 = sprt->g0 = sprt->b0 = _masterBrightness;
    AddPrim(data[1] + 0x1FFC, sprt++);
    data[0] = sprt;

    // Fade top & bottom
    poly =
        (POLY_G4*)_insertTpage(getTPage(clut4Bit, semiTransparencyFull, 832, 0), 0x7FF);
    SetPolyG4(poly);
    poly->x0 = poly->x2 = 0;
    poly->x1 = poly->x3 = 320;
    poly->y0 = poly->y1 = 10;
    poly->y2 = poly->y3 = 30;
    poly->r0 = poly->r1 = poly->g0 = poly->g1 = poly->b0 = poly->b1 = 255;
    poly->r2 = poly->r3 = poly->g2 = poly->g3 = poly->b2 = poly->b3 = 0;
    setSemiTrans(poly, 1);
    AddPrim(data[1] + 8, poly++);

    SetPolyG4(poly);
    poly->x0 = poly->x2 = 0;
    poly->x1 = poly->x3 = 320;
    poly->y0 = poly->y1 = 194;
    poly->y2 = poly->y3 = 214;
    poly->r0 = poly->r1 = poly->g0 = poly->g1 = poly->b0 = poly->b1 = 0;
    poly->r2 = poly->r3 = poly->g2 = poly->g3 = poly->b2 = poly->b3 = 255;
    setSemiTrans(poly, 1);
    AddPrim(data[1] + 8, poly++);

    // Add letterboxing
    tile = (TILE*)poly;
    SetTile(tile);
    tile->r0 = tile->g0 = tile->b0 = 0;
    setWH(tile, 320, 10);
    setXY0(tile, 0, 0);
    AddPrim(data[1] + 8, tile++);

    // TODO: Top bar added twice, this can probably go
    SetTile(tile);
    tile->r0 = tile->g0 = tile->b0 = 0;
    setWH(tile, 320, 10);
    setXY0(tile, 0, 0);
    AddPrim(data[1] + 8, tile++);

    SetTile(tile);
    tile->r0 = tile->g0 = tile->b0 = 0;
    setWH(tile, 320, 10);
    setXY0(tile, 0, 214);
    AddPrim(data[1] + 8, tile++);
    data[0] = tile;

    data[0] = _insertTpage(getTPage(clut8Bit, semiTransparencySubtract, 0, 0), 2);
}

/**
 * Fades in over 128 steps, used for the start of the credits roll.
 */
static void _screenFadeIn(_creditsElement* element)
{
    if (element->state == creditsElementStateStarting) {
        element->currentStep = 0;
        element->state = creditsElementStatePhase1;
    }

    if (++element->currentStep == 128) {
        _isFadedOut = 0;
        element->state = creditsElementStateFinished;
    }

    _masterBrightness = (u_int)_ease(easeModeLinear, element->currentStep, 128) / 32;
}

/**
 * Fades out over 128 steps, used for the end of the credits roll.
 */
static void _screenFadeOut(_creditsElement* element)
{
    if (element->state == creditsElementStateStarting) {
        element->state = creditsElementStatePhase1;
        element->currentStep = 0;
        _isFadedOut = 1;
    }

    if (++element->currentStep == 128) {
        if (element->width != 0) {
            _creditsComplete = 1;
        }
        element->state = creditsElementStateFinished;
    }

    _masterBrightness =
        128 - ((_ease(easeModeLinear, element->currentStep, 128) << 7) >> 0xC);
}

/**
 * Fades out over 128 steps, with easing. Used when the player skips the credits,
 * unclear why _screenFadeOut couldn't just be used.
 *
 * @param element The credits element being processed.
 * @return The computed result.
 */
static void _renderFadeOut(_creditsElement* element)
{
    void** p = (void**)0x1F800000;
    TILE* tile = p[0];

    if (element->state == creditsElementStateStarting) {
        element->currentStep = 0;
        element->state = creditsElementStatePhase1;
    }

    if (++element->currentStep == 128) {
        _creditsComplete = 1;
    }

    SetTile(tile);
    setSemiTrans(tile, 1);
    tile->r0 = tile->g0 = tile->b0 =
        (_ease(easeModeEaseOut, element->currentStep, 128) * 255) >> 0xC;
    setWH(tile, 320, 240);
    setXY0(tile, 0, 0);

    AddPrim(p[1], tile++);

    p[0] = tile;
    p[0] = _insertTpage(getTPage(clut4Bit, semiTransparencySubtract, 0, 0), 0);
}

static void _streamEndingXa(void);
static void _setDrawEnv(DRAWENV*);
static void _renderCredits(void);
static void _resetElements(void);
static _creditsElement* _addRenderer(void (*arg0)(_creditsElement*));
static void _initEnvironment(void);
static void _updateClearGameStats(void);
static void _checkStreamXaEnd(void);
static void _congratulationsScreen(void);

/**
 * Module entrypoint
 */
void vs_ending_exec(void)
{
    extern u_char const _credits[];
    extern _timData const _creditsFont;
    extern _timData const _illustMerlose;
    extern _timData const _illustDragon;
    extern _timData const _illustSamantha;
    extern _timData const _illustDuane;
    extern _timData const _creditsBg;
    extern _timData const _devCopyright;
    extern _timData const _titleLogo;
    extern _timData const _shugeki;
    extern _timData const _fin;
    extern _timData const _episodeLogo;

    vs_main_CdFile file;
    short i;
    vs_main_CdQueueSlot* slot;

    _initEnvironment();
    SetGeomOffset(160, 112);
    SetGeomScreen(512);
    _setDrawEnv(vs_main_drawEnv);
    _setDrawEnv(&vs_main_drawEnv[1]);

    vs_main_dispEnv[1].isinter = 0;
    vs_main_dispEnv[0].isinter = 0;

    _loadTim(&_creditsFont);
    _loadTim(&_creditsBg);
    _loadTim(&_devCopyright);
    _loadTim(&_shugeki);
    _loadTim(&_titleLogo);
    _loadTim(&_fin);
    _loadTim(&_episodeLogo);
    _loadTim(&_illustSydney);
    _loadTim(&_illustMerlose);
    _loadTim(&_illustDragon);
    _loadTim(&_illustSamantha);
    _loadTim(&_illustDuane);

    for (i = 5; i < 16; ++i) {
        file.lba = _illustLbas[i - 5];
        file.size = _illustSizes[i - 5];
        _compressedIllustBufs[i] = vs_main_allocHeapR(file.size);
        slot = vs_main_allocateCdQueueSlot(&file);
        vs_main_cdEnqueuePriority(slot, _compressedIllustBufs[i]);

        do {
            vs_main_gametimeUpdate(0);
        } while (slot->state != 4);

        vs_main_freeCdQueueSlot(slot);
    }

    _masterBrightness = 0;
    _skipInvoked = 0;

    _resetElements();
    _addRenderer(_renderBackground);
    DrawSync(0);
    SetDispMask(1);

    _creditsBytestreamHead = _credits;
    _scrollSpeed = -128;
    _creditsComplete = 0;
    _textStreamDelay = 0;
    _currentCreditsFrame = 0;
    _isFadedOut = 1;

    _streamEndingXa();
    _renderCredits();
    vs_main_checkStreamXaEnd();
    SetDispMask(0);

    for (i = 5; i < 16; ++i) {
        vs_main_freeHeapR(_compressedIllustBufs[i]);
    }

    _checkStreamXaEnd();
    _updateClearGameStats();
    _congratulationsScreen();
}

/**
 * Initializes the DRAWENV struct.
 */
static void _setDrawEnv(DRAWENV* drawenv)
{
    drawenv->isbg = 1;
    drawenv->dtd = 0;
    drawenv->dfe = 0;
    drawenv->b0 = 0;
    drawenv->g0 = 0;
    drawenv->r0 = 0;
    drawenv->tpage = 0x20;
}

static int _renderElements(void);
static void _parseCreditsScript(void);
static int _decompressTim(void);
static int _drawScreen(u_long*);
static void _beginFrame(void);

/**
 * Runs the credits render loop until the credits end or the user skips.
 */
static void _renderCredits(void)
{
    while (_creditsComplete == 0) {

        _frameStartVsync = VSync(1);

        _beginFrame();
        _parseCreditsScript();
        _renderElements();
        _decompressTim();

        if ((vs_main_buttonsPressed.all & PADstart) && (_skipInvoked == 0)) {
            _addRenderer(_renderFadeOut);
            _skipInvoked = 1;
        }

        _drawScreen(*(u_long**)0x1F800004 + 0x7FF);

        ++_currentCreditsFrame;
    }
}

/**
 * Inserts a texture page into the ordering table at the requested offset.
 */
static void* _insertTpage(int tPage, int otOffset)
{
    void** scratch;
    DR_TPAGE* drTpage;

    scratch = (void**)0x1F800000;
    drTpage = scratch[0];

    SetDrawTPage(drTpage, 0, 1, tPage & 0xFFFF);
    AddPrim(scratch[1] + (otOffset * 4), drTpage++);

    return drTpage;
}

/**
 * Loads a TIM texture into memory.
 */
static void _loadTim(_timData const* tim)
{
    RECT rect;
    _timChunk const* p = &tim->chunk;

    if (tim->flags & 8) {
        rect.x = p->rect.x;
        rect.y = p->rect.y;
        rect.w = p->rect.w;
        rect.h = p->rect.h;
        LoadImage(&rect, (void*)p->data);
        p = (_timChunk const*)((void*)tim + (p->size + 8));
    }

    rect.x = p->rect.x;
    rect.y = p->rect.y;
    rect.w = p->rect.w;
    rect.h = p->rect.h;

    LoadImage(&rect, (void*)p->data);
}

/**
 * Initializes the credits element buffer.
 */
static void _resetElements(void)
{
    short i;
    _creditsElement* element = _creditsElements;

    for (i = 0; i < 32; ++i, ++element) {
        element->state = creditsElementStateInactive;
    }
}

/**
 * Enumerates the credits element buffer and renders active elements
 * @return The count of elements rendered.
 */
static int _renderElements(void)
{
    short i;
    short elementsRendered = 0;
    _creditsElement* element = _creditsElements;

    for (i = 0; i < 32; ++i, ++element) {
        if (element->state < creditsElementStateInactive) {
            element->state = creditsElementStateInactive;
        } else if (element->state > creditsElementStateInactive) {
            ++elementsRendered;
            element->renderer(element);
        }
    }

    return elementsRendered;
}

/**
 * Registers a new credits renderer and assigns it to the next available element slot.
 *
 * @param renderer The callback used to render the credits element.
 * @return The newly activated credits element.
 */
static _creditsElement* _addRenderer(void (*renderer)(_creditsElement*))
{
    extern void SystemError(char, long) __attribute__((noreturn));

    short i;
    _creditsElement* element = &_creditsElements[1];

    for (i = 1; i < 32; ++i, ++element) {
        if (element->state == creditsElementStateInactive) {
            element->renderer = renderer;
            element->state = creditsElementStateStarting;
            element->currentStep = 0;
            return element;
        }
    }

    SystemError('M', 100);
}

/**
 * Replaces the first credits element's renderer if not active. In practice
 * only used by the fade in and fade out ops.
 *
 * @return The active first credits element, or NULL if the slot is still active.
 */
static _creditsElement* _replaceMainRenderer(void (*renderer)(_creditsElement*))
{
    if (_creditsElements[0].state == creditsElementStateInactive) {
        _creditsElements[0].renderer = renderer;
        _creditsElements[0].state = creditsElementStateStarting;
        _creditsElements[0].currentStep = 0;
        return &_creditsElements[0];
    }

    return NULL;
}

/**
 * Parses the credits script. Up to 32 elements can be batch processed,
 * less those currently active. Wait ops serve a dual purpose of allowing
 * the function to yield to the parent, so the queue can be processed.
 */
static void _parseCreditsScript(void)
{
    enum opcodes {
        waitOp = 1,
        textOp,
        enableBgOp,
        specialOp,
        copyrightSpecialOp = 0,
        titleSpecialOp,
        finSpecialOp,
        episodeSpecialOp,
        fadeInOp = 5,
        fadeOutOp,
        freezeOp,
        setTimerOp,
        endStreamOp = 0xFF,
    };

    if (_textStreamDelay != 0) {
        --_textStreamDelay;
        return;
    }

    while (1) {
        int op;
        int delay;
        u_char const* bytestream = _creditsBytestreamHead;

        switch (bytestream[0]) {

        // Wait: u8 duration
        case waitOp:
            _creditsBytestreamHead = bytestream + 1;
            delay = bytestream[1] * 2;
            _creditsBytestreamHead = bytestream + 2;
            _textStreamDelay = delay;
            return;

        // Render text: u8 len
        case textOp:
            _creditsBytestreamHead = bytestream + 1;
            _addRenderer(_renderText)->data = _creditsBytestreamHead;
            _creditsBytestreamHead += _creditsBytestreamHead[0] + 1;
            break;

        // Enable background illustrations
        case enableBgOp:
            _creditsBytestreamHead = bytestream + 1;
            _addRenderer(_renderllustration)->illustId = 0;
            break;

        // Render special: u8 secondary op
        case specialOp:
            _creditsBytestreamHead = bytestream + 1;
            op = bytestream[1];
            _creditsBytestreamHead = bytestream + 2;

            switch (op) {
            case copyrightSpecialOp:
                _addRenderer(_renderCopyright);
                break;

            case titleSpecialOp:
                _addRenderer(_renderVagrantStory);
                break;

            case finSpecialOp:
                _addRenderer(_renderFin);
                break;

            case episodeSpecialOp:
                _addRenderer(_renderPhantomPain);
                break;
            }
            break;

        // Fade in
        case fadeInOp:
            _creditsBytestreamHead = bytestream + 1;
            _replaceMainRenderer(_screenFadeIn);
            break;

        // Fade out
        case fadeOutOp:
            _creditsBytestreamHead = bytestream + 1;
            _replaceMainRenderer(_screenFadeOut)->width = 0;
            break;

        // Freeze scrolling
        case freezeOp:
            _creditsBytestreamHead = bytestream + 1;
            _scrollSpeed = 0;
            break;

        // Set illustration timer: u8 illustration id, u16 duration
        case setTimerOp:
            *(_illustrationTimers + bytestream[1]) =
                (bytestream[2] + (bytestream[3] << 8)) - 160;
            _creditsBytestreamHead = bytestream + 4;
            break;

        // End of stream
        case endStreamOp:
            _creditsComplete = 1;
            return;

        default:
            return;
        }
    }
}

/**
 * Applies the selected easing curve.
 */
static int _ease(short mode, short currentStep, short totalSteps)
{
    switch (mode) {
    case easeModeLinear:
        return (currentStep * ONE) / totalSteps;
    case easeModeEaseOut:
        return rsin((currentStep * (ONE / 4)) / totalSteps);
    case easeModeEaseInOut:
        return (rcos(((currentStep * (ONE / 2)) / totalSteps) + (ONE / 2)) + ONE) >> 1;
    case easeModeEaseIn:
        return rsin(((currentStep * (ONE / 4)) / totalSteps) - (ONE / 4)) + ONE;
    }
}

/**
 * Initializes the TIM decompression work buffer for the active illustration.
 */
static void _initTimDecompress(_timData* targetBuf, void const* compressedData)
{
    _compressionState = decompressionStateReady;
    _currentCompressedIllust = compressedData;
    _currentDecompressedIllust = targetBuf;
}

/**
 * Decompresses the current TIM image data into the target buffer.
 * @return 0 if there is no work, or if 200 frames have passed
 * since the render loop started. 1 if the content has just finished
 * decompression.
 */
static int _decompressTim(void)
{
    enum opcodes { singleByteRle = 0x7D, doubleByteRle, endOfStream, backReferenceFlag };

    static u_char const* backReference;
    static u_char const* compressedStream;
    static u_char* decompressedStream;
    static u_char rleByte0;
    static u_char rleByte1;
    static u_short byteCount;
    static u_short backReferencePos;
    static u_char _[6] __attribute__((unused));

    short i;

    if (_compressionState == decompressionStateIdle) {
        return 0;
    }

    if (_compressionState == decompressionStateReady) {
        _compressionState = decompressionStateActive;
        compressedStream = _currentCompressedIllust;
        decompressedStream = _currentDecompressedIllust;
    }

    while (1) {
        u_char op;

        if (VSync(1) - _frameStartVsync > 200) {
            return 0;
        }

        op = *compressedStream;

        if (!(op & backReferenceFlag)) {
            if (op == endOfStream) {
                _compressionState = decompressionStateIdle;
                return 1;
            }

            if (op == singleByteRle) {
                ++compressedStream;
                byteCount = *compressedStream++;
                rleByte0 = *compressedStream++;

                for (i = 0; i <= byteCount; ++i) {
                    *decompressedStream++ = rleByte0;
                }
            } else if (op == doubleByteRle) {
                ++compressedStream;
                byteCount = *compressedStream++;
                rleByte0 = *compressedStream++;
                rleByte1 = *compressedStream++;

                for (i = 0; i <= byteCount; ++i) {
                    *decompressedStream++ = rleByte0;
                    *decompressedStream++ = rleByte1;
                }
            } else {
                byteCount = *compressedStream++;

                for (i = 0; i <= byteCount; ++i) {
                    *decompressedStream++ = *compressedStream++;
                }
            }
        } else {
            byteCount = ((op >> 4) & 7) + 3;
            backReferencePos = ((compressedStream[0] & 0xF) << 8) + compressedStream[1];
            compressedStream += 2;
            backReference = decompressedStream - backReferencePos - 1;

            for (i = 0; i < byteCount; ++i) {
                *decompressedStream++ = *backReference++;
            }

            while (*compressedStream == 124) {
                backReference = decompressedStream - backReferencePos - 1;
                ++compressedStream;

                for (i = 0; i < byteCount; ++i) {
                    *decompressedStream++ = *backReference++;
                }
            }
        }
    }
}

#pragma region dead_code

/**
 * Renders a string using the loaded debug font.
 */
__attribute__((unused)) static void _renderDebugString(
    short x, short y, int clut, char const* string)
{
    int c;
    SPRT_8* sprt = *(void**)0x1F800000;

    for (c = *string; c != 0; c = *++string, x += 7) {
        int cTemp = c - ' ';
        u_char c_2 = cTemp;

        if (((cTemp & 0xFF) < 96u) && (c_2 != 0)) {
            u_long** ot;

            if (c_2 == ('\\' - ' ')) {
                c_2 = 15;
            }

            if (c_2 > ('`' - ' ')) {
                c_2 -= 32;
            }

            setSprt8(sprt);
            setShadeTex(sprt, 1);
            setXY0(sprt, x, y);
            setUV0(sprt, (c_2 & 0xF) * 8, (c_2 & 0xF0) / 2);
            setClut(sprt, 960, clut + 32);

            ot = (u_long**)0x1F800000;
            setaddr(sprt, *ot[1] & 0xFFFFFF);
            setaddr(ot[1], sprt);

            ++sprt;
        }
    }

    *(void**)0x1F800000 = sprt;
    *(void**)0x1F800000 = _insertTpage(getTPage(0, 0, 960, 0), 0);
}

#pragma endregion

/**
 * Initializes the video mode and projection parameters for the credits.
 */
static void _initVideo(int w, int h, int projectionDistance, int r, int g, int b)
{
    RECT rect;
    int fbHeight;

    rect = (RECT) { 0, 0, 1024, 512 };

    SetDispMask(0);
    SetGeomOffset(w / 2, h / 2);
    SetGeomScreen(projectionDistance);

    fbHeight = h - 16;

    SetDefDrawEnv(vs_main_drawEnv, 0, 0, w, fbHeight);
    SetDefDispEnv(vs_main_dispEnv, w, 0, w, fbHeight);
    SetDefDrawEnv(&vs_main_drawEnv[1], w, 0, w, fbHeight);
    SetDefDispEnv(&vs_main_dispEnv[1], 0, 0, w, fbHeight);

    setRECT(&vs_main_dispEnv[0].screen, 0, 8, 256, 224);
    setRECT(&vs_main_dispEnv[1].screen, 0, 8, 256, 224);

    D_8005DFD4 = 0;
    D_8005DFD8 = 0;
    vs_main_screenWidth = w;
    vs_main_screenHeight = fbHeight;
    vs_main_drawEnv[1].dtd = 0;
    vs_main_drawEnv[0].dtd = 0;
    vs_main_drawEnv[1].isbg = 1;
    vs_main_drawEnv[0].isbg = 1;
    setRGB0(&vs_main_drawEnv[0], r, g, b);
    setRGB0(&vs_main_drawEnv[1], r, g, b);

    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    FntLoad(960, 0);
    SetDumpFnt(FntOpen(40, 16, 512, 256, 0, 512));
    PutDispEnv(&vs_main_dispEnv[vs_main_frameBuf]);
    PutDrawEnv(&vs_main_drawEnv[vs_main_frameBuf]);

    vs_main_frameDuration = 0;
}

/**
 * Draws the current screen and synchronizes the frame.
 *
 * @param ot The ordering table used by the draw pass.
 * @return Result of VSync(0).
 */
static int _drawScreen(u_long* ot)
{
    int _[2] __attribute__((unused));
    int vSync;

    vs_main_frameBuf = vs_main_frameBuf == 0;

    DrawSync(0);

    vSync = vs_main_gametimeUpdate(0);

    PutDispEnv(&vs_main_dispEnv[vs_main_frameBuf]);
    PutDrawEnv(&vs_main_drawEnv[vs_main_frameBuf]);
    DrawOTag(ot);

    ++vs_main_frameDuration;

    return vSync;
}

static void _updateTitles(void);

/**
 * Refreshes stats relevant for the completion screen.
 */
static void _do_updateClearGameStats(void)
{
    int i;

    if (vs_main_scoredata.completionTimeMinutes == 0) {
        vs_main_scoredata.clearCount = vs_main_stateFlags.clearCount;
        vs_main_scoredata.completionTimeMinutes =
            (vs_main_gametime.t.h * 60) + vs_main_gametime.t.m;
    } else {
        u_int minutes = (vs_main_gametime.t.h * 60) + vs_main_gametime.t.m;
        if (minutes < vs_main_scoredata.completionTimeMinutes) {
            vs_main_scoredata.completionTimeMinutes = minutes;
            vs_main_scoredata.clearCount = vs_main_stateFlags.clearCount;
        }
    }

    _updateTitles();
    vs_main_bzero(&vs_main_mapStatus, sizeof vs_main_mapStatus);

    for (i = 16; i < 1088; ++i) {
        ((u_char*)&vs_main_stateFlags)[i] = 0;
    }

    if (vs_main_stateFlags.difficulty != 0) {
        vs_main_stateFlags.normalModeCleared = 1;
    } else {
        vs_main_stateFlags.difficulty = 1;
    }

    if (vs_main_stateFlags.clearCount < 99) {
        ++vs_main_stateFlags.clearCount;
    }

    D_80061068.zndId = 1;
    D_80061068.mpdId = 0;
}

/**
 * Initializes the credits environment and allocates OTs.
 */
static void _initEnvironment(void)
{
    _initVideo(320, 240, 512, 0, 0, 0);
    vs_main_initHeap((vs_main_HeapHeader*)0x8010C000, 0xF2000);
    D_8005E0C0[0] = vs_main_allocHeap(0x20000);
    D_8005E0C0[1] = vs_main_allocHeap(0x20000);
    D_80055C80[0] = vs_main_allocHeap(0x2088);
    D_80055C80[1] = vs_main_allocHeap(0x2088);
}

/**
 * Just calls _do_updateClearGameStats
 */
static void _updateClearGameStats(void) { _do_updateClearGameStats(); }

/**
 * Sets the scratch OTs and draw state.
 * @return The computed result.
 */
static void _beginFrame(void)
{
    void* temp_a0;

    vs_main_processPadState();
    temp_a0 = D_80055C80[vs_main_frameBuf];
    vs_scratch.unk8 = temp_a0 + 8;
    vs_scratch.unk4 = temp_a0 + 0x48;
    ClearOTagR((u_long*)temp_a0, 0x822);
    vs_scratch.unk0 = D_8005E0C0[vs_main_frameBuf];
}

/**
 * Starts streaming the ending music track.
 */
static void _streamEndingXa(void)
{
    vs_main_streamXa(VS_ENDING_XA_LBA, 0x7FFF); // Partial playback?
}

/**
 * Checks whether the ending music stream has finished.
 */
static void _checkStreamXaEnd(void) { vs_main_checkStreamXaEnd(); }

static int _countableRooms[] = { 0xFF3FFE00, 0xBEBFDFF7, 0xFFFFFDE8, 0xDFFFFE6F,
    0xFFFFF807, 0xFFFBE87D, 0xF007FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFDFFFFF,
    0xFFFFFFFF, 0x0EFFFFFF, 0x00000000, 0x00000000, 0x00000000 };

/**
 * Refreshes the titles earned by the player.
 */
static void _updateTitles(void)
{
    int i;
    int j;
    u_int count;

    if (vs_main_scoredata.completionTimeMinutes < 600) {
        vs_main_scoredata.titles |= 2;
    }

    for (i = 184; i < 224; ++i) {
        if (!vs_main_actions[i].unlocked) {
            break;
        }
    }

    if (i == 224) {
        vs_main_scoredata.titles |= 1 << 14;
    }

    for (i = 22; i < 54; ++i) {
        if ((i != 33) && (i != 36) && (i != 38) && (i != 39)
            && !vs_main_actions[i].unlocked) {
            break;
        }
    }

    if (i == 54) {
        vs_main_scoredata.titles |= 1 << 15;
    }

    if (vs_main_settings.currentGameSaveCount == 0) {
        vs_main_scoredata.titles |= 1 << 16;
    }

    if (vs_main_stateFlags.magicUsed == 0) {
        vs_main_scoredata.titles |= 1 << 17;
    }

    if (vs_main_stateFlags.battleAbilitiesUsed == 0) {
        vs_main_scoredata.titles |= 1 << 18;
    }

    if (vs_main_stateFlags.breakArtsUsed == 0) {
        vs_main_scoredata.titles |= 1 << 19;
    }

    count = 0;

    for (i = 0; i < 16; ++i) {
        int t1 = 1;
        for (j = 0; j < 32; ++j) {
            if (vs_main_mapStatus.roomFlags[i] & _countableRooms[i] & (t1 << j)) {
                ++count;
            }
        }
    }

    if (vs_main_scoredata.mapCompletion < count) {
        vs_main_scoredata.mapCompletion = count;
    }

    count = 0;

    for (i = 0; i < 64; ++i) {
        if (vs_main_stateFlags.chestsOpened[i] != 0) {
            ++count;
        }
    }

    if (vs_main_scoredata.openedChestCount < count) {
        vs_main_scoredata.openedChestCount = count;
    }

    if (vs_main_stateFlags.damascusGolemDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 4;
    }

    if (vs_main_stateFlags.damascusCrabDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 5;
    }

    if (vs_main_stateFlags.ravanaDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 6;
    }

    if (vs_main_stateFlags.dragonZombieDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 7;
    }

    if (vs_main_stateFlags.deathAndOgreZombieDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 8;
    }

    if (vs_main_stateFlags.asuraDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 9;
    }

    if (vs_main_stateFlags.goldKeyObtained != 0) {
        vs_main_scoredata.titles |= 1 << 12;
    }

    if (vs_main_stateFlags.chestKeyObtained != 0) {
        vs_main_scoredata.titles |= 1 << 13;
    }
}

static vs_main_CdQueueSlot* cdSlot;
static void* timData;
static u_int _rank;
static int _clearCount;
static u_int _score;
static u_int _mapCompletion;
static u_int _onScreenMapCompletion;
static u_int _onScreenScore;
static int _submenuState;
static int _screenTimer;
static int _congratulationsAnimSkip;

static int _initCongratulationsScreen(void);
static int _renderCongratulationsScreen(void);
static void _renderCongratulations(int arg0, int arg1, int arg2);

/**
 * Sets up and runs the congratulations screen.
 */
static void _congratulationsScreen(void)
{
    int done;

    _submenuState = 0;
    SetDispMask(1);

    do {
        _beginFrame();
        done = _initCongratulationsScreen();
        _drawScreen(*(u_long**)0x1F800004 + 0x7FF);
    } while (done == 0);

    do {
        _beginFrame();
        done = _renderCongratulationsScreen();
        VSync(0);
        _drawScreen(*(u_long**)0x1F800004 + 0x7FF);
    } while (done == 0);
}

static void _parseTim(u_int* arg0, TIM_IMAGE* arg1);
static void _determineRank(void);
static void _updateScore(void);

/**
 * Initializes the congratulations screen and score data.
 * @return 1 when complete, 0 otherwise.
 */
static int _initCongratulationsScreen(void)
{
    static const vs_main_CdFile endScrDisFiles[] = {
        { VS_END_DIS_LBA, VS_END_DIS_SIZE },
        { VS_ENDSCR00_DIS_LBA, VS_ENDSCR00_DIS_SIZE },
        { VS_ENDSCR01_DIS_LBA, VS_ENDSCR01_DIS_SIZE },
        { VS_ENDSCR02_DIS_LBA, VS_ENDSCR02_DIS_SIZE },
        { VS_ENDSCR03_DIS_LBA, VS_ENDSCR03_DIS_SIZE },
        { VS_ENDSCR04_DIS_LBA, VS_ENDSCR04_DIS_SIZE },
        { VS_ENDSCR05_DIS_LBA, VS_ENDSCR05_DIS_SIZE },
        { VS_ENDSCR06_DIS_LBA, VS_ENDSCR06_DIS_SIZE },
        { VS_ENDSCR07_DIS_LBA, VS_ENDSCR07_DIS_SIZE },
        { VS_ENDSCR08_DIS_LBA, VS_ENDSCR08_DIS_SIZE },
        { VS_ENDSCR09_DIS_LBA, VS_ENDSCR09_DIS_SIZE },
        { VS_ENDSCR10_DIS_LBA, VS_ENDSCR10_DIS_SIZE },
        { VS_ENDSCR11_DIS_LBA, VS_ENDSCR11_DIS_SIZE },
        { VS_ENDSCR12_DIS_LBA, VS_ENDSCR12_DIS_SIZE },
        { VS_ENDSCR13_DIS_LBA, VS_ENDSCR13_DIS_SIZE },
        { VS_ENDSCR14_DIS_LBA, VS_ENDSCR14_DIS_SIZE },
        { VS_ENDSCR15_DIS_LBA, VS_ENDSCR15_DIS_SIZE },
    };

    TIM_IMAGE tim;
    int i;

    if (_submenuState == 0) {

        timData = vs_main_allocHeapR(endScrDisFiles[0].size);
        cdSlot = vs_main_allocateCdQueueSlot(&endScrDisFiles[0]);

        vs_main_cdEnqueue(cdSlot, timData);

        ++_submenuState;

    } else if (_submenuState == 1) {

        if (cdSlot->state != vs_main_CdQueueStateLoaded) {
            return 0;
        }

        for (i = 0; i < 3; ++i) {

            _parseTim(timData + i * 0x8220, &tim);

            if (tim.paddr != NULL) {
                tim.prect->x = 832 + i * 64;
                tim.prect->y = 256;
                tim.prect->h = 255;
                LoadImage(tim.prect, tim.paddr);
            }

            if (i == 0) {
                if (tim.caddr != NULL) {
                    tim.crect->x = 768;
                    tim.crect->y = 511;
                    tim.crect->w = 128;
                    tim.crect->h = 1;
                    *tim.caddr = 0;
                    LoadImage(tim.crect, tim.caddr);
                }
            }
        }

        vs_main_freeCdQueueSlot(cdSlot);
        ++_submenuState;

    } else if (_submenuState == 2) {
        u_int mapCompletion;
        u_int chestsOpened;

        vs_main_freeHeapR(timData);

        mapCompletion = 0;
        _onScreenMapCompletion = 0;
        _onScreenScore = 0;
        _screenTimer = 0;
        _congratulationsAnimSkip = 0;
        _clearCount = vs_main_stateFlags.clearCount;

        for (i = 0; i < 16; ++i) {
            int flag;
            for (flag = 0; flag < 32; ++flag) {
                int v = 1;
                if (vs_main_mapStatus.roomFlags[i] & _countableRooms[i] & (v << flag)) {
                    ++mapCompletion;
                }
            }
        }

        chestsOpened = 0;

        for (i = 0; i < 64; ++i) {
            if (vs_main_stateFlags.chestsOpened[i] != 0) {
                ++chestsOpened;
            }
        }

        if (vs_main_scoredata.mapCompletion < mapCompletion) {
            vs_main_scoredata.mapCompletion = mapCompletion;
        }

        if (vs_main_scoredata.openedChestCount < chestsOpened) {
            vs_main_scoredata.openedChestCount = chestsOpened;
        }

        _mapCompletion = (vs_main_scoredata.mapCompletion * 100) / 361;

        _updateScore();
        _determineRank();

        timData = vs_main_allocHeapR(endScrDisFiles[_rank + 1].size);
        cdSlot = vs_main_allocateCdQueueSlot(&endScrDisFiles[_rank + 1]);
        vs_main_cdEnqueue(cdSlot, timData);
        ++_submenuState;

    } else if (_submenuState == 3) {

        if (cdSlot->state != 4) {
            return 0;
        }

        _parseTim(timData, &tim);

        if (tim.paddr != NULL) {
            tim.prect->x = 0;
            tim.prect->y = 256;
            LoadImage(tim.prect, tim.paddr);
        }

        vs_main_freeCdQueueSlot(cdSlot);

        ++_submenuState;

    } else {
        _submenuState = 0;
        vs_main_freeHeapR(timData);

        return 1;
    }

    return 0;
}

static void _fadeIn(int);
static void _renderScore(int, int, int, int);
static void _renderIncrementalScore(int, int, int, int);
static void _renderMapCompletion(int arg0, int arg1, int arg2, int colors);
static void _renderIncrementalMapCompletion(int, int, int, int);
static void _renderRiskbreakerRankHeader(int arg0, int arg1, int arg2);
static void _renderRiskbreakerRank(int, int, int);

/**
 * Renders the congratulations screen.
 * @return 1 when all animations are complete, 0 otherwise.
 */
static int _renderCongratulationsScreen(void)
{
    if (_congratulationsAnimSkip == 0) {

        if (_screenTimer == 208) {
            vs_main_playSfxDefault(126, 119);
            vs_main_playSfxDefault(126, 120);
        }

        _fadeIn(_screenTimer);
        _renderCongratulations(160, 40, _screenTimer);
        _renderIncrementalScore(160, 80, _screenTimer - 32, _congratulationsAnimSkip);
        _renderIncrementalMapCompletion(
            160, 102, _screenTimer - 112, _congratulationsAnimSkip);
        _renderRiskbreakerRankHeader(160, 138, _screenTimer - 192);
        _renderRiskbreakerRank(160, 154, _screenTimer - 208);

        if (_screenTimer > 4096) {
            _screenTimer = 4096;
        }

        if (vs_main_buttonsPressed.all != 0) {
            _congratulationsAnimSkip = 1;
            _screenTimer = 0;
        }

    } else {

        _fadeIn(8 - _screenTimer);
        _renderCongratulations(160, 40, 8 - _screenTimer);
        _renderScore(160, 80, 8 - _screenTimer, 3);
        _renderMapCompletion(160, 102, 8 - _screenTimer, 3);
        _renderRiskbreakerRankHeader(160, 138, 8 - _screenTimer);
        _renderRiskbreakerRank(160, 154, 8 - _screenTimer);

        if (_screenTimer >= 8) {
            return 1;
        }
    }

    ++_screenTimer;
    return 0;
}

#define CLAMP_ANIMATION_TIMER(timer) \
    if (timer < 0) {                 \
        timer = 0;                   \
    }                                \
    if (timer > 64) {                \
        timer = 64;                  \
    }

/**
 * Fades the background in.
 */
static void _fadeIn(int timer)
{
    int i;
    int brightness;
    POLY_FT4* poly;

    CLAMP_ANIMATION_TIMER(timer)

    brightness = timer * 2;

    if (timer <= 0) {
        return;
    }

    poly = *(void**)0x1F800000;

    for (i = 0; i < 5; ++i) {
        setPolyFT4(poly);
        setXY4(poly, i * 64, 8, 64 + i * 64, 8, i * 64, 232, 64 + i * 64, 232);
        setUV4(poly, 0, 0, 64, 0, 0, 224, 64, 224);
        setRGB0(poly, brightness, brightness, brightness);
        setClut(poly, 0, 0);
        poly->tpage = (i + 16) | getTPage(3, 0, 0, 0);
        AddPrim(*((void**)0x1F800004) + 0x1FF8, poly++);
    }

    *(void**)0x1F800000 = poly;
}

enum disIndices {
    disIndexRank0Comma = 10,
    disIndexRank0RiskbreakerRank = 12,
    disIndexRank0Score = 18,
    disIndexRank0Percent,
    disIndexRank0Pts,
    disIndexRank0MapCompleted,
    disIndexRank0Congratulations,
    disIndexRank0Colon = 26,
    disIndexRank1Grand,
    disIndexRank1Master,
    disIndexRank1Breaker,
    disIndexRank1Paladin,
    disIndexRank1Gladiator,
    disIndexRank1Raging,
    disIndexRank1Berserker,
    disIndexRank1Radiant,
    disIndexRank1Couragous,
    disIndexRank1Adventurer,
    disIndexRank1Knight,
    disIndexRank1Archer = 39,
    disIndexRank1DareDevil = 42,
    disIndexRank1Blade = 44,
    disIndexRank2Of = 48,
    disIndexRank2Mystic = 55,
    disIndexRank2Wanderer,
    disIndexRank2Destroyer,
    disIndexRank2Gladiator,
    disIndexRank2Spectrebane,
    disIndexRank2Normal,
    disIndexRank2Phantom,
    disIndexRank2Fighter,
    disIndexRank2Demon,
    disIndexRank2Eater,
    disIndexRank2Agent,
    disIndexRank2Dragon,
    disIndexRank2Slayer,
    disIndexRank2Cartographer
};

static _texture_t _disMap[] = {
    { 0, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 14, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 28, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 42, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 56, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 70, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 84, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 98, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 112, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 126, 0, 14, 20, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 240, 16, 4, 8, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 148, 4, 60, 16, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 4, 24, 156, 16, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 4, 44, 38, 18, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 50, 44, 44, 18, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 98, 44, 38, 18, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 144, 44, 30, 18, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 182, 44, 34, 18, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 0, 64, 66, 22, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 104, 70, 12, 12, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 118, 70, 28, 14, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 0, 88, 170, 22, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 8, 118, 152, 24, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 8, 150, 152, 24, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 200, 82, 10, 10, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 216, 82, 8, 6, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 232, 82, 6, 12, getTPage(0, 0, 832, 256), vs_getUV(240, 127) },
    { 30, 12, 66, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 98, 12, 70, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 170, 12, 76, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 70, 36, 72, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 144, 36, 102, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 78, 60, 70, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 152, 60, 94, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 38, 84, 80, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 118, 84, 122, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 46, 108, 118, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 166, 108, 74, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 78, 132, 94, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 172, 132, 74, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 82, 156, 86, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 170, 156, 76, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 60, 180, 96, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 158, 180, 88, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 120, 204, 54, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 178, 204, 68, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 56, 228, 114, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 172, 228, 72, 24, getTPage(0, 0, 896, 256), vs_getUV(240, 127) },
    { 110, 12, 26, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 138, 12, 54, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 194, 12, 52, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 64, 36, 88, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 182, 36, 64, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 90, 60, 90, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 184, 60, 62, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 82, 84, 66, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 148, 84, 98, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 42, 108, 102, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 144, 108, 102, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 50, 132, 116, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 168, 132, 78, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 74, 156, 92, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 166, 156, 80, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 58, 180, 68, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 130, 180, 52, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 184, 180, 62, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 106, 204, 78, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 188, 204, 58, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
    { 106, 228, 140, 24, getTPage(0, 0, 960, 256), vs_getUV(240, 127) },
};

static u_char _riskbreakerRanks[][4] = { { 3, disIndexRank1Grand, disIndexRank1Master,
                                             disIndexRank1Breaker },
    { 2, disIndexRank1Grand, disIndexRank1Paladin },
    { 2, disIndexRank1Radiant, disIndexRank1Knight },
    { 2, disIndexRank1Raging, disIndexRank1Berserker },
    { 2, disIndexRank2Dragon, disIndexRank2Slayer },
    { 2, disIndexRank1Couragous, disIndexRank1Adventurer },
    { 2, disIndexRank1Master, disIndexRank1Gladiator },
    { 2, disIndexRank1Blade, disIndexRank1Master },
    { 2, disIndexRank2Mystic, disIndexRank2Wanderer }, { 1, disIndexRank1Paladin },
    { 1, disIndexRank2Spectrebane }, { 1, disIndexRank2Destroyer },
    { 1, disIndexRank1Berserker }, { 1, disIndexRank1DareDevil },
    { 1, disIndexRank1Gladiator }, { 2, disIndexRank2Normal, disIndexRank2Agent } };

/**
 * Renders the "Mission Complete!" text.
 */
static void _renderCongratulations(int x, int y, int timer)
{
    static CVECTOR colors[] = {
        { 128, 96, 64 },
        { 200, 180, 160 },
        { 128, 96, 64 },
    };

    CLAMP_ANIMATION_TIMER(timer)

    if (timer > 0) {
        colors[0].cd = timer;
        colors[1].cd = timer;
        x = x
          - ((_disMap[disIndexRank0Congratulations].w
                 + _disMap[disIndexRank0Congratulations + 1].w)
              >> 1);
        _renderTexturePopIn(x, y, disIndexRank0Congratulations, colors);
        _renderTexturePopIn(x + _disMap[disIndexRank0Congratulations].w, y,
            disIndexRank0Congratulations + 1, &colors[1]);
    }
}

/**
 * Renders the final score display without counting up.
 */
static void _renderScore(int x, int y, int timer, int _ __attribute__((unused)))
{
    static CVECTOR colors[] = {
        { 100, 180, 220 },
        { 100, 180, 220 },
    };

    char buf[16];
    int i;
    int textW;

    CLAMP_ANIMATION_TIMER(timer)

    if (timer <= 0) {
        return;
    }

    colors[0].cd = timer;

    sprintf(buf, "%09d", _score);

    textW = _disMap[disIndexRank0Score].w + _disMap[disIndexRank0Colon].w
          + _disMap[disIndexRank0Pts].w;
    x -= (_disMap[disIndexRank0Comma].w * 2 + textW + 116) >> 1;

    _renderTextureFadeInTint(x, y, disIndexRank0Score, colors);

    x += _disMap[disIndexRank0Score].w;

    _renderTextureFadeInTint(x, y + 7, disIndexRank0Colon, colors);

    x += _disMap[disIndexRank0Colon].w + 2;

    for (i = 0; i < 9; ++i) {
        _renderTextureFadeInTint(x, y + 3, buf[i] - '0', colors);
        x += 12;
        if ((i == 2) || (i == 5)) {
            _renderTextureFadeInTint(x, y + 14, disIndexRank0Comma, colors);
            x += _disMap[disIndexRank0Comma].w + 3;
        }
    }

    _renderTextureFadeInTint(x, y + 8, disIndexRank0Pts, colors);
}

static int _incrementingScore;

/**
 * Renders the final score, animating up from 0.
 */
static void _renderIncrementalScore(
    int x, int y, int timer, int _ __attribute__((unused)))
{
    static CVECTOR colors[] = {
        { 100, 180, 220 },
        { 100, 180, 220 },
    };

    char buf[16];
    int maxX;
    int i;
    int textW;

    CLAMP_ANIMATION_TIMER(timer)

    if (timer <= 0) {
        return;
    }

    maxX = x + (timer * 8);

    if (_score != 0 && timer >= 32) {

        if (_onScreenScore == 0) {
            _incrementingScore = 1;
            vs_main_playSfxDefault(126, 114);
        }

        if ((_onScreenScore == _score) && (_incrementingScore != 0)) {
            _incrementingScore = 0;
            func_80045D64(126, 114);
            vs_main_playSfxDefault(126, 115);
        }
    }

    if (timer >= 32) {
        _onScreenScore = (_score >> 5) * (timer - 32);
    }

    if (timer == 64) {
        _onScreenScore = _score;
    }

    sprintf(buf, "%09d", _onScreenScore);

    textW = _disMap[disIndexRank0Score].w + _disMap[disIndexRank0Colon].w
          + _disMap[disIndexRank0Pts].w;
    x -= (_disMap[disIndexRank0Comma].w * 2 + textW + 116) >> 1;

    _renderTextureWipe(x, y, disIndexRank0Score, colors, maxX);

    x += _disMap[disIndexRank0Score].w;

    _renderTextureWipe(x, y + 7, disIndexRank0Colon, colors, maxX);

    x += _disMap[disIndexRank0Colon].w + 2;

    for (i = 0; i < 9; ++i) {
        _renderTextureWipe(x, y + 3, buf[i] - '0', colors, maxX);
        x += 12;

        if ((i == 2) || (i == 5)) {
            _renderTextureWipe(x, y + 14, disIndexRank0Comma, colors, maxX);
            x += 3 + _disMap[disIndexRank0Comma].w;
        }
    }

    _renderTextureWipe(x, y + 8, disIndexRank0Pts, colors, maxX);
}

/**
 * Renders the final map completion percentage.
 */
static void _renderMapCompletion(int x, int y, int timer, int _ __attribute__((unused)))
{
    static CVECTOR colors[] = {
        { 100, 180, 220 },
        { 100, 180, 220 },
    };

    char buf[2];
    int i;

    CLAMP_ANIMATION_TIMER(timer)

    if (timer > 0) {

        colors[0].cd = timer;

        sprintf(buf, "%03d", _mapCompletion);

        x -= ((_disMap[disIndexRank0MapCompleted].w + _disMap[disIndexRank0Colon].w
                  + _disMap[disIndexRank0Percent].w + 38)
              >> 1);

        _renderTextureFadeInTint(x, y, disIndexRank0MapCompleted, colors);

        x += _disMap[disIndexRank0MapCompleted].w;

        _renderTextureFadeInTint(x, y + 7, disIndexRank0Colon, colors);

        x += _disMap[disIndexRank0Colon].w + 2;

        for (i = 0; i < 3; ++i) {
            _renderTextureFadeInTint(x, y + 3, buf[i] - '0', colors);
            x += 12;
        }

        _renderTextureFadeInTint(x, y + 8, disIndexRank0Percent, colors);
    }
}

static int _incrementingMapCompletion;

/**
 * Renders the final map completion percentage, animating up from 0.
 */
static void _renderIncrementalMapCompletion(
    int x, int y, int timer, int _ __attribute__((unused)))
{
    static CVECTOR colors[] = {
        { 100, 180, 220 },
        { 100, 180, 220 },
    };

    char buf[2];
    int temp_s4;
    int i;

    CLAMP_ANIMATION_TIMER(timer)

    if (timer <= 0) {
        return;
    }

    temp_s4 = x + timer * 8;

    if (_mapCompletion != 0 && timer >= 32) {

        if (_onScreenMapCompletion == 0) {
            _incrementingMapCompletion = 1;
            vs_main_playSfxDefault(126, 114);
        }

        if ((_onScreenMapCompletion == _mapCompletion)
            && (_incrementingMapCompletion != 0)) {
            _incrementingMapCompletion = 0;
            func_80045D64(126, 114);
            vs_main_playSfxDefault(126, 115);
        }
    }

    if (timer >= 32) {
        if (_mapCompletion >= 32u) {
            _onScreenMapCompletion = (u_int)(_mapCompletion * (timer - 32)) >> 5;
        } else if (_onScreenMapCompletion < _mapCompletion) {
            _onScreenMapCompletion += 1;
        }
    }

    sprintf(buf, "%03d", _onScreenMapCompletion);

    x -= ((_disMap[disIndexRank0MapCompleted].w + _disMap[disIndexRank0Colon].w
              + _disMap[disIndexRank0Percent].w + 38)
          >> 1);

    _renderTextureWipe(x, y, disIndexRank0MapCompleted, colors, temp_s4);

    x += _disMap[disIndexRank0MapCompleted].w;

    _renderTextureWipe(x, y + 7, disIndexRank0Colon, colors, temp_s4);

    x += _disMap[disIndexRank0Colon].w + 2;

    for (i = 0; i < 3; ++i) {
        _renderTextureWipe(x, y + 3, buf[i] - '0', colors, temp_s4);
        x += 12;
    }

    _renderTextureWipe(x, y + 8, disIndexRank0Percent, colors, temp_s4);
}

/**
 * Renders the "Riskbreaker Rank" text.
 */
static void _renderRiskbreakerRankHeader(int x, int y, int timer)
{
    static CVECTOR colors[] = {
        { 200, 80, 20 },
        { 200, 80, 20 },
    };

    CLAMP_ANIMATION_TIMER(timer)

    if (timer > 0) {
        colors[0].cd = timer;
        _renderTextureFadeInTint(x - (_disMap[disIndexRank0RiskbreakerRank].w >> 1), y,
            disIndexRank0RiskbreakerRank, colors);
    }
}

/**
 * Renders the player's final rank.
 */
static void _renderRiskbreakerRank(int x, int y, int timer)
{
    static CVECTOR colors[] = {
        { 128, 128, 128 },
        { 128, 128, 128 },
    };

    int xInset;
    int i;

    CLAMP_ANIMATION_TIMER(timer)

    xInset = 0;

    if (timer > 0) {

        colors[0].cd = timer;

        for (i = 0; i < _riskbreakerRanks[_rank][0]; ++i) {
            xInset += _disMap[_riskbreakerRanks[_rank][i + 1]].w;
        }

        xInset /= 2;
        x -= xInset;

        for (i = 0; i < _riskbreakerRanks[_rank][0]; ++i) {
            _renderTexturePopIn(x, y, _riskbreakerRanks[_rank][i + 1], colors);

            x += _disMap[_riskbreakerRanks[_rank][i + 1]].w;
        }
    }
}

#undef CLAMP_ANIMATION_TIMER

#include "src/renderTextures.h"

/**
 * Parses a raw TIM image.
 *
 * @param data Pointer to the raw TIM data block.
 * @param tim Destination TIM image structure that receives the parsed metadata.
 */
static void _parseTim(u_int* data, TIM_IMAGE* tim)
{
    ++data;
    tim->mode = *data;
    ++data;

    if (tim->mode & 8) {
        tim->crect = (void*)(data + 1);
        tim->caddr = (void*)(data + 3);
        data += data[0] / 4;
    } else {
        tim->crect = 0;
        tim->caddr = 0;
    }

    tim->prect = (void*)(data + 1);
    tim->paddr = (void*)(data + 3);
}

/**
 * Determines the final rank based on the player's data.
 */
static void _determineRank(void)
{
    static short titleThresholds[16] = { 16, 12, 8 };
    static u_int rankScores[] = { 100000000, 75000000, 60000000, 40000000, 32000000,
        24000000, 16000000, 12000000, 8000000, 5000000, 4000000, 3000000, 2000000,
        1000000, 500000, 0 };

    int unlockedTitles;
    int flag;
    int i;

    for (i = 0, unlockedTitles = 0, flag = 1; i < 16; ++i) {
        if (vs_main_scoredata.titles & (flag << i)) {
            ++unlockedTitles;
        }
    }

    for (i = 0; i < 16; ++i) {
        if (unlockedTitles >= titleThresholds[i]) {
            if (_score >= rankScores[i]) {
                _rank = i;
                return;
            }
        }
    }
}
/**
 * Refreshes the players score.
 */
static void _updateScore(void)
{
    short enemyKillPoints[] = { 20, 20, 40, 80, 100, 60 };
    short weaponAttackPoints[] = { 20, 40, 20, 100, 60, 100, 60, 100, 80, 60 };
    int i;

    _score = 0;

    for (i = 0; i < 6; ++i) {
        _score += vs_main_scoredata.enemyKills[i] * enemyKillPoints[i];
    }

    for (i = 0; i < 10; ++i) {
        _score += vs_main_scoredata.weaponAttacks[i] * weaponAttackPoints[i];
    }

    for (i = 0; i < 8; ++i) {
        if (vs_main_scoredata.bossTimeTrialScores[i][0].time != 0x800000) {
            _score += 20000;
        }
    }

    if (vs_main_scoredata.maxChain < 6) {
        _score += vs_main_scoredata.maxChain * 10;
    } else if (vs_main_scoredata.maxChain < 11) {
        _score += vs_main_scoredata.maxChain * 20;
    } else if (vs_main_scoredata.maxChain < 16) {
        _score += vs_main_scoredata.maxChain * 40;
    } else if (vs_main_scoredata.maxChain < 21) {
        _score += vs_main_scoredata.maxChain * 80;
    } else if (vs_main_scoredata.maxChain < 26) {
        _score += vs_main_scoredata.maxChain * 160;
    } else if (vs_main_scoredata.maxChain < 31) {
        _score += vs_main_scoredata.maxChain * 320;
    } else if (vs_main_scoredata.maxChain < 51) {
        _score += vs_main_scoredata.maxChain * 640;
    } else {
        _score += vs_main_scoredata.maxChain * 1280;
    }

    _score += _clearCount * 100000;

    if ((_clearCount != 0) && (vs_main_scoredata.completionTimeMinutes < 600)) {
        if (vs_main_scoredata.completionTimeMinutes >= 540) {
            _score += _score / 4;
        } else if (vs_main_scoredata.completionTimeMinutes >= 300) {
            _score += _score / 2;
        } else {
            _score *= 2;
        }
    }

    _score += vs_main_scoredata.streakScore;
    _score += vs_main_scoredata.miscScore;

    if (_score > 999999999) {
        _score = 999999999;
    }
}
