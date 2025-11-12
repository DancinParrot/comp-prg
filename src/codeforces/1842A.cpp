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

/*
 * This function checks to make sure index is within bounds of array.
 * @param n Size of array.
 * @param i Index to access.
 * @return true if within bounds, else false
 */
bool in(int n, int i) { return i >= 0 && i < n; }

void solve() {
  int n, m;
  cin >> n >> m;
  ll nSum = 0;
  ll mSum = 0;
  while (n--) {
    ll tmp;
    cin >> tmp;
    nSum += tmp;
  }

  while (m--) {
    ll tmp;
    cin >> tmp;
    mSum += tmp;
  }

  if (nSum > mSum) {
    cout << "Tsondu" << '\n';
  } else if (nSum < mSum) {
    cout << "Tenzing" << '\n';
  } else {
    cout << "Draw" << '\n';
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
