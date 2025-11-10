# Codeforces Stuff

My attempts at some Codeforces problems.

## Compilation

```bash
g++ -std=c++11 -O2 -Wall -pedantic -Wconversion -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address 1999C.cpp -o build/1999C
```

[Catching silly mistakes with GCC](https://codeforces.com/blog/entry/15547)

## Debugging

A debugging template made by Anshul_Johri has been added to this repo to ease debugging efforts, links to [GitHub](https://github.com/Anshul-Johri-1/Debug-Template) repo and [Codeforces Blog](https://codeforces.com/blog/entry/125435).

To use the template, include `debug.h` in solution and use `debug(var1, var2, ...)` to print out values of variables with different types, works with all types including primitives, derived, and user-defined.

For user-defined data types, a function named `print(SomeStruct s)` is required before using `debug`:

```cpp
struct Point
{
    int x{};
    int y{};
};
void print(Point ob)
{
    cerr << "(" << ob.x << "," << ob.y << ")";
}

// debug(ob);
```

For arrays decayed into pointers, use `debugArr(arr, n)` where n is size of array. A decayed array occurs when an array is passed to a function in which the array will then be converted to a pointer to the first element of the array.

> [!TIP]
> `debug()` statements do not need to be removed during submission to Codeforces, thanks to the `ONLINE_JUDGE` macro which will ignore all debug statements.

Ensure the following is included in the solution file, which will allow Codeforces to ignore debug statements and imports.

```cpp
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
```

## Solutions

### Domino Piling

<div>
  <img src="./assets/domino-piling.png" width="400" />
</div>

Draw to better visualize. Just `n * m / 2` , where 2 is the domino of size 2 x 1. If use int in C++, will round up/down or just floor() in Python to take whole num instead of float which provides the num of dominos that can perfectly fit the M x N matrix excluding the remainder.

### Hit the Lottery

Input size is 1≤n≤10^9 means that cannot use DP due to space complexity of o(n) to create an array of size n will lead to memory overflow when n = 10^9. Since nominal value of bills is constant and can be divided from one another in sequence, can use Greedy to always pick the bill with the greatest nominal value in sequence while eliminating the need for array.

This problem is similar to Coin Change, but coin change must use DP as Greedy does not always guarantee the most optimal solution.

### Young Physicist

Consider vectors a (aX, aY, aZ) and b (bX, bY, bZ), a + b = (aX+bX, aY+bY, aZ+bZ).

### Effective Approach

Instead of following the problem statement to perform linear search, use hashmap instead to allow O(1) lookup of values. Linear search is O(n) and since upper bound for n and m is 1e5, may need to perform 1e10 operations leading to a TLE verdict. For reverse search used by Petya, just take difference of n (length of array) and index of b (target) with the formula, $p=\left| i_{b}-n \right| + 1$.

Hence, no need to perform linear search for every $b_{i}$ in m array with worst case O(n) as need to populate hashmap.

### 102B: Sum of Digits

Take note that the input $n$ upper limit is $10^{100000}\gt 2^{63}-1 \text{ (the limit of long long)}$. Hence, take the input as string and loop through it to obtain individual digits as chars. Since, ASCII digits start from 48 or `'0'`, convert char to int using `int i = '1' - '0';` or `int i = (int)'1' - 48;`. Then, sum up the individual digits. The summation process is to be repeated until the sum contains only one digit.

### 579A: Raising Bacteria

Everday, each bacterium split into 2, so go by 2 to the power of n-th day, $2^{n}$. Since the question only requires the least number of bacteria possible, the number of days taken can be ignored. As a result, if x is a valid value for $2^{n}$ will only need 1 bacteria and it will eventually reach exactly x bacteria. This is valid for values such as $2^{3}$ = x = 8, and $2^{6}$ = x = 64 where only 1 bacteria is needed to be inserted on the first day.

Otherwise, some bacteria will need to be manually inserted at some point in time. For instance, x = 5, bacteria needs to be inserted twice on the first and last day (third day). If you lay out the values like so, 101, it is conincidentally the binary representation of the integer, 5 which contains 2 set bits. Likewise, the binary representation for all $2^{n}$ values only contain 1 set bit. Hence, the answer for a x value may be derived by simply counting the number of set bits.

Bit Tricks:
https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetNaive

### 2000C: Numeric String Template

The implementation is quite trivial since it involves only `std::map` for the solution. However, I overlooked the method of passing std containers to another function, resulting in a TLE verdict.

Originally, I passed both the `std::vector` and `std::string` by value, meaning copies of the original containers will be created which is a linear time operation. It was this exact bug resulted in a TLE, and I simply did not think of it during my debugging efforts.

Time complexity analysis: $o(n\ log\ n)$, where `n = nums.size()`

`std::map` methods such as access, insert, and count are of logarithmic complexity, O(log n). By looping over the `nums` array and inserting elements, the time complexity of `solve()` will be O(n log n). However, with passing by value for `vector<int> nums` and `string s`, it would be $o(n^2m\ log\ n)$ where `n = nums.size()` and `m = s.size()` were traversed with each execution of `solve()`. Hence, especially since, `nums` and `s` combined can be large values, it's best to pass them by reference instead.

## Useful Resources

Great books:

- [Competitive Programmer’s Handbook, Antti Laaksonen](https://cses.fi/book/book.pdf)
- [Competitive Programming 3 - Book 1, Steven Halim & Felix Halim](https://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/cp1.pdf)
