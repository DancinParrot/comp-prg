#include <bits/stdc++.h>
#include <utility>

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

void solve() {
  ll n;
  string s;
  cin >> n >> s;

  ll g = 0, bestG = 0, a = 0, bestA = 0;
  bool validSubstr = false;
  for (ll i = n - 1; i >= 0; i--) {
    if (s[i] == 'G')
      g++;
    else if (s[i] == 'A')
      a++;
    else
      // ignore D as it doesn't affect the win ratio
      continue;

    if (!validSubstr) {
      bestG = g;
      bestA = a;
      validSubstr = true;
    } else {
      // Compare current win ratio to best
      // g / (g+a) > bestG / (bestG + bestA)
      // Avoid floating pt divison so cross product:
      if ((g * (bestG + bestA)) > (bestG * (g + a))) {
        bestG = g;
        bestA = a;
      }
    }
  }

  cout << bestG << "-" << bestA << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
