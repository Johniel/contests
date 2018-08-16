# atcoder/arc075/E

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

template<typename V>
class BIT {
public:
  vector<V> bit;
  int n;
  BIT (int n_)
  {
    n = n_;
    bit.resize(n + 1);
  }
  V sum(int i)
  {
    ++i; // 1-origin
    V s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void add(int i, V x)
  {
    ++i; // 1-origin
    while (i <= n)
    {
      bit[i] += x;
      i += i & -i;
    }
    return ;
  }
  void set(int i, V x)
  {
    return add(i, x - bit[i]);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, k;
  while (cin >> n >> k) {
    vector<lli> a(n);
    each (i, a) cin >> i;
    each (i, a) i-= k;

    vector<lli> acc(n);
    acc[0] = a[0];
    for (int i = 1; i < n; ++i) {
      acc[i] = acc[i - 1] + a[i];
    }

    vector<pair<lli, int>> v;
    v.push_back(make_pair(0, 0));
    each (i, acc) {
      v.push_back(make_pair(i, v.size()));
    }
    stable_sort(v.begin(), v.end());

    lli sum = 0;
    BIT<lli> bit(v.size());
    each (i, v) {
      sum += bit.sum(i.second);
      bit.add(i.second, 1);
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
