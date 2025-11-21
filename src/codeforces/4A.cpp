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
  int w;
  cin >> w;

  // Why not 2? Cause 2 split into 1 and 1, 1 is not even. Weight must be even!
  // If w = 6, cannot split into 3 and 3, must split into 2 and 2 and 2, as
  // weights must be even. Hence, for any even numbers, they can be split evenly
  // except 2 itself.
  cout << (((w % 2 == 0) && (w != 2)) ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
