#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int t, c = 1;
  scanf("%d", &t);
  while (t--) {
    int n, s, max = 0;
    scanf("%d", &n);

    while (n--) {
      scanf("%d", &s);
      if (s > max)
        max = s;
    }
    printf("Case %d: %d\n", c++, max);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); // don't mix C scanf() with C++ cin with this
  cout.tie(0);

  solve();
  return 0;
}
