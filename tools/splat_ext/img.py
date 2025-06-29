from pathlib import Path
from splat.segtypes.segment import Segment
from splat.util import options

class PSXSegImg(Segment):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        if isinstance(kwargs['yaml'], dict) and "width" in kwargs['yaml'] and "height" in kwargs['yaml']:
            self.width = kwargs['yaml']["width"]
            self.height = kwargs['yaml']["height"]
        elif len(kwargs['yaml']) > 3:
            self.width = kwargs['yaml'][3]
            self.height = kwargs['yaml'][4]

    def out_path(self) -> Path:
        type_extension = f".{self.type}" if options.opts.image_type_in_extension else ""
        return options.opts.asset_path / self.dir / f"{self.name}{type_extension}.segment.png"
    
    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path
