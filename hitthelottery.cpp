#include <algorithm>
#include <cstdio>
using namespace std;

// ret: min num of bills to withdraw n
int withdraw(int n, int best, int *dp) {
  int bs[5] = {1, 5, 10, 20, 100};

  if (n == 0) {
    return 0;
  }

  if (dp[n] < best) {
    return dp[n];
  }

  for (int b : bs) {
    if (b > n) {
      continue;
    }

    int diff = n - b;

    dp[n] = min(withdraw(diff, best, dp) + 1, best);
    // printf("dp[%d] in loop: %d\n", n, dp[n]);
  }

  return dp[n];
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  // Store num of bills to withdraw n
  int *dp = new int[n];

  // init dynamic array, o(n)
  for (int i = 0; i < n + 1; i++) {
    dp[i] = n + 1;
  }

  int min = withdraw(n, n + 1, dp);
  free(dp);
  printf("%d\n", min);
  return 0;
}
