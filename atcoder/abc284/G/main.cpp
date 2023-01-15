// github.com/Johniel/contests
// atcoder/abc284/G/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
lli mod;

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

  lli mod_pow(lli n, lli p, lli M = mod)
  {
    if (p == 0) return 1;
    if (p == 1) return n % M;
    lli m = mod_pow(n, p / 2, M);
    m *= m;
    m %= M;
    if (p % 2) m = (m * n) % M;
    return m;
  }
};

int main(int argc, char *argv[])
{
  const int N = 2 * 1e5 + 3;

  lli n;
  while (cin >> n >> mod) {
    static lli fact[N];
    static lli pow[N];
    fact[0] = 1;
    pow[0] = 1;
    for (int i = 1; i < N; ++i) {
      fact[i] = (fact[i - 1] * i) % mod;
      pow[i] = (pow[i - 1] * n) % mod;
    }
    lli z = 0;
    lli a = 1;
    for (lli i = 0; i < n; ++i) {
      // ループするまでの長さ(i+1)。n種類から(i+1)個選んで昇順
      // lli a = fact[n] * math::mod_inverse(fact[n - (i + 1)], mod) % mod;
      (a *= n - i) %= mod;
      // ループしたあと。n種類からn-(i+1)個選ぶ。
      lli b = pow[n - (i + 1)];
      // ループしてどこまで戻るか。0番目からi番目まで(i+1)通り。
      lli c = i * (i + 1) / 2 % mod;
      // cout << i+1 << ": " << a << ' ' << b << ' ' << c << ", " << endl;
      // cout << "a: " << fact[n] << '/' << fact[n - (i + 1)] << " := " << a << endl;
      // cout << "b: " << n << "^" << (n - (i + 1)) << " := " << b << endl;
      // cout << "c: " << c << endl;
      // cout << endl;
      (z += a * b % mod * c % mod) %= mod;
    }
    cout << z << endl;
  }
  return 0;
}
