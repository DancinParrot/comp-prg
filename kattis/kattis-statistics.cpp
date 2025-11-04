#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int n, count = 1;
  while (scanf("%d", &n) != EOF) {
    int min = -9999999, max = 9999999, i;
    while (n--) {
      scanf("%d", &i);

      if ((min == -9999999) || (i < min)) {
        min = i;
      }

      if ((max == 9999999) || (i > max)) {
        max = i;
      }
    }
    printf("Case %d: %d %d %d\n", count++, min, max, max - min);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
  return 0;
}
