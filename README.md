# Int-string-parser: A small practice to parse 8-bit integer out of a given UTF-8 string

# 1. Background

This is a practice initiated by Prof Daniel Lemire (Twitter @lemire).

# 2. Brief Intro

**Program Name**: Int-string-parser

**Purpose**: Parse an integer out of a given UTF-8 string

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

# 4 Bugs and Communications

Any bugs or problems found, please submit issues to this repo. I'd be glad to communicate on any issues.

Or, you can also email me: zhenrongwang@live.com
