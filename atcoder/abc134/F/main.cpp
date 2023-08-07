// github.com/Johniel/contests
// atcoder/abc134/F/main.cpp

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
  int n, oddness;
  while (cin >> n >> oddness) {
    const int N = 50 + 2;
    const int M = N * N + N;
    // 添字側をA、順列側をBとしてとき、
    // AとBをi番目まで見て、使われていない(保留)がj個あり、奇妙さの合計がkであるようなパターン数
    static lli dp[N][N][M]; // dp[i][j][k]
    fill(&dp[0][0][0], &dp[N - 1][N - 1][M - 1] + 1, 0);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k <= oddness; ++k) {

          // Ai使うとして、Biを避けてBの残りから選んで使うとき、結局jに変化は無い。Biの分で+1, 残りから選んで-1。
          // 逆も同じ。

          // AiもしくはBiを使わない場合、kに与える影響はjになる。
          // マッチングさせるもの同士を線で結んで交差する箇所を数えることを想像すると、１つ飛ばすごとに保留されているもの分の増加がある。

          // AiもBiも使わない
          (dp[i + 1][j + 1][k + 2 * j + 2] += dp[i][j][k]) %= mod;
          // AiとBの残りを使う
          if (j) (dp[i + 1][j][k + 2 * j] += dp[i][j][k] * j % mod) %= mod;
          // BiとAの残りを使う
          if (j) (dp[i + 1][j][k + 2 * j] += dp[i][j][k] * j % mod) %= mod;
          // AiとBiを使う
          (dp[i + 1][j][k + 2 * j] += dp[i][j][k]) %= mod;
          // AiとBの残りを使う && BiとAの残りを使う
          if (j) (dp[i + 1][j - 1][k + 2 * j - 2] += dp[i][j][k] * j * j % mod) %= mod;
        }
      }
    }
    cout << dp[n][0][oddness] << endl;
  }
  return 0;
}
