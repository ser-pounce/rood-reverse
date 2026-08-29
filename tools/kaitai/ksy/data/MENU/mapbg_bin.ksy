meta:
  id: mapbg_bin
  file-extension: BIN
  imports: [/img]
  

seq:
  - id: clut
    type: img::clut
    size: 512
  - id: indices
    type: u1
    repeat: eos
