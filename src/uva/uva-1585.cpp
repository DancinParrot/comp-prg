#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  char s[81];
  while (t--) {
    scanf("%80s", s);
    int count = 0, score = 0;
    for (size_t i = 0; i < strlen(s); i++) {
      if (s[i] == 'O') {
        count += 1;
      } else
        count = 0;
      score += count;
    }
    printf("%d\n", score);
  }
  return 0;
}
