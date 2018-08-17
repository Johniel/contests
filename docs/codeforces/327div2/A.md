# codeforces/327div2/A

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
  int l;
  while (scanf("%d", &l) == 1) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.10lf\n", a / (a + b) * l);
  }
  return 0;
}
```
