#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int k, s;
  cin >> k >> s;
  int c = 0;

  for (int x = 0; (x <= k) && (x <= s); x++) {
    for (int y = 0; (y <= k) && (y <= s); y++) {
      int z = s - x - y;
      if (z >= 0 and z <= k) {
        c += 2;
      }
    }
  }

  cout << c << endl;
}

int main() {
  solve();
  return 0;
}
