#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>

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
  int n, m; // rows x cols
  cin >> n >> m;

  vector<string> v(n + 1);
  for (auto &i : v) {
    getline(cin, i);
  }

  vector<pair<int, int>> ans;

  for (int r = 0; r < v.size(); r++) {
    string col = v[r];
    for (int c = 0; c < col.size(); c++) {
      if (col[c] == '*')
        ans.push_back(make_pair(r, c + 1));
    }
  }

  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << p.F << " " << p.S << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
