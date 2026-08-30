meta:
  id: menubg_bin
  file-extension: BIN
  imports: [/img]

seq:
  - id: clut
    type: img::clut
    size: 512
  - id: indices
    size-eos: true
    process: tools.libdata.rle.rle_decompressor
  