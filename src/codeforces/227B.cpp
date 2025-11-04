// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  // value, index of value stored in hashmap to allow O(1) lookup
  unordered_map<int, int> nums;

  int c = 1;
  int t = n;
  while (t--) {
    int tmp;
    cin >> tmp;
    nums[tmp] = c;
    c++;
  }

  int m;
  cin >> m;
  vector<int> q;

  while (m--) {
    int tmp;
    cin >> tmp;
    q.push_back(tmp);
  }

  ll v = 0;
  ll p = 0;

  for (auto b : q) {
    v += nums[b];
    p += abs(nums[b] - n) + 1;
  }

  cout << v << " " << p << endl;
}
