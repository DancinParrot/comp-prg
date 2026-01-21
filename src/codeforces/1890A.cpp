#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>

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
  // bi = bi + 2, e.g. 1,2,1 where b0 = 1 and b0 = b2 = 1. This also suggests a
  // repeating sequence of 3 numbers. Given the above condition, within an array
  // n, should have ceil(n/2) same numbers with the remaining being the same as
  // well, meaning every repeating sequence should only have 2 same numbers to
  // produce a good array: 1,2,1,2 = good 1,2,1,1 = not good 1,2,1,4 = 3
  // different numbers, not good

  int n;
  cin >> n;
  vector<ll> nums(n);
  for (auto &a : nums) {
    cin >> a;
  }

  if (n == 2) {
    cout << "Yes" << '\n';
    return;
  }

  unordered_map<ll, int> freq;

  REP(x, 0, n) {
    if (!freq.count(nums[x])) {
      REP(y, 0, n) {
        if (nums[x] == nums[y]) {
          freq[nums[x]] += 1;
        }
      }
    }
  }

  if (freq.size() > 2) {
    cout << "No" << '\n';
    return;
  }

  debug(freq);
  for (auto it : freq) {
    if ((freq.size() == 1) || (it.S == n / 2)) {
      cout << "Yes" << '\n';
      return;
    }
  }

  cout << "No" << '\n';
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
