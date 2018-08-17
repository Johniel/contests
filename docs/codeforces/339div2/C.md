# codeforces/339div2/C

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

point normal(point v)
{
  return v * point(0, -1);
}

double dot(point a, point b)
{
  return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(point a, point b)
{
  return (a.real() * b.imag() - a.imag() * b.real());
}

namespace CCW{
  enum{ RIGHT = 1, LEFT = -1, FRONT = -2, BACK = +2, OTHER = 0 };
};
int ccw(point a, point b, point c)
{
  b -= a;
  c -= a;
  if( cross(b, c) < 0 )return CCW::RIGHT;
  if( cross(b, c) > 0 )return CCW::LEFT;
  if( dot(b, c) < 0 )return CCW::BACK;
  if( norm(b) < norm(c) )return CCW::FRONT;
  return CCW::OTHER;
}

bool inside(vector<point> v, point p)
{
  bool r = true;
  bool l = true;
  for (int i = 0; i < v.size() + 2; ++i) {
    int a = i % v.size();
    int b = (i + 1) % v.size();
    r = r && (ccw(v[a], v[b], p) == CCW::RIGHT);
    l = l && (ccw(v[a], v[b], p) == CCW::LEFT);
  }
  return r || l;
}

double dist_pp(point a, point b)
{
  double s = a.real() - b.real();
  double t = a.imag() - b.imag();
  s *= s;
  t *= t;
  return sqrt(s + t);
}


double D(point a, point b)
{
  double s = a.real() - b.real();
  double t = a.imag() - b.imag();
  s *= s;
  t *= t;
  return s + t;
}

double area(double r)
{
  return r * r * 3.14159265358979323846264338327950288;
}

const double EPS = 1e-8;

double distance_lp(point a1, point a2, point b)
{
  if(dot(a2-a1, b-a1) < EPS)return abs(b-a1);
  if(dot(a1-a2, b-a2) < EPS)return abs(b-a2);
  return abs(cross(a2-a1, b-a1)) / abs(a2-a1);
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    point p(a, b);

    vector<point> v;
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      v.push_back(point(a, b));
    }
    point f = v[0];
    each (q, v) {
      if (D(p, f) < D(p, q)) {
        f = q;
      }
    }
    double mn = 1e128;
    for (int i = 0; i < v.size() + 10; ++i) {
      mn = min(mn, distance_lp(v[i % v.size()], v[(i + 1) % v.size()], p));
    }
    printf("%.10lf\n", area(dist_pp(p, f)) - area(mn));
  }
  return 0;
}
```
