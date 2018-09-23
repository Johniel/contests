#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template <typename P, typename Q>
ostream& operator<<(ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
  os << "(";
  each (i, v)
    os << i << ",";
  os << ")";
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

namespace CCW
{
enum { RIGHT = 1, LEFT = -1, FRONT = -2, BACK = +2, OTHER = 0 };
};
int ccw(point a, point b, point c)
{
  b -= a;
  c -= a;
  if (cross(b, c) < 0) return CCW::RIGHT;
  if (cross(b, c) > 0) return CCW::LEFT;
  if (dot(b, c) < 0) return CCW::BACK;
  if (norm(b) < norm(c)) return CCW::FRONT;
  return CCW::OTHER;
}

int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, d, m;
  while (cin >> n >> d >> m) {
    vector<point> ps;
    ps.push_back(point(0, d));
    ps.push_back(point(d, 0));
    ps.push_back(point(n, n - d));
    ps.push_back(point(n - d, n));
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      point z(x, y);
      bool f = false;
      for (int j = 0; j < ps.size(); ++j) {
        int k = (j + 1) % ps.size();
        f = f || ccw(ps[j], ps[k], z) == CCW::OTHER;
      }
      bool g = true;
      for (int j = 0; j < ps.size(); ++j) {
        int k = (j + 1) % ps.size();
        g = g && ccw(ps[j], ps[k], z) == CCW::LEFT;
      }
      cout << (f || g ? "YES" : "NO") << endl;
    }
  }

  return 0;
}
