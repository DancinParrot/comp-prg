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

  ll z = 0; // how many zeros
  ll sum = 0;
  for (auto &a : nums) {
    cin >> a;
    sum += a;
    if (!a)
      z++;
  }

  // All non-zero case:
  // n = 5, nums = 1 1 1 1 1
  // sum = 5, n - 1 = 5 - 1 = 4, sum - (n-1) = 5 - 4 = 1: hence, len of longest
  // subarray can only be 1

  // n = 5, nums = 1 2 3 4 5 sum = 15, n - 1 = 4, 15 - 4 = 11,
  // which is impossible as you cannot have longest subarray with len of
  // subarray > len of original array (n). So, choose n - z, 5 - 0 = 5

  // Some zero case:
  // n = 5, nums = 1 2 3 0 0
  // 5 - 2 = 3, 6 - 4 = 2

  // Why does sum - (n - 1) work? Cause, we'll use one subarray of len = 1
  // to do 1 operation, then we need (n-1) more subarrays to do
  // exactly (n-1) operations.
  cout << min(n - z, sum - (n - 1)) << '\n';
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
