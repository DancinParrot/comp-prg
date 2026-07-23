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

ll largest_power_of_two(ll n) {
  ll p = 1;
  while (p * 2 <= n) {
    p *= 2;
  }
  return p;
}

void solve() {
  ll n;
  cin >> n;
  ll l = n - largest_power_of_two(n);
  // For any number N, N = 2^a + l
  // e.g. 77 = 2^6 + 13 so winner is 27
  // Position of winner in Josephus Problem = 2l + 1
  cout << 2 * l + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
