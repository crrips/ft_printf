# ft_printf

This repository contains the implementation of the ft_printf project, which is a key component of the curriculum at 42 School. The ft_printf project challenges students to create their own version of the printf function in C.

## Project Overview

The ft_printf project requires students to implement a custom version of the printf function, which is used in C to format and print text. The custom printf function, named `ft_printf`, should be able to handle a wide range of format specifiers and arguments, similar to the standard printf function.

Key components and features of the project include:

- Handling various format specifiers (e.g., `%s` for strings, `%d` for integers, `%f` for floating-point numbers, etc.).
- Supporting length modifiers (e.g., `h`, `l`, `ll`, `L`, etc.).
- Managing flags (e.g., `+`, `-`, `0`, etc.).
- Handling precision and width formatting.
- Managing variadic arguments.

## Usage

To use the `ft_printf` function:

1. Clone the repository or download the relevant files.
2. Include the `ft_printf.h` header file in your C program.
3. Call `ft_printf` in your code with the desired format string and arguments, just like you would with the standard printf function.

Example usage:
```c
#include "ft_printf.h"

int main() {
    int value = 42;
    ft_printf("The answer is %d\n", value);
    return (0);
}
```

## Code Structure

The code for the ft_printf project is organized into several files:

- `ft_printf.c`: The main implementation of the `ft_printf` function.
- `ft_printf.h`: The header file containing function prototypes and necessary includes.
- `Makefile`: A Makefile to build the project.

The `ft_printf` function is the core of the project, responsible for parsing the format string, handling format specifiers, and printing the formatted output.

## Documentation

For detailed information about the project's requirements, specific format specifiers, and functionality, refer to the official project documentation and subject provided by 42 School.

## Acknowledgments

The ft_printf project is a valuable learning experience in C programming and provides insight into how the printf function works under the hood. It is often used to improve students' understanding of variadic functions, string manipulation, and memory management in C.
