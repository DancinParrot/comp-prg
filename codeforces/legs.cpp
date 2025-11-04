// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  int t;
  cin >> t;

  vi r;

  while (t--) {
    double n;

    cin >> n;

    r.push_back(ceil(n / 4));
  }

  for (auto i : r) {
    cout << i << "\n";
  }
}
