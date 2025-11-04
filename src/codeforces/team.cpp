#include <cstdio>
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int r = 0;

  while (n--) {
    int p, v, t;

    scanf("%d %d %d", &p, &v, &t);

    int s = p + v + t;

    if (s >= 2) {
      r++;
    }
  }

  printf("%d", r);

  return 0;
}
