#include <bits/stdc++.h>
#include <cstdio>

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
  ll n, m;
  scanf("%lld %lld", &n, &m);

  vector<ll> nums(n);
  ll lg = 0;

  REP(i, 0, n) {
    scanf("%lld", &nums[i]);

    if (nums[i] > nums[lg]) {
      lg = i;
    }
  }

  vector<ll> ops;
  REP(x, 0, m) {
    char c[2];
    string s;
    ll l, r;
    scanf("%1s %lld %lld", c, &l, &r);

    if ((nums[lg] >= l) && (nums[lg] <= r)) {
      debug(nums, c, l, r, nums[lg]);
      if (c[0] == '+') {
        nums[lg]++;
      } else {
        nums[lg]--;
      }
    }
    ops.PB(nums[lg]);
  }

  // debug(nums);
  for (auto i : ops) {
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {

  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
