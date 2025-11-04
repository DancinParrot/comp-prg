#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  if ((a == c) || (b == c)) {
    cout << "YES" << endl;
    return;
  }

  if ((a > c) && (b > c)) {
    cout << "NO" << endl;
    return;
  }

  int x = 0;
  int y = 0;
  while (x < 10000) {
    while (y < 10000) {
      if ((a * x) + (b * y) == c) {
        cout << "YES" << endl;
        return;
      }
      y++;
    }
    x++;
    y = 0;
  }

  cout << "NO" << endl;
  return;
}

int main() {
  solve();
  return 0;
}
