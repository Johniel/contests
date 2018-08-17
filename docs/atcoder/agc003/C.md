# atcoder/agc003/C

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
  int n;
  while (cin >> n) {
    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    map<int, int> no;
    for (int i = 0; i < n; ++i) {
      no[b[i]] = i;
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(no[a[i]]);
    }

    int odd = 0;
    int even = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (i % 2 != v[i] % 2) {
        int& o = odd;
        int& e = even;
        (i % 2 ? o : e) += 1;
      }
    }
    assert(odd == even);
    cout << odd << endl;
  }
  return 0;
}
```
