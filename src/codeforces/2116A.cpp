// Direct simulation with o(n) will not work due to input size of 10^9
// In worst case scenario, both Gellyfish and Flower could have HP and knight of
// 10^9, and subtracting one by one will cause TLE.
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

    // O(1)
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
