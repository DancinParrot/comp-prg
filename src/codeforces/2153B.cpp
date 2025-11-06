#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (((x & y) == (y & z)) && ((x & y) == (x & z)) && ((y & z) == (x & z)))
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
