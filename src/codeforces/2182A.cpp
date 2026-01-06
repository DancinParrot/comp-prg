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
  int n;
  cin >> n;
  string nums;
  cin >> nums;

  vi chk = {2, 0, 2, 6};
  vi chk2 = {2, 0, 2, 5};

  int c = 0;
  // find 2026s in array
  for (int i = 0; i <= n - 4; i++) {
    REP(j, 0, 4) {
      if (nums[i + j] - '0' != chk[j]) {
        break;
      } else if ((nums[i + j] - '0' == chk[j]) && (j == 3)) {
        cout << c << '\n';
        return;
      }
    }
  }

  // if none found, must or must not have 2025
  for (int i = 0; i <= n - 4; i++) {
    REP(j, 0, 4) {
      debug(nums[i + j], chk2[j], j);
      if (nums[i + j] - '0' != chk2[j]) {
        break;
      } else if ((nums[i + j] - '0' == chk2[j]) && (j == 3)) {
        // if 2025 found, change 5 to 6 to become 2026, the string will always
        // be valid as long as there's one 2026
        c++;
        cout << c << '\n';
        return;
      }
    }
  }
  cout << c << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
