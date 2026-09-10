import argparse
from pathlib import Path
from typing import Any

from PIL import Image
from splat.segtypes.segment import Segment
from splat.util import options


class PSXSegImg(Segment):

    def out_path(self) -> Path:
        type_extension = f'.{self.type}' if options.opts.image_type_in_extension else ''
        return options.opts.asset_path / self.dir / f'{self.name}{type_extension}.img.png'

    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    @staticmethod
    def load_input_image(image_path: Path) -> Image.Image:
        image = Image.open(image_path)
        image.load()
        return image

    @staticmethod
    def symbol_name_from_path(image_path: Path) -> str:
        return image_path.name.split('.')[0]

    @classmethod
    def encode_to_binary(cls, image_path: Path) -> tuple[bytes, list[tuple[str, int]]]:
        raise NotImplementedError

    @classmethod
    def run_encoder(cls) -> None:
        parser = argparse.ArgumentParser()
        parser.add_argument('input', type=Path, help='Input PNG file')
        parser.add_argument('output', type=Path, help='Output binary file')
        args = parser.parse_args()

        binary, symbols = cls.encode_to_binary(args.input)
        args.output.write_bytes(binary)

        with args.output.with_suffix('.sym').open('w') as symbol_file:
            for name, offset in symbols:
                symbol_file.write(f'{name} {offset}\n')



class PSXSegSizedImg(PSXSegImg):

    width:  int
    height: int

    def __init__(self, **kwargs: Any) -> None:
        super().__init__(**kwargs)
        yaml = kwargs['yaml']

        if isinstance(yaml, dict):
            self.width  = int(yaml.get('width', 0))
            self.height = int(yaml.get('height', 0))
        elif isinstance(yaml, (list, tuple)) and len(yaml) > 4:
            self.width  = int(yaml[3])
            self.height = int(yaml[4])

        if self.width == 0 or self.height == 0:
            raise ValueError(
                f'{self.__class__.__name__} requires width and height'
            )
