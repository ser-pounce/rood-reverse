import subprocess
import sys
import unittest
from pathlib import Path

from tools.etc.vsStringTransformer import process_vsstring_block


class VsStringTransformerTests(unittest.TestCase):
    def test_adjacent_strings(self):
        self.assertEqual(
            process_vsstring_block('char text[] = "Hello " "world";'),
            'char text[] = {17, 40, 47, 47, 50, 143, 58, 50, 53, 47, 39};',
        )

    def test_adjacent_strings_without_whitespace(self):
        self.assertEqual(process_vsstring_block('"A""B"'), '{10, 11}')

    def test_glyph_split_across_literals(self):
        self.assertEqual(process_vsstring_block('"L"\n"v.1"'), '{182, 1}')

    def test_control_split_across_literals(self):
        self.assertEqual(process_vsstring_block('"|>" "6|"'), '{250, 6}')

    def test_comments_between_literals(self):
        self.assertEqual(
            process_vsstring_block('"L" /* "ignored" */ // "ignored"\n"v.1"'),
            '{182, 1}',
        )

    def test_comments_are_not_encoded(self):
        source = '// "unsupported 🐈" and \'x\'\n/* "also ignored" */\n'
        self.assertEqual(process_vsstring_block(source), source)

    def test_comments_inside_literals(self):
        self.assertEqual(process_vsstring_block('"/*A*/"'), '{161, 169, 10, 169, 161}')

    def test_escaped_quotes_and_character_literals(self):
        self.assertEqual(
            process_vsstring_block(r'''"A\"B" '\'' 'A' '\000' '''),
            '{10, 145, 11} 150 10 231 ',
        )

    def test_separate_initializers_remain_separate(self):
        self.assertEqual(process_vsstring_block('"A", "B"'), '{10}, {11}')

    def test_cli_transforms_only_pragma_blocks(self):
        source = (
            'char outside[] = "ASCII";\n'
            '#pragma vsstring(start)\n'
            'char inside[] = "L" "v.1";\n'
            '#pragma vsstring(end)\n'
            'char after[] = "ASCII";\n'
        )
        result = subprocess.run(
            [sys.executable, '-m', 'tools.etc.vsStringTransformer'],
            input=source,
            text=True,
            capture_output=True,
            check=True,
            cwd=Path(__file__).resolve().parents[2],
        )
        self.assertEqual(
            result.stdout,
            'char outside[] = "ASCII";\n'
            'char inside[] = {182, 1};\n'
            'char after[] = "ASCII";\n',
        )


if __name__ == '__main__':
    unittest.main()
