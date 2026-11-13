*This project has been created as part of the 42 curriculum by balca.*

# ft_printf

## Description

ft_printf is one of my first projects at 42 Heilbronn, after Libft.

The goal of this project is to recode the `printf()` function. My `ft_printf()` handles the conversions `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` and `%%`, and returns the number of printed characters like the original.

The project helped me understand variadic functions and how numbers are converted into characters in decimal and hexadecimal.

## Instructions

To compile the library, run:

```bash
make
```

This first compiles my Libft with its own Makefile and then creates `libftprintf.a`.

Other available commands are `make clean`, `make fclean` and `make re`.

To use it, include `ft_printf.h` and compile your program with the library:

```bash
cc main.c libftprintf.a
```

## Algorithm and Data Structure

`ft_printf` goes through the format string character by character. Normal characters are printed directly. When it finds a `%`, the next letter is given to `which_char`, which calls the right function for this conversion.

I split it like this because of the Norm (max. 25 lines per function) and so every function has only one job. Every conversion has its own file, which makes it easy to test and change.

Every helper function returns how many characters it printed, so `ft_printf` can add everything up and return the total.

The `va_list` is passed as a pointer, so when a value is read with `va_arg`, the original list moves forward and the next `%` gets the next argument.

For numbers I used the idea of my `ft_itoa`: count the digits, allocate a string, fill it from the back with `% 10` and `/ 10`, print it and free it. For hexadecimal I use `% 16` and `/ 16`, and the digit is taken from `"0123456789abcdef"`. `%p` uses `unsigned long`, because a pointer has 8 bytes.

## Resources

- the ft_printf subject
- `man 3 printf` and `man 3 stdarg`
- discussions with other students
- my own tests compared with the original `printf`
- Francinette / Paco and Norminette

### AI Usage

I used AI as a tutor when I did not understand a concept, for example `va_list`, hexadecimal numbers or how a Makefile works.

I also used it to review my code, understand error messages and test edge cases. Some parts, like the Makefile and the hex version of my `itoa`, were written together with AI step by step, and I made sure I understand every line.