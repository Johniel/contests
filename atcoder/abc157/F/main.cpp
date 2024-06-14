// github.com/Johniel/contests
// atcoder/abc157/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

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
  // verified at: abc259/B
  pair<double, double> rot(double x, double y, double th)
  {
    double a = x * cos(th) - y * sin(th);
    double b = x * sin(th) + y * cos(th);
    return make_pair(a, b);
  }

  // verified at: abc259/B
  pair<double, double> rot(pair<double, double> p, double th)
  {
    return rot(p.first, p.second, th);
  }

  // verified at: abc259/B
  point rot(point p, double th)
  {
    auto r = rot(p.real(), p.imag(), th);
    return point(r.first, r.second);
  }

  template<typename T>
  pair<T, T> rot90(T x, T y)
  {
    T a = x * 0 - y * 1;
    T b = x * 1 + y * 0;
    return make_pair(a, b);
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


  const double eps = 1e-8;
  const double PI = acos(-1);

  bool eq(double a, double b) {
    return abs(a - b) < eps;
  }

  bool eq(point a, point b) {
    return eq(a.real(), b.real()) && eq(a.imag(), b.real());
  }

  // 円と円の交差判定。
  //  0 : 交差、内包なし
  //  1 : 外部で1点と接する
  //  2 : 2点で交差
  // -1 : 内包して接する
  // -2 : 完全に内包
  int intersectCC(Circle<double> a, Circle<double> b) {
    double x = a.p.real() - b.p.real();
    double y = a.p.imag() - b.p.imag();
    double s = a.r + b.r;
    double d = x*x + y*y;
    s *= s;
    if(eq(d, s)) return 1;
    if(d > s) return 0;
    double r = abs(a.r - b.r);
    r *= r;
    if(eq(d, r)) return -1;
    if(d > r) return 2;
    return -2;
  }

  // 円aと円bが１点もしくは２点で接しているかを判定する。
  // verified at: abc259/D
  bool intersectCC(const Circle<long long int>& a, const Circle<long long int>& b) {
    // a.r>b.rとしたとき、aとbの距離がaの円周上から|b.r|の範囲にあれば接する。
    long long int x = a.x() - b.x();
    long long int y = a.y() - b.y();
    long long int D = x * x + y * y;
    long long int mn = a.r - b.r;
    mn *= mn;
    long long int mx = a.r + b.r;
    mx *= mx;
    return mn <= D && D <= mx;
  }

  // 円と円の交点
  vector<point> get_cross_points(Circle<double> c1, Circle<double> c2) {
    vector<point> v;
    int cp = intersectCC(c1,c2);
    if(cp == 0 || cp == -2) return v;

    double ll = norm(c1.p - c2.p);
    double A = (c1.r * c1.r - c2.r * c2.r + ll) / (2.0 * ll);
    point base = c2.p - c1.p;

    if(abs(cp) == 1) {
      v.push_back(c1.p + A * base);
    } else {
      point n(-base.imag(), base.real());
      n /= abs(n);
      double h = sqrt(c1.r * c1.r - A * A * ll);
      v.push_back(c1.p + A * base + h * n);
      v.push_back(c1.p + A * base - h * n);
    }
    return v;
  }
};

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k) {
    double x[n], y[n], r[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> r[i];
    }
    vec<geo::point> ps;
    for (int i = 0; i < n; ++i) {
      ps.push_back(geo::point(x[i], y[i]));
    }

    auto fn = [&] (const double T) {
      vec<geo::point> cand;
      for (int i = 0; i < n; ++i) {
        cand.push_back(ps[i]);
        for (int j = i + 1; j < n; ++j) {
          auto a = geo::Circle(ps[i], T / r[i]);
          auto b = geo::Circle(ps[j], T / r[j]);
          vec<geo::point> u = geo::get_cross_points(a, b);
          each (c, u) cand.push_back(c);
        }
      }
      each (c, cand) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
          double dist = abs(c - ps[i]) * r[i];
          cnt += (dist <= (T + geo::eps));
        }
        if (k <= cnt) return true;
      }
      return false;
    };

    double small = 0.0;
    double large = 1e20;
    for (int _ = 0; _ < 1000; ++_) {
      double mid = (small + large) / 2;
      if (fn(mid)) large = mid;
      else small = mid;
    }
    cout << small << endl;
  }
  return 0;
}
