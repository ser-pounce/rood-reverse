from io import BytesIO

from kaitaistruct import KaitaiStream

from tools.etc.vsString import decode
from tools.kaitai.parsers.data.vs_main_actions import VsMainActions

ACTION_COUNT = 256
ACTION_SIZE = 52


def _format_hit_params(params: VsMainActions.HitParams, indent: str) -> list[str]:
    return [
        f"{indent}{{",
        f"{indent}    .effect = {params.effect},",
        f"{indent}    .prerequisiteFunction = {params.prerequisite_function},",
        f"{indent}    .hitFunction = {params.hit_function},",
        f"{indent}    .statCalculator = {params.stat_calculator},",
        f"{indent}    .statFactor = {params.stat_factor},",
        f"{indent}    .type = {params.type},",
        f"{indent}    .affinity = {params.affinity},",
        f"{indent}}},",
    ]


def _c_string(value: str) -> str:
    escaped = []
    for char in value:
        if char == "\\":
            escaped.append("\\\\")
        elif char == '"':
            escaped.append('\\"')
        elif char == "\n":
            escaped.append("\\n")
        elif char == "\r":
            escaped.append("\\r")
        elif char == "\t":
            escaped.append("\\t")
        elif ord(char) < 0x20 or ord(char) == 0x7F:
            escaped.append(f"\\{ord(char):03o}")
        else:
            escaped.append(char)
    return '"' + "".join(escaped) + '"'


def _format_action(action: VsMainActions.Action) -> list[str]:
    flags = action.flags_e
    lines = [
        "    {",
        f"        .id = {action.id},",
        f"        .unk1 = {action.unk1},",
        f"        .unk2_0 = {int(action.unk2_0)},",
        f"        .type = {action.type},",
        f"        .unk2_4 = {action.unk2_4},",
        f"        .cost = {action.cost},",
        f"        .rangeX = {action.range_x},",
        f"        .rangeY = {action.range_y},",
        f"        .rangeZ = {action.range_z},",
        f"        .shape = {action.shape},",
        f"        .angle = {action.angle},",
        f"        .aoe_0 = {action.aoe_0},",
        f"        .aoe_8 = {action.aoe_8},",
        f"        .aoe_16 = {action.aoe_16},",
        f"        .aoe_24 = {action.aoe_24},",
        f"        .flags_0 = {action.flags_0},",
        f"        .flagsD_0 = {action.flags_d_0},",
        f"        .flagsD_4 = {action.flags_d_4},",
        f"        .flagsD_6 = {int(action.flags_d_6)},",
        f"        .unlocked = {int(action.unlocked)},",
        "        .flagsE = {",
        f"            .unk0 = {flags.unk0},",
        f"            .unk4 = {int(flags.unk4)},",
        f"            .unk5 = {int(flags.unk5)},",
        f"            .unk6 = {int(flags.unk6)},",
        f"            .unk7 = {int(flags.unk7)},",
        f"            .unk8 = {flags.unk8},",
        f"            .unk12 = {int(flags.unk12)},",
        f"            .unk13 = {int(flags.unk13)},",
        f"            .unk14 = {flags.unk14},",
        "        },",
        f"        .unk10 = {action.unk10},",
        "        .hitParams = {",
    ]
    lines.extend(_format_hit_params(action.hit_params[0], "            "))
    lines.extend(_format_hit_params(action.hit_params[1], "            "))
    lines.extend(
        (
            "        },",
            f"        .name = {_c_string(decode(action.name, read_to_end=True))},",
        )
    )
    lines.append("    },")
    return lines


def dump_actions(data: bytes) -> str:
    expected_size = ACTION_COUNT * ACTION_SIZE
    if len(data) != expected_size:
        raise ValueError(
            f"Expected {expected_size} action-table bytes, got {len(data)}"
        )

    parsed = VsMainActions(KaitaiStream(BytesIO(data)))
    lines = ["#pragma vsstring(start)", "vs_action_t vs_main_actions[] = {"]
    for action in parsed.actions:
        lines.extend(_format_action(action))
    lines.append("};")
    lines.append("#pragma vsstring(end)")
    return "\n".join(lines) + "\n"
