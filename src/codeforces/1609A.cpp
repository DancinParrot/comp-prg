#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

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

  ll c = 0;
  bool isValid = true;
  while (isValid) {
    REP(i, 0, n) {
      debug(nums[i]);
      if (nums[i] % 2 == 0) {
        nums[i] /= 2;
        c++;
        break;
      }

      if (i == n - 1) {
        isValid = false;
      }
    }
  }

  sort(nums.begin(), nums.end());
  nums.back() *= pow(2, c);

  debug(nums);
  cout << accumulate(nums.begin(), nums.end(), 0LL) << '\n';
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
