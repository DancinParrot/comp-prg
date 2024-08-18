#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
  int n;
  cin >> n;

  int sx = 0, sy = 0, sz = 0;
  while (n--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    sx += x;
    sy += y;
    sz += z;
  }

  if (sx == 0 && sy == 0 && sz == 0) {
    printf("YES");
  } else {
    printf("NO");
  }
}
