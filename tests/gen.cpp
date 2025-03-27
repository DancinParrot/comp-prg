#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  // Take in seed
  srand(atoi(argv[1]));
  int n = rand(2, 100); // num of test cases
  printf("%d\n", n);
  set<int> used;
  for (int i = 0; i < n; i++) {
    int x, x2;
    do {
      x = rand(1, 2500);
      x2 = rand(1, 2500);
    } while (used.count(x));
    printf("%d %d\n", x, x2);
    used.insert(x);
  }
  puts("");
  return 0;
}
