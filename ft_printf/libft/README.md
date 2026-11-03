*This project has been created as part of the 42 curriculum by balca.*

# ft_printf

## Description

ft_printf is one of my first projects at 42 Heilbronn, after Libft.

The goal of this project is to recode the `printf()` function from the C standard library. My `ft_printf()` prints the same output as the original and returns the same value, which is the number of printed characters.

It handles the conversions `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` and `%%`.

The project helped me understand variadic functions, which can take a different number of arguments every time they are called. I also learned how numbers are converted into characters and how decimal and hexadecimal numbers are related.

At the end, everything is compiled into the library `libftprintf.a`, which can be used in later projects.

## Instructions

To compile the library, run:

```bash
make
```

This first compiles my Libft with its own Makefile and then creates the file:

```bash
libftprintf.a
```

Other available commands are:

```bash
make clean
```

Removes the object files.

```bash
make fclean
```

Removes the object files and the libraries.

```bash
make re
```

Deletes everything and compiles the library again.

To use it, include `ft_printf.h` in your program and compile it with the library:

```bash
cc main.c libftprintf.a
```

## Algorithm and Data Structure

`ft_printf` goes through the format string character by character. Normal characters are printed directly. When it finds a `%`, the next letter is given to `which_char`, which calls the right function for this conversion. If a `%` is the last character, it is printed like a normal character, so the loop never reads past the end of the string.

I split it like this because the Norm allows only 25 lines per function and because every function should have only one job. Every conversion has its own file, which makes it easy to find, test and change one part without touching the others.

Every helper function returns how many characters it printed. This way `ft_printf` can add everything up and return the total at the end.

The `va_list` is passed to `which_char` as a pointer. So when a value is read with `va_arg`, the original list moves forward and the next `%` gets the next argument and not the same one again. For `%c` the value is read as `int`, because small types like `char` are promoted to `int` when they are passed through `...`.

For numbers I used the idea of my `ft_itoa`: count the digits, allocate a string, fill it from the back with `% 10` and `/ 10`, print it and free it. For hexadecimal I use `% 16` and `/ 16`, and the digit is taken from `"0123456789abcdef"`. `%u` has its own version with `unsigned int`, and `%p` uses `unsigned long`, because a pointer has 8 bytes.

## Resources

During the project I mainly used:

- the ft_printf subject
- man pages
- discussions with other students
- my own test programs, where I compared `ft_printf` with the original `printf`
- Francinette / Paco for testing
- Norminette

### AI Usage

I used AI as a tutor to explain concepts I did not understand, like `va_list` or hexadecimal numbers, and to review my code and find mistakes. Some parts, like the Makefile, were written together with AI step by step, and I made sure I understand every line.