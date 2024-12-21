// github.com/Johniel/contests
// atcoder/abc385/F/main.cpp

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

#define double long double

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const double eps = 1e-11;

typedef complex<lli> point;

bool eq(double a, double b)
{
  return fabs(a - b) < eps;
}

point normal(point v)
{
  return v * point(0, -1);
}

lli dot(point a, point b)
{
  return (a.real() * b.real() + a.imag() * b.imag());
}

lli cross(point a, point b)
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

inline int ccw(pair<lli, lli> a, pair<lli, lli> b, pair<lli, lli> c) {
  return ccw(
    point(a.first, a.second),
    point(b.first, b.second),
    point(c.first, c.second));
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<pair<lli, lli>> v(n);
    cin >> v;

    if (n == 1) {
      cout << -1 << endl;
      continue;
    }

    const pair<lli, lli> O = make_pair(0, 0);
    {
      bool f = true;
      for (int i = 1; i < v.size(); ++i) {
        auto tmp = ccw(O, v[i - 1], v[i]);
        f = f && (tmp == CCW::FRONT);
      }
      if (f) {
        cout << 0.000000000000 << endl;
        continue;
      }
    }
    {
      bool f = true;
      for (int i = 1; i < v.size(); ++i) {
        auto tmp = ccw(O, v[i - 1], v[i]);
        f = f && (tmp == CCW::LEFT);
      }
      if (f) {
        cout << -1 << endl;
        continue;
      }
    }

    vec<pair<lli, lli>> a;
    // a.push_back(make_pair(0, 0));
    a.push_back(v[0]);
    a.push_back(v[1]);
    double z = 0;
    {
        const int sz = a.size();
        double dx = a[sz - 1].first - a[sz - 2].first;
        double dy = a[sz - 1].second - a[sz - 2].second;
        double A = dy / dx;
        double C = a[sz - 1].second - A * a[sz - 1].first;
        // cout << "C: " << C << endl;
        setmax(z, C);

    }
    for (int i = 2; i < v.size(); ++i) {
      while (2 <= a.size()) {
        int sz = a.size();
        if (ccw(a[sz - 2], a[sz - 1], v[i]) == CCW::LEFT) {
          a.pop_back();
        } else {
          break;
        }
      }
      a.push_back(v[i]);
      if (2 <= a.size()) {
        const int sz = a.size();
        double dx = a[sz - 1].first - a[sz - 2].first;
        double dy = a[sz - 1].second - a[sz - 2].second;
        double A = dy / dx;
        double C = a[sz - 1].second - A * a[sz - 1].first;
        // cout << "C: " << C << endl;
        setmax(z, C);
      }
    }
    cout << z << endl;
  }
  return 0;
}
