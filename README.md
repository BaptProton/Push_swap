# push_swap

`push_swap` is a 42-school project where you must sort a list of integers using two stacks (A and B) and a very limited set of operations. The program prints the sequence of operations needed to sort stack A in ascending order.

The goal is not only to sort correctly, but also to use as few operations as possible.

## What this program does

- Takes integers as arguments.
- Builds stack A with the input values (stack B starts empty).
- Outputs instructions (one per line) among the allowed operations to sort stack A.
- Prints `Error` on invalid input (non-numeric, duplicates, overflow, etc.).

### Allowed operations (printed by the program)

- `sa`, `sb`, `ss`: swap the first 2 elements of stack A / B / both
- `pa`, `pb`: push the top element from B to A / from A to B
- `ra`, `rb`, `rr`: rotate A / B / both (top becomes bottom)
- `rra`, `rrb`, `rrr`: reverse rotate A / B / both (bottom becomes top)

## Concepts / new notions practiced

- Parsing & validation: handling multiple arguments and the single-string form (`"1 2 3"`)
- Robust error handling: duplicates, integer overflow/underflow, invalid characters
- Linked lists as stacks: building, traversing, freeing
- Sorting strategy design under constraints (only stack operations)
- Optimization ideas: indexing values, choosing targets, computing move costs, reducing rotations
- Time/space reasoning: building an approach that scales better than naive sorting

## How to build

From the project root:

```bash
make
```

This also builds `libft` (used by the project).

## How to use

### Basic usage

```bash
./push_swap 3 2 1
```

You can also pass everything as one quoted string:

```bash
./push_swap "3 2 1"
```

The program prints a list of operations. If the input is already sorted (or empty/invalid according to the subject), it prints nothing.

### Useful checks (manual)

Count how many operations are produced:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

If you have the 42 `checker` program available, you can verify correctness like this:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Project structure

After refactoring, the repository is organized like this:

- `src/`: mandatory project sources
- `include/`: project headers (`push_swap.h`)
- `libft/`: your Libft
- `Makefile`: builds `push_swap` and `libft`
