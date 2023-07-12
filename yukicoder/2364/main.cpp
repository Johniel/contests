// github.com/Johniel/contests
// yukicoder/2364/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n, m, w;
  while (cin >> n >> m >> w) {
    vec<lli> a(n), b(n), c(m), d(m);
    cin >> a >> b >> c >> d;
    const int N = (1 << 7) + 3;
    const int M = (1 << 7) + 3;
    const int W = 500 + 3;
    static lli dp[N][M][W];
    const lli inf = 1LL << 60;
    fill(&dp[0][0][0], &dp[N - 1][M - 1][W - 1] + 1, -inf);
    dp[0][0][0] = 0;
    for (int b1 = 0; b1 < (1 << n); ++b1) {
      for (int b2 = 0; b2 < (1 << m); ++b2) {
        for (int k = 0; k < W; ++k) {
          if (dp[b1][b2][k] < 0) continue;
          for (int i = 0; i < n; ++i) {
            if (b1 & (1 << i)) continue;
            if (k + a[i] <= w) {
              setmax(dp[b1 | (1 << i)][b2][k + a[i]], dp[b1][b2][k] + b[i]);
            }
          }
          for (int j = 0; j < m; ++j) {
            if (b2 & (1 << j)) continue;
            if (0 <= k - c[j]) {
              setmax(dp[b1][b2 | (1 << j)][k - c[j]], dp[b1][b2][k] - d[j]);
            }
          }
        }
      }
    }
    cout << *max_element(&dp[0][0][0], &dp[N - 1][M - 1][W - 1] + 1) << endl;
  }
  return 0;
}
