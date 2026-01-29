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

void factors(map<int, int> &f, int x) {
  int i = 2;

  while (i * i <= x) {
    while (x % i == 0) {
      f[i]++;
      x /= i;
    }
    i++;
  }

  if (x > 1)
    f[x]++;
}

// Notice the product of all elements in the array is always the same after n
// operations. Due to this, get frequency of all prime factors of each element
// and ensure frequency is k * n times, or in other words, divisible by n.
void solve() {
  int n;
  cin >> n;
  vi nums(n);

  map<int, int> f;

  REP(i, 0, n) {
    cin >> nums[i];
    factors(f, nums[i]);
  }

  debug(f);

  for (auto p : f) {
    if (p.S % n != 0) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
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
