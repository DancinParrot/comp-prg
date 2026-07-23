#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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
  int n;
  cin >> n;

  vi nums(n);
  for (auto &a : nums) {
    cin >> a;
  }

  int p = 0;
  while (p < n) {
    int prev = p;
    auto it = min_element(nums.begin() + p, nums.end());
    p = distance(nums.begin(), it);

    fill(nums.begin() + prev, nums.begin() + p, nums[p]);
    p++;
  }

  // debug(nums);
  cout << accumulate(nums.begin(), nums.end(), 0) << '\n';

  // Case 1:
  // 5 6 7 8 9 3 2 7 8 9
  // 2 2 2 2 2 2 2 7 8 9

  // Case 2:
  // 4 3 5 6 7 (2) 4 7 8 3 9 8
  // 2 2 2 2 2  2  3 3 3 3 8 8
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
