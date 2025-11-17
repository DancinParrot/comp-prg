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
  ll a, b, n;
  cin >> a >> b >> n;

  // Make sure length is same as whichever is smallest a/m or b at first.

  if (n == 1) {
    // if only 1 tab, will always move cursor once only
    cout << 1 << '\n';
    return;
  }

  ll c = 1;
  ll m = n;
  // (a/m) can either slowly fomr 0.x increase to 1, or x.x decrease to 1
  // can start at leftmost or rightmost, at most 2 ops

  if (a >= m * b) {
    // start left
    if (a < 1 * b) {
      c++;
    }
  } else if (a < m * b) {
    // start right
    if (a > 1 * b) {
      c++;
    }
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
