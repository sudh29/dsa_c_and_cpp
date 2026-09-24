# 0_Basics: C & C++ Fundamentals

This module covers core foundational programming constructs in C (C11) and modern C++ (C++20), focusing on memory management, pointers, object-oriented programming, and essential mathematical algorithms.

## Programs

### Pure C (C11)
| File | Topic / Concept |
|------|-----------------|
| [c_syntax_and_types.c](c_syntax_and_types.c) | Data types, type sizes, limits, arithmetic operators |
| [c_pointers_and_memory.c](c_pointers_and_memory.c) | Pointers, dereferencing, manual dynamic allocation (`malloc`/`free`) |
| [c_structs_and_typedefs.c](c_structs_and_typedefs.c) | Custom `struct` definitions, `typedef`, pass-by-pointer |
| [swap_two_numbers.c](swap_two_numbers.c) | In-place swapping via pointers and bitwise XOR |
| [prime_check.c](prime_check.c) | Optimized trial division primality test ($O(\sqrt{n})$) |
| [count_set_bits.c](count_set_bits.c) | Brian Kernighan's set-bit counting algorithm |

### Modern C++ (C++20)
| File | Topic / Concept |
|------|-----------------|
| [cpp_hello_and_io.cpp](cpp_hello_and_io.cpp) | Standard streams (`std::cout`, `std::cin`), string streams |
| [cpp_spaceship_operator.cpp](cpp_spaceship_operator.cpp) | C++20 three-way comparison operator (`<=>`) |
| [cpp_references_and_functions.cpp](cpp_references_and_functions.cpp) | Pass-by-reference (`&`), lambdas, function composition |
| [cpp_classes_and_oop.cpp](cpp_classes_and_oop.cpp) | Classes, constructors, encapsulation, const-correctness |
| [cpp_stl_containers.cpp](cpp_stl_containers.cpp) | `std::vector`, `std::unordered_map`, `std::unordered_set` |
| [cpp_anagrams.cpp](cpp_anagrams.cpp) | Anagram validation using frequency hashing |
| [cpp_pattern_count.cpp](cpp_pattern_count.cpp) | Substring search and pattern occurrence counting |
| [cpp_grid_paths.cpp](cpp_grid_paths.cpp) | Unique grid paths via Dynamic Programming |
| [cpp_file_io.cpp](cpp_file_io.cpp) | File stream processing with `std::ifstream` and `std::ofstream` |
| [system_details.cpp](system_details.cpp) | Compiler identification, `__cplusplus` standard version |

## Compilation & Execution
```bash
# Compile C programs
gcc -std=c11 -Wall -Wextra c_syntax_and_types.c -o syntax && ./syntax

# Compile C++ programs
g++ -std=c++20 -Wall -Wextra cpp_spaceship_operator.cpp -o spaceship && ./spaceship
```
