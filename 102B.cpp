#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int sum_digits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}

void solve() {
  string n;
  cin >> n;

  int sum = 0;
  int count = 1;

  if (n.length() == 1) {
    cout << 0 << endl;
    return;
  }

  for (auto c : n) {
    int i = c - '0';
    sum += i;
  }

  while (sum >= 10) {
    sum = sum_digits(sum);
    count += 1;
  }

  cout << count << endl;
}

int main() {
  solve();
  return 0;
}
