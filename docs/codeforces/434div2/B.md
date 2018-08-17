# codeforces/434div2/B

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
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      int k, f;
      cin >> k >> f;
      v.push_back(make_pair(k, f));
    }
    set<int> vis;
    for (int flats = 1; flats <= 200; ++flats) {
      auto fn = [&] (lli floor) {
        return make_pair<lli, lli>(floor * flats - flats + 1, floor * flats);
      };
      bool f = true;
      each (i, v) {
        pair<int, int> p = fn(i.second);
        f = f && p.first <= i.first && i.first <= p.second;
      }
      if (f) {
        int x = (n / flats) + (bool)(n % flats);
        vis.insert(x);
      }
    }
    if (vis.size() == 1) cout << *vis.begin() << endl;
    else cout << -1 << endl;
  }
  
  return 0;
}
```
