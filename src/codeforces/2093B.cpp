#include <bits/stdc++.h>
#include <cstdio>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (size_t i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

/*
 * This function checks to make sure index is within bounds of array.
 * @param n Size of array.
 * @param i Index to access.
 * @return true if within bounds, else false
 */
bool in(int n, int i) { return i >= 0 && i < n; }

/*
 * Find rightmost non-zero digit, and set everything non-zero on the left to
 * zero. The remaining zeros can then be removed for cost to be minimal, or cost
 * = 1.
 */
void solve(string &s) {
  int c = 0, skipped = 0;

  // start counting after meeting rightmost non-zero digit
  bool right_digit_met = false;

  // 00731, when 7, right_digit_met = true, so when 3 count + 1, and when 1,
  // count + 1
  for (int i = s.size() - 1; i >= 0; i--) {
    debug(s[i]);
    if ((s[i] != '0') && !right_digit_met) {
      right_digit_met = true;
    } else if ((s[i] != '0') && right_digit_met) {
      c++;
    } else if ((s[i] == '0') && !right_digit_met) {
      skipped++;
    }
  }

  cout << c + skipped << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    solve(s);
  }
  return 0;
}
