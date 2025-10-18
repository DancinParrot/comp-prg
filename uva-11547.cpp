#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int a = abs(((((n * 567) / 9) + 7492) * 235) / 47 - 498);
    int r = a % 100;
    cout << r / 10 << endl;
  }
}

int main() {
  solve();
  return 0;
}
