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
  int d, h, v, e;
  while (scanf("%d%d%d%d", &d, &h, &v, &e) == 4) {
    const double pi =  3.141592653589793238462643383279;
    auto fn = [&] (double t) {
      const double a = pi * (d / 2.0) * (d / 2.0);
      return (a * h) + (a * e * t) < (v * t) + 1e-10;
    };
    double small = 0, large = 100000;
    for (int loop = 100; loop--; ) {
      double mid = (small + large) / 2;
      if (fn(mid)) large = mid;
      else small = mid;
    }
    if (fn(large)) {
      puts("YES");
      printf("%.10lf\n", large);
    } else {
      puts("NO");
    }
    
  }
  return 0;
}
