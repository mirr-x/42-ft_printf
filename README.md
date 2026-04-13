![Libft Banner](https://github.com/mirr-x/42-CC-1337/blob/main/images/github_piscine_and_common_core_banner_ft_printf.png)

# 42-ft_printf
![pp](https://camo.githubusercontent.com/56da27f57391425a37b5eb38c94eadf6ca2d3e27e9669a157bf588908cf9888b/68747470733a2f2f656e637279707465642d74626e302e677374617469632e636f6d2f696d616765733f713d74626e3a414e64394763516231387a6b625565667868364d4151534f66565f3958396932484d555676556c6f4c5126757371703d434155)

A custom implementation of the C standard library function `printf()`. This project is part of the 42 curriculum and focuses on understanding variadic functions, format specifiers, and low-level output operations.

## [TABLE OF CONTENTS]

- [Overview](#overview)
- [Features](#features)
- [Technical Concepts](#technical-concepts)
  - [Variadic Functions](#variadic-functions)
  - [va_list Structure](#va_list-structure)
  - [Registers and ABI](#registers-and-abi)
- [Supported Format Specifiers](#supported-format-specifiers)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Usage](#usage)
- [Implementation Details](#implementation-details)

## [OVERVIEW]

`ft_printf` recreates the behavior of the standard `printf()` function, handling multiple format specifiers and variadic arguments. This project demonstrates deep understanding of C programming fundamentals including memory management, type conversions, and system-level I/O operations.

## [FEATURES]

- [x] Handles multiple format specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`)
- [x] Variable number of arguments support
- [x] Returns the number of characters printed
- [x] Bonus features for enhanced formatting
- [x] Error handling for edge cases

## [TECHNICAL CONCEPTS]

### Variadic Functions

Variadic functions are functions that accept a variable number of arguments. In C, this is achieved using the `<stdarg.h>` library, which provides macros for traversing argument lists.

**Key Macros:**
- `va_start(ap, last)` - Initializes the argument pointer
- `va_arg(ap, type)` - Retrieves the next argument of specified type
- `va_end(ap)` - Cleans up the argument pointer

**Example:**
```c
int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);  // Initialize with last known parameter
    
    // Process arguments
    int value = va_arg(args, int);
    
    va_end(args);  // Clean up
    return count;
}
```

### va_list Structure

`va_list` is an opaque data type used to hold the information needed to retrieve additional arguments. Its internal structure varies by platform and architecture.

**On x86-64 (System V AMD64 ABI):**
```c
typedef struct {
    unsigned int gp_offset;    // Offset in register save area for GP registers
    unsigned int fp_offset;    // Offset in register save area for FP registers
    void *overflow_arg_area;   // Pointer to overflow arguments on stack
    void *reg_save_area;       // Pointer to register save area
} va_list[1];
```

**Fields Explained:**
- **gp_offset**: Tracks position in general-purpose register arguments (rdi, rsi, rdx, rcx, r8, r9)
- **fp_offset**: Tracks position in floating-point register arguments (xmm0-xmm7)
- **overflow_arg_area**: Points to stack memory for arguments beyond registers
- **reg_save_area**: Points to saved register values

### Registers and ABI

The x86-64 calling convention defines how arguments are passed to functions:

**Argument Passing Order:**
1. **Integer/Pointer Arguments** (first 6): `%rdi`, `%rsi`, `%rdx`, `%rcx`, `%r8`, `%r9`
2. **Floating-Point Arguments** (first 8): `%xmm0` - `%xmm7`
3. **Additional Arguments**: Pushed onto the stack (right-to-left)

**Example:**
```c
ft_printf("%d %s %c", 42, "hello", 'A');
```

**Argument Distribution:**
- `%rdi` → pointer to format string `"%d %s %c"`
- `%rsi` → 42 (integer)
- `%rdx` → pointer to "hello"
- `%rcx` → 'A' (character as int)

**Register Save Area:**
When `va_start` is called, registers containing variadic arguments are saved to memory, allowing sequential access through `va_arg`.

**How va_arg Works:**
1. Checks current offset in `va_list`
2. If argument is in registers: reads from `reg_save_area` + offset
3. If argument overflowed to stack: reads from `overflow_arg_area`
4. Increments offset for next argument
5. Returns value cast to requested type

## [SUPPORTED FORMAT SPECIFIERS]

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `'A'` |
| `%s` | String of characters | `"Hello"` |
| `%p` | Pointer address (hexadecimal) | `0x7ffd5a3c2b10` |
| `%d` | Signed decimal integer | `42` or `-42` |
| `%i` | Signed decimal integer | `42` or `-42` |
| `%u` | Unsigned decimal integer | `42` |
| `%x` | Unsigned hexadecimal (lowercase) | `2a` |
| `%X` | Unsigned hexadecimal (uppercase) | `2A` |
| `%%` | Literal percent sign | `%` |

## [PROJECT STRUCTURE]

```
42-ft_printf/
├── ft_printf/
│   ├── ft_printf.c              # Main printf implementation
│   ├── ft_printf.h              # Header file
│   ├── ft_printf_bonus.c        # Bonus features
│   ├── ft_printf_bonus.h        # Bonus header
│   ├── Makefile                 # Compilation rules
│   ├── utilities/
│   │   ├── ft_puthex_dec_fd.c   # Hexadecimal output
│   │   ├── ft_puthex_ptr_fd.c   # Pointer output
│   │   ├── ft_putnbr_fd.c       # Number output
│   │   └── ft_putstr_fd.c       # String output
│   └── utilities_bonus/
│       └── [bonus utility files]
└── README.md
```

## [COMPILATION]

```bash
# Compile the library
make

# Compile with bonus features
make bonus

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

## [USAGE]

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    // Basic usage
    count = ft_printf("Hello, %s!\n", "World");
    
    // Multiple format specifiers
    ft_printf("Number: %d, Hex: %x, Char: %c\n", 42, 42, 'A');
    
    // Pointer printing
    int x = 10;
    ft_printf("Address of x: %p\n", &x);
    
    // Return value
    count = ft_printf("This prints %d characters\n", 25);
    // count will be 26 (including newline)
    
    return 0;
}
```

**Compile with your program:**
```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
./program
```

## [IMPLEMENTATION DETAILS]

### Core Algorithm

1. **Parse Format String**: Iterate through the format string character by character
2. **Detect Format Specifiers**: When `%` is encountered, identify the conversion specifier
3. **Extract Arguments**: Use `va_arg()` to retrieve the corresponding argument from `va_list`
4. **Convert and Output**: Convert the argument to appropriate format and write to file descriptor
5. **Count Characters**: Track total number of characters written
6. **Return Count**: Return total characters printed (or -1 on error)

### Memory and Performance

- **No Dynamic Allocation**: Uses only stack memory for efficiency
- **Direct System Calls**: Writes directly to file descriptors using `write()`
- **Buffer-Free Output**: Immediate character-by-character or small buffer output
- **Type Safety**: Relies on correct format specifier usage (programmer responsibility)

### Edge Cases Handled

- NULL string pointers (`%s` with NULL prints `(null)`)
- Zero values for all numeric types
- Maximum/minimum integer values (`INT_MIN`, `INT_MAX`)
- NULL pointer addresses (`%p` with NULL)
- Consecutive `%%` sequences
- Invalid file descriptor handling

## [LEARNING OUTCOMES]

This project teaches:

- **Variadic Functions**: Deep understanding of how C handles variable arguments
- **Low-Level I/O**: Direct interaction with file descriptors
- **Type Conversions**: Converting between different numeric representations
- **ABI Understanding**: How arguments are passed at the assembly level
- **Memory Layout**: Stack vs. register argument storage
- **Format String Processing**: Parsing and interpreting format specifications
- **Edge Case Handling**: Robust error checking and boundary conditions

## [ADDITIONAL RESOURCES]

- [C Variadic Functions](https://en.cppreference.com/w/c/variadic)
- [x86-64 ABI Documentation](https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf)
- [System V AMD64 Calling Convention](https://wiki.osdev.org/System_V_ABI)
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html)


---

*This project is part of the 42 School curriculum. It must be completed according to the project requirements and norms.*
