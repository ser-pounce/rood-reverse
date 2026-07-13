#include "texture_t.h"

void _renderTextureFadeInTint(int x, int y, int texId, P_CODE colors[])
{
    POLY_GT4* poly;
    void** p;

    if (colors[0].code == 0) {
        return;
    }

    poly = *(void**)0x1F800000;

    setPolyGT4(poly);
    setXY4(poly, x, y, _disMap[texId].w + x, y, x, _disMap[texId].h + y,
        _disMap[texId].w + x, _disMap[texId].h + y);
    setUV4(poly, _disMap[texId].x, _disMap[texId].y, _disMap[texId].x + _disMap[texId].w,
        _disMap[texId].y, _disMap[texId].x, _disMap[texId].y + _disMap[texId].h,
        _disMap[texId].x + _disMap[texId].w, _disMap[texId].y + _disMap[texId].h);

    if (colors[0].code < 8) {
        setRGB0(poly, (colors[0].r0 * colors[0].code) / 8,
            (colors[0].g0 * colors[0].code) / 8, (colors[0].b0 * colors[0].code) / 8);
        setRGB1(poly, (colors[1].r0 * colors[0].code) / 8,
            (colors[1].g0 * colors[0].code) / 8, (colors[1].b0 * colors[0].code) / 8);
        setRGB2(poly, (colors[0].r0 * colors[0].code) / 8,
            (colors[0].g0 * colors[0].code) / 8, (colors[0].b0 * colors[0].code) / 8);
        setRGB3(poly, (colors[1].r0 * colors[0].code) / 8,
            (colors[1].g0 * colors[0].code) / 8, (colors[1].b0 * colors[0].code) / 8);
    } else {
        setRGB0(poly, colors[0].r0, colors[0].g0, colors[0].b0);
        setRGB1(poly, colors[1].r0, colors[1].g0, colors[1].b0);
        setRGB2(poly, colors[0].r0, colors[0].g0, colors[0].b0);
        setRGB3(poly, colors[1].r0, colors[1].g0, colors[1].b0);
    }

    setSemiTrans(poly, 1);

    if (colors[0].code < 8) {
        poly->clut = _disMap[texId].clut + 1;
        poly->tpage = _disMap[texId].tpage | 0x20;
    } else {
        poly->clut = _disMap[texId].clut;
        poly->tpage = _disMap[texId].tpage;
    }

    p = (void**)0x1F800000;

    AddPrim(p[1] - 0x1C, poly++);

    p[0] = poly;
}

static inline int _adjust(int component, int weight)
{
    int ret = (component * weight) + ((4 - weight) * 192);
    return ret / 4;
}

void _renderTexturePopIn(int x, int y, int texId, P_CODE colors[])
{
    POLY_GT4* poly;
    void** p;

    if (colors[0].code != 0) {
        poly = *(void**)0x1F800000;

        setPolyGT4(poly);
        setXY4(poly, x, y, _disMap[texId].w + x, y, x, _disMap[texId].h + y,
            _disMap[texId].w + x, _disMap[texId].h + y);
        setUV4(poly, _disMap[texId].x, _disMap[texId].y,
            _disMap[texId].x + _disMap[texId].w, _disMap[texId].y, _disMap[texId].x,
            _disMap[texId].y + _disMap[texId].h, _disMap[texId].x + _disMap[texId].w,
            _disMap[texId].y + _disMap[texId].h);

        if (colors[0].code < 8) {
            setRGB0(poly, (colors[0].r0 * colors[0].code) / 8,
                (colors[0].g0 * colors[0].code) / 8, (colors[0].b0 * colors[0].code) / 8);
            setRGB1(poly, (colors[1].r0 * colors[0].code) / 8,
                (colors[1].g0 * colors[0].code) / 8, (colors[1].b0 * colors[0].code) / 8);
            setRGB2(poly, (colors[0].r0 * colors[0].code) / 8,
                (colors[0].g0 * colors[0].code) / 8, (colors[0].b0 * colors[0].code) / 8);
            setRGB3(poly, (colors[1].r0 * colors[0].code) / 8,
                (colors[1].g0 * colors[0].code) / 8, (colors[1].b0 * colors[0].code) / 8);
        } else if (colors[0].code == 8) {
            setRGB0(poly, 192, 192, 192);
            setRGB1(poly, 192, 192, 192);
            setRGB2(poly, 192, 192, 192);
            setRGB3(poly, 192, 192, 192);
        } else if (colors[0].code == 9) {
            setRGB0(poly, 224, 224, 224);
            setRGB1(poly, 224, 224, 224);
            setRGB2(poly, 224, 224, 224);
            setRGB3(poly, 224, 224, 224);
        } else if (colors[0].code < 14) {
            int temp_a0 = colors[0].code - 10;
            setRGB0(poly, _adjust(colors[0].r0, temp_a0), _adjust(colors[0].g0, temp_a0),
                _adjust(colors[0].b0, temp_a0));
            setRGB1(poly, _adjust(colors[1].r0, temp_a0), _adjust(colors[1].g0, temp_a0),
                _adjust(colors[1].b0, temp_a0));
            setRGB2(poly, _adjust(colors[0].r0, temp_a0), _adjust(colors[0].g0, temp_a0),
                _adjust(colors[0].b0, temp_a0));
            setRGB3(poly, _adjust(colors[1].r0, temp_a0), _adjust(colors[1].g0, temp_a0),
                _adjust(colors[1].b0, temp_a0));
        } else {
            setRGB0(poly, colors[0].r0, colors[0].g0, colors[0].b0);
            setRGB1(poly, colors[1].r0, colors[1].g0, colors[1].b0);
            setRGB2(poly, colors[0].r0, colors[0].g0, colors[0].b0);
            setRGB3(poly, colors[1].r0, colors[1].g0, colors[1].b0);
        }

        setSemiTrans(poly, 1);

        if (colors[0].code < 10) {
            poly->clut = _disMap[texId].clut + getClut(16, 0);
            poly->tpage = _disMap[texId].tpage | getTPage(0, 1, 0, 0);
        } else {
            poly->clut = _disMap[texId].clut;
            poly->tpage = _disMap[texId].tpage;
        }

        p = (void**)0x1F800000;

        AddPrim(p[1] - 0x1C, poly++);

        p[0] = poly;
    }
}

