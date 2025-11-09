#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(vi nums, string s) {

  map<char, int> m1;
  map<int, char> m2;

  for (size_t i = 0; i < nums.size(); i++) {
    if ((m1.count(s[i]) && (m1[s[i]] != nums[i])) ||
        (m2.count(nums[i]) && (m2[nums[i]] != s[i]))) {
      cout << "NO\n";
      return;
    }
    m1.insert({s[i], nums[i]});
    m2.insert({nums[i], s[i]});
  }
  debug(nums, s, m1, m2);
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi nums(n);
    for (auto &i : nums) {
      cin >> i;
    }

    int m;
    string s;
    cin >> m;
    for (size_t i = 0; i < m; i++) {
      cin >> s;
      if (nums.size() != s.size()) {
        cout << "NO\n";
      } else {
        solve(nums, s);
      }
    }
  }
  return 0;
}
