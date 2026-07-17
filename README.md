# libft

A from-scratch reimplementation of a useful subset of the C standard library, plus some extra string/memory/output helpers and a small singly-linked-list toolkit — built as a static library (`libft.a`) meant to be reused across other 42 school projects.

## Functions

### Character classification
`ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` `ft_toupper` `ft_tolower`

### Memory
`ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` `ft_calloc`

### Strings
`ft_strlen` `ft_strlcpy` `ft_strlcat` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_strdup` `ft_substr` `ft_strjoin` `ft_strtrim` `ft_split` `ft_strmapi` `ft_striteri`

### Conversion
`ft_atoi` `ft_itoa`

### Writing to a file descriptor
`ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd`

### Bonus — singly-linked list (`t_list`)
`ft_lstnew` `ft_lstadd_front` `ft_lstsize` `ft_lstlast` `ft_lstadd_back` `ft_lstdelone` `ft_lstclear`

Every prototype (plus the `t_list` struct) is declared in `libft.h`.

## Build

```bash
make          # mandatory functions only -> libft.a
make bonus    # also compiles the linked-list functions into the same libft.a
```

```bash
make clean   # remove object files
make fclean  # remove object files and libft.a
make re      # fclean + all
```

> Run `make` before `make bonus` (or just `make bonus` on a clean checkout) to get both the mandatory and bonus functions in the same archive — `make bonus` alone only compiles the bonus files. Also: the bonus source list in the Makefile lists `ft_lstnew_bonus.c` twice; harmless (Make just rebuilds the same object twice), but worth a mental note if you're editing it.

## Using it in another project

```bash
cc -Wall -Wextra -Werror your_file.c -I/path/to/libft -L/path/to/libft -lft -o your_program
```

```c
#include "libft.h"
```

## License

[Unlicense](LICENSE) — public domain, use it however you like.

---

## Concept notes

These are study notes on the underlying C concepts, written while working through this project.

### `const`

Used as a type qualifier, `const` ensures the value it's applied to can't be modified.

```c
const char a = 'a'; // cannot be modified
```

#### `const char *` vs. `char * const`

*(Corrected from the original notes — `const char *` and `char const *` are actually identical; the real contrast worth knowing is with `char * const`.)*

- `const char *` — equivalently `char const *` — is a pointer to a `const char`: the value it points to can't be changed through this pointer, but the pointer itself can be reassigned to point somewhere else.
- `char * const` is a constant pointer to a (non-const) `char`: the pointer itself can't be reassigned, but the value it points to can be modified.

### Type casting

Type conversion normally happens automatically ("implicit" casting), but it follows a rule: it goes from a smaller type toward a larger one, because the larger type has a wider range — going the other way risks losing data.

If you convert a larger type down into a smaller one, the value effectively gets reduced (by repeatedly subtracting the smaller type's range) until it fits inside that smaller type's bounds:

```c
int  i;
char a;
i = 289;
a = (char)i;
```

Here, casting `289` down to a `char` subtracts 256 (that generalizes to "subtract the target type's range") until the value fits. Another common case is `float → int`, where the fractional part is simply dropped.
([see also](https://www.geeksforgeeks.org/type-conversion-c/))

### Pointer arithmetic

Pointer arithmetic is essentially "shifting an address." For example:

```c
char *ptr = "arithmetic";
ptr++;
```

Say the first character of this string lives at address `1001` — that's what `ptr` holds initially. After `ptr++`, `ptr` holds `1002`.

The part that's easy to get wrong: the address doesn't always move by exactly 1. `ptr++` moves the pointer by *one element* of whatever type it points to — for a `char` (1 byte), that's +1 to the address. For an `int` array, the same `ptr++` would move the address by +4 (since `int` is 4 bytes), not +1.

*(And to close the loop on the open question in the original notes — a pointer's own size doesn't depend on what it points to; it's fixed by the architecture, typically 8 bytes on a 64-bit system and 4 bytes on a 32-bit one.)*

### File descriptors

A file descriptor is an integer used to refer to a file or other I/O resource — basically an ID. A few are assigned by default:

```
0 = standard input  (reading from the keyboard)
1 = standard output (printing to the screen)
2 = standard error  (printing error messages)
```

Other file descriptors are obtained via functions like `open()`.

#### `open`

```c
int open(const char *path, int flags, mode_t mode);
```

`path` is the file's location and name, `flags` controls the mode the file is opened in and what kind of access is allowed, and `mode` sets the permissions the file gets if it's created (same idea as the `chmod` parameters). ([more detail](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/#opening_or_creating_a_file_in_c)) Commonly used flags:

- `O_RDONLY` — open read-only; the file's contents can't be modified, only read.
- `O_WRONLY` — open write-only; the file's contents can't be read, only modified.
- `O_RDWR` — open for both reading and writing.
- `O_CREAT` — create the file if it doesn't already exist.
- `O_TRUNC` — if the file exists, clear (truncate) its contents on open.
- `O_APPEND` — if the file exists, every write goes to the end of the file rather than overwriting existing content.
- `O_EXCL` — used together with `O_CREAT`; fails with an error if the file already exists.

### `mem` vs. `str` functions

The core difference: `str` functions operate on chars/char arrays and rely on them being null-terminated. `mem` functions instead check raw memory block by block — comparing two `int`s with a `mem`-style function checks byte by byte (4 bytes for an `int`) and only reports "equal" if every byte matches.

### Overlap

"Overlap" is what happens when copying from `src` to `dst` and `src` itself gets modified partway through the copy, corrupting data that hasn't been read yet. Take the Turkish word *"merhaba"* ("hello"): say `src` starts at the `m`, and `dst` starts overlapping partway through, at the `h`. Copying byte-by-byte naively, the buffer gets progressively corrupted: `mermaba` → `mermeba` → `mermera` — each write clobbers a byte that hasn't been read yet. This exact scenario is why `memmove` checks the relative order of the two addresses before copying (and copies back-to-front when the ranges overlap the "wrong" way), whereas plain `memcpy` doesn't bother, and assumes the buffers never overlap.

### Linked lists

Think of a linked list as a series of blocks chained together: each block holds a pointer to the next block's address, and that's what links them. Unlike an array, these blocks don't need to be contiguous in RAM.
([see also](https://www.youtube.com/playlist?list=PLh9ECzBB8tJN9bckI6FbWB03HkmogKrFT))

#### `struct`

Structs let you combine existing data types into a block of your own — effectively, your own custom type.

```c
struct s_block
{
    int  x;
    char a;
};
```

`s_block` is now a block holding an `int x` and a `char a`, laid out contiguously in RAM — if `x` starts at address `1010`, `a` sits at `1014` (right after `x`'s 4 bytes).

#### `typedef`

`typedef` lets you assign a new name to an existing type:

```c
typedef int my_int; // typedef old_name new_name;
```

Since a struct itself counts as a type, `typedef` can give it a shorter, more convenient name too. Using the struct above as-is would require writing:

```c
struct s_block first;
```

every time. But by writing:

```c
typedef struct s_block
{
    int  x;
    char a;
}   t_block;
```

we only need `t_block first;` afterward, instead of the longer form.

### `malloc` / `free`

`malloc` allocates space for us on the heap. `free` releases memory that was allocated — without touching the value that was stored there.

#### `malloc`

`malloc` returns a `void *`. We cast it to whatever type we actually want with a leading parenthesis:

```c
(target_type *)malloc(number_of_bytes)
```

##### `sizeof`

`sizeof` returns how many bytes whatever you pass it takes up — `sizeof(int)`, for instance, returns `4` on most common platforms.

#### `free`

`free` gives back a region of memory that had been allocated (in a sense, "claimed" for our own use). It doesn't touch the value stored there — it just makes that block available to be allocated and overwritten again.
