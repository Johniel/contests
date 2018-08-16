# atcoder/agc002/C

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
  int n, l;
  while (cin >> n >> l) {
    vector<int> v;;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      v.push_back(a);
    }

    int idx = -1;
    for (int i = 0; i + 1 < v.size(); ++i) {
      if (l <= v[i] + v[i + 1]) {
        idx = i;
        break;
      }
    }

    if (idx == -1) {
      cout << "Impossible" << endl;
      continue;
    }

    cout << "Possible" << endl;
    for (int i = 0; i < idx; ++i) {
      cout << i + 1 << endl;
    }
    for (int i = n - 2; idx <= i; --i) {
      cout << i + 1 << endl;
    }
  }
  return 0;
}
```
