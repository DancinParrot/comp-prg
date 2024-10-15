// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int p_search(int b, vector<int> &nums) {
  int c = 0;
  for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
    c++;

    if (*it == b) {
      break;
    }
  }

  return c;
}

int v_search(int b, vector<int> &nums) {
  int c = 0;

  for (auto &v : nums) {
    c++;

    if (v == b) {
      break;
    }
  }

  return c;
}

int main() {
  int n;
  cin >> n;

  vector<int> nums;

  int t = n;
  while (t--) {
    int tmp;
    cin >> tmp;
    nums.push_back(tmp);
  }

  int m;
  cin >> m;
  vector<int> queries;

  t = m;
  while (t--) {
    int tmp;
    cin >> tmp;
    queries.push_back(tmp);
  }

  int v = 0;
  int p = 0;

  vector<int> v_ans(n + 1, 0);
  vector<int> p_ans(n + 1, 0);

  // n, m: 1e5 or 10^5, m can have repeats
  // worst case: O(n * m), best case: O(n log m)
  for (auto &b : queries) {
    if (v_ans[b] == 0) {
      // does not exist
      v_ans[b] = v_search(b, nums);
      p_ans[b] = p_search(b, nums);
    }

    v += v_ans[b];
    p += p_ans[b];
  }

  cout << v << " " << p << endl;
}
