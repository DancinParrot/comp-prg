#include <bits/stdc++.h>
#include <map>

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
typedef vector<ll> vl;
typedef pair<int, int> pi;
const int INF = 1e9;

/*
 * This function checks to make sure index is within bounds of array.
 * @param n Size of array.
 * @param i Index to access.
 * @return true if within bounds, else false
 */
bool in(int n, int i) { return i >= 0 && i < n; }

// odd = al, al+2, al+4, ...
// even = al+1, al+3, ...
// even = odd where al, al+2, al+4 = al+1, al+3, can be rewritten as
// al - al+1 + al+2 - al3 + al+4 ... = 0 which is an alternating sequence with
// the sum of 0. Hence, for every i and j, odd[i] - even[i] = odd[j] - even[j]
// where odd[i] - even[i] can be stored in a map along with its frequence such
// that when it repeats or prefix sum = 0 (meaning sum of even and odd seq are
// equal), we know it's an alternating sequence which fits the above equation.
void solve() {
  ll n;
  cin >> n;
  vl nums(n);
  for (auto &a : nums) {
    cin >> a;
  }

  ll s = 0;
  map<ll, ll> fseen = {{0, 1}};
  REP(i, 0, n) {
    nums[i] *= ((i % 2) ? -1 : 1); // flip to get alternating sequence
    s += nums[i];

    if (fseen[s]) {
      cout << "YES" << '\n';
      return;
    }
    fseen[s]++;
  }

  cout << "NO" << '\n';
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
