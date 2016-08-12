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
  while (scanf("%d", &n) == 1) {
    int x[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", x + i);
    }
    sort(x, x + n);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      int m;
      scanf("%d", &m);
      printf("%d\n", (int)(upper_bound(x, x + n, m) - x));
    }
  }
  return 0;
}
