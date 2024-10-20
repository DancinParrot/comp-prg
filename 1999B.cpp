// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int res(int a, int b) {
  if (a > b)
    return 1;
  if (a == b)
    return 0;
  if (a < b)
    return -1;
}

int main() {
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;

  vector<int> r;
  while (t--) {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int ans = 0;

    // 4 permutations: 2 turns each round, 4 rounds
    if (res(a1, b1) + res(a2, b2) > 0)
      ans += 1;

    if (res(a1, b2) + res(a2, b1) > 0)
      ans += 1;

    if (res(a2, b1) + res(a1, b2) > 0)
      ans += 1;

    if (res(a2, b2) + res(a1, b1) > 0)
      ans += 1;

    cout << ans << endl;
  }
}
