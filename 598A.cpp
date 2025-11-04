/* o(n) result in TLE due as n < 10^9
 * Hence, need o(log n) solution
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    // Without trick (minus all powers of 2), it'll be a
    // simple AP: 1 + 2 +3 + ... + n
    // sum of AP = n(a+l)/2 where a = 1, and l = n; hence n(n+1)/2
    ll s = ((n * (n + 1)) / 2);

    // minus all power of 2s like 2^0, 2^1, 2^2
    for (int p = 1; p <= n;) {
      s -= p * 2;
      p *= 2;
    }

    cout << s << endl;
  }
  return;
}

int main() {
  solve();
  return 0;
}
