#include <algorithm>
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

/*
 * For every cow (in range of n), the m cards should fit the sequence of i, n +
 * i, 2n + i, 3n + i, ...
 */
void solve(vector<vi> &cows, int n) {
  int c = 1;
  vi p(n);
  bool valid = true;
  REP(i, 0, n) {
    // min element determines order, if min = 0, cow go first
    int minN = *min_element(cows[i].begin(), cows[i].end());
    if (minN < n) {
      p[minN] = c++;
    }
    valid &= minN < n;

    sort(cows[i].begin(), cows[i].end());
    // check sequence correct or not
    int last = cows[i][0] - n;
    debug(cows[i], p, minN, valid);
    for (auto x : cows[i]) {
      valid &= last + n == x;
      last = x;
    }
  }

  if (!valid) {
    cout << "-1\n";
    return;
  } else {
    for (auto y : p) {
      cout << y << ' ';
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
    vector<vi> cows(n, vi(m));

    for (auto &c : cows) {
      for (auto &i : c)
        cin >> i;
    }

    solve(cows, n);
  }

  return 0;
}
