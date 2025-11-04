// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M, N;
  cin >> M >> N;

  // Will round up/down
  int m = (N * M) / 2;

  printf("%d\n", m);

  return 0;
}
