// github.com/Johniel/contests
// atcoder/abc277/G/main.cpp

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

int main(int argc, char *argv[])
{
  int n, m, step;
  while (cin >> n >> m >> step) {
    vec<int> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vec<int> c(n);
    cin >> c;

    const int N = 3000 + 3;
    static lli dp[N][N][3];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][3 - 1] + 1, 0);
    dp[0][0][0] = 1;
    for (int k = 0; k < step; ++k) {
      for (int i = 0; i < n; ++i) {
        lli deg = g[i].size();
        lli p = math::mod_inverse(deg, mod);
        each (j, g[i]) {
          (dp[k + 1][j][0] += dp[k][i][0] * p % mod) %= mod;
          (dp[k + 1][j][1] += dp[k][i][1] * p % mod) %= mod;
          (dp[k + 1][j][2] += dp[k][i][2] * p % mod) %= mod;
          if (!c[j]) {
            (dp[k + 1][j][1] += dp[k][i][0] * p % mod) %= mod;
            (dp[k + 1][j][2] += dp[k][i][1] * p % mod) %= mod;
          }
        }
      }
    }

    lli z = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (c[j]) {
          (z += dp[i][j][1]) %= mod;
          (z += dp[i][j][2] * 2) %= mod;
        }
      }
    }
    cout << z << endl;
  }

  return 0;
}
