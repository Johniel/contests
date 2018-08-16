# codeforces/325div2/A

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
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    if (count(a, a + n, 0) == n) {
      cout << 0 << endl;
      continue;
    }
    int h = 0;
    while (a[n-1] == 0) --n;
    {
      int i;
      for (i = 0; i < n; ++i) {
        if (a[i]) break;
      }
      for (; i < n; ++i) {
        if (i + 1 < n && a[i] == 0 && a[i + 1] == 0) ;
        else if (i && a[i] == 0 && a[i - 1] == 0) ;
        else ++h;
      }
    }
    cout << h << endl;

  }
  return 0;
}
```
