*This project has been created as part of the 42 curriculum by aanjum, balca.*

# push_swap

## Description

push_swap is a sorting challenge with strict rules. The program receives a list of
integers, puts them in a stack called **a**, and must sort them in ascending order using
only a second empty stack **b** and eleven allowed moves. It does not print the sorted
numbers: it prints the **list of moves** that sorts them. The goal is to use as few
moves as possible.

The allowed moves are:

| Move | Effect |
| --- | --- |
| `sa` / `sb` / `ss` | swap the two top numbers of a, of b, or of both |
| `pa` / `pb` | take the top number of one stack and put it on top of the other |
| `ra` / `rb` / `rr` | rotate up: the top number goes to the bottom (a, b, or both) |
| `rra` / `rrb` / `rrr` | rotate down: the bottom number comes to the top (a, b, or both) |

This version of the subject asks for more than one algorithm. Our program contains four
strategies, one per complexity class, and measures how unsorted the input is before it
starts:

| Flag | Strategy | Complexity (in moves) |
| --- | --- | --- |
| `--simple` | selection sort | O(n²) |
| `--medium` | chunk sort with a sliding window | O(n√n) |
| `--complex` | binary LSD radix sort | O(n log n) |
| `--adaptive` (default) | chooses one of the above from the measured disorder | per regime |

All complexities are counted in **push_swap moves**, as the subject requires, not in
array operations.

## Instructions

### Compilation

```bash
make        # builds libft, then push_swap
make clean  # removes object files
make fclean # removes object files, libft.a and push_swap
make re     # full rebuild
```

The project is compiled with `cc -Wall -Wextra -Werror`. Our `libft` (including our
`ft_printf`) is in the `libft/` folder and is built automatically by the main Makefile.

### Usage

Each number is passed as its own argument. Flags start with `--` and may appear before
or between the numbers.

```bash
./push_swap 3 2 5 1 4             # adaptive strategy (default)
./push_swap --simple 3 2 5 1 4    # force one strategy
./push_swap --medium 3 2 5 1 4
./push_swap --complex 3 2 5 1 4
```

The moves are printed on standard output, one per line. Some special cases:

- No numbers (for example `./push_swap` or `./push_swap --bench`): nothing is printed.
- Numbers already sorted: nothing is printed.
- Invalid input (a value that is not an integer, a number outside the `int` range, a
  duplicate, an empty argument, or an unknown flag next to numbers): `Error` is printed
  on standard error.
- A list inside one argument, such as `"3 2 1"`, is not accepted: each number must be a
  separate argument.

### Benchmark mode

`--bench` adds a report on **standard error** after sorting, so standard output still
contains only the moves:

```bash
./push_swap --bench 8 3 12 1 9 5 2 7 4 10 6 11 > /dev/null
```

```
[bench] disorder: 42.42%
[bench] strategy: adaptive -> medium, O(n*sqrt(n))
[bench] total_ops: 38
[bench] sa: 0 sb: 0 ss: 0 pa: 12 pb: 12 ra: 3 rb: 7 rr: 0 rra: 0 rrb: 4 rrr: 0
```

It shows the disorder measured before any move, the strategy that really ran with its
complexity class, the total number of moves, and the count of each move.

### Checking the result

The 42 checker reads the moves and tells whether they sort the input:

```bash
ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG     # prints OK or KO
./push_swap $ARG | wc -l                    # number of moves
```

## How the program works

`main` runs the same steps for every input:

1. **Parse** the flags and the numbers, rejecting anything invalid.
2. **Build the stacks**: stack a holds the numbers, stack b is an empty array of the
   same size.
3. **Convert to ranks**: every number is replaced by its position in sorted order.
4. **Measure the disorder** of stack a, before any move.
5. **Dispatch** to the chosen strategy, which prints its moves through `do_op`.
6. **Print the benchmark** if `--bench` was given, then free everything.

### Key ideas

**Stacks as arrays.** Each stack is an `int` array with a size (`t_stack`). Index 0 is
the top. A push or a rotation shifts the array. This costs a little CPU time, but it does
not change the number of moves, which is what the project measures, and it keeps memory
simple: one `malloc` per stack.

**Ranks.** Before sorting, `make_ranks` replaces each value by how many values are
smaller than it, so `42 -7 100` becomes `1 0 2`. The order does not change, but the
algorithms can now work with the numbers 0 to n-1. Chunk sort needs this for its window,
and radix sort needs it so that the number of bits depends only on n.

