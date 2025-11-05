#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    // attack the minimum, either health of knight
    // if knight dies, cannot attack, so automatic lost
    if (min(a, c) >= min(b, d)) {
      cout << "Gellyfish" << endl;
    } else {
      cout << "Flower" << endl;
    }
  }
}

int main() {
  solve();
  return 0;
}
