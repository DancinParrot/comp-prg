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
  long long n, m, k;
  cin >> n >> m >> k;

  if (k < m) {
    cout << ":(" << '\n';
    return;
  }

  long long total = 0;
  while (n--) {
    long long i;
    cin >> i;
    total += i;
  }

  long long tpd = k / m;
  long long days = (total + tpd - 1) / tpd;
  cout << days << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
