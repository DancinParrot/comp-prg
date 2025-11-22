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

  ll start = -1;
  REP(i, 0, n) {
    // find starting point
    if (nums[i] > 0) {
      start = i;
      break;
    }
  }

  if ((start == -1) || (start == n - 1)) {
    cout << 0 << '\n';
    return;
  }

  ll ops = 0;
  REP(i, start, n - 1) {
    if (nums[i + 1] == 0) {
      nums[i]--;
      nums[i + 1]++;
      ops++;
    }
  }

  REP(i, start, n - 1) {
    nums.back() += nums[i];
    ops += nums[i];
    nums[i] = 0;
  }

  debug(nums);
  cout << ops << '\n';
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
