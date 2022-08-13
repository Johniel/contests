// https://github.com/johniel/atcoder/abc227/F/main.cpp

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
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w, y;
  while (cin >> h >> w >> y) {
    const int H = 30 + 3;
    const int W = 30 + 3;
    static int g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const lli inf = (1LL << 60);
    auto fn = [&] (int x) {
      const int K = H + W;
      static lli dp[H][W][K];
      fill(&dp[0][0][0], &dp[H - 1][W - 1][K - 1] + 1, inf);
      dp[0][0][0] = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          for (int k = 0; k <= y; ++k) {
            bool a = (g[i][j] >= x);
            setmin(dp[i + 1][j][k + a], dp[i][j][k] + (a ? g[i][j] : 0));
            setmin(dp[i][j + 1][k + a], dp[i][j][k] + (a ? g[i][j] : 0));
            bool b = (g[i][j] > x);
            setmin(dp[i + 1][j][k + b], dp[i][j][k] + (b ? g[i][j] : 0));
            setmin(dp[i][j + 1][k + b], dp[i][j][k] + (b ? g[i][j] : 0));
          }
        }
      }

      return min(dp[h - 1][w][y], dp[h][w - 1][y]);
    };

    vec<int> v;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        v.push_back(g[i][j]);
      }
    }
    sort(v.begin(), v.end());

    lli mn = inf;
    each (i, v) setmin(mn, fn(i));
    cout << mn << endl;
  }

  return 0;
}
