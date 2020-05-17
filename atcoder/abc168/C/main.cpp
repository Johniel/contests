// atcoder/abc168/C/main.cpp
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

pair<double, double> rot(double x, double y, double th)
{
  double p = x * cos(th) - y * sin(th);
  double q = x * sin(th) + y * cos(th);
  return {p, q};
}

double dist(pair<double, double> a, pair<double, double> b)
{
  double x = a.first - b.first;
  double y = a.second - b.second;
  return sqrt(x * x + y * y);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  double a, b, h, m;
  while (cin >> a >> b >> h >> m) {
    double p, q;

    p = ((2 * M_PI) / 12.0 * h) + ((2 * M_PI) / 12.0 / 60.0 * m);
    q = (2 * M_PI) / 60.0 * m;

    pair<double, double> x = rot(0, 1, p);
    pair<double, double> y = rot(0, 1, q);

    x.first *= -a;
    x.second *= -a;

    y.first *= -b;
    y.second *= -b;

    cout << dist(x, y) << endl;
  }

  return 0;
}
