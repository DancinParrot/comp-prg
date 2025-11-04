// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  int t;
  cin >> t;

  vector<int> r;

  while (t--) {
    string v;

    cin >> v;

    int v1 = v[0] - '0';
    int v2 = v[1] - '0';

    int sum = v1 + v2;
    r.push_back(sum);
  }

  for (auto v : r) {
    cout << v << endl;
  }
}
