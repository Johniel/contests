// atcoder/abc217/F/main.cpp
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
constexpr lli mod = 998244353;

const int N = 200 * 2 + 3;

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

  inline lli nCk(int n, int k)
  {
    return mod_comb(n, k);
  }

  // n個の箱にm個の何かを分配する場合の数
  inline lli nHm(int n, int m)
  {
    return nCk(n + m - 1, m);
  }
};

lli memo[N][N];
bool g[N][N];

lli rec(int begin, int end)
{
  if ((end - begin) % 2) return 0;
  if (begin == end) return 1;
  lli& ret = memo[begin][end];
  if (ret != -1) return ret;
  lli x = 0;
  for (int i = begin + 1; i < end; ++i) {
    // cout << make_pair(begin, i) << ' ' << g[begin][i] << endl;
    if (g[begin][i]) {
      lli a = rec(begin + 1, i);
      lli b = rec(i + 1, end);
      if (a == 0 || b == 0) {
        // cout << make_pair(begin, end) << "->" << make_pair(begin+1,i) << "," << make_pair(i+1,end) << ' ' << make_pair(a, b) << endl;
        continue;
      }
      lli c;
      if (i + 1 == end) {
        c = 1;
      } else {
        c = math::mod_comb((end - begin) / 2, (i + 1 - begin) / 2);
      }

      lli y = 1;
      (y *= a) %= mod;
      (y *= b) %= mod;
      (y *= c) %= mod;
      // cout << make_pair(begin, end) << "->" << make_pair(begin+1,i) << "," << make_pair(i+1,end) << ' ' << make_pair(a, b) << ' ' << c << ' ' <<y << endl;
      // cout << make_pair(begin, end) << "->" << make_pair(begin+1,i) << "," << make_pair(i+1,end) << ' ' << make_pair(a, b) << ' ' << c << ' ' <<y << ' ' << (end - begin) / 2 << "C" <<(i - begin) / 2 << endl;
      (x += y) %= mod;
    }
  }
  return ret = x;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  math::init();

  int n, m;
  while (cin >> n >> m) {
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    fill(&g[0][0], &g[N - 1][N - 1] + 1, false);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      // cout << make_pair(a, b) << endl;
      g[a][b] = g[b][a] = true;
    }
    cout << rec(0, 2 * n) << endl;
  }

  return 0;
}
