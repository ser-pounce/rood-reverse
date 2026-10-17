import argparse
from pathlib import Path

from tools.data.SMALL.DIS import encode_tim


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Encode a TIM PNG for linking")
    parser.add_argument("input", type=Path, help="input TIM PNG")
    parser.add_argument("output", type=Path, help="output TIM binary")
    args = parser.parse_args(argv)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(encode_tim(args.input))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
