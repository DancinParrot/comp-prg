#include <bits/stdc++.h>
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

/*
 * This function checks to make sure index is within bounds of array.
 * @param n Size of array.
 * @param i Index to access.
 * @return true if within bounds, else false
 */
bool in(int n, int m, int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}

/*
 * Visualize the grid as a black and white chess board will make solving the
 * problem much easier. If Vika is on a cell with the same color as any of her
 * friends, they will eventually meet. Otherwise, they will never meet.
 *
 * For example, if Vika is on White and her friend, k1 is on White as well. When
 * they move to adjacent cells, all valid adjacent cells will be Black.
 *
 * Conversely, if Vika is on Black and her friend, k1 is on White. When they
 * move, Vika will move to White cells while k1 will move to Black cells. Hence,
 * they will never meet each other.
 */
void solve() {
  int n, m, k, a, b;
  cin >> n >> m >> k >> a >> b;

  // if V is even, V is on black cell
  // if V is odd, V is on white cell
  bool isEven = (a + b) % 2 == 0;
  bool valid = true;

  while (k--) {
    int x, y;
    cin >> x >> y;

    //
    if ((isEven && ((x + y) % 2 == 0)) || (!isEven && ((x + y) % 2 != 0))) {
      valid = false;
    }
  }
  cout << (valid ? "YES" : "NO") << '\n';
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
