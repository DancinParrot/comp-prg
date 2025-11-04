#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int reverse(int n) {
  int num = 0;
  for (int i = 3; i > 0; i--) {
    int r = n % 10;
    num += (int)(r * pow(10, i - 1));
    n = n / 10;
  }
  return num;
}

void solve() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d", max(reverse(a), reverse(b)));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
  return 0;
}
