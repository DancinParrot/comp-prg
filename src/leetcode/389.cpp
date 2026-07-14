#include <bits/stdc++.h>
#include <unordered_map>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const int INF = 1e9;

/*
 * This function checks to make sure index is within bounds of array.
 * @param n Size of array.
 * @param i Index to access.
 * @return true if within bounds, else false
 */
bool in(int n, int i) { return i >= 0 && i < n; }

void solve(string s, string t) {
  unordered_map<char, int> ms;
  unordered_map<char, int> mt;
  for (auto c : s) {
    ms[c] += 1;
  }
  for (auto c : t) {
    mt[c] += 1;
  }

  for (auto p : mt) {
    if (ms.find(p.F) != ms.end()) {
      if (p.F != ms[p.F]) {
        cout << p.F << '\n';
        return;
      }
    } else {
      cout << p.F << '\n';
      return;
    }
  }
}

void editorial(string s, string t) {
  unordered_map<char, int> m;

  for (auto c : t) {
    m[c] += 1;
  }

  for (auto c : s) {
    m[c] -= 1;
    if (m[c] == 0)
      m.erase(c);
  }
  cout << m.begin()->first << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s, t;
  cin >> s >> t;
  editorial(s, t);
  return 0;
}
