#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll recursion(ll n) {
  cout << n << endl;
  // base case
  if (n == 1) {
    return n;
  }

  if (n % 2 == 0) {
    return recursion(n / 2);
  }

  return recursion((n * 3) + 1);
}

void solve() {
  ll n;
  cin >> n;

  recursion(n);
}

int main() {
  solve();
  return 0;
}
