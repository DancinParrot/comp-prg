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

/*
 * This function checks to make sure index is within bounds of array.
 * @param n Size of array.
 * @param i Index to access.
 * @return true if within bounds, else false
 */
bool in(int n, int i) { return i >= 0 && i < n; }

// NOTE: Valid diagonals are cells whose i+j is the same. This means, valid
// diagonal starts from bottom left to top right. A diagonal with 1 cell is also
// valid. Top left to bottom right diagonal is invalid as in n = 2 grid, sum(1,
// 1) != sum(2, 2), doesn't satisfy the problem's condition for a valid
// diagonal.
void solve() {
  int n, k;
  cin >> n >> k;

  // if chips fewer than longest diagonal with most cells, will either fit the
  // longest diagonal or not if no chips provided.
  if (k <= n) {
    cout << (k > 0) << '\n';
    return;
  }

  k -= n;
  int c = 1, cur = n - 1;

  while (k > 0) {
    // Minus twice as from top and bottom of longest diagonal
    // Use greedy approach: Prefer longest or longer diagonals first
    debug(cur, k);
    k -= cur;
    c++;

    if (k <= 0)
      break;
    k -= cur;
    c++;

    cur--;
  }

  cout << c << '\n';
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
