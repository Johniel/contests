// codeforces/677div3/F/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w, k;
  while (cin >> h >> w >> k) {
    vec<int> v[h];
    for (int i = 0; i < h; ++i) {
      v[i].resize(w);
      cin >> v[i];
    }

    const int N = 70 + 5;
    const int W = 70 + 5;
    const int K = 70 + 5;
    static int dp[N][W][K];
    vec<vec<pair<int, int>>> u(h);
    for (int i = 0; i < h; ++i) {
      fill(&dp[0][0][0], &dp[N - 1][W - 1][K - 1] + 1, -(1 << 29));
      dp[0][0][0] = 0;
      for (int a = 0; a < w; ++a) {
        for (int b = 0; b < W; ++b) {
          for (int c = 0; c < K; ++c) {
            if (dp[a][b][c] < 0) continue;
            if (b + 1 <= w / 2) setmax(dp[a + 1][b + 1][(c + v[i][a]) % k], dp[a][b][c] + v[i][a]);
            setmax(dp[a + 1][b][c], dp[a][b][c]);
          }
        }
      }
      map<int, int> mx;
      for (int b = 0; b <= w/2; ++b) {
        for (int c = 0; c < K; ++c) {
          if (0 <= dp[w][b][c]) setmax(mx[c], dp[w][b][c]);
        }
      }
      each (j, mx) u[i].push_back(j);
      // cout << u[i] << endl;
    }

    {
      static int dp[N][K];
      fill(&dp[0][0], &dp[N - 1][K - 1] + 1, -(1 << 29));
      dp[0][0] = 0;
      for (int i = 0; i < u.size(); ++i) {
        for (int j = 0; j < K; ++j) {
          each (x, u[i]) {
            setmax(dp[i + 1][(j + x.first) % k], dp[i][j] + x.second);
          }
        }
      }
      cout << dp[u.size()][0] << endl;
    }
  }

  return 0;
}
