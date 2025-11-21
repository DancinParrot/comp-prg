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
  string s;
  cin >> s;

  reverse(s.begin(), s.end());

  debug(s);
  int j = -1;
  int c = 0;
  REP(i, 0, s.size()) {
    if ((j == -1) && (s[i] - '0' > 0)) {
      j = i;
      break;
    }
    c++;
  }

  REP(i, j + 1, s.size()) {
    if (s[i] - '0' > 0) {
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
