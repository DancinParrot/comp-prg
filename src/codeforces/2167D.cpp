#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

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

  int valid = INF;
  vector<ll> nums(n);
  for (auto &a : nums) {
    cin >> a;
  }

  /*
   * Numbers in nums(n) array can be as big as 1e18. However, consider possible
   * prime factors for each number: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
   * 41, 43, 47, 53, 59, 61, 67, ...
   *
   * If multiply prime factors, product will reach 1e18 very soon. In fact to
   * reach 1e18, only prime numbers until 53 are needed. So can just brute
   * force, worst case will be O(n * 53), or O(n).
   */
  for (auto a : nums) {
    REP(i, 2, INF) {
      ll g = gcd(i, a);
      debug(i, a, g, valid);

      // ax + by = gcd(a, b) = gcd(b, a % b) = 1
      // a = bq + r where q = a / b and r = a % b
      // a - (a/b)b = a % b
      // (a > b)  a / b = c, a % b = r
      // gcd(a, 0) = a
      // gcd(0, b) = b
      // gcd(a, b) = gcd(b, a - b) = gcd(b, q)

      if (g == 1) {
        valid = min(i, valid);
        break;
      }
    }
  }
  cout << valid << '\n';
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
