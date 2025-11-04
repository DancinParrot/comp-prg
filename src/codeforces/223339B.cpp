#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void recur(int &c, int n) {
  if (c == n) {
    return;
  }

  c += 1;
  cout << c << endl;
  return recur(c, n);
}

void solve() {
  int n;
  cin >> n;

  int c = 0;

  recur(c, n);

  return;
}

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0); don't mix C scanf() with C++ cin with this
  // cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // May use diff ./output.txt ./expected.txt to assert correctness
  // freopen("output.txt", "w", stdout); // write stdout to output.txt

  solve();
  return 0;
}