void _renderTextureWipe(int x, int y, int texId, P_CODE arg3[], int arg4)
{
    int temp_a1;
    int var_a0;
    int i;
    char var_s6;
    POLY_GT4* poly;
    void** scratch;

    if ((x + _disMap[texId].w) < (arg4 - 64)) {

        scratch = (void**)0x1F800000;
        poly = scratch[0];

        setPolyGT4(poly);
        setXY4(poly, x, y, _disMap[texId].w + x, y, x, _disMap[texId].h + y,
            _disMap[texId].w + x, _disMap[texId].h + y);
        setUV4(poly, _disMap[texId].x, _disMap[texId].y,
            _disMap[texId].x + _disMap[texId].w, _disMap[texId].y, _disMap[texId].x,
            _disMap[texId].y + _disMap[texId].h, _disMap[texId].x + _disMap[texId].w,
            _disMap[texId].y + _disMap[texId].h);
        setRGB0(poly, arg3[0].r0, arg3[0].g0, arg3[0].b0);
        setRGB1(poly, arg3[1].r0, arg3[1].g0, arg3[1].b0);
        setRGB2(poly, arg3[0].r0, arg3[0].g0, arg3[0].b0);
        setRGB3(poly, arg3[1].r0, arg3[1].g0, arg3[1].b0);
        setSemiTrans(poly, 1);

        poly->clut = _disMap[texId].clut;
        poly->tpage = _disMap[texId].tpage;

        scratch = (void**)0x1F800000;

        AddPrim(scratch[1] - 0x1C, poly++);

        scratch[0] = poly;
        return;
    }

    if (x < arg4) {

        scratch = (void**)0x1F800000;
        poly = scratch[0];
        var_s6 = _disMap[texId].x;

        for (i = 0; i < _disMap[texId].w; i += 12, x += 12, var_s6 += 12) {

            var_a0 = 12;

            if ((i + 12) >= _disMap[texId].w) {
                var_a0 = _disMap[texId].w - i;
            }

            setPolyGT4(poly);
            temp_a1 = x + var_a0;
            setXY4(poly, x, y, temp_a1, y, x, _disMap[texId].h + y, temp_a1,
                _disMap[texId].h + y);
            setUV4(poly, var_s6, _disMap[texId].y, var_s6 + var_a0, _disMap[texId].y,
                var_s6, _disMap[texId].y + _disMap[texId].h, var_s6 + var_a0,
                _disMap[texId].y + _disMap[texId].h);

            var_a0 = arg4 - x;

            if (var_a0 > 64) {
                var_a0 = 64;
            }

            if (var_a0 < 0) {
                var_a0 = 0;
            }

            setRGB0(poly, (arg3[0].r0 * var_a0) / 64, (arg3[0].g0 * var_a0) / 64,
                (arg3[0].b0 * var_a0) / 64);
            setRGB2(poly, (arg3[0].r0 * var_a0) / 64, (arg3[0].g0 * var_a0) / 64,
                (arg3[0].b0 * var_a0) / 64);

            var_a0 = arg4 - temp_a1;

            if (var_a0 > 64) {
                var_a0 = 64;
            }

            if (var_a0 < 0) {
                var_a0 = 0;
            }

            setRGB1(poly, (arg3[1].r0 * var_a0) / 64, (arg3[1].g0 * var_a0) / 64,
                (arg3[1].b0 * var_a0) / 64);
            setRGB3(poly, (arg3[1].r0 * var_a0) / 64, (arg3[1].g0 * var_a0) / 64,
                (arg3[1].b0 * var_a0) / 64);

            setSemiTrans(poly, 1);

            poly->clut = (_disMap[texId].clut + 1);
            poly->tpage = (_disMap[texId].tpage | 0x20);

            scratch = (void**)0x1F800000;

            AddPrim(scratch[1] - 0x1C, poly++);
        }

        scratch = (void**)0x1F800000;
        scratch[0] = poly;
    }
}
