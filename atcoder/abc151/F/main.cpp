// atcoder/abc151/F/main.cpp
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

namespace {
// from: https://tubo28.me/compprog/algorithm/minball/
  using ld = long double;
  using P = std::complex<ld>;
  const ld eps = 1e-10;

  ld cross(const P &a, const P &b) { return a.real() * b.imag() - a.imag() * b.real(); }
  ld dot(const P &a, const P &b) { return a.real() * b.real() + a.imag() * b.imag(); }

  template <class iter>
  std::pair<P, ld> min_ball(iter left, iter right, int seed = 1333) {
    const int n = right - left;

    assert(n >= 1);
    if (n == 1) {
      return {*left, ld(0)};
    }

    std::mt19937 mt(seed);
    std::shuffle(left, right, mt);
    // std::random_shuffle(left, right); // simple but deprecated

    iter ps = left;
    using circle = std::pair<P, ld>;

    auto make_circle_3 = [](const P &a, const P &b, const P &c) -> circle {
      ld A = std::norm(b - c), B = std::norm(c - a), C = std::norm(a - b),
        S = cross(b - a, c - a);
      P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) / (4 * S * S);
      ld r2 = std::norm(p - a);
      return {p, r2};
    };

    auto make_circle_2 = [](const P &a, const P &b) -> circle {
      P c = (a + b) / (ld)2;
      ld r2 = std::norm(a - c);
      return {c, r2};
    };

    auto in_circle = [](const P &a, const circle &c) -> bool {
      return std::norm(a - c.first) <= c.second + eps;
    };

    circle c = make_circle_2(ps[0], ps[1]);

    // MiniDisc
    for (int i = 2; i < n; ++i) {
      if (!in_circle(ps[i], c)) {
        // MiniDiscWithPoint
        c = make_circle_2(ps[0], ps[i]);
        for (int j = 1; j < i; ++j) {
          if (!in_circle(ps[j], c)) {
            // MiniDiscWith2Points
            c = make_circle_2(ps[i], ps[j]);
            for (int k = 0; k < j; ++k) {
              if (!in_circle(ps[k], c)) {
                c = make_circle_3(ps[i], ps[j], ps[k]);
              }
            }
          }
        }
      }
    }
    return c;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<P> ps;
    for (int i = 0; i < n; ++i) {
      ld a, b;
      cin >> a >> b;
      ps.push_back(P(a, b));
    }

    auto q = min_ball(ps.begin(), ps.end());
    cout << sqrt(q.second) << endl;
  }

  return 0;
}
