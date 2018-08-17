# codeforces/307/A

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
    int m[n];
    for (int i = 0; i < n; ++i) {
      cin >> m[i];
    }
    for (int i = 0; i < n; ++i) {
      int cnt = 1;
      for (int j = 0; j < n; ++j) {
        cnt += (m[i] < m[j]);
      }
      if (i) cout << ' ';
      cout << cnt;
    }
    cout << endl;
  }
  return 0;
}
```
