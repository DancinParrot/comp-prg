#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int recur(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  }

  return recur(n - 1) + recur(n - 2);
}

void solve() {
  int n;
  cin >> n;

  cout << recur(n) << endl;
}

int main() {
  solve();
  return 0;
}
