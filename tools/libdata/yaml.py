import yaml
from enum import IntEnum
from functools import partial


def _str_representer(dumper: yaml.Dumper, data: str):
    if "\n" in data:
        return dumper.represent_scalar("tag:yaml.org,2002:str", data, style="|")
    return dumper.represent_scalar("tag:yaml.org,2002:str", data)


def _int_enum_representer(dumper: yaml.Dumper, data: IntEnum):
    return dumper.represent_scalar("tag:yaml.org,2002:str", data.name)


def configure_yaml() -> None:
    yaml.add_representer(str, _str_representer)
    yaml.add_multi_representer(IntEnum, _int_enum_representer)


dump = partial(
    yaml.dump,
    allow_unicode=True,
    sort_keys=False,
    default_flow_style=False,
)
