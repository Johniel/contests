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

double dist_pp(point a, point b)
{
  double x = a.real() - b.real();
  double y = a.imag() - b.imag();
  x *= x;
  y *= y;
  return sqrt(x + y);
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    point a(x, y);
    scanf("%lf%lf", &x, &y);
    point b(x, y);
    vector<point> v;
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf", &x, &y);
      v.push_back(point(x, y));
    }
    sort(v.begin(), v.end(), [&] (point s, point t) { return dist_pp(a, s) < dist_pp(a, t); });
    
    double mn = 0;
    {
      double mn1 = 0;
      double mn2 = 0;
      each (p, v) mn1 = max(mn1, dist_pp(p, a));
      each (p, v) mn2 = max(mn2, dist_pp(p, b));
      mn = min(mn1, mn2) * min(mn1, mn2);
    }

    for (int i = 0; i < v.size(); ++i) {
      double A = dist_pp(v[i], a);
      double B = 0;
      for (int j = i + 1; j < v.size(); ++j) {
        double db = dist_pp(b, v[j]);
        B = max(B, db);
      }
      mn = min(mn, A * A + B * B);
    }
    printf("%.0lf\n", mn);
  }
  return 0;
}
