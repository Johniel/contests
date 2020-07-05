// atcoder/abc172/E/main.cpp
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

const lli N = 5 * 1e5 + 5;
namespace math {
  lli fact[N], finv[N], inv[N];

  void init()
  {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; i++){
      fact[i] = fact[i - 1] * i % mod;
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
  }

  lli mod_comb(int n, int k)
  {
    assert(n < N && k < N);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
  }

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
  // nHm=n+m-1Cm

  lli mod_pow(lli n, lli p)
  {
    if (p == 0) return 1;
    if (p == 1) return n;
    lli m = mod_pow(n, p / 2);
    m *= m;
    m %= mod;
    if (p % 2) m = (m * n) % mod;
    return m;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  math::init();

  lli n, m;
  while (cin >> n >> m) {
    // Aの選び方mCn
    // Aの並び替えがN!パターン
    // あるAに対してBの選び方はnCm
    // Aを固定して条件を満たすBを数える。その数のnCm倍が答え。
    const lli N = 5 * 1e5 + 5;
    lli x[N]; // x[n] := n個が一致するAとBの選び方
    fill(x, x + N, 0);
    lli y = 0;
    for (int i = n; 0 <= i; --i) {
      lli z = 1;
      // Aのパターン数
      // MからN個取り出して使う数字を決める(順番に意味あり)
      z *= (math::mod_comb(m, n) * math::fact[n]) % mod;
      z %= mod;
      // N個のうち、一致する位置を選ぶ。個数はi。
      z *= math::mod_comb(n, i);
      z %= mod;
      // 選ばれなかった部分のBの取り替え方(順番に意味あり)
      // 取り替えられるのはN-i個で、候補はM-i個。
      z *= (math::mod_comb(m - i, n - i) * math::fact[n - i]) % mod;
      z %= mod;

      // x[i] = (z - y + mod) % mod;
      // y += x[i];
      // y %= mod;
      x[i] = z;
    }

    lli sum = 0;
    for (int i = 0; i <= n; ++i) {
      if (i%2) sum -= x[i];
      else sum += x[i];
      sum = (sum + mod) % mod;
    }
    // for (int i = 0; i < 10; ++i) {
    //   cout << make_pair(i, x[i]) << ' ';
    // }
    // cout << endl;

    // cout << x[0] << endl;
    cout << sum << endl;
  }

  return 0;
}
