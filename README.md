# EnhancedQuickSort

A C++ project implementing and optimizing the quicksort algorithm using median-of-three pivot selection, `constexpr`, and `std::optional` for error handling.

## Key Optimizations
- **Median-of-three pivot selection** for better pivot choice.
- **`constexpr`** for compile-time pivot calculation.
- **`std::optional`** for optional error handling.

## How to Compile and Run
To compile and run the program, use the following commands in your terminal:

```sh
g++ -std=c++17 -o enhanced_quick_sort enhanced_quick_sort.cpp
./enhanced_quick_sort
