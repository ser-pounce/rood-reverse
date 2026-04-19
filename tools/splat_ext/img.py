import os
import shlex
import subprocess
import tempfile
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
    def objcopy_from_env() -> tuple[str, list[str]]:
        """Read OBJCOPY and OBJCOPYFLAGS from the environment."""
        objcopy       = os.environ.get('OBJCOPY', 'objcopy')
        objcopy_flags = shlex.split(os.environ.get('OBJCOPYFLAGS', ''))
        return objcopy, objcopy_flags

    @staticmethod
    def write_object_file(
        binary:        bytes,
        output_path:   Path,
        symbols:       list[tuple[str, int]],
        objcopy:       str,
        objcopy_flags: list[str],
    ) -> None:
        """
        Write a linkable .o file from a binary blob with named symbols at given offsets.

        Uses a temporary file since objcopy cannot read from stdin.
        objcopy and objcopy_flags are typically sourced from the environment
        via objcopy_from_env(), which reads OBJCOPY and OBJCOPYFLAGS exported
        from the Makefile.
        """
        symbol_args = [arg for name, offset in symbols
                           for arg in ('--add-symbol', f'{name}=.data:{offset}')]
        with tempfile.NamedTemporaryFile(delete=True) as tmp:
            tmp.write(binary)
            tmp.flush()
            subprocess.run(
                [objcopy, *objcopy_flags, *symbol_args, tmp.name, str(output_path)],
                check=True,
            )