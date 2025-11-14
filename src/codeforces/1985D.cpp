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
  int n, m;
  cin >> n >> m;
  vector<vector<char>> g(n, vector<char>(m));

  for (auto &r : g) {
    for (auto &c : r) {
      cin >> c;
    }
  }

  debug(n, m, g);

  // Center point (h, k) is directly below top point, and directly above bottom
  // point
  pi top = MP(INF, INF), bot = MP(-INF, -INF);
  REP(i, 0, n) {
    REP(j, 0, m) {
      // get h by (top + bot) / 2
      if (g[i][j] == '#') {
        top = min(MP(i, j), top);
        bot = max(MP(i, j), bot);
      }
    }
  }

  cout << ((top.F + bot.F) / 2) + 1 << ' ' << top.S + 1 << '\n';
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
