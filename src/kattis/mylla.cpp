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
  int n;
  string s;
  cin >> n >> s;

  int a = 0, ar = 0, h = 0, hr = 0;
  for (auto i : s) {
    if (i == 'A')
      a++;
    else
      h++;

    if (a >= 3) {
      ar++;
      a = 0;
      h = 0;
    } else if (h >= 3) {
      hr++;
      a = 0;
      h = 0;
    }

    if (ar >= n) {
      cout << "Hannes" << '\n';
      return;
    } else if (hr >= n) {
      cout << "Arnar" << '\n';
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
