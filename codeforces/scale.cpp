// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    int n, k;

    scanf("%d %d", &n, &k);

    for (int in = 0; in < n; in++) {
      string s;
      cin >> s;

      if (in % k == 0) {
        for (int i = 0; i < int(s.length()); i += k) {
          int c = int(s[i] - '0');
          cout << c;
        }
        cout << endl;
      }
    }
  }
}
