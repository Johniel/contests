# codeforces/339div2/B

## Codes
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

bool beautiful(string s)
{
  return s[0] == '1' && (count(s.begin(), s.end(), '0') + 1 == s.size());
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    char buff[100000 + 10];
    string no_b;
    int z = 0;
    bool f = true;
    for (int i = 0; i < n; ++i) {
      scanf("%s", buff);
      string s(buff);
      f = f && s != "0";
      if (beautiful(s)) {
        z += (int)s.size() - 1;
      } else {
        no_b = s;
      }
    }
    if (f) {
      if (no_b.empty()) no_b = "1";
      printf("%s", no_b.c_str());
      for (int i = 0; i < z; ++i) {
        printf("0");  
      }
      puts("");
    } else {
      puts("0");
    }
  }
  return 0;
}
```
