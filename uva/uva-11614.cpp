#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    // Use arithmetic series formula for sum of n terms to derive quad eqn
    // Find quad roots of r^2 + r - 2n
    int a = 1;
    int b = 1;
    ll c = -(2 * n);

    double r1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double r2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    cout << (ll)floor(max(r1, r2)) << endl;
  }

  return;
}

int main() {
  solve();
  return 0;
}
