#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  unsigned int x;
  cin >> x;

  int c = 0;
  while (x != 0) {
    unsigned int b = x & 1;
    if (b == 1) {
      c++;
    }
    x >>= 1;
  }

  cout << c << endl;
}

int main() {
  solve();
  return 0;
}
