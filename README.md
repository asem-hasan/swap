This activity has been created as part of the 42 curriculum by ahasan, syaseen.

Push_swap

Description

Push_swap is a 42 school project focused on sorting a list of integers using two stacks and a limited set of operations.

The main objective is to sort Stack A in ascending order while generating the smallest possible number of operations.

The project uses two stacks:

- Stack A: Contains the initial list of integers.
- Stack B: Used as temporary storage during sorting.

The project focuses on algorithm design, optimization, data structures, C programming, and memory management.

Instructions

Requirements

- GCC or another C compiler.
- Make.
- Linux or macOS.

Compilation

Clone the repository:

git clone <repository-url>
cd swap

Compile the project:

make

Execution

Run the program with a list of integers:

./push_swap 4 2 7 1 3

You can also provide numbers inside quotes:

./push_swap "5 3 8 1 2"

The program prints the sequence of operations required to sort Stack A.

Makefile Commands

make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything

Stack Operations

The project implements the 11 operations provided by the Push_swap subject.

Operation| Description
"sa"| Swap the first two elements of Stack A.
"sb"| Swap the first two elements of Stack B.
"ss"| Execute sa and sb simultaneously.
"pa"| Push the top element of Stack B onto Stack A.
"pb"| Push the top element of Stack A onto Stack B.
"ra"| Rotate Stack A upwards.
"rb"| Rotate Stack B upwards.
"rr"| Execute ra and rb simultaneously.
"rra"| Reverse rotate Stack A.
"rrb"| Reverse rotate Stack B.
"rrr"| Execute rra and rrb simultaneously.

Sorting Algorithms

The project implements three sorting algorithms, each designed for a different input characteristic.

1. Simple Algorithm — Minimum Extraction

The simple algorithm repeatedly finds the minimum element in Stack A and moves it to Stack B.

Implementation:

1. Find the position of the minimum element in Stack A.
2. Determine the shortest direction to bring it to the top.
3. Use "ra" or "rra" to position the minimum element.
4. Push the minimum element to Stack B using "pb".
5. Repeat until Stack A becomes empty.
6. Move all elements back to Stack A using "pa".

Since the minimum elements are pushed onto Stack B in ascending order of extraction, moving them back to Stack A produces an ascending sequence.

Complexity Analysis:

- Time Complexity: O(n²).
- Auxiliary Space: O(n).

The algorithm performs a linear search for the minimum element during each iteration. Since this process is repeated for up to n elements, the overall time complexity is O(n²).

Why this algorithm?

Minimum Extraction is straightforward and effective for small or mostly ordered inputs. It also provides a simple implementation with predictable complexity.

2. Medium Algorithm — Square Root Chunk-Based Sorting

The medium algorithm uses Chunk-Based Sorting, dividing the normalized indexes into approximately √n chunks.

The chunk size is calculated using the integer square root of the input size:

chunk_size = ft_isqrt(stack_a->size);

For example, with 100 elements:

Number of elements = 100
Chunk size = √100 = 10
Number of chunks = 10

Implementation:

1. Normalize the input values into indexes ranging from 0 to n - 1.
2. Calculate the chunk size using √n.
3. Divide the indexes into consecutive ranges.
4. Process Stack A and identify elements belonging to the current chunk.
5. Push selected elements from Stack A to Stack B using "pb".
6. Use rotations ("ra" and "rb") to organize elements during chunk processing.
7. Continue until all chunks have been processed.
8. Organize the elements in Stack B to facilitate efficient extraction.
9. Move elements back to Stack A using "pa" and the appropriate rotations.

Complexity Analysis:

- Time Complexity: O(n√n).
- Auxiliary Space: O(n).
[11/11/2026 9:26 AM] ! ?: The algorithm processes approximately √n chunks, with each chunk containing approximately √n elements. Its operation count is designed to remain within the O(n√n) upper bound.

Why this algorithm?

Square-root chunking provides a balance between the number of chunks and the number of elements in each chunk. It reduces unnecessary stack movements and provides an efficient sorting strategy for medium-disorder inputs.

3. Complex Algorithm — Binary Radix Sort (LSD)

The complex algorithm implements Binary Radix Sort using the Least Significant Digit (LSD) approach.

The algorithm processes the binary representation of normalized indexes, starting with the least significant bit and moving toward the most significant bit.

Implementation:

1. Normalize all values into indexes ranging from 0 to n - 1.
2. Calculate the maximum number of bits required using "get_max_bits()".
3. Start processing from bit 0.
4. Examine the current bit of each element in Stack A.
5. If the current bit is 0, push the element to Stack B using "pb".
6. If the current bit is 1, rotate Stack A using "ra".
7. After processing all elements, move every element from Stack B back to Stack A using "pa".
8. Repeat for each remaining bit.

The process continues until all required bits have been processed.

Why LSD Radix Sort?

Binary Radix Sort is suitable for large inputs because it processes elements by individual bits instead of repeatedly comparing pairs of values.

Normalization allows the algorithm to work with both positive and negative integers without directly processing their original values.

Complexity Analysis:

- Time Complexity: O(n log n).
- Auxiliary Space: O(n).

The algorithm processes n elements for each bit, and the number of bits required to represent the normalized indexes is O(log n).

Therefore, the overall complexity is O(n log n).

Disorder Calculation

The project measures the disorder of the input using the Inversion Count method.

An inversion is a pair of elements in which an earlier element is greater than a later element.

For example:

