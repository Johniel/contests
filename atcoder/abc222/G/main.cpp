// atcoder/abc222/G/main.cpp
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
// constexpr lli mod = 998244353;

namespace math {
  lli mod_pow(lli n, lli p, const lli mod)
  {
    if (p == 0) return 1;
    if (p == 1) return n % mod;
    lli m = mod_pow(n, p / 2, mod);
    m *= m;
    m %= mod;
    if (p % 2) m = (m * n) % mod;
    return m;
  }
};

namespace math {
  // nと互いに素である1以上n以下の自然数の個数
  // オイラーの定理 x^φ(m)≡1(mod m) xとmは互いに素
  template<typename T=long long int>
  T euler_phi(T n)
  {
    T x = n;
    for (T i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        while (n % i == 0) n /= i;
        x -= x / i;
      }
    }
    if (n != 1) x -= x / n;
    return x;
  }

  // 約数列挙
  // https://qiita.com/drken/items/3beb679e54266f20ab63#4-2-%E9%AB%98%E9%80%9F%E7%B4%84%E6%95%B0%E5%88%97%E6%8C%99
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  lli n;
  while (cin >> n) {
    lli m = n * 9;
    if (m % 2 == 0) m /= 2;
    const lli phim = math::euler_phi(m);
    vec<lli> v;
    for (lli i = 1; i * i <= phim; ++i) {
      if (phim % i == 0) {
        v.push_back(i);
        v.push_back(phim / i);
      }
    }
    sort(v.begin(), v.end());
    lli z = -1;
    each (i, v) {
      if (math::mod_pow(10, i, m) == 1) {
        z = i;
        break;
      }
    }
    cout << z << endl;
  }

  return 0;
}
