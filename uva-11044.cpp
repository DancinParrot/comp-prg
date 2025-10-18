#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    double n, m;
    cin >> n >> m;

    double ans = ceil((n - 2) / 3) * ceil((m - 2) / 3);
    cout << (ll)ans << endl;
  }
}

int main() {
  solve();
  return 0;
}
