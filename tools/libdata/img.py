def rgba8888_to_bgr1555(r: int, g: int, b: int, a: int) -> int:
    if a == 0:
        return 0
    return ((b >> 3) << 10) | ((g >> 3) << 5) | (r >> 3)
