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
const int INF = 1e9;

/*
 * This function checks to make sure index is within bounds of array.
 * @param n Size of array.
 * @param i Index to access.
 * @return true if within bounds, else false
 */
bool in(int n, int i) { return i >= 0 && i < n; }

/*
 * Pick indices i and j such that 1 <= i <= j <= n
 * The subarray to reverse: {ai, ..., aj-1, aj}, so any elements before ai and
 * after aj will not be involved, i.e. ai-1, and aj+1.
 *
 * Thus forming the array, a1, a2, ai-1, {aj, aj-1, ..., ai}, aj+1, ..., an.
 *
 * If k > 1, meaning if subarray length is at least 2, then the array can be
 * reversed. Otherwise, if only able to operate on 1 element, definitely cannot
 * reverse.
 */
void solve() {
  int n, k;
  cin >> n >> k;
  vi nums(n);

  for (auto &a : nums) {
    cin >> a;
  }

  if (is_sorted(nums.begin(), nums.end()) || (k > 1)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
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
