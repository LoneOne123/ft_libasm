# ft_libasm

A reimplementation of core C standard library functions in **x86-64 assembly (NASM)**, built following the System V AMD64 calling convention.

The goal wasn't just to make the functions *work*, but to get the low-level details right: correct handling of caller-/callee-saved registers, 16-byte stack alignment before every `call`, and clean interop with C code and libc functions like `malloc`/`free`.

## Overview

| Function | Description |
|---|---|
| `ft_strlen` | Compute the length of a null-terminated string |
| `ft_strcpy` | Copy a null-terminated string |
| `ft_strcmp` | Lexicographically compare two strings |
| `ft_strdup` | Duplicate a string via `malloc` |
| `ft_read` / `ft_write` | Raw syscall wrappers with `errno` propagation |
| `ft_atoi_base` *(bonus)* | Parse a signed integer in an arbitrary base (binary, hex, ...) |
| `ft_list_push_front` *(bonus)* | Push a new node to the front of a singly linked list |
| `ft_list_size` *(bonus)* | Count the nodes in a linked list |
| `ft_list_sort` *(bonus)* | Sort a linked list in place with a custom comparator |
| `ft_list_remove_if` *(bonus)* | Remove a node matching a predicate, freeing it via a custom `free` function |

Full signatures are in [`includes/libasm.h`](includes/libasm.h) and [`includes/libasm_bonus.h`](includes/libasm_bonus.h).

## Build

```bash
make        # builds libasm.a (mandatory part)
make bonus  # builds libasm_bonus.a (mandatory + bonus)
```

Object files are compiled with NASM into `obj/` and archived into a static library with `ar`. Nothing outside `obj/`, `libasm.a` and `libasm_bonus.a` is generated.

### Running the tests

```bash
make test        # mandatory test suite
make test_bonus   # bonus test suite
```

Each test suite cross-checks the assembly implementations against their libc equivalents (e.g. `ft_atoi_base` against `strtol`) and reports pass/fail per function.

```bash
make clean   # remove object files
make fclean  # remove object files, libraries and test binaries
make re      # fclean + all
```

## Technical notes

Assembly at this level lives or dies by the calling convention, so a couple of things were deliberately checked function by function:

- **Register preservation** — any use of a callee-saved register (`rbx`, `rbp`, `r12`–`r15`) is wrapped in `push`/`pop`, or avoided entirely in favor of a caller-saved register where saving isn't necessary.
- **Stack alignment** — `rsp` is kept a multiple of 16 immediately before every `call` instruction, as required by the ABI. This matters in practice: `free()` and other libc functions can use SSE instructions internally that fault on a misaligned stack, which won't necessarily show up in casual testing but can crash intermittently depending on the libc build.

## Project structure

```
.
├── includes/   # public headers (libasm.h, libasm_bonus.h)
├── src/        # NASM source files
├── test/       # mandatory and bonus test suites (C)
└── Makefile
```