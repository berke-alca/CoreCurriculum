*This project has been created as part of the 42 curriculum by balca.*

# Libft

## Description

Libft is my first project at 42 Heilbronn.

The goal of this project is to create my own C library by reimplementing functions from the standard C library and adding some additional functions.

The project helped me understand how basic C functions actually work internally. While working on it I learned more about pointers, memory, strings, malloc, linked lists and how data is handled in memory.

At the end, all functions are compiled into the library `libft.a`, which can be reused in later projects.

## Library Description

The library is divided into three main parts.

The first part contains reimplementations of libc functions such as `strlen`, `memcpy`, `memmove`, `atoi`, `calloc` and many others. These functions have the same behavior as the original ones, but use the `ft_` prefix.

The second part contains additional functions like `ft_substr`, `ft_strjoin`, `ft_split`, `ft_itoa` and functions for writing to file descriptors.

The last part contains functions for working with linked lists. This includes creating nodes, adding nodes to the front or back, counting nodes, deleting nodes and creating a new list from an existing one.

This part especially helped me understand how pointers can be used to connect different parts of memory.

## Instructions

To compile the library, run:

```bash
make
```

This creates the file:

```bash
libft.a
```

Other available commands are:

```bash
make clean
```

Removes the object files.

```bash
make fclean
```

Removes the object files and `libft.a`.

```bash
make re
```

Deletes everything and compiles the library again.

The project is compiled with the flags:

```bash
-Wall -Wextra -Werror
```

## Resources

During the project I mainly used:

- the Libft subject
- C man pages
- C documentation
- discussions with other students
- my own tests
- Francinette / Paco for testing

### AI Usage

I used AI mainly when I did not understand a concept or when I wanted to understand why something in my code was not working.

I used it for explanations about pointers, memory allocation, linked lists or some edge cases.

I also used it to discuss my own code and understand mistakes, instead of only getting a finished solution.