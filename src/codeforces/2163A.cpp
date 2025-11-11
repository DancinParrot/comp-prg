#include <algorithm>
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

bool in(int n, int i) { return i >= 0 && i < n; }

/* Counter example:
 * s k s k
 * 1 1 2 4
 * 1 2 1 4
 * hence, s lost
 */
void solve(vi &a) {
  sort(a.begin(), a.end());

  for (int i = 1; i <= a.size(); i++) {
    if ((in(a.size(), i + 1)) && (i % 2 != 0) && (a[i] < a[i + 1])) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n);
    for (auto &i : a) {
      cin >> i;
    }
    solve(a);
  }
  return 0;
}
