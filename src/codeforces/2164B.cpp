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
  ll n;
  cin >> n;

  vector<ll> nums(n);
  for (auto &a : nums) {
    cin >> a;
  }

  // if no or not enough evens, bruteforce check
  REP(i, 0, n) {
    REP(j, i + 1, n) {
      debug(nums[i], nums[j]);
      if (nums[i] < nums[j]) {
        if ((nums[j] % nums[i] == 0) || ((nums[j] % nums[i]) % 2 == 0)) {
          cout << nums[i] << ' ' << nums[j] << '\n';
          return;
        }
      }
    }
  }
  cout << -1 << '\n';
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
