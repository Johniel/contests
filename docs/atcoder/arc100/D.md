# atcoder/arc100/D

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
struct Acc {
  vector<T> v;
  Acc() {
    v.push_back(0);
  }
  // returns sum of (begin, end]
  T query(int begin, int end) {
    return v[end] - v[begin];
  }
  void append(T x) {
    v.push_back(v.back() + x);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> v(n);
    each (i, v) cin >> i;

    Acc<lli> a;
    each (i, v) a.append(i);

    const lli inf = 1LL << 60;
    auto fn = [&] (int i, int j, int k) {
      unless (i < j) return inf;
      unless (j < k) return inf;
      lli x = max({a.query(0, i), a.query(i, j), a.query(j, k), a.query(k, n)});
      lli y = min({a.query(0, i), a.query(i, j), a.query(j, k), a.query(k, n)});
      return x - y;
    };

    lli mn = inf;
    int i = 1;
    int k = 3;
    for (int j = 2; j < n - 1; ++j) {
      while (i + 1 < j) {
        lli x = abs(a.query(0, i + 0) - a.query(i + 0, j));
        lli y = abs(a.query(0, i + 1) - a.query(i + 1, j));
        if (x > y) ++i;
        else break;
      }
      k = max(k, j + 1);
      while (k + 1 < n) {
        lli x = abs(a.query(j, k + 0) - a.query(k + 0, n));
        lli y = abs(a.query(j, k + 1) - a.query(k + 1, n));
        if (x > y) ++k;
        else break;
      }
      mn = min(mn, fn(i, j, k));
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
