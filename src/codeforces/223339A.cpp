#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void rec(int n) {
  if (n == 0) {
    return;
  }

  cout << "I love Recursion"
       << "\n";

  n -= 1;
  return rec(n);
}

void solve() {
  int n;
  cin >> n;

  rec(n);

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
