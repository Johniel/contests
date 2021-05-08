// atcoder/arc049/B/main.cpp
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
constexpr double eps = 1e-7;

struct R {
  pair<double, double> mn, mx;
  // a-->x
  // ^   |
  // |   v
  // x<--b

  bool valid(void) const {
    return mn.first <= mx.first + 1e-7 && mn.second <= mx.second + 1e-7;
  }
};

R operator | (R x, R y) {
  pair<double, double> p, q;
  p.first = max(x.mn.first, y.mn.first);
  p.second = max(x.mn.second, y.mn.second);
  q.first = min(x.mx.first, y.mx.first);
  q.second = min(x.mx.second, y.mx.second);
  return R({p, q});
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    const int N = 1000 + 3;
    static double x[N];
    static double y[N];
    static double c[N];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> c[i];
    }

    auto fn = [&] (double d) {
      R comm;
      comm.mn = make_pair(x[0] - d / c[0], y[0] - d / c[0]);
      comm.mx = make_pair(x[0] + d / c[0], y[0] + d / c[0]);

      for (int i = 0; i < n; ++i) {
        R r;
        r.mn = make_pair(x[i] - d / c[i], y[i] - d / c[i]);
        r.mx = make_pair(x[i] + d / c[i], y[i] + d / c[i]);
        comm = (comm | r);
      }
      return comm;
    };

    double small = 0;
    double large = 1e128;
    for (int _ = 10000; _--;) {
      double mid = (small + large) / 2.0;
      if (fn(mid).valid()) large = mid;
      else small = mid;
    }
    R r = fn(large);
    cout << large << endl;
    // double mx = 0;
    // for (int i = 0; i < n; ++i) {
    //   double c1 = abs(x[i] - r.mn.first);
    //   double c2 = abs(x[i] - r.mx.first);
    //   double c3 = abs(y[i] - r.mn.second + eps);
    //   double c4 = abs(y[i] - r.mx.second + eps);
    //   setmax(mx, c[i] * max({c1, c2, c3, c4}));
    // }
    // cout << mx << endl;
  }

  return 0;
}
