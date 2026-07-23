#include <bits/stdc++.h>

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
  string s;
  cin >> s;
  int t = 0, h = 0;

  for (auto c : s) {
    if (c == 'T')
      t++;
    if (c == 'H')
      h++;

    if ((t >= 11) && (t > h) && ((t - h) >= 2)) {
      // t wins, so reset score
      t = 0, h = 0;
    }
    if ((h >= 11) && (h > t) && ((h - t) >= 2)) {
      // t wins, so reset score
      t = 0, h = 0;
    }
  }

  cout << t << '-' << h << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
