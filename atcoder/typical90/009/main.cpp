// atcoder/typical90/009/main.cpp
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
constexpr double eps = 1e-11;
constexpr lli mod = 1e9 + 7;

namespace geo {
  // [-M_PI,+M_PI]
  double angle(double x, double y)
  {
    return atan2(y, x);
  }
  template<typename T>
  double angle(complex<T> p)
  {
    return atan2(p.imag(), p.real());
  }
  pair<double, double> rot(pair<double, double> p, double th)
  {
    double a = p.first * cos(th) - p.second * sin(th);
    double b = p.first * sin(th) + p.second * cos(th);
    return make_pair(a, b);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<point> v;
    for (int i = 0; i < n; ++i) {
      double a, b;
      cin >> a >> b;
      v.push_back(point(a, b));
    }

    auto fn = [] (vec<point> u) {
      vec<double> v;
      each (i, u) v.push_back(geo::angle(i));
      const int size = v.size();
      for (int i = 0; i < size; ++i) {
        v.push_back(v[i] + 2 * M_PI);
      }
      sort(v.begin(), v.end());
      double mx = 0;
      each (i, v) {
        auto itr = lower_bound(v.begin(), v.end(), i + M_PI);
        if (itr != v.end()) {
          double j = *itr;
          double th = j - i;
          unless (M_PI < th) setmax(mx, th);
        }
        if (itr != v.begin()) {
          --itr;
          double j = *itr;
          double th = j - i;
          unless (M_PI < th) setmax(mx, th);
        }
      }
      return mx;
    };

    double mx = 0;
    for (int i = 0; i < v.size(); ++i) {
      vec<point> u;
      for (int j = 0; j < v.size(); ++j) {
        if (i != j) u.push_back(v[j] - v[i]);
      }
      setmax(mx, fn(u));
    }
    cout << 360.0 * mx / (2 * M_PI) << endl;
  }

  return 0;
}
