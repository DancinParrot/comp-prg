#include <bits/stdc++.h>
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
  int n, m, k;
  string s;
  cin >> n >> m >> k >> s;

  vector<char> mArr(n, 0);

  int ans = 0, c = 0, sum = 0;
  // Don't need to actually set the 0 to 1, just use -1 to indicate where
  // subarray of k ends
  REP(i, 0, n) {
    sum += mArr[i];
    // If 1 then reset count, as 0 is not consecutive anymore
    // If sum == 1, also reset count as this indicates the end of k. For all
    // before k has been set to 1.
    if (sum || s[i] == '1')
      c = 0;
    else {
      c++;
      if (c == m) {
        sum++, ans++, c = 0;
        if (i + k < n)
          // When a sequence of 0s of length m is detected, set the last 0 of
          // that sequence to -1 which indicates the end of k.
          mArr[i + k]--;
      }
    }
  }

  cout << ans << '\n';
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
