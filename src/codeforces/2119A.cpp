#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, x, y, cost = 0;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    while (a != b) {
      if (a < b) {
        if ((a % 2 == 0) && (y < x)) {
          a = a ^ 1;
          cost += y;
        } else {
          a++;
          cost += x;
        }
      } else {
        if (a % 2 != 0) {
          a = a ^ 1;
          cost += y;
        } else {
          cost = -1;
          break;
        }
      }
    }
    printf("%d\n", cost);
  }
  return 0;
}
