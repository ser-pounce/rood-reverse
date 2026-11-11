import argparse
from io import BytesIO, StringIO
from pathlib import Path
from typing import Any

from kaitaistruct import KaitaiStream
import yaml

from tools.kaitai.parsers.data.ENDING.ENDING_PRG.credits import Credits
from tools.libdata.yaml import configure_yaml, dump

TEXT_CONTROLS = {
    "|f1|": 0x01,
    "|f2|": 0x02,
    "|u|": 0x03,
    "|<|": 0x1F,
}


class CreditsDumper(yaml.Dumper):
    pass


CreditsDumper.add_representer(
    type(None),
    lambda dumper, _: dumper.represent_scalar("tag:yaml.org,2002:null", ""),
)


def _encode_credits_text(text: str) -> bytes:
    encoded = bytearray()
    char_table_offset = 0
    index = 0
    while index < len(text):
        control = next(
            (token for token in TEXT_CONTROLS if text.startswith(token, index)),
            None,
        )
        if control is not None:
            code = TEXT_CONTROLS[control]
            encoded.append(code)
            if code == 0x01:
                char_table_offset = 0
            elif code == 0x02:
                char_table_offset = 112
            index += len(control)
            continue

        char = text[index]
        if char_table_offset == 112 and char == "ç":
            encoded.append(ord(">"))
        elif " " <= char <= "\x7f":
            encoded.append(ord(char))
        else:
            raise ValueError(
                f"Character {char!r} at position {index} is not representable "
                "in the credits script"
            )
        index += 1

    if len(encoded) > 0xFF:
        raise ValueError(f"Credits text is {len(encoded)} bytes; maximum is 255")
    return bytes((len(encoded),)) + encoded


def _encode_credits_command(command: Any, index: int) -> bytes:
    if isinstance(command, str):
        return bytes((Credits.Opcode.render_text,)) + _encode_credits_text(command)
    if not isinstance(command, dict) or len(command) != 1:
        raise ValueError(f"Command {index} must be a string or one-key mapping")

    name, value = next(iter(command.items()))
    if not isinstance(name, str):
        raise ValueError(f"Command {index} name must be a string")

    if name in Credits.SpecialOpcode.__members__:
        return _encode_special_command(name, value)

    try:
        opcode = Credits.Opcode[name]
    except KeyError as error:
        raise ValueError(f"Unknown credits command {name!r}") from error
    return _encode_opcode_command(name, value, opcode)


def _encode_special_command(name: str, value: Any) -> bytes:
    if value is not None:
        raise ValueError(f"Special command {name!r} must have an empty value")
    return bytes((Credits.Opcode.render_special, Credits.SpecialOpcode[name]))


def _encode_opcode_command(name: str, value: Any, opcode: Credits.Opcode) -> bytes:
    if opcode == Credits.Opcode.wait:
        return _encode_wait(value)
    if opcode == Credits.Opcode.illustration_timer:
        return _encode_illustration_timer(value)
    if opcode in (Credits.Opcode.render_text, Credits.Opcode.render_special):
        raise ValueError(f"{name!r} must use its simplified YAML representation")
    if value is not None:
        raise ValueError(f"Command {name!r} must have an empty value")
    return bytes((opcode,))


def _encode_wait(value: Any) -> bytes:
    if (
        isinstance(value, bool)
        or not isinstance(value, int)
        or not 0 <= value <= 0xFF
    ):
        raise ValueError(f"wait value must be an integer from 0 to 255, got {value!r}")
    return bytes((Credits.Opcode.wait, value))


def _encode_illustration_timer(value: Any) -> bytes:
    if not isinstance(value, dict) or set(value) != {"id", "duration"}:
        raise ValueError(
            "illustration_timer must contain exactly 'id' and 'duration'"
        )

    illustration_id = value["id"]
    duration = value["duration"]
    if (
        isinstance(illustration_id, bool)
        or not isinstance(illustration_id, int)
        or not 0 <= illustration_id <= 0xFF
    ):
        raise ValueError(
            "illustration_timer id must be from 0 to 255, "
            f"got {illustration_id!r}"
        )
    if (
        isinstance(duration, bool)
        or not isinstance(duration, int)
        or not 0 <= duration <= 0xFFFF
    ):
        raise ValueError(
            "illustration_timer duration must be from 0 to 65535, "
            f"got {duration!r}"
        )
    return (
        bytes((Credits.Opcode.illustration_timer, illustration_id))
        + duration.to_bytes(2, "little")
    )


def encode_credits(commands: Any) -> bytes:
    if not isinstance(commands, list):
        raise ValueError("Credits YAML must contain a list of commands")

    result = bytearray()
    for index, command in enumerate(commands):
        result.extend(_encode_credits_command(command, index))

    result.append(0xFF)
    result.extend(bytes(-len(result) % 16))
    return bytes(result)


def _format_credits_text(text: bytes) -> str:
    controls = {
        0x01: "|f1|",
        0x02: "|f2|",
        0x03: "|u|",
        0x1F: "|<|",
    }
    char_table_offset = 0
    result = []
    for code in text:
        if code in controls:
            result.append(controls[code])
            if code == 0x01:
                char_table_offset = 0
            elif code == 0x02:
                char_table_offset = 112
        elif code >= 0x20:
            char = bytes((code,)).decode("ascii")
            if char_table_offset == 112 and char == ">":
                char = "ç"
            result.append(char)
    return "".join(result)


def dump_credits(data: bytes) -> str:
    credits = Credits(KaitaiStream(BytesIO(data)))
    configure_yaml()
    commands = []
    for command in credits.commands[:-1]:
        key = command.opcode.name
        payload = None
        if command.opcode == Credits.Opcode.wait:
            payload = command.body.duration
        elif command.opcode == Credits.Opcode.render_text:
            commands.append(_format_credits_text(command.body.text))
            continue
        elif command.opcode == Credits.Opcode.render_special:
            key = command.body.opcode.name
        elif command.opcode == Credits.Opcode.illustration_timer:
            payload = {
                "id": command.body.id,
                "duration": command.body.duration,
            }
        commands.append({key: payload})

    output = StringIO()
    dump(commands, output, Dumper=CreditsDumper)
    return output.getvalue()


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(
        description="Encode ENDING credits YAML for linking"
    )
    parser.add_argument("input", type=Path, help="credits YAML file")
    parser.add_argument("output", type=Path, help="output binary path")
    args = parser.parse_args(argv)

    commands = yaml.safe_load(args.input.read_text(encoding="utf-8"))
    binary = encode_credits(commands)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(binary)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
