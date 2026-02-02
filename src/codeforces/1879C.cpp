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

void mod(ll &a, ll b) { a = (a * b) % 998244353; }

void solve() {
  // Return:
  // 1. min number of operations to make s alternating
  // 2. number of different shortest sequences of operations

  // Solution for (1):
  // Seperate s into blocks of identical characters e.g. 00011 into [000, 11]
  // where number of blocks = k = 2. In this case, we only need to choose 1 from
  // each block to make string s alternating and erase the rest, e.g. [0, 1]
  // which is basically k. Hence, we need to erase (n - k) characters or (n - k)
  // operations to make s alternating.

  // Solution for (2):
  // Let the length of each block, i, be len[i]. For each block, there are
  // len[i] ways to choose one character and erase the rest, e.g. for [000]
  // choose 1 to preserve and erase the rest so, 3! / (3-1)! = 3 = len[i].
  // Hence, multiply the product of every block together to obtain the total
  // permutations for **one** operation = PI(len[i]). This means for one
  // operation or to erase one character, there are PI(len[i]) possible orders.
  // To get for all operations to erase all necessary characters, multiply the
  // product with the factorial of (1).
  //
  // Hence, return: PI(len[i]) * (n-k)!

  // For example:
  // 1000101011000 = [1, 000, 1, 0, 11, 000] = (11 - 6) = 5 operations
  //
  // For number of different shortest sequences of one operation, it can be
  // found like so: len[0] * len[1] * len[2] * len[3] * len[4] * len[5] = 1 * 3
  // * 1 * 1 * 2 * 3 = 18 permutations for one operation. THis means, after you
  // performed 1 operation and erased 1 character, the remaining characters
  // require different orders.
  //
  // The final answer is: 18 * 5!

  string s;
  cin >> s;

  vector<ll> lens;
  char prev = s[0];
  ll len = 0;
  for (auto c : s) {
    if (prev == c) {
      len++;
      continue;
    }

    lens.PB(len);
    len = 1;
    prev = c;
  }

  lens.PB(len);

  debug(lens);

  // (1) number of operations
  ll ops = s.size() - lens.size();

  // (2) number of different shortest sequences of operations
  ll ans = 1;
  for (auto i : lens) {
    mod(ans, i);
  }

  REP(i, 1, ops + 1) { mod(ans, i); }

  cout << ops << " " << ans << '\n';
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
