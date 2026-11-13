*This project has been created as part of the 42 curriculum by balca.*

# get_next_line

## Description

`get_next_line` is a function that reads from a file descriptor and returns **one line per call**, including the trailing `\n`. Calling it in a loop reads a whole file (or standard input) line by line.

```c
char	*get_next_line(int fd);
```

It returns the next line, or `NULL` when there is nothing left to read or an error occurred.

## How it works

The file is read in chunks of `BUFFER_SIZE` bytes. Since a chunk can end in the middle of a line or contain several lines, the leftover data is kept in a `static` variable (the *stash*) that survives between function calls.

1. **Read:** read chunks and append them to the stash until it contains a `\n` or the file ends.
2. **Extract:** copy everything up to and including the first `\n` into a new string: this is the returned line.
3. **Trim:** keep only the rest after the `\n` in the stash for the next call.

## Files

| File | Content |
| :--- | :--- |
| `get_next_line.c` | Main function and the reading loop |
| `get_next_line_utils.c` | Helper functions (`ft_strlen`, `ft_strchr`, `ft_strjoin`, `extract_line`, `trim_stash`) |
| `get_next_line.h` | Prototypes and the default `BUFFER_SIZE` (42) |

## Usage

Compile it together with your own `main.c`. The buffer size can be set at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

## Resources

- the get_next_line subject
- the man pages of `read`, `malloc` and `free`
- discussions with other students
