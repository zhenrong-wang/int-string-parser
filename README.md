# Int-string-parser: A small practice to parse a string and extract an 8-bit integer

# 1. Background

Inspired by Professor Daniel Lemire's Twitter post. Check his Twitter @lemire

The code here is very useful to parse a complex string and extract integer strings among ASCII characters.

# 2. Brief Intro

**Program Name**: Int-string-parser

**Purpose**: Extract an integer out of a given UTF-8 ASCII string

**License**: MIT

# 3. How-To: Build, Run, and Use

## 3.1 Build

### 3.1.1 Prerequisites

You need a C compiler to build. 

- For Microsoft Windows users, [mingw](https://sourceforge.net/projects/mingw/) is a good choice
- For GNU/Linux Distro or other *nix users, the [GNU Compiler Collections](https://gcc.gnu.org/), known as gcc, is a perfect one
- For macOS users, [clang](https://clang.llvm.org/) is easy to install and use (brew is not needed to install clang on macOS).

### 3.1.2 Build Guide

1. Use git to clone this code: `git clone https://github.com/zhenrong-wang/int-string-parser.git`
2. Build command example: `gcc integer_parser.c -o my-int-parser.exe -lm`

**Note**: the `-lm` may not be valid for Windows or macOS. It is necessary for GNU/Linux distros.

## 3.2 Run

Command Format: `cmd argv[1] argv[2]`

- `argv[1]`: A UTF-8 string **end with a space**. E.g. `test102string103tobe0023parsed`
- `argv[2]`: An 8-bit integer in string format. Starting with '0' is acceptable. E.g. `102` `0102`

### An Example for UNIX-like OS:

`./my-int-parser.exe test102string103tobe0023parsed 0102`

### An Example for Windows:

`.\my-int-parser.exe test102string103tobe0023parsed 0102`

If everything goes well, you'll see the output below:

    INFO   : Parsing the integer 102 started ...

    FOUND  : Parsed out 102 at position 4, # 1.

    SUMMARY: Parsed out 1 integer string 102.

# 4 Bugs and Communications

Any bugs or problems found, please submit issues to this repo. I'd be glad to communicate on any issues.

Or, you can also email me: zhenrongwang@live.com
