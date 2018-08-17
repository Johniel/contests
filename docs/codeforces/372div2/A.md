# codeforces/372div2/A

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

int main(int argc, char *argv[])
{
  int n, c;
  while (scanf("%d%d", &n, &c) == 2) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      if (v.empty()) v.push_back(x);
      else {
        if (abs(v.back() - x) > c) {
          v.clear();
        }
        v.push_back(x);
      }
    }
    printf("%d\n", (int)v.size());
  }
  return 0;
}
```
