# atcoder/agc014/B

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

  int n, m;
  while (cin >> n >> m) {
    map<int, int> cnt;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      ++cnt[a];
      ++cnt[b];
    }
    bool f = true;
    each (i, cnt) f = f && (i.second % 2 == 0);
    cout << (f ? "YES" : "NO") << endl;
  }
  
  return 0;
}

```
