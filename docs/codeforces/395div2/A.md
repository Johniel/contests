# codeforces/395div2/A

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
  int n, m, z;
  while (cin >> n >> m >> z) {
    map<int, int> cnt;
    for (int i = 1; i * n <= z; ++i) {
      ++cnt[i * n];
    }
    for (int i = 1; i * m <= z; ++i) {
      ++cnt[i * m];
    }
    int x = 0;
    each (i, cnt) {
      x += (i.second == 2);
    }
    cout << x << endl;
  }
  return 0;
}
```
