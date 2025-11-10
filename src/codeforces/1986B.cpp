#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;

typedef long long ll;
typedef vector<int> vi;

/*
 * Check if in bounds
 */
bool in(vector<vi> &rows, vi &cols, int r, int c) {
  return r >= 0 && c >= 0 && r < rows.size() && c < cols.size();
}

/*
 * 1. Find cell with values greater than all its neighbor
 * 2. After which, mx = max(neighbors cells) and set valid cell = x = min(x, m)
 *
 * Time Complexity: O(n * m)
 */
void solve(vector<vi> &m) {
  int dx[] = {-1, 0, 1, 0}; // left, right
  int dy[] = {0, -1, 0, 1}; // top, bottom

  // save valid cell index, and loop until it's invalid
  for (int r = 0; r < m.size(); r++) {
    // check surrounding indices > 0
    for (int c = 0; c < m[r].size(); c++) {
      int mx = 0;
      for (int k = 0; k < 4; k++) {
        // Check all 4 adjacent cells (left, right, top, bottom)
        int nr = r + dy[k], nc = c + dx[k];

        if (in(m, m[r], nr, nc))
          mx = max(mx, m[nr][nc]);
      }
      m[r][c] = min(m[r][c], mx);
    }
  }

  for (auto r : m) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vi> a(n);

    for (auto &r : a) {
      vi c(m);
      for (auto &ci : c) {
        cin >> ci;
      }
      r = c;
    }
    solve(a);
  }

  return 0;
}
