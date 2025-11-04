#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int a, b;
  cin >> a >> b;

  if (a > b) {
    cout << 0 << endl;
    return;
  }

  int n = b - a + 1;
  cout << n << endl;
}

int main() {
  solve();
  return 0;
}
