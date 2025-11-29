#include <bits/stdc++.h>
#include <cmath>

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
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }

  if (n == 2) {
    cout << 9 << '\n';
    return;
  }
  ll last = n * n - 1 + n * n - 2 + n * n + ((n - 1) * n) - 1;
  ll second_last = (n - 1) * n - 1 + (n - 1) * n - 2 + (n - 1) * n +
                   ((n - 2) * n) - 1 + n * n - 1;

  cout << max(last, second_last) << '\n';
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
