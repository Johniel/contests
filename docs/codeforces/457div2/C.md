# codeforces/457div2/C

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

bool is_prime(int x)
{
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, m;
  while (cin >> n >> m) {
    const int P = 524287;
    if (n == 2) {
      cout << P << ' ' << P << endl;
      cout << 1 << ' ' << 2 << ' ' << P << endl;
      continue;
    }
    
    map<pair<int, int>, int> vis;

    vis[make_pair(n-1, n)] = P - (n - 2);
    for (int i = 1; i + 1 < n; ++i) {
      vis[make_pair(i, i + 1)] = 1;
    }

    cout << P << ' ' << P << endl;
    each (e, vis) {
      cout << e.first.first << ' ' << e.first.second << ' ' << e.second << endl;
    }
    m -= vis.size();
    
    for (int i = 1; i <= n && m; ++i) {
      for (int j = i + 2; j <= n && m; ++j) {
        cout << i << ' ' << j << ' ' << 1000000000 << endl;
        --m;
      }
    }
  }

  return 0;
}
```
