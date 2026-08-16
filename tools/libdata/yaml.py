import yaml


def _str_representer(dumper: yaml.Dumper, data: str):
    if "\n" in data:
        return dumper.represent_scalar("tag:yaml.org,2002:str", data, style="|")
    return dumper.represent_scalar("tag:yaml.org,2002:str", data)


def configure_yaml() -> None:
    """Register project-wide YAML representers. Call once before yaml.dump()."""
    yaml.add_representer(str, _str_representer)
