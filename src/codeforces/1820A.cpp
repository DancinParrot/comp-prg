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

// INSERT! Not replace the characters
void solve() {
  string s;
  cin >> s;

  int c = 0;

  if (*s.begin() == '_')
    c++;
  if (s.back() == '_')
    c++;

  REP(i, 0, s.size()) {
    if (in(s.size(), i) && in(s.size(), i + 1) && (s[i] == '_') &&
        (s[i + 1] == '_')) {
      c++;
    }
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
