# atcoder/arc061/D

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
  lli h, w, n;
  while (cin >> h >> w >> n) {
    map<int, lli> cnt;
    set<pair<int, int>> s;
    s.clear();
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      s.insert(make_pair(a - 1, b - 1));
    }

    vector<pair<int, int>> v;
    each (p, s) {
      for (int i = -2; i < 3; ++i) {
        for (int j = -2; j < 3; ++j) {
          int I = p.first + i;
          int J = p.second + j;
          unless (0 <= I && I + 2 < h) continue;
          unless (0 <= J && J + 2 < w) continue;
          v.push_back(make_pair(I, J));
        }
      }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
   
    each (p, v) {
      int x = 0;
      for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
          x += s.count(make_pair(p.first + i, p.second + j));
        }
      }
      ++cnt[x];
    }


    lli sum = 0;
    for (int i = 1; i <= 9; ++i) {
      sum += cnt[i];
    }

    cnt[0] = (h - 2LL) * (w - 2LL) - sum;
    for (int i = 0; i <= 9; ++i) {
      cout << cnt[i] << endl;
    }
  }
  return 0;
}
```
