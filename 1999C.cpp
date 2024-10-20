// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;

  vector<string> a;
  while (t--) {
    ll n, s, m;
    cin >> n >> s >> m;
    vector<ll> tasks;

    ll tmp = n;
    while (tmp--) {
      ll l, r;
      cin >> l >> r;
      tasks.push_back(l);
      tasks.push_back(r);
    }

    ll l = 0, r = 1, f = 0;

    string res = "NO";
    while (l < r && r <= n * 2) {
      ll diff = tasks[l] - f;

      // cout << "l: " << tasks[l] << " r: " << tasks[r] << " f: " << f << endl;
      if (diff >= s) {
        res = "YES";
        break;
      }

      f = tasks[r];
      l = r + 1;
      r = r + 2;
    }

    if (res == "NO") {
      ll diff = m - tasks.back();

      if (diff >= s) {
        res = "YES";
      }
    }

    a.push_back(res);
  }

  for (auto v : a) {
    cout << v << endl;
  }
}
