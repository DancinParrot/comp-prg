#include <algorithm>
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
  cin >> n;
  vector<ll> tmps(n);
  for (auto &i : tmps) {
    cin >> i;
  }

  cout << *max_element(tmps.begin(), tmps.end()) << " "
       << *min_element(tmps.begin(), tmps.end()) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