**Disorder.** As defined in the subject, disorder is the share of pairs (i, j), with i
above j in stack a, where the upper number is bigger. A sorted stack has disorder 0, a
reversed stack has disorder 1. We store it as an integer from 0 to 10000 (basis points)
so that no floating point is needed: the thresholds become `< 2000` and `< 5000`, and
`4987` prints as `49.87%`.

**One entry point for all moves.** Every algorithm calls `do_op(ps, RA)` and never
prints by itself. `do_op` applies the move, increases its counter, and prints its name.
This is what makes the benchmark counts exact.

## Algorithms

### Small inputs (2 to 5 numbers, adaptive only)

Small inputs have their own fixed method, because the general algorithms waste moves on
them.

- **2 numbers**: `sa` if they are in the wrong order.
- **3 numbers** (`sort_three`): first put the biggest number at the bottom (`ra` if it is
  on top, `rra` if it is in the middle). The two numbers left on top then need at most one
  `sa`. This is at most **2 moves**.
- **4 or 5 numbers**: bring the smallest number to the top the short way and `pb` it,
  until 3 numbers are left. Sort those three, then `pa` everything back. This is at
  most **10 moves** for 5 numbers.

Forced flags (`--simple`, `--medium`, `--complex`) always run their own algorithm, even on
small inputs, because the subject says a selector forces that algorithm.

### Simple: selection sort, O(n²)

1. Find the smallest number in a.
2. Rotate it to the top the short way: `ra` if it is in the top half, `rra` otherwise.
3. `pb` it.
4. Repeat until a is empty, then `pa` everything back. b holds the numbers with the
   biggest on top, so they return to a in ascending order.

**Upper bound**: each of the n rounds needs at most n/2 rotations plus one push, and the
final `pa` phase costs n moves, so the total is O(n²). It is very cheap when the input is
almost sorted, because the smallest number is then always close to the top.

### Medium: chunk sort with a sliding window, O(n√n)

The window size is `k = ⌊√n⌋ × 3 / 2` (15 for 100 numbers, 33 for 500). The square root
is computed with an integer loop, because `math.h` is not allowed.

**Phase 1, fill b** (`fill_b`). A counter `i` counts the numbers already pushed. For the
top of a:

- below `i`: `pb` then `rb` (it goes to the bottom of b)
- below `i + k`: `pb` (it stays on top of b)
- otherwise: `ra` and look at the next number

There is always a number below `i + k` left in a, because only `i` numbers have left a so
far, so this phase always ends.

**Phase 2, refill a**. While b is not empty, find the biggest number of b, rotate it to
the top the short way (`rb` or `rrb`), and `pa` it.

**Upper bound**: in phase 1 the window moves forward one step per push, so a number
can be skipped by `ra` only about n/k times before it enters the window: at most about
n × n/k = O(n√n) moves. Phase 1 leaves b roughly ordered, with the biggest numbers near
its top and bottom, so in phase 2 each maximum is found about k positions from an end:
about n × k = O(n√n) moves.

### Complex: binary LSD radix sort, O(n log n)

Radix sort sorts by one binary digit (bit) at a time, starting with the least significant
bit (LSD). Two stacks match the two possible values of a bit.

For each bit, from the rightmost one up to the highest bit of n - 1:

1. Look at the top of a n times: if the current bit is 0, `pb`; if it is 1, `ra`.
2. `pa` everything back from b.

After each pass, a is sorted by all the bits seen so far, and the order from earlier
passes is kept. After the last bit, a is fully sorted.

**Upper bound**: ranks go from 0 to n - 1, so there are ⌈log₂ n⌉ bits. Each pass costs n
moves (one `pb` or `ra` per number) plus at most n `pa`, so at most 2n moves per bit and
O(n log n) in total. The count does not depend on the input order: 100 random numbers
always take 1084 moves and 500 always take 6784.

### Adaptive (default)

| Disorder | Method | Class required by the subject |
| --- | --- | --- |
| 5 numbers or fewer | small sort | (constant) |
| below 0.2 | selection sort | O(n²) |
| 0.2 to below 0.5 | chunk sort | O(n√n) |
| 0.5 and above | radix sort | O(n log n) |

**Why these regimes.** The thresholds 0.2 and 0.5 are fixed by the subject; our part was
to choose the method for each one:

- **Low disorder**: most numbers are already near their place, so selection sort often
  finds the next minimum close to the top and needs few rotations. It is also the
  simplest method to reason about, and it stays within the O(n²) bound the subject
  requires for this regime.
- **Medium disorder**: chunk sort is our fastest algorithm on mixed input, and its cost
  stays O(n√n) whatever the order.
