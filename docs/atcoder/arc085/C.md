# atcoder/arc085/C

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
  int n, m;
  while (cin >> n >> m) {
    double p = 1.0;
    for (int i = 0; i < m; ++i) {
      p /= 2.0;
    }
    const double q = p;
    double x = 0;
    const double a = (n - m) * 100.0;
    const double b = m * 1900.0;
    for (int i = 1; i <= 10000; ++i) {
      x += i * p * (a + b);
      p = p * (1.0 - q);
    }
    printf("%.0lf\n", x);
  }
  
  return 0;
}
```
