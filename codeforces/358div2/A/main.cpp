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
  lli n, m;
  while (scanf("%lld%lld", &n, &m) == 2) {
    lli sum = 0;
    for (int i = 1; i <= n; ++i) {
      lli a = i + 1;
      lli b = i + m;
      sum += b/5 - max<lli>(0, a - 1)/5;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
