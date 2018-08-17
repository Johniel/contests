# codeforces/hello2018/D

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

struct S {
  int first, second, idx;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, T;
  while (cin >> n >> T) {
    vector<S> a(n);
    each (i, a) cin >> i.first >> i.second;
    for (int i = 0; i < n; ++i) {
      a[i].idx = i;
    }
    sort(a.begin(), a.end(), [] (auto x, auto y) { return x.second < y.second; });
    auto f = [&] (int m) {
      lli sum = 0;
      int cap = m;
      each (i, a) {
        if (cap == 0) break;
        if (m <= i.first) {
          --cap;
          sum += i.second;
        }
      }
      return cap == 0 && sum <= T;
    };
    int small = 0;
    int large = a.size() + 1;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (f(mid)) small = mid;
      else large = mid;
    }
    cout << small << endl;
    vector<int> v;
    for (int i = 0; i < a.size() && v.size() < small; ++i) {
      if (small <= a[i].first) {
        v.push_back(a[i].idx);
      }
    }
    cout << v.size() << endl;
    each (i, v) cout << i+1 << ' ';
    cout << endl;
  }
  
  return 0;
}
```
