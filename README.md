*This activity has been created as part of the 42 curriculum by <ahasan>, <syaseen>.*

# push_swap

> Sort a stack of integers using a second stack and a very limited instruction set, in as few operations as possible.

## Description

`push_swap` reads a list of unique integers, loads them into stack **a** (first argument on top), and prints to `stdout` the shortest sequence of Push_swap operations it can find that sorts **a** in ascending order, using an empty stack **b** as auxiliary storage.

The goal of the project is to make algorithmic complexity concrete: the cost of an algorithm is measured **in number of operations emitted**, not in CPU time.

The binary embeds four strategies and can pick one at runtime:

| Flag | Strategy | Complexity (in operations) |
|---|---|---|
| `--simple` | <Selection / Insertion> sort adaptation | O(n²) |
| `--medium` | <Chunk sort with ~√n chunks> | O(n√n) |
| `--complex` | <LSD Radix sort on indexes> | O(n log n) |
| `--adaptive` *(default)* | Chooses one of the above from the measured disorder | see below |

### Allowed operations

`sa sb ss pa pb ra rb rr rra rrb rrr` (see the subject for exact semantics).

## Instructions

### Build

```bash
make        # builds ./push_swap
make clean  # removes object files
make fclean # removes objects and binary
make re     # fclean + all
```

Compiled with `cc -Wall -Wextra -Werror`. The Makefile does not relink.

### Usage

```bash
./push_swap [strategy] [--bench] <int> <int> ...
```

- `strategy`: `--simple`, `--medium`, `--complex`, or `--adaptive` (default).
- `--bench`: prints metrics to **stderr** after sorting; operations still go to **stdout**.
- Arguments may be passed as separate values or as one quoted string (`"3 2 1"`). <adjust if your parser differs>
- No arguments: prints nothing.
- Invalid input (non-integer, out of `int` range, duplicates): prints `Error\n` on **stderr**.

### Examples

```bash
$ ./push_swap 2 1 3 6 5 8
$ ./push_swap --simple 5 4 3 2 1
$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
$ ./push_swap --bench $(shuf -i 0-9999 -n 500) >/dev/null
[bench] disorder: 49.93%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 7997
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 4840 rb: 1098 rr: 0 rra: 0 rrb: 1059 rrr: 0
```

### Testing

```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG   # expects OK
./push_swap $ARG | wc -l                  # operation count
```

Also tested: already sorted input, reverse sorted input, 1 / 2 / 3 elements, `INT_MIN` / `INT_MAX`, duplicates, non-numeric input, and Valgrind for leaks.

## Disorder metric

Computed **before any move**, as the fraction of inverted pairs:

```
disorder = (# pairs i<j with a[i] > a[j]) / (n·(n-1)/2)
```

It is `0` for a sorted stack and `1` for a reverse-sorted one. The computation itself is O(n²) but costs **zero** Push_swap operations.

## Algorithms

### 1. Simple — O(n²)

<Describe: e.g. repeatedly find the minimum of a, bring it to the top with the cheapest of `ra`/`rra`, `pb` it, then `pa` everything back.>

**Why O(n²):** each of the n extractions costs up to n/2 rotations, giving at most ~n²/2 + 2n operations.

### 2. Medium — O(n√n)

<Describe: values are indexed 0..n-1 and split into ~√n chunks. Elements of the current chunk are pushed to b (using `rb` to keep smaller ones deeper). Then elements are brought back to a from b in descending order, choosing `rb`/`rrb` by shortest distance.>

**Why O(n√n):** with √n chunks, pushing costs O(n) rotations per chunk pass overall, and each pull from b is bounded by the chunk-sized window, giving O(√n) rotations per element, so O(n·√n) in total.

### 3. Complex — O(n log n)

<Describe: LSD radix sort on normalized indexes. For each bit, `pb` elements whose bit is 1 and `ra` the others, then `pa` everything back.>

**Why O(n log n):** values are normalized to ranks 0..n-1, so there are ⌈log₂ n⌉ passes; each pass emits ≤ 3n operations (`pb`/`ra` pass plus `pa` pass).

### 4. Adaptive

| Disorder | Strategy used | Bound |
|---|---|---|
| `< 0.2` | <Simple> | O(n²) |
| `0.2 ≤ d < 0.5` | <Medium> | O(n√n) |
| `≥ 0.5` | <Complex> | O(n log n) |

**Threshold rationale:** <Explain with your own measurements: e.g. below 0.2 the stack is nearly sorted, so a selection/insertion approach with few displaced elements beats the constant factors of chunking and radix. Around 0.5 the chunk approach stops winning against radix on 500 elements, etc. Include a small table of average operation counts at n = 100 / 500 across disorder levels.>

**Complexity summary (Push_swap model):**
- **Time:** the worst case of the selected regime, as per the table above.
- **Space:** O(n): two stacks (total n elements) plus a rank array / index map.

## Project structure

```
.
├── Makefile
├── README.md
├── bench.c
├── complex.c
├── disorder.c
├── ft_printf.c
├── ft_printf_char.c
├── ft_printf_nbr.c
├── ft_printf_str.c
├── ft_utils.c
├── main.c
├── medium.c
├── parse_args.c
├── parse_flag.c
├── parse_utils.c
├── push.c
├── push_swap.h
├── reverse_rotate.c
├── rotate.c
├── simple.c
├── small_sort.c
├── sort_uttils.c
├── split.c
├── stack.c
├── stack_utils.c
└── swap.c

```

## Contributions

| Learner | Contributions |
|---|---|
| <ahasan> | <e.g. stack operations, simple + medium algorithms, tests> |
| <syaseen> | <e.g. parsing and error handling, complex algorithm, disorder metric, adaptive selector, bench mode> |

Both learners reviewed and can explain the entire codebase.

## Resources

**References**
- [Big-O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)) (basis of the disorder metric)
- <add the tutorials / articles you actually used>

**Use of AI**
- <Task>: <e.g. brainstorming test cases, explaining radix sort on two stacks, reviewing the README structure>.
- Not used for: <e.g. writing the core algorithms>. All AI-assisted content was reviewed, tested, and is understood by both learners.