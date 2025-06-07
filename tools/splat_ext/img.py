from pathlib import Path
from splat.segtypes.segment import Segment
from splat.util import options

class PSXSegImg(Segment):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        if len(kwargs['yaml']) > 3:
            self.width = kwargs['yaml'][3]
            self.height = kwargs['yaml'][4]

    def out_path(self) -> Path:
        type_extension = f".{self.type}" if options.opts.image_type_in_extension else ""
        return options.opts.asset_path / self.dir / f"{self.name}{type_extension}.png"
    
    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path
