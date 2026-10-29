import subprocess
import sys
import unittest
from pathlib import Path

from tools.etc.textTransformer import process_lines, process_sjis_block, process_vsstring_block


class TextTransformerTests(unittest.TestCase):
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
            [sys.executable, '-m', 'tools.etc.textTransformer'],
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

    def test_cli_dispatches_each_pragma_to_its_encoding(self):
        source = (
            '#pragma sjis(start)\n'
            'char jp[] = "ＡＢ　１";\n'
            '#pragma sjis(end)\n'
            '#pragma vsstring(start)\n'
            'char vs[] = "A";\n'
            '#pragma vsstring(end)\n'
            '#pragma pack(1)\n'
            'char outside[] = "ＡＢ";\n'
        )
        self.assertEqual(
            ''.join(process_lines(source.splitlines(keepends=True))),
            'char jp[] = {130, 96, 130, 97, 129, 64, 130, 80};\n'
            'char vs[] = {10};\n'
            '#pragma pack(1)\n'
            'char outside[] = "ＡＢ";\n',
        )

    def test_mismatched_end_pragma_does_not_close_block(self):
        source = '#pragma sjis(start)\n"Ａ"\n#pragma vsstring(end)\n"Ｂ"\n'
        self.assertEqual(
            ''.join(process_lines(source.splitlines(keepends=True))),
            '{130, 96}\n#pragma vsstring(end)\n{130, 97}\n',
        )

    def test_unclosed_encoding_block_is_processed_at_eof(self):
        source = '#pragma vsstring(start)\nchar text[] = "A";\n'
        self.assertEqual(
            ''.join(process_lines(source.splitlines(keepends=True))),
            'char text[] = {10};\n',
        )


class SjisTests(unittest.TestCase):
    def test_full_width_text(self):
        self.assertEqual(process_sjis_block('"ＶＡＧ　０"'), '{130, 117, 130, 96, 130, 102, 129, 64, 130, 79}')

    def test_adjacent_literals_concatenate(self):
        self.assertEqual(process_sjis_block('"Ａ" "Ｂ"'), '{130, 96, 130, 97}')

    def test_ascii_character_literal(self):
        self.assertEqual(process_sjis_block("'A'"), '65')

    def test_unmappable_text_is_an_error(self):
        with self.assertRaises(UnicodeEncodeError):
            process_sjis_block('"🐈"')


if __name__ == '__main__':
    unittest.main()
