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
  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  map<char, int> ms, mt;
  REP(i, 0, n) {
    if (ms.find(s[i]) == ms.end()) {
      ms.insert({s[i], 1});
    } else {
      ms[s[i]] += 1;
    }

    if (mt.find(t[i]) == mt.end()) {
      mt.insert({t[i], 1});
    } else {
      mt[t[i]] += 1;
    }
  }

  for (auto i : ms) {
    debug(i, ms, mt);
    if (mt.find(i.first) == mt.end()) {
      cout << "no" << '\n';
      return;
    } else if (mt[i.first] != i.second) {
      cout << "no" << '\n';
      return;
    }
  }
  cout << "yes" << '\n';
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
