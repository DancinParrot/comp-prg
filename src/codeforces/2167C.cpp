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
  // count how many even and odds, if equal amount, then use sort()
  // if all odds or all even, cannot sort
  // if different amount of even and odds, also use sort
  int n;
  cin >> n;
  vector<ll> nums(n);
  ll evens = 0, odds = 0;
  for (auto &i : nums) {
    cin >> i;
    if (i % 2 == 0) {
      evens++;
    } else {
      odds++;
    }
  }

  if ((evens == n) || (odds == n)) {
    for (auto i : nums) {
      cout << i << ' ';
    }
  } else {
    sort(nums.begin(), nums.end());
    for (auto i : nums) {
      cout << i << ' ';
    }
  }
  cout << '\n';
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
