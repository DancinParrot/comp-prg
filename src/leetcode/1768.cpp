#include <bits/stdc++.h>

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

void solve(string word1, string word2) {
  string s;
  if (word1.size() < word2.size()) {
    for (int i = 0; i < word1.size(); i++) {
      s += word1[i];
      s += word2[i];
    }
    for (int i = word1.size(); i < word2.size(); i++) {
      s += word2[i];
    }
  } else if (word1.size() > word2.size()) {
    for (int i = 0; i < word2.size(); i++) {
      s += word1[i];
      s += word2[i];
    }
    for (int i = word2.size(); i < word1.size(); i++) {
      s += word1[i];
    }
  } else {
    for (int i = 0; i < word1.size(); i++) {
      s += word1[i];
      s += word2[i];
    }
  }

  cout << s << '\n';
}

void editorial(string word1, string word2) {
  int p1 = 0, p2 = 0; // ptrs to word1 and word2 respectively
  string r;
  while (p1 < word1.size() || p2 < word2.size()) {
    // If word1 still not fully traversed, continue appending to r
    if (p1 < word1.size()) {
      r += word1[p1++];
    }
    if (p2 < word2.size()) {
      r += word2[p2++];
    }
  }

  cout << r << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string w1, w2;
  cin >> w1 >> w2;
  editorial(w1, w2);
  return 0;
}
