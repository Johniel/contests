# atcoder/arc086/D

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

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    each (i, a) cin >> i;


    int idx = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (abs(a[idx]) < abs(a[i])) {
        idx = i;
      }
    }

    vector<pair<int, int>> v;
    if (0 == a[idx]) {
    } else if (0 < a[idx]) {
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] < 0) {
          a[i] += a[idx];
          v.push_back(make_pair(idx, i));
        }
      }
      for (int i = 0; i + 1 < a.size(); ++i) {
        v.push_back(make_pair(i, i + 1));
      }
    } else {
      for (int i = 0; i < a.size(); ++i) {
        if (0 < a[i]) {
          a[i] += a[idx];
          v.push_back(make_pair(idx, i));
        }
      }
      for (int i = a.size() - 1; 0 <= i - 1; --i) {
        v.push_back(make_pair(i, i - 1));
      }      
    }

    cout << v.size() << endl;
    each (i, v) cout << i.first + 1 << ' ' << i.second + 1 << endl;
  }
  
  return 0;
}
```
