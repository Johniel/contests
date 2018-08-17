# codeforces/hello2018/A

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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, m;
  while (cin >> n >> m) {
    lli x = 0;
    for (int i = 0; i < min<lli>(n, 60); ++i) {
      if (m & (1LL << i)) {
        x |= 1LL << i;
      }
    }
    cout << x << endl;
  }

  return 0;
}
```
