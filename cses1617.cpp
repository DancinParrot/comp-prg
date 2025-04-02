#include <bits/stdc++.h>
#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  ll n;
  cin >> n;

  // Each bit has 2 possible values, 1 or 0. Hence, for a 3 bits, 2 * 2 * 2
  // permutations
  ll x = 1;

  // Based on the mod rule of (x * y) mod z = (x mod z) * (y mod z)
  // Hence, e.g. 2^2 mod z = (2 mod z) * (2 mod z)
  for (int i = 0; i < n; i++) {
    x = (x * 2) % MOD;
  }

  cout << x << endl;
}

int main() {
  solve();
  return 0;
}
