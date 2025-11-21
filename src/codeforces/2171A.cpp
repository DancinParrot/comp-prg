#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const int INF = 1e9;

/*
 * This function checks to make sure index is within bounds of array.
 * @param n Size of array.
 * @param i Index to access.
 * @return true if within bounds, else false
 */
bool in(int n, int i) { return i >= 0 && i < n; }

void solve() {
  int n;
  cin >> n;
  // Check for multiples of 4, which are also divisible by 2
  // e.g. 12 is a multiple of 4:
  // Then, compute the number of multiples of 4 which are <= n, the remainders
  // will be chickens:
  // 4, 8, 12 are multiples of 4 that are <= n and hence, 12 / 4 = 3 multiples,
  // the remainder will be chickens only, so add 1 to be (n / 4 + 1, the
  // combinations will be as follows:

  // There can be 4 combinations of cows: 1 cow, 2 cow, ..., n cow, so n / 4.
  // When there's no cow, only chickens remain so + 1. 1 cows 4 chickens = 1 * 4
  // + 4 * 2 = 12 2 cows 2 chickens = 2 * 4 + 2 * 2 = 12 3 cows 0 chickens = 4 *
  // 3 = 12 0 cows 6 chickens = 6 * 2 = 12

  // If even, e.g. 4 = 100; if odd, e.g. 5 = 101, so 1 & 1 will be odd number.
  // Odd number will not have any valid configuration.
  cout << ((n & 1) ? 0 : (n / 4) + 1) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
