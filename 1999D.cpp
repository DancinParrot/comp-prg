#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {

  int n;
  cin >> n;
  while (n--) {
    string s, t;
    cin >> s >> t;

    unsigned long sp = 0, tp = 0;

    while (sp < s.size()) {
      if (tp < t.size()) {
        if (s[sp] == '?') {
          s[sp] = t[tp];

          tp++;
        } else if (s[sp] == t[tp]) {
          tp++;
        }
      } else if (tp == t.size()) {
        if (s[sp] == '?') {
          s[sp] = s[sp - 1];
        }
      }

      sp++;
    }

    if (tp == t.size()) {
      cout << "YES" << "\n";
      cout << s << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}
