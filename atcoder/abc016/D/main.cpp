// atcoder/abc016/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

constexpr double eps = 1e-11;

bool eq(double a, double b)
{
  return fabs(a - b) < eps;
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

bool online_pl(point a1, point a2, point b)
{
  return eq(cross(a1-a2, b-a2), 0);
}

bool intersect_ll(point a1, point a2, point b1, point b2)
{
  return ( ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
           ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0 );
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x1, y1, x2, y2;
  while (cin >> x1 >> y1 >> x2 >> y2) {
    point a(x1, y1);
    point b(x2, y2);
    int n;
    cin >> n;
    vector<point> ps;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      ps.push_back(point(x, y));
    }
    int sum = 0;
    for (int i = 0; i < ps.size(); ++i) {
      point s = ps[i];
      point t = ps[(i + 1) % ps.size()];
      if (online_pl(a, b, s) || online_pl(a, b, t)) ++sum;
      else if (intersect_ll(a, b, s, t)) sum += 2;
    }
    cout << sum / 2 / 2 + 1 << endl;
  }

  return 0;
}
