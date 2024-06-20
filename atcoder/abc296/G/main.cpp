// github.com/Johniel/contests
// atcoder/abc296/G/main.cpp

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

namespace std {
  template<typename T>
  bool operator < (complex<T> a, complex<T> b) {
    if(a.real() != b.real())return a.real() < b.real();
    return a.imag() < b.imag();
  }
  template<typename T>
  complex<T> operator * (complex<T> v, T n) {
    v.real(v.real() * n);
    v.imag(v.imag() * n);
    return v;
  }
  template<typename T>
  complex<T> operator / (complex<T> v, T n) {
    v.real(v.real() / n);
    v.imag(v.imag() / n);
    return v;
  }
};

namespace geo {
  template<typename T>
  complex<T> normal(complex<T> v)
  {
    return v * complex<T>(0, -1);
  }

  template<typename T>
  T dot(complex<T> a, complex<T> b)
  {
    return (a.real() * b.real() + a.imag() * b.imag());
  }

  template<typename T>
  T cross(complex<T> a, complex<T> b)
  {
    return (a.real() * b.imag() - a.imag() * b.real());
  }

  namespace CCW {
    enum { RIGHT = 1, LEFT = -1, FRONT = -2, BACK = +2, OTHER = 0 };
  };
  template<typename T>
  int ccw(complex<T> a, complex<T> b, complex<T> c)
  {
    b -= a;
    c -= a;
    if (cross(b, c) < 0) return CCW::RIGHT;
    if (cross(b, c) > 0) return CCW::LEFT;
    if (dot(b, c) < 0) return CCW::BACK;
    if (norm(b) < norm(c)) return CCW::FRONT;
    return CCW::OTHER;
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

  complex<double> rot(complex<double> p, double th)
  {
    auto r = rot(p.real(), p.imag(), th);
    return complex<double>(r.first, r.second);
  }

  template<std::integral T>
  complex<T> rot90(complex<T> p)
  {
    T x = -p.imag();
    T y = p.real();
    return complex<T>(x, y);
  }
};

template<typename T> istream& operator >> (istream& is, complex<T>& p)
{
  T x, y;
  is >> x >> y;
  p.real(x);
  p.imag(y);
  return is;
}

using namespace geo;

using point = complex<lli>;

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n) {
    vec<point> a;
    for (int i = 0; i < n; ++i) {
      point p;
      cin >> p;
      a.push_back(p);
    }
    int q;
    cin >> q;
    while (q--) {
      point p;
      cin >> p;

      if (ccw(a[0], a[1], p) == CCW::OTHER) {
        cout << "ON" << endl;
        continue;
      }
      if (ccw(a[0], a[n - 1], p) == CCW::OTHER) {
        cout << "ON" << endl;
        continue;
      }

      int small = 0;
      int large = a.size();
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (ccw(a[0], a[1], p) == ccw(a[0], a[mid], p)) small = mid;
        else large = mid;
      }
      if (
        large &&
        large < a.size() &&
        ccw(a[0], a[large - 1], p) == ccw(a[large - 1], a[large], p) &&
        ccw(a[large - 1], a[large], p) == ccw(a[large], a[0], p)) {
        cout << "IN" << endl;
        continue;
      }
      if (large && large < a.size() && ccw(a[large - 1], a[large], p) == CCW::OTHER) {
        cout << "ON" << endl;
        continue;
      }
      if (large && ccw(a[0], a[large - 1], p) == CCW::OTHER) {
        cout << "IN" << endl;
        continue;
      }
      if (large < a.size() && ccw(a[0], a[large], p) == CCW::OTHER) {
        cout << "IN" << endl;
        continue;
      }
      cout << "OUT" << endl;
    }
  }
  return 0;
}
