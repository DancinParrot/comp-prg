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
  ll n, a;
  cin >> n >> a;

  // find out A pos in array
  // check which part of array after or before A has more elements, then plus or
  // minus accordingly

  int before = 0, after = 0;
  bool equal = true;
  while (n--) {
    ll v;
    cin >> v;

    if (v < a) {
      before++;
      equal = false;
    } else if (v > a) {
      after++;
      equal = false;
    }
  }

  if (equal) {
    // if all equal, doesn't matter as A will win anyway
    cout << 1 << '\n';
    return;
  }

  if (before > after) {
    cout << --a << '\n';
  } else {
    cout << ++a << '\n';
  }
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
