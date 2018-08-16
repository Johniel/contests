# atcoder/abc105/D

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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<lli> a(n);
    each (i, a) cin >> i;
    map<lli, lli> cnt;
    lli x = 0;
    each (i, a) {
      x += i;
      x %= m;
      ++cnt[x];
    }
    lli sum = cnt[0];
    each (i, cnt) {
      sum += i.second * (i.second - 1) / 2;
    }
    cout << sum << endl;
  }

  return 0;
}
```