- **High disorder**: radix sort gives a guaranteed O(n log n) bound and a cost that does
  not depend on how badly the input is ordered.
- **Very small inputs**: the fixed small sorts are much cheaper than any general method.

**Space**: every regime uses the two stacks (two `int` arrays of size n) and a few
counters, so O(n) memory in total. Ranking briefly uses one more array of size n. Nothing
else is allocated during sorting.

### Measured results

Averages over 20 random inputs per row, checked with `checker_linux`:

| Strategy | 100 numbers | 500 numbers |
| --- | --- | --- |
| `--simple` | 1467 | 32298 |
| `--medium` | 568 | 5020 |
| `--complex` | 1084 | 6784 |
| adaptive (default) | 851 (max 1084) | 5813 (max 6784) |

Random input has a disorder close to 0.5, so in adaptive mode it goes either to chunk
sort or to radix sort.

## Project structure

| File | Content |
| --- | --- |
| `main.c` | the program flow described above |
| `parsing.c` | `is_number`, `ft_atoi_ps` (reads into a `long` to detect overflow), `count_numbers`, `has_duplicates`, `parse_args` |
| `flag.c` | `is_flag`, `set_flag`, `parse_flags`: reads `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench` |
| `error.c` | `print_error`: frees the stacks and prints `Error` on standard error |
| `init_stacks.c` | `init_stacks`: stack a uses the parsed array, stack b gets an empty array of the same size |
| `ops_swap.c`, `ops_push.c`, `ops_rotate.c`, `ops_reverse.c` | the eleven moves |
| `do_op.c` | `do_op`: applies a move, counts it, prints its name |
| `stack_utils.c` | `is_sorted`, `free_stacks` |
| `ranks.c` | `make_ranks`: converts values to ranks 0 to n-1 |
| `disorder.c` | `compute_disorder`: disorder in basis points |
| `dispatch.c` | `dispatch` and `choose_adaptive`: picks and runs the strategy |
| `sort_small.c` | sorts for 2 to 5 numbers |
| `sort_simple.c` | selection sort |
| `sort_medium.c` | chunk sort |
| `sort_complex.c` | binary radix sort |
| `bench.c` | `print_bench`: the `--bench` report on standard error |
| `push_swap.h` | the structures `t_stack` and `t_push_swap`, the enums `t_op` and `t_strat`, all prototypes |
| `libft/` | our libft, including `ft_printf` |

## Testing

We tested with the `checker_linux` program from the project page:

- random lists of 100 and 500 numbers for every strategy, comparing the move count with
  the subject's limits;
- every possible order of 2, 3, 4 and 5 numbers in adaptive mode, and every order of 3
  and 5 numbers with each forced flag;
- invalid input: letters, signs alone, empty strings, numbers just above `INT_MAX` and
  below `INT_MIN`, duplicates, unknown flags;
- already sorted input, which must print nothing;
- memory with `valgrind --leak-check=full`, on normal runs and error runs;
- `norminette` on all files, libft included.

## Contributions

| Learner | Main work |
| --- | --- |
| **aanjum** (Areej) | moves `sa`, `sb`, `ss`, `pa`, `pb`; `is_sorted` and `free_stacks`; ranks; disorder; dispatch and adaptive choice; small sorts; chunk sort (`--medium`); benchmark mode; test plan |
| **balca** (Berke) | Makefile and libft; parsing and error handling; flags; moves `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`; `do_op`; `init_stacks`; selection sort (`--simple`); radix sort (`--complex`) |
| Both | the shared header and data structures, `main`, reviewing each other's code, testing, this README |

Each of us read and tested the other's code, so both of us can explain every part of the
project.

## Resources

- The push_swap subject and evaluation sheet (42)
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort), Wikipedia
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort), Wikipedia
- [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort), Wikipedia (the idea behind chunk sort)
- [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)), Wikipedia (the idea behind the disorder metric)
- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation), Wikipedia
- [push_swap algorithms overview](https://42-guide.gitbook.io/42-guide/core-curriculum/rank-02/push-swap/algorithms), 42 Guide
- [Valgrind quick start](https://valgrind.org/docs/manual/quick-start.html)
- [42 Norm (norminette)](https://github.com/42School/norminette)
- C manual pages: `malloc(3)`, `free(3)`, `write(2)`

### AI usage

We used AI for understanding:

- **Explanations**: the disorder metric, complexity counted in moves, binary radix sort,
  and Norm and memory questions, and understanding other algorithms.

- **Documentation**: help with structuring and wording this README.

The design decisions, the integration of the parts, and the final checks are our own
work.