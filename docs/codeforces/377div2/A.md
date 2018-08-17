# codeforces/377div2/A

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
  std::ios::sync_with_stdio(false);
  int k, r;
  while (cin >> k >> r) {
    for (int i = 1; i < 1000; ++i) {
      int mod = (k * i) % 10;
      if (mod == r || mod == 0) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
```
