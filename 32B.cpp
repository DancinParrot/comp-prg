// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  vector<char> s;

  string l;
  getline(cin, l);
  char c;

  istringstream ss(l);

  // valid code:
  // . -> 0
  // -. -> 1
  // -- -> 2

  vector<char> res;
  while (ss >> c) {
    if (s.empty()) {
      if (c == '.') {
        res.push_back('0');
      } else {
        s.push_back(c);
      }
    } else {
      char r[2] = {s.back(), c};

      if (strncmp(r, "-.", 2) == 0) {
        s.pop_back();
        res.push_back('1');
      } else if (strncmp(r, "--", 2) == 0) {
        s.pop_back();
        res.push_back('2');
      } else {
        s.push_back(c);
      }
    }
  }

  for (auto v : res) {
    cout << v;
  }
}
