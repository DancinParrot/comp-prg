#include <bits/stdc++.h>
#include <map>
#include <numeric>
#include <utility>

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
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> nums(n);
  for (auto &a : nums) {
    cin >> a;
  }

  map<pair<ll, ll>, ll> m;

  ll c = 0;
  REP(i, 0, n) {
    // A pair needs to satisfy 2 conditions to be valid:
    // 1) ai mod x = (x - aj mod x) mod x
    // 2) ai mod x = aj mod x
    ll xx = nums[i] % x;
    ll yy = nums[i] % y;

    pair<ll, ll> p = MP(xx, yy);

    // If another number is found to have the same remainder as an existing
    // number in the "seen" hashmap, form a pair and increase the count by 1 as
    // we have just found a valid pair.
    c += m[{(x - xx) % x, yy}];
    m[p] = m[p] + 1; // keep track of remainders for all numbers
  }
  cout << c << '\n';
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
