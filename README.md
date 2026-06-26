*This project has been created as part of the 42 curriculum by labia-fe.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of integers stored in a stack using two stacks (`a` and `b`) and a restricted set of operations, producing the **shortest possible sequence of instructions**.

The challenge lies in minimizing the operation count — the program is evaluated against hard benchmarks:
- 100 numbers sorted in fewer than **700 operations**
- 500 numbers sorted in fewer than **5500 operations**

### Available operations

| Instruction | Effect |
|-------------|--------|
| `sa` | Swap top 2 elements of stack a |
| `sb` | Swap top 2 elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of b to top of a |
| `pb` | Push top of a to top of b |
| `ra` | Rotate stack a up by 1 (first becomes last) |
| `rb` | Rotate stack b up by 1 |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b |
| `rrr` | `rra` and `rrb` simultaneously |

### Algorithm

The program selects the strategy based on stack size:

- **2 elements** — single `sa`
- **3 elements** — hardcoded 3-element sort
- **4–5 elements** — small dedicated sort routines
- **6+ elements** — **chunk-based sort (k-sort)**:
  1. Elements are assigned a rank index (coordinate compression)
  2. Stack a is pushed to stack b in chunks of size ≈ `√n × 1.4`, rotating a when the next target isn't in the current chunk
  3. Stack b is drained back to a by always rotating to the largest remaining element via the cheapest rotation direction

The bonus `checker` program reads a sequence of instructions from stdin and verifies whether they correctly sort the given stack, printing `OK` or `KO`.

## Instructions

### Compilation

```bash
make        # builds push_swap
make bonus  # builds checker (bonus)
make re     # clean rebuild
make fclean # remove all binaries and objects
```

### Usage

```bash
# Sort a list of integers
./push_swap 4 67 3 87 23

# Count the number of operations
./push_swap 4 67 3 87 23 | wc -l

# Verify the result with the bonus checker
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23

# Pass arguments as a quoted string
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

Error cases (non-integers, duplicates, values outside int range) print `Error` to stderr.

## Resources

### References

- [Sorting algorithm complexity — Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — useful for debugging and visualizing the instruction sequence
- [Chunk sort explanation (medium article by Ayaz Aliyev)](https://medium.com/@ayaz.aliyev_97566/push-swap-explained-chunk-sorting-and-more-d4c4d55c5c0b)
- [42 Norm documentation](https://github.com/42School/norminette)

### AI usage

AI (Claude) was used in this project for the following:
- Generating the content of this README file based on the subject requirements and source code
- No algorithm logic, code, or implementation was AI-generated; all sorting code was written and understood by the author independently
