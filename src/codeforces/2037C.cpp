#include <bits/stdc++.h>
#include <cstdio>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;

typedef long long ll;
typedef vector<int> vi;

// source: https://www.geeksforgeeks.org/dsa/composite-number/
bool composite(int n) {
  // Corner cases
  if (n <= 1)
    return false;
  if (n <= 3)
    return false;

  // This is checked so that we can skip
  // middle five numbers in below loop
  if (n % 2 == 0 || n % 3 == 0)
    return true;

  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return true;

  return false;
}

void solve(int n) {
  if (n <= 2) {
    printf("-1\n");
    return;
  }

  vi odd, even;
  bool isValid = false;
  for (int i = 1; i < n + 1; i++) {
    if (i % 2 == 0)
      even.push_back(i);
    else
      odd.push_back(i);
  }

  for (size_t i = 0; i < even.size(); i++) {
    if (composite(odd.back() + even[i])) {
      odd.push_back(even[i]);
      even.erase(even.begin() + i);
      isValid = true;
      break;
    }
  }

  debug(odd);
  if (!isValid) {
    printf("-1\n");
    return;
  }

  odd.insert(odd.end(), even.begin(), even.end());
  for (auto i : odd) {
    printf("%d ", i);
  }
  printf("\n");
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    solve(n);
  }
  return 0;
}
