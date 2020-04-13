// atcoder/arc029/B/main.cpp
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

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  double a, b;
  int n;
  while (cin >> a >> b >> n) {
    unless (a < b) swap(a, b);
    vec<pair<double, double>> v(n);
    cin >> v;

    auto fn = [&] (double th) {
      double i = a * cos(th) + b * sin(th);
      double r = a * sin(th) + b * cos(th);
      return make_pair(i, r);
    };

    constexpr double eps = 1e-11;

    auto binsearch = [&] (double x, double y) {
      if (a <= x && b <= y) return true;
      double small = 0;
      double large = M_PI / 2.0;
      for (int _ = 0; _ < 1000; ++_) {
        double th = (small + large) / 2.0;
        auto p = fn(th);
        if (p.first <= x && p.second <= y) return true;
        if (p.first < x) small = th;
        else large = th;
      }
      return false;
      // return fn(small).second <= y + eps;
    };

    each (i, v) {
      bool f = false;
      f = f || binsearch(i.first, i.second);
      f = f || binsearch(i.second, i.first);
      cout << (f ? "YES" : "NO") << endl;
    }
  }

  return 0;
}
