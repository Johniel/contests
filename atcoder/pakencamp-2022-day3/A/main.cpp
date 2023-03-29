// github.com/Johniel/contests
// atcoder/pakencamp-2022-day3/A/main.cpp

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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  const int N = 300 + 1;
  int n;
  while (cin >> n) {
    const int h = 2 * n + 1;
    const int w = 2 * n + 1;
    const int H = 2 * N + 1;
    const int W = 2 * N + 1;
    static int g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    static lli dp[H][W];
    const lli inf = 1LL << 61;
    fill(&dp[0][0], &dp[H - 1][W - 1] + 1, inf);

    for (int i = 0; i < h; ++i) {
      dp[i][0] = g[i][0];
    }
    for (int j = 0; j < n; ++j) {
      dp[0][j] = g[0][j];
      dp[h - 1][j] = g[h - 1][j];
    }

    auto show = [&] () {
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (dp[i][j] != inf) cout << dp[i][j] << ' ';
          else cout << "_ ";
        }
        cout << endl;
      }
      return ;
    };

    for (int j = 0; j < w; ++j) {
      auto fn = [&] (int i) {
        const int D = 5;
        const int di[D] = {-1, -1, 0, +1, +1};
        const int dj[D] = { 0,  1, 1,  1,  0};
        for (int d = 0; d < D; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          if (g[ni][nj] == -1) continue;
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          setmin(dp[ni][nj], dp[i][j] + g[ni][nj]);
        }
      };
      for (int i = 0; i < h; ++i) fn(i);
      for (int i = h - 1; 0 <= i; --i) fn(i);
      for (int i = 0; i < h; ++i) fn(i);
    }

    // show();

    lli mn = inf;
    for (int i = 0; i < h; ++i) {
      setmin(mn, dp[i][w - 1]);
    }
    for (int j = w - n; j < w; ++j) {
      setmin(mn, dp[0][j]);
      setmin(mn, dp[h - 1][j]);
    }
    cout << mn << endl;
  }
  return 0;
}
