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
  int a, b;
  while (scanf("%d%d", &a, &b) == 2) {
    int n;
    scanf("%d", &n);
    double x[n];
    double y[n];
    double v[n];
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf%lf", x + i, y + i, v + i);
    }

    double mn = 1e128;
    auto d = [&] (int i) {
      double s = (a - x[i]);
      double t = (b - y[i]);
      double u = sqrt(s * s + t * t);
      return u / v[i];
    };
    for (int i = 0; i < n; ++i) {
      mn = min(mn, d(i));
    }
    printf("%.10lf\n", mn);
  }
  return 0;
}
