#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  scanf("%d\n", &n);
  vector<string> strings;
  strings.reserve(n);

  for (int i = 0; i < n; i++) {
    string s;

    cin >> s;

    int len = s.size();

    if (len > 10) {
      char f = s[0];
      char l = s[len - 1];

      stringstream fmt;
      fmt << f << len - 2 << l;
      string fmt_str = fmt.str();
      strings.push_back(fmt_str);

    } else {
      strings.push_back(s);
    }
  }

  for (int i = 0; i < strings.size(); i++) {
    cout << strings[i] << "\n";
  }

  return 0;
}
