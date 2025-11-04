#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int y;
  cin >> y;

  y += 1;
  while (true) {
    int tmp = y;
    set<int> used;
    for (int x = 0; x < 4; x++) {
      used.insert(tmp % 10);
      tmp = tmp / 10;
    }

    if (used.size() == 4) {
      cout << y << endl;
      return;
    }
    y++;
  }
}

int main() {
  solve();
  return 0;
}
