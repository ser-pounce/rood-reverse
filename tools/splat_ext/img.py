from pathlib import Path
from typing import Any

from splat.segtypes.segment import Segment
from splat.util import options


class PSXSegImg(Segment):

    def __init__(self, **kwargs: Any) -> None:
        super().__init__(**kwargs)
        if isinstance(kwargs['yaml'], dict) and 'width' in kwargs['yaml'] and 'height' in kwargs['yaml']:
            self.width  = kwargs['yaml']['width']
            self.height = kwargs['yaml']['height']
        elif len(kwargs['yaml']) > 3:
            self.width  = kwargs['yaml'][3]
            self.height = kwargs['yaml'][4]

    def out_path(self) -> Path:
        type_extension = f'.{self.type}' if options.opts.image_type_in_extension else ''
        return options.opts.asset_path / self.dir / f'{self.name}{type_extension}.img.png'

    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    @property
    def symbol_name(self) -> str:
        """Symbol name derived from the segment name, stripping all extensions."""
        return self.name.split('.')[0]

    @staticmethod
    def write_image_files(
        binary:        bytes,
        output_path:   Path,
        symbols:       list[tuple[str, int]],
    ) -> None:
        """
        Write image data, the legacy textual representation, and symbol metadata.

        Make uses the binary and symbol files to create the final object file.
        """
        output_path.write_bytes(binary)

        with output_path.with_suffix('.dat').open('w') as dat:
            for byte in binary:
                dat.write(f'0x{byte:02X},')

        with output_path.with_suffix('.sym').open('w') as symbol_file:
            for name, offset in symbols:
                symbol_file.write(f'{name} {offset}\n')