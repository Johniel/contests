// github.com/Johniel/contests
// atcoder/abc411/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

namespace math {
  // gcd(a,b)を返す。xとyにはax+by=±gcd(a,b)を満たす数を設定する。
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

  constexpr lli constexpr_mod_inverse(lli a, lli mod)
  {
    lli inv = 1;
    lli p = mod - 2;
    while (p > 0) {
      if (p & 1) (inv *= a) %= mod;
      (a *= a) %= mod;
      p >>= 1;
    }
    return inv;
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

template<std::integral T>
inline int find_first_set(T b) {
  // assert(b);
  return __builtin_ffsll(b) - 1; // change to 0-origin
}

int main(int argc, char *argv[])
{
  const int N = 20 + 1;
  const int B = 1 << N;

  vec<lli> inv;
  for (int i = 0; i < N; ++i) {
    inv.push_back(math::mod_inverse(i, mod));
  }

  int n, m;
  // while (cin >> n >> m) {
  while (scanf("%d%d", &n, &m) == 2) {
    static lli g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, 0);
    for (int i = 0; i < m; ++i) {
      int a, b;
      // cin >> a >> b;
      scanf("%d%d", &a, &b);
      --a;
      --b;
      ++g[a][b];
      ++g[b][a];
    }

    static lli dp[B][N];
    vec<lli> v(N + 3, 0);
    for (int src = 0; src < n; ++src) {
      fill(&dp[0][0], &dp[B - 1][N - 1] + 1, 0);
      dp[1 << src][src] = 1;
      for (int bit = (1 << src); bit < (1 << n); ++bit) {
        int vis = bit;
        while (vis) {
          int a = vis - (vis & (vis - 1));
          int i = find_first_set(a);
          if (dp[bit][i]) {
            int rem = (((1 << n) - 1) ^ bit);
            while (rem) {
              int b = rem ^ (rem & (rem - 1));
              int j = find_first_set(b);
              (dp[bit | (1 << j)][j] += dp[bit][i] * g[i][j] % mod) %= mod;
              rem -= b;
            }
          }
          vis -= a;
        }
      }
      for (int bit = (1 << src); bit < (1 << n); ++bit) {
        const int len = __builtin_popcount(bit);
        if (len == 2) continue;
        for (int i = 0; i < n; ++i) {
          (v[len] += dp[bit][i] * g[i][src] % mod) %= mod;
        }
      }
    }

    lli z = 0;
    for (int i = 1; i < v.size(); ++i) {
      // lli reverse_order  = math::mod_inverse(2, mod);
      // lli start_position = math::mod_inverse(i, mod);
      lli reverse_order  = inv[2];
      lli start_position = inv[i];
      lli div = reverse_order * start_position % mod;
      (z += v[i] * div % mod) %= mod;
    }
    lli w = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        (w += g[i][j] * (g[i][j] - 1) % mod) %= mod;
      }
    }
    // (z += w * math::mod_inverse(2, mod) % mod) %= mod;
    (z += w * inv[2] % mod) %= mod;
    // cout << z << endl;
    printf("%lld\n", z);
  }
  return 0;
}
