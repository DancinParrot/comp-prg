#include <algorithm>
#include <bits/stdc++.h>

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
  int n;
  cin >> n;
  vector<ll> a(n), b(n), diff(n);
  for (auto &x : a) {
    cin >> x;
  }

  for (auto &x : b) {
    cin >> x;
  }

  // Solution:
  // This problem doesn't require any graph traversal techniques, just basic
  // math. For an edge to exist from vertex u to vertex v, it has to satisfy the
  // condition of au - av >= bu - bv, which can be transformed into au - bu >=
  // av - bv. This basically solves the problem as now we just need to traverse
  // a and b arrays, compute ai - bi and store the result in another array
  // named, diff.
  //
  // The max element in the diff array will have edges to every other vertices,
  // which is then considered a "strong vertex". Take note, the max element may
  // have duplicates, so just return the frequency of the max elements along
  // with the 1-based indexing of the strong vertices.

  ll max = -INF;
  REP(i, 0, n) {
    diff[i] = a[i] - b[i];
    max = std::max(diff[i], max);
  }

  vector<ll> strong;
  REP(i, 0, n) {
    if (diff[i] == max) {
      strong.PB(i + 1); // 1-based indexing as vertices start from 1 to n
    }
  }

  sort(strong.begin(), strong.end()); // ascending order

  cout << strong.size() << '\n';
  for (auto x : strong) {
    cout << x << " ";
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
