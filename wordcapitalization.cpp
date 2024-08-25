// g++ -std=c++11 -O2 -Wall test.cpp -o build/test
#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  // freopen("input.txt", "r", stdin);
  // May use diff ./output.txt ./expected.txt to assert correctness
  // freopen("output.txt", "w", stdout); // write stdout to output.txt

  char w[1000];
  scanf("%s", w);

  w[0] = toupper(w[0]);

  printf("%s", w);
}
