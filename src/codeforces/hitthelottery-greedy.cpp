#include <cstdio>
using namespace std;

// Since nominal value of bills is constant and each value of bill in the
// sequence 1,5,10,20,100 is a divisor of the number after it. Greedy works,
// otherwise no guarantee that always taking largest bill will yield minimum num
// of bills used, see coin change, so will need DP.
int main(int argc, char *argv[]) {
  int bs[5] = {100, 20, 10, 5, 1};
  int n, min;
  scanf("%d", &n);

  for (int b : bs) {
    min += n / b; // round up
    n = n % b;
  }

  printf("%d\n", min);
  return 0;
}
