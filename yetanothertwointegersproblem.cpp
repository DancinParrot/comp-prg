#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REN(i, a, b) for (int i = a; i >= b; i--)

/*
 * Time Complexity: o(n * k) since for each n, have to loop through set k
 * Space Complexity: o(n) where n = a and since 1 <= a <= 10^9, the creation of
 * an array with 10^9 elements for memoization is too much.
 *
 * Very similar to Hit the Lottery in which greedy is able to solve the problem.
 * So just calculate the min num of moves required to make the difference
 * between a and b = 0 and keep taking the largest num from set k.
 */
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  int *a = new int[t];
  int *b = new int[t];

  REP(i, 0, t - 1) { cin >> a[i] >> b[i]; }

  REP(i, 0, t - 1) {
    int m = 0;
    int diff = abs(a[i] - b[i]);

    if (diff == 0) {
      printf("%d\n", m);
      continue;
    }

    REN(x, 10, 1) {
      m += diff / x;
      diff = diff % x;
    }

    printf("%d\n", m);
  }
}
