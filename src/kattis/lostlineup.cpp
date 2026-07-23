#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int n;
  scanf("%d", &n);
  vi o(n);
  o[0] = 1; // Jimmy

  for (int i = 2; i < n + 1; i++) {
    int p;
    scanf("%d", &p);
    o[p + 1] = i;
  }

  for (auto i : o) {
    printf("%d ", i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
  return 0;
}
