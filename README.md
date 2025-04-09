# Codeforces Stuff

My attempts at some Codeforces problems.

## Compilation

```bash
g++ -std=c++11 -O2 -Wall -pedantic -Wconversion -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address 1999C.cpp -o build/1999C
```

[Catching silly mistakes with GCC](https://codeforces.com/blog/entry/15547)

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

## Useful Resources

Great books:

- [Competitive Programmer’s Handbook, Antti Laaksonen](https://cses.fi/book/book.pdf)
- [Competitive Programming 3 - Book 1, Steven Halim & Felix Halim](https://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/cp1.pdf)
