#include <bits/stdc++.h>
#include <unordered_set>

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
  ll a, b;
  cin >> a >> b;

  int ans = 0;
  ll diff = max(a, b) - min(a, b);
  if (diff == 1) {
    cout << 1 << ' ' << '0' << '\n';
    return;
  } else if (diff == 0) {
    cout << 0 << ' ' << 0 << '\n';
    return;
  }

  // b = a % diff or diff - (a % diff) whichever is the smallest, but why does
  // this work?
  // a mod diff = b mod diff
  // diff = | a - b | will never change
  // Hence, need to make b a multiple of diff
  // 1. Decrease b to largest multiple of diff <= b: b mod diff
  // 2. Or, increase b to smallest multiple of diff > b: diff - b mod diff
  // a mod diff == b mod diff since a = b + diff
  cout << diff << ' ' << min(a % diff, diff - (a % diff)) << '\n';
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
