// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string op;

  int x = 0;

  while (n--) {
    cin >> op;

    if (op == "X++" || op == "++X") {
      x += 1;
    } else {
      x -= 1;
    }
  }

  cout << x << endl;
}
