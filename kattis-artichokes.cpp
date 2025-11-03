#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int p, a, b, c, d, n;
  scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
  double max = -1, min = -1;
  double max_range = 0, range = 0;
  bool isConsec = false;

  for (int i = 1; i < n + 1; i++) {
    double price = p * (sin(a * i + b) + cos(c * i + d) + 2);

    if (max == -1) {
      max = price;
      continue;
    }

    if (price > max) {
      // stop of decline
      if (isConsec) {
        range = max - min;
        if ((range > max_range))
          max_range = range;
      }
      isConsec = false;
      max = price;
      min = -1; // reset min for new decline
    } else if (price < max) {
      // start of decline
      isConsec = true;
      if ((min == -1) || (price < min))
        min = price;
    }
  }

  // End of array, also calculate range
  if (isConsec) {
    range = max - min;
    if (range > max_range)
      max_range = range;
  }

  printf("%.6f", max_range);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
  return 0;
}
