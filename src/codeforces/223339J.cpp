#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll recur(ll n) {

  if (n == 1) {
    return 1;
  }

  return n * recur(n - 1);
}

void solve() {
  int n;
  cin >> n;

  cout << recur((ll)n) << endl;
}

int main() {
  solve();
  return 0;
}
