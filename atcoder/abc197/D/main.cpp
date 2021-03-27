// atcoder/abc197/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

point rot(point p, double th)
{
  double x = p.real() * cos(th) - p.imag() * sin(th);
  double y = p.real() * sin(th) + p.imag() * cos(th);
  return point(x, y);
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  double n, x0, y0, xn2, yn2;
  while (cin >> n >> x0 >> y0 >> xn2 >> yn2) {
    swap(x0, xn2);
    swap(y0, yn2);

    const point p0(x0, y0);
    const point p1(xn2, yn2);

    double a = 180.0 - 180 * (n - 2.0) / n;

    point base((xn2 - x0) / 2.0, (yn2 - y0) / 2.0);
    point o(xn2 - x0 - base.real(), yn2 - y0 - base.imag());

    // cout << 180 * (n - 2.0) << endl;
    // cout << a << endl;
    // cout << base << endl;
    // cout << o << endl;

    double th = a / 360.0 * 2 * M_PI;
    // cout << th << endl;

    point s = rot(o, +th);
    point t = rot(o, -th);

    // cout << s << ' ' << t << endl;

    s = point(s.real() + base.real() + x0, s.imag() + base.imag() + y0);
    t = point(t.real() + base.real() + x0, t.imag() + base.imag() + y0);

    // cout << s << ' ' << t << endl;

    if (ccw(p0, p1, s) == CCW::LEFT) {
      cout << s.real() << ' ' << s.imag() << endl;
    } else {
      cout << t.real() << ' ' << t.imag() << endl;
    }
    // cout << endl;
  }

  return 0;
}
