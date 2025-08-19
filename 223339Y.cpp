#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void recur(int s, int e, int &c) {
  if (s == e) {
    c++;
    return;
  } else if (s > e) {
    return;
  }

  recur(s + 3, e, c);
  recur(s + 2, e, c);
  recur(s + 1, e, c);
}

void solve() {
  int s, e;
  cin >> s >> e;

  int c = 0;

  recur(s, e, c);
  cout << c << endl;
}

int main() {
  solve();
  return 0;
}
