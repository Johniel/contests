// atcoder/abc259/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

namespace geo {
  using point = complex<double>;

  // [-M_PI,+M_PI]の範囲で偏角を返す。
  double angle(double x, double y)
  {
    return atan2(y, x);
  }
  template<typename T>
  double angle(complex<T> p)
  {
    return atan2(p.imag(), p.real());
  }

  // 点pを原点中心にthだけ回転させた座標を返す。
  pair<double, double> rot(double x, double y, double th)
  {
    double a = x * cos(th) - y * sin(th);
    double b = x * sin(th) + y * cos(th);
    return make_pair(a, b);
  }
  pair<double, double> rot(pair<double, double> p, double th)
  {
    return rot(p.first, p.second, th);
  }
  point rot(point p, double th) {
    auto r = rot(p.real(), p.imag(), th);
    return point(r.first, r.second);
  }

  template<typename T>
  struct Circle {
    complex<T> p;
    T r;
    Circle(complex<T> p_, T r_) : p(p_), r(r_) {}
    Circle(T x, T y, T r_) : p(complex<T>(x, y)), r(r_) {}
    T x() const { return p.real(); }
    T y() const { return p.imag(); }
  };


  template<typename T>
  bool intersectCC(const Circle<T>& a, const Circle<T>& b) {
    assert(false);
    return false;
  }

  // verified at: abc259/D
  template<>
  bool intersectCC(const Circle<long long int>& a, const Circle<long long int>& b) {
    long long int x = a.x() - b.x();
    long long int y = a.y() - b.y();
    long long int D = x * x + y * y;

    long long int mn = a.r - b.r;
    mn *= mn;

    long long int mx = a.r + b.r;
    mx *= mx;

    return mn <= D && D <= mx;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  lli s1, s2, t1, t2;
  while (cin >> n >> s1 >> s2 >> t1 >> t2) {
    const int N = 3000 + 3;
    static lli x[N], y[N], r[N];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> r[i];
    }
    const double eps = 1e-11;
    x[n] = s1;
    y[n] = s2;
    r[n] = 0;
    const int src = n++;
    x[n] = t1;
    y[n] = t2;
    r[n] = 0;
    const int dst = n++;
    static bool g[N][N];
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        geo::Circle<lli> a(x[i], y[i], r[i]);
        geo::Circle<lli> b(x[j], y[j], r[j]);
        g[i][j] = g[j][i] = geo::intersectCC<lli>(a, b);
      }
    }

    queue<int> q;
    static bool vis[N];
    fill(vis, vis + N, false);
    vis[src] = true;
    for (q.push(src); q.size(); q.pop()) {
      int curr = q.front();
      for (int next = 0; next < n; ++next) {
        if (g[curr][next] && !vis[next]) {
          vis[next] = true;
          q.push(next);
        }
      }
    }
    cout << (vis[dst] ? "Yes" : "No") << endl;
  }

  return 0;
}
