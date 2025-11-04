#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
  int n;
  cin >> n;

  if (n % 10000 < 1000) {
    string s = to_string(n);
    while (s.length() != 4) {
      // prepend at offset 0
      s.insert(0, 1, '0');
    }
    cout << s << endl;
  } else {
    cout << n << endl;
  }
}

int main() {
  solve();
  return 0;
}
