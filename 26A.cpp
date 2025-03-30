#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

bool is_prime(int n) {
  int divisors = 0;

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      divisors += 1;
    }
  }

  if (divisors == 2) {
    return true;
  }

  return false;
}

bool is_almost_prime(int n) {
  int prime_divisors = 0;

  for (int i = 1; i <= n; i++) {
    if ((n % i == 0) && (is_prime(i))) {
      prime_divisors += 1;
    }
  }

  if (prime_divisors == 2) {
    return true;
  }

  return false;
}

void solve() {
  int n;
  cin >> n;

  int almost_primes = 0;

  for (int i = 1; i <= n; i++) {
    if (is_almost_prime(i)) {
      almost_primes += 1;
    }
  }

  cout << almost_primes << endl;
}

int main() {
  solve();
  return 0;
}