Input: 3 1 2

The inversions are:

(3, 1)
(3, 2)

There are two inversions out of three possible pairs.

The disorder formula is:

Disorder = Inversions / Maximum Possible Inversions

Where:

Maximum Possible Inversions = n * (n - 1) / 2

The implementation uses an integer scale of 10000 instead of floating-point values:

return (mistakes * 10000 / pair);

Therefore:

- 0 represents completely sorted input.
- 10000 represents completely reversed input.

Complexity Analysis:

- Time Complexity: O(n²).
- Auxiliary Space: O(1).

The algorithm compares each element with the elements that follow it to count all inversions.

Custom Adaptive Algorithm

The adaptive algorithm selects a sorting strategy based on the measured disorder of the input.

It uses three regimes defined by the project requirements.

1. Low Disorder

Condition:

disorder < 0.2

Equivalent implementation threshold:

disorder < 2000

Selected strategy:

Simple Algorithm — Minimum Extraction

Complexity:

- Time: O(n²).
- Auxiliary Space: O(n).

This strategy uses minimum extraction to sort the input.

2. Medium Disorder

Condition:

0.2 <= disorder < 0.5

Equivalent implementation thresholds:

disorder >= 2000 && disorder < 5000

Selected strategy:

Medium Algorithm — Square Root Chunk-Based Sorting

Complexity:

- Time: O(n√n).
- Auxiliary Space: O(n).

The strategy divides the input into approximately √n chunks and processes each chunk using the two stacks.

3. High Disorder

Condition:

disorder >= 0.5

Equivalent implementation threshold:

disorder >= 5000

Selected strategy:

Complex Algorithm — Binary Radix Sort (LSD)

Complexity:

- Time: O(n log n).
- Auxiliary Space: O(n).

This strategy processes normalized indexes bit by bit using Stack A and Stack B.

Adaptive Strategy Summary

Disorder| Strategy| Time Complexity
Below 0.2| Minimum Extraction| O(n²)
0.2 to below 0.5| √n Chunk-Based Sorting| O(n√n)
0.5 or above| Binary Radix Sort (LSD)| O(n log n)

Threshold Rationale
[11/11/2026 9:26 AM] ! ?: The thresholds divide the input into three ordering regimes:

- Low disorder: The input is mostly ordered, making a simple sorting strategy suitable.
- Medium disorder: The input has a moderate amount of disorder, making chunk-based processing a suitable approach.
- High disorder: The input is highly disordered, making Radix Sort a suitable strategy for larger sorting workloads.

The thresholds follow the requirements specified in the project subject.

Team Responsibilities

The project was divided between two teammates.

Teammate A — Core Operations and Algorithms

Responsibilities:

- Implement the stack data structure and helper functions.
- Implement the 11 Push_swap operations.
- Implement the Simple Algorithm using minimum/maximum extraction methods.
- Implement the Medium Algorithm using square-root chunk-based sorting.
- Unit-test stack operations and sorting algorithms.

Teammate B — Input Handling and Optimization

Responsibilities:

- Parse and validate command-line arguments.
- Handle invalid integers and integer overflow.
- Detect duplicate numbers.
- Handle errors and memory cleanup.
- Implement the Complex Algorithm using Binary Radix Sort.
- Implement the disorder calculation.
- Implement the custom adaptive algorithm.
- Test input validation and adaptive strategy selection.

Error Handling

The program handles invalid inputs, including:

./push_swap 1 2 2
./push_swap 1 abc 3
./push_swap 2147483648
./push_swap ""

The program should:

- Detect duplicate numbers.
- Reject invalid numeric arguments.
- Detect integer overflow.
- Handle empty or invalid arguments.
- Release allocated memory when an error occurs.

For invalid input, the program prints "Error" followed by a newline to standard error.

Testing

Different input types should be tested to verify the correctness of the algorithms.

Small Inputs

./push_swap 2 1
./push_swap 3 1 2

Medium Inputs

./push_swap 8 3 6 1 5 2 7 4

Large Inputs

ARG=$(shuf -i 0-499 -n 500 | tr '\n' ' ')
./push_swap $ARG

Already Sorted Input

./push_swap 1 2 3 4 5

Invalid Inputs

./push_swap 1 2 2
./push_swap 1 abc 3
./push_swap 2147483648

The generated operations should be checked using a compatible Push_swap checker to verify that Stack A is sorted correctly and Stack B is empty.

Resources

Documentation and References

- "42 Push_swap Subject" — Project requirements and rules.
- "C Programming Language" — C language documentation.
- "Radix Sort" — Understanding the Radix Sort algorithm.
- "Sorting Algorithms" — Sorting techniques and complexity.
- "Big O Cheat Sheet" — Algorithm complexity reference.

AI Usage

AI tools were used as supporting resources during the development of this project.

AI assistance was used for:

- Understanding sorting algorithms, including minimum extraction, chunk-based sorting, and Binary Radix Sort.
- Understanding disorder calculation using the Inversion Count method.
- Discussing algorithm optimization and complexity analysis.
- Explaining C programming concepts, pointers, stack operations, and memory management.
AI was used as a learning and support tool. The implementation, testing, debugging, and final technical decisions were handled by the project team.

Conclusion

Push_swap combines C programming, data structures, algorithm design, and optimization.

By implementing multiple sorting strategies and measuring input disorder, the project aims to select an appropriate sorting approach for different input characteristics while respecting the limited set of available stack operations.
