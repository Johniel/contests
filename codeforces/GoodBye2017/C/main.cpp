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

double dist(point a, point b)
{
  double x = a.real() - b.real();
  double y = a.imag() - b.imag();
  x *= x;
  y *= y;
  return sqrt(x + y);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  double R;
  while (cin >> n >> R) {
    vector<double> xs(n);
    each (i, xs) cin >> i;

    vector<point> ps;
    each (x, xs) {
      double mx = R;
      each (p, ps) {
        if (2.0 * R < abs(p.real() - x)) continue;
        double small = p.imag();
        double large = 1000 * 1000 * 10;
        for (int loop = 50; loop--; ) {
          double mid = (small + large) / 2.0;
          if (dist(p, point(x, mid)) <= 2.0 * R) small = mid;
          else large = mid;
        }
        mx = max(mx, small);
      }
      ps.push_back(point(x, mx));
    }

    for (int i = 0; i < ps.size(); ++i) {
      if (i) printf(" ");
      printf("%.10lf", ps[i].imag());
    }
    puts("");
  }


  return 0;
}
