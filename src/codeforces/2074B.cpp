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

/*
 * a + b = x
 * c = x - 1
 * Due to the above, a + b > c, a + c > b, b + c > a, will always be true. For
 * instance, a = 100, b = 200, c = 100 + 200 - 1 = 299. Hence, 100 + 299 > 200,
 * 200 + 299 > 100, and 100 + 200 > 299
 *
 * Since n is quite large, direct simulation will cause TLE, so just use sum up
 * all input values - n + 1, resulting in constant time.
 */
void solve(ll n, ll sum) { printf("%lld\n", sum - n + 1); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  scanf("%d", &t);
  while (t--) {
    ll n, tmp, sum = 0;
    scanf("%lld", &n);
    tmp = n;

    while (tmp--) {
      int i;
      scanf("%d", &i);
      sum += i;
    }
    solve(n, sum);
  }
  return 0;
}
