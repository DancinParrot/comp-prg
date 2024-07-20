// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;

int inverse(int t) { return abs(9 - t); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string x;

  cin >> x;

  string r;

  for (int i = 0; i < int(x.length()); i++) {
    int t = x[i] - '0';

    int inv = inverse(t);

    while (inv > t) {
      inv = inverse(inv);
    }

    // shouldn't start with 0
    if (inv == 0 && i == 0) {
      inv = t;
    }

    r += to_string(inv);
  }

  cout << r;
}
