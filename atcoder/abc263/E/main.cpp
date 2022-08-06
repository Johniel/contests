// atcoder/abc263/E/main.cpp
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
constexpr lli mod = 998244353;

namespace math {
  lli extgcd(lli a, lli b, lli& x, lli& y)
  {
    lli g = a;
    x = 1;
    y = 0;
    if (b != 0) {
      g = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    return g;
  }

  lli mod_inverse(lli a, lli m)
  {
    lli x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }
};

template<typename T = long long int>
struct BIT {
  vector<T> v;
  int n;

  BIT(int n_ = 0) {
    n = n_;
    v.resize(n + 1, 0);
  }

  T operator () (int i) const {
    T s = 0;
    while (i > 0) {
      (s += v.at(i)) %= mod;
      i -= i & -i;
    }
    return s;
  }

  T operator () (int begin, int end) const {
    assert(begin <= end);
    return ((*this)(end) - (*this)(begin) + mod) % mod;
  }

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      (v.at(i) += x) %= mod;
      i += i & -i;
    }
    return ;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 2 * 1e5 + 3;
  int n;
  while (cin >> n) {
    vec<int> a(n - 1);
    cin >> a;

    // static lli dp[N];
    // fill(dp, dp + N, 0);
    // for (int i = a.size() - 1; 0 <= i; --i) {
    //   lli x = a[i] + 1;
    //   for (int j = 1; j <= a[i] && i + j < n; ++j) {
    //     (x += dp[i + j]) %= mod;
    //   }
    //   (x *= math::mod_inverse(a[i], mod)) %= mod;
    //   dp[i] = x;
    // }
    // cout << dp[0] << endl;

    BIT<lli> bit(N);
    for (int i = a.size() - 1; 0 <= i; --i) {
      auto x = bit(i + 1, min(i + a[i] + 1, N - 1)) + a[i] + 1;
      x *= math::mod_inverse(a[i], mod);
      bit.add(i, x);
    }
    cout << bit(0, 1) << endl;
  }

  return 0;
}
