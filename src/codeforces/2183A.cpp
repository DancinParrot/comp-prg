#include <iostream>

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
  // if array is not full of 1s, then check first and last element
  // take note, the subrray only needs the first or last element to be 1 for
  // Alice to win.If so, the array will contain at least one 0 such that 1 -
  // min(1, 0) = 0, and the subarray is replaced with 1 to form 1, 1. Then, Bob
  // can only pick 1, 1 such that 1 - min(1, 1) = 0, and Alice wins.

  // If first and last element is 0, then Bob will always win. Since no matter
  // how Alice manipulate the array, will always end up with 0 since it's the
  // first and last element.
  int n;
  cin >> n;
  vi nums(n);
  for (auto &a : nums) {
    cin >> a;
  }

  if ((*nums.begin() == 1) || (nums.back() == 1))
    cout << "Alice" << '\n';
  else
    cout << "Bob" << '\n';
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
