// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  // freopen("input.txt", "r", stdin);

  vector<vector<int>> m;
  int x = 0, y = 0;

  for (int i = 0; i < 5; i++) {
    string l;
    getline(cin, l);

    istringstream ss(l);

    int n;
    vector<int> nums;

    int c = 0;
    while (ss >> n) {
      if (n == 1) {
        x = c;
        y = i;
      }
      nums.push_back(n);
      c++;
    }

    m.push_back(nums);
  }

  cout << abs(x - 2) + abs(y - 2) << endl;

  return 0;
}
